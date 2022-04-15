//
//  AudioViewController.m
//  SdkTest
//
//  Created by zsl on 2021/3/24.
//  Copyright © 2021 FunPlus. All rights reserved.
//

#import "AudioViewController.h"
#import "UIImage+RTM.h"
#import <Rtm/Rtm.h>
#import "NSObject+Description.h"

@interface AudioViewController ()<RTMProtocol,RTMVoiceProtocol>
@property(nonatomic,strong)RTMClient* client;
@property(nonatomic,strong)UIButton * openSpeak;
@property(nonatomic,strong)UIButton * openPlay;
@end

@implementation AudioViewController


- (void)viewDidLoad {
    [super viewDidLoad];

    self.view.backgroundColor = [UIColor whiteColor];
    
    [self.view addSubview:self.openSpeak];
    self.openSpeak.frame = CGRectMake(100, 100, 200, 50);
    
    [self.view addSubview:self.openPlay];
    self.openPlay.frame = CGRectMake(100, 200, 200, 50);
    
    //1 初始化Rtm
    self.client = [RTMClient clientWithEndpoint:@""
                                      projectId:123
                                     userId:777
                                   delegate:self
                                     config:nil];
    
    self.client.rtcEndpoint = @"";
    self.client.voiceDelegate = self;
    [self _login];
    
}
-(void)_login{
    [self.client loginWithToken:@""
                       language:@"en"
                      attribute:@{@"aaa":@"bbb"}
                        timeout:30
                        success:^{
        
        NSLog(@"client 登录成功");
        [self _createRoom];
        
    } connectFail:^(FPNError * _Nullable error) {
        
        NSLog(@"client 登录失败  %@",error);
        
    }];
}

-(void)_createRoom{
    
    [self.client createVoiceRoomWithId:@(111)
                          enableRecord:NO
                               timeout:10
                               success:^(RTMVoiceCreateRoomAnswer * answer) {
        
        NSLog(@"创建并加入房间成功");
        //创建成功后会自动加入该房间
        [self.client setCurrentVoiceActiveRoom:111];
        //可同时加入多个房间  但是只会播放发送 voiceActiveRoom 活跃房间的实时语音  默认-1为未设置  语音结束后设置为-1
        //voiceActiveRoom 只会对已加入成功的房间设置生效
        
        //每次设置voiceActiveRoom后  isOpenVoicePlay为YES  isOpenVoiceSpeak为NO
        self.client.isOpenVoicePlay = YES;
        self.client.isOpenVoiceSpeak = YES;
        
        dispatch_async(dispatch_get_main_queue(), ^{
            self.openPlay.selected = self.client.isOpenVoicePlay;
            self.openSpeak.selected = self.client.isOpenVoiceSpeak;
        });
        
    } fail:^(FPNError * _Nullable error) {
        
        NSLog(@"创建房间失败 %@",error);
        //如果房间已经存在  可以直接加入enterVoiceRoomWithRoomId
        if (error.code == 700004) {
            //创建房间失败 该房间已经存在
            [self _joinVioceRoom];
        }
        
        
    }];
}
-(void)_joinVioceRoom{
    
    [self.client enterVoiceRoomWithRoomId:@(111)
                                  timeout:10
                                  success:^(RTMVoiceEnterRoomAnswer * answer) {
        
        NSLog(@"加入房间成功");
        
        [self.client setCurrentVoiceActiveRoom:111];
        //可同时加入多个房间  但是只会播放发送 voiceActiveRoom 活跃房间的实时语音  默认-1为未设置  语音结束后设置为-1
        //voiceActiveRoom 只会对已加入成功的房间设置生效
        
        //每次设置voiceActiveRoom后  isOpenVoicePlay为YES  isOpenVoiceSpeak为NO
        self.client.isOpenVoicePlay = YES;
        self.client.isOpenVoiceSpeak = YES;
        dispatch_async(dispatch_get_main_queue(), ^{
            self.openPlay.selected = self.client.isOpenVoicePlay;
            self.openSpeak.selected = self.client.isOpenVoiceSpeak;
        });
        
    } fail:^(FPNError * _Nullable error) {
        
        NSLog(@"加入房间失败~~  %@",error);
        
    }];
}


#pragma mark client代理通知  必须要实现
-(BOOL)rtmReloginWillStart:(RTMClient *)client reloginCount:(int)reloginCount{
    
    //每次重连前会询问是否重连
    return YES;
}
-(void)rtmReloginCompleted:(RTMClient *)client reloginCount:(int)reloginCount reloginResult:(BOOL)reloginResult error:(FPNError *)error{
    //重连结果
    NSLog(@"重连成功后需要重新加入房间 并设置活跃房间");
}

