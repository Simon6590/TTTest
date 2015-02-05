//
//  NSMeapVerifyEngine.h
//  NSMeap
//
//  Created by 罗忠燕 on 13-11-9.
//  Copyright (c) 2013年 nationsky. All rights reserved.
//

#pragma mark - 验证中国邮政编码
//中国邮政编码的正则表达式[1-9]\\d{5}(?!\\d)
CG_INLINE BOOL isPostCode(NSString *postcose)
{
    NSString *postcoseRegex = @"[1-9]\\d{5}(?!\\d)";
    NSPredicate *postcoseTest = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", postcoseRegex];
    return [postcoseTest evaluateWithObject:postcose];
}

#pragma mark - 验证身份证号
// （1）前6位为数字，第1位不为0；
// （2）7~14位符合日期格式，YYYYMMdd；
// （3）15~17为字数；
// （4）末位为数字或x；
//  身份证正则表达式(15位)
//  isIDCard1 = @"^[1-9]\\d{7}((0\\d)|(1[0-2]))(([0|1|2]\\d)|3[0-1])\\d{3}"
//  身份证正则表达式(18位)
//  isIDCard2 = @"^[1-9]\\d{5}[1-9]\\d{3}((0\\d)|(1[0-2]))(([0|1|2]\\d)|3[0-1])\\d{4}"
//  身份证正则表达式(17位+X)
//  isIDCard3 = @"^[1-9]\\d{5}[1-9]\\d{3}((0\\d)|(1[0-2]))(([0|1|2]\\d)|3[0-1])\\d{3}(\\d|X|x)"
CG_INLINE BOOL isIDCard(NSString *idCard)
{
    // 15位
    NSString *idIDCard1 = @"^[1-9]\\d{7}((0\\d)|(1[0-2]))(([0|1|2]\\d)|3[0-1])\\d{3}";
    // 18位
    NSString *isIDCard2 = @"^[1-9]\\d{5}[1-9]\\d{3}((0\\d)|(1[0-2]))(([0|1|2]\\d)|3[0-1])\\d{4}";
    // 17位＋X
    NSString *isIDCard3 = @"^[1-9]\\d{5}[1-9]\\d{3}((0\\d)|(1[0-2]))(([0|1|2]\\d)|3[0-1])\\d{3}(\\d|X|x)";
    NSPredicate *idCardTest1 = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", idIDCard1];
    NSPredicate *idCardTest2 = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", isIDCard2];
    NSPredicate *idCardTest3 = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", isIDCard3];
    BOOL right1 = [idCardTest1 evaluateWithObject:idCard];
    BOOL right2 = [idCardTest2 evaluateWithObject:idCard];
    BOOL right3 = [idCardTest3 evaluateWithObject:idCard];
    BOOL right = (right1 || right2 || right3);
    if (right)
    {
        // 判断出生年月日是否正确 必须小于现在日期
        NSString *birthDateStr = [idCard substringWithRange:NSMakeRange(6, 8)];
        NSString *year = [birthDateStr substringWithRange:NSMakeRange(0, 4)];
        NSString *month = [birthDateStr substringWithRange:NSMakeRange(4, 2)];
        NSString *day = [birthDateStr substringWithRange:NSMakeRange(6, 2)];
        NSArray *strArray = [NSArray arrayWithObjects:year,month,day, nil];
        birthDateStr = [strArray componentsJoinedByString:@"-"];
        NSDate *birthDate = dateForString(birthDateStr, @"yyyy-MM-dd");
        NSDate *nowDate = [NSDate date];
        NSDate *earlierDate = [birthDate earlierDate:nowDate];
        if ([earlierDate isEqual:nowDate])
        {
            right = NO;
        }
        
        DEBUG_NSLOG(birthDateStr);
    }
    return right;
}

#pragma mark - 国内电话号码验证
//匹配国内电话号码的正则表达式：\\d{3}-\\d{8}|\\d{4}-\\d{7}|\\d{4}-\\d{8}  评注：匹配形式如 0511-4405222 或 021-87888822
CG_INLINE BOOL isTelPhone(NSString *telPhone)
{
    NSString *telPhoneRegex = @"\\d{3}-\\d{8}|\\d{4}-\\d{7}|\\d{4}-\\d{8}";
    NSPredicate *telPhoneTest = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", telPhoneRegex];
    return [telPhoneTest evaluateWithObject:telPhone];
}

