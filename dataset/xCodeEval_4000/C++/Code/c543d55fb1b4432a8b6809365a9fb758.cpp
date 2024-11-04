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
#endif 










pi zero = { -1,-1 };


void cinArr(vi &arr) {
	for (int i = 0; i < arr.size(); i++) {
		cin >> arr[i];
	}
}

void cinArr(V<int> &arr) {
	for (int i = 0; i < arr.size(); i++) {
		cin >> arr[i];
	}
}

void cinMatr(vvi &matr) {
	ll n = matr.size();
	ll m = matr[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matr[i][j];
		}
	}
}

int xx[4] = { 1,-1,0,0 };
int yy[4] = { 0, 0, 1,-1 };

vi prim;
vi prims;
void er() {
	ll n = 1e6;
	prim = vi(n + 1);
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

	ll a;
	ll del;


	LCA &lca;

	ll l;
	ll r;
	Node* lChildren;
	Node* rChildren;


	pi merge(pi x, pi y, ll len1, ll len2) {

		if (len1 > 2 && len2 > 2) {
			ll a = x.first;
			ll b = x.second;
			ll c = y.first;
			ll d = y.second;


			ll ac = lca.getLCA(a, c);
			ll acb = lca.getLCA(ac, b);
			ll acd = lca.getLCA(ac, d);
			if (lca.getLvl(acb) > lca.getLvl(acd)) {
				return { acb,d };
			}
			else {
				return { acd,b };
			}

		}
		if (len1 == 0) {
			return y;
		}
		if (len2 == 0) {
			return x;
		}
		ll a = x.first;
		ll b = x.second;
		ll c = y.first;
		ll d = y.second;

		if (len1 == 1 && len2 == 1) {
			if (lca.getLvl(b) > lca.getLvl(d)) {
				return { b,d };
			}
			else {
				return { d,b };
			}
		}

		if (len1 == 1) {
			if (len2 == 2) {
				

				ll bc = lca.getLCA(b, c);
				ll bd = lca.getLCA(b, d);
				ll cd = lca.getLCA(c, d);
				ll lbc = lca.getLvl(bc);
				ll lbd = lca.getLvl(bd);
				ll lcd = lca.getLvl(cd);
				if (lbc > lbd&&lbc > lcd) {
					return { bc,d };
				}
				if (lbd > lcd) {
					return { bd,c };
				}
				return { cd,b };
			}
			

			ll bc = lca.getLCA(b, c);
			ll cd = lca.getLCA(c, d);
			ll lbc = lca.getLvl(bc);
			ll lcd = lca.getLvl(cd);
			if (lbc > lcd) {
				return { bc,d };
			}
			else {
				return { cd,b };
			}
		}
		if (len2 == 1) {
			if (len1 == 2) {
				

				ll ab = lca.getLCA(a, b);
				ll ad = lca.getLCA(a, d);
				ll bd = lca.getLCA(b, d);
				ll lab = lca.getLvl(ab);
				ll lad = lca.getLvl(ad);
				ll lbd = lca.getLvl(bd);
				if (lab > lad && lab > lbd) {
					return { ab,d };
				}
				if (lad > lbd) {
					return { ad,b };
				}
				return { bd,a };
			}
			

			ll ab = lca.getLCA(b, a);
			ll ad = lca.getLCA(a, d);
			ll lab = lca.getLvl(ab);
			ll lad = lca.getLvl(ad);
			if (lab > lad) {
				return { ab,d };
			}
			else {
				return { ad,b };
			}
		}
		if (len1 == 2 && len2 > 2) {
			ll abc = lca.getLCA(a, lca.getLCA(b, c));
			ll acd = lca.getLCA(a, lca.getLCA(c, d));
			ll bcd = lca.getLCA(b, lca.getLCA(c, d));

			ll labc = lca.getLvl(abc);
			ll lacd = lca.getLvl(acd);
			ll lbcd = lca.getLvl(bcd);
			ll ans = max({ labc,lacd,lbcd });
			if (labc == ans) {
				return { abc,d };
			}
			if (lacd == ans) {
				return { acd,b };
			}
			if (lbcd == ans) {
				return { bcd,a };
			}
		}
		if (len2 == 2 && len1 > 2) {
			ll abc = lca.getLCA(a, lca.getLCA(b, c));
			ll abd = lca.getLCA(a, lca.getLCA(b, d));
			ll acd = lca.getLCA(a, lca.getLCA(c, d));

			ll labc = lca.getLvl(abc);
			ll labd = lca.getLvl(abd);
			ll lacd = lca.getLvl(acd);
			ll ans = max({ labc,labd,lacd });
			if (labc == ans) {
				return { abc,d };
			}
			if (labd == ans) {
				return { abd,c };
			}
			if (lacd == ans) {
				return { acd,b };
			}
		}

		

		

		ll abc = lca.getLCA(a, lca.getLCA(b, c));
		ll abd = lca.getLCA(a, lca.getLCA(b, d));
		ll acd = lca.getLCA(a, lca.getLCA(c, d));
		ll bcd = lca.getLCA(b, lca.getLCA(c, d));

		ll labc = lca.getLvl(abc);
		ll labd = lca.getLvl(abd);
		ll lacd = lca.getLvl(acd);
		ll lbcd = lca.getLvl(bcd);
		ll ans = max({ labc,labd,lacd,lbcd });
		if (labc == ans) {
			return { abc,d };
		}
		if (labd == ans) {
			return { abd,c };
		}
		if (lacd == ans) {
			return { acd,b };
		}
		if (lbcd == ans) {
			return { bcd,a };
		}

		return zero;

	}

	Node(ll l, ll r, vi &arr, LCA &lca) :lca(lca) {
		this->l = l;
		this->r = r;
		if (l == r) {
			a = -1;
			del = arr[l];
		}
		else {
			ll mid = (l + r) / 2;
			lChildren = new Node(l, mid, arr, lca);
			rChildren = new Node(mid + 1, r, arr, lca);
			ll len1 = mid - l + 1;
			ll len2 = r - mid;
			pi p = merge(lChildren->getValue(), rChildren->getValue(), len1, len2);
			a = p.first;
			del = p.second;
		}
	}

public:



	Node(vi &arr, LCA &lca) :Node(0, arr.size() - 1, arr, lca) {
	}

	pi getValue() {
		pi p = { a,del };
		return p;
	}

	pi getValue(ll left, ll right) {
		if (l == left && r == right) {
			return getValue();
		}
		ll mid = (l + r) / 2;
		pi p1, p2;
		ll len1 = 0;
		ll len2 = 0;
		p1 = p2 = zero;
		if (left <= mid) {
			p1 = lChildren->getValue(left, min(right, mid));
			len1 = min(right, mid) - left + 1;
		}
		if (right > mid) {
			p2 = rChildren->getValue(max(mid + 1, left), right);
			len2 = right - max(mid + 1, left) + 1;
		}
		pi p = merge(p1, p2, len1, len2);
		return p;
	}


	void update(ll l, ll r, ll value) {
		if (l == this->l && r == this->r) {

			return;
		}
		ll mid = (this->l + this->r) / 2;
		if (l <= mid) {
			lChildren->update(l, min(mid, r), value);
		}
		if (r > mid) {
			rChildren->update(max(mid + 1, l), r, value);
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

ll nok(ll a, ll b) {
	ll nnod = gcd(a, b);
	ll ans = a / nnod * b;
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
	SNM(ll n) {
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



ll bs(ll x, vi &arr) {
	ll l = 0;
	ll r = arr.size();
	while (l < r) {
		ll mid = (l + r) / 2;
		if (arr[mid] >= x) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	return l;
}
ll E = 998244353;
void dfs(ll v, vvi &g, vi &count, vi &fac) {

	count[v] = fac[g[v].size() + (v==0?0:1)];
	for (ll u : g[v]) {
		dfs(u, g, count, fac);
		count[v] *= count[u];
		count[v] %= E;
	}
}

void delR(ll v, vvi &g, vb &viz, vvi &G) {
	viz[v] = true;
	for (ll u : g[v]) {
		if (!viz[u]) {
			G[v].push_back(u);
			delR(u, g, viz, G);
		}
	}
}

int main()
{


	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	

	

	

	


	ll n;
	cin >> n;
	if (n == 2) {
		cout << 2;
		return 0;
	}
	vvi g(n);
	vpi reb;
	for (int i = 0; i < n - 1; i++) {
		ll v, u;
		cin >> v >> u;
		v--;
		u--;
		g[v].push_back(u);
		g[u].push_back(v);
		reb.push_back({ v,u });
	}
	ll ans = 1;
	vi fac(n + 1);
	fac[1] = 1;
	for (int i = 2; i <= n; i++) {
		ans *= i;
		ans %= E;
		fac[i] = ans;
	}
	

	vvi G(n);
	vb viz(n, false);
	delR(0, g, viz, G);


	vi count(n, 0);
	vi lvl(n, 0);
	dfs(0, G, count, fac);

	ans = count[0]*n;
	ans %= E;

	cout << ans;
	return 0;
}