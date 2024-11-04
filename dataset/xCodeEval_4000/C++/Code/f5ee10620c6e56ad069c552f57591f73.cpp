#include <bits/stdc++.h>
#include <map>
#include <iostream>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
#define zhalok Zhalok
#define inf 1000000001
#define ll long long int
#define ull unsigned long long
#define loop(i, a, b) for (ll i = a; i < b; i++)
#define negloop(i, a, b) for (ll i = a; i >= b; i--)
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define pb push_back
#define be begin()
#define en end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define ff first
#define ss second
#define MOD 1000000007
#define sz 10001
#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(), v.end()
#define eps 1e-9
#define pi acos(-1.0)

ll minn(ll a, ll b)
{
	return a < b ? a : b;
}

ll maxx(ll a, ll b)
{
	return a > b ? a : b;
}

ll cill(ll a, ll b)
{
	if (a % b == 0)
		return a / b;
	return a / b + 1;
}



ll mod_exp(ll a, ll n, ll mod)
{
	if (n == 0)
		return 1;
	if (n % 2 == 0)
	{
		ll temp = mod_exp(a, n / 2, mod);
		return (temp % mod * temp % mod) % mod;
	}
	else
	{
		ll temp1 = a;
		ll temp2 = mod_exp(a, n - 1, mod);
		return (temp1 % mod * temp2 % mod) % mod;
	}
}

ll abss(ll a)
{
	if (a >= 0)
		return a;
	else
		return -1 * (a);
}

long double get_angle(pii a, pii b, pii c)
{
	int x1 = a.first;
	int y1 = a.second;
	int x2 = b.first;
	int y2 = b.second;
	int x3 = c.first;
	int y3 = c.second;
	long double len1 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	long double len2 = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
	long double val = ((x1 - x2) * (x3 - x2) + (y1 - y2) * (y3 - y2)) / (len1 * len2);
	return acos(val);
}

long double find_point_dis(pii point1, pii point2)
{
	long double temp_ans;
	temp_ans = ((point1.first - point2.first) * (point1.first - point2.first));
	temp_ans += ((point1.second - point2.second) * (point1.second - point2.second));
	return sqrt(temp_ans);
}

int check_sidde(pii p1, pii p2, pii p3)
{
	int x1 = p1.first;
	int y1 = p1.second;
	int x2 = p2.first;
	int y2 = p2.second;
	int x3 = p3.first;
	int y3 = p3.second;

	ll ans = (x3 - x1) * (y1 - y2) - (y3 - y1) * (x1 - x2);
	if (ans >= 0)
		return 1;
	else
		return -1;
}

ll cnt_div(ll n, ll k)
{
	ll cnt = 0;
	while (n % k == 0)
	{
		cnt++;
		n /= k;
	}
	return cnt;
}

ll gcd(ll a, ll b)
{
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
	ll g = gcd(a, b);
	return (a * b) / g;
}




















































































































































































































































































































































































































































































































































































































ll get_digit_sum(ll n)
{
	ll sum = 0;
	while (n)
	{
		sum += (n % 10);
		n /= 10;
	}
	return sum;
}

ll count_digits(ll n)
{
	ll ans = 0;
	while (n)
	{
		ans++;
		n /= 10;
	}
	return ans;
}








































































































vll fact;

void precalculation()
{
	fact.push_back(1);
	ll factor = 1;
	for (int i = 1; i <= 200000; i++)
	{
		factor *= i;
		factor %= MOD;
		fact.push_back(factor);
	}
}

bool primechk[sz];

vector<int> primes;

void seive(ll n)
{

	for (ll i = 2; i * i <= n; i++)
		if (primechk[i] == false)
			for (ll j = i * i; j <= n; j += i)
				primechk[j] = true;

	for (int i = 2; i <= n; i++)
		if (primechk[i] == false)
			primes.push_back(i);
}

ll count_primes(ll x, ll p)
{
	ll cnt = 0;
	while (x % p == 0)
	{
		cnt++;
		x /= p;
	}

	return cnt;
}

vll used_primes;

void factorization(ll n)
{
	used_primes.clear();
	ll temp_n = n;
	for (int i = 2; i * i <= temp_n; i++)
		if (n % i == 0)
		{
			used_primes.push_back(i);

			n /= i;
		}

	if (n > 1)
		used_primes.push_back(n);
}

int calculate_digits(ll n)
{

	ll cnt = 0;
	while (n)
	{
		n /= 10;
		cnt++;
	}

	return cnt;
}

ll digit_to_num(vll v)
{
	ll sum = 0;
	for (auto x : v)
	{
		sum *= 10;
		sum += x;
	}
	return sum;
}

int sum_of_digits(int n)
{
	int sum = 0;
	while (n)
	{
		sum += (n % 10);
		n /= 10;
	}

	return sum;
}

int extended_gcd(int a, int b, int &x, int &y)
{

	if (b == 0)
	{
		cout << "BAse case" << endl;
		x = 1;
		y = 0;
		return a;
	}

	cout << "not base case" << endl;
	int x1, y1;
	int d = extended_gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

void solve()
{
	int cnt1[100001][2];
	int cnt2[100001][2];
	memset(cnt1, 0, sizeof cnt1);
	memset(cnt2, 0, sizeof cnt2);

	int n;
	cin >> n;

	vi v;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
		cnt1[x][i % 2]++;
	}

	sort(all(v));

	for (int i = 0; i < n; i++)
		cnt2[v[i]][i % 2]++;

	for (int i = 0; i < n; i++)
		if (cnt1[v[i]][1] != cnt2[v[i]][1] || cnt1[v[i]][0] != cnt2[v[i]][0])
		{
			cout << "NO" << endl;
			return;
		}

	cout << "YES" << endl;
}

int main()
{

	

	


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;

	


	cin >> t;
	for (int i = 1; i <= t; i++)
		solve();
}



