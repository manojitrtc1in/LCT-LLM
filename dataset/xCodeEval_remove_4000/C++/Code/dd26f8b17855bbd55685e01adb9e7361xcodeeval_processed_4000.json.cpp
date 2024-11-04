



















using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<char> vc;
typedef vector<string> vs;

typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vc> vvc;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

class String
{
public:
	static vector<ll> id2(string &s)
	{
		ll n = s.size();
		vll res(n);
		res[0] = n;
		for (ll i = 1, l = 0, r = 0; i < n; i++)
		{
			if (i <= r)
				res[i] = min(r - i + 1, res[i - l]);
			while (i + res[i] < n && s[res[i]] == s[i + res[i]])
				res[i]++;
			if (i + res[i] - 1 > r)
			{
				l = i;
				r = i + res[i] - 1;
			}
		}
		return res;
	}
	template <typename T>
	static vector<ll> id2(vector<T> &s)
	{
		ll n = s.size();
		vll res(n);
		res[0] = n;
		for (ll i = 1, l = 0, r = 0; i < n; i++)
		{
			if (i <= r)
				res[i] = min(r - i + 1, res[i - l]);
			while (i + res[i] < n && s[res[i]] == s[i + res[i]])
				res[i]++;
			if (i + res[i] - 1 > r)
			{
				l = i;
				r = i + res[i] - 1;
			}
		}
		return res;
	}

	static vector<ll> id0(string &s)
	{
		ll n = s.size();
		vll res(n);
		res[0] = 0;
		for (ll i = 1; i < n; i++)
		{
			ll j = res[i - 1];
			while (j > 0 && s[i] != s[j])
				j = res[j - 1];
			if (s[i] == s[j])
				j++;
			res[i] = j;
		}
		return res;
	}
	template <typename T>
	static vector<ll> id0(vector<T> &s)
	{
		ll n = s.size();
		vll res(n);
		res[0] = 0;
		for (ll i = 1; i < n; i++)
		{
			ll j = res[i - 1];
			while (j > 0 && s[i] != s[j])
				j = res[j - 1];
			if (s[i] == s[j])
				j++;
			res[i] = j;
		}
		return res;
	}
};
class Math
{
public:
	template <typename T>
	static T gcd(T a, T b)
	{
		return (a == 0) ? b : gcd(b % a, a);
	}

	template <typename T>
	static T lcm(T a, T b)
	{
		return a / Math::gcd(a, b) * b;
	}
};
class V
{
public:
	template <typename T>
	static void Print(vector<T> &v)
	{
		copy(All(v), ostream_iterator<T>(cout, " "));
	}
	template <typename T>
	static void Read(vector<T> &v)
	{
		for (int i = 0; i < v.size(); i++)
			cin >> v[i];
	}
};

void id1(ll first, vector<vector<pair<ll, ll>>> &gr, vector<ll> &d, vector<ll> &p)
{
	ll start = first;
	d[start] = 0;
	set<pair<ll, ll>> q;
	q.insert({d[start], start});
	while (!q.empty())
	{
		ll v = q.begin()->second;
		q.erase(q.begin());

		for (int j = 0; j < gr[v].size(); j++)
		{
			ll to = gr[v][j].second,
			   w = gr[v][j].first;
			if (d[v] + w < d[to])
			{
				q.erase({d[to], to});
				d[to] = d[v] + w;
				p[to] = v;
				q.insert({d[to], to});
			}
		}
	}
}

void Floid(vvll &gr)
{
	int sz = gr.size();
	for (int k = 0; k < sz; k++)
	{
		for (int i = 0; i < sz; i++)
		{
			for (int j = 0; j < sz; j++)
			{
				gr[i][j] = min(gr[i][j], gr[i][k] + gr[k][j]);
			}
		}
	}
}

class RMQ 

{
private:
	struct result
	{
		ll val; 

