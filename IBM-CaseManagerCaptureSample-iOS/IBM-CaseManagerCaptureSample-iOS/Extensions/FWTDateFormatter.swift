//
//  FWTDateFormatter.swift
//  IBM-CaseManagerCaptureSample-iOS
//
//  Copyright © 2015 IBM. All rights reserved.
//

import Foundation

extension NSDateFormatter {
    static func defaultIBMFormatter() -> NSDateFormatter {
        let formatter = NSDateFormatter()
        formatter.locale = NSLocale.systemLocale()
        formatter.calendar = NSCalendar(identifier: NSCalendarIdentifierGregorian)
        formatter.calendar?.timeZone = NSTimeZone.defaultTimeZone()
        formatter.dateFormat = "yyyy-MM-dd'T'HH:mm:ss.SSSZ"
        return formatter
    }
}