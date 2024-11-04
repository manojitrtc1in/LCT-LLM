














































using namespace std;



mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct id0 {
	vector<int> p, c, nc, np, h, p2, lcp;
	string s;
	int n;
	id0(string s)
	{
		this->s = s + char(0);
		this->n = this->s.size();
		build();
		buildlcp();
	}
	int mode1(int a, int k) { return (a + (1 << (k - 1)) % n); }
	int mode2(int a, int k) { return (a - (1 << (k - 1)) + n) % n; }
	bool prov(int i, int j, int k) { return c[i] != c[j] || c[mode1(i, k)] != c[mode1(j, k)]; }
	void build()
	{
		p.resize(n), c = nc = np = h = p;
		vector<pair<char, int>> in;
		for (int i = 0; i < s.size(); i++)
			in.push_back({ s[i], i });
		sort(in.begin(), in.end());
		for (int i = 0; i < in.size(); i++)
			p[i] = in[i].second;
		int g = h[0] = c[p[0]] = 0, k = 1;
		for (int i = 1; i < n; i++)
		{
			if (in[i - 1].first != in[i].first)
				g++, h[g] = i;
			c[p[i]] = g;
		}
		while (1 << (k - 1) < n)
		{
			for (int i = 0; i < n; i++)
			{
				int v = mode2(p[i], k);
				np[h[c[v]]++] = v;
			}
			g = nc[np[0]] = h[0] = 0;
			for (int i = 1; i < n; i++)
			{
				if (prov(np[i - 1], np[i], k))
					g++, h[g] = i;
				nc[np[i]] = g;
			}
			c = nc, p = np, k++;
			if (g == n)
				break;
		}
	}
	void buildlcp() {
		p2.resize(n), lcp.resize(n);
		for (int i = 0; i < n; i++)
			p2[p[i]] = i;
		for (int i = 0; i < n; i++)
		{
			if (i > 0)
				lcp[p2[i]] = max(lcp[p2[i - 1]] - 1, 0);
			while (p2[i] + 1 < n && s[i + lcp[p2[i]]] == s[p[p2[i] + 1] + lcp[p2[i]]])
				lcp[p2[i]]++;
		}
	}
};


struct spars {

	vector<int> e;
	vector<int> sparst[20];
	vector<int> ot;

	spars(vector<int> t)
	{
		e = t;
		ot.resize(e.size() + 113);
		int u = 1, k = 0;
		for (int i = 1; i <= e.size(); i++)
		{
			while (2 * u <= i)
				u *= 2, k++;
			ot[i] = k;
		}
		sparst[0].resize(e.size() + 1);
		for (int i = 0; i < e.size(); i++)
			sparst[0][i] = e[i];
		for (int i = 1; i <= 19; i++)
		{
			sparst[i].resize(e.size() + 1);
			int t = (1 << i);
			for (int j = 0; j + t - 1 < e.size(); j++)
				sparst[i][j] = min(sparst[i - 1][j], sparst[i - 1][j + t / 2]);
		}
	}

	int rmq(int l, int r)
	{
		int y = ot[r - l + 1];
		return min(sparst[y][l], sparst[y][r - (1 << y) + 1]);
	}
};

int zp(int i, int j, id0 &ms, spars &tb, int len)
{
	int s1 = ms.p2[i];
	int s2 = ms.p2[j + len];
	if (s1 > s2)
		swap(s1, s2);
	return tb.rmq(s1, s2 - 1);
}

const long long maxn = 1e5 + 113;
long long dp[maxn][33];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(0);
	int n;
	cin >> n;
	string a, b;
	cin >> a >> n >> b;
	int h;
	cin >> h;
	id0 ms(a + '$' + b);
	spars tb(ms.lcp);
	int len = a.size() + 1;
	int tr = false;
	for (int t = 0; t <= h; t++)
	{
		for (int i = 0; i < len - 1; i++)
		{
			dp[i + 1][t] = max(dp[i + 1][t], dp[i][t]);
			int s = dp[i][t];
			if (s != b.size())
			{
				int d = zp(i, s, ms, tb, len);
				dp[i + d][t + 1] = max(dp[i + d][t + 1], 0LL + s + d);
				if (t < h && s + d == b.size())
					tr = true;
			}
			else
				tr = true;
		}
	}
	if (tr)
		cout << "YES\n";
	else
		cout << "NO\n";
	

}

