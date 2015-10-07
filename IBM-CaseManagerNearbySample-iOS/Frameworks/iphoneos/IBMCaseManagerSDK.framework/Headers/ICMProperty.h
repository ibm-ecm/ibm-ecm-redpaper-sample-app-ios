//
//  ICMProperty.h
//  ICMCaseManager
//
//  Copyright (c) 2015 Future Workshops Ltd. All rights reserved.
//


/**
 The ICMPropertyType constant is an enumeration representing the property type.
 */
typedef NS_ENUM(NSUInteger, ICMPropertyType) {
    /** Type : Boolean */
    ICMPropertyTypeBoolean = 0,
    /** Type : Integer */
    ICMPropertyTypeInteger = 1,
    /** Type : Double */
    ICMPropertyTypeDouble = 2,
    /** Type : Timestamp */
    ICMPropertyTypeTimestamp = 3,
    /** Type : String */
    ICMPropertyTypeString = 4,
    /** Type : Attachment */
    ICMPropertyTypeAttachment = 5,
    /** Type : Group */
    ICMPropertyTypeGroup = 6,
    /** Type : Unknown */
    ICMPropertyTypeUnknown = 7,
    ICMPropertyTypeCount = 8,
};


@protocol ICMTask
, ICMDocument, ICMCase;

/** The ICMProperty protocol models a property in a case. **/
@protocol ICMProperty

/** The property identifier. */
@property (nonatomic, strong, readonly) NSString *identifier;
/** The name of the property displayed to the user. */
@property (nonatomic, strong, readonly) NSString *displayName;
/** The description of the property. */
@property (nonatomic, strong, readonly) NSString *propertyDescription;
/** The choice list if the property has a choice list associated. */
@property (nonatomic, strong, readonly) NSDictionary *choices;
/** The maximum value of the property if any. */
@property (nonatomic, assign, readonly) NSObject *maximumValue;
/** The minimum value of the property if any. */
@property (nonatomic, assign, readonly) NSObject *minimumValue;
/** The default value of the property if any. */
@property (nonatomic, strong, readonly) NSObject *defaultValue;
/** The value of the property. */
@property (nonatomic, strong, readonly) NSObject *value;
/** The maximum length of the property if any. */
@property (nonatomic, assign, readonly) NSUInteger maximumLength;
/** The type of the property. */
@property (nonatomic, assign, readonly) ICMPropertyType type;
/** True if the property has an associated choice list. */
@property (nonatomic, assign, readonly) BOOL hasChoiceList;
/** True if the property is required. */
@property (nonatomic, assign, readonly) BOOL required;
/** True if the property is read-only. */
@property (nonatomic, assign, readonly) BOOL readOnly;
/** True if the property is an array of values. */
@property (nonatomic, assign, readonly) BOOL isArray;
/** True if the property is hidden. */
@property (nonatomic, assign, readonly) BOOL hidden;
/** The property the document belongs to */
@property (nonatomic, strong, readonly) id<ICMDocument> document;
/** The names in the choice list if the property has a choice list associated. */
@property (nonatomic, strong, readonly) NSArray *choiceNames;

@end
