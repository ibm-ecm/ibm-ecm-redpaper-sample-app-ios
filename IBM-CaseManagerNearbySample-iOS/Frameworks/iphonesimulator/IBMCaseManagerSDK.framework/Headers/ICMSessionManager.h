//
//  ICMSessionApi.h
//  ICMCaseManager
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//
#import <Foundation/Foundation.h>

@class ICMSolutionObjectManager;

@protocol ICMObjectFactory;
@protocol ICMSolution;

/**
 A block of code that will executed after an operation is completed.
 @param success True if the operation is completed successfully.
 @param error An error returned if the operation is not successful.
 */
typedef void (^ICMSessionManagerSessionsCompletionBlock)(BOOL success, NSError *__nullable error);

/** Represents the type of peristance model to be used. */
typedef NS_ENUM(NSUInteger, ICMPersistenceType) {
    /** Persistence Type = Disk  : data is persisted on device storage.*/
    ICMPersistenceTypeDisk = 0,
    /** Persistence Type = Memory : data is persisted in-memory. */
    ICMPersistenceTypeMemory,
};

/**
 This class is the entry point into the IBM Case Manager Mobile SDK. It provides management operations for a session.
 From here you can load solutions for the authenticated session, and create further managers for those solutions.
 @see ICMSolution
 */
@interface ICMSessionManager : NSObject

/** An array containing the list of accessible solutions for the user authenticated in this session. */
@property (nonatomic, strong, readonly, nullable) NSArray *solutions;

/**
 Initialize an object with credentials used to authenticate the session.
 @param baseURL the base URL.
 @param credential the credentials for the connection @see NSURLCredential.
 @param persistenceType the type of persistence @see ICMPersistenceType.
 */
- (nonnull instancetype)initWithBaseURL:(nonnull NSURL *)baseURL
                             credential:(nonnull NSURLCredential *)credential
                        persistenceType:(ICMPersistenceType)persistenceType;

/**
 Asycronously load solutions that can be accessed from the authenticated session.
 @param completion The completion block.
 */
- (void)getSolutionsWithCompletion:(nonnull ICMSessionManagerSessionsCompletionBlock)completion;

/**
 Create a solution object manager for the given solution.
 @return An object manager for the given solution.
 @param solution The solution for which an object manager should be constructed.
 */
- (nonnull ICMSolutionObjectManager *)solutionObjectManagerForSolution:(nonnull id<ICMSolution>)solution;

@end
