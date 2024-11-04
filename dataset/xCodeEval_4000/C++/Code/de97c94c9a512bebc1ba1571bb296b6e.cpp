#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <ostream>
#include <iomanip>
#include <sstream>
#include <math.h>
#pragma warning(disable:4996)

using namespace std;
using std::vector;
using std::queue;
using ll = long long;
using real = long double;
typedef std::vector<int> vint;
typedef std::vector<long long> vell;
typedef std::vector<std::vector<int>> biVint;
typedef std::vector<std::vector<long long>> biVell;
typedef std::pair<int, int> piir;
typedef std::vector<std::pair<int, int>> vpiir;
#define range00(a, b) for(int i = a + 1; i < b; ++i)
#define range01(a, b) for(int i = a + 1; i <= b; ++i)
#define range10(a, b) for(int i = a; i < b; ++i)
#define range11(a, b) for(int i = a; i <= b; ++i)
#define input(x) for(auto it = begin(x); it != end(x); ++it) std::cin >> *it;
#define iterate(x, it) for(auto it = begin(x); it != end(x); ++it)
#define all(x) std::begin(x), std::end(x)
#define debug(x) std::cout << #x << " = " << x

class big_integer {
	

	static const int BASE = 1000000000;

	

	std::vector<int> _digits;

	

	bool _is_negative;

	void _remove_leading_zeros();
	void _shift_right();

public:
	

	class divide_by_zero : public std::exception {  };

	big_integer();
	big_integer(std::string);
	big_integer(signed char);
	big_integer(unsigned char);
	big_integer(signed short);
	big_integer(unsigned short);
	big_integer(signed int);
	big_integer(unsigned int);
	big_integer(signed long);
	big_integer(unsigned long);
	big_integer(signed long long);
	big_integer(unsigned long long);

	friend std::ostream& operator <<(std::ostream&, const big_integer&);
	operator std::string() const;
	const big_integer operator +() const;
	const big_integer operator -() const;
	const big_integer operator ++();
	const big_integer operator ++(int);
	const big_integer operator --();
	const big_integer operator --(int);
	friend bool operator ==(const big_integer&, const big_integer&);
	friend bool operator <(const big_integer&, const big_integer&);
	friend bool operator !=(const big_integer&, const big_integer&);
	friend bool operator <=(const big_integer&, const big_integer&);
	friend bool operator >(const big_integer&, const big_integer&);
	friend bool operator >=(const big_integer&, const big_integer&);
	friend const big_integer operator +(big_integer, const big_integer&);
	big_integer& operator +=(const big_integer&);
	friend const big_integer operator -(big_integer, const big_integer&);
	big_integer& operator -=(const big_integer&);
	friend const big_integer operator *(const big_integer&, const big_integer&);
	big_integer& operator *=(const big_integer&);
	friend const big_integer operator /(const big_integer&, const big_integer&);
	big_integer& operator /=(const big_integer&);
	friend const big_integer operator %(const big_integer&, const big_integer&);
	big_integer& operator %=(const big_integer&);

	bool odd() const;
	bool even() const;
	const big_integer pow(big_integer) const;
};



big_integer::big_integer() {
	this->_is_negative = false;
}



big_integer::big_integer(std::string str) {
	if (str.length() == 0) {
		this->_is_negative = false;
	}
	else {
		if (str[0] == '-') {
			str = str.substr(1);
			this->_is_negative = true;
		}
		else {
			this->_is_negative = false;
		}

		for (long long i = str.length(); i > 0; i -= 9) {
			if (i < 9)
				this->_digits.push_back(atoi(str.substr(0, i).c_str()));
			else
				this->_digits.push_back(atoi(str.substr(i - 9, 9).c_str()));
		}

		this->_remove_leading_zeros();
	}
}



void big_integer::_remove_leading_zeros() {
	while (this->_digits.size() > 1 && this->_digits.back() == 0) {
		this->_digits.pop_back();
	}

	if (this->_digits.size() == 1 && this->_digits[0] == 0) this->_is_negative = false;
}



