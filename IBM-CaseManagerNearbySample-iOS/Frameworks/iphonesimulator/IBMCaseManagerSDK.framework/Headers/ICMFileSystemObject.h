//
//  ICMFileSystemObject.h
//  ICMCaseManager
//
//  Copyright (c) 2015 Future Workshops Ltd. All rights reserved.
//

@protocol ICMCase;
@protocol ICMFolder;


/** The ICMFileSystemObject protocol models an object in the repository's filesystem. */
@protocol ICMFileSystemObject <NSObject>

/** The ID of the object. */
@property (nonatomic, strong, readonly) NSString *objectId;
/** The name of the object. */
@property (nonatomic, strong, readonly) NSString *name;
/** The name of the user who created object. */
@property (nonatomic, strong, readonly) NSString *createdBy;
/** The name of the user who most recently modified the object. */
@property (nonatomic, strong, readonly) NSString *lastModifiedBy;
/** The date in which the object has been created. */
@property (nonatomic, strong, readonly) NSDate *creationDate;
/** The date in which the object has been most recently modified. */
@property (nonatomic, strong, readonly) NSDate *lastModificationDate;
/** True if the object is a folder */
@property (nonatomic, assign, readonly) BOOL isFolder;

/** The case instance where the object belong to. @see ICMCase */
@property (nonatomic, strong, readonly) id<ICMCase> caseInstance;
/** The folder where the object belong to. @see ICMFolder */
@property (nonatomic, strong, readonly) id<ICMFolder> folder;

@end
