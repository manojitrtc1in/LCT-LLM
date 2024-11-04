

#define STR_I(x) #x
#define STR(x) STR_I(x)
#define MACRO_DEFINED(x) (#x[0]-STR(x)[0])
#define MACRO_GET_OR_DEFAULT(x,d) ((#x[0]-STR(x)[0])?((const char*)STR(x)+1):d)

#if defined(__x86_64__)and not defined(__clang__)and __GNUC__<9
#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif

#define _USE_MATH_DEFINES
#include<cctype>
#include<climits>
#include"stdio.h"
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
#ifdef _GLIBCXX_USE_FLOAT128
using f128=__float128;
#elif defined(noacm)
using f128=f80;
#endif

template<size_t N>using cbuf=char[N];
enum Bool:u8{False,True};

const u32 E9=1e9,E8=1e8,E7=1e7,E6=1e6,E5=1e5,E4=1e4,E3=1e3,E2=1e2;

#ifdef __GNUC__
#define __forceinline __attribute__((always_inline))
#endif

namespace Fmt{
	template<char...r>struct Str{static constexpr cbuf<sizeof...(r)+1>v={r...,'\0'};};template<char...r>constexpr cbuf<sizeof...(r)+1>Str<r...>::v;

	template<u64 N,char...r>struct I2Str:I2Str<(N>>8),(char)N,r...>{};template<char...r>struct I2Str<0,r...>:Str<r...>{};

	template<typename u,typename v,bool f=1,size_t N=2,size_t i=0,char...r>struct StrStrImpl:StrStrImpl<u,v,!v::v[i+1],N-!v::v[i+1],i+1,r...,v::v[i]>{};
	template<typename v,typename u,size_t N,size_t i,char...r>struct StrStrImpl<v,u,true,N,i,r...>:StrStrImpl<u,v,!*v::v,N-!*v::v,0,r...>{};
	template<typename u,typename v,size_t i,char...r>struct StrStrImpl<u,v,true,0,i,r...>:Str<r...>{};

	template<typename s,typename...r> struct StrStr:StrStrImpl<s,StrStr<r...>>{};template<typename s>struct StrStr<s>:s{};

	template<typename s,bool f=1,size_t i=0,char...r>struct StrRSan:StrRSan<s,s::v[i+1]>='A',i+1,r...,s::v[i]>{};template<typename s,size_t i,char...r>struct StrRSan<s,false,i,r...>:Str<r...>{};

	template<typename T>struct FmtS;

	template<u64 F,u64 E,u64 P,typename T,typename... R>struct Fmt:StrStr<Fmt<E,F,P,T>,Fmt<F,E,P,R...>>{};
	template<u64 F,u64 E,u64 P,typename T>struct Fmt<F,E,P,T>:StrStr<Str<'%'>,I2Str<P>,StrRSan<FmtS<T>>,I2Str<E>>{};

	#define F(t,f,...) template<__VA_ARGS__>struct FmtS<t>{constexpr static auto v=f;}
	F(_*,"p",typename _);F(i8,MACRO_GET_OR_DEFAULT(SCNd8,"hhd"));F(i16,SCNd16);F(i32,SCNd32);F(i64,SCNd64);F(u8,MACRO_GET_OR_DEFAULT(SCNu8,"hhu"));F(u16,SCNu16);F(u32,SCNu32);F(u64,SCNu64);F(char,"c");F(char*,"s");F(const char*,"s");F(char[_],"s",size_t _);F(bool,MACRO_GET_OR_DEFAULT(SCNu8,"hhu"));F(f32,"f");F(f64,"lf");F(f80,"Lf");
	#undef F

	template<typename A,typename B>struct Ref{A v;B _;};
	template<>struct Ref<char**,char*>{char**_;char*v;};
}

template<u64 P=0,u64 E='\n',u64 F=' ',typename...R>__forceinline int pr(R...r){return printf(Fmt::Fmt<F,E,P,R...>::v,r...);}
template<typename...R>__forceinline int sc(R&&...r){return scanf(Fmt::Fmt<0,0,0,remove_reference_t<R>...>::v,Fmt::Ref<add_pointer_t<R>,R>{&r,r}.v...);}

template<u64 F=' ',typename...R>string spr(R...r){cbuf<E5>_;sprintf(_,Fmt::Fmt<F,0,0,R...>::v,r...);return _;}

#define forn(i,n) for(decltype((n)+0) i=0;i<(n);++i)
#define for1n(i,n) for(decltype((n)+0) i=1;i<(n);++i)
#define forab(i,a,b) for(decltype((a)+(b)) i=(a);i<=(b);++i)
#define fornd(i,n) for(auto i=(n);i--;)
#define repn(n) for(auto _=(n);_;--_)

#if defined(__x86_64__) and __GNUC__<9
#define talloc(a,n,...) __VA_ARGS__ _r_##a[n];auto*const a=_r_##a
#else
#define talloc(a,n,...) vector<__VA_ARGS__>_r_##a(n);auto*const a=_r_##a.data()
#endif

