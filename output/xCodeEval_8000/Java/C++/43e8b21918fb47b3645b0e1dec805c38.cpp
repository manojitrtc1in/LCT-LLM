#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define trav(a, x) for(auto& a : x)
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = (b)-1; i >= a; --i)
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vpii> vvpii;

const int gigamod = 1000000007;

struct FastReader {
    FastReader() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
} fr;

struct CFPS {
    static const int gigamod = 1000000007;
    static int t;
    static double epsilon;
    static bool isPrime[1000001];
    static int smallestFactorOf[1000001];

    static void main() {
        int n, mod;
        cin >> n >> mod;

        vector<ll> dp(n + 1);
        dp[n] = 1;

        for (int i = n - 1; i > 0; i--) {
            dp[i] += dp[i + 1];
            dp[i] %= mod;

            for (ll div = 1; div * i <= n; div++) {
                int lb = div * i;
                int ub = min(div * (i + 1) - 1, (ll)n);
                ll segSum = dp[lb];
                if (ub + 1 <= n)
                    segSum -= dp[ub + 1];
                dp[i] += segSum;
                dp[i] %= mod;
            }

            dp[i] += dp[i + 1];
            dp[i] %= mod;
        }

        cout << (dp[1] - dp[2] + mod) % mod << endl;
    }
};

int CFPS::t = 1;
double CFPS::epsilon = 0.00000001;
bool CFPS::isPrime[1000001];
int CFPS::smallestFactorOf[1000001];

int main() {
    CFPS::main();
    return 0;
}
