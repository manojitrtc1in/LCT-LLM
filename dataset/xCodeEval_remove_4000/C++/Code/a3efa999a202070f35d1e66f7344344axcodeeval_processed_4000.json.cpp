
using namespace std;
struct _ { ios_base::Init i; _() { cin.sync_with_stdio(0); cin.tie(0); } } _;
using ll = long long int;
using ull = unsigned long long;



const int base = 1000000000;
const int base_digits = 9;

typedef int ELEM_TYPE;
typedef long long PRODUCT_TYPE;
static const ELEM_TYPE id2 = 9;
std::vector<ELEM_TYPE> val; 

static const int powersOfTen[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };

struct bigint {
	static const bigint zero;
	static const bigint one;
	static const bigint two;
	std::vector<int> a;
	int sign;

	bigint() :
		sign(1) {
	}

	bigint(long long v) {
		*this = v;
	}

	bigint(const std::string &s) {
		read(s);
	}

	void operator=(const bigint &v) {
		sign = v.sign;
		a = v.a;
	}

	void operator=(long long v) {
		sign = 1;
		if (v < 0)
			sign = -1, v = -v;
		a.clear();
		for (; v > 0; v = v / base)
			a.push_back(v % base);
	}

	bigint operator+(const bigint &v) const {
		if (sign == v.sign) {
			bigint res = v;

			for (int i = 0, carry = 0; i < (int)max(a.size(), v.a.size()) || carry; ++i) {
				if (i == (int)res.a.size())
					res.a.push_back(0);
				res.a[i] += carry + (i < (int)a.size() ? a[i] : 0);
				carry = res.a[i] >= base;
				if (carry)
					res.a[i] -= base;
			}
			return res;
		}
		return *this - (-v);
	}

	bigint operator-(const bigint &v) const {
		if (sign == v.sign) {
			if (abs() >= v.abs()) {
				bigint res = *this;
				for (int i = 0, carry = 0; i < (int)v.a.size() || carry; ++i) {
					res.a[i] -= carry + (i < (int)v.a.size() ? v.a[i] : 0);
					carry = res.a[i] < 0;
					if (carry)
						res.a[i] += base;
				}
				res.trim();
				return res;
			}
			return -(v - *this);
		}
		return *this + (-v);
	}

	void operator*=(int v) {
		if (v < 0)
			sign = -sign, v = -v;
		for (int i = 0, carry = 0; i < (int)a.size() || carry; ++i) {
			if (i == (int)a.size())
				a.push_back(0);
			long long cur = a[i] * (long long)v + carry;
			carry = (int)(cur / base);
			a[i] = (int)(cur % base);
			

			
		}
		trim();
	}

	bigint operator*(int v) const {
		bigint res = *this;
		res *= v;
		return res;
	}

	friend std::pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
		int norm = base / (b1.a.back() + 1);
		bigint a = a1.abs() * norm;
		bigint b = b1.abs() * norm;
		bigint q, r;
		q.a.resize(a.a.size());

		for (int i = a.a.size() - 1; i >= 0; i--) {
			r *= base;
			r += a.a[i];
			int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
			int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
			int d = ((long long)base * s1 + s2) / b.a.back();
			r -= b * d;
			while (r < 0)
				r += b, --d;
			q.a[i] = d;
		}

