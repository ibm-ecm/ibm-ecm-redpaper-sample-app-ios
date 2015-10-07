//
//  ICMInbasket.h
//  ICMCaseManager
//
//  Copyright (c) 2015 Future Workshops Ltd. All rights reserved.
//


/** The ICMInbasket protocol models a in-basket inside a solution */
@protocol ICMInbasket

/** The name of the in-basket. */
@property (nonatomic, strong, readonly) NSString *name;
/** The name of the in-basket presented to the user. */
@property (nonatomic, strong, readonly) NSString *displayName;
/** An authored name of the in-basket. */
@property (nonatomic, strong, readonly) NSString *authoredName;
/** The description of the in-basket. */
@property (nonatomic, strong, readonly) NSString *inbasketDescription;
/** The name of the queue associated with the in-basket. */
@property (nonatomic, strong, readonly) NSString *queueName;
/** The count of the task in the in-basket */
@property (nonatomic, assign, readonly) NSUInteger taskCount;
/** The count of the task in the queue associated with the in-basket */
@property (nonatomic, assign, readonly) NSUInteger queueTaskCount;
/** An array of roles associated with the in-basket */
@property (nonatomic, strong, readonly) NSArray *roles;
/** An array of tasks contained into the in-basket */
@property (nonatomic, strong, readonly) NSArray *tasks;

/** True if the in-basket is a personal  */
@property (nonatomic, assign, readonly) BOOL isInbox;

@end
