
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <queue>
#include<numeric>
#include <array>
#include <stack>
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
#define endl '\n'
#define Endl '\n'
#define ENDL '\n'
#define tin int
#define itn int
#define tni int
#define nit int
#define nti int
int gcd(int x, int y){
    if (y == 0){
        return x;
    } else {
        return gcd(y, x % y);
    }
}
int quickPower(int a, int b)

{
    int ans = 1, base = a;

    while(b > 0)

        {
        if(b & 1)

            ans *= base;

 
            base *= base;

            b >>= 1;

        }
    return ans;
}
bool cmp(ld x,ld y){
    if (abs(x-y)<=1e-9)
        return true;
    return false;
}
 
ld Power(ld base,int exponent){
    ld sum=1;
    ld curr=base;
    int n;
    if(exponent>0)
        n=exponent;
    else if(exponent<0){
        if(base==0)
            exit(EXIT_FAILURE);
        n=-exponent;
    }
    else if(exponent==0){
        return 1;
    }
    while(n !=0){
        if((n&1)==1)
            sum*=curr;
        curr*=curr;
        n>>=1;
    }
    return (exponent>0)?sum : (ld ( 1)/ sum);
}





 
pll a[200005];
const int mod = 998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int kase;
    cin>>kase;
    while(kase--){
        ll n, m, k, s;
        cin>> n >> m >> k >> s;
        ll ans = 1;
        map<ll,ll>hh, tt;
        for (int i = 1; i <= s; i++) {
            cin>>a[i].first>>a[i].second;
        }
        ll h = 0;
        ll t = 0;
        for (ll i = s; i >= 1; i--) {
            if (h == n || t == m)
                break;
            int f1 = 0;
            if (!hh[a[i].first]) {
                f1 = 1;
                hh[a[i].first] = 1;
                h++;
            }
            if (!tt[a[i].second]) {
                f1 = 1;
                tt[a[i].second] = 1;
                t++;
            }
            if (f1)
                ans = ans * k % mod;
 
        }
        printf("%lld\n",ans);
    }
    return 0;
}