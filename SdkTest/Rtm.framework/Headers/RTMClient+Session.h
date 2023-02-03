//
//  RTMClient+Conversations.h
//  Rtm
//
//  Created by zsl on 2022/11/22.
//  Copyright © 2022 FunPlus. All rights reserved.
//

#import <Rtm/Rtm.h>
#import "RTMHistoryMessage.h"
#import "RTMConversation.h"
NS_ASSUME_NONNULL_BEGIN

@interface RTMClient (Conversations)

/// 获取所有p2p会话列表
/// @param mtime mtime参数为毫秒级时间戳，大于该时间戳的消息被计为未读消息，未读消息的最后一条作为会话的最后一条消息。不传则默认取上次离线时间。
/// @param messageType 参数为消息类型列表，不传则默认查询mtype为30-50的消息
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)getP2pConversationsList:(int64_t)mtime
                   messageType:(NSArray <NSNumber*>* _Nullable)messageType
                       timeout:(int)timeout
                       success:(void(^)(RTMConversation * sendAnswer))successCallback
                          fail:(RTMAnswerFailCallBack)failCallback;


/// 获取所有群组会话列表
/// @param mtime 参数为毫秒级时间戳，大于该时间戳的消息被计为未读消息，未读消息的最后一条作为会话的最后一条消息。不传则默认取上次离线时间。
/// @param messageType 参数为消息类型列表，不传则默认查询mtype为30-50的消息
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)getGroupConversationsList:(int64_t)mtime
                     messageType:(NSArray <NSNumber*>* _Nullable)messageType
                         timeout:(int)timeout
                         success:(void(^)(RTMConversation * sendAnswer))successCallback
                            fail:(RTMAnswerFailCallBack)failCallback;



/// 获取p2p未读会话列表
/// @param mtime mtime参数为毫秒级时间戳，大于该时间戳的消息被计为未读消息，未读消息的最后一条作为会话的最后一条消息。不传则默认取上次离线时间。
/// @param messageType 参数为消息类型列表，不传则默认查询mtype为30-50的消息
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)getP2pUnreadConversationsList:(int64_t)mtime
                         messageType:(NSArray <NSNumber*>* _Nullable)messageType
                             timeout:(int)timeout
                             success:(void(^)(RTMConversation * sendAnswer))successCallback
                                fail:(RTMAnswerFailCallBack)failCallback;



/// 获取所有群组未读会话列表
/// @param mtime mtime参数为毫秒级时间戳，大于该时间戳的消息被计为未读消息，未读消息的最后一条作为会话的最后一条消息。不传则默认取上次离线时间。
/// @param messageType 参数为消息类型列表，不传则默认查询mtype为30-50的消息
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)getGroupUnreadConversationsList:(int64_t)mtime
                           messageType:(NSArray <NSNumber*>* _Nullable)messageType
                               timeout:(int)timeout
                               success:(void(^)(RTMConversation * sendAnswer))successCallback
                                  fail:(RTMAnswerFailCallBack)failCallback;



/// 获取所有未读会话列表
/// @param mtime 参数为毫秒级时间戳，大于该时间戳的消息被计为未读消息，未读消息的最后一条作为会话的最后一条消息。不传则默认取上次离线时间。
/// @param clear 参数为是否清除会话未读状态
/// @param messageType 参数为消息类型列表，不传则默认查询mtype为30-50的消息
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)getUnreadConversationsList:(int64_t)mtime
                            clear:(BOOL)clear
                      messageType:(NSArray <NSNumber*>* _Nullable)messageType
                          timeout:(int)timeout
                          success:(void(^)(RTMConversation * p2pConversation,RTMConversation * groupConversation))successCallback
                             fail:(RTMAnswerFailCallBack)failCallback;



/// 删除p2p会话
/// @param toId 参数为p2p会话中对方的uid
/// @param timeout 请求超时时间 秒
/// @param successCallback 成功回调
/// @param failCallback 失败回调
-(void)removeConversation:(int64_t)toId
                  timeout:(int)timeout
                  success:(void(^)(void))successCallback
                     fail:(RTMAnswerFailCallBack)failCallback;

@end


NS_ASSUME_NONNULL_END

