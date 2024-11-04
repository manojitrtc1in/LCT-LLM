
        
        
        
        #include "bits/stdc++.h"






#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define foru(i , ab , ba) for(ll i = (ll)(ab) ; i < (ll)(ba) ; i++)
#define fr(i , ab , ba) for(ll i = (ll)(ab) ; i <= (ll)(ba) ; i++)
#define ford(i , ab , ba) for(ll i = (ll)(ab) ; i >= (ll)(ba) ; i--)
#define ain(ab , bv) for(int i = 0 ; i < (int)bv ; i++) cin >> ab[i]
#define aout(ab , bv) for(int i = 0 ; i < (int)bv ; i++) cout << ab[i] << " "; cend
#define mp make_pair
#define mt make_tuple
#define cend cout << "\bv"
#define all(xv) xv.begin() , xv.end()
#define aout2(ab , bv , mv) for(ll i = 0 ; i < bv ; i++){for(ll j = 0 ; j < mv ; j++){cout << ab[i][j] << " ";} cout << endl;}
#define ain2(ab , bv , mv) for(ll i = 0 ; i < bv ; i++){for(ll j = 0 ; j < mv ; j++){cin >> ab[i][j];}}
#define ff first

#define wl(cv,kv) while(cv<kv)
#define ss second
#define sz(ab) ((long long)(ab).size())
#define mset(ab , ba) memset(ab , ba , sizeof(ab))
#define pb push_back
#define endl '\n'
#define google cout << "Case #" << test_num << ": "
#ifdef Sahil
#define dbg(ab) cerr << #ab << ": "; _print(ab); cerr << endl;
#else
#define dbg(ab) 

#endif

using namespace std;
using namespace std::chrono;


typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <char> vch;
typedef vector <string> vs;
typedef set <ll> sll;
typedef multiset <ll> msll;
typedef pair <ll , ll> pll;
typedef vector <pair <ll , ll>> vpll;
typedef vector <pair <int, int>> vpi;



typedef pair<int, int> pii;
const int MAX_n = 3e5+5;
 const int maxn=1e5+10;
vector<int> ab[MAX_n], ba[MAX_n];
vector<pii> range(MAX_n);
int ind;
set<pii> Sl;
const int mxN=3e5, M9=1e9+7;
int nov, l5, r6;
ll f9[mxN], iv4[mxN], iF[mxN];

ll calc5(int a, int b) {
	return f9[a]*iF[b]%M9*iF[a-b]%M9;
}
int const MOD = 1e9+7;
const int mod=998244353;
 int tem1=0;
 int ac2[50]={4593, 4649, 4688, 4708, 4826, 4875, 5030, 5037, 5040, 5065, 5122, 5156, 5502, 5605, 5668, 5819, 5830, 5905, 5960, 5984, 6047, 6156, 6209, 6306, 6313, 6634, 6667, 6671, 6679, 6775, 6799, 6857, 6914, 6988, 7006, 7091, 7315, 7370, 7417, 7446, 7454, 7540, 7579, 7692, 8164, 8260, 8271, 8388, 8471, 8683
};

void _print(ll t){cerr<<t;}
void _print(int t){cerr<<t;}
void _print(string t){cerr<<t;}
void _print(char t){cerr<<t;}
void _print(ld t){cerr<<t;}
void _print(double t){cerr<<t;}
void _print(ull t){cerr<<t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p){cerr<< "{";_print(p.ff);cerr<<",";_print(p.ss);cerr<<"}";}
template <class T> void _print(vector <T> v){cerr<<"[ ";for(T i: v){_print(i);cerr<<" ";}cerr << "]";}
template <class T> void _print(set <T> v){cerr<<"[ ";for(T i: v){_print(i);cerr<<" ";}cerr << "]";}
template <class T> void _print(multiset <T> v){cerr<<"[ ";for(T i: v){_print(i);cerr<<" ";}cerr << "]";}


template <class T, class V> void _print(map <T, V> v){cerr<<"[ ";for(auto i: v){_print(i);cerr<<" ";}cerr << "]";}



