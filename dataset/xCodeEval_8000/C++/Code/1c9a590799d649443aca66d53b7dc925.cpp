﻿






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
		ll n, k;
		cin >> n >> k;
		vector<ll>a(n), b;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i < n; i++) {
			if (a[i - 1] / a[i] >= 2) {
				b.push_back(i);
			}
		}
		k++;
		ll p = 0, otv = 0;
		for (auto& i : b) {
			ll dl = i - p;
			if (dl >= k) {
				otv = otv + dl - k + 1;
			}
			p = i;
		}
		ll dl = n - p;
		if (dl >= k) {
			otv = otv + dl - k + 1;
		}
		cout << otv << endl;
	}
}
