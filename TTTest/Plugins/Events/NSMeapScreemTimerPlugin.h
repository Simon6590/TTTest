//
//  NSMeapScreemTimerPlugin.h
//  Cordova_TEST
//
//  Created by Yalin on 14-3-19.
//
//

/**
 * @file        NSMeapScreemTimerPlugin.h
 * @brief       屏幕动作监听插件.
 * @version     1.0
 * @date        2014-3-19
 *
 * [2014-03-19] <杨亚霖> v1.0
 *
 * + v1.0版发布.
 *
 */

#import <Foundation/Foundation.h>
#import "CDVPlugin.h"

/**
 *  屏幕触摸事件计时器,需要在html代码中加入下面这句代码.
 *  <script language="javascript">
        document.ontouchstart=function()
        {
            document.location="myweb:touch:start";
        };
        document.ontouchend=function()
        {
            document.location="myweb:touch:end";
        };
        document.ontouchmove=function()
        {
            document.location="myweb:touch:move";
        }
     </script>
 */
@interface NSMeapScreemTimerPlugin : CDVPlugin

/**
 *  监听屏幕动作开始
 *
 *  @param arguments 参数 [到时时间(以秒为单位)]
 *  @param options   配置
 */
- (void)startListener:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options;

@end
