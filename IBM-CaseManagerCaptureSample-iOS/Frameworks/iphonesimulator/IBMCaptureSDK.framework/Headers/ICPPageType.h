//
//  ICPPageType.h
//  IBMCaptureSDK
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//

#import "ICPObjectType.h"

/** The ICPPageType protocol represents the page type. */
@protocol ICPPageType <ICPObjectType>

/** This the reference height returned in the DCO that was used to determine the field zones. It can be used to recalculate field zones based on actual image size of the page captured */
@property (nonatomic, assign, readonly) NSNumber *referencePageHeight;

/** This the reference width returned in the DCO that was used to determine the field zones. It can be used to recalculate field zones based on actual image size of the page captured */
@property (nonatomic, assign, readonly) NSNumber *referencePageWidth;


@end
