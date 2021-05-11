//
//  RTVClient+RealTimeAudio.h
//  Rtm
//
//  Created by zsl on 2021/1/4.
//  Copyright © 2021 FunPlus. All rights reserved.
//
#import <Rtm/Rtm.h>
#import "RTMClient.h"
#import "RTMVoiceCreateRoomAnswer.h"
#import "RTMVoiceEnterRoomTokenAnswer.h"
#import "RTMVoiceRoomMembersAnswer.h"
#import "RTMVoiceRoomMemberCount.h"
#import "RTMVoiceEnterRoomAnswer.h"

NS_ASSUME_NONNULL_BEGIN

@interface RTMClient (RealTimeAudioInterface)


/// 实时语音初始化 如果使用实时语音功能需要调用此接口 每个client只需要调用一次成功后即可
/// @param dualChannel 是否双声道  默认NO单声道
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)initVoiceClientWithTimeout:(int)timeout
                      dualChannel:(BOOL)dualChannel
                          success:(void(^)(void))successCallback
                             fail:(RTMAnswerFailCallBack)failCallback;


//--------------------------------------------------------------------------------------------------
/// 进入语音房间成功后需要设置 voiceActiveRoom 设置当前活跃房间 多房间只会播放和发送当前活跃房间的语音
/// @param roomId 房间ID int64
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)enterVoiceRoomWithRoomId:(NSNumber * _Nonnull)roomId
                        timeout:(int)timeout
                        success:(void(^)(RTMVoiceEnterRoomAnswer * answer))successCallback
                           fail:(RTMAnswerFailCallBack)failCallback;
//设置当前活跃房间  默认-1为没有设置活跃房间 同时加入多个房间 只会播放和发送这个房间的声音（不会持久化）  也可通过该接口设置-1  来暂时关闭实时语音功能（例如录音前 设置-1 完成后恢复到活跃房间）
@property(nonatomic,assign)int64_t voiceActiveRoom;
//默认闭麦（不会持久化 重新设置活跃房间会自动恢复默认闭麦状态）
@property(nonatomic,assign)BOOL isOpenVoiceSpeak;
//默认播放房间声音（不会持久化 重新设置活跃房间会自动恢复默认状态）
@property(nonatomic,assign)BOOL isOpenVoicePlay;
@property(nonatomic,assign)RTMClientConnectStatus voiceConnectStatus;
//---------------------------------------------------------------------------------------------------



/// 创建语音房间 创建成功后会自动加入（有可能会加入失败）
/// @param roomId 房间id int64
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)createVoiceRoomWithId:(NSNumber * _Nonnull)roomId
                     timeout:(int)timeout
                     success:(void(^)(RTMVoiceCreateRoomAnswer * answer))successCallback
                        fail:(RTMAnswerFailCallBack)failCallback;



/// 邀请用户加入房间(非强制，需要对端确认)
/// @param roomId 房间id int64
/// @param userIds [int64]
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)inviteUserIntoVoiceRoomWithId:(NSNumber * _Nonnull)roomId
                             userIds:(NSArray<NSNumber*>*)userIds
                             timeout:(int)timeout
                             success:(void(^)(void))successCallback
                                fail:(RTMAnswerFailCallBack)failCallback;
-(RTMBaseAnswer*)inviteUserIntoVoiceRoomWithId:(NSNumber * _Nonnull)roomId
                                       userIds:(NSArray<NSNumber*>*)userIds
                                       timeout:(int)timeout;



/// 离开语音房间
/// @param roomId 房间id int64
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)exitVoiceRoomWithId:(NSNumber * _Nonnull)roomId
                   timeout:(int)timeout
                   success:(void(^)(void))successCallback
                      fail:(RTMAnswerFailCallBack)failCallback;
-(RTMBaseAnswer*)exitVoiceRoomWithId:(NSNumber * _Nonnull)roomId
                             userIds:(NSArray<NSNumber*>*)userIds
                             timeout:(int)timeout;



/// 获取语音房间成员列表
/// @param roomId 房间id int64
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)getVoiceRoomMembersWithId:(NSNumber * _Nonnull)roomId
                         timeout:(int)timeout
                         success:(void(^)(RTMVoiceRoomMembersAnswer * answer))successCallback
                            fail:(RTMAnswerFailCallBack)failCallback;
-(RTMVoiceRoomMembersAnswer*)getVoiceRoomMembersWithId:(NSNumber * _Nonnull)roomId
                                               timeout:(int)timeout;


/// 获取语音房间成员个数
/// @param roomId 房间id int64
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)getVoiceRoomMemberCountWithId:(NSNumber * _Nonnull)roomId
                             timeout:(int)timeout
                             success:(void(^)(RTMVoiceRoomMemberCount * answer))successCallback
                                fail:(RTMAnswerFailCallBack)failCallback;
-(RTMVoiceRoomMemberCount*)getVoiceRoomMemberCountWithId:(NSNumber * _Nonnull)roomId
                                                 timeout:(int)timeout;



/// 屏蔽房间某些人的语音
/// @param roomId 房间id int64
/// @param userIds [int64]
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)shieldUserInVoiceRoomWithId:(NSNumber * _Nonnull)roomId
                           userIds:(NSArray<NSNumber*>*)userIds
                           timeout:(int)timeout
                           success:(void(^)(void))successCallback
                              fail:(RTMAnswerFailCallBack)failCallback;
-(RTMBaseAnswer*)shieldUserInVoiceRoomWithId:(NSNumber * _Nonnull)roomId
                                     userIds:(NSArray<NSNumber*>*)userIds
                                     timeout:(int)timeout;



/// 解除屏蔽房间某些人的语音
/// @param roomId 房间id int64
/// @param userIds [int64]
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)removeShieldUserInVoiceRoomWithId:(NSNumber * _Nonnull)roomId
                                 userIds:(NSArray<NSNumber*>*)userIds
                                 timeout:(int)timeout
                                 success:(void(^)(void))successCallback
                                    fail:(RTMAnswerFailCallBack)failCallback;
-(RTMBaseAnswer*)removeShieldUserInVoiceRoomWithId:(NSNumber * _Nonnull)roomId
                                           userIds:(NSArray<NSNumber*>*)userIds
                                           timeout:(int)timeout;
@end

NS_ASSUME_NONNULL_END
