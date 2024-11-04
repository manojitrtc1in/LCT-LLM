

 
 
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
   





 
using namespace std;
using namespace __gnu_pbds;
 


























 
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
typedef set < ll > sll;
typedef set < ull > sull;
typedef set < string > ss;
typedef set < pii > spii;
typedef set < pll > spll;
typedef multiset < int > msi;
typedef map < pii , int > mpiii;
typedef map < int , pii > mipii;
typedef vector < pair < int , pair < int , int > > > vpipii;
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
const int maxn = int(1.5 * 1e7);
const int inf = 1e9 + 7;
const ll ll_inf = 1e18 + 420;
const double eps = 1e-4;
const int N = 1e6 + 7;
const int MAX = 2e5 + 9;
const int MOD = 1e9 + 7;
const ld pi = 3.14159265359;
 
ll bpow(int a, int b,int mod = 1e9 + 7){
	ll res = a, ret = 1;
	while(b > 0){
		if(b % 2)
			ret = (ret * res) % mod;
		res = (res * res) % mod;
		b /= 2;
	}
	return ret % mod;
}
 
void Random(){
    unsigned int seed;
    asm("rdtsc" : "=A" (seed));
    srand(seed);
}
 
ll fact(ll n,int mod = 1e9 + 7){
    int fuc = 1;
    for(int i = 2;i <= n;++i){
        fuc = fuc * i % mod;
    }
    return fuc;
}
 
ll Cnk(ll n, ll r,int mod = 1e9 + 7){
    r = min(r,n - r);
    ll ans = 1;
    for(int i = n;i >= (n - r + 1);--i){
        ans = (ans * i) % mod;
    }
    for(int i = 1;i <= r;++i){
        ans = (ans * bpow(i,mod - 2)) % mod;
    }
    return ans;
}
 
int n, cnt1[N], cnt2[N];
string s1[N], s2[N];
bool was[N];
 
int main(){
    IOS;
    Random();
    

    

    cin >> n;
    for(int i = 0; i< n; ++i){
        cin >> s1[i];
        cnt1[s1[i][0] - 'A']++;
    }
    for(int i = 0; i < n; ++i){
        cin >> s2[i];
        cnt2[s2[i][0] - 'A']++;
    }
    sort(s1, s1 + n);
    sort(s2, s2 + n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(!was[j] && (s1[i][0] == s2[j][0] || cnt1[s1[i][0] - 'A'] > cnt2[s1[i][0] - 'A'] && cnt1[s2[j][0] - 'A'] < cnt2[s2[j][0] - 'A'])){
                was[j] = 1;
                cnt1[s1[i][0] - 'A']--;
                cnt2[s2[j][0] - 'A']--;
                if(i) cout << ", ";
                cout << s1[i] << ' ' << s2[j];
                break;
            }
        }
    }
}