

 
 
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
   

#include <bits/stdc++.h>
 
using namespace std;
 
#define fr(i,a,b)       	for(int i = (a); i <= (b); i++)
#define pb              	push_back
#define f               	first
#define se              	second
#define pii             	pair < int , int >
#define mp              	make_pair
#define LOGMAX          	17
#define FIND(N,pos)     	((N) & (1 << (pos)))
#define sf(h)           	scanf("%d",&h)
#define sff(h,b)        	scanf("%d%d",&h,&b)
#define sfff(h,b,c)     	scanf("%d%d%d",&h,&b,&c)
#define TCASE(test)    		for(int z = 1;z <= test;z++)
#define PRINT           	printf("Case %d:\n",z)
#define en              	"\n"
#define lwb             	lower_bound
#define upb             	upper_bound
#define IOS             	ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define rep(i,l,r)      	for(int i = (l);i <= (r);i++)
#define cno             	cout<<"NO";return 0;
#define cye             	cout<<"YES";return 0;
#define sz(x)           	((int)(x).size())
#define all(a)              (a).begin(), (a).end()
#define forn(i, n)          	for(ll i=0;i<n;++i)
#define forl(i, a, b)       	for(ll i=(a);i<=(b);++i)
#define ford(i, a, b)       	for(int i=(a);i>=(b);--i)
#define forg(i, a, b, c)		for(ll i=(a);i<=(b);i += (c))
 
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
const int N = 1e6 + 7;
const int MAX = 2e5 + 9;
const int mod = 1e9 + 7;
const ld pi = 3.14159265359;
 
ll fast_pow(int a, int b){
	ll res = a, ret = 1;
	while(b > 0){
		if(b % 2)
			ret = (ret * res) % mod;
		res = (res * res) % mod;
		b /= 2;
	}
	return ret % mod;
}
 
ll fact(ll n){
    if(n == 1 || n == 0)
        return 1;
    return ((n % mod) * (fact(n - 1) % mod) % mod);
}
 
ll Cnk(ll n, ll r){
    return (fact(n) * fast_pow((fact(r) * fact(n - r)) % mod, mod - 2)) % mod;
}
 
int n,k,a,b,q,t[N],t1[N];
 
void update(int v,int tl,int tr,int pos,int val){
    if(tr < pos || tl > pos)
        return;
    if(tl == tr){
        t[v] += val;
        if(t[v] > b){
            t[v] = b;
        }
        return;
    }
    int tm = (tl + tr) / 2;
    update(v + v,tl,tm,pos,val);
    update(v + v + 1,tm + 1,tr,pos,val);
    t[v] = t[v + v] + t[v + v + 1];
}
 
void update1(int v,int tl,int tr,int pos,int val){
    if(tr < pos || tl > pos)
        return;
    if(tl == tr){
        t1[v] += val;
        if(t1[v] > a){
            t1[v] = a;
        }
        return;
    }
    int tm = (tl + tr) / 2;
    update1(v + v,tl,tm,pos,val);
    update1(v + v + 1,tm + 1,tr,pos,val);
    t1[v] = t1[v + v] + t1[v + v + 1];
}
 
ll get(int v,int tl,int tr,int l,int r){
    if(r < tl || tr < l){
        return 0;
    }
    if(l <= tl && tr <= r){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return get(v + v,tl,tm,l,r) + get(v + v + 1,tm + 1,tr,l,r);
}
 
ll get1(int v,int tl,int tr,int l,int r){
    if(r < tl || tr < l){
        return 0;
    }
    if(l <= tl && tr <= r){
        return t1[v];
    }
    int tm = (tl + tr) / 2;
    return get1(v + v,tl,tm,l,r) + get1(v + v + 1,tm + 1,tr,l,r);
}
 
int main() {
    IOS;
    cin >> n >> k >> a >> b >> q;
    for(int i = 1,x,y,w;i <= q;++i){
        cin >> x >> y;
        if(x == 1){
            cin >> w;
            update(1,1,n,y,w);
            update1(1,1,n,y,w);
        }
        else{
            

            int e = 0,f = 0;
            if(y - 1 > 0){
                e = get(1,1,n,1,y - 1);
            }
            

            if(y + k <= n){
                f = get1(1,1,n,y + k,n);
            }
            cout << e + f << en;
            

        }
    }
}