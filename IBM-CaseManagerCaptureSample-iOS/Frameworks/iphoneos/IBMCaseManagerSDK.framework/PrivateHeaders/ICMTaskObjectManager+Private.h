//
//  ICMTaskManager+Private.h
//  ICMCaseManager
//
//  Created by Matt Brooke-Smith on 09/08/2015.
//  Copyright (c) 2015 Future Workshops Ltd. All rights reserved.
//

#import "ICMTaskObjectManager.h"

@protocol ICMTask;
@protocol ICMObjectFactory;

@class ICMNavigatorRequestManager;

@interface ICMTaskObjectManager (Private)

- (nonnull instancetype)initWithRequestManager:(nonnull ICMNavigatorRequestManager *)requestManager
                                 objectFactory:(nonnull id<ICMObjectFactory>)objectFactory
                                          task:(nonnull id<ICMTask>)task;

- (nullable NSDictionary *)_buildPropertiesParameters:(nonnull NSDictionary *)properties;

@end
