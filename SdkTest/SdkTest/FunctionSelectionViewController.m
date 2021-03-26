//
//  FunctionSelectionViewController.m
//  SdkTest
//
//  Created by zsl on 2021/3/24.
//  Copyright © 2021 FunPlus. All rights reserved.
//

#import "FunctionSelectionViewController.h"
#import "NormalViewController.h"
#import "AudioViewController.h"
@interface FunctionSelectionViewController ()

@end

@implementation FunctionSelectionViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    UIButton * normalButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [normalButton setTitle:@"常规使用" forState:UIControlStateNormal];
    normalButton.frame = CGRectMake(100, 100, 200, 50);
    normalButton.backgroundColor = [UIColor orangeColor];
    [normalButton addTarget:self action:@selector(normalClick) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:normalButton];
    
    UIButton * audioButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [audioButton setTitle:@"实时语音" forState:UIControlStateNormal];
    audioButton.frame = CGRectMake(100, 200, 200, 50);
    audioButton.backgroundColor = [UIColor orangeColor];
    [audioButton addTarget:self action:@selector(audioClick) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:audioButton];
    
}
-(void)normalClick{
    [self.navigationController pushViewController:[NormalViewController new] animated:YES];
}
-(void)audioClick{
    [self.navigationController pushViewController:[AudioViewController new] animated:YES];
}
/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
