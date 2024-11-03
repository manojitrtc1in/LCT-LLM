#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native") 
#pragma GCC optimize("unroll-loops") 

























#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<math.h>
#include<algorithm>
#include<time.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<deque>
#include<fstream>
#include<unordered_map>
#include<bitset>
#include<cstdio>
#include<random>
#include<chrono>

using namespace std;



mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e5 + 113;
vector<int> gr[maxn];
bool used[maxn];
vector<int> ts, tf;
vector<int> se[maxn];
int col[maxn];

struct dot {
	struct tree {
		int left, right, x, rev;
		tree() { left = right = x = rev = 0; }
	};
	vector<tree> ms;
	int cnt, n;
	dot() {
		cnt = 1;
		ms.resize(10);
		this->n = 0;
	}
	dot(int n)
	{
		cnt = 2;
		ms.resize(10);
		this->n = n;
	}
	int nw()
	{
		ms.push_back(tree());
		return cnt++;
	}
	void add(int root)
	{
		if (ms[root].left == 0)
			ms[root].left = nw();
		if (ms[root].right == 0)
			ms[root].right = nw();
	}
	void push(int root, int l, int r)
	{
		if (l > r || !ms[root].rev)
			return;
		if (l == r)
		{
			ms[root].x = 1 - ms[root].x;
			ms[root].rev = 0;
			return;
		}
		add(root);
		ms[ms[root].left].rev = (ms[ms[root].left].rev + ms[root].rev) % 2;
		ms[ms[root].right].rev = (ms[ms[root].right].rev + ms[root].rev) % 2;
		ms[root].x = (r - l + 1) - ms[root].x;
		ms[root].rev = 0;
	}
	void upd(int root, int l, int r, int l1, int r1)
	{
		push(root, l, r);
		if (l1 > r || r1 < l)
			return;
		if (l == l1 && r == r1)
		{
			ms[root].rev = (ms[root].rev + 1) % 2;
			push(root, l, r);
			return;
		}
		int m = (l + r) / 2;
		add(root);
		upd(ms[root].left, l, m, l1, min(m, r1));
		upd(ms[root].right, m + 1, r, max(m + 1, l1), r1);
		ms[root].x = ms[ms[root].left].x + ms[ms[root].right].x;
	}
	void upd(int l, int r)
	{
		upd(1, 1, n, l, r);
	}
};

bool dfs(int v, int p)
{
	ts.push_back(v);
	used[v] = 1;
	for (int to : gr[v])
	{
		if (to == p)
			continue;
		if (used[to])
		{
			tf.push_back(to);
			while (ts.back() != to)
			{
				tf.push_back(ts.back());
				ts.pop_back();
			}
			return true;
		}
		else if (dfs(to, v))
			return true;
	}
	ts.pop_back();
	return false;
}

void dfs2(int v, int c)
{
	used[v] = 1;
	col[v] = c;
	se[c].push_back(v);
	for (int to : gr[v])
		if (!used[to])
			dfs2(to, c);
}

int sz[maxn];

int dfs3(int v, int f, int p)
{
	sz[v] = 1;
	for (int to : gr[v])
		if (col[to] == f && to != p)
			sz[v] += dfs3(to, f, v);
	return sz[v];
}

int le[maxn], re[maxn], pos[maxn], cf[maxn], lvl[maxn], pr[maxn];
int cod = 1;
vector<int> ip;

void dfs4(int v, int f, int p, int c)
{
	pr[v] = p;
	cf[v] = c;
	pos[v] = ip.size();
	re[c] = v;
	ip.push_back(v);
	vector<pair<int, int>> fg;
	for(int to : gr[v])
		if (col[to] == f && to != p)
			fg.push_back({ sz[to], to });
	sort(fg.begin(), fg.end());
	reverse(fg.begin(), fg.end());
	for (int i = 0; i < fg.size(); i++)
	{
		int to = fg[i].second;
		lvl[to] = lvl[v] + 1;
		if(i == 0)
			dfs4(to, f, v, c);
		else
		{
			cod++;
			le[cod] = to;
			dfs4(to, f, v, cod);
		}
	}
}

void zp(int a, int b, int &sum, vector<dot> &mas)
{
	int c = mas[col[a]].ms[1].x;
	while (true)
	{
		if (cf[a] == cf[b])
		{
			if (lvl[a] > lvl[b])
				swap(a, b);
			if(a != b)
				mas[col[a]].upd(pos[a] + 1, pos[b]);
			break;
		}
		if (lvl[le[cf[a]]] > lvl[le[cf[b]]])
			swap(a, b);
		mas[col[a]].upd(pos[le[cf[b]]], pos[b]);
		b = pr[le[cf[b]]];
	}
	int d = mas[col[a]].ms[1].x;
	sum -= (d - c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	dfs(1, -1);
	for (int i = 1; i <= n; i++)
		used[i] = 0;
	for (int i = 0; i < tf.size(); i++)
		used[tf[i]] = 1;
	int gh = 1;
	vector<dot> mas(1);
	for (int i = 0; i < tf.size(); i++)
	{
		ip.push_back(0);
		dfs2(tf[i], gh);
		dfs3(tf[i], gh, 0);
		dfs4(tf[i], gh++, 0, 1);
		

		ip.clear();
		mas.push_back(dot(sz[tf[i]] + 4));
	}
	dot glo(tf.size());
	int sum = n;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (col[a] == col[b])
			zp(a, b, sum, mas);
		else
		{
			int hn = tf.size();
			int d1 = tf[col[a] - 1];
			zp(a, d1, sum, mas);
			int d2 = tf[col[b] - 1];
			zp(b, d2, sum, mas);
			bool tr = false;
			if (col[d1] > col[d2])
			{
				swap(d1, d2);
				tr = true;
			}
			int di1 = col[d2] - col[d1];
			if (di1 < hn - di1)
			{
				int c = glo.ms[1].x;
				glo.upd(col[d1], col[d2] - 1);
				int d = glo.ms[1].x;
				if (c == tf.size())
					c--;
				sum += c;
				if (d == tf.size())
					d--;
				sum -= d;
			}
			else if (di1 > hn - di1)
			{
				int c = glo.ms[1].x;
				glo.upd(1, col[d1] - 1);
				glo.upd(col[d2], n);
				int d = glo.ms[1].x;
				if (c == tf.size())
					c--;
				sum += c;
				if (d == tf.size())
					d--;
				sum -= d;
			}
			else if(!tr)
			{
				int c = glo.ms[1].x;
				int nu1 = tf[col[d1] % tf.size()];
				int nu2 = tf[(col[d1] - 2 + (int)tf.size()) % tf.size()];
				if (nu1 < nu2)
					glo.upd(col[d1], col[d2] - 1);
				else
				{
					glo.upd(1, col[d1] - 1);
					glo.upd(col[d2], n);
				}
				int d = glo.ms[1].x;
				if (c == tf.size())
					c--;
				sum += c;
				if (d == tf.size())
					d--;
				sum -= d;
			}
			else
			{
				int c = glo.ms[1].x;
				int nu1 = tf[col[d2] % tf.size()];
				int nu2 = tf[(col[d2] - 2 + (int)tf.size()) % tf.size()];
				if (nu2 < nu1)
					glo.upd(col[d1], col[d2] - 1);
				else
				{
					glo.upd(1, col[d1] - 1);
					glo.upd(col[d2], n);
				}
				int d = glo.ms[1].x;
				if (c == tf.size())
					c--;
				sum += c;
				if (d == tf.size())
					d--;
				sum -= d;
			}
		}
		cout << sum << "\n";
	}
	

}