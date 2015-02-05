function NSMeapPlugin()
{

}
var Meap  = new NSMeapPlugin();
NSMeapPlugin.prototype.alert = function(args)
{
alert(args);
};
/**
 *	@brief	网络检测
 *
 *	@param 	successCallback 	成功回调
 *	@param 	failureCallback 	失败回调
 *
 *	@return	01  02  03   代表01:wifi  02:3G 03: noConnect
 */
NSMeapPlugin.prototype.isNetConnect = function(successCallback,failureCallback)
{
    return  cordova.exec(successCallback,failureCallback,'NSMeapPasswordLock','showPasswordLock',['1',1234]);
};

/**
 *	@brief	网络检测
 *
 *	@param 	successCallback 	成功回调
 *	@param 	failureCallback 	失败回调
 *
 *	@return	01  02  03   代表01:wifi  02:3G 03: noConnect
 */
NSMeapPlugin.prototype.zip = function(successCallback,failureCallback)
{
    return  cordova.exec(successCallback,failureCallback,'NSMeapZip','zipCompression',["fewagewfew"]);
};

/**
 *	@brief	二维码插件---扫描二维码
 *
 *	@param 	successCallback 	成功回调
 *	@param 	failureCallback 	失败回调
 *
 *	@return	扫描的结果信息
 */
NSMeapPlugin.prototype.scanQRCodeWithController = function(successCallback, failureCallback)
{
    return  cordova.exec(successCallback,failureCallback,'NSMeapQRCode','scanQRCodeWithController',[]);
};


/**
 *	@brief	二维码插件---字符串生成二维码图片
 *
 *	@param 	text 	文本信息
 *	@param 	size 	生成的图片大小
 *	@param 	successCallback 	成功回调
 *	@param 	failureCallback 	失败回调
 *
 *	@return	图片的保存路径
 */
NSMeapPlugin.prototype.qrImageForString = function(text,size, successCallback, failureCallback)
{
    return cordova.exec(successCallback,failureCallback,'NSMeapQRCode','qrImageForString',[text,size]);
}

/**
 *	@brief	打电话
 *
 *	@param 	phoneNum 	电话号码
 *	@param 	successCallback 	成功回调
 *	@param 	failureCallback 	失败回调
 *
 *	@return	
 */
NSMeapPlugin.prototype.callTelPhone = function(phoneNum, successCallback, failureCallback)
{
    return cordova.exec(successCallback,failureCallback,'NSMeapTelPhone','callPhone',[phoneNum]);
}

/**
 *	@brief	媒体库
 *
 *	@param 	action 	方法名（camera 调用照像机  picture 调用图库  video 调用录像  audio录音 playaudio播放录音）
 *	@param 	filename 	文件名称
 *	@param 	successCallback 	回调方法
 *	@param 	failureCallback 	失败回调
 *
 *	@return	
 */
NSMeapPlugin.prototype.media = function(action,filename, successCallback, failureCallback)
{
    return cordova.exec(successCallback,failureCallback,'NSMeapMedia','media',[action,filename]);
}

///网络请求
/**
 *	@brief	http/https 网络请求
 *
 *  @param  interface  <调取meap接口名>
 *	@param 	method 	<调取meap服务名称>
 *	@param 	group       <调取meap组名称>
 *	@param 	version 	<调取meap服务名称>
 *	@param 	bodyJson 	<报文body中的JSON内容>
 *	@param 	isHttps 	<是否是https 请求 > :01 http 02 单向https  03 双向https
 *	@param 	encryptionType 	<加密类型> 01 无加密 02 3des 03 rsa
 *	@param 	isSalt 	<是否加盐>
 *	@param 	isCompres 	<是否压缩>
 *	@param 	successCallback 	回调方法
 *	@param 	failureCallback 	失败方法
 *
 *	@return	
 */
NSMeapPlugin.prototype.httpRequest = function(interface,method,group,bodyJson,isHttps,encryptionType,isSalt, isCompres,version, successCallback, failureCallback)
{
    return cordova.exec(successCallback, failureCallback, 'NSMeapWebRequest', 'httpRequest', [method, bodyJson, isHttps,encryptionType,isSalt, isCompres,version,interface,group]);
};

//{"b":[{"abc":"bcd","username":"bbb"}]}]}

/**
 *	@brief	发短信
 *
 *	@param 	phoneNumber 	电话号码
 *	@param 	context 	短信内容
 *	@param 	successCallback 	成功回调
 *	@param 	failureCallback 	失败回调
 *
 *	@return	
 */
