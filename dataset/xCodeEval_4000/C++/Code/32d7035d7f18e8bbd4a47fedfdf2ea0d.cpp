











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
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
#define double long double
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef set<int> seti;

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
bool iss_sqr(int __1){ll __2=sqrt(__1); return __2*__2==__1;};
bool iss_prime(ll __1){for (int i=2; i*i<=__1; ++i) if (!(__1%i)) return 0; return 1;}
int gcd(int __1,int __2){ while (__1 && __2) if (__1>__2)  __1=__1%__2; else __2=__2%__1; return __1+__2;}
int lcm(int &__1,int &__2){ return __1*__2/(gcd(__1, __2));}
int sq_cube(ll x){if (x==0) return 0;int l=0,r=2e6;while (l+1<r){int m=(l+r)/2;if (m*m*m>x) r=m;else l=m;}return l;}

int arr[100100];

int forr[100100];
set<pair<int,pii > > VEC;
set<pii> SET;
void sol1(){
    if (SET.size()==0 && VEC.size()==0) return;
    if (VEC.size()){
        auto x=*VEC.rbegin();
        VEC.erase(x);
        if (arr[x.second.first]>arr[x.second.second]){
            cout<<x.second.first<<endl;
        }else
            cout<<x.second.second<<endl;
        SET.erase({arr[x.second.second],x.second.second});
        SET.erase({arr[x.second.first],x.second.first});
        if (SET.size()==0 && VEC.size()==0) return;
        cin>>x.first;
        sol1();
    }else{
        auto x=*SET.rbegin();
        cout<<x.second<<endl;
        SET.erase(x);
        if (SET.size()==0 && VEC.size()==0) return;
        cin>>x.second;
        x.first=arr[x.second];
        SET.erase(x);
        sol1();
    }
}

void sol2(){
if (SET.size()==0 && VEC.size()==0) return;
    int x;
    cin>>x;
    if (forr[x]){
        cout<<forr[x]<<endl;
        SET.erase({arr[forr[x]],forr[x]});
        SET.erase({arr[x],x});
        VEC.erase({max(arr[x],arr[forr[x]]),{min(x,forr[x]),max(x,forr[x])}});
        sol2();
    }else{
        SET.erase({arr[x],x});
        sol1();
    }
}

signed main(signed argc, const char * argv[]){
    FAST();
    int n,m;
    cin>>n>>m;
    
    for (int i=1; i<=2*n; ++i){
        cin>>arr[i];
        SET.insert({arr[i],i});
    }
    
    while (m--){
        int x,y;
        cin>>x>>y;
        if (x>y) swap(x, y);
        forr[x]=y;
        forr[y]=x;
        
        VEC.insert({max(arr[x],arr[y]),{x,y}});
    }
    int t;
    cin>>t;
    if (t==1){
        sol1();
    }else{
        sol2();
    }
    return 0;
}
