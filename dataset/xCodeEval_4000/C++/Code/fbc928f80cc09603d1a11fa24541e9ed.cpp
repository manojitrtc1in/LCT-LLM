

#if defined(__GNUC__)&&!defined(__ANDROID__)&&!defined(__clang__)
#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast")
#define talloc(a,n,...) __VA_ARGS__ _r_##a[n];auto*const a=_r_##a
#else
#define talloc(a,n,...) vector<__VA_ARGS__>_r_##a(n);auto*const a=_r_##a.data()
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
#include<chrono>
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

#define STR_I(x) #x
#define STR(x) (STR_I(x))
#define DEFINED(x) (*#x-*STR(x))
#define GET_OR_DEFAULT(x,d) ((*#x-*STR(x))?(STR(x)+1):d)

using i8=int8_t;using u8=uint8_t;using i16=int16_t;using u16=uint16_t;using i32=int32_t;using u32=uint32_t;using i64=int64_t;using u64=uint64_t;using f32=float;using f64=double;using f80=long double;
template<size_t n>using cbuf=char[n];
enum Bool:u8{False,True};
[[maybe_unused]]const u32 E9=1e9,E8=1e8,E7=1e7,E6=1e6,E5=1e5,E4=1e4,E3=1e3,E2=1e2;

#define a first
#define b second

#define forn(i,n) for(auto i=1?0:n;i<(n);++i)
#define for1n(i,n) for(auto i=1?1:n;i<(n);++i)
#define forab(i,a,b) for(auto i=1?a:b;i<=(b);++i)
#define fornd(i,n) for(auto i=n;i--;)
#define repn(n) for(auto _=n;_;--_)

namespace Fmt{
	template<u8...r>struct Str{static constexpr cbuf<sizeof...(r)+1>v={r...,'\0'};};template<u8...r>constexpr cbuf<sizeof...(r)+1>Str<r...>::v;

	template<u64 n,u8...r>struct I2Str:I2Str<(n>>8),(u8)n,r...>{};template<u8...r>struct I2Str<0,r...>{using S=Str<r...>;};
	constexpr u64 S2I(const char s[],char b=0,u8 i=0,u64 v=0){return s[i]?S2I(s,b,i+1,s[i]>b?(v<<8)+s[i]:v):v;}

	template<class A,class B>struct StrStrImpl{};template<u8...u,u8...v>struct StrStrImpl<Str<u...>,Str<v...>>{using S=Str<u...,v...>;};
	template<class F,class...R>struct StrStr:StrStrImpl<typename F::S,typename StrStr<R...>::S>{};template<class F>struct StrStr<F>:F{};

	template<class T,class F=void>struct FmtS;
	#define F(s,...) template<class T>struct FmtS<T,typename enable_if<__VA_ARGS__::value>::type>{enum{I=S2I(s,'"')};using S=typename I2Str<I>::S;};
	F(sizeof(T)>1?sizeof(T)>2?sizeof(T)>4?is_signed<T>()?SCNd64:SCNu64:is_signed<T>()?SCNd32:SCNu32:is_signed<T>()?SCNd16:SCNu16:(is_same<char,T>()?"c":is_signed<T>()?GET_OR_DEFAULT(SCNd8,"hhd"):GET_OR_DEFAULT(SCNu8,"hhu")),is_integral<T>);F("f",is_same<T,f32>);F("lf",is_same<T,f64>);F("Lf",is_same<T,f80>);F((is_same<char,decay_t<remove_pointer_t<T>>>()?"s":"p"),is_pointer<T>);
	#undef F

	template<u64 f,u64 e,u64 p,u64 s,class T,class...R>struct Fmt:StrStr<I2Str<s>,I2Str<'%'>,I2Str<p>,FmtS<T>,StrStr<I2Str<f>,I2Str<'%'>,I2Str<p>,FmtS<R>>...,I2Str<e>>::S{};

	template<class A,class B>struct Ref{A v;B _;};template<>struct Ref<char**,char*>{char**_;char*v;};
}

template<u64 f=' ',class...R>string spr(R...r){cbuf<E5>_;sprintf(_,Fmt::Fmt<f,0,0,0,R...>::v,r...);return _;}
void fswp(FILE*&a,FILE*&b){swap(a,b);}void fswp(const FILE*a,const FILE*b){swap(*const_cast<FILE*>(a),*const_cast<FILE*>(b));}
#ifdef noacm
namespace Test{
	struct InputGen:public function<string()>{
		using function::function;
		InputGen(string s):function([s]()mutable{return exchange(s,"");}){}
		template<class F>InputGen(F f,typename Fmt::FmtS<decltype(f())>::S={}):function([f]{return spr(f());}){}
		template<class T>InputGen(T x,typename Fmt::FmtS<T>::S={}):InputGen(spr(x)){}
		InputGen(initializer_list<InputGen>&&v):function([Q=queue<InputGen>(v)]()mutable{string r;while(Q.size()&&(r=Q.front()()).empty())Q.pop();return r;}){}
	};

