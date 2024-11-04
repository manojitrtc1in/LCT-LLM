

 
 
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
   


 
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
const int inf = ~0U >> 1;
const ll ll_inf = 1e18 + 420;
const double eps = 1e-4;
const int N = 300100;
const int MAX = 2e5 + 9;
const int MOD = 1e9 + 7;
const ld pi = 3.14159265359;
 
int n, p, cn[N], pr[N];
ll bit[N], ans;
map < pii , int > ma;
 
void update(int x) {
    int y = x;
	while (x <= n) {
		++bit[x];
		

		x += x & (- x);
		

	}
}
 
ll get1(int x) {
	ll ret = 0;
	

	while (x > 0) {
		ret += bit[x];
		x -= x & -x;
		

	}
	return ret;
}
 
int get(int a, int b) {
	return get1(b) - get1(a - 1);
}
 
main(void) {
	cin >> n >> p;
	for (int i = 0,x,y; i < n; ++i) {
		cin >> x >> y;
        ++cn[x] , ++cn[y];
        if (x > y){
            swap(x, y);
        }
        ++ma[mp(x, y)];
	}
	for (map < pii , int > :: iterator it = ma.begin(); it != ma.end(); ++it) {
	    int x,y,v;
		x = it -> first.first, y = it -> first.second, v = it -> second;
        if (cn[x] + cn[y] >= p + v){
            ++ans;
        }
		if (cn[x] + cn[y] >= p){
            --ans;
		}
	}
	for (int i = 1; i <= n; ++i) {
	    int x;
		x = max(0, p - cn[i]);
        if (x == 0){
            ans += i - 1;
        }
	    else{ 
            ans += get(x, n);
        }
		if(cn[i]){ 
            update(cn[i]);
		}
	}
	cout << ans;
}