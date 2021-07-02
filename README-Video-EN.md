
iOS RTM Real time video Usage document (integration + interface description)
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
* 引入协议 RTMProtocol  RTMVideoProtocol
    
````objc
@required
//reconnection is valid only after one successful login
//reconnection is will begin
-(BOOL)rtmReloginWillStart:(RTMClient *)client reloginCount:(int)reloginCount;

//reconnection result
-(void)rtmReloginCompleted:(RTMClient *)client reloginCount:(int)reloginCount reloginResult:(BOOL)reloginResult error:(FPNError*)error;

@optional
//someone enters the room
-(void)userEnterVideoRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId time:(int64_t)time;
//someone leaves the room
-(void)userExitVideoRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId time:(int64_t)time;
//close room
-(void)videoRoomCloseNotificationWithRoomId:(int64_t)roomId;
//kickout from
-(void)kickOutVideoRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId;
//invited into the room
-(void)inviteIntoVideoRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId;
//Permission command notification
-(void)pushVideoAdminCommand:(NSArray*)uids command:(int)type;
```






<a id="quick use">quickuse</a>
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
self.client.videoDelegate = self;
self.rtcEndpoint = @"";

//2.login
[self.client loginWithToken:
                   language:
                  attribute:
                    timeout:
                    success:nil 
                connectFail:nil];
                    
     
//3.video init
[self.client setVideoEngine];
         
         
//4.join videoRoom
[self.client enterVideoRoomWithRoomId:@(0)
                              timeout:10
                              success:^(RTMVideoEnterRoomAnswer * answer) {

       
        
} fail:nil];

//5.openCamera getMirrorView
[self.client openCamera];
[self.view addSubview:self.client.mySelfPreview];


//6.subscribe
[self.client subscribeVideoWithRoomId:
                                  uid:
                       containerViews:
                              timeout:
                              success:^{
   
   

    
} fail:nil];




```




 



