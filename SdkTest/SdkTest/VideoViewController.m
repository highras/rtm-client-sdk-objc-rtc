//
//  VideoViewController.m
//  SdkTest
//
//  Created by zsl on 2021/7/1.
//  Copyright © 2021 FunPlus. All rights reserved.
//

#import "VideoViewController.h"
#import <Rtm/Rtm.h>
#import "RTMTokenTest.h"
#import "Masonry.h"
#import "MBProgressHUD.h"
@interface VideoViewController ()<RTMProtocol,RTMVideoProtocol>
@property(nonatomic,strong)UIButton * joinRoomButton;
@property(nonatomic,strong)UIButton * createRoomButton;
@property(nonatomic,strong)UIButton * subscribeUserButton;
@property(nonatomic,strong)UIButton * audioManagerButton;
@property(nonatomic,strong)RTMClient * client;
@end

@implementation VideoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    
    [self.view addSubview:self.createRoomButton];
    [self.createRoomButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.view).offset(40);
        make.top.equalTo(self.view).offset(88);
        make.width.equalTo(@100);
        make.height.equalTo(@40);
    }];
    
    
    [self.view addSubview:self.joinRoomButton];
    [self.joinRoomButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.right.equalTo(self.view).offset(-40);
        make.top.equalTo(self.view).offset(88);
        make.width.equalTo(@100);
        make.height.equalTo(@40);
    }];
    
    [self.view addSubview:self.subscribeUserButton];
    [self.subscribeUserButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.createRoomButton);
        make.top.equalTo(self.createRoomButton.mas_bottom).offset(50);
        make.width.equalTo(@100);
        make.height.equalTo(@40);
    }];
    
    
    [self.view addSubview:self.audioManagerButton];
    [self.audioManagerButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.right.equalTo(self.joinRoomButton);
        make.top.equalTo(self.createRoomButton.mas_bottom).offset(50);
        make.width.equalTo(@100);
        make.height.equalTo(@40);
    }];
    
    
    NSString * endpoint = nil;
    if(endpoint.length == nil){
        return;
    }
    
    self.client = [RTMClient clientWithEndpoint:endpoint
                                      projectId:80000071
                                         userId:777
                                       delegate:self
                                         config:nil];
    
    self.client.videoDelegate = self;
    
    [self showLoadHudMessage:@"登录中..."];
    NSDictionary * tokenDic = [RTMTokenTest getToken:@"" projectId:@"80000071" uid:@"777"];
    [self.client loginWithToken:[tokenDic objectForKey:@"token"]
                             ts:[[tokenDic objectForKey:@"ts"] longLongValue]
                       language:@"en"
                      attribute:@{@"aaa":@"bbb"}
                        timeout:30
                        success:^{
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [self showHudMessage:@"登录成功" hideTime:2];

        });
        
    } connectFail:^(FPNError * _Nullable error) {
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [self showHudMessage:[NSString stringWithFormat:@"登录失败%@",error.ex] hideTime:2];

        });
       
       
        
    }];
    
}
#pragma mark client代理通知  必须要实现
-(BOOL)rtmReloginWillStart:(RTMClient *)client reloginCount:(int)reloginCount{
    
    //每次重连前会询问是否重连
    dispatch_async(dispatch_get_main_queue(), ^{
        [self showLoadHudMessage:@"重连中..."];
        
    });
    return YES;
}
-(void)rtmReloginCompleted:(RTMClient *)client reloginCount:(int)reloginCount reloginResult:(BOOL)reloginResult error:(FPNError *)error{
    //重连结果
    NSLog(@"重连成功后需要重新加入房间");
    if (error == nil){
        dispatch_async(dispatch_get_main_queue(), ^{
            [self showHudMessage:@"重连成功后需要重新加入房间 并进行订阅" hideTime:3];
        });
    }else{
        
    }
    
}

-(void)rtmErrorLog:(NSString *)errorLog{
    NSLog(@"%@",errorLog);
}
#pragma mark 实时视频代理通知
//某人进入房间
-(void)userEnterVideoRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId time:(int64_t)time{
    
}
//某人离开房间
-(void)userExitVideoRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId time:(int64_t)time{
    
}
//房间关闭
-(void)videoRoomCloseNotificationWithRoomId:(int64_t)roomId{
    
}
//从房间被踢出
-(void)kickOutVideoRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId{
    
}
//被邀请进入房间
-(void)inviteIntoVideoRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId{
    
}
//权限命令通知
-(void)pushVideoAdminCommand:(NSArray*)uids command:(int)type{
    
}

-(void)_subscribeButtonClick{
    
    
    [self showLoadHudMessage:@"订阅中..."];
    
    NSMutableArray * uids = [NSMutableArray array];
    UIView * uidsItemView = [UIView new];
    uidsItemView.backgroundColor = [UIColor redColor];
    uidsItemView.frame = CGRectMake(200, 450, 120, 160);
    [self.view addSubview:uidsItemView];
    [uidsItemView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.right.equalTo(self.joinRoomButton);
        make.top.equalTo(self.subscribeUserButton.mas_bottom).offset(80);
        make.width.equalTo(@120);
        make.height.equalTo(@160);
    }];
    [uids addObject:uidsItemView];
