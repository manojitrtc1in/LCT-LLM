#define _tmc is_trivially_move_constructible_v
#define _tcc is_trivially_copy_constructible_v
#define _mc is_move_constructible_v
#define _icv is_class_v
#define F friend
#define S  salgo::
#define _c _container()
#define _h _handle()
#define _a auto
#define _te template
#define _ty typename
#define _cl class
#define CF Const_Flag
#define _ce constexpr
#define _re return
#define _uB  using BASE::
#define cr construct
#define _ const
#define _op operator
#define _u using
#include <bits/stdc++.h>
_u namespace std;
#ifdef USE_FAST_IO
#define FREAD  fread_unlocked
#define FWRITE fwrite_unlocked
struct Buffer {
FILE* _ stream;
_ int buffer_size;
uint8_t* _ buff;
int pos = 0;
Buffer(FILE* a_stream, int a_buffer_size) :
stream( a_stream ),
buffer_size( a_buffer_size ),
buff( new uint8_t[ buffer_size ] ) {
setvbuf(stream, NULL, _IONBF, 0);
}
~Buffer() {
delete[] buff;
}
};
_cl In_Buffer : private Buffer {
public:
In_Buffer(FILE* a_stream, int a_buffer_size) : Buffer(a_stream, a_buffer_size) {
FREAD(buff, 1, buffer_size, stream);
}
public:
void prepare(int num_chars) {
int remaining = buffer_size - pos;
if(remaining >= num_chars) _re;
memcpy(buff, buff+pos, remaining);
FREAD(buff+remaining, 1, pos, stream);
pos = 0;
}
public:
char get_unchecked() {
_re buff[ pos++ ];
}
};
_te<_cl INT>
INT read_unsigned(In_Buffer& buff) {
buff.prepare(25);
char c = buff.get_unchecked();
while(c < '-') c = buff.get_unchecked();
INT r = 0;
for(;;) {
if(c < '0') _re r;
c -= '0';
r = r*10 + c;
c = buff.get_unchecked();
}
}
_te<_cl INT>
INT read_signed(In_Buffer& buff) {
buff.prepare(25);
char c = buff.get_unchecked();
while(c < '-') c = buff.get_unchecked();
bool minus = false;
if(c=='-') {
c = buff.get_unchecked();
minus = true;
}
INT r = 0;
for(;;)
{
if(c < '0') _re minus ? -r : r;
c -= '0';
r = r*10 + c;
c = buff.get_unchecked();
}
}
In_Buffer& _op>>( In_Buffer& buff, char& c) {
buff.prepare(1);
c = buff.get_unchecked();
_re buff;
}
In_Buffer& _op>>( In_Buffer& buff, uint16_t& r) { r = read_unsigned<uint16_t>(buff); _re buff; }
In_Buffer& _op>>( In_Buffer& buff, uint32_t& r) { r = read_unsigned<uint32_t>(buff); _re buff; }
In_Buffer& _op>>( In_Buffer& buff, uint64_t& r) { r = read_unsigned<uint64_t>(buff); _re buff; }
In_Buffer& _op>>( In_Buffer& buff, unsigned long long& r) { r = read_unsigned<unsigned long long>(buff); _re buff; }
In_Buffer& _op>>( In_Buffer& buff, int16_t& r) { r = read_signed<int16_t>(buff); _re buff; }
In_Buffer& _op>>( In_Buffer& buff, int32_t& r) { r = read_signed<int32_t>(buff); _re buff; }
In_Buffer& _op>>( In_Buffer& buff, int64_t& r) { r = read_signed<int64_t>(buff); _re buff; }
In_Buffer& _op>>( In_Buffer& buff, long long& r) { r = read_signed<long long>(buff); _re buff; }
In_Buffer& _op>>( In_Buffer& buff, string& r) {
r.clear();
char c = buff.get_unchecked();
while(c <= ' ') c = buff.get_unchecked();
do {
r.push_back( c );
c = buff.get_unchecked();
} while(c > ' ');
_re buff;
}
_cl Out_Buffer : private Buffer {
public:
Out_Buffer(FILE* a_stream, int a_buffer_size) : Buffer(a_stream, a_buffer_size) {}
~Out_Buffer() {
flush();
}
public:
void prepare(int num_chars) {
if(buffer_size - pos >= num_chars) _re;
flush();
}
void flush() {
FWRITE(buff, 1, pos, stream);
pos = 0;
}
public:
void put_unchecked(_ char& c) {
buff[ pos++ ] = c;
}
void put_unchecked(_ char* str, int len) {
memcpy(buff+pos, str, len);
pos += len;
}
};
_te<_cl INT>
void write_signed(Out_Buffer& buff, _ INT& i) {
buff.prepare(25);
if(i == 0) {
buff.put_unchecked('0');
_re;
}
_a ci = i;
if(ci < 0) {
buff.put_unchecked('-');
ci = -ci;
}
_ int sz = 25;
char temp[sz];
int pos = sz;
while(ci) {
temp[ --pos ] = '0' + ci%10;
ci/=10;
}
buff.put_unchecked(temp+pos, sz-pos);
}
_te<_cl INT>
void write_unsigned(Out_Buffer& buff, _ INT& i) {
buff.prepare(25);
if(i==0) {
buff.put_unchecked('0');
_re;
}
_ int sz = 25;
char temp[sz];
int pos = sz;
_a ci = i;
while(ci) {
temp[ --pos ] = '0' + ci%10;
ci/=10;
}
buff.put_unchecked(temp+pos, sz-pos);
}
Out_Buffer& _op<<( Out_Buffer& buff, _ char& c) {
buff.prepare(1);
buff.put_unchecked( c );
_re buff;
}
Out_Buffer& _op<<( Out_Buffer& buff, _ uint16_t& r) { write_unsigned<uint16_t>(buff, r); _re buff; }
Out_Buffer& _op<<( Out_Buffer& buff, _ uint32_t& r) { write_unsigned<uint32_t>(buff, r); _re buff; }
Out_Buffer& _op<<( Out_Buffer& buff, _ uint64_t& r) { write_unsigned<uint64_t>(buff, r); _re buff; }
Out_Buffer& _op<<( Out_Buffer& buff, _ int16_t& r) { write_signed<int16_t>(buff, r); _re buff; }
Out_Buffer& _op<<( Out_Buffer& buff, _ int32_t& r) { write_signed<int32_t>(buff, r); _re buff; }
Out_Buffer& _op<<( Out_Buffer& buff, _ int64_t& r) { write_signed<int64_t>(buff, r); _re buff; }
Out_Buffer& _op<<( Out_Buffer& buff, _ char* cstr) { _a len = strlen(cstr); buff.prepare(len); buff.put_unchecked(cstr, len); _re buff; }
Out_Buffer& _op<<( Out_Buffer& buff, _ string& str) { buff.prepare( str.size() ); buff.put_unchecked(str.data(), str.size()); _re buff; }
#define BUFF_SIZE 32768
In_Buffer  fast_cin(  stdin,  BUFF_SIZE );
Out_Buffer fast_cout( stdout, BUFF_SIZE );
char fast_endl = '\n';
#define cin fast_cin
#define cout fast_cout
#define cerr fast_cerr
#define endl fast_endl
#else
struct Slow_IO_Singleton {
Slow_IO_Singleton() {
ios_base::sync_with_stdio( false );
std::cin.tie( nullptr );
std::cout.tie( nullptr );
setlocale(LC_ALL,"C");
_ int buffer_size = 32768;
static char stdin_buffer[ buffer_size ];
static char stdout_buffer[ buffer_size ];
cin.rdbuf()->pubsetbuf( stdin_buffer, buffer_size );
cout.rdbuf()->pubsetbuf( stdout_buffer, buffer_size );
}
~Slow_IO_Singleton() {
}
};
Slow_IO_Singleton slow_io_singleton;
#define endl '\n'
#endif
#define ASS(x) assert(x)
#define uint unsigned int
#define ll long long
#define ull unsigned long long
_a ri()   { int r; cin >> r; _re r; }
_a rui()  { uint r; cin >> r; _re r; }
_a rll()  { ll r;  cin >> r; _re r; }
_a rull() { ull r; cin >> r; _re r; }
_a rstr() {string s; cin >> s; _re s; }
#define FOR(i,n) for(int i=0; i<int(n); ++i)
#define FO(i,a,b) for(int i=(a); i<int(b); ++i)
#define OF(i,a,b) for(int i=(a)-1; i>=int(b); --i)
#define MIN(a,b) ((a)<(b) ? (a) : (b))
#define MAX(a,b) ((b)<(a) ? (a) : (b))
#define REMIN(a,b) ((a) = min(a,b))
#define REMAX(a,b) ((a) = max(a,b))
#include <type_traits>
#include <iostream>
#include <iomanip>
namespace salgo {
#define GENERATE_HAS_MEMBER(member) \
\
_te < _cl T > \
_cl _Class_Has_Member__##member \
{ \
struct Fallback { int member; }; \
struct Derived : T, Fallback { }; \
\
_te<_ty U, U> struct Check; \
\
typedef char ArrayOfOne[1]; \
typedef char ArrayOfTwo[2]; \
\
_te<_ty U> static ArrayOfOne & func(Check<int Fallback::*, &U::member> *); \
_te<_ty U> static ArrayOfTwo & func(...); \
public: \
enum { value = sizeof(func<Derived>(0)) == 2 }; \
}; \
\
_te<_cl T> \
_u _Has_Member__##member = std::conditional_t< std::_icv<T>, _Class_Has_Member__##member<T>, std::false_type>; \
\
_te<_cl X> \
static _ce bool has_member__##member = _Has_Member__##member<X>::value;
#define ENABLE_BITWISE_OPERATORS(X) \
\
_ce X _op | (X lhs, X rhs)\
{ \
_u underlying = _ty std::underlying_type_t<X>;\
_re static_cast<X> ( \
static_cast<underlying>(lhs) |\
static_cast<underlying>(rhs) \
);\
} \
\
_ce X _op & (X lhs, X rhs) \
{ \
_u underlying = _ty std::underlying_type_t<X>;\
_re static_cast<X> ( \
static_cast<underlying>(lhs) &\
static_cast<underlying>(rhs) \
);\
} \
\
_ce X _op ! (X x) \
{ \
_u underlying = _ty std::underlying_type_t<X>;\
_re static_cast<X> ( \
! static_cast<underlying>(x) \
);\
} \
\
_ce X _op ~ (X x) \
{ \
_u underlying = _ty std::underlying_type_t<X>;\
_re static_cast<X> ( \
~ static_cast<underlying>(x) \
);\
}
#define FORWARDING_CONSTRUCTOR(SELF,BASE) \
_te<_cl... ARGS> \
SELF(ARGS&&... args) : BASE{ std::forward<ARGS>(args)... }
#define FORWARDING_INITIALIZER_LIST_CONSTRUCTOR(SELF,BASE) \
_te<_cl _X> SELF(std::initializer_list<_X>&& il) : BASE( std::move(il) )
#define EXPLICIT_FORWARDING_CONSTRUCTOR(SELF,BASE) \
_te<_cl... ARGS> \
explicit SELF(ARGS&&... args) : BASE{ std::forward<ARGS>(args)... }
#define EXPLICIT_FORWARDING_INITIALIZER_LIST_CONSTRUCTOR(SELF,BASE) \
_te<_cl _X> explicit SELF(std::initializer_list<_X>&& il) : BASE( std::move(il) )
#define CRTP_COMMON(THIS_BASE, CRTP_DERIVED)\
private:\
_a& _self()	   { _re *static_cast<	   CRTP_DERIVED* >(this); }\
_a& _self() _ { _re *static_cast< _ CRTP_DERIVED* >(this); }
struct First_Tag {};
struct Last_Tag {};
#define FIRST S First_Tag()
#define LAST S Last_Tag()
#define ADD_MEMBER(member) \
_te<_cl TYPE, bool> struct Add_##member { \
TYPE member; \
FORWARDING_CONSTRUCTOR(Add_##member, member) {} \
}; \
_te<_cl TYPE> struct Add_##member<TYPE,false> {};
}

