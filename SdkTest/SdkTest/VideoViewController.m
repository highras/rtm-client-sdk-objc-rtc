//
//  VideoViewController.m
//  SdkTest
//
//  Created by zsl on 2021/7/1.
//  Copyright © 2021 FunPlus. All rights reserved.
//

#import "VideoViewController.h"
#import <Rtm/Rtm.h>
@interface VideoViewController ()<RTMProtocol,RTMVideoProtocol>
@property(nonatomic,strong)UIButton * joinRoomButton;
@property(nonatomic,strong)UIButton * createRoomButton;
@property(nonatomic,strong)UIButton * subscribeUserButton;
@property(nonatomic,strong)UIButton * exitRoomButton;
@property(nonatomic,strong)RTMClient * client;
@end

@implementation VideoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    self.createRoomButton.frame = CGRectMake(100, 150, 100, 40);
    [self.view addSubview:self.createRoomButton];
    
    
    self.joinRoomButton.frame = CGRectMake(100, 250, 100, 40);
    [self.view addSubview:self.joinRoomButton];
    
    
    self.subscribeUserButton.frame = CGRectMake(100, 350, 100, 40);
    [self.view addSubview:self.subscribeUserButton];
    
    
    self.exitRoomButton.frame = CGRectMake(100, 450, 100, 40);
    [self.view addSubview:self.exitRoomButton];
    
    
    
    self.client = [RTMClient clientWithEndpoint:@"rtm endpoint"
                                  projectId:0
                                     userId:666
                                   delegate:self
                                     config:nil
                                autoRelogin:YES];
    
    self.client.rtcEndpoint = @"rtc endpoint";
    self.client.videoDelegate = self;
    
    
    [self.client loginWithToken:@"token"
                       language:@"en"
                      attribute:@{@"aaa":@"bbb"}
                        timeout:30
                        success:^{
        
        //视频初始化
        RTMBaseAnswer * an = [self.client setVideoEngine];
        if (an.error == nil) {
            NSLog(@"登录成功 + 视频初始化成功");
        }else{
            NSLog(@"%@",an.error);
        }
        
        
    } connectFail:^(FPNError * _Nullable error) {
        
        NSLog(@"login error %@",error);
       
        
    }];
    
}
#pragma mark client代理通知  必须要实现
-(BOOL)rtmReloginWillStart:(RTMClient *)client reloginCount:(int)reloginCount{
    
    //每次重连前会询问是否重连
    return YES;
}
-(void)rtmReloginCompleted:(RTMClient *)client reloginCount:(int)reloginCount reloginResult:(BOOL)reloginResult error:(FPNError *)error{
    //重连结果
    NSLog(@"重连成功后需要重新加入房间 并订阅用户");
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
    
    NSMutableArray * uids = [NSMutableArray array];
    UIView * uidsItemView = [UIView new];
    uidsItemView.backgroundColor = [UIColor redColor];
    uidsItemView.frame = CGRectMake(200, 550, 120, 160);
    [self.view addSubview:uidsItemView];
    [uids addObject:uidsItemView];
//
    [self.client subscribeVideoWithRoomId:@(666)
                                      uid:@[@(777)]
                           containerViews:uids
                                  timeout:10 success:^{
       
        NSLog(@"订阅成功");
    
        
    } fail:^(FPNError * _Nullable error) {
        
        NSLog(@"订阅失败%@",error);
        
    }];
    
}
-(void)_joinRoomButtonClick{
    
    [self.client enterVideoRoomWithRoomId:@(666)
                                  timeout:10
                                  success:^(RTMVideoEnterRoomAnswer * _Nonnull answer) {
        
        
        NSLog(@"加入房间成功");
        dispatch_async(dispatch_get_main_queue(), ^{
            
            [self.view addSubview:self.client.mySelfPreview];
            self.client.mySelfPreview.backgroundColor = [UIColor orangeColor];
            self.client.mySelfPreview.frame = CGRectMake(50, 550, 120, 160);
            [self.client updatePreviewFrame];
            
        });
        
        [self.client openCamera];
        
    } fail:^(FPNError * _Nullable error) {
        
        NSLog(@"加入房间失败%@",error);
        
    }];
    
}
-(void)_createRoomButtonClick{
    
    [self.client createVideoRoomWithId:@(666)
                               timeout:10
                               success:^(RTMVideoCreateRoomAnswer * _Nonnull answer) {
        
        NSLog(@"创建成功");
        
    } fail:^(FPNError * _Nullable error) {
        
        NSLog(@"创建失败%@",error);
    }];
    
}
-(void)_exitRoomButtonClick{
    [self.client exitVideoRoomWithRoomId:@(666)
                                 timeout:11
                                 success:^{
        
        
        NSLog(@"退出成功");
        
        
    } fail:^(FPNError * _Nullable error) {
        
        NSLog(@"退出失败%@",error);
        
    }];
}
-(UIButton*)createRoomButton{
    if (_createRoomButton == nil) {
        _createRoomButton = [UIButton buttonWithType:UIButtonTypeCustom];
        _createRoomButton.backgroundColor = [UIColor orangeColor];
        [_createRoomButton setTitle:@"创建房间" forState:UIControlStateNormal];
        [_createRoomButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_createRoomButton addTarget:self action:@selector(_createRoomButtonClick) forControlEvents:UIControlEventTouchUpInside];
    }
    return _createRoomButton;
}
-(UIButton*)joinRoomButton{
    if (_joinRoomButton == nil) {
        _joinRoomButton = [UIButton buttonWithType:UIButtonTypeCustom];
        _joinRoomButton.backgroundColor = [UIColor orangeColor];
        [_joinRoomButton setTitle:@"加入房间" forState:UIControlStateNormal];
        [_joinRoomButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_joinRoomButton addTarget:self action:@selector(_joinRoomButtonClick) forControlEvents:UIControlEventTouchUpInside];
    }
    return _joinRoomButton;
}
-(UIButton*)subscribeUserButton{
    if (_subscribeUserButton == nil) {
        _subscribeUserButton = [UIButton buttonWithType:UIButtonTypeCustom];
        _subscribeUserButton.backgroundColor = [UIColor orangeColor];
        [_subscribeUserButton setTitle:@"订阅用户" forState:UIControlStateNormal];
        [_subscribeUserButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_subscribeUserButton addTarget:self action:@selector(_subscribeButtonClick) forControlEvents:UIControlEventTouchUpInside];
    }
    return _subscribeUserButton;
}
-(UIButton*)exitRoomButton{
    if (_exitRoomButton == nil) {
        _exitRoomButton = [UIButton buttonWithType:UIButtonTypeCustom];
        _exitRoomButton.backgroundColor = [UIColor orangeColor];
        [_exitRoomButton setTitle:@"退出房间" forState:UIControlStateNormal];
        [_exitRoomButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_exitRoomButton addTarget:self action:@selector(_exitRoomButtonClick) forControlEvents:UIControlEventTouchUpInside];
    }
    return _exitRoomButton;
}


@end
