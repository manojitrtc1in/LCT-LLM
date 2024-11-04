
using namespace std;




template<typename T>
struct id8{
	using Type = typename decay<decltype(T::value)>::type;
	static vector<Type> MOD_INV;
	constexpr id8(): value(){ }
	template<typename U> id8(const U &x){ value = normalize(x); }
	template<typename U> static Type normalize(const U &x){
		Type v;
		if(-mod() <= x && x < mod()) v = static_cast<Type>(x);
		else v = static_cast<Type>(x % mod());
		if(v < 0) v += mod();
		return v;
	}
	const Type& operator()() const{ return value; }
	template<typename U> explicit operator U() const{ return static_cast<U>(value); }
	constexpr static Type mod(){ return T::value; }
	id8 &operator+=(const id8 &otr){ if((value += otr.value) >= mod()) value -= mod(); return *this; }
	id8 &operator-=(const id8 &otr){ if((value -= otr.value) < 0) value += mod(); return *this; }
	template<typename U> id8 &operator+=(const U &otr){ return *this += id8(otr); }
	template<typename U> id8 &operator-=(const U &otr){ return *this -= id8(otr); }
	id8 &operator++(){ return *this += 1; }
	id8 &operator--(){ return *this -= 1; }
	id8 operator++(int){ id8 result(*this); *this += 1; return result; }
	id8 operator--(int){ id8 result(*this); *this -= 1; return result; }
	id8 operator-() const{ return id8(-value); }
	template<typename U = T>
	typename enable_if<is_same<typename id8<U>::Type, int>::value, id8>::type &operator*=(const id8& rhs){
		
		uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
		uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
		asm(
			"divl %4; \n\t"
			: "=a" (d), "=d" (m)
			: "d" (xh), "a" (xl), "r" (mod())
		);
		value = m;
		
		value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
		
		return *this;
	}
	template<typename U = T>
	typename enable_if<is_same<typename id8<U>::Type, int64_t>::value, id8>::type &operator*=(const id8 &rhs){
		int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
		value = normalize(value * rhs.value - q * mod());
		return *this;
	}
	template<typename U = T>
	typename enable_if<!is_integral<typename id8<U>::Type>::value, id8>::type &operator*=(const id8 &rhs){
		value = normalize(value * rhs.value);
		return *this;
	}
	template<typename U>
	id8 &operator^=(U e){
		if(e < 0) *this = 1 / *this, e = -e;
		id8 res = 1;
		for(; e; *this *= *this, e >>= 1) if(e & 1) res *= *this;
		return *this = res;
	}
	template<typename U>
	id8 operator^(U e) const{
		return id8(*this) ^= e;
	}
	id8 &operator/=(const id8 &otr){
		Type a = otr.value, m = mod(), u = 0, v = 1;
		if(a < (int)MOD_INV.size()) return *this *= MOD_INV[a];
		while(a){
			Type t = m / a;
			m -= t * a; swap(a, m);
			u -= t * v; swap(u, v);
		}
		assert(m == 1);
		return *this *= u;
	}
	template<typename U> friend const id8<U> &abs(const id8<U> &v){ return v; }
	Type value;
};
template<typename T> bool operator==(const id8<T> &lhs, const id8<T> &rhs){ return lhs.value == rhs.value; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(const id8<T>& lhs, U rhs){ return lhs == id8<T>(rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(U lhs, const id8<T> &rhs){ return id8<T>(lhs) == rhs; }
template<typename T> bool operator!=(const id8<T> &lhs, const id8<T> &rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(const id8<T> &lhs, U rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(U lhs, const id8<T> &rhs){ return !(lhs == rhs); }
template<typename T> bool operator<(const id8<T> &lhs, const id8<T> &rhs){ return lhs.value < rhs.value; }
template<typename T> bool operator>(const id8<T> &lhs, const id8<T> &rhs){ return lhs.value > rhs.value; }
template<typename T> bool operator<=(const id8<T> &lhs, const id8<T> &rhs){ return lhs.value <= rhs.value; }
template<typename T> bool operator>=(const id8<T> &lhs, const id8<T> &rhs){ return lhs.value >= rhs.value; }
template<typename T> id8<T> operator+(const id8<T> &lhs, const id8<T> &rhs){ return id8<T>(lhs) += rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> id8<T> operator+(const id8<T> &lhs, U rhs){ return id8<T>(lhs) += rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> id8<T> operator+(U lhs, const id8<T> &rhs){ return id8<T>(lhs) += rhs; }
template<typename T> id8<T> operator-(const id8<T> &lhs, const id8<T> &rhs){ return id8<T>(lhs) -= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> id8<T> operator-(const id8<T>& lhs, U rhs){ return id8<T>(lhs) -= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> id8<T> operator-(U lhs, const id8<T> &rhs){ return id8<T>(lhs) -= rhs; }
template<typename T> id8<T> operator*(const id8<T> &lhs, const id8<T> &rhs){ return id8<T>(lhs) *= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> id8<T> operator*(const id8<T>& lhs, U rhs){ return id8<T>(lhs) *= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> id8<T> operator*(U lhs, const id8<T> &rhs){ return id8<T>(lhs) *= rhs; }
template<typename T> id8<T> operator/(const id8<T> &lhs, const id8<T> &rhs) { return id8<T>(lhs) /= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> id8<T> operator/(const id8<T>& lhs, U rhs) { return id8<T>(lhs) /= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> id8<T> operator/(U lhs, const id8<T> &rhs) { return id8<T>(lhs) /= rhs; }
template<typename T> istream &operator>>(istream &in, id8<T> &number){
	typename common_type<typename id8<T>::Type, int64_t>::type x;
	in >> x;
	number.value = id8<T>::normalize(x);
	return in;
}
template<typename T> ostream &operator<<(ostream &out, const id8<T> &number){ return out << number(); }

constexpr int mod = 1e9 + 7; 





using modular = id8<integral_constant<decay<decltype(mod)>::type, mod>>;
template<typename T> vector<typename id8<T>::Type> id8<T>::MOD_INV;
template<typename T = integral_constant<decay<decltype(mod)>::type, mod>>
void id4(int SZ){
	auto &inv = id8<T>::MOD_INV;
	if(inv.empty()) inv.assign(2, 1);
	for(; inv.size() <= SZ; ) inv.push_back((mod - 1LL * mod / (int)inv.size() * inv[mod % (int)inv.size()]) % mod);
}
template<typename T>
vector<T> id1(T base, int SZ){
	vector<T> res(SZ + 1, 1);
	for(auto i = 1; i <= SZ; ++ i) res[i] = res[i - 1] * base;
	return res;
}



void id9(vector<complex<double>> &a, bool invert = false){
	int n = (int)a.size();
	static vector<complex<double>> root(2, 1);
	static vector<complex<long double>> root_ld(2, 1);
	for(static int k = 2; k < n; k <<= 1){
		root.resize(n), root_ld.resize(n);
		auto theta = polar(1.0L, acos(-1.0L) / k);
		for(auto i = k; i < k << 1; ++ i) root[i] = root_ld[i] = i & 1 ? root_ld[i >> 1] * theta : root_ld[i >> 1];
	}
	for(auto i = 1, j = 0; i < n; ++ i){
		int bit = n >> 1;
		for(; j & bit; bit >>= 1) j ^= bit;
		j ^= bit;
		if(i < j) swap(a[i], a[j]);
	}
	for(auto k = 1; k < n; k <<= 1) for(auto i = 0; i < n; i += k << 1) for(auto j = 0; j < k; ++ j){
		auto x = (double *)&root[j + k], y = (double *)&a[i + j + k];
		complex<double> z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);
		a[i + j + k] = a[i + j] - z, a[i + j] += z;
	}
	if(invert){
		reverse(a.begin() + 1, a.end());
		auto inv_n = 1.0 / n;
		for(auto &x: a) x *= inv_n;
	}
}







template<class T>
vector<T> id0(const vector<T> &p, const vector<T> &q){
	if(min(p.size(), q.size()) < 150){
		vector<T> res((int)p.size() + (int)q.size() - 1);
		for(auto i = 0; i < p.size(); ++ i) for(auto j = 0; j < q.size(); ++ j) res[i + j] += p[i] * q[j];
		return res;
	}
	int n = 1 << __lg((int)p.size() + (int)q.size() - 1) + 1;
	vector<complex<double>> L(n), R(n), outL(n), outR(n);
	const int cut = 32000;
	for(auto i = 0; i < (int)p.size(); ++ i) L[i] = {p[i].value / cut, p[i].value % cut};
	for(auto i = 0; i < (int)q.size(); ++ i) R[i] = {q[i].value / cut, q[i].value % cut};
	id9(L), id9(R);
	for(auto i = 0; i < n; ++ i){
		int j = -i & n - 1;
		outL[i] = (L[i] + conj(L[j])) * R[i] / 2.0;
		outR[i] = (L[i] - conj(L[j])) * R[i] / 2i;
	}
	id9(outL, true), id9(outR, true);
	vector<T> res((int)p.size() + (int)q.size() - 1);
	for(auto i = 0; i < (int)res.size(); ++ i){
		res[i] = ((T)(long long)round(outL[i].real()) * cut + (T)(long long)(round(outL[i].imag()) + round(outR[i].real()))) * cut + (T)(long long)round(outR[i].imag());
	}
	return res;
}































template<class T>
vector<T> operator*(const vector<T> &p, const vector<T> &q){
	return id0(p, q);
}


















template<class T>
vector<T> &operator*=(vector<T> &a, const vector<T> &b){
	return a = a * b;
}
template<class T, class U>
vector<T> &operator*=(vector<T> &a, U x){
	for(auto &c: a) c *= x;
	return a;
}
template<class T, class U>
vector<T> operator*(const vector<T> &a, U x){
	vector<T> b = a;
	return b *= x;
}
template<class T, class U>
vector<T> operator*(U x, const vector<T> &a){
	vector<T> b = a;
	return b *= x;
}
template<class T>
vector<T> &operator+=(vector<T> &a, const vector<T> &b){
	if(a.size() < b.size()) a.resize(b.size());
	for(auto i = 0; i < (int)b.size(); ++ i) a[i] += b[i];
	return a;
}
template<class T>
vector<T> operator+(const vector<T> &a, const vector<T> &b){
	vector<T> c = a;
	return c += b;
}
template<class T>
vector<T> &operator-=(vector<T> &a, const vector<T> &b){
	if(a.size() < b.size()) a.resize(b.size());
	for(auto i = 0; i < (int)b.size(); ++ i) a[i] -= b[i];
	return a;
}
template<class T>
vector<T> operator-(const vector<T> &a, const vector<T> &b){
	vector<T> c = a;
	return c -= b;
}
template<class T>
vector<T> operator-(const vector<T> &a){
	vector<T> c = a;
	for(auto i = 0; i < (int)c.size(); ++ i) c[i] = -c[i];
	return c;
}
template<class T>
vector<T> inverse(vector<T> a){
	assert(!a.empty());
	int n = (int)a.size();
	while(!a.empty() && a.back().value == 0) a.pop_back(); 

	vector<T> b = {1 / a[0]};
	while((int)b.size() < n){
		vector<T> a_cut(a.begin(), a.begin() + min(a.size(), b.size() << 1)), x = b * b * a_cut;
		b.resize(b.size() << 1);
		for(auto i = (int)b.size() >> 1; i < (int)min(x.size(), b.size()); ++ i) b[i] = -x[i];
	}
	b.resize(n);
	return b;
}
template<class T>
vector<T> &operator/=(vector<T> &a, const vector<T> &b){
	int n = (int)a.size(), m = (int)b.size();
	if(n < m) a.clear();
	else{
		vector<T> d = b;
		reverse(a.begin(), a.end());
		reverse(d.begin(), d.end());
		d.resize(n - m + 1);
		a *= inverse(d);
		a.erase(a.begin() + n - m + 1, a.end());
		reverse(a.begin(), a.end());
	}
	return a;
}
template<class T>
vector<T> operator/(const vector<T> &a, const vector<T> &b){
	vector<T> c = a;
	return c /= b;
}
template<class T>
vector<T> &operator/=(vector<T> &a, T x){
	T inv_x = 1 / x;
	for(auto &c: a) c *= inv_x;
	return a;
}
template<class T>
vector<T> operator/(const vector<T> &a, T x){
	vector<T> b = a;
	return b /= x;
}
template<class T>
vector<T> &operator%=(vector<T> &a, const vector<T> &b){
	int n = (int)a.size(), m = (int)b.size();
	if(n >= m){
		vector<T> c = (a / b) * b;
		a.resize(m - 1);
		for(auto i = 0; i < m - 1; ++ i) a[i] -= c[i];
	}
	return a;
}
template<class T>
vector<T> operator%(const vector<T> &a, const vector<T> &b){
	vector<T> c = a;
	return c %= b;
}
template<class T>
vector<T> derivative(const vector<T> &a){
	vector<T> c = a;
	for(auto i = 0; i < (int)c.size(); ++ i) c[i] *= i;
	if(!c.empty()) c.erase(c.begin());
	return c;
}
template<class T>
vector<T> id6(const vector<T> &a){
	vector<T> c = a;
	c.insert(c.begin(), 0);
	for(auto i = 1; i < (int)c.size(); ++ i) c[i] /= i;
	return c;
}
template<class T>
vector<T> id2(const vector<T> &a){
	assert(!a.empty() && a[0] == 1);
	vector<T> u = id6(derivative(a) * inverse(a));
	u.resize(a.size());
	return u;
}
template<class T>
vector<T> exponential(const vector<T> &a){
	assert(!a.empty() && a[0] == 0);
	int n = (int)a.size();
	vector<T> b = {1};
	while((int)b.size() < n){
		vector<T> x(a.begin(), a.begin() + min(a.size(), b.size() << 1));
		x[0] += 1;
		vector<T> old_b = b;
		b.resize(b.size() << 1);
		x -= id2(b);
		x *= old_b;
		for(auto i = (int)b.size() >> 1; i < (int)min(x.size(), b.size()); ++ i) b[i] = x[i];
	}
	b.resize(n);
	return b;
}
template<class T, class U>
vector<T> &operator^=(vector<T> &a, U e){
	int n = (int)a.size();
	if(!e){
		fill(a.begin(), a.end(), 0);
		a[0] = 1;
		return a;
	}
	if(all_of(a.begin(), a.end(), [&](auto x){ return x == 0; })) return a = vector<T>(n, 0);
	if(n < 60){
		vector<T> res(n); res[0] = 1;
		for(; e; e >>= 1, a *= a, a.resize(n)) if(e & 1) res *= a, res.resize(n);
		swap(a, res);
		return a;
	}
	int low = find_if(a.begin(), a.end(), [&](auto x){ return x; }) - a.begin();
	if(1LL * low * e >= n) return a = vector<T>(n, 0);
	a.erase(a.begin(), a.begin() + low);
	T temp = a[0], low_c = 1;
	for(auto f = e; f; f >>= 1, temp *= temp) if(f & 1) low_c *= temp;
	a = exponential(T(e) * id2(a / a[0]));
	a.insert(a.begin(), low * e, 0);
	a.resize(n);
	return a *= low_c;
}
template<class T, class U>
vector<T> operator^(const vector<T> &a, U e){
	vector<T> b = a;
	return b ^= e;
}
template<class T>
vector<T> multiply_all(const vector<vector<T>> &a){
	if(a.empty()) return {0};
	auto solve = [&](auto self, int l, int r)->vector<T>{
		if(r - l == 1) return a[l];
		int m = l + (r - l >> 1);
		return self(self, l, m) * self(self, m, r);
	};
	return solve(solve, 0, (int)a.size());
}
template<class T, class U>
T evaluate(const vector<T> &a, U x){
	T res = {};
	for(auto i = (int)a.size() - 1; i >= 0; -- i) res = res * x + a[i];
	return res;
}


template<class T>
vector<T> interpolation(const vector<T> &x, const vector<T> &y){
	assert(x.size() == y.size());
	if(x.empty()) return { };
	int n = (int)x.size();
	vector<vector<T>> st((n << 1) - 1);
	auto build = [&](auto self, int u, int l, int r)->void{
		if(r - l == 1) st[u] = vector<T>{-x[l], 1};
		else{
			int m = l + (r - l >> 1), v = u + (m - l << 1);
			self(self, u + 1, l, m), self(self, v, m, r);
			st[u] = st[u + 1] * st[v];
		}
	};
	build(build, 0, 0, n);
	vector<T> m = st[0], dm = derivative(m), val(n);
	auto eval = [&](auto self, int u, int l, int r, vector<T> f)->void{
		f %= st[u];
		if((int)f.size() < 150){
			for(auto i = l; i < r; ++ i) val[i] = evaluate(f, x[i]);
			return;
		}
		if(r - l == 1) val[l] = f[0];
		else{
			int m = l + (r - l >> 1), v = u + (m - l << 1);
			self(self, u + 1, l, m, f), self(self, v, m, r, f);
		}
	};
	eval(eval, 0, 0, n, dm);
	for(auto i = 0; i < n; ++ i) val[i] = y[i] / val[i];
	auto calc = [&](auto self, int u, int l, int r)->vector<T>{
		if(r - l == 1) return vector<T>{val[l]};
		int m = l + (r - l >> 1), v = u + (m - l << 1);
		return self(self, u + 1, l, m) * st[v] + self(self, v, m, r) * st[u + 1];
	};
	return calc(calc, 0, 0, n);
}


template<class T>
vector<T> id10(const vector<T> &a, const vector<T> &x){
	if(x.empty()) return {};
	if(a.empty()) return vector<T>(x.size(), 0);
	int n = (int)x.size();
	vector<vector<T>> st((n << 1) - 1);
	auto build = [&](auto self, int u, int l, int r)->void{
		if(r - l == 1) st[u] = vector<T>{-x[l], 1};
		else{
			int m = l + (r - l >> 1), v = u + (m - l << 1);
			self(self, u + 1, l, m), self(self, v, m, r);
			st[u] = st[u + 1] * st[v];
		}
	};
	build(build, 0, 0, n);
	vector<T> res(n);
	auto eval = [&](auto self, int u, int l, int r, vector<T> f)->void{
		f %= st[u];
		if((int)f.size() < 150){
			for(auto i = l; i < r; ++ i) res[i] = evaluate(f, x[i]);
			return;
		}
		if(r - l == 1) res[l] = f[0];
		else{
			int m = l + (r - l >> 1), v = u + (m - l << 1);
			self(self, u + 1, l, m, f), self(self, v, m, r, f);
		}
	};
	eval(eval, 0, 0, n, a);
	return res;
}
template<class T>
struct id7{
	const vector<T> a;
	vector<T> b, c;
	id7(const vector<T> &a): a(a){ }
	T add(const T &val){
		int i = (int)b.size();
		b.push_back(val);
		if((int)c.size() <= i) c.resize(i + 1);
		c[i] += a[0] * b[i];
		int z = 1;
		while((i & z - 1) == z - 1 && (int)a.size() > z){
			vector<T> a_mul(a.begin() + z, a.begin() + min(z << 1, (int)a.size()));
			vector<T> b_mul(b.end() - z, b.end());
			vector<T> c_mul = a_mul * b_mul;
			if((int)c.size() <= i + (int)c_mul.size()) c.resize(i + c_mul.size() + 1);
			for(auto j = 0; j < (int)c_mul.size(); ++ j) c[i + 1 + j] += c_mul[j];
			z <<= 1;
		}
		return c[i];
	}
};


template<class T>
vector<T> id3(const vector<T> &a){
	assert(!a.empty() && a[0] == 1);
	int n = (int)a.size();
	vector<T> b = {1};
	while((int)b.size() < n){
		vector<T> x(a.begin(), a.begin() + min(a.size(), b.size() << 1));
		b.resize(b.size() << 1);
		x *= inverse(b);
		T inv2 = 1 / static_cast<T>(2);
		for(auto i = (int)b.size() >> 1; i < (int)min(x.size(), b.size()); ++ i) b[i] = x[i] * inv2;
	}
	b.resize(n);
	return b;
}
template<class T>
pair<vector<T>, vector<T> > id11(vector<T> A, const vector<T> &B) { 

	vector<T> res;
	while(A.size() >= B.size()) {
		res.push_back(A.back() / B.back());
		if (res.back() != (T)0)
			for(int i=0; i<B.size(); i++)
				A[A.size()-i-1] -= res.back() * B[B.size()-i-1];
		A.pop_back();
	}
	reverse(res.begin(), res.end());
	return {res, A};
}


ll fa[3000004], ifa[3000004];
ll pw(ll a, ll n)
{
	ll ret = 1;
	while(n)
	{
		if (n&1) ret=ret*a%MOD;
		a=a*a%MOD;
		n>>=1;
	}
	return ret;
}
ll inv(ll a)
{
	return pw(a, MOD-2);
}
ll C(ll n, ll r)
{
	if (n < 0 || r < 0 || r > n) return 0LL;
	return fa[n]*ifa[r]%MOD*ifa[n-r]%MOD;
}
void id5(int n)
{
	fa[0] = 1;
	for(int i=1; i<=n; i++)
		fa[i] = fa[i-1] * i % MOD;
	ifa[n] = inv(fa[n]);
	for(int i=n-1; i>=0; i--)
		ifa[i] = ifa[i+1] * (i+1) % MOD;
}

int N, Q;

int main()
{
	

	id5(3000003);
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cin >> N >> Q;
	vector<modular> v(3*N+4);
	for(int i=0; i<=3*N+3; i++)
		v[i] = (modular)C(3*N+3, i);
	v[0] -= (modular)1;
 
	vector<modular> tmp = {0, 3, 3, 1};
	v = id11(v, tmp).first;

	while(Q--)
	{
		int x;
		cin >> x;
		cout << v[x] << "\n";
	}
	

	

	return 0;
}