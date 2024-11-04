#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<ll, ll>> vpll;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define mp make_pair
#define rsz resize
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
#define f first
#define s second
#define cont continue
#define endl '\n'
#define ednl '\n'
#define test int t;cin>>t;while(t--)
#define vin(v,n) vi (v);(v).rsz((n));F0R(i,(n))cin>>(v)[i];
#define vlln(v,n) vector<ll> (v);(v).rsz((n));F0R(i,(n))cin>>(v)[i];
#define vvin(v,n,m) vector<vi>(v);(v).rsz((n));F0R(i,(n))(v)[i].rsz((m));F0R(i,(n))F0R(j,(m))cin>>(v)[i][j];
#define vvlln(v,n,m) vector<vector<ll>>(v);(v).rsz((n));F0R(i,(n))(v)[i].rsz((m));F0R(i,(n))F0R(j,(m))cin>>(v)[i][j];
#define pq priority_queue
const ll linf = 4000000000000000000LL;
const int inf = 1000000007;
const double pi = 3.1415926535;


ll maximum(ll x, ll y)
{
	if (x > y)
		return x;
	return y;
}
ll minimum(ll x, ll y)
{
	if (x < y)
		return x;
	return y;
}
void print_vector(vector<int>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void print_vector(vector<ll>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void print_vector(vector<double>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void print_vector(vector<string>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void print_vector(vector<bool>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void print_vector(vector<pii>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).f << " ";
	cout << endl;
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).s << " ";
	cout << endl;
}
void print_vector(vector<pair<ll, ll>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).f << " ";
	cout << endl;
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).s << " ";
	cout << endl;
}
void print_vector(vector<pair<pii, int>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).f.f << " " << (*i).f.s << " " << (*i).s << endl;
	cout << endl;
}
void print_vector(vector<pair<int, pii>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << (*i).f << " " << (*i).s.f << " " << (*i).s.s << endl;
	cout << endl;
}
void print_vector(vector<vector<string>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		print_vector(*i);
		cout << endl;
	}
	cout << endl;
}
void print_vector(vector<vector<int>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		print_vector(*i);
		cout << endl;
	}
	cout << endl;
}
void print_vector(vector<vector<ll>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		print_vector(*i);
		cout << endl;
	}
	cout << endl;
}
void print_vector(vector<vector<pair<ll, ll>>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		print_vector(*i);
	}
	cout << endl;
}
void print_vector(vector<vector<vi>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		print_vector(*i);
		cout << endl;
	}
	cout << endl;
}
void print_vector(vector<vector<vector<ll>>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		print_vector(*i);
		cout << endl;
	}
	cout << endl;
}
void print_vector(vector<vector<bool>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		print_vector(*i);
		cout << endl;
	}
	cout << endl;
}
void print_set(set<int>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void print_set(set<pii>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << i->f << " " << i->s << endl;
	cout << endl;
}
void print_vector(vector<set<int>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		print_set(*i);
		cout << endl;
	}
	cout << endl;
}
void print_vector(vector<vector<pii>>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
	{
		cout << i - amount.begin() << endl;
		print_vector(*i);
	}
}
void print_set(set<string>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void print_map(map<int, vector<int>> m)
{
	for (map<int, vector<int>>::iterator i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " ";
		print_vector(i->second);
	}
}
void print_map(map<string, vector<string>> m)
{
	for (map<string, vector<string>>::iterator i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " ";
		print_vector(i->second);
	}
}
void print_map(map<string, int> m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " " << i->s << endl;
	}
}
void print_map(map<string, vector<bool>> m)
{
	for (map<string, vector<bool>>::iterator i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " ";
		print_vector(i->second);
	}
}
void print_map(map<string, set<string>> m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " ";
		print_set(i->second);
	}
}
void print_map(map<int, int> m)
{
	for (map<int, int>::iterator i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << " " << i->second << endl;
	}
}
void print_map(map<char, vector<string>> m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << endl;
		cout << '\t';
		print_vector(i->second);
	}
}
void print_map(map<char, int> m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first << endl;
		cout << '\t' << i->second << endl;
	}
}
void print_map(map<pii, int> m)
{
	for (auto i = m.begin(); i != m.end(); i++)
	{
		cout << i->first.f << " " << i->first.s << " " << i->second << endl;
	}
}
bool comp(pii x, pii y)
{
	if (x.s == y.s)return x.f < y.f;
	return x.s < y.s;
}
struct Graph
{
	int V, E;
	vector<pair<int, pii>> edges; 


	

	Graph(int a, int b)
	{
		V = a;
		E = b;
	}

	void addEdge(int a, int b, int w)
	{
		edges.push_back({ w,{a,b} });
	}

	


