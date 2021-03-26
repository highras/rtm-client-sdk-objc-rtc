//
//  AppDelegate.m
//  Test
//
//  Created by zsl on 2019/11/27.
//  Copyright © 2019 FunPlus. All rights reserved.
//

#import "AppDelegate.h"
#import "FunctionSelectionViewController.h"


@interface AppDelegate ()

@end

@implementation AppDelegate
                

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UINavigationController * nav = [[UINavigationController alloc]initWithRootViewController:[[FunctionSelectionViewController alloc]init] ];
    [self.window setRootViewController:nav];
    [self.window makeKeyAndVisible];

    
    return YES;
}


@end
