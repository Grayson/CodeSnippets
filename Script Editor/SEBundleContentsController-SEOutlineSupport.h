/*
 *     Generated by class-dump 3.1.
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2005 by Steve Nygard.
 */

#import "SEBundleContentsController.h"

@interface SEBundleContentsController (SEOutlineSupport)
- (id)_filterContentsOfPath:(id)fp8;
- (id)outlineView:(id)fp8 child:(int)fp12 ofItem:(id)fp16;
- (BOOL)outlineView:(id)fp8 isItemExpandable:(id)fp12;
- (int)outlineView:(id)fp8 numberOfChildrenOfItem:(id)fp12;
- (id)outlineView:(id)fp8 objectValueForTableColumn:(id)fp12 byItem:(id)fp16;
- (void)outlineView:(id)fp8 setObjectValue:(id)fp12 forTableColumn:(id)fp16 byItem:(id)fp20;
- (void)outlineView:(id)fp8 willDisplayCell:(id)fp12 forTableColumn:(id)fp16 item:(id)fp20;
- (BOOL)outlineView:(id)fp8 writeItems:(id)fp12 toPasteboard:(id)fp16;
- (unsigned int)outlineView:(id)fp8 validateDrop:(id)fp12 proposedItem:(id)fp16 proposedChildIndex:(int)fp20;
- (BOOL)outlineView:(id)fp8 acceptDrop:(id)fp12 item:(id)fp16 childIndex:(int)fp20;
@end

