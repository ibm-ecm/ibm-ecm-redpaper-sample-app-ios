//
//  ICPCredential.h
//  IBMCaptureSDK
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ICPDatacapService.h"

/**
 ICPCredentials are used by an ICPDatacapClient as a reference for authentication.

 Passwords are stored in the keychain, and can be cleared from memory once the App is put into the background.
 */
@interface ICPCredential : NSObject

/** The username. */
@property (nonatomic, strong, readonly) NSString *username;

/** The password, stored in the keychain. */
@property (nonatomic, strong, readonly) NSString *password;

/** The stationId. */
@property (nonatomic, strong, readonly) NSString *stationId;


/**
 *  Returns the shared credential object.
 *
 *  @return instance of ICPCredential
 */
+ (instancetype)sharedCredential;

/**
 *  Updates and returns the shared credential instance
 *
 *  @param username  The username
 *  @param password  The password
 *  @param stationId The station ID
 *
 *  @return instance of ICPCredential
 */
+ (instancetype)credentialWithUsername:(NSString *)username password:(NSString *)password stationId:(NSString *)stationId;

/**
 *  Updates and returns the shared credential instance
 *
 *  @param password The password
 *  @param service  Datacap service
 *
 *  @return instance of ICPCredential
 */
+ (instancetype)credentialWithPassword:(NSString *)password forService:(id<ICPDatacapService>)service;

/**
 Clears the credentials from memory.
 */
- (void)clear;

/**
 Loads the stored credentials from the keychain for the active service.
 */
- (void)load;

/**
 *  Return password from keychain if available for a unique identifier.
 *
 *  @param serviceIdentifier unique identifier for the service instance
 *  @param username          username
 *
 *  @return The password
 */
+ (NSString *)passwordForServiceIdentifier:(NSString *)serviceIdentifier andUsername:(NSString *)username;


/**
 *  Delete password from keychain for a unique identifier
 *
 *  @param serviceIdentifier unique identifier for the service instance
 *  @param username          username
 *
 *  @return YES if password was deleted successfully, otherwise NO.
 */
+ (BOOL)deletePasswordForServiceIdentifier:(NSString *)serviceIdentifier andUsername:(NSString *)username;


/**
 *  Store password in keychain for a unique identifier
 *
 *  @param password          The password
 *  @param serviceIdentifier The service identifier
 *  @param username          The username
 *
 *  @return YES if keychain was successful, otherwise NO.
 */
+ (BOOL)storePassword:(NSString *)password
 forServiceIdentifier:(NSString *)serviceIdentifier
          andUsername:(NSString *)username;

@end