		q.sign = a1.sign * b1.sign;
		r.sign = a1.sign;
		q.trim();
		r.trim();
		return std::make_pair(q, r / norm);
	}

	bigint operator/(const bigint &v) const {
		return divmod(*this, v).first;
	}

	bigint operator%(const bigint &v) const {
		return divmod(*this, v).second;
	}

	void operator/=(int v) {
		if (v < 0)
			sign = -sign, v = -v;
		for (int i = (int)a.size() - 1, rem = 0; i >= 0; --i) {
			long long cur = a[i] + rem * (long long)base;
			a[i] = (int)(cur / v);
			rem = (int)(cur % v);
		}
		trim();
	}

	bigint operator/(int v) const {
		bigint res = *this;
		res /= v;
		return res;
	}

	int operator%(int v) const {
		if (v < 0)
			v = -v;
		int m = 0;
		for (int i = a.size() - 1; i >= 0; --i)
			m = (a[i] + m * (long long)base) % v;
		return m * sign;
	}

	void operator+=(const bigint &v) {
		*this = *this + v;
	}
	void operator-=(const bigint &v) {
		*this = *this - v;
	}
	void operator*=(const bigint &v) {
		*this = *this * v;
	}
	void operator/=(const bigint &v) {
		*this = *this / v;
	}
	void operator%=(const bigint &v) {
		*this = *this % v;
	}

	bool operator<(const bigint &v) const {
		if (sign != v.sign)
			return sign < v.sign;
		if (a.size() != v.a.size())
			return a.size() * sign < v.a.size() * v.sign;
		for (int i = a.size() - 1; i >= 0; i--)
			if (a[i] != v.a[i])
				return a[i] * sign < v.a[i] * sign;
		return false;
	}

	bool operator>(const bigint &v) const {
		return v < *this;
	}
	bool operator<=(const bigint &v) const {
		return !(v < *this);
	}
	bool operator>=(const bigint &v) const {
		return !(*this < v);
	}
	bool operator==(const bigint &v) const {
		return !(*this < v) && !(v < *this);
	}
	bool operator!=(const bigint &v) const {
		return *this < v || v < *this;
	}

	void trim() {
		while (!a.empty() && a.back() == 0)
			a.pop_back();
		if (a.empty())
			sign = 1;
	}

	bool isZero() const {
		return a.empty() || (a.size() == 1 && !a[0]);
	}

	bigint operator-() const {
		bigint res = *this;
		res.sign = -sign;
		return res;
	}

	bigint abs() const {
		bigint res = *this;
		res.sign *= res.sign;
		return res;
	}

	long long longValue() const {
		long long res = 0;
		for (int i = a.size() - 1; i >= 0; i--)
			res = res * base + a[i];
		return res * sign;
	}

	friend bigint gcd(const bigint &a, const bigint &b) {
		return b.isZero() ? a : gcd(b, a % b);
	}
	friend bigint lcm(const bigint &a, const bigint &b) {
		return a / gcd(a, b) * b;
	}

	void read(const string &s) {
		sign = 1;
		a.clear();
		int pos = 0;
		while (pos < (int)s.size() && (s[pos] == '-' || s[pos] == '+')) {
			if (s[pos] == '-')
				sign = -sign;
			++pos;
		}
		for (int i = s.size() - 1; i >= pos; i -= base_digits) {
			int x = 0;
			for (int j = max(pos, i - base_digits + 1); j <= i; j++)
				x = x * 10 + s[j] - '0';
			a.push_back(x);
		}
		trim();
	}

	friend istream& operator>>(istream &stream, bigint &v) {
		string s;
		stream >> s;
		v.read(s);
		return stream;
	}

	friend ostream& operator<<(ostream &stream, const bigint &v) {
		if (v.sign == -1)
			stream << '-';
		stream << (v.a.empty() ? 0 : v.a.back());
		for (int i = (int)v.a.size() - 2; i >= 0; --i)
			stream << setw(base_digits) << setfill('0') << v.a[i];
		return stream;
	}

	static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
		vector<long long> p(max(old_digits, new_digits) + 1);
		p[0] = 1;
		for (int i = 1; i < (int)p.size(); i++)
			p[i] = p[i - 1] * 10;
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
		while (!res.empty() && res.back() == 0)
			res.pop_back();
		return res;
	}

	void fft(vector<complex<double> > & a, bool invert) const {
		int n = (int)a.size();

		for (int i = 1, j = 0; i < n; ++i) {
			int bit = n >> 1;
			for (; j >= bit; bit >>= 1)
				j -= bit;
			j += bit;
			if (i < j)
				swap(a[i], a[j]);
		}

		for (int len = 2; len <= n; len <<= 1) {
			double ang = 2 * 3.14159265358979323846 / len * (invert ? -1 : 1);
			complex<double> wlen(cos(ang), sin(ang));
			for (int i = 0; i < n; i += len) {
				complex<double> w(1);
				for (int j = 0; j < len / 2; ++j) {
					complex<double> u = a[i + j];
					complex<double> v = a[i + j + len / 2] * w;
					a[i + j] = u + v;
					a[i + j + len / 2] = u - v;
					w *= wlen;
				}
			}
		}
		if (invert)
			for (int i = 0; i < n; ++i)
				a[i] /= n;
	}

	void multiply_fft(const vector<int> &a, const vector<int> &b, vector<int> &res) const {
		vector<complex<double> > fa(a.begin(), a.end());
		vector<complex<double> > fb(b.begin(), b.end());
		int n = 1;
		while (n < (int)max(a.size(), b.size()))
			n <<= 1;
		n <<= 1;
		fa.resize(n);
		fb.resize(n);

		fft(fa, false);
		fft(fb, false);
		for (int i = 0; i < n; ++i)
			fa[i] *= fb[i];
		fft(fa, true);

		res.resize(n);
		for (int i = 0, carry = 0; i < n; ++i) {
			res[i] = int(fa[i].real() + 0.5) + carry;
			carry = res[i] / 1000;
			res[i] %= 1000;
		}
	}

	bigint operator*(const bigint &v) const {
		bigint res;
		res.sign = sign * v.sign;
		multiply_fft(convert_base(a, base_digits, 3), convert_base(v.a, base_digits, 3), res.a);
		res.a = convert_base(res.a, 3, base_digits);
		res.trim();
		return res;
	}

	bigint mul_simple(const bigint &v) const {
		bigint res;
		res.sign = sign * v.sign;
		res.a.resize(a.size() + v.a.size());
		for (int i = 0; i < (int)a.size(); ++i)
			if (a[i])
				for (int j = 0, carry = 0; j < (int)v.a.size() || carry; ++j) {
					long long cur = res.a[i + j] + (long long)a[i] * (j < (int)v.a.size() ? v.a[j] : 0) + carry;
					carry = (int)(cur / base);
					res.a[i + j] = (int)(cur % base);
				}
		res.trim();
		return res;
	}

	typedef vector<long long> vll;

	static vll karatsubaMultiply(const vll &a, const vll &b) {
		int n = a.size();
		vll res(n + n);
		if (n <= 32) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					res[i + j] += a[i] * b[j];
			return res;
		}

		int k = n >> 1;
		vll a1(a.begin(), a.begin() + k);
		vll a2(a.begin() + k, a.end());
		vll b1(b.begin(), b.begin() + k);
		vll b2(b.begin() + k, b.end());

		vll id0 = karatsubaMultiply(a1, b1);
		vll id1 = karatsubaMultiply(a2, b2);

		for (int i = 0; i < k; i++)
			a2[i] += a1[i];
		for (int i = 0; i < k; i++)
			b2[i] += b1[i];

		vll r = karatsubaMultiply(a2, b2);
		for (int i = 0; i < (int)id0.size(); i++)
			r[i] -= id0[i];
		for (int i = 0; i < (int)id1.size(); i++)
			r[i] -= id1[i];

		for (int i = 0; i < (int)r.size(); i++)
			res[i + k] += r[i];
		for (int i = 0; i < (int)id0.size(); i++)
			res[i] += id0[i];
		for (int i = 0; i < (int)id1.size(); i++)
			res[i + n] += id1[i];
		return res;
	}

	bigint mul_karatsuba(const bigint &v) const {
		vector<int> a6 = convert_base(this->a, base_digits, 6);
		vector<int> b6 = convert_base(v.a, base_digits, 6);
		vll a(a6.begin(), a6.end());
		vll b(b6.begin(), b6.end());
		while (a.size() < b.size())
			a.push_back(0);
		while (b.size() < a.size())
			b.push_back(0);
		while (a.size() & (a.size() - 1))
			a.push_back(0), b.push_back(0);
		vll pasc = karatsubaMultiply(a, b);
		bigint res;
		res.sign = sign * v.sign;
		for (int i = 0, carry = 0; i < (int)pasc.size(); i++) {
			long long cur = pasc[i] + carry;
			res.a.push_back((int)(cur % 1000000));
			carry = (int)(cur / 1000000);
		}
		res.a = convert_base(res.a, 6, base_digits);
		res.trim();
		return res;
	}
	
	bigint intSqrt() const; 

	void optimizeSqrtSearchBounds(bigint& lo, bigint& hi) const;
	
	char digitAt(size_t i) const; 

	size_t numberOfDigits() const;

	inline std::string toString() const
	{
		std::ostringstream oss;
		oss << *this;
		return oss.str();
	}
};
const bigint bigint::zero = 0;
const bigint bigint::one = 1;
const bigint bigint::two = 2;

