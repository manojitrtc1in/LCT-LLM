



















































































namespace ab{

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

typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;

struct VOID {};


template<typename I>struct FloatFrom{typedef VOID R;};
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

template<typename I>struct Double{typedef VOID R;};
template<>struct Double<i8>{typedef i16 R;};
template<>struct Double<ui8>{typedef ui16 R;};
template<>struct Double<i16>{typedef i32 R;};
template<>struct Double<ui16>{typedef ui32 R;};
template<>struct Double<i32>{typedef i64 R;};
template<>struct Double<ui32>{typedef ui64 R;};

template<>struct Double<float>{typedef float R;};
template<>struct Double<double>{typedef double R;};
template<>struct Double<long double>{typedef long double R;};



typedef int128_t i128;
typedef uint128_t ui128;
template<>struct Double<i64>{typedef i128 R;};
template<>struct Double<ui64>{typedef ui128 R;};



}














inline void ec(int a){static HANDLE h=GetStdHandle(-12);SetConsoleTextAttribute(h,a?12:0xf);}
inline void oc(int a){static HANDLE h=GetStdHandle(-11);SetConsoleTextAttribute(h,a?10:0xf);}







































              (__GNUC__ == (a) && (__GNUC_MINOR__ > (b) || \
                                 (__GNUC_MINOR__ == (b) && \
                                  __GNUC_PATCHLEVEL__ >= (c)))))
								  



















































const char N='\n';
const char S=' ';

using namespace std;
using namespace __gnu_cxx;

namespace ab{}
using namespace ab;



template<class T>inline T id1(T x,int i){return (x<<i) ^ (x>>(sizeof(T)*8-i));}

namespace std{





template<class T>struct hash<T>{}




template<>template<class A,class B>struct hash<map<A,B>>{
    size_t operator()(const map<A,B>& m) const{
        size_t r = m.size();
        if(!r)return r;
        auto i=m.be;
        r^=hash<type(i)>()(i);
        ++i;
        r^=id1(hash<type(i)>()(*i),sizeof(r)*8/4);
        i=m.end();
        --i;
        r^=id1(hash<type(i)>()(*i),sizeof(r)*8/2);
        return r;
    }
};
template<>template<class A, class B>struct hash<pair<A,B>>{
    size_t operator()(const pair<A,B>& p) const{
        return hash<A>()(p.first) ^ id1(hash<B>()(p.second),sizeof(size_t)*8/2);
    }
};
}








inline void fin(int){}inline void fout(int){}

inline int _rint(){int r;cin>>r;return r;}
inline uint _ruint(){uint r;cin>>r;return r;}
inline ull _rull(){ull r;cin>>r;return r;}
inline char _rchar(){return cin.get();}
template<typename T>inline void W(const T& i){cout<<i;}
inline void W(){W('\n');}

inline int _rint(){int r;scanf("%d",&r);return r;}
inline uint _ruint(){uint r;scanf("%u",&r);return r;}
inline ull _rull(){ull r;scanf("%llu",&r);return r;}
inline ull _rll(){ll r;scanf("%lld",&r);return r;}
inline char _rchar(){return getchar();}
inline void W(char a='\n'){printf("%c",a);}
inline void W(int a){printf("%d",a);}
inline void W(uint a){printf("%u",a);}
inline void W(const ull& a){printf("%llu",a);}
inline void W(const ll& a){printf("%lld",a);}
inline void W(const char *str){fputs(str,stdout);}
inline void W(const double& d){printf("%.20f",d);}
inline void W(const long double& d){printf("%.50Lf",d);}













const int _IB=32768;const int _OB=32768;
char _iB[_IB];int _iP = _IB;char _oB[_OB];int _oP = 0;
inline void fin(int mc){int r=_IB-_iP;if(r>mc)return;fo(i,r)_iB[i]=_iB[i+_iP];	

    FREAD(_iB+r,1,_iP,stdin);_iP = 0;}
inline void fout(int mc){if(_OB-_oP>mc)return;FWRITE(_oB,1,_oP,stdout);_oP = 0;}
inline void W(char c='\n'){_oB[_oP++]=c;}
inline char _rchar(){return _iB[_iP++];}
template<class T>inline T _rur(){
    T r=0;char c=rchar;
    do c-='0',r=r*10+c,c=rchar;while(c>='0');
    return r;}
template<class T>inline T _rsi(){
	char c=rchar;
	while(c<'-')c=rchar;
	if(c=='-')return -_rur<T>();
	else{--_iP;return _rur<T>();}}
template<class T>inline T _ru(){while(rchar<'0');--_iP;return _rur<T>();}

inline int _rint(){fin(15);return _rsi<int>();}
inline uint _ruint(){fin(15);return _ru<uint>();}
inline ll _rll(){fin(25);return _rsi<ll>();}
inline ull _rull(){fin(25);return _ru<ull>();}

const int _rs = 20;char _r[_rs];
template<class T>inline void _w(T i){
	if(numeric_limits<T>::is_signed && i<0)W('-'),i=-i;
	else if(i==0){W('0');return;}
	int pos = _rs;
	do{_r[--pos]='0'+i%10;i/=10;}while(i);
	do W(_r[pos]),++pos;while(pos<_rs);}
