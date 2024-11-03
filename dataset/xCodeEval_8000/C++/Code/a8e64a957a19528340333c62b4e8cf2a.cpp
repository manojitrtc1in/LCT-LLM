#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define PI 3.14159265



template<typename T>
struct point {
	T x, y;
	point() : x(0), y(0) {}
	point(T _x, T _y) : x(_x), y(_y) {}
	friend istream& operator>>(istream& i, point& p) { return i >> p.x >> p.y; }
	friend ostream& operator<<(ostream& o, const point& p) {
		return o << "(" << p.x << ", " << p.y << ")";
	}

	T norm() const { return x * x + y * y; }
	double len() const { return sqrt(norm()); }
	double ang() const { return atan2(y, x); }
	point<T> conj() const { return { x, -y }; }

	point& operator+=(const point& o) {
		x += o.x;
		y += o.y;
		return *this;
	}
	point& operator-=(const point& o) {
		x -= o.x;
		y -= o.y;
		return *this;
	}
	point& operator*=(const T& c) {
		x *= c;
		y *= c;
		return *this;
	}
	point& operator/=(const T& c) {
		x /= c;
		y /= c;
		return *this;
	}
	friend point operator+(const point& a, const point& b) { return point(a) += b; }
	friend point operator-(const point& a, const point& b) { return point(a) -= b; }
	friend point operator*(const point& a, const T& c) { return point(a) *= c; }
	friend point operator*(const T& c, const point& a) { return point(a) *= c; }
	friend point operator/(const point& a, const T& c) { return point(a) /= c; }

	bool operator==(const point& o) const { return x == o.x && y == o.y; }
	bool operator!=(const point& o) const { return x != o.x || y != o.y; }
	bool operator<(const point& o) const { return (x != o.x) ? x < o.x : y < o.y; }
	bool operator>(const point& o) const { return (x != o.x) ? x > o.x : y > o.y; }
	bool operator<=(const point& o) const { return !(*this > o); }

	friend T dot(const point& a, const point& b) { return a.x * b.x + a.y * b.y; }
	friend T cross(const point& a, const point& b) { return a.x * b.y - a.y * b.x; }
	friend T cross(const point& p, const point& a, const point& b) { return cross(a - p, b - p); }

	friend point<T> operator*(const point& a, const point& b) {
		return { a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x };
	}
	friend point<T> operator/(const point& a, const point& b) {
		return a * b.conj() / b.norm();
	}

	point dir() const { return point(*this) / len(); }
	point rotate(const double& ang) const { return *this * point(cos(ang), sin(ang)); }

	T dist(const point& a) const { return (a - *this).len(); }
	T dist(const point& a, const point& b) {
		return abs(cross(*this, a, b)) / a.dist(b);
	}
	point reflect(const point& a, const point& b) const {
		return a + ((*this - a) / (b - a)).conj() * (b - a);
	}
	point foot(const point& a, const point& b) const {
		return (*this + this->reflect(a, b)) / 2;
	}
	friend point extension(const point& a, const point& b, const point& c, const point& d) {
		T x = cross(a, b, c), y = cross(a, b, d);
		return (d * x - c * y) / (x - y);
	}

	friend vector<point> seg_intersect(point a, point b, point c, point d) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);

		T a1 = cross(a, b, c), a2 = cross(a, b, d);
		if (a1 > a2) swap(a1, a2);
		if (!(a1 <= 0 && a2 >= 0)) return {};

		if (a1 == 0 && a2 == 0) {
			if (cross(a, c, d) != 0) return {};
			point<T> x1 = max(a, c), x2 = min(b, d);
			if (x1 > x2) return {};
			if (x1 == x2) return { x1 };
			return { x1, x2 };
		}

		point<T> z = extension(a, b, c, d);
		if (a <= z && z <= b) return { z };
		return {};
	}

	using polygon = vector<point<T>>;
	friend ostream& operator<<(ostream& o, const polygon& poly) {
		o << "{";
		for (auto pt : poly) o << " " << pt;
		return o << " }";
	}

	string classify(const polygon& p) const {
		bool ans = 0;
		for (int i = 0; i < p.size(); i++) {
			point<T> a = p[i], b = p[(i + 1) % p.size()];
			if (cross(a, b, *this) == 0 && min(a, b) <= *this && *this <= max(a, b))
				return "on";
			if (a.y > b.y) swap(a, b);
			if (a.y <= y && y < b.y && cross(*this, a, b) > 0) ans ^= 1;
		}
		return ans ? "in" : "out";
	}

	friend polygon convex_hull(const vector<point>& pts) {
		point pivot = *min_element(all(pts));
		auto sorted = pts;
		sort(all(sorted), [&pivot](const point& p, const point& q) {
			T cp = cross(pivot, p, q);
			if (cp != 0) return cp > 0;
			return pivot.dist(p) < pivot.dist(q);
			});

		int j = 0;
		polygon res(pts.size());
		for (const point& p : sorted) {
			while (j > 1 && cross(res[j - 2], res[j - 1], p) <= 0)
				j--;
			res[j++] = p;
		}
		res.erase(res.begin() + j, res.end());
		return res;
	}

	

	friend T area(const polygon& p) {
		T a = 0;
		for (int i = 0; i < sz(p); i++)
			a += cross(p[i], p[i + 1 < sz(p) ? i + 1 : 0]);
		return a;
	}
};