std::ostream& operator <<(std::ostream& os, const big_integer& bi) {
	if (bi._digits.empty()) os << 0;
	else {
		if (bi._is_negative) os << '-';
		os << bi._digits.back();
		char old_fill = os.fill('0');
		for (long long i = static_cast<long long>(bi._digits.size()) - 2; i >= 0; --i) os << std::setw(9) << bi._digits[i];
		os.fill(old_fill);
	}

	return os;
}



bool operator ==(const big_integer& left, const big_integer& right) {
	if (left._is_negative != right._is_negative) return false;
	if (left._digits.empty()) {
		if (right._digits.empty() || (right._digits.size() == 1 && right._digits[0] == 0)) return true;
		else return false;
	}

	if (right._digits.empty()) {
		if (left._digits.size() == 1 && left._digits[0] == 0) return true;
		else return false;
	}

	if (left._digits.size() != right._digits.size()) return false;
	for (size_t i = 0; i < left._digits.size(); ++i) if (left._digits[i] != right._digits[i]) return false;

	return true;
}



const big_integer big_integer::operator +() const {
	return big_integer(*this);
}



const big_integer big_integer::operator -() const {
	big_integer copy(*this);
	copy._is_negative = !copy._is_negative;
	return copy;
}



bool operator <(const big_integer& left, const big_integer& right) {
	if (left == right) return false;
	if (left._is_negative) {
		if (right._is_negative) return ((-right) < (-left));
		else return true;
	}
	else if (right._is_negative) return false;
	else {
		if (left._digits.size() != right._digits.size()) {
			return left._digits.size() < right._digits.size();
		}
		else {
			for (long long i = left._digits.size() - 1; i >= 0; --i) {
				if (left._digits[i] != right._digits[i]) return left._digits[i] < right._digits[i];
			}

			return false;
		}
	}
}



bool operator !=(const big_integer& left, const big_integer& right) {
	return !(left == right);
}



bool operator <=(const big_integer& left, const big_integer& right) {
	return (left < right || left == right);
}



bool operator >(const big_integer& left, const big_integer& right) {
	return !(left <= right);
}



bool operator >=(const big_integer& left, const big_integer& right) {
	return !(left < right);
}



const big_integer operator +(big_integer left, const big_integer& right) {
	if (left._is_negative) {
		if (right._is_negative) return -(-left + (-right));
		else return right - (-left);
	}
	else if (right._is_negative) return left - (-right);
	int carry = 0;
	for (size_t i = 0; i < std::max(left._digits.size(), right._digits.size()) || carry != 0; ++i) {
		if (i == left._digits.size()) left._digits.push_back(0);
		left._digits[i] += carry + (i < right._digits.size() ? right._digits[i] : 0);
		carry = left._digits[i] >= big_integer::BASE;
		if (carry != 0) left._digits[i] -= big_integer::BASE;
	}

	return left;
}



big_integer& big_integer::operator +=(const big_integer& value) {
	return *this = (*this + value);
}



const big_integer big_integer::operator++() {
	return (*this += 1);
}



big_integer::operator std::string() const {
	std::stringstream ss;
	ss << *this;
	return ss.str();
}



big_integer::big_integer(signed char c) {
	if (c < 0) this->_is_negative = true;
	else this->_is_negative = false;
	this->_digits.push_back(std::abs(c));
}



big_integer::big_integer(unsigned char c) {
	this->_is_negative = false;
	this->_digits.push_back(c);
}



big_integer::big_integer(signed short s) {
	if (s < 0) this->_is_negative = true;
	else this->_is_negative = false;
	this->_digits.push_back(std::abs(s));
}



big_integer::big_integer(unsigned short s) {
	this->_is_negative = false;
	this->_digits.push_back(s);
}



