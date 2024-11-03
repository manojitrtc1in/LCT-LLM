






#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include <iostream>
#include <cmath>
#include <iomanip>
#include <set>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <climits>
#include <ctime>
#include <queue>
#include <map>
#include <stack>
#include <unordered_set>
#define ll long long
#define f .first
#define s .second
#define mp make_pair
#define pb push_back
using namespace std;
vector<pair<ll, ll>>b;
ll pp(ll n) {
	return n * (n - 1) / 2;
}
ll bin_f(ll n, ll left, ll l) {
	l++;
	ll r = b.size() - 1;
	while (l != r) {
		ll mid = (l + r) / 2;
		if (n + b[mid]f <= left) {
			l = mid + 1;
		}
		else { r = mid; }
	}
	return l;
}
int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin >> t;
	while (t--) {
		ll n, k, l, r, otv = 0;
		cin >> n >> l >> r;
		map<ll, ll>a;
		for (int i = 0; i < n; i++) {
			cin >> k;
			a[k]++;
		}
		ll p = LLONG_MAX;
		p -= 1e9;
		a[p] = 1;
		b.clear();
		n = a.size();
		vector<ll>c(n + 1, 0);
		for (auto& i : a) {
			b.push_back(mp(i.first, i.second));
			c[b.size()] = c[b.size() - 1] + i.second;
		}
		for (int i = 0; i < n; i++) {
			c[i + 1] = c[i] + b[i]s;
		}
		for (int i = 0; i < n; i++) {
			if (b[i].first > r) { break; }
			else {
				if (b[i].first * 2 >= l && b[i].first * 2 <= r && b[i].second > 1) {
					otv += pp(b[i].second);
				}
				ll left = bin_f(b[i].first, l - 1, i);
				ll right = bin_f(b[i].first, r, i);
				otv = otv + (c[right] - c[left]) * b[i]s;

			}
		}
		cout << otv << endl;
	}
}