template<typename T>
int SIZE(T(&t)) { return t.size(); }
template<typename T, size_t N>
int SIZE(T(&t)[N]) { return N; }
string to_string(char t) { return "'" + string({ t }) + "'"; }
string to_string(bool t) { return t ? "true" : "false"; }
string to_string(const string& t, int x1 = 0, int x2 = 1e9) {
	string ret = "";
	for (int i = min(x1, SIZE(t)), _i = min(x2, SIZE(t) - 1); i <= _i; ++i) { ret += t[i]; }
	return '"' + ret + '"';
}
string to_string(const char* t) {
	string ret(t);
	return to_string(ret);
}
template<size_t N>
string to_string(const bitset<N>& t, int x1 = 0, int x2 = 1e9) {
	string ret = "";
	for (int i = min(x1, SIZE(t)); i <= min(x2, SIZE(t) - 1); ++i) { ret += t[i] + '0'; }
	return to_string(ret);
}
template<typename T, typename... Coords>
string to_string(const T(&t), int x1 = 0, int x2 = 1e9, Coords... C);
template<typename T, typename S>
string to_string(const pair<T, S>& t) { return "(" + to_string(t.first) + ", " + to_string(t.second) + ")"; }
template<typename T, typename... Coords>
string to_string(const T(&t), int x1, int x2, Coords... C) {
	string ret = "[";
	x1 = min(x1, SIZE(t));
	auto e = begin(t);
	advance(e, x1);
	for (int i = x1, _i = min(x2, SIZE(t) - 1); i <= _i; ++i) {
		ret += to_string(*e, C...) + (i != _i ? ", " : "");
		e = next(e);
	}
	return ret + "]";
}
template<int Index, typename... Ts>
struct print_tuple {
	string operator()(const tuple<Ts...>& t) {
		string ret = print_tuple<Index - 1, Ts...>{}(t);
		ret += (Index ? ", " : "");
		return ret + to_string(get<Index>(t));
	}
};
template<typename... Ts>
struct print_tuple<0, Ts...> { string operator()(const tuple<Ts...>& t) { return to_string(get<0>(t)); } };
template<typename... Ts>
string to_string(const tuple<Ts...>& t) {
	const auto Size = tuple_size<tuple<Ts...>>::value;
	return print_tuple<Size - 1, Ts...>{}(t);
}
void dbgr() { ; }
template<typename Heads, typename... Tails>
void dbgr(Heads H, Tails... T) {
	cout << to_string(H) << " | ";
	dbgr(T...);
}
void dbgs() { ; }
template<typename Heads, typename... Tails>
void dbgs(Heads H, Tails... T) {
	cout << H << " ";
	dbgs(T...);
}
#define dbgv(...) cout << to_string(__VA_ARGS__) << endl;
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgv(__VA_ARGS__);
#define dbgr(...) dbgr(__VA_ARGS__); cout << endl;
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgr(__VA_ARGS__);







const int MOD = 1e9 + 7;
struct mod_int {
	ll val;
	mod_int(ll v = 0) {
		if (v < 0) v = v % MOD + MOD;
		if (v >= MOD) v %= MOD;
		val = v;
	}

