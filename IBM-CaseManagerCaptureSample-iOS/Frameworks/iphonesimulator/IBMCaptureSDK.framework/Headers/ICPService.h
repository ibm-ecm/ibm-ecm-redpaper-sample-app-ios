//
//  ICPService.h
//  IBMCaptureSDK
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//

@protocol ICPBatchType;

/**
 *  The ICPService protocol represents a remote service.
 */
@protocol ICPService <NSObject>

/** The URL of the remote service. */
@property (nonatomic, strong) NSURL *baseURL;

/** The batch types supported by the service */
@property (nonatomic, strong) NSArray *batchTypes;

/** Allow invalid certificates. This is usually used in development mode where the certificate is self-signed, else connection
 * will be refused */
@property (nonatomic, assign) BOOL allowInvalidCertificates;

/** The username for the remote service */
@property (nonatomic, strong) NSString *username;

/**
 Adds a batch type to the service.
 @param batchType the batch type to be added to the service.
 */
- (void)addBatchType:(id<ICPBatchType>)batchType;

/**
 Removes a batch type from the service.
 @param batchType the batch type to be removed from the service.
 */
- (void)removeBatchType:(id<ICPBatchType>)batchType;

@end
