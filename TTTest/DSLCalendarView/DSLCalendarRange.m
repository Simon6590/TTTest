/*
 DSLCalendarRange.m
 
 Copyright (c) 2012 Dative Studios. All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 
 * Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 
 * Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.
 
 * Neither the name of the author nor the names of its contributors may be used
 to endorse or promote products derived from this software without specific
 prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#import "DSLCalendarRange.h"


@interface DSLCalendarRange ()

@property (nonatomic, retain) NSDate *startDate;

@property (nonatomic, retain) NSDate *endDate;

@end

@implementation DSLCalendarRange 

- (void)dealloc
{
    self.startDay = nil;
    self.endDay = nil;
    self.startDate = nil;
    self.endDate = nil;
    
    [super dealloc];
}

// Designated initialiser
- (id)initWithStartDay:(NSDateComponents *)start endDay:(NSDateComponents *)end
{
    NSParameterAssert(start);
    NSParameterAssert(end);
    
    self = [super init];
    if (self)
    {
        // Initialise properties
        self.startDay = [start retain];
        self.startDate = [start date];
        self.endDay = [end retain];
        self.endDate = [end date];
    }

    return self;
}


#pragma mark - Properties

//- (void)setStartDay:(NSDateComponents *)startDay
//{
//    NSParameterAssert(startDay);
//    self.startDay = [startDay copy];
//}
//
//- (void)setEndDay:(NSDateComponents *)endDay
//{
//    NSParameterAssert(endDay);
//    self.endDay = [endDay copy];
//}


#pragma mark

- (BOOL)containsDay:(NSDateComponents*)day
{
    return [self containsDate:day.date];
}

- (BOOL)containsDate:(NSDate*)date
{
    if ([self.startDate compare:date] == NSOrderedDescending)
    {
        return NO;
    }
    else if ([self.endDate compare:date] == NSOrderedAscending)
    {
        return NO;
    }
    
    return YES;
}

@end
