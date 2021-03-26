//
//  RTMEnterVoiceRoomAnswer.h
//  Rtm
//
//  Created by zsl on 2021/1/5.
//  Copyright © 2021 FunPlus. All rights reserved.
//

#import "RTMBaseAnswer.h"

NS_ASSUME_NONNULL_BEGIN

@interface RTMVoiceEnterRoomAnswer : RTMBaseAnswer
@property(nonatomic,assign)BOOL isOpenMicrophone;
@end

NS_ASSUME_NONNULL_END
