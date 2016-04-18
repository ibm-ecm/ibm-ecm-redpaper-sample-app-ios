//
//  FWTTask.swift
//  IBM-CaseManagerCaptureSample-iOS
//
//  Copyright © 2015 IBM. All rights reserved.
//

import Foundation
import IBMCaseManagerSDK

extension SequenceType where Generator.Element : ICMTask {
    func filterByRegex(pattern:String) -> [Generator.Element] {
        let filtered = self.filter { $0.stepName.matchRegex(pattern) }
        return filtered
    }
}