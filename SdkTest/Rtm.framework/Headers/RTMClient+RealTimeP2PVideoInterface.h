//
//  RTMClient+RealTimeP2PVideoInterface.h
//  Rtm
//
//  Created by zsl on 2022/2/28.
//  Copyright © 2022 FunPlus. All rights reserved.
//

#import <Rtm/Rtm.h>

NS_ASSUME_NONNULL_BEGIN
@interface RTMClient (RealTimeP2PVideoInterface)


/// 发起p2p视频
/// @param userId 用户iD int64
/// @param captureVideoLevel 清晰度等级
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)requestP2PVideoWithUserId:(NSNumber * _Nonnull)userId
               captureVideoLevel:(RTMCaptureVideoLevel)captureVideoLevel
                         timeout:(int)timeout
                         success:(void(^)(void))successCallback
                            fail:(RTMAnswerFailCallBack)failCallback;


/// 发起者取消p2p视频
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)cancelP2PVideoWithTimeout:(int)timeout
                         success:(void(^)(void))successCallback
                            fail:(RTMAnswerFailCallBack)failCallback;


/// 关闭p2p视频
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)closeP2PVideoWithTimeout:(int)timeout
                         success:(void(^)(void))successCallback
                            fail:(RTMAnswerFailCallBack)failCallback;


/// 接受p2p视频
/// @param timeout 请求超时时间 秒
/// @param captureVideoLevel 清晰度等级
/// @param containerView 对方视频显示容器视图
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)acceptP2PVideoWithTimeout:(int)timeout
               captureVideoLevel:(RTMCaptureVideoLevel)captureVideoLevel
                   containerView:(UIView*)containerView
                         success:(void(^)(void))successCallback
                            fail:(RTMAnswerFailCallBack)failCallback;


/// 拒绝p2p视频
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)refuseP2PVideoWithTimeout:(int)timeout
                         success:(void(^)(void))successCallback
                            fail:(RTMAnswerFailCallBack)failCallback;
@end

NS_ASSUME_NONNULL_END
