//
//  ICMSessionManager+Private.h
//  IBMCaseManagerSDK
//
//  Created by Matt Brooke-Smith on 17/09/2015.
//  Copyright © 2015 Future Workshops Ltd. All rights reserved.
//

#import <IBMCaseManagerSDK/ICMSessionManager.h>

@interface ICMSessionManager (Private)

- (NSArray *)findAll:(Protocol *)protocol withPredicate:(NSPredicate *)predicate;

@end
