//
//  FWTDatacapSessionConfiguration.swift
//  IBM-CaseManagerCaptureSample-iOS
//
//  Copyright © 2015 IBM. All rights reserved.
//

import Foundation

struct FWTDatacapSessionConfiguration {
    private let serverUrl = NSURL(string: "http://ecm1.fws.io:8070/servicewtm.svc")
    private let username = "ecmexec"
    private let password = "ecmexec"
    private let stationId = "1"
    private let applicationId = "CarLoan"
    private let workflowId = "CarLoan"
    private let jobId = "Manual Select"
    private let dcoName = "CarLoan"
    
    lazy var credential:ICPCredential = { return ICPCredential(username: "ecmexec", password: "ecmexec", stationId: "1") }()
    
    lazy var capture:ICPCapture = { return ICPCapture.instanceWithObjectFactoryType(.NonPersistent) }()
    
    lazy var service:ICPDatacapService = {
        let service = self.capture.objectFactory.datacapServiceWithBaseURL(self.serverUrl)
        service.allowInvalidCertificates = true
        service.applicationId = self.applicationId
        service.workflowId = self.workflowId
        service.jobId = self.jobId
        service.dcoName = self.dcoName
        return service
    }()
    
    lazy var serviceClient:ICPServiceClient = {
        return self.capture.clientForService(self.service, withCredential: self.credential)
    }()
    
    lazy var datacapHelper:ICPDatacapHelper = {
        return ICPDatacapHelper(datacapService: self.service, credential: self.credential)
    }()
    
    init() {}
}