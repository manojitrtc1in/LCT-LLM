




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
#define ALL(c) (c).begin() , (c).end()
#define MOD 1000000007
#define MEM0(a) memset(a,0,sizeof(a))
#define FAST() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FILES(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define elif else if
#define SORT(x) sort(all(x))
#define REVERSE(x) reverse(all(x))
#define SZ(a) ((long long)((a).size()))
#define WHAT_IS(x) cerr << #x << " is " << x << en
#define TIMER (clock()*1.0/CLOCKS_PER_SEC)
#define int long long

using namespace std;

template<class A, class B, class C> struct Triple { A first; B second; C third;
    bool operator<(const Triple& t) const { if (fi != t.fi) return fi < fi.st; if (se != t.se) return se < t.se; return th < t.th; } };


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



bool iss_ll(ll &__1,ll &__2){ return INF64/__1>=__2;}
bool equal(double _1,double _2){ return (abs(_1-_2)<EPS);}
bool iss_sqr(int &__1){ll __2=sqrt(__1); return __2*__2==__1;};
bool iss_prime(ll __1){for (int i=2; i*i<=__1; ++i) if (!(__1%i)) return 0; return 1;}
int gcd(int __1,int __2){ while (__1 && __2) if (__1>__2)  __1=__1%__2; else __2=__2%__1; return __1+__2;}
int lcm(int &__1,int &__2){ return __1*__2/(gcd(__1, __2));}
int sq_cube(ll x){if (x==0) return 1;int l=0,r=2e6;while (l+1<r){int m=(l+r)/2;if (m*m*m>x) r=m;else l=m;}return l;}
int bp(int a,int b,int &md){int res=1;while (b) {if (b&1) res*=a;a*=a;a%=md;res%=md;b>>=1;}return res;}

vector <int> z_function(string &s){
    int n=SZ(s);
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

#define  maxN 500200

char arr[maxN];

void s(){
    
    int a,b;
    cin>>a>>b;
    string s;
    cin>>s;
    int n=s.size();
    for (int i=0; i<n; ++i) arr[i+1]=s[i];
    vector<int> VEC;
    int len=0;
    arr[n+1]='P';
    for (int i=1; i<=n+1; ++i){
        if (arr[i]!='.'){
            if (len>0) VEC.push_back(len);
            len=0;
        }else{
            ++len;
        }
    }
    for (int i:VEC){
        if (i>=b && i<a){
            cout<<"NO"<<en;
            return;
        }
    }
    vector<int> bad;
    for (int i:VEC){
        if (i>=2*b){
            bad.push_back(i);
        }
    }
    if (bad.size()>1){
        cout<<"NO"<<en;
        return;
    }
    if (bad.size()==0){
        int cnt=0;
        for (int i:VEC) if (i>=a) ++cnt;
        if (cnt%2){
            cout<<"YES"<<en;
        }else
            cout<<"NO"<<en;
        return;
    }else{
        int cnt=0;
        int x=bad.front();
        vector<int> can_make_step;
        for (int i:VEC) if (i>=a) can_make_step.push_back(i);
        if (can_make_step.size()==0){
            cout<<"NO"<<en;
            return;
        }
        for (int i=1; i<=x-a+1; ++i){
            int y=i-1;
            int z=x-y-a;
            cnt=can_make_step.size()-1;
            if (y>=b && y<a) continue;
            if (z>=b && z<a) continue;
            if (y>=a) ++cnt;
            if (z>=a) ++cnt;
            if (y>=2*b || z>=2*b) continue;
            if (cnt%2==0){
                cout<<"YES"<<en;
                return;
            }
        }
        cout<<"NO"<<en;
        return;
    }
}

signed main(void){
    

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    while (q--) {
        s();
    }
    return 0;
}




