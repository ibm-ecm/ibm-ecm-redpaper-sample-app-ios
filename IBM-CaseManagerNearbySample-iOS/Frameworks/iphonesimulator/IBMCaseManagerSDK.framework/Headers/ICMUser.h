//
//  ICMUser.h
//  ICMCaseManager
//
//  Copyright (c) 2015 Future Workshops Ltd. All rights reserved.
//

/** The ICMUser protocol provides information about the user, including the roles assigned to him/her. */
@protocol ICMUser

/** The user id. */
@property (nonatomic, strong, readonly) NSString *userId;

/** A short name for the user. */
@property (nonatomic, strong, readonly) NSString *shortName;

/** The name displayed for the user. */
@property (nonatomic, strong, readonly) NSString *displayName;

/** The user's email. */
@property (nonatomic, strong, readonly) NSString *email;


/** The list of roles assigned to the user. */
@property (nonatomic, strong, readonly) NSSet *roles;

@end
