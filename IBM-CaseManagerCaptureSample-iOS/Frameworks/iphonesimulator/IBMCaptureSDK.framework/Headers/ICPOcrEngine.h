//
//  ICPOcrEngine.h
//  IBMCaptureSDK
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol ICPPage;

/**
 *  A completion block for OCR processing.
 *
 *  @param image    The image processed by the OCR engine after cropping.
 *  @param text     The text returned by the OCR engine.
 *  @param metadata Dictionary with extended information such as the confidence level per character recognized.
 */
typedef void (^ICPOcrEngineTextRecognizedBlock)(UIImage *image, NSString *text, NSDictionary *metadata);

typedef void (^ICPOcrEngineTextCompletionBlock)();

/**
 The ICPOcrEngine provides on-device OCR capabilities.

 All methods are dispatched onto the DISPATCH_QUEUE_PRIORITY_BACKGROUND queue, and call completion blocks on the main thread.
 */

@protocol ICPOcrEngine <NSObject>

/**
 *  Performs OCR on a rectangle in an image with a set whitelist of characters.
 *
 *  @param image           The image.
 *  @param rect            The zone within which OCR should be performed.
 *  @param whitelist       A string of characters to recognize, for example @"1234567890" for an integer field.
 *  @param highlightChars  When set to true, the completion block recieves an image showing the character blocks recognized by
 OCR. Turning this on is useful for debugging OCR issues.
 *  @param completionBlock The completionBlock.
 */
- (void)recognizeTextInImage:(UIImage *)image
                    withRect:(CGRect)rect
                   whitelist:(NSString *)whitelist
              highlightChars:(BOOL)highlightChars
             completionBlock:(ICPOcrEngineTextRecognizedBlock)completionBlock;

@end
