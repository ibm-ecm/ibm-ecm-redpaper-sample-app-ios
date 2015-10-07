//
//  ICPPage+Private.h
//  IBMCapture
//
//  Created on 15/04/2015.
//  Copyright (c) 2015 Future Workshops Ltd. All rights reserved.
//

#import <IBMCaptureSDK/ICPPage.h>
#import <IBMCaptureSDK/ICPObject+Private.h>

@protocol Private_ICPPage <ICPPage, Private_ICPObject>

@property (nonatomic, strong) NSString *remoteId;

/** Implement confidence rule for page based on its fields confidence */
@property (nonatomic, assign, readonly) BOOL isConfident;

@end
