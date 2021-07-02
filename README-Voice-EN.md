

iOS RTM Usage document (integration + interface description)
================================

* [version support](#versionsupport)
* [integration dependency](#integrationdependency)
* [delegate](#delegate)
* [quick use](#quickuse)

<a id="versionsupport">version support</a>
================
* language:Objective-C  
* minimum system iOS 9 



<a id="integrationdependency">integration dependency</a>
================
* import SDK and #import <Rtm/Rtm.h>
* import folder RTMAudioManager
* TARGETS->Build Settings->Other Linker Flags add "-ObjC"
* SDK use Objective-C++，need to add .mm file (any one .m file to .mm)
* add libresolv.9.tbd




<a id="delegate">delegate</a>
================
* import RTMProtocol  RTMVoiceProtocol
    
```objc
@required
//reconnection is valid only after one successful login
//reconnection is will begin
-(BOOL)rtmReloginWillStart:(RTMClient *)client reloginCount:(int)reloginCount;

//reconnection result
-(void)rtmReloginCompleted:(RTMClient *)client reloginCount:(int)reloginCount reloginResult:(BOOL)reloginResult error:(FPNError*)error;

@optional
//someone enters the room
-(void)userEnterVoiceRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId time:(int64_t)time;
//someone leaves the room
-(void)userExitVoiceRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId time:(int64_t)time;
//close room
-(void)voiceRoomCloseNotificationWithRoomId:(int64_t)roomId;
//kickout from
-(void)kickOutVoiceRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId;
//invited into the room
-(void)inviteIntoVoiceRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId;
//forced invited into the room
-(void)forceInviteIntoVoiceRoomNotificationWithRoomId:(int64_t)roomId error:(FPNError * _Nullable)error;
//Permission command notification
-(void)pushVoiceAdminCommand:(NSArray*)uids command:(int)type;
```






<a id="quick use">quickuse</a>
================
================
```objc
#import <Rtm/Rtm.h>

//1.init
self.client = [RTMClient clientWithEndpoint:
                                  projectId:
                                     userId:
                                   delegate:
                                     config:
                                 autoRelogin:];
self.client.voiceDelegate = self;
self.rtcEndpoint = @"";

//2.login
[self.client loginWithToken:
                   language:
                  attribute:
                    timeout:
                    success:nil 
                connectFail:nil];
                    
     
//3.voice initialization after successful login
[self.client setAudioEngineWithDualChannel:NO];
         
         
//4.join voice room
[self.client enterVoiceRoomWithRoomId:@(0)
                              timeout:10
                              success:^(RTMVoiceEnterRoomAnswer * answer) {

        //set voice active room after joining successfully
        
} fail:nil];

           
```



