#ifdef DEBUG
	#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>
#include <climits>
#include <stack>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <random>
#include <cstring>
#include <chrono>





using namespace std;



typedef long long ll;
typedef long double ld;






mt19937 rnd('r' + 'o' + 'b' + 'i' + 'v' + 'i' + 'r' + 't');
const int BUBEN = 400;
const int BUBEN3D = 2100;
const int BASE = 29;
const int MOD = (int)1e9 + 7;
const int BASE1 = 179;
const int MOD1 = (int)1e9 + 9;
const int SMALL_INT = (int)1e9 + 228;
const ll INF = (ll)(1e18) + 228;

#ifndef _getchar_nolock
char _getchar_nolock() {
	return getchar_unlocked();
}
#endif

inline ll gcd(ll a, ll b) {
	while (b) {	
		a %= b;
		swap(a, b);
	}
	return a;
}

inline int bin_pow(int a, ll n, int mod) {
	if (n == 0) {
		return 1;
	}
	if (n % 2 == 0) {
		int b = bin_pow(a, n / 2, mod);
		return (ll)b * b % mod;
	}
	else {
		return (ll)a * bin_pow(a, n - 1, mod) % mod;
	}
}






























































#define int ll

struct S { 
	vector<pair<int, int>> pref1;
	vector<pair<int, int>> pref2;
	vector<pair<int, int>> suff1;
	vector<pair<int, int>> suff2;
};

vector<pair<pair<int, int>, pair<int, int>>> arr;
vector<set<int>> query;
map<pair<int, int>, pair<pair<int, int>, pair<int, int>>> mm;
vector<int> ans;


int MN(int a, int b, int c, int d) {
	return min(min(a, b), min(c, d));
}

S build(int l, int r) {
	if (l + 1 == r) {
		vector<pair<int, int>> arr1(1, {0, abs(arr[l].first.first - arr[l].second.first) + abs(arr[l].first.second - arr[l].second.second)});
		vector<pair<int, int>> arr2(1, {abs(arr[l].first.first - arr[l].second.first) + abs(arr[l].first.second - arr[l].second.second), 0});

		while (!query[l].empty()) {
			int x = *(query[l].begin());
			if (x < r) {
				mm[{l, x}] = {arr1[0], arr2[0]};
				query[l].erase(query[l].begin());
			} else {
				break;
			}
		}
		
		return {arr1, arr2, arr1, arr2};
	}
	int mid = (l + r) / 2;
	S a = build(l, mid);
	S b = build(mid, r);
	pair<int, int> G = {};
	G.first = 1 + abs(arr[mid - 1].first.first - arr[mid].first.first);
	pair<int, int> H = {};
	H.second = 1 + abs(arr[mid - 1].second.second - arr[mid].second.second);

	G.second = min(H.second + abs(arr[mid - 1].first.first - arr[mid - 1].second.first) + abs(arr[mid - 1].first.second - arr[mid - 1].second.second),
					1 + abs(arr[mid].second.first - arr[mid - 1].first.first) + abs(arr[mid].second.second - (arr[mid - 1].first.second + 1)));
	G.second = min(G.second, G.first + abs(arr[mid].first.first - arr[mid].second.first) + abs(arr[mid].first.second - arr[mid].second.second));
	H.first = min(G.first + abs(arr[mid - 1].first.first - arr[mid - 1].second.first) + abs(arr[mid - 1].first.second - arr[mid - 1].second.second),
					1 + abs(arr[mid].first.first - (arr[mid - 1].second.first + 1)) + abs(arr[mid].first.second - arr[mid - 1].second.second));
	H.first = min(H.first, H.second + abs(arr[mid].first.first - arr[mid].second.first) + abs(arr[mid].first.second - arr[mid].second.second));

	for (int i = l; i < mid; i++) {
		while (!query[i].empty()) {
			int x = *(query[i].begin());
			if (x < r) {
				int dist1 = MN(a.suff1[i - l].first + G.first + b.pref1[x - mid].first, a.suff1[i - l].first + G.second + b.pref2[x - mid].first,
								a.suff1[i - l].second + H.first + b.pref1[x - mid].first, a.suff1[i - l].second + H.second + b.pref2[x - mid].first);
				int dist2 = MN(a.suff1[i - l].first + G.first + b.pref1[x - mid].second, a.suff1[i - l].first + G.second + b.pref2[x - mid].second,
								a.suff1[i - l].second + H.first + b.pref1[x - mid].second, a.suff1[i - l].second + H.second + b.pref2[x - mid].second);

				int dist3 = MN(a.suff2[i - l].first + G.first + b.pref1[x - mid].first, a.suff2[i - l].first + G.second + b.pref2[x - mid].first,
								a.suff2[i - l].second + H.first + b.pref1[x - mid].first, a.suff2[i - l].second + H.second + b.pref2[x - mid].first);
				int dist4 = MN(a.suff2[i - l].first + G.first + b.pref1[x - mid].second, a.suff2[i - l].first + G.second + b.pref2[x - mid].second,
								a.suff2[i - l].second + H.first + b.pref1[x - mid].second, a.suff2[i - l].second + H.second + b.pref2[x - mid].second);

				

				

				

				

				

				


				

				


				mm[{i, x}] = {{dist1, dist2}, {dist3, dist4}};
				query[i].erase(query[i].begin());
			} else {
				break;
			}
		}
	}

	vector<pair<int, int>> pref1(r - l), pref2(r - l), suff1(r - l), suff2(r - l);
	for (int i = 0; i < mid - l; i++) {
		pref1[i] = a.pref1[i];
		pref2[i] = a.pref2[i];
	}
	for (int i = mid - l; i < r - l; i++) {
		int dist1 = MN(a.pref1.back().first + G.first + b.pref1[i - (mid - l)].first, a.pref1.back().first + G.second + b.pref2[i - (mid - l)].first,
						a.pref1.back().second + H.first + b.pref1[i - (mid - l)].first, a.pref1.back().second + H.second + b.pref2[i - (mid - l)].first);

		int dist2 = MN(a.pref1.back().first + G.first + b.pref1[i - (mid - l)].second, a.pref1.back().first + G.second + b.pref2[i - (mid - l)].second,
						a.pref1.back().second + H.first + b.pref1[i - (mid - l)].second, a.pref1.back().second + H.second + b.pref2[i - (mid - l)].second);
		

		

		

		
		int dist3 = MN(a.pref2.back().first + G.first + b.pref1[i - (mid - l)].first, a.pref2.back().first + G.second + b.pref2[i - (mid - l)].first,
						a.pref2.back().second + H.first + b.pref1[i - (mid - l)].first, a.pref2.back().second + H.second + b.pref2[i - (mid - l)].first);

		int dist4 = MN(a.pref2.back().first + G.first + b.pref1[i - (mid - l)].second, a.pref2.back().first + G.second + b.pref2[i - (mid - l)].second,
						a.pref2.back().second + H.first + b.pref1[i - (mid - l)].second, a.pref2.back().second + H.second + b.pref2[i - (mid - l)].second);


		

		



		pref1[i] = {dist1, dist2};
		pref2[i] = {dist3, dist4};	
	}
	for (int i = mid - l; i < r - l; i++) {
		suff1[i] = b.suff1[i - (mid - l)];
		suff2[i] = b.suff2[i - (mid - l)];
	}
	for (int i = mid - l - 1; i >= 0; i--) {
		int dist1 = MN(b.suff1[0].first + G.first + a.suff1[i].first, b.suff1[0].first + H.first + a.suff1[i].second,
						b.suff2[0].first + G.second + a.suff1[i].first, b.suff2[0].first + H.second + a.suff1[i].second);

		int dist2 = MN(b.suff1[0].second + G.first + a.suff1[i].first, b.suff1[0].second + H.first + a.suff1[i].second,
						b.suff2[0].second + G.second + a.suff1[i].first, b.suff2[0].second + H.second + a.suff1[i].second);

		

		


		int dist3 = MN(b.suff1[0].first + G.first + a.suff2[i].first, b.suff1[0].first + H.first + a.suff2[i].second,
						b.suff2[0].first + G.second + a.suff2[i].first, b.suff2[0].first + H.second + a.suff2[i].second);

		int dist4 = MN(b.suff1[0].second + G.first + a.suff2[i].first, b.suff1[0].second + H.first + a.suff2[i].second,
						b.suff2[0].second + G.second + a.suff2[i].first, b.suff2[0].second + H.second + a.suff2[i].second);

		

		


		suff1[i] = {dist1, dist2};
		suff2[i] = {dist3, dist4};
	}

	return {pref1, pref2, suff1, suff2};
}

