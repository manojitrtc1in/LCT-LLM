




const ll mod = 1e9 + 7;


using namespace std;




const int N = 2e5 + 5;


ll ncr(ll n, ll r)
{
	ll res = 1;
	if (r > n)
		return 0;
	if (r > n - r)
		r = n - r;
	for (ll i = 1; i <= r; i++)
	{
		res *= (n - i + 1);
		res /= i;
	}
	return res;
}
ll _gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	return _gcd(b, a % b);
}
ll pow(ll a, ll b, ll mod)
{
	if (b == 0)
		return 1;
	if (b == 1)
		return a;
	ll smallans = pow(a, b / 2, mod);
	if (b & 1)
		return ((smallans * smallans) * a) ;
	return (smallans * smallans) ;
}
ll power(ll x, ll y, ll m)
{
	if (y == 0)
		return 1;
	ll p = power(x, y / 2, m) % m;
	p = (p * p) % m;
	return (y % 2 == 0) ? p : (x * p) % m;
}
ll id5(ll x, ll y, ll mod)
{
	ll ans = 1;
	ll a = x;
	while (y)
	{
		if (y & 1)
			ans = (ans * a) % mod;
		y = y >> 1;
		a = (a * a) % mod;
	}
	return ans;
}
ll modInv(ll x, ll mod)
{
	return power(x, mod - 2, mod) % mod;
}

ll fact(ll n)
{
	ll ans = 1;
	for (ll i = 2; i <= n; i++)
	{
		ans *= i;
	}
	return ans;
}
ll nck(ll n, ll k)
{
	ll res = 1;
	ll x = n;
	for (int i = 1; i <= k; i++)
	{
		res *= n--;
		res /= i;
	}
	return res;
}
void solve(int n, string &out, int i, int open, int close, vector<string> &ans)
{
	if (ans.size() == n)
		return;

	if (i == 2 * n)
	{
		ans.push_back(out);
		return;
	}

	if (open < n)
	{
		out[i] = '(';
		solve(n, out, i + 1, open + 1, close, ans);
	}
	if (close < open)
	{
		out[i] = ')';
		solve(n, out, i + 1, open, close + 1, ans);
	}
}
int id17(int maxSum, vector<int> a, vector<int> b) {
	

	int ans = 0;
	int index_a = 0, index_b = 0;
	int len_a = a.size(), len_b = b.size();
	int cur_sum = 0;
	

	

	

	

	

	

	


	

	


	

	


	

	


	

	

	

	

	

	

	

	

	

	

	

	

	while ( index_a < len_a and index_b  < len_b)
	{
		int minn = min( a[index_a], b[index_b]);

		if (cur_sum + minn > maxSum)
			break;

		cur_sum += minn;
		ans++;

		if (index_a + 1 < len_a and a[index_a] == minn and index_b + 1 < len_b and b[index_b] == minn)
		{
			int i = index_a , j = index_b;

			while (i < len_a and j < len_b)
			{
				if (a[i] != b[j])
				{
					if (a[i] < b[j])
					{
						index_a++;
					}
					else
					{
						index_b++;
					}
					break;
				}
				else
				{
					i++;
					j++;
				}
			}

			if (i == len_a)
				index_b++;
			else if (j == len_b)
				index_a++;
		}
		else if (a[index_a] == minn)
			index_a++;
		else
			index_b++;
	}
	while (index_a < len_a)
	{
		if (cur_sum + a[index_a] > maxSum)
			break;

		ans++;
		cur_sum += a[index_a];
		index_a++;
	}
	while (index_b < len_b)
	{
		if (cur_sum + b[index_b] > maxSum)
			break;
		ans++;
		cur_sum += b[index_b];
		index_b++;
	}
	return ans;

	

	

	

}





































