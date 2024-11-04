


 

  

 

 

 

 

 


 

 

 

  

   



using namespace std;



























typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef pair < long long , long long > pll;
typedef vector < ll > vll;
typedef vector < vll > vvll;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef vector < pii > vpii;
typedef pair < pii , pii > ppiipii;
typedef long double ld;
typedef map < int , int > mii;
typedef map < ll , ll > mll;
typedef set < int > si;
typedef set < ull > sull;
typedef set < string > ss;
typedef set < pii > spii;
typedef multiset < int > msi;
typedef map < pii , int > mpiii;
typedef map < int , pii > mipii;
typedef vector < pair < int , pair < int , int > > > vpipii;

const int maxn = int(1.5 * 1e7);
const int inf = 1e9 + 7;
const ll ll_inf = 1e18 + 420;
const double eps = 1e-4;


const int MAX = 2e5 + 9;
const int MOD = 1e9 + 7;
const ld pi = 3.14159265359;

ll Binpow(int a, int b,int mod = 1e9 + 7){
	ll res = a, ret = 1;
	while(b > 0){
		if(b % 2)
			ret = (ret * res) % mod;
		res = (res * res) % mod;
		b /= 2;
	}
	return ret % mod;
}

ll fact(ll n,int mod = 1e9 + 7){
    if(n==1 || n==0) return 1;
    return ((n%mod)*(fact(n-1)%mod)%mod);
}



const int N = int(2e5);

int a[N + 1],sz[N + 1],p[N + 1];
ll f[N + 1],ans[N + 1],d[N + 1];
vector <int> cnt[N + 1],g[N + 1];

int add(int a, int b){
	a += b;
	return a;
}

int Get(int x){
	if(x == p[x]) return x;
	return p[x] = Get(p[x]);
}

void Merge(int a, int b){
	a = Get(a), b = Get(b);
	if(a == b) return;
	if(sz[a] < sz[b]) {
		sz[b] += sz[a];
		p[a] = b;
	}
	else{
		sz[a] += sz[b];
		p[b] = a;
	}
}

ll Calc(int n){
	return 1ll * n * (n - 1) / 2;
}

int main (){
	IOS;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
	    cin >> a[i], cnt[a[i]].pb(i), d[a[i]]++;
	}
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
    for(int i = 1; i <= N; i++){
        for(int j = i + i; j <= N; j += i){
            for(auto to : cnt[j]){
                cnt[i].pb(to);
            }
        }
	}
	for(int i = 1; i <= N; i++){
		if(!sz(cnt[i]))
		    continue;
		for(auto to : cnt[i]){
			p[to] = to;
			sz[to] = 1;
		}
		for(auto to : cnt[i])
			for(auto it : g[to])
                if(p[it] != 0)
                    Merge(it, to);
		for(auto to : cnt[i])
			if(to == Get(to))
			    f[i] += Calc(sz[to]);
		for(auto to : cnt[i])
            p[to] = sz[to] = 0;
	}
	for(int i = N; i >= 1; i--) {
		ans[i] += f[i];
		for(int j = i + i; j <= N; j += i)
            ans[i] -= ans[j];
	}
	for(int i = 1; i <= N; i++){
        if(ans[i] || d[i]){
            cout << i << ' ' << ans[i] * 1ll + d[i] * 1ll << endl;
        }
	}
}
