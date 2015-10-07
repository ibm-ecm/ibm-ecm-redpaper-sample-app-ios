//
//  ICMRole.h
//  ICMCaseManager
//
//  Copyright (c) 2015 Future Workshops Ltd. All rights reserved.
//

@protocol ICMSolution;

/** The ICMRole protocol models a role in the solution. */
@protocol ICMRole

/** The role ID. */
@property (nonatomic, assign, readonly) NSUInteger roleId;
/** The name for the role. */
@property (nonatomic, strong, readonly) NSString *name;
/** An authored for the role. */
@property (nonatomic, strong, readonly) NSString *authoredName;
/** The description of the role. */
@property (nonatomic, strong, readonly) NSString *roleDescription;
/** The solution the role belongs to. */
@property (nonatomic, strong, readonly) id<ICMSolution> solution;
/** An array of in-baskets associated to the role */
@property (nonatomic, strong, readonly) NSArray *inbaskets;
/** An array of users associated to the role */
@property (nonatomic, strong, readonly) NSArray *users;

@end
