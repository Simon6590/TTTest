//
//  NSString+YY_Unit_Method.h
//  TextActionSheet
//
//  Created by yangyalin on 12-12-1.
//
//

#import <Foundation/Foundation.h>

#pragma mark - 单例定义宏
//----------------------------------------------------------------------/
/*
 * 单例定义宏
 */
//* 单例interface
#define CLASS_SINGLETON_INTERFACE(classname)                            \
                                         \
+ (classname *)share##classname;


//* 单例implementation
#define CLASS_SINGLETON_IMPLEMENTATION(classname)                       \
static classname* shared##classname = nil;                              \
                                               \
+ (classname *)share##classname                                         \
{                                                                       \
@synchronized(self)                                                     \
{                                                                       \
if (shared##classname == nil)                                           \
{                                                                       \
shared##classname = [[self alloc] init];                                \
}                                                                       \
}                                                                       \
return shared##classname;                                               \
}                                                                       \
 
#pragma mark - 网络通知宏定义
//----------------------------------------------------------------------/
/*
 * 网络通知宏定义
 */
#define DEFINE_DECLARE_NOTIFICATION(name)               \
extern NSString *name##_NOTIFICATION_START;       \
extern NSString *name##_NOTIFICATION_SUCCESS;     \
extern NSString *name##_NOTIFICATION_FAIL;        \
extern NSString *name##_NOTIFICATION_END;       


#define DEFINE_REALIZE_NOTIFICATION(name)                               \
NSString *name##_NOTIFICATION_START                        \
= @"NOTIFICATION_START_"#name;                                          \
NSString *name##_NOTIFICATION_SUCCESS                      \
= @"NOTIFICATION_SUCCESS_"#name;                                        \
NSString *name##_NOTIFICATION_FAIL                         \
= @"NOTIFICATION_FAIL_"#name;                                           \
NSString *name##_NOTIFICATION_END                          \
= @"NOTIFICATION_END_"#name;

#pragma mark - 判断当前版本是否大于等于某个版本
//----------------------------------------------------------------------/
#define SYSTEM_VERSION_ABOVE_7 (([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0)? (YES):(NO))

#pragma mark - 通知的便捷方法
//----------------------------------------------------------------------/
/*
 * 通知的便捷方法
 */
CG_INLINE void ADD_NOTIFICATION(NSString *name, id target, SEL action, id object)
{
    [[NSNotificationCenter defaultCenter] addObserver:target selector:action name:name object:object];
}

CG_INLINE void REMOVE_NOTIFICATION(NSString *name, id target, id object)
{
    [[NSNotificationCenter defaultCenter] removeObserver:target name:name object:object];
}

CG_INLINE void POST_NOTIFICATION(NSString *name, id object, NSDictionary *userInfo)
{
    [[NSNotificationCenter defaultCenter] postNotificationName:name object:object userInfo:userInfo];
}

#pragma mark - NSDate、NSString转换
CG_INLINE NSDate* dateForString(NSString *dateStr, NSString*dateFormatter)
{
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:dateFormatter];
    NSDate *date = [formatter dateFromString:dateStr];
    return date;
}

CG_INLINE NSString* stringForDate(NSDate *date, NSString*dateFormatter)
{
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:dateFormatter];
    NSString *dateStr = [formatter stringFromDate:date];
    return dateStr;
}


#pragma mark - alert框
//* --------------------------------------------------------------------------//
/*
 * alert框
 */

