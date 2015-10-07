//
//  FWTDocumentTableViewCell.swift
//  IBM-CaseManagerCaptureSample-iOS
//
//  Copyright © 2015 IBM. All rights reserved.
//

import UIKit

class FWTDocumentTableViewCell: UITableViewCell {
    func configCellWithPage(page:ICPPage) {
        textLabel?.text = page.type.typeId.ibm_prettyPrint()
        imageView?.image = page.thumbnailImage
        accessoryType = (page.originalImage != nil ? UITableViewCellAccessoryType.Checkmark : UITableViewCellAccessoryType.None)
    }
}