#pragma mark - 验证邮箱
//* --------------------------------------------------------------------------//
// 通过区分字符串验证邮箱

CG_INLINE BOOL isEmailByStringValidator(NSString *email)
{
    if((0 != [email rangeOfString:@"@"].length) &&
       (0 != [email rangeOfString:@"."].length))
    {
        NSCharacterSet* tmpInvalidCharSet = [[NSCharacterSet alphanumericCharacterSet] invertedSet];
        
#if !__has_feature(objc_arc)
        NSMutableCharacterSet* tmpInvalidMutableCharSet = [[tmpInvalidCharSet mutableCopy] autorelease];
#else
        NSMutableCharacterSet* tmpInvalidMutableCharSet = [tmpInvalidCharSet mutableCopy];
#endif
        
        [tmpInvalidMutableCharSet removeCharactersInString:@"_-"];
        
        
        NSRange range1 = [email rangeOfString:@"@"
                                      options:NSCaseInsensitiveSearch];
        
        //取得用户名部分
        NSString* userNameString = [email substringToIndex:range1.location];
        NSArray* userNameArray   = [userNameString componentsSeparatedByString:@"."];
        
        for(NSString* string in userNameArray)
        {
            NSRange rangeOfInavlidChars = [string rangeOfCharacterFromSet: tmpInvalidMutableCharSet];
            if(rangeOfInavlidChars.length != 0 || [string isEqualToString:@""])
                return NO;
        }
        
        //取得域名部分
        NSString *domainString = [email substringFromIndex:range1.location+1];
        NSArray *domainArray   = [domainString componentsSeparatedByString:@"."];
        
        for(NSString *string in domainArray)
        {
            NSRange rangeOfInavlidChars=[string rangeOfCharacterFromSet:tmpInvalidMutableCharSet];
            if(rangeOfInavlidChars.length !=0 || [string isEqualToString:@""])
                return NO;
        }
        
        return YES;
    }
    else {
        return NO;
    }
}
#if !__has_feature(objc_arc)
#else
#endif

//利用正则表达式验证
CG_INLINE BOOL isEmailByRegExp(NSString *email)
{
    NSString *emailRegex = @"[A-Z0-9a-z._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}";
    NSPredicate *emailTest = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", emailRegex];
    return [emailTest evaluateWithObject:email];
}

#pragma mark - 判断是否纯数字
//只能输入有1-6位小数的正实数：“^[0-9]+(.[0-9]{1,6})?$”
CG_INLINE BOOL isNumText(NSString *str)
{
    NSString * regex        = @"^[0-9]+(.[0-9]{1,6})?$";
    NSPredicate * pred      = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regex];
    BOOL isMatch            = [pred evaluateWithObject:str];
    if (isMatch)
    {
        return YES;
    }
    else{
        return NO;
    }
}

#pragma mark - 手机号验证
//* --------------------------------------------------------------------------//
/*
 * 手机号验证
 */
CG_INLINE BOOL isMobileNumber(NSString* mobileNum)
{
    
    //* 普通
    NSString*MOBILE=@"^1(3[0-9]|5[0-35-9]|8[025-9])\\d{8}$";
    
    //* 移动
    NSString*CM=@"^1(34[0-8]|(3[5-9]|5[017-9]|8[278])\\d)\\d{7}$";
    
    //* 联通
    NSString*CU=@"^1(3[0-2]|5[256]|8[56])\\d{8}$";
    
    //* 电信
    NSString*CT=@"^1((33|53|8[09])[0-9]|349)\\d{7}$";
    
    // NSString * PHS = @"^0(10|2[0-5789]|\\d{3})\\d{7,8}$";
    
    NSPredicate*regextestmobile = [NSPredicate predicateWithFormat:@"SELF MATCHES %@",MOBILE];
    NSPredicate*regextestcm = [NSPredicate predicateWithFormat:@"SELF MATCHES %@",CM];
    NSPredicate*regextestcu = [NSPredicate predicateWithFormat:@"SELF MATCHES %@",CU];
    NSPredicate*regextestct = [NSPredicate predicateWithFormat:@"SELF MATCHES %@",CT];
    
    
    if(([regextestmobile evaluateWithObject:mobileNum] ==YES)
       || ([regextestcm evaluateWithObject:mobileNum] ==YES)
       || ([regextestct evaluateWithObject:mobileNum] ==YES)
       || ([regextestcu evaluateWithObject:mobileNum] ==YES))
    {
        return YES;
    }
    else
    {
        return NO;
    }
}