CG_INLINE void AlertlogError (NSString* message)
{
    static UIAlertView *alertView = nil;
    if (!alertView)
    {
        alertView = [[UIAlertView alloc] initWithTitle:  @""
                                                              message: message
                                                             delegate: nil
                                                    cancelButtonTitle: @"OK"
                                                    otherButtonTitles: nil,
                                    nil];
        [alertView show];
    }
    else if ([alertView isVisible])
    {
        
        [alertView dismissWithClickedButtonIndex:0 animated:NO];
#if !__has_feature(objc_arc)
        [alertView release];
#else
#endif
        
        alertView = nil;
        alertView = [[UIAlertView alloc] initWithTitle:  @""
                                                message: message
                                               delegate: nil
                                      cancelButtonTitle: @"OK"
                                      otherButtonTitles: nil,
                      nil];
        [alertView show];
    }
    else
    {
        [alertView dismissWithClickedButtonIndex:0 animated:NO];
#if !__has_feature(objc_arc)
        [alertView release];
#else
#endif
        alertView = nil;
        alertView = [[UIAlertView alloc] initWithTitle:  @""
                                                message: message
                                               delegate: nil
                                      cancelButtonTitle: @"OK"
                                      otherButtonTitles: nil,
                      nil];
        [alertView show];
    }
}

//* DEBUG NSLOG
CG_INLINE void DEBUG_NSLOG (NSString *format, ...)
{
    
#if DEBUG
    va_list args;
    va_start(args,format);
    if (format != nil)
    {
        NSLogv(format, args);
    }
#endif
     
}

#pragma mark - 获取一些系统信息
//* --------------------------------------------------------------------------//
/*
 * 获取一些系统信息
 */
#import "sys/utsname.h"

//* 系统版本号
#define SYSTEM_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]

//* 应用版本号
#define APP_VERSION [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]
 
/*  设备类型
 *  get the information of the device and system
 *  "i386"          simulator
 *  "iPod1,1"       iPod Touch
 *  "iPhone1,1"     iPhone
 *  "iPhone1,2"     iPhone 3G
 *  "iPhone2,1"     iPhone 3GS
 *  "iPad1,1"       iPad
 *  "iPhone3,1"     iPhone 4
 *  @return null
 */
#define DEVICE_NAME() struct utsname systemInfo;                        \
                uname(&systemInfo);                                     \
                return [NSString stringWithCString:systemInfo.machine encoding:NSUTF8StringEncoding];


#pragma mark - URL编码
//* --------------------------------------------------------------------------//
/*
 * URL编码
 */

CG_INLINE NSString* URLEncode(NSString *string)
{
    #if !__has_feature(objc_arc)
    NSString *newString = NSMakeCollectable([(NSString *)CFURLCreateStringByAddingPercentEscapes(
                                                                                                 kCFAllocatorDefault,
                                                                                                 (CFStringRef)string, NULL, CFSTR(":/?#[]@!$ &'()*+,;=\"<>%{}|\\^~`"),
                                                                                                 CFStringConvertNSStringEncodingToEncoding(NSUTF8StringEncoding)) autorelease]);
#else
    NSString *newString = (__bridge_transfer NSString *)CFURLCreateStringByAddingPercentEscapes(kCFAllocatorDefault,( __bridge CFStringRef)string, NULL, CFSTR(":/?#[]@!$ &'()*+,;=\"<>%{}|\\^~`"),CFStringConvertNSStringEncodingToEncoding(NSUTF8StringEncoding));
#endif
    if (newString) {
        return newString;
    }
    return string;
}

CG_INLINE NSString* URLDecode(NSString *string)
{
#if !__has_feature(objc_arc)
    
    NSString *newString = NSMakeCollectable([(NSString *)CFURLCreateStringByReplacingPercentEscapesUsingEncoding(kCFAllocatorDefault,(__bridge CFStringRef) string,CFSTR(""),CFStringConvertNSStringEncodingToEncoding(NSUTF8StringEncoding)) autorelease]);
#else
    NSString *newString = (__bridge NSString *) CFURLCreateStringByReplacingPercentEscapesUsingEncoding(kCFAllocatorDefault,(__bridge CFStringRef) string,CFSTR(""),CFStringConvertNSStringEncodingToEncoding(NSUTF8StringEncoding));;
#endif
    if (newString) {
        return newString;
    }
    return string;
}

