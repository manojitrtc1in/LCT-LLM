

#define STR_I(x) #x
#define STR(x) (STR_I(x))
#define DEFINED(x) (*#x-*STR(x))
#define GET_OR_DEFAULT(x,d) ((*#x-*STR(x))?(STR(x)+1):d)

#if defined(__x86_64__)and not defined(__clang__)and __GNUC__<9
#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif

#define _USE_MATH_DEFINES
#include"stdio.h"
#include<cctype>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cinttypes>
#include<cstdint>
#include<ctgmath>
#include<bitset>
#include<iostream>
#include<limits>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<random>
#include<set>
#include<stack>
#include<vector>
#include<regex>
#include<tuple>
#include<unordered_map>
#include<unordered_set>

using namespace std;

using i8=int8_t;using u8=uint8_t;using i16=int16_t;using u16=uint16_t;using i32=int32_t;using u32=uint32_t;using i64=int64_t;using u64=uint64_t;using f32=float;using f64=double;using f80=long double;
template<size_t N>using cbuf=char[N];
enum Bool:u8{False,True};

[[maybe_unused]] const u32 E9=1e9,E8=1e8,E7=1e7,E6=1e6,E5=1e5,E4=1e4,E3=1e3,E2=1e2;

#ifdef __GNUC__
#define __forceinline [[gnu::always_inline]]
#endif

namespace Fmt{
	template<char...r>struct Str{static constexpr cbuf<sizeof...(r)+1>v={r...,'\0'};};template<char...r>constexpr cbuf<sizeof...(r)+1>Str<r...>::v;

	template<u64 n,char...r>struct I2Str:I2Str<(n>>8),(char)n,r...>{};template<char...r>struct I2Str<0,r...>:Str<r...>{};

	template<class A,typename B,bool f=1,u8 n=2,u32 i=0,char...r>struct StrStrImpl:StrStrImpl<A,B,!B::v[i+1],n-!B::v[i+1],i+1,r...,B::v[i]>{};
	template<class B,typename A,u8 n,u32 i,char...r>struct StrStrImpl<B,A,1,n,i,r...>:StrStrImpl<A,B,!*B::v,n-!*B::v,0,r...>{};
	template<class A,typename B,u32 i,char...r>struct StrStrImpl<A,B,1,0,i,r...>:Str<r...>{};

	template<class S,typename...R> struct StrStr:StrStrImpl<S,StrStr<R...>>{};template<class S>struct StrStr<S>:S{};

	template<class S,bool f=1,u32 i=0,char...r>struct StrRSan:StrRSan<S,S::v[i+1]>='A',i+1,r...,S::v[i]>{};template<class S,u32 i,char...r>struct StrRSan<S,0,i,r...>:Str<r...>{};

	template<class T>struct FmtS;

	template<u64 f,u64 e,u64 p,typename T,typename...R>struct Fmt:StrStr<Fmt<e,f,p,T>,Fmt<f,e,p,R...>>{};
	template<u64 f,u64 e,u64 p,typename T>struct Fmt<f,e,p,T>:StrStr<Str<'%'>,I2Str<p>,StrRSan<FmtS<T>>,I2Str<e>>{};

	#define F(t,f,...) template<__VA_ARGS__>struct FmtS<t>{constexpr static auto v=f;}
	F(_*,"p",typename _);F(i8,GET_OR_DEFAULT(SCNd8,"hhd"));F(i16,SCNd16);F(i32,SCNd32);F(i64,SCNd64);F(u8,GET_OR_DEFAULT(SCNu8,"hhu"));F(u16,SCNu16);F(u32,SCNu32);F(u64,SCNu64);F(char,"c");F(char*,"s");F(const char*,"s");F(char[_],"s",size_t _);F(bool,FmtS<u8>::v);F(f32,"f");F(f64,"lf");F(f80,"Lf");
	#undef F

	template<class A,typename B>struct Ref{A v;B _;};
	template<>struct Ref<char**,char*>{char**_;char*v;};
}

template<u64 p=0,u64 e='\n',u64 f=' ',typename...R>__forceinline int pr(R...r){return printf(Fmt::Fmt<f,e,p,R...>::v,r...);}
template<class...R>__forceinline int sc(R&&...r){return scanf(Fmt::Fmt<0,0,0,remove_reference_t<R>...>::v,Fmt::Ref<add_pointer_t<R>,R>{&r,r}.v...);}

template<u64 f=' ',typename...R>string spr(R...r){cbuf<E5>_;sprintf(_,Fmt::Fmt<f,0,0,R...>::v,r...);return _;}

