#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,avx2,popcnt,tune=native")


#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma comment(linker, "/STACK:36777216")

#define _CRT_SECURE_NO_WARNINGS
#include <chrono>
#include <set>
#include <map>
#include <deque>
#include <cmath>
#include <queue>
#include <cassert>
#include <random>
#include <bitset>
#include <iomanip>
#include <numeric>
#include <time.h>

#include <ctime>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>




#define mp make_pair
#define pbc push_back
#define pob pop_back()
#define empb emplace_back
#define queuel queue<long long>
#define sqr(a) ((a) * (a))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define matrix vector<vector<ll>>
#define pin(p) cin >> p.first >> p.second;
#define rev(v) reverse(v.begin(), v.end());
#define mx(v) max_element(v.begin(), v.end());
#define mn(v) min_element(v.begin(), v.end());
#define sout(s, c) for (auto i : s) cout << i << c;
#define pout(p) cout << p.first << " " << p.second;
#define er(v, l, r) erase(v.begin() + l, v.begin() + r);
#define vin(v) for (ll i = 0; i < v.size(); ++i) cin >> v[i];
#define vout(v, c) for (int i = 0; i < v.size(); ++i) cout << v[i] << c;
#define pushi(v, a) for (int i = 0; i < a.size(); ++i) v.push_back(a[i]);
#define sin(s, n) for (int i = 0; i < n; ++i){int a; cin >> a; s.insert(a); }
#define fastio() ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0); srand(time(NULL))
#define sp system("pause")


using namespace std;

					

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;


const int MAXN = 2007;
const ll inf = 2e9 + 239;
const ld EPS = 1e-4;
const ld PI = acos(-1);
int mod = (int)998244353;
const int MOD7 = 1000000007;
const int MOD9 = 1000000009;
const int a228 = 18;
const ll kekmod = 1791791791;
const ll bestmod = 1148822869;
vector<ll> mods = { kekmod,bestmod,mod,MOD9,1000000007 };
vector<ll> hashpows = { 29,31,37,43,47,53,179,229 };
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count() + 228 + 'i' + 'q' + 1337 + 1488);
ll MOD = mods[rnd() % mods.size()];
ll hashpow = hashpows[rand() % hashpows.size()];
signed main()
{
	fastio();
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	ll c1 = 1;
	ll c2 = 1;
	ll c3 = 1;
	ll c4 = 1;
	for (int i = 0; i < s1.size(); ++i)
	{
		c1 *= (s1[i] == '?' ? 10 : 1);
		c1 *= (s2[i] == '?' ? 10 : 1);
		c1 %= MOD7;
		if (s1[i] != '?' && s2[i] != '?' && s1[i] < s2[i]) c2 = 0;
		if (s1[i] != '?' && s2[i] != '?' && s1[i] > s2[i]) c3 = 0;
		if (s1[i] != '?' && s2[i] != '?' && s1[i] != s2[i]) c4 = 0;
		if (s1[i] == '?' && s2[i] == '?')
		{
			c4 *= 10;
			c4 %= MOD7;
			c2 *= 55;
			c2 %= MOD7;
			c3 *= 55;
			c3 %= MOD7;
		}
		if (s1[i] == '?' && s2[i] != '?')
		{
			c2 *= '9' - s2[i] + 1;
			c2 %= MOD7;
			c3 *= s2[i] - '0' + 1;
			c3 %= MOD7;
		}
		else if (s1[i] != '?' && s2[i] == '?')
		{
			c2 *= s1[i] - '0' + 1;
			c3 *= '9' - s1[i] + 1;
			c2 %= MOD7;
			c3 %= MOD7;
		}
	}
	cout << (c1 - c2 - c3 + c4 + 1ll *  MOD7 * 3) % MOD7;
	

}