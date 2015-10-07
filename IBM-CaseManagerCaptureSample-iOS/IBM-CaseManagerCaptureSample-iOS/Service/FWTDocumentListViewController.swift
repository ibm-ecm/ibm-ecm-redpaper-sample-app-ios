//
//  FWTDocumentListViewController.swift
//  IBM-CaseManagerCaptureSample-iOS
//
//  Created by Igor Fereira on 06/10/2015.
//  Copyright © 2015 Future Workshops. All rights reserved.
//

import UIKit

class FWTDocumentListViewController: UITableViewController {

    var taskManager:ICMTaskObjectManager?
    var batchType:ICPBatchType?
    let datacapRequester = FWTDatacapRequester(sessionConfiguration: FWTDatacapSessionConfiguration())
    
    @IBOutlet var doneButton:UIBarButtonItem!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        displayTaskInformation()
    }
    
    override func viewDidAppear(animated: Bool) {
        if batchType == nil {
            reloadData()
        }
    }
    
    func reloadData() {
        MBProgressHUD.showHUDAddedTo(self.view, animated: true)
        datacapRequester.getBatchType { [weak self] (success, batchType) -> Void in
            self?.batchType = batchType
            self?.tableView?.reloadData()
            MBProgressHUD.hideAllHUDsForView(self?.view, animated: true)
        }
    }
    
    func displayTaskInformation() {
        guard let taskManager = taskManager else { return }
        self.title = taskManager.task.stepName
    }
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        guard let cameraPreviewController = segue.destinationViewController as? FWTCameraPreviewViewController else {
            return
        }
        cameraPreviewController.cameraScanBlock = { [weak self] (image, error) in
            if let indexPath = self?.tableView.indexPathForSelectedRow {
                print(indexPath)
            }
            self?.navigationController?.popViewControllerAnimated(true)
        }
    }
    
    override func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return batchType?.documentTypes.count ?? 0
    }
    
    override func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
        self.performSegueWithIdentifier("ShowCamera", sender: self)
    }
    
    override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        let cell = UITableViewCell(style: .Default, reuseIdentifier: nil)
        cell.textLabel?.text = "Document"
        cell.accessoryType = UITableViewCellAccessoryType.Checkmark
        return cell
    }
}
