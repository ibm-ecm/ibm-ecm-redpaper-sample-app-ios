//
//  ICPBatch.h
//  IBMCaptureSDK
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//

#import "ICPObject.h"

@protocol ICPDocument;

/**
 The ICPBatch protocol contains a number of documents.
 It extends ICPObject so it may also contain fields and has a type.
 @see ICPObject

 An ICPBatch instance can be uploaded to a specified remote service using the ICPServiceClient object.
 @see ICPServiceClient -uploadBatch:progressBlock:completionBlock.
 */
@protocol ICPBatch <ICPObject>

/** A reference id for the batch once it has been uploaded to a remote service. */
@property (nonatomic, strong) NSString *remoteId;

/** The status of the ICPBatch on the remote service. For example: "Processing". */
@property (nonatomic, strong) NSString *remoteStatus;

/** A date representing the date and time the batch was created by the SDK. */
@property (nonatomic, strong) NSDate *creationDate;

/** An NSArray containing documents inside the batch. */
@property (nonatomic, strong) NSArray *documents;

/**
 Adds a document to the batch.
 @param document The document to add to the batch.
 */
- (void)addDocument:(id<ICPDocument>)document;

/**
 Removes a document from the batch.
 @param document The document to remove from the batch.
 */
- (void)removeDocument:(id<ICPDocument>)document;

@end
