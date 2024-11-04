

















































using namespace std;





string all;

const int base = 10;
const int nblock = 9;
const int blockbase = (int)1000000000;
struct Bigint {
public:
	vector<int> a;
	int sign;
	Bigint() : sign(1) {}
	Bigint(long long v) { *this = v; }
	Bigint(const string& s) { read(s); }
	void operator = (const Bigint& v) { sign = v.sign; a = v.a; }
	void operator = (long long v) {
		sign = 1;
		if (v < 0)
			sign = -1, v = -v;
		for (; v > 0; v = v / blockbase)
			a.push_back(v % blockbase);
	}
	Bigint operator + (const Bigint& v) const {
		if (sign == v.sign) {
			Bigint res = v;
			for (int i = 0, carry = 0; i < (int)max(a.size(), v.a.size()) || carry; i++) {
				if (i == (int)res.a.size()) res.a.push_back(0);
				res.a[i] += carry + (i < (int)a.size() ? a[i] : 0);
				carry = res.a[i] >= blockbase;
				if (carry) res.a[i] -= blockbase;
			}
			return res;
		}
		return *this - (-v);
	}
	Bigint operator - (const Bigint& v) const {
		if (sign == v.sign) {
			if (abs() >= v.abs()) {
				Bigint res = *this;
				for (int i = 0, carry = 0; i < (int)v.a.size() || carry; i++) {
					res.a[i] -= carry + (i < (int)v.a.size() ? v.a[i] : 0);
					carry = res.a[i] < 0;
					if (carry) res.a[i] += blockbase;
				}
				res.trim();
				return res;
			}
			return -(v - *this);
		}
		return *this + (-v);
	}
	void operator *= (int v) {
		if (v < 0) sign = -sign, v = -v;
		for (int i = 0, carry = 0; i < (int)a.size() || carry; i++) {
			if (i == (int)a.size()) a.push_back(0);
			long long cur = a[i] * (long long)v + carry;
			carry = (int)(cur / blockbase);
			a[i] = (int)(cur % blockbase);
		}
		trim();
	}
	void operator *= (long long v) {
		if (v >= (long long)blockbase * blockbase) {
			*this *= Bigint(v);
		}
		int a = v / blockbase;
		int b = v % blockbase;
		*this = *this * a * blockbase + *this * b;
	}
	Bigint operator * (int v) const {
		Bigint res = *this;
		res *= v;
		return res;
	}
	Bigint operator * (long long v) const {
		Bigint res = *this;
		res *= v;
		return res;
	}
	friend pair<Bigint, Bigint> divmod(const Bigint& a1, const Bigint& b1) {
		int norm = blockbase / (b1.a.back() + 1);
		Bigint a = a1.abs() * norm;
		Bigint b = b1.abs() * norm;
		Bigint q, r;
		q.a.resize(a.a.size());
		for (int i = a.a.size() - 1; i >= 0; i--) {
			r *= blockbase;
			r += a.a[i];
			int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
			int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
			int d = ((long long)blockbase * s1 + s2) / b.a.back();
			r -= b * d;
			while (r < 0)
				r += b, d--;
			q.a[i] = d;
		}
		q.sign = a1.sign * b1.sign;
		r.sign = a1.sign;
		q.trim();
		r.trim();
		return make_pair(q, r / norm);
	}
	Bigint operator / (const Bigint& v) const {
		return divmod(*this, v).first;
	}
	Bigint operator % (const Bigint& v) const {
		return divmod(*this, v).second;
	}
	void operator /= (int v) {
		if (v < 0) sign = -sign, v = -v;
		for (int i = (int)a.size() - 1, rem = 0; i >= 0; i--) {
			long long cur = a[i] + rem * (long long)blockbase;
			a[i] = (int)(cur / v);
			rem = (int)(cur % v);
		}
		trim();
	}
	void operator /= (long long v) {
		*this /= Bigint(v);
	}
	Bigint operator / (int v) const {
		Bigint res = *this;
		res /= v;
		return res;
	}
	Bigint operator / (long long v) const {
		Bigint res = *this;
		res /= v;
		return res;
	}
	int operator % (int v) const {
		if (v < 0) v = -v;
		int m = 0;
		for (int i = a.size() - 1; i >= 0; i--) m = (a[i] + m * (long long)blockbase) % v;
		return m * sign;
	}
	long long operator % (long long v) const {
		return (*this % Bigint(v)).longValue();
	}
	void operator += (const Bigint& v) {
		*this = *this + v;
	}
	void operator -= (const Bigint& v) {
		*this = *this - v;
	}
	void operator *= (const Bigint& v) {
		*this = *this * v;
	}
	void operator /= (const Bigint& v) {
		*this = *this / v;
	}
	bool operator < (const Bigint& v) const {
		if (sign != v.sign) return sign < v.sign;
		if (a.size() != v.a.size()) return a.size() * sign < v.a.size() * v.sign;
		for (int i = a.size() - 1; i >= 0; i--) if (a[i] != v.a[i]) return a[i] * sign < v.a[i] * sign;
		return false;
	}
	bool operator > (const Bigint& v) const {
		return v < *this;
	}
	bool operator <= (const Bigint& v) const {
		return !(v < *this);
	}
	bool operator >= (const Bigint& v) const {
		return !(*this < v);
	}
	bool operator == (const Bigint& v) const {
		return !(*this < v) && !(v < *this);
	}
	bool operator != (const Bigint& v) const {
		return *this < v || v < *this;
	}
	void trim() {
		while (!a.empty() && !a.back()) a.pop_back();
		if (a.empty()) sign = 1;
	}
	bool isZero() const {
		return a.empty() || (a.size() == 1 && !a[0]);
	}
	Bigint operator - () const {
		Bigint res = *this;
		res.sign = -sign;
		return res;
	}
	Bigint abs() const {
		Bigint res = *this;
		res.sign *= res.sign;
		return res;
	}
	long long longValue() const {
		long long res = 0;
		for (int i = a.size() - 1; i >= 0; i--) res = (res * blockbase + a[i]);
		return res * sign;
	}
	friend Bigint gcd(const Bigint& a, const Bigint& b) {
		return b.isZero() ? a : gcd(b, a % b);
	}
	friend Bigint lcm(const Bigint& a, const Bigint& b) {
		return a / gcd(a, b) * b;
	}
	void read(const string& s) {
		sign = 1; a.clear(); int pos = 0;
		while (pos < (int)s.size() && (s[pos] == '-' || s[pos] == '+')) { if (s[pos] == '-') sign = -sign; pos++; }
		for (int i = s.size() - 1; i >= pos; i -= nblock) {
			int x = 0;
			for (int j = max(pos, i - nblock + 1); j <= i; j++) x = x * base + s[j] - '0';
			a.push_back(x);
		}
		trim();
	}
	friend istream& operator >> (istream& stream, Bigint& v) {
		string s; stream >> s; v.read(s);
		return stream;
	}
	friend ostream& operator<<(ostream& stream, const Bigint& v) {
		if (v.sign == -1) stream << '-';
		stream << (v.a.empty() ? 0 : v.a.back());
		for (int i = (int)v.a.size() - 2; i >= 0; i--) stream << setw(nblock) << setfill('0') << v.a[i];
		return stream;
	}
	static vector<int> convert_base(const vector<int>& a, int old_digits, int new_digits) {
		vector<long long> p(max(old_digits, new_digits) + 1);
		p[0] = 1;
		for (int i = 1; i < (int)p.size(); i++) p[i] = p[i - 1] * base;
		vector<int> res;
		long long cur = 0;
		int cur_digits = 0;
		for (int i = 0; i < (int)a.size(); i++) {
			cur += a[i] * p[cur_digits];
			cur_digits += old_digits;
			while (cur_digits >= new_digits) {
				res.push_back(int(cur % p[new_digits]));
				cur /= p[new_digits];
				cur_digits -= new_digits;
			}
		}
		res.push_back((int)cur);
		while (!res.empty() && !res.back()) res.pop_back();
		return res;
	}
	static vector<long long> karatsuba(vector<long long>& a, vector<long long>& b) {
		int n = a.size();
		vector<long long> res(n << 1);
		if (n <= 32) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					res[i + j] += a[i] * b[j];
			return res;
		}
		int k = n >> 1;
		vector<long long> a1(a.begin(), a.begin() + k);
		vector<long long> a2(a.begin() + k, a.end());
		vector<long long> b1(b.begin(), b.begin() + k);
		vector<long long> b2(b.begin() + k, b.end());
		vector<long long> id0 = karatsuba(a1, b1);
		vector<long long> id1 = karatsuba(a2, b2);
		for (int i = 0; i < k; i++) a2[i] += a1[i];
		for (int i = 0; i < k; i++) b2[i] += b1[i];
		vector<long long> r = karatsuba(a2, b2);
		for (int i = 0; i < (int)id0.size(); i++) r[i] -= id0[i];
		for (int i = 0; i < (int)id1.size(); i++) r[i] -= id1[i];
		for (int i = 0; i < (int)r.size(); i++) res[i + k] += r[i];
		for (int i = 0; i < (int)id0.size(); i++) res[i] += id0[i];
		for (int i = 0; i < (int)id1.size(); i++) res[i + n] += id1[i];
		return res;
	}
	Bigint operator * (const Bigint& v) const {
		int r = 6;
		int t = round(pow(base, r));
		vector<int> ar = convert_base(this->a, nblock, r);
		vector<int> br = convert_base(v.a, nblock, r);
		vector<long long> a(ar.begin(), ar.end());
		vector<long long> b(br.begin(), br.end());
		while (a.size() < b.size()) a.push_back(0);
		while (b.size() < a.size()) b.push_back(0);
		while (a.size() & (a.size() - 1)) a.push_back(0), b.push_back(0);
		vector<long long> c = karatsuba(a, b);
		Bigint res;
		res.sign = sign * v.sign;
		for (int i = 0, carry = 0; i < (int)c.size(); i++) {
			long long cur = c[i] + carry;
			res.a.push_back((int)(cur % t));
			carry = (int)(cur / t);
		}
		res.a = convert_base(res.a, r, nblock);
		res.trim();
		return res;
	}
	friend Bigint sqrt(const Bigint& a) {
		Bigint x0 = a, x1 = (a + 1) / 2;
		while (x1 < x0) {
			x0 = x1;
			x1 = (x1 + a / x1) / 2;
		}
		return x0;
	}
	friend Bigint pow(Bigint a, Bigint b) {
		if (b == Bigint(0)) return Bigint(1);
		Bigint T = pow(a, b / 2);
		if (b % 2 == 0) return T * T;
		return T * T * a;
	}
	friend Bigint pow(Bigint a, int b) {
		return pow(a, (Bigint(b)));
	}
	friend int log(Bigint a, int n) {
		int res = 0;
		while (a > Bigint(1)) {
			res++;
			a /= n;
		}
		return res;
	}
	template<class T> friend Bigint operator + (const T& v, const Bigint& a) {
		return a + v;
	}
	template<class T> friend Bigint operator - (const T& v, const Bigint& a) {
		return -a + v;
	}
	template<class T> friend Bigint operator * (const T& v, const Bigint& a) {
		return a * v;
	}
	template<class T> friend Bigint operator / (const T& v, const Bigint& a) {
		return Bigint(v) / a;
	}
	Bigint operator ++() {
		(*this) += 1;
		return *this;
	}
	Bigint operator ++(int) {
		(*this) += 1;
		return *this - 1;
	}
	Bigint operator --() {
		(*this) -= 1;
		return *this;
	}
	Bigint operator --(int) {
		(*this) -= 1;
		return *this + 1;
	}
};
string bob;
typedef pair<ll, ll> pp;
typedef vector<pp> ve;
typedef pair<ll, ll> point;
typedef complex<ld> id3;
typedef vector<ld> north;
ld MPI = acos(-1.0);



