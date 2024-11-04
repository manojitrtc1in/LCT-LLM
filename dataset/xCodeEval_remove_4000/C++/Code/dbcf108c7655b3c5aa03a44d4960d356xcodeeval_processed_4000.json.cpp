



using namespace std;
using namespace chrono;
using namespace __gnu_pbds;








using ll = long long;
using lld = long double;
using vll = vector<ll>;
using vii = vector<int>;
using pll = pair<ll, ll>;
using pii = pair<int, int>;












void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(ordered_set v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


struct comp {
	bool operator()(const std::pair<int, int> &a, const std::pair<int, int> &b) {
		if (a.first != b.first) {
			return a.first < b.first;
		}
		return a.second > b.second;
	}
};
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b); }
ll id1(ll n, ll k) { ll ans = 1; while (k > 0) {if (k % 2 != 0) {ans = (ans * n) % MOD;} n = (n * n) % MOD; k /= 2;} return ans;}
ll id0(ll n, ll k) { ll ans = 1; while (k > 0) {if (k % 2 != 0) {ans = (ans * n);} n = (n * n); k /= 2;} return ans; }\

struct tup {
	ll x, y, z;
	

};
bool custom(const tup &x, const tup &y) {
	if (x.y - x.x == y.y - y.x) {
		return x.x < y.x;
	}
	return x.y - x.x < y.y - y.x;
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<ll> prime;
void sieve(ll n) {
	prime.resize(n + 1);
	rep(i, 0, n + 1) {
		prime[i] = i;
	}
	for (int p = 2; p * p <= n; p++) {
		if (prime[p] == p) {
			for (int i = p * p; i <= n; i += p)
				if (prime[i] == i) {
					prime[i] = p;
				}
		}
	}
}
struct Graph {
	vector<vll> adj;
	

	vector<ll> siz;
	vector<ll> inf;
	ll count = 0;
	set<ll> s;
	vll parent;
	Graph(ll n) {
		adj.resize(n + 1);
		siz.resize(n + 1);
		inf.resize(n + 1);
		parent.resize(n + 1);
		parent[1] = 0;
	}

	void dfs(ll c , ll p) {
		siz[c] = 1;
		for (auto x : adj[c]) {
			if (x != p) {
				dfs(x, c);
			}
		}
		for (auto x : adj[c]) {
			if (x != p) {
				siz[c] += siz[x];
			}
		}
	}

	void dfs2(ll c, ll p) {
		inf[c] = 0;
		for (auto x : adj[c]) {
			if (x != p) {
				dfs2(x, c);
			}
		}

		if ((adj[c].size() == 3 ) || (adj[c].size() == 2 && c == 1)) {
			vector<ll> temp;
			for (auto x : adj[c]) {
				if (x != p) {
					temp.pb(x);
				}
			}
			inf[c] = max(inf[temp[0]] + siz[temp[1]] - 1, inf[temp[1]] + siz[temp[0]] - 1);
		}
		else if ((adj[c].size() == 2 && c != 1) || (adj[c].size() == 1 && c == 1)) {
			ll x;
			for (auto y : adj[c]) {
				if (y != p) x = y;
			}
			inf[c] = siz[x] - 1;
		}
	}
};
struct SegTree {
	vector<ll> seg;
	vector<bool> marked;
	SegTree(ll n) {
		seg.resize(8 * n + 5);
		marked.resize(8 * n + 5);
	}
	ll combine(ll a, ll b) {
		return a + b;
	}
	void push(ll v) {
		if (marked[v]) {
			seg[v * 2] = (seg[v] + 1) / 2;
			seg[v * 2 + 1] = seg[v] - (seg[v] + 1) / 2;
			marked[v * 2] = marked[v * 2 + 1] = true;
			marked[v] = false;
		}
	}
	void updatetillparent(ll v) {
		ll parent = v / 2;
		while (parent != 0) {
			seg[parent] = combine(seg[parent * 2], seg[2 * parent + 1]);
			parent = parent / 2;
		}
	}
	void build(vll &a, ll v, ll tl, ll tr) {
		if (tl == tr) {
			seg[v] = a[tl];
		}
		else {
			ll tm = (tl + tr) / 2;
			build(a, 2 * v, tl, tm);
			build(a, v * 2 + 1, tm + 1, tr);
			seg[v] = combine(seg[v * 2], seg[2 * v + 1]);
		}
	}
	ll range_query(ll v, ll tl, ll tr, ll l, ll r) {
		push(v);
		if (tl == l && tr == r) {
			return seg[v];
		}
		ll tm = (tl + tr) / 2;
		if (r <= tm) {
			return range_query(2 * v, tl, tm, l, r);
		}
		else if (l > tm) {
			return range_query(2 * v + 1, tm + 1, tr, l, r);
		}
		else return combine(range_query(2 * v, tl, tm, l, tm), range_query(2 * v + 1, tm + 1, tr, tm + 1, r));
	}
	

	

	

	

	

	

	

	

	

	

	

	

	


	void update(ll v, ll tl, ll tr, ll l, ll r, ll new_val) {
		if (l > r)
			return;
		if (l == tl && tr == r) {
			seg[v] = new_val * (r - l + 1);
			marked[v] = true;
			updatetillparent(v);
		} else {
			push(v);
			ll tm = (tl + tr) / 2;
			update(v * 2, tl, tm, l, min(r, tm), new_val);
			update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, new_val);
		}
	}


	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	

	

	


	

	

	

	

	

	

	

	

	

	

	


};

