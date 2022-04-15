//
//  RTMVoicePlayerManger.h
//  Rtm
//
//  Created by zsl on 2021/1/13.
//  Copyright © 2021 FunPlus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RTVOpusManager.h"
#import "RTVAudioEngine.h"
NS_ASSUME_NONNULL_BEGIN
@class RTMClient;
@interface RTMVoicePlayerManger : NSObject
#define RTVSampleRate_48000 48000
#define RTVFrameNumber_48000   RTVSampleRate_48000/50

@property(nonatomic,assign)int channelNum;//单1  双2
@property(nonatomic,strong)RTVAudioEngine * audioEngine;
+ (id)initWithRTMClient:(RTMClient*)client dualChannel:(BOOL)dualChannel;
-(void)receiveOpusData:(NSDictionary*)pcmData;
-(void)receiveP2pOpusData:(NSDictionary*)pcmData;
-(void)cleanCacheData;
-(void)openSpeak;
-(void)closeSpeak;
-(void)openPlay;
-(void)closePlay;
-(void)activeRoomChang;
-(void)startActiveAudio;
//-(void)stopActiveAudio;
@end

NS_ASSUME_NONNULL_END

