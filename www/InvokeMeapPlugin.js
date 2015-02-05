/*调取meap服务名称：（test）
报文body中的json串：（{"b":[]}）
isHttp: 01
是否加点盐：（NO）
加密类型：(01)
是否压缩：（NO）*/
var cssStyle ={
position:'absolute',
zIndex:5,
width:'50px',
height:'50px',
border:'1px solid #00AEEF',
background:'#4CC6F4',
opacity:0
};
function defaultStyle(obj){
var node  = obj.parentNode.parentNode;
for(var o in cssStyle){
node.style[o] = cssStyle[o];
}
}
function showDiv(){
                            $("#animatel").css3Animate({
                                width: "350px",
                                height: "450px",
                                x: "5%",
                                y: "-90%",
                                time: "800ms",
                                opacity: 100,
                                callback: function () {
                                   // reset()
                                }
                            });
}
function showLogin() {
 var info = "用户名: <input type='text' id='popuuser' class='af-ui-forms' style='width:270px;'><br>密&nbsp;&nbsp;&nbsp;&nbsp;码: <input type='password' id='popuupsd' class='af-ui-forms' style='webkit-text-security:disc;width:270px;'>"
 info+='<br>'+
       '<div style="float:left;"> '+
            '<br style="clear:both">'+
                '<input id="forgetuser" type="checkbox" name="tesrt2" value="1"><label for="forgetuser">是否记住用户名</label>'+
                '<input id="forgetpsd" type="checkbox" name="tesrt2" value="1"><label for="forgetpsd">是否记住密码</label>'+
                '<input id="forgetunderline" type="checkbox" name="tesrt2" value="1"><label for="forgetunderline">是否支持离线登陆</label>'+
                '<br></div>';
                            $("#afui").popup({
                                title: "Login",
                                message: info,
                                cancelCallback: function () {},
                                doneText: "登录",
                                cancelText: "取消",
                                doneCallback: function () {
                                   var u,p,un,us,psd;
                                   u = document.getElementById('forgetuser').checked;
                                   p = document.getElementById('forgetpsd').checked;
                                   un = document.getElementById('forgetunderline').checked;
                                   us = $("#popuuser").val();
                                   psd = $("#popuupsd").val();
                                   Meap.login(us,psd,u,p,us,function(){var i=0;},function(){var i=0;});
                                },
                                cancelOnly: false
                            });
                        }
function showLoginforValidate() {
 var info = "用户名: <input type='text' id='popuuser' class='af-ui-forms' style='width:270px;'><br>密&nbsp;&nbsp;&nbsp;&nbsp;码: <input type='password' id='popuupsd' class='af-ui-forms' style='webkit-text-security:disc;width:270px;'><br>"
 info +='验&nbsp;证&nbsp;码:<input type="text" class="af-ui-forms" id="capchas" style="width:90px;">&nbsp;&nbsp;&nbsp;<img src=""  id="yzmtp" style="display:none;" alt="默认验证码图片" /><a id = "getcap" class="button icon pencil">获取验证码</a>';
 info+='<br><div style="float:left;">'+
                '<input id="forgetuser" type="checkbox" name="tesrt2" value="1"><label for="forgetuser">是否记住用户名</label>'+
                '<input id="forgetpsd" type="checkbox" name="tesrt2" value="1"><label for="forgetpsd">是否记住密码</label>'+
                '<input id="forgetunderline" type="checkbox" name="tesrt2" value="1"><label for="forgetunderline">是否支持离线登陆</label>'+
'</div><br style="clear:both">';
                            $("#afui").popup({
                            	width:"400",
                                title: "Login",
                                message: info,
                                cancelText: "取消",
                                cancelCallback: function () {},
                                doneText: "登录",
                                doneCallback: function (event) {
                                   var u,p,un,us,psd,capcha;
                                   u = document.getElementById('forgetuser').checked;
                                   p = document.getElementById('forgetpsd').checked;
                                   un = document.getElementById('forgetunderline').checked;
                                   us = $("#popuuser").val();
                                   psd = $("#popuupsd").val();
                                   capcha = $("#capchas").val();
                                   if(capcha==""&&($("#yzmtp").attr("src")==""))
                                   			{
                                   				
                                             getCaptcha("yzmtp");
                                             document.getElementById("getcap").style.display ="none";
                                             event.stopPropagation();
                                   				return;
                                   			}
//                                             else if ()
//                                             {
//                                             getCaptcha("yzmtp");
//                                             event.stopPropagation();
//                                             return;
//                                             }
                                   Meap.loginWithCaptcha(us,psd,u,p,un,capcha,function(msg){alert(msg);},function(msg){alert(msg);});
                                },
                                cancelOnly: false
                            });
                        }
/**
 *	@brief	网络检测
 *
 *	@param 	successCallback 	成功回调
 *	@param 	failureCallback 	失败回调
 *
 *	@return	01  02  03   代表01:wifi  02:3G 03: noConnect
 */
