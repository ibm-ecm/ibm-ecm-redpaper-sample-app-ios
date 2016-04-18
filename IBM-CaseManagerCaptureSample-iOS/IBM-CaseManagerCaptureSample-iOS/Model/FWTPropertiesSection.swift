//
//  FWTPropertiesSection.swift
//  IBM-CaseManagerCaptureSample-iOS
//
//  Copyright © 2015 IBM. All rights reserved.
//

import Foundation
import IBMCaseManagerSDK

struct FWTPropertiesSection {
    var elements:[FWTPropertyElement]
    let title:String!
    
    init(elements:[FWTPropertyElement], title:String!) {
        self.elements = elements
        self.title = title
    }
}

extension ICMTaskPropertiesLayout {
  func section()->FWTPropertiesSection {
    let elements : [FWTPropertyElement] = properties.map {
      FWTPropertyElement(property : $0)
    }
    return FWTPropertiesSection(elements : elements, title : title)
  }
}