namespace FFT {
	const int N = 22;
	const int MAXN = (1 << N);
	class id3 {
	private:
		double x, y;
	public:
		id3() : x(0.0), y(0.0) {}
		id3(double a) : x(a), y(0.0) {}
		id3(double a, double b) : x(a), y(b) {}
		double get_real() { return this->x; }
		double get_img() { return this->y; }
		id3 conj() { return id3(this->x, -(this->y)); }
		id3 operator = (const id3& a) { this->x = a.x; this->y = a.y; return *this; }
		id3 operator + (const id3& b) { return id3(this->x + b.x, this->y + b.y); }
		id3 operator - (const id3& b) { return id3(this->x - b.x, this->y - b.y); }
		id3 operator * (const double& num) { return id3(this->x * num, this->y * num); }
		id3 operator / (const double& num) { return id3(this->x / num, this->y / num); }
		id3 operator * (const id3& b) {
			return id3(this->x * b.x - this->y * b.y, this->y * b.x + this->x * b.y);
		}
		id3 operator / (const id3& b) {
			id3 temp(b.x, -b.y); id3 n = (*this) * temp;
			return n / (b.x * b.x + b.y * b.y);
		}
	};
	id3 w[MAXN];
	id3 f1[MAXN];
	int rev[MAXN];
	void ReserveBits(int k) {
		static int rk = -1, lim;
		if (k == rk) return;
		rk = k, lim = 1 << k;
		for (int i = 1; i <= lim; ++i) {
			int j = rev[i - 1], t = k - 1;
			while (t >= 0 && ((j >> t) & 1)) {
				j ^= 1 << t; --t;
			}
			if (t >= 0) {
				j ^= 1 << t; --t;
			}
			rev[i] = j;
		}
	}
	void fft(id3 *a, int k) {
		ReserveBits(k);
		int n = 1 << k;
		for (int i = 0; i < n; ++i)
			if (rev[i] > i) swap(a[i], a[rev[i]]);
		for (int l = 2, m = 1; l <= n; l += l, m += m) {
			if (w[m].get_real() == 0 && w[m].get_img() == 0) {
				double angle = MPI / m;
				id3 ww(cos(angle), sin(angle));
				if (m > 1) {
					for (int j = 0; j < m; ++j) {
						if (j & 1) w[m + j] = w[(m + j) / 2] * ww;
						else w[m + j] = w[(m + j) / 2];
					}
				}
				else w[m] = id3(1, 0);
			}
			for (int i = 0; i < n; i += l) {
				for (int j = 0; j < m; ++j) {
					id3 v = a[i + j], u = a[i + j + m] * w[m + j];
					a[i + j] = v + u;
					a[i + j + m] = v - u;
				}
			}
		}
	}
	vector<ll> mul(const vector<ll>& a, const vector<ll>& b) {
		int k = 1;
		while ((1 << k) < (a.size() + b.size())) ++k;
		int n = (1 << k);
		for (int i = 0; i < n; ++i) f1[i] = id3(0, 0);
		for (int i = 0; i < a.size(); ++i) f1[i] = f1[i] + id3(a[i], 0);
		for (int i = 0; i < b.size(); ++i) f1[i] = f1[i] + id3(0, b[i]);
		fft(f1, k);
		for (int i = 0; i <= n / 2; ++i) {
			id3 p = f1[i] + f1[(n - i) % n].conj();
			id3 _q = f1[(n - i) % n] - f1[i].conj();
			id3 q(_q.get_img(), _q.get_real());
			f1[i] = (p * q) * 0.25;
			if (i > 0) f1[(n - i)] = f1[i].conj();
		}
		for (int i = 0; i < n; ++i) f1[i] = f1[i].conj();
		fft(f1, k);
		vector<ll> ans(a.size() + b.size() - 1);
		int sizz = ans.size();
		for (int i = 0; i < sizz; ++i) {
			ans[i] = (ll)(f1[i].get_real() / n + 0.5);

			if (ans[i] >= (ll)1000000000000) {
				cout << "YES" << endl;
			}
			if (ans[i] >= (ll)1000000000000) {
				int id2 = i + 4;
				while (ans.size() <= id2) {
					ans.push_back(0);
				}
				ans[id2] = ans[i] / 1000;
				ans[i] = ans[i] % 1000;
			}
		}
		int en = 0;
		while (en < ans.size()) {
			if (en == ans.size() - 1 && ans[en] < (ll)1000) { break; }
			ll value = ans[en] / (ll)1000;
			ans[en] = ans[en] % (ll)1000;
			if (en + 1 < ans.size()) {
				ans[en + 1] = ans[en + 1] + value;
			}
			else if (value) {
				ans.push_back(value);
			}
			en++;
		}
		return ans;
	}
};

