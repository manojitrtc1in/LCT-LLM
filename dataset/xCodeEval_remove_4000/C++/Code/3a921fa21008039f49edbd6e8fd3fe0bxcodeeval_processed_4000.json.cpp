
































using namespace __gnu_pbds;













using namespace std;




























mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
inline int rnd(int x,int y){return rng()%(y-x+1)+x;}

const int MOD1=1000000007;
const int MOD2=998244353;
const int INF=2139062143;
const long long LLINF=1000000000000000000LL;

template<typename T> bool chmin(T &a,T b){return b<a?(a=b,true):false;}
template<typename T> bool chmax(T &a,T b){return b>a?(a=b,true):false;}

namespace Math{
inline long long gcd(long long a,long long b){if(!b) return a; return gcd(b,a%b);}
inline long long qpow(long long a,long long b){ 

    long long tmp=1;
    while(b){
        if(b&1) tmp=tmp*a;
        a=a*a;
        b>>=1;
    }
    return tmp;
}
inline long long id4(long long a,long long b,long long m){ 

    a%=m;
    long long tmp=1;
    while(b){
        if (b&1) tmp=tmp*a%m;
        a=a*a%m;
        b>>=1;
    }
    return tmp;
}
inline long long inv(long long a,long long m){return id4(a,m-2,m);} 

inline long long mul(long long a,long long b,long long MOD){
    return (1LL*a*b)%MOD;
}
inline long long add(long long a,long long b,long long MOD){
    long long s=(a+b);
    if (s>=MOD) s-=MOD;
    return s;
} 
inline long long sub(long long a, long long b,long long MOD){
    long long s=(a+MOD-b);
    if (s>=MOD) s-=MOD;
    return s;
}
vector<long long>pre_fac,id2,pre_inv;
inline void inv_init(long long LIM, long long MOD){ 

    pre_fac.resize(LIM);
    id2.resize(LIM);
    pre_inv.resize(LIM);
    pre_fac[0]=1;
    for(int i=1;i<LIM;i++) pre_fac[i]=mul(pre_fac[i-1],i,MOD);
    id2[LIM-1]=inv(pre_fac[LIM-1],MOD);
    for(int i=LIM-2;i>=0;i--) id2[i] = mul(id2[i+1],i+1,MOD);
    for(int i=1;i<LIM;i++) pre_inv[i]=mul(id2[i],pre_fac[i-1],MOD);
 
}
inline long long C(long long n,long long k,long long MOD){ 

    if (n<k) return 0;
    if (n<0||k<0) return 0;
    return mul(pre_fac[n],mul(id2[k],id2[n-k],MOD),MOD);
}

} 


using namespace Math;



