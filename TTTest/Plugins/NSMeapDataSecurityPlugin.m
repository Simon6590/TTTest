//
//  NSMDataSecurityCD.m
//  Cordova_TEST
//
//  Created by yalin on 13-7-18.
//
//

#import "NSMeapDataSecurityPlugin.h"
#import <NSMeap/NSMeapDataSecurity.h>

@implementation NSMeapDataSecurityPlugin

/**
 *	@brief	获取加密 解密密码
 *
 *	@param 	arguments 	参数数组
 *  0:id
 *  1:Password：本地数据加密的密码
 *	@param 	options 	参数字典
 */
- (void)getPassword:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    NSString *currentCallBackID = [arguments objectAtIndex:0];
    NSString *password = [[NSMeapDataSecurity shareNSMeapDataSecurity] password];
    
    CDVPluginResult *result = nil;
    NSString *returnStr = password == nil ? @"null" : password;
    result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:returnStr];
    [self success:result callbackId:currentCallBackID];
}

/**
 *	@brief	设置加密 解密密码
 *
 *	@param 	arguments 	参数数组
 *  0:id
 *  1:Password：本地数据加密的密码
 *	@param 	options 	参数字典
 */
- (void)setPassword:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    NSString *currentCallBackID = [arguments objectAtIndex:0];
    NSString *password = [arguments objectAtIndex:1];
    NSString *overTime = [arguments objectAtIndex:2];
    
    CDVPluginResult *result = nil;
    
    NSError *error = nil;
    if ([[NSMeapDataSecurity shareNSMeapDataSecurity] setOrCheckPassword:password overTime:overTime.integerValue error:&error])
    {
        if (error != nil)
        {
            result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.domain];
            [self error:result callbackId:currentCallBackID];
        }
        else
        {
            result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"设置成功!"];
            [self success:result callbackId:currentCallBackID];
        }
        
    }
    else
    {
        if (error != nil)
        {
            result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.domain];
            [self error:result callbackId:currentCallBackID];
        }
        else
        {
            result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"设置失败!"];
            [self error:result callbackId:currentCallBackID];
        }
        
    }
}

/**
 *	@brief	加密一个字符串保存
 *
 *	@param 	arguments 	参数数组
 *  0:id
 *  1:string：需要加密的字符串
 *	@param 	options 	参数字典
 */
- (void)saveString:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    NSString *currentCallBackID = [arguments objectAtIndex:0];
    NSString *string = [arguments objectAtIndex:1];
    
    NSError *error = nil;
    NSString *stringID = [[NSMeapDataSecurity shareNSMeapDataSecurity] saveString:string error:&error];
    
    CDVPluginResult *result = nil;
    if (!error)
    {
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:stringID];
        [self success:result callbackId:currentCallBackID];
    }
    else
    {
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.domain];
        [self error:result callbackId:currentCallBackID];
    }
}

/**
 *	@brief	获取一个加密的字符串
 *
 *	@param 	arguments 	参数数组
 *  0:id
 *  1:stringID：加密的字符串的id
 *	@param 	options 	参数字典
 */
- (void)getString:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    NSString *currentCallBackID = [arguments objectAtIndex:0];
    if ([arguments count] != 2) {
       
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"参数错误"];
        [self error:result callbackId:currentCallBackID];
         return;
    }
    NSString *stringID = [arguments objectAtIndex:1];
    
    NSError *error = nil;
    NSString *string = [[NSMeapDataSecurity shareNSMeapDataSecurity] getStringWithID:stringID error:&error];
    
    CDVPluginResult *result = nil;
    if (!error)
    {
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:string];
        [self success:result callbackId:currentCallBackID];
    }
    else
    {
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.domain];
        [self error:result callbackId:currentCallBackID];
    }
}

/**
 *	@brief	加密一个文件
 *
 *	@param 	arguments 	参数数组
 *  0:id
 *  1:filePath：需要加密的文件的路径
 *	@param 	options 	参数字典
 */