int totalPairs(int n, vector<int>& values) {
	

	stack<pair<int, int>> s;
	vector<int> nextgreater(n);
	for (int i = n - 1; i >= 0; i--)
	{
		while (!s.empty() and values[i] >= s.top().first)
			s.pop();
		if (s.empty())
			nextgreater[i] = -1;
		else
			nextgreater[i] = s.top().second;
		s.push({values[i], i});
	}

	int ans = 0;
	set<pair<int, int>> sett;
	for (int i = 0; i < n - 1; i++)
	{
		int curans = 0;
		int curmax = INT_MIN;
		int index = nextgreater[i];
		if (index == -1)
			index = n - 1;
		cout << index << " ";
		

		if (i + 1 < n)
			sett.insert({values[i], values[i + 1]});
		for (int j = i + 1; j <= index; j++)
		{
			if (values[j] >= curmax)
			{
				

				curans++;
				sett.insert({values[i], values[j]});
				

			}

			curmax = max(curmax, values[j]);
		}
		ans += curans;
		

	}
	cout << "size = " << sett.size() << endl;
	

	return ans;
	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

}
string solution(string n) {
	

	

	

	int len = n.length();
	vector<int> a(100000, 0);
	for (int i = 0; i < len; i++)
	{
		if (n[i] == '0')
		{
			int j = i;
			while (j < len and n[j] == '0')
				j++;

			int cur_len = j - i;
			a[cur_len]++;
			i = j - 1;
		}
	}
	int id21 = 0 , count = -1;
	for (int i = 0; i < 100000; i++)
	{
		if (a[i] > 0)
		{
			id21 = i;
			count = a[i];
		}
	}

	cout << id21 << " " << count;
	if (id21 % 2 == 0)
		return "B";
	else
	{
		if (count > 1)
			return "B";
		else
			return "A";
	}
}






















void id9(int n, int m, int a, int b, int f, int s, int t) {
	

	vector<int> department_size = {0, f, s, t};
	unordered_map<string, int> department;
	for (int i = 0; i < n; i++)
	{
		string str; cin >> str;
		ll depart; cin >> depart;
		department[str] = depart;
	}
	vector< pair< vector<int>, set<string> > > groups;
	groups.push_back({{}, {} });
	vector<bool> flag(n + 1, true);
	unordered_map<string, int> group_no;
	for (int i = 0; i < m; i++)
	{
		string x, y; cin >> x >> y;
		if (x == y)
			continue;
		if (group_no.find(x) == group_no.end() and group_no.find(y) == group_no.end())
		{
			int id11 = groups.size();
			group_no[x] = id11 ;
			group_no[y] = id11 ;
			vector<int> cur(4, 0);
			int d1 = department[x], d2 = department[y];
			cur[d1]++;
			cur[d2]++;

			groups.push_back({cur, {x, y}});
		}
		else if (group_no.find(x) != group_no.end() and group_no.find(y) == group_no.end())
		{
			pair< vector<int>, set<string> > cur = groups[group_no[x]];
			int d1 = department[x], d2 = department[y];
			if (cur.second.size() + 1 <= b and cur.first[d2] + 1 <= department_size[d2])
			{
				groups[group_no[x]].first[d2]++;
				groups[group_no[x]].second.insert(y);
				group_no[y] = group_no[x];
			}
		}
		else if (group_no.find(x) == group_no.end() and group_no.find(y) != group_no.end())
		{
			pair< vector<int>, set<string> > cur = groups[group_no[y]];
			int d1 = department[x], d2 = department[y];
			if (cur.second.size() + 1 <= b and cur.first[d1] + 1 <= department_size[d1])
			{
				groups[group_no[y]].first[d1]++;
				groups[group_no[y]].second.insert(x);
				group_no[x] = group_no[y];
			}
		}
		else
		{
			pair< vector<int>, set<string> > cur1 = groups[group_no[x]], cur2 = groups[group_no[y]];
			int d1 = department[x], d2 = department[y];
			if (cur1.second.size() + cur2.second.size() <= b and cur1.first[1] + cur2.first[1]  <= f and cur1.first[2] + cur2.first[2] <= s and cur1.first[3] + cur2.first[3] <= t)
			{
				flag[group_no[y]] = false;
				groups[group_no[x]].first[1] += cur2.first[1];
				groups[group_no[x]].first[2] += cur2.first[2];
				groups[group_no[x]].first[3] += cur2.first[3];
				for (auto cur_str : cur2.second)
				{
					group_no[cur_str] = group_no[x];
					groups[group_no[x]].second.insert(cur_str);;
				}
			}
		}
	}
	int ans_len = INT_MIN;
	

	for (int i = 1; i < groups.size(); i++)
	{
		auto cur = groups[i];
		if (flag[i] == true and a <= cur.second.size() and ans_len < (int)cur.second.size())
		{
			

			ans_len = (int)cur.second.size();
		}
	}
	if (ans_len > 0)
	{
		vector<string> lastans;
		for (int i = 1; i < groups.size(); i++)
		{
			auto cur = groups[i];
			if (ans_len == (int)cur.second.size())
			{
				for (auto str : cur.second)
					lastans.push_back(str);
			}
		}
		sort(lastans.begin(), lastans.end());
		for (int i = 0; i < lastans.size(); i++)
			cout << lastans[i] << endl;
	}
	else
	{
		cout << "no groups";
	}
}



