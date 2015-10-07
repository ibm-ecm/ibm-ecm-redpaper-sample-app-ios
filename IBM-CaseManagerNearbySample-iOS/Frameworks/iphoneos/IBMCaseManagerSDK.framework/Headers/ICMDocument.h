//
//  ICMDocument.h
//  ICMCaseManager
//
//  Copyright (c) 2015 Future Workshops Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ICMFileSystemObject.h"

@protocol ICMDocumentType;


/** The ICMDocument protocol models a document inside a case or in the repository. 
 
 @see ICMFileSystemObject
 */
@protocol ICMDocument <ICMFileSystemObject>

/** The mime-type of the document. */
@property (nonatomic, strong, readonly) NSString *mimeType;
/** The owner of the document in the repository. */
@property (nonatomic, strong, readonly) NSString *owner;
/** The major version number for the document. */
@property (nonatomic, assign, readonly) NSUInteger majorVersionNumber;
/** The size of the document. */
@property (nonatomic, assign, readonly) NSUInteger contentSize;
/** A boolean value that is true if the document is locked. */
@property (nonatomic, assign, readonly) BOOL locked;
/** The set of properties associated to the document. */
@property (nonatomic, strong, readonly) NSSet *properties;
/** The type of the document. @see ICMDocumentType */
@property (nonatomic, strong, readonly) id<ICMDocumentType> documentType;
/** An image with the thumbnail of the document. */
@property (nonatomic, strong, readonly) UIImage *thumbnailImage;
/** The content of the document. */
@property (nonatomic, strong, readonly) NSData *content;

@end
