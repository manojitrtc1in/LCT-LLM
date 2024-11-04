

#if defined(__GNUC__)&&!defined(__linux__)&&!defined(__clang__)
#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
[[maybe_unused]] const u32 E9=1e9,E8=1e8,E7=1e7,E6=1e6,E5=1e5,E4=1e4,E3=1e3,E2=1e2;

#define a first
#define b second

#define forn(i,n) for(decltype((n)+1) i=0;i<(n);++i)
#define for1n(i,n) for(decltype((n)+1) i=1;i<(n);++i)
#define forab(i,a,b) for(decltype((a)+(b)) i=(a);i<=(b);++i)
#define fornd(i,n) for(auto i=(n);i--;)
#define repn(n) for(auto _=(n);_;--_)

namespace Fmt{
	template<u8...r>struct Str{static constexpr cbuf<sizeof...(r)+1>v={r...,'\0'};};template<u8...r>constexpr cbuf<sizeof...(r)+1>Str<r...>::v;

	template<u64 n,u8...r>struct I2Str:I2Str<(n>>8),(u8)n,r...>{};template<u8...r>struct I2Str<0,r...>{using S=Str<r...>;};

	template<class A,class B>struct StrStrImpl{};template<u8...u,u8...v>struct StrStrImpl<Str<u...>,Str<v...>>{using S=Str<u...,v...>;};
	template<class F,class...R> struct StrStr:StrStrImpl<typename F::S,typename StrStr<R...>::S>{};template<class S>struct StrStr<S>:S{};

	template<class T,class F=void>struct FmtS;
	#define F(s,...) template<class T>struct FmtS<T,typename enable_if<__VA_ARGS__()|0>::type>{enum:u64{a,b=a+(s[a]>'"'),c=b+(s[b]>'"'),d=c+(s[c]>'"'),e=d+(s[d]>'"'),f=e+(s[e]>'"'),g=f+(s[f]>'"'),h=g+(s[g]>'"'),i=h+(s[h]>'"'),p=256};using S=typename I2Str<(((((((s[a]*p+s[b])*p+s[c])*p+s[d])*p+s[e])*p+s[f])*p+s[g])*p+s[h]>>(8-i<<3))>::S;}
	F((0?"":is_signed<T>()?SCNd16:SCNu16),sizeof(T)==2&&is_integral<T>);F((0?"":is_signed<T>()?SCNd32:SCNu32),sizeof(T)==4&&is_integral<T>);F((0?"":is_signed<T>()?SCNd64:SCNu64),sizeof(T)==8&&is_integral<T>);F("f",is_same<T,f32>);F("lf",is_same<T,f64>);F("Lf",is_same<T,f80>);F((is_same<char,T>()?"c":is_signed<T>()?GET_OR_DEFAULT(SCNd8,"hhd"):GET_OR_DEFAULT(SCNu8,"hhu")),sizeof(T)==1&&is_integral<T>);F((0?"":is_same<char,decay_t<remove_pointer_t<T>>>()?"s":"p"),is_pointer<T>);
	#undef F

	template<u64 f,u64 e,u64 p,class T,class...R>struct Fmt:StrStr<I2Str<'%'>,I2Str<p>,FmtS<T>,StrStr<I2Str<f>,I2Str<'%'>,I2Str<p>,FmtS<R>>...,I2Str<e>>::S{};

	template<class A,class B>struct Ref{A v;B _;};template<>struct Ref<char**,char*>{char**_;char*v;};
}

