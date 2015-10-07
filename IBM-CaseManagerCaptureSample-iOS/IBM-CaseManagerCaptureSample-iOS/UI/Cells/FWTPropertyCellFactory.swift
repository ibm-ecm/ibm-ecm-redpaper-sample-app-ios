//
//  FWTPropertyCellFactory.swift
//  IBM-CaseManagerCaptureSample-iOS
//
//  Copyright © 2015 IBM. All rights reserved.
//

import UIKit

protocol FWTPropertyCellFactory {
    func cellForElement(tableView tableView:UITableView!, element:FWTPropertyElement, dateFormatter: NSDateFormatter, valueChangeNotifier:FWTPropertyCellValueChange) -> UITableViewCell
    func emptyCell() -> UITableViewCell
}

extension FWTPropertyCellFactory {
    
    func cellForElement(tableView tableView:UITableView!, element:FWTPropertyElement, dateFormatter: NSDateFormatter, valueChangeNotifier:FWTPropertyCellValueChange) -> UITableViewCell {
        switch element.property.type {
            case .Timestamp:
                return timestampCell(tableView:tableView, element: element, dateFormatter: dateFormatter, valueChangeNotifier: valueChangeNotifier)
            default:
                return propertyCell(tableView:tableView, element: element, valueChangeNotifier: valueChangeNotifier)
        }
    }
    
    func timestampCell(tableView tableView:UITableView!, element:FWTPropertyElement, dateFormatter: NSDateFormatter, valueChangeNotifier:FWTPropertyCellValueChange) -> UITableViewCell {
        let cell = tableView.dequeueReusableCellWithIdentifier("FWTTimestampCell") as! FWTTimestampCell
        cell.configCellWithProperty(element.property, formatter: dateFormatter, valueChangeNotifier: valueChangeNotifier)
        return cell
    }

    func propertyCell(tableView tableView:UITableView!, element:FWTPropertyElement, valueChangeNotifier:FWTPropertyCellValueChange) -> UITableViewCell {
        let cell = tableView.dequeueReusableCellWithIdentifier("FWTPropertyCell") as! FWTPropertyCell
        cell.configCellWithProperty(element.property, valueChangeNotifier: valueChangeNotifier)
        return cell
    }
    
    func emptyCell() -> UITableViewCell {
        return FWTPropertyCell(style: .Default, reuseIdentifier: "EmptyCell")
    }
    
    func heightOfCellForProperty(element:FWTPropertyElement) -> CGFloat {
        switch element.property.type {
            case .Timestamp:
                return CGFloat(261)
            default:
                return CGFloat(70)
        }
    }
}