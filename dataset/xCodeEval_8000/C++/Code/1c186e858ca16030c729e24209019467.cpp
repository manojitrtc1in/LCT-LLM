






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
bool comp(ll a, ll b) {
	return a > b;
}
bool can(ll k, vector<ll>& pref, ll c, ll d, ll n) {
	ll c1 = 0, day = 0;
	k++;
	c1 = floor(c / pref[min(n, k)]) * pref[min(n, k)];
	day = floor(c / pref[min(n, k)]) * k;
	if (c1 < c) {
		ll l = 0, r = n;
		while (l != r) {
			ll mid = (l + r) / 2;
			if (c1 + pref[mid] < c) {
				l = mid + 1;
			}
			else { r = mid; }
		}
		day += l;
	}
	else {
		day -= max(0ll, k - n);
	}
	if (day <= d) { return true; }
	else { return false; }
}
int main() {
	

	ifstream fin("input.txt");
	ofstream fout("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t = 1;
	cin >> t;
	while (t--) {
		ll n, c, d;
		cin >> n >> c >> d;
		vector<ll>a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end(), comp);
		vector<ll>pref(n + 2);
		pref[0] = 0;
		for (int i = 0; i < n; i++) {
			pref[i + 1] = pref[i] + a[i];
		}
		pref[n + 1] = c + 1;
		if (pref[min(d, n)] >= c) {
			cout << "Infinity" << endl;
		}
		else {
			if (a[0] * d < c) {
				cout << "Impossible" << endl;
			}
			else {
				ll l = 0, r = 1e9;
				while (l != r) {
					ll mid = (l + r) / 2;
					if (can(mid, pref, c, d, n)) {
						l = mid + 1;
					}
					else { r = mid; }
				}
				cout << l - 1 << endl;
			}
		}
	}
}


