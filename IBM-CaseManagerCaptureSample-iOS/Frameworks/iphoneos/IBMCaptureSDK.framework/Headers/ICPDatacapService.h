//
//  ICPDatacapService.h
//  IBMCaptureSDK
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//

#import "ICPService.h"

/**
 The ICPDatacapService protcol contains the information required to connect to a remote IBM Datacap application.
 It is used by the ICPServiceClient and the ICPDatacapHelper.

 @see ICPServiceClient
 @see ICPDatacapHelper
 */
@protocol ICPDatacapService <ICPService>

/** The ID of the application */
@property (nonatomic, strong) NSString *applicationId;

/** The ID of the workflow */
@property (nonatomic, strong) NSString *workflowId;

/** The ID of the job */
@property (nonatomic, strong) NSString *jobId;

/** The DCO name */
@property (nonatomic, strong) NSString *dcoName;

/** The Station ID name */
@property (nonatomic, strong) NSString *stationId;

@end
