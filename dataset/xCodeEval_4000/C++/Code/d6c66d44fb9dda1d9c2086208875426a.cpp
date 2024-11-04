#define _CRT_SECURE_NO_WARNINGS




#include <set>
#include <map>
#include <deque>
#include <string>
#include <cstdint>
#include <cmath>
#include <queue>
#include <cassert>
#include <random>
#include <bitset>
#include <iomanip>
#include <cstring>
#include <numeric>
#include <time.h>

#include <ctime>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <complex>
#include <chrono>
#include <unordered_set>




#define mp make_pair
#define pbc push_back
#define pob pop_back()
#define empb emplace_back
#define queuel queue<long long>
#define sqr(a) ((a) * (a))
#define lsqr(a) (ld(a) * a)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pin(p) cin >> p.first >> p.second;
#define uniq(a) sort(all(a));(a).resize(unique(all(a)) - a.begin());
#define rev(v) reverse(v.begin(), v.end());
#define sout(s, c) for (auto i : s) cout << i << c;
#define pout(p) cout << p.first << " " << p.second;
#define er(v, l, r) erase(v.begin() + l, v.begin() + r);
#define vin(v) for (ll i = 0; i < v.size(); ++i) cin >> v[i];
#define vout(v, c) for (int i = 0; i < v.size(); ++i) cout << v[i] << c;
#define pushi(v, a) for (int i = 0; i < a.size(); ++i) v.push_back(a[i]);
#define fastio() ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0); srand(time(NULL))
#define dab(v) for(auto i:v)cout<<i<<' ';
#define sp system("pause")



typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;
typedef complex<double> cd;


const int inf = 1e9;
const ll INF = 1e18;
const ld PI = acos(-1);
const ld EPS = 1e-9;
int mod = 998244353;
const int MOD7 = 1000000007;
const int MOD9 = 1000000009;
const int MAXN = 4e5 + 228;
int p[MAXN];
int rnk[MAXN];
void make(int v)
{
	p[v] = v;
	rnk[v] = 0;
}
int fin(int v)
{
	return (v == p[v] ?v: p[v] = fin(p[v]));
}
void unite(int a, int b)
{
	a = fin(a), b = fin(b);
	if (a == b)return;
	if (rnk[a] < rnk[b])swap(a, b);
	rnk[a] += (rnk[a] == rnk[b]);
	p[b] = a;
}
vector<pair<int, int>> rbs;
int cnt[MAXN];
int n, m;
int getn(int i, int j)
{
	return i * m + j;
}
vector<int> g[MAXN];
vector<int> tg[MAXN];
int cal[MAXN];
int used[MAXN];
int ans = 0;
vector<int> ts;
vector<int> rg[MAXN];

void dfsere(int v)
{
	used[v] = 1;
	for (int i : tg[v])
	{
		if (!used[i])
		{
			dfsere(i);
		}
	}
}
void d1(int v)
{
	used[v] = 1;
	for (int i : g[v])
	{
		if (!used[i])
		{
			d1(i);
		}
	}ts.pbc(v);
}int cln = 1;
vector<int> cmp[MAXN];
int dp[MAXN];
vector<int> rtg[MAXN];
void d2(int v)
{
	used[v] = 1;
	cal[v] = cln;
	cmp[cln].pbc(v);
	for (int i : rg[v])
	{
		if (!used[i])
		{
			d2(i);
		}
	}
}
int xs[MAXN];
int lol[MAXN];
int calcdp(int v)
{
	if (dp[v] != -1) return dp[v];
	int nx = -1;
	int no = 0;
	if (xs[v] >= 0)
	{
		dp[v] = v;
		no = v;
		nx = xs[v];
	}
	for (int i : rtg[v])
	{
		int jj = calcdp(i);
		if (xs[jj] > nx)
		{
			nx = xs[jj], no = jj;
		}
	}
	dp[v] = no;
	return dp[v];
}
int tused[MAXN];
vector<int> gg[MAXN];
int nd[MAXN];
void dfscome(int v)
{
	tused[v] = 1;
	nd[v % m] = max(nd[v % m] - 1, 0);	
	for (int i : gg[v])
	{
		if (!tused[i])
		{
			dfscome(i);
		}
	}
}
int stupid(vector<vector<char>> a, vector<int> nouse)
{
	int ans = inf;
	for (int mask = 0; mask < (1 << m); ++mask)
	{
		vector<vector<int>> used(n, vector<int>(m));
		queue<pair<int,int>> q;
		vector<int> dx{ 1,-1,0,0 };
		vector<int> dy{ 0,0,1,-1 };
		int now = 0;
		for (int i = 0; i < m; ++i)
		{
			if ((mask >> i) & 1)
			{
				int ok = -1;
				for (int j = 0; j < n; ++j)
				{
					if (a[j][i] == '#')
					{
						ok = j;
						break;
					}
				}
				if (ok != -1)
				{
					++now;
					q.push({ ok,i });
					used[ok][i] = 1;
				}
			}
		}
		while (q.size())
		{
			auto v = q.front();
			q.pop();
			for (int j = v.first; j < n; ++j)
			{
				for (int k = 0; k < 4; ++k)
				{
					int nx = j + dx[k];
					int ny = v.second + dy[k];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && !used[nx][ny] && a[nx][ny] == '#')
					{
						used[nx][ny] = 1;
						q.push({ nx,ny });
					}
				}
			}
		}
		bool fine = 1;
		for (int j = 0; j < m; ++j)
		{
			int cnt = 0;
			for (int i = 0; i < n; ++i)
			{
				cnt += (a[i][j] == '#' && used[i][j]);
			}
			if (cnt < nouse[j]) fine = 0;
		}
		if (fine)ans = min(ans, now);
	}
	return ans;
}

