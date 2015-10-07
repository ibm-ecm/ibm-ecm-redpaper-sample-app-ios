//
//  ICPDocumentType.h
//  IBMCaptureSDK
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//

#import "ICPObjectType.h"

/** ICPDocumentType is a protocol for the document type. */
@protocol ICPDocumentType <ICPObjectType>

/** An array of pageTypes avalaible for this document type. */
@property (nonatomic, strong) NSArray *pageTypes;

@end
