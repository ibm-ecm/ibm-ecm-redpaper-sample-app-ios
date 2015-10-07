//
//  FWTCameraPreviewViewController.swift
//  IBM-CaseManagerCaptureSample-iOS
//
//  Created by Igor Fereira on 09/10/2015.
//  Copyright © 2015 Future Workshops. All rights reserved.
//

import UIKit

typealias FWTCameraPreviewScanDocument = (UIImage!, NSError!)->Void

class FWTCameraPreviewViewController: UIViewController {

    @IBOutlet var cameraPreview:ICPCameraPreview!
    var cameraScanBlock:FWTCameraPreviewScanDocument?
    let cameraStatusChangedBlock:ICPCameraPreviewStatusChangedBlock = { (cameraStatus) -> Void in }
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    override func viewDidAppear(animated: Bool) {
        cameraPreview?.startCapturingWithStatusChangedBlock(cameraStatusChangedBlock)
    }
    
    override func viewWillTransitionToSize(size: CGSize, withTransitionCoordinator coordinator: UIViewControllerTransitionCoordinator) {
        cameraPreview?.stopCapturing()
        super.viewWillTransitionToSize(size, withTransitionCoordinator: coordinator)
        coordinator.animateAlongsideTransition(nil) { [weak self] (coordinator) -> Void in
            self?.cameraPreview?.startCapturingWithStatusChangedBlock(cameraStatusChangedBlock)
        }
    }
    
    override func viewWillDisappear(animated: Bool) {
        cameraPreview?.stopCapturing()
        super.viewWillDisappear(animated)
    }

    @IBAction func tapOnCamera(sender: UITapGestureRecognizer) {
        cameraPreview?.takePictureWithCompletionBlock({ [weak self] (originalImage, rectifiedPicture, error) -> Void in
            let image = (originalImage ?? rectifiedPicture)
            self?.cameraScanBlock?(image, error)
        })
    }
}
