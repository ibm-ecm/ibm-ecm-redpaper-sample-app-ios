//
//  ICPDatacapHelper.h
//  IBMCaptureSDK
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ICPCaptureCompletionBlock.h"

@protocol ICPDatacapService;
@class ICPCredential;

typedef void (^ICPDatacapHelperActionBlock)();

/**
    The ICPDatacapHelper class provides miscellaneous networking methods that are specific to IBM Datacap.
    Methods that are more general and might in the future apply to other remote services (for example: IBM Navigator) can be
   found in the ICPServiceClient protcol.
 */
@interface ICPDatacapHelper : NSObject

/**
 *  The remote service to which this helper instance connects.
 */
@property (nonatomic, strong, readonly) id<ICPDatacapService> service;

/**
 *  Creates an instance of the ICPDatacapHelper class with service and credential information.
 *
 *  @param service    The remote service.
 *  @param credential The credentials needed to connect to the remote service.
 *
 *  @return An instance of the ICPDatacapHelper class.
 */
- (instancetype)initWithDatacapService:(id<ICPDatacapService>)service credential:(ICPCredential *)credential;

/**
 Gets a list of applications from the remote service.

 @param completionBlock The completion block.
 */
- (void)getApplicationListWithCompletionBlock:(ICPCaptureCompletionBlock)completionBlock;

/**
 Gets a list station IDs from the remote service.

 @param application The application for which to retrieve station IDs.
 @param completionBlock The completion block.
 */
- (void)getStationListForApplication:(NSString *)application completionBlock:(ICPCaptureCompletionBlock)completionBlock;

/**
 Gets a list of workflows for the application from the remote service.

 @param application The application.
 @param completionBlock The completion block.
 */
- (void)getWorkflowListForApplication:(NSString *)application completionBlock:(ICPCaptureCompletionBlock)completionBlock;

/**
 Gets a list of jobs for the application and workflow from the remote service.

 @param application The application.
 @param workflowIndex The workflow index.
 @param completionBlock The completion block.
 */
- (void)getJobListForApplication:(NSString *)application
                   workflowIndex:(int32_t)workflowIndex
                 completionBlock:(ICPCaptureCompletionBlock)completionBlock;

/**
 Gets a list of DCOs for the application from the remote service.

 @param application The application.
 @param completionBlock The completion block.
 */
- (void)getDCONamesForApplication:(NSString *)application completionBlock:(ICPCaptureCompletionBlock)completionBlock;

/**
 Logoff from the service. This remove the session cookie on success

 @param completionBlock The completion block
 */
- (void)logoffWithCompletionBlock:(ICPCaptureCompletionBlock)completionBlock;

@end
