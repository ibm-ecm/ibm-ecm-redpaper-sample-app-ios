//
//  ICMCaseManager.h
//  ICMCaseManager
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol ICMCase;
@protocol ICMDocument;
@class ICMDocumentObjectManager;

/**
 A block that will be executed after a case operation is performed.
 @param success True if the operation is completed successfully.
 @param error An error returned if the operation is not successful.
 */
typedef void (^ICMCaseObjectManagerCompletionBlock)(BOOL success, NSError *__nullable error);

/**
 A block executed while an upload operation to a document is in progress.
 @param bytesWritten number of bytes uploaded since the last time the method was called
 @param totalBytesWritten total number of bytes uploaded.
 @param totalBytesExpectedToWrite total number of bytes to upload.
 */
typedef void (^ICMCaseObjectManagerUploadProgressBlock)(NSUInteger bytesWritten,
                                                        long long totalBytesWritten,
                                                        long long totalBytesExpectedToWrite);
/**
 Provides management operations for a case.
 @see ICMCase
 */
@interface ICMCaseObjectManager : NSObject

/** The case under management */
@property (nonatomic, strong, readonly, nonnull) id<ICMCase> caseObject;

/**
 Asyncronously load details for the case.
 @params completion A completion block which will be executed once the case details have been loaded.
 */
- (void)getCaseDetailsWithCompletion:(__nonnull ICMCaseObjectManagerCompletionBlock)completion;

/**
 Asyncronously add a document to a case.
 @param title The title.
 @param fileName The name of the remote file.
 @param data The raw data of the document.
 @param mimeType The mime type.
 @param progress A block executed while the document is being uploaded.
 @param completion A block executed once the upload has completed.
 */
- (void)addDocumentWithTitle:(nonnull NSString *)title
                    fileName:(nonnull NSString *)fileName
                        data:(nonnull NSData *)data
                    mimeType:(nonnull NSString *)mimeType
                    progress:(__nullable ICMCaseObjectManagerUploadProgressBlock)progress
                  completion:(__nonnull ICMCaseObjectManagerCompletionBlock)completion;


/**
 Create a document object manager for a given document.
 @return The document object manager
 @param task The document the object manager will manage.
 */
- (nonnull ICMDocumentObjectManager *)documentObjectManagerForDocument:(nonnull id<ICMDocument>)document;

@end
