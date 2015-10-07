//
//  FWTStringRegex.swift
//  IBM-CaseManagerCaptureSample-iOS
//
//  Copyright © 2015 IBM. All rights reserved.
//

import Foundation

extension String {
    
    /**
    An extension on `String` to simplify the search of a substring using regular expression.
    
    - parameter pattern: The regular expresion pattern
    
    - returns: True if the pattern matches a range of the string
    */
    func matchRegex(pattern:String) -> Bool
    {
        guard let _ = self.rangeOfString(pattern, options: .RegularExpressionSearch, range: self.characters.indices, locale: NSLocale.currentLocale()) else {
            return false
        }
        return true
    }
}

infix operator ~= { associativity left precedence 160 }

/**
Infix operator to encapsulate the `String.matchRegex(pattern:String)` method call.

- parameter input: The main `String`
- parameter pattern: Regular expression pattern that will be used on the search

- returns: True if the pattern matches a range of the string
*/
func ~= (input:String, pattern:String) -> Bool {
    return input.matchRegex(pattern)
}