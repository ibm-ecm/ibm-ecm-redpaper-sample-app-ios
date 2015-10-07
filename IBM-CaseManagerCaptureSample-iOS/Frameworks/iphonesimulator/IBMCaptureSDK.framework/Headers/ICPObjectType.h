//
//  ICPObjectType.h
//  IBMCaptureSDK
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

/** ICPObjectType is a protocol that represents the object type. */
@protocol ICPObjectType <NSObject>

/** The type of the object. */
@property (nonatomic, strong) NSString *typeId;

/** An NSArray of available field types. */
@property (nonatomic, strong) NSArray *fieldTypes;

/** An NSDictionary with the values of the properties/variables */
@property (nonatomic, strong) NSDictionary *dcoDictionary;

@end