#define sca(T,...) T __VA_ARGS__;sc(__VA_ARGS__)
#define scn(a,n) do{forn(_,n){sc((a)[_]);}}while(0)
#define scnn(a,n,T) talloc(a,n,T);scn(a,n)
#define scna(a,n,T) sca(size_t,n);scnn(a,n,T)

#define prs(...) pr<0,' '>(__VA_ARGS__)
#define prn(a,n) if(n)do{forn(_,(n)-1){prs((a)[_]);}pr((a)[(n)-1]);}while(0)

#define gets(s) fgets(s,(is_same<decltype(s),decltype((s)+1)>::value)?E6:sizeof(s),stdin)

#define a first
#define b second

void FSWP(FILE*&a,FILE*&b){swap(a,b);}void FSWP(const FILE*a,const FILE*b){swap(*const_cast<FILE*>(a),*const_cast<FILE*>(b));}

#define dbug(...) if(MACRO_DEFINED(noacm))do{fflush(stdout);FSWP(stdout,stderr);pr("DBug:",__VA_ARGS__);fflush(stdout);FSWP(stdout,stderr);}while(0)
#define dbugn(a,n) if(MACRO_DEFINED(noacm))do{fflush(stdout);FSWP(stdout,stderr);pr<0,0,0>("Dbug[",n,"]: ");prn(a,n);fflush(stdout);FSWP(stdout,stderr);}while(0)

template<typename T>int scmp(T a,T b){return (*b<*a)-(*a<*b);}

#define sqsort(a,n) qsort(a,n,sizeof(*(a)),(int(*)(const void*,const void*))scmp<decltype(a+1)>)
#define tqsort(a,n,...) qsort(a,n,sizeof(*(a)),(int(*)(const void*,const void*))scmp<__VA_ARGS__*>)
#define fqsort(a,n,...) qsort(a,n,sizeof(*(a)),(int(*)(const void*,const void*))((int(*)(decltype(a+1),decltype(a+1)))(__VA_ARGS__)))

#define sbsearch(k,a,n) (decltype(a+1))bsearch(&k,a,n,sizeof(*(a)),(int(*)(const void*,const void*))scmp<decltype(a+1)>)
#define tbsearch(k,a,n,...) (decltype(a+1))bsearch(&k,a,n,sizeof(*(a)),(int(*)(const void*,const void*))scmp<__VA_ARGS__*>)
#define fbsearch(k,a,n,...) (decltype(a+1))bsearch(&k,a,n,sizeof(*(a)),(int(*)(const void*,const void*))((int(*)(decltype(&k+1),decltype(a+1)))(__VA_ARGS__)))

#define memnul(a,n) memset(a,0,(n)*sizeof(*(a)))
#define memneg(a,n) memset(a,-1,(n)*sizeof(*(a)))

template<typename T>T rrand(T a,T b){static mt19937 G(time(0));return uniform_int_distribution<T>(a,b)(G);}

#ifdef noacm
namespace Test{
	struct InputGen:public function<string()>{
		using function::function;
		template<typename F>InputGen(F f,typename enable_if<is_arithmetic<decltype(f())>::value>::type* =0,typename enable_if<is_constructible<function<decltype(f())()>,F>::value>::type* =0):function([f](){return spr(f());}){}
		template<typename S>InputGen(S&&s,typename enable_if<is_constructible<string,S>::value>::type* =0):function([s=(string)s]()mutable{string _=s;s="";return _;}){}
		template<typename T>InputGen(T x,typename enable_if<is_arithmetic<T>::value>::type* =0):InputGen(spr(x)){}
		InputGen(initializer_list<InputGen>&&v):function([Q=deque<InputGen>(v)]()mutable{string r;while(!Q.empty()&&(r=Q.front()()).empty())Q.pop_front();return r;}){}
	};

	template<size_t N=1,u64 S=' '>class Prod{
		vector<InputGen>v;
	public:
		Prod(initializer_list<InputGen>&&v):v(v){};
		auto operator()(){
			string r;
			repn(N)for(auto&f:v){
				auto _=f();
				if(_.empty())return _;
				if(!r.empty())r+=Fmt::I2Str<S>::v;
				r+=_;
			}
			return r;
		}
	};

	class Rep{
		InputGen c,o;size_t n;
	public:
		Rep(size_t n,InputGen&&f):c{},o(f),n(n){}
		auto operator()(){
			auto _=c();
			if(_.empty()^!!n)return _;
			n--;c=o;return c();
		}
	};

	class Range{
		i64 n,a,d;
	public:
		Range(i64 n,i64 a=1,i64 d=1):n(n),a(a),d(d){}
		auto operator()(){
			if(!n)return""s;
			auto _=spr(a);
			n--;a+=d;return _;
		}
	};

