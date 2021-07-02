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
@end

NS_ASSUME_NONNULL_END
