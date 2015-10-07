//
//  ICPBarcode.h
//  IBMCaptureSDK
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

/**
 *  Barcode types supported by the app and matching values used in IBM Datacap application
 */
typedef NS_OPTIONS(uint64_t, ICPBarcodeType) {
    /**
     *  No type or unknown
     */
    ICPBarcodeTypeNone = 0,
    /**
     *  Interleaved 2 of 5
     */
    ICPBarcodeTypeInterleaved2of5 = (1 << 1),
    /**
     *  Code 39
     */
    ICPBarcodeTypeCode39 = (1 << 8),
    /**
     *  Code 93
     */
    ICPBarcodeTypeCode93 = (1 << 10),
    /**
     *  Code 128
     */
    ICPBarcodeTypeCode128 = (1 << 11),
    /**
     *  EAN 13
     */
    ICPBarcodeTypeEAN13 = (1 << 12),
    /**
     *  EAN 8
     */
    ICPBarcodeTypeEAN8 = (1 << 13),
    /**
     *  UPC-A
     */
    ICPBarcodeTypeUPCA = (1 << 14),
    /**
     *  UPC-E
     */
    ICPBarcodeTypeUPCE = (1 << 15),
    /**
     *  PDF 417
     */
    ICPBarcodeTypePDF417 = (1 << 21),
    /**
     *  Data Matrix
     */
    ICPBarcodeTypeDataMatrix = (1 << 22),
    /**
     *  Code 39 Extended
     */
    ICPBarcodeTypeCode39Extended = (1 << 23),
    /**
     *  Code 93 Extended
     */
    ICPBarcodeTypeCode93Extended = (1 << 24),
    /**
     *  QR Code
     */
    ICPBarcodeTypeQRCode = (1 << 25),
    /**
     *  Aztec
     */
    ICPBarcodeTypeAztec = (1 << 29)
};

/**
 *  An object representing data read from a barcode
 */
@interface ICPBarcode : NSObject

/**
 *  The string value read from the code
 */
@property (nonatomic, strong, readonly) NSString *code;

/**
 *  The barcode type
 */
@property (nonatomic, assign, readonly) ICPBarcodeType type;

/**
 *  The CGRect in the page where the code was detected
 */
@property (nonatomic, assign, readonly) CGRect rect;

/**
 *  Create an instance of a ICPBarcode
 *
 *  @param type The barcode type
 *  @param code The barcode value
 *  @param rect The CGRect where the code is detected
 *
 *  @return an instance of ICPBarcode
 */
+ (instancetype)barcodeWithType:(ICPBarcodeType)type code:(NSString *)code rect:(CGRect)rect;

@end
