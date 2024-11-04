














































using namespace std;



mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct id0 {
	vector<int> p, c, np, nc, h;
	string s;
	int n;
	id0(string &s)
	{
		this->s = s;
		this->n = s.size();
		build();
	}
	int mode1(int a, int k) { return (a + (1 << (k - 1))) % n; }
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
			if (in[i].first != in[i - 1].first)
				g++, h[g] = i;
			c[p[i]] = g;
		}
		while ((1 << (k - 1)) < n)
		{
			for (int i = 0; i < n; i++)
			{
				int v = mode2(p[i], k);
				np[h[c[v]]++] = v;
			}
			g = h[0] = nc[np[0]] = 0;
			for (int i = 1; i < n; i++)
			{
				if (prov(np[i], np[i - 1], k))
					g++, h[g] = i;
				nc[np[i]] = g;
			}
			c = nc, p = np, k++;
			if (g == n)
				break;
		}
	}
};

struct que {
	stack<pair<int, int>> s1, s2;
	void add(int x)
	{
		int ane = 1e9;
		if (s1.size())
			ane = min(ane, s1.top().second);
		s1.push({ x, min(ane, x) });
	}
	void res()
	{
		while (s1.size())
		{
			int g = s1.top().first;
			s1.pop();
			int ane = 1e9;
			if (s2.size())
				ane = min(ane, s2.top().second);
			s2.push({ g, min(ane, g) });
		}
	}
	int mi()
	{
		int ane1 = 1e9, ane2 = 1e9;
		if (s1.size())
			ane1 = min(ane1, s1.top().second);
		if (s2.size())
			ane2 = min(ane2, s2.top().second);
		return min(ane1, ane2);
	}
	int gy() {
		if (!s2.size())
			res();
		int x = s2.top().first;
		return x;
	}
	int del()
	{
		if (!s2.size())
			res();
		int x = s2.top().first;
		s2.pop();
		return x;
	}
};

const int maxn = 1e6 + 113;
bool used[maxn];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(0);
	string s;
	cin >> s;
	int yt = s.size();
	int b1 = 0, b2 = 0;
	int de = 0, su = 0, lasty = 0;
	que mu;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			b1++;
			su++;
		}
		else
		{
			b2++;
			su--;
		}
		mu.add(su);
		lasty = su;
	}
	int vs = max(b2 - b1, 0);
	for (int i = 0; i < s.size(); i++)
	{
		int u = mu.mi();
		if (u + de >= -vs)
			used[i] = 1;
		if (s[i] == '(')
			de--;
		else
			de++;
		mu.del();
		mu.add(lasty - de);
	}
	id0 mg(s);
	int pos;
	for (int i = 0; i < s.size(); i++)
		if (used[mg.p[i]])
		{
			pos = mg.p[i];
			break;
		}
	string h;
	for (int i = pos; i < s.size(); i++)
		h.push_back(s[i]);
	for (int i = 0; i < pos; i++)
		h.push_back(s[i]);
	while (b1 < b2)
	{
		cout << "(";
		b1++;
	}
	cout << h;
	while (b1 > b2)
	{
		cout << ")";
		b2++;
	}
	

}