big_integer::big_integer(signed int i) {
	if (i < 0) this->_is_negative = true;
	else this->_is_negative = false;
	this->_digits.push_back(std::abs(i) % big_integer::BASE);
	i /= big_integer::BASE;
	if (i != 0) this->_digits.push_back(std::abs(i));
}



big_integer::big_integer(unsigned int i) {
	this->_digits.push_back(i % big_integer::BASE);
	i /= big_integer::BASE;
	if (i != 0) this->_digits.push_back(i);
}



big_integer::big_integer(signed long l) {
	if (l < 0) this->_is_negative = true;
	else this->_is_negative = false;
	this->_digits.push_back(std::abs(l) % big_integer::BASE);
	l /= big_integer::BASE;
	if (l != 0) this->_digits.push_back(std::abs(l));
}



big_integer::big_integer(unsigned long l) {
	this->_digits.push_back(l % big_integer::BASE);
	l /= big_integer::BASE;
	if (l != 0) this->_digits.push_back(l);
}



big_integer::big_integer(signed long long l) {
	if (l < 0) { this->_is_negative = true; l = -l; }
	else this->_is_negative = false;
	do {
		this->_digits.push_back(l % big_integer::BASE);
		l /= big_integer::BASE;
	} while (l != 0);
}



big_integer::big_integer(unsigned long long l) {
	this->_is_negative = false;
	do {
		this->_digits.push_back(l % big_integer::BASE);
		l /= big_integer::BASE;
	} while (l != 0);
}



const big_integer big_integer::operator ++(int) {
	*this += 1;
	return *this - 1;
}



const big_integer big_integer::operator --() {
	return *this -= 1;
}



const big_integer big_integer::operator --(int) {
	*this -= 1;
	return *this + 1;
}



const big_integer operator -(big_integer left, const big_integer& right) {
	if (right._is_negative) return left + (-right);
	else if (left._is_negative) return -(-left + right);
	else if (left < right) return -(right - left);
	int carry = 0;
	for (size_t i = 0; i < right._digits.size() || carry != 0; ++i) {
		left._digits[i] -= carry + (i < right._digits.size() ? right._digits[i] : 0);
		carry = left._digits[i] < 0;
		if (carry != 0) left._digits[i] += big_integer::BASE;
	}

	left._remove_leading_zeros();
	return left;
}



big_integer& big_integer::operator -=(const big_integer& value) {
	return *this = (*this - value);
}



const big_integer operator *(const big_integer& left, const big_integer& right) {
	big_integer result;
	result._digits.resize(left._digits.size() + right._digits.size());
	for (size_t i = 0; i < left._digits.size(); ++i) {
		int carry = 0;
		for (size_t j = 0; j < right._digits.size() || carry != 0; ++j) {
			long long cur = result._digits[i + j] +
				left._digits[i] * 1LL * (j < right._digits.size() ? right._digits[j] : 0) + carry;
			result._digits[i + j] = static_cast<int>(cur % big_integer::BASE);
			carry = static_cast<int>(cur / big_integer::BASE);
		}
	}

	result._is_negative = left._is_negative != right._is_negative;
	result._remove_leading_zeros();
	return result;
}



big_integer& big_integer::operator *=(const big_integer& value) {
	return *this = (*this * value);
}



void big_integer::_shift_right() {
	if (this->_digits.size() == 0) {
		this->_digits.push_back(0);
		return;
	}
	this->_digits.push_back(this->_digits[this->_digits.size() - 1]);
	for (size_t i = this->_digits.size() - 2; i > 0; --i) this->_digits[i] = this->_digits[i - 1];
	this->_digits[0] = 0;
}



