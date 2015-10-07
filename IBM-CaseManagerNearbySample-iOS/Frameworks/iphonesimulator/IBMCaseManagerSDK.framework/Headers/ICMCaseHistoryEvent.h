//
//  ICMCaseHistoryEvent.h
//  IBMCaseManagerSDK
//
//  Created by Matt Brooke-Smith on 10/09/2015.
//  Copyright © 2015 Future Workshops Ltd. All rights reserved.
//

@protocol ICMCase;

/**
 The ICMCaseHistoryEventType constant is an enumeration representing the event type.
 */
typedef NS_ENUM(NSUInteger, ICMCaseHistoryEventType) {
    /** Type : Case Created */
    ICMCaseHistoryEventTypeCaseCreated = 0,
    /** Type : Document Filed */
    ICMCaseHistoryEventTypeDocumentFiled = 1,
    /** Type : Folder Created */
    ICMCaseHistoryEventTypeFolderCreated = 2,
    /** Type : Task Created */
    ICMCaseHistoryEventTypeTaskCreated = 3,
    /** Type : Task Ready */
    ICMCaseHistoryEventTypeTaskReady = 4,
    /** Type : Task Started */
    ICMCaseHistoryEventTypeTaskStarted = 5,
    /** Type : Task Completed */
    ICMCaseHistoryEventTypeTaskCompleted = 6,
    /** Type : Unknown */
    ICMCaseHistoryEventTypeUnknown = 7,
	ICMCaseHistoryEventTypeCount = 8,
};

/** The ICMCaseHistoryEvent protocol provides information about an event occured in the Case's history. */
@protocol ICMCaseHistoryEvent

/** The date in which the event occurred. */
@property (nonatomic, retain, readonly) NSDate* date;

/** A description of the event. */
@property (nonatomic, retain, readonly) NSString* eventDescription;

/** The event ID. */
@property (nonatomic, retain, readonly) NSString* eventId;

/** The event title. */
@property (nonatomic, retain, readonly) NSString* title;

/** The user who generates the event. */
@property (nonatomic, retain, readonly) NSString* user;

/** The type of the event. @see ICMCaseHistoryEventType */
@property (nonatomic, assign, readonly) ICMCaseHistoryEventType type;

/** A reference to the case instance. @see ICMCase */
@property (nonatomic, retain, readonly) id<ICMCase> caseInstance;

@end
