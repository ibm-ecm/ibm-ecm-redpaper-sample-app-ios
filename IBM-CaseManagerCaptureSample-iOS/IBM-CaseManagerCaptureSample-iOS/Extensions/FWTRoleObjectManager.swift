//
//  FWTRoleObjectManager.swift
//  IBM-CaseManagerCaptureSample-iOS
//
//  Copyright © 2015 IBM. All rights reserved.
//

import Foundation
import IBMCaseManagerSDK

extension ICMRoleObjectManager {
    /**
    Get all the tasks for a specific role
    
    - returns: `[ICMTask]` with all the tasks for that role
    */
    func getAllTasks() -> [ICMTask] {
        let tasks:[ICMTask] = self.role.inbaskets.map { $0.tasks }.filter { $0 != nil }.flatMap { $0! }
        return tasks
    }
}