#include              <algorithm>
#include               <iostream>
#include                <cstring>
#include                <stdio.h>
#include                 <string>
#include                 <vector>
#include                 <time.h>
#include                  <queue>
#include                  <cmath>
#include                    <map>
#include                    <set>
using   namespace            std;
typedef	long long             vt;
typedef unsigned long long   vt2;
typedef	pair<vt,vt>          PVV;
typedef	pair<char,vt>        PCV;
typedef	pair<string, vt>     PSV;
typedef	map<vt,vt>           MVV;
typedef map<char,vt>         MCV;
typedef map<string,vt>       MSV;
#define sd(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define ss(x)   scanf("%s",&x)
#define fi(x,y) for(int i=x;i<y;i++)
#define fj(x,y) for(int j=x;j<y;j++)
#define fk(x,y) for(int k=x;k<y;k++)
const int MAXN = 1e6 + 9, INF = 0x3f3f3f3f;
vt HASHprime = 13331;



vt2 p[MAXN];
vt2 hashv(int len, char* s, vt2* hashs)
{
	hashs[0] = s[0];
	fi(1, len)
		hashs[i] = hashs[i - 1] * HASHprime + s[i];
	return hashs[len - 1];
}
map<char, bool> fxc;
map<vt2, vector<string>> vtos;
map<int, vector<string>> same;
map<string, int> k;
int main()
{
	fxc['a'] = 1; fxc['e'] = 1; fxc['i'] = 1; fxc['o'] = 1; fxc['u'] = 1;
	int n;
	sd(n);
	fi(0, n)
	{
		string temp;
		cin >> temp;
		int len = temp.size(), cnt = 0;
		char last='y',temp1[MAXN];
		fj(0, len)
		{
			if (fxc[temp[j]] == 1)
			{
				temp1[cnt++]='y';
				last = temp[j];
			}
		}
		temp1[cnt] = '\0';
		temp1[cnt - 1] = last;
		vt2 hashval = hashv(cnt, temp1, p);
		vtos[hashval].push_back(temp);
		k[temp] = cnt;
	}
	for (auto& it : vtos)
	{
		if (it.second.size() % 2 != 0)
		{
			same[k[it.second.back()]].push_back(it.second.back());
			it.second.pop_back();
		}
		if (it.second.size() < 2)
		{
			while (!it.second.empty())
			{
				same[k[it.second.back()]].push_back(it.second.back());
				it.second.pop_back();
			}
		}
	}
	vector<string> ans1, ans2;
	for (auto& it : same)
	{
		if (it.second.size() % 2 == 1)
			it.second.pop_back();
		while (!it.second.empty())
		{
			ans2.push_back(it.second.back());
			it.second.pop_back();
		}
	}
	for (auto& it : vtos)
	{
		while(it.second.size() >= 2)
		{
			ans1.push_back(it.second.back());
			it.second.pop_back();
			ans1.push_back(it.second.back());
			it.second.pop_back();
		}
	}
	if (ans1.size() >= 4)
	{
		if (ans2.size() >= ans1.size())
			cout << ans1.size() / 2 << endl;
		else
			cout << ans2.size() / 2 + (ans1.size()-ans2.size()) / 4 << endl;
	}
	else
	{
		cout << 0 << endl;
		return 0;
	}
	while (!ans1.empty())
	{
		if (!ans2.empty())
		{
			cout << ans2.back() << " ";
			ans2.pop_back();
			cout << ans1.back() << endl;
			ans1.pop_back();
			cout << ans2.back() << " ";
			ans2.pop_back();
			cout << ans1.back() << endl;
			ans1.pop_back();
		}
		else
		{
			if (ans1.size() < 4)
				break;
			cout << ans1.back() << ' ';
			ans1.pop_back();
			string temp = ans1.back();
			ans1.pop_back();
			cout << ans1.back() << endl;
			ans1.pop_back();
			cout << temp << ' ';
			cout << ans1.back() << endl;
			ans1.pop_back();
		}
	}
	return 0;
}
