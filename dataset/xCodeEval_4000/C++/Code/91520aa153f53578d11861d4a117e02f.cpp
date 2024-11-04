




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

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef set<int> seti;
typedef pair<double, double> pdd;
typedef long double ld;



const double EPS=0.000000001;
const double INFD32=1000000000;
const ll INF64=1000000000000000000;
const int INF32=1000000000;

#define maxN 100300

int to_int(string s){
    int x=0;

    for (int i=0; i<s.size(); ++i){
        x*=10;
        x+=(s[i]-'0');
    }
    return x;
    
}

int st10[20];

void solve(){
    string s;
    cin>>s;
    st10[0]=1;
    for (int i=1; i<20; ++i) st10[i]=st10[i-1]*10;
    REVERSE(s);
    while (s.back()<'0' || s.back()>'9') s.pop_back();
    REVERSE(s);
    vector<int> VEC;
    for (int i=s.size(); i>0; --i){
        
        VEC.push_back(to_int(s));
        REVERSE(s);
        s.pop_back();
        REVERSE(s);
    }
    REVERSE(VEC);
    

    

    set<int> SET;
    int ans=0;
    for (int i=0; i<VEC.size(); ++i){
        int x=VEC[i];
        while (x<1989 || SET.count(x)){
            x+=st10[i+1];
        }
        

        SET.insert(x);
        ans=x;
    }
    cout<<ans<<en;
}

signed main(void){
    

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
}




