











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
#include <unordered_map>
#include <unordered_set>
#include <bitset>


#define en "\n"
#define sqrt(n) sqrt((double) n)
#define all(c) (c).begin() , (c).end()
#define int long long
#define MOD 1000000007
#define mem0(a) memset(a,0,sizeof(a))
#define FAST() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
#define double long double
#define elif else if
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const double EPS=0.000000001;
const ll INF64=1000000000000000000;
const int INF32=2000000000;

bool iss_pt_in_triangle(pii a,pii b,pii c,pii point){
    int x1=a.first,x2=b.first,x3=c.first,x0=point.first;
    int y1=a.second,y2=b.second,y3=c.second,y0=point.second;
    int aa=(x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0);
    int bb=(x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0);
    int cc=(x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0);
    if (aa==0 || bb==0 || cc==0) return 1;
    if (aa>=0 && bb>=0 && cc>=0) return 1;
    if (aa<=0 && bb<=0 && cc<=0) return 1;
    return 0;
}

bool iss_ll(ll &__1,ll &__2){ return INF64/__1>=__2;}
bool equal(double _1,double _2){ return (abs(_1-_2)<EPS);}
bool iss_sqr(int &__1){ll __2=sqrt(__1); return __2*__2==__1;};
bool iss_prime(ll __1){for (int i=2; i*i<=__1; ++i) if (!(__1%i)) return 0; return 1;}
int gcd(int __1,int __2){ while (__1 && __2) if (__1>__2)  __1=__1%__2; else __2=__2%__1; return __1+__2;}
int lcm(int &__1,int &__2){ return __1*__2/(gcd(__1, __2));}
int sq_cube(ll x){if (x==0) return 1;int l=0,r=2e6;while (l+1<r){int m=(l+r)/2;if (m*m*m>x) r=m;else l=m;}return l;}

set<int> G[100100];
vector<int> GR[100100];
bool used[100100];
void dfs(int v){
    if (used[v]) return;
    used[v]=1;
    for (int i:G[v])
        dfs(i);
}int n,k;
int step(int k){
    int res=1;
    for (int i=0; i<k; ++i) res*=3;
    return res;
}
int dfss(int v,int deep){
    int ans=deep;
    used[v]=1;
    if (deep!=k){
        if ((GR[v].size()<4 && deep>0 && deep!=k) || (deep==0 && GR[v].size()<3)){
            

            

            cout<<"No"<<en;
            exit(0);
        }
    }
    for (int i:GR[v]){
        if (used[i]) continue;
        ans=max(dfss(i,deep+1),ans);
    }
    if (ans!=k) {
        

        cout<<"No"<<en;
        exit(0);
    }
    return ans;
}
signed main(signed argc, const char * argv[]) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>n>>k;
    if (k>20){
        cout<<"No"<<en;
        return 0;
    }
    for (int i=1; i<n; ++i){
        int x,y;
        cin>>x>>y;
        G[x].insert(y);
        G[y].insert(x);
        GR[x].push_back(y);
        GR[y].push_back(x);
    }
    dfs(1);
    for (int i=1; i<=n; ++i){
        if (!used[i]){
            cout<<"No"<<en;
            return 0;
        }
    }
    vi VEC;
    int k1=k;
    int pos=0;
    for (int i=1; i<=n; ++i) if (G[i].size()==1) VEC.push_back(i);
    while (k--){
        if (VEC.size()==0){
            cout<<"No"<<en;
            return 0;
        }
        if (k==0){
            pos=*G[VEC.front()].begin();
        }
        for (int i:VEC){
            G[*G[i].begin()].erase(i);
            G[i].clear();
        }
        VEC.clear();
        for (int i=1; i<=n; ++i){
            if (G[i].size()==1) VEC.push_back(i);
            if (G[i].size()==2) {
                cout<<"No"<<en;
                return 0;
            }
        }
    }
    mem0(used);
    

    k=k1;
    dfss(pos,0);
    cout<<"Yes"<<en;
}
