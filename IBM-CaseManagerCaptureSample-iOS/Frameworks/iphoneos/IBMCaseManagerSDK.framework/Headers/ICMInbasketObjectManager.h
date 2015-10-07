//
//  ICMInbasketObjectManager.h
//  ICMCaseManager
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//
#import <Foundation/Foundation.h>

@protocol ICMInbasket;
@protocol ICMTask;
@class ICMTaskObjectManager;

/**
 A block that will be executed after an in-basket operation is performed.
 @param success True if the operation is completed successfully.
 @param error An error returned if the operation is not successful.
 */
typedef void (^ICMInbasketManagerCompletionBlock)(BOOL success, NSError *__nullable error);

/**
 Provides management operations for an in-basket.
 @see ICMInbasket
 */
@interface ICMInbasketObjectManager : NSObject

/** The in-basket under management */
@property (nonatomic, strong, readonly, nonnull) id<ICMInbasket> inbasket;

/**
 Asyncronously load details for the in-basket.
 @params completion A completion block which will be executed once the inbasket's details have been loaded.
 */
- (void)getInbasketDetailsWithCompletion:(__nonnull ICMInbasketManagerCompletionBlock)completion;

/**
 Create an task object manager for a given task.
 @return The task object manager
 @param task The task the object manager will manage.
 */
- (nonnull ICMTaskObjectManager *)taskObjectManagerForTask:(nonnull id<ICMTask>)task;

@end
