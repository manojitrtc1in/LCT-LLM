#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iterator>
#include <ctime>

using namespace std;

#define ll long long 
vector<bool> prime(1000001, true);
ll cha;
const int INF = 1000000000;
vector <vector<int>> g(0);
vector <pair<ll, ll>> t(0);
pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
	if (a.first > b.first)
		return a;
	if (b.first > a.first)
		return b;
	return make_pair(a.first, a.second + b.second);
}

void build(vector <ll> a, int v, int tl, int tr) {
	if (tl == tr)
		t[v] = make_pair(a[tl], 1);
	else {
		int tm = (tl + tr) / 2;
		build(a, v * 2, tl, tm);
		build(a, v * 2 + 1, tm + 1, tr);
		t[v] = combine(t[v * 2], t[v * 2 + 1]);
	}
}
pair<int, int> get_max(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return make_pair(-INF, 0);
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return combine(
		get_max(v * 2, tl, tm, l, min(r, tm)),
		get_max(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
	);
}
void update(int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
		t[v] = make_pair(new_val, 1);
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update(v * 2, tl, tm, pos, new_val);
		else
			update(v * 2 + 1, tm + 1, tr, pos, new_val);
		t[v] = combine(t[v * 2], t[v * 2 + 1]);
	}
}

void swap(ll a, ll b)
{
	a += b;
	b = a - b;
	a -= b;
}

unsigned ll binpow(ll a, ll n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}

int phi(int n) {
	int result = n;
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}

void pr(int n)
{
	prime[0] = prime[1] = false;
	for (int i = 2; i <= n; ++i)
		if (prime[i])
			if (i * 1ll * i <= n)
				for (int j = i * i; j <= n; j += i)
					prime[j] = false;
}
ll gcd(ll a, ll b)
{
	if (b == 0)
	{
		if (a == 0)
		{
			return -1;
		}
		return a;
	}
	return gcd(abs(b - a), a);
}


int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tt,n;

	cin >> tt;
	while (tt--)
	{
		int last = 0, h = 1, g, last1 = 0;
		cin >> n;
		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			cin >> g;
			if (g == 0)
			{
				last1 = 0;
				last++;
			}
			else
			{
				last = 0;
				last1++;
				if (last1 == 1)
				{
					h++;
				}
				else
				{
					h += 5;
				}
			}
			if (last == 2)
			{
				h = -1;
				flag = true;

			}
		}
		if (flag)
		{
			h = -1;
		}
		cout << h << endl;
	}
}
