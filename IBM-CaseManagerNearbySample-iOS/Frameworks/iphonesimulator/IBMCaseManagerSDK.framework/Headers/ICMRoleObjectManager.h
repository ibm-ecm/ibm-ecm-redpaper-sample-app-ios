//
//  ICMRoleObjectManager.h
//  ICMCaseManager
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@protocol ICMRole;
@protocol ICMTask;
@protocol ICMInbasket;
@class ICMInbasketObjectManager;

/**
 A block that will be executed after a role operation is performed.
 @param success True if the operation is completed successfully.
 @param taks    Array with tasks near by
 @param error An error returned if the operation is not successful.
 */
typedef void (^ICMRoleObjectManagerNearbyCompletionBlock)(BOOL success, NSArray *__nullable tasks, NSError *__nullable error);

/** A measurement in meters */
typedef double ICMRoleObjectManagerRadiusMeters;

/**
 Provides management operations for a role.
 @see ICMRole
 */
@interface ICMRoleObjectManager : NSObject

/** The role under management */
@property (nonatomic, strong, readonly, nonnull) id<ICMRole> role;

/**
 Asyncronously get nearby tasks, executing the provided completition block executed after tasks are loaded.
 @param coordinate The center point to load tasks from
 @param radius The radius to load tasks within
 @param completion The completion block to execute once tasks have been loaded.
 */
- (void)getNearbyTasksAtCoordinate:(CLLocationCoordinate2D)coordinate
                            radius:(ICMRoleObjectManagerRadiusMeters)radius
                    withCompletion:(__nonnull ICMRoleObjectManagerNearbyCompletionBlock)completion;
/**
 Create an in-basket object manager for a given in-basket.
 @return The in-basket object manager
 @param inbasket the ICMInbasket the object manager is required for.
 */
- (nonnull ICMInbasketObjectManager *)inbasketObjectManagerForInbasket:(nonnull id<ICMInbasket>)inbasket;

@end
