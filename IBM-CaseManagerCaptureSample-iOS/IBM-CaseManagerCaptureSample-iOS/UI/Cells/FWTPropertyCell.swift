//
//  FWTPropertyCell.swift
//  IBM-CaseManagerCaptureSample-iOS
//
//  Copyright © 2015 IBM. All rights reserved.
//

import UIKit
import IBMCaseManagerSDK

typealias FWTPropertyCellValueChange = (cell:UITableViewCell, value:NSObject!) -> Void

class FWTPropertyCell : UITableViewCell, UITextFieldDelegate
{
    @IBOutlet weak var titleLabel:UILabel?
    @IBOutlet weak var valueFiled:UITextField? {
        didSet {
            valueFiled?.delegate = self
        }
    }
    
    var value:NSObject! {
        get {
            guard let property = property, let string = valueFiled?.text where string.characters.count > 0 else {
                return nil
            }
            
            switch property.type {
            case .String:
                return string
            case .Double:
                return Double(string)
            case .Count:
                return Int(string)
            case .Boolean:
                return NSString(string: string).boolValue
            default:
                return nil
            }
        }
    }
    
    var property:ICMProperty? {
        didSet {
            if let property = property {
                titleLabel?.text = property.displayName + (property.required ? " (required)" : "")
                if let value = property.value {
                    valueFiled?.text = "\(value)"
                }
                valueFiled?.enabled = !property.readOnly
            }
        }
    }

    var valueChangeNotifier:FWTPropertyCellValueChange?
    
    func configCellWithProperty(property:ICMProperty, valueChangeNotifier:FWTPropertyCellValueChange) -> Void {
        self.property = property
        self.valueChangeNotifier = valueChangeNotifier
    }
    
    func textFieldShouldReturn(textField: UITextField) -> Bool {
        textField.resignFirstResponder()
        return true
    }
    
    func textFieldShouldEndEditing(textField: UITextField) -> Bool {
        self.valueChangeNotifier?(cell: self, value: value)
        return true
    }
}