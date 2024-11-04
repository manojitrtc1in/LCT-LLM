


















using namespace std;
































template <class T> auto& operator>>(istream& is, vector<T>& xs) {
	for (auto& x : xs) is >> x;
	return is;
}
template <class T> auto& operator<<(ostream& os, vector<T>& xs) {
	int sz = xs.size();
	rep(i, 0, sz) os << xs[i] << " \n"[i + 1 == sz];
	return os;
}
template <class T, class Y> auto& operator<<(ostream& os, pair<T, Y>& xs) {
	os << "{" << xs.first << ", " << xs.second << "}";
	return os;
}
template <class T, class Y> auto& operator>>(istream& is, vector<pair<T, Y>>& xs) {
	for (auto& [x1, x2] : xs) is >> x1 >> x2;
	return is;

}
template <class  ...Args>
auto& read(Args & ...args) { return (cin >> ... >> args); }


void id3() {}
template <typename Head, class  ...Args>
void id3(const Head& head, const Args & ...args) {
	cout << head << " ";
	id3(args...);
}



class id2 {
public:
	vector<int> parent;
	vector<int> union_size;
	vector<ll> w;
	int len;
	ll value = 0;

	id2(int n) {
		len = n;
		parent.resize(n + 1, 0);
		w.resize(n + 1, 0);
		union_size.resize(n + 1, 1);
		value = 0;
		rep(i, 0, n + 1) parent[i] = i;
	}

	int root(int a) {
		if (parent[a] == a)
			return a;
		parent[a] = root(parent[a]);
		return parent[a];
	}

	void setWeight(int a, ll we) {
		w[a] = we;
	}

	ll getWeight(int a) {
		int ra = root(a);
		return w[ra];
	}

	void join(int a, int b) {
		int ra = root(a);
		int rb = root(b);
		if (ra == rb)
			return;
		if (union_size[ra] > union_size[rb]) {
			parent[rb] = ra;
			union_size[ra] += union_size[rb];
			w[ra] += w[rb];
		}
		else {
			parent[ra] = rb;
			union_size[rb] += union_size[ra];
			w[rb] += w[ra];
		}
		len--;
	}

	int size(int a) {
		return union_size[root(a)];
	}

};

template <typename T>
class segmentTree {
public:
	vector<T> v;
	int n;
	T(*func)(T, T);
	T defval = 0;

	segmentTree(int s, T(*f)(T, T)) {
		n = 1;
		while (n < s) n *= 2;
		v.resize(2 * n, defval);
		func = f;
	}
	

	

	

	

	void setNode(int ind, T val) {
		v[ind + n - 1] = val;
	}

	ll calculateTree() {
		for (int i = n - 2; i >= 0; i--)
			v[i] = func(v[i * 2 + 1], v[i * 2 + 2]);
		return v[0];
	}
	

	

	

	

	void addValue(int ind, T val) {
		updateNode(ind, val + v[ind + n - 1]);
	}

	T getValue(int ind) {
		return v[ind + n - 1];
	}
	

	

	

	

	void updateNode(int ind, T val) {
		v[ind + n - 1] = val;
		for (int i = (ind + n - 2) / 2; i != 0; i = (i - 1) / 2) {
			v[i] = func(v[i * 2 + 1], v[i * 2 + 2]);
		}
		v[0] = func(v[1], v[2]);
	}

	

	

	

	

	T queryInternal(int ind, int st, int en, int l, int r) {
		if (st >= l && en <= r)
			return v[ind];
		if (l > en || r < st)
			return defval;
		int mid = st + (en - st) / 2;
		return func(queryInternal(ind * 2 + 1, st, mid, l, r),
			queryInternal(ind * 2 + 2, mid + 1, en, l, r));
	}

	

	

	

	

	T query(int l, int r) {
		if (l > r)
			return 0;
		return queryInternal(0, 0, n - 1, l, r);
	}

	

	

	

	

	int querySumIndex(int ind, ll sum) {
		int left, right;
		left = ind * 2 + 1;
		right = left + 1;
		if (ind >= n - 1) {
			return (ind - n + 1);
		}
		

		

		if (v[left] >= sum) {
			return querySumIndex(left, sum);
		}
		else {
			return querySumIndex(right, sum - v[left]);
		}
	}
};

