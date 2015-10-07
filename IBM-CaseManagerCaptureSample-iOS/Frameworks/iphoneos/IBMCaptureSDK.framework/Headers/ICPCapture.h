//
//  ICPCapture.h
//  IBMCaptureSDK
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ICPObjectFactory
, ICPServiceClient, ICPService, ICPOcrEngine, ICPImageEngine, ICPBarcodeEngine;

@class ICPCredential;

/**
 *  The ICPCaptureObjectFactoryType is used to specify the persistence mode to be used for objects created by the
 * ICPObjectFactory
 */
typedef NS_ENUM(NSUInteger, ICPCaptureObjectFactoryType) {
    /** Objects are not saved on the device storage. */
    ICPCaptureObjectFactoryTypeNonPersistent = 0,
    /** Objects are stored on device. */
    ICPCaptureObjectFactoryTypePersistent,
    /** Counter property for enum. */
    ICPCaptureObjectFactoryTypeCount
};

/**
 The ICPCapture class is the entry point into the IBMCapture SDK. Responsibilities of this class include creation of an
 ICPObjectFactory for persistence and an ICPServiceClient for networking
*/
@interface ICPCapture : NSObject

/**
 *  The ICPObjectFactory for this ICPCapture instance. The ICPObjectFactory is responsible for object lifecycle management and
 * persistence.
 */
@property (nonatomic, strong, readonly) id<ICPObjectFactory> objectFactory;

/**
 Create an instance of the ICPCapture class with an objectFactoryType, used to control object persistence.

 @param objectFactoryType The type of object factory to use.
 @return An instance of the ICPCapture class.
 */
+ (instancetype)instanceWithObjectFactoryType:(ICPCaptureObjectFactoryType)objectFactoryType;

/**
 Creates a client object for the given server and credential information. The client object will be used to call network
 functions, such as retrieving batch types or uploading batches.
 @param service Service information for the client including the base URL.
 @param credential Credentials for the client.
 */
- (id<ICPServiceClient>)clientForService:(id<ICPService>)service withCredential:(ICPCredential *)credential;

@end