	template<u32 n=1,u64 s=' '>class Prod{
		vector<InputGen>v;
	public:
		Prod(initializer_list<InputGen>&&v):v(v){};
		auto operator()(){
			string r;
			repn(n)for(auto&f:v){
				auto t=f();if(t.empty())return t;
				r+=r.size()?Fmt::I2Str<s>::S::v+t:t;
			}
			return r;
		}
	};

	class Rep{
		InputGen c,o;u32 n;
	public:
		Rep(u32 n,InputGen&&f):c(""),o(f),n(n){}
		auto operator()(){auto r=c();if(r.empty()*n){n--;c=o;r=c();}return r;}
	};

	class Range{
		i64 n,a,d;
	public:
		Range(i64 n,i64 a=1,i64 d=1):n(n),a(a),d(d){}
		auto operator()(){if(!n)return""s;n--;a+=d;return spr(a-d);}
	};

	bool Log=1;map<void*,pair<string,string>>BM;u32 No;
	int Input(void*_,char*b,conditional_t<DEFINED(__CYGWIN__),size_t,int>n){
		auto& G=*(InputGen*)_;auto& B=BM[_];int r=0;
		for(;;){
			if(B.a.size()) {
				if((int)B.a.size()<n-r){
					memcpy(b+r,B.a.data(),B.a.size());
					r+=B.a.size();B.a="";
				}else{
					memcpy(b+r,B.a.data(),n-r);B.a.erase(0,n-r);
					Log=Log||fprintf(stderr,"\n\nTest input data:\n###\n%.*s...\n###\n\n",min<int>(n,253),b);
					B.b+={b,(size_t)n};return n;
				}
			}
			B.a=G();
			if(B.a.empty()){
				Log=Log||fprintf(stderr,"\n\nTest input data:\n###\n%.*s%s\n###\n\n",min(r,253),b,(253<r)?"...":"");
				B.b+={b,(size_t)r};return r;
			}
			B.a+='\n';
		}
	}

	int Output(void*s,const char*b,conditional_t<DEFINED(__CYGWIN__),size_t,int>n){*(string*)s+={b,(size_t)n};return n;}

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
		template<class T>Checker(T t,typename enable_if<!!is_constructible<InputGen,T>()>::type* =0):function([I=InputGen(t)](string,string o){return equal(InputGenIter(I),{},InputGenIter(o),{});}){}
		template<class F>Checker(F f,typename enable_if<!!is_same<void,decltype(f())>()>::type* =0):function([f](string i,string o){InputGen Q{i};i="";auto I=fropen(&Q,Input),O=fwopen(&i,Output);fswp(I,stdin);fswp(O,stdout);f();fflush(stdout);fswp(I,stdin);fswp(O,stdout);fclose(I);fclose(O);return equal(InputGenIter(i),{},InputGenIter(o),{});}){}
		template<class F>Checker(F f,typename enable_if<!!is_same<Bool,decltype(f())>()>::type* =0):function([f](string,string o){InputGen Q{o};auto I=fropen(&Q,Input);fswp(I,stdin);bool r=f();fswp(I,stdin);fclose(I);return r;}){}
	};
}

#define TEST(...) do{using namespace Test;Log=0;BM.clear();InputGen G{__VA_ARGS__};auto F=fropen(&G,Input);fswp(F,stdin);solve();fswp(F,stdin);fclose(F);fflush(stdout);}while(0)
#define TESTIO(...) do{using namespace Test;Log=0;BM.clear();string OB,EB;pair<InputGen,Checker>Q{__VA_ARGS__};auto I=fropen(&Q,Input),O=fwopen(&OB,Output),E=fwopen(&EB,Output);fswp(I,stdin);fswp(O,stdout);fswp(E,stderr);auto s=chrono::system_clock::now();solve();chrono::duration<f64,milli> d=chrono::system_clock::now()-s;fflush(stdout);fflush(stderr);fswp(I,stdin);fswp(O,stdout);fswp(E,stderr);fclose(I);fclose(O);fclose(E);if(Q.b(BM[&Q].b,OB))pr<0,Fmt::S2I("ms\n")>("OK",++No,d.count());else{pr<0,0>("ER",++No,"Output mismatch!\nGot:",OB.c_str());pr("Log:",EB.c_str());fflush(stdout);return 1;}}while(0)
#endif

void solve();

#if defined(__GNUC__)&&!defined(__clang__)
#define __forceinline inline
#elif defined(__clang__)
#define __forceinline [[gnu::always_inline]]
#endif
bool prE=0;template<u64 p=0,u64 e='\n',u64 f=' ',u64 s=0,class...R>__forceinline int pr(R...r){return fprintf(prE?stderr:stdout,Fmt::Fmt<f,e,p,s,R...>::v,r...);}
template<class...R>__forceinline int sc(R&&...r){return scanf(Fmt::Fmt<0,0,0,0,decay_t<R>...>::v,Fmt::Ref<add_pointer_t<R>,R>{&r,r}.v...);}

