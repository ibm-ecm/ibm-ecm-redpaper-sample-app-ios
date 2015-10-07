//
//  ICMSolutionsApi.h
//  ICMCaseManager
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//
#import <Foundation/Foundation.h>

@protocol ICMSolution;
@protocol ICMRole;


@class ICMRoleObjectManager;

/**
 A block that will be executed after a solution operation is performed.
 @param success True if the operation is completed successfully.
 @param error An error returned if the operation is not successful.
 */
typedef void (^ICMSolutionManagerCompletionBlock)(BOOL success, NSError *__nullable error);
typedef void (^ICMSolutionManagerQueryUsersCompletionBlock)(BOOL success, NSError *__nullable error, NSArray *__nonnull users);

/**
 Provides management operations for a solution.
 @see ICMSolution
 */
@interface ICMSolutionObjectManager : NSObject

/** The solution under management */
@property (nonatomic, strong, readonly, nonnull) id<ICMSolution> solution;

/**
 Asyncronously load details for the solution.
 @params completion A completion block which will be executed once the solution's details have been loaded.
 */
- (void)getSolutionDetailsWithCompletion:(__nonnull ICMSolutionManagerCompletionBlock)completion;

/**
 Asyncronously load users for roles inside the solution
 @params completion A completion block which will be executed once the solution's users have been loaded.
 */
- (void)getUsersForRolesWithCompletion:(__nonnull ICMSolutionManagerCompletionBlock)completion;

- (void)getUsersForRolesWithQuery:( NSString * _Nonnull )query andCompletion:( __nonnull ICMSolutionManagerQueryUsersCompletionBlock)completion;

/**
 Create a role object manager for the given role.
 @return An object manager for the given role.
 @param role The role for which an object manager should be constructed.
 */
- (nonnull ICMRoleObjectManager *)roleObjectManagerForRole:(nonnull id<ICMRole>)role;

@end
