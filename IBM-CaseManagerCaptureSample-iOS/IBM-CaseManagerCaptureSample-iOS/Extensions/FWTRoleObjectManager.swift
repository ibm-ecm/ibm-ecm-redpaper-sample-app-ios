//
//  FWTRoleObjectManager.swift
//  IBM-CaseManagerCaptureSample-iOS
//
//  Copyright © 2015 IBM. All rights reserved.
//

import Foundation

extension ICMRoleObjectManager {
    /**
    Get all the tasks for a specific role
    
    - returns: `[ICMTask]` with all the tasks for that role
    */
    func getAllTasks() -> [ICMTask] {
        guard let inbaskets = self.role.inbaskets as? [ICMInbasket] else {
            return []
        }
       
        let tasks:[ICMTask] = inbaskets.map { $0.tasks as? [ICMTask] }.filter { $0 != nil }.flatMap { $0! }
        return tasks
    }
}