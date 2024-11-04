#ifndef ABC
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <queue>
#include <stack>
#include <list>
#define endl '\n'
#define ABS(x) (((x)^((x) >> 31)) - ((x) >> 31))
#include <ctime>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef pair<pi, ll> ppi;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<ppi> vppi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef map<ll, ll> mii;
typedef set<pi> spi;
typedef set<ll> si;
typedef multiset<ll> msi;
typedef multiset<pi> mspi;
typedef vector<si> vsi;
template <typename T> using V = vector<T>;
template <typename T> using VV = vector<V<T>>;
template <typename T> using Mi = map<ll, T>;
template <typename T> using MMi = map<ll, Mi<T>>;

const double PI = 3.141592653589793238463;



template < typename T >
istream& operator>> (istream &cin, V<T> &arr) {
	for (T &val : arr) {
		cin >> val;
	}
	return cin;
}
template < typename T >
ostream& operator<< (ostream &cout, VV<T> &arr) {
	for (V<T> &val : arr) {
		cout << val << endl;
	}
	return cout;
}
template < typename T >
ostream& operator<< (ostream &cout, V<T> &arr) {
	for (T &val : arr) {
		cout << val << " ";
	}
	return cout;
}
template < typename T, typename R>
istream& operator>> (istream &cin, pair<T, R> &p) {
	cin >> p.first >> p.second;
	return cin;
}
template < typename T, typename R>
ostream& operator<< (ostream &cout, pair<T, R> &p) {
	cout << p.first << " " << p.second;
	return cout;
}

template < typename T >
V<T>& operator--(V<T> &arr) {
	for (T &val : arr) {
		val--;
	}
	return arr;
}
template < typename T >
V<T>& operator++(V<T> &arr) {
	for (T &val : arr) {
		val++;
	}
	return arr;
}


#endif 










pi zero = { -1,-1 };



int xx[4] = { 1,-1,0,0 };
int yy[4] = { 0, 0, 1,-1 };



class Siev
{
public:
	V<int> prim;
	V<int> prims;
	ll n
		;
	Siev(ll n = 1e6) :n(n) {
		prim.resize(n + 1);
		for (int i = 0; i <= n; i++) {
			prim[i] = i;
		}
		for (ll i = 2; i <= n; i++) {
			if (prim[i] == i) {
				prims.push_back(i);
				for (ll j = i * i; j <= n; j += i) {
					if (prim[j] == j) {
						prim[j] = i;
					}
				}
			}
		}
	}

};


