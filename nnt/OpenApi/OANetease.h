
#ifndef __OANetEase_5E0CC85CDC964E52A9919DD62EF732BE_H_INCLUDED
#define __OANetEase_5E0CC85CDC964E52A9919DD62EF732BE_H_INCLUDED

# import "OAuth.h"

WSI_BEGIN_HEADER_OBJC

@interface OARequestNetease : OARequest_1_0 {
    NSString *urlCallback;
}

@property (nonatomic, copy) NSString *urlCallback;

@end

@interface OAuthorizeNetease : OAuthorize_1_0
@end

@interface OAccessNetease : OAccess_1_0
@end

@interface OANetease : OAuth_1_0 
@end

@interface OANeteaseWeibo : OANetease
@end

@interface OApiNetease : OACommonApi_1_0
@end

@interface OApiNetUserInfo : OApiNetease
@end

@interface OApiNetSuggestions : OApiNetease
@end

@interface OApiNeteaseWeiboPost : OApiNetease

@property (nonatomic, copy) NSString *content;

@end

@interface OApiNeteaseWeiboUpload : OApiNetease

@property (nonatomic, copy) NSString * content;
@property (nonatomic, retain) WCGImage* image;
@property (nonatomic, retain) NSData* imageData;

@end

WSI_END_HEADER_OBJC

# ifdef WSI_CXX

WSI_BEGIN_HEADER_CXX
WSI_BEGIN_NS(netease)

typedef oauth::Provider<OANetease> Provider;

WSI_BEGIN_NS(weibo)

typedef oauth::Function<OApiNetUserInfo> Userinfo;
typedef oauth::PostFunction<OApiNeteaseWeiboPost> Post;
typedef oauth::UploadFunction<OApiNeteaseWeiboUpload> Upload;

WSI_END_NS

WSI_END_NS
WSI_END_HEADER_CXX

# endif

#endif