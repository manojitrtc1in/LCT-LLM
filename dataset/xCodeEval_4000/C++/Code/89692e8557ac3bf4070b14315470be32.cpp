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

struct suff_auto {
	struct vert {
		map<char, int> nex;
		bool term;
		int cn, link, len;
		vert() {
			term = cn = link = len = 0;
		}
	};
	vector<vert> ms;
	int cnt = 1, last = 0;
	suff_auto() {
		ms.push_back(vert());
		ms[0].link = -1;
	}
	void upd(char s, int u)
	{
		int newcnt = cnt + 1;
		ms.push_back(vert());
		ms[cnt].cn = 1;
		ms[cnt].len = ms[last].len + 1;
		while (last != -1 && ms[last].nex[s] == 0)
		{
			ms[last].nex[s] = cnt;
			last = ms[last].link;
		}
		if (last == -1)
			ms[cnt].link = 0;
		else if (ms[ms[last].nex[s]].len == ms[last].len + 1)
			ms[cnt].link = ms[last].nex[s];
		else
		{
			newcnt = cnt + 2;
			ms.push_back(vert());
			int q = ms[last].nex[s];
			ms[cnt + 1].len = ms[last].len + 1;
			ms[cnt + 1].nex = ms[q].nex;
			ms[cnt + 1].link = ms[q].link;
			ms[cnt].link = ms[q].link = cnt + 1;
			while (last != -1 && ms[last].nex[s] == q)
			{
				ms[last].nex[s] = cnt + 1;
				last = ms[last].link;
			}
		}
		last = cnt;
		cnt = newcnt;
	}
	void buildcn() {
		vector<pair<int, int>> sp;
		for (int i = 0; i < ms.size(); i++)
			sp.push_back({ ms[i].len, i });
		sort(sp.begin(), sp.end());
		for (int i = sp.size() - 1; i >= 1; i--)
			ms[ms[sp[i].second].link].cn += ms[sp[i].second].cn;
	}
};
const int maxn = 5e6;
bool used[maxn];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(0);
	string s;
	cin >> s;
	suff_auto mg;
	for (int i = 0; i < s.size(); i++)
		mg.upd(s[i], 1);
	mg.buildcn();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		vector<int> fd;
		int le = 0;
		int i1 = 0;
		int root = 0;
		long long ans = 0;
		for (int d = 0; d < s.size(); d++)
		{
			while (le < s.size())
			{
				if (mg.ms[root].nex[s[i1]] == 0)
					break;
				root = mg.ms[root].nex[s[i1]];
				le++;
				i1 = (i1 + 1) % s.size();
			}
			if (le == s.size() && !used[root])
			{
				ans += mg.ms[root].cn;
				used[root] = 1;
				fd.push_back(root);
			}
			int y = mg.ms[root].link;
			if (y == -1)
				break;
			if (mg.ms[y].len == le - 1)
				root = y;
			le--;
		}
		cout << ans << "\n";
		for (int i = 0; i < fd.size(); i++)
			used[fd[i]] = 0;
	}
	

}

