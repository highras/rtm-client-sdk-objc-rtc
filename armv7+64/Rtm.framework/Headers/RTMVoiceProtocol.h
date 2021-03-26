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

@end

NS_ASSUME_NONNULL_END
