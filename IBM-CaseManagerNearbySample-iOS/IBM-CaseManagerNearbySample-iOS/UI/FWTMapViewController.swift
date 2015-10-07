//
//  ViewController.swift
//  IBM-CaseManagerNearbySample-iOS
//
//  Copyright © 2015 IBM. All rights reserved.
//

import UIKit
import MapKit

// MARK: Server configuration

let SimpleSampleBaseURLString = "http://ecmtest1.ibm.office.fwn:9080/navigator"
let SimpleSampleUsername = "p8admin"
let SimpleSamplePassword = "filenet"

// MARK: CLLocationManager configuration

protocol FWTLocationManager {
    func createLocationManager(delegate delegate:CLLocationManagerDelegate) -> CLLocationManager
}

extension FWTLocationManager {
    func createLocationManager(delegate delegate:CLLocationManagerDelegate) -> CLLocationManager
    {
        let manager = CLLocationManager()
        manager.delegate = delegate
        if CLLocationManager.authorizationStatus() != .AuthorizedWhenInUse {
            manager.requestWhenInUseAuthorization()
        }
        return manager
    }
}

// MARK: ICMSessionManager configuration

protocol FWTCoreManagerSession {
    func createSession(host host:String, user:String, password:String) -> ICMSessionManager
}

extension FWTCoreManagerSession {
    func createSession(host host:String, user:String, password:String) -> ICMSessionManager
    {
        let baseURL = NSURL(string: host)
        let credential = NSURLCredential(user: user, password: password, persistence: .None)
        let manager = ICMSessionManager(baseURL: baseURL!, credential: credential, persistenceType: .Memory)
        return manager
    }
}

struct FWTTaskInformation {
    let task:ICMTask?
    let roleManager:ICMRoleObjectManager?
    
    init(task:ICMTask?, roleManager:ICMRoleObjectManager?) {
        self.task = task
        self.roleManager = roleManager
    }
}

// MARK: First view controller

class FWTMapViewController: UIViewController, CLLocationManagerDelegate, MKMapViewDelegate, FWTLocationManager, FWTCoreManagerSession {

    // MARK: Constants
    let annotationViewIdentifier = "MKAnnoationView"
    let coreManagerRequester = FWTNearbyCoreManagerRequester(profile: FWTProfileConfiguration(solutionPrefix: "CRE1", role: "Loan Officer"))
    let span = 0.3
    let searchRadius = 0.5
    var taskInformation = FWTTaskInformation(task: nil, roleManager: nil)
    var lastCoordinate = CLLocationCoordinate2DMake(0, 0)
    
    
    // MARK: Outlets
    
    @IBOutlet weak var mapView: MKMapView!
    @IBOutlet weak var loadingLabel: UILabel!
    
    // MARK: Lazy variables
    
    lazy var locationManager:CLLocationManager =  { [unowned self] in
        let manager = self.createLocationManager(delegate: self)
        return manager
    }()
    
    lazy var sessionManager:ICMSessionManager = { [unowned self] in
        let manager = self.createSession(host: SimpleSampleBaseURLString, user: SimpleSampleUsername, password: SimpleSamplePassword)
        return manager
    }()
    
    // MARK: View lifecicle
    
    override func viewDidLoad() {
        super.viewDidLoad()
        locationManager.startUpdatingLocation()
        loadingLabel?.hidden = true
        mapView?.delegate = self
        mapView?.showsUserLocation = true
    }
    
    // MARK: Navigation
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        if let destinationViewController = segue.destinationViewController as? FWTTaskDetailViewController {
            destinationViewController.configDetail(self.taskInformation.task, roleManager: self.taskInformation.roleManager, coreManagerRequester: self.coreManagerRequester)
        }
    }
    
    // MARK: Data handler
    
    func reloadData(coordinate:CLLocationCoordinate2D) {
        loadingLabel?.hidden = false
        if let annotations = mapView?.annotations {
            mapView?.removeAnnotations(annotations)
        }
        coreManagerRequester.getUserNearbyTasks(sessionManager, coordinate: coordinate, radius: (searchRadius * span)) { [weak self] (success, roleManager, tasks) -> Void in
            self?.loadingLabel?.hidden = true
            if success, let roleManager = roleManager {
                self?.putTasksOnMap(tasks, roleManager)
            }
        }
    }
    
    func putTasksOnMap(tasks:[ICMTask], _ roleManager:ICMRoleObjectManager) {
        let annotations = tasks.map { FWTTaskAnnotation(task: $0, roleManager: roleManager) }
        mapView?.addAnnotations(annotations)
    }
    
    // MARK: Location Manager Delegate
    
    func locationManager(manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        if let location = locations.last {
            moveCamera(location.coordinate)
        }
        locationManager.stopUpdatingLocation()
    }
    
    // MARK: MapView Delegate
    
    func moveCamera(coordinate:CLLocationCoordinate2D) {
        let coordinateSpan = MKCoordinateSpanMake(span, span)
        mapView?.setRegion(MKCoordinateRegionMake(coordinate, coordinateSpan), animated: true)
    }
    
    func mapView(mapView: MKMapView, didUpdateUserLocation userLocation: MKUserLocation) {
        moveCamera(userLocation.coordinate)
        reloadData(userLocation.coordinate)
    }
    
    func mapView(mapView: MKMapView, viewForAnnotation annotation: MKAnnotation) -> MKAnnotationView? {
        if annotation is MKUserLocation {
            return nil
        }
        
        if let annotationView = mapView.dequeueReusableAnnotationViewWithIdentifier(annotationViewIdentifier) {
            annotationView.annotation = annotation
            return annotationView
        }
        
        let annotationView = MKPinAnnotationView(annotation: annotation, reuseIdentifier: annotationViewIdentifier)
        annotationView.canShowCallout = true
        annotationView.leftCalloutAccessoryView = UIButton(type: .InfoLight)
        return annotationView
    }
    
    func mapView(mapView: MKMapView, annotationView view: MKAnnotationView, calloutAccessoryControlTapped control: UIControl) {
        if let taskAnnotation = view.annotation as? FWTTaskAnnotation {
            self.taskInformation = FWTTaskInformation(task: taskAnnotation.task, roleManager: taskAnnotation.roleManager)
            self.performSegueWithIdentifier("taskDetail", sender: self)
        }
    }
}