#define forn(i,n) for(decltype(n) i=0;i<(n);++i)
#define for1n(i,n) for(decltype(n) i=1;i<(n);++i)
#define forab(i,a,b) for(decltype((a)+(b)) i=(a);i<=(b);++i)
#define fornd(i,n) for(auto i=(n);i--;)
#define repn(n) for(auto _=(n);_;--_)

#if defined(__x86_64__) and __GNUC__<9
#define talloc(a,n,...) __VA_ARGS__ _r_##a[n];auto*const a=_r_##a
#else
#define talloc(a,n,...) vector<__VA_ARGS__>_r_##a(n);auto*const a=_r_##a.data()
#endif

#define sca(T,...) T __VA_ARGS__;sc(__VA_ARGS__)
#define scn(a,n) forn(_,n)sc((a)[_])
#define scnn(a,n,T) talloc(a,n,T);scn(a,n)
#define scna(a,n,T) sca(size_t,n);scnn(a,n,T)

#define prs(...) pr<0,' '>(__VA_ARGS__)
#define prn(a,n) if(n)do{for1n(_,n){prs((a-1)[_]);}pr((a-1)[n]);}while(0)

#define gets(s) fgets(s,is_same<decltype(s),decltype(s+1)>::value?E6:sizeof(s),stdin)

#define a first
#define b second

void FSWP(FILE*&a,FILE*&b){swap(a,b);}void FSWP(const FILE*a,const FILE*b){swap(*const_cast<FILE*>(a),*const_cast<FILE*>(b));}

#define dbug(...) if(DEFINED(noacm))do{fflush(stdout);FSWP(stdout,stderr);pr("DBug:",__VA_ARGS__);fflush(stdout);FSWP(stdout,stderr);}while(0)
#define dbugn(a,n) if(DEFINED(noacm))do{fflush(stdout);FSWP(stdout,stderr);pr<0,0,0>("Dbug[",n,"]: ");prn(a,n);fflush(stdout);FSWP(stdout,stderr);}while(0)

template<class T>int scmp(T a,T b){return (*b<*a)-(*a<*b);}

#define sqsort(a,n) qsort(a,n,sizeof(*(a)),(int(*)(const void*,const void*))scmp<decltype(a+1)>)
#define tqsort(a,n,...) qsort(a,n,sizeof(*(a)),(int(*)(const void*,const void*))scmp<__VA_ARGS__*>)
#define fqsort(a,n,...) qsort(a,n,sizeof(*(a)),(int(*)(const void*,const void*))((int(*)(decltype(a+1),decltype(a+1)))(__VA_ARGS__)))

#define sbsearch(k,a,n) (decltype(a+1))bsearch(&k,a,n,sizeof(*(a)),(int(*)(const void*,const void*))scmp<decltype(a+1)>)
#define tbsearch(k,a,n,...) (decltype(a+1))bsearch(&k,a,n,sizeof(*(a)),(int(*)(const void*,const void*))scmp<__VA_ARGS__*>)
#define fbsearch(k,a,n,...) (decltype(a+1))bsearch(&k,a,n,sizeof(*(a)),(int(*)(const void*,const void*))((int(*)(decltype(&k+1),decltype(a+1)))(__VA_ARGS__)))

#define memnul(a,n) memset(a,0,(n)*sizeof(*(a)))
#define memneg(a,n) memset(a,-1,(n)*sizeof(*(a)))

template<class T>T rrand(T a,T b){static mt19937 G(time(0));return uniform_int_distribution<T>(a,b)(G);}

#ifdef noacm
namespace Test{
	struct InputGen:public function<string()>{
		using function::function;
		template<class F>InputGen(F f,typename enable_if<is_arithmetic<decltype(f())>::value>::type* =0,typename enable_if<is_constructible<function<decltype(f())()>,F>::value>::type* =0):function([f](){return spr(f());}){}
		template<class S>InputGen(S&&s,typename enable_if<is_constructible<string,S>::value>::type* =0):function([s=(string)s]()mutable{auto _=s;s="";return _;}){}
		template<class T>InputGen(T x,typename enable_if<is_arithmetic<T>::value>::type* =0):InputGen(spr(x)){}
		InputGen(initializer_list<InputGen>&&v):function([Q=queue<InputGen>(v)]()mutable{string r;while(Q.size()&&(r=Q.front()()).empty())Q.pop();return r;}){}
	};

	template<u32 N=1,u64 S=' '>class Prod{
		vector<InputGen>v;
	public:
		Prod(initializer_list<InputGen>&&v):v(v){};
		auto operator()(){
			string r;
			repn(N)for(auto&f:v){
				auto _=f();
				if(_.empty())return _;
				if(r.size())r+=Fmt::I2Str<S>::v;
				r+=_;
			}
			return r;
		}
	};

	class Rep{
		InputGen c,o;u32 n;
	public:
		Rep(u32 n,InputGen&&f):c(""),o(f),n(n){}
		auto operator()(){
			auto _=c();
			if(_.size()+!n)return _;
			n--;c=o;return c();
		}
	};