template<u64 f=' ',class...R>string spr(R...r){cbuf<E5>_;sprintf(_,Fmt::Fmt<f,0,0,R...>::v,r...);return _;}
void fswp(FILE*&a,FILE*&b){swap(a,b);}void fswp(const FILE*a,const FILE*b){swap(*const_cast<FILE*>(a),*const_cast<FILE*>(b));}
#ifdef noacm
namespace Test{
	struct InputGen:public function<string()>{
		using function::function;
		InputGen(string s):function([s]()mutable{return exchange(s,"");}){}
		template<class F>InputGen(F f,typename Fmt::FmtS<decltype(f())>::S* =0):function([f](){return spr(f());}){}
		template<class T>InputGen(T x,typename Fmt::FmtS<T>::S* =0):InputGen(spr(x)){}
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
	int Input(void*_,char*b,int n){
		auto& G=*(InputGen*)_;auto& B=BM[_];int r=0;
		for(;;){
			if(B.a.size()) {
				if((int)B.a.size()<n-r){
					memcpy(b+r,B.a.data(),B.a.size());
					r+=B.a.size();B.a="";
				}else{
					memcpy(b+r,B.a.data(),n-r);B.a.erase(0,n-r);
					Log=Log||fprintf(stderr,"\n\nTest input data:\n###\n%.*s...\n###\n\n",min(n,253),b);
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
		template<class T>Checker(T t,typename enable_if<!!is_constructible<InputGen,T>()>::type* =0):function([I=InputGen(t)](string,string o){return equal(InputGenIter(I),{},InputGenIter(o),{});}){}
		template<class F>Checker(F f,typename enable_if<!!is_same<void,decltype(f())>()>::type* =0):function([f](string i,string o){InputGen Q{i};i="";auto I=fropen(&Q,Input),O=fwopen(&i,Output);fswp(I,stdin);fswp(O,stdout);f();fflush(stdout);fswp(I,stdin);fswp(O,stdout);fclose(I);fclose(O);return equal(InputGenIter(i),{},InputGenIter(o),{});}){}
		template<class F>Checker(F f,typename enable_if<!!is_same<Bool,decltype(f())>()>::type* =0):function([f](string,string o){InputGen Q{o};auto I=fropen(&Q,Input);fswp(I,stdin);bool r=f();fswp(I,stdin);fclose(I);return r;}){}
	};
}

#define TEST(...) do{using namespace Test;Log=0;BM.clear();InputGen G{__VA_ARGS__};auto F=fropen(&G,Input);fswp(F,stdin);solve();fswp(F,stdin);fclose(F);fflush(stdout);}while(0)
#define TESTIO(...) do{using namespace Test;Log=0;BM.clear();string OB,EB;pair<InputGen,Checker>Q{__VA_ARGS__};auto I=fropen(&Q,Input),O=fwopen(&OB,Output),E=fwopen(&EB,Output);fswp(I,stdin);fswp(O,stdout);fswp(E,stderr);solve();fflush(stdout);fflush(stderr);fswp(I,stdin);fswp(O,stdout);fswp(E,stderr);fclose(I);fclose(O);fclose(E);if(Q.b(BM[&Q].b,OB))pr("OK",++No);else{pr<0,0>("ER",++No,"Output mismatch!\nGot:",OB.c_str());pr("Log:",EB.c_str());fflush(stdout);return 1;}}while(0)
#endif

void solve();

#if defined(__GNUC__)&&!defined(__clang__)
#define __forceinline inline [[gnu::always_inline]]
#elif defined(__clang__)
#define __forceinline [[gnu::always_inline]]
#endif
template<u64 p=0,u64 e='\n',u64 f=' ',class...R>__forceinline int pr(R...r){return printf(Fmt::Fmt<f,e,p,R...>::v,r...);}
template<class...R>__forceinline int sc(R&&...r){return scanf(Fmt::Fmt<0,0,0,decay_t<R>...>::v,Fmt::Ref<add_pointer_t<R>,R>{&r,r}.v...);}

#define sca(T,...) T __VA_ARGS__;sc(__VA_ARGS__)
#define scn(a,n) forn(_,n)sc((a)[_])
#define scnn(a,n,T) talloc(a,n,T);scn(a,n)
#define scna(a,n,T) sca(size_t,n);scnn(a,n,T)

#define prs(...) pr<0,' '>(__VA_ARGS__)
#define prn(a,n) if(n)do{for1n(_,n){prs((a-1)[_]);}pr((a-1)[n]);}while(0)

#define gets(s) fgets(s,is_array<decltype(s)>()?sizeof(s):E6,stdin)

#define dbug(...) if(DEFINED(noacm))do{fflush(stdout);fswp(stdout,stderr);pr("DBug:",__VA_ARGS__);fflush(stdout);fswp(stdout,stderr);}while(0)
#define dbugn(a,n) if(DEFINED(noacm))do{fflush(stdout);fswp(stdout,stderr);pr<0,0,0>("Dbug[",n,"]: ");prn(a,n);fflush(stdout);fswp(stdout,stderr);}while(0)

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
	

	TESTIO("5\n5 2 3\n1 2 3\n4 3 3\n4 1 2\n10 2 6\n1 2 3 4 5 7\n2 1 1\n2\n100 76 8\n76 75 36 67 41 74 10 77","2\n0\n4\n0\n2");
	
	auto f=[]{
		sca(u32,T);
		repn(T){
			sca(u32,n,s,k);
			set<u32>o;
			forn(i,n)o.insert(i+1);
			forn(i,k){
				sca(u32,x);
				o.erase(x);
			}
			u32 r=-1;
			auto b=o.lower_bound(s);
			if(b!=o.end())r=min<u32>(r,*b-s);
			if(b!=o.begin())r=min<u32>(r,s-*(--b));
			pr(r);
		}
	};
	TESTIO(
		{
			1,
			E6,E6/2,E3,
			E6/2,E6/2-1,E6/2+1,
			bind(rrand<u32>,1,E6)
		},
		f
	);
	TESTIO(
		{
			1,
			4,3,1,
			3
		},
		f
	);
	#endif
}

void solve(){
	

	sca(u32,T);
	repn(T){
		sca(u32,n,s,k);
		talloc(a,k+2,u32);
		scn(a+1,k);
		a[0]=0;
		a[k+1]=n+1;
		sqsort(a+1,k);
		dbugn(a,k+2);
		u32* sp=0;
		forn(i,k){
			if(a[i+1]==s){
				sp=a+i+1;
				break;
			}
		}
		if(!sp){
			pr(0);
			continue;
		}
		dbug(*sp);
		
		u32 r=-1;
		
		if(sp>=a+1){
			auto p=fbsearch(*sp,a,sp-a,[](u32*a,u32*b){
				dbug(*a,*b);
				if((*a-*b)==a-b){
					dbug(-1);
					return -1;
				}
				b++;
				dbug(1-((*a-*b)==a-b));
				return 1-((*a-*b)==a-b);
			});
			if(p){dbug('<',sp-p,*p);}else{dbug('<');}
			if(p&&sp-p<r)r=sp-p;
		}
		
		if(sp<=a+k){
			auto p=fbsearch(*sp,sp+1,a+k+1-sp,[](u32*a,u32*b){
				dbug(*a,*b);
				if((*b-*a)==b-a){
					dbug(1);
					return 1;
				}
				b--;
				dbug(-1+((*b-*a)==b-a));
				return -1+((*b-*a)==b-a);
			});
			if(p){dbug('>',p-sp,*p);}else{dbug('>');}
			if(p&&p-sp<r)r=p-sp;
		}
		
		pr(r);
		dbug("###");
	}
}
