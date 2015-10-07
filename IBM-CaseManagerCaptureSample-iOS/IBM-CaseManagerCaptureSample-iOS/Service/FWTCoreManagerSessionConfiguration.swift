//
//  FWTCoreManagerSessionConfiguration.swift
//  IBM-CaseManagerCaptureSample-iOS
//
//  Copyright © 2015 IBM. All rights reserved.
//

import Foundation

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

struct FWTCoreManagerSessionConfiguration:FWTCoreManagerSession
{
    let serverHost = "http://ecm1.fws.io:9080/navigator"
    let user = "ecmexec"
    let password = "ecmexec"
    
    private(set) lazy var coreManagerSession:ICMSessionManager = {
        let sessionManager = self.createSession(host: self.serverHost, user: self.user, password: self.password)
        return sessionManager
    }()
    
    let solutionPrefix:String
    let role:String
    let taskRagexPattern:String
    
    init(solutionPrefix:String, role:String, taskRagexPattern:String) {
        self.solutionPrefix = solutionPrefix
        self.role = role
        self.taskRagexPattern = taskRagexPattern
    }
}