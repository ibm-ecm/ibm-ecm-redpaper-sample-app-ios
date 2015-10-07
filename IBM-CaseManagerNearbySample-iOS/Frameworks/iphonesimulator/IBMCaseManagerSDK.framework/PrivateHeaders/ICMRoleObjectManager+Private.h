//
//  ICMRoleObjectManager+Private.h
//  ICMCaseManager
//
//  Created by Matt Brooke-Smith on 13/08/2015.
//  Copyright (c) 2015 Future Workshops Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ICMRoleObjectManager.h"

@protocol ICMRole;
@protocol ICMObjectFactory;

@class ICMNavigatorRequestManager;

@interface ICMRoleObjectManager (Private)

- (nonnull instancetype)initWithRequestManager:(nonnull ICMNavigatorRequestManager *)requestManager
                                 objectFactory:(nonnull id<ICMObjectFactory>)objectFactory
                                          role:(nonnull id<ICMRole>)role;

@end
