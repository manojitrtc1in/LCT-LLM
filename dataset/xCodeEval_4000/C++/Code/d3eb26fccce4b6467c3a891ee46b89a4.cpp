#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
#include <string>
#include <cmath>
#include <map>
#include <stack>

using namespace std;
typedef long long ll;
const ll mod = 1000000007, INF = 2000000001;
int dx[] = {0,1,0,-1, 1,1,-1,-1, 0}, dy[] = {-1,0,1,0, -1,1,1,-1, 0};
const double EPS = 1e-9;

ll gcd(ll a, ll b)
{
    return (b != 0) ? gcd(b, a % b) : a;
}

ll modpow(ll a, ll x, ll m = mod)
{
	int p = 1;
	while (x > 0)
	{
		if (x & 1 == 1)
		{
			p = p * a % m;
			--x;
		}
		else
		{
			x >>= 1;
			a = a * a % m;
		}
	}
	return p;
}

void z(const string & s, vector<int> & v)
{
	int n = s.length();
	for (int i = 1, l = 0, r = 0; i < n; ++i)
	{
		if (i <= r)
			v[i] = min(v[i-l],r-i+1);
		while (i + v[i] < n && s[v[i]] == s[i+v[i]])
			++v[i];
		if (i + v[i] - 1 > r)
			r = (l = i) + v[i] - 1;
	}
}

bool dfs(vector< vector<string> > & states, int sx, int sy, int n)
{
	bool ans = false;
	if (n == 8)
		ans = true;
	else if (states[n][sy][sx] == 'S')
		ans = false; 
	else
		for (int d = 0; d < 9 && !ans; ++d)
		{
			int x = sx + dx[d], y = sy + dy[d];
			if (min(x,y) >= 0 && max(x,y) < 8)
			{
				if (states[n][y][x] == '.')
				{
					ans = dfs(states,x,y,n+1);
				}
			}
		}
	return ans;
}

void _a()
{
	string s;
	cin >> s;
	int n = s.length();
	vector< vector<int> > d1(n + 2, vector<int>(3));
	for (int i = 1; i <= n; ++i)
	{
		d1[i] = d1[i - 1];
		++d1[i][s[i-1] - 'x'];
	}
	int m;
	cin >> m;
	while (m--)
	{
		int l, r;
		cin >> l >> r;
		int x = d1[r][0] - d1[l - 1][0], y = d1[r][1] - d1[l - 1][1], z = d1[r][2] - d1[l - 1][2];
		int tmin = min(x, min(y, z)), tmax = max(x, max(y, z));
		if (r - l < 2)
			cout << "YES\n";
		else if (tmin == 0 || tmax - tmin > 1)
			cout << "NO\n";
		else
			cout << "YES\n";
	}


	

	


	
}

void _b()
{
	int n, m, p;
	cin >> n >> m >> p;
	vector<int> a(n);
	map<int,int> b;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < m; ++i)
	{
		int t;
		cin >> t;
		++b[t];
	}
	vector<int> ans;
	for (int i = 0; i < p; ++i)
	{
		if (p * (m - 1) < n - 1)
		{
			map<int, int> mp;
			int j = 0;
			for (int c = 0; c < m; ++c, j += p)
			{
				++mp[a[j]];
			}
			if (mp == b)
				ans.push_back(i);
			

			while (j < n)
			{
				++mp[a[j]];
				if (mp[j - m * p] == 1)
					mp.erase(mp[j - m * p]);
				else
					--mp[j - m * p];

			}

		}
	}

	

	

	
}

class P
{
public:
	double n, d;
	P(double dd):
		n(dd), d(dd-floor(n))
	{
	}
};

class CP
{
public:
	bool operator()(const P & a, const P & b) const
	{
		return a.d < b.d;
	}
};

void _c()
{
	



	
}

void _d()
{
	



	
}


























































































































































void _e()
{


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

}

ll gcdex(ll a, ll b, ll & x, ll & y)
{
	if (a == 0)
	{
		x = 0;
		y = 1;
		return b;
	}
	else
	{
		ll x1, y1;
		ll g = gcdex(b%a,a,x1,y1);
		x = y1 - b / a * x1;
		y = x1;
		return g;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	_a();
	

	

	

	

	return 0;
}