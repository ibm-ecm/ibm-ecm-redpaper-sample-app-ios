//
//  ICMDocumentType.h
//  ICMCaseManager
//
//  Copyright (c) 2015 Future Workshops Ltd. All rights reserved.
//

@protocol ICMSolution;


/** The ICMDocumentType protocol describes document types in the repository. */
@protocol ICMDocumentType

/** A user-friendly name for the document type. */
@property (nonatomic, strong, readonly) NSString *displayName;
/** The description of the document type. */
@property (nonatomic, strong, readonly) NSString *typeDescription;
/** If true the user can create a new instance of the document. */
@property (nonatomic, assign, readonly) BOOL hasCreationRights;
/** The solution the document type belongs to. */
@property (nonatomic, strong, readonly) id<ICMSolution> solution;
/** An array of document in the repository for the document type. */
@property (nonatomic, strong, readonly) NSArray *documents;

@end
