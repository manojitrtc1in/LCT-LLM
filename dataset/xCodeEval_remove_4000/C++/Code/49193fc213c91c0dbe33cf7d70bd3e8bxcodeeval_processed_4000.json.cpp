














































using namespace std;



mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct vert {
	int len, link;
	bool term;
	map<long long, int> next;
};

struct id0 {
	vector<vert> ms;
	vector<long long> dp;
	int cnt, last;
	id0(vector<long long> &s) {
		ms.push_back(vert());
		cnt = 1, last = 0;
		ms[0].len = 0, ms[0].link = -1;
		for (int i = 0; i < s.size(); i++)
			suff_upd(s[i]);
		dp.resize(cnt);
	}

	void suff_upd(long long e)
	{
		int newcnt = cnt + 1;
		ms.push_back((vert()));
		ms[cnt].len = ms[last].len + 1;
		while (last != -1 && ms[last].next[e] == 0)
		{
			ms[last].next[e] = cnt;
			last = ms[last].link;
		}
		if (last == -1)
			ms[cnt].link = 0;
		else if (ms[ms[last].next[e]].len == ms[last].len + 1)
			ms[cnt].link = ms[last].next[e];
		else
		{
			newcnt = cnt + 2;
			ms.push_back((vert()));
			int q = ms[last].next[e], p = last;
			ms[cnt + 1].next = ms[q].next;
			ms[cnt + 1].len = ms[p].len + 1;
			ms[cnt + 1].link = ms[q].link;
			ms[q].link = ms[cnt].link = cnt + 1;
			while (last != -1 && ms[last].next[e] == q)
			{
				ms[last].next[e] = cnt + 1;
				last = ms[last].link;
			}
		}
		last = cnt;
		cnt = newcnt;
	}

	void dfs(int v)
	{
		for (auto it : ms[v].next)
		{
			if (!dp[it.second] && it.first != -1)
			{
				if (it.first != 0)
					dp[it.second] = 1;
				dfs(it.second);
			}
			if (it.first != -1)
				dp[v] += dp[it.second];
		}
	}
};

const long long p1 = 29, p2 = 31, mod1 = 1e9 + 9, mod2 = 1e9 + 7;
const long long maxn = 5e5 + 113;
int le[maxn], re[maxn];
vector<long long> hs1, hs2, prost1, prost2;

void solve(int l, int r, vector<long long> &dx)
{
	dx.push_back(-1);
	if (l > r)
		return;
	vector<pair<int, int>> vb;
	while (l < r)
	{
		while (l < r && le[l] == -1)
		{
			dx.push_back(-1);
			l++;
		}
		if (l < r)
		{
			int t = le[l];
			long long h1 = hs1[t], h2 = hs2[t];
			if (l != 0)
			{
				h1 = (h1 - hs1[l - 1] + mod1) % mod1;
				h2 = (h2 - hs2[l - 1] + mod2) % mod2;
			}
			h1 = (h1 * prost1[(int)prost1.size() - 1 - l]) % mod1;
			h2 = (h2 * prost2[(int)prost2.size() - 1 - l]) % mod2;
			dx.push_back(h1 + h2 * mod1);
			vb.push_back({ l + 1, t - 1 });
			l = t + 1;
		}
	}
	for (int i = 0; i < vb.size(); i++)
		solve(vb[i].first, vb[i].second, dx);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	prost1.push_back(1), prost2.push_back(1);
	for (int i = 1; i <= s.size() + 2; i++)
	{
		prost1.push_back((prost1.back() * p1) % mod1);
		prost2.push_back((prost2.back() * p2) % mod2);
	}
	hs1.push_back(s[0]);
	hs2.push_back(s[0]);
	for (int i = 1; i < s.size(); i++)
	{
		hs1.push_back((hs1.back() + 1LL * s[i] * prost1[i]) % mod1);
		hs2.push_back((hs2.back() + 1LL * s[i] * prost2[i]) % mod2);
	}
	stack<int> ds;
	vector<long long> dx;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			ds.push(i);
		else if (ds.size())
		{
			le[ds.top()] = i;
			re[ds.top()] = -1;
			re[i] = ds.top();
			le[i] = -1;
			ds.pop();
		}
		else
			re[i] = le[i] = -1;
	}
	while (ds.size())
	{
		int h = ds.top();
		ds.pop();
		le[h] = re[h] = -1;
	}
	solve(0, s.size() - 1, dx);
	id0 ms(dx);
	ms.dfs(0);
	cout << ms.dp[0];
	

}

