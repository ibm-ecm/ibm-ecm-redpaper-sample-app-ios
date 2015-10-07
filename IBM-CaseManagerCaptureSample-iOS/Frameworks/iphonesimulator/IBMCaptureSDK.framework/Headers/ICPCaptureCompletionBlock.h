
//
//  ICPCaptureCompletionBlock.h
//  IBMCaptureSDK
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//

/**
 A default completion block.
 
 This block is commonly executed after completion of a network task.
 */
typedef void (^ICPCaptureCompletionBlock)(BOOL success, id result, NSError *error);
