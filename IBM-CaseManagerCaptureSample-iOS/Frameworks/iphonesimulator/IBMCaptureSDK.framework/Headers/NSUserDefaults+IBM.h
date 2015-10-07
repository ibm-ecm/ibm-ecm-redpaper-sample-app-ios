//
//  NSUserDefaults+IBM.h
//  IBMDatacapMobile
//
//  Created on 06/05/2015.
//  Copyright (c) 2015 Future Workshops Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSUserDefaults (IBM)

+ (BOOL)ibm_ocrDebugModeEnabled;
+ (NSString *)ibm_configurationEndpoint;
+ (BOOL)ibm_visualizeTouchesEnabled;
+ (NSString *)ibm_currentUsername;
+ (void)ibm_setCurrentUsername:(NSString *)value;
+ (NSString *)ibm_currentStation;
+ (void)ibm_setCurrentStation:(NSString *)value;
+ (NSString *)ibm_tesseractLanguageCode;
+ (void)ibm_setActiveDatacapServiceObjectID:(NSString *)objectID;
+ (NSString *)ibm_activeDatacapServiceObjectID;

@end
