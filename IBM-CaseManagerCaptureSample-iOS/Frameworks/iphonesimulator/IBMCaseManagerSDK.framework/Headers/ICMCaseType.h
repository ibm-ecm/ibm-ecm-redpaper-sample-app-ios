//
//  ICMCaseType.h
//  ICMCaseManager
//
//  Copyright (c) 2015 Future Workshops Ltd. All rights reserved.
//

@protocol ICMSolution;


/** The ICMCaseType protocol provides information about a Case type. */
@protocol ICMCaseType

/** The ID of the case type. */
@property (nonatomic, strong, readonly) NSString *typeId;
/** The name of the case type. */
@property (nonatomic, strong, readonly) NSString *name;
/** The name of the case type displayed to the user. */
@property (nonatomic, strong, readonly) NSString *displayName;
/** The description of the case type. */
@property (nonatomic, strong, readonly) NSString *typeDescription;
/** The name of the property used as title. */
@property (nonatomic, strong, readonly) NSString *titlePropertyName;
/** True if the user is allowed to create cases of this type. */
@property (nonatomic, assign, readonly) BOOL hasCreationRights;
/** The solution where the case type belongs to. @seen ICMSolution */
@property (nonatomic, strong, readonly) id<ICMSolution> solution;
/** The list of the cases of this type */
@property (nonatomic, strong, readonly) NSArray *cases;
/** The list of task types avalible for this case type */
@property (nonatomic, strong, readonly) NSArray *taskTypes;

@end
