//
//  RTMVideoProtocol.h
//  Rtm
//
//  Created by zsl on 2021/6/2.
//  Copyright © 2021 FunPlus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@protocol RTMVideoProtocol <NSObject>


@optional


//视频房间
//某人进入房间
-(void)userEnterVideoRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId time:(int64_t)time;
//某人离开房间
-(void)userExitVideoRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId time:(int64_t)time;
//房间关闭
-(void)videoRoomCloseNotificationWithRoomId:(int64_t)roomId;
//从房间被踢出
-(void)kickOutVideoRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId;
//被邀请进入房间
-(void)inviteIntoVideoRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId;
//权限命令通知
-(void)pushVideoAdminCommand:(NSArray*)uids command:(int)type;




//视频单聊
//接收发送的语音请求
-(void)receiveP2PVideoRequestWithUserId:(int64_t)userId;



/// 对应requestP2PVideoWithUserId接口调用后  接收对方的反馈状态
/// @param userId 对端用户iD
/// @param eventId 1.取消p2p请求(自己调用cancelP2PVoiceWithCallId接口)  2.对端挂断   3.对端已经接请求(返回UIView 对面图像渲染背景，其他eventId返回nil)  4.对端拒绝请求  5.对端无人接听
-(UIView * _Nullable)receiveP2PVideoEventWithUserId:(int64_t)userId eventId:(int64_t)eventId;
@end

NS_ASSUME_NONNULL_END
