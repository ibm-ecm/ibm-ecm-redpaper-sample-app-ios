//
//  ICPServiceClient.h
//  IBMCaptureSDK
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//

/**
 A block used by networking methods to indicate completion.

 @param success Indicates whether the operation was succesful.
 @param results Results return from the operation.
 @param error The error returned.
 */
typedef void (^ICPServiceClientCompletionBlock)(BOOL success, id results, NSError *error);

/**
 A block used by networking operations to report progress.

 @param progress The estimated progress of the upload from 0-1.
 @param uploadingObject The current object being uploaded.
 */
typedef void (^ICPServiceClientProgressBlock)(float progress, id uploadingObject);

@protocol ICPObjectFactory
, ICPService, ICPBatch;

/**
 *  The ICPServiceClient protocol provides an interface to query, monitor, and upload to remote services.
 */
@protocol ICPServiceClient <NSObject>

/**
 *  The service the client will connects to
 */
@property (nonatomic, strong, readonly) id<ICPService> service;

/**
 Get batch type from the remote service.

 @param completionBlock The completion block.
 */
- (void)getBatchTypeWithCompletionBlock:(ICPServiceClientCompletionBlock)completionBlock;

/**
 Monitor batches on the remote service.

 @param completionBlock The completion block.
 */
- (void)monitorBatchesWithCompletionBlock:(ICPServiceClientCompletionBlock)completionBlock;

/**
 Upload a batch to the remote service

 @param batch The batch to upload to the remote service.
 @param progressBlock The progress block.
 @param completionBlock The completion block.
 */
- (void)uploadBatch:(id<ICPBatch>)batch
      progressBlock:(ICPServiceClientProgressBlock)progressBlock
    completionBlock:(ICPServiceClientCompletionBlock)completionBlock;

@end
