//
//  RTMVideoTools.h
//  Rtm
//
//  Created by zsl on 2021/5/6.
//  Copyright © 2021 FunPlus. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <VideoToolbox/VideoToolbox.h>
#import <AVFoundation/AVFoundation.h>
#import "RTMClient+RealTimeVideoInterface.h"
NS_ASSUME_NONNULL_BEGIN

@interface RTMVideoTools : NSObject
+ (AVCaptureDevice *)getCaptureDevicePosition:(AVCaptureDevicePosition)position;
+ (AVCaptureSessionPreset)getResolutionRatioWithHeight:(int)height;
+ (int)getResolutionRatioWidthWithHeight:(int)height;
+ (AVCaptureVideoOrientation)getVideoOrientationWithScreenOrientation:(UIDeviceOrientation)orientation;
+ (int)getFrame:(RTMCaptureVideoLevel)videoLevel;
+ (int)getWidth:(RTMCaptureVideoLevel)videoLevel;
+ (int)getHeight:(RTMCaptureVideoLevel)videoLevel;
+ (int)getBitRate:(RTMCaptureVideoLevel)videoLevel;
+ (int)getDeviceOrientation:(UIInterfaceOrientation)direction;

//+ (int)getFrame:(RTMCaptureVideoLevel)videoLevel;
@end

NS_ASSUME_NONNULL_END
