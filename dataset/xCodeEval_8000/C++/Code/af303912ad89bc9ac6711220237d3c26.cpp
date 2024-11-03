






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
vector<vector<ll>>g;
ll timer = 0, kol1, kol2, otv;
vector<ll>visit, ans1, ans2;
string st;
void dfs(ll v) {
	visit[v] = timer;
	for (auto& i : g[v]) {
		if (visit[i] != timer) {
			dfs(i);
			ans1[v] += ans1[i];
			ans2[v] += ans2[i];
		}
	}
	if (st[v] == 'W') { ans1[v]++; }
	else { ans2[v]++; }
	if (ans1[v] == ans2[v]) { otv++; }
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
		ll n, m;
		cin >> n;
		g.resize(n);
		visit.resize(n);
		ans1.resize(n, 0);
		ans2.resize(n, 0);
		for (int i = 0; i < n; i++) {
			ans1[i] = 0;
			ans2[i] = 0;
		}
		for (int i = 1; i < n; i++) {
			cin >> m;
			g[m - 1].pb(i);
		}
		cin >> st;
		otv = 0;
		++timer;
		dfs(0);
		cout << otv << endl;
		g.clear();
	}


}