	static int mod_inv_gcdex(int a, int m = MOD) {
		

		int g = m, r = a, x = 0, y = 1;

		while (r != 0) {
			int q = g / r;
			g %= r;
			swap(g, r);
			x -= q * y;
			swap(x, y);
		}

		return x < 0 ? x + m : x;
	}

	static ll mod_inv(ll a, ll m = MOD) {
		if (a == 1) return 1;
		return (m - m / a * mod_inv(m % a) % m) % m;
	}

	explicit operator ll() const {
		return val;
	}

	mod_int& operator+=(const mod_int& other) {
		val += other.val;
		if (val >= MOD) val -= MOD;
		return *this;
	}

	mod_int& operator-=(const mod_int& other) {
		val -= other.val;
		if (val < 0) val += MOD;
		return *this;
	}

	mod_int& operator*=(const mod_int& other) {
		val *= ll(other) % MOD;
		val %= MOD;
		return *this;
	}

	mod_int& operator/=(const mod_int& other) {
		return *this *= other.inv();
	}

	friend mod_int operator+(const mod_int& a, const mod_int& b) { return mod_int(a) += b; }
	friend mod_int operator-(const mod_int& a, const mod_int& b) { return mod_int(a) -= b; }
	friend mod_int operator*(const mod_int& a, const mod_int& b) { return mod_int(a) *= b; }
	friend mod_int operator/(const mod_int& a, const mod_int& b) { return mod_int(a) /= b; }

	mod_int& operator++() {
		val = val == MOD - 1 ? 0 : val + 1;
		return *this;
	}

	mod_int& operator--() {
		val = val == 0 ? MOD - 1 : val - 1;
		return *this;
	}

	mod_int operator++(int) {
		mod_int before = *this;
		++* this;
		return before;
	}
	mod_int operator--(int) {
		mod_int before = *this;
		--* this;
		return before;
	}

	mod_int operator-() const {
		return val == 0 ? 0 : MOD - val;
	}

	bool operator==(const mod_int& other) const { return val == other.val; }
	bool operator!=(const mod_int& other) const { return val != other.val; }

	mod_int inv() const {
		return mod_inv(val);
	}

	static mod_int fact(ll n) {
		if (n <= 1) return 1;
		mod_int res(n);
		--n;
		while (n > 1) res *= n--;
		return res;
	}

	mod_int pow(int64_t p) const {
		if (p < 0)
			return inv().pow(-p);

		mod_int a = *this, result = 1;

		while (p > 0) {
			if (p & 1)
				result *= a;

			p >>= 1;

			if (p > 0)
				a *= a;
		}

		return result;
	}

	friend ostream& operator<<(ostream& stream, const mod_int& m) {
		return stream << m.val;
	}
};

class BigInt
{
public:

	BigInt() : mySign(positive),
		myDigits(1, '0'),
		myNumDigits(1) {}

	BigInt(ll num) : mySign(positive),
		myDigits(1, '0'),
		myNumDigits(0)
	{
		ll copy;
		if (num < 0)
		{
			mySign = negative;
			if (num == LLONG_MIN)
			{
				copy = unsigned(LLONG_MAX) + 1;
			}
			else
			{
				copy = -1 * num;
			}
		}
		else
		{
			copy = num;
		}

		


		AddSigDigit(copy % BASE);
		copy = copy / BASE;

		


		while (copy != 0)
		{
			AddSigDigit(copy % BASE);
			copy = copy / BASE;
		}
	}
	BigInt(const string& s) : mySign(positive),
		myDigits(s.length(), '0'),
		myNumDigits(0)
	{
		int k;
		int limit = 0;
		if (s.length() == 0) {
			myDigits.resize(1);
			AddSigDigit(0);
			return;
		}
		if (s[0] == '-') {
			mySign = negative;
			limit = 1;
		}
		if (s[0] == '+') {
			limit = 1;
		}
		


		for (k = s.length() - 1; k >= limit; k--) {
			if (!isdigit(s[k])) {
				cerr << "badly formed BigInt value = " << s << endl;
				abort();
			}
			AddSigDigit(s[k] - '0');
		}
		Normalize();
	}

	BigInt(const BigInt& rhs) : mySign(rhs.mySign),
		myDigits(rhs.myDigits),
		myNumDigits(rhs.myNumDigits) {}

	const BigInt& operator = (const BigInt& rhs) {
		mySign = rhs.mySign;
		myNumDigits = rhs.myNumDigits;
		myDigits = rhs.myDigits;
		return *this;
	}
	virtual ~BigInt() {}

	