template <typename T> T id0(T a, T b) { return gcd(a, b); }
template <typename T> T my_min(T a, T b) { return min(a, b); }
template <typename T> T my_max(T a, T b) { return max(a, b); }
template <typename T> T my_and(T a, T b) { return (a & b); }
template <typename T> T id6(T a, T b) { return (a ^ b); }
template <typename T> T my_or(T a, T b) { return (a | b); }
template <typename T> T my_sum(T a, T b) { return (a + b); }
template <typename T> T id7(T a, T b) { return (a + b) % MOD; }







class SparseTable {

public:
	vvll table;
	ll(*func)(ll, ll);
	ll deep = 0;

	SparseTable(vector<ll> vec, ll(*f)(ll, ll)) {
		this->func = f;
		ll s = vec.size();
		deep = floor(log2(s));
		table.resize(deep + 1);
		table[0].resize(s);
		rep(i, 0, s)
			table[0][i] = vec[i];
		rep(k, 1, deep + 1) {
			ll g = pow(2, k - 1);
			table[k].resize(s);
			rep(i, 0, s - (g * 2 - 1)) {
				table[k][i] = f(table[k - 1][i], table[k - 1][i + g]);
			}
		}
	}

	

	

	

	

	

	

	ll query(ll st, ll size) {
		ll g = floor(log2(size));
		ll ret = this->func(table[g][st], table[g][st + size - pow(2, g)]);
		return ret;
	}

};







class BITree {
public:
	vector<ll> v;
	int sz;

	BITree(int n) {
		v.resize(n + 1, 0);
		sz = n;
	}

	void add(int ind, ll val) {
		int i = ind;
		while (i <= sz) {
			v[i] += val;
			i += (i & (-i));
		}
	}

	ll query(int ind) {
		ll r = 0;
		int i = ind;
		if (i > sz) i = sz;
		while (i > 0) {
			r += v[i];
			i -= (i & (-i));
		}
		return r;
	}
};


vll fact, invfact, inv;
void initFacts(ll n, ll m) {
	fact.resize(n + 1);
	invfact.resize(n + 1);
	inv.resize(n + 1);
	fact[0] = 1;
	invfact[0] = 1;
	inv[0] = 1;
	inv[1] = 1;
	rep(i, 1, n + 1) {
		fact[i] = (fact[i - 1] * i) % m;
	}
	rep(i, 2, n + 1) {
		inv[i] = -inv[m % i] * (m / i) % m;
		if (inv[i] < 0) inv[i] += m;
	}
	rep(i, 1, n + 1) {
		invfact[i] = invfact[i - 1] * inv[i] % m;
	}
}

ll id1(ll n, ll k) {
	ll v = (((fact[n] * invfact[k]) % MOD) * invfact[n - k]) % MOD;
	return v;
}