signed main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	

	

	

	

	

	

	

	

	

	

	

	

	int n;
	cin >> n;
	

	for (int i = 0; i + 1 < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		arr.push_back({{y1, x1}, {y2, x2}});
	}
	int q;
	cin >> q;
	ans.resize(q);
	query.resize(n);
	vector<vector<int>> qq(q);
	for (int j = 0; j < q; j++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		swap(y1, x1);
		swap(y2, x2);
		int ooo1 = max(x1, y1) - 1;
		int ooo2 = max(x2, y2) - 1;
		if (ooo1 > ooo2) {
			swap(x1, x2);
			swap(y1, y2);
			swap(ooo1, ooo2);
		}
		if (ooo1 == ooo2) {
			ans[j] = abs(x1 - x2) + abs(y1 - y2);
		} else {
			query[ooo1].insert(ooo2 - 1);
		}
		qq[j] = {x1, y1, x2, y2};
	}
	build(0, n - 1);
	

	

	

	for (int i = 0; i < q; i++) {
		int x1 = qq[i][0], y1 = qq[i][1], x2 = qq[i][2], y2 = qq[i][3];
		int ooo1 = max(x1, y1) - 1;
		int ooo2 = max(x2, y2) - 1;
		if (ooo1 != ooo2) {
			ooo2--;
			int dist1 = mm[{ooo1, ooo2}].first.first;
			int dist2 = mm[{ooo1, ooo2}].first.second;
			int dist3 = mm[{ooo1, ooo2}].second.first;
			int dist4 = mm[{ooo1, ooo2}].second.second;

			
			ans[i] = MN(dist1 + abs(arr[ooo1].first.first - x1) + abs(arr[ooo1].first.second - y1) + abs(x2 - arr[ooo2].first.first) + abs(y2 - (arr[ooo2].first.second + 1)),
						dist2 + abs(arr[ooo1].first.first - x1) + abs(arr[ooo1].first.second - y1) + abs(x2 - (arr[ooo2].second.first + 1)) + abs(y2 - arr[ooo2].second.second),
						dist3 + abs(arr[ooo1].second.first - x1) + abs(arr[ooo1].second.second - y1) + abs(x2 - arr[ooo2].first.first) + abs(y2 - (arr[ooo2].first.second + 1)), 
						dist4 + abs(arr[ooo1].second.first - x1) + abs(arr[ooo1].second.second - y1) + abs(x2 - (arr[ooo2].second.first + 1)) + abs(y2 - arr[ooo2].second.second)) + 1;

		}
	}

	for (int i = 0; i < q; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}