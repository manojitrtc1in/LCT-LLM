






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
	

	

	

	ll n;
	cin >> n;
	vector<ll>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll k1, k2, otv1, otv = LLONG_MAX;
	otv = min(otv, otv1);
	ll otv2;
	for (int i = 1; i < n - 1; i++) {
		ll k1 = a[i - 1];
		ll k2 = a[i + 1];
		if (k1 < k2) {
			swap(k1, k2);
		}
		if (a[i] / 2 >= k2) {
			otv = min(otv, k2 + (k1 - k2 + 1) / 2);
		}
	}
	for (int i = 0; i < n - 1; i++) {
		k1 = a[i];
		k2 = a[i + 1];
		if (k1 < k2) { swap(k1, k2); }
		otv1 = (k1 + 1) / 2;
		if (k2 - otv1 > 0) {
			otv1 = otv1 + (k2 + 1 - otv1) / 2;
		}
		if ((k1 + 1) / 2 >= k2) {
			otv2 = (k1 + 1) / 2;
		}else{ otv2 = (k1 + k2 + 2) / 3; }
		
		otv1 = min(otv1, otv2);
		otv = min(otv, otv1);
	}
	sort(a.begin(), a.end());
	otv = min(otv, (a[0] + 1) / 2 + (a[1] + 1) / 2);
	cout << otv << endl;
}
