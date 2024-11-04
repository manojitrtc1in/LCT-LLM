











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
			if(!used[to.first])s.insert({dist[to.first], to.first});
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


int nearf(int a, int b) {
	

	return min(122 - max(a, b) + (min(a, b) - 96), max(a, b) - min(a, b));
}
void near() {
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 1; i < n; i++) {
		if (s[i] == s[i - 1]) {
			char c = 'a';
			while (s[i - 1] == c || i < n - 1 && s[i + 1] == c) c++;
			s[i] = c;
		}
	}
	cout << s;
}
void exa() {
	int n = xin();
	vi a(n);
	bool f = 0;
	int fi = 0;
	int res = 0;
	set<int>s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s.insert(a[i]);
		if (!a[i]) {
			f = 1; 
			fi = i;
		}
	}
	if (!f) {
		res+=2;
		a[1] = min(a[0], a[1]);
		a[0] = 0;
		if (s.size() < n) res--;
	}
	for (int i = 0; i < n; i++) if (a[i]) res++;
	cout << res << endl;
}
void exb() {
	int n = xin();
	int res = 0;
	string s;
	cin >> s;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (i > 0 && s[i] != s[i - 1]) {
			if (cur % 2 == 1) {
				res++;
				s[i] = s[i - 1];
				cur = -1;
			}
			else cur = 0;
		}
		cur++;
	}
	cout << res << endl;
}
int32_t main()
{
	int t = xin();
	

	

	

	while (t--) exb();
}









































