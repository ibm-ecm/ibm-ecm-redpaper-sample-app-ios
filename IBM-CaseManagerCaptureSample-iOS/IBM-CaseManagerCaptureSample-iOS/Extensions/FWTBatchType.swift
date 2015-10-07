//
//  FWTBatchType.swift
//  IBM-CaseManagerCaptureSample-iOS
//
//  Copyright © 2015 IBM. All rights reserved.
//

import Foundation

extension String {
    func ibm_prettyPrint() -> String {
        return self.stringByReplacingOccurrencesOfString("_", withString: " ")
    }
}

extension ICPBatchType {
    func updateVariable(key:String, value:AnyObject!) {
        var variables = dcoDictionary
        variables[key] = value
        dcoDictionary = variables
    }
}