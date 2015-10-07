//
//  ICPObjectFactory.h
//  IBMCaptureSDK
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//

@protocol ICPService
, ICPDatacapService, ICPBatch, ICPDocument, ICPPage, ICPField, ICPBatchType, ICPDocumentType, ICPPageType, ICPFieldType,
    ICPObject, ICPObjectType, ICPCharacter;

/**
 The ICPObjectFactory manages the lifecycle of ICPObjects, depending on the configuration of the object factory.

 ICPObjectFactory supports two types of managed objects: ICPCaptureObjectFactoryTypeNonPersistent and
 ICPCaptureObjectFactoryTypePersistent.

 ICPCaptureObjectFactoryTypeNonPersistent does not persist to disk once an app leaves
 memory, which is useful when data security is of high importance, or when users are required to complete tasks before leaving
 the app.

 ICPCaptureObjectFactoryTypePersistent creates a factory implementing the ICPPersistentObjectFactory protocol. This will cause
 all objects to be stored on disk until they are explicitly removed, such as when objects are uploaded.

 @see ICPCapture
 @see ICPPersistentObjectFactory
 */
@protocol ICPObjectFactory <NSObject>

/**
 Creates an ICPDatacapService.
 @param baseURL The base URL for the service.
 @return A managed object which conforms to the ICPDataService protocol.
 */
- (id<ICPDatacapService>)datacapServiceWithBaseURL:(NSURL *)baseURL;

/**
 Creates an ICPBatchType.
 @param service The service which created the batchType.
 @return A managed object which conforms to the ICPBatchType protocol.
 */
- (id<ICPBatchType>)batchTypeWithService:(id<ICPService>)service;

/**
 Creates an ICPBatch.
 @return A managed object which conforms to the ICPBatch protocol.
 */
- (id<ICPBatch>)batchWithType:(id<ICPBatchType>)batchType;

/**
 Creates an ICPDocument.
 @return A managed object which conforms to the ICPDocument protocol.
 */
- (id<ICPDocument>)documentWithBatch:(id<ICPBatch>)batch type:(id<ICPDocumentType>)documentType;

/**
 Creates an ICPPage.
 @return A managed object which conforms to the ICPPage protocol.
 */
- (id<ICPPage>)pageWithDocument:(id<ICPDocument>)document type:(id<ICPPageType>)pageType;

/**
 Creates an ICPField.
 @return A managed object which conforms to the ICPField protocol.
 */
- (id<ICPField>)fieldWithObject:(id<ICPObject>)object type:(id<ICPFieldType>)fieldType;

/**
 Creates an ICPCharacter.
 @return A managed object which conforms to the ICPCharacter protocol.
 */
- (id<ICPCharacter>)character;

/**
 Creates an ICPBatchType.
 @return A managed object which conforms to the ICPBatchType protocol.
 */
- (id<ICPBatchType>)batchType;

/**
 Creates an ICPDocumentType.
 @return A managed object which conforms to the ICPDocumentType protocol.
 */
- (id<ICPDocumentType>)documentType;

/**
 Creates an ICPPageType.
 @return A managed object which conforms to the ICPPageType protocol.
 */
- (id<ICPPageType>)pageType;

/**
 Creates an ICPFieldType.
 @return A managed object which conforms to the ICPFieldType protocol.
 */
- (id<ICPFieldType>)propertyType;


@end
