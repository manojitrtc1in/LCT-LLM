#include <bits/stdc++.h>
 
using namespace std;
 
template<class T>
istream & operator >> (istream & is, vector<T> & v)
{
	for (auto & item : v)
		is >> item;
	return is; 
}
 
template<class T1, class T2>
istream & operator >> (istream & is, pair<T1, T2> & p)
{
	is >> p.first >> p.second;
	return is; 
}
 
template <template <typename, typename...> class V, typename... Args>
typename std::enable_if<!std::is_same<std::string, V<Args...>>::value, ostream &>::
type operator << (ostream & os, const V<Args...> & cont)
{
	for (const auto & item : cont)
		os << item << " ";
	os << endl;
	return os; 
}
 
template<class T1, class T2>
ostream & operator << (ostream & os, const pair<T1, T2> & p)
{
	os << p.first << ';' << p.second;
	return os; 
}
 
template<class T>
struct VectorHasher 
{
    T operator()(const vector<T> &V) const 
    {
        T hash = 0;
        for(size_t i = 0; i < V.size(); i++)
            hash ^= V[i];
        return hash;
    }
};

 
static int _ = [] {ios_base::sync_with_stdio(false); return 0; }();
 

class Bigint
{
	static const int BASE = 1e9;
	static const int BASE_DIGITS = 9;

	

	


	vector<int> repr;
	bool sign = false;

	Bigint abs() const  {
		return Bigint(repr, false);
	}

	void trim() {
		while(!repr.empty() and !repr.back())
			repr.pop_back();

		if (repr.empty())
			sign = false;
	}

	static inline vector<int> sum_repr(const vector<int> & a, const vector<int> & b) {
		vector<int> c(max(a.size(), b.size()) + 1, 0);

		for (int i = 0; i < a.size() or i < b.size(); i++)
		{
			int64_t sum = c[i];

			if (i < b.size())
				sum += b[i];

			if (i < a.size())
				sum += a[i];

			if (sum > (BASE - 1))
			{
				c[i + 1] += sum / BASE;
				c[i] = int(sum % BASE);
			}
			else
				c[i] = int(sum);
		}

		return c;
	}

	static inline vector<int> subtract_repr(vector<int> a, const vector<int> & b) {
		for (int i = 0; i < a.size(); i++)
		{
			if (i < b.size())
				a[i] -= b[i];

			if (a[i] < 0)
			{
				a[i + 1]--;
				a[i] += BASE;
			}
		}
		return a;
	}

	template<class T>
	friend typename std::enable_if<std::is_same<T, Bigint>::value, istream & >::
	type operator >> (istream & is, T & x);

	Bigint(vector<int> repr_, bool sign_) : repr(move(repr_)), sign(sign_) {
		if (repr.empty())
			repr = {0};
		if (repr.size() == 1 and repr[0] == 0)
			sign = false;
	}

public:

	Bigint() : sign(false) {
	}

	Bigint(const Bigint & other) : repr(other.repr), sign(other.sign) {
		trim();
	}

	Bigint(const string & s) {
		sign = s[0] == '-';
		int i = (int)s.size();
		int leftmost = 0;
		if (sign)
		{
			leftmost = 1;
			sign = true;
		}

		int step = (int) floor(log10(BASE));

		while(i > leftmost)
		{
			i -= step;
			int l = max(leftmost, i);
			const string & subs = s.substr(l, step + i - l);
			repr.push_back(stoi(subs));
		}

		trim();
	}

	Bigint(const int64_t & i) : Bigint(to_string(i)) {
	}

	

	Bigint & operator ++ () {
		(*this) = (*this) + 1;
		return *this;
	}

	

	const Bigint operator ++ (int) {
		Bigint tmp = *this;
		++(*this);
		return tmp;
	}

	

	Bigint & operator -- () {
		return ((*this) = ((*this) - 1));
	}

	

	const Bigint operator -- (int) {
		Bigint tmp = *this;
		--(*this);
		return tmp;
	}

	bool operator < (const Bigint & other) const {
		if (sign != other.sign)
			return sign;

		if (repr.size() != other.repr.size())
			return (repr.size() < other.repr.size()) ^ sign;

		for (int i = repr.size() - 1; i >= 0; i--) {
			if (repr[i] != other.repr[i])
				return (repr[i] < other.repr[i]) ^ sign;
		}

		return false;
	}

	bool operator > (const Bigint & other) const {
		return other < (*this);
	}

	bool operator <= (const Bigint & other) const {
		return !(*this > other);
	}

	bool operator >= (const Bigint & other) const {
		return !(*this < other);
	}

	bool operator != (const Bigint & other) const {
		return (*this < other) or (*this > other);
	}

	bool operator == (const Bigint & other) const {
		return !(*this != other);
	}

	friend bool operator == (const int64_t & left_int, const Bigint & right_long) {
		return right_long == left_int;
	}

