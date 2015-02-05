//
//  NSMeapQRCodePlugin.h
//  Cordova_TEST
//
//  Created by 十九 on 13-7-19.
//
//

#import <Foundation/Foundation.h>
#import "CDVPlugin.h"

@interface NSMeapQRCodePlugin : CDVPlugin

//------------
//字符串生成二维码图片插件调用接口
//arguments: 参数数组
//0: id
//1:text 字符串
//2:imageSize 图片大小
//------------
-(void)qrImageForString:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

//-----------
//扫描二维码 插件接口
//arguments: 参数数组
//0: id
//1:superController 要调用扫面页面的controller
//-----------
-(void)scanQRCodeWithController:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;
@end
