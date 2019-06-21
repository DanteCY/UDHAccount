//
//  UDHUser.h
//  UDHAccount
//
//  Created by hcy on 2019/6/21.
//  Copyright © 2019 yd. All rights reserved.
//

#ifndef UDHUser_h
#define UDHUser_h

/**
 用户信息
 */
@protocol UDHUser <NSObject>
-(NSString *)account;
-(NSString *)nick;
-(NSInteger)gender;
-(NSString *)iconPath;

@end



#endif /* UDHUser_h */
