













































































































              (__GNUC__ == (a) && (__GNUC_MINOR__ > (b) || \
                                 (__GNUC_MINOR__ == (b) && \
								 __GNUC_PATCHLEVEL__ >= (c)))))















































const char NL='\n';
const char SP=' ';


















typedef unsigned int uint;

typedef int8_t i8;
typedef uint8_t ui8;
typedef int16_t i16;
typedef uint16_t ui16;
typedef int32_t i32;
typedef uint32_t ui32;
typedef int64_t i64;
typedef uint64_t ui64;



typedef i64 ll;
typedef ui64 ull;

typedef std::pair<i32,i32> pii;
typedef std::pair<double,double> pdd;

typedef std::vector<i32> vi;







typedef unsigned short ushort;
typedef unsigned char uchar;


template<class T> using sptr = std::shared_ptr<T>;
template<class T> using uptr = std::unique_ptr<T>;
template<class A, class B> using p = std::pair<A, B>;



namespace ab{

struct Void {};




template<typename I>struct FloatFrom{typedef Void R;};
template<>struct FloatFrom<i32>{typedef double R;};
template<>struct FloatFrom<ui32>{typedef double R;};
template<>struct FloatFrom<i64>{typedef long double R;};
template<>struct FloatFrom<ui64>{typedef long double R;};
template<>struct FloatFrom<i16>{typedef float R;};
template<>struct FloatFrom<ui16>{typedef float R;};
template<>struct FloatFrom<i8>{typedef float R;};
template<>struct FloatFrom<ui8>{typedef float R;};
template<>struct FloatFrom<float>{typedef float R;};
template<>struct FloatFrom<double>{typedef double R;};
template<>struct FloatFrom<long double>{typedef long double R;};



template<typename I>struct Double{typedef Void R;};
template<>struct Double<i8>{typedef i16 R;};
template<>struct Double<ui8>{typedef ui16 R;};
template<>struct Double<i16>{typedef i32 R;};
template<>struct Double<ui16>{typedef ui32 R;};
template<>struct Double<i32>{typedef i64 R;};
template<>struct Double<ui32>{typedef ui64 R;};

template<>struct Double<float>{typedef float R;};
template<>struct Double<double>{typedef double R;};
template<>struct Double<long double>{typedef long double R;};




typedef __int128_t i128;
typedef __uint128_t ui128;
template<>struct Double<i64>{typedef i128 R;};
template<>struct Double<ui64>{typedef ui128 R;};



}






	
	

	
		
	
		inline int id0(__int64 a){ return __builtin_popcount((ui32)a) + __builtin_popcount(a >> 32); }
	






	
	
	



namespace ab{

template<class T>inline T id3(T x,int i){return (x<<i) ^ (x>>(sizeof(T)*8-i));} 

inline int popcount(uint i){return __builtin_popcount(i);}
inline int popcount(ull i){return id0(i);}


inline int parity(uint i){return __builtin_parity(i);}
inline int parity(ull i){return __builtin_parityll(i);}
inline int ilog2(uint i){return 31-__builtin_clz(i);} 

inline int ilog2(ull i){return 63-__builtin_clzll(i);}



template<class T>inline bool id1(const T&x){return !(x&(x-1));}



struct Static{
	Static() = default;
	Static(const Static&) = delete;
	Static(Static&&) = delete;
	Static(const Static&&) = delete;
	Static& operator=(const Static&) = delete;
	Static& operator=(Static&&) = delete;
	Static& operator=(const Static&&) = delete;
};



}







































	
	


	
	
	








































	
	

namespace std{
	template<class T>
	inline string to_string(const T& t){
		stringstream ss;
		ss << t;
		return ss.str();
	}
}



namespace ab{










class Log{
public:
	enum{
		DEBUG = 5000,
		INFO = 4000, 

		WARNING = 3000,
		ERROR = 2000,
		FAIL = 1000};

public:
	void debug(const std::string& _message, const std::string& file="", int line=0){
		message(DEBUG, _message, file, line);
	}
	void info(const std::string& _message, const std::string& file = "", int line = 0){
		message(INFO, _message, file, line);
	}
	void warning(const std::string& _message, const std::string& file = "", int line = 0){
		message(WARNING, _message, file, line);
	}
	void error(const std::string& _message, const std::string& file = "", int line = 0){
		message(ERROR, _message, file, line);
	}
	void fail(const std::string& _message, const std::string& file = "", int line = 0){
		message(FAIL, _message, file, line);
	}

	

	void flushConsole(){
		

		

		static const uint id2 = 128;
		std::vector<Message> messages_copy;
		{
			std::lock_guard<std::mutex> lock(mut);
			messages_copy.assign(messages.begin() + numPrinted, messages.begin() + numPrinted + std::min(id2, messages.size() - numPrinted));
		}

		for (uint i = 0; i < messages_copy.size(); ++i){
			std::cout << messageToString(messages_copy[i]) << '\n';
		}
		std::cout.flush();

		numPrinted += messages_copy.size();
	}

