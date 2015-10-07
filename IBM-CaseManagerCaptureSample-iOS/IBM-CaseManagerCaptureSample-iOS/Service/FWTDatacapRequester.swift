//
//  FWTDatacapRequester.swift
//  IBM-CaseManagerCaptureSample-iOS
//
//  Copyright © 2015 IBM. All rights reserved.
//

struct FWTDatacapRequester {
    let service:ICPDatacapService
    let helper:ICPDatacapHelper
    let serviceClient:ICPServiceClient
    let capture:ICPCapture
    
    init(var sessionConfiguration:FWTDatacapSessionConfiguration) {
        self.service = sessionConfiguration.service
        self.serviceClient = sessionConfiguration.serviceClient
        self.helper = sessionConfiguration.datacapHelper
        self.capture = sessionConfiguration.capture
    }
    
    func getBatchType(completion:(success:Bool, batchType:ICPBatchType?) -> Void)
    {
        serviceClient.getBatchTypeWithCompletionBlock { (success, result, error) -> Void in
            if let batchType = result as? ICPBatchType where success {
                completion(success: success, batchType: batchType)
            } else {
                completion(success: success, batchType: nil)
            }
        }
    }
    
    func updateBatch(batch:ICPBatch, completion:(success:Bool, error:NSError!) -> Void) {
        batch.status = .Queued
        serviceClient.uploadBatch(batch, progressBlock: nil, completionBlock: { (success, result, error) -> Void in
            completion(success: success, error: error)
        })
    }
    
    func getBatchForType(type:ICPBatchType) -> ICPBatch {
        return capture.objectFactory.batchWithType(type)
    }
    
    func getDocumentForType(batch:ICPBatch, documentType:ICPDocumentType) -> ICPDocument {
        return capture.objectFactory.documentWithBatch(batch, type: documentType)
    }
    
    func getPageForType(document:ICPDocument, pageType:ICPPageType) -> ICPPage {
        return capture.objectFactory.pageWithDocument(document, type: pageType)
    }
}
