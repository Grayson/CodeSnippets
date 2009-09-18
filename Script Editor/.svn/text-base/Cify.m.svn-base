//
//  Cify.m
//  Cify
//
//  Created by Grayson Hansard on 8/17/06.
//  Copyright 2006 From Concentrate Software. All rights reserved.
//

#import "Cify.h"


@implementation Cify

+ (void)pluginDidLoad:(NSBundle *)bundle
{
	[[Cify alloc] init];
}

-(id)init
{
	self = [super init];

	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(appWillFinishLaunching:) name:NSApplicationDidFinishLaunchingNotification object:nil];

	return self;
}

-(void)appWillFinishLaunching:(NSNotification *)notification
{
	[SEScriptController swizzleSelector:@selector(compileScript:withUndo:) 
						   withSelector:@selector(realCompileScript:withUndo:) 
							forInstance:YES];
}

@end
