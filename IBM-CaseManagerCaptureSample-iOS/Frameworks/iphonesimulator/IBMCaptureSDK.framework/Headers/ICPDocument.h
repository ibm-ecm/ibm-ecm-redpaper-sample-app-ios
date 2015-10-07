//
//  ICPDocument.h
//  IBMCaptureSDK
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//

#import "ICPObject.h"

@protocol ICPPage;

/** 
 The ICPDocument protocol contains an array of pages. It extends ICPObject so may also contain fields and has a type.
 
 @see ICPObject
 */
@protocol ICPDocument <ICPObject>

/** An array of pages belonging to the document. */
@property (nonatomic, strong) NSArray *pages;

/**
 Adds a page to the document.
 @param page The page to add to the document.
*/
- (void)addPage:(id<ICPPage>)page;

/**
 Removes a page from the document.
 @param page The page to remove from the document.
 */
- (void)removePage:(id<ICPPage>)page;

/**
 Reorders pages in the document.
 @param atIndex The index from where the page should be moved.
 @param toIndex The index to where the page should be moved.
 */
- (void)movePageAtIndex:(NSUInteger)atIndex toIndex:(NSUInteger)toIndex;

/**
 Inserts a page at the given index.
 @param page The page to be inserted.
 @param index The index where the page should be inserted.
 */
- (void)insertPage:(id<ICPPage>)page atIndex:(NSUInteger)index;

@end