-(void)rtmErrorLog:(NSString *)errorLog{
    NSLog(@"%@",errorLog);
}
#pragma mark 实时语音代理通知
//某人进入房间
-(void)userEnterVoiceRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId time:(int64_t)time{
    NSLog(@"userEnterVoiceRoomNotificationWithRoomId  roomId = %lld  userId = %lld time = %lld ",roomId,userId,time);
}
//某人离开房间
-(void)userExitVoiceRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId time:(int64_t)time{
    NSLog(@"userExitVoiceRoomNotificationWithRoomId  roomId = %lld  userId = %lld time = %lld ",roomId,userId,time);
}
//房间关闭
-(void)voiceRoomCloseNotificationWithRoomId:(int64_t)roomId{
    NSLog(@"voiceRoomCloseNotificationWithRoomId  roomId = %lld   ",roomId);
}
//从房间被踢出
-(void)kickOutVoiceRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId{
    NSLog(@"kickOutVoiceRoomNotificationWithRoomId  roomId = %lld  userId = %lld ",roomId,userId);
}
//被邀请进入房间
-(void)inviteIntoVoiceRoomNotificationWithRoomId:(int64_t)roomId userId:(int64_t)userId{
    NSLog(@"inviteIntoVoiceRoomNotificationWithRoomId  roomId = %lld  userId = %lld ",roomId,userId);
}
//被强制拉入房间结果
-(void)forceInviteIntoVoiceRoomNotificationWithRoomId:(int64_t)roomId error:(FPNError * _Nullable)error{
    NSLog(@"forceInviteIntoVoiceRoomNotificationWithRoomId  roomId = %lld error = %@ ",roomId,error);
}
//权限控制
-(void)pushVoiceAdminCommand:(NSArray *)uids command:(int)type{
    
}



-(void)_openSpeakClick{
    
    if (self.client.voiceActiveRoom != -1) {
        self.client.isOpenVoiceSpeak = !self.client.isOpenVoiceSpeak;
        self.openSpeak.selected = self.client.isOpenVoiceSpeak;
    }
    
}
-(void)_openPlayClick{
    
    if (self.client.voiceActiveRoom != -1) {
        self.client.isOpenVoicePlay = !self.client.isOpenVoicePlay;
        self.openPlay.selected = self.client.isOpenVoicePlay;
    }
    
}
-(UIButton*)openSpeak{
    if (_openSpeak == nil) {
        _openSpeak = [UIButton buttonWithType:UIButtonTypeCustom];
        [_openSpeak setTitle:@"已打开麦克风" forState:UIControlStateSelected];
        [_openSpeak setTitle:@"已关闭麦克风" forState:UIControlStateNormal];
        [_openSpeak setTitleColor:[UIColor whiteColor] forState:UIControlStateSelected];
        [_openSpeak setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_openSpeak setBackgroundImage:[UIImage imageWithColor:[UIColor greenColor]]forState:UIControlStateSelected];
        [_openSpeak setBackgroundImage:[UIImage imageWithColor:[UIColor redColor]] forState:UIControlStateNormal];
        [_openSpeak addTarget:self action:@selector(_openSpeakClick) forControlEvents:UIControlEventTouchUpInside];
        _openSpeak.layer.masksToBounds = YES;
        _openSpeak.layer.cornerRadius = 5;
    }
    return _openSpeak;
}
-(UIButton*)openPlay{
    if (_openPlay == nil) {
        _openPlay = [UIButton buttonWithType:UIButtonTypeCustom];
        [_openPlay setTitle:@"已打开扬声器" forState:UIControlStateSelected];
        [_openPlay setTitle:@"已关闭扬声器" forState:UIControlStateNormal];
        [_openPlay setTitleColor:[UIColor whiteColor] forState:UIControlStateSelected];
        [_openPlay setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_openPlay setBackgroundImage:[UIImage imageWithColor:[UIColor greenColor]] forState:UIControlStateSelected];
        [_openPlay setBackgroundImage:[UIImage imageWithColor:[UIColor redColor]] forState:UIControlStateNormal];
        [_openPlay addTarget:self action:@selector(_openPlayClick) forControlEvents:UIControlEventTouchUpInside];
        _openPlay.selected = YES;
        _openPlay.layer.masksToBounds = YES;
        _openPlay.layer.cornerRadius = 5;
    }
    return _openPlay;
}



@end
