//
//  RTMVideoDataModel.h
//  Rtm
//
//  Created by zsl on 2021/5/19.
//  Copyright © 2021 FunPlus. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTMVideoDataModel : NSObject
@property(nonatomic,strong)NSData * frameData;
@property(nonatomic,strong)NSData * spsData;
@property(nonatomic,strong)NSData * ppsData;
@property(nonatomic,assign)BOOL flags;
@property(nonatomic,assign)int64_t timestamp;
@property(nonatomic,assign)int rotation;
@property(nonatomic,assign)int64_t version;//gop
@property(nonatomic,assign)int64_t uid;
@property(nonatomic,assign)int64_t rid;
@property(nonatomic,assign)int64_t seq;//
@end

NS_ASSUME_NONNULL_END
