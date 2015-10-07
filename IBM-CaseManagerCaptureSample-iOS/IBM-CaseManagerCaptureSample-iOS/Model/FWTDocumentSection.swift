//
//  FWTDocumentSection.swift
//  IBM-CaseManagerCaptureSample-iOS
//
//  Copyright © 2015 IBM. All rights reserved.
//

import Foundation

struct FWTDocumentSection {
    let document:ICPDocument
    var pages:[ICPPage]
    
    var title:String {
        get {
            return document.type.typeId.ibm_prettyPrint()
        }
    }
    
    init(document:ICPDocument, pages:[ICPPage]) {
        self.document = document
        self.pages = pages
    }
    
    mutating func updateImages(original original:UIImage?, modified:UIImage?, index:Int) {
        let page = pages[index]
        page.originalImage = original
        page.modifiedImage = modified
        page.status = .Queued
        pages[index] = page
    }
    
    func pagesComplete() -> Int {
        return pages.reduce(0) {
            return $0 + ($1.originalImage != nil ? 1 : 0)
        }
    }
}