int smart(vector<vector<char>> a, vector<int> nouse)
{
	fill(xs, xs + MAXN, -1);
	fill(dp, dp + MAXN, -1);
	fill(tused, tused + MAXN, 0);
	fill(cal, cal + MAXN, 0);
	cln = 1;
	ans = 0;  
	fill(lol, lol + MAXN, 0);
	fill(rtg, rtg + MAXN, vector<int>(0));
	fill(tg, tg + MAXN, vector<int>(0));
	fill(g, g + MAXN, vector<int>(0));
	fill(rg, rg + MAXN, vector<int>(0));
	fill(cmp, cmp + MAXN, vector<int>(0));
	fill(used, used + MAXN, 0);
	fill(gg, gg + MAXN, vector<int>(0));
	rbs.clear();
	fill(cnt, cnt + MAXN, 0);
	fill(p, p + MAXN, 0);
	fill(rnk, rnk + MAXN, 0);
	for (int j = 0; j < m; ++j) nd[j] = nouse[j];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)make(getn(i, j));
	}vector<vector<int>> fd(n, vector<int>(m));
	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (a[i][j] == '#')
			{
				fd[i][j] = i;
			}
			else if (i == n - 1)
			{
				fd[i][j] = n;
			}
			else
			{
				fd[i][j] = fd[i + 1][j];
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (a[i][j] == '.')continue;
			vector<int> dx{ 1,-1,0,0 };
			vector<int> dy{ 0,0,1,-1 };
			for (int k = 0; k < 4; ++k)
			{
				int nx = i + dx[k], ny = j + dy[k];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == '#')
				{
					unite(getn(i, j), getn(nx, ny));
					rbs.pbc({ getn(i,j), getn(nx,ny) });
					rbs.pbc({ getn(nx,ny), getn(i,j) });
				}
			}
			vector<int> dyy{ 1,-1,0 };
			for (int k = 0; k < 3; ++k)
			{
				int ny = j + dyy[k];
				if (ny >= 0 && ny < m && i != n - 1)
				{
					int tyy = fd[i + 1][ny];
					if (tyy == n) continue;
					int kok = getn(tyy, ny);
					rbs.pbc({ getn(i,j), kok });
				}
			}
		}
	}

	for (int i = 0; i < rbs.size(); ++i)
	{
		gg[rbs[i].first].pbc(rbs[i].second);

		rbs[i].first = fin(rbs[i].first);
		rbs[i].second = fin(rbs[i].second);
		if (rbs[i].first == rbs[i].second)continue;
		g[rbs[i].first].pbc(rbs[i].second);
		rg[rbs[i].second].pbc(rbs[i].first);
	}
	vector<int> rts;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (a[i][j] != '#')continue;
			rts.pbc(fin(getn(i, j)));
		}
	}
	uniq(rts);
	for (int i : rts)
	{
		if (!used[i])
		{
			d1(i);
		}
	}
	rev(ts);
	fill(used, used + MAXN, 0);
	for (int i : ts)
	{
		if (!used[i])
		{
			d2(i);
			cln++;
		}
	}
	for (int i = 0; i < rbs.size(); ++i)
	{
		rbs[i].first = cal[rbs[i].first];
		rbs[i].second = cal[rbs[i].second];
		if (rbs[i].first == rbs[i].second) continue;
		tg[rbs[i].first].pbc(rbs[i].second);
		rtg[rbs[i].second].pbc(rbs[i].first);
		cnt[rbs[i].second]++;
	}
	fill(used, used + MAXN, 0);
	vector<int> outcomes;
	for (int i = 1; i < cln; ++i)
	{
		if (cnt[i] == 0 && !used[i])
		{
			outcomes.pbc(i);
			dfsere(i);
		}
	}
	
	for (int i : outcomes)
	{
		for (int j : cmp[i])
		{
			xs[i] = max(xs[i], j % m);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (a[i][j] == '#')
			{
				int xx = fin(getn(i, j));
				if (binary_search(all(outcomes), cal[xx]))
				{
					xs[cal[xx]] = max(xs[cal[xx]], j);
				}
			}
		}
	}
	set<int> kekos;
	vector<int> rofl(m);
	for (int j = 0; j < m; ++j)
	{
		int xx = nouse[j];
		if (!xx)continue;
		int ti;
		for (int i = n - 1; i >= 0; --i)
		{
			if (a[i][j] == '.')continue;
			xx--;
			ti = i;
			if (!xx)break;
		}
		int vv = getn(ti, j);
		rofl[j] = ti;
		vv = fin(vv);
	}
	for (int i = 1; i < cln; ++i) calcdp(i);
	int pt = 0;
	fill(tused, tused + MAXN, 0);
	

	xs[0] = 228228228;
	while(pt<m)
	{
		if (!nd[pt])
		{
			pt++;
			continue;
		}
		int r = pt;
		int cll = -1;
		int goy = m;
		while (r < m && r <= goy)
		{
			int newy = 0;
			if (nd[r])
			{
				int vv = getn(rofl[r], r);
				vv = fin(vv);
				vv = cal[vv];
				int nw = dp[vv];
				newy = nw;
			}
			if (goy > xs[newy])cll = newy;
			goy = min(goy, xs[newy]);
			++r;
		}
		r--;
		++ans;
		pt = r + 1;
		if (cll == -1 || cmp[cll].size() < 1)return -228;
		if(!tused[cmp[cll][0]])
		dfscome(cmp[cll][0]);
	}
	return ans;
}
mt19937 rnd(time(0));
signed main()
{
	fastio();

	cin >> n >> m;
	vector<vector<char>> a(n, vector<char>(m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> a[i][j];
			make(getn(i, j));
		}
	}
	vector<int> nouse(m);
	vin(nouse);
	cout << smart(a, nouse);
	

}
