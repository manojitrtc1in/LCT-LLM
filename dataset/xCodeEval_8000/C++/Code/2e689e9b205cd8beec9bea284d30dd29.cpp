






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
int main() {
	ifstream fin("cowart.in");
	ofstream fout("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin >> t;
	while (t--) {
		ll n, k, sum = 0;
		cin >> n >> k;
		vector<ll>a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		if (sum < k) {
			cout << -1 << endl;
		}
		else {
			vector<ll>b, b2;
			for (int i = 0; i < n; i++) {
				if (a[i] == 1) {
					b.push_back(i + 1ll);
				}
			}
			ll p = 1;
			for (int i = n - 1; i >= 0; i--) {
				if (a[i] == 1) {
					b2.push_back(p);
				}
				p++;
			}
			ll otv = LLONG_MAX;
			if (b.size() == k) {
				cout << 0 << endl;
			}
			else {
				n = b.size();
				ll otv = b2[n - k - 1];
				p = n - k;
				for (int i = 1; i <= n - k; i++) {
					ll p1 = b[i - 1];
					ll c = p - i, p2 = 0;
					if (c > 0) {
						p2 = b2[c - 1];
					}
					otv = min(otv, p1 + p2);
				}
				cout << otv << endl;
			}
		}
	}
}

