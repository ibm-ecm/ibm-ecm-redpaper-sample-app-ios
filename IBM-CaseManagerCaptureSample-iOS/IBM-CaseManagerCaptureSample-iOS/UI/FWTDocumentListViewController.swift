//
//  FWTDocumentListViewController.swift
//  IBM-CaseManagerCaptureSample-iOS
//
//  Copyright © 2015 IBM. All rights reserved.
//

import UIKit
import IBMCaseManagerSDK

class FWTDocumentListViewController: UITableViewController {

    let documentCellIdentifier = "DocumentCellIdentifier"
    
    var taskManager:ICMTaskObjectManager?
    var batch:ICPBatch?
    var documents:[FWTDocumentSection] = []
    var enableDoneButton = true
    let datacapRequester:FWTDatacapRequester = FWTDatacapRequester(sessionConfiguration: FWTDatacapSessionConfiguration())
    
    var sectionsComplete:Bool {
        get {
            return enableDoneButton && (documents.count > 0 && documents.filter{ $0.pagesComplete() == $0.pages.count }.count == documents.count)
        }
    }
    
    @IBOutlet var doneButton:UIBarButtonItem!
    
    //MARK: View lifecicle
    
    override func viewDidLoad() {
        super.viewDidLoad()
        displayTaskInformation()
    }
    
    override func viewDidAppear(animated: Bool) {
        if batch == nil {
            reloadData()
        }
        self.doneButton?.enabled = sectionsComplete
        super.viewDidAppear(animated)
    }
    
    //MARK: Actions
    
    @IBAction func doneButtonTapped(sender: AnyObject) {
        if let batch = completeBatch() {
            
            MBProgressHUD.showHUDAddedTo(self.view, animated: true)
            
            self.datacapRequester.updateBatch(batch, completion: { [weak self] (success, error) -> Void in
                
                MBProgressHUD.hideHUDForView(self?.view, animated: true)
                
                if let error = error where !success {
                    self?.presentError(error)
                } else {
                    self?.presentBatchComplete()
                }
            })
        }
    }
    
    override func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
        self.performSegueWithIdentifier("ShowCamera", sender: self)
    }
    
    //MARK: Data
    
    func createSection(batchType:ICPBatchType) {
        batch = datacapRequester.getBatchForType(batchType)
        
        if let documentTypes = batchType.documentTypes as? [ICPDocumentType] {
           self.documents = documentTypes.map {
                let document = self.datacapRequester.getDocumentForType(self.batch!, documentType: $0)
                let pageTypes = $0.pageTypes as! [ICPPageType]
                let builtPages = pageTypes.map { self.datacapRequester.getPageForType(document, pageType: $0) }
                return FWTDocumentSection(document: document, pages: builtPages)
            }
        } else {
            self.documents = []
        }
    }
    
    func completeBatch() -> ICPBatch? {
        let batch = self.batch
        
        if let caseId = taskManager?.task.caseInstance.caseId {
            batch?.type.dcoDictionary["CASE ID"] = caseId;
        }
        
        let docs:[ICPDocument] = self.documents.map {
            let doc = $0.document
            doc.pages = $0.pages
            doc.status = .Queued
            return doc
        }
        batch?.documents = docs
        return batch
    }
    
    //MARK: UI update
    
    func reloadData() {
        MBProgressHUD.showHUDAddedTo(self.view, animated: true)
        datacapRequester.getBatchType { [weak self] (success, batchType) -> Void in
            MBProgressHUD.hideAllHUDsForView(self?.view, animated: true)
            
            guard let batchType = batchType else {
                return;
            }
            
            guard self?.batch == nil else {
                return;
            }
            
            self?.createSection(batchType)
            self?.tableView.reloadData()
        }
    }
    
    func displayTaskInformation() {
        guard let taskManager = taskManager else { return }
        self.title = taskManager.task.stepName
    }
    
    func presentBatchComplete() {
        enableDoneButton = false
        doneButton.enabled = false
        presentAlert("Success", message: "Documents uploaded to server")
    }
    
    func presentError(error:NSError) {
        presentAlert("Error", message: error.localizedDescription)
    }
    
    func presentAlert(title:String, message:String) {
        let alert = UIAlertController(title: title, message: message, preferredStyle: .Alert)
        let action = UIAlertAction(title: "Ok", style: .Default, handler: nil)
        alert.addAction(action)
        self.presentViewController(alert, animated: true, completion: nil)
    }
    
    //MARK: Navigation Controller
    
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        guard let cameraPreviewController = segue.destinationViewController as? FWTCameraPreviewViewController else {
            return
        }
        cameraPreviewController.cameraScanBlock = { [weak self] (original, modified, error) in
            
            self?.navigationController?.popViewControllerAnimated(true)
            
            guard let sself = self, let indexPath = self?.tableView?.indexPathForSelectedRow else {
                return
            }
            
            guard indexPath.section < sself.documents.count else {
                return
            }
            
            var section = sself.documents[indexPath.section]
            section.updateImages(original: original, modified: modified, index: indexPath.row)
            sself.documents[indexPath.section] = section
            
            sself.tableView.beginUpdates()
            sself.tableView.reloadRowsAtIndexPaths([indexPath], withRowAnimation: UITableViewRowAnimation.None)
            sself.tableView.endUpdates()
        }
        
        guard let indexPath = tableView?.indexPathForSelectedRow where indexPath.section < self.documents.count else {
            return
        }
        
        let section = self.documents[indexPath.section]
        
        guard indexPath.row < section.pages.count else {
            return
        }
        
        let page = section.pages[indexPath.row]
        cameraPreviewController.enableDocumentDetection = page.type.typeId.ibm_prettyPrint() != "Other"
    }
    
    //MARK: Table view data source
    
    override func numberOfSectionsInTableView(tableView: UITableView) -> Int {
        return self.documents.count
    }
    
    override func tableView(tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        guard (section < self.documents.count) else {
            return ""
        }
        let sectionItem = self.documents[section]
        return sectionItem.title
    }
    
    override func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        guard (section < self.documents.count) else {
            return 0
        }
        let sectionItem = self.documents[section]
        return sectionItem.pages.count
    }
    
    override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        return documentCell(tableView, indexPath: indexPath, sections: self.documents)
    }
    
    func documentCell(tableView:UITableView, indexPath:NSIndexPath, sections:[FWTDocumentSection]) -> UITableViewCell!
    {
        var cell:UITableViewCell!
        
        cell = tableView.dequeueReusableCellWithIdentifier(documentCellIdentifier)
        if cell == nil {
            cell = UITableViewCell(style: .Default, reuseIdentifier: nil)
        }
        
        guard (indexPath.section < sections.count) else {
            return cell
        }
        
        let section = sections[indexPath.section]
        
        guard (indexPath.row < section.pages.count) else {
            return cell
        }
        
        let page = section.pages[indexPath.row]
        
        cell?.textLabel?.text = page.type.typeId.ibm_prettyPrint()
        cell?.imageView?.image = page.thumbnailImage
        cell?.accessoryType = (page.originalImage != nil ? UITableViewCellAccessoryType.Checkmark : UITableViewCellAccessoryType.None)
        
        return cell
    }
}
