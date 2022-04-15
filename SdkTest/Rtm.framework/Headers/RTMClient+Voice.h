//
//  RTMClient+Voice.h
//  Rtm
//
//  Created by zsl on 2021/1/6.
//  Copyright © 2021 FunPlus. All rights reserved.
//

#import <Rtm/Rtm.h>
#import "FPNNTCPClient.h"
#import "RTMVoiceProtocol.h"
#import "RTMAnswer.h"
#import "RTMVoicePlayerManger.h"
#import "FPNNUDPClient.h"
NS_ASSUME_NONNULL_BEGIN

typedef void (^RTMVoiceConnectSuccessCallBack)(void);
typedef void (^RTMVoiceConnectFailCallBack)(void);
@interface RTMClient (Voice)
@property(nonatomic,strong)NSString * voiceClientEndpoint;
@property(nonatomic,strong)FPNNUDPClient * voiceClient;
@property(nonatomic,strong)NSMutableDictionary * currentVoiceRoomCache;
@property(nonatomic,assign)BOOL voiceInitFinish;
@property(nonatomic,strong)RTMVoicePlayerManger * voicePlayerManger;
-(void)closeVoiceClient;
-(void)addRoomCacheWithRoomId:(NSString*)roomId;
-(void)removeRoomCacheWithRoomId:(NSString*)roomId;
-(RTMAnswer*)handldVoicePushWithMethod:(NSString*)method data:(NSDictionary*)data;
-(void)initVoiceClient:(NSString *)voiceClientEndpoint;
@property(nonatomic,assign)RTMClientConnectStatus voiceConnectStatus;

@end

NS_ASSUME_NONNULL_END
