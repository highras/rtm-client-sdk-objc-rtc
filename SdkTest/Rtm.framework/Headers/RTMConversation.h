//
//  RTMSession.h
//  Rtm
//
//  Created by zsl on 2022/11/22.
//  Copyright © 2022 FunPlus. All rights reserved.
//

#import "RTMBaseAnswer.h"
#import "RTMHistoryMessage.h"

NS_ASSUME_NONNULL_BEGIN

@interface RTMConversation : RTMBaseAnswer
@property(nonatomic,strong)NSArray <NSNumber*>* conversations;//会话ID
@property(nonatomic,strong)NSArray <NSNumber*>* unreads;//每个会话未读数
@property(nonatomic,strong)NSArray <RTMHistoryMessage*>* lastMessages;//最后一条消息
@end

NS_ASSUME_NONNULL_END