	friend bool operator != (const int64_t & left_int, const Bigint & right_long) {
		return right_long != left_int;
	}

	Bigint operator + (Bigint other) const  {
		if (sign == other.sign)
		{
			other.repr = sum_repr(repr, other.repr);
		}
		else
		{
			if (this->abs() > other.abs())
			{
				other.repr = subtract_repr(this->repr, other.repr);
				other.sign = this->sign;
			}
			else
			{
				other.repr = subtract_repr(other.repr, this->repr);
				other.sign = !this->sign;
			}
		}

		other.trim();
		return other;
	}

	void operator += (const Bigint &v) {
		*this = *this + v;
	}

	Bigint operator - () const  {
		if (repr.empty())
			return *this;

		Bigint tmp = *this;
		tmp.sign = !tmp.sign;

		return tmp;
	}

	Bigint operator - (const Bigint & other) const {
		return *this + (-other);
	}

	void operator -= (const Bigint &v) {
		*this = *this - v;
	}

	static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
		vector<int64_t> p(max(old_digits, new_digits) + 1);

		p[0] = 1;
		for (int i = 1; i < (int) p.size(); i++)
			p[i] = p[i - 1] * 10;

		vector<int> res;
		int64_t cur = 0;
		int cur_digits = 0;

		for (int i = 0; i < (int) a.size(); i++)
		{
			cur += a[i] * p[cur_digits];
			cur_digits += old_digits;
			while (cur_digits >= new_digits)
			{
				res.push_back(int(cur % p[new_digits]));
				cur /= p[new_digits];
				cur_digits -= new_digits;
			}
		}

		res.push_back((int) cur);
		while (!res.empty() && !res.back())
			res.pop_back();