////
    [self.client subscribeVideoWithRoomId:@(666)
                                      uid:@[@(666)]
                           containerViews:uids
                                  timeout:10 success:^{
       
        dispatch_async(dispatch_get_main_queue(), ^{
            [self showHudMessage:@"订阅成功" hideTime:2];
        });
        
        
    } fail:^(FPNError * _Nullable error) {
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [self showHudMessage:error.ex hideTime:2];
        });
        
        
        
    }];
    
}
-(void)_joinRoomButtonClick{
    
    [self showLoadHudMessage:@"加入中..."];
    [self.client enterVideoRoomWithRoomId:@(666)
                        captureVideoLevel:RTMCaptureVideoDefault
                                  timeout:10
                                  success:^(RTMVideoEnterRoomAnswer * _Nonnull answer) {
        
        
        
        dispatch_async(dispatch_get_main_queue(), ^{
            
            
            [self showHudMessage:@"加入成功" hideTime:2];
            
            
            [self.view addSubview:self.client.mySelfPreview];
            self.client.mySelfPreview.backgroundColor = [UIColor orangeColor];
            [self.client.mySelfPreview mas_makeConstraints:^(MASConstraintMaker *make) {
                make.left.equalTo(self.createRoomButton);
                make.top.equalTo(self.subscribeUserButton.mas_bottom).offset(80);
                make.width.equalTo(@120);
                make.height.equalTo(@160);
            }];
            
            [self.client updatePreviewFrame];
            
        });
        
        [self.client openCamera];
        
    } fail:^(FPNError * _Nullable error) {
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [self showHudMessage:error.ex hideTime:2];
        });
        
    }];
    
}
-(void)_createRoomButtonClick{
    
    [self showLoadHudMessage:@"创建中..."];
    [self.client createVideoRoomWithId:@(666)
                     captureVideoLevel:RTMCaptureVideoDefault
                          enableRecord:NO
                               timeout:10
                               success:^(RTMVideoCreateRoomAnswer * _Nonnull answer) {
        
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [self showHudMessage:@"创建成功" hideTime:2];
        });
        
    } fail:^(FPNError * _Nullable error) {
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [self showHudMessage:error.ex hideTime:2];
        });
    }];
    
}
-(void)_audioButtonClick{
    
    if (self.client.isOpenVideoRoomVoicePlay) {
        [self.client closeVideoRoomVoicePlay];
        [self.client closeVideoRoomVoiceSpeak];
    }else{
        [self.client openVideoRoomVoicePlay];
        [self.client openVideoRoomVoiceSpeak];
    }
}
-(UIButton*)createRoomButton{
    if (_createRoomButton == nil) {
        _createRoomButton = [UIButton buttonWithType:UIButtonTypeCustom];
        _createRoomButton.backgroundColor = [UIColor orangeColor];
        [_createRoomButton setTitle:@"1创建房间" forState:UIControlStateNormal];
        [_createRoomButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_createRoomButton addTarget:self action:@selector(_createRoomButtonClick) forControlEvents:UIControlEventTouchUpInside];
    }
    return _createRoomButton;
}
-(UIButton*)joinRoomButton{
    if (_joinRoomButton == nil) {
        _joinRoomButton = [UIButton buttonWithType:UIButtonTypeCustom];
        _joinRoomButton.backgroundColor = [UIColor orangeColor];
        [_joinRoomButton setTitle:@"2加入房间" forState:UIControlStateNormal];
        [_joinRoomButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_joinRoomButton addTarget:self action:@selector(_joinRoomButtonClick) forControlEvents:UIControlEventTouchUpInside];
    }
    return _joinRoomButton;
}
-(UIButton*)subscribeUserButton{
    if (_subscribeUserButton == nil) {
        _subscribeUserButton = [UIButton buttonWithType:UIButtonTypeCustom];
        _subscribeUserButton.backgroundColor = [UIColor orangeColor];
        [_subscribeUserButton setTitle:@"3订阅用户" forState:UIControlStateNormal];
        [_subscribeUserButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_subscribeUserButton addTarget:self action:@selector(_subscribeButtonClick) forControlEvents:UIControlEventTouchUpInside];
    }
    return _subscribeUserButton;
}
-(UIButton*)audioManagerButton{
    if (_audioManagerButton == nil) {
        _audioManagerButton = [UIButton buttonWithType:UIButtonTypeCustom];
        _audioManagerButton.backgroundColor = [UIColor orangeColor];
        [_audioManagerButton setTitle:@"4音频控制" forState:UIControlStateNormal];
        [_audioManagerButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_audioManagerButton addTarget:self action:@selector(_audioButtonClick) forControlEvents:UIControlEventTouchUpInside];
    }
    return _audioManagerButton;
}

- (void)hiddenHud{
    [MBProgressHUD hideHUDForView:self.view animated:YES];
}
- (void)showLoadHudMessage:(NSString*)message{
    [self hiddenHud];
    MBProgressHUD * hud = [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    hud.removeFromSuperViewOnHide = true;
    hud.bezelView.style = MBProgressHUDBackgroundStyleSolidColor;
    hud.bezelView.backgroundColor = [[UIColor blackColor] colorWithAlphaComponent:0.8];
    hud.contentColor = [UIColor whiteColor];
    hud.label.text = message;
    hud.label.textColor = [UIColor whiteColor];
}
- (void)showHudMessage:(NSString*)message hideTime:(int)hideTime{
    [self hiddenHud];
    MBProgressHUD * hud = [MBProgressHUD showHUDAddedTo:self.view animated:YES];
    hud.bezelView.style = MBProgressHUDBackgroundStyleSolidColor;
    hud.bezelView.backgroundColor = [[UIColor blackColor] colorWithAlphaComponent:0.8];
    hud.mode = MBProgressHUDModeText;
    hud.label.text = message;
    hud.label.textColor = [UIColor whiteColor];
    hud.label.numberOfLines = 0;
    hud.removeFromSuperViewOnHide = YES;
    [hud hideAnimated:YES afterDelay:hideTime];
}
@end
