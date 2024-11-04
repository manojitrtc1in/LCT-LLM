#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <set>
#include <map>
#include <stack>
#include <math.h>
#include <time.h>
#include <numeric>
#include <array>
#include <functional>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef array<ll, 3> arr3;


struct BIT {
	int n;
	vector<int> v;

	BIT(int _n) : n(_n), v(_n + 1, 0) {}

	int lowbit(int x) { return x & (-x); }

	void add(int i, int k) {
		while (i <= n) {
			v[i] += k;
			i += lowbit(i);
		}
	}

	int getSum(int i) {
		int res = 0;
		while (i > 0) {
			res += v[i];
			i -= lowbit(i);
		}
		return res;
	}

	int getSum(int l, int r) {
		return getSum(r) - getSum(l - 1);
	}
};
 
const ll base = 1e9 + 7;
 
ll pw(ll a, ll b) {
    ll t = a, r = 1;
    while (b) {
        if (b & 1) r = (r * t) % base;
        t = (t * t) % base;
        b >>= 1;
    }
    return r;
}
 
ll inv(ll x) {
    return pw(x, base - 2);
}
 
const int maxn = 1e6 + 42;
 
ll F[maxn], RF[maxn];
 
ll fact(ll n) {
    return F[n] ? F[n] : F[n] = n ? n * fact(n - 1) % base : 1;
}
ll rfact(ll n) {
    return RF[n] ? RF[n] : RF[n] = inv(fact(n));
}
 
ll nCr(ll n, ll r) {
    return fact(n) * rfact(r) % base * rfact(n - r) % base;
}

bool dp[41][41][41][41];
void solve() {
	ll T;
	cin >> T;
	const ll base = 1e9 + 7;
	for (ll ii = 1; ii <= T; ++ii) {
		int n, a, b;
		string s;
		cin >> n >> a >> b >> s;
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j < a; ++j) {
				for (int k = 0; k < b; ++k) {
					for (int l = 0; l <= n; ++l) {
						dp[i][j][k][l] = false;
					}
				}
			}
		}
		dp[0][0][0][0] = true;
		for (int i = 0; i < n; ++i) {
			int x = s[i] - '0';
			for (int j = 0; j < a; ++j) {
				for (int k = 0; k < b; ++k) {
					for (int l = 0; l <= i; ++l) {
						if (dp[i][j][k][l] == false) continue;
						dp[i + 1][(j * 10 + x) % a][k][l + 1] = true;
						dp[i + 1][j][(k * 10 + x) % b][l] = true;
					}
				}
			}
		}
		bool res = false;
		for (int i = 1; i < n; ++i) res |= dp[n][0][0][i];
		if (res) {
			int diff = 100;
			int red = -1;
			for (int l = 1; l < n; ++l) {
				if (dp[n][0][0][l] == false) continue;
				if (abs(l - (n - l)) < diff) {
					diff = abs(2 * l - n);
					red = l;
				}
			}
			string str;
			int state[4] = { n, 0, 0, red };
			for (int i = n - 1; i >= 0; --i) {
				int x = s[i] - '0';
				for (int j = 0; j < a; ++j) {
					if ((j * 10 + x) % a == state[1] && dp[i][j][state[2]][state[3] - 1]) {
						state[1] = j;
						state[3]--;
						str.push_back('R');
						goto CON;
					}
				}
				for (int k = 0; k < b; ++k) {
					if ((k * 10 + x) % b == state[2] && dp[i][state[1]][k][state[3]]) {
						state[2] = k;
						str.push_back('B');
						goto CON;
					}
				}
				CON:
				continue;
			}
			reverse(str.begin(), str.end());
			cout << str << endl;
		}
		else cout << "-1\n";
	}
}

int main() {
	solve();
    return 0;
}












































































































































































