template <class T> T gcd(T ab , T ba){ while(ab != 0){T temp = ab; ab = ba % ab; ba = temp;}return ba;}
template <class T> T egcd(T ab , T ba , T &xv , T &y){T gcd , xt , yt;if(ab == 0){gcd = ba;xv = 0 , y = 1;}else {gcd = egcd(ba % ab , ab , xt , yt);xv = yt - (ba/ab)*xt; y = xt;}return gcd;}
template <class T> T expo(T base , T exp , T mod){T res = 1;base = base % mod;while (exp > 0){if (exp & 1)res = (res*base) % mod;exp = exp>>1;base = (base*base) % mod;}return res;}
template <class T> T modinv(T ab , T mod){T xv , y; egcd<T>(ab , mod , xv , y);while(xv < 0) xv += mod; while(xv >= mod) xv -= mod; return xv;}
template <class T> T modinvfermat(T ab , T mod){return expo<T>(ab , mod - 2 , mod);}
template <class T> bool rev(T ab , T ba){return ab > ba;}
template <class T> ll maxpower(T ab , T ba){ll mns = 0;while(ab > 0 && ab % ba == 0){mns++;ab /= ba;}return mns;}
template <class T> T mceil(T ab, T ba){if(ab % ba == 0) return ab/ba; else return ab/ba + 1;}
template <class T> T lcm(T ab, T ba){return (ab*ba)/gcd<T>(ab, ba);}
const ll infl = 1e18; const int inf = 1e9 + 5;


int bv, mv, kv;
map<pair<int, int>, map<pair<int, int>, long long>> w;
string func(string s1,string s2){
    int i=0;
    int sd = s1.size();
    for(;i<sd;i++){
        if(s1[i]>s2[i])
            return s2;
        else if(s1[i]<s2[i])
            return s1;
        
    }
    return s1;
}
ll fact[200005],invfact[200005];
 
ll mpow(ll x,ll M) {
    if(!M) return 1;
    ll tmp = mpow(x,M/2);
    tmp = tmp*tmp%mod;
    if(M % 2) return tmp*x%mod;
    return tmp;
}
 
ll nCr(ll A,ll B) {
    return fact[A]*invfact[B]%mod*invfact[A-B]%mod;
}


