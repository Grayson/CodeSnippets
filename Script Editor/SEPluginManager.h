/*
 *     Generated by class-dump 3.1.
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2005 by Steve Nygard.
 */

#import "NSObject.h"

@class NSMutableArray;

@interface SEPluginManager : NSObject
{
    NSMutableArray *_plugins;
}

+ (id)sharedPluginManager;
- (id)init;
- (void)dealloc;
- (id)plugins;
- (id)_searchPaths;
- (void)findAndLoadPlugins;
- (void)menu:(id)fp8 forEvent:(id)fp12 inView:(id)fp16;
- (id)toolbar:(id)fp8 itemForItemIdentifier:(id)fp12 willBeInsertedIntoToolbar:(BOOL)fp16;
- (void)allowedItemIdentifiers:(id)fp8 forToolbar:(id)fp12;
- (BOOL)validateToolbarItem:(id)fp8;

@end
