//
//  RTMClient+FileToken.h
//  Rtm
//
//  Created by zsl on 2020/10/19.
//  Copyright © 2020 FunPlus. All rights reserved.
//

#import <Rtm/Rtm.h>
#import "FPNNTCPClient.h"
NS_ASSUME_NONNULL_BEGIN

@interface RTMClient (FileToken)
-(void)getP2PFileTokenWithId:(NSNumber*)userId
                     timeout:(int)timeout
                     success:(RTMAnswerSuccessCallBack)successCallback
                        fail:(RTMAnswerFailCallBack)failCallback;

    
-(void)getGroupFileTokenWithId:(NSNumber*)groupId
                       timeout:(int)timeout
                       success:(RTMAnswerSuccessCallBack)successCallback
                          fail:(RTMAnswerFailCallBack)failCallback;

                                  
-(void)getRoomFileTokenWithId:(NSNumber*)roomId
                      timeout:(int)timeout
                      success:(RTMAnswerSuccessCallBack)successCallback
                         fail:(RTMAnswerFailCallBack)failCallback;


-(void)getUploadFileTokenWithTimeout:(int)timeout
                             success:(RTMAnswerSuccessCallBack)successCallback
                                fail:(RTMAnswerFailCallBack)failCallback;



-(NSDictionary*)getFileQuestBody:(NSDictionary *)data
                           recvId:(NSNumber *)recvId
                         fileData:(NSData * _Nonnull)fileData
                         fileName:(NSString * _Nonnull)fileName
                       fileSuffix:(NSString * _Nonnull)fileSuffix
                         fileType:(RTMFileType)fileType
                           attrs:(NSDictionary*)attrs;
-(NSDictionary*)getAudioFileQuestBody:(NSDictionary *)data
                               recvId:(NSNumber *)recvId
                             fileData:(NSData * _Nonnull)fileData
                                 lang:(NSString * _Nonnull)lang
                             duration:(long long)duration
                                attrs:(NSDictionary*)attrs;
                            

-(FPNNTCPClient*)getFileClient:(NSString*)endPoint;

@end

NS_ASSUME_NONNULL_END

