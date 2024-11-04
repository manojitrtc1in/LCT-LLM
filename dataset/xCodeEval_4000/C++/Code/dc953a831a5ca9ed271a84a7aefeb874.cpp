






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
int main()
{
	ifstream fin("cowart.in");
	ofstream fout("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n;
		vector<ll>a(n), b(n, -1);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		ll pos1 = 0, pos2 = n / 2;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				b[i] = a[pos1];
				pos1++;
			}
			else { b[i] = a[pos2]; pos2++; }
		}
		bool kl = 1, kl1 = 0, kl2 = 0;
		swap(a, b);
		if ((a[0] > a[1] && a[0] > a[n - 1]) || (a[0] < a[1] && a[0] < a[n - 1])) {
			kl1 = 1;
		}
		if ((a[n - 1] > a[0] && a[n - 1] > a[n - 2]) || (a[n - 1] < a[n - 2] && a[n - 1] < a[0])) {
			kl2 = 1;
		}
		for (int i = 1; i < n - 1; i++) {
			if ((a[i] > a[i + 1] && a[i] > a[i - 1]) || (a[i] < a[i + 1] && a[i] < a[i - 1])) {
				continue;
			}
			else { kl = 0; break; }
		}
		if (kl == 0 || kl1 == 0 || kl2 == 0) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
			for (auto& i : a) {
				cout << i << ' ';
			}cout << endl;
		}
	}
}