int spf[MAXN];






void sieve()
{
	spf[1] = 1;
	for (int i = 2; i < MAXN; i++)

		

		

		spf[i] = i;

	

	

	for (int i = 4; i < MAXN; i += 2)
		spf[i] = 2;

	for (int i = 3; i * i < MAXN; i++)
	{
		

		if (spf[i] == i)
		{
			

			for (int j = i * i; j < MAXN; j += i)

				

				

				if (spf[j] == j)
					spf[j] = i;
		}
	}
}
vector<int> id27(int x)
{
	vector<int> ret;
	while (x != 1)
	{
		ret.push_back(spf[x]);
		x = x / spf[x];
	}
	return ret;
}


void helper(vector<int> &values, int n, int i, long long int p1, long long int p2, int count1, int count2)
{
	if (_gcd(p1, p2) > 1)
		return;
	if (i >= n)
	{
		if (_gcd(p1, p2) == 1 and count1 > 0 and count2 > 0)
			

			return;
	}

	

	helper(values, n, i + 1, p1 * values[i], p2, count1 + 1, count2);
	

	helper(values, n, i + 1, p1, p2 * values[i], count1, count2 + 1);
	

	

	

	

	

	

	

	

	


	

	

	

}
void id16(int n, vector<int>& values)
{
	vector<int> sieve(1000002, 1);
	for (int i = 0; i <= 1000002; i += 2)
		sieve[i] = 0;
	for (int i = 3; i <= 1000002; i += 2)
	{
		if (sieve[i] == 1)
		{
			for (int j = i * 2 ; j <= 1000002; j += i)
				sieve[j] = 0;
		}
	}
	sieve[1] = 1;
	sieve[2] = 1;
	

	

	

	

	

	unordered_map<int, int> freq;
	for (int i = 0; i < n; i++)
		freq[values[i]]++;
	set<int> s;
	long long int id13 = 0;
	for (int i = 0; i < n; i++)
	{
		s.insert(values[i]);
		if (values[i] == 1)
			id13++;
	}
	vector<int> a;
	for (auto x : s)
		a.push_back(x);
	sort(a.begin(), a.end());

	vector<int> primes;
	for (int i = 0; i < a.size(); i++)
		if (sieve[a[i]] == 1 and a[i] != 1)
			primes.push_back(a[i]);

	unordered_map<int, pair<long long int, vector<int>>> mp;
	for (int i = 0; i < primes.size(); i++)
	{
		for (int j = primes[i]; j < 1000001; j += primes[i])
			if (s.find(j) != s.end())
			{
				mp[primes[i]].second.push_back(j);
				if (mp[primes[i]].second.size() == 1)
					mp[primes[i]].first = pow(j, freq[j]);
				else
					mp[primes[i]].first *= pow(j, freq[j]);
			}
	}
	vector<pair<long long int, vector<int>>> sets;
	for (auto p : mp)
		sets.push_back(p.second);
	vector<int> flag(n, true);
	

	

	

	

	

	for (int i = 0; i < sets.size(); i++)
	{
		cout << flag[i] << "  " << sets[i].first << " ";
		for (auto x : sets[i].second)
			cout << x << " ";
		cout << endl;
	}
	

	while (1)
	{
		bool id23 = false;
		for (int i = 0; i < sets.size(); i++)
		{
			if (flag[i] == false)
				continue;
			for (int j = 0; j < sets.size(); j++)
			{
				if (i != j and flag[j] == true)
				{
					long long int gcd = _gcd(sets[i].first, sets[j].first);
					if (gcd > 1)
					{
						flag[j] = false;
						sets[i].first *= sets[j].first;
						sets[i].first /= gcd;
					}
				}
			}
		}
		if (id23 == false)
			break;
	}
	for (int i = 0; i < sets.size(); i++)
	{
		cout << flag[i] << "  " << sets[i].first << " ";
		for (auto x : sets[i].second)
			cout << x << " ";
		cout << endl;
	}
	cout << endl << sets.size() << endl;
	long long int k = 0;
	for (int i = 0; i < sets.size(); i++)
	{
		if (flag[i] == true)
		{
			

			k++;
		}
	}
	cout << "k = " << k << endl;
	k += id13;
	if (k == 0 or k == 1)
	{
		cout << "NO" << endl << "0";
	}
	else
	{
		cout << "id13 = " << id13 << endl;
		cout << endl << k << endl;
		long long int lastans = 1;
		for (int i = 1; i <= k; i++)
			lastans = (lastans * 2) % mod;
		cout << "YES" << endl << lastans - 2;
	}



	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	















































































































































































































}


