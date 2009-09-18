/*
 *     Generated by class-dump 3.1.
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2005 by Steve Nygard.
 */

#import "SEPreferences.h"

@class NSMutableDictionary, NSTableView, SEDataSource;

@interface SEPlugInPreferences : SEPreferences
{
    NSTableView *_tableView;
    SEDataSource *_dataSource;
    NSMutableDictionary *_pluginPreferences;
}

- (id)initWithOwner:(id)fp8;
- (void)dealloc;
- (void)awakeFromNib;
- (id)tableView;
- (id)dataSource;
- (void)read;
- (void)write;

@end

