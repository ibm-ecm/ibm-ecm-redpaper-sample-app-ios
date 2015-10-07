//
//  ICMTaskManager.h
//  ICMCaseManager
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ICMTask
, ICMUser, ICMCase;

@class ICMCaseObjectManager;

/**
 A block that will be executed after a task operation is performed.
 @param success True if the operation is completed successfully.
 @param error An error returned if the operation is not successful.
 */
typedef void (^ICMTaskManagerCompletionBlock)(BOOL success, NSError *__nullable error);


/**
 Provides management operations for a task.
 @see ICMTask
 */
@interface ICMTaskObjectManager : NSObject

/** The task under management */
@property (nonatomic, strong, readonly, nonnull) id<ICMTask> task;

/**
 Asyncronously load details for the task.
 @params completion A completion block which will be executed once the task's details have been loaded.
 */
- (void)getTaskDetailWithCompletion:(__nonnull ICMTaskManagerCompletionBlock)completion;

/**
 Asyncronously lock the task.
 @params completion A completion block which will be executed once the task has been locked.
 */
- (void)lockTaskWithCompletion:(__nonnull ICMTaskManagerCompletionBlock)completion;

/**
 Asyncronously unlock the task.
 @params completion A completion block which will be executed once the task has been unlocked.
 */
- (void)unlockTaskWithCompletion:(__nonnull ICMTaskManagerCompletionBlock)completion;

/**
 Asyncronously update the task with a set properties.
 @param properties The updated set of properties.
 @param completion A completion block which will be executed once the task has been updated.
 */
- (void)updateTaskWithProperties:(nonnull NSDictionary *)properties
                      completion:(__nonnull ICMTaskManagerCompletionBlock)completion;

/**
 Asyncronously complete the task with a response and an optional set properties.
 @param response The response.
 @param properties The updated set of properties.
 @param completion A completion block which will be executed once the task has been updated.
 */
- (void)completeTaskWithResponse:(nonnull NSString *)response
                      properties:(nullable NSDictionary *)properties
                      completion:(__nonnull ICMTaskManagerCompletionBlock)completion;

/**
 Asyncronously reassign the task to another user.
 @param user The user to reassign the task to.
 @param completion A completion block which will be executed once the task has been updated.
 */
- (void)reassignTaskToUser:(nonnull id<ICMUser>)user completion:(__nonnull ICMTaskManagerCompletionBlock)completion;

/**
 Create an case object manager for a given case.
 @return The case object manager
 @param task The case the object manager will manage.
 */
- (nonnull ICMCaseObjectManager *)caseObjectManagerForCase:(nonnull id<ICMCase>)caseObject;

@end