	class Range{
		i64 n,a,d;
	public:
		Range(i64 n,i64 a=1,i64 d=1):n(n),a(a),d(d){}
		auto operator()(){
			if(!n)return""s;
			n--;a+=d;return spr(a-d);
		}
	};

	bool Log=1;map<void*,pair<string,string>>BM;u32 No;
	int Input(void*_,char*b,int n){
		auto& G=*(InputGen*)_;auto& B=BM[_];int r=0;
		for(;;){
			if(B.a.size()) {
				if((int)B.a.size()<n-r){
					memcpy(b+r,B.a.data(),B.a.size());
					r+=B.a.size();B.a="";
				}else{
					memcpy(b+r,B.a.data(),n-r);
					B.a.erase(0,n-r);
					Log=Log||fprintf(stderr,"\n\nTest input data:\n###\n%.*s...\n###\n\n",min(n,253),b);
					B.b+={b,(size_t)n};
					return n;
				}
			}
			B.a=G();
			if(B.a.empty()){
				Log=Log||fprintf(stderr,"\n\nTest input data:\n###\n%.*s%s\n###\n\n",min(r,253),b,(253<r)?"...":"");
				B.b+={b,(size_t)r};
				return r;
			}
			B.a+='\n';
		}
	}

	int Output(void*s,const char*b,int n){*(string*)s+={b,(size_t)n};return n;}

	class InputGenIter:public iterator<input_iterator_tag,string>{
		InputGen g;shared_ptr<FILE>f;cbuf<E5>s;
	public:
		InputGenIter():g{}{*s=0;}
		InputGenIter(InputGen _):g(_),f(fropen(&g,Input),fclose){++*this;}
		InputGenIter&operator++(){fscanf(f.get(),"%s",s)>0||(*s=0);return*this;}
		string operator*(){return s;}
		bool operator!=(InputGenIter&o){return*s|*o.s;}bool operator==(InputGenIter&o){return!*s&!*o.s;}
	};

	struct Checker:public function<bool(string,string)>{
		using function::function;
		template<class T>Checker(T t,typename enable_if<is_constructible<InputGen,T>::value>::type* =0):function([I=InputGen(t)](string,string o){return equal(InputGenIter(I),{},InputGenIter(o),{});}){}
		template<class F>Checker(F f,typename enable_if<is_same<void,decltype(f())>::value>::type* =0):function([f](string i,string o){InputGen Q{i};i="";auto I=fropen(&Q,Input),O=fwopen(&i,Output);FSWP(I,stdin);FSWP(O,stdout);f();fflush(stdout);FSWP(I,stdin);FSWP(O,stdout);fclose(I);fclose(O);return equal(InputGenIter(i),{},InputGenIter(o),{});}){}
		template<class F>Checker(F f,typename enable_if<is_same<Bool,decltype(f())>::value>::type* =0):function([f](string,string o){InputGen Q{o};auto I=fropen(&Q,Input);FSWP(I,stdin);bool r=f();FSWP(I,stdin);fclose(I);return r;}){}
	};
}

#define TEST(...) do{using namespace Test;Log=0;BM.clear();InputGen G{__VA_ARGS__};auto F=fropen(&G,Input);FSWP(F,stdin);solve();FSWP(F,stdin);fclose(F);fflush(stdout);}while(0)
#define TESTIO(...) do{using namespace Test;Log=0;BM.clear();string OB,EB;pair<InputGen,Checker>Q{__VA_ARGS__};auto I=fropen(&Q,Input),O=fwopen(&OB,Output),E=fwopen(&EB,Output);FSWP(I,stdin);FSWP(O,stdout);FSWP(E,stderr);solve();fflush(stdout);fflush(stderr);FSWP(I,stdin);FSWP(O,stdout);FSWP(E,stderr);fclose(I);fclose(O);fclose(E);if(Q.b(BM[&Q].b,OB))pr("OK",++No);else{pr<0,0>("ER",++No,"Output mismatch!\nGot:",OB.c_str());pr("Log:",EB.c_str());fflush(stdout);return 1;}}while(0)
#endif

void solve();



#define acm_in	"input.txt"
#define acm_out	"output.txt"

int main(){
	#ifndef noacm
	if(DEFINED(acm_files)){freopen(acm_in,"r",stdin);freopen(acm_out,"w",stdout);}
	solve();
	if(DEFINED(acm_files)){fclose(stdin);fflush(stdout);fclose(stdout);}
	#else
	

	TESTIO("2 2","5");
	TESTIO("10 1","55");
	TESTIO("723 9","157557417");
	#endif
}

class uint128_t{
	private:
		uint64_t UPPER, LOWER;

