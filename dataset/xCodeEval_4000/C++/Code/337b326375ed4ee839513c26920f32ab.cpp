
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <queue>
#include <array>
#include<numeric>
#include <stack>
#include <bitset>
#include <functional>

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
#define all(x) (x).begin(), (x).end()

int gcd(int x, int y){
    if (y == 0){
        return x;
    } else {
        return gcd(y, x % y);
    }
}

ll qmi(ll m, ll k, ll p){

    ll res = 1 % p, t = m;
    while (k){
        if (k&1) res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }
    return res;
}

bool cmp(ld x,ld y){
    if (abs(x-y)<=1e-9)
        return true;
    return false;
}




void solve(){
    int n, q;
    cin >> n >> q;
    vector<int>a(n);
    vector<int>s(n + 1, 0);
    vector<int>ans(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    s[n - 1] = 1;
    for (int i = n - 2; i >=0 ; i--) {
        if (a[i] > s[i + 1]){
            s[i] = s[i + 1] + 1;
        } else{
            s[i] = s[i + 1];
        }
    }
    for (int i = 0; i < n; i++) {
        if (q >= s[i]){
            for (int j = i; j < n; j++) {
                ans[j] = 1;
            }
            break;
        } else if (a[i] <= q){
            ans[i] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i];
    }
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int kase;
    cin >> kase;
    while (kase--) {
        solve();
    }
    return 0;
}