	const BigInt& operator += (const BigInt& rhs) {

		int sum;
		int carry = 0;

		int k;
		int len = NumDigits();         


		if (this == &rhs)              

		{
			*this *= 2;
			return *this;
		}

		if (rhs == 0)                   

		{
			return *this;
		}

		if (IsPositive() != rhs.IsPositive())    

		{
			*this -= (-1 * rhs);
			return *this;
		}

		


		if (len < rhs.NumDigits())
		{
			len = rhs.NumDigits();
		}
		for (k = 0; k < len; k++)
		{
			sum = GetDigit(k) + rhs.GetDigit(k) + carry;
			carry = sum / BASE;
			sum = sum % BASE;

			if (k < myNumDigits)
			{
				ChangeDigit(k, sum);
			}
			else
			{
				AddSigDigit(sum);
			}
		}
		if (carry != 0)
		{
			AddSigDigit(carry);
		}
		return *this;
	}
	const BigInt& operator -= (const BigInt& rhs) {
		int diff;
		int borrow = 0;

		int k;
		int len = NumDigits();

		if (this == &rhs)         

		{
			*this = 0;
			return *this;
		}

		


		if (IsNegative() != rhs.IsNegative())
		{
			*this += (-1 * rhs);
			return *this;
		}
		

		

		

		

		

		if (IsPositive() && (*this) < rhs ||
			IsNegative() && (*this) > rhs)
		{
			*this = rhs - *this;
			if (IsPositive()) mySign = negative;
			else              mySign = positive;   

			return *this;
		}
		


		for (k = 0; k < len; k++)
		{
			diff = GetDigit(k) - rhs.GetDigit(k) - borrow;
			borrow = 0;
			if (diff < 0)
			{
				diff += BASE;
				borrow = 1;
			}
			ChangeDigit(k, diff);
		}
		Normalize();
		return *this;
	}
	const BigInt& operator *= (const BigInt& rhs) {
		


		if (IsNegative() != rhs.IsNegative())
		{
			mySign = negative;
		}
		else
		{
			mySign = positive;
		}

		BigInt self(*this);                        

		BigInt sum(0);                             

		int k;
		int len = rhs.NumDigits();                 


		for (k = 0; k < len; k++)
		{
			sum += self * rhs.GetDigit(k);          

			self *= BASE;                           

		}
		*this = sum;
		return *this;
	}
	const BigInt& operator *= (int num) {
		int carry = 0;
		int product;               

		int k;
		int len = NumDigits();

		if (0 == num)              

		{
			*this = 0;
			return *this;
		}

		if (BASE < num || num < 0)        

		{
			*this *= BigInt(num);
			return *this;
		}

		if (1 == num)              

		{
			return *this;
		}

		for (k = 0; k < len; k++)     

		{
			product = num * GetDigit(k) + carry;
			carry = product / BASE;
			ChangeDigit(k, product % BASE);
		}

		while (carry != 0)         

		{
			AddSigDigit(carry % BASE);
			carry /= BASE;
		}
		return *this;
	}
	const BigInt& operator /= (const BigInt& rhs) {
		BigInt quotient, remainder;
		bool resultNegative = (IsNegative() != rhs.IsNegative());
		mySign = positive;      


		


		if (rhs.IsNegative())
		{
			DivideHelp(*this, -1 * rhs, quotient, remainder);
		}
		else
		{
			DivideHelp(*this, rhs, quotient, remainder);
		}
		*this = quotient;
		mySign = resultNegative ? negative : positive;
		Normalize();
		return *this;
	}
	const BigInt& operator /= (int num) {
		int carry = 0;
		int quotient;
		int k;
		int len = NumDigits();

		if (num > BASE)     

		{
			return operator /= (BigInt(num));
		}
		if (0 == num)       

		{
			cerr << "division by zero error" << endl;
			abort();
		}
		else
		{
			for (k = len - 1; k >= 0; k--)  

			{
				quotient = (BASE * carry + GetDigit(k));
				carry = quotient % num;
				ChangeDigit(k, quotient / num);
			}
		}
		Normalize();
		return *this;
	}
	const BigInt& operator %= (const BigInt& rhs) {
		BigInt quotient, remainder;
		bool resultNegative = IsNegative();

		


		if (rhs.IsNegative())
		{
			DivideHelp(*this, -1 * rhs, quotient, remainder);
		}
		else
		{
			DivideHelp(*this, rhs, quotient, remainder);
		}
		*this = remainder;
		mySign = resultNegative ? negative : positive;
		return *this;
	}