- (void)saveFile:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    
    NSString *currentCallBackID = [arguments objectAtIndex:0];
    
    if ([arguments count] != 2) {
        
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"参数错误"];
        [self error:result callbackId:currentCallBackID];
        return;
    }
    NSString *filePath = [arguments objectAtIndex:1];
    
    NSError *error = nil;
    NSString *stringID = [[NSMeapDataSecurity shareNSMeapDataSecurity] saveFile:filePath error:&error];
    
    CDVPluginResult *result = nil;
    if (!error)
    {
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:stringID];
        [self success:result callbackId:currentCallBackID];
    }
    else
    {
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.domain];
        [self error:result callbackId:currentCallBackID];
    }
}

/**
 *	@brief	获取一个加密的文件
 *
 *	@param 	arguments 	参数数组
 *   0:id
 *   1:fileID：加密的文件的id
 *	@param 	options 	参数字典
 */
- (void)getFile:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    NSString *currentCallBackID = [arguments objectAtIndex:0];
    if ([arguments count] != 2) {
        
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"参数错误"];
        [self error:result callbackId:currentCallBackID];
        return;
    }
    NSString *fileID = [arguments objectAtIndex:1];
    
    NSError *error = nil;
    NSString *string = [[NSMeapDataSecurity shareNSMeapDataSecurity] getFileWithID:fileID error:&error];
    
    CDVPluginResult *result = nil;
    if (!error)
    {
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:string];
        [self success:result callbackId:currentCallBackID];
    }
    else
    {
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.domain];
        [self error:result callbackId:currentCallBackID];
    }
}

/**
 *	@brief	清空一个加密的数据
 *
 *	@param 	arguments 	参数数组
 *  0:id
 *  1:dataID：加密的数据的id
 *	@param 	options 	参数字典
 */
- (void)clearData:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
      NSString *currentCallBackID = [arguments objectAtIndex:0];
    if ([arguments count] != 2) {
        
        CDVPluginResult *result = nil;
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"参数错误"];
        [self error:result callbackId:currentCallBackID];
        return;
    }
    NSString *dataID = [arguments objectAtIndex:1];
    NSError *error = nil;
    [[NSMeapDataSecurity shareNSMeapDataSecurity] clearID:dataID error:&error];
    
  
    CDVPluginResult *result = nil;
    if (!error)
    {
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"删除数据成功"];
        [self success:result callbackId:currentCallBackID];
    }
    else
    {
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.domain];
        [self error:result callbackId:currentCallBackID];
    }
}

/**
 *	@brief	清空所有加密的数据
 *
 *	@param 	arguments 	参数数组
 *   0:id
 *	@param 	options 	参数字典
 */
- (void)clearAll:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    NSError *error = nil;
    [[NSMeapDataSecurity shareNSMeapDataSecurity] clearAllData:&error];
    
    NSString *currentCallBackID = [arguments objectAtIndex:0];
    CDVPluginResult *result = nil;
    if (!error)
    {
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"清空数据成功"];
        [self success:result callbackId:currentCallBackID];
    }
    else
    {
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.domain];
        [self error:result callbackId:currentCallBackID];
    }
}

/**
 *	@brief	给所有的数据加密
 */
- (void)encryAllData:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    NSError *error = nil;
    [[NSMeapDataSecurity shareNSMeapDataSecurity] encrypteAllData:&error];
    NSString *currentCallBackID = [arguments objectAtIndex:0];
    CDVPluginResult *result = nil;
    if (!error)
    {
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"加密数据成功"];
        [self success:result callbackId:currentCallBackID];
    }
    else
    {
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.domain];
        [self error:result callbackId:currentCallBackID];
    }
}

/**
 *	@brief	给所有的数据解密
 */
- (void)decryAllData:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    NSError *error = nil;
    [[NSMeapDataSecurity shareNSMeapDataSecurity] decrypteAllData:&error];
    NSString *currentCallBackID = [arguments objectAtIndex:0];
    CDVPluginResult *result = nil;
    if (!error)
    {
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"解密数据成功"];
        [self success:result callbackId:currentCallBackID];
    }
    else
    {
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:error.domain];
        [self error:result callbackId:currentCallBackID];
    }
}

@end
