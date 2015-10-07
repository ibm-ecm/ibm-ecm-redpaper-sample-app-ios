//
//  FWTCaseDetailsViewController.swift
//  IBM-CaseManagerCaptureSample-iOS
//
//  Created by Igor Fereira on 28/09/2015.
//  Copyright © 2015 Future Workshops. All rights reserved.
//

import UIKit

class FWTCaseDetailsViewController: UITableViewController {

    //MARK: TableView content
    var taskManager:ICMTaskObjectManager?
    var layout:[FWTPropertiesSection] = []

    //MARK: Lazy properties
    private(set) lazy var coreManagerRequester:FWTCoreManagerRequester = {
        return FWTSampleCoreManagerRequester()
    }()
    
    private(set) lazy var sessionManager:FWTCoreManagerSessionConfiguration = {
        let sessionManager = FWTCoreManagerSessionConfiguration(solutionPrefix: "CRE1", role: "Loan Officer", taskRagexPattern: "^([Gg]ather)\\s")
        return sessionManager
    }()
    
    private(set) lazy var dateFormatter:NSDateFormatter = {
        return NSDateFormatter.defaultIBMFormatter()
    }()
    
    //MARK: View lifecicle
    override func viewDidAppear(animated: Bool) {
        super.viewDidAppear(animated)
        
        guard layout.count == 0 else { return }
        
        MBProgressHUD.showHUDAddedTo(self.tableView, animated: true)
        updateData { [weak self] in
            MBProgressHUD.hideAllHUDsForView(self?.tableView, animated: true)
            self?.updateTaskOnScreen()
        }
    }

    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        guard let destinationViewController = segue.destinationViewController as? FWTDocumentListViewController else { return }
        destinationViewController.taskManager = taskManager
    }
    
    //MARK: View actions
    @IBAction func updateAndCompleteAction(sender: UIBarButtonItem)
    {
        view?.endEditing(true)
        let elements:[FWTPropertyElement] = layout.flatMap { $0.elements }
        
        do {
            let properties = try elements.dictionary()
            guard let response = taskManager?.task.responses.first as? String else { return }
            
            taskManager?.completeTaskWithResponse(response, properties: properties, completion: { [weak self] (success, error) -> Void in
                self?.performSegueWithIdentifier("ShowDocuments", sender: self)
            })
        } catch {
            presentErrorMessage("Missing required property")
        }
    }
    
    //MARK: UI Tasks
    func updateTaskOnScreen() {
        if let task = self.taskManager?.task {
            self.title = task.subject
        }
        self.tableView?.reloadData()
    }
    
    func presentErrorMessage(message:String) {
        let alertView = UIAlertController(title: "Error", message: message, preferredStyle: .Alert)
        alertView.addAction(UIAlertAction(title: "Ok", style: .Default, handler: nil))
        self.presentViewController(alertView, animated: true, completion: nil)
    }
    
    //MARK: Data methods
    func updateData(completion:(()->Void)?) {
        coreManagerRequester.getLayout(self.sessionManager) { (taskManager) -> Void in
            self.taskManager = taskManager
            if let layout = self.taskManager?.task.layout as? [ICMTaskPropertiesLayout] {
                self.layout = layout.map { $0.section() }
            }
            completion?()
        }
    }
}