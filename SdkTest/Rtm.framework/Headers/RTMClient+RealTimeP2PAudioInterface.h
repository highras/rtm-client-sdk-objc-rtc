//
//  RTMClient+RealTimeP2PInterface.h
//  Rtm
//
//  Created by zsl on 2022/2/7.
//  Copyright © 2022 FunPlus. All rights reserved.
//

#import <Rtm/Rtm.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTMClient (RealTimeP2PAudioInterface)


/// 发起p2p语音
/// @param userId 用户iD int64
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)requestP2PVoiceWithUserId:(NSNumber * _Nonnull)userId
                         timeout:(int)timeout
                         success:(void(^)(void))successCallback
                            fail:(RTMAnswerFailCallBack)failCallback;


/// 发起者取消p2p语音
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)cancelP2PVoiceWithTimeout:(int)timeout
                         success:(void(^)(void))successCallback
                            fail:(RTMAnswerFailCallBack)failCallback;


/// 关闭p2p语音
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)closeP2PVoiceWithTimeout:(int)timeout
                         success:(void(^)(void))successCallback
                            fail:(RTMAnswerFailCallBack)failCallback;


/// 接受p2p语音
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)acceptP2PVoiceWithTimeout:(int)timeout
                         success:(void(^)(void))successCallback
                            fail:(RTMAnswerFailCallBack)failCallback;


/// 拒绝p2p语音
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)refuseP2PVoiceWithTimeout:(int)timeout
                         success:(void(^)(void))successCallback
                            fail:(RTMAnswerFailCallBack)failCallback;


@end

NS_ASSUME_NONNULL_END