#define sca(T,...) T __VA_ARGS__;sc(__VA_ARGS__)
#define scn(a,n) forn(_,n)sc((a)[_])
#define scnn(a,n,T) talloc(a,n,T);scn(a,n)
#define scna(a,n,T) sca(size_t,n);scnn(a,n,T)

#define prs(...) pr<0,' '>(__VA_ARGS__)
#define prn(a,n) if(n)do{for1n(_,n){prs((a-1)[_]);}pr((a-1)[n]);}while(0)

#define gets(s) fgets(s,is_array<decltype(s)>()?sizeof(s):E6,stdin)

#define dbug(...) for(;DEFINED(noacm)&&(prE^=1);)pr<0,'\n',' ',Fmt::S2I("DBug: ")>(__VA_ARGS__)
#define dbugn(a,n) if(DEFINED(noacm))do{prE=1;pr<0,Fmt::S2I("]: "),0,Fmt::S2I("DBug[")>(n);prn(a,n);}while(prE=0)

template<class T>int scmp(T a,T b){return (*b<*a)-(*a<*b);}

#define sqsort(a,n) qsort(a,n,sizeof(*(a)),reinterpret_cast<int(*)(const void*,const void*)>(scmp<decltype(a+1)>))
#define tqsort(a,n,...) qsort(a,n,sizeof(*(a)),reinterpret_cast<int(*)(const void*,const void*)>(scmp<__VA_ARGS__*>))
#define fqsort(a,n,...) qsort(a,n,sizeof(*(a)),reinterpret_cast<int(*)(const void*,const void*)>(static_cast<int(*)(decltype(a+1),decltype(a+1))>(__VA_ARGS__)))

#define sbsearch(k,a,n) (decltype(a+1))bsearch(&k,a,n,sizeof(*(a)),reinterpret_cast<int(*)(const void*,const void*)>(scmp<decltype(a+1)>))
#define tbsearch(k,a,n,...) (decltype(a+1))bsearch(&k,a,n,sizeof(*(a)),reinterpret_cast<int(*)(const void*,const void*)>(scmp<__VA_ARGS__*>))
#define fbsearch(k,a,n,...) (decltype(a+1))bsearch(&k,a,n,sizeof(*(a)),reinterpret_cast<int(*)(const void*,const void*)>(static_cast<int(*)(decltype(&k+1),decltype(a+1))>(__VA_ARGS__)))
#define nbsearch(d,n,...) (uintptr_t)bsearch(d,(u8*)0+1,n,1,reinterpret_cast<int(*)(const void*,const void*)>(static_cast<int(*)(decltype(d),uintptr_t)>(__VA_ARGS__)))

#define memnul(a,n) memset(a,0,(n)*sizeof(*(a)))
#define memneg(a,n) memset(a,-1,(n)*sizeof(*(a)))

template<class T>T rrand(T a,T b){static mt19937 G(time(0));return uniform_int_distribution<T>(a,b)(G);}



#define acm_in	"input.txt"
#define acm_out	"output.txt"

int main(){
	#ifndef noacm
	if(DEFINED(acm_files)){freopen(acm_in,"r",stdin);freopen(acm_out,"w",stdout);}
	solve();
	if(DEFINED(acm_files)){fclose(stdin);fflush(stdout);fclose(stdout);}
	#else
	

		TESTIO("4\n4\nLRUD\n4\nLURD\n5\nRRUDU\n5\nLLDDR","1 2\n1 4\n3 4\n-1");
		TESTIO(
			{
				1,2*E5,
				Prod<2*E5,0>{[]{return 'R';}}
			},
			-1
		);
		TESTIO(
			{
				1,2*E5,
				Prod<1,0>{
					Prod<E5-1,0>{[]{return 'R';}},
					'U',
					Prod<E5-1,0>{[]{return 'L';}},
					'D'
				}
			},
			"1 200000"
		);
		TESTIO(
			{
				1,2*E5,
				Prod<1,0>{
					Prod<E5/2,0>{[]{return 'R';}},
					Prod<E5/2,0>{[]{return 'D';}},
					Prod<E5/2,0>{[]{return 'L';}},
					Prod<E5/2,0>{[]{return 'U';}}
				}
			},
			"1 200000"
		);
	#endif
}

void solve(){
	

	cbuf<2*E5+4>b;
	sca(u16,Q);gets(b);repn(Q){
		gets(b);
		gets(b+1);

		

		map<u64,u32>v;
		union{i32 v[2];u64 r;}u;
		i32&x=u.v[0];
		i32&y=u.v[1];
		x=0;y=0;
		u64&Z=u.r;
		u32 l=0,r=-1;
		v[Z]=1;
		for(u32 i=1;;){
			switch(b[i]){
				case 'L':x--;break;
				case 'R':x++;break;
				case 'U':y--;break;
				case 'D':y++;break;
				default:goto ENDLOOP;
			}
			auto&c=v[Z];
			if(c&&(i-c<r-l)){
				r=i;
				l=c;
			}
			c=++i;
		}
		ENDLOOP:
		if(~r){
			pr(l,r);
		}else{
			pr(-1);
		}
	}
}
