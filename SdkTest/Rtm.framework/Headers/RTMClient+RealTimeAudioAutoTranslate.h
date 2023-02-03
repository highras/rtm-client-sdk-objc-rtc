//
//  RTMClient+RealTimeAudioAutoTranslate.h
//  Rtm
//
//  Created by zsl on 2022/10/10.
//  Copyright © 2022 FunPlus. All rights reserved.
//

#import <Rtm/Rtm.h>
#import "RTMClient.h"
#import "RTMVoiceCreateRoomAnswer.h"
#import "RTMVoiceEnterRoomTokenAnswer.h"
#import "RTMVoiceRoomMembersAnswer.h"
#import "RTMVoiceRoomMemberCount.h"
#import "RTMVoiceEnterRoomAnswer.h"

NS_ASSUME_NONNULL_BEGIN

@interface RTMClient (RealTimeAudioAutoTranslate)


/// 创建自动翻译语音房间 创建成功后会自动加入（有可能会加入失败）
/// @param roomId 房间id int64
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)createAutoTranslateVoiceRoomWithId:(NSNumber * _Nonnull)roomId
                                 language:(NSString * _Nonnull)language
                             enableRecord:(BOOL)enableRecord
                                  timeout:(int)timeout
                                  success:(void(^)(RTMVoiceCreateRoomAnswer * answer))successCallback
                                     fail:(RTMAnswerFailCallBack)failCallback;


/// 进入语音房间成功后需要设置 voiceActiveRoom 设置当前活跃房间 多房间只会播放和发送当前活跃房间的语音
/// @param roomId 房间ID int64
/// @param language 翻译目标语言
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)enterAutoTranslateVoiceRoomWithRoomId:(NSNumber * _Nonnull)roomId
                                    language:(NSString * _Nonnull)language
                                     timeout:(int)timeout
                                     success:(void(^)(RTMVoiceEnterRoomAnswer * answer))successCallback
                                        fail:(RTMAnswerFailCallBack)failCallback;

@end

NS_ASSUME_NONNULL_END