	string ToString() const {
		int k;
		int len = NumDigits();
		string s = "";

		if (IsNegative())
		{
			s = '-';
		}
		for (k = len - 1; k >= 0; k--)
		{
			s += char('0' + GetDigit(k));
		}
		return s;
	}
	ll ToInt() const {
		ll result = 0;
		int k;
		if (BigInt(LLONG_MAX) < *this) return LLONG_MAX;
		if (*this < BigInt(LLONG_MIN)) return LLONG_MIN;

		for (k = NumDigits() - 1; k >= 0; k--)
		{
			result = result * BASE + GetDigit(k);
		}
		if (IsNegative())
		{
			result *= -1;
		}
		return result;
	}
	double   ToDouble() const {
		double result = 0.0;
		int k;
		for (k = NumDigits() - 1; k >= 0; k--)
		{
			result = result * BASE + GetDigit(k);
		}
		if (IsNegative())
		{
			result *= -1;
		}
		return result;
	}

	


	bool Equal(const BigInt& rhs)        const {

		if (NumDigits() != rhs.NumDigits() || IsNegative() != rhs.IsNegative())
		{
			return false;
		}
		


		int k;
		int len = NumDigits();
		for (k = 0; k < len; k++)
		{
			if (GetDigit(k) != rhs.GetDigit(k)) return false;
		}

		return true;
	}
	bool LessThan(const BigInt& rhs)     const {
		


		if (IsNegative() != rhs.IsNegative())
		{
			return IsNegative();
		}

		


		if (NumDigits() != rhs.NumDigits())
		{
			return (NumDigits() < rhs.NumDigits() && IsPositive()) ||
				(NumDigits() > rhs.NumDigits() && IsNegative());
		}

		


		int k;
		int len = NumDigits();

		for (k = len - 1; k >= 0; k--)
		{
			if (GetDigit(k) < rhs.GetDigit(k)) return IsPositive();
			if (GetDigit(k) > rhs.GetDigit(k)) return IsNegative();
		}
		return false;      

	}



	friend ostream& operator <<(ostream& out, const BigInt& big) {
		out << big.ToString();
		return out;
	}

	friend istream& operator >>(istream& in, BigInt& big) {
		string s;
		in >> s;
		big = BigInt(s);
		return in;
	}

	friend BigInt operator +(const BigInt& lhs, const BigInt& rhs) {
		BigInt result(lhs);
		result += rhs;
		return result;
	}
	friend BigInt operator -(const BigInt& lhs, const BigInt& rhs) {
		BigInt result(lhs);
		result -= rhs;
		return result;
	}
	friend BigInt operator *(const BigInt& lhs, const BigInt& rhs) {
		BigInt result(lhs);
		result *= rhs;
		return result;
	}
	friend BigInt operator *(const BigInt& lhs, int num) {
		BigInt result(lhs);
		result *= num;
		return result;
	}
	friend BigInt operator *(int num, const BigInt& rhs) {
		BigInt result(rhs);
		result *= num;
		return result;
	}
	friend BigInt operator /(const BigInt& lhs, const BigInt& rhs) {
		BigInt result(lhs);
		result /= rhs;
		return result;
	}
	friend BigInt operator /(const BigInt& lhs, int num) {
		BigInt result(lhs);
		result /= num;
		return result;
	}
	friend BigInt operator %(const BigInt& lhs, const BigInt& rhs) {
		BigInt result(lhs);
		result %= rhs;
		return result;
	}

	friend bool operator == (const BigInt& lhs, const BigInt& rhs) {
		return lhs.Equal(rhs);
	}

	friend bool operator <  (const BigInt& lhs, const BigInt& rhs) {
		return lhs.LessThan(rhs);
	}
	friend bool operator != (const BigInt& lhs, const BigInt& rhs) {
		return !(lhs == rhs);
	}
	friend bool operator >  (const BigInt& lhs, const BigInt& rhs) {
		return rhs < lhs;
	}
	friend bool operator >= (const BigInt& lhs, const BigInt& rhs) {
		return lhs == rhs || lhs > rhs;
	}
	friend bool operator <= (const BigInt& lhs, const BigInt& rhs) {
		return lhs == rhs || lhs < rhs;
	}
private:

	