int helper(int n, int k, int d, int m, vector<int> &returns, int i, int curk)
{
	if (curk == 0)
	{
		int curans = 0;
		for (int index = i; index < n; index++)
		{
			if (d > 0)
			{
				curans += m * returns[index];
				d--;
			}
			else
				curans += returns[index];
		}
		return curans;
	}
	if (i >= n)
	{
		return INT_MIN;
	}

	int curans = INT_MIN;
	for (int index = i; index < n; index++)
	{
		int id3 = 0, dd = d;
		if (curk != k)
		{
			for (int index2 = i; index2 < index; index2++)
			{
				if (dd > 0)
				{
					id3 += m * returns[index2];
					dd--;
				}
				else
					id3 += returns[index2];
			}
		}
		else
		{
			for (int index2 = i; index2 < index; index2++)
				id3 += returns[index2];
		}
		int smallans = helper(n, k , d, m, returns, index + 1, curk - 1);
		curans = max(curans, smallans + id3);
	}

	return curans;
}
int id12(int n, int k, int d, int m, vector<int> returns) {
	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	return helper(n, k, d, m, returns, 0, k);
}
int helper(int c, int b, vector<vector<int>> &time, int bankerno, int col)
{
	if (col >= c)
		return 0;
	if (bankerno == b - 1)
	{
		int curans = 0;
		for (int index = col; index < c; index++)
			curans += time[bankerno][index];
		return curans;
	}

	int ans = INT_MAX;
	for (int times = 0; times <= c - col; times++)
	{
		int curans = 0;
		for (int index = col; index <= col + times - 1; index++)
			curans += time[bankerno][index];

		int smallans = helper(c, b, time, bankerno + 1, col + times);

		ans = min(ans, curans + smallans);
	}
	return ans;
}



















































ll helperrr(int c, int b, vector<vector<int>> &time, int id2, int col, vector<bool> &visited, int curtime, vector<vector<int>> &dp)
{
	

	

	cout << curtime << endl;
	if (col == c)
	{
		cout << "curtime = " << curtime << endl;
		

		

		return curtime;
	}
	ll k = 0, pow = 1;
	for (auto x : visited)
	{
		if (x == true)
		{
			k += pow;
		}
		pow *= 2;
	}
	if (dp[col][k] != -1 )
	{
		cout << "hlo " << col << " " << k << " " << dp[col][k] << endl;
		return dp[col][k];
	}
	ll smallans = INT_MAX;
	for (int i = 0; i < b; i++)
	{
		

		if (visited[i] == false)
		{
			if (i != id2)
				visited[id2] = true;
			

			

			

			

			

			

			

			

			

			

			

			

			

			

			


			smallans = min( helperrr(c, b, time, i, col + 1, visited, curtime + time[i][col], dp), smallans);
			visited[id2] = false;
		}
	}
	cout << "putting = " << col << " " << k << " " << dp[col][k] << endl;
	dp[col][k] = smallans;
	cout << "putting = " << col << " " << k << " " << dp[col][k] << endl;
	return dp[col][k];
}












































ll id20(int c, int b, vector<vector<int>> &time, int col, vector<bool> &visited, int id2, vector<vector<int>> &dp, int started)
{
	if (col == c)
		return 0;
	int k = 0, pow = 1;
	for (auto x : visited)
	{
		if (x == true)
			k += pow;
		pow *= 2;
	}
	if (dp[col][k] != -1)
	{
		

		return dp[col][k];
	}
	int ourans = INT_MAX;
	for (int i = 0; i < b; i++)
	{
		if (id2 != i)
			visited[id2] = true;
		if (visited[i] == false)
		{
			

			

			int id8 = id20(c, b, time, col + 1, visited, i, dp, started) + time[i][col];
			ourans = min(ourans, id8);
			

		}
		

		visited[id2] = false;
	}
	return dp[col][k] = ourans;
}
int id4(int c, int b, vector< vector<int> > &time) {


	vector<bool> visited(b, false);
	

	vector<vector<int>> dp(22, vector<int>(12, -1));
	

	

	

	

	

	

	

	

	

	

	ll lastans = INT_MAX;
	

	

	

	

	

	

	

	

	

	

	

	

	

	

	for (ll i = 0; i < b; i++)
	{
		

		lastans = min(id20(c, b, time, 1, visited, i, dp, i) + time[i][0], lastans);
		cout << lastans << endl;
		

	}
	return lastans;
}
const int MAX = 1e6 + 5;


