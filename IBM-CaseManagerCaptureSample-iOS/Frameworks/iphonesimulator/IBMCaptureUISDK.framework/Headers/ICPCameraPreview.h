//
//  ICPCameraPreview.h
//  IBMCaptureUISDK
//
//  Copyright (c) 2015 Future Workshops Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 *  Status of the camera preview
 */
typedef NS_ENUM(NSUInteger, ICPCameraStatus) {
    /**
     *  Camera status is initalizing and not ready
     */
    ICPCameraStatusInitializing = 0,
    /**
     *  Camera status is scanning for documents
     */
    ICPCameraStatusWaiting,
    /**
     *  Camera has detected a document
     */
    ICPCameraStatusDocumentDetected,
    /**
     *  Camera status is processing and is not available
     */
    ICPCameraStatusLocked,
};

/**
 *  Camera filters
 */
typedef NS_ENUM(NSUInteger, ICPCameraFilter) {
    /**
     *  No filter, camera preview will display colour picture
     */
    ICPCameraFilterNone = 0,
    /**
     *  Black and white filter
     */
    ICPCameraFilterBlackAndWhite
};

/**
 *  Completion block called when a picture has been taken, either a rectangle in the picture has been detected or the picture
 *was taken manually by the user
 *
 *  @param originalPhoto  picture as seen by the camera
 *  @param rectifiedPhoto picture after cropped along rectangle edge detection
 *  @param error          error that occured during capture
 */
typedef void (^ICPCameraPreviewTakePhotoCompletionBlock)(UIImage *originalPhoto, UIImage *rectifiedPhoto, NSError *error);

/**
 *  Block called when camera status changes. This can be used to force taking a picture when status changes to document
 *detected.
 *
 *  @param status the new ICPCameraStatus
 */
typedef void (^ICPCameraPreviewStatusChangedBlock)(ICPCameraStatus status);

@interface ICPCameraPreview : UIView

/**
 *  The current status of the camera preview
 */
@property (nonatomic, assign, readonly) ICPCameraStatus status;

/**
 *  enabled automatic rectangle edge detection for documents
 */
@property (nonatomic, assign) BOOL rectDetectionEnabled;

/**
 *  The ICPCameraFilter to use
 */
@property (nonatomic, assign) ICPCameraFilter filter;

/**
 *  Turn flash on/off
 */
@property (nonatomic, assign, getter=isFlashEnabled) BOOL flashEnabled;

/**
 *  The block called when camera status has changed
 */
@property (nonatomic, strong) ICPCameraPreviewStatusChangedBlock statusChangedBlock;

/**
 *  Take picture
 *
 *  @param completionBlock returns the original picture, the cropped version if applicable and an error if one occured
 */
- (void)takePictureWithCompletionBlock:(ICPCameraPreviewTakePhotoCompletionBlock)completionBlock;

/**
 *  Start the camera preview video session
 *
 *  @param statusChangedBlock block called when camera status changes
 */
- (void)startCapturingWithStatusChangedBlock:(ICPCameraPreviewStatusChangedBlock)statusChangedBlock;

/**
 *  Stops the camera preview video session
 */
- (void)stopCapturing;

@end
