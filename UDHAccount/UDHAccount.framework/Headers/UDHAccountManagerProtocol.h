//
//  YDIOTSDKLoginManagerProtocol.h
//  uodi_iot_ios
//
//  Created by hcy on 2019/4/10.
//  Copyright © 2019 yd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UDHUser.h"
NS_ASSUME_NONNULL_BEGIN
/**
 *  登录服务相关Block
 *
 *  @param error 执行结果,如果成功error为nil
 */
typedef void(^YDIOTSDKLoginHandler)(NSError * __nullable error);

/**
 登录代理
 */
@protocol DIOTSDKLoginManagerDelegate <NSObject>

@end

@protocol UDHAccountManager <NSObject>
/**
 *  登录
 *
 *  @param account    帐号
 *  @param token      令牌
 *  @param completion 完成回调
 */
- (void)login:(NSString *)account
        token:(NSString *)token
   completion:(YDIOTSDKLoginHandler)completion;

/**
 *  登出
 *
 *  @param completion 完成回调
 *  @discussion 用户在登出是需要调用这个接口进行 SDK 相关数据的清理,回调 Block 中的 error 只是指明和服务器的交互流程中可能出现的错误,但不影响后续的流程。
 *              如用户登出时发生网络错误导致服务器没有收到登出请求，客户端仍可以登出(切换界面，清理数据等)，但会出现推送信息仍旧会发到当前手机的问题。
 */
- (void)logout:(nullable YDIOTSDKLoginHandler)completion;

/**
 *  返回当前登录帐号
 *
 *  @return 当前登录帐号,如果没有登录成功,这个地方会返回空字符串""
 */
- (NSString *)currentAccount;

/**
 当前登录的用户

 @return 当前用户对象。没有登录的话是nil
 */
-(__nullable  id<UDHUser>)currentUser;
/**
 *  当前登录状态
 *
 *  @return 当前登录状态
 */
- (BOOL)isLogined;

/**
 *  添加登录委托
 *
 *  @param delegate 登录委托
 */
- (void)addDelegate:(id<DIOTSDKLoginManagerDelegate>)delegate;

/**
 *  移除登录委托
 *
 *  @param delegate 登录委托
 */
- (void)removeDelegate:(id<DIOTSDKLoginManagerDelegate>)delegate;

@end





NS_ASSUME_NONNULL_END
