



































using namespace std;
int gcd(int a, int b) {
	if (!b)return a;
	return gcd(b, a % b);
}
int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}
bool isprime(int n) {
	if (n == 1)return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)return false;
	}
	return true;
}
int mypow(int a, int b) {
	if (!b)return 1;
	if (b & 1)return mypow(a, b - 1) * a;
	int memo = mypow(a, b >> 1);
	return memo * memo;
}
int modpow(int a, int b, int m = mod) {
	if (!b)return 1;
	if (b & 1)return mypow(a, b - 1) * a % m;
	int memo = mypow(a, b / 2);
	return memo * memo % m;
}
class modInt {
	int value, modulo;
public:
	constexpr modInt() : value(0), modulo(mod) { value = 0; }
	template<typename T>
	constexpr modInt(T value = 0, int modulo = mod) : value(value), modulo(modulo) {
		this->value += T(modulo) * max((int)1, -value / modulo + 1);
		this->value %= T(modulo);
	}
	inline constexpr operator int()const { return value; }
	inline constexpr modInt& operator+=(modInt x) {
		value += x.value;
		if (value >= modulo)value -= modulo;
		return *this;
	}
	inline constexpr modInt& operator++() {
		if (value == modulo - 1)value = 0;
		else value++;
		return *this;
	}
	inline constexpr modInt& operator-()const {
		return modInt(0) -= *this;
	}
	inline constexpr modInt& operator-=(modInt x) {
		value -= x.value;
		if (value < 0)value += modulo;
		return *this;
	}
	inline constexpr modInt& operator--() {
		if (value == 0)value = modulo - 1;
		else value--;
		return *this;
	}
	inline constexpr modInt& operator*=(modInt x) {
		value = value * x.value % mod;
		return *this;
	}
	inline modInt& operator/=(modInt x) {
		return operator*=(x.inv());
	}
	static modInt pow(modInt x, int y) {
		if (!y)return 1;
		if (y & 1)return pow(x, y - 1) * x;
		modInt memo = pow(x, y / 2);
		return memo * memo;
	}
	inline modInt inv() {
		return pow(*this, modulo - 2);
	}
	template<typename T> modInt operator+(T x) { return modInt(*this) += x; }
	template<typename T> modInt& operator+=(T x) { return operator+=(modInt(x)); }
	template<typename T> modInt operator-(T x) { return modInt(*this) -= x; }
	template<typename T> modInt& operator-=(T x) { return operator-=(modInt(x)); }
	template<typename T> modInt operator*(T x) { return modInt(*this) *= x; }
	template<typename T> modInt& operator*=(T x) { return operator*=(modInt(x)); }
	template<typename T> modInt operator/(T x) { return modInt(*this) /= x; }
	template<typename T> modInt& operator/=(T x) { return operator/=(modInt(x)); }
};
istream& operator>>(istream& ist, modInt& x) {
	int a;
	ist >> a;
	x = a;
	return ist;
}
int modpow(modInt a, int b, int m = mod) {
	if (!b)return modInt(1);
	if (b & 1)return mypow(a, b - 1) * a % m;
	modInt memo = mypow(a, b / 2);
	return memo * memo;
}
class UnionFind {
protected:
	int* par, * rank, * size;
public:
	UnionFind(unsigned int size) {
		par = new int[size];
		rank = new int[size];
		this->size = new int[size];
		rep(i, size) {
			par[i] = i;
			rank[i] = 0;
			this->size[i] = 1;
		}
	}
	int find(int n) {
		if (par[n] == n)return n;
		return par[n] = find(par[n]);
	}
	void unite(int n, int m) {
		n = find(n);
		m = find(m);
		if (n == m)return;
		if (rank[n] < rank[m]) {
			par[n] = m;
			size[m] += size[n];
		}
		else {
			par[m] = n;
			size[n] += size[m];
			if (rank[n] == rank[m])rank[n]++;
		}
	}
	bool same(int n, int m) {
		return find(n) == find(m);
	}
	int getsize(int n) {
		return size[find(n)];
	}
};
class id4 :UnionFind {
	P* notparent;
	vector<P>* sizevec;
	int opcount = 0;
public:
	id4(unsigned int size) :UnionFind(size) {
		this->sizevec = new vector<P>[size];
		notparent = new P[size];
		rep(i, size) {
			par[i] = i;
			rank[i] = 0;
			sizevec[i].push_back(make_pair(-1, 1));
			notparent[i] = make_pair(INF, i);
		}
	}
	int find(int n, int t = INF) {
		if (opcount <= t) {
			if (par[n] == n)return n;
			return par[n] = find(par[n]);
		}
		if (notparent[n].first <= t)return find(notparent[n].second, t);
		return n;
	}
	void unite(int n, int m) {
		n = find(n);
		m = find(m);
		if (n == m) {
			opcount++;
			return;
		}
		if (rank[n] < rank[m]) {
			par[n] = m;
			notparent[n] = make_pair(opcount, m);
			sizevec[m].push_back(make_pair(opcount, sizevec[m].back().second + sizevec[n].back().second));
		}
		else {
			par[m] = n;
			notparent[m] = make_pair(opcount, n);
			sizevec[n].push_back(make_pair(opcount, sizevec[n].back().second + sizevec[m].back().second));
			if (rank[n] == rank[m])rank[n]++;
		}
		opcount++;
	}
	bool same(int n, int m, int t = INF) {
		return find(n, t) == find(m, t);
	}
	int getsize(int n, int t = INF) {
		n = find(n, t);
		auto ite = lower_bound(sizevec[n].begin(), sizevec[n].end(), make_pair(t, (int)0));
		if (ite == sizevec[n].end())ite--;
		if (t < (*ite).first)ite--;
		return (*ite).second;
	}
};
class RollingHash {
	string s;
	int n, m;
	modInt base;
	deque<modInt> has;
public:
	RollingHash(string s, int m, int b) : n(s.size()), m(m), base(b, m) { init(s, m, b); }
	void init(string s, int m, int b) {
		n = s.size();
		has.resize(n);
		base = b;
		this->s = s;
		this->m = m;
		rep(i, n) {
			has[i] = (int)s[i];
			if (i)has[i] += base * has[i - 1] % m;
		}
	}
	operator int() const {
		return has.back();
	}
	void cut(int a, int b) {
		assert(!(a >= b || a < 0 || n < b));
		rep(i, a)has.pop_front();
		rep(i, n - b)has.pop_back();
		s = s.substr(a, b);
		modInt memo = mypow(mypow(base, n - b), m - 2);
		rep(i, b - a)has[i] *= memo;
		n = b - a;
	}
	int query(int a, int b) {
		assert(!(a >= b || a < 0 || n < b));
		return has[b - 1] - mypow(base, b - a) * (!a ? modInt(0) : has[a - 1]);
	}
	int operator+(RollingHash t) {
		assert(m == t.m && base == t.base);
		return (has[n - 1] * mypow(base, t.n) % m + t.has[t.n - 1]) % m;
	}
	RollingHash& operator+=(string t) {
		s += t;
		has.resize(n + t.size());
		for (int i = n; i < n + t.size(); i++) {
			has[i] = (int)t[i] * base;
			has[i] += base * has[i - 1];
		}
		n += t.size();
		return *this;
	}
};
template<typename T, typename U>
class SegTree {
	int n = 1;
	T* node = NULL;
	U* lazy = NULL;
	bool* lazyflag = NULL;
	T nodee;
	function<T(T, T)> nodef;
	function<U(U, U)> lazyf;
	function<T(int, T, U)> updf;
	void eval(int k, int l, int r) {
		if (lazyflag[k]) {
			node[k] = updf(r - l, node[k], lazy[k]);
			if (r - l > 1) {
				lazyflag[2 * k + 1] = lazyflag[2 * k + 2] = true;
				lazy[2 * k + 1] = lazyf(lazy[2 * k + 1], lazy[k]);
				lazy[2 * k + 2] = lazyf(lazy[2 * k + 2], lazy[k]);
			}
			lazyflag[k] = false;
		}
	}
public:
	SegTree(int m, int init, T nodee, function<T(T, T)> nodef, function<U(U, U)> lazyf, function<T(int, T, U)> updf) :nodee(nodee), nodef(nodef), lazyf(lazyf), updf(updf) {
		delete[] node;
		delete[] lazy;
		while (n < m)n *= 2;
		node = new T[2 * n], lazy = new U[2 * n], lazyflag = new bool[2 * n];
		rep(i, 2 * n) {
			node[i] = init;
			lazyflag[i] = false;
		}
	}
	~SegTree() {
		delete[] node;
		delete[] lazy;
	}
	void update(int a, int b, U x, int k = 0, int l = 0, int r = -1) {
		if (r == -1)r = n;
		eval(k, l, r);
		if (b <= l || r <= a)return;
		if (a <= l && r <= b) {
			lazyflag[k] = true;
			lazy[k] = x;
			eval(k, l, r);
		}
		else {
			update(a, b, x, 2 * k + 1, l, (l + r) / 2);
			update(a, b, x, 2 * k + 2, (l + r) / 2, r);
			node[k] = nodef(node[2 * k + 1], node[2 * k + 2]);
		}
	}
	T query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r == -1)r = n;
		eval(k, l, r);
		if (b <= l || r <= a)return nodee;
		if (a <= l && r <= b)return node[k];
		T vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
		T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
		return nodef(vl, vr);
	}
};
template<typename T>
class id1 :public SegTree<T, T> {
	using base = SegTree<T, T>;
public:
	id1(int size, const T& def = T()) :base(size, def, T(), [](T a, T b) {return a + b; }, [](T a, T b) {return a + b; }, [](int range, T a, T b) {return a + range * b; }) {};
};
template<typename T>
class id3 :public SegTree<T, T> {
	using base = SegTree<T, T>;
public:
	id3(int size, const T& def = T()) :base(size, def, T(), [](T a, T b) {return min(a, b); }, [](T a, T b) {return a + b; }, [](int range, T a, T b) {return a + b; }) {};
};
template<typename T>
class id2 :public SegTree<T, T> {
	using base = SegTree<T, T>;
public:
	id2(int size, const T& def = T()) :base(size, def, T(), [](T a, T b) {return a + b; }, [](T a, T b) {return b; }, [](int range, T a, T b) {return range * b; }) {};
};
template<typename T>
class id0 :public SegTree<T, T> {
	using base = SegTree<T, T>;
public:
	id0(int size, const T& def = T()) :base(size, def, T(), [](T a, T b) {return min(a, b); }, [](T a, T b) {return b; }, [](int range, T a, T b) {return b; }) {};
};
template<typename T>
class BIT {
	int n;
	T* bit;
public:
	BIT(int n) :n(n) {
		bit = new T[n];
		fill(bit, bit + n, T());
	}
	void add(int a, T x) {
		while (a < n) {
			bit[a] += x;
			a += a & -a;
		}
	}
	T query(int a) {
		int cnt = 0;
		while (a > 0) {
			cnt += bit[a];
			a -= a & -a;
		}
		return cnt;
	}
};
template<typename T>
class Matrix {
	int n;
	T zero, e;
	vector<vector<T>> vec;
	void letmeasure() {
		rep(i, n) {
			rep(j, n) {
				if (i != j)vec[i][j] = zero;
				else vec[i][j] = e;
			}
		}
	}
public:
	Matrix(int n, T zero, T e) :n(n), zero(zero), e(e) {
		vec.resize(n, vector<T>(n));
	}
	Matrix(int n, T zero, T e, vector<int> vec) :n(n), zero(zero), e(e) {
		if (vec.size() != n * n) {
			cerr << "Invalid construct of matrix" << endl;
			exit(1);
		}
		this->vec.resize(n, vector<T>(n));
		rep(i, n) {
			rep(j, n)this->vec[i][j] = vec[i * n + j];
		}
	}
	T& operator[](int a) {
		return vec[a / n][a % n];
	}
	unsigned int size() { return n; }
	Matrix operator*(const Matrix a) {
		if (this->n != a.n) {
			cerr << "Invalid multiply of matrix" << endl;
			exit(1);
		}
		vector<T> memo(n);
		rep(i, n) {
			rep(j, n) {
				rep(k, n) {
					memo[j] += vec[i][k] * a.vec[k][j];
				}
			}
			vec[i] = memo;
			memo.clear();
			memo.resize(n);
		}
		return *this;
	}
	static Matrix<T> measure(int n, T zero, T e) {
		Matrix<T> res(n, zero, e);
		res.letmeasure();
		return res;
	}
};
class mycomplex {
	double realvalue, imagvalue;
public:
	mycomplex() :realvalue(0), imagvalue(0) {}
	mycomplex(double realvalue, double imagvalue) : realvalue(realvalue), imagvalue(imagvalue) {}
	mycomplex(double realvalue) : realvalue(realvalue), imagvalue(0) {}
	mycomplex(complex<double> c) :realvalue(c.real()), imagvalue(c.imag()) {}
	mycomplex(const mycomplex& rhs) :realvalue(rhs.realvalue), imagvalue(rhs.imagvalue) {}
	double real()const { return this->realvalue; }
	double imag()const { return this->imagvalue; }
	double abs() { return hypot(realvalue, imagvalue); }
	mycomplex& operator=(const mycomplex& obj) {
		if (this != &obj) {
			this->realvalue = obj.realvalue;
			this->imagvalue = obj.imagvalue;
		}
		return *this;
	}
	mycomplex& operator=(mycomplex&& obj)noexcept {
		if (this != &obj) {
			this->realvalue = exchange(obj.realvalue, 0);
			this->imagvalue = exchange(obj.imagvalue, 0);
		}
		return *this;
	}
	mycomplex& operator+=(const mycomplex& rhs) {
		this->realvalue += rhs.realvalue;
		this->imagvalue += rhs.imagvalue;
		return *this;
	}
	friend mycomplex operator+(mycomplex lhs, const mycomplex& rhs) {
		lhs += rhs;
		return lhs;
	}
	mycomplex& operator-=(const mycomplex& rhs) {
		this->realvalue -= rhs.realvalue;
		this->imagvalue -= rhs.imagvalue;
		return *this;
	}
	mycomplex& operator-=(const double& rhs) {
		this->realvalue -= rhs;
		return *this;
	}
	friend mycomplex operator-(mycomplex lhs, const mycomplex& rhs) {
		lhs -= rhs;
		return lhs;
	}
	mycomplex& operator*=(const mycomplex& rhs) {
		double pastreal = this->realvalue;
		this->realvalue = this->realvalue * rhs.realvalue - this->imagvalue * rhs.imagvalue;
		this->imagvalue = pastreal * rhs.imagvalue + rhs.realvalue * this->imagvalue;
		return *this;
	}
	friend mycomplex operator*(mycomplex lhs, const mycomplex& rhs) {
		lhs *= rhs;
		return lhs;
	}
	mycomplex& operator/=(const mycomplex& rhs) {
		*this *= mycomplex(rhs.real(), -rhs.imag());
		double dnm = rhs.real() * rhs.real() - rhs.imag() * rhs.imag();
		this->realvalue /= dnm;
		this->imagvalue /= dnm;
		return *this;
	}
	friend mycomplex operator/(mycomplex lhs, const mycomplex& rhs) {
		lhs /= rhs;
		return lhs;
	}
};
class FastFourierTransform {
private:
	static void dft(vector<mycomplex>& func, int inverse) {
		int sz = func.size();
		if (sz == 1)return;
		vector<mycomplex> veca, vecb;
		rep(i, sz / 2) {
			veca.push_back(func[2 * i]);
			vecb.push_back(func[2 * i + 1]);
		}
		dft(veca, inverse); dft(vecb, inverse);
		mycomplex now = 1, zeta = polar(1.0, inverse * 2.0 * acos(-1) / sz);
		rep(i, sz) {
			func[i] = veca[i % (sz / 2)] + now * vecb[i % (sz / 2)];
			now *= zeta;
		}
	}
public:
	template<typename T>
	static vector<double> multiply(vector<T> f, vector<T> g) {
		vector<mycomplex> nf, ng;
		int sz = 1;
		while (sz < f.size() + g.size())sz *= 2;
		nf.resize(sz); ng.resize(sz);
		rep(i, f.size()) {
			nf[i] = f[i];
			ng[i] = g[i];
		}
		dft(nf, 1);
		dft(ng, 1);
		rep(i, sz)nf[i] *= ng[i];
		dft(nf, -1);
		vector<double> res;
		rep(i, sz)res.push_back(nf[i].real() / sz);
		return res;
	}
};
int t, n, s, a[100010];
signed main() {
	cin >> t;
	rep(i, t) {
		cin >> n >> s;
		rep(j, n){
			cin >> a[j];
			if (j)a[j] += a[j - 1];
		}
		if (a[n - 1] <= s) {
			cout << 0 << endl;
			continue;
		}
		int ans = 0, now;
		rep(j, n) {
			int cnt = s;
			if (j)cnt -= a[j - 1];
			if (cnt < 0)break;
			int mi = j, ma = n;
			while (mi + 1 < ma) {
				int md = (mi + ma) / 2;
				if (a[md] - a[j] <= cnt)mi = md;
				else ma = md;
			}
			if (ans < mi) {
				ans = mi;
				now = j;
			}
		}
		rep(j, n) {
			if (a[j] > s) {
				if (ans <= j) {
					cout << 0 << endl;
					goto kaage;
				}
				else break;
			}
		}
		cout << now + 1 << endl;
	kaage:;
	}
	return 0;
}
