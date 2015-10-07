//
//  FWTCaseDetailsViewControllerDataSource.swift
//  IBM-CaseManagerCaptureSample-iOS
//
//  Copyright © 2015 IBM. All rights reserved.
//

import Foundation

extension FWTCaseDetailsViewController : FWTPropertyCellFactory {
    
    func updateElement(indexPath indexPath:NSIndexPath, value:NSObject!)
    {
        var element = layout[indexPath.section].elements[indexPath.row]
        element.value = value
        layout[indexPath.section].elements[indexPath.row] = element
    }
    
    // MARK: UITableViewDataSource methods
    override func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return layout[section].elements.count
    }
    
    override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        let element = layout[indexPath.section].elements[indexPath.row]
        return cellForElement(tableView: tableView, element: element, dateFormatter: dateFormatter, valueChangeNotifier: { [weak tableView, weak self] (cell, value) -> Void in
            if let tableView = tableView, let cellIndexPath = tableView.indexPathForCell(cell) {
                self?.updateElement(indexPath: cellIndexPath, value: value)
            }
        })
    }
    
    override func numberOfSectionsInTableView(tableView: UITableView) -> Int {
        return layout.count
    }
    
    override func tableView(tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        let layoutItem = layout[section]
        return layoutItem.title
    }
    
    override func tableView(tableView: UITableView, heightForRowAtIndexPath indexPath: NSIndexPath) -> CGFloat {
        return heightOfCellForProperty(layout[indexPath.section].elements[indexPath.row])
    }
    
    override func tableView(tableView: UITableView, heightForFooterInSection section: Int) -> CGFloat {
        return CGFloat(5.0)
    }
    override func tableView(tableView: UITableView, viewForFooterInSection section: Int) -> UIView? {
        return UIView(frame: CGRectMake(0, 0, self.view.bounds.width, 5))
    }
}