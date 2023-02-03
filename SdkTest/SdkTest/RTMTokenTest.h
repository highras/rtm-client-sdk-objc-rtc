//
//  GeyTokenTest.h
//  SdkTest
//
//  Created by zsl on 2022/11/23.
//  Copyright © 2022 FunPlus. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTMTokenTest : NSObject
+(NSDictionary*)getToken:(NSString*)key projectId:(NSString*)pid uid:(NSString*)uid;
@end

NS_ASSUME_NONNULL_END
