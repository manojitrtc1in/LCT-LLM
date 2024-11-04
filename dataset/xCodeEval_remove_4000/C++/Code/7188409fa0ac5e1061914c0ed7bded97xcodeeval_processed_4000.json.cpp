



































using namespace std;






using i8=int8_t;using u8=uint8_t;using i16=int16_t;using u16=uint16_t;using i32=int32_t;using u32=uint32_t;using i64=int64_t;using u64=uint64_t;using f32=float;using f64=double;using f80=long double;
template<size_t n>using cbuf=char[n];
enum Bool:u8{False,True};
[[maybe_unused]] const u32 E9=1e9,E8=1e8,E7=1e7,E6=1e6,E5=1e5,E4=1e4,E3=1e3,E2=1e2;










namespace Fmt{
	template<u8...r>struct Str{static constexpr cbuf<sizeof...(r)+1>v={r...,'\0'};};template<u8...r>constexpr cbuf<sizeof...(r)+1>Str<r...>::v;

	template<u64 n,u8...r>struct I2Str:I2Str<(n>>8),(u8)n,r...>{};template<u8...r>struct I2Str<0,r...>{using S=Str<r...>;};

	template<class A,class B>struct StrStrImpl{};template<u8...u,u8...v>struct StrStrImpl<Str<u...>,Str<v...>>{using S=Str<u...,v...>;};
	template<class F,class...R> struct StrStr:StrStrImpl<typename F::S,typename StrStr<R...>::S>{};template<class S>struct StrStr<S>:S{};

	template<class T,class F=void>struct FmtS;
	
	F((0?"":is_signed<T>()?SCNd16:SCNu16),sizeof(T)==2&&is_integral<T>);F((0?"":is_signed<T>()?SCNd32:SCNu32),sizeof(T)==4&&is_integral<T>);F((0?"":is_signed<T>()?SCNd64:SCNu64),sizeof(T)==8&&is_integral<T>);F("f",is_same<T,f32>);F("lf",is_same<T,f64>);F("Lf",is_same<T,f80>);F((is_same<char,T>()?"c":is_signed<T>()?GET_OR_DEFAULT(SCNd8,"hhd"):GET_OR_DEFAULT(SCNu8,"hhu")),sizeof(T)==1&&is_integral<T>);F((0?"":is_same<char,decay_t<remove_pointer_t<T>>>()?"s":"p"),is_pointer<T>);
	

	template<u64 f,u64 e,u64 p,class T,class...R>struct Fmt:StrStr<I2Str<'%'>,I2Str<p>,FmtS<T>,StrStr<I2Str<f>,I2Str<'%'>,I2Str<p>,FmtS<R>>...,I2Str<e>>::S{};

	template<class A,class B>struct Ref{A v;B _;};template<>struct Ref<char**,char*>{char**_;char*v;};
}

template<u64 f=' ',class...R>string spr(R...r){cbuf<E5>_;sprintf(_,Fmt::Fmt<f,0,0,R...>::v,r...);return _;}
void fswp(FILE*&a,FILE*&b){swap(a,b);}void fswp(const FILE*a,const FILE*b){swap(*const_cast<FILE*>(a),*const_cast<FILE*>(b));}

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
					Log=Log||fprintf(stderr,"\n\nTest input data:\n
					B.b+={b,(size_t)n};return n;
				}
			}
			B.a=G();
			if(B.a.empty()){
				Log=Log||fprintf(stderr,"\n\nTest input data:\n
				B.b+={b,(size_t)r};return r;
			}
			B.a+='\n';
		}
	}

	int Output(void*s,const char*b,int n){*(string*)s+={b,(size_t)n};return n;}

	class id0:public iterator<input_iterator_tag,string>{
		InputGen g;shared_ptr<FILE>f;cbuf<E5>s;
	public:
		id0():g{}{*s=0;}
		id0(InputGen _):g(_),f(fropen(&g,Input),fclose){++*this;}
		id0&operator++(){fscanf(f.get(),"%s",s)>0||(*s=0);return*this;}
		string operator*(){return s;}
		bool operator!=(id0&o){return*s|*o.s;}bool operator==(id0&o){return!*s&!*o.s;}
	};

	struct Checker:public function<bool(string,string)>{
		using function::function;
		template<class T>Checker(T t,typename enable_if<!!is_constructible<InputGen,T>()>::type* =0):function([I=InputGen(t)](string,string o){return equal(id0(I),{},id0(o),{});}){}
		template<class F>Checker(F f,typename enable_if<!!is_same<void,decltype(f())>()>::type* =0):function([f](string i,string o){InputGen Q{i};i="";auto I=fropen(&Q,Input),O=fwopen(&i,Output);fswp(I,stdin);fswp(O,stdout);f();fflush(stdout);fswp(I,stdin);fswp(O,stdout);fclose(I);fclose(O);return equal(id0(i),{},id0(o),{});}){}
		template<class F>Checker(F f,typename enable_if<!!is_same<Bool,decltype(f())>()>::type* =0):function([f](string,string o){InputGen Q{o};auto I=fropen(&Q,Input);fswp(I,stdin);bool r=f();fswp(I,stdin);fclose(I);return r;}){}
	};
}





void solve();






template<u64 p=0,u64 e='\n',u64 f=' ',class...R>__forceinline int pr(R...r){return printf(Fmt::Fmt<f,e,p,R...>::v,r...);}
template<class...R>__forceinline int sc(R&&...r){return scanf(Fmt::Fmt<0,0,0,decay_t<R>...>::v,Fmt::Ref<add_pointer_t<R>,R>{&r,r}.v...);}














template<class T>int scmp(T a,T b){return (*b<*a)-(*a<*b);}













template<class T>T rrand(T a,T b){static mt19937 G(time(0));return uniform_int_distribution<T>(a,b)(G);}






int main(){
	
	if(DEFINED(acm_files)){freopen(acm_in,"r",stdin);freopen(acm_out,"w",stdout);}
	solve();
	if(DEFINED(acm_files)){fclose(stdin);fflush(stdout);fclose(stdout);}
	
	

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
		dbug("
	}
}
