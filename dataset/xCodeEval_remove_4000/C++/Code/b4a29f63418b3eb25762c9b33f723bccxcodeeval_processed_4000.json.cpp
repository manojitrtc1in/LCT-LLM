














































using namespace std;



mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct persdo {
	struct tree {
		int left, right, old;
		int x, upd;
		tree() {
			left = right = old = x = upd = 0;
		}
	};
	vector<tree> ms;
	vector<int> vers;
	int n, cnt;
	persdo(int n)
	{
		vers.push_back(1);
		ms.resize((int)2e6);
		cnt = 2;
		this->n = n;
	}
	int nw() {
		

		return cnt++;
	}
	int clone(int b)
	{
		int a = nw();
		ms[a].left = ms[b].left;
		ms[a].right = ms[b].right;
		ms[a].old = b;
		ms[a].x = ms[b].x;
		return a;
	}
	void addleft(int root, bool tr)
	{
		if (ms[root].left == 0)
			ms[root].left = nw();
		else if (tr || ms[root].left == ms[ms[root].old].left)
			ms[root].left = clone(ms[root].left);
	}
	void addright(int root, bool tr)
	{
		if (ms[root].right == 0)
			ms[root].right = nw();
		else if (tr || ms[root].right == ms[ms[root].old].right)
			ms[root].right = clone(ms[root].right);
	}
	void push(int root, int l, int r)
	{
		if (ms[root].upd == 0)
			return;
		if (l == r)
		{
			ms[root].x += ms[root].upd;
			ms[root].upd = 0;
			return;
		}
		addleft(root, 0);
		addright(root, 0);
		ms[ms[root].left].upd += ms[root].upd;
		ms[ms[root].right].upd += ms[root].upd;
		ms[root].x += ms[root].upd * (r - l + 1);
		ms[root].upd = 0;
	}
	bool prov(int l, int r, int l1, int r1)
	{
		return l1 > r || r1 < l;
	}
	int sum(int root, int l, int r, int l1, int r1)
	{
		if (prov(l, r, l1, r1) || !root)
			return 0;
		push(root, l, r);
		if (l == l1 && r == r1)
			return ms[root].x;
		int m = (l + r) / 2;
		int x = sum(ms[root].left, l, m, l1, min(m, r1));
		int y = sum(ms[root].right, m + 1, r, max(m + 1, l1), r1);
		return x + y;
	}
	void upd(int root, int l, int r, int l1, int r1, int x)
	{
		push(root, l, r);
		if (l == l1 && r == r1)
		{
			ms[root].upd += x;
			push(root, l, r);
			return;
		}
		int m = (l + r) / 2;
		if (!prov(l, m, l1, min(m, r1)))
		{
			addleft(root, 1);
			upd(ms[root].left, l, m, l1, min(m, r1), x);
		}
		if (!prov(m + 1, r, max(m + 1, l1), r1))
		{
			addright(root, 1);
			upd(ms[root].right, m + 1, r, max(l1, m + 1), r1, x);
		}
		ms[root].x = ms[ms[root].left].x + ms[ms[root].right].x;
	}
	int sum(int l, int r) { return sum(vers.back(), 1, n, l, r); }
	int sum(int s, int l, int r) { return sum(vers[s], 1, n, l, r); }
	int sum(int s1, int s2, int l, int r) { return sum(s2, l, r) - sum(s1, l, r); }
	void upd(int l, int r, int x)
	{
		vers.push_back(clone(vers.back()));
		upd(vers.back(), 1, n, l, r, x);
	}
};

const int maxn = 1e5 + 113, maxs = 25;
int sz[maxn];
vector<int> gr[maxn];
vector<int> io;
vector<int> sp[maxn];
int cr[maxn], le[maxn], re[maxn], pos[maxn], pos2[maxn];
int co = 2;
int pr[maxn][maxs], timein[maxn], timeout[maxn];
int vin = 0, vout = 0;

int dfs1(int v, int p)
{
	timein[v] = vin++;
	sz[v] = 1;
	pr[v][0] = p;
	for (int i = 1; i < maxs && pr[v][i - 1] != 0; i++)
		pr[v][i] = pr[pr[v][i - 1]][i - 1];
	for (int to : gr[v])
		sz[v] += dfs1(to, v);
	timeout[v] = vout++;
	return sz[v];
}

int ppr(int a, int b)
{
	return timein[a] <= timein[b] && timeout[a] >= timeout[b];
}