struct DSU {
	vll parent;
	vll size;
	DSU(ll n) {
		parent.resize(n + 1);
		size.resize(n + 1);
	}
	ll find_set(ll v) {
		if (v == parent[v])
			return v;
		return  parent[v] = find_set(parent[v]);
	}
	void make_set(ll v) {
		parent[v] = v;
		size[v] = 1;
	}
	void union_sets(ll a, ll b) {
		a = find_set(a);
		b = find_set(b);
		if (a != b) {
			if (size[a] < size[b])
				swap(a, b);
			parent[b] = a;
			size[a] += size[b];
		}
	}
};






































ll query(string m, ll i, ll j) {
	cout << m << " " << i + 1 << " " << j + 1 << endl;
	ll ans;
	cin >> ans;
	return ans;
}



ll hepler(ll k, ll n) {
	debug(k)
	debug(n)
	if (n >= k) {
		return k;
	}
	if (n == 1) {
		return  __builtin_popcount(k);
	}
	ll ans = 0;
	rrep(i, n - 1, max(1ll, n - 31)) {
		ll q = hepler(k - i, n - i);
		ans = max(ans, q + i);
	}
	return ans;

}

void solve(ll op) {
	ll n, m;
	cin >> n >> m;
	vector<string> s(n);
	rep(i, 0, n) {
		cin >> s[i];
	}
	vector<vector<ll>> adj(n);
	vector<vector<ll>> adj2(n);
	rep(i, 0, n) {
		rep(j, 0, n) {
			if (i != j) {
				if (s[i][j] == 'a') {
					adj[i].pb(j);
				}
				else {
					adj2[i].pb(j);
				}
			}
		}
	}
	pll p;
	bool done  = false;
	rep(i, 0, n) {
		rep(j, 0, n) {
			if (i != j) {
				if (s[i][j] == s[j][i]) {
					done = true;
					p = {i + 1, j + 1};
					break;
				}
			}
		}
	}


	if (done) {
		cout << "YES\n";
		rep(i, 0, (m + 1) / 2) {
			cout << p.first << " " << p.second << " ";
		}
		if (m % 2 == 0) {
			cout << p.first;
		}
		cout << "\n";
	}
	else {
		bool done2 = false;
		tup p;
		rep(i, 0, n) {
			if (adj[i].size() == 0) {
				continue;
			}
			else {
				for (auto x : adj[i]) {
					if (adj[x].size() > 0) {
						done2 = true;
						p  = {i + 1, x + 1, adj[x][0] + 1};
						break;
					}
				}
				if (done2) {
					break;
				}
				else {
					continue;
				}
			}
		}
		if (m % 2 == 1) {
			cout << "YES\n";
			rep(i, 0, (m + 1) / 2) {
				cout << "1 2 ";
			}
			cout << "\n";
		}
		else {
			if (!done2) {
				cout << "NO\n";
			}
			else {
				cout << "YES\n";
				if (m % 4 == 2) {
					cout << p.x << " " << p.y <<  " ";
					rep(i, 0, (m - 2) / 4) {
						cout << p.z << " " << p.y << " " << p.x << " " << p.y << " ";
					}
					cout << p.z << "\n";
					

				}
				else {
					rep(i, 0, m / 4) {
						cout << p.y << " " << p.z << " " << p.y << " " << p.x << " ";
					}
					cout << p.y << "\n";
					

				}
			}
		}

	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("error.txt", "w", stderr);

	auto start1 = high_resolution_clock::now();
	int t = 1;
	

	

	cin >> t;
	rep(i, 1, t + 1) {
		solve(i);
	}
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);

	cerr << "Time: " << duration . count() / 1000 << endl;

}