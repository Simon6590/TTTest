//
//  NSMeapMessage.m
//  Cordova_TEST
//
//  Created by 罗忠燕 on 13-7-19.
//
//

#import "NSMeapMessagePlugin.h"
#import <MessageUI/MessageUI.h>

@interface  NSMeapMessagePlugin () <MFMessageComposeViewControllerDelegate>

@property (nonatomic, retain) NSString *currentCallBackID;

@end

@implementation NSMeapMessagePlugin

- (void)dealloc
{
    self.currentCallBackID = nil;
    
    [super dealloc];
}

//---------------------
// 短信插件发送调用接口
// arguments: 参数数组
// 0: id
// options: 参数字典
// body: 短信内容
// toRecipients: 短信的接受者
//---------------------
- (void)sendMessage:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    self.currentCallBackID = [arguments queueHead];
    NSLog(@"message");
    Class messageClass = (NSClassFromString(@"MFMessageComposeViewController"));
	if (messageClass)
    {
        if (![messageClass canSendText])
        {
			
			UIAlertView *alert = [[UIAlertView alloc] initWithTitle:nil
                                                            message:@"设备没有短信功能"
														   delegate:nil
                                                  cancelButtonTitle:@"OK"
                                                  otherButtonTitles: nil];
			[alert show];
			[alert release];
            
            CDVPluginResult *resultDate = nil;
            NSString *resultString = @"设备没有短信功能";
            resultDate = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:resultString];
            [self success:resultDate callbackId:self.currentCallBackID];

			return;
        }
		
    }
    else
    {
		UIAlertView *alert = [[UIAlertView alloc] initWithTitle:nil
                                                        message:@"iOS版本过低,不能发送短信"
													   delegate:nil
                                              cancelButtonTitle:@"OK"
                                              otherButtonTitles: nil];
		[alert show];
		[alert release];
        
        CDVPluginResult *resultDate = nil;
        NSString *resultString = @"iOS版本过低,不能发送短信";
        resultDate = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:resultString];
        [self success:resultDate callbackId:self.currentCallBackID];
        
		return;
	}
	
    NSString* body = [options valueForKey:@"body"];
	NSString* toRecipientsString = [options valueForKey:@"toRecipients"];
	
    MFMessageComposeViewController *picker = [[MFMessageComposeViewController alloc] init];
    picker.messageComposeDelegate = self;
	
	if(body != nil)
		picker.body = [options valueForKey:@"body"];
	
	if(toRecipientsString != nil)
		[picker setRecipients:[ toRecipientsString componentsSeparatedByString:@","]];
    
    [self.viewController presentModalViewController:picker animated:YES];
    [picker release];
}

#pragma mark - MFMessageComposeViewControllerDelegate
- (void)messageComposeViewController:(MFMessageComposeViewController *)controller didFinishWithResult:(MessageComposeResult)result
{
    // Notifies users about errors associated with the interface
    NSString *resultString = [NSString string];
	switch (result)
	{ 
		case MessageComposeResultCancelled:
            resultString = @"短信发送取消";
			break;
            
		case MessageComposeResultSent:
            resultString = @"短信发送成功";
			break;
		case MessageComposeResultFailed:
            resultString = @"短信发送失败";
			break;
		default:
            resultString = @"短信未发送";
			break;
	}
	
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:nil
                                                    message:resultString
                                                   delegate:nil
                                          cancelButtonTitle:@"OK"
                                          otherButtonTitles: nil];
    [alert show];
    [alert release];
    [controller dismissModalViewControllerAnimated:YES];
	
	CDVPluginResult *resultDate = nil;
    resultDate = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:resultString];
    [self success:resultDate callbackId:self.currentCallBackID];
}

@end