function isNetConnect(successCallback,failureCallback)
{
      Meap.isNetConnect(function(message){
      	var netType =""; 
      switch(message){
      	case "01":
      	     netType="wifi";
      		break;
      	case "02":
      	    netType="3G";
      		break;
      	case "03":
      	    netType ="noConnect";
      }
      alert(netType);
    },function(){var i=0;});
};

/**
 *	@brief	二维码插件---扫描二维码
 *
 *	@param 	successCallback 	成功回调
 *	@param 	failureCallback 	失败回调
 *
 *	@return	扫描的结果信息
 */
function scanQRCodeWithController(successCallback, failureCallback)
{
    return  Meap.scanQRCodeWithController(function(msg){
                                          alert(msg);},failureCallback);
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
function qrImageForString(text,size, successCallback, failureCallback)
{
    var s,i;
    s = $("#strInfo").val();
    i = $("#createImg").val();
    return Meap.qrImageForString(s,i,function(message){
     document.getElementById("erweima").src = "";
                                 
       document.getElementById("erweima").src = message;
    },function(){var i=0;});
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
function callTelPhone(phoneNum, successCallback, failureCallback)
{
var num = $("#telephoNum").val(); 
     Meap.callTelPhone(num,successCallback,failureCallback);
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
var filePath="";
function media(action,filename, successCallback, failureCallback)
{
    if(action=="playaudio")
    { Meap.media(action,filePath!=""?filePath:"",function(){},function(){var i1=0;});
    }
        else
     Meap.media(action,!!filename?"6":filename,function(mes){if(action=="audio")filePath=mes;},function(){var i1=0;});
}

///网络请求
/**
 *	@brief	http/https 网络请求
 *
 *	@param 	method 	<调取meap服务名称>
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
function httpRequest(method,bodyJson,isHttps,encryptionType,isSalt, isCompres,version, successCallback, failureCallback) {
    
//    alert(0);
//    method = $("#MeapServiceName").val();
//    bodyJson = $("#messageJson").val();
//    isHttps = $("#isHttps").val();
//    encryptionType = $("#encryptionType").val();
//    isSalt = $("#isSalt").val();
//    isCompres = $("#isCompres").val();
//    version = $("#versionNum").val();
    
     Meap.httpRequest(interface,method,group, bodyJson, isHttps,encryptionType,isSalt,isCompres,version,function(message){alert(message);},function(){var i=0;} );
//
//       Meap.httpRequest("abc","test","" ,"{\"b\":[{\"value.s\":\"Hello hello\"}]}", "01","01","false","false","01",function(message){alert(message);},function(){var i=0;} );
};

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
function sendMessage(phoneNumber,context,successCallback, failureCallback) {
var d = $("#dhhm").val();
var d1 = $("#dxnr").val();
      Meap.sendMessage(d,d1,function(){var i=0;},function(){var i1=0;});
 };

/**
 *	@brief	SSO设置参数接口
 *
 *	@param 	arguments 	参数数组
 *	0: id
 *	1: parma 参数名
 *	2: dataType 参数类型
 *  3: value 参数值
 *  4: isOffLineParam 是否为离线登录参数
 */
function SSOSetUserNameParma(parma,dataType,value,isOffLine,successCallback, failureCallback){
    Meap.SSOSetParma("username","2","bb","1",function(msg){}, function(error){});
}

function SSOSetPasswordParma(parma,dataType,value,isOffLine,successCallback, failureCallback){
    Meap.SSOSetParma("password","2","b","1",successCallback, failureCallback);
}

/**
 *	@brief	SSO获取参数接口
 *
 *	@param 	parmaName 	参数名
 */
function SSOGetParma(parmaName,successCallback, failureCallback){
    
    Meap.SSOGetParma(parmaName,successCallback, failureCallback);
}

/**
 *	@brief	开始在线登录
 *
 *	@param 	parmaName 	参数名
 */
function startOnLineLogin(successCallback, failureCallback){
    Meap.startOnLineLogin(function(msg){alert(msg)}, function(msg){alert("error" + msg)});
}

/**
 *	@brief	注销登录
 */
function logout(successCallback, failureCallback){
   Meap.logout(function(msg){alert(msg)}, function(msg){alert("error" + msg)});
}

/**
 *	@brief	检测登录状态
 */
function checkSSOLogin(successCallback, failureCallback){
    
    Meap.checkSSOLogin(function(msg){alert(msg)}, function(msg){alert("error" + msg)});
}
/**
 *	@brief	有验证码登录
 *
 *	@param 	userName 	用户名
 *	@param 	password 	密码
 *	@param 	captcha 	验证码
 *	@param 	saveUserName 	是否记住用户名
 *	@param 	savePassword 	是否记住密码
 *	@param 	offLineLogine 	是否支持离线登陆
 *	@param 	successCallback 	成功回调
 *	@param 	failureCallback 	失败回调
 *
 *	@return
 */
function loginWithCaptcha(userName,password,isSaveUserName,isSavePassword,isOffLine,captcha, successCallback, failureCallback)
{
   showLoginforValidate();
   // Meap.loginWithCaptcha(userName,password,isSaveUserName,isSavePassword,isOffLine,captcha, successCallback, failureCallback);
}
/**
 *	@brief	Hybrid小版本更新
 *
 *	@param 	successCallback 	成功回调
 *	@param 	failureCallback 	失败回调
 *
 *	@return
 */
function autoCheckUpdateForJS(successCallback,failureCallback)
{
  
     Meap.autoCheckUpdateForJS(successCallback,failureCallback);
}
/**
 *	@brief	APP版本更新
 *
 *	@param 	successCallback 	成功回调
 *	@param 	failureCallback 	失败回调
 *
 *	@return	
 */
function autoCheckUpdate(successCallback,failureCallback)
{
    return Meap.autoCheckUpdate(successCallback,failureCallback);
}
/**
 *	@brief	获取验证码
 *
 *	@param 	successCallback 	成功回调
 *	@param 	failureCallback 	失败回调
 *
 *	@return	
 */
function getCaptcha(yzm,successCallback,failureCallback)
{
   
     Meap.getCaptcha(function(message)
    {
        $("#"+yzm).attr("src","data:image/png;base64,"+message);
        $("#"+yzm).css("display","block");
     },function(){var i=0;});
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
function getDate(pointX,pointY,dateModel,successCallback, failureCallback)
{
    
    Meap.getDate(pointX,pointY,dateModel,function(mes){
                 $("#displaydate").val(mes);
                 },failureCallback);
}
//*********文件操作********************************//
/// 文件操作   上传
function uploadFile(path,fileName, successCallback, failureCallback)
{ 
var path = $("#uploadpaths").val();
var fn = $("#fileNames").val();
     Meap.uploadFile(path,fn,function(message){alert(message);}, function(){});
};

/// 文件操作   下载
function downloadFile(url, successCallback, failureCallback)
{
var downLoadUrl = $("#downLoadUrl").val();
    Meap.downloadFile(downLoadUrl,function(message){$("#downLoadPath").val(message);}, function(){});
};

/// 文件操作  文件移除
function removeFile(filePath, successCallback, failureCallback)
{
filePath = $("#moveUrl").val();
     Meap.removeFile(filePath,function(message){alert(message);}, function(){});
};
/// 文件操作  文件移动
function moveFile(filePath,newPath,newName, successCallback, failureCallback)
{   
filePath = $("#oldUrl").val();
newPath = $("#newUrl").val();
newName = $("#newFile").val();
     Meap.moveFile(filePath,newPath,newName,function(message){alert(message);}, function(){});
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
function getPassword(successCallback, failureCallback)
{
    Meap.getPassword(successCallback,failureCallback);
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
function setPassword(password,overTime,successCallback, failureCallback)
{
    password =$("#encryptpsd").val();
    overTime =$("#outofDate").val();
    Meap.setPassword(password,overTime,function(msg){alert(msg);},function(error){alert("error: "+ error);});
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
function saveString(string, successCallback, failureCallback)
{
    text =$("#encryptString").val();
    Meap.saveString(text,function(message){$("#encryptStringid").val(message)},failureCallback);
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
function getString(stringID, successCallback, failureCallback)
{
    stringID = $("#encryptStringid").val();
    Meap.getString(stringID,function(msg){alert(msg)},function(error){alert("error"+error)});
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
function saveFile(filePath, successCallback, failureCallback)

{
    filePath =$("#encryptfilepath").val();
    Meap.saveFile(filePath,function (msg) {
                  $("#encryptfileid").val(msg);
                  },failureCallback);
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
function getFile(fileID, successCallback, failureCallback)

{
    fileID =$("#encryptfileid").val();
    Meap.getFile(fileID,successCallback,failureCallback);
}

/**
 *	@brief	删除加密的字符串
 *
 *	@param 	stringID 	字符串的ID
 *
 *	@return
 */
function clearData(dataId)
{
    dataId =$("#encryptfileid").val();
    return Meap.clearData(dataId);
}

/**
 *	@brief	删除加密的文件
 *
 *	@return
 */
function clearAll()
{
    Meap.clearAll();
}

/**
 *	@brief	加密所有文件
 *
 *	@return
 */
function encryAllData()
{
    Meap.encryAllData();
}

/**
 *	@brief	解密所有文件
 *
 *	@return
 */
function decryAllData()
{
    Meap.decryAllData();
}








/*Cordova.addConstructor(function() {
 
                       if (!window.plugins) {
                       
                       window.plugins = {};
                       
                       }
                       window.plugins.NSMeapPlugin = new NSMeapPlugin();
                       
                       });*/