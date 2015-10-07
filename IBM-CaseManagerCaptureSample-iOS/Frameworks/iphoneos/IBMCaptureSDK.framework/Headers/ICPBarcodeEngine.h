//
//  ICPBarcodeEngine.h
//  IBMCaptureSDK
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ICPBarcode.h"

/**
 *  A completion block for barcode processing.
 *
 *  @param barcodes The array containing the recognized ICPBarcode objects
 *  @see ICPBarcode
 */
typedef void (^ICPBarcodeEngineBarcodesRecognizedBlock)(NSArray *barcodes);

/**
 *  The ICPBarcodeEngine provides on-device barcode recognition capabilities. All methods are dispatched onto the
 * DISPATCH_QUEUE_PRIORITY_BACKGROUND queue, and call completion blocks on the main thread
 */
@protocol ICPBarcodeEngine <NSObject>

/**
 *  Processes barcodes on a rectangle in an image, if the rectangle provided is equal to CGRectNull the method scans the whole
 image.
 *
 *  @param image           The image.
 *  @param bounds          The zone within which scan should be performed. CGRectNull means to scan the entire image.
 *  @param barcodeHints    bitmask options of ICPBarceType to look for in image. This improves the speed of processing the
 image for barcodes.
 *  @param completionBlock The completionBlock.
 */
- (void)recognizeBarcodeInImage:(UIImage *)image
                     withBounds:(CGRect)bounds
               withBarcodeHints:(ICPBarcodeType)barcodeHints
                completionBlock:(ICPBarcodeEngineBarcodesRecognizedBlock)completionBlock;

@end
