//
//  RTMVoiceProtocol.h
//  Rtm
//
//  Created by zsl on 2021/1/5.
//  Copyright © 2021 FunPlus. All rights reserved.
//

#import <Foundation/Foundation.h>
@class FPNError;
NS_ASSUME_NONNULL_BEGIN

@protocol RTMVoiceProtocol <NSObject>

@optional

//语音房间
//某人进入房间
-(void)userEnterVoiceRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId time:(int64_t)time;
//某人离开房间
-(void)userExitVoiceRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId time:(int64_t)time;
//房间关闭
-(void)voiceRoomCloseNotificationWithRoomId:(int64_t)roomId;
//从房间被踢出
-(void)kickOutVoiceRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId;
//被邀请进入房间
-(void)inviteIntoVoiceRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId;
//被强制拉入房间结果
-(void)forceInviteIntoVoiceRoomNotificationWithRoomId:(int64_t)roomId error:(FPNError * _Nullable)error;
//权限命令通知
-(void)pushVoiceAdminCommand:(NSArray*)uids command:(int)type;



//语音单聊
//接收发送的语音请求
-(void)receiveP2PVoiceRequestWithUserId:(int64_t)userId;

/// 对应requestP2PVoiceWithUserId接口调用后  接收对方的反馈状态
/// @param userId 对端用户iD
/// @param eventId 1.取消p2p请求(自己调用cancelP2PVoiceWithCallId接口)  2.对端挂断   3.对端已经接请求 4.对端拒绝请求  5.对端无人接听
-(void)receiveP2PVoiceEventWithUserId:(int64_t)userId eventId:(int64_t)eventId;

@end

NS_ASSUME_NONNULL_END
