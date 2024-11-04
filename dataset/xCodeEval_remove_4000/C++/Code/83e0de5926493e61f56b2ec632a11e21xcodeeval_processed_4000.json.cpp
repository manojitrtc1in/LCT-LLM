





























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
	int n = s.size();
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

ll gcd(int a, int b)
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
		vector<pair<ll, char>>buf;
	};
	int ns;
	vector<node>d;
	result res;
	void addBuffer(pair<ll, char>bf, int i)
	{
		if (i >= d.size() || i < 1)
			return;
		if (d[i].buf.empty())
		{
			d[i].buf.push_back(bf);
			return;
		}
		if (bf.second == 'p')
		{
			d[i].buf.clear();
			d[i].buf.push_back(bf);
			return;
		}
		ll val = bf.first;
		while (!d[i].buf.empty() && d[i].buf.back().second == 's')
		{
			val += d[i].buf.back().first;
			d[i].buf.pop_back();
		}
		d[i].buf.push_back({ val, 's' });
	}
	void push(int i)
	{
		if (d[i].buf.empty())
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
			d[i].buf.clear();
			return;
		}
		if (d[i].buf[0].second != 'p')
			exit(-1);
		ll el = d[i].buf[0].first;
		addBuffer({ el, 'p' }, 2 * i);
		addBuffer({ el, 'p' }, 2 * i + 1);
		d[i].sum = el * (d[i].right - d[i].left + 1);
		d[i].mn = d[i].mx = el;
		d[i].buf.erase(d[i].buf.begin());
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
		if (d[2 * i].mn < d[2 * i + 1].mn)
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
			} if (res.val == d[i].mn && res.id < d[i].id_mn)
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
bool id0(point a, point b, point c)
{
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y) > 0;
}

int MAX_BITS = 18;

int getBit(int a, int i)
{
	int k = ((1 << (MAX_BITS)) >> i);
	return ((a & k) > 0);
}

struct segTree
{
	struct segment
	{
		ll sum = 0;
		ll ans = 0;
		ll suff = 0;
		ll pref = 0;
	};
	struct node
	{
		node* child[2]{ NULL };
		segment* segmentSum;
		ll sum = 0;
	};
	void updateNode(node* v, int i, int level)
	{
		node* left = v->child[0];
		node* right = v->child[1];
		int k = ((1 << (MAX_BITS)) >> level);
		v->segmentSum[i].sum = left->sum + right->sum;
		v->segmentSum[i].ans = max(left->segmentSum[i].ans, right->segmentSum[i].ans);
		v->segmentSum[i].ans = max(v->segmentSum[i].ans, left->segmentSum[i].suff + right->segmentSum[i].pref);
		v->segmentSum[i].suff = max(right->segmentSum[i].suff, left->segmentSum[i].suff + right->segmentSum[i].sum);
		v->segmentSum[i].pref = max(left->segmentSum[i].pref, left->segmentSum[i].sum + right->segmentSum[i].pref);
		swap(left, right);
		v->segmentSum[i ^ k].sum = left->sum + right->sum;
		v->segmentSum[i ^ k].ans = max(left->segmentSum[i].ans, right->segmentSum[i].ans);
		v->segmentSum[i ^ k].ans = max(v->segmentSum[i ^ k].ans, left->segmentSum[i].suff + right->segmentSum[i].pref);
		v->segmentSum[i ^ k].suff = max(right->segmentSum[i].suff, left->segmentSum[i].suff + right->segmentSum[i].sum);
		v->segmentSum[i ^ k].pref = max(left->segmentSum[i].pref, left->segmentSum[i].sum + right->segmentSum[i].pref);
	}
	node* root;
	void recInit(node* v, vector<ll>& a, int id = 1, int sz = (1 << MAX_BITS), int i = 1)
	{
		if (i == MAX_BITS + 1)
		{
			v->segmentSum = new segment[1];
			v->segmentSum[0].ans = v->segmentSum[0].pref =
				v->segmentSum[0].suff = v->segmentSum[0].sum = a[id - (1 << MAX_BITS)];
			v->sum = a[id - (1 << MAX_BITS)];
			return;
		}
		v->segmentSum = new segment[sz];
		v->child[0] = new node;
		v->child[1] = new node;
		recInit(v->child[0], a, 2 * id, sz / 2, i + 1);
		recInit(v->child[1], a, 2 * id + 1, sz / 2, i + 1);
		v->sum = v->child[0]->sum + v->child[1]->sum;
		for (int j = 0; j < sz / 2; j++)
			updateNode(v, j, i);
	}
	void init(vector<ll>&a)
	{
		root = new node;
		recInit(root, a);
	}
	ll getAns(int i)
	{
		return root->segmentSum[i].ans;
	}
};

void solve()
{
	segTree sg;
	ll n;
	cin >> n;
	MAX_BITS = n;
	vector<ll>a((1 << n));
	for (int i = 0; i < (1 << n); i++)
		cin >> a[i];
	int q;
	cin >> q;
	sg.init(a);
	int _xor = 0;
	while (q--)
	{
		int k;
		cin >> k;
		_xor ^= (1 << k);
		cout << max(sg.getAns(_xor), 0ll) << ln;
	}
	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
