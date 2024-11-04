

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

template<u32...r>struct Arr{static constexpr u32 v[]={r...};};

template<u32 x,u32...p>struct IsNextPrime{enum{v=(...&&(x%p))};};

template<u32 n,bool f,u32...p>struct GetNextPrime:GetNextPrime<n+1+(sizeof...(p)>2),IsNextPrime<n+1+(sizeof...(p)>2),p...>::v,p...>{};
template<u32 n,u32...p>struct GetNextPrime<n,1,p...>{enum{v=n};};

template<u32 n,u32 i=1,u32...p>struct GenPrimes:GenPrimes<(n>=GetNextPrime<GetNextPrime<i,0,p...>::v,0,p...>::v*GetNextPrime<GetNextPrime<i,0,p...>::v,0,p...>::v)?n:0,GetNextPrime<i,0,p...>::v,p...,GetNextPrime<i,0,p...>::v>{};
template<u32 i,u32...p>struct GenPrimes<0,i,p...>:Arr<p...>{};

int main(){
	#ifndef noacm
	if(DEFINED(acm_files)){freopen(acm_in,"r",stdin);freopen(acm_out,"w",stdout);}
	solve();
	if(DEFINED(acm_files)){fclose(stdin);fflush(stdout);fclose(stdout);}
	#else
	

	TESTIO("6 3\n1 3 9 8 24 1","5");
	#endif
}

void solve(){
	

	sca(u32,n,k);

	map<u32,u32> divs;

	u64 ans=0;

	forn(i,n){
		sca(u32,x);

		dbug('>',x);

		u32 dh=1,rh=1;

		for(auto p:GenPrimes<E5>::v){
			u32 c=0;

			while(!(x%p)){
				x/=p;
				c++;
				dbug('%',p);
			}

			c%=k;

			if(c){
				for(u32 dm=c,rm=k-c,pp=p;dm||rm;dm>>=1,rm>>=1,pp*=pp){
					if(dm&1ul)dh*=pp;
					if(rm&1ul)rh*=pp;
				}
			}

			if(x==1){
				break;
			}
		}

		if(x!=1){
			if(k>2){
				goto nonono;
			}

			dh*=x;
			rh*=x;
		}

		if(rh>E5){
			goto nonono;
		}

		{
			auto it=divs.find(rh);

			if(it!=divs.end()){
				ans+=it->b;
			}
		}

		divs[dh]++;

		nonono:
		continue;
	}

	pr(ans);
}