NSMeapPlugin.prototype.sendMessage = function(phoneNumber,context,successCallback, failureCallback) {
 
 
     var args = {};
     
     if(phoneNumber)
     args.toRecipients = phoneNumber;
     
     if(context)
     args.body = context;
     return cordova.exec(successCallback,failureCallback,'NSMeapMessage','sendMessage',[args]);
 };

/**
 *	@brief	SSO设置参数接口
 *
 *	@param 	arguments 	参数数组
 *	0: id
 *	1: parma 参数名
 *	2: dataType 参数类型 传（2）
 *  3: value 参数值
 *  4: isOffLineParam 是否为离线登录参数 0 或 1
 */
NSMeapPlugin.prototype.SSOSetParma = function(parma,dataType,value,isOffLine, successCallback, failureCallback)
{
    cordova.exec(successCallback,failureCallback,'NSMeapSSO','setParma',[parma,dataType,value,isOffLine]);
    
}

/**
 *	@brief	SSO获取参数接口
 *
 *	@param 	parmaName 	参数名
 */
NSMeapPlugin.prototype.SSOGetParma = function(parmaName, successCallback, failureCallback)
{
    cordova.exec(successCallback,failureCallback,'NSMeapSSO','getParma',[parmaName]);
    
}

/**
 *	@brief	开始在线登录
 *
 *	@param 	parmaName 	参数名
 */
NSMeapPlugin.prototype.startOnLineLogin = function(successCallback, failureCallback)
{
    cordova.exec(successCallback,failureCallback,'NSMeapSSO','startOnLineLogin',[]);
    
}

/**
*	@brief	注销登录
*/
NSMeapPlugin.prototype.logout = function(successCallback, failureCallback)
{
    cordova.exec(successCallback,failureCallback,'NSMeapSSO','logout',[]);
}

/**
 *	@brief	检测登录状态
 */
NSMeapPlugin.prototype.checkSSOLogin = function(successCallback, failureCallback)
{
    cordova.exec(successCallback,failureCallback,'NSMeapSSO','checkSSOLogin',[]);
}

/**
 *	@brief	Hybrid小版本更新
 *
 *	@param 	successCallback 	成功回调
 *	@param 	failureCallback 	失败回调
 *
 *	@return
 */
NSMeapPlugin.prototype.autoCheckUpdateForJS = function(successCallback,failureCallback)
{
  
    return cordova.exec(successCallback,failureCallback,'NSMeapCheckWebUpdate','checkUpdate',[]);
}
/**
 *	@brief	APP版本更新
 *
 *	@param 	successCallback 	成功回调
 *	@param 	failureCallback 	失败回调
 *
 *	@return	
 */
NSMeapPlugin.prototype.autoCheckUpdate = function(successCallback,failureCallback)
{
//    alert("autoCheckUpdate js");
    return cordova.exec(successCallback,failureCallback,'NSMeapCheckAppUpdate','checkUpdate',[]);
}
/**
 *	@brief	获取验证码
 *
 *	@param 	successCallback 	成功回调
 *	@param 	failureCallback 	失败回调
 *
 *	@return	
 */
NSMeapPlugin.prototype.getCaptcha = function(successCallback,failureCallback)
{
   
    return cordova.exec(successCallback,failureCallback,'NSMeapGetCaptcha','getCaptcha',[]);
}

/**
 *	@brief	日期选择器
 *
 *	@param 	pointX 	日期选择器的X坐标  (btn.offsetLeft+btn.offsetWidth/2)
 *	@param 	pointY 	日期选择器的Y坐标  (btn.offsetTop+btn.offsetHeight/2)
 *	@param 	dateModel 	日期选择器的类型（date、date_time、time、hour_Minute）
 *	@param 	successCallback 	成功回调
 *	@param 	failureCallback 	失败回调
 *
 *	@return
 */
NSMeapPlugin.prototype.getDate = function(pointX,pointY,dateModel,successCallback, failureCallback)
{
    
    return cordova.exec(successCallback,failureCallback,'NSMeapDatePicker','getDate',[pointX,pointY,dateModel]);
}
//*********文件操作********************************//
/// 文件操作   上传
NSMeapPlugin.prototype.uploadFile = function(path,fileName, successCallback, failureCallback)
{
    return cordova.exec(successCallback, failureCallback, 'NSMeapFileManager','uploadFile', [path,fileName]);
};

/// 文件操作   下载
NSMeapPlugin.prototype.downloadFile = function(url, successCallback, failureCallback)
{
    return cordova.exec(successCallback, failureCallback, 'NSMeapFileManager','downloadFile', [url]);
};

