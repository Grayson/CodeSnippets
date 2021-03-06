/*
 *     Generated by class-dump 3.1.
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2005 by Steve Nygard.
 */

#import "SEPreferences.h"

@class NSPopUpButton;

@interface SEGeneralPreferences : SEPreferences
{
    unsigned int _defaultLanguageType;
    NSPopUpButton *_languagePopUpButton;
}

+ (id)sharedGeneralPreferences;
- (id)initWithOwner:(id)fp8;
- (void)dealloc;
- (void)awakeFromNib;
- (unsigned long)defaultLanguageType;
- (void)setDefaultLanguageType:(unsigned long)fp8;
- (void)read;
- (void)write;
- (void)defaultLanguageChanged:(id)fp8;

@end

