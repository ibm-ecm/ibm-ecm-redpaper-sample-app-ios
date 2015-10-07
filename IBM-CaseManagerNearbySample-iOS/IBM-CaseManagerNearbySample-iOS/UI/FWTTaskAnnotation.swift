//
//  FWTTaskAnnotation.swift
//  IBM-CaseManagerNearbySample-iOS
//
//  Copyright © 2015 IBM. All rights reserved.
//

import MapKit

class FWTTaskAnnotation: NSObject, MKAnnotation {
    
    let task:ICMTask
    let roleManager:ICMRoleObjectManager
    
    var coordinate: CLLocationCoordinate2D
    
    // Title and subtitle for use by selection UI.
    var title: String? {
        get {
            return task.subject
        }
    }
    var subtitle: String? {
        get {
            return task.stepName
        }
    }
    
    init(task:ICMTask, roleManager:ICMRoleObjectManager) {
        self.coordinate = CLLocationCoordinate2DMake(task.caseInstance.latitude, task.caseInstance.longitude)
        self.task = task
        self.roleManager = roleManager
    }
}
