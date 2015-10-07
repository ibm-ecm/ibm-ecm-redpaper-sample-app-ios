//
//  ICPObject.h
//  IBMCaptureSDK
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//

#import "ICPStatus.h"

@protocol ICPObjectType
, ICPField;

/**
 The ICPObject protocol is the root object class for all IBM Capture domain classes.
 */
@protocol ICPObject <NSObject>

/** The type of this object, usually defined by the remote service */
@property (nonatomic, strong) id<ICPObjectType> type;

/** The upload status of this object */
@property (nonatomic, assign) ICPStatus status;

/** An NSArray of ICPField objects belonging to this ICPObject instance */
@property (nonatomic, strong) NSArray *fields;

/**
 Add a field to this object
 @param field The field to add
 */
- (void)addField:(id<ICPField>)field;

/**
 Remove a field from this object
 @param field The field to remove
 */
- (void)removeField:(id<ICPField>)field;

@end
