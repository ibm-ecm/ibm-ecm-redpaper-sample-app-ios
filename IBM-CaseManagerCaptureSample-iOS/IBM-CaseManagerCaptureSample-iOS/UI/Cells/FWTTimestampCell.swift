//
//  FWTTimestampCell.swift
//  IBM-CaseManagerCaptureSample-iOS
//
//  Copyright © 2015 IBM. All rights reserved.
//

import UIKit

class FWTTimestampCell : FWTPropertyCell
{
    override var value:NSObject! {
        get {
            guard let date = date, let dateFormatter = formatter else {
                return nil
            }
            
            return dateFormatter.stringFromDate(date)
        }
    }
    
    var date:NSDate? {
        set {
            if let date = newValue {
                datePicker?.setDate(date, animated:true)
            }
        }
        get {
            return datePicker?.date
        }
    }
    
    var formatter:NSDateFormatter?
    
    @IBOutlet weak var datePicker:UIDatePicker?
    
    func configCellWithProperty(property:ICMProperty, formatter:NSDateFormatter, valueChangeNotifier:FWTPropertyCellValueChange) -> Void {
        configCellWithProperty(property, valueChangeNotifier: valueChangeNotifier)
        self.formatter = formatter
        self.date = formatter.dateFromString("\(property.value)")
    }
    
    @IBAction func datePickerChangedValue(sender:UIDatePicker) {
        valueChangeNotifier?(cell: self, value: value)
    }
}