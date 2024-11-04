





using namespace std;


























ll minn(ll a, ll b)
{
	return a < b ? a : b;
}

ll maxx(ll a, ll b)
{
	return a > b ? a : b;
}

double maxx(double a, double b)
{
	return (a >= b ? a : b);
}

double minn(double a, double b)
{
	return (a <= b ? a : b);
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

long double id4(pii point1, pii point2)
{
	long double temp_ans;
	temp_ans = ((point1.first - point2.first) * (point1.first - point2.first));
	temp_ans += ((point1.second - point2.second) * (point1.second - point2.second));
	return sqrt(temp_ans);
}

int id2(pii p1, pii p2, pii p3)
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




















































































































































































































































































































































































































































































































































































































ll id6(ll n)
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

void id7()
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

ll process(ll p, ll gap, ll pr)
{

	for (int i = 0; i < gap; i++)
		p /= pr;

	return p;
}

ll id3(ll x, ll p)
{
	ll cnt = 0;
	while (x % p == 0)
	{
		cnt++;
		x /= p;
	}

	return cnt;
}

vll id1;

void factorization(ll n)
{
	id1.clear();
	ll temp_n = n;
	for (int i = 2; i * i <= temp_n; i++)
		if (n % i == 0)
		{
			id1.push_back(i);

			n /= i;
		}

	if (n > 1)
		id1.push_back(n);
}

ll dp[100001][2];

vll vertices[100001];

vll adj[100001];

ll dfs(int cur_node, int set_val, int par)
{

	if (dp[cur_node][set_val] != -1)
		return dp[cur_node][set_val];

	ll ans = 0;

	for (int i = 0; i < adj[cur_node].size(); i++)
	{

		int next_node = adj[cur_node][i];
		if (next_node != par)
		{
			ll temp_ans = 0;
			temp_ans = maxx(temp_ans, abs(vertices[cur_node][set_val] - vertices[next_node][0]) + dfs(next_node, 0, cur_node));
			temp_ans = maxx(temp_ans, abs(vertices[cur_node][set_val] - vertices[next_node][1]) + dfs(next_node, 1, cur_node));
			ans += temp_ans;
		}
	}

	return dp[cur_node][set_val] = ans;
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

ll id0(vll v)
{
	ll sum = 0;
	for (auto x : v)
	{
		sum *= 10;
		sum += x;
	}
	return sum;
}

int id5(int n)
{
	int sum = 0;
	while (n)
	{
		sum += (n % 10);
		n /= 10;
	}

	return sum;
}

ll calc(vll v)
{
	sort(all(v), greater<ll>());
	vll cs;
	cs.push_back(0);
	ll sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i];
		cs.push_back(sum);
	}

	ll ans = 0;
	for (int i = 1; i <= v.size(); i++)
	{
		ll temp_ans = (v.size() - i) * v[i - 1] - (cs[v.size()] - cs[i]);
		ans += temp_ans;
	}

	return ans;
}

pll avg(vll v)
{
	ll sum = 0;
	for (int i = 0; i < v.size(); i++)
		sum += v[i];
	return {(sum / v.size()), (sum % v.size())};
}

double ans = 0;

void get_ans(double c, double m, double p, double v, int cnt, double cur_prob)
{

	ans += cur_prob * cnt * p;

	if (c > eps)
	{
		double newc = maxx(0.0, c - v);

		double fact = minn(c, v);

		double new_prob = cur_prob * c;
		if (m > eps && p > eps)
		{
			fact /= 2;

			double newm = m + fact;
			double newp = p + fact;
			get_ans(newc, newm, newp, v, cnt + 1, new_prob);
		}
		else if (m > eps)
		{
			double newm = m + fact;
			get_ans(newc, newm, p, v, cnt + 1, new_prob);
		}
		else if (p > eps)
		{
			double newp = p + fact;
			get_ans(newc, m, newp, v, cnt + 1, new_prob);
		}
	}

	if (m > eps)
	{
		double newm = maxx(0.0, m - v);
		double fact = minn(m, v);

		double new_prob = m * cur_prob;
		if (c > eps && p > eps)
		{
			fact /= 2;

			double newc = c + fact;
			double newp = p + fact;
			get_ans(newc, newm, newp, v, cnt + 1, new_prob);
		}
		else if (c > eps)
		{
			double newc = c + fact;
			get_ans(newc, newm, p, v, cnt + 1, new_prob);
		}
		else if (p > eps)
		{
			double newp = p + fact;
			get_ans(c, newm, newp, v, cnt + 1, new_prob);
		}
	}
}

void solve()
{

	double c, m, p, v;
	cin >> c >> m >> p >> v;
	ans = 0;
	get_ans(c, m, p, v, 1, 1.0);
	printf("%.9lf\n", ans);
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



