

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
#include <fstream>
#include <string>
#include <set>
#include <deque>
#include <queue>
#include <map>
#include <bitset>
#include <random>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;


#define endl "\n"
#define sqrt sqrtl



const ll inf = (ll)1e18 + 7;
ld eps = 1e-9;
ll mod = 1e9 + 7;

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
	cin >> t;
	while (t--) {
		ll n, i, j, mx = -inf, mx2 = -inf, id, id2;
		cin >> n;
		vector <ll> a(n);
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.rbegin(), a.rend());
		cout << a[0] + a[1] << endl;
	}
}