vector<ll> fpow(ll q) {
	if (q == 0) {
		vector<ll> bob;bob.push_back(1);
		return bob;
	}
	vector<ll> ret;ret.push_back(1);
	vector<ll> ff;ff.push_back(3);
	for (; q; q >>= 1) {
		if (q & 1) {
			ret = FFT::mul(ret, ff);
		}
		ff = FFT::mul(ff, ff);
	}
	return ret;
}
int main() {
	cin >> bob;
	if (bob == "1") {
		cout << 1 << endl;
		return 0;
	}
	Bigint sos = bob;
	int sz = bob.length()*log(10) / log(3);sz -= 3;
	sz = max(0, sz);
	

	auto it = fpow(sz);
	
	string god;
	int dx = 0;
	for (int g = it.size() - 1;g >= 0;g--) {
		if (it[g] < 0 || it[g] >= 1000) {
			cout << "fak" << endl;
		}
		string vv = to_string(it[g]);
		if (g == it.size() - 1) {
			god.resize((it.size() - 1) * 3 + vv.length(), '0');
			for (auto s : vv) {
				god[dx] = s;
				dx++;
			}
		}
		else {
			int rm = 3 - vv.length();

			while (rm) {
				god[dx] = '0';
				dx++;
				rm--;
			}
			for (auto s : vv) {
				god[dx] = s;
				dx++;
			}
		}
	}
	Bigint lol = god;
	while (lol >= sos) {
		sz--;
		lol = lol / (ll)3;
	}
	while (lol < sos) {
		sz++;
		lol = lol * 3;
	}
	lol = lol / (ll)3;
	sz--;
	Bigint ans = -1;
	if (lol<sos && (lol * (ll)2) >= sos) {
		Bigint kl = sz * 3 + 2;
		if (ans == -1 || kl < ans) {
			ans = kl;
		}
	}
	if (lol<sos && lol*(ll)3 >= sos) {
		Bigint kl = (sz + 1) * 3;
		if (ans == -1 || kl < ans) {
			ans = kl;
		}
	}
	lol = lol / (ll)3;
	sz--;
	if (lol<sos && (lol * (ll)4) >= sos) {
		Bigint kl = (sz) * 3 + 4;
		if (ans == -1 || kl < ans) {
			ans = kl;
		}
	}
	cout << ans << endl;
	return 0;
}