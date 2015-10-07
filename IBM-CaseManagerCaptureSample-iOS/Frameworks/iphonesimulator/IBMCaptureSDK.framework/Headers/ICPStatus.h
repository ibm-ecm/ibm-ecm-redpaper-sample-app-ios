//
//  ICPStatus.h
//  IBMCaptureSDK
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//

/**
 The ICPStatus constant is an enumeration representing the upload status.
 */
typedef NS_ENUM(int32_t, ICPStatus) {
    /** Stauts : Failed. */
    ICPStatusFailed = -1,
    /** Stauts : Incompleted. */
    ICPStatusIncompleted = 0,
    /** Stauts : Queued. */
    ICPStatusQueued = 1,
    /** Stauts : Uploading. */
    ICPStatusUploading = 2,
    /** Stauts : Uploaded. */
    ICPStatusUploaded = 3,
    /** Counter property for enum. */
    ICPStatusCount
};