	public:
		

		uint128_t();
		uint128_t(const uint128_t & rhs);
		uint128_t(uint128_t && rhs);
		uint128_t(std::string & s);
		uint128_t(const char *s);

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		uint128_t(const T & rhs)
			: UPPER(0), LOWER(rhs)
		{}

		template <typename S, typename T, typename = typename std::enable_if <std::is_integral<S>::value && std::is_integral<T>::value, void>::type>
		uint128_t(const S & upper_rhs, const T & lower_rhs)
			: UPPER(upper_rhs), LOWER(lower_rhs)
		{}

		


		

		uint128_t & operator=(const uint128_t & rhs);
		uint128_t & operator=(uint128_t && rhs);

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		uint128_t & operator=(const T & rhs){
			UPPER = 0;
			LOWER = rhs;
			return *this;
		}

		

		operator bool() const;
		operator uint8_t() const;
		operator uint16_t() const;
		operator uint32_t() const;
		operator uint64_t() const;

		

		uint128_t operator&(const uint128_t & rhs) const;

		void export_bits(std::vector<uint8_t> & ret) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		uint128_t operator&(const T & rhs) const{
			return uint128_t(0, LOWER & (uint64_t) rhs);
		}

		uint128_t & operator&=(const uint128_t & rhs);

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		uint128_t & operator&=(const T & rhs){
			UPPER = 0;
			LOWER &= rhs;
			return *this;
		}

