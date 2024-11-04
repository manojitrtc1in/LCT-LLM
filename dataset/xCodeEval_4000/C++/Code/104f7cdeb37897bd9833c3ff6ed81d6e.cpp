
#define All(x) x.begin(), x.end()
#define Len(x) (int)x.size()
#define fi(a,b) for(int i = a; i <= b; i++)
#define fj(a,b) for(int j = a; j <= b; j++)
#define fo(a,b) for(int o = a; o <= b; o++)
#define fw(a,b) for(int w = a; w <= b; w++)
#define get1(x) get<0>(x)
#define get2(x) get<1>(x)
#define get3(x) get<2>(x)
#define get4(x) get<3>(x)

#define fai(arr) for(auto& i : arr)
#define faj(arr) for(auto& j : arr)

#define rfi(a,b) for(int i = a; i >= b; i--)
#define rfj(a,b) for(int j = a; j >= b; j--)
#define rfo(a,b) for(int o = a; o >= b; o--)
#define rfw(a,b) for(int w = a; w >= b; w--)
#define pb push_back
#define ins insert
#define ln '\n'
#define _CRT_SECURE_NO_WARNINGS
#define CF int t_; cin >> t_; while(t_--) solve();
#define Files freopen("landscape.in", "r", stdin); freopen("landscape.out", "w", stdout);






#include <bits/stdc++.h>




















using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<vector<ll>> vvll;
const ll INF = 1e18;
ll pow_m(ll a, ll n, ll m)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return a % m;
	ll r = pow_m(a, n / 2, m);
	if (n % 2 == 0)
	{
		return (r * r) % m;
	}
	return ((r * r) % m * (a % m)) % m;
}
ll fast_pow(ll a, ll n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return a;
	ll r = fast_pow(a, n / 2);
	if (n % 2 == 0)
	{
		return (r * r);
	}
	return r * r * a;
}
vector<int> ZF(string s)
{
	int n = Len(s);
	vector<int> z(n);
	int L = 0, R = 0;
	for (int i = 1; i < n; i++)
	{
		if (i <= R)
			z[i] = min(R - i + 1, z[i - L]);
		while (i + z[i] < n && (s[z[i]] == s[i + z[i]] || s[i + z[i]] == '?'))
			z[i]++;
		if (i + z[i] - 1 > R)
		{
			L = i; R = i + z[i] - 1;
		}
	}
	return z;
}

ll gcd(ll a, ll b)
{
	return b ? gcd(b, a % b) : a;
}
ll rnd(ll A, ll B)
{
	return rand() % (B - A + 1) + A;
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
		pair<ll, char>buf[2];
	};
	int ns;
	vector<node>d;
	result res;
	void addBuffer(pair<ll, char>bf, int i)
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
				addBuffer({ val, 's' }, 2 * i);
				addBuffer({ val, 's' }, 2 * i + 1);
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
		addBuffer({ el, 'p' }, 2 * i);
		addBuffer({ el, 'p' }, 2 * i + 1);
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
			addBuffer({ x, 's' }, i);
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
			} if (res.val == d[i].mn && res.id > d[i].id_mn)
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
			addBuffer({ x, 'p' }, i);
			push(i);
			return;
		}
		recSetNumber(L, R, x, 2 * i);
		recSetNumber(L, R, x, 2 * i + 1);
		updateNode(i);
	}
public:
	RMQ() {}
	RMQ(vector<ll>& a)
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
			return { (ll)1e18, -1 };
		res.val = 1e18;
		res.id = -1;
		recCountMin(L + ns, R + ns);
		return res;
	}
	result findMaximum(int L, int R)
	{
		if (L > R)
			return { (ll)-1e18, -1 };
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
class QRM
{
private:
	deque<ll>dq;
	queue<ll>q;
public:
	void push_back(ll x)
	{
		while (!dq.empty() && dq.back() < x)
			dq.pop_back();
		dq.push_back(x);
		q.push(x);
		return;
	}
	ll get()
	{
		return dq.front();
	}
	ll pop()
	{
		ll r = dq.front();
		if (q.front() == r)
			dq.pop_front();
		q.pop();
		return r;
	}
};
struct point
{
	ll x, y;
	void input()
	{
		cin >> x >> y;
	}
	bool operator<(point b)
	{
		return (x < b.x || (x == b.x && y < b.y));
	}
};
bool cw(point a, point b, point c)
{
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y) < 0;
}
bool against_cw(point a, point b, point c)
{
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y) > 0;
}
int MAX_BITS = 20;
int getBit(int a, int i)
{
	int k = ((1 << (MAX_BITS)) >> i);
	return ((a & k) > 0);
}

vector<vector<int>>g;

void buildD(ll start, vector<ll>&minDist)
{
	set<pair<ll, int>>q;
	minDist[start] = 0;
	q.insert({ minDist[start], start });
	while (!q.empty())
	{
		int v = q.begin()->second;
		q.erase({ minDist[v], v });
		for (auto to : g[v])
		{
			if (minDist[to] > minDist[v] + 1)
			{
				q.erase({ minDist[to], to });
				minDist[to] = minDist[v] + 1;
				q.insert({ minDist[to], to });
			}
		}
	}
	return;
}

void solve()
{
	int n;
	cin >> n;
	vector<ll>a(n + 1);
	vector<bool>used(n + 1);
	fi(1, n)
	{
		cin >> a[i];
	}
	ll x = 0;
	int id = -1;
	ll mx = -1;
	vector<ll>ans;
	fi(1, 32)
	{
		fj(1, n)
		{
			if (used[j]) continue;
			if (mx < (x | a[j]))
			{
				mx = (x | a[j]);
				id = j;
			}
		}
		if (id > 0)
		{
			ans.push_back(a[id]);
			used[id] = 1;
			x = (x | a[id]);
			mx = -1;
			id = -1;
		}
	}
	fi(1, n)
	{
		if (!used[i])
			ans.push_back(a[i]);
	}
	cerr << "ANSWER IS ";
	fai(ans)
		cout << i << ' ';
	cout << ln;
	
	

}

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	CF;
	
}

