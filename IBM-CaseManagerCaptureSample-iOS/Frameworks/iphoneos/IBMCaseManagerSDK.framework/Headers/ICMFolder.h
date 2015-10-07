//
//  ICMFolder.h
//  ICMCaseManager
//
//  Copyright (c) 2015 Future Workshops Ltd. All rights reserved.
//

#import "ICMFileSystemObject.h"

/** The ICMFolder protocol models a folder in the repository and provides a reference to the set of objects contained in it.
 
 @see ICMFileSystemObject
 */
@protocol ICMFolder <ICMFileSystemObject>

/** An array with the objects contained into the folder. */
@property (nonatomic, strong, readonly) NSArray *objects;

@end
