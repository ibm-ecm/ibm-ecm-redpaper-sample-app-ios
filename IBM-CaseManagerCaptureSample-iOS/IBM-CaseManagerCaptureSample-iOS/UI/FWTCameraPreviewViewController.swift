//
//  FWTCameraPreviewViewController.swift
//  IBM-CaseManagerCaptureSample-iOS
//
//  Copyright © 2015 IBM. All rights reserved.
//

import UIKit

typealias FWTCameraPreviewScanDocument = (original:UIImage!, modified:UIImage!, error:NSError!)->Void

class FWTCameraPreviewViewController: UIViewController {

    let enabledDetectionMessage = "Scan the document"
    let disabledDetectionMessage = "Touch the screen to take the picture"
    
    @IBOutlet var cameraPreview:ICPCameraPreview!
    @IBOutlet var messageLabel:UILabel!
    var cameraScanBlock:FWTCameraPreviewScanDocument?
    var enableDocumentDetection:Bool = true
    private(set) lazy var cameraStatusChangedBlock:ICPCameraPreviewStatusChangedBlock = { [weak self] (cameraStatus) -> Void in
        if cameraStatus == ICPCameraStatus.DocumentDetected {
            dispatch_async(dispatch_get_main_queue(), { () -> Void in
                guard let sself = self where sself.enableDocumentDetection else {
                    return
                }
                sself.cameraPreview.stopCapturing()
                sself.takePicture()
            })
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        cameraPreview?.rectDetectionEnabled = enableDocumentDetection
        messageLabel?.text = (enableDocumentDetection ? enabledDetectionMessage : disabledDetectionMessage)
    }
    
    override func viewDidAppear(animated: Bool) {
        cameraPreview?.startCapturingWithStatusChangedBlock(cameraStatusChangedBlock)
    }
    
    override func viewWillTransitionToSize(size: CGSize, withTransitionCoordinator coordinator: UIViewControllerTransitionCoordinator) {
        cameraPreview?.stopCapturing()
        super.viewWillTransitionToSize(size, withTransitionCoordinator: coordinator)
        coordinator.animateAlongsideTransition(nil) { [weak self] (coordinator) -> Void in
            self?.cameraPreview?.startCapturingWithStatusChangedBlock(self?.cameraStatusChangedBlock)
        }
    }
    
    override func viewWillDisappear(animated: Bool) {
        cameraPreview?.stopCapturing()
        super.viewWillDisappear(animated)
    }

    @IBAction func tapOnCamera(sender: UITapGestureRecognizer!) {
        if !enableDocumentDetection {
            takePicture()
        }
    }
    
    func takePicture() {
        MBProgressHUD.showHUDAddedTo(self.view, animated: true)
        cameraPreview?.takePictureWithCompletionBlock({ [weak self] (originalImage, rectifiedPicture, error) -> Void in
            MBProgressHUD.hideAllHUDsForView(self?.view, animated: true)
            self?.cameraScanBlock?(original:originalImage, modified:rectifiedPicture, error:error)
        })
    }
}
