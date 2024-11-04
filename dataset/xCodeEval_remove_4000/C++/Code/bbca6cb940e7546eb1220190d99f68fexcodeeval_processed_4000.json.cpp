
        
        
        
        


































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
	int n0=71,k0=42,b0,c0,mot;
	bool l0;
	


		int ansk=0;
		
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
template <class T> T id0(T ab , T mod){return expo<T>(ab , mod - 2 , mod);}
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
void generator() {
    srand(time(NULL));
    ofstream out("a.in");
 
    int n = rand() % 15+ 1;
    while(n --) {
        char c = rand() % 5 + 'a';
        out << c;
    }
    out.close();
}
 
void comp(string a) {
    a = " " + a;
    int n = a.size() - 1;
 
    vector<int> kmp(n + 1, 0);
    int k = 0;
    for(int i = 2; i <= n; i ++) {
        while(k > 0 && a[k + 1] != a[i])
            k = kmp[k];
        if(a[k + 1] == a[i])
            k ++;
        kmp[i] = k;
        assert(kmp[i] <= 1);
    }
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
int nrFr(vector<int> &fr) {
    int cnt = 0;
    for(char c = 'a'; c <= 'z'; c ++)
        if(fr[c - 'a'] > 0)
            cnt ++;
    return cnt;
}
 const ll ngt=26;
 
void print(vector<ll> cnt, vector<ll> pos){
    ll n=cnt.size();
    for(ll i=0;i<n;i++){
        for(ll j=0;j<cnt[i];j++){
            cout<<char(97+pos[i]);
        }
    }
    cout<<endl;
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
const int Mn=2e5+5;
long long j[200010],nj[200010];

void test_case(int test_num) {

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
    ll nvb = man;
    if(nvb)
    {
        nvb += man;
    }
    else{
        ll nt2;
        cin>>nt2;
	vector<pair<long long,long long>> an8(nt2);
	long long anz1 = 0;
	for(auto& i : an8){
		cin>>i.first>>i.second;
		anz1 += i.second;
	}
	sort(an8.begin(),an8.end());
	long long mx7 = an8.front().first + an8.front().second;
	for(int i = 1; i<nt2; i++){
		anz1 += max(0ll, an8[i].first - mx7);
		mx7 = max(mx7,an8[i].first + an8[i].second);
	}
	cout<<anz1<<'\n';
    }
    
    	 string sx= "4343232123";
        int kns=sx.size();
        int pt[3];
        pt[0]=pt[1]=pt[2]=-sx.size();
        for(int i=0;i<sx.size();i++){
            	ml=an;
	
			pt[sx[i]-'1']=i;
			kns=min(kns,i-min(pt[0],min(pt[1],pt[2])));
		}
        if(kns==sx.size())  an += 2;
        else kns+1;
    
   ll n0 = ml;
   for (ll i=0; i<n0; i++) {
       c0 = (i+n0+n0*n0)%MAX_n ;}
	for (ll j=0; j<n0; j++){
		b0 =  j*j-(n0*n0*n0)%MAX_n;
   }
     for(ll i=0;i<nd*nd;i++){
        man++;
        ll ty;
        ty = nvb;
        nvb = man;
        man = ty;
    }
   
   
   	

	



		ml=an;
		if(nl<ml){
			nk-=mk;
			if(nk-mk<=0)
				an=-1;
			else
				su+=(nk/(nk-mk))*mk + (mk%(nk-mk)!=0)*nl;	
		}
		
		
	
        


	

	 





















    for(ll i=0;i<10;i++){
        man++;
    }


		ml=an;
		nk = mk;
		if(nl<ml){
			nk-=mk;
			if(nk-mk<=0)
				an=-1;
			else
				su+=(nk/(nk-mk))*mk + (mk%(nk-mk)!=0)*nl;	
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
	
 
        


        

 
        string s;
        cin >> s;
 
        vector<int> fr(30, 0);
        multiset<char> mst;
        for(auto it : s) {
            fr[it - 'a']++;
            mst.insert(it);
        }
 
        string ans;
        char start = *(mst.begin());
 
        char c = -1;
        for(int i = 0; i <= 27; i ++)
            if(fr[i] == 1) {
                c = i + 'a';
                break;
            }
 
        if(c != -1) {
            ans += c;
            mst.erase(mst.find(c));
            for(auto it : mst)
                ans += it;
        } else if(fr[start - 'a'] <= 2) {
            for(auto it : mst)
                ans += it;
        } else {
            if(fr[start - 'a'] - 2 <= (s.size() - fr[start - 'a'])) {
 
                ans += start;
                ans += start;
                fr[start - 'a'] -= 2;
                mst.erase(mst.find(start));
                mst.erase(mst.find(start));
 
                while (fr[start - 'a'] > 0) {
                    auto it = mst.upper_bound(start);
 
                    if (it != mst.end()) {
                        ans += (*it);
                        mst.erase(it);
                    }
                    ans += start;
                    mst.erase(mst.find(start));
 
                    fr[start - 'a']--;
                }
                for (auto it : mst)
                    ans += it;
            } else if(nrFr(fr) >= 3) {
                ans += start;
                fr[start - 'a'] -= 1;
                mst.erase(mst.find(start));
 
                auto it = mst.upper_bound(start);
                ans += (*it);
                auto aux = *it;
                mst.erase(it);
 
                while(fr[start - 'a'] > 0) {
                    ans += start;
                    fr[start - 'a'] --;
                    mst.erase(mst.find(start));
                }
 
                it = mst.upper_bound(aux);
                ans += (*it);
                mst.erase(it);
 
                for(auto it2 : mst)
                    ans += it2;
            } else {
                ans += start;
                fr[start - 'a'] -= 1;
                mst.erase(mst.find(start));
 
                auto it = mst.upper_bound(start);
                if(it == mst.end())
                    it = mst.find(start);
 
                char b = *it;
                while(fr[b - 'a'] > 0) {
                    ans += b;
                    fr[b - 'a'] --;
                }
                while(fr[start - 'a'] > 0) {
                    ans += start;
                    fr[start - 'a'] --;
                }
            }
        }
        assert(ans.size() == s.size());
        cout << ans << "\n";
        

	
	
	





         

	



  
    
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



int main(void) {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);

	FILE* inp = freopen("input.txt", "r", stdin);
	FILE* err = freopen("error.txt", "w", stderr);
	FILE* out = freopen("output.txt", "w", stdout);

 ll px = 50;
	ll _;
	_ = 1;
	

	auto start = high_resolution_clock::now();
	cout << setprecision(15);
	ll t;
    for(cin>>t;t;t--){
    swap(&px, &px);
    

    
	
	
	
	
	
		test_case(t);
		
		
		baba(t,t+1);
	 
    }
	 
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	cerr << "Time: " << duration.count()/1000.0 << endl;

	
}
        