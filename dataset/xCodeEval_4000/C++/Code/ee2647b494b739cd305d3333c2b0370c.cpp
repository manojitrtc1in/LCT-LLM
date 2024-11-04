#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <array>
#include <set>
#include <list>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <iterator>
#include <iomanip>


#ifdef DEBUG__
#include <chrono>
#define FILE__ "tree"
#else


#endif

using namespace std;

#define loop(i,start,end) for(auto i = start;i < end;i ++)
#define loopi(end) loop(i,0,end)
#define loopj(end) loop(j,0,end)
const double pi = 3.1415926535;
#define FIRST_SOLUTION__
void build(int v, int vl, int vr)
{
}


















































bool Ans(long long a)
{
	vector<bool> used(10);
	while (a)
	{
		if (a % 10 == 2 || a % 10 == 0 || used[a % 10]) return false;
		used[a % 10] = true;
		a /= 10;
	}
	return true;
}
int mc = -1;
float dist(pair<int, int> a)
{
	return (a.first) * (a.first) + (a.second - mc) * (a.second - mc);
}










vector<pair<int, int>> st = { { 0,1 }, { 0,-1 },  { 1,0 }, { 1,1 }, { 1,-1 }, { -1,0 }, { -1,-1 }, { -1,1 } };
int gcd(int a, int b)
{
	int t = max(a, b);
	b = min(a, b);
	a = t;
	if (b == 0) return a;
	else return gcd(b, a % b);
}

void disp(vector<vector<char>>& a)
{
	loopi(a.size())
	{
		loopj(a[i].size())
		{
			cout << a[i][j];
		}
		cout << endl;
	}
}

int conv(char s)
{
	if (isdigit(s))
	{
		return s - '0';
	}
	else return s - 'A' + 10;
}

bool check(int a, int b, int c, int d)
{
	int cu = 0, w = 0;
	vector<int> used1(10);
	vector<int> used2(10);
	while (a > 0)
	{
		if (a % 10 == b % 10) { cu++; }
		else
		{
			used1[a % 10]++;
			used2[b % 10]++;
		}
		a /= 10;
		b /= 10;
	}
	loopi(10)
	{
		w += min(used1[i], used2[i]);
	}
	return (c == cu && d == w);
}
int ask(int a, int b)
{
	cout << "? " << a + 1 << " " << b + 1 << endl;
	cout.flush();
	int t;
	cin >> t;
	return t;
}
int bs(vector<int>& a, int l, int r, int f)
{
	if (l == r - 1) return (a.size() > r ? r + 1 : -1e9 - 2);
	int m = (l + r) / 2;
	if (a[m] > f) return bs(a, m, r, f);
	else return bs(a, l, m, f);
}
int sc_prod(pair<int, int> a, pair<int, int> b)
{
	return b.second * a.second + b.first * a.first;
}
#ifdef FIRST_SOLUTION__
vector<pair<int, vector<int>>> d;
vector<int> li;
vector<bool> used;
int Max;
int maxPos;
int lastmaxPos;


























































int go(vector<vector<int>>& d, vector<vector<pair<vector<int>, vector<int>>>>& g, int p, int l, bool& flag, int x2, int y2)
{
	if (l == x2 && p == y2) {
		flag = true; return g[l][p].first[0];
	}
	else flag = false;
	if (d[l][p] == 0) d[l][p] = g[l][p].first[0];
	else return d[l][p];
	int mx = -1;
	bool f = false;
	for (auto e : g[l][p].second)
	{
		int temo = go(d, g, e, l + 1, flag, x2, y2);
		if (flag) { mx = temo; f = true; }
		flag = f;
	}
	if (mx == -1) return mx;
	d[l][p] += mx;
	return d[l][p];
}
bool comp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first) return a.second > b.second;
	return a.first >= b.first;
}
bool comp2(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second) return a.first > b.first;
	return a.second >= b.second;
}
double dist(int x1, int y)
{
	return sqrt((double)x1 * x1 + y * y);
}
int sc_pr(int x1, int x2, int y1, int y2)
{
	return x1 * x2 + y1 * y2;
}










































int mask(string s)
{
	int a = 0;
	loopi(s.size())
		a += (1 << s[i] - 'a');
	return a;
}
int mask(char s)
{
	return 1 << s - 'a';
}
int color(vector<int>& ans, vector<vector<int>>& g, int v)
{
	if (ans[v] != -1) return ans[v];
	ans[v] = v;
	int n = g[v].size();
	loopi(n)
	{
		if (g[i][v] == g[v][i] && g[v][i] == 1) ans[v] = color(ans, g, i);
		else color(ans, g, i);
	}
	return ans[v];
}














vector<pair<int, vector<int>>> cols;
vector<vector<int>> g;
int s;
bool dfs(int v, int col)
{
	for (auto e : g[v])
	{
		if (e == s) continue;
		if (cols[e].first == 0)
		{
			cols[e] = { col,vector<int>{v} };
			if (dfs(e, col)) return true;
		}
		else if (cols[e].first != col)
		{
			cols[e].second.push_back(v);
			return true;
		}
	}
	return false;
}
void solve()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;  vector<int> a(n);
		int c = 0; bool f = true;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] == 0) c++;
		}

		sort(a.begin(), a.end());
		for (int i = 0; i < n - 1; i++) if (a[i] == a[i + 1]) {
			f = false;
		}
		if (c) f = false;
		cout << f + n - c << endl;
	}
	return;