	void message(int level, const std::string& messageText, const std::string& file = "", int line = 0){

		
			if (level >= DEBUG) return;
		
		
		std::lock_guard<std::mutex> lock(mut);

		messages.push_back(Message{ level, messageText, file, line });

		
			if (level <= ERROR){
				
					__debugbreak();
				
				
					__builtin_trap();
				
			}
		

	}


	

	static Log*& global(){
		static Log* log = nullptr;
		return log;
	}

public:
	Log(){
		levelNames[DEBUG] = "DEBUG";
		levelNames[INFO] = "INFO";
		levelNames[WARNING] = "WARNING";
		levelNames[ERROR] = "ERROR";
		levelNames[FAIL] = "FAIL";
	}
	~Log(){
		if (filename != ""){
			std::ofstream os(filename);
			for (auto&m : messages){
				os << messageToString(m) << '\n';
			}
		}
	}

private:
	struct Message{
		int level;
		std::string text;
		std::string file;
		int line;
	};
	
	static std::string shortenPath(const std::string& s){
		std::string result = s;
		std::string ss[] = {"include/", "include\\", "src/", "src\\"};
		for(uint i=0; i<sizeof(ss)/sizeof(std::string); ++i){
			auto pos = result.rfind(ss[i]);
			if(pos == std::string::npos) continue;
			
			result = result.substr(pos + ss[i].size(), std::string::npos);
		}
		return result;
	}

	std::string messageToString(const Message& m) const {
		std::string levelName;
		auto r = levelNames.find(m.level);
		if (r == levelNames.end()) levelName = std::to_string(m.level);
		else levelName = r->second;
		std::string result = levelName + ": " + m.text;
		if (m.file != "") result += " at " + shortenPath(m.file) + ":" + std::to_string(m.line);
		return result;
	}

	uint numPrinted = 0;
	std::vector<Message> messages;
	std::mutex mut; 


	std::unordered_map<int, std::string> levelNames;
	std::string filename = "atablash.log";

private:
	Log(const Log&) = delete;
	Log& operator=(const Log&) = delete;
};










}





inline void breakpoint(){}

	


	




	
	
	

	
	
	
	







	
	
		
		
		
		
		
		
		
		
		
		inline void ec(int a){static HANDLE h=GetStdHandle(-12);SetConsoleTextAttribute(h,a?12:0xf);}	

		inline void oc(int a){static HANDLE h=GetStdHandle(-11);SetConsoleTextAttribute(h,a?10:0xf);}	

	
		

	

	
	





struct _E{template<class T>_E&operator<(const T&_t){DE{ec(1);std::cerr<<_t;ec(0);}return*this;}};






	
	



static _E E;


	








	template<class T>void id4(){(void)E;}

















namespace std{



namespace __gnu_cxx{









 template<class A,class B>struct hash<std::map<A,B> >{
    size_t operator()(const std::map<A,B>& m) const{
        size_t r = m.size();
        if(!r)return 0;
        __typeof(m.begin()) i=m.be;
        r^=hash<__typeof(i)>()(i);
        ++i;
        r^=id3(hash<__typeof(i)>()(*i),sizeof(r)*8/4);
        i=m.end();
        --i;
        r^=id3(hash<__typeof(i)>()(*i),sizeof(r)*8/2);
        return r;
    }
};





