
//The MIT License (MIT)
//
//Copyright (c) 2013 Rafał Augustyniak
//
//Permission is hereby granted, free of charge, to any person obtaining a copy of
//this software and associated documentation files (the "Software"), to deal in
//the Software without restriction, including without limitation the rights to
//use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
//the Software, and to permit persons to whom the Software is furnished to do so,
//subject to the following conditions:
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
//FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
//COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
//IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
//CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#import <Foundation/Foundation.h>
@class NSMeapTreeNodeInfo;

@interface NSMeapTreeNode : NSObject

@property (nonatomic, getter = isExpanded, readonly) BOOL expanded;
@property (nonatomic, getter = isVisible, readonly) BOOL visible;

@property (weak, nonatomic) NSMeapTreeNode *parent;
@property (strong, nonatomic) NSArray *children;

@property (strong, nonatomic, readonly) NSMeapTreeNodeInfo *treeNodeInfo;
@property (strong, nonatomic, readonly) id item;

@property (strong, nonatomic, readonly) NSArray *descendants;

- (id)initWithItem:(id)item parent:(NSMeapTreeNode *)parent expanded:(BOOL)expanded;
- (void)addChildNode:(NSMeapTreeNode *)child;

- (NSArray *)visibleDescendants;
- (NSInteger)numberOfVisibleDescendants;

- (void)collapse;
- (void)expand;

- (NSInteger)startIndex;
- (NSInteger)endIndex;


@end