#if 0
#define X first
#define Y second
#define double long double
#define sqrt sqrtl

	int n;
	cin >> n;
	vector<pair<double, double>> p(n);
	for (auto& v : p)
		cin >> v.X >> v.Y;

	sort(p.begin(), p.end());

	if (n == 1) {

		cout << p[0].Y << endl;
		return;
	}

	auto d = p[1].X - p[0].X;
	auto x = ((p[0].Y * p[0].Y) - (p[1].Y * p[1].Y) + d * d) / (2 * d) + p[0].X;
	auto h = sqrt(p[1].Y * p[1].Y - (x-p[1].X) * (x-p[1].X));
	auto l = 0, r = 1;

	if (p[0].Y <= sqrt(p[1].Y * p[1].Y - (p[0].X - p[1].X)* (p[0].X - p[1].X)) || 
		p[1].Y <= sqrt(p[0].Y * p[0].Y - (p[0].X - p[1].X) * (p[0].X - p[1].X)))
		h = min(p[0].Y, p[1].Y);

	auto h_bk = h;

	for (int i = 2; i < n; ++i) {

		{
			auto d = p[i].X - p[l].X;
			auto x = ((p[l].Y * p[l].Y) - (p[i].Y * p[i].Y) + d * d) / (2 * d) + p[l].X;
			auto h1 = sqrt(p[i].Y * p[i].Y - (x - p[i].X) * (x - p[i].X));

			if (p[l].Y <= sqrt(p[i].Y * p[i].Y - (p[l].X - p[i].X) * (p[l].X - p[i].X)) ||
				p[i].Y <= sqrt(p[l].Y * p[l].Y - (p[l].X - p[i].X) * (p[l].X - p[i].X)))
				h1 = min(p[l].Y, p[i].Y);

			if (h1 < h) {
				h = h1;
				r = i;
			}
		}
		{
			auto d = p[i].X - p[r].X;
			auto x = ((p[r].Y * p[r].Y) - (p[i].Y * p[i].Y) + d * d) / (2 * d) + p[r].X;
			auto h1 = sqrt(p[i].Y * p[i].Y - (x - p[i].X) * (x - p[i].X));

			if (p[r].Y <= sqrt(p[i].Y * p[i].Y - (p[r].X - p[i].X) * (p[r].X - p[i].X)) ||
				p[i].Y <= sqrt(p[r].Y * p[r].Y - (p[r].X - p[i].X) * (p[r].X - p[i].X)))
				h1 = min(p[r].Y, p[i].Y);

			if (h1 < h) {
				h = h1;
				l = r;
				r = i;
			}
		}
	}

	cout << fixed << setprecision(3) << h;
#endif
#if 0
	int a, b, c;
	cin >> a >> b >> c;

	if (c > a + b || a + b > 1000000) {
		cout << "No" << endl;
		return;
	}

	


	if (a < b)
		std::swap(a, b);

	int aand = std::max(0, a - c);

	if (!aand) {

		cout << "Yes\n" << string(a, '1') + string(b, '0') << endl
			<< string(a, '0') + string(b, '1');
		return;
	}

	string l(aand, '1'), r(aand - 1, '0');
	r += "10";
	l += '0';

	a -= aand;
	b -= 1;

	cout << "Yes\n" << l + string(b, '1') + string(abs(a - b), '1') << endl
		<< r + string(b, '1') + string(abs(a - b), '0') << endl;

	return;
#endif
}


#else


const int sze = 1e5 + 100;
struct node {
	bool term;
	map<char, int> child;
	node()
	{
		term = false;
	}
};
node trie[sze];
int dp[sze];
int cnt = 0;
int j = 0;
int curlen = 5e6;
bool fnd(string s)
{
	int i = 0, idx = 0, sz = s.size();
	while (i != sz + 1)
	{
		char ch;
		ch = s[i];
		int ce = trie[idx].child[ch];
		if (ce == 0)
		{
			return false;
		}
		else idx = ce;
		i++;
	}
	return trie[idx].term;
}
void insert(string s)
{
	int i = 0, idx = 0, sz = s.size();
	dp[0]++;
	while (i != sz)
	{
		char ch;
		ch = s[i];
		int ce = trie[idx].child[ch];
		if (ce == 0)
		{
			trie[idx].child[ch] = ++j;
			idx = j;
		}
		else idx = ce;
		i++;
		dp[idx]++;
	}
	if (!trie[idx].term) cnt++;
	trie[idx].term = true;
}
int find(int k, int idx, int l)
{
	if (trie[idx].child.find((k >> l) % 2 + '0') == trie[idx].child.end())
	{
		return 0;
	}
	if (dp[trie[idx].child[(k >> l) % 2 + '0']] != 1 << l)
		return ((k >> l) % 2) * (1 << l) + find(k, trie[idx].child[((k >> l) % 2) + '0'], l - 1);
	return (((k >> l) % 2) ^ 1) * (1 << l) + find(k, trie[idx].child[((k >> l) % 2) ^ 1 + '0'], l - 1);
}
string tobin(int a)
{
	string s = "";
	loopi(2)
	{
		s = to_string(a % 2) + s;
		a /= 2;
	}
	return s;

}
void solve() {


	return;
	
	int n, max = 0;
	cin >> n;
	vector<int> a(n);
	loopi(n)
	{
		cin >> a[i];
		if (a[i] > max) max = a[i];
	}
	int c = 0;
	loopi(n)
	{
		if (a[i] == max) c++;
	}
	cout << c;
	
}
#endif

int main() {
#ifdef DEBUG__
	auto timestamn = std::chrono::system_clock::now();
#else
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
#endif
#ifdef FILE__
	freopen(FILE__".in", "r", stdin);
	freopen(FILE__".out", "w", stdout);
#endif
	solve();
#ifdef DEBUG__
	cout << endl << "Time elansed: " << chrono::duration_cast<chrono::milliseconds>(std::chrono::system_clock::now() - timestamn).count() << " ms" << endl;
#endif
	return 0;
}