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

const int maxn = 3e5 + 113;
long long ans[maxn];
const long long mod = 1e9 + 7;

struct suff_auto {
	struct vert {
		int len, link;
		map<char, int> nt;
		int cn[3];
		vert() {
			len = link = cn[0] = cn[1] = cn[2] = 0;
		}
	};
	vector<vert> ms;
	vector<bool> used;
	int cnt, last;
	suff_auto(string s)
	{
		ms.push_back(vert());
		cnt = 1, last = 0;
		ms[0].len = 0, ms[0].link = -1;
		for (int i = 0; i < s.size(); i++)
			add(s[i]);
		used.resize(cnt);
	}
	void add(char e)
	{
		int newcnt = cnt + 1;
		ms.push_back((vert()));
		ms[cnt].len = ms[last].len + 1;
		while (last != -1 && ms[last].nt[e] == 0)
		{
			ms[last].nt[e] = cnt;
			last = ms[last].link;
		}
		if (last == -1)
			ms[cnt].link = 0;
		else if (ms[ms[last].nt[e]].len == ms[last].len + 1)
			ms[cnt].link = ms[last].nt[e];
		else
		{
			newcnt = cnt + 2;
			ms.push_back(vert());
			int q = ms[last].nt[e];
			ms[cnt + 1].len = ms[last].len + 1;
			ms[cnt + 1].nt = ms[q].nt;
			ms[cnt + 1].link = ms[q].link;
			ms[cnt].link = ms[q].link = cnt + 1;
			while (last != -1 && ms[last].nt[e] == q)
			{
				ms[last].nt[e] = cnt + 1;
				last = ms[last].link;
			}
		}
		last = cnt;
		cnt = newcnt;
	}
	void dfs(int v)
	{
		used[v] = 1;
		for (pair<char, int> to : ms[v].nt)
		{
			if (!used[to.second]) dfs(to.second);
			if (to.first == '1')
				ms[v].cn[0]++;
			else if (to.first == '2')
				ms[v].cn[1]++;
			else if (to.first == '3')
				ms[v].cn[2]++;
			else
			{
				ms[v].cn[0] += ms[to.second].cn[0];
				ms[v].cn[1] += ms[to.second].cn[1];
				ms[v].cn[2] += ms[to.second].cn[2];
			}
		}
	}
	void build() {
		dfs(0);
		for (int i = 0; i <= last; i++)
		{
			if (i != 0)
			{
				int r = ms[i].len, l = ms[ms[i].link].len;
				ans[r] = (ans[r] + 1LL * ms[i].cn[0] * ms[i].cn[1] * ms[i].cn[2]) % mod;
				ans[l] = (ans[l] - 1LL * ms[i].cn[0] * ms[i].cn[1] * ms[i].cn[2]) % mod;
			}
			else
				ans[ms[i].len] = (ans[ms[i].len] + 1LL * ms[i].cn[0] * ms[i].cn[1] * ms[i].cn[2]) % mod;
		}
	}
};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(0);
	string a, b, c;
	cin >> a >> b >> c;
	suff_auto fb(a + '1' + b + '2' + c + '3');
	fb.build();
	for (int i = min(a.size(), min(b.size(), c.size())); i >= 0; i--)
		ans[i] = ((ans[i] + ans[i + 1]) % mod + mod) % mod;
	for (int i = 1; i <= min(a.size(), min(b.size(), c.size())); i++)
		cout << ans[i] << " ";
	

}

