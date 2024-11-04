











#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <functional>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <ctime>
#include <climits>
#include <numeric>
#define afk printf("")
#define endl '\n'
#define elif else if
#define int long long
#define done printf("DONE")
using namespace std;
typedef long long ll;
using vi = vector<int>;
using pii = pair<ll, ll>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vb=vector<bool>;
using vvi = vector<vi>;


int z1, z2;
int dxtra(int n, vvpii& g, int start, int finish, vi& dist) {
	

	vector<bool>used(n + 1, 0);
	set<pair<int, int>>s;
	dist[start] = 0;
	s.insert({ 0, start });
	while (s.size() > 0) {
		auto it = *s.begin();
		int len = it.first;
		int v = it.second;
		s.erase(*s.begin());
		used[v] = 1;
		for (auto to : g[v]) {
			s.erase({ dist[to.first], to.first });
			dist[to.first] = min(dist[to.first], len + to.second);
			if(!used[to.first] && to.first!=z1 && to.first!=z2)s.insert({dist[to.first], to.first});
		}
	}
	if (dist[finish] == INT_MAX) return -1;
	return dist[finish];
}
inline int xin() {
	int n=0;
	

	scanf("%lld", &n);
	return n;
}
void masIn(int n, int* a) {
	for (int i = 0; i < n; i++) { *a = xin(); a++; }
}
void masIn(vi& a) {
	int n = a.size();
	for (int i = 0; i < n; i++) { a[i] = xin(); }
}



string toBits(int n)
{
	string s = "";
	if (n == 2) return "10";
	while (n != 0)
	{
		char c;
		c = n % 2 + 48;
		s += c;
		n /= 2;
	}
	reverse(s.begin(), s.end());
	return s;
}
unsigned int fact(int n) {
	unsigned int sum = 1;
	for (int i = 1; i <= n; i++)sum *= i;
	return sum;
}
vector<int> min_dist_way(int n, vector<vector<pair<int, int>>>& g, int start, int finish)
{
	

	vector<int>dist(n + 1, INT_MAX);
	vector<bool>used(n + 1, false);
	set<pair<int, int>>s;
	int* parent = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		parent[i] = 0;
	}
	dist[start] = 0;
	s.insert({ 0, start });
	int rev = 0;
	while (!s.empty())
	{
		auto it = *s.begin();
		int v = it.second;
		int len = it.first;
		used[v] = 1;

		s.erase(*s.begin());
		for (auto to : g[v])
		{
			s.erase({ dist[to.first], to.first });
			if (dist[to.first] > len + to.second) parent[to.first] = v;
			dist[to.first] = min(dist[to.first], len + to.second);
			if (!used[to.first])
			{
				s.insert({ dist[to.first], to.first });
			}
		}
	}
	vector<int>res(0);
	if (dist[finish] == INT_MAX)
	{
		res.push_back(-1);
		return res;
	}
	for (int i = n; i > start; i = parent[i])
	{
		res.push_back(i);
	}
	res.push_back(start);
	reverse(res.begin(), res.end());
	return res;
}
#define MOD7 1000000007
int safe_move(int x, int n, int step=32) {
	for (int i = 0; i < n;) {
		x = (x << min(step, n-i)) % MOD7;
		i += min(step, n - i);
	}
	return x;
}
int dfs(int& n, vvi& g, vi& a, vb& used, int& v, pair<int, int> excep={0, 0}) {
	int res = a[v - 1];
	used[v] = 1;
	for (auto to : g[v])if (!used[to] && make_pair(v, to)!=excep && make_pair(to, v)!=excep)res += dfs(n, g, a, used, to, excep);
	return res;
}
struct trip {
	int a;
	int b;
	int c;
};