ll modInverse(ll a, ll m)
{
	ll m0 = m;
	ll y = 0, x = 1;

	if (m == 1)
		return 0;

	while (a > 1) {
		

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


class LazyPart {
public:


	LazyPart() {
	}

	LazyPart(ll aa) {
	}

	LazyPart& operator=(const LazyPart& other) {
		return *this;
	}

	void reset() {
	}
};

class LazyReal {
public:
	unordered_set<int> s;

	LazyReal() {
		s.clear();
	}

	LazyReal(int v) {
		s.insert(v);
	}

	LazyReal& operator=(const LazyReal& other) {
		s = other.s;
		return *this;
	}

	void reset() {
		s.clear();
	}
};


class id5 {
public:
	vector<LazyReal> v;
	vector<LazyPart> z;
	LazyReal dummyReal;
	LazyPart dummyLazy;

	vb islazy;
	int n;
	LazyReal defval = dummyReal;

	id5() {
	}

	id5(int size) {
		n = 1;
		while (n < size) n *= 2;
		v.resize(2 * n, dummyReal);
		z.resize(2 * n, dummyLazy);
		islazy.resize(2 * n, false);
	}

	id5(int size, LazyReal defReal, LazyPart deflazy) {
		n = 1;
		while (n < size) n *= 2;
		defval = defReal;
		v.resize(2 * n, defReal);
		z.resize(2 * n, deflazy);
		islazy.resize(2 * n, false);
	}

	

	

	

	LazyReal func(LazyReal& a, LazyReal& b) {
		LazyReal r = dummyReal;
		r.s = a.s;
		r.s.insert(b.s.begin(), b.s.end());
		return r;
	}

	

	

	void applyLazy(LazyReal& a, LazyPart& b, int len) {
		

	}
	

	

	void passDownLazy(LazyPart& a, LazyPart& b) {
		

	}


	void passDown(int ind, ll len) {
		if (!islazy[ind]) return;
		LazyPart t = z[ind];
		z[ind].reset();
		

		applyLazy(v[ind], t, len);
		islazy[ind] = false;

		if (ind >= n - 1) return;

		

		int d = ind * 2 + 1;
		passDownLazy(z[d], t);
		islazy[d] = true;
		d = ind * 2 + 2;
		passDownLazy(z[d], t);
		islazy[d] = true;
	}

	void setNode(int ind, LazyReal val) {
		v[ind + n - 1] = val;
	}

	void calculateTree() {
		for (int i = n - 2; i >= 0; i--)
			v[i] = func(v[i * 2 + 1], v[i * 2 + 2]);
	}

	LazyReal queryInternal(int ind, int st, int en, int us, int ue) {
		passDown(ind, en - st + 1);
		if (ue < st || en < us) return defval;
		if (us <= st && en <= ue) return v[ind];
		int mid = st + (en - st) / 2;
		LazyReal t1 = queryInternal(ind * 2 + 1, st, mid, us, ue);
		LazyReal t2 = queryInternal(ind * 2 + 2, mid + 1, en, us, ue);
		return func(t1, t2);
	}

	LazyReal query(int us, int ue) {
		return  queryInternal(0, 0, n - 1, us, ue);
	}

	void updateRangeInternal(int ind, int st, int en, int us, int ue, LazyPart val) {
		passDown(ind, en - st + 1);
		if (ue < st || en < us) return;
		if (us <= st && en <= ue) {
			z[ind] = val;
			islazy[ind] = true;
			passDown(ind, en - st + 1);
			return;
		}
		int mid = st + (en - st) / 2;
		updateRangeInternal(ind * 2 + 1, st, mid, us, ue, val);
		updateRangeInternal(ind * 2 + 2, mid + 1, en, us, ue, val);
		v[ind] = func(v[ind * 2 + 1], v[ind * 2 + 2]);
		return;
	}

	void updateRange(int us, int ue, LazyPart val) {
		updateRangeInternal(0, 0, n - 1, us, ue, val);
	}

};

ll lis(vll& v, ll maxVal) {
	int n = v.size();
	vll dp(n, maxVal);
	for (int i = 0; i < n; i++) {
		

		

		

		int x = (lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin());
		dp[x] = v[i];
	}
	return (lower_bound(dp.begin(), dp.end(), maxVal) - dp.begin());
}



vector<ll> primes;
void id4(int max_val) {
	primes.push_back(2);
	primes.push_back(3);
	for (ll i = 5; i <= max_val; i += 2) {
		int j = 0;
		ll max_val = sqrt(i);
		bool isprime = true;
		while (primes[j] <= max_val) {
			if (i % primes[j] == 0) {
				isprime = false;
				break;
			}
			j++;
		}
		if (isprime)
			primes.push_back(i);
	}
}

ll phi(ll n) {
	ll ans = n;
	ll i = 2;
	while (i * i <= n) {
		if (n % i == 0) {
			ans -= ans / i;
			while (n % i == 0)
				n /= i;
		}
		i++;
	}
	if (n != 1)
		ans -= ans / n;
	return ans;
}

ll bigPow(ll a, ll d, ll m) {
	if (a % m == 0) return 0;
	if (d == 0) return 1LL;
	ll r = bigPow(a, d / 2, m);
	r = (r * r) % m;
	if ((d % 2) == 1)
		r = (r * a) % m;
	return r;
}


void solve(int test) {
	ll rd(n);
	vpll rdv(s, n);
	vvll vals(21);
	ld maxval = 0;
	ll maxind = 0;
	rep(j, 1, 21) {
		map<ll, ll> p;
		rep(i, 0, n) {
			p[s[i].first] += min((ll)j, s[i].second);
		}
		vpll pp;
		for (auto u : p)
			pp.emplace_back(u.second, u.first);
		sort(all(pp));
		reverse(all(pp));
		ld expect = 0;
		if (pp.size() < j) {
			break;
		}
		int vv = 0;
		for (auto d : pp) {
			expect += d.first;
			vals[j].push_back(d.second);
			vv++;
			if (vv == j) {
				break;
			}
		}
		expect = expect / j;
		if (expect > maxval) {
			maxind = j;
			maxval = expect;
		}
	}
	

	cout << vals[maxind].size() << "\n";
	for (auto d : vals[maxind]) {
		cout << d << " ";
	}
}


int main() {
	

	ios::sync_with_stdio(0); cin.tie(0);
	int test = 1;
	

	for (int t = 1; t <= test; t++)
		solve(0);
	return 0;
}