		return res;
	}

	inline static vector<int64_t> karatsuba_mult(const vector<int64_t> &a, const vector<int64_t> &b) 
	{
		size_t n = a.size();

		vector<int64_t> res(n * 2);

		if (n <= 32)
		{
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					res[i + j] += a[i] * b[j];
			return res;
		}

		size_t k = n >> 1;
		vector<int64_t> a1(a.begin(), a.begin() + k);
		vector<int64_t> a2(a.begin() + k, a.end());
		vector<int64_t> b1(b.begin(), b.begin() + k);
		vector<int64_t> b2(b.begin() + k, b.end());

		vector<int64_t> a1b1 = karatsuba_mult(a1, b1);
		vector<int64_t> a2b2 = karatsuba_mult(a2, b2);

		for (int i = 0; i < k; i++)
			a2[i] += a1[i];
		for (int i = 0; i < k; i++)
			b2[i] += b1[i];

		vector<int64_t> r = karatsuba_mult(a2, b2);
		for (int i = 0; i < (int) a1b1.size(); i++)
			r[i] -= a1b1[i];

		for (int i = 0; i < (int) a2b2.size(); i++)
			r[i] -= a2b2[i];

		for (int i = 0; i < (int) r.size(); i++)
			res[i + k] += r[i];

		for (int i = 0; i < (int) a1b1.size(); i++)
			res[i] += a1b1[i];

		for (int i = 0; i < (int) a2b2.size(); i++)
			res[i + n] += a2b2[i];

		return res;
	}

	Bigint operator * (const Bigint & v) const 
	{
		vector<int> a6 = convert_base(this->repr, BASE_DIGITS, 6);
		vector<int> b6 = convert_base(v.repr, BASE_DIGITS, 6);
		vector<int64_t> a(a6.begin(), a6.end());
		vector<int64_t> b(b6.begin(), b6.end());

		while (a.size() < b.size())
			a.push_back(0);

		while (b.size() < a.size())
			b.push_back(0);

		while (a.size() & (a.size() - 1))
			a.push_back(0), b.push_back(0);

		auto c = karatsuba_mult(a, b);
		Bigint res;

		res.sign = sign != v.sign;
		for (int i = 0, carry = 0; i < (int) c.size(); i++)
		{
			int64_t cur = c[i] + carry;
			res.repr.push_back((int) (cur % (int) 1e6));
			carry = (int) (cur / (int) 1e6);
		}

		res.repr = convert_base(res.repr, 6, BASE_DIGITS);

		res.trim();
		return res;
	}

	void operator *= (int v) 
	{
		if (v < 0)
			sign = -sign, v = -v;

		for (int i = 0, carry = 0; i < (int) repr.size() || carry; ++i)
		{
			if (i == (int) repr.size())
				repr.push_back(0);

			int64_t cur = repr[i] * (int64_t) v + carry;
			carry = (int) (cur / BASE);
			repr[i] = (int) (cur % BASE);
			

		}

		trim();
	}

	void operator *= (const Bigint &v) {
		*this = *this * v;
	}

	friend pair<Bigint, Bigint> divmod(const Bigint &a1, const Bigint &b1) 
	{
		int norm = BASE / (b1.repr.back() + 1);

		Bigint a = a1.abs() * norm;
		Bigint b = b1.abs() * norm;
		Bigint q, r;
		q.repr.resize(a.repr.size());

		for (int i = int(a.repr.size()) - 1; i >= 0; i--)
		{
			r *= BASE;
			r += a.repr[i];

			int s1 = r.repr.size() <= b.repr.size()     ? 0 : r.repr[b.repr.size()];
			int s2 = r.repr.size() <= b.repr.size() - 1 ? 0 : r.repr[b.repr.size() - 1];

			int d = ((int64_t) BASE * s1 + s2) / b.repr.back();
			r -= b * d;

			while (r < 0)
				r += b, --d;

			q.repr[i] = d;
		}

		q.sign = a1.sign != b1.sign;
		r.sign = a1.sign;
		q.trim();
		r.trim();

		return make_pair(q, r / norm);
	}

	friend pair<Bigint, Bigint> divmod(const Bigint &a1, int64_t b) 
	{
		bool b_sign = b < 0;
		b = std::abs(b);

		if (b == 0)
		{
			assert(false);
			return {0, 0};
		}

		assert(b < BASE);

		auto a = a1.repr;

		int64_t carry = 0;
		int64_t mod = 0;
		for (int i = int(a.size()) - 1; i >= 0; i--)
		{
			int64_t res = carry + a[i];
			mod = res % b;
			carry = mod * BASE;
			a[i] = int(res / b);
		}

		auto res = Bigint(a, a1.sign != b_sign);
		res.trim();
		return {res, mod};
	}

	Bigint operator / (const Bigint &v) const {
		return divmod(*this, v).first;
	}

	Bigint operator / (const int64_t & v) const {
		return divmod(*this, v).first;
	}

	void operator /= (const Bigint &v) {
		*this = *this / v;
	}

	Bigint operator % (const Bigint &v) const {
		return divmod(*this, v).second;
	}

	Bigint operator % (const int64_t &v) const {
		return divmod(*this, v).second;
	}

	void operator %= (const Bigint &v) {
		*this = *this % v;
	}

	Bigint pow(Bigint exp) const {
		Bigint a = (*this);
		Bigint p = 1;

		while(exp > 0)
		{
			if (exp % 2 == 1)
			{
				p = p * a;
				exp--;
			}
			else
			{
				a = a * a;
				exp = exp / 2;
			}
		}

		return p;
	}

	friend ostream & operator << (ostream & os, const Bigint & x) {
		if (x.sign)
			os << '-';

		os << (x.repr.empty() ? 0 : x.repr.back());


		for (int i = int(x.repr.size()) - 2; i >= 0 ; i--)
		{
			int fill_size = (int) ceil(log10(BASE + 1))
					- (int) ceil(log10(max(1, x.repr[i]) + 1)) - 1;

			if (fill_size > 0)
				os << string((size_t) fill_size, '0');
			os << x.repr[i];
		}

		return os;
	}

	template<class T>
	friend typename std::enable_if<std::is_same<T, Bigint>::value, istream & >::
	type operator >> (istream & is, T & x) {
		string s;
		is >> s;
		x = Bigint(s);
		return is;
	}

	int64_t to_int()
	{
		if(repr.empty())
			return 0;
		return repr.front() * (sign ? -1 : 1);
	}

	Bigint sqrt() const
	{
		Bigint l = 1, r = *this / 2 + 1;

		while(l < r)
		{
			Bigint m = l + (r - l) / 2;
			if ((m * m) < *this)
				l = m + 1;
			else
				r = m;
		}

		if (l * l > *this)
			return l - 1;
		return l;
	}

	Bigint log(const Bigint & base) const 
	{
		if (base < 2)
			throw std::range_error("Unsupported logarithm base");

		Bigint l = 0, r = (repr.size() + 1) * BASE_DIGITS - (base.repr.size()  * BASE_DIGITS);

		while(l < r)
		{
			Bigint m = l + (r - l) / 2;
			Bigint p = base.pow(m);
			if (p < *this)
				l = m + 1;
			else
				r = m;
		}

		if (base.pow(l) > *this)
			return l - 1;
		return l;
	}
};



int main()
{



#ifndef ONLINE_JUDGE
	ifstream ifs("input.txt");
	#define cerr cout
	#define cin ifs
#else
	#define cerr if (false) cerr
#endif


	int n;
	while(cin >> n)
	{
		int m = 2 * 3 * 5 * 7;

		if (n < 3)
		{
			cout << -1 << endl;
		}
		else
		{
			Bigint x = 10;
			x = x.pow(n - 1);
			x = (x / m + 1) * m;
			cout << x << endl;
		}
		
#ifdef ONLINE_JUDGE
		break;
#endif
		cout << "------------------------\n";
	}

	return 0;
}