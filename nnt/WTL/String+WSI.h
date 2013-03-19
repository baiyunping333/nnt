
# ifndef __WSI_CORE_STRING_97921F73AF9D4FAD99AA5C45D592CFB2_H_INCLUDED
# define __WSI_CORE_STRING_97921F73AF9D4FAD99AA5C45D592CFB2_H_INCLUDED

WSI_BEGIN_HEADER_C

//! @param len, if -1, will calc the input str's length by strlen.
int str_indexof_char(char const*, char c, int len, int offset);

WSI_END_HEADER_C

# ifdef WSI_CXX

# include <string>
# include <vector>
# include <deque>
# include <stack>

WSI_BEGIN_HEADER_CXX 
WSI_BEGIN_NS(wtl)

using ::std::string;
using ::std::stringstream;

//! present bytes as HEX char, must pass length of bytes.
WSIAPI(string) hex_cast(byte const* bytes, usize len);

//! replace/
WSIAPI(string) replace(string const&, string const& from, string const& to);
WSIAPI(string&) replace_of(string&, string const& from, string const& to);

//! present bytes from HEX char.
WSIAPI(bool) hex_cast(string const&, byte** bytes, usize* len);

//! splite string.
WSIAPI(void) split(string const& str, string const& by, ::std::vector<string>& res, bool compress = true);
WSIAPI(void) split(string const& str, string const& by, ::std::deque<string>& res, bool compress = true);

//! format.
WSIAPI(string) format(char const*, ...);

//! to string.
WSIAPI(string) tostr(int);
WSIAPI(string) tostr(uint);
WSIAPI(string) tostr(float);
WSIAPI(string) tostr(double);
WSIAPI(string) tostr(short);
WSIAPI(string) tostr(ushort);
WSIAPI(string) tostr(long);
WSIAPI(string) tostr(ulong);

inline_impl string const& tostr(string const& str) {
    return str;
};

//! to number.
WSIAPI(int) toint(string const&);
WSIAPI(uint) touint(string const&);
WSIAPI(bool) tobool(string const&);
WSIAPI(short) toshort(string const&);
WSIAPI(ushort) toushort(string const&);
WSIAPI(long) tolong(string const&);
WSIAPI(ulong) toulong(string const&);
WSIAPI(float) tofloat(string const&);
WSIAPI(double) todouble(string const&);
WSIAPI(real) toreal(string const&);
WSIAPI(int) hex2int(string const&);
WSIAPI(long) hex2long(string const&);
WSIAPI(longlong) hex2longlong(string const&);

# ifdef WSI_OBJC

WSIAPI(bool) tobool(NSString*);
WSIAPI(string) tostr(NSString*);
WSIAPI(int) toint(NSString*);
WSIAPI(uint) touint(NSString*);
WSIAPI(short) toshort(NSString*);
WSIAPI(ushort) toushort(NSString*);
WSIAPI(long) tolong(NSString*);
WSIAPI(ulong) toulong(NSString*);
WSIAPI(float) tofloat(NSString*);
WSIAPI(double) todouble(NSString*);
WSIAPI(real) toreal(NSString*);

# endif

template <typename StrT, typename ConT>
static StrT combine(ConT const& con, StrT const& sep)
{
    typename ConT::const_iterator iter = con.begin();
    StrT re;
    while (iter != con.end())
    {
        re += *iter;
        if (++iter != con.end())
            re += sep;
    }
    
    return re;
}

const string null_string = "";

template <typename valT>
inline_impl string& operator << (string& str, valT const& val)
{
    str += tostr(val);
    return str;
}

WSI_END_NS

WSI_BEGIN_NS(core)

using namespace wtl;

WSI_END_NS

WSI_END_HEADER_CXX

# endif

# ifdef WSI_C_COMPATIABLE

WSI_BEGIN_HEADER_C

static const char MAP_BINARY_ASCII_LOWER[16] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
};

static const char MAP_BINARY_ASCII[16] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
};

extern uchar crd(char);

static const char MAP_ASCII_BINARY[] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0x0,
    0x1,
    0x2,
    0x3,
    0x4,
    0x5,
    0x6,
    0x7,
    0x8,
    0x9,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0xA,
    0xB,
    0xC,
    0xD,
    0xE,
    0xF,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0xa,
    0xb,
    0xc,
    0xd,
    0xe,
    0xf,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
};

static const char MAP_ASCII_BINARY_MATCH[] = {
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    0x0,
    0x1,
    0x2,
    0x3,
    0x4,
    0x5,
    0x6,
    0x7,
    0x8,
    0x9,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    0xA,
    0xB,
    0xC,
    0xD,
    0xE,
    0xF,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    0xa,
    0xb,
    0xc,
    0xd,
    0xe,
    0xf,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1,
    -1
};

static const char MAP_ASCII_BINARY_XID[] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0x0,
    0x1,
    0x2,
    0x3,
    0x4,
    0x5,
    0x6,
    0x7,
    0x8,
    0x9,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0xA,
    0xB,
    0xC,
    0xD,
    0xE,
    0xF,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    -1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0xa,
    0xb,
    0xc,
    0xd,
    0xe,
    0xf,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    -1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
};

WSI_END_HEADER_C

# endif

# ifdef WSI_OBJC

WSI_BEGIN_HEADER_OBJC

@interface WSIString : NSString <NSHash> {
    
}

@end

extern CFStringEncoding CFStringEncodingFromWindowsLocaleCode(udword lang);

WSI_END_HEADER_OBJC

# endif

# endif