		uint128_t operator|(const uint128_t & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		uint128_t operator|(const T & rhs) const{
			return uint128_t(UPPER, LOWER | (uint64_t) rhs);
		}

		uint128_t & operator|=(const uint128_t & rhs);

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		uint128_t & operator|=(const T & rhs){
			LOWER |= (uint64_t) rhs;
			return *this;
		}

		uint128_t operator^(const uint128_t & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		uint128_t operator^(const T & rhs) const{
			return uint128_t(UPPER, LOWER ^ (uint64_t) rhs);
		}

		uint128_t & operator^=(const uint128_t & rhs);

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		uint128_t & operator^=(const T & rhs){
			LOWER ^= (uint64_t) rhs;
			return *this;
		}

		uint128_t operator~() const;

		

		uint128_t operator<<(const uint128_t & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		uint128_t operator<<(const T & rhs) const{
			return *this << uint128_t(rhs);
		}

		uint128_t & operator<<=(const uint128_t & rhs);

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		uint128_t & operator<<=(const T & rhs){
			*this = *this << uint128_t(rhs);
			return *this;
		}

		uint128_t operator>>(const uint128_t & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		uint128_t operator>>(const T & rhs) const{
			return *this >> uint128_t(rhs);
		}

		uint128_t & operator>>=(const uint128_t & rhs);

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		uint128_t & operator>>=(const T & rhs){
			*this = *this >> uint128_t(rhs);
			return *this;
		}

		

		bool operator!() const;
		bool operator&&(const uint128_t & rhs) const;
		bool operator||(const uint128_t & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		bool operator&&(const T & rhs){
			return static_cast <bool> (*this && rhs);
		}

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		bool operator||(const T & rhs){
			return static_cast <bool> (*this || rhs);
		}

		

		bool operator==(const uint128_t & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		bool operator==(const T & rhs) const{
			return (!UPPER && (LOWER == (uint64_t) rhs));
		}

		bool operator!=(const uint128_t & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		bool operator!=(const T & rhs) const{
			return (UPPER | (LOWER != (uint64_t) rhs));
		}

		bool operator>(const uint128_t & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		bool operator>(const T & rhs) const{
			return (UPPER || (LOWER > (uint64_t) rhs));
		}

		bool operator<(const uint128_t & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		bool operator<(const T & rhs) const{
			return (!UPPER)?(LOWER < (uint64_t) rhs):false;
		}

		bool operator>=(const uint128_t & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		bool operator>=(const T & rhs) const{
			return ((*this > rhs) | (*this == rhs));
		}

		bool operator<=(const uint128_t & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		bool operator<=(const T & rhs) const{
			return ((*this < rhs) | (*this == rhs));
		}

		

		uint128_t operator+(const uint128_t & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		uint128_t operator+(const T & rhs) const{
			return uint128_t(UPPER + ((LOWER + (uint64_t) rhs) < LOWER), LOWER + (uint64_t) rhs);
		}

		uint128_t & operator+=(const uint128_t & rhs);

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		uint128_t & operator+=(const T & rhs){
			UPPER = UPPER + ((LOWER + rhs) < LOWER);
			LOWER = LOWER + rhs;
			return *this;
		}

		uint128_t operator-(const uint128_t & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		uint128_t operator-(const T & rhs) const{
			return uint128_t((uint64_t) (UPPER - ((LOWER - rhs) > LOWER)), (uint64_t) (LOWER - rhs));
		}

		uint128_t & operator-=(const uint128_t & rhs);

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		uint128_t & operator-=(const T & rhs){
			*this = *this - rhs;
			return *this;
		}

		uint128_t operator*(const uint128_t & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		uint128_t operator*(const T & rhs) const{
			return *this * uint128_t(rhs);
		}

		uint128_t & operator*=(const uint128_t & rhs);

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		uint128_t & operator*=(const T & rhs){
			*this = *this * uint128_t(rhs);
			return *this;
		}

	private:
		std::pair <uint128_t, uint128_t> divmod(const uint128_t & lhs, const uint128_t & rhs) const;
		void init(const char * s);
		void ConvertToVector(std::vector<uint8_t> & current, const uint64_t & val) const;
		uint8_t HexToInt(const char *s) const;
		uint64_t ConvertToUint64(const char *s) const;

	public:
		uint128_t operator/(const uint128_t & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		uint128_t operator/(const T & rhs) const{
			return *this / uint128_t(rhs);
		}

		uint128_t & operator/=(const uint128_t & rhs);

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		uint128_t & operator/=(const T & rhs){
			*this = *this / uint128_t(rhs);
			return *this;
		}

		uint128_t operator%(const uint128_t & rhs) const;

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		uint128_t operator%(const T & rhs) const{
			return *this % uint128_t(rhs);
		}

		uint128_t & operator%=(const uint128_t & rhs);

		template <typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type >
		uint128_t & operator%=(const T & rhs){
			*this = *this % uint128_t(rhs);
			return *this;
		}

		

		uint128_t & operator++();
		uint128_t operator++(int);

		

		uint128_t & operator--();
		uint128_t operator--(int);

		

		uint128_t operator+() const;

		

		uint128_t operator-() const;

		

		const uint64_t & upper() const;
		const uint64_t & lower() const;

		

		uint8_t bits() const;

		

		std::string str(uint8_t base = 10, const unsigned int & len = 0) const;
};

const uint128_t uint128_0(0);
const uint128_t uint128_1(1);

uint128_t::uint128_t()
	: UPPER(0), LOWER(0)
{}

uint128_t::uint128_t(const uint128_t & rhs)
	: UPPER(rhs.UPPER), LOWER(rhs.LOWER)
{}

uint128_t::uint128_t(uint128_t && rhs)
	: UPPER(std::move(rhs.UPPER)), LOWER(std::move(rhs.LOWER))
{
	if (this != &rhs){
		rhs.UPPER = 0;
		rhs.LOWER = 0;
	}
}

uint128_t::uint128_t(std::string & s) {
	init(s.c_str());
}

uint128_t::uint128_t(const char *s) {
	init(s);
}

void uint128_t::init(const char *s) {
	if (s == NULL || s[0] == 0) { uint128_t(); return; }
	if (s[1] == 'x')
		s += 2;
	else if (*s == 'x')
		s++;

	UPPER = ConvertToUint64(s);
	LOWER = ConvertToUint64(s + 16);
}

uint64_t uint128_t::ConvertToUint64(const char *s) const {
	int count = 0;
	uint64_t val = 0;
	uint8_t hv = HexToInt(s++);
	while (hv != 0xFF && count < 16) {
		val = (val << 4) | hv;
		hv = HexToInt(&s[count]);
		count++;
	}
	return val;
}

uint8_t uint128_t::HexToInt(const char *s) const {
	uint8_t ret = 0xFF;
	if (*s >= '0' && *s <= '9') {
		ret = uint8_t(*s - '0');
	}
	else if (*s >= 'a' && *s <= 'f') {
		ret = uint8_t(*s - 'a' + 10);
	}
	else if (*s >= 'A' && *s <= 'F') {
		ret = uint8_t(*s - 'A' + 10);
	}
	return ret;
}

uint128_t & uint128_t::operator=(const uint128_t & rhs){
	UPPER = rhs.UPPER;
	LOWER = rhs.LOWER;
	return *this;
}

uint128_t & uint128_t::operator=(uint128_t && rhs){
	if (this != &rhs){
		UPPER = std::move(rhs.UPPER);
		LOWER = std::move(rhs.LOWER);
		rhs.UPPER = 0;
		rhs.LOWER = 0;
	}
	return *this;
}

uint128_t::operator bool() const{
	return (bool) (UPPER | LOWER);
}

uint128_t::operator uint8_t() const{
	return (uint8_t) LOWER;
}

uint128_t::operator uint16_t() const{
	return (uint16_t) LOWER;
}

uint128_t::operator uint32_t() const{
	return (uint32_t) LOWER;
}

uint128_t::operator uint64_t() const{
	return (uint64_t) LOWER;
}

uint128_t uint128_t::operator&(const uint128_t & rhs) const{
	return uint128_t(UPPER & rhs.UPPER, LOWER & rhs.LOWER);
}

uint128_t & uint128_t::operator&=(const uint128_t & rhs){
	UPPER &= rhs.UPPER;
	LOWER &= rhs.LOWER;
	return *this;
}

uint128_t uint128_t::operator|(const uint128_t & rhs) const{
	return uint128_t(UPPER | rhs.UPPER, LOWER | rhs.LOWER);
}

uint128_t & uint128_t::operator|=(const uint128_t & rhs){
	UPPER |= rhs.UPPER;
	LOWER |= rhs.LOWER;
	return *this;
}

uint128_t uint128_t::operator^(const uint128_t & rhs) const{
	return uint128_t(UPPER ^ rhs.UPPER, LOWER ^ rhs.LOWER);
}

uint128_t & uint128_t::operator^=(const uint128_t & rhs){
	UPPER ^= rhs.UPPER;
	LOWER ^= rhs.LOWER;
	return *this;
}

uint128_t uint128_t::operator~() const{
	return uint128_t(~UPPER, ~LOWER);
}

uint128_t uint128_t::operator<<(const uint128_t & rhs) const{
	const uint64_t shift = rhs.LOWER;
	if (((bool) rhs.UPPER) || (shift >= 128)){
		return uint128_0;
	}
	else if (shift == 64){
		return uint128_t(LOWER, 0);
	}
	else if (shift == 0){
		return *this;
	}
	else if (shift < 64){
		return uint128_t((UPPER << shift) + (LOWER >> (64 - shift)), LOWER << shift);
	}
	else if ((128 > shift) && (shift > 64)){
		return uint128_t(LOWER << (shift - 64), 0);
	}
	else{
		return uint128_0;
	}
}

uint128_t & uint128_t::operator<<=(const uint128_t & rhs){
	*this = *this << rhs;
	return *this;
}

uint128_t uint128_t::operator>>(const uint128_t & rhs) const{
	const uint64_t shift = rhs.LOWER;
	if (((bool) rhs.UPPER) || (shift >= 128)){
		return uint128_0;
	}
	else if (shift == 64){
		return uint128_t(0, UPPER);
	}
	else if (shift == 0){
		return *this;
	}
	else if (shift < 64){
		return uint128_t(UPPER >> shift, (UPPER << (64 - shift)) + (LOWER >> shift));
	}
	else if ((128 > shift) && (shift > 64)){
		return uint128_t(0, (UPPER >> (shift - 64)));
	}
	else{
		return uint128_0;
	}
}

uint128_t & uint128_t::operator>>=(const uint128_t & rhs){
	*this = *this >> rhs;
	return *this;
}

bool uint128_t::operator!() const{
	return !(bool) (UPPER | LOWER);
}

bool uint128_t::operator&&(const uint128_t & rhs) const{
	return ((bool) *this && rhs);
}

bool uint128_t::operator||(const uint128_t & rhs) const{
	 return ((bool) *this || rhs);
}

bool uint128_t::operator==(const uint128_t & rhs) const{
	return ((UPPER == rhs.UPPER) && (LOWER == rhs.LOWER));
}

bool uint128_t::operator!=(const uint128_t & rhs) const{
	return ((UPPER != rhs.UPPER) | (LOWER != rhs.LOWER));
}

bool uint128_t::operator>(const uint128_t & rhs) const{
	if (UPPER == rhs.UPPER){
		return (LOWER > rhs.LOWER);
	}
	return (UPPER > rhs.UPPER);
}

bool uint128_t::operator<(const uint128_t & rhs) const{
	if (UPPER == rhs.UPPER){
		return (LOWER < rhs.LOWER);
	}
	return (UPPER < rhs.UPPER);
}

bool uint128_t::operator>=(const uint128_t & rhs) const{
	return ((*this > rhs) | (*this == rhs));
}

bool uint128_t::operator<=(const uint128_t & rhs) const{
	return ((*this < rhs) | (*this == rhs));
}

uint128_t uint128_t::operator+(const uint128_t & rhs) const{
	return uint128_t(UPPER + rhs.UPPER + ((LOWER + rhs.LOWER) < LOWER), LOWER + rhs.LOWER);
}

uint128_t & uint128_t::operator+=(const uint128_t & rhs){
	UPPER += rhs.UPPER + ((LOWER + rhs.LOWER) < LOWER);
	LOWER += rhs.LOWER;
	return *this;
}

uint128_t uint128_t::operator-(const uint128_t & rhs) const{
	return uint128_t(UPPER - rhs.UPPER - ((LOWER - rhs.LOWER) > LOWER), LOWER - rhs.LOWER);
}

uint128_t & uint128_t::operator-=(const uint128_t & rhs){
	*this = *this - rhs;
	return *this;
}

uint128_t uint128_t::operator*(const uint128_t & rhs) const{
	

	uint64_t top[4] = {UPPER >> 32, UPPER & 0xffffffff, LOWER >> 32, LOWER & 0xffffffff};
	uint64_t bottom[4] = {rhs.UPPER >> 32, rhs.UPPER & 0xffffffff, rhs.LOWER >> 32, rhs.LOWER & 0xffffffff};
	uint64_t products[4][4];

	

	for(int y = 3; y > -1; y--){
		for(int x = 3; x > -1; x--){
			products[3 - x][y] = top[x] * bottom[y];
		}
	}

	

	uint64_t fourth32 = (products[0][3] & 0xffffffff);
	uint64_t third32  = (products[0][2] & 0xffffffff) + (products[0][3] >> 32);
	uint64_t second32 = (products[0][1] & 0xffffffff) + (products[0][2] >> 32);
	uint64_t first32  = (products[0][0] & 0xffffffff) + (products[0][1] >> 32);

	

	third32  += (products[1][3] & 0xffffffff);
	second32 += (products[1][2] & 0xffffffff) + (products[1][3] >> 32);
	first32  += (products[1][1] & 0xffffffff) + (products[1][2] >> 32);

	

	second32 += (products[2][3] & 0xffffffff);
	first32  += (products[2][2] & 0xffffffff) + (products[2][3] >> 32);

	

	first32  += (products[3][3] & 0xffffffff);

	

	third32  += fourth32 >> 32;
	second32 += third32  >> 32;
	first32  += second32 >> 32;

	

	fourth32 &= 0xffffffff;
	third32  &= 0xffffffff;
	second32 &= 0xffffffff;
	first32  &= 0xffffffff;

	

	return uint128_t((first32 << 32) | second32, (third32 << 32) | fourth32);
}

uint128_t & uint128_t::operator*=(const uint128_t & rhs){
	*this = *this * rhs;
	return *this;
}

void uint128_t::ConvertToVector(std::vector<uint8_t> & ret, const uint64_t & val) const {
	ret.push_back(static_cast<uint8_t>(val >> 56));
	ret.push_back(static_cast<uint8_t>(val >> 48));
	ret.push_back(static_cast<uint8_t>(val >> 40));
	ret.push_back(static_cast<uint8_t>(val >> 32));
	ret.push_back(static_cast<uint8_t>(val >> 24));
	ret.push_back(static_cast<uint8_t>(val >> 16));
	ret.push_back(static_cast<uint8_t>(val >> 8));
	ret.push_back(static_cast<uint8_t>(val));
}

void uint128_t::export_bits(std::vector<uint8_t> &ret) const {
	ConvertToVector(ret, const_cast<const uint64_t&>(UPPER));
	ConvertToVector(ret, const_cast<const uint64_t&>(LOWER));
}

std::pair <uint128_t, uint128_t> uint128_t::divmod(const uint128_t & lhs, const uint128_t & rhs) const{
	

	if (rhs == uint128_0){
		throw std::domain_error("Error: division or modulus by 0");
	}
	else if (rhs == uint128_1){
		return std::pair <uint128_t, uint128_t> (lhs, uint128_0);
	}
	else if (lhs == rhs){
		return std::pair <uint128_t, uint128_t> (uint128_1, uint128_0);
	}
	else if ((lhs == uint128_0) || (lhs < rhs)){
		return std::pair <uint128_t, uint128_t> (uint128_0, lhs);
	}

	std::pair <uint128_t, uint128_t> qr (uint128_0, uint128_0);
	for(uint8_t x = lhs.bits(); x > 0; x--){
		qr.first  <<= uint128_1;
		qr.second <<= uint128_1;

		if ((lhs >> (x - 1U)) & 1){
			++qr.second;
		}

		if (qr.second >= rhs){
			qr.second -= rhs;
			++qr.first;
		}
	}
	return qr;
}

uint128_t uint128_t::operator/(const uint128_t & rhs) const{
	return divmod(*this, rhs).first;
}

uint128_t & uint128_t::operator/=(const uint128_t & rhs){
	*this = *this / rhs;
	return *this;
}

uint128_t uint128_t::operator%(const uint128_t & rhs) const{
	return divmod(*this, rhs).second;
}

uint128_t & uint128_t::operator%=(const uint128_t & rhs){
	*this = *this % rhs;
	return *this;
}

uint128_t & uint128_t::operator++(){
	return *this += uint128_1;
}

uint128_t uint128_t::operator++(int){
	uint128_t temp(*this);
	++*this;
	return temp;
}

uint128_t & uint128_t::operator--(){
	return *this -= uint128_1;
}

uint128_t uint128_t::operator--(int){
	uint128_t temp(*this);
	--*this;
	return temp;
}

uint128_t uint128_t::operator+() const{
	return *this;
}

uint128_t uint128_t::operator-() const{
	return ~*this + uint128_1;
}

const uint64_t & uint128_t::upper() const{
	return UPPER;
}

const uint64_t & uint128_t::lower() const{
	return LOWER;
}

uint8_t uint128_t::bits() const{
	uint8_t out = 0;
	if (UPPER){
		out = 64;
		uint64_t up = UPPER;
		while (up){
			up >>= 1;
			out++;
		}
	}
	else{
		uint64_t low = LOWER;
		while (low){
			low >>= 1;
			out++;
		}
	}
	return out;
}

std::string uint128_t::str(uint8_t base, const unsigned int & len) const{
	if ((base < 2) || (base > 16)){
		throw std::invalid_argument("Base must be in the range [2, 16]");
	}
	std::string out = "";
	if (!(*this)){
		out = "0";
	}
	else{
		std::pair <uint128_t, uint128_t> qr(*this, uint128_0);
		do{
			qr = divmod(qr.first, base);
			out = "0123456789abcdef"[(uint8_t) qr.second] + out;
		} while (qr.first);
	}
	if (out.size() < len){
		out = std::string(len - out.size(), '0') + out;
	}
	return out;
}

uint128_t operator<<(const bool & lhs, const uint128_t & rhs){
	return uint128_t(lhs) << rhs;
}

uint128_t operator<<(const uint8_t & lhs, const uint128_t & rhs){
	return uint128_t(lhs) << rhs;
}

uint128_t operator<<(const uint16_t & lhs, const uint128_t & rhs){
	return uint128_t(lhs) << rhs;
}

uint128_t operator<<(const uint32_t & lhs, const uint128_t & rhs){
	return uint128_t(lhs) << rhs;
}

uint128_t operator<<(const uint64_t & lhs, const uint128_t & rhs){
	return uint128_t(lhs) << rhs;
}

uint128_t operator<<(const int8_t & lhs, const uint128_t & rhs){
	return uint128_t(lhs) << rhs;
}

uint128_t operator<<(const int16_t & lhs, const uint128_t & rhs){
	return uint128_t(lhs) << rhs;
}

uint128_t operator<<(const int32_t & lhs, const uint128_t & rhs){
	return uint128_t(lhs) << rhs;
}

uint128_t operator<<(const int64_t & lhs, const uint128_t & rhs){
	return uint128_t(lhs) << rhs;
}

uint128_t operator>>(const bool & lhs, const uint128_t & rhs){
	return uint128_t(lhs) >> rhs;
}

uint128_t operator>>(const uint8_t & lhs, const uint128_t & rhs){
	return uint128_t(lhs) >> rhs;
}

uint128_t operator>>(const uint16_t & lhs, const uint128_t & rhs){
	return uint128_t(lhs) >> rhs;
}

uint128_t operator>>(const uint32_t & lhs, const uint128_t & rhs){
	return uint128_t(lhs) >> rhs;
}

uint128_t operator>>(const uint64_t & lhs, const uint128_t & rhs){
	return uint128_t(lhs) >> rhs;
}

uint128_t operator>>(const int8_t & lhs, const uint128_t & rhs){
	return uint128_t(lhs) >> rhs;
}

uint128_t operator>>(const int16_t & lhs, const uint128_t & rhs){
	return uint128_t(lhs) >> rhs;
}

uint128_t operator>>(const int32_t & lhs, const uint128_t & rhs){
	return uint128_t(lhs) >> rhs;
}

uint128_t operator>>(const int64_t & lhs, const uint128_t & rhs){
	return uint128_t(lhs) >> rhs;
}

std::ostream & operator<<(std::ostream & stream, const uint128_t & rhs){
	if (stream.flags() & stream.oct){
		stream << rhs.str(8);
	}
	else if (stream.flags() & stream.dec){
		stream << rhs.str(10);
	}
	else if (stream.flags() & stream.hex){
		stream << rhs.str(16);
	}
	return stream;
}

void solve(){
	

	sca(u32,n,m);

	u64 ans=0;
	u64 mod=E9+7;

	auto C=[&mod](u64 n,u64 k){
		::uint128_t r=1;
		u64 d=1;
		if(k>n-k)k=n-k;
		forab(i,n-k+1,n){
			r*=i;
			if(d<=k){
				r/=d;
				d++;
			}
		}
		return (r%mod).lower();
	};

	forab(i,1,n){
		ans += C((m-1)+i-1, m-1) * C(m+(n-i+1)-1, m);
		ans %= mod;
	}

	pr((u64)ans);
}
