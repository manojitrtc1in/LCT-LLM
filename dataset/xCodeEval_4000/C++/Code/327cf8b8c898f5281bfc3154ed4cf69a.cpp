






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
	ll t;
	cin >> t;
	while (t--) {
		ll n, m, k;
		cin >> n >> m;
		vector<ll>otv(n, 0);
		vector<vector<ll>>a(n + 1);
		for (int i = 0; i < n; i++) {
			cin >> k;
			a[k].push_back(i);
		}
		queue<ll>b;
		for (int i = 0; i <= n; i++) {
			if (a[i].size() >= m) {
				for (int j = 0; j < m; j++) {
					otv[a[i][j]] = j + 1ll;
				}
			}
			else {
				for (auto& j : a[i]) {
					b.push(j);
				}
			}
		}
		while (b.size() >= m) {
			for (int i = 0; i < m; i++) {
				otv[b.front()] = i + 1ll;
				b.pop();
			}
		}
		for (int i = 0; i < n; i++) {
			cout << otv[i] << ' ';
		}cout << '\n';
	}
}