int id[MAX], arr[MAX];
bool visited[MAX];

vector<int> graph[MAX];





























unsigned long long power(unsigned long long x, int y, int p)
{
	unsigned long long res = 1;
	x = x % p;
	while (y > 0)
	{
		if (y & 1)
			res = (res * x) % p;
		y = y >> 1; 

		x = (x * x) % p;
	}
	return res;
}

unsigned long long modInverse(unsigned long long n, int p)
{
	return power(n, p - 2, p);
}
unsigned long long id24(unsigned long long n, int r, int p)
{
	if (n < r)
		return 0;
	if (r == 0)
		return 1;
	unsigned long long fac[n + 1];
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = (fac[i - 1] * i) % p;

	return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}
void dfs(vector<vector<ll>> &g, ll vertex, ll par, vector<ll> &visited, vector<ll> &level)
{
	visited[vertex] = 1;
	level[vertex] = level[par] + 1;
	for (auto child : g[vertex])
	{
		if (visited[child] == true)
			continue;
		dfs(g, child, vertex, visited, level);
	}
}
bool isvalid(ll x, ll y, ll n, ll m)
{
	if (x >= 0 and y >= 0 and x < n and y < m)
		return true;
	return false;
}














































































int root(int x)
{
	while (id[x] != x)
	{
		id[x] = id[id[x]];
		x = id[x];
	}
	return x;
}
ll findparent(ll v, vector<ll> &par)
{
	

	

	

	while (par[v] != v)
	{
		par[v] = par[par[v]];
		v = par[v];
	}
	return par[v];
}
void id1(ll p1, ll p2, vector<ll> &par, vector<ll> &rank)
{
	if (rank[p1] < rank[p2])
	{
		rank[p1] += rank[p1];
		par[p1] = p2;
	}
	else
	{
		rank[p1] += rank[p2];
		par[p2] = p1;
	}
}
ll check(vector<ll> &a, ll k, ll mid)
{
	ll sum = mid;
	for (ll i = 1; i < a.size(); i++)
		sum += a[i];
	ll steps = a[0] - mid;
	for (ll i = a.size() - 1; i > 0; i--)
	{
		if (sum <= k)
			return steps;
		sum -= a[i];
		sum += mid;
		steps++;
	}
	if (sum <= k)
		return steps;
	return INT_MAX;
}
void solve(vector<ll> &a, ll n, ll i, ll &count)
{
	if (i == n)
	{
		ll curans = 0;
		for (ll index = 1; index < n - 1; index++)
			if ((a[index - 1]<a[index] and a[index]>a[index + 1]) or (a[index - 1] > a[index] and a[index] < a[index + 1]) )
				curans++;
		count += curans;
		return;
	}
	a[i] = 0;
	solve(a, n, i + 1, count);
	a[i] = 1;
	solve(a, n, i + 1, count);
	a[i] = 2;
	solve(a, n, i + 1, count);
}
int id15(int n)
{
	int cnt = 0;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			

			

			if (n / i == i)
				cnt++;

			else 

				cnt = cnt + 2;
		}
	}
	return cnt;
}
void primeFactors(int n, set<ll> &a)
{
	

	while (n % 2 == 0)
	{
		a.insert(2);
		n = n / 2;
	}

	

	

	for (int i = 3; i <= sqrt(n); i = i + 2)
	{
		

		while (n % i == 0)
		{
			a.insert(i);
			n = n / i;
		}
	}

	

	

	if (n > 2)
		a.insert(n);
}
ll solve(vector<ll> &a, ll i, ll n, vector<ll> &dp, ll k)
{
	if (i >= n - 1)
		return 0;
	if (dp[i] != -1)
		return dp[i];
	ll id8 = INT_MAX;
	for (ll index = 1; index <= k; index++)
	{
		if (i + index < n)
		{
			id8 = min(id8 , solve(a, i + index, n, dp, k) + abs(a[i] - a[i + index]));
		}
	}
	return dp[i] = id8;
	

	

	

	

	

	

	

}
ll solve2(vector<ll> &a, ll i, ll k, vector<ll> &dp)
{
	if (i <= 0)
		return 0;
	if (dp[i] != -1)
		return dp[i];
	ll cost = INT_MAX;
	for (ll index = 1; index <= k; index++)
	{
		if (i - index >= 0)
			cost = min( cost, solve2(a, i - index, k, dp) + abs(a[i] - a[i - index]));
	}
	

	

	

	return dp[i] = cost;
}
ll solve(vector<vector<ll>> &a, ll i, ll n, ll lastwork, vector<vector<ll>> &dp)
{
	if (i >= n)
		return 0;
	if (dp[i][lastwork] != -1)
		return dp[i][lastwork];
	ll smallans = INT_MIN;
	for (ll index = 0; index < 3; index++)
	{
		if (lastwork != index + 1)
			smallans = max(smallans , solve(a, i + 1, n, index + 1, dp) + a[i][index]);
	}
	return dp[i][lastwork] = smallans;
}
bool compare(pair<ll, ll> a, pair<ll, ll> b)
{
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}
ll  lis(ll  a[], ll n) {
	vector<ll > v;
	for (ll  i = 0; i < n; i++) {
		auto id22 = upper_bound(v.begin(), v.end(), a[i]);
		if (id22 != v.end()) {
			*id22 = min(*id22, a[i]);
		}
		else
			v.push_back(a[i]);
	}
	return v.size();
}
ll id14(vector<ll>& arr)
{
	vector<ll> ans;
	ll n = arr.size();
	for (ll i = 0; i < n; i++)
	{
		auto it = lower_bound(ans.begin(), ans.end(), arr[i]);
		if (it == ans.end()  )
		{
			ans.push_back(arr[i]);
		}
		else
		{
			*it = arr[i];
		}
	}
	return ans.size();
}
ll solve(vector<ll> &weight, vector<ll> &value, ll W, ll index, map<pair<ll, ll>, ll> &mp)
{
	if (W == 0)
		return 0;
	if (index < 0)
		return 0;
	

	

	if (mp.find({index, W}) != mp.end())
		return mp[ {index, W}];
	ll smallans = solve(weight, value, W, index - 1, mp);
	if (W - weight[index] >= 0)
		smallans = max( smallans, solve(weight, value, W - weight[index], index - 1, mp) + value[index] );
	return mp[ {index, W}] = smallans;
}
ll solve4(vector<ll> &weight, vector<ll> &value, ll W, ll index, vector<vector<ll>> &dp, ll curvalue)
{
	if (index < 0)
		return 0;
	if (dp[index][curvalue] != -1)
		return dp[index][curvalue];
	

	ll ans1 = solve4(weight, value, W, index - 1, dp, curvalue);
	

	ll ans2 = solve4(weight, value, W, index - 1, dp, curvalue + value[index]) + weight[index];
	

	dp[index][curvalue] = ans1;
	dp[index][curvalue + value[index]] = ans2;
	return dp[index][curvalue];
}
ll fun(vector<ll> &weight, vector<ll> &value, ll index, ll value_left, vector<vector<ll>> &dp)
{
	if (value_left == 0)
		return 0;
	if (index < 0)
		return INT_MAX;
	if (dp[index][value_left] != -1)
		return dp[index][value_left];
	ll o1 = fun(weight, value, index - 1, value_left, dp);
	if (value_left - value[index] >= 0)
		o1 = min(o1, fun(weight, value, index - 1, value_left - value[index], dp) + weight[index] );
	return dp[index][value_left] = o1;
}
long long solve(long long n) {
	int z = ceil(log2(n));
	long long k = pow(2, z);
	long long ans = 0;
	if (k == n) {
		k = pow(2, z + 1);
	}
	if (n == (k - 1)) {
		n--;
	}
	if (n <= 1) {
		return 0;
	} else {
		ans = solve(k - 2 - n);
	}

	long long pairs = (2 * n - (k - 2));
	return pairs * (k - 1) + ans;
}















