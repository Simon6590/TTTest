
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


#import <UIKit/UIKit.h>
#import "NSMeapTreeNodeInfo.h"



@class NSMeapTreeView;
@class NSMeapTreeViewCell;
@class NSMeapTreeNodeInfo;
@class NSMeapTreeNodeCollectionController;
@class NSMeapTreeNode;


typedef enum {
  NSMeapTreeViewStylePlain = 0,
  NSMeapTreeViewStyleGrouped
} NSMeapTreeViewStyle;

typedef enum NSMeapTreeViewCellSeparatorStyle {
  NSMeapTreeViewCellSeparatorStyleNone = 0,
  NSMeapTreeViewCellSeparatorStyleSingleLine,
  NSMeapTreeViewCellSeparatorStyleSingleLineEtched
} NSMeapTreeViewCellSeparatorStyle;

typedef enum NSMeapTreeViewScrollPosition {
  NSMeapTreeViewScrollPositionNone = 0,
  NSMeapTreeViewScrollPositionTop,
  NSMeapTreeViewScrollPositionMiddle,
  NSMeapTreeViewScrollPositionBottom
} NSMeapTreeViewScrollPosition;

typedef enum NSMeapTreeViewRowAnimation {
  NSMeapTreeViewRowAnimationNone = 0,
  NSMeapTreeViewRowAnimationRight,
  NSMeapTreeViewRowAnimationLeft,
  NSMeapTreeViewRowAnimationTop,
  NSMeapTreeViewRowAnimationBottom,
  NSMeapTreeViewRowAnimationMiddle,
  NSMeapTreeViewRowAnimationAutomatic
} NSMeapTreeViewRowAnimation;



@protocol NSMeapTreeViewDataSource <NSObject>

@required
- (NSInteger)treeView:(NSMeapTreeView *)treeView numberOfChildrenOfItem:(id)item;
- (UITableViewCell *)treeView:(NSMeapTreeView *)treeView cellForItem:(id)item treeNodeInfo:(NSMeapTreeNodeInfo *)treeNodeInfo;
- (id)treeView:(NSMeapTreeView *)treeView child:(NSInteger)index ofItem:(id)item;
@optional
//Inserting or Deleting Table Rows
- (void)treeView:(NSMeapTreeView *)treeView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowForItem:(id)item treeNodeInfo:(NSMeapTreeNodeInfo *)treeNodeInfo;
- (BOOL)treeView:(NSMeapTreeView *)treeView canEditRowForItem:(id)item treeNodeInfo:(NSMeapTreeNodeInfo *)treeNodeInfo;
@end


@protocol NSMeapTreeViewDelegate <NSObject, UIScrollViewDelegate>
@optional
// Configuring Rows for the Table View
- (CGFloat)treeView:(NSMeapTreeView *)treeView heightForRowForItem:(id)item treeNodeInfo:(NSMeapTreeNodeInfo *)treeNodeInfo;
- (NSInteger)treeView:(NSMeapTreeView *)treeView indentationLevelForRowForItem:(id)item treeNodeInfo:(NSMeapTreeNodeInfo *)treeNodeInfo;
- (void)treeView:(NSMeapTreeView *)treeView willDisplayCell:(UITableViewCell *)cell forItem:(id)item treeNodeInfo:(NSMeapTreeNodeInfo *)treeNodeInfo;

// Managin Accessory Views
- (void)treeView:(NSMeapTreeView *)treeView accessoryButtonTappedForRowForItem:(id)item treeNodeInfo:(NSMeapTreeNodeInfo *)treeNodeInfo;

//Expanding and Collapsing the Outline
- (BOOL)treeView:(NSMeapTreeView *)treeView shouldItemBeExpandedAfterDataReload:(id)item treeDepthLevel:(NSInteger)treeDepthLevel;
- (BOOL)treeView:(NSMeapTreeView *)treeView shouldExpandRowForItem:(id)item treeNodeInfo:(NSMeapTreeNodeInfo *)treeNodeInfo;
- (BOOL)treeView:(NSMeapTreeView *)treeView shouldCollapaseRowForItem:(id)item treeNodeInfo:(NSMeapTreeNodeInfo *)treeNodeInfo;
- (void)treeView:(NSMeapTreeView *)treeView willExpandRowForItem:(id)item treeNodeInfo:(NSMeapTreeNodeInfo *)treeNodeInfo;
- (void)treeView:(NSMeapTreeView *)treeView willCollapseRowForItem:(id)item treeNodeInfo:(NSMeapTreeNodeInfo *)treeNodeInfo;