int lca(int a, int b)
{
	if (ppr(a, b))
		return a;
	if (ppr(b, a))
		return b;
	for (int t = 21; t >= 0; t--)
		if (pr[b][t] != 0 && !ppr(pr[b][t], a))
			b = pr[b][t];
	return pr[b][0];
}

void dfs2(int v, int c)
{
	cr[v] = c;
	pos2[v] = sp[c].size();
	sp[c].push_back(v);
	re[c] = v;
	pos[v] = io.size();
	io.push_back(v);
	vector<pair<int, int>> kl;
	for (int to : gr[v])
		kl.push_back({ sz[to], to });
	sort(kl.begin(), kl.end());
	reverse(kl.begin(), kl.end());
	for (int i = 0; i < kl.size(); i++)
	{
		if (i == 0)
			dfs2(kl[i].second, c);
		else
		{
			le[co] = kl[i].second;
			dfs2(kl[i].second, co++);
		}
	}
}

struct df {
	int a, b, k, y, t;
	df(int s1, int s2, int s3, int s4, int s5)
	{
		a = s1, b = s2, k = s3, y = s4, t = s5;
	}
	df() {}
};

int func(int a, int b, int k, int y, int t, persdo &ms)
{
	k += 1 - ms.sum(y, t, pos[a], pos[a]);
	

	vector<pair<int, int>> dt1, dt2;
	bool tr = false;
	int bc = b;
	int uc = lca(a, b);
	int hj = 1000;
	while (true)
	{
		if (cr[a] == cr[uc])
		{
			if (a != uc)
			{
				int f = pos2[uc];
				dt1.push_back({ pos[sp[cr[uc]][f + 1]], pos[a] });
			}
			break;
		}
		int g = le[cr[a]];
		dt1.push_back({ pos[g], pos[a] });
		a = pr[g][0];
		hj--;
		if (hj < 500)
		{
			return -123;
		}
	}
	while (true)
	{
		if (cr[b] == cr[uc])
		{
			dt2.push_back({ pos[uc], pos[b] });
			break;
		}
		int g = le[cr[b]];
		dt2.push_back({ pos[g], pos[b] });
		b = pr[g][0];
		if (hj < 500)
		{
			return -321;
		}
		hj--;
	}
	reverse(dt2.begin(), dt2.end());
	for (int i = 0; i < dt1.size(); i++)
	{
		int h = dt1[i].second - dt1[i].first + 1 - ms.sum(y, t, dt1[i].first, dt1[i].second);
		if (k > h)
		{
			k -= h;
			continue;
		}
		else
		{
			int l = dt1[i].first - 1, r = dt1[i].second + 1;
			while (l + 1 < r)
			{
				int m = (l + r) / 2;
				int uh = ms.sum(y, t, m, dt1[i].second);
				if (dt1[i].second - m + 1 - uh < k)
					r = m;
				else
					l = m;
			}
			return (l != dt1[i].first - 1 && io[l] != bc) ? io[l] : -1;
		}
	}
	for (int i = 0; i < dt2.size(); i++)
	{
		int h = dt2[i].second - dt2[i].first + 1 - ms.sum(y, t, dt2[i].first, dt2[i].second);
		if (k > h)
		{
			k -= h;
			continue;
		}
		else
		{
			int l = dt2[i].first - 1, r = dt2[i].second + 1;
			while (l + 1 < r)
			{
				int m = (l + r) / 2;
				if (m - dt2[i].first + 1 - ms.sum(y, t, dt2[i].first, m) >= k)
					r = m;
				else
					l = m;
			}
			return (r != dt2[i].second + 1 && io[r] != bc) ? io[r] : -1;
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(0);
	int n, m;
	cin >> n;
	int s;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		if (a == 0)
			s = i;
		else
			gr[a].push_back(i);
	}
	io.push_back(0);
	dfs1(s, 0);
	le[1] = s;
	dfs2(s, 1);
	cin >> m;
	vector<df> qu;
	persdo ms(n + 113);
	for (int i = 1; i <= m; i++)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int a;
			cin >> a;
			ms.upd(pos[a], pos[a], 1);
		}
		else
		{
			int a, b, k, y;
			cin >> a >> b >> k >> y;
			ms.upd(1, ms.n, 0);
			qu.push_back({ a, b, k, y, i });
		}
	}
	for (int i = 0; i < qu.size(); i++)
		cout << func(qu[i].a, qu[i].b, qu[i].k, qu[i].y, qu[i].t, ms) << "\n";
	

}