 template<class A, class B>struct hash<pair<A,B> >{
    size_t operator()(const pair<A,B>& p) const{
        return hash<A>()(p.first) ^ ab::id3(hash<B>()(p.second),sizeof(size_t)*8/2);
    }
};










template<class E> struct hash {
    using sfinae = typename std::enable_if<std::is_enum<E>::value, E>::type;
public:
    size_t operator()(const E&e) const {
      return std::hash<typename std::underlying_type<E>::type>()((typename std::underlying_type<E>::type)e);
    }
};

  
} 











template<class A, class B, class C, class D>
inline std::pair<A,B>& operator+=(std::pair<A,B>& p, const std::pair<C,D>& o){
	p.first+=o.first;
	p.second+=o.second;
	return p;
}
template<class A, class B, class C, class D>
inline std::pair<A,B>& operator-=(std::pair<A,B>& p, const std::pair<C,D>& o){
	p.first-=o.first;
	p.second-=o.second;
	return p;
}
template<class A, class B, class C, class D>
inline std::pair<A,B>& operator*=(std::pair<A,B>& p, const std::pair<C,D>& o){
	p.first*=o.first;
	p.second*=o.second;
	return p;
}
template<class A, class B, class C, class D>
inline std::pair<A,B>& operator/=(std::pair<A,B>& p, const std::pair<C,D>& o){
	p.first/=o.first;
	p.second/=o.second;
	return p;
}

template<class Afi, class Ase, class Bfi, class Bse>
inline std::pair<decltype(Afi() + Bfi()), decltype(Ase() + Bse())>&
operator+(const std::pair<Afi,Ase>& a, const std::pair<Bfi,Bse>& b){
	return std::make_pair(a.fi+b.fi, a.se+b.se);
}
template<class Afi, class Ase, class Bfi, class Bse>
inline std::pair<decltype(Afi() - Bfi()), decltype(Ase() - Bse())>&
operator-(const std::pair<Afi,Ase>& a, const std::pair<Bfi,Bse>& b){
	return std::make_pair(a.fi-b.fi, a.se-b.se);
}
template<class Afi, class Ase, class Bfi, class Bse>
inline std::pair<decltype(Afi()*Bfi()), decltype(Ase()*Bse())>&
operator*(const std::pair<Afi,Ase>& a, const std::pair<Bfi,Bse>& b){
	return std::make_pair(a.fi*b.fi, a.se*b.se);
}
template<class Afi, class Ase, class Bfi, class Bse>
inline std::pair<decltype(Afi() / Bfi()), decltype(Ase() / Bse())>&
operator/(const std::pair<Afi,Ase>& a, const std::pair<Bfi,Bse>& b){
	return std::make_pair(a.fi/b.fi, a.se/b.se);
}










template<class T, class U>
inline std::vector<T>& operator+=(std::vector<T>& v, const std::vector<U>& o){
	ASS(v.siz == o.siz);
	FOR(i,v.siz) v[i] += o[i];
	return v;
}


template<class T>
inline std::vector<T>& operator*=(std::vector<T>& v, const T& a){
	FOR(i,v.siz) v[i] *= a;
	return v;
}







template<class A,class B>inline std::ostream&operator<<(std::ostream&o,const std::pair<A,B>&p){o<<'<'<<p.first<<", "<<p.second<<'>';return o;}
template<class A,class B>inline std::ostream&operator<<(std::ostream&o,const std::map<A,B>&m){o<<'\n';FE(k,m)o<<"map["<<k->first<<"] -> "<<k->se<<'\n';return o;}
template<class A>inline std::ostream&operator<<(std::ostream&o,const std::vector<A>&_v){o<<'\n';FOR(i,_v.sz)o<<"vector["<<i<<"] = "<<_v[i]<<'\n';return o;}






















	























using namespace std;
using namespace __gnu_cxx;

namespace ab{}
using namespace ab;





template<class T>inline void sortu(T& t){t.resize(std::unique(ALL(t))-t.be);}


inline uint _rand(){
	if(RAND_MAX < (1<<15)) return (rand()<<15) | rand();
	else return rand();
}











inline void _fin(int){}
inline void _fout(int){}

inline int _rint(){int r;cin>>r;return r;}
inline uint _ruint(){uint r;cin>>r;return r;}
inline ull _rull(){ull r;cin>>r;return r;}
inline ll _rll(){ll r;cin>>r;return r;}
inline char _rchar(){return cin.get();}
inline string _rstr(){string s;cin>>s;return s;}
template<typename T>inline void W(const T& i){cout<<i; cout.flush();}
inline void W(){W('\n');}

inline int _rint(){int r;scanf("%d",&r);return r;}
inline uint _ruint(){uint r;scanf("%u",&r);return r;}
inline ull _rull(){ull r;scanf("%" SCNu64,&r);return r;}
inline ull _rll(){ll r;scanf("%" SCNd64,&r);return r;}
inline char _rchar(){return getchar();}
inline string _rstr(){
	string s;
	char c=rchar;
	while(c!=-1 && !isgraph(c))c=rchar;
	for(;;){
		if(!isgraph(c))break;
		s+=c;
		c=rchar;
	}
	return s;
}
inline void W(char a='\n'){printf("%c",a);}
inline void W(const string&s){printf("%s",s.c_str());}
inline void W(int a){printf("%d",a);}
inline void W(uint a){printf("%u",a);}
inline void W(const ui64& a){printf("%" PRIu64,a);}
inline void W(const i64& a){printf("%" PRIi64,a);}
inline void W(const char *str){fputs(str,stdout);}
inline void W(const double& d){printf("%.20f",d);}
inline void W(const long double& d){printf("%.50Lf",d);}













const int _IB=32768;const int _OB=32768;
char _iB[_IB];int _iP = _IB;
char _oB[_OB];int _oP = 0;
inline void _fin(int mc){
	int r=_IB-_iP;
	if(r>mc)return;
	F(i,r) _iB[i]=_iB[i+_iP];	

    int rd=FREAD(_iB+r,1,_iP,stdin);
	if(rd!=_iP) _iB[r+rd]=0;
	_iP = 0;
}
inline void _fout(int mc){
	if(_OB-_oP>mc)return;
	FWRITE(_oB,1,_oP,stdout);
	_oP = 0;
}
inline void _W(char c='\n'){_oB[_oP++]=c;} 

inline char _rc(){return _iB[_iP++];}
inline char _rchar(){_fin(1);return _rc();}
inline string _rstr(){
	string s;
	for(;;){
		char c=rchar;
		if(!isprint(c)||isspace(c))break;
		s+=c;
	}
	return s;
}
template<class T>inline T _rur(){ 

    T r=0;char c=_rc();
    do c-='0',r=r*10+c,c=_rc();while(c>='0');
    return r;}
template<class T>inline T _rsi(){ 

	char c=_rc();
	while(c<'-')c=_rc();
	if(c=='-')return -_rur<T>();
	else{--_iP;return _rur<T>();}}
template<class T>inline T _ru(){  

	while(_rc()<'0');--_iP;
	return _rur<T>();
}

inline int _rint(){_fin(15);return _rsi<int>();}
inline uint _ruint(){_fin(15);return _ru<uint>();}
inline ll _rll(){_fin(25);return _rsi<ll>();}
inline ull _rull(){_fin(25);return _ru<ull>();}

const int _rs = 20; char _r[_rs];
template<class T>inline void _w(T i){	

	if(numeric_limits<T>::is_signed and i<0) _W('-'), i=-i;
	else if(i==0){_W('0'); return;}
	int pos = _rs;
	do _r[--pos]='0'+i%10, i/=10; while(i);
	do _W(_r[pos++]); while(pos<_rs);
}
inline void W(const char c){_fout(2);_W(c);}
inline void W(const int32_t& i){_fout(15);_w(i);}
inline void W(const uint32_t& i){_fout(15);_w(i);}
inline void W(const int64_t& i){_fout(25);_w(i);}
inline void W(const uint64_t& i){_fout(25);_w(i);}
inline void W(const char*str, int l){
	for(int b=0; b<l; b+=_OB){
		int num = min(_OB,l-b);
		_fout(num);
		memcpy(&_oB[_oP], str+b, num);
		_oP+=num;
	}
}
inline void W(const char*str){W(str,strlen(str));}
inline void W(const string&s){W(s.c_str(),s.siz);}
inline void W(double d){_fout(50);_oP+=sprintf(&_oB[_oP],"%.20f",d);}	


template<class A,class B>inline void W(const A&a,const B&b){W(a);W(b);}
template<class A,class B,class C>
inline void W(const A&a,const B&b,const C&c){W(a);W(b);W(c);}
template<class A,class B,class C,class DD>
inline void W(const A&a,const B&b,const C&c,const DD&dd){W(a);W(b);W(c);W(dd);}
template<class T>inline void sortall(T&t){sort(t.be,t.en);}
template<class T>inline void uniqall(T&t){t.resize(unique(t.be,t.en)-t.be);}





inline uint knext(uint a){uint b=(a|(a-1))+1;return b|((a^b)>>(__builtin_ctz(a)+2));}


struct _O{template<class T>_O&operator<(const T&_t){
		oc(1);W(_t);oc(0);
		return *this;
}}O;

struct _I{
	_I&operator>(int32_t&_t){_t=ri;return*this;}
	_I&operator>(uint32_t&_t){_t=rui;return*this;}
	_I&operator>(int64_t&_t){_t=rll;return*this;}
	_I&operator>(uint64_t&_t){_t=rull;return*this;}
	_I&operator>(char&_t){_t=rchar;return*this;}
	_I&operator>(string&_t){_t=rstr;return*this;}
}I;




inline void tc();

int argc;  char **argv;
int main(int _argc, char *_argv[]){
	argc = _argc;  argv = _argv;
	if(argc<2){
		O < "Usage: " < argv[0] < " NR_TESTU" < N;
		return 1;
	}
	srand(atoi(argv[1]));

int main(){



    setvbuf(stdin,0,_IONBF,0);setvbuf(stdout,0,_IONBF,0);

	ios_base::sync_with_stdio(0);cout.precision(10);cout.setf(ios::fixed,ios::floatfield);
	
	cin.tie(0);
	




	ec(0);
	oc(0);





	

	int nz=rui;F(i,nz)

	tc();

    FWRITE(_oB,1,_oP,stdout);

	return 0;
}



















































inline void tc(){
	int x,y;
	I>x>y;
	
	int xx = x + y;
	
	int ile = xx / (2*y);
	
	if(ile == 0){
		O < -1 < NL;
		return;
	}
	
	double result = 1.0*xx / ile;
	result *= 0.5;
	
	O<result<NL;
}