const big_integer operator /(const big_integer& left, const big_integer& right) {
	if (right == 0) throw big_integer::divide_by_zero();
	big_integer b = right;
	b._is_negative = false;
	big_integer result, current;
	result._digits.resize(left._digits.size());
	for (long long i = static_cast<long long>(left._digits.size()) - 1; i >= 0; --i) {
		current._shift_right();
		current._digits[0] = left._digits[i];
		current._remove_leading_zeros();
		int x = 0, l = 0, r = big_integer::BASE;
		while (l <= r) {
			int m = (l + r) / 2;
			big_integer t = b * m;
			if (t <= current) {
				x = m;
				l = m + 1;
			}
			else r = m - 1;
		}

		result._digits[i] = x;
		current = current - b * x;
	}

	result._is_negative = left._is_negative != right._is_negative;
	result._remove_leading_zeros();
	return result;
}



big_integer& big_integer::operator /=(const big_integer& value) {
	return *this = (*this / value);
}



const big_integer operator %(const big_integer& left, const big_integer& right) {
	big_integer result = left - (left / right) * right;
	if (result._is_negative) result += right;
	return result;
}



big_integer& big_integer::operator %=(const big_integer& value) {
	return *this = (*this % value);
}



bool big_integer::odd() const {
	if (this->_digits.size() == 0) return false;
	return this->_digits[0] & 1;
}



bool big_integer::even() const {
	return !this->odd();
}



const big_integer big_integer::pow(big_integer n) const {
	big_integer a(*this), result(1);
	while (n != 0) {
		if (n.odd()) result *= a;
		a *= a;
		n /= 2;
	}

	return result;
}

ll fast_multip(ll a, ll b, ll m) {
	if (!a || !b) return 0;
	if (b == 1) return a;
	if (a == 1) return b;
	if (b % 2 == 0) {
		long long t = fast_multip(a, b / 2, m);
		return (2 * t) % m;
	}
	return (fast_multip(a, b - 1, m) + a) % m;
}

ll fast_pow(ll a, ll b, ll m) {
	if (b == 0)
		return (m == 1) ? 0 : 1;
	if (b % 2 == 0) {
		ll t = fast_pow(a, b / 2, m);
		return fast_multip(t, t, m) % m;
	}
	return (fast_multip(fast_pow(a, b - 1, m), a, m)) % m;
}

big_integer C(int n, int k)
{
	big_integer up = 1;
	big_integer down = 1;
	for (int i = n; i >= (n - k + 1); --i)
		up *= i;
	for (int i = 1; i <= k; ++i)
		down *= i;
	return (up / down);
}

ll countDivP(ll a, ll b, ll p)
{
	if (a % p != 0)
	{
		if (a + (p - a % p) > b) return 0;
		else a += (p - a % p);
	}
	ll ans = (b - a) / p;
	return (++ans);
}

void decomp(vector<int>& dec, ll num)
{
	int i = 0;
	while (num > 0)
		dec[i++] = num % 2, num /= 2;
}

ll gcd(ll a, ll b) {
	while (b) {
		a = 1LL * a % b;
		swap(a, b);
	}
	return a;
}

ll lcm(ll a, ll b) {
	return 1LL * a / gcd(a, b) * b;
}

ll lcmAll(vector<ll>& nums, int n)
{
	ll ans = lcm(nums[0], nums[1]);
	if (ans == -1) return -1;
	for (int i = 2; i < n; ++i)
	{
		ans = lcm(ans, nums[i]);
		if (ans == -1) return -1;
	}
	return ans;
}

piir pairMin(piir a, piir b)
{
	if (a.first > 180) a.first = -(360 - a.first);
	else if(a.first < -180)  a.first = (360 + a.first);
	if (b.first > 180) b.first = -(360 - b.first);
	else if (b.first < -180)  b.first = (360 + b.first);
	if (abs(a.first) < abs(b.first)) return a;
	else return b;
}

int main()
{
	cout.precision(20);
	int a, b, c;
	cin >> a >> b >> c;
	real d = sqrt(b*b - 4 * a * c);
	real x1 = (-b + d) / (2*a);
	real x2 = (-b - d) / (2*a);
	cout << max(x1, x2) << endl << min(x1, x2) << endl;
	return 0;
}