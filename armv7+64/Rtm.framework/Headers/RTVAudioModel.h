//
//  RTVAudioModel.h
//  RTV
//
//  Created by zsl on 2020/11/26.
//  Copyright © 2020 FunPlus. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTVAudioModel : NSObject
@property(nonatomic,strong)NSData * opusData;
@property(nonatomic,assign)int64_t seq;
@property(nonatomic,assign)int64_t time;
@property(nonatomic,assign)int64_t uid;
@end

NS_ASSUME_NONNULL_END
