//
//  ICPBatchType.h
//  IBMCaptureSDK
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//

#import "ICPObjectType.h"

@protocol ICPService;

/** A protocol that represents the batch type. */
@protocol ICPBatchType <ICPObjectType>

/** The service from which this profile was created */
@property (nonatomic, strong) id<ICPService> service;

/** An array of documentTypes avalible for this batch type. */
@property (nonatomic, strong) NSArray *documentTypes;

@end