#include <functional>
namespace salgo {
enum _cl CF {
MUTAB = 0,
CONST = 1
};
namespace {
_ce _a MUTAB = CF::MUTAB;
_ce _a CONST = CF::CONST;
};
_te<_cl T, CF c> _u Const = std::conditional_t<c == CONST, _ T, T>;
}
#define CHECK_EQ(...) if(0) cerr
#define DCHECK_EQ(...) if(0) cerr
#define CHECK_GE(...) if(0) cerr
#define DCHECK_GE(...) if(0) cerr
#define CHECK(...) if(0) cerr
#define DCHECK(...) if(0) cerr
#define LOG(...) if(0) cerr
#define DLOG(...) if(0) cerr
namespace salgo {
namespace internal {
namespace Stack_Storage {
_te<
_cl _T,
bool _TREAT_AS_POD,
bool _TREAT_AS_VOID,
bool _PERSISTENT
>
struct Context {
_u T = _T;
static _ce bool Treat_As_Pod = _TREAT_AS_POD;
static _ce bool Treat_As_Void = _TREAT_AS_VOID;
static _ce bool Persistent = _PERSISTENT;
_cl Stack_Storage__nt {
private:
char data[ sizeof(T) ];
#ifndef NDEBUG
bool cred = false;
#endif
static_assert(Treat_As_Pod + Treat_As_Void + Persistent <= 1, "can have max 1");
public:
Stack_Storage__nt() = default;
Stack_Storage__nt(_ Stack_Storage__nt& o) {
#ifndef NDEBUG
DCHECK(o.cred);
DCHECK(!cred);
#endif
cr(*(_ T*)&o.data[0]);
}
Stack_Storage__nt(Stack_Storage__nt&& o) {
#ifndef NDEBUG
DCHECK(o.cred);
DCHECK(!cred);
#endif
cr( std::move( *(T*)&o.data[0] ) );
}
Stack_Storage__nt& _op=(_ Stack_Storage__nt& o) {
#ifndef NDEBUG
DCHECK(o.cred);
DCHECK(cred);
#endif
*(T*)&data[0] = *(_ T*)&o.data[0];
_re *this;
}
#ifndef NDEBUG
~Stack_Storage__nt() {
if _ce( !std::is_trivially_destructible_v<T> ) DCHECK(!cred);
}
#endif
_te<_cl... ARGS>
void cr(ARGS&&... args) {
#ifndef NDEBUG
DCHECK(!cred);
cred = true;
#endif
new (&get()) T( std::forward<ARGS>(args)... );
}
void destruct() {
get().~T();
#ifndef NDEBUG
DCHECK(cred);
cred = false;
#endif
}
inline _op T&() {
_re get();
}
inline _op _ T&() _ {
_re get();
}
inline T& get() {
#ifndef NDEBUG
DCHECK(cred);
#endif
_re *reinterpret_cast<T*>( &data[0] );
}
inline _ T& get() _ {
#ifndef NDEBUG
DCHECK(cred);
#endif
_re *reinterpret_cast<_ T*>( &data[0] );
}
};
_cl Stack_Storage__t {
private:
char data[ sizeof(T) ];
#ifndef NDEBUG
bool cred = false;
#endif
static_assert(Treat_As_Pod + Treat_As_Void + Persistent <= 1, "can have max 1");
public:
_te<_cl... ARGS>
void cr(ARGS&&... args) {
new (&get()) T( std::forward<ARGS>(args)... );
}
void destruct() { static_assert(std::is_trivially_destructible_v<T>); }
_op _a&()       { _re get(); }
_op _a&() _ { _re get(); }
T& get() {
_re *reinterpret_cast<T*>( &data[0] );
}
_ T& get() _ {
_re *reinterpret_cast<_ T*>( &data[0] );
}
};
_cl Stack_Storage__noop {
private:
char data[ sizeof(T) ];
static_assert(Treat_As_Pod + Treat_As_Void + Persistent <= 1, "can have max 1");
public:
Stack_Storage__noop() {}
Stack_Storage__noop(_ Stack_Storage__noop&) {}
Stack_Storage__noop(Stack_Storage__noop&&) {}
Stack_Storage__noop& _op=(_ Stack_Storage__noop&) { _re *this; }
Stack_Storage__noop& _op=(Stack_Storage__noop&&) { _re *this; }
bool _op==(_ Stack_Storage__noop& o) _ { _re get() == o.get(); }
bool _op!=(_ Stack_Storage__noop& o) _ { _re get() != o.get(); }
public:
_te<_cl... ARGS>
void cr(ARGS&&... args) {
new (&get()) T( std::forward<ARGS>(args)... );
}
void destruct() {}
_op _a&()       { _re get(); }
_op _a&() _ { _re get(); }
T& get() {
_re *reinterpret_cast<T*>( &data[0] );
}
_ T& get() _ {
_re *reinterpret_cast<_ T*>( &data[0] );
}
};
_u Stack_Storage = std::conditional_t<
Treat_As_Void,
Stack_Storage__noop,
std::conditional_t<
Treat_As_Pod || std::_tmc<T>,
Stack_Storage__t,
Stack_Storage__nt
>
>;
struct With_Builder_Persistent;
struct With_Builder : Stack_Storage {
FORWARDING_CONSTRUCTOR(With_Builder, Stack_Storage) {}
_u TREAT_AS_POD =
_ty Context<T, true, Treat_As_Void, Persistent> :: With_Builder;
_u TREAT_AS_VOID =
_ty Context<T, Treat_As_Pod, true, Persistent> :: With_Builder;
_u PERSISTENT =
_ty Context<T, Treat_As_Pod, Treat_As_Void, true> :: With_Builder_Persistent;
};
struct With_Builder_Persistent : With_Builder {
With_Builder_Persistent() { static_assert(Persistent); }
With_Builder_Persistent(_ With_Builder_Persistent&) = delete;
With_Builder_Persistent(With_Builder_Persistent&&) = delete;
With_Builder_Persistent& _op=(_ With_Builder_Persistent&) = delete;
With_Builder_Persistent& _op=(With_Builder_Persistent&&) = delete;
};
};
}
}
_te<_cl T>
_u Stack_Storage = _ty internal::Stack_Storage::Context<
T,
false,
false,
false
> :: With_Builder;
}
namespace salgo {
namespace internal {
GENERATE_HAS_MEMBER(Reference)
_te<bool, CF C, _cl CONTEXT>
_cl _Reference;
_te<CF C, _cl CONTEXT>
_u Reference = _Reference< has_member__Reference<CONTEXT>, C, CONTEXT>;
_te<CF C, _cl CONTEXT> _cl Accessor_Base;
_te<CF C, _cl CONTEXT> _cl Iterator_Base;
_te<CF C, _cl CONTEXT>
_cl Reference_Base {
public:
_u Container = _ty CONTEXT::Container;
_u Handle = _ty CONTEXT::Handle;
_te<CF CC> _u Reference = Reference<C,CONTEXT>;
_te<CF CC> _u Accessor = _ty CONTEXT::_te Accessor<CC>;
_te<CF CC> _u Iterator = _ty CONTEXT::_te Iterator<CC>;
public:
Reference_Base(Const<Container,C>* container, Handle handle) : __handle(handle), __container(container) {}
private:
Handle __handle;
Const<Container,C>* __container;
public:
_a& accessor()       { _check(); _re *static_cast<      Accessor<C>*>(this); }
_a& accessor() _ { _check(); _re *static_cast<_ Accessor<C>*>(this); }
_a& iterator()       { _check(); _re *static_cast<      Iterator<C>*>(this); }
_a& iterator() _ { _check(); _re *static_cast<_ Iterator<C>*>(this); }
private:
void _check() _ {
static_assert(sizeof(Accessor<C>) == sizeof(Reference<C>), "Accessors can't have any additional members");
static_assert(sizeof(Iterator<C>) == sizeof(Reference<C>), "Accessors can't have any additional members");
}
protected:
_a& _h       { _re __handle; }
_a& _h _ { _re __handle; }
_a& _c       { _re *__container; }
_a& _c _ { _re *__container; }
_a& _val()       { _re (*__container)[__handle]; }
_a& _val() _ { _re (*__container)[__handle]; }
void _will_compare_with(_ Reference_Base& o) _ {
DCHECK_EQ(__container, o.__container) << "comparing iterators to different containers";
}
public:
_a     handle() _ { _re _h; }
_op Handle() _ { _re handle(); }
_a& _op()()       { _re _val(); }
_a& _op()() _ { _re _val(); }
_op       _a&()       { _re _op()(); }
_op _ _a&() _ { _re _op()(); }
bool exists() _ { _re _h.valid(); }
};
_te<bool, CF C, _cl CONTEXT>
_cl _Reference : public CONTEXT::_te Reference<C> {
_u BASE = _ty CONTEXT::_te Reference<C>;
public:
FORWARDING_CONSTRUCTOR(_Reference, BASE) {}
};
_te<CF C, _cl CONTEXT>
_cl _Reference<false,C,CONTEXT> : public Reference_Base<C, CONTEXT> {
_u BASE = Reference_Base<C, CONTEXT>;
public:
FORWARDING_CONSTRUCTOR(_Reference, BASE) {}
};
_te<CF C, _cl CONTEXT>
_u Reference = _Reference< has_member__Reference<CONTEXT>, C, CONTEXT>;
_te<CF C, _cl CONTEXT>
_cl Accessor_Base : public Reference<C,CONTEXT> {
_u BASE = Reference<C,CONTEXT>;
public:
_u Handle = _ty BASE::Handle;
_te<CF CC>	_u Accessor = _ty BASE::_te Accessor<CC>;
public:
FORWARDING_CONSTRUCTOR(Accessor_Base, BASE) {}
_te<_cl VAL>
_a& _op=(VAL&& val) { BASE::_op()() = std::forward<VAL>(val); _re _self(); }
public:
Accessor<C>& _op++() { ++BASE::_op()(); _re _self(); }
Accessor<C>& _op--() { --BASE::_op()(); _re _self(); }
_a _op++(int) { _re BASE::_op()()++; }
_a _op--(int) { _re BASE::_op()()--; }
public:
_a next() _ { _a r = _self(); ++r.iterator(); _re r; }
_a prev() _ { _a r = _self(); --r.iterator(); _re r; }
private:
_uB accessor;
public:
CRTP_COMMON( Iterator_Base, Accessor<C> )
};
GENERATE_HAS_MEMBER(_get_comparable);
GENERATE_HAS_MEMBER(_will_compare_with);
GENERATE_HAS_MEMBER(_increment_n);
GENERATE_HAS_MEMBER(_decrement_n);
_te<CF C, _cl CONTEXT>
_cl Iterator_Base : public Reference<C,CONTEXT> {
_u BASE = Reference<C,CONTEXT>;
public:
_u Handle = _ty BASE::Handle;
_te<CF CC>	_u Iterator = _ty BASE::_te Iterator<CC>;
public:
FORWARDING_CONSTRUCTOR(Iterator_Base, BASE) {}
public:
_u difference_type = ptrdiff_t;
_u value_type = char;
_u pointer = value_type*;
_u reference = value_type&;
_u iterator_category = std::bidirectional_iterator_tag;
public:
_a&  _op++()&  { _self()._increment(); _re            _self()  ; }
_a&& _op++()&& { _self()._increment(); _re std::move( _self() ); }
_a&  _op--()&  { _self()._decrement(); _re            _self()  ; }
_a&& _op--()&& { _self()._decrement(); _re std::move( _self() ); }
_a _op++(int) { _a old = _self(); _self()._increment(); _re old; }
_a _op--(int) { _a old = _self(); _self()._decrement(); _re old; }
public:
Iterator<C>& _op+=(int n) {
if _ce(has_member___increment_n< Iterator<C> >) _self()._increment_n(n);
else for(int i=0; i<n; ++i) _self()._increment();
_re _self();
}
Iterator<C>& _op-=(int n) {
if _ce(has_member___decrement_n< Iterator<C> >) _self()._decrement_n(n);
else for(int i=0; i<n; ++i) _self()._decrement();
_re _self();
}
public:
Iterator<C> _op+(int n) {
_a iter = _self();
iter += n;
_re iter;
}
Iterator<C> _op-(int n) {
_a iter = _self();
iter -= n;
_re iter;
}
public:
_te<CF CC>
bool _op==(_ Iterator<CC>& o) _ {
_will_compare_with_base(o);
_re _get_comparable_base() == o._get_comparable_base();
}
_te<CF CC>
bool _op!=(_ Iterator<CC>& o) _ {
_will_compare_with_base(o);
_re _get_comparable_base() != o._get_comparable_base();
}
_te<CF CC>
bool _op<(_ Iterator<CC>& o) _ {
_will_compare_with_base(o);
_re _get_comparable_base() < o._get_comparable_base();
}
_te<CF CC>
bool _op>(_ Iterator<CC>& o) _ {
_will_compare_with_base(o);
_re _get_comparable_base() > o._get_comparable_base();
}
_te<CF CC>
bool _op<=(_ Iterator<CC>& o) _ {
_will_compare_with_base(o);
_re _get_comparable_base() <= o._get_comparable_base();
}
_te<CF CC>
bool _op>=(_ Iterator<CC>& o) _ {
_will_compare_with_base(o);
_re _get_comparable_base() >= o._get_comparable_base();
}
private:
_te<CF CC>
void _will_compare_with_base(_ Iterator<CC>& o) _ {
if _ce(has_member___will_compare_with<BASE>) {
BASE::_will_compare_with(o);
}
if _ce(has_member___will_compare_with< Iterator<C> >) {
_self()._will_compare_with(o);
}
}
decltype(_a) _get_comparable_base() _ {
if _ce(has_member___get_comparable< Iterator<C> >) {
_re _self()._get_comparable();
}
else {
_re BASE::_h;
}
}
public:
_a& _op*()       { _re BASE::accessor(); }
_a& _op*() _ { _re BASE::accessor(); }
_a _op->()       { _re &BASE::accessor(); }
_a _op->() _ { _re &BASE::accessor(); }
private:
_uB iterator;
public:
CRTP_COMMON( Iterator_Base, Iterator<C> )
};
_te<CF C, _te<CF> _cl Iterator>
_cl Iterator_Base_Old {
public:
Iterator_Base_Old() = default;
Iterator_Base_Old(_ Iterator_Base_Old&) = delete;
Iterator_Base_Old(Iterator_Base_Old&&) = default;
Iterator_Base_Old& _op=(_ Iterator_Base_Old&) = delete;
Iterator_Base_Old& _op=(Iterator_Base_Old&&) = delete;
public:
_u difference_type = ptrdiff_t;
_u value_type = char;
_u pointer = value_type*;
_u reference = value_type&;
_u iterator_category = std::bidirectional_iterator_tag;
public:
_a& _op++() {
_self()._increment();
_re _self(); }
_a _op++(int) {
_a old = _self();
_self()._increment();
_re old; }
_a& _op--() {
_self()._decrement();
_re _self(); }
_a _op--(int) {
_a old = _self();
_self()._decrement();
_re old; }
public:
_te<CF CC>
bool _op==(_ Iterator<CC>& o) _ {
_will_compare_with_base(o);
_re _self()._get_comparable() == o._get_comparable();
}
_te<CF CC>
bool _op!=(_ Iterator<CC>& o) _ {
_will_compare_with_base(o);
_re _self()._get_comparable() != o._get_comparable();
}
_te<CF CC>
bool _op<(_ Iterator<CC>& o) _ {
_will_compare_with_base(o);
_re _self()._get_comparable() < o._get_comparable();
}
_te<CF CC>
bool _op>(_ Iterator<CC>& o) _ {
_will_compare_with_base(o);
_re _self()._get_comparable() > o._get_comparable();
}
_te<CF CC>
bool _op<=(_ Iterator<CC>& o) _ {
_will_compare_with_base(o);
_re _self()._get_comparable() <= o._get_comparable();
}
_te<CF CC>
bool _op>=(_ Iterator<CC>& o) _ {
_will_compare_with_base(o);
_re _self()._get_comparable() >= o._get_comparable();
}
private:
_te<CF CC>
void _will_compare_with_base(_ Iterator<CC>& o) _ {
if _ce(has_member___will_compare_with< Iterator<C> >) {
_self()._will_compare_with(o);
}
}
public:
_a& _op*()       { _re *this; }
_a& _op*() _ { _re *this; }
CRTP_COMMON( Iterator_Base, Iterator<C> )
};
}
}
namespace salgo {
_te<_cl CRTP, _cl INT=int, INT default_value = std::numeric_limits<INT>::max()>
struct Int_Handle_Base {
INT a = default_value;
Int_Handle_Base() = default;
explicit Int_Handle_Base(INT new_key) : a(new_key) {}
bool valid() _ { _re a != default_value; }
void reset() { a = default_value; }
bool _op==(_ CRTP& o) _ { _re a == o.a; }
bool _op!=(_ CRTP& o) _ { _re a != o.a; }
_op INT() _ { _re a; }
CRTP& _op++()    { ++a; _re _self(); }
CRTP  _op++(int) { _a old = _self(); ++(*this); _re old; }
CRTP& _op--()    { --a; _re _self(); }
CRTP  _op--(int) { _a old = _self(); --(*this); _re old; }
static_assert(std::is_integral_v<INT>);
CRTP_COMMON(Int_Handle_Base, CRTP)
};
_te<_cl INT=int, INT default_value = std::numeric_limits<INT>::max()>
struct Int_Handle : Int_Handle_Base<Int_Handle<INT,default_value>, INT, default_value> {
_u BASE = Int_Handle_Base<Int_Handle, INT, default_value>;
FORWARDING_CONSTRUCTOR(Int_Handle, BASE) {}
};
_te<
_cl CRTP,
_cl HANDLE_A,
_cl HANDLE_B
>
struct Pair_Handle_Base {
HANDLE_A a = HANDLE_A();
HANDLE_B b = HANDLE_B();
Pair_Handle_Base() = default;
Pair_Handle_Base(HANDLE_A aa, HANDLE_B bb) : a(aa), b(bb) {}
bool valid() _ { _re a.valid(); }
void reset() { a.reset(); }
bool _op==(_ Pair_Handle_Base& o) _ { _re a==o.a && b==o.b; }
bool _op!=(_ Pair_Handle_Base& o) _ { _re !(*this == o); }
};
_te<_cl CRTP, _cl HANDLE_A, _cl HANDLE_B>
std::ostream& _op<<(std::ostream& s, _ Pair_Handle_Base<CRTP,HANDLE_A, HANDLE_B>& p) {
_re s << "{" << p.a << "," << p.b << "}";
}
}
#include <cstring>
namespace salgo {
namespace internal {
namespace Memory_Block {
_te<bool> struct Add_num_existing { int num_existing = 0; };
_te<> struct Add_num_existing<false> {};
_te<bool> struct Add_exists { bool exists = false; };
_te<> struct Add_exists<false> {};
_te<bool> struct Add_exists_bitset {
std::vector<bool> exists;
};
_te<> struct Add_exists_bitset<false> {};
_te<_cl _VAL, _cl _ALLOCATOR, int _STACK_BUFFER, bool _DENSE,
bool _CONSTRUCTED_FLAGS_INPLACE, bool _CONSTRUCTED_FLAGS_BITSET, bool _COUNT>
struct Context {
struct Node;
_te<CF C> _cl Accessor;
_cl Memory_Block;
_u Container = Memory_Block;
_u Val = _VAL;
_u Allocator = _ty std::allocator_traits< _ALLOCATOR >::_te rebind_alloc<Node>;
static _ce int  Stack_Buffer = _STACK_BUFFER;
static _ce bool Dense = _DENSE;
static _ce bool Sparse = !Dense;
static _ce bool Exists_Inplace = _CONSTRUCTED_FLAGS_INPLACE;
static _ce bool Exists_Bitset = _CONSTRUCTED_FLAGS_BITSET;
static _ce bool Exists = _CONSTRUCTED_FLAGS_BITSET || _CONSTRUCTED_FLAGS_INPLACE;
static _ce bool Count = _COUNT;
static _ce bool Iterable = Exists || Dense;
static _ce bool Countable = Count || Dense;
struct Handle : Int_Handle_Base<Handle,int> {
_u BASE = Int_Handle_Base<Handle,int>;
EXPLICIT_FORWARDING_CONSTRUCTOR( Handle, BASE ) {}
};
_u Handle_Small = Handle;
struct Index : Handle {
FORWARDING_CONSTRUCTOR(Index, Handle) {}
};
struct Node : S Stack_Storage<Val>, Add_exists<Exists_Inplace> {};
_te<CF C>
_cl Accessor : public Accessor_Base<C,Context> {
_u BASE = Accessor_Base<C,Context>;
_uB _container;
_uB _handle;
public:
FORWARDING_CONSTRUCTOR(Accessor, BASE) {}
public:
_a index() _ { _re BASE::handle(); }
_te<_cl... ARGS>
_a& cr(ARGS&&... args) {
static_assert(C == MUTAB, "called cr() on CONST accessor");
static_assert(!Dense, "cr() not supported for DENSE memory-blocks");
_check_bounds();
if _ce(Exists) {
DCHECK( !cred() ) << "element already cred";
_c._set_exists(_h, true);
}
_get().cr( std::forward<ARGS>(args)... );
if _ce(Count) ++_c.num_existing;
_re *this;
}
_a& destruct() {
static_assert(C == MUTAB, "called destruct() on CONST accessor");
static_assert(!Dense, "destruct() not supported for DENSE memory-blocks");
_check_bounds();
if _ce(Exists) {
DCHECK( cred() ) << "erasing already erased element";
_c._set_exists(_h, false);
}
_get().destruct();
if _ce(Count) --_c.num_existing;
_re *this;
}
bool cred() _ {
_check_bounds();
static_assert(Dense || Exists, "called cred() on object without CONSTRUCTED_FLAGS or DENSE");
if _ce(Dense) {
_re true;
} else if _ce(Exists_Inplace) {
_re _get().exists;
} else if _ce(Exists_Bitset) {
_re _c.exists[ _h ];
}
}
bool exists_SLOW() _ {
if(!_is_in_bounds()) _re false;
_re cred();
}
private:
bool _is_in_bounds() _ {
_re _c._is_in_bounds( _h );
}
void _check_bounds() _ {
_c._check_bounds( _h );
}
_a& _get()       { _re _c._get( _h ); }
_a& _get() _ { _re _c._get( _h ); }
};
_cl End_Iterator {};
_te<CF C>
_cl Iterator : public Iterator_Base<C,Context> {
_u BASE = Iterator_Base<C,Context>;
_uB _container;
_uB _handle;
public:
FORWARDING_CONSTRUCTOR(Iterator, BASE) {}
private:
F BASE;
void _increment() {
if _ce(Dense) ++_h;
else do ++_h; while( (int)_h != _c.domain() && !BASE::accessor().cred() );
}
void _decrement() {
if _ce(Dense) --_h;
else do --_h; while( !BASE::accessor().cred() );
}
public:
bool _op!=(_ End_Iterator&) { _re _h != _c.domain(); }
};
_cl Memory_Block :
private Allocator,
private Add_num_existing<Count>,
private Add_exists_bitset<Exists_Bitset> {
_u NUM_EXISTING_BASE = Add_num_existing<Count>;
_u CONSTRUCTED_FLAGS_BITSET_BASE = Add_exists_bitset<Exists_Bitset>;
public:
_u Val = Context::Val;
_u Allocator = Context::Allocator;
static _ce int Stack_Buffer = Context::Stack_Buffer;
static _ce bool Is_Dense = Context::Dense;
static _ce bool Is_Sparse = Context::Sparse;
static _ce bool Has_Exists_Inplace = Context::Exists_Inplace;
static _ce bool Has_Exists_Bitset = Context::Exists_Bitset;
static _ce bool Has_Exists = Context::Exists;
static _ce bool Has_Count = Context::Count;
_u Handle       = Context::Handle;
_u Handle_Small = Context::Handle_Small;
_u Index        = Context::Index;
private:
F Accessor<MUTAB>;
F Accessor<CONST>;
static_assert(!(Dense && Count), "no need for COUNT if vector is DENSE");
private:
static _ce int _stack_buffer_sizeof() {
if _ce(Stack_Buffer > 0) {
_re Stack_Buffer * sizeof(Node);
} else _re 0;
}
private:
Node* _data = _get_stack_buffer();
char _stack_buffer[ _stack_buffer_sizeof() ];
int _size = 0;
_a _get_stack_buffer() {
_re (Node*)_stack_buffer;
}
_a _get_stack_buffer() _ {
_re (_ Node*)_stack_buffer;
}
_a& _get(Index key)       { _re _data[key]; }
_a& _get(Index key) _ { _re _data[key]; }
public:
Memory_Block(_ Memory_Block& o) :
Allocator(o),
NUM_EXISTING_BASE(o),
CONSTRUCTED_FLAGS_BITSET_BASE(o),
_size(o._size) {
static_assert(Dense || Exists || std::_tcc<Val>,
"can't copy-cr non-POD container if no CONSTRUCTED_FLAGS or DENSE flags");
if(_size > Stack_Buffer) {
_data = std::allocator_traits<Allocator>::allocate(_allocator(), _size);
}
else {
_data = _get_stack_buffer();
}
for(int i=0; i<_size; ++i) {
std::allocator_traits<Allocator>::cr(_allocator(), _data+i);
if( o(i).cred() ) {
_get(i).cr( o._get(i) );
}
}
}
Memory_Block(Memory_Block&& o) :
Allocator( std::move(o) ),
NUM_EXISTING_BASE( std::move(o) ),
CONSTRUCTED_FLAGS_BITSET_BASE( std::move(o) ),
_size( std::move(o._size) ) {
if(_size > Stack_Buffer) {
_data = o._data;
}
else if _ce( _stack_buffer_sizeof() > 0 ) {
_data = _get_stack_buffer();
std::memcpy( _stack_buffer, o._stack_buffer, _stack_buffer_sizeof() );
}
o._size = 0;
}
Memory_Block& _op=(_ Memory_Block& o) {
this->~Memory_Block();
new(this) Memory_Block(o);
_re *this;
}
Memory_Block& _op=(Memory_Block&& o) {
this->~Memory_Block();
new(this) Memory_Block( std::move(o) );
_re *this;
}
public:
Memory_Block() {
static_assert(!Exists_Inplace || !Exists_Bitset, "can't have both");
static_assert(!Dense || !Exists, "can't have both");
static_assert(!Dense || !Count, "can't have both");
}
_te<_cl... ARGS>
Memory_Block(int size, ARGS&&... args) : _size(size) {
static_assert(Dense || sizeof...(ARGS) == 0, "only DENSE memory_blocks can supply crion args");
if(_size > Stack_Buffer) {
_data = std::allocator_traits<Allocator>::allocate(_allocator(), _size);
}
else {
_data = _get_stack_buffer();
}
for(int i=0; i<_size; ++i) {
std::allocator_traits<Allocator>::cr(_allocator(), _data+i);
if _ce(Dense) {
_get(i).cr( args... );
}
}
if _ce(Exists_Bitset) CONSTRUCTED_FLAGS_BITSET_BASE::exists.resize( _size );
}
~Memory_Block() {
if _ce(Dense || Exists) {
_destruct_block(_data, _size);
}
if(_size > Stack_Buffer) {
std::allocator_traits<Allocator>::deallocate(_allocator(), _data, _size);
}
}
private:
_a& _allocator()       { _re *static_cast<      Allocator*>(this); }
_a& _allocator() _ { _re *static_cast<_ Allocator*>(this); }
private:
void _destruct_block(Node* data, int size) {
static_assert(Dense || Exists || std::is_trivially_destructible_v<Val>,
"can't destroy non-POD container if no CONSTRUCTED_FLAGS or DENSE flags");
_destruct_block(data, size, [this](int i){ _re (*this)(i).cred(); });
}
_te<_cl CONSTRUCTED_FLAGS_FUN>
void _destruct_block(Node* data, int size, CONSTRUCTED_FLAGS_FUN&& exists_fun) {
(void)data;
if _ce(!std::is_trivially_destructible_v<Val>) {
for(int i=0; i<size; ++i) if(exists_fun(i)) {
_get(i).destruct();
}
}
for(int i=0; i<size; ++i) {
std::allocator_traits<Allocator>::destroy(_allocator(), data+i);
}
}
public:
void resize(int new_size) {
static_assert(Dense || Exists || std::_tmc<Val>,
"can't resize non-POD container if no CONSTRUCTED_FLAGS or DENSE flags");
if _ce(std::_tmc<Val>) {
_resize(new_size, [](int){ _re true; });
}
else _resize(new_size, [this](int i){ _re (*this)(i).cred(); });
}
_te<_cl CONSTRUCTED_FLAGS_FUN>
void resize(int new_size, CONSTRUCTED_FLAGS_FUN&& exists_fun) {
static_assert(!Dense && !Exists, "can only supply CONSTRUCTED_FLAGS_FUN if not Dense and Exists");
_resize(new_size, std::forward<CONSTRUCTED_FLAGS_FUN>(exists_fun));
}
private:
_te<_cl CONSTRUCTED_FLAGS_FUN>
void _resize(int new_size, CONSTRUCTED_FLAGS_FUN&& exists_fun) {
decltype(_data) new_data;
if(new_size > Stack_Buffer) {
new_data = std::allocator_traits<Allocator>::allocate(_allocator(), new_size);
}
else {
new_data = _get_stack_buffer();
}
int n = std::min(_size, new_size);
if(new_data != _data) {
if _ce(!std::_tmc<Val>) {
for(int i=0; i<n; ++i) {
if(exists_fun(i)) {
std::allocator_traits<Allocator>::cr(_allocator(), new_data+i, std::move( _data[i] ));
}
else {
std::allocator_traits<Allocator>::cr(_allocator(), new_data+i);
}
}
}
else {
static_assert(std::_tmc<Node>);
std::memcpy(new_data, _data, n * sizeof(Node));
}
_destruct_block(_data, _size, std::forward<CONSTRUCTED_FLAGS_FUN>(exists_fun));
}
else {
_destruct_block(_data + n, _size - n, std::forward<CONSTRUCTED_FLAGS_FUN>(exists_fun));
}
for(int i=_size; i<new_size; ++i) {
std::allocator_traits<Allocator>::cr(_allocator(), new_data+i);
if _ce(Dense) {
new_data[i].cr();
}
}
if(_size > Stack_Buffer) {
std::allocator_traits<Allocator>::deallocate(_allocator(), _data, _size);
}
_data = new_data;
_size = new_size;
if _ce(Exists_Bitset) CONSTRUCTED_FLAGS_BITSET_BASE::exists.resize( new_size );
}
public:
_a domain() _ { _re _size; }
_a size() _ {
static_assert(Dense, "size() is ambiguous when memory block is Sparse");
_re _size;
}
public:
Val& _op[](Index key) {
_check_bounds(key);
if _ce(Exists) DCHECK( (*this)(key).cred() ) << "accessing non-existing element";
_re _get(key);
}
_ Val& _op[](Index key) _ {
_check_bounds(key);
if _ce(Exists) DCHECK( (*this)(key).cred() ) << "accessing non-existing element";
_re _get(key);
}
_a& _op[](First_Tag)       { _re _op()(FIRST)(); }
_a& _op[](First_Tag) _ { _re _op()(FIRST)(); }
_a& _op[](Last_Tag)        { _re _op()(LAST)(); }
_a& _op[](Last_Tag)  _ { _re _op()(LAST)(); }
public:
_a _op()(Index key) {
_check_bounds(key);
_re Accessor<MUTAB>(this, key);
}
_a _op()(Index key) _ {
_check_bounds(key);
_re Accessor<CONST>(this, key);
}
_a _op()(First_Tag) {
DCHECK(!empty());
Handle h = Index(0);
while(!(*this)(h).cred()) ++h;
_re _op()(h);
}
_a _op()(First_Tag) _ {
DCHECK(!empty());
Handle h = Index(0);
while(!(*this)(h).cred()) ++h;
_re _op()(h);
}
_a _op()(Last_Tag) {
DCHECK(!empty());
Handle h = Index( domain() );
do --h; while(!(*this)(h).cred());
_re _op()(h);
}
_a _op()(Last_Tag) _ {
DCHECK(!empty());
Handle h = Index( domain() );
do --h; while(!(*this)(h).cred());
_re _op()(h);
}
public:
_te<_cl... ARGS>
void cr_all(_ ARGS&... args) {
static_assert(!Dense, "cr_all() not supported for DENSE memory-blocks");
for(int i=0; i<_size; ++i) {
if _ce(Exists) {
DCHECK( !(*this)(i).cred() ) << "can't cr_all() if some elements already exist";
}
(*this)(i).cr( args... );
}
}
private:
bool _is_in_bounds(Index key) _ {
_re key >= 0 && key < domain();
}
void _check_bounds(Index key) _ {
DCHECK( _is_in_bounds(key) ) << "index " << key << " out of bounds [0," << domain() << ")";
}
public:
int count() _ {
static_assert(Countable);
if _ce(Dense) _re domain();
else _re NUM_EXISTING_BASE::num_existing;
}
bool empty() _ {
static_assert(Countable);
_re count() == 0;
}
public:
_a begin() {
static_assert(Iterable);
_a e = Iterator<MUTAB>(this, Index(0));
if(_size && !e.accessor().cred()) ++e;
_re e;
}
_a begin() _ {
static_assert(Iterable);
_a e = Iterator<CONST>(this, Index(0));
if(_size && !e.accessor().cred()) ++e;
_re e;
}
_a end() _ {
static_assert(Iterable);
_re End_Iterator();
}
private:
void _set_exists(Handle key, bool new_exists) {
static_assert(Exists);
if _ce(Exists_Inplace) {
_get(key).exists = new_exists;
}
else if _ce(Exists_Bitset) {
CONSTRUCTED_FLAGS_BITSET_BASE::exists[key] = new_exists;
}
}
};
struct With_Builder : Memory_Block {
FORWARDING_CONSTRUCTOR(With_Builder, Memory_Block) {}
_te<_cl NEW_ALLOCATOR>
_u ALLOCATOR =
_ty Context< Val, NEW_ALLOCATOR, Stack_Buffer, Dense, Exists_Inplace, Exists_Bitset, Count > :: With_Builder;
_te<int NEW_STACK_BUFFER>
_u INPLACE_BUFFER =
_ty Context< Val, Allocator, NEW_STACK_BUFFER, Dense, Exists_Inplace, Exists_Bitset, Count > :: With_Builder;
_u DENSE =
_ty Context< Val, Allocator, Stack_Buffer, true, Exists_Inplace, Exists_Bitset, Count > :: With_Builder;
_u SPARSE =
_ty Context< Val, Allocator, Stack_Buffer, false, Exists_Inplace, Exists_Bitset, Count > :: With_Builder;
_u CONSTRUCTED_FLAGS_INPLACE =
_ty Context< Val, Allocator, Stack_Buffer, Dense, true, false, Count > :: With_Builder;
_u CONSTRUCTED_FLAGS_BITSET =
_ty Context< Val, Allocator, Stack_Buffer, Dense, false, true, Count > :: With_Builder;
_u CONSTRUCTED_FLAGS = CONSTRUCTED_FLAGS_BITSET;
_u COUNT =
_ty Context< Val, Allocator, Stack_Buffer, Dense, Exists_Inplace, Exists_Bitset, true > :: With_Builder;
_u FULL_BLOWN =
_ty Context< Val, Allocator, Stack_Buffer, Dense, false, true, true > :: With_Builder;
};
};
}
}
_te<
_cl T
>
_u Memory_Block = _ty internal::Memory_Block::Context<
T,
std::allocator<T>,
0,
false,
false,
false,
false
> :: With_Builder;
}
namespace salgo {
namespace internal {
namespace vector_allocator {
_te<
_cl _VAL
>
struct Context {
_u Val = _VAL;
_u Block = _ty S Memory_Block<Val> ::CONSTRUCTED_FLAGS ::COUNT;
_u Handle       = _ty Block::Handle;
_u Handle_Small = _ty Block::Handle_Small;
_u Index        = _ty Block::Index;
_cl Vector_Allocator;
_u Container = Vector_Allocator;
_te<CF C>
_cl Accessor : public Accessor_Base<C,Context> {
_u BASE = Accessor_Base<C,Context>;
_uB _container;
_uB _handle;
private:
FORWARDING_CONSTRUCTOR(Accessor, BASE) {}
F Vector_Allocator;
public:
void cr() {
static_assert(C == MUTAB, "called cr() on CONST accessor");
_c.v( _h ).cr();
}
void destruct() {
static_assert(C == MUTAB, "called destruct() on CONST accessor");
_c.v( _h ).destruct();
}
void erase() { destruct(); }
bool cred() _ { _re _c.v( _h ).cred(); }
_a exists() _ { _re cred(); }
};
_cl End_Iterator {};
_te<CF C>
_cl Iterator : public Iterator_Base<C,Context> {
_u BASE = Iterator_Base<C,Context>;
_uB _container;
_uB _handle;
private:
FORWARDING_CONSTRUCTOR(Iterator, BASE) {}
F Vector_Allocator;
private:
F Iterator_Base<C,Context>;
void _increment() {
do ++_h; while( *this != End_Iterator()  &&  !_c( _h ).cred() );
}
void _decrement() {
do --_h; while( !_c.exists( _h ) );
}
public:
bool _op!=(End_Iterator) _ { _re _h != _c.v.domain(); }
};
_cl Vector_Allocator {
F Accessor<CONST>;
F Accessor<MUTAB>;
F Iterator<CONST>;
F Iterator<MUTAB>;
public:
_u Val = Context::Val;
_u Handle_Small = Context::Handle_Small;
_u Handle       = Context::Handle;
_u Index        = Context::Index;
static _ce bool Auto_Destruct = true;
private:
Block v;
Index lookup_index = 0;
public:
Vector_Allocator() = default;
_te<_cl... ARGS>
Vector_Allocator(int num_starting_elements, ARGS... args) :
v(num_starting_elements),
lookup_index(num_starting_elements) {
for(int i=0; i<num_starting_elements; ++i) {
v(i).cr( args... );
}
}
public:
_te<_cl... ARGS>
_a cr(ARGS&&... args) {
static_assert(std::_mc<Val>, "Vector_Allocator must be able to move its elements");
if(v.count()*2 >= v.domain()) {
v.resize( v.domain()*2 + 1 );
}
while( v(lookup_index).cred() ) {
++lookup_index;
if((int)lookup_index == v.domain()) {
lookup_index = 0;
}
}
_a index = lookup_index;
++lookup_index;
if(lookup_index == v.domain()) {
lookup_index = 0;
}
_re Accessor<MUTAB>( this, v(index).cr( std::forward<ARGS>(args)... ).handle() );
}
_te<_cl... ARGS>
_a cr_near(Handle, ARGS&&... args) {
_re cr( std::forward<ARGS>(args)... );
}
_te<_cl... ARGS>
_a add(ARGS&&... args) { _re cr( std::forward<ARGS>(args)... ); }
_te<_cl... ARGS>
void resize(int new_size, ARGS&&... args) {
_a old_size = v.domain();
v.resize(new_size);
for(int i=old_size; i<new_size; ++i) {
_op()(i).cr( args... );
}
}
public:
_a& _op[]( Index h )       { _re v[h]; }
_a& _op[]( Index h ) _ { _re v[h]; }
_a  _op()( Index h )       { _re Accessor<MUTAB>(this, h); }
_a  _op()( Index h ) _ { _re Accessor<CONST>(this, h); }
_a& _op[]( First_Tag )       { _re v[FIRST]; }
_a& _op[]( First_Tag ) _ { _re v[FIRST]; }
_a  _op()( First_Tag )       { _re Accessor<MUTAB>(this, v(FIRST)); }
_a  _op()( First_Tag ) _ { _re Accessor<CONST>(this, v(FIRST)); }
_a& _op[]( Last_Tag )       { _re v[LAST]; }
_a& _op[]( Last_Tag ) _ { _re v[LAST]; }
_a  _op()( Last_Tag )       { _re Accessor<MUTAB>(this, v(LAST)); }
_a  _op()( Last_Tag ) _ { _re Accessor<CONST>(this, v(LAST)); }
_a count() _ { _re v.count(); }
_a empty() _ { _re v.empty(); }
_a domain() _ { _re v.domain(); }
public:
_a begin()       { _re Iterator<MUTAB>(this, v.begin()); }
_a begin() _ { _re Iterator<MUTAB>(this, v.begin()); }
_a end()       { _re End_Iterator(); }
_a end() _ { _re End_Iterator(); }
};
struct With_Builder : Vector_Allocator {
FORWARDING_CONSTRUCTOR( With_Builder, Vector_Allocator ) {}
_te<_cl NEW_VAL>
_u VAL = _ty
Context<NEW_VAL> :: With_Builder;
};
};
}
}
_te< _cl VAL = int >
_u Vector_Allocator = _ty internal::vector_allocator::Context<
VAL
> :: With_Builder;
}
namespace salgo {
namespace internal {
namespace Vector {
_te<_cl _VAL, bool _SPARSE, _cl _MEMORY_BLOCK>
struct Context {
_te<CF C> _cl Accessor;
_te<CF C> _cl Iterator;
_cl Vector;
_u Container = Vector;
_u Val = _VAL;
_u Memory_Block = _MEMORY_BLOCK;
_u Allocator = _ty _MEMORY_BLOCK :: Allocator;
static _ce int  Stack_Buffer   = _MEMORY_BLOCK :: Stack_Buffer;
static _ce bool Exists_Inplace = _MEMORY_BLOCK :: Has_Exists_Inplace;
static _ce bool Exists_Bitset  = _MEMORY_BLOCK :: Has_Exists_Bitset;
static _ce bool Exists         = _MEMORY_BLOCK :: Has_Exists;
static _ce bool Count          = _MEMORY_BLOCK :: Has_Count;
static _ce bool Sparse         = _SPARSE;
static _ce bool Dense          = !Sparse;
static _ce bool Iterable = Dense || Exists;
struct Handle : Int_Handle_Base<Handle,int> {
_u BASE = Int_Handle_Base<Handle,int>;
EXPLICIT_FORWARDING_CONSTRUCTOR(Handle, BASE) {}
};
_u Handle_Small = Handle;
struct Index : Handle {
FORWARDING_CONSTRUCTOR(Index, Handle) {}
};
_te<CF C>
_cl Accessor : public Accessor_Base<C,Context> {
_u BASE = Accessor_Base<C,Context>;
FORWARDING_CONSTRUCTOR(Accessor, BASE) {}
F Vector;
_uB _container;
_uB _handle;
public:
_uB _op=;
_te<_cl... ARGS>
void cr(ARGS&&... args) {
static_assert(C == MUTAB, "called cr() on CONST accessor");
static_assert(Sparse);
_c._check_bounds( _h );
_c._mb( _h ).cr( std::forward<ARGS>(args)... );
}
void destruct() {
static_assert(C == MUTAB, "called destruct() on CONST accessor");
static_assert(Sparse);
_c._check_bounds( _h );
_c._mb( _h ).destruct();
}
void erase() {
destruct();
}
bool cred() _ {
_c._check_bounds( _h );
if _ce(Dense) _re true;
else _re _c._mb( _h ).cred();
}
bool exists_SLOW() _ {
if(!_c._is_in_bounds( _h )) _re false;
_re cred();
}
};
struct End_Iterator {};
_te<CF C>
_cl Iterator : public Iterator_Base<C,Context> {
_u BASE = Iterator_Base<C,Context>;
FORWARDING_CONSTRUCTOR(Iterator, BASE) {}
F Vector;
_uB _container;
_uB _handle;
private:
F Iterator_Base<C,Context>;
void _increment() {
do ++_h; while( (int)_h != _c.domain() && !_c( _h ).cred() );
}
void _decrement() {
do --_h; while( !_container( _h ).cred() );
}
public:
bool _op!=(End_Iterator) { _re _h < _c.domain(); }
};
_cl Vector {
static_assert(!(Dense && Count), "no need for COUNT if vector is DENSE");
public:
_u Val = Context::Val;
static _ce bool Has_Exists_Inplace = Context::Exists_Inplace;
static _ce bool Has_Exists_Bitset = Context::Exists_Bitset;
static _ce bool Has_Exists = Context::Exists;
static _ce bool Has_Count = Context::Count;
_u Handle       = Context::Handle;
_u Handle_Small = Context::Handle_Small;
_u Index        = Context::Index;
private:
F Accessor<MUTAB>;
F Accessor<CONST>;
private:
Memory_Block _mb;
int _size = 0;
public:
Vector() : _mb( Memory_Block::Stack_Buffer ) {}
_te<_cl... ARGS>
Vector(int size, ARGS&&... args) : _mb( std::max(size, Memory_Block::Stack_Buffer )), _size(size) {
for(int i=0; i<size; ++i) {
_mb(i).cr( args... );
}
}
Vector(std::initializer_list<Val>&& l) {
reserve( l.size() );
for(_a&& e : l) {
emplace_back( std::move(e) );
}
}
~Vector() {
static_assert(!(Sparse && !Exists && !std::_tmc<Val>),
"no way to know which destructors have to be called");
if _ce(Dense) {
for(int i=0; i<_size; ++i) {
_mb(i).destruct();
}
}
DCHECK_LE(_size, _mb.domain());
}
Vector(_ Vector&) = default;
Vector(Vector&& o) {
_mb = std::move(o._mb);
_size = o._size;
o._size = 0;
}
Vector& _op=(_ Vector&) = default;
Vector& _op=(Vector&& o) {
this->~Vector();
new(this) Vector( std::move(o) );
_re *this;
}
_te<_cl... ARGS>
void resize(int new_size, ARGS&&... args) {
if _ce(Dense) {
_mb.resize( new_size, [this](int i){_re i<_size;} );
}
else {
_mb.resize( new_size );
}
for(int i=_size; i<_mb.domain(); ++i) {
_mb(i).cr( args... );
}
_size = new_size;
}
void clear() { resize(0); }
bool empty() _ { _re _size == 0; }
void reserve(int capacity) {
if _ce(Dense) {
_mb.resize( capacity, [this](int i){_re i<_size;} );
}
else {
_mb.resize( capacity );
}
}
public:
_a& _op[](Index key) {
_check_bounds(key);
_re _mb[ key.a ];
}
_a& _op[](Index key) _ {
_check_bounds(key);
_re _mb[ key.a ];
}
_a& _op[](First_Tag)       { static_assert(Dense, "todo: implement for sparse"); _re _op[]( Index(0) ); }
_a& _op[](First_Tag) _ { static_assert(Dense, "todo: implement for sparse"); _re _op[]( Index(0) ); }
_a& _op[](Last_Tag)       { static_assert(Dense, "todo: implement for sparse"); _re _op[]( Index(_size-1) ); }
_a& _op[](Last_Tag) _ { static_assert(Dense, "todo: implement for sparse"); _re _op[]( Index(_size-1) ); }
public:
_a _op()(Index key) {
_check_bounds(key);
_re Accessor<MUTAB>(this, key);
}
_a _op()(Index key) _ {
_check_bounds(key);
_re Accessor<CONST>(this, key);
}
_a _op()(First_Tag)       { static_assert(Dense, "todo: implement for sparse"); _re _op()( Index(0) ); }
_a _op()(First_Tag) _ { static_assert(Dense, "todo: implement for sparse"); _re _op()( Index(0) ); }
_a _op()(Last_Tag)       { static_assert(Dense, "todo: implement for sparse"); _re _op()( Index(_size-1) ); }
_a _op()(Last_Tag) _ { static_assert(Dense, "todo: implement for sparse"); _re _op()( Index(_size-1) ); }
private:
bool _is_in_bounds(Index key) _ {
_re key >= 0 && key < domain();
}
void _check_bounds(Index key) _ {
DCHECK(_is_in_bounds(key)) << "index " << key << " out of bounds [0," << domain() << ")";
}
public:
_te<_cl... ARGS>
Accessor<MUTAB> emplace_back(ARGS&&... args) {
static_assert( Dense || Exists || std::_tmc<Val>,
"non-trivially-crible types require CONSTRUCTED_FLAGS to emplace_back()" );
if(_size == _mb.domain()) {
if _ce(Dense) {
_mb.resize( (_mb.domain() + 1) * 3/2, [](int){ _re true; } );
}
else {
_mb.resize( (_mb.domain() + 1) * 3/2 );
}
}
_mb(_size).cr( std::forward<ARGS>(args)... );
_re Accessor<MUTAB>( this, Index(_size++) );
}
_te<_cl... ARGS>
_a add(ARGS&&... args) {
_re emplace_back( std::forward<ARGS>(args)... );
}
_a pop_back() {
static_assert(Dense || Exists, "can't pop_back() if last element is unknown");
if _ce(Exists) {
while(!_mb(_size-1).cred()) {
--_size;
DCHECK_GE(_size, 0);
}
}
DCHECK_GE(_size, 1) << "pop_back() on empty Vector";
DCHECK( (*this)(_size-1).cred() );
Val result( std::move(_mb[_size-1]) );
_mb(--_size).destruct();
_re result;
}
int count() _ {
if _ce(Dense) _re domain();
else _re _mb.count();
}
int domain() _ {
_re _size;
}
int size() _ {
static_assert(Dense, "size() for Sparse_Vector is a bit ambiguous. Use count() or domain() instead");
_re _size;
}
int capacity() _ {
_re _mb.domain();
}
_te<_cl FUN>
int compact(_ FUN& fun = [](int,int){}) {
static_assert(Exists, "can only compact if have CONSTRUCTED_FLAGS flags");
static_assert(std::_mc<Val>, "compact() requires move crible Val type");
int target = 0;
for(int i=0; i<_mb.domain(); ++i) {
if(_mb(i).cred() && target != i) {
_mb(target).cr( std::move( _mb[i] ) );
_mb(i).destruct();
fun(i, target);
++target;
}
}
_mb.resize( target );
_size = target;
_re target;
}
public:
_a begin() {
static_assert(Iterable);
_a e = Iterator<MUTAB>(this, Index(0));
if(_size && !e->cred()) ++e;
_re e;
}
_a begin() _ {
static_assert(Iterable);
_a e = Iterator<CONST>(this, Index(0));
if(_size && !e->cred()) ++e;
_re e;
}
_a end() _ {
static_assert(Iterable);
_re End_Iterator();
}
};
struct With_Builder : Vector {
FORWARDING_CONSTRUCTOR(With_Builder, Vector) {}
FORWARDING_INITIALIZER_LIST_CONSTRUCTOR(With_Builder, Vector) {}
_te<int X>
_u INPLACE_BUFFER =
_ty Context< Val, Sparse, _ty Memory_Block::_te INPLACE_BUFFER<X> > :: With_Builder;
_u CONSTRUCTED_FLAGS =
_ty Context< Val, Sparse, _ty Memory_Block::CONSTRUCTED_FLAGS > :: With_Builder;
_u CONSTRUCTED_FLAGS_INPLACE =
_ty Context< Val, Sparse, _ty Memory_Block::CONSTRUCTED_FLAGS_INPLACE > :: With_Builder;
_u CONSTRUCTED_FLAGS_BITSET =
_ty Context< Val, Sparse, _ty Memory_Block::CONSTRUCTED_FLAGS_BITSET > :: With_Builder;
_u SPARSE =
_ty Context< Val, true, Memory_Block > :: With_Builder :: CONSTRUCTED_FLAGS;
_u SPARSE_NO_CONSTRUCTED_FLAGS =
_ty Context< Val, true, Memory_Block > :: With_Builder;
_u COUNT =
_ty Context< Val, Sparse, _ty Memory_Block::COUNT > :: With_Builder;
_u FULL_BLOWN =
_ty Context< Val, true, _ty Memory_Block::FULL_BLOWN > :: With_Builder;
};
};
}
}
_te< _cl T >
_u Vector = _ty internal::Vector::Context<
T,
false,
Memory_Block<T>
> :: With_Builder;
}
namespace salgo {
namespace internal {
namespace graph {
ADD_MEMBER(data);
ADD_MEMBER(_es);
ADD_MEMBER(edge);
enum _cl Erasable {
NON_ERASABLE = 0,
ERASABLE_HOLES,
ERASABLE_REORDER
};
namespace {
_ce _a NON_ERASABLE     = Erasable:: NON_ERASABLE;
_ce _a ERASABLE_HOLES   = Erasable:: ERASABLE_HOLES;
_ce _a ERASABLE_REORDER = Erasable:: ERASABLE_REORDER;
}
_te<
bool _DIRECTED,
bool _BACKLINKS,
_cl _VERT_PROPS,
_cl _EDGE_PROPS,
Erasable _VERTS_ERASABLE,
Erasable _EDGES_ERASABLE,
bool _EDGES_GLOBAL
>
struct Context {
static _ce bool Directed = _DIRECTED;
static _ce bool Backlinks = _BACKLINKS;
_u Vert_Data      = _VERT_PROPS;
_u Edge_Data      = _EDGE_PROPS;
static _ce Erasable Verts_Erasable = _VERTS_ERASABLE;
static _ce Erasable Edges_Erasable = _EDGES_ERASABLE;
static _ce bool Edges_Global = _EDGES_GLOBAL;
static _ce bool Has_Vert_Data =
!std::is_same_v<Vert_Data, void>;
static _ce bool Has_Edge_Data =
!std::is_same_v<Edge_Data, void>;
static _ce bool Outs_Link_Outs = !Directed;
static _ce bool Outs_Link_Ins = Directed && Backlinks;
static _ce bool Has_Ins = Directed && Backlinks;
#define GRAPH_FRIENDS \
F A_Vert<MUTAB>; \
F A_Vert<CONST>; \
F I_Vert<MUTAB>; \
F I_Vert<CONST>; \
F A_Edge<MUTAB>; \
F A_Edge<CONST>; \
F I_Edge<MUTAB>; \
F I_Edge<CONST>; \
F A_Out<MUTAB,0>; \
F A_Out<CONST,0>; \
F A_Out<MUTAB,1>; \
F A_Out<CONST,1>; \
F I_Out<MUTAB,0>; \
F I_Out<CONST,0>; \
F I_Out<MUTAB,1>; \
F I_Out<CONST,1>; \
F A_Verts<MUTAB>; \
F A_Verts<CONST>; \
F A_Edges<MUTAB>; \
F A_Edges<CONST>; \
F A_Outs<MUTAB,0>; \
F A_Outs<CONST,0>; \
F A_Outs<MUTAB,1>; \
F A_Outs<CONST,1>;
_cl Graph;
struct Vert;
struct Vert_Edge;
struct Edge;
_u Verts = std::conditional_t< Verts_Erasable == ERASABLE_HOLES,
S Vector_Allocator< Vert >,
std::conditional_t< Verts_Erasable == ERASABLE_REORDER,
S Vector< Vert >,
S Vector< Vert >
>
>;
_u Edges = std::conditional_t< Edges_Erasable == ERASABLE_HOLES,
S Vector_Allocator< Edge >,
std::conditional_t< Verts_Erasable == ERASABLE_REORDER,
S Vector< Edge >,
S Vector< Edge >
>
>;
_u Vert_Edges = std::conditional_t< Edges_Erasable == ERASABLE_HOLES,
S Vector_Allocator< Vert_Edge >,
std::conditional_t< Verts_Erasable == ERASABLE_REORDER,
S Vector< Vert_Edge >,
S Vector< Vert_Edge >
>
>;
_u   H_Vert = _ty Verts::Handle;
_u  SH_Vert = _ty Verts::Handle_Small;
_u IDX_Vert = _ty Verts::Index;
_u   H_Edge = _ty Edges::Handle;
_u  SH_Edge = _ty Edges::Handle_Small;
_u IDX_Edge = _ty Edges::Index;
_u   H_Out  = _ty Vert_Edges::Handle;
_u  SH_Out  = _ty Vert_Edges::Handle_Small;
_u IDX_Out  = _ty Vert_Edges::Index;
struct H_Vert_Edge : Pair_Handle_Base< H_Vert_Edge, H_Vert, _ty Vert_Edges::Handle > {
_u BASE = Pair_Handle_Base< H_Vert_Edge, H_Vert, _ty Vert_Edges::Handle >;
FORWARDING_CONSTRUCTOR(H_Vert_Edge, BASE) {}
};
struct Edge : Add_data<Edge_Data, Has_Edge_Data> {
_u BASE = Add_data<Edge_Data, Has_Edge_Data>;
_te<_cl... ARGS>
Edge(IDX_Vert, IDX_Vert, ARGS&&... args) : BASE(std::forward<ARGS>(args)...) {}
};
struct Vert_Edge : Add_edge<SH_Edge, Has_Edge_Data || Edges_Global> {
static _ce bool Links_Vert_Edge = Outs_Link_Outs || Outs_Link_Ins;
std::conditional_t<Links_Vert_Edge, H_Vert_Edge, H_Vert> link;
_a& vert() { if _ce(Links_Vert_Edge) _re link.a; else _re link; }
};
struct Vert :
Add_data<Vert_Data, Has_Vert_Data> {
std::array<Vert_Edges, Has_Ins ? 2 : 1> outs_ins;
_a& outs()       { _re outs_ins[0]; }
_a& outs() _ { _re outs_ins[0]; }
_a& ins()       { static_assert(Has_Ins); _re outs_ins[1]; }
_a& ins() _ { static_assert(Has_Ins); _re outs_ins[1]; }
};
struct Verts_Context;
struct Edges_Context;
_te<int> struct Outs_Context;
_te<CF C> _u A_Vert = _ty Verts_Context::_te Accessor<C>;
_te<CF C> _u I_Vert = _ty Verts_Context::_te Iterator<C>;
_te<CF C> _u A_Edge = _ty Edges_Context::_te Accessor<C>;
_te<CF C> _u I_Edge = _ty Edges_Context::_te Iterator<C>;
_te<CF C, int oi_idx> _u A_Out = _ty Outs_Context<oi_idx>::_te Accessor<C>;
_te<CF C, int oi_idx> _u I_Out = _ty Outs_Context<oi_idx>::_te Iterator<C>;
_te<CF C> _cl A_Verts;
_te<CF C> _cl A_Edges;
_te<CF, int> _cl A_Outs;
struct Verts_Context {
_u Container = Graph;
_u Handle = H_Vert;
_te<CF C>
_cl Accessor : public Accessor_Base<C,Verts_Context> {
_u BASE = Accessor_Base<C,Verts_Context>;
_uB _container;
_uB _handle;
public:
FORWARDING_CONSTRUCTOR(Accessor, BASE) {}
public:
_a& graph()       { _re _container; }
_a& graph() _ { _re _container; }
_a& data()       { _re _c._vs[ _h ].data; }
_a& data() _ { _re _c._vs[ _h ].data; }
_a _op->()       { _re &data(); }
_a _op->() _ { _re &data(); }
_a outs()       { _re A_Outs<MUTAB,0>( _c, _h ); }
_a outs() _ { _re A_Outs<CONST,0>( _c, _h ); }
_a ins()       { _re A_Outs<MUTAB,1>( _c, _h ); }
_a ins() _ { _re A_Outs<CONST,1>( _c, _h ); }
_te<_cl X> _a out(_ X& x)       { _re outs()(x); }
_te<_cl X> _a out(_ X& x) _ { _re outs()(x); }
_te<_cl X> _a in(_ X& x)       { _re ins()(x); }
_te<_cl X> _a in(_ X& x) _ { _re ins()(x); }
void erase() {
static_assert(C==MUTAB, "called erase() on CONST A_Vert accessor");
static_assert(Verts_Erasable != NON_ERASABLE, "called erase() on non-verts-erasable graph");
if _ce(Edges_Erasable != NON_ERASABLE) {
if _ce(Outs_Link_Outs) {
for(_a& outt : _c._vs[ _h ].outs()) {
_c._vs[outt().link.a].outs()(outt().link.b).erase();
}
}
if _ce(Outs_Link_Ins) {
for(_a& outt : _c._vs[ _h ].outs()) {
_c._vs[outt().link.a].ins()(outt().link.b).erase();
}
for(_a& outt : _c._vs[ _h ].ins()) {
_c._vs[outt().link.a].outs()(outt().link.b).erase();
}
}
}
else {
for( _a& outs : _c._vs[_h].outs_ins ) {
DCHECK( outs.empty() ) << "removing this vert removes edges, so requires Edges_Erasable";
}
}
_c._vs( _h).erase();
}
};
struct End_Iterator {};
_te<CF C>
_cl Iterator : public Iterator_Base<C,Verts_Context> {
_u BASE = Iterator_Base<C,Verts_Context>;
_uB _container;
_uB _handle;
public:
FORWARDING_CONSTRUCTOR(Iterator, BASE) {}
private:
GRAPH_FRIENDS
private:
F BASE;
void _increment() { _h = _c._vs( _h ).next(); }
void _decrement() { _h = _c._vs( _h ).prev(); }
public:
bool _op!=(End_Iterator) _ { _re _h < _c._vs.domain(); }
};
};
struct Edges_Context {
_u Container = Graph;
_u Handle = H_Edge;
_te<CF C>
_cl Accessor : public Accessor_Base<C,Edges_Context> {
_u BASE = Accessor_Base<C,Edges_Context>;
_uB _container;
_uB _handle;
public:
FORWARDING_CONSTRUCTOR(Accessor, BASE) {}
public:
_a& graph()       {  _re _container;  }
_a& graph() _ {  _re _container;  }
_a& data()       {  _re _c._es[ _h ].data;  }
_a& data() _ {  _re _c._es[ _h ].data;  }
_a _op->()       { _re &data(); }
_a _op->() _ { _re &data(); }
};
struct End_Iterator {};
_te<CF C>
_cl Iterator : public Iterator_Base<C,Edges_Context> {
_u BASE = Iterator_Base<C,Edges_Context>;
_uB _container;
_uB _handle;
public:
FORWARDING_CONSTRUCTOR(Iterator, BASE) {}
private:
GRAPH_FRIENDS
private:
F BASE;
void _increment() { _h = _c._es( _h ).iterator().next(); }
void _decrement() { _h = _c._es( _h ).iterator().prev(); }
public:
bool _op!=(End_Iterator) _ { _re _h < _c._es.domain(); }
};
};
_te<int oi>
struct Outs_Context {
_u Container = Graph;
_u Handle = H_Vert_Edge;
_te<CF C>
_cl Accessor : public Accessor_Base<C,Outs_Context> {
_u BASE = Accessor_Base<C,Outs_Context>;
_uB _container;
_uB _handle;
public:
FORWARDING_CONSTRUCTOR(Accessor, BASE) {}
public:
_a& graph()       {  _re _c;  }
_a& graph() _ {  _re _c;  }
_a& data()       {  _re _raw().data();  }
_a& data() _ {  _re _raw().data();  }
_a vert() { _re _c.vert( _raw().vert() ); }
_a edge() { _re _c.edge( _raw().edge ); }
private:
_a& _raw()       { _re _raw_outs()[ _h.b ]; }
_a& _raw() _ { _re _raw_outs()[ _h.b ]; }
_a& _raw_outs()       { _re _c._vs[ _h.a ].outs_ins[oi]; }
_a& _raw_outs() _ { _re _c._vs[ _h.a ].outs_ins[oi]; }
};
struct End_Iterator {};
_te<CF C>
_cl Iterator : public Iterator_Base<C,Outs_Context> {
_u BASE = Iterator_Base<C,Outs_Context>;
_uB _container;
_uB _handle;
public:
FORWARDING_CONSTRUCTOR( Iterator, BASE ) {}
private:
GRAPH_FRIENDS
private:
F BASE;
void _increment() {	_h.b = _raw_outs()(_h.b).next(); }
void _decrement() { _h.b = _raw_outs()(_h.b).prev(); }
private:
_a& _raw_outs()       { _re _c._vs[ _h.a ].outs_ins[oi]; }
_a& _raw_outs() _ { _re _c._vs[ _h.a ].outs_ins[oi]; }
public:
bool _op!=(End_Iterator) _ { _re _h.b != _raw_outs().domain(); }
};
};
_te<CF C>
_cl A_Verts {
public:
_a domain() _ {  _re _graph.vs.domain();  }
_a empty() _ {  _re _graph._vs.empty();  }
_a count() _ {  _re _graph._vs.count();  }
void resize(int new_size) {
if _ce(Verts_Erasable != NON_ERASABLE) {
for(int i=_graph._vs.domain()-1; i>=new_size; --i) {
if(_graph.vert(i).exists()) _graph.vert(i).erase();
}
}
else {
DCHECK(new_size > _graph._vs.domain()) << "can't shrink vertices list if not Verts_Erasable";
}
_graph._vs.resize(new_size);
}
_a begin()       {  _re I_Vert<C>    (&_graph, IDX_Vert(0));  }
_a begin() _ {  _re I_Vert<CONST>(&_graph, IDX_Vert(0));  }
_a end()       {  _re _ty Verts_Context::End_Iterator(); }
_a end() _ {  _re _ty Verts_Context::End_Iterator(); }
private:
A_Verts(Const<Graph,C>& graph) : _graph(graph) {}
F Graph;
GRAPH_FRIENDS
private:
Const<Graph,C>& _graph;
};
_te<CF C>
_cl A_Edges {
public:
_a domain() _ {  _re _graph._es.domain();  }
_a empty() _ {  _re _graph._es.empty();  }
_a count() _ {  _re _graph._es.count();  }
_te<_cl... ARGS>
_a add(IDX_Vert fr, IDX_Vert to, ARGS&&... args) {
if _ce(Directed && !Backlinks) {
_a out = _graph._vs[fr].outs().add();
out().link = to;
if _ce(Has_Edge_Data || Edges_Global) {
out().edge = _graph._es.add( fr, to, std::forward<ARGS>(args)... );
}
}
else if _ce(Directed && Backlinks) {
_a fr_out = _graph._vs[fr].outs().add();
_a to_in  = _graph._vs[to].ins().add();
fr_out().link = H_Vert_Edge{ to, to_in };
to_in().link  = H_Vert_Edge{ fr, fr_out };
if _ce(Has_Edge_Data || Edges_Global) {
_a edge = _graph._es.add( fr, to, std::forward<ARGS>(args)... );
fr_out().edge = edge;
to_in().edge = edge;
}
}
else if _ce(!Directed) {
_a fr_out = _graph._vs[fr].outs().add();
_a to_out = _graph._vs[to].outs().add();
fr_out().link = H_Vert_Edge{ to, to_out };
to_out().link = H_Vert_Edge{ fr, fr_out };
if _ce(Has_Edge_Data || Edges_Global) {
_a edge = _graph._es.add( fr, to, std::forward<ARGS>(args)... );
fr_out().edge = edge;
to_out().edge = edge;
}
}
else {
DCHECK(false);
}
}
_a begin()       {  _re I_Edge<C>    (&_graph, 0);  }
_a begin() _ {  _re I_Edge<CONST>(&_graph, 0);  }
_a end()       {  _re Edges_Context::End_Iterator(); }
_a end() _ {  _re Edges_Context::End_Iterator(); }
private:
A_Edges(Const<Graph,C>& graph) : _graph(graph) {}
F Graph;
GRAPH_FRIENDS
private:
Const<Graph,C>& _graph;
};
_te<CF C, int oi>
_cl A_Outs {
public:
_a domain() _ { _re _raw().domain(); }
_a empty() _ {  _re _raw().empty();  }
_a count() _ {  _re _raw().count();  }
_a _op()(_ty Vert_Edges::Index idx)       { _re A_Out<C,oi>(&_graph, _vert, idx); }
_a _op()(_ty Vert_Edges::Index idx) _ { _re A_Out<C,oi>(&_graph, _vert, idx); }
_a _op()(First_Tag)       { _re A_Out<C,oi>(&_graph, H_Vert_Edge{_vert, _raw()(FIRST)}); }
_a _op()(First_Tag) _ { _re A_Out<C,oi>(&_graph, H_Vert_Edge{_vert, _raw()(FIRST)}); }
_a _op()(Last_Tag)        { _re A_Out<C,oi>(&_graph, H_Vert_Edge{_vert, _raw()(LAST)}); }
_a _op()(Last_Tag)  _ { _re A_Out<C,oi>(&_graph, H_Vert_Edge{_vert, _raw()(LAST)}); }
_a begin()       { _re I_Out<C,oi>(&_graph, H_Vert_Edge{_vert, _raw().begin()}); }
_a begin() _ { _re I_Out<C,oi>(&_graph, H_Vert_Edge{_vert, _raw().begin()}); }
_a end()         { _re _ty Outs_Context<oi>::End_Iterator(); }
_a end() _   { _re _ty Outs_Context<oi>::End_Iterator(); }
private:
_a& _raw()       { _re _graph._vs[_vert].outs_ins[oi]; }
_a& _raw() _ { _re _graph._vs[_vert].outs_ins[oi]; }
private:
A_Outs(Const<Graph,C>& graph, H_Vert vert) : _graph(graph), _vert(vert) {}
GRAPH_FRIENDS
private:
Const<Graph,C>& _graph;
H_Vert _vert;
};
_cl Graph :
private Add__es<Edges, Has_Edge_Data> {
_u ADD_ES_BASE = Add__es<Edges, Has_Edge_Data>;
public:
_u H_Vert = Context::H_Vert;
_u H_Edge = Context::H_Edge;
private:
Verts _vs;
public:
Graph() {}
Graph(int verts_size) : _vs(verts_size) {}
public:
_a vert(IDX_Vert handle)       {  _re A_Vert<MUTAB>( this, handle );  }
_a vert(IDX_Vert handle) _ {  _re A_Vert<CONST>( this, handle );  }
_a vert(First_Tag)       { _re vert( _vs(FIRST) ); }
_a vert(First_Tag) _ { _re vert( _vs(FIRST) ); }
_a vert(Last_Tag)       { _re vert( _vs(LAST) ); }
_a vert(Last_Tag) _ { _re vert( _vs(LAST) ); }
_a edge(IDX_Edge handle)       {  _re A_Edge<MUTAB>( this, handle );  }
_a edge(IDX_Edge handle) _ {  _re A_Edge<CONST>( this, handle );  }
_a edge(First_Tag)       { _re edge( ADD_ES_BASE::_es(FIRST) ); }
_a edge(First_Tag) _ { _re edge( ADD_ES_BASE::_es(FIRST) ); }
_a edge(Last_Tag)       { _re edge( ADD_ES_BASE::_es(LAST) ); }
_a edge(Last_Tag) _ { _re edge( ADD_ES_BASE::_es(LAST) ); }
_a _op()(H_Vert handle)       {  _re A_Vert<MUTAB>( this, handle );  }
_a _op()(H_Vert handle) _ {  _re A_Vert<CONST>( this, handle );  }
_a& _op[](H_Vert handle)       {  _re A_Vert<MUTAB>( this, handle ).data();  }
_a& _op[](H_Vert handle) _ {  _re A_Vert<CONST>( this, handle ).data();  }
_a _op()(H_Edge handle)       {  _re A_Edge<MUTAB>( this, handle );  }
_a _op()(H_Edge handle) _ {  _re A_Edge<CONST>( this, handle );  }
_a& _op[](H_Edge handle)       {  _re A_Edge<MUTAB>( this, handle ).data();  }
_a& _op[](H_Edge handle) _ {  _re A_Edge<CONST>( this, handle ).data();  }
public:
_a verts()       {  _re A_Verts<MUTAB>( *this );  }
_a verts() _ {  _re A_Verts<CONST>( *this );  }
_a edges()       {  _re A_Edges<MUTAB>( *this );  }
_a edges() _ {  _re A_Edges<CONST>( *this );  }
private:
GRAPH_FRIENDS
};
struct With_Builder : Graph {
FORWARDING_CONSTRUCTOR( With_Builder, Graph ) {}
_u DIRECTED = _ty Context<true, Backlinks, Vert_Data, Edge_Data, Verts_Erasable,
Edges_Erasable, Edges_Global> ::With_Builder;
_u BACKLINKS = _ty Context<Directed, true, Vert_Data, Edge_Data, Verts_Erasable,
Edges_Erasable, Edges_Global> ::With_Builder;
_te<_cl DATA>
_u VERT_DATA = _ty Context<Directed, Backlinks, DATA, Edge_Data, Verts_Erasable,
Edges_Erasable, Edges_Global> ::With_Builder;
_te<_cl DATA>
_u EDGE_DATA = _ty Context<Directed, Backlinks, Vert_Data, DATA, Verts_Erasable,
Edges_Erasable, Edges_Global> ::With_Builder;
_u VERTS_ERASABLE = _ty Context<Directed, Backlinks, Vert_Data, Edge_Data, ERASABLE_HOLES,
Edges_Erasable, Edges_Global> ::With_Builder;
_u EDGES_ERASABLE = _ty Context<Directed, Backlinks, Vert_Data, Edge_Data, Verts_Erasable,
ERASABLE_HOLES, Edges_Global> ::With_Builder;
_u VERTS_ERASABLE_REORDER = _ty Context<Directed, Backlinks, Vert_Data, Edge_Data, ERASABLE_REORDER,
Edges_Erasable, Edges_Global> ::With_Builder;
_u EDGES_ERASABLE_REORDER = _ty Context<Directed, Backlinks, Vert_Data, Edge_Data, Verts_Erasable,
ERASABLE_REORDER, Edges_Global> ::With_Builder;
};
};
}
}
_u Graph = internal::graph::Context<
false,
false,
void,
void,
internal::graph::NON_ERASABLE,
internal::graph::NON_ERASABLE,
false
> ::With_Builder;
}
_u namespace salgo;
struct Test_Case {
struct V {
int collapsed_weights = 0;
};
struct E {
int weight = 0;
};
_u G = Graph
::VERT_DATA<V>
::EDGE_DATA<E>
::VERTS_ERASABLE
::EDGES_ERASABLE;
G g;
multimap<int, G::H_Vert> leafs_by_weight;
void solve() {
_a n = ri();
_a k = ri();
g.verts().resize(n);
FOR(i,n-1) {
_a a = ri() - 1;
_a b = ri() - 1;
_a weight = ri();
g.edges().add(a, b, weight);
}
for(_a& v : g.verts()) {
if(v.outs().count() == 1) {
_a weight = v.out(FIRST).edge()->weight;
_a h = v.handle();
leafs_by_weight.emplace( weight, h );
}
}
int result = 0;
while(g.verts().count() > k || leafs_by_weight.size() > 2) {
_a h = leafs_by_weight.begin()->second;
leafs_by_weight.erase( leafs_by_weight.begin() );
_a v = g(h);
ASS( v.outs().count() == 1 );
_a out = v.out(FIRST);
_a next = out.vert();
_a weight = out.edge()->weight + v->collapsed_weights;
REMAX( next->collapsed_weights, weight );
REMAX( result, weight );
v.erase();
if(next.outs().count() == 1) {
leafs_by_weight.emplace( next->collapsed_weights + next.out(FIRST).edge()->weight, next.handle() );
}
}
cout << result << endl;
}
int icase = -1;
};
int main() {
#ifdef READ_NUM_TEST_CASES
int num_test_cases = ri();
for(int i=0; i < num_test_cases; ++i) {
Test_Case tc;
tc.icase = i;
tc.solve();
}
#else
Test_Case tc;
tc.icase = -1;
tc.solve();
#endif
_re 0;
}
