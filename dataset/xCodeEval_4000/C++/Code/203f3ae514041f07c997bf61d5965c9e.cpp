




#pragma GCC optimize("O3")
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <stack>
#include <ctime>
#include <iomanip>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <bitset>






#define fi first
#define se second
#define th third

#define en "\n"
#define sqrt(n) sqrt((long double) n)
#define all(c) (c).begin() , (c).end()
#define MOD 1000000007
#define mem0(a) memset(a,0,sizeof(a))
#define FAST() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define elif else if
#define SORT(x) sort(all(x))
#define REVERSE(x) reverse(all(x))
#define sz(a) ((long long)((a).size()))
#define what_is(x) cerr << #x << " is " << x << en
#define timer (clock()*1.0/CLOCKS_PER_SEC)
#define int long long

using namespace std;

template<class A, class B, class C> struct Triple { A first; B second; C third;
    bool operator<(const Triple& t) const { if (fi != t.fi) return fi < fi.st; if (se != t.se) return se < t.se; return th < t.th; } };


int gcd(int a,int b){
    while (a && b)
        if (a>b) a=a%b; else b=b%a;
    return a+b;
}

int bp(int a,int b,int &md){
    int res=1;
    while (b) {
        if (b&1) res*=a;
        a*=a;
        a%=md;
        res%=md;
        b>>=1;
    }
    return res;
}

vector <int> z_function(string &s){
    int n=sz(s);
    vector <int> ans(n,0);
    int l=0,r=0;
    for (int i=1; i<n; ++i){
        ans[i]=min(r-i+1,ans[i-l]);
        while (ans[i]+i<n && s[ans[i]]==s[i+ans[i]]){
            ++ans[i];
        }
        if (i+ans[i]-1>r){
            l=i,r=i+ans[i]-1;
        }
        r=max(r,i);
    }
    return ans;
}


typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef set<int> seti;
typedef long double ld;
typedef pair<ld, ld> pdd;
typedef Triple<int, int, int> tiii;


const ld EPS=0.000000001;
const ld INFD32=1000000000;
const ll INF64=1000000000000000000;
const ll INF32=1000000000;
const ll one=1;

#define  maxN 1000200

int arr[maxN];

int tree[4*maxN];

int w;

void bld(int v,int l,int r){
    if (l==r){
        tree[v]=arr[l];
    }else{
        int m=(l+r)>>1;
        bld(v<<1, l, m);
        bld(v<<1|1, m+1, r);
        tree[v]=max(tree[v<<1],tree[v<<1|1]);
    }
}

int gett(int v,int l,int r,int L,int R){
    if (l==L && r==R)
        return tree[v];
    else{
        int m=(l+r)>>1;
        if (R<=m)
            return gett(v<<1, l, m, L, R);
        elif (L>m)
        return gett(v<<1|1, m+1, r, L, R);
        else{
            return max(gett(v<<1, l, m, L, m),gett(v<<1|1, m+1, r, m+1, R));
        }
    }
}

ll prom[maxN];

ll ans[maxN];

void help(int pos,int n){
    int l=pos-1,r=w-pos;
    int m=-INF32;
    if (l>=n || r>=n) m=0;
    int L=max(1ll,n+pos-w);
    int R=min(n,pos);
    

    m=max(m,gett(1, 1, n, L, R));
    ans[pos]+=m;
}



void f(){
    int n;
    cin>>n;
    int m=0;
    for (int i=1; i<=n; ++i){
        cin>>arr[i];
        m=max(m,arr[i]);
    }
    bld(1,1,n);
    for (int i=1; i<=n; ++i){
        help(i, n);
    }
    for (int i=max(n+1,w-n+1); i<=w; ++i){
        help(i, n);
    }
    if (n>=w-n+1) return;
    prom[n+1]+=m;
    prom[w-n+1]-=m;
}

signed main(void){
    

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n>>w;
    for (int i=1; i<=n; ++i){
        f();
    }
    ll x=0;
    for (int i=1; i<=w; ++i){
        x+=prom[i];
        ans[i]+=x;
        cout<<ans[i]<<" ";
    }
    return 0;
    
}




