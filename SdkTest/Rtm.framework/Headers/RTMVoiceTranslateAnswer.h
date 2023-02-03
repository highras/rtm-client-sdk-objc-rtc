//
//  RTMVoiceTranslateAnswer.h
//  Rtm
//
//  Created by zsl on 2022/11/18.
//  Copyright © 2022 FunPlus. All rights reserved.
//

#import "RTMBaseAnswer.h"


NS_ASSUME_NONNULL_BEGIN

@interface RTMVoiceTranslateAnswer : RTMBaseAnswer
@property(nonatomic,strong)NSString * source;
@property(nonatomic,strong)NSString * target;
@property(nonatomic,strong)NSString * sourceText;
@property(nonatomic,strong)NSString * targetText;
@end

NS_ASSUME_NONNULL_END