#pragma mark - 16进制颜色值转RGB值
CG_INLINE NSArray *getColor(NSString *hexColor)
{
    unsigned int red, green, blue, alpha;
    NSRange range;
    range.length = 2;
    
    if ([hexColor length] == 6)
    {
        range.location = 0;
        [[NSScanner scannerWithString:[hexColor substringWithRange:range]]scanHexInt:&red];
        range.location = 2;
        [[NSScanner scannerWithString:[hexColor substringWithRange:range]]scanHexInt:&green];
        range.location = 4;
        [[NSScanner scannerWithString:[hexColor substringWithRange:range]]scanHexInt:&blue];
        
        return [NSArray arrayWithObjects:[NSString stringWithFormat:@"%f",red/255.0],[NSString stringWithFormat:@"%f",green/255.0],[NSString stringWithFormat:@"%f",blue/255.0],[NSString stringWithFormat:@"%@",@"1"], nil];
    }
    
    range.location = 0;
    [[NSScanner scannerWithString:[hexColor substringWithRange:range]]scanHexInt:&alpha];
    range.location = 2;
    [[NSScanner scannerWithString:[hexColor substringWithRange:range]]scanHexInt:&red];
    range.location = 4;
    [[NSScanner scannerWithString:[hexColor substringWithRange:range]]scanHexInt:&green];
    range.location = 6;
    [[NSScanner scannerWithString:[hexColor substringWithRange:range]]scanHexInt:&blue];
    
    return [NSArray arrayWithObjects:[NSString stringWithFormat:@"%f",red/255.0],[NSString stringWithFormat:@"%f",green/255.0],[NSString stringWithFormat:@"%f",blue/255.0],[NSString stringWithFormat:@"%f",alpha/255.0], nil];
}

#pragma mark - 创建一个UUID
CG_INLINE NSString* creatUUID()
{
    // Create universally unique identifier (object)
    CFUUIDRef uuidObject = CFUUIDCreate(kCFAllocatorDefault);
    // Get the string representation of CFUUID object.
    NSString *uuidStr = (NSString *)CFBridgingRelease(CFUUIDCreateString(kCFAllocatorDefault, uuidObject));
    CFRelease(uuidObject);
    
    return uuidStr;
}

#pragma mark - MD5
#import <CommonCrypto/CommonDigest.h>
//* --------------------------------------------------------------------------//
/*
 * MD5
 */
CG_INLINE NSString *MD5ForFile(NSString *path)
{
    NSFileHandle *handle = [NSFileHandle fileHandleForReadingAtPath:path];
    if( handle== nil )
    {
        return nil;
    }
    CC_MD5_CTX md5;
    CC_MD5_Init(&md5);
    BOOL done = NO;
    while(!done)
    {
        NSData* fileData = [handle readDataOfLength:256];
        CC_MD5_Update(&md5, [fileData bytes], [fileData length]);
        if( [fileData length] == 0 ) done = YES;
    }
    unsigned char digest[CC_MD5_DIGEST_LENGTH];
    CC_MD5_Final(digest, &md5);
    NSString* s = [NSString stringWithFormat: @"%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
                   digest[0], digest[1],
                   digest[2], digest[3],
                   digest[4], digest[5],
                   digest[6], digest[7],
                   digest[8], digest[9],
                   digest[10], digest[11],
                   digest[12], digest[13],
                   digest[14], digest[15]];
    return s;
}

CG_INLINE NSString* MD5FromString(NSString *sourceString)
{
    const char *original_str = [sourceString UTF8String];
    unsigned char result[CC_MD5_DIGEST_LENGTH];
    CC_MD5(original_str, strlen(original_str), result);
    NSMutableString *hash = [NSMutableString string];
    for (int i = 0; i < 16; i++)
        [hash appendFormat:@"%02X", result[i]];
    return [hash lowercaseString];
}
