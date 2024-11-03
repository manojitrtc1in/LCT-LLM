






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
		cin >> n;
		vector<ll>a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i != 0) {
				if (a[i - 1] == a[i]) {
					n--;
					i--;
				}
			}
		}
		if (n == 1) {
			cout << "YES" << endl;
		}
		else {
			ll kol = 0;
			for (int i = 1; i < n - 1; i++) {
				if (a[i - 1] > a[i] && a[i] < a[i + 1])kol++;
			}
			if (a[0] < a[1])kol++;
			if (a[n - 2] > a[n - 1])kol++;
			if (kol == 1) {
				cout << "YES" << endl;
			}
			else { cout << "NO" << endl; }
		}
	}
}