	vector<int> links, sizes;

	int find(int a) 

	{
		if (a == links[a])
			return a;
		return links[a] = find(links[a]);
	}

	bool same(int a, int b) 

	{
		return find(a) == find(b);
	}

	void unite(int a, int b)
	{
		a = find(a);
		b = find(b);
		if (sizes[a] < sizes[b]) swap(a, b);
		sizes[a] += sizes[b]; 

		links[b] = a;
	}

	void sort_edges()
	{
		sort(edges.begin(), edges.end());
	}

	ll kruskalMST()
	{
		sort_edges();
		

		links.resize(V);
		sizes.resize(V);

		for (int i = 0; i < V; i++)
		{
			links[i] = i;
			sizes[i] = 1;
		}
		ll sum = 0;
		int count = 0;
		F0R(i, E)
		{
			int start = edges[i].s.f;
			int end = edges[i].s.s;
			if (!same(start, end))
			{
				unite(start, end);
				sum += edges[i].f;
				count++;
			}
		}
		if (count != V - 1)return -inf;
		return sum;
	}
};


int modInverse(int a, int m)
{
	int m0 = m;
	int y = 0, x = 1;

	if (m == 1)
		return 0;

	while (a > 1)
	{
		

		int q = a / m;
		int t = m;

		

		

		m = a % m, a = t;
		t = y;

		

		y = x - q * y;
		x = t;
	}

	

	if (x < 0)
		x += m0;

	return x;
}
ll power(ll x, ll y)
{
	ll k = 1 << 30;
	ll z = 1;
	while (k != 0)
	{
		z *= z;
		z %= inf;
		if (y >= k)
		{
			z *= x;
			z %= inf;
			y -= k;
		}
		k >>= 1;
	}
	return z;
}


long double area(pii x, pii y, pii z)
{
	return ((ll)x.s * y.f + (ll)y.s * z.f + (ll)z.s * x.f - (ll)x.f * y.s - (ll)y.f * z.s - (ll)z.f * x.s) / 2.0;
}
bool clockwise(pii x, pii y, pii z)
{
	return area(x, y, z) > 0;
}
int gcd(int a, int b)
{
	if (a > b)swap(a, b);
	if (a == 0)return b;
	return gcd(a, b % a);
}
int popcount(int a)
{
	int count = 0;
	while (a != 0)
	{
		count += (a % 2);
		a >>= 1;
	}
	return count;
}


class segment_tree {

	vi tree;   


	int height;   

	int maxSize;  

				  


	int STARTINDEX = 0;   

	int ENDINDEX;         


public:segment_tree() {
}

public:int leftChild(int k) { return 2 * k + 1; }

public:int rightChild(int k) { return 2 * k + 2; }

	   

public:void buildSegTree(vi& A, int n) {

	height = (int)ceil(log2(n));
	maxSize = (1 << (height + 1)) - 1;   

	tree.rsz(maxSize);
	ENDINDEX = (1 << height) - 1;
	A.rsz(1 << height, 0);
	

	buildSegTreeRec(STARTINDEX, ENDINDEX, 0, A);
}

	   

	   

	   

	   

public:int buildSegTreeRec(int low, int high, int p, vi& A) {
	if (low == high) {
		tree[p] = A[low];
		return tree[p];
	}

	int mid = (low + high) / 2;

	tree[p] = buildSegTreeRec(low, mid, leftChild(p), A)
		+ buildSegTreeRec(mid + 1, high, rightChild(p), A);

	return tree[p];
}
	   









	   

public:int getSum(int x, int y) {

	if (x < 0 || ENDINDEX < y)
		return 0;

	return getSumRec(STARTINDEX, ENDINDEX, x, y, 0);
}

	   

	   

	   

public:int getSumRec(int low, int high, int x, int y, int p) {

	if (x <= low && high <= y)  

		return tree[p];

	if (y < low || high < x)   

		return 0;

	int mid = (low + high) / 2;

	return getSumRec(low, mid, x, y, leftChild(p))
		+ getSumRec(mid + 1, high, x, y, rightChild(p));
}

	   

public:void addValue(int pos, int val) {
	addValueRec(STARTINDEX, ENDINDEX, pos, val, 0);
}
	   

public:void set_remove(int pos, int val) {
	addValueRec(STARTINDEX, ENDINDEX, pos, max(val, tree[pos + (maxSize + 1) / 2]), 0);
}
public:void remove_index(int index) {
	remove_index_rec(0, index + 1);
}
public:void remove_index_rec(int index, int sum) {
	if (leftChild(index) >= maxSize)
	{
		addValue(index - (maxSize + 1) / 2 + 1, -1);
		return;
	}
	if (tree[leftChild(index)] < sum)
		remove_index_rec(rightChild(index), sum - tree[leftChild(index)]);
	else
		remove_index_rec(leftChild(index), sum);
}
	   

	   

	   

	   

public:void addValueRec(int low, int high, int pos, int val, int p) {
	if (low <= pos && pos <= high) {
		tree[p] = tree[p] + val;

		if (low != high) {
			int mid = (low + high) / 2;
			addValueRec(low, mid, pos, val, leftChild(p));
			addValueRec(mid + 1, high, pos, val, rightChild(p));
		}
	}
}
public:void print()
{
	print_vector(tree);
}
public:void print_set()
{
	int a = 0;
	F0R(i, tree.size())
		if (i >= maxSize / 2 && tree[i] != 0)
		{
			F0R(j, tree[i])
			{
				a = 1;
				cout << i - maxSize / 2 << " ";
			}
		}
	if (a == 1)
		cout << endl;
	else
		cout << 0 << endl;
}
public:void print_any()
{
	int a = 0;
	F0R(i, tree.size())
		if (i >= maxSize / 2 && tree[i] != 0)
		{
			F0R(j, tree[i])
			{
				cout << i - maxSize / 2 << " ";
				return;
			}
		}
	cout << 0 << endl;
}
public:void clear()
{
	fill(all(tree), 0);
}
};
int a, b, c;
void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	

}
int n, m;
vector<vi>adjacency;
vi order;
vi types;
void init()
{
	setIO("");
	cin >> n >> m;
	types.rsz(n);
	F0R(i, n)cin >> types[i];
	adjacency.rsz(n);
	F0R(i, n - 1)
	{
		cin >> a >> b;
		adjacency[--a].pb(--b);
		adjacency[b].pb(a);
	}
}
vi v;
vi parents;
void preorder(int index)
{
	order.pb(index);
	v[index] = 1;
	trav(x, adjacency[index])
	{
		if (v[x] == 0)
		{
			parents[x] = index;
			preorder(x);
		}
	}
}
int sqrt_n;
struct query
{
	int l;
	int r;
	int idx;
	int t; 

};
vector<int> ans;

