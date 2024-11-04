





























































































































































































































































































using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;













int gcd(int n, int n1) {
	while (n != 0 && n1 != 0) {
		if (n > n1) n %= n1;
		else n1 %= n;
	}
	return n + n1;
}

ll lcm(ll n, ll n1) {
	ll nod = gcd(n, n1);
	return (n / nod) * (n1 / nod) * nod;
}

ll mod = 1000000007;

ll binpow(ll n, ll m) {
	if (m == 0)
		return (ll)1;
	if (m % 2 == 1)
		return binpow(n, m - 1) * n;
	else {
		ll b = binpow(n, m / 2);
		return b * b;
	}
}

ll INF = 999999999999999999;

mt19937 gen(time(0));

vector<ll> c(1000001, 0), t, t_add;

struct str {
	int l, r, c;
};

struct CMP {
	bool operator()(str a, str b) const{
		return a.l < b.l;
	}
};

struct CMP2 {
	bool operator()(str a, str b) const {
		return a.l > b.l;
	}
};

void push(int v) {
	if (t_add[v] == 0) return;
	t[2 * v] += t_add[v];
	t[2 * v + 1] += t_add[v];
	t_add[2 * v] += t_add[v];
	t_add[2 * v + 1] += t_add[v];
	t_add[v] = 0;
}

void upd(int v, int l, int r, int askl, int askr, ll val) {
	if (l >= askr || r <= askl) return;
	if (l >= askl && r <= askr) {
		t_add[v] += val;
		t[v] += val;
		return;
	}
	push(v);
	int m = (l + r) / 2;
	upd(2 * v, l, m, askl, askr, val);
	upd(2 * v + 1, m, r, askl, askr, val);
}

ll get(int v, int l, int r, int pos) {
	if (l == r - 1) return t[v];
	push(v);
	int m = (l + r) / 2;
	if (pos < m) return get(2 * v, l, m, pos);
	else return get(2 * v + 1, m, r, pos);
}

void solve() {
	int n, q;
	cin >> n >> q;
	t.resize(4 * n, 0);
	t_add.resize(4 * n, 0);
	set<str, CMP> st;
	set<str, CMP2> st2;
	st.insert({ 0, n - 1, 1 });
	st2.insert({ 0, n - 1, 1 });
	for (int i = 0; i < q; i++) {
		string s;
		ll val;
		int l, r, cl;
		cin >> s;
		if (s == "Color") {
			cin >> l >> r >> cl;
			l--; r--;
			if (st2.lower_bound({ l, -1, -1 }) != st2.end() && (*st2.lower_bound({ l, -1, -1 })).r >= r) {
				str u = *st2.lower_bound({ l, -1, -1 });
				upd(1, 0, n, l, r + 1, c[u.c] - c[cl]);
				st.erase(u);
				st2.erase(u);
				if (u.l < l) {
					st.insert({ u.l, l - 1, u.c });
					st2.insert({ u.l, l - 1, u.c });
				}
				if (u.r > r) {
					st.insert({ r + 1, u.r, u.c });
					st2.insert({ r + 1, u.r, u.c });
				}
				st.insert({ l, r, cl });
				st2.insert({ l, r, cl });
				continue;
			}
			while (st.lower_bound({ l, -1, -1 }) != st.end() && (*st.lower_bound({ l, -1, -1 })).r <= r) {
				str u = *st.lower_bound({ l, -1, -1 });
				upd(1, 0, n, u.l, u.r + 1, c[u.c] - c[cl]);
				st.erase(u);
				st2.erase(u);
			}
			if (st.lower_bound({ l, -1, -1 }) != st.end()) {
				str u = *st.lower_bound({ l, -1, -1 });
				if (u.l <= r) {
					upd(1, 0, n, u.l, r + 1, c[u.c] - c[cl]);
					st.erase(u);
					st2.erase(u);
					st.insert({ r + 1, u.r, u.c });
					st2.insert({ r + 1, u.r, u.c });
				}
			}
			if (st2.lower_bound({ l, -1, -1 }) != st2.end()) {
				str u = *st2.lower_bound({ l, -1, -1 });
				if (u.r >= l) {
					upd(1, 0, n, l, u.r + 1, c[u.c] - c[cl]);
					st.erase(u);
					st2.erase(u);
					st.insert({ u.l, l - 1, u.c });
					st2.insert({ u.l, l - 1, u.c });
				}
			}
			st.insert({ l, r, cl });
			st2.insert({ l, r, cl });
		}
		else if (s == "Add") {
			cin >> l >> val;
			c[l] += val;
		}
		else {
			cin >> l;
			l--;
			str u = (*st2.lower_bound({ l, -1, -1 }));
			assert(u.l <= l && u.r >= l);
			cout << (ll)(get(1, 0, n, l) + c[u.c]) << '\n';
		}
		
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	

	tt = 1;
	while (tt--) {
		solve();
	}
	return 0;
}