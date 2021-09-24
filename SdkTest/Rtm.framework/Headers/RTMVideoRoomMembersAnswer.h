//
//  RTMVideoRoomMembersAnswer.h
//  Rtm
//
//  Created by zsl on 2021/6/21.
//  Copyright © 2021 FunPlus. All rights reserved.
//

#import "RTMBaseAnswer.h"

NS_ASSUME_NONNULL_BEGIN

@interface RTMVideoRoomMembersAnswer : RTMBaseAnswer

@property(nonatomic,strong)NSArray <NSNumber*>* userIds;
@property(nonatomic,strong)NSArray <NSNumber*>* administrators;
@property(nonatomic,assign)int64_t owner;

@end

NS_ASSUME_NONNULL_END
