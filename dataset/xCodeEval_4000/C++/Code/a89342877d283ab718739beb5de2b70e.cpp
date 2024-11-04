#include<bits/stdc++.h>
#define ll long long
#define el endl
#define ld long double
#define pi 3.1415926536
#define Covid ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const ll N=5e5;


vector<ll>v;
void rec(ll x=0){
    if(x>1e9)return;
    v.push_back(x);
    rec(x*10+4);
    rec(x*10+7);
}

   bool cmp(string& s1){
        string s2="Hello,World!";
        if(s1!=s2)return 0;
       else return 1;
}

ld a[N];
int main() {
    Covid
    ll tc;
    cin >> tc;
    while (tc--) {
        ll n;
        bool f1 = 0;
        cin >> n;
        ll ans = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i != 0 && i != n - 1 && a[i] != 1)f1 = 1;
            if (i != 0 && i != n - 1) {
                ans += (ceil(a[i] / 2));
                cnt++;
            }
        }
        if (!f1)cout << -1 << el;
        else if (cnt == 1 && int(a[1])%2==1)cout << -1 << el;
        else cout << ans << el;
    }
        return 0;
}

					 			 								 			 			   	