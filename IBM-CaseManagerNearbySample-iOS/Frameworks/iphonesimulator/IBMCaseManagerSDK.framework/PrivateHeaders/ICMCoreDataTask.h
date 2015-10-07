//
//  ICMCoreDataTask.h
//  ICMCaseManager
//
//  Created by Carlos Vidal on 22/07/2015.
//  Copyright (c) 2015 Future Workshops Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "ICMTask.h"
#import "ICMMappableObject.h"

@protocol ICMCase;

@class RKEntityMapping;

@interface ICMCoreDataTask : NSManagedObject <ICMTask, ICMMappableObject>

+ (RKEntityMapping *)nearbyMapping;

@end
