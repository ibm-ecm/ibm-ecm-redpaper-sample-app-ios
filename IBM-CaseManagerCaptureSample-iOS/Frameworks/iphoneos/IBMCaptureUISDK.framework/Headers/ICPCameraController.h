//
//  ICPCameraController.h
//  IBMCaptureUISDK
//
//  Copyright (c) 2015 IBM Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 *  This block is used to return an image to the camera controller
 *
 *  @param image image to be added to the camera roll view in the camera controller
 */
typedef void (^ICPCameraControllerImagePickedBlocked)(UIImage *image);

@class ICPCameraController;

@protocol ICPObjectFactory
, ICPBatchType, ICPBatch, ICPPage, ICPOcrEngine;

/**
 *  The ICPCameraControllerDelegate methods are used to be notified about events happening in the camera controller and react
 * to them
 */
@protocol ICPCameraControllerDelegate <NSObject>

@optional

/**
 Notify delegate that a user tapped on a page in the camera roll view
 @param cameraController The Camera Controller
 @param page ICPPage selected in camera roll view.
 */
- (void)cameraController:(ICPCameraController *)cameraController didSelectPage:(id<ICPPage>)page;

/**
 Notify delegate that the gallery button in the Camera Controller has been tapped and the controller expects an image in
 return
 @param cameraController The Camera Controller
 @param rect The frame of the gallery button, usually needed to display popover on iPad
 @param completionBlock A completion block returning an image for the page to be added to the Camera Controller
 */
- (void)cameraController:(ICPCameraController *)cameraController
    didSelectImportImageFromRect:(CGRect)rect
             withCompletionBlock:(ICPCameraControllerImagePickedBlocked)completionBlock;

/**
 Notify delegate that position of the gallery button in the camera controller has changed. This is generally used to update
 the position of a popover after a rotation event.
 @param cameraController The Camera Controller
 @param frame The Gallery Button frame
 */
- (void)cameraController:(ICPCameraController *)cameraController galleryButtonFrameDidChange:(CGRect)frame;

@end

/**
 *  This completion block is called when the next button is pressed in the camera controller
 *
 *  @param controller the camera controller
 *  @param batch      the ICPBatch currently being edited
 */
typedef void (^ICPCameraControllerCompletionBlock)(ICPCameraController *controller, id<ICPBatch> batch);

/**
 The ICPCameraController is a complete UI widget for capturing and processing images and documents. You can present the
 controller
 as you would any standard UIViewController. It supports both iPhone and iPad layouts.

 You can customise the controller by adding buttons to the top toolbar, or changing the tint color.
 */
@interface ICPCameraController : UIViewController

/** The tint color to apply to the controller. The default value is ```[UINavigationBar appearance].tintColor```.*/
@property (nonatomic, strong) UIColor *tintColor;

/**
 When this is turned on and the batch type has information about barcodes to identify pages, the controller will scan the
 image for the page and
 document types through barcode identification. If the page type is detected, it will attempt to perform OCR on the fields if
 present in the DCO. This property is set to YES by default. Setting the property to NO will make the image processing faster.
 */
@property (nonatomic, assign) BOOL detectPageTypeThroughBarcode;

/**
 The object that acts as the delegate of camera controller.
 */
@property (nonatomic, weak) id<ICPCameraControllerDelegate> delegate;

/**
 *  Create a new instance of the controller using an object factory and batch type. The controller displays the documents
 *types available in the batch type in the top toolbar.
 *
 *  @param objectFactory   The object factory the controller will use to create and manage objects.
 *  @param batchType       The batch type to be used
 *  @param ocrEngine       the OCR Engine to be used to recognize characters in document
 *  @param completionBlock The completionBlock executed when pressing next in the controller
 *
 *  @return instance of ICPCameraController
 */
+ (instancetype)controllerWithObjectFactory:(id<ICPObjectFactory>)objectFactory
                                  batchType:(id<ICPBatchType>)batchType
                                  ocrEngine:(id<ICPOcrEngine>)ocrEngine
                            completionBlock:(ICPCameraControllerCompletionBlock)completionBlock;

/**
 *  Add a custom button to the top toolbar of the camera controller.
 *
 *  @param title  The title of the button, displayed on iPad
 *  @param image  The icon of the button. Pass a UIImage with rendering mode UIImageRenderingModeAlwaysTemplate for the
 *tintColor to be reflected.
 *  @param target The target object
 *  @param action The action to perform on the target object once the button is pressed.
 *
 *  @return the ICPToolbarItem being added to the top toolbar
 */
- (UIView *)addCustomButtonWithTitle:(NSString *)title image:(UIImage *)image target:(id)target action:(SEL)action;

@end
