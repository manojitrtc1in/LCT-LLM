






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
	ll t = 1;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vector<ll>a(n);
		map<ll, ll>b;
		bool zero = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			while (a[i] % 10 != 2 && a[i] % 10 != 0) {
				a[i] = a[i] + a[i] % 10;
			}
			b[a[i]]++;
			if (a[i] % 10 == 0) { zero = 1; }
		}
		bool kl = 0;
		if (b.size() != 1 && zero==0) {
			ll mx = a[0];
			for (int i = 1; i < n; i++) {
				if ((mx - a[i]) % 20 == 0 || (mx - a[i]) % 20 == 2 || (mx - a[i]) % 20 == 6 || (mx - a[i]) % 20 == 14) {
					continue;
				}
				else { kl = 1; break; }
			}
		}
		if (b.size() != 1 && zero == 1) kl = 1;
		if (kl == 1) {
			cout << "NO" << endl;
		}
		else { cout << "YES" << endl; }
	}
}


