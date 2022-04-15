//
//  RTMClient.h
//  Rtm
//
//  Created by zsl on 2019/12/11.
//  Copyright © 2019 FunPlus. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RTMProtocol.h"
#import "RTMCallBackDefinition.h"
#import "RTMClientConfig.h"
//YIN
#import "RTMVoiceProtocol.h"

#import "RTMVideoProtocol.h"
NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, RTMCaptureVideoLevel){
    
    RTMCaptureVideoDefault = 1,
    RTMCaptureVideoMiddle = 2,
    RTMCaptureVideoHigh = 3,
    
};

typedef NS_ENUM(NSInteger, RTMClientConnectStatus){
    
    RTMClientConnectStatusConnectClosed = 0,
    RTMClientConnectStatusConnecting = 1,
    RTMClientConnectStatusConnected = 2,
    
};
typedef void (^RTMLoginSuccessCallBack)(void);
typedef void (^RTMLoginFailCallBack)(FPNError * _Nullable error);

@interface RTMClient : NSObject


+ (nullable instancetype)clientWithEndpoint:(nonnull NSString * )endpoint
                                   projectId:(int64_t)projectId
                                      userId:(int64_t)userId
                                    delegate:(id <RTMProtocol>)delegate
                                      config:(nullable RTMClientConfig *)config;


- (void)loginWithToken:(nonnull NSString *)token
              language:(nullable NSString *)language
             attribute:(nullable NSDictionary *)attribute
               timeout:(int)timeout //默认30秒
               success:(RTMLoginSuccessCallBack)loginSuccess
           connectFail:(RTMLoginFailCallBack)loginFail;



@property (nonatomic,strong)RTMClientConfig * clientConfig;
@property (nonatomic,readonly,strong)NSString * sdkVersion;
+(NSString*)getSdkVersion;
@property (nonatomic,readonly,strong)NSString * apiVersion;
@property (nonatomic,readonly,assign)RTMClientConnectStatus currentConnectStatus;
@property (nonatomic,assign,nullable)id <RTMProtocol> delegate;

//YIN
@property(nonatomic,assign)id <RTMVoiceProtocol> voiceDelegate;
@property(nonatomic,assign)id <RTMVideoProtocol> videoDelegate;

@property (nonatomic,strong)NSString * rtcEndpoint;

@property(nonatomic,readonly,assign)int64_t projectId;
@property(nonatomic,readonly,assign)int64_t userId;


//登录状态下有效 RTMClientConnectStatusConnected
-(BOOL)closeConnect;





- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end


NS_ASSUME_NONNULL_END