//Managing Selections
- (id)treeView:(NSMeapTreeView *)treeView willSelectRowForItem:(id)item treeNodeInfo:(NSMeapTreeNodeInfo *)treeNodeInfo;
- (void)treeView:(NSMeapTreeView *)treeView didSelectRowForItem:(id)item treeNodeInfo:(NSMeapTreeNodeInfo *)treeNodeInfo;
- (id)treeView:(NSMeapTreeView *)treeView willDeselectRowForItem:(id)item treeNodeInfo:(NSMeapTreeNodeInfo *)treeNodeInfo;
- (void)treeView:(NSMeapTreeView *)treeView didDeselectRowForItem:(id)item treeNodeInfo:(NSMeapTreeNodeInfo *)treeNodeInfo;

//Editing Tree Rows
- (void)treeView:(NSMeapTreeView *)treeView willBeginEditingRowForItem:(id)item treeNodeInfo:(NSMeapTreeNodeInfo *)treeNodeInfo;
- (void)treeView:(NSMeapTreeView *)treeView didEndEditingRowForItem:(id)item treeNodeInfo:(NSMeapTreeNodeInfo *)treeNodeInfo;
- (UITableViewCellEditingStyle)treeView:(NSMeapTreeView *)treeView editingStyleForRowForItem:(id)item treeNodeInfo:(NSMeapTreeNodeInfo *)treeNodeInfo;
- (NSString *)treeView:(NSMeapTreeView *)treeView titleForDeleteConfirmationButtonForRowForItem:(id)item treeNodeInfo:(NSMeapTreeNodeInfo *)treeNodeInfo;
- (BOOL)treeView:(NSMeapTreeView *)treeView shouldIndentWhileEditingRowForItem:(id)item treeNodeInfo:(NSMeapTreeNodeInfo *)treeNodeInfo;

//Tracking the Removal of Views
- (void)treeView:(NSMeapTreeView *)treeView didEndDisplayingCell:(NSMeapTreeViewCell *)cell forItem:(id)item treeNodeInfo:(NSMeapTreeNodeInfo *)treeNodeInfo;

//Copying and Pasting Row Content
- (BOOL)treeView:(NSMeapTreeView *)treeView shouldShowMenuForRowForItem:(id)item treeNodeInfo:(NSMeapTreeNodeInfo *)treeNodeInfo;
- (BOOL)treeView:(NSMeapTreeView *)treeView canPerformAction:(SEL)action forRowForItem:(id)item treeNodeInfo:(NSMeapTreeNodeInfo *)treeNodeInfo withSender:(id)sender;
- (void)treeView:(NSMeapTreeView *)treeView performAction:(SEL)action forRowForItem:(id)item treeNodeInfo:(NSMeapTreeNodeInfo *)treeNodeInfo withSender:(id)sender;

//Managing Table View Highlighting
- (BOOL)treeView:(NSMeapTreeView *)treeView shouldHighlightRowForItem:(id)item treeNodeInfo:(NSMeapTreeNodeInfo *)treeNodeInfo;
- (BOOL)treeView:(NSMeapTreeView *)treeView didHighlightRowForItem:(id)item treeNodeInfo:(NSMeapTreeNodeInfo *)treeNodeInfo;
- (BOOL)treeView:(NSMeapTreeView *)treeView didUnhighlightRowForItem:(id)item treeNodeInfo:(NSMeapTreeNodeInfo *)treeNodeInfo;
@end


@interface NSMeapTreeView : UIView

@property (weak, nonatomic) id<NSMeapTreeViewDataSource> dataSource;
@property (weak, nonatomic) id<NSMeapTreeViewDelegate> delegate;

// Initializing a TreeView Object
- (id)initWithFrame:(CGRect)frame style:(NSMeapTreeViewStyle)style;

//Configuring a Tree View
- (NSInteger)numberOfRows;
@property (nonatomic, readonly) NSMeapTreeViewStyle style;
@property (nonatomic) NSMeapTreeViewCellSeparatorStyle separatorStyle;
@property (strong, nonatomic) UIColor *separatorColor;
@property (nonatomic) CGFloat rowHeight;
@property (strong, nonatomic) UIView *backgroundView;