ll gcd(ll a, ll b) {
	if (a < b) {
		swap(a, b);
	}
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}
ll gcd(ll a, ll b, ll & x, ll & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcd(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
ll lcm(ll a, ll b) {
	ll nod = gcd(a, b);
	ll ans = a / nod * b;
	return ans;
}


ll divup(ll a, ll b) {
	if (a%b == 0) {
		return a / b;
	}
	else {
		return a / b + 1;
	}
}



class SNM {
private:
	vi parent;
	vi size;
public:
	SNM(int n) {
		parent = vi(n);
		size = vi(n, 1);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	void make_set(int v) {
		parent[v] = v;
	}
	int find_set(int v) {
		if (v == parent[v])
			return v;
		ll ans = find_set(parent[v]);
		parent[v] = ans;
		return ans;
	}
	void union_sets(int a, int b) {
		a = find_set(a);
		b = find_set(b);
		if (a != b) {
			parent[b] = a;
			size[a] += size[b];
		}
	}
	ll getSize(int v) {
		v = find_set(v);
		return size[v];
	}
};


class LCA {
private:
	ll N;
	ll n;
	vvi up;
	vvi g;
	vi lvl;
	void dfs(ll v, ll h) {
		lvl[v] = h;
		for (ll u : g[v]) {
			dfs(u, h + 1);
		}
	}

public:
	LCA(vi &parent) {
		n = parent.size();
		N = log2(n) + 1;
		g = vvi(n);
		lvl = vi(n);
		ll core = -1;
		for (int i = 0; i < n; i++) {
			if (parent[i] != -1) {
				g[parent[i]].push_back(i);
			}
			else {
				core = i;
			}
		}
		dfs(core, 0);
		up = vvi(N, vi(n));
		up[0] = parent;
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < n; j++) {
				ll parent = up[i - 1][j];
				if (parent == -1) {
					up[i][j] = -1;
				}
				else {
					up[i][j] = up[i - 1][parent];
				}
			}
		}

	}
	ll getParent(ll v, ll needUp) {
		for (int i = N - 1; i >= 0; i--) {
			if (up[i][v] != -1 && lvl[v] - lvl[up[i][v]] <= needUp) {
				needUp -= lvl[v] - lvl[up[i][v]];
				v = up[i][v];
			}
		}
		if (needUp != 0) {
			return -1;
		}
		else {
			return v;
		}
	}

	ll getLCA(ll a, ll b) {
		if (lvl[a] > lvl[b]) {
			ll del = abs(lvl[a] - lvl[b]);
			a = getParent(a, del);
		}
		if (lvl[a] < lvl[b]) {
			ll del = abs(lvl[a] - lvl[b]);
			b = getParent(b, del);
		}
		if (a == b) {
			return a;
		}
		for (int i = N - 1; i >= 0; i--) {
			if (up[i][a] != up[i][b]) {
				a = up[i][a];
				b = up[i][b];
			}
		}
		return up[0][a];
	}
	ll getLvl(ll v) {
		return lvl[v];
	}
};


class Node {
private:
	ll val;
	ll l;
	ll r;
	Node* lChildren;
	Node* rChildren;

	ll merge(Node *a, Node *b) {
		return max(a->val, b->val);
	}
	Node(ll l, ll r, vi &arr) {
		this->l = l;
		this->r = r;
		if (l == r) {
			val = arr[l];
		}
		else {
			ll mid = (l + r) / 2;
			lChildren = new Node(l, mid, arr);
			rChildren = new Node(mid + 1, r, arr);
			val = merge(lChildren, rChildren);
		}
	}



public:



	Node(vi arr) :Node(0, arr.size() - 1, arr) {
	}

	ll getValue(ll left, ll right) {
		if (l == left && r == right) {
			return val;
		}
		ll mid = (l + r) / 2;
		ll ans = -1e18;
		if (left <= mid) {
			ll lp = lChildren->getValue(left, min(right, mid));
			ans = max(ans, lp);
		}
		if (right > mid) {
			ll rp = rChildren->getValue(max(mid + 1, left), right);
			ans = max(ans, rp);
		}
		return ans;
	}

	void update(ll l, ll r, ll value) {
		if (l == this->l && r == this->r) {
			val = value;
			return;
		}
		ll mid = (this->l + this->r) / 2;
		if (l <= mid) {
			lChildren->update(l, min(mid, r), value);
		}
		if (r > mid) {
			rChildren->update(max(mid + 1, l), r, value);
		}
		val = merge(lChildren, rChildren);
	}
};





void delR(ll v, vvi &g, vb &viz, vvi &G) {
	viz[v] = true;
	for (ll u : g[v]) {
		if (!viz[u]) {
			G[v].push_back(u);
			delR(u, g, viz, G);
		}
	}
}






class Drob {
public:
	ll a = 0;
	ll b = 1;
	Drob(ll a, ll b = 1) :a(a), b(b) {
		ll nod = gcd(a, b);
		a /= nod;
		b /= nod;
	}

	Drob operator+(Drob &add) {
		ll na = a * add.b + add.a*b;
		ll nb = b * add.b;
		return Drob(na, nb);
	}

	Drob operator+=(Drob &add) {
		return *this + add;
	}

	Drob operator-(Drob &minus) {
		minus.a *= -1;
	}
	Drob operator-=(Drob &minus) {
		return *this - minus;
	}

	Drob operator*(Drob &d) {
		ll na = a * d.a;
		ll nb = b * d.b;
		return Drob(na, nb);
	}
	Drob operator*=(Drob &d) {
		return (*this)*d;
	}
	Drob operator/(Drob &d) {
		Drob dd(d.b, d.a);
		return (*this)*dd;
	}
	Drob operator/=(Drob &d) {
		return (*this) / d;
	}

	bool operator==(Drob &d) {
		return a == d.a && b == d.b;
	}
	bool operator>(Drob &d) {
		ll aa = a * d.b;
		ll ad = d.a*b;
		return aa > ad;
	}
};


void split(string &str, char &space, V<string> &ans) {
	auto i = str.begin();
	while (i != str.end()) {
		i = std::find_if(i, str.end(), [space](char c)
		{
			return c != space;
		}
		); 

		auto j = std::find_if(i, str.end(), [space](char c)
		{
			return c == space;
		}
		); 

		if (i != str.end()) {
			ans.push_back(std::string(i, j)); 

			i = j; 

		}
	}
}

ll sumNumber(ll n) {
	ll sum = 0;
	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}


class Prefix {
	vi prefix;
	ll n;
public:
	Prefix(vi &arr) {
		n = arr.size() + 1;
		prefix.resize(n);
		prefix[0] = 0;
		for (int i = 0; i < n - 1; i++) {
			prefix[i + 1] = prefix[i] + arr[i];
		}
	}
	ll sum(ll l, ll r) {
		return prefix[r + 1] - prefix[l];
	}
};

class DPrefix {
	vvi prefix;
	ll n;
	ll m;
public:
	DPrefix(vvi &matr) {
		ll n = matr.size() + 1;
		ll m = matr[0].size() + 1;
		prefix = vvi(n, vi(m, 0));
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m - 1; j++) {
				prefix[i + 1][j + 1] = prefix[i + 1][j] + prefix[i][j + 1] - prefix[i][j] + matr[i][j];
			}
		}
	}
	ll sum(pi p1, pi p2) {
		p2.first++;
		p2.second++;
		ll res = prefix[p1.first][p1.second] + prefix[p2.first][p2.second] - prefix[p1.first][p2.second] - prefix[p2.first][p1.second];
		return res;
	}
	ll sum(ll x1, ll y1, ll x2, ll y2) {
		pi p1 = { x1,y1 };
		pi p2 = { x2,y2 };
		return sum(p1, p2);
	}
};