	bool IsNegative()  const {
		return mySign == negative;
	}
	bool IsPositive()  const {
		return mySign == positive;
	}
	int  NumDigits()   const {
		return myNumDigits;
	}

	int  GetDigit(int k) const {
		if (0 <= k && k < NumDigits())
		{
			return myDigits[k] - '0';
		}
		return 0;
	}
	void AddSigDigit(int value) {
		if (myNumDigits >= myDigits.size())
		{
			myDigits.resize(myDigits.size() * 2);
		}
		myDigits[myNumDigits] = char('0' + value);
		myNumDigits++;
	}
	void ChangeDigit(int k, int value) {
		if (0 <= k && k < NumDigits())
		{
			myDigits[k] = char('0' + value);
		}
		else
		{
			cerr << "error changeDigit " << k << " " << myNumDigits << endl;
		}
	}

	void Normalize() {
		int k;
		int len = NumDigits();
		for (k = len - 1; k >= 0; k--)        

		{
			if (GetDigit(k) != 0) break;
			myNumDigits--;               

		}
		if (k < 0)    

		{
			myNumDigits = 1;
			mySign = positive;
		}
	}
	void DivideHelp(const BigInt& lhs, const BigInt& rhs,
		BigInt& quotient, BigInt& remainder) {
		if (lhs < rhs)             

		{                          

			quotient = 0;
			remainder = lhs;
			return;
		}
		else if (lhs == rhs)       

		{
			quotient = 1;
			remainder = 0;
			return;
		}

		BigInt dividend(lhs);      

		BigInt divisor(rhs);
		quotient = remainder = 0;
		int k, trial;
		int zeroCount = 0;

		


		while (divisor.NumDigits() < dividend.NumDigits())
		{
			divisor *= BASE;
			zeroCount++;
		}

		


		if (divisor > dividend)
		{
			divisor /= BASE;
			zeroCount--;
		}


		

		


		int divisorSig = divisor.GetDigit(divisor.NumDigits() - 1);
		int dividendSig;
		BigInt hold;
		for (k = 0; k <= zeroCount; k++)
		{
			dividendSig = dividend.GetDigit(dividend.NumDigits() - 1);
			trial =
				(dividendSig * BASE + dividend.GetDigit(dividend.NumDigits() - 2))
				/ divisorSig;

			if (BASE <= trial)   

			{
				trial = BASE - 1;
			}
			while ((hold = divisor * trial) > dividend)
			{
				trial--;
			}

			

			


			quotient *= BASE;
			quotient += trial;
			dividend -= hold;
			divisor /= BASE;
			divisorSig = divisor.GetDigit(divisor.NumDigits() - 1);
		}
		remainder = dividend;
	}

	


	enum Sign { positive, negative };
	Sign mySign;                

	vector<char> myDigits;     

	int myNumDigits;		

	const int BASE = 10;
};



















vector<int> ZFunction(const string& s) {
	int n = (int)s.length();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	return z;
}

vector<int> SuffixArray() {
	return {};
}

bool IsPowOf2(ll n) {
	return (n & (n - 1)) == 0;
}

template<class T>
struct SegmentTree {
	vector<T> tree_;
	size_t size;

	SegmentTree(size_t n, const T& v) {
		size = 1;
		while (size < n) size *= 2;
		tree_.assign(size * 2 - 1, v);
	}

	void SetSumVal(int i, const T& v) {
		SetSumVal(i, v, 0, 0, size);
	}

	void SetSumVal(int i, const T& v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			tree_[x] = v;
			return;
		}

		int m = (lx + rx) / 2;
		if (i < m) {
			SetSumVal(i, v, 2 * x + 1, lx, m);
		}
		else SetSumVal(i, v, 2 * x + 2, m, rx);

