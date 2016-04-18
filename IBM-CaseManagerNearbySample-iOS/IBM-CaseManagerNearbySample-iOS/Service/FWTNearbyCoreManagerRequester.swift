//
//  FWTNearbyCoreManagerRequester.swift
//  IBM-CaseManagerNearbySample-iOS
//
//  Copyright © 2015 IBM. All rights reserved.
//

import Foundation

// MARK: Configuration of the request

/**
Profile (solution and role) configuration for searches and loads
*/
struct FWTProfileConfiguration
{
    let solutionPrefix:String
    let role:String
    
    init(solutionPrefix:String, role:String) {
        self.solutionPrefix = solutionPrefix
        self.role = role
    }
}

// MARK: Requester of the user nearby tasks

struct FWTNearbyCoreManagerRequester : FWTCoreManagerRequester {
    
    typealias UserNearbyTasksCompletion = (success: Bool, roleManager: ICMRoleObjectManager?, tasks:[ICMTask])->Void
    
    let profile:FWTProfileConfiguration
    var loading = false
    
    init(profile:FWTProfileConfiguration) {
        self.profile = profile
    }
    
    /**
    Asynchronously goes through all the steps needed to get nearby tasks, based on the profile configuration. The step are:
    - Get the solution
    - Get the specific role
    - Get the neaby tasks for that role
    
    - parameter sessionManager: Core Manager session
    - parameter coordinate: Coordinate used to search the tasks
    - parameter radius: Radius of the search
    - parameter callback: The completion block to execute when the operation is completed
    */
    func getUserNearbyTasks(sessionManager:ICMSessionManager, coordinate:CLLocationCoordinate2D, radius:Double, callback:UserNearbyTasksCompletion) {
        getSolutionManagers(sessionManager, completion: {(success , solutions) in
            guard success, let solution = solutions.filter({ $0.solution.prefix == self.profile.solutionPrefix }).first else {
                callback(success: false, roleManager: nil, tasks: [])
                return
            }
            
            self.getRoleManagers(solution, completion: { (success, roles) -> Void in
                guard success, let userRole = roles.filter({ $0.role.name == self.profile.role }).first else {
                    callback(success: false, roleManager: nil, tasks: [])
                    return
                }
                
                
                
                userRole.getNearbyTasksAtCoordinate(coordinate, radius: radius, withCompletion: { success, tasks, error in
                    if let tasks = tasks {
                        callback(success: success, roleManager: userRole, tasks: tasks)
                    } else {
                        callback(success: false, roleManager: userRole, tasks: [])
                    }
                })
            })
        })
    }
}