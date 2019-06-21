//
//  UDHAccountManager.m
//  uodi_iot_ios
//
//  Created by hcy on 2019/4/17.
//  Copyright © 2019 yd. All rights reserved.
//

#import "UDHAccountManager.h"
#import "UDHUser.h"
@interface YDIOTUser : NSObject<UDHUser>
@property(copy,nonatomic)NSString *account;
@property(copy,nonatomic)NSString *nick;
@property(copy,nonatomic)NSString *iconPath;
@property(assign,nonatomic)int gender;
@end
@implementation YDIOTUser


@end




@interface UDHAccountManager()

@property(strong,nonatomic)YDIOTUser *user;
@end
@implementation UDHAccountManager

+(instancetype)sharedInstance{
    static UDHAccountManager *manager;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        manager=[UDHAccountManager new];
    });
    return manager;
}

-(void)login:(NSString *)account token:(NSString *)token completion:(YDIOTSDKLoginHandler)completion{
#warning 网络请求
    YDIOTUser *user=[YDIOTUser new];
    user.account=account;
    user.nick=@"昵称少年";
    user.gender=1;
    user.iconPath=@"";
    self.user=user;
    
    completion(nil);
    
}
-(void)logout:(YDIOTSDKLoginHandler)completion{
#warning 网络请求
    self.user=nil;
    completion(nil);
}

-(NSString *)currentAccount{
    return self.user?self.user.account:@"";
}

-(BOOL)isLogined{
    return self.user!=nil;
}
- (id<UDHUser>)currentUser {
    return self.user;
}



- (void)addDelegate:(nonnull id<DIOTSDKLoginManagerDelegate>)delegate {
    
}





- (void)removeDelegate:(nonnull id<DIOTSDKLoginManagerDelegate>)delegate {
    
}




@end
