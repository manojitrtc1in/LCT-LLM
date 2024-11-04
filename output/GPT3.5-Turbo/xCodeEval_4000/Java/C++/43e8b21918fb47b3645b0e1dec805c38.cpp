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
#include <iomanip>
#include <bitset>
#include <numeric>
#include <cassert>
#include <climits>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define sz(a) int((a).size())
#define mem(a, x) memset(a, x, sizeof(a))
#define endl '\n'
#define debug(x) cout << #x << " = " << x << endl
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define debug3(x, y, z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define debug4(x, y, z, w) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #w << " = " << w << endl

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

const int gigamod = 1000000007;

class FastReader {
public:
    FastReader() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    int nextInt() {
        int num;
        cin >> num;
        return num;
    }

    long long nextLong() {
        long long num;
        cin >> num;
        return num;
    }

    double nextDouble() {
        double num;
        cin >> num;
        return num;
    }

    string nextString() {
        string s;
        cin >> s;
        return s;
    }
};

int main() {
    fastio;
    FastReader fr;

    int t = 1;
    double epsilon = 0.00000001;

    for (int tc = 0; tc < t; tc++) {
        int n = fr.nextInt();
        long long mod = fr.nextLong();

        vector<long long> dp(n + 1);
        dp[n] = 1;

        for (int i = n - 1; i > 0; i--) {
            dp[i] += dp[i + 1];
            dp[i] %= mod;

            for (long long div = 1; div * i <= n; div++) {
                int lb = div * i;
                int ub = min(div * (i + 1) - 1, n);
                long long segSum = dp[lb];
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

    return 0;
}
