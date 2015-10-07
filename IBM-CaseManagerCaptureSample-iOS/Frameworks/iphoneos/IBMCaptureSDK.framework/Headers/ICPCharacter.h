//
//  ICPCharacter.h
//  IBMCaptureSDK
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//

#import "ICPObject.h"

/**
 *  ICPPoint is the local equivalent of CGPoint
 */
struct ICPPoint {
    double x;
    double y;
};
typedef struct ICPPoint ICPPoint;

/**
 *  ICPSize is the local equivalent of CGSize
 */
struct ICPSize {
    double width;
    double height;
};
typedef struct ICPSize ICPSize;

/**
 *  ICPRect is the local equivalent of CGRect
 */
struct ICPRect {
    ICPPoint origin;
    ICPSize size;
};
typedef struct ICPRect ICPRect;

/**
 *  Creates an ICPSize
 *
 *  @param width  The width
 *  @param height The height
 *
 *  @return ICPSize structure
 */
static inline ICPSize ICPSizeMake(double width, double height)
{
    ICPSize size;
    size.width = width;
    size.height = height;
    return size;
}

/**
 *  Creates an ICPRect
 *
 *  @param x      The x origin
 *  @param y      The y origin
 *  @param width  The width
 *  @param height The height
 *
 *  @return ICPRect structure
 */
static inline ICPRect ICPRectMake(double x, double y, double width, double height)
{
    ICPRect rect;
    rect.origin.x = x;
    rect.origin.y = y;
    rect.size.width = width;
    rect.size.height = height;
    return rect;
}

/**
 *  The ICPCharacter describe a character recognized in the ICPField value
 */
@protocol ICPCharacter <ICPObject>

/**
 *  Frame of the character recognised by OCR
 */
@property (nonatomic, assign) ICPRect frame;

/**
 *  Confidence between 0 and 1 as set by OCR
 */
@property (nonatomic, strong) NSNumber *confidence;

/**
 *  Character string. This contains a string of length 1 with the unicode character
 */
@property (nonatomic, strong) NSString *text;

@end