	bool Log;map<void*,pair<string,string>>BM;u32 No;
	int Input(void*_,char*b,int n){
		auto& G=*(InputGen*)_;auto& B=BM[_];int r=0;
		for(;;){
			if (!B.a.empty()) {
				if ((int)B.a.length()<n-r) {
					memcpy(b+r,B.a.data(),B.a.length());
					r+=B.a.length();B.a="";
				}else{
					memcpy(b+r,B.a.data(),n-r);
					B.a.erase(0,n-r);
					Log=Log||fprintf(stderr,"\n\nTest input data:\n###\n%.*s...\n###\n\n", min(n,253), b);
					B.b+={b,(size_t)n};
					return n;
				}
			}
			B.a=G();
			if (B.a.empty()) {
				Log=Log||fprintf(stderr,"\n\nTest input data:\n###\n%.*s%s\n###\n\n", min(r,253), b, (253<r) ? "..." : "");
				B.b+={b,(size_t)r};
				return r;
			}
			B.a+='\n';
		}
	}

	int Output(void*s,const char*b,int n){*(string*)s+={b,(size_t)n};return n;}

	class InputGenIter:public iterator<input_iterator_tag,string>{
		InputGen g;FILE*f;cbuf<E5>s;
	public:
		InputGenIter():g(""),f(0){*s=0;}
		InputGenIter(InputGen g):g(g),f(fropen(&g,Input)){++*this;}
		~InputGenIter(){f&&fclose(f);}
		InputGenIter&operator++(){fscanf(f,"%s",s)>0||(*s=0);return*this;}
		string operator*(){return s;}
		bool operator!=(InputGenIter&o){return*s||*o.s;}bool operator==(InputGenIter&o){return!*s&&!*o.s;}
	};

	struct Checker:public function<bool(string,string)>{
		using function::function;
		template<typename T>Checker(T t,typename enable_if<is_constructible<InputGen,T>::value>::type* =0):function([I=InputGen(t)](string,string o){return equal(InputGenIter(I),{},InputGenIter(o),{});}){}
		template<typename F>Checker(F f,typename enable_if<is_same<void,decltype(f())>::value>::type* =0):function([f](string i,string o){InputGen Q{i};i="";auto I=fropen(&Q,Input),O=fwopen(&i,Output);FSWP(I,stdin);FSWP(O,stdout);f();fflush(stdout);FSWP(I,stdin);FSWP(O,stdout);fclose(I);fclose(O);return equal(InputGenIter(i),{},InputGenIter(o),{});}){}
		template<typename F>Checker(F f,typename enable_if<is_same<Bool,decltype(f())>::value>::type* =0):function([f](string,string o){InputGen Q{o};auto I=fropen(&Q,Input);FSWP(I,stdin);bool r=f();FSWP(I,stdin);fclose(I);return r;}){}
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
	if(MACRO_DEFINED(acm_files)){freopen(acm_in,"r",stdin);freopen(acm_out,"w",stdout);}
	solve();
	if(MACRO_DEFINED(acm_files)){fclose(stdin);fflush(stdout);fclose(stdout);}
	#else
	

	TESTIO(STR(
		6
		5 -1000 1 -3 7 -8
	),16);
	TESTIO(STR(
		5
		1000 1000 1001 1000 1000
	),15003);
	TESTIO(STR(
		3
		-60 -70 -80
	),0);
	TESTIO(
		{8,
		100,100,100,100,-2,0,0,1},
		1000
	);
	#endif
}

void solve(){
	

	scna(a,n,i32);
	i64 ans=0,sum=0,score=0,smin=0,smsum=0;
	
	talloc(v,n,map<i64,i64>);
	
	fornd(i,n){
		sum+=a[i];
		score+=sum;
		
		smin+=smsum;
		
		if(score<smin || (score==smin && sum<smsum)){
			smin=score;
			smsum=sum;
		}else if(sum<smsum){
			auto d=(score-smin);
			auto r=(smsum-sum);
			auto t=(d+r-1)/r;
			dbug('t',t,score*sum+t,sum);
			
			if(t<=i){
				auto nscore=score+sum*t;
				v[i-t][nscore]=min(v[i-t][nscore],sum);
			}
		}
		
		for(auto x:v[i]){
			if(x.a>=smin && x.b>=smsum){
				continue;
			}
			
			if(x.a<=smin && x.b<=smsum){
				smin=x.a;
				smsum=x.b;
			}else if(x.a<=smin){
				auto d=(smin-x.a);
				auto r=(x.b-smsum);
				auto t=(d+r-1)/r;
				
				if(t<=i){
					auto nscore=smin+smsum*t;
					v[i-t][nscore]=min(v[i-t][nscore],smsum);
				}
				
				smin=x.a;
				smsum=x.b;
			}else{
				auto d=(x.a-smin);
				auto r=(smsum-x.b);
				auto t=(d+r-1)/r;
				
				if(t<=i){
					auto nscore=x.a+x.b*t;
					v[i-t][nscore]=min(v[i-t][nscore],x.b);
				}
			}
		}
		
		ans=max(ans,score-smin);
		
		dbug(sum,score,smin);
	}
	pr(ans);
}