		tree_[x] = tree_[2 * x + 1] + tree_[2 * x + 2];
	}

	T Sum(int l, int r) {
		return Sum(l, r, 0, 0, size);
	}

	T Sum(int l, int r, int x, int lx, int rx) {
		if (lx >= l && rx <= r) {
			return tree_[x];
		}

		if (lx >= r || rx <= l) return 0;
		int m = (lx + rx) / 2;
		T left = Sum(l, r, 2 * x + 1, lx, m);
		T right = Sum(l, r, 2 * x + 2, m, rx);

		return left + right;
	}

	void SetMaxVal(int i, const T& v) {
		SetMaxVal(i, v, 0, 0, size);
	}

	void SetMaxVal(int i, const T& v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			tree_[x] = v;
			return;
		}

		int m = (lx + rx) / 2;
		if (i < m) {
			SetSumVal(i, v, 2 * x + 1, lx, m);
		}
		else SetSumVal(i, v, 2 * x + 2, m, rx);

		tree_[x].first = max(tree_[2 * x + 1].first, tree_[2 * x + 2].first);
		tree_[x].second = max(tree_[2 * x + 1].first, tree_[2 * x + 2].first);
	}
};

class DSU {
	vector<int> parent;

public:
	DSU(int n) {
		parent.resize(n);
		for (int i = 0; i < n; ++i) parent[i] = i;
	}

	int find(int u) {
		if (parent[u] == u) return u;
		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v) {
		parent[find(v)] = find(u);
	}
};

struct Sieve {
	vector<bool> isp;
	vector<int> primes;
	vector<short> mn;

	Sieve(int n, bool gen_primes = false, bool gen_mn = false) {
		isp.assign(n + 1, true); isp[0] = isp[1] = false;
		for (int i = 2; i * i <= n; ++i)
			if (isp[i])
				for (int j = i * i; j <= n; j += i)
					isp[j] = false;

		if (gen_primes)
			for (int i = 2; i <= n; ++i)
				if (isp[i])
					primes.push_back(i);

		if (gen_mn) {
			mn.resize(n + 1);
			for (int i = 2; i * i <= n; ++i)
				if (isp[i])
					for (int j = i * i; j <= n; j += i)
						mn[j] = i;
		}
	}

	bool is_prime(int k) const {
		return isp[k];
	}

	bool operator[](int k) const {
		return isp[k];
	}

	vector<pair<int, int>> get_prime_divs(int k) const {
		static vector<int> v;
		v.clear();
		while (k != 1 && !isp[k]) {
			v.push_back(mn[k]);
			k /= mn[k];
		}
		if (k != 1)
			v.push_back(k);
		sort(v.begin(), v.end());
		vector<pair<int, int>> res;
		for (int k : v) {
			if (res.empty() || k != res.back().first)
				res.emplace_back(k, 0);
			res.back().second++;
		}
		return res;
	}

	

	

	

	

	

	

};

class Graph {
public:
	Graph(int n, bool dir = 0) : directed(dir) {
		g.resize(n);
	}

	void Set(int a, int b) {
		g[a].push_back(b);
		if (!directed)
			g[b].push_back(a);
	}

	void LCAPrepare(int root) {

	}
private:
	vector<vector<ll>> g;
	bool directed;
};

void tutorial() {
	int n, q;
	cin >> n >> q;
	SegmentTree<int> seg(n, 0);

	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		seg.SetSumVal(i, k);
	}

	dbg(seg.tree_);

	for (int i = 0; i < q; ++i) {
		int type;
		cin >> type;
		if (type == 1) {
			int l, r;
			cin >> l >> r;
		}
		else {
			int j, v;
			cin >> j >> v;
			seg.SetSumVal(j, v);
		}
	}

}



ll pref[17][17][17][17][17];



mod_int fact[200000 + 7] = { 0 };

class Solution {
public:
	virtual ~Solution() {
		

		

	}
	void YES() { cout << "Yes\n"; }
	void NO() { cout << "No\n"; }

	inline ll gcd(ll x, ll y) {
		return y ? gcd(y, x % y) : x;
	}

	inline ll lcm(ll x, ll y) {
		return x / gcd(x, y) * y;
	}

	mod_int C(ll n, ll k) {
		return fact[n] * mod_int::mod_inv(mod_int(fact[k] * fact[n - k]).val);
	}

	mod_int A(ll n, ll k) {
		return fact[n] * mod_int::mod_inv(fact[n - k].val);
	}

	int cntMaxBit(ll x) {
		int k = 0;
		while (x > 0) x /= 2; ++k;
	}

