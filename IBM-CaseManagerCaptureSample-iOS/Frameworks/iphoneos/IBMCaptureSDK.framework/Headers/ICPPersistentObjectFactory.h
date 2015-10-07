//
//  ICPPersistentObjectFactory.h
//  IBMCaptureSDK
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//

#import <CoreData/CoreData.h>

#import "ICPObjectFactory.h"

/**
 The ICPPersistentObjectFactory manages the lifecycle of persistent ICPObjects. It augments the ICPObjectFactory with a number
 of methods which
 enable persistent operations.

 Note that changes made to objects managed by an ICPPersistentObjectFactory are not saved to the persistent store until the
 ```save``` method is called.
 @see ICPCapture
 @see ICPObjectFactory
 */
@protocol ICPPersistentObjectFactory <ICPObjectFactory>

/**
 Create an NSFetchedResultsController to fetch objects conforming to the given protocol.

 @param protocol Fetch objects conforming to this protocol.
 @param groupedBy Group the results by this property.
 @param predicate Filter the results by this predicate.
 @param sortDescriptor Sort the results by this property.
 @param ascending Indicates whether sort order should be descending or ascending.
 @return The fetch results controller.
 */
- (NSFetchedResultsController *)fetchProtocolObjects:(Protocol *)protocol
                                           groupedBy:(NSString *)groupedBy
                                           predicate:(NSPredicate *)predicate
                                      sortDescriptor:(NSString *)sortDescriptor
                                           ascending:(BOOL)ascending;

/**
 Get objects conforming to the given protocol.

 @param protocol Fetch objects conforming to this protocol.
 @param predicate Filter the results by this predicate.
 @param sortDescriptor Sort the results by this property.
 @param ascending Indicates whether sort order should be descending or ascending.
 @return The results.
 */
- (NSArray *)allProtocolObjects:(Protocol *)protocol
                  withPredicate:(NSPredicate *)predicate
                 sortDescriptor:(NSString *)sortDescriptor
                      ascending:(BOOL)ascending;

/**
 Delete the given object from the persistent store.

 @param object The object to delete from the persistent store.
 */
- (void)deleteObject:(id)object;

/**
 Save new objects, updated objects and deleted objects to the persistent store.
 */
- (void)save;

@end