ll findparent(vector<ll> &nge, ll index)
{
	

	if (nge[index] == -1)
		return index;
	int smallans = findparent(nge, nge[index]);
	return nge[index] = smallans;
}


int lcs( string X, string Y, int m, int n )
{
	int L[m + 1][n + 1];
	int i, j;

	
	for (i = 0; i <= m; i++)
	{
		for (j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				L[i][j] = 0;

			else if (X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;

			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}

	
	return L[m][n];
}
ll solve(string &s, int i, string cur, vector<ll> &dp)
{
	


	if (i >= s.length())
		return 0;
	if (i == s.length() - 1)
	{
		return 1;
	}
	if (i == s.length() - 2)
	{
		if (s[i + 1] == s[i])
			return 0;
		return 2;
	}
	if (dp[i] != -1)
		return dp[i];
	

	int id8 = INT_MAX, id6 = INT_MAX, id26 = INT_MAX;
	int n = s.length();

	if (s[i] == s[i + 1])
		return dp[i] = solve(s, i + 2, cur, dp);
	id8 = solve(s, i + 2, cur, dp) + 2;


	int j = i + 1;
	while (j < n and s[j] != s[i])
		j++;
	id6 = solve(s, j + 1, cur, dp) + j - i - 1;
	if (j == n)
		id6 = n - i;


	j = i + 2;
	while (j < n and s[j] != s[i + 1])
		j++;
	id26 = solve(s, j + 1, cur, dp) + j - (i + 1) - 1 + 1;
	if (j == n)
		id26 = n - i;


	

	return dp[i] = min({id8, id6, id26});
}
ll l, r, c2 = 0;
void solve(vector<ll> &a, ll i, ll j)
{
	

	ll cn = 0, fn = j, ln = i, tc2 = 0;
	for (ll index = i; index <= j; index++)
	{
		if (a[index] == 2 or a[index] == -2)
			tc2++;
		if (a[index] < 0)
		{
			cn++;
			fn = min(fn, index);
			ln = max(ln, index);
		}
	}
	if (tc2 == 0)
	{
		return;
	}
	if (cn % 2 == 0)
	{
		if (tc2 > c2)
		{
			l = i;
			r = j;
			return;
		}
	}
	ll id19 = 0;
	for (ll index = i; index <= fn; index++)
	{
		if (a[index] == 2 or a[index] == -2)
		{
			id19++;
		}
	}
	if (tc2 - id19 > c2)
	{
		c2 = tc2 - id19;
		l = fn + 1;
		r = j;
	}

	id19 = 0;
	for (ll index = j; index >= ln; index--)
	{
		if (a[index] == 2 or a[index] == -2)
		{
			id19++;
		}
	}
	if (tc2 - id19 > c2)
	{
		c2 = tc2 - id19;
		r = ln - 1;
		l = i;
	}
}
void dfs1(vector<vector<ll>> &g, ll s, vector<ll> &id10, ll id0, ll par, unordered_map<ll, ll> &initiators, ll &ans, vector<pair<ll, ll>> &a)
{
	id0 = max(id0, a[s].first);
	if (initiators.find(s) != initiators.end())
	{
		ans += id0;
		

		return ;
	}
	ll id18 = INT_MAX, id25;
	for (auto child : g[s])
	{
		if (child == par)
			continue;
		if (id18 > id10[child])
		{
			id18 = id10[child];
			id25 = child;
		}
	}
	for (auto child : g[s])
	{
		if (child == par)
			continue;
		if (child == id25)
			dfs1(g, child, id10, id0, s, initiators, ans, a);
		else
			dfs1(g, child, id10, INT_MIN, s, initiators, ans, a);
	}
}
ll dfs(vector<vector<ll>> &g, ll s, vector<ll> &id10, ll par, vector<pair<ll, ll>> &a)
{
	ll curans = a[s].first;
	if (id10[s] != -1)
		return id10[s];
	for (auto child : g[s])
	{
		if (child == par)
			continue;
		curans = max(curans, dfs(g, child, id10, s, a));
	}
	return id10[s] = curans;
}
void dfs(vector<vector<ll>> &g, ll & sum, ll s, ll par, vector<ll> &a, vector<ll> &visited, vector<ll> &curans)
{
	visited[s] = 1;
	curans.push_back(s);
	

	for (auto child : g[s])
	{
		if (child == par or visited[child] == 1)
			continue;
		if ( (a[s] & a[child]) == 0)
		{
			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			

			dfs(g, sum, child, s, a, visited, curans);
		}
	}
}
ll solve(vector<ll> &arr, ll index, ll curpos, ll a, ll b, vector<unordered_map<ll, ll>> &dp)
{
	if (index == arr.size() - 1)
		return b * (arr[index] - curpos);
	

	

	if (dp[index].find(curpos) != dp[index].end())
	{
		

		return dp[index][curpos];
	}
	ll k = (arr[index] - curpos) * b;
	

	ll id8 = solve(arr, index + 1, arr[index ], a, b, dp) + a * (arr[index ] - curpos);
	ll id6 = solve(arr, index + 1, curpos, a, b, dp);
	ll ans =  k + min(id8, id6);
	

	return dp[index][curpos] = ans;
}
pair<ll, ll> dfs(vector<vector<ll>> &g, ll &ans, string &s, ll v, ll par)
{
	ll white = 0, black = 0;
	pair<ll, ll> curans = {0, 0};
	for (auto child : g[v])
	{
		if (child == par)
			continue;
		pair<ll, ll> smallans = dfs(g, ans, s, child, v);
		curans.first += smallans.first;
		curans.second += smallans.second;
		if (smallans.first == smallans.second and smallans.first != 0)
			ans++;
	}
	

	if (s[v - 1] == 'B')
		curans.second = curans.second + 1;
	else
		curans.first = curans.first + 1;
	return curans;
}
void update1(ll index, ll value, vector<ll> &BIT, ll n)
{

	for (; index <= n; index += index & (-index)) {
		BIT[index] += value;
	}
}
void update2(ll index, ll value, vector<ll> &BIT)
{
	int sum = 0;
	

	for (; index > 0; index -= index & (-index))
	{
		ll i = index;
		ll newindex = i - (i & (-i));
		cout << index << " " << newindex << "  ";
		

		

		ll times = index - newindex;
		

		BIT[index] = value * times;
	}
	

}
ll query(ll index, vector<ll> &BIT)
{
	ll sum = 0;
	for (; index > 0; index -= index & (-index)) {
		sum += BIT[index];
	}
	return sum;
}
void solve(string s, ll index, ll & ans, vector<ll> &factorial)
{
	

	if (s.length() == 1)
	{
		

		ans += 1;
		return ;
	}
	string newstr = "";
	for (ll i = 0; i < s.length(); i++)
	{
		if (i != index)
			newstr += s[i];
	}
	

	

	string revstr = newstr;
	reverse(revstr.begin(), revstr.end());
	if (revstr == newstr)
		ans += factorial[newstr.length()];
	

	for (ll i = 0; i < newstr.length(); i++)
		solve(newstr, i, ans, factorial);
}
ll calculate(ll p, ll q)
{
	ll mod = 1e9 + 7, expo;
	expo = mod - 2;

	

	

	while (expo) {

		

		

		if (expo & 1) {
			p = (p * q) % mod;
		}
		q = (q * q) % mod;

		

		

		expo >>= 1;
	}
	return p;
}
ll ans;
ll solve(ll n, ll x, ll steps)
{
	if (steps >= ans)
		return INT_MAX;
	cout << x << endl;
	string s = to_string(x);
	if (s.length() >= n)
	{
		cout << "hlo" << x << " ";
		return 0;
	}
	ll smallans = INT_MAX;
	ll maxx = -1;
	vector<ll> freq(10, 0);
	for (auto c : s)
	{
		if (c != '0' and c != '1')
			freq[c - '0']++;
		

	}
	for (ll i = 9; i > 1; i--)
	{
		if (freq[i] > 0)
			smallans = min(smallans, solve(n, x * i, steps + 1));
	}
	ans = min(ans, smallans + 1);
	

	return smallans + 1;
}
int find(vector<pair<int, int> > V, pair<int, int> P, int ind) {
	for (int i = ind; i < V.size(); i++) {
		if (V[i].first == P.first && V[i].second == P.second) {
			return i;
		}
	}
	return -1;
}
int main()
{

	

	freopen("input.txt", "r", stdin);

	

	freopen("output.txt", "w", stdout);

	IOS;
	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	int testcase;
	cin >> testcase;
	while (testcase--) {
		int n, x;
		cin >> n;
		vector<int> A;
		vector<int> B;
		for (int i = 0; i < n; i++) {
			cin >> x;
			A.push_back(x);
		}
		for (int i = 0; i < n; i++) {
			cin >> x;
			B.push_back(x);
		}
		vector<pair<int , int> > V;
		vector<pair<int , int> > sorted_V;
		for (int i = 0; i < n; i++) {
			V.push_back(make_pair(A[i], B[i]));
			sorted_V.push_back(make_pair(A[i], B[i]));
		}
		sort(sorted_V.begin(), sorted_V.end());
		int id7 = 1;
		for (int i = 1; i < n; i++) {
			if (sorted_V[i].second < sorted_V[i - 1].second) {
				id7 = 0;
			}
		}
		if (id7 == 0) {
			cout << -1 << endl;
		} else {
			vector<pair<int , int> > ans;
			for (int i = 0; i < n - 1; i++) {
				int k  = find(V, sorted_V[i], i);
				if (k == i) {
					continue;
				} else {
					swap(V[i].first, V[k].first);
					swap(V[i].second, V[k].second);
					ans.push_back(make_pair(k + 1, i + 1));
				}
			}
			cout << ans.size() << endl;
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i].first << " " << ans[i].second << endl;
			}
		}

	}
}






