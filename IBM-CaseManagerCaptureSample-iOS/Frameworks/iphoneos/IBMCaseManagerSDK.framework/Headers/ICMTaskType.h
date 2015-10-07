//
//  ICMTaskType.h
//  ICMCaseManager
//
//  Copyright (c) 2015 Future Workshops Ltd. All rights reserved.
//

@protocol ICMCaseType;

/** The ICMTaskType describes a task type. */
@protocol ICMTaskType

/** The ID of the task type. */
@property (nonatomic, strong, readonly) NSString *typeId;
/** The name of the task type. */
@property (nonatomic, strong, readonly) NSString *name;
/** The name of the task type displayed to the user. */
@property (nonatomic, strong, readonly) NSString *displayName;
/** The description of the task type. */
@property (nonatomic, strong, readonly) NSString *typeDescription;
/** True if the task type is hidden. */
@property (nonatomic, assign, readonly) BOOL isHidden;
/** True if the task type is task container. */
@property (nonatomic, assign, readonly) BOOL isContainer;
/** True if the task type requires creation rights. */
@property (nonatomic, assign, readonly) BOOL hasCreationRights;
/** True if launch information is required to create an instance of this discretionary task type. */
@property (nonatomic, assign, readonly) BOOL isLaunchInfoRequired;
/** The type of the case where the task type belong to. */
@property (nonatomic, strong, readonly) id<ICMCaseType> caseType;

/** The list of tasks for the task type. */
@property (nonatomic, strong, readonly) NSArray *tasks;

@end
