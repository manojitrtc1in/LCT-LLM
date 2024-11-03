#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz size()
#define ll long long
#define ld long double
#define all(_v) _v.begin(), _v.end()
#define pii pair <int, int>
#define pll pair <ll, ll>
#define veci vector <int>
#define vecll vector <ll>


const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const double PI = 3.1415926535897932384626433832795;
const double eps = 1e-9;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;

const int MAXN = 2e5 + 10;
int a[MAXN], b[MAXN];
int pos[MAXN];
bool was[MAXN];



void solve() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i], pos[a[i]] = i;
    for(int i = 1; i <= k; ++i) cin >> b[i], was[b[i]] = 1;
    int ans = 1;
    for(int i = 1; i <= k; ++i) {
        int p = pos[b[i]];
        int mul = 0;
        if(p > 1 && !was[a[p - 1]]) ++mul;
        if(p < n && !was[a[p + 1]]) ++mul;
        ans = ans * 1ll * mul % MOD2;
        was[b[i]] = 0;
    }
    cout << ans;
    for(int i = 1; i <= n; ++i) was[i] = pos[i] = a[i] = b[i] = 0;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve(), cout << '\n';
    return 0;
}