/// 文件操作  文件移除
NSMeapPlugin.prototype.removeFile = function(filePath, successCallback, failureCallback)
{
    return cordova.exec(successCallback, failureCallback, 'NSMeapFileManager','removeFile', [filePath]);
};
/// 文件操作  文件移动
NSMeapPlugin.prototype.moveFile = function(filePath,newPath,newName, successCallback, failureCallback)
{   
    return cordova.exec(successCallback, failureCallback, 'NSMeapFileManager','moveFile', [filePath,newPath,newName]);
};


//********************本地数据加密插件********************//
/**
 *	@brief	获取加密的密码
 *
 *	@param 	successCallback 	成功回调
 *	@param 	failureCallback 	失败回调
 *
 *	@return	
 */
NSMeapPlugin.prototype.getPassword = function(successCallback, failureCallback)
{
   return cordova.exec(successCallback,failureCallback,'NSMeapDataSecurity','getPassword',[]);
}

/**
 *	@brief	设置加密的密码
 *
 *	@param 	password 	加密的密码
 *	@param 	overTime 	密码过期时间
 *	@param 	successCallback 	成功回调
 *	@param 	failureCallback 	失败回调
 *
 *	@return	
 */
NSMeapPlugin.prototype.setPassword = function(password,overTime,successCallback, failureCallback)
{
    return cordova.exec(successCallback,failureCallback,'NSMeapDataSecurity','setPassword',[password,overTime]);
}

/**
 *	@brief	本地数据加密插件---保存加密字符串
 *
 *	@param 	string 	需要加密的字符串
 *	@param 	stringID 	需要加密的字符串的ID
 *	@param 	successCallback 	成功回调
 *	@param 	failureCallback 	失败回调
 *
 *	@return	
 */
NSMeapPlugin.prototype.saveString = function(string, successCallback, failureCallback)
{
   return cordova.exec(successCallback,failureCallback,'NSMeapDataSecurity','saveString',[string]);
}

/**
 *	@brief	本地数据加密插件---获取加密的字符串
 *
 *	@param 	stringID 	字符串的ID
 *	@param 	successCallback 	成功回调
 *	@param 	failureCallback 	失败回调
 *
 *	@return	
 */
NSMeapPlugin.prototype.getString = function(stringID, successCallback, failureCallback)
{
   return cordova.exec(successCallback,failureCallback,'NSMeapDataSecurity','getString',[stringID]);
}

/**
 *	@brief	加密文件
 *
 *	@param 	filePath 	文件的路径
 *	@param 	fileID 	文件的ID
 *	@param 	successCallback 	成功回调
 *	@param 	failureCallback 	失败回调
 *
 *	@return
 */
NSMeapPlugin.prototype.saveFile = function(filePath, successCallback, failureCallback)
{
   return cordova.exec(successCallback,failureCallback,'NSMeapDataSecurity','saveFile',[filePath]);
}

/**
 *	@brief	获取加密的文件
 *
 *	@param 	fileID 	文件的ID
 *	@param 	successCallback 	成功回调
 *	@param 	failureCallback 	失败回调
 *
 *	@return	文件的路径
 */
NSMeapPlugin.prototype.getFile = function(fileID, successCallback, failureCallback)
{
   return cordova.exec(successCallback,failureCallback,'NSMeapDataSecurity','getFile',[fileID]);
}

/**
 *	@brief	删除加密的字符串
 *
 *	@param 	stringID 	字符串的ID
 *
 *	@return	
 */
NSMeapPlugin.prototype.clearData = function(dataId)
{
    return cordova.exec(null,null,'NSMeapDataSecurity','clearString',[dataId]);
}

/**
 *	@brief	删除加密的文件
 *
 *	@return	
 */
NSMeapPlugin.prototype.clearAll = function()
{
    Cordova.exec(null,null,'NSMeapDataSecurity','clearAll',[]);
}

/**
 *	@brief	加密所有文件
 *
 *	@return
 */
NSMeapPlugin.prototype.encryAllData = function()
{
    Cordova.exec(null,null,'NSMeapDataSecurity','getString',[]);
}

/**
 *	@brief	解密所有文件
 *
 *	@return
 */
NSMeapPlugin.prototype.decryAllData = function()
{
    Cordova.exec(null,null,'NSMeapDataSecurity','decryAllData',[]);
}






/*Cordova.addConstructor(function() {
 
                       if (!window.plugins) {
                       
                       window.plugins = {};
                       
                       }
                       window.plugins.NSMeapPlugin = new NSMeapPlugin();
                       
                       });*/