//
//  RTMVoiceEnterRoom.h
//  Rtm
//
//  Created by zsl on 2021/1/5.
//  Copyright © 2021 FunPlus. All rights reserved.
//

#import "RTMBaseAnswer.h"

NS_ASSUME_NONNULL_BEGIN

@interface RTMVoiceCreateRoomAnswer : RTMBaseAnswer
@property(nonatomic,assign)int64_t roomId;
//@property(nonatomic,strong)NSString * token;
@end

NS_ASSUME_NONNULL_END
