






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
	

	ifstream fin("input.txt");
	ofstream fout("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t = 1;
	cin >> t;
	while (t--) {
		ll n;
		map<ll, ll>a;
		cin >> n;
		ll x;
		for (int i = 0; i < n; i++) {
			cin >> x;
			a[x]++;
		}
		ll l=0, r=0;
		for (auto& i : a) {
			if (i.second > 1) {
				l++;
				r++;
			}
			else {
				if (l > r) {
					swap(l, r);
				}
				l++;
			}
		}
		if (l != r) { l++; r++; }
		cout << max(1ll, min(l, r)) << endl;
	}
}


