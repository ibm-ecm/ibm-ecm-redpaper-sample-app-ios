//
//  FWTCoreManagerRequester.swift
//  IBM-CaseManagerNearbySample-iOS
//
//  Copyright © 2015 IBM. All rights reserved.
//

import Foundation

typealias SolutionManagerCompletion = (Bool, [ICMSolutionObjectManager]) -> Void
typealias RoleManagerCompletion = (Bool, [ICMRoleObjectManager]) -> Void
typealias TaskDetailCompletion = (Bool, ICMTaskObjectManager?) -> Void

// MARK: Methods to get the object managers that will be used to get the tasks

protocol FWTCoreManagerRequester {
    func getSolutionManagers(sessionManager:ICMSessionManager, completion:SolutionManagerCompletion)
    func getRoleManagers(solutionManager:ICMSolutionObjectManager, completion:RoleManagerCompletion)
    func getTaskDetails(roleManager:ICMRoleObjectManager, task:ICMTask, completion:TaskDetailCompletion)
}

/**
Collection of methods to asyncronously get the object managers of the session
*/
extension FWTCoreManagerRequester {
    
    /**
    Asyncronously get all the solutions related to a session and map the response to an object manager
    
    - parameter sessionManager: The session that will be used to look for solutions
    - parameter completion: The block that will be called once that the operations is finished.
    */
    func getSolutionManagers(sessionManager:ICMSessionManager, completion:SolutionManagerCompletion) {
        sessionManager.getSolutionsWithCompletion({ [weak sessionManager] (success, error) in
            if  success, let sessionManager = sessionManager, let solutions = sessionManager.solutions as? [ICMSolution] {
                let managers = solutions.map{ sessionManager.solutionObjectManagerForSolution($0) }
                completion(true, managers)
            } else {
                completion(false, [])
            }
        })
    }
    
    /**
    Given a specific solution, Asyncronously get the roles informations.
    
    - parameter solutionManager: The manager of the solution
    - parameter completion: The block that will be called once that the operation is finished.
    */
    func getRoleManagers(solutionManager:ICMSolutionObjectManager, completion:RoleManagerCompletion) {
        solutionManager.getSolutionDetailsWithCompletion { (success, error) in
            if success, let roles = solutionManager.solution.roles as? [ICMRole] {
                let managers = roles.map { solutionManager.roleObjectManagerForRole($0) }
                completion(true, managers)
            } else {
                completion(false, [])
            }
        }
    }
    
    /**
    Get the details of a specific task
    
    - parameter roleManager: Manager of the role of which the task belongs
    - parameter task: Task that will request for details
    - parameter completion: The block that will be called once that the operation is finished.
    */
    func getTaskDetails(roleManager:ICMRoleObjectManager, task:ICMTask, completion:TaskDetailCompletion) {
        guard let inbasket = task.inbaskets.first as? ICMInbasket else {
            completion(false, nil)
            return
        }
        let inbasketManager = roleManager.inbasketObjectManagerForInbasket(inbasket)
        let taskManager = inbasketManager.taskObjectManagerForTask(task)
        taskManager.getTaskDetailWithCompletion { (success, error) -> Void in
            completion(success, taskManager)
        }
    }
}