inline void W(const int32_t& i){fout(15);_w(i);}
inline void W(const uint32_t& i){fout(15);_w(i);}
inline void W(const int64_t& i){fout(25);_w(i);}
inline void W(const uint64_t& i){fout(25);_w(i);}
inline void W(const char*str){int l=strlen(str);fout(l);memcpy(&_oB[_oP],str,l);_oP+=l;}
inline void W(double d){fout(50);_oP+=sprintf(&_oB[_oP],"%.20f",d);}	


template<class A,class B>inline void W(const A&a,const B&b){W(a);W(b);}
template<class A,class B,class C>
inline void W(const A&a,const B&b,const C&c){W(a);W(b);W(c);}
template<class A,class B,class C,class DD>
inline void W(const A&a,const B&b,const C&c,const DD&dd){W(a);W(b);W(c);W(dd);}
template<class T>inline void sortall(T&t){sort(t.be,t.en);}
template<class T>inline void uniqall(T&t){t.resize(unique(t.be,t.en)-t.be);}

inline int count1(uint i){return __builtin_popcount(i);}
inline int count1(ull i){return __builtin_popcountll(i);}
inline int parity(uint i){return __builtin_parity(i);}
inline int parity(ull i){return __builtin_parityll(i);}
inline int ilog(uint i){return 31-__builtin_clz(i);} 

inline int ilog(ull i){return 63-__builtin_clzll(i);}




inline uint knext(uint a){uint b=(a|(a-1))+1;return b|((a^b)>>(__builtin_ctz(a)+2));}



template<class A,class B>inline ostream&operator<<(ostream&o,const pair<A,B>&p){o<<'<'<<p.fi<<", "<<p.se<<'>';return o;}
template<class A,class B>inline ostream&operator<<(ostream&o,const map<A,B>&m){o<<N;for(auto&k:m)o<<"map["<<k.fi<<"] -> "<<k.se<<N;return o;}
template<class A>inline ostream&operator<<(ostream&o,const vector<A>&_v){o<<N;fo(i,_v.sz)o<<"vector["<<i<<"] = "<<_v[i]<<N;return o;}

struct _O{template<class T>_O&operator<(const T&t){oc(1);W(t);oc(0);return*this;}}O;
struct _I{
	_I&operator>(int32_t&t){t=rint;return*this;}
	_I&operator>(uint32_t&t){t=ruint;return*this;}
	_I&operator>(int64_t&t){t=rll;return*this;}
	_I&operator>(uint64_t&t){t=rull;return*this;}
}I;

struct _E{template<class T>_E&operator<(const T&t){D{ec(1);cerr<<t;ec(0);}return*this;}}E;



inline void tc();
int main()
{

    setvbuf(stdin,0,_IONBF,0);setvbuf(stdout,0,_IONBF,0);

	ios_base::sync_with_stdio(0);cin.tie(0);cout.precision(99);cout.setf(ios::fixed,ios::floatfield);




	ec(0);
	oc(0);





	

	int nz=rint;fo(i,nz)

	tc();

    FWRITE(_oB,1,_oP,stdout);

	return 0;
}







int tab[2][100009];

ll sums[2][100009];

inline void tc()
{
	int nm[2];
	I>nm[0]>nm[1];
	
	fo(k,2)fo(i,nm[k]) I>tab[k][i];
	
	fo(k,2)sort(tab[k], tab[k]+nm[k]);
	
	fo(k,2)fo(i,1,nm[k]+1) sums[k][i] = sums[k][i-1] + tab[k][i-1];
	
	ll wynik = id0;
	
	

	

	
	fo(i,nm[0]){
		E<N;
		ll m = (ll)tab[0][i]*i - sums[0][i];
		E<tab[0][i-1]*i<N;
		E<"inc "<m<N;
		int ith = lb(tab[1], tab[1]+nm[1], tab[0][i]) - tab[1];
		E<"ith "<ith<N;
		
		m += sums[1][nm[1]] - sums[1][ith] - (ll)(nm[1]-ith)*tab[0][i];
		
		E<"cand for index "<i<"   "<m<N;
		wynik = min(wynik,m);
	}
	
	fo(k,2)fo(i,nm[k]+1)tab[k][i]*=-1;
	
	fo(k,2)sort(tab[k], tab[k]+nm[k]);
	
	fo(k,2)fo(i,1,nm[k]+1) sums[k][i] = sums[k][i-1] + tab[k][i-1];
	
	fo(i,nm[1]){
		E<N;
		ll m = (ll)tab[1][i]*i - sums[1][i];
		E<tab[1][i-1]*i<N;
		E<"inc "<m<N;
		int ith = lb(tab[0], tab[0]+nm[0], tab[1][i]) - tab[0];
		E<"ith "<ith<N;
		
		m += sums[0][nm[0]] - sums[0][ith] - (ll)(nm[0]-ith)*tab[1][i];
		
		E<"cand for index "<i<"   "<m<N;
		wynik = min(wynik,m);
	}
	
	O<wynik<N;
}