bool co2(query x, query y)
{
	if (x.l / sqrt_n == y.l / sqrt_n)return x.r < y.r;
	return x.l / sqrt_n < y.l / sqrt_n;
}
vi temp;
vi counts;
void add(int i)
{
	if (i >= 0)
	{
		temp[types[order[i]]]++;
		counts[temp[types[order[i]]]]++;
	}
}
void sub(int i)
{
	if (i >= 0)
	{
		counts[temp[types[order[i]]]]--;
		temp[types[order[i]]]--;

	}
}
const int MAXN = 100005;
int main()
{
	init();

	sqrt_n = sqrt(n - 1) + 1;
	v.rsz(n);
	parents.rsz(n);
	v[0] = 1;
#if 1
	preorder(0);
	parents[0] = -1;
	

	vi s;
	s.rsz(n);
	F0R(i, n)s[i] = sz(adjacency[i]);
	list<int>t;
	F0R(i, n)if (s[i] == 1 && i != 0)t.pb(i);
	vi o;
	while (!t.empty())
	{
		int index = t.back();
		t.pop_back();
		o.pb(index);
		trav(x, adjacency[index])
		{
			s[x]--;
			if (s[x] == 1 && x != 0)
				t.pb(x);
		}
	}
	o.pb(0);
	

	vi sizes;
	sizes.rsz(n);
	trav(x, o)
	{
		sizes[x]++;
		if (parents[x] != -1)
			sizes[parents[x]] += sizes[x];
	}
	trav(x, sizes)x--;
#endif
	

	vector<query>queries;
	queries.rsz(m);
	vi index;
	index.rsz(n);
	F0R(i, n)index[order[i]] = i;
	F0R(i, m)
	{
		cin >> a >> b;
		a--;
		queries[i].l = index[a];
		queries[i].r = index[a] + sizes[a];
		queries[i].t = b;
		queries[i].idx = i;
	}
	sort(all(queries), co2);
	ans.resize(m);
	

	int l = -1, r = -1;
	temp.rsz(MAXN + 1);
	

	counts.rsz(MAXN + 1);
	

	

	F0R(i, m)
	{
		while (r < queries[i].r)
		{
			r++;
			add(r);
		}
		while (l > queries[i].l)
		{
			l--;
			add(l);
		}
		while (l < queries[i].l)
		{
			sub(l);
			l++;
		}
		while (r > queries[i].r)
		{
			sub(r);
			r--;
		}
		ans[queries[i].idx] = counts[queries[i].t];
		

	

	}
	for (auto i = 0; i < m; i++)
		cout << ans[i] << endl;
}