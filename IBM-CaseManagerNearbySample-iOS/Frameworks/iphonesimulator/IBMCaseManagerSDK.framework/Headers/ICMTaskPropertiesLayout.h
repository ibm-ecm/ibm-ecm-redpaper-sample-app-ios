//
//  ICMTaskPropertiesLayout.h
//  IBMCaseManagerSDK
//
//  Created by Igor Fereira on 30/09/2015.
//  Copyright © 2015 Future Workshops Ltd. All rights reserved.
//

@protocol ICMProperty;

/** 
The ICMTaskPropertiesLayoutType constant is an enumeration representing the layout item type.
*/
typedef NS_ENUM(NSInteger, ICMTaskPropertiesLayoutType){
    /** Type: Section */
    ICMTaskPropertiesLayoutTypeSection = 0,
    /** Type: Property */
    ICMTaskPropertiesLayoutTypeProperty = 1
};

/** The ICMTaskPropertiesLayout protocol models a task properties layout in Case Manager. */
@protocol ICMTaskPropertiesLayout

/** The type of this layout item */
@property (nonatomic, assign, readonly) ICMTaskPropertiesLayoutType layoutType;
/** The title of the section, if the specific layout item is a section */
@property (nonatomic, strong, readonly) NSString*   title;
/** The properties contained in this layout item */
@property (nonatomic, strong, readonly) NSArray*    properties;

@end