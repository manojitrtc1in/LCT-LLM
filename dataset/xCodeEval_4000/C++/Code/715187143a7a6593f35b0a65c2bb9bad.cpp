




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
#define int long long
#define SORT(x) sort(all(x))
#define REVERSE(x) reverse(all(x))


using namespace std;

template<class A, class B, class C> struct Triple { A first; B second; C third;
    bool operator<(const Triple& t) const { if (fi != t.fi) return fi < fi.st; if (se != t.se) return se < t.se; return th < t.th; } };

int gcd(int a,int b){
    while (a && b)
        if (a>b) a=a%b; else b=b%a;
    return a+b;
}


typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef set<int> seti;
typedef long double ld;
typedef pair<ld, ld> pdd;
typedef Triple<int, int, int> TIII;


const double EPS=0.000000001;
const double INFD32=1000000000;
const ll INF64=1000000000000000000;
const int INF32=1000000000;

#define  maxN 100100

struct pt {
    int x,y;
};

struct line {
    int a,b,c;
};

bool operator <(line x,line y){
    if (x.a!=y.a) return x.a<y.a;
    if (x.b!=y.b) return x.b<y.b;
    if (x.c!=y.c) return x.c<y.c;
    return 0;
}

void fix(line &LL){
    if (LL.a<0) LL.a*=-1,LL.b*=-1,LL.c*=-1;
    if (LL.a==0 && LL.b<0) LL.a*=-1,LL.b*=-1,LL.c*=-1;
    int g=gcd(abs(LL.a),gcd(abs(LL.b),abs(LL.c)));
    LL.a/=g;
    LL.b/=g;
    LL.c/=g;
}

line L (pt _1,pt _2){
    line res;
    res.a=(_2.y-_1.y);
    res.b=(_1.x-_2.x);
    res.c=-_1.x*(_2.y-_1.y)+_1.y*(_2.x-_1.x);
    fix(res);
    return res;
}

pt arr[maxN];

vector<line> VEC;


int iss(int i1,int i2){
    if (VEC[i1].a*VEC[i2].b!=VEC[i1].b*VEC[i2].a){
        return 1;
    }
    return 0;
}

pii f(pii x){
    int g=gcd(abs(x.first),abs(x.second));
    x.first/=g;
    x.second/=g;
    if (x.first==0) x.second=abs(x.second);
    if (x.first<0) x.first*=-1,x.second*=-1;
    return x;
}

map <pii,int> MP;
signed main(void){
    

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    set<line> SET;
    for (int i=1; i<=n; ++i){
        cin>>arr[i].x>>arr[i].y;
        for (int j=1; j<i; ++j)
            SET.insert(L(arr[i],arr[j]));
    }
    int cnt=(ll)SET.size()*(SET.size()-1)/2;
    int l1=0,l2=0;
    for (auto i:SET) if (i.a!=0 && i.b!=0) MP[f({i.a,i.b})]++;
    elif (i.a==0) ++l1;
    else ++l2;
    cnt-=l1*(l1-1)/2;
    cnt-=l2*(l2-1)/2;
    for (auto i:MP) cnt-=(i.second)*(i.second-1)/2;
    cout<<cnt<<en;
    return 0;
}



