//
//  FWTTaskDetailViewController.swift
//  IBM-CaseManagerNearbySample-iOS
//
//  Copyright © 2015 IBM. All rights reserved.
//

import UIKit

extension SequenceType where Generator.Element == ICMProperty {
    var propertyDictionary: [String:AnyObject!] {
        get {
            let enabledProperties = filter({ !$0.readOnly && ($0.value != nil) })
            var dict:[String:AnyObject!] = [:]
            enabledProperties.forEach({ dict[$0.identifier] = $0.value })
            return dict
        }
    }
}

class FWTTaskDetailViewController: UIViewController {

    @IBOutlet weak var nameLabel: UILabel!
    @IBOutlet weak var subjectLabel: UILabel!
    @IBOutlet weak var lockButton: UIButton!
    @IBOutlet weak var finishTaskButton: UIButton!
    var coreManagerRequester:FWTCoreManagerRequester?
    var roleManager:ICMRoleObjectManager?
    var task:ICMTask?
    var taskManager:ICMTaskObjectManager? {
        didSet {
            self.task = taskManager?.task
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.updateScreen()
    }

    override func viewDidAppear(animated: Bool) {
        updateTaskInformation()
    }
    
    func updateTaskInformation() {
        if let task = task, let requester = coreManagerRequester, let roleManager = roleManager {
            requester.getTaskDetails(roleManager, task: task, completion: { [weak self] (success, taskManager) -> Void in
                if success, let sself = self {
                    sself.taskManager = taskManager
                    sself.updateScreen()
                }
            })
        }
    }
    
    func configDetail(task:ICMTask?, roleManager:ICMRoleObjectManager?, coreManagerRequester:FWTCoreManagerRequester?) {
        self.task = task
        self.roleManager = roleManager
        self.coreManagerRequester = coreManagerRequester
    }
    
    func showMessage(title title:String, message:String) {
        let alertController = UIAlertController(title: title, message: message, preferredStyle: .Alert)
        alertController.addAction(UIAlertAction(title: "Ok", style: .Cancel, handler: nil))
        self.presentViewController(alertController, animated: true, completion: nil)
    }
    
    func updateScreen() {
        let actionsEnabled = taskManager != nil
        
        if let task = task {
            nameLabel?.text = task.stepName
            subjectLabel?.text = task.subject
            
            if !task.lockedUser.isEmpty {
                lockButton?.setTitle("Unlock Task", forState: .Normal)
            } else {
                lockButton?.setTitle("Lock Task", forState: .Normal)
            }
            
            finishTaskButton?.enabled = actionsEnabled
            lockButton?.enabled = actionsEnabled
        }
    }
    
    @IBAction func changeLockState(sender: UIButton)
    {
        if let task = task, let taskManager = taskManager {
            if !task.lockedUser.isEmpty {
                taskManager.unlockTaskWithCompletion({ [weak self] (success, error) -> Void in
                    self?.showMessage(title: "Unlock Task", message: ( success ? "Task unlocked" : (error?.localizedDescription ?? "Error") ))
                    if success {
                        self?.lockButton?.setTitle("Lock Task", forState: .Normal)
                    }
                })
            } else {
                taskManager.lockTaskWithCompletion({ [weak self] (success, error) -> Void in
                    self?.showMessage(title: "Lock Task", message: ( success ? "Task locked" : (error?.localizedDescription ?? "Error") ))
                    if success {
                        self?.lockButton?.setTitle("Unlock Task", forState: .Normal)
                    }
                })
            }
        }
    }
    
    @IBAction func finishTask(sender: UIButton)
    {
        if let taskManager = taskManager {
            
            let response = taskManager.task.responses.first ?? "Complete"
            let properties = taskManager.task.properties
            let dictionary = properties.propertyDictionary
            
            taskManager.completeTaskWithResponse(response, properties: dictionary, completion: { [weak self] (success, error) -> Void in
                self?.showMessage(title: "Complete Task", message: ( success ? "Task completed" : (error?.localizedDescription ?? "Error") ))
            })
        }
    }
}
