

 
 
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
   





 
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
typedef vector < pll > vpll;
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
 
const int maxn = 5e5 + 10;
const int inf = 1e9 + 7;
const ld ll_inf = 6e18 + 420;
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
 
int n,q,pos1 = 1,pos2 = 2,a[N];
 
int main(){
    IOS;
    Random();
    

    

    cin >> n >> q;
    for(int i = 1,x,y;i <= q;++i){
        cin >> x;
        if(x == 1){
            cin >> y;
            pos1 = pos1 + y;
            if(pos1 > n){
                pos1 -= n;
            }
            if(pos1 < 0){
                pos1 += n;
            }
            if(pos1 == 0){
                pos1 = n;
            }
            pos2 = pos2 + y;
            if(pos2 > n){
                pos2 -= n;
            }
            if(pos2 < 0){
                pos2 += n;
            }
            if(pos2 == 0){
                pos2 = n;
            }
        }
        else{
            pos1 = (pos1 % 2 == 0 ? pos1 - 1 : pos1 + 1);
            pos2 = (pos2 % 2 == 0 ? pos2 - 1 : pos2 + 1);
        }
        

    }
    int cnt = 1;
    while(!a[pos1]){
        a[pos1] = cnt;
        cnt += 2;
        pos1 = pos1 + 2;
        if(pos1 > n){
            pos1 -= n;
        }
        if(pos1 < 0){
            pos1 += n;
        }
        if(pos1 == 0){
            pos1 = n;
        }
    }
    cnt = 2;
    while(!a[pos2]){
        a[pos2] = cnt;
        cnt += 2;
        pos2 = pos2 + 2;
        if(pos2 > n){
            pos2 -= n;
        }
        if(pos2 < 0){
            pos2 += n;
        }
        if(pos2 == 0){
            pos2 = n;
        }
    }
    for(int i = 1;i <= n;++i){
        cout << a[i] << " ";
    }
}