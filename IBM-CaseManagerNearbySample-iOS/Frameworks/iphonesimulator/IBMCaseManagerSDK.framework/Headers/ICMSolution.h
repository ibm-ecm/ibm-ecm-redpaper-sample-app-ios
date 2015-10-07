//
//  ICMSolution.h
//  ICMCaseManager
//
//  Copyright (c) 2015 Future Workshops Ltd. All rights reserved.
//

/**
 The ICMSolution protocol contains informations related to the solution such as the roles, the case types and the total number
 of tasks.
 */

@protocol ICMSolution

/** The name of the solution */
@property (nonatomic, strong, readonly) NSString *name;

/** The solution's prefix */
@property (nonatomic, strong, readonly) NSString *prefix;

/** A description of the solution */
@property (nonatomic, strong, readonly) NSString *solutionDescription;

/** The list of the roles in the solution */
@property (nonatomic, strong, readonly) NSArray *roles;

/** The list of the document types in the solution */
@property (nonatomic, strong, readonly) NSArray *documentTypes;

/** The list of the case types in the solution  */
@property (nonatomic, strong, readonly) NSArray *caseTypes;

@end
