#pragma GCC optimize("Ofast,no-stack-protector")


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

const int mx = 2e5 + 113;
vector<long long> prost;
const long long p = 31, mod = 1e9 + 7;

struct hashs {
	vector<long long> hs;
	hashs(string s)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (i == 0)
				hs.push_back(s[i]);
			else
				hs.push_back((hs.back() + 1LL * s[i] * prost[i]));
		}
	}
	long long zp(int l, int r)
	{
		long long s1 = hs[r], s2 = (l != 0) ? hs[l - 1] : 0;
		return ((1LL * (s1 - s2) * prost[mx - l + 5]));
	}
};

bool us[mx][30];

vector<int> sp2[mx];
vector<int> sp3;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(0);
	prost.push_back(1);
	for (int i = 1; i <= mx + 13; i++)
		prost.push_back((prost.back() * p));
	int xs;
	cin >> xs >> xs;
	string s, t;
	cin >> s >> t;
	vector<string> ms1, ms2;
	vector<hashs> f1, f2;
	for (char e = 'a'; e <= 'z'; e++)
	{
		string b1, b2;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == e)
				b1.push_back('1');
			else
				b1.push_back('0');
		}
		for (int i = 0; i < t.size(); i++)
		{
			if (t[i] == e)
				b2.push_back('1');
			else
				b2.push_back('0');
		}
		f1.push_back(hashs(b1));
		f2.push_back(hashs(b2));
	}
	int c = t.size();
	for (int i = 0; i + c - 1 < s.size(); i++)
	{
		for (int k1 = 0; k1 < 26; k1++)
		{
			for (int k2 = 0; k2 < 26; k2++)
			{
				long long h1 = f1[k1].zp(i, i + c - 1);
				long long h2 = f2[k2].zp(0, c - 1);
				long long h3 = f1[k2].zp(i, i + c - 1);
				long long h4 = f2[k1].zp(0, c - 1);
				if (h1 == h2 && h3 == h4)
					us[i][k1] = us[i][k2] = 1;
			}
		}
	}
	for (int k1 = 0; k1 < 26; k1++)
	{
		int h = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == char(k1 + 'a'))
				h++;
			if (i >= c - 1)
			{
				if (h != 0)
					sp2[i - c + 1].push_back(k1);
				if (s[i - c + 1] == char(k1 + '1'))
					h--;
			}
		}
	}
	for (int k1 = 0; k1 < 26; k1++)
	{
		bool tr = false;
		for (int i = 0; i < t.size(); i++)
		{
			if (t[i] == char('a' + k1))
				tr = true;
		}
		if (tr)
			sp3.push_back(k1);
	}
	vector<int> ans;
	for (int i = 0; i + c - 1 < s.size(); i++)
	{
		bool tr = true;
		for (int j = 0; j < sp2[i].size(); j++)
			tr = (tr & us[i][sp2[i][j]]);
		for (int j = 0; j < sp3.size(); j++)
			tr = (tr & us[i][sp3[j]]);
		if (tr)
			ans.push_back(i + 1);
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	

}