namespace IO{




char buf[MAXSIZE],*p1,*p2;



template<typename T> inline void R(T &x){ 

    x=0; T Sign=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') Sign=-1;c=getchar();}
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=Sign;
}
template<typename A> inline void R(vector<A> &x){ 

    for(auto &a:x) R(a);
}
template<typename H, typename... T> inline void R(H& h,T&... t){ 

    R(h);
    R(t...);
}

template<typename T> inline void PR(T &x){ 

    x=0;
    char c=getchar();
    while(c<'0'||c>'9'){c=getchar();}
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
}
template<typename A> inline void PR(vector<A> &x){ 

    for(auto &a: x) PR(a);
}
template<typename H, typename... T> inline void PR(H& h,T&... t){ 

    PR(h);
    PR(t...);
}







char pbuf[MAXSIZE],*pp=pbuf;

inline void pc(const char &c) {
    if (pp-pbuf==MAXSIZE) fwrite(pbuf,1,MAXSIZE,stdout),pp=pbuf;
    *pp++=c;
}

template<typename T> void W(T y){ 

    if(y<0)y=-y,putchar('-');
    static T sta[40];
    T top=0;
    do {
      sta[top++] = y%10, y/=10;
    } while (y);
    while (top) putchar(sta[--top] + '0');
}
template<typename T> void PW(T y){ 

    static T sta[40];
    T top=0;
    do {
      sta[top++]=y%10,y/=10;
    } while (y);
    while (top) putchar(sta[--top] + '0');
}
template <typename T> void W(T y, char lastChar) {
    W(y),putchar(lastChar);
  }
template <typename T> void PW(T y, char lastChar) {
    PW(y),putchar(lastChar);
}




std::istream &operator>>(std::istream &is,__int128_t &n){
    n=0;
    __int128_t Sign=1;
    std::string s;
    is >> s;
    int __length=s.length();
    ((s[0]=='-')?Sign=-1:n=s[0]-'0');
    for(int i=1;i<__length;i++){
        n=(__int128_t)10*n+s[i]-'0';
    }
    n*=Sign;
    return is;
}
std::istream &operator>>(std::istream &is,__uint128_t &n){
    n=0;
    std::string s;
    is >> s;
    int __length=s.length();
    for(int i=0;i<__length;i++){
        n=(__uint128_t)10*n+s[i]-'0';
    }
    return is;
}
std::ostream &operator<<(std::ostream &os,__int128_t n){
    if(n==0){
        return os << 0;
    }
    std::string s;
    bool Neg=false;
    if(n<0){
        n=-n;
        Neg=true;
    }
    while(n>0){
        s+=n%(__int128_t)10+'0';
        n/=(__int128_t)10;
    }
    if(Neg){
        s+='-';
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}
std::ostream &operator<<(std::ostream &os,__uint128_t n){
    if(n==0) {
        return os << 0;
    }
    std::string s;
    while(n>0){
        s+=n%(__uint128_t)10+'0';
        n/=(__uint128_t)10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}


} 


using namespace IO;



namespace DBG{
template<typename A, typename B> ostream& operator<<(ostream &os,const pair<A, B> &p){return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v){ os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void debug_out() { cerr << "]\n";}
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T){cerr << H;if(sizeof...(T)) cerr << ", "; debug_out(T...);}






}


using namespace DBG;

const int d4x[4]={-1,0,1,0},d4y[4]={0,1,0,-1};
const int d8x[8]={-1,-1,0,1,1,1,0,-1},d8y[8]={0,1,1,1,0,-1,-1,-1};



namespace TWNWAKing{


struct Data{
    int maximum_subarray_sum,l,r;
};







Data id0(vi &v){
	int SZ=sz(v);
	vi buffer;
	int buffer_size=2*SZ-1;
	buffer.reserve(buffer_size);
	Data ans;
	buffer.pb(1LL);
	for(int i=0;i<(SZ-1);++i){
		buffer.pb(-(v[i+1]-v[i]-1));
		buffer.pb(1LL);
	}
	

	int best=-LLINF,sum=0,s=0,start=0,end=0;
	

	

	

    for(int i=0;i<buffer_size;++i){
        sum+=buffer[i];
        if(best<sum){
            best=sum;
            start=s;
            end=i;
        }
        if(sum<0){
            sum=0;
            s=i+1;
        }
    }
    ans.l=v[start>>1];
    ans.r=v[end>>1];
    ans.maximum_subarray_sum=best;
    return ans;
}

void id1(){
    int n;
    R(n);
    vi arr(n);
    R(arr);
    
    

    

    map<int,vector<int>> id3;
    for(int i=0;i<n;i++) id3[arr[i]].pb(i+1);

    vi arr2=arr;
    sort(all(arr2));
    arr2.erase(unique(all(arr2)),arr2.end());
    int len=sz(arr2);
    int best_l=-1,best_r=-1,ans=-INF;
    for(int i=0;i<len;i++){
    	auto tmp=id0(id3[arr2[i]]);
    	if(chmax(ans,tmp.maximum_subarray_sum)){
    		best_l=tmp.l;
    		best_r=tmp.r;
    	}
    }
    

    W(arr[best_l-1],' ');
    W(best_l,' ');
    W(best_r,'\n');
}

} 


I_always_get_WA{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    cout << fixed << setprecision(20);

    

    

    auto begin = std::chrono::high_resolution_clock::now();

    int test_cases=1;
    

    R(test_cases);
    while(test_cases--) TWNWAKing::id1();

    auto end = std::chrono::high_resolution_clock::now();
    cerr << setprecision(4) << fixed;
    cerr << endl << "------------\nExecution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;


    fwrite(IO::pbuf,1,IO::pp-IO::pbuf,stdout);

    return C8763;
}


