//
//  NSMDataSecurityCD.h
//  Cordova_TEST
//
//  Created by yalin on 13-7-18.
//
//

#import <Foundation/Foundation.h>
#import "CDVPlugin.h"

@interface NSMeapDataSecurityPlugin : CDVPlugin

/**
 *	@brief	获取加密 解密密码
 *
 *	@param 	arguments 	参数数组
 *  0:id
 *  1:password 本地数据加密的密码
 *	@param 	options 	参数字典
 */
- (void)getPassword:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

/**
 *	@brief	设置加密 解密密码
 *
 *	@param 	arguments 	参数数组
 *  0:id
 *  1:password 本地数据加密的密码
 *  2:overTime 密码过期时间 
 *	@param 	options 	参数字典
 */
- (void)setPassword:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

/**
 *	@brief	加密一个字符串保存
 *
 *	@param 	arguments 	参数数组
 *  0:id
 *  1:string 需要加密的字符串
 *	@param 	options 	参数字典
 */
- (void)saveString:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

/**
 *	@brief	获取一个加密的字符串
 *
 *	@param 	arguments 	参数数组
 *  0:id
 *  1:stringID：加密的字符串的id
 *	@param 	options 	参数字典
 */
- (void)getString:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

/**
 *	@brief	加密一个文件
 *
 *	@param 	arguments 	参数数组
 *  0:id
 *  1:filePath 需要加密的文件的路径
 *	@param 	options 	参数字典
 */
- (void)saveFile:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

/**
*	@brief	获取一个加密的文件
*
*	@param 	arguments 	参数数组
*   0:id
*   1:fileID 加密的文件的id
*	@param 	options 	参数字典
*/
- (void)getFile:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

/**
 *	@brief	清空一个加密的数据
 *
 *	@param 	arguments 	参数数组
 *  0:id
 *  1:dataID：加密的字符串的id
 *	@param 	options 	参数字典
 */
- (void)clearData:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

/**
 *	@brief	清空所有加密的数据
 *
 *	@param 	arguments 	参数数组
 *   0:id
 *	@param 	options 	参数字典
 */
- (void)clearAll:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

/**
 *	@brief	给所有的数据加密
 */
- (void)encryAllData:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

/**
 *	@brief	给所有的数据解密
 */
- (void)decryAllData:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

@end