int simple(int x)
{
	if (x == 1 || x % 2 == 0) return 0;
	int k = 2;
	int t = sqrt(x);
	for (int i = 2; i <= t; i++)
	{
		if (x % i == 0)
		{
			k++;
			break;
		}
	}
	return k == 2;
}
int nearf(int a, int b) {
	

	return min(122 - max(a, b) + (min(a, b) - 96), max(a, b) - min(a, b));
}
void near() {
	int n = xin();
	int p = 0;
	for (int i = n-1; i >= 2; i--) {
		if (simple(i) && n%i==0) {
			p = i;
			break;
		}
	}
	

	int mn = INT_MAX;
	for (int i = n - p + 1; i <= n; i++) {
		for (int j = i-1; j >= 2; j--) {
			if (simple(j) && i%j==0) {
				mn = min(mn, i-j+1);
				

				break;
			}
		}
	}
	cout << mn;
}
int LIS(vector<int> a) {
	int n = a.size();
	vi d(n+1, INT_MAX);
	d[0] = INT_MIN;
	vi pos(n+1, -1);
	vi pre(n+1, 0);
	int res = 0;
	for (int i = 0; i < n; i++) {
		
		int x = 0;
		for (; x < n && d[x]<a[i]; x++);
		

		

		if (x == 0) continue;
		if (d[x - 1] < a[i] && a[i] < d[x]) {
			d[x] = a[i];
			pos[x] = i;
			pre[x] = pos[x - 1];
			res = max(res, x);
		}
	}
	return res;
}
void exd() {
	int a, b, ab, ba;
	cin >> a >> b >> ab >> ba;
	string s; cin >> s;
	int n = s.size();
	int pa = 0, pb = 0, pab = 0, pba = 0, aba = 0, bab = 0;
	

	for (int i = 0; i < n; i++) {
		if (i < n - 2 && s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'A') {
			aba++;
			i += 2;
			continue;
		}
		if (i < n - 2 && s[i] == 'B' && s[i + 1] == 'A' && s[i + 2] == 'B') {
			bab++;
			i += 2;
			continue;
		}
		if (i < n - 1 && s[i] == 'A' && s[i + 1] == 'B') {
			pab++;
			i++;
			continue;
		}
		if (i < n - 1 && s[i] == 'B' && s[i + 1] == 'A') {
			pba++;
			i++;
			continue;
		}
		if (s[i] == 'A') {
			pa++;
		}
		if (s[i] == 'B') pb++;
	}
	

	while (a > 0) {
		if (pa > 0){
			pa--;
			a--;
		}
		elif(aba > 0) {
			if (ba - pba > ab - pab) pba++;
			else pab++;
			aba--;
			a--;
		}
		elif(bab > 0) {
			bab--;
			pb += 2;
			a--;
		}
		else {
			if (ba - pba < 0) {
				pba--;
				a--;
				pb++;
			}
			else if (ab - pab < 0) {
				pab--;
				a--;
				pb++;
			}
			else {
				printf("NO\n");
				return;
			}
		}
	}
	while (b > 0) {
		if (pb > 0) {
			pb--;
			b--;
		}
		elif(bab > 0) {
			if (ba - pba > ab - pab) pba++;
			else pab++;
			bab--;
			b--;
		}
		else {
			printf("NO\n");
			return;
		}
	}
	while (ab > 0) {
		pab--;
		ab--;
	}
	while (ba > 0) {
		pba--;
		ba--;
	}
	if (a != 0 || b != 0 || ab != 0 || ba != 0 || pa!=0 || pb!=0 || pab!=0 || pba!=0 || bab!=0 || aba!=0) printf("NO\n");
	else printf("YES\n");
}
int ff(string s) {
	int r = 0;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] == '1')r += 10;
		if (s[i + 1] == '1')r++;
	}
	return r;
}
void solve() {
	int n = xin(), k = xin();
	string s; cin >> s;
	int l = -1, r = 0;
	for (int i = 0; i < n; i++) {
		if (l == -1 && s[i] == '1') l = i;
		if (s[i] == '1')r = i;
	}
	int y = n - r - 1;
	if (y <= k) {
		swap(s[r], s[n - 1]);
		k -= y;
	}
	if (l <= k && l != -1 && (l != r || y>k)) swap(s[0], s[l]);
	cout << ff(s) << endl;

}
void exddd() {
	int n = xin();
	vi a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	if (a[0] + a[1] <= a[n-1]) {
		cout << 1 << ' ' << 2 << ' ' << n << endl;
	}
	else cout << -1 << endl;

}
int32_t main()
{
	int t = xin();
	

	

	while (t--) solve();
}





















