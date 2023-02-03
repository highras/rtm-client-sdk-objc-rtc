//
//  RTMFileAnswer.h
//  Rtm
//
//  Created by 张世良 on 2023/1/4.
//  Copyright © 2023 FunPlus. All rights reserved.
//

#import "RTMBaseAnswer.h"

NS_ASSUME_NONNULL_BEGIN

@interface RTMFileAnswer : RTMBaseAnswer
@property(nonatomic,strong)NSString * url;
@property(nonatomic,assign)int size;
@end

NS_ASSUME_NONNULL_END
