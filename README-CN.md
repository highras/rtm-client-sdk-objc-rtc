
iOS RTM实时语音使用文档 （集成+接口说明）
================================

* [版本支持](#版本支持)
* [集成依赖](#集成依赖)
* [代理方法](#代理方法)
* [快速使用](#快速使用)


<a id="版本支持">版本支持</a>
================
* 语言:Objective-C  
* 最低支持 iOS9 系统



<a id="集成依赖">集成依赖</a>
================
* 导入SDK 引入头文件 #import <Rtm/Rtm.h>
* 拖入文件夹 RTMAudioManager
* 在TARGETS->Build Settings->Other Linker Flags （选中ALL视图）中添加-ObjC，字母O和C大写，符号“-”请勿忽略
* 静态库中采用Objective-C++实现，因此需要您保证您工程中至少有一个.mm后缀的源文件(您可以将任意一个.m后缀的文件改名为.mm)
* 添加库libresolv.9.tbd




<a id="代理方法">代理方法</a>
================
* 引入协议 RTMProtocol  RTMVoiceProtocol
    
```objc
@required
//重连只有在登录成功过1次后才会有效
//重连将要开始
-(BOOL)rtmReloginWillStart:(RTMClient *)client reloginCount:(int)reloginCount;

//重连结果
-(void)rtmReloginCompleted:(RTMClient *)client reloginCount:(int)reloginCount reloginResult:(BOOL)reloginResult error:(FPNError*)error;

@optional
//某人进入房间
-(void)userEnterVoiceRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId time:(int64_t)time;
//某人离开房间
-(void)userExitVoiceRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId time:(int64_t)time;
//房间关闭
-(void)voiceRoomCloseNotificationWithRoomId:(int64_t)roomId;
//从房间被踢出
-(void)kickOutVoiceRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId;
//被邀请进入房间
-(void)inviteIntoVoiceRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId;
//被强制拉入房间结果
-(void)forceInviteIntoVoiceRoomNotificationWithRoomId:(int64_t)roomId error:(FPNError * _Nullable)error;

```






<a id="快速使用">快速使用</a>
================
```objc
#import <Rtm/Rtm.h>

//1.初始化
self.client = [RTMClient clientWithEndpoint:
                                  projectId:
                                     userId:
                                   delegate:
                                     config:
                                 autoRelogin:];
self.client.voiceDelegate = self;
self.voiceEndpoint = @"";

//2.登录
[self.client loginWithToken:
                   language:
                  attribute:
                    timeout:
                    success:nil 
                connectFail:nil];
                    
     
//3.登录成功后 语音初始化
[self.client initVoiceClientWithTimeout:10
                                success:nil 
                            connectFail:nil];
         
         
//4.加入语音房间
[self.client enterVoiceRoomWithRoomId:@(0)
                              timeout:10
                              success:^(RTMVoiceEnterRoomAnswer * answer) {

        //加入成功后  设置voiceActiveRoom活跃房间
        
} fail:nil];

           
```




 