		int id; 

	};
	struct node
	{
		ll sum;
		ll mx;
		ll mn = 1e9;
		int id_mx;
		int id_mn;
		int left;
		int right;
		int bufN = 0;
		pair<ll, char> buf[2];
	};
	int ns;
	vector<node> d;
	result res;
	void addBuffer(pair<ll, char> bf, int i)
	{
		if (i >= d.size() || i < 1)
			return;
		if (d[i].bufN == 0)
		{
			d[i].buf[0] = bf;
			d[i].bufN++;
			return;
		}
		if (bf.second == 'p')
		{
			d[i].buf[0] = bf;
			d[i].bufN = 1;
			return;
		}
		if (d[i].buf[d[i].bufN - 1].second == 'p')
		{
			d[i].buf[1] = bf;
			d[i].bufN = 2;
			return;
		}
		d[i].buf[d[i].bufN - 1].first += bf.first;
		return;
	}
	void push(int i)
	{
		if (d[i].bufN == 0)
			return;
		if (d[i].buf[0].second == 's')
		{
			ll val = d[i].buf[0].first;
			if (d[i].left == d[i].right)
			{
				d[i].sum += val;
				d[i].mn += val;
				d[i].mx += val;
			}
			else
			{
				addBuffer({val, 's'}, 2 * i);
				addBuffer({val, 's'}, 2 * i + 1);
				d[i].sum += (d[i].right - d[i].left + 1) * val;
				d[i].mn += val;
				d[i].mx += val;
			}
			d[i].bufN = 0;
			return;
		}
		if (d[i].buf[0].second != 'p')
			exit(-1);
		ll el = d[i].buf[0].first;
		addBuffer({el, 'p'}, 2 * i);
		addBuffer({el, 'p'}, 2 * i + 1);
		d[i].sum = el * (d[i].right - d[i].left + 1);
		d[i].mn = d[i].mx = el;
		d[i].buf[0] = d[i].buf[1];
		d[i].bufN--;
		push(i); 

	}
	void updateNode(int i) 

	{
		push(i);
		push(2 * i);
		push(2 * i + 1);
		d[i].sum = d[2 * i].sum + d[2 * i + 1].sum;
		if (d[2 * i].mx >= d[2 * i + 1].mx)
		{
			d[i].mx = d[2 * i].mx;
			d[i].id_mx = d[2 * i].id_mx;
		}
		else
		{
			d[i].mx = d[2 * i + 1].mx;
			d[i].id_mx = d[2 * i + 1].id_mx;
		}
		if (d[2 * i].mn <= d[2 * i + 1].mn)
		{
			d[i].mn = d[2 * i].mn;
			d[i].id_mn = d[2 * i].id_mn;
		}
		else
		{
			d[i].mn = d[2 * i + 1].mn;
			d[i].id_mn = d[2 * i + 1].id_mn;
		}
	}
	void recAddNumber(int L, int R, ll x, int i = 1)
	{
		push(i);
		if (d[i].left > R || d[i].right < L)
			return;
		if (d[i].left >= L && d[i].right <= R)
		{
			addBuffer({x, 's'}, i);
			push(i);
			return;
		}
		recAddNumber(L, R, x, 2 * i);
		recAddNumber(L, R, x, 2 * i + 1);
		updateNode(i);
	}
	void recCountSum(int L, int R, int i = 1)
	{
		push(i);
		if (d[i].right < L || d[i].left > R)
			return;
		if (d[i].left >= L && d[i].right <= R)
		{
			res.val += d[i].sum;
			return;
		}
		recCountSum(L, R, 2 * i);
		recCountSum(L, R, 2 * i + 1);
	}
	void recCountMin(int L, int R, int i = 1)
	{
		push(i);
		if (d[i].left > R || d[i].right < L)
			return;
		if (d[i].left >= L && d[i].right <= R)
		{
			if (res.val > d[i].mn)
			{
				res.val = d[i].mn;
				res.id = d[i].id_mn;
			}
			if (res.val == d[i].mn && res.id > d[i].id_mn)
			{
				res.val = d[i].mn;
				res.id = d[i].id_mn;
			}
			return;
		}
		recCountMin(L, R, 2 * i);
		recCountMin(L, R, 2 * i + 1);
	}
	void recCountMax(int L, int R, int i = 1)
	{
		push(i);
		if (d[i].left > R || d[i].right < L)
			return;
		if (d[i].left >= L && d[i].right <= R)
		{
			if (res.val < d[i].mx)
			{
				res.val = d[i].mx;
				res.id = d[i].id_mx;
			}
			else if (res.val == d[i].mx && res.id > d[i].id_mx)
			{
				res.val = d[i].mx;
				res.id = d[i].id_mx;
			}
			return;
		}
		recCountMax(L, R, 2 * i);
		recCountMax(L, R, 2 * i + 1);
	}
	void recSetNumber(int L, int R, ll x, int i = 1)
	{
		push(i);
		if (d[i].left > R || d[i].right < L)
			return;
		if (d[i].left >= L && d[i].right <= R)
		{
			addBuffer({x, 'p'}, i);
			push(i);
			return;
		}
		recSetNumber(L, R, x, 2 * i);
		recSetNumber(L, R, x, 2 * i + 1);
		updateNode(i);
	}

public:
	RMQ(vector<ll> &a)
	{
		int n = (int)a.size();
		ns = 1;
		while (ns < n)
			ns *= 2;
		d.resize(2 * ns);
		for (int i = ns; i < d.size(); i++)
		{
			d[i].left = d[i].right = i;
		}
		for (int i = 0; i < n; i++)
		{
			d[i + ns].sum = d[i + ns].mn = d[i + ns].mx = a[i];
			d[i + ns].id_mn = d[i + ns].id_mx = i;
		}
		for (int i = ns - 1; i >= 1; i--)
		{
			d[i].left = d[2 * i].left;
			d[i].right = d[2 * i + 1].right;
			d[i].sum = d[2 * i].sum + d[2 * i + 1].sum;
			if (d[2 * i].mx >= d[2 * i + 1].mx)
			{
				d[i].mx = d[2 * i].mx;
				d[i].id_mx = d[2 * i].id_mx;
			}
			else
			{
				d[i].mx = d[2 * i + 1].mx;
				d[i].id_mx = d[2 * i + 1].id_mx;
			}
			if (d[2 * i].mn <= d[2 * i + 1].mn)
			{
				d[i].mn = d[2 * i].mn;
				d[i].id_mn = d[2 * i].id_mn;
			}
			else
			{
				d[i].mn = d[2 * i + 1].mn;
				d[i].id_mn = d[2 * i + 1].id_mn;
			}
		}
	}
	result findMinimum(int L, int R)
	{
		if (L > R)
			return {(ll)1e18, -1};
		res.val = 1e18;
		res.id = -1;
		recCountMin(L + ns, R + ns);
		return res;
	}
	result findMaximum(int L, int R)
	{
		if (L > R)
			return {(ll)-1e18, -1};
		res.val = -1e18;
		res.id = -1;
		recCountMax(L + ns, R + ns);
		return res;
	}
	void addNumber(int L, int R, ll x) 

