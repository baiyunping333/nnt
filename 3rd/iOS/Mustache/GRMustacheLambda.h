// The MIT License
// 
// Copyright (c) 2010 Gwendal Roué
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import "GRMustacheEnvironment.h"
#import "GRMustacheSection.h"

@class GRMustacheContext;

#if GRMUSTACHE_BLOCKS_AVAILABLE
@interface GRMustacheBlockHelper: NSObject {
@private
	NSString *(^block)(GRMustacheSection* section, id context);
}
+ (id)helperWithBlock:(NSString *(^)(GRMustacheSection* section, id context))block;
@end

// =================== DEPRECATED STUFF BELOW ===================

typedef NSString *(^GRMustacheRenderingBlock)(GRMustacheSection*, GRMustacheContext*);
id GRMustacheLambdaBlockMake(GRMustacheRenderingBlock block) __attribute__((deprecated));

typedef NSString *(^GRMustacheRenderer)(id object);
typedef id GRMustacheLambda __attribute__((deprecated));
GRMustacheLambda GRMustacheLambdaMake(NSString *(^block)(NSString *(^)(id object), id, NSString *)) __attribute__((deprecated));
#endif
