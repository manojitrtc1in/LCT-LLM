














































using namespace std;



mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

pair<int, int> df[11];

struct id0 {
	struct vert {
		map<char, int> nex;
		int cn[10];
		int len, link;
		int u;
		vert() {
			len = link = u = 0;
			for (int i = 0; i < 10; i++)
				cn[i] = 0;
		}
	};
	vector<vert> ms;
	vector<bool> us;
	int cnt, last;
	id0()
	{
		ms.push_back(vert());
		cnt = 1, last = 0;
		ms[0].link = -1;
	}
	void upd(char e)
	{
		int newcnt = cnt + 1;
		ms.push_back(vert());
		ms[cnt].len = ms[last].len + 1;
		while (last != -1 && ms[last].nex[e] == 0)
		{
			ms[last].nex[e] = cnt;
			last = ms[last].link;
		}
		if (last == -1)
			ms[cnt].link = 0;
		else if (ms[ms[last].nex[e]].len == ms[last].len + 1)
			ms[cnt].link = ms[last].nex[e];
		else
		{
			newcnt = cnt + 2;
			ms.push_back(vert());
			int q = ms[last].nex[e];
			ms[cnt + 1].len = ms[last].len + 1;
			ms[cnt + 1].nex = ms[q].nex;
			ms[cnt + 1].link = ms[q].link;
			ms[q].link = ms[cnt].link = cnt + 1;
			while (last != -1 && ms[last].nex[e] == q)
			{
				ms[last].nex[e] = cnt + 1;
				last = ms[last].link;
			}
		}
		last = cnt;
		cnt = newcnt;
	}
	void dfs(int v, int g, long long &s)
	{
		us[v] = 1;
		for (auto it : ms[v].nex)
		{
			if (!us[it.second])
				dfs(it.second, g, s);
			if ((it.first >= '0' && it.first <= '9') || it.first == '
			{
				if (it.first == '
					ms[v].u++;
				else
					ms[v].cn[(int)it.first - '0']++;
			}
			else
			{
				for (int i = 0; i <= 9; i++)
					ms[v].cn[i] += ms[it.second].cn[i];
				ms[v].u += ms[it.second].u;
			}
		}
		if (v != 0)
		{
			int l = ms[ms[v].link].len + 1, r = ms[v].len;
			bool tr = (ms[v].u != 0);
			for (int i = 0; i < g; i++)
			{
				if (ms[v].cn[i] < df[i].first || ms[v].cn[i] > df[i].second)
					tr = false;
			}
			if (tr)
				s += (r - l + 1);
		}
	}
};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(0);
	id0 de;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		de.upd(s[i]);
	de.upd('
	int y;
	cin >> y;
	for (int i = 0; i < y; i++)
	{
		cin >> s;
		for (int j = 0; j < s.size(); j++)
			de.upd(s[j]);
		de.upd(char('0' + i));
		int a, b;
		cin >> a >> b;
		df[i] = { a, b };
	}
	de.us.resize(de.ms.size());
	long long ans = 0;
	de.dfs(0, y, ans);
	cout << ans;
	

	
}