//Expanding and Collapsing Rows
- (void)expandRowForItem:(id)item withRowAnimation:(NSMeapTreeViewRowAnimation)animation;
- (void)collapseRowForItem:(id)item withRowAnimation:(NSMeapTreeViewRowAnimation)animation;
- (void)expandRowForItem:(id)item;
- (void)collapseRowForItem:(id)item;
@property (nonatomic) NSMeapTreeViewRowAnimation rowsExpandingAnimation;
@property (nonatomic) NSMeapTreeViewRowAnimation rowsCollapsingAnimation;

// Creating Table View Cells
- (void)registerNib:(UINib *)nib forCellReuseIdentifier:(NSString *)identifier;
- (id)dequeueReusableCellWithIdentifier:(NSString *)identifier;

// Accessing Header and Footer Views
@property (strong, nonatomic) UIView *treeHeaderView;
@property (strong, nonatomic) UIView *treeFooterView;

// Accessing Cells
- (UITableViewCell *)cellForItem:(id)item;
- (NSArray *)visibleCells;

// Scrolling the TreeView
- (void)scrollToRowForItem:(id)item atScrollPosition:(NSMeapTreeViewScrollPosition)scrollPosition animated:(BOOL)animated;
- (void)scrollToNearestSelectedRowAtScrollPosition:(NSMeapTreeViewScrollPosition)scrollPosition animated:(BOOL)animated;
- (void)scrollToRowForItem:(id)item animated:(BOOL)animated;

// Managing Selections
- (id)itemForSelectedRow;
- (NSArray *)itemsForSelectedRows;
- (void)selectRowForItem:(id)item animated:(BOOL)animated scrollPosition:(NSMeapTreeViewScrollPosition)scrollPosition;
- (void)deselectRowForItem:(id)item animated:(BOOL)animated;
@property (nonatomic) BOOL allowsSelection;
@property (nonatomic) BOOL allowsMultipleSelection;
@property (nonatomic) BOOL allowsSelectionDuringEditing;
@property (nonatomic) BOOL allowsMultipleSelectionDuringEditing;

// Managing the Editing of Tree Cells
- (void)setEditing:(BOOL)editing animated:(BOOL)animated;
@property (nonatomic, getter = isEditing) BOOL editing;

// Reloading the Tree View
- (void)reloadData;
- (void)reloadRowsForItems:(NSArray *)items withRowAnimation:(NSMeapTreeViewRowAnimation)animation;

/////////////////////////////
// UIScrollView Staff
/////////////////////////////

//Managing the Display of Content
- (void)setContentOffset:(CGPoint)contentOffset animated:(BOOL)animated;
@property (nonatomic) CGPoint contentOffset;
@property (nonatomic) CGSize contentSize;
@property (nonatomic) UIEdgeInsets contentInset;

//Managing Scrolling
@property (nonatomic) BOOL scrollEnabled;
@property (nonatomic) BOOL directionalLockEnabled;
@property (nonatomic) BOOL scrollsToTop;
- (void)scrollRectToVisible:(CGRect)visible animated:(BOOL)animated;
@property (nonatomic) BOOL pagingEnabled;
@property (nonatomic) BOOL bounces;
@property (nonatomic) BOOL alwaysBounceVertical;
@property (nonatomic) BOOL alwaysBounceHorizontal;
@property (nonatomic) BOOL canCancelContentTouches;
@property (nonatomic) BOOL delaysContentTouches;
@property (nonatomic) BOOL decelerationRate;
@property (nonatomic, readonly) BOOL dragging;
@property (nonatomic, readonly) BOOL tracking;
@property (nonatomic, readonly) BOOL decelerating;

//Managing the Scroll Indicator
@property (nonatomic) UIScrollViewIndicatorStyle indicatorStyle;
@property (nonatomic) UIEdgeInsets scrollIndicatorInsets;
@property (nonatomic) BOOL showsHorizontalScrollIndicator;
@property (nonatomic) BOOL showsVerticalScrollIndicator;
- (void)flashScrollIndicators;

//Zooming and Panning
@property (strong, nonatomic, readonly) UIPanGestureRecognizer *panGestureRecognizer;
@property (strong, nonatomic, readonly) UIPinchGestureRecognizer *pinchGestureRecognizer;
- (void)zoomToRect:(CGRect)rect animated:(BOOL)animated;
@property (nonatomic) CGFloat zoomScale;
- (void)setZoomScale:(CGFloat)zoomScale animated:(BOOL)animated;
@property (nonatomic) CGFloat maximumZoomScale;
@property (nonatomic) CGFloat minimumZoomScale;
@property (nonatomic, readonly) BOOL zoomBouncing;
@property (nonatomic, readonly) BOOL zooming;
@property (nonatomic) BOOL bouncesZoom;

@end

