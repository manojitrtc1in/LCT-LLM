#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <numeric>
#include <functional>
#include <random>
#include <chrono>
#include <climits>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define int long long
#define double long double
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define mii map<int, int>
#define mci map<char, int>
#define msi map<string, int>
#define si set<int>
#define usi unordered_set<int>
#define umsi unordered_map<string, int>
#define umci unordered_map<char, int>
#define rep(i, a, b) for(int i=a; i<b; i++)
#define repd(i, a, b) for(int i=a; i>=b; i--)
#define trav(a, x) for(auto& a : x)
#define sz(x) (int)(x.size())
#define MOD 1000000007
#define INF 1e18

int power(int a, int b, int m) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int modInverse(int a, int m) {
    return power(a, m - 2, m);
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int nCr(int n, int r) {
    if (r > n - r) {
        r = n - r;
    }
    int res = 1;
    for (int i = 0; i < r; i++) {
        res = (res * (n - i)) % MOD;
        res = (res * modInverse(i + 1, MOD)) % MOD;
    }
    return res;
}

void solve() {
    string lng, sht;
    cin >> lng >> sht;
    int n = lng.length();
    int m = sht.length();
    int leftmost[m + 1];
    int rightmost[m + 1];
    rightmost[m] = n;

    int idx = 0;
    for (int i = 0; i < m; i++) {
        while (sht[i] != lng[idx]) {
            idx++;
        }
        leftmost[i] = idx;
        idx++;
    }
    idx = n - 1;
    for (int i = m - 1; i >= 0; i--) {
        while (sht[i] != lng[idx]) {
            idx--;
        }
        rightmost[i] = idx;
        idx--;
    }

    int ans = rightmost[0];
    for (int i = 0; i < m; i++) {
        ans = max(ans, rightmost[i + 1] - leftmost[i] - 1);
    }
    cout << ans << endl;
}

signed main() {
    fastio;

    solve();

    return 0;
}
