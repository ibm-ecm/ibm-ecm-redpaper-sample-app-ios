//
//  ICMDocumentObjectManager.h
//  IBMCaseManagerSDK
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ICMDocument;

/**
 A block that will be executed after a document operation is performed.
 @param success True if the operation is completed successfully.
 @param error An error returned if the operation is not successful.
 */
typedef void (^ICMDocumentObjectManagerCompletionBlock)(BOOL success, NSError *__nullable error);

/**
 A block executed while a document is retrieved.
 @param bytesRead number of bytes read since the last time the method was called.
 @param totalBytesRead total bytes read.
 @param totalBytesExpectedToRead total bytes to be read.
 */
typedef void (^ICMDocumentObjectManagerProgressBlock)(NSUInteger bytesRead,
                                                      long long totalBytesRead,
                                                      long long totalBytesExpectedToRead);

/**
 Provides management operations for a document.
 @see ICMDocument
 */
@interface ICMDocumentObjectManager : NSObject

/** The document under management */
@property (nonatomic, strong, readonly, nonnull) id<ICMDocument> document;

/**
 Asyncronously load the document's content.
 @param completion A completion block which will be executed once the document has been downloaded.
 @param progress An optional block which will be executed during download to provide progress updates.
 */
- (void)getDocumentContentWithCompletion:(nonnull ICMDocumentObjectManagerCompletionBlock)completion
                                progress:(__nullable ICMDocumentObjectManagerProgressBlock)progress;

/**
 Asyncronously load a thumbnail for the document.
 @param completion A completion block which will be executed once the document's thumbnail has been completed.
 */
- (void)getDocumentThumbnailWithCompletion:(nonnull ICMDocumentObjectManagerCompletionBlock)completion;

@end