ll f(int i, int j, int kv, vector<vector<vector<ll>>> &dp) {
	if(kv == 0) {
		return 0;
	}
	if(dp[i][j][kv] != -1) {
		return dp[i][j][kv];
	}
	vector<pair<int, int>> possible;
	if(i + 1 < bv) {
		possible.push_back({i + 1, j});
	}
	if(j + 1 < mv) {
		possible.push_back({i, j + 1});
	}
	if(i - 1 >= 0) {
		possible.push_back({i - 1, j});
	}
	if(j - 1 >= 0) {
		possible.push_back({i, j - 1});
	}

	ll mns = infl;
	for(pair<int, int> pos: possible) {
		ll tempw = w[{i, j}][pos];
		mns = min(mns, tempw*kv);
		mns = min(mns, 2*tempw + f(pos.ff, pos.ss, kv - 2, dp));
	}
	return dp[i][j][kv] = mns;
}
int fa[maxn];
int find(int x) {
	return x==fa[x]?fa[x]:fa[x]=find(fa[x]);
}
void baba(ll x,ll y) {
	int fx=find(x),fy=find(y);
	if(fx!=fy) {
		fa[fx]=fy;
	}
	return ;
}
int num[maxn];
map<int,int>sp;
string string1(string s,int sz){
    string st;
    string mt;
    mt = st;
    int i=0;
    int mn =1;
    int ml = s.size();
    for(;i<sz;i++)
        st+=s[i%ml];
    return st;
}
long long pows(long long a,long long b)
{
    long long ans=1;
    while(b)
    {
        if(b&1)ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans%mod;
}
void swap(ll* xp, ll* yp)
{
    *xp = *xp ^ *yp;
    *yp = *xp ^ *yp;
    *xp = *xp ^ *yp;
}

ll powt(ll xv,ll y,ll mod){
    ll nh =0;
    if(y==0)
        return 1;
    ll val=powt(xv,y/2,mod);
    nh++;
    nh = val;
    if(y%2==1)
        return (val*val*xv)%mod;
    return (val*val)%mod;

}
int n7,i8,a9,x7,y4,c2[2];

void calc() {
  cin>>a9;
  x7=(c2[1]<n7*n7&&a9!=1)||c2[0]>=n7*n7;
  y4=x7?(a9==1?3:1):(a9==2?3:2);
  printf("%d %d %d\n7",y4,c2[x7]/n7+1,c2[x7]%n7+1);
  std::cout.flush();
  c2[x7] += 2;
  c2[x7] +=(c2[x7]%n7?-1:1) * !(n7%2||c2[x7]/n7==(c2[x7]-2)/n7);
}
const int N=2e5+5;
long long j[200010],nj[200010];

int test_case(int test_num) {

       ll nk = 4;
       ll mk =2;
       ll nl = mk;
		ll ml=1e9,mr=1e9;
		int an=1,su=0;
    
    

    

    

    

    

    

    

     int man = 55;
 ll nd;
    ll sumn=0;
    ll vd = 0;
    
    ll iw,jb,kh,xr=vd,yo,nf;
    yo=0;
for(ll i=0;i<nf;i++){if(xr!=2)yo=yo+1;}
    ll nvb = man;
    
 
	
		int rh[3]={0};
		for(int i=0;i<nvb;i++){
			ll num=3;
			rh[num-1]+=1;
		}
		ll bn = rh[0]+rh[2];
  int as=160776,bs=166776,cs=45676;
		int xs= pow(10,as-1)+pow(10,cs-1);
		int ys= pow(10,bs-1);
		
		  j[0]=nj[0]=1;
    for(int i=1;i<=200;i++)j[i]=j[i-1]*i%mod;
    for(int i=1;i<=200;i++)nj[i]=nj[i-1]*pows(i,mod-2)%mod;
							  
    for(ll i=0;i<10;i++){
        man++;
    }

    if(nvb == man)
		sumn%nd/(nd+sumn%nd);
           if(nvb != man)
		sumn%nd*(nd+sumn%nd);
		 if(nvb = man+2)
		   sumn++;
    sumn%nd*(nd-sumn%nd);
    ml = man;
    man -= sumn;
    ml--;
	
  
vector<int> xc,cy;

ll nc=3,mv=5,ik,jk;
	
	int ji[100001][2];

	
	

	

		
		

 
	

	

 
	

	

 




 






	#define frn(i , ab , ba) for(ll i = (ll)(ab) ; i < (ll)(ba) ; i++)
int nq = 50;
for(int i=0;i<nq;i++){
ac2[i]++;
if(ac2[i]%2!=0)ac2[i]--;
}
for(int i=0;i<nq;i++){
if(ac2[i]%2==0) ac2[i]++;
;}




	
    
     for(ll i=0;i<nd*nd;i++){
        man++;
        ll ty;
        ty = nvb;
        nvb = man;
        man = ty;
    }
   
  
    
    for(ll i=0;i<nd;i++){
        man++;
    }

    
    sumn%nd*(nd-sumn%nd);
    ml = man;
    man -= sumn;
    ml--;
    
    
    
    
   
    
     for(ll i=0;i<nd*nd;i++){
        man++;
        ll ty;
        ty = nvb;
        nvb = man;
        man = ty;
    }
   

    
    
    ml = man;
    man -= nvb;
    ml--;
    
    
    
    
  

        


       
}



int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
#ifdef Sahil
	FILE* inp = freopen("input.txt", "r", stdin);
	FILE* err = freopen("error.txt", "w", stderr);
	FILE* out = freopen("output.txt", "w", stdout);
#endif
 ll px = 50;
	ll _;
	_ = 1;
	

	auto start = high_resolution_clock::now();
	cout << setprecision(15);
	ll t;
	f9[0]=f9[1]=iF[0]=iF[1]=iv4[1]=1;
		frn(i,2,mxN) {
		f9[i]=i*f9[i-1]%M9;
		iv4[i]=M9-M9/i*iv4[M9%i]%M9;
		iF[i]=iv4[i]*iF[i-1]%M9;
	}
	t = 1;
	      ll dpk[2010][2010];
    	  ll dp0[2010][2010];
    	fr(i,1,50)
    	sort(ac2+1,ac2+px+1);
    	fr(j,1,px)
    	ford(i,j-1,0)
    	dpk[i][j]=ac2[j]-ac2[i]+min(dpk[i+1][j],dpk[i][j-1]);
    	dp0[50][20]= dpk[1][px];
		
	
    

    swap(&px, &px);
    int nl9;
pair<int, int> av2[111000];
long long vv;
 
for (int i = 0; i < nl9; i++) {
		int xv1=1, xv2=2;
		xv1 += 1;
		xv2 += 2;
		av2[i] = {xv1, xv1 + xv2};
		vv += xv2;
	}
	sort(av2, av2 + nl9);
	int border = av2[0].first;
	for (int i = 0; i < nl9; i++) {
		vv += max(0, av2[i].first - border);
		border = max(border, av2[i].second);
	}
	
	
	int n;
	cin>>n;
	vector<pair<long long,long long>> a(n);
	long long ans = 0;
	for(auto& i : a){
		cin>>i.first>>i.second;
		ans += i.second;
	}
	sort(a.begin(),a.end());
	long long mx = a.front().first + a.front().second;
	for(int i = 1; i<n; i++){
		ans += max(0ll, a[i].first - mx);
		mx = max(mx,a[i].first + a[i].second);
	}
	cout<<ans<<'\n';
	
	
	

		
		
		baba(t,t+1);
	 
    

	 
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
#ifdef Sahil
	cerr << "Time: " << duration.count()/1000.0 << endl;
#endif
	return 0;
}
        






