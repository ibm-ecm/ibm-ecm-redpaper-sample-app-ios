//
//  ICMCase.h
//  ICMCaseManager
//
//  Copyright (c) 2015 Future Workshops Ltd. All rights reserved.
//


/**
 The ICMCaseState constant is an enumeration representing the state of a Case.
 */
typedef NS_ENUM(NSUInteger, ICMCaseState) {
    /** State : New */
    ICMCaseStateNew = 0,
    /** State : Initializing */
    ICMCaseStateInitializing = 1,
    /** State : Working */
    ICMCaseStateWorking = 2,
    /** State : Complete */
    ICMCaseStateComplete = 3,
    /** State : Failed */
    ICMCaseStateFailed = 4
};

@protocol ICMCaseType;

/** The ICMCase protocol provides information about a Case*/
@protocol ICMCase

/** The ID of the case. */
@property (nonatomic, strong, readonly) NSString *caseId;
/** The title of the case. */
@property (nonatomic, strong, readonly) NSString *title;
/** The id of the folder which contains the case. */
@property (nonatomic, strong, readonly) NSString *folderId;
/** The case creator.*/
@property (nonatomic, strong, readonly) NSString *creator;
/** The date when the Case has been created. */
@property (nonatomic, strong, readonly) NSDate *dateCreated;
/** The date when the Case has been modified. */
@property (nonatomic, strong, readonly) NSDate *dateModified;
/** The state of the case. @see ICMCaseState */
@property (nonatomic, assign, readonly) ICMCaseState state;
/** The latitude of the case. */
@property (nonatomic, assign, readonly) double latitude;
/** The longitude of the case. */
@property (nonatomic, assign, readonly) double longitude;
/** The type of the case. @see ICMCaseType */
@property (nonatomic, strong, readonly) id<ICMCaseType> caseType;
/** An array of objects representing the history of the case. */
@property (nonatomic, strong, readonly) NSArray *history;
/** An array of objects representing a set of objects in the repository related to the case. */
@property (nonatomic, strong, readonly) NSArray *fileSystemObjects;
/** An array of objects representing the properties of the case. */
@property (nonatomic, strong, readonly) NSArray *properties;
/** An array of objects representing the tasks of the case. */
@property (nonatomic, strong, readonly) NSArray *tasks;

@end