	{
		if (L > R)
			return;
		recAddNumber(L + ns, R + ns, x);
	}
	void setNumber(int L, int R, ll x)
	{
		if (L > R)
			return;
		recSetNumber(L + ns, R + ns, x);
	}
	result findSum(int L, int R)
	{
		res.val = 0;
		res.id = -1;
		recCountSum(L + ns, R + ns);
		return res;
	}
	result findElement(int i)
	{
		res.val = 0;
		res.id = -1;
		recCountSum(i + ns, i + ns);
		return res;
	}
};

ll rnd(ll a, ll b)
{
	return rand() % (b - a + 1) + a;
}

void solve()
{
	string s;
	cin >> s;
	int n = s.size();

	

	vector<pair<char, int>> v;
	for (int i = 0; i < n; i++)
	{
		v.push_back({s[i], i});
	}

	sort(All(v));
	int a, b;
	for (int i = 0; i < n; i++)
	{
		if (v[i].second == 0)
			a = i;
		if (v[i].second == n - 1)
			b = i;
	}
	if (a > b)
		swap(a, b);
	while (a > 0 && v[a - 1].first == v[a].first)
	{
		a--;
	}
	while(b < n - 1 && v[b + 1].first == v[b].first)
	{
		b++;
	}

	

	

	

	

	

	


	


	ll cnt = 1, sum = 0;
	vector<int> res;
	res.push_back(v[a].second + 1);
	for (auto i = a + 1; i <= b; i++)
	{
		cnt++;
		sum += abs(v[i - 1].first - v[i].first);
		res.push_back(v[i].second + 1);
	}
	cout << sum << ' ' << cnt << ln;
	if(res[0] != 1)
		reverse(All(res));
	cout << 1;
	for(int i = 0; i < res.size(); i++)
		if(res[i] != 1 && res[i] != n)
			cout << ' ' << res[i];
	cout << ' ' << n << ln;
	cout << ln;
}

int main()
{
	

	

	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		

		solve();
	}
}