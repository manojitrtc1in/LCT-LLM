


 

  

 

 

 

 

 


 

 

 

  

   

#include <bits/stdc++.h>

using namespace std;

#define fr(i,a,b)       for(int i = (a); i <= (b); i++)
#define pb              push_back
#define f               first
#define se              second
#define pii             pair < int , int >
#define mp              make_pair
#define LOGMAX          17
#define MX              1 << 22
#define FIND(N,pos)     ((N) & (1 << (pos)))
#define sf(h)           scanf("%d",&h)
#define sff(h,b)        scanf("%d%d",&h,&b)
#define sfff(h,b,c)     scanf("%d%d%d",&h,&b,&c)
#define TCASE(test)     for(int z = 1;z <= test;z++)
#define PRINT           printf("Case %d:\n",z)
#define en              "\n"
#define lwb             lower_bound
#define upb             upper_bound
#define IOS             ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define rep(i,l,r)      for(int i = (l);i <= (r);i++)

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
const int inf = ~0U;
const ll ll_inf = 1e18 + 420;
const double eps = 1e-4;
const int N = 1e6 + 7;
const int MAX = 2e5 + 9;
const int MOD = 1e9 + 7;
const ld pi = 3.14159265359;

int n,m,a[N],b[N],q[N],y[N],w[N],t[N],p[N];

void push(int v,int tl,int mif,int tr){
    if(p[v] == 0)
        return;
    t[v + v] = p[v];
    p[v + v] = p[v];
    t[v + v + 1] = p[v];
    p[v + v + 1] = p[v];
    p[v] = 0;
}

void update(int v,int tl,int tr,int l,int r,int x){
    if(tl > r || tr < l)
        return;
    if(tl >= l && tr <= r){
        t[v] = x;
        p[v] = x;
        return;
    }
    int mid = (tl + tr) / 2;
    push(v,tl,mid,tr);
    update(v + v,tl,mid,l,r,x);
    update(v + v + 1,mid + 1,tr,l,r,x);
}

void get(int v,int tl,int tr,int pos){
    if(tl > pos || tr < pos){
        return;
    }
    if(tl == tr){
        int x = t[v];
        if(x == 0){
            cout << b[pos] << en;
        }
        else{
            cout << a[q[x] + (pos - y[x])] << en;
        }
        return;
    }
    int mid = (tl + tr) / 2;
    push(v,tl,mid,tr);
    get(v + v,tl,mid,pos);
    get(v + v + 1,mid + 1,tr,pos);
}

int main(){
    IOS;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
        cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
        cin >> b[i];
	}
	for(int i = 1,c,z;i <= m;i++){
        cin >> c;
        if(c == 1){
            cin >> q[i] >> y[i] >> w[i];
            update(1,1,n,y[i],y[i] + w[i] - 1,i);
        }
        else{
            cin >> z;
            get(1,1,n,z);
        }
	}
}
