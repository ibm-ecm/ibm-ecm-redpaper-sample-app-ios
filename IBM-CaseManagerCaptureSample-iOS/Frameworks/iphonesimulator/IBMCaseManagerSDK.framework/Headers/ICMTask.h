//
//  ICMTask.h
//  ICMCaseManager
//
//  Copyright (c) 2015 Future Workshops Ltd. All rights reserved.
//

/**
 The ICMTaskState constant is an enumeration representing the task state.
 */
typedef NS_ENUM(NSUInteger, ICMTaskState) {
    /** State : Waiting All */
    ICMTaskStateWaitingAll = 0,
    /** State : Waiting Precondition */
    ICMTaskStateWaitingPrecondition = 1,
    /** State : Waiting Predecessors */
    ICMTaskStateWaitingPredecessors = 2,
    /** State : Ready */
    ICMTaskStateReady = 3,
    /** State : Working */
    ICMTaskStateWorking = 4,
    /** State : Complete */
    ICMTaskStateComplete = 5,
    /** State : Failed */
    ICMTaskStateFailed = 6,
    ICMTaskStateCount
};

/**
 The ICMTaskOverdueStatus constant is an enumeration representing the task overdue state.
 */
typedef NS_ENUM(NSUInteger, ICMTaskOverdueStatus) {
    /** State : Not Overdue */
    ICMTaskOverdueStatusNotOverdue = 0,
    /** State : Past Reminder Date */
    ICMTaskOverdueStatusPastReminderDate = 1,
    /** State : Past Deadline */
    ICMTaskOverdueStatusPastDeadline = 2,
    ICMTaskOverdueStatusCount
};


@protocol ICMCaseType, ICMCase, ICMTaskType, ICMProperty;

/** The ICMTask protocol models a task in Case Manager. */
@protocol ICMTask

/** The ID of the task. */
@property (nonatomic, strong, readonly) NSString *taskId;
/** The subject of the task. */
@property (nonatomic, strong, readonly) NSString *subject;
/** The step name. */
@property (nonatomic, strong, readonly) NSString *stepName;
/** The step description. */
@property (nonatomic, strong, readonly) NSString *stepDescription;
/** The default response for the task. */
@property (nonatomic, strong, readonly) NSString *defaultResponse;
/** The participant name for the task. */
@property (nonatomic, strong, readonly) NSString *participantName;
/** The task originator. */
@property (nonatomic, strong, readonly) NSString *originator;
/** The user locking the task. */
@property (nonatomic, strong, readonly) NSString *lockedUser;
/** A comment for the task. */
@property (nonatomic, strong, readonly) NSString *comment;
/** The date the task has been received. */
@property (nonatomic, strong, readonly) NSDate *dateReceived;
/** The date the task has started. */
@property (nonatomic, strong, readonly) NSDate *dateStarted;
/** The date the task has been modified. */
@property (nonatomic, strong, readonly) NSDate *dateModified;
/** The date the task has been created. */
@property (nonatomic, strong, readonly) NSDate *dateCreated;
/** The date the task has been completed. */
@property (nonatomic, strong, readonly) NSDate *dateCompleted;
/** The task deadline. */
@property (nonatomic, strong, readonly) NSDate *deadline;
/** The task reminder date. */
@property (nonatomic, strong, readonly) NSDate *reminderDate;
/** True if the task can be reassigned. */
@property (nonatomic, assign, readonly) BOOL canReassign;
/** The overdue status of the task. */
@property (nonatomic, assign, readonly) ICMTaskOverdueStatus overdueStatus;
/** The state of the task. */
@property (nonatomic, assign, readonly) ICMTaskState state;
/** The case the task belong to. @see ICMCase */
@property (nonatomic, strong, readonly) id<ICMCase> caseInstance;
/** The type of the task. @see ICMTaskType */
@property (nonatomic, strong, readonly) id<ICMTaskType> taskType;
/** The list of in-baskets where the task is contained */
@property (nonatomic, strong, readonly) NSArray *inbaskets;
/** The properties of the task */
@property (nonatomic, strong, readonly) NSArray *properties;
/** The responses available for the task */
@property (nonatomic, strong, readonly) NSArray *responses;
/** The layout that the properties shoulf be displayed @see ICMProperty */
@property (nonatomic, strong, readonly) NSArray *layout;

@end