inline char bigint::digitAt(size_t i) const
{
	if (numberOfDigits() <= i)
	{
		std::cerr << "Invalid digit index: " << i << std::endl;
		return -1;
	}
	return (this->a[i / id2] / powersOfTen[i % id2]) % 10;
}

inline size_t bigint::numberOfDigits() const
{
	return (this->a.size() - 1) * id2 +
		(this->a.back() > 99999999 ? 9 : (this->a.back() > 9999999 ? 8 : (this->a.back() > 999999 ? 7 : (this->a.back() > 99999 ? 6 :
			(this->a.back() > 9999 ? 5 : (this->a.back() > 999 ? 4 : (this->a.back() > 99 ? 3 : (this->a.back() > 9 ? 2 : 1))))))));
}

inline void bigint::optimizeSqrtSearchBounds(bigint& lo, bigint& hi) const
{
	bigint hdn = one;
	for (int i = (int) this->numberOfDigits() / 2; i >= 2; --i)
	{
		hdn *= 10;
	}
	if (lo < hdn)
	{
		lo = hdn;
	}
	hdn *= 100;
	if (hi > hdn)
	{
		hi = hdn;
	}
}

inline bigint bigint::intSqrt() const
{
	if (*this <= zero)
	{
		std::cerr << "intSqrt called for non-positive integer: " << *this << std::endl;
		return zero;
	}
	bigint hi = *this / two + one, lo = zero, mid, mid2;
	optimizeSqrtSearchBounds(lo, hi);
	do
	{
		mid = (hi + lo) / two; 

		mid2 = mid * mid; 

		if (mid2 == *this)
		{
			lo = mid;
			break;
		}
		else if (mid2 < *this)
		{
			lo = mid;
		}
		else
		{
			hi = mid;
		}
	} while (lo < hi - one && mid2 != *this);
	return lo;
}


unsigned int __prime[N / 64];


void sieve()
{
	memset(__prime, -1, sizeof(__prime));

	unsigned int i;
	unsigned int sqrtN = (unsigned int)sqrt((double)N) + 1;
	for (i = 3; i < sqrtN; i += 2) if (gP(i))
	{
		unsigned int i2 = i + i;
		for (unsigned int j = i * i; j < N; j += i2) rP(j);
	}
}
int main()
{
	int n; cin >> n;
	if (n == 2) {
		cout << -1 << endl;
		return 0;
	}
	sieve();
	vector<bigint>primes{ 2 };
	for (int i = 3, j = 0; j < n; i += 2)
	{
		if (gP(i)) {
			bigint tmp{ i };
			primes.push_back(tmp);
			++j;
		}
	}
	bigint com = primes.back();
	for (int i = 1; i <= n; i++)
	{
		cout << accumulate(primes.begin() + 1, primes.end(), bigint::one, 
				::multiplies<bigint>()) / com << endl;
		rotate(primes.begin(), primes.begin() + 1, primes.end());
	}
}