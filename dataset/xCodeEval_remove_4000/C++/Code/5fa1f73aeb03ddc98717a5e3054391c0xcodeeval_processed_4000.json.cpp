





















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


void id5() {}
template <typename Head, class  ...Args>
void id5(const Head& head, const Args & ...args) {
	cout << head << " ";
	id5(args...);
}



class id4 {
public:
	vector<int> parent;
	vector<int> union_size;
	vector<ll> w;
	int len;
	int nn;
	ll value = 0;

	id4(int n) {
		len = n;
		nn = n;
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

	bool join(int a, int b) {
		if (a<0 || a>nn) return false;
		if (b<0 || b>nn) return false;
		int ra = root(a);
		int rb = root(b);
		if (ra == rb)
			return false;
		if (ra < rb) {
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
		return true;
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

template <typename T> T id1(T a, T b) { return gcd(a, b); }
template <typename T> T my_min(T a, T b) { return min(a, b); }
template <typename T> T my_max(T a, T b) { return max(a, b); }
template <typename T> T my_and(T a, T b) { return (a & b); }
template <typename T> T id9(T a, T b) { return (a ^ b); }
template <typename T> T my_or(T a, T b) { return (a | b); }
template <typename T> T my_sum(T a, T b) { return (a + b); }
template <typename T> T id11(T a, T b) { return (a + b) % MOD; }







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
		invfact[i] = (invfact[i - 1] * inv[i]) % m;
	}
}

ll id3(ll n, ll k, ll m) {
	if (k > n) return 0;
	if (k < 0) return 0;
	if (k == 0) return 1LL;
	ll v = (((fact[n] * invfact[k]) % m) * invfact[n - k]) % m;
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
	ll val = 0;

	LazyPart() {
	}

	LazyPart(ll aa) {
		val = aa;
	}

	LazyPart& operator=(const LazyPart& other) {
		val = other.val;
		return *this;
	}

	void reset() {
		val = 0;
	}
};

class LazyReal {
public:
	ll val;
	ll ind;

	LazyReal() {
		val = 0;
		ind = 0;
	}

	LazyReal(ll value, ll indx) {
		val = value;
		ind = indx;
	}

	LazyReal& operator=(const LazyReal& other) {
		val = other.val;
		ind = other.ind;
		return *this;
	}

	void reset() {
		val = ind = 0;
	}
};

class id8 {
public:
	vector<LazyReal> v;
	vector<LazyPart> z;
	LazyReal dummyReal;
	LazyPart dummyLazy;

	vb islazy;
	int n;
	LazyReal defval = dummyReal;

	id8() {

	}

	id8(int size) {
		n = 1;
		dummyReal.val = INFLL;
		dummyReal.ind = INFLL;
		dummyLazy.val = 0;
		while (n < size) n *= 2;
		v.resize(2 * n, dummyReal);
		z.resize(2 * n, dummyLazy);
		islazy.resize(2 * n, false);
	}

	id8(int size, LazyReal defReal, LazyPart deflazy) {
		n = 1;
		while (n < size) n *= 2;
		defval = defReal;
		v.resize(2 * n, defReal);
		z.resize(2 * n, deflazy);
		islazy.resize(2 * n, false);
	}

	

	

	

	LazyReal func(LazyReal& a, LazyReal& b) {
		LazyReal r = dummyReal;
		if (a.val <= b.val) {
			r.val = a.val;
			r.ind = a.ind;
		}
		else {
			r.val = b.val;
			r.ind = b.ind;
		}
		return r;
	}

	

	

	void applyLazy(LazyReal& a, LazyPart& b, int len) {
		a.val += b.val;
	}
	

	

	void passDownLazy(LazyPart& a, LazyPart& b) {
		a.val += b.val;
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
		

		int x = (upper_bound(dp.begin(), dp.end(), v[i]) - dp.begin());
		

		

		dp[x] = v[i];
	}
	return (lower_bound(dp.begin(), dp.end(), maxVal) - dp.begin());
}

vector<ll> primes;
void id6(int max_val) {
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

bool isPrime(ll n) {
	if (n == 1) return false;
	if (n <= primes.back()) {
		auto itr = lower_bound(all(primes), n);
		if ((*itr) == n) {
			return true;
		}
		else {
			return false;
		}
	}
	for (auto v : primes) {
		if (n % v == 0) return false;
		if (v * v > n) break;
	}
	return true;
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
	a %= m;
	if (d == 0) return 1LL;
	ll r = bigPow(a, d / 2, m);
	r = (r * r) % m;
	if ((d % 2) == 1)
		r = (r * a) % m;
	return r;
}

ll id10(ll n, ll k, ll m) {
	if (n == 0) return 1;
	if (k == 0) return 1;
	if (n < k) return 1;
	ll v = 1;
	ll p = 1;
	rep(i, 0, k) {
		v = (v * (n - i)) % m;
		p = (p * (i + 1)) % m;
	}
	p = modInverse(p, m);
	v = (v * p) % m;
	return v;
}

void findDiv(vpll& p, vll v, vll& divs) {
	ll val = 1;
	ll n = p.size();
	rep(i, 0, n) {
		rep(j, 0, v[i]) {
			val *= p[i].first;
		}
	}
	divs.push_back(val);
	v[0] ++;
	rep(i, 0, n - 1) {
		if (v[i] > p[i].second) {
			v[i + 1]++;
			v[i] = 0;
		}
	}
	if (v[n - 1] > p[n - 1].second)
		return;
	findDiv(p, v, divs);
}

void id2(ll n, vpll& p) {
	

	ll ps = primes.size();
	ll i = 0;
	if (n == 1) {
		p.emplace_back(1, 1);
		return;
	}
	while (n > 1 && i < ps) {
		if (n % primes[i] == 0) {
			ll d = 0;
			while (n % primes[i] == 0) {
				d++;
				n /= primes[i];
			}
			p.emplace_back(primes[i], d);
		}
		i++;
	}
	if (n > 1) {
		p.emplace_back(n, 1);
	}
}

void id7(ll n, vll& divs) {
	vpll p;
	id2(n, p);
	vll v(p.size(), 0);
	findDiv(p, v, divs);
}



bool cmp(pll p, pll q) {
	if (p.first / MOS_BLOCK != q.first / MOS_BLOCK)
		return p < q;
	return p.second < q.second;
}

void func_add(vll& mp, vll& a, ll ind, ll& sum) {
	ll tmp = mp[a[ind]];
	sum += (2 * tmp + 1) * a[ind];
	mp[a[ind]]++;
}
void func_minus(vll& mp, vll& a, ll ind, ll& sum) {
	ll tmp = mp[a[ind]];
	tmp--;
	sum -= (2 * tmp + 1) * a[ind];
	mp[a[ind]]--;
}

void id0(int test) {
	ll rd(n, t);
	vll rdv(a, n);
	vpll rdv(q, t);
	map<pll, vll> mpq;
	rep(i, 0, t) {
		q[i].first--;
		q[i].second--;
		mpq[q[i]].push_back(i);
	}
	vll mp(1001001, 0);
	sort(all(q), cmp);
	vll ans(t);
	ll l = 0, r = 0;
	mp[a[l]]++;
	ll sum = a[l];
	rep(i, 0, t) {
		while (l > q[i].first) {
			l--;
			func_add(mp, a, l, sum);
		}
		while (r < q[i].second) {
			r++;
			func_add(mp, a, r, sum);
		}
		while (r > q[i].second) {
			func_minus(mp, a, r, sum);
			r--;
		}
		while (l < q[i].first) {
			func_minus(mp, a, l, sum);
			l++;
		}
		for (auto inde : mpq[q[i]])
			ans[inde] = sum;
	}
	rep(i, 0, t) {
		cout << ans[i] << "\n";
	}
}


map<vll, ll> mem;
segmentTree<ll> s(2e5+1, my_max<ll>);
vll a;

ll func(map<ll, vll>& mp, int maxval, ll l, ll r) {
	if (l == r) return maxval;
	if (l > r) return 0LL;
	if (maxval < 1) return 0LL;
	vll p;
	p.push_back(l);
	p.push_back(r);
	p.push_back(maxval);
	if (mem.find(p)!=mem.end()) return mem[p];
	ll val = s.query(l, r);
	auto itr = lower_bound(all(mp[val]), l);
	ll pos = (*itr);
	ll ans = 0;
	vll tmp(maxval + 1, 0);
	for (ll i = maxval; i >0 ; i--) {
		ll v1 = 1,v2=1;
		if(l<pos) v1 = func(mp, i - 1, l, pos - 1) % MOD;
		if(r>pos) v2 = func(mp, i, pos + 1, r) % MOD;

		v1 = (v1 * v2) % MOD;
		tmp[i] = v1;
		ans = (ans + v1) % MOD;
	}
	ll sum = 0;
	rep(i, 1, maxval + 1) {
		sum = (sum + tmp[i]) % MOD;
		p[2] = i;
		mem[p] = sum;
	}
	return ans;
}


void solve(int test) {
	
	ll rd(n, m);
	a.resize(n);
	rep(i, 0, n) cin >> a[i];
	map<ll, vll> mp;
	mem.clear();
	
	rep(i, 0, n) {
		mp[a[i]].push_back(i);
		s.setNode(i, a[i]);
	}
	s.calculateTree();
	ll ans = func(mp,m,0,n-1);
	cout << ans << "\n";
}


int main() {
	

	

	

	ios::sync_with_stdio(0); cin.tie(0);
	int test = 1;
	cin >> test;
	for (int t = 1; t <= test; t++)
		solve(t);
	return 0;
}