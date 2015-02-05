//
//  NSMeapEditOfficeFilePlugin.m
//  Cordova_TEST
//
//  Created by Yalin on 14-3-20.
//
//

#import "NSMeapEditOfficeFilePlugin.h"

@implementation NSMeapEditOfficeFilePlugin

/**
 *  编辑Office文档
 *
 *  @param arguments 传参 [文件路径]
 *  @param options   配置
 */
- (void)editOfficeFile:(NSMutableArray *)arguments withDict:(NSMutableDictionary *)options
{
    self.callBackID = [arguments objectAtIndex:0];
    NSString *filePath = [arguments objectAtIndex:1];
    
    _controller = [[UIDocumentInteractionController interactionControllerWithURL:[NSURL fileURLWithPath:filePath]] retain];
    self.controller.delegate = self;
    [self.controller presentOptionsMenuFromRect:self.viewController.view.frame inView:self.viewController.view animated:YES];
}

#pragma mark - Documents Edit Delegate
-(UIViewController*)documentInteractionControllerViewControllerForPreview:(UIDocumentInteractionController*)controller

{
    return self.viewController;
}

- (UIView*)documentInteractionControllerViewForPreview:(UIDocumentInteractionController*)controller

{
    return self.viewController.view;
}

- (CGRect)documentInteractionControllerRectForPreview:(UIDocumentInteractionController*)controller

{
    return self.viewController.view.frame;
}

- (void)documentInteractionControllerDidEndPreview:(UIDocumentInteractionController*)controller

{
    [_controller autorelease];
}

@end