template < typename T >
class AV :public V<T> {
public:
	AV() :V<T>() {};
	AV(ll n) :V<T>(n) {};
	AV(ll n, ll val) :V<T>(n, val) {};

	T sum() {
		T ans = 0;
		for (T &val : *this) {
			ans += val;
		}
		return ans;
	}

	T max() {
		T ans = (*this)[0];
		for (T &val : *this) {
			ans = std::max(ans, val);
		}
		return ans;
	}
	T min() {
		T ans = (*this)[0];
		for (T &val : *this) {
			ans = std::min(ans, val);
		}
		return ans;
	}

	void rsort() {
		std::sort(this->rbegin(), this->rend());
	}
	void sort() {
		std::sort(this->begin(), this->end());
	}

	ll bs(T &x) {
		V<T> &arr = *this;
		ll l = 0;
		ll r = arr.size();
		while (l < r) {
			ll mid = (l + r) / 2;
			if (arr[mid] > x) {
				r = mid;
			}
			else {
				l = mid + 1;
			}
		}
		return l;
	}

};


class MinQueue {
	deque<ll> q;

public:
	ll getMin() {
		return q.front();
	}

	void add(ll val) {
		while (!q.empty() && q.back() > val) {
			q.pop_back();
		}
		q.push_back(val);
	}

	void pop(ll val) {
		if (!q.empty() && q.front() == val)
			q.pop_front();
	}

};


ll powM(ll a, ll b, ll mod) {
	if (b == 1) {
		return a;
	}
	ll A = (a * a) % mod;
	ll ans = powM(A, b / 2, mod);
	if (b % 2 == 1) {
		ans *= a;
		ans %= mod;
	}
	return ans;
}



ll bs(ll x, vpi &arr) {
	ll l = 0;
	ll r = arr.size() - 1;
	while (l < r) {
		ll mid = (l + r + 1) / 2;
		if (arr[mid].first > x) {
			r = mid - 1;
		}
		else {
			l = mid;
		}
	}
	return l;
}


ll MOD = 9 * 8 * 7 * 5;
ll ADD = 1e9*MOD;

VV<int> dp(1000, V<int>(MOD, 0));
VV<int> viz(1000, V<int>(MOD, 0));
VV<int> g(1000);
vi arr;
V<int> in(1000);
ll add(ll x, ll y) {
	x += y;
	x %= MOD;
	x += MOD;
	x %= MOD;
	return x;
}
ll dfs(ll v, ll c, ll num, ll &time) {
	if (viz[v][c] != 0) {
		if (viz[v][c] == num) {
			ll sum = 0;
			for (int i = 0; i < in.size(); i++) {
				if (in[i] >= -dp[v][c]) {
					sum++;
				}
			}
			return dp[v][c] = sum;
		}
	}
	else {
		viz[v][c] = num;
		in[v] = time++;
		dp[v][c] = -in[v];
		ll nc = add(c, arr[v]);
		ll cc = nc % g[v].size();
		ll u = g[v][cc];
		dp[v][c] = dfs(u, nc, num, time);
	}
	return dp[v][c];
}


int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	

	

	

	


	ll n;
	cin >> n;
	arr = vi(n);
	cin >> arr;

	for (int i = 0; i < n; i++) {
		ll m;
		cin >> m;
		for (int j = 0; j < m; j++) {
			ll a;
			cin >> a;
			a--;
			g[i].push_back(a);
		}
	}

	

	ll q;
	cin >> q;
	vi ans(q);
	ll num = 1;
	ll time = 1;
	for (int i = 0; i < q; i++) {
		ll x, y;
		cin >> x >> y;
		x--;
		y = add(y, 0);
		ans[i] = dfs(x, y, num++, time);
	}
	cout << ans;

	return 0;


}