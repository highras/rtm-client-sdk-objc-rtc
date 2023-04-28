//
//  RTMSendAnswer.h
//  Rtm
//
//  Created by zsl on 2020/8/13.
//  Copyright © 2020 FunPlus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RTMBaseAnswer.h"
NS_ASSUME_NONNULL_BEGIN

@interface RTMSendAnswer : RTMBaseAnswer
@property(nonatomic,assign)int64_t mtime;
@property(nonatomic,assign)int64_t messageId;
@property(nonatomic,strong)NSString * msg;   //chat类型mType = 30 会返回审核后的文本
@end

NS_ASSUME_NONNULL_END
