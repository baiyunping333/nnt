
# ifndef __NNT_CORE_STRING_97921F73AF9D4FAD99AA5C45D592CFB2_H_INCLUDED
# define __NNT_CORE_STRING_97921F73AF9D4FAD99AA5C45D592CFB2_H_INCLUDED

NNT_BEGIN_HEADER_C

//! @param len, if -1, will calc the input str's length by strlen.
int str_indexof_char(char const*, char c, int len, int offset);

NNT_END_HEADER_C

# if defined(NNT_CXX)

# if defined(NNT_USER_SPACE)

# include <string>
# include <vector>
# include <deque>
# include <stack>

NNT_BEGIN_HEADER_CXX 
NNT_BEGIN_NS(ntl)

using ::std::string;
using ::std::stringstream;

//! present bytes as HEX char, must pass length of bytes.
NNTAPI(string) hex_cast(byte const* bytes, usize len);

//! replace/
NNTAPI(string) replace(string const&, string const& from, string const& to);
NNTAPI(string&) replace_of(string&, string const& from, string const& to);

//! present bytes from HEX char.
NNTAPI(bool) hex_cast(string const&, byte** bytes, usize* len);

//! splite string.
NNTAPI(void) split(string const& str, string const& by, ::std::vector<string>& res, bool compress = true);
NNTAPI(void) split(string const& str, string const& by, ::std::deque<string>& res, bool compress = true);

//! format.
NNTAPI(string) format(char const*, ...);

//! to string.
NNTAPI(string) tostr(int);
NNTAPI(string) tostr(uint);
NNTAPI(string) tostr(float);
NNTAPI(string) tostr(double);
NNTAPI(string) tostr(short);
NNTAPI(string) tostr(ushort);
NNTAPI(string) tostr(long);
NNTAPI(string) tostr(ulong);
NNTAPI(string) tostr(longlong);
NNTAPI(string) tostr(ulonglong);

inline_impl string const& tostr(string const& str) {
    return str;
};

//! to number.
NNTAPI(int) toint(string const&);
NNTAPI(uint) touint(string const&);
NNTAPI(bool) tobool(string const&);
NNTAPI(short) toshort(string const&);
NNTAPI(ushort) toushort(string const&);
NNTAPI(long) tolong(string const&);
NNTAPI(ulong) toulong(string const&);
NNTAPI(float) tofloat(string const&);
NNTAPI(double) todouble(string const&);
NNTAPI(real) toreal(string const&);
NNTAPI(int) hex2int(string const&);
NNTAPI(long) hex2long(string const&);
NNTAPI(longlong) hex2longlong(string const&);

# ifdef NNT_OBJC

NNTAPI(bool) tobool(NSString*);
NNTAPI(string) tostr(NSString*);
NNTAPI(int) toint(NSString*);
NNTAPI(uint) touint(NSString*);
NNTAPI(short) toshort(NSString*);
NNTAPI(ushort) toushort(NSString*);
NNTAPI(long) tolong(NSString*);
NNTAPI(ulong) toulong(NSString*);
NNTAPI(float) tofloat(NSString*);
NNTAPI(double) todouble(NSString*);
NNTAPI(real) toreal(NSString*);

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

NNT_END_NS
NNT_END_HEADER_CXX

# else // kernel space

NNT_BEGIN_HEADER_CXX 
NNT_BEGIN_NS(ntl)

class string
# ifdef NNT_MSVC
    : public uml::composition<string, UNICODE_STRING>
# endif
{
public:

    string();
    string(char const*);
    string(wchar_t const*);
    string(string const&);
    string(value_type const&);
    ~string();

    string& operator = (string const&);
    string operator + (string const&) const;
    string& operator += (string const&);
    bool operator == (string const&) const;
    bool operator != (string const&) const;

    bool is_equal(string const&, bool casesens = true) const;
    void clear();
    bool is_empty() const;
    usize length() const;

protected:

    bool _need_release;

};

static string operator + (char const* str, string const& strr)
{
    return string(str) + strr;
}

static string operator + (wchar_t const* str, string const& strr)
{
    return string(str) + strr;
}

NNT_END_NS
NNT_END_HEADER_CXX

# endif
# endif

# ifdef NNT_C_COMPATIABLE

NNT_BEGIN_HEADER_C

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

NNT_END_HEADER_C

# endif

# ifdef NNT_OBJC

NNT_BEGIN_HEADER_OBJC

@interface NNTString : NSString <NSHash>
@end

NNT_EXTERN CFStringEncoding CFStringEncodingFromWindowsLocaleCode(udword lang);

NNT_END_HEADER_OBJC

# endif

# endif