	ll prefCnt(int i1, int i2, int i3, int i4, int i5) {
		ll res = 0;
		for (int k1 = i1; k1 <= i1 + 1; ++k1) {
			for (int k2 = i2; k2 <= i2 + 1; ++k2) {
				for (int k3 = i3; k3 <= i3 + 1; ++k3) {
					for (int k4 = i4; k4 <= i4 + 1; ++k4) {
						for (int k5 = i5; k5 <= i5 + 1; ++k5) {
							res += pref[k1][k2][k3][k4][k5];
						}
					}
				}
			}
		}

		res -= (pow(2, 5) - 1) * pref[i1][i2][i3][i4][i5];
		return res;
	}

	void solve(int tc = 0) {
		int n1, n2, n3, n4, n5; 
		cin >> n1 >> n2 >> n3 >> n4 >> n5;

		for (int i5 = 0; i5 < n5; ++i5) {
			for (int i4 = 0; i4 < n4; ++i4) {
				for (int i3 = 0; i3 < n3; ++i3) {
					for (int i2 = 0; i2 < n2; ++i2) {
						for (int i1 = 0; i1 < n1; ++i1) {
							int x; cin >> x;
							pref[i1 + 1][i2 + 1][i3 + 1][i4 + 1][i5 + 1] = prefCnt(i1, i2, i3, i4, i5) + x;
						}
					}
				}
			}
		}

		for (int i5 = 0; i5 <= n5; ++i5) {
			for (int i4 = 0; i4 <= n4; ++i4) {
				for (int i3 = 0; i3 <= n3; ++i3) {
					for (int i2 = 0; i2 <= n2; ++i2) {
						for (int i1 = 0; i1 <= n1; ++i1) {
							cout << i5 << ' ' << i4 << ' ' << i3 << ' ' << i2 << ' ' << i1 << ' ';
							cout << pref[i1][i2][i3][i4][i5] << endl;
						}
					}
				}
			}
		}

		int q; cin >> q;
		while (q--) {
			int l1, l2, l3, l4, l5, r1, r2, r3, r4, r5;
			cin >> l1 >> l2 >> l3 >> l4 >> l5 >> r1 >> r2 >> r3 >> r4 >> r5;
			--l1, --l2, --l3, --l4, --l5;

			ll res = 0;
			for (int k1 = l1; k1 <= r1; k1 += (r1 - l1)) {
				for (int k2 = l2; k2 <= r2; k2 += (r2 - l2)) {
					for (int k3 = l3; k3 <= r3; k3 += (r3 - l3)) {
						for (int k4 = l4; k4 <= r4; k4 += (r4 - l4)) {
							for (int k5 = l5; k5 <= r5; k5 += (r5 - l5)) {
								res += pref[k1][k2][k3][k4][k5];
							}
						}
					}
				}
			}
			cout << 2 * pref[r1][r2][r3][r4][r5] - res + 2 * pref[l1][l2][l3][l4][l5] << '\n';
		}
	}

	void solveC(int tc = 0) {
		int n; cin >> n;
		vector<int> a(n);
		for (auto& x : a) cin >> x;


		if (a[0] == 1) {
			cout << n + 1 << ' ';
			for (int i = 1; i <= n; ++i)
				cout << i << ' ';
			cout << '\n';
			return;
		}
		else if (a[n - 1] == 0) {
			for (int i = 1; i <= n + 1; ++i)
				cout << i << ' ';
			cout << '\n';
			return;
		}

		for (int i = 1; i < n; ++i) {
			if (a[i - 1] == 0 && a[i] == 1) {
				for (int j = 1; j <= i; ++j) cout << j << ' ';
				cout << n + 1 << ' ';
				for (int j = i + 1; j <= n; ++j) cout << j << ' ';
				cout << '\n';
				return;
			}
		}

		cout << -1 << endl;

	}

	int countSubsequencesByPattern(string X, string Y)
	{
		int m = X.size();
		int n = Y.size();
		vector<vector<ll>> T(m + 1, vector<ll>(n + 1));

		for (int i = 0; i <= m; i++) {
			T[i][0] = 1;
		}

		for (int j = 1; j <= n; j++) {
			T[0][j] = 0;
		}

		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				mod_int tmp = T[i - 1][j - 1];
				tmp += T[i - 1][j];
				T[i][j] = X[i - 1] == Y[j - 1] ? (ll)tmp : T[i - 1][j];
			}
		}

		return T[m][n];
	}

private:
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	Solution sol;
	int test = 1;
	cin >> test;
	while (test--) sol.solveC();

	return 0;
}

