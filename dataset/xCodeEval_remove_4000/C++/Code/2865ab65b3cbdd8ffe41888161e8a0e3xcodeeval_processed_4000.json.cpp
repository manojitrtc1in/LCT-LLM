


























using namespace std;




typedef const int cint;
typedef unsigned int uint;
typedef long long ll;
typedef const long long cll;
typedef unsigned long long ull;
typedef long double ld;
typedef const long double cld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<string> vs;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<pld> vpld;
typedef set<int> si;
typedef set<ll> sll;
typedef set<ld> sld;
typedef set<string> ss;
typedef map<int, int> mi;
typedef map<ll, ll> mll;
typedef map<int, ll> mill;
typedef map<ll, int> mlli;
typedef map<int, string> mis;
typedef map<string, int> msi;









































































































template<class T, class U> inline void id0(T &a, U b) { a = min(a, b); }
template<class T, class U> inline void id5(T &a, U b) { a = max(a, b); }

template<typename T> inline bool updmax(T &a, const T &b){ return a < b ? a = b, 1 : 0; }
template<typename T> inline bool updmin(T &a, const T &b){ return a > b ? a = b, 1 : 0; }

template<class T, class U> istream &operator>>(istream &in, pair<T, U> &a)
{
	in >> a.first >> a.second;
	return in;
}

template<class T, class U> ostream &operator<<(ostream &out, const pair<T, U> &a)
{
	out << a.first << ' ' << a.second;
	return out;
}

template<class T> istream &operator>>(istream &in, vector<T> &a)
{
	forn(i, sz(a))
		in >> a[i];
	return in;
}

template<class T> ostream &operator<<(ostream &out, const vector<T> &a)
{
	forn(i, sz(a))
		out << a[i] << ' ';
	return out;
}

int next_int()
{
	scid(tmp);
	return tmp;
}

ll modPow(ll a, ll b, ll MOD){
	ll ret = 1;
	for (; b; b >>= 1)
	{
		if (b & 1)
			ret = modMul(ret, a, MOD);
		a = modMul(a, a, MOD);
	}
	return ret;
}




cint id7 = (int)1e5 + EXTRA_MEMORY;
cint id8 = (int)2e5 + EXTRA_MEMORY;
cint id6 = (int)3e5 + EXTRA_MEMORY;
cint id2 = (int)4e5 + EXTRA_MEMORY;
cint id1 = (int)5e5 + EXTRA_MEMORY;



cint INF = (int)1e9 + 7;
cint INF2 = 1 << 30;
cll INFLL = (ll)4e18 + 7;
cll id3 = 1LL << 60;

cld Pi = acos(-1.0);
cld eps = 1e-7;

cint mod = (int)1e9 + 7;















using namespace std;










typedef const int cint;
typedef long long ll;
typedef vector < int > vi;


cint MAX_NUMBER = 1e2;
cint MAX_N = 200;






cint id4 = 1;


cint id4 = 40;





class BigInt
{
	static const int base = 1000 * 1000 * 1000;
	bool sign;
	vi number;

public:
	static ll count_num_operations;  


	enum
	{
		positive = 0,
		negative = 1,
	};

	BigInt(const string & $number)
	{
		sign = positive;

		int n = sz($number);

		if (n == 0)
			return;

		int start = 0;
		if ($number[0] == '-')
		{
			sign = negative;
			start = 1;
		}

		for (int i = n; i > start; i -= 9)
		{
			if (i - start < 9)
				number.push_back(stoi($number.substr(start, i)));
			else
				number.push_back(stoi($number.substr(i - 9, 9)));
		}

		

	}

	BigInt(int $number)
	{
		sign = positive;
		if ($number < 0)
		{
			sign = negative;
			$number = -$number;
		}

		do
		{
			number.push_back($number % base);
			$number /= base;
		} while ($number > 0);
	}

	BigInt() : sign(positive) {}

	BigInt(const BigInt & a)
	{
		sign = a.sign;
		number = a.number;
	}

	

	

	size_t size() const
	{
		return number.size();
	}

	BigInt operator = (const ll a)
	{
		*this = BigInt(a);
		return *this;
	}

	BigInt operator = (const string & a)
	{
		*this = BigInt(a);
		return *this;
	}

	bool operator < (const BigInt & a) const
	{
		if (size() == 1 && a.size() == 1 && number[0] == 0 && a.number[0] == 0)
			return false;

		if (sign == positive && a.sign == negative)
			return false;
		if (sign == negative && a.sign == positive)
			return true;

		bool is_less;

		if (size() < a.size())
			is_less = true;
		else if (size() == a.size())
		{
			int n = size();

			bool are_equal = true;
			rofn(i, n)
			{
				if (number[i] != a.number[i])
				{
					is_less = number[i] < a.number[i];
					are_equal = false;
					break;
				}
			}

			if (are_equal)      

				return false;  

		}
		else
			is_less = false;

		if (sign == negative)
			is_less = !is_less;

		return is_less;
	}

	bool operator > (const BigInt & a) const
	{
		return a < *this;
	}

	bool operator == (const BigInt & a) const
	{
		return !(*this < a || a < *this);
	}

	bool operator <= (const BigInt & a) const
	{
		return (*this < a) || (*this == a);
	}

	bool operator >= (const BigInt & a) const
	{
		return (*this > a) || (*this == a);
	}

	bool operator != (const BigInt & a) const
	{
		return !(*this == a);
	}

	BigInt operator - () const
	{
		BigInt result = *this;

		if (sign == positive)
			result.sign = negative;
		else
			result.sign = positive;

		return result;
	}

	BigInt operator + (const BigInt & a) const
	{
		++count_num_operations;

		if (sign == a.sign)
		{
			BigInt result;
			result.sign = sign;

			int carry = 0;
			int n = size();
			int m = a.size();

			forn(i, max(n, m) + 1)
			{
				int cur_digit = carry;
				if (i < sz(number))
					cur_digit += number[i];
				if (i < sz(a.number))
					cur_digit += a.number[i];

				carry = cur_digit / base;
				cur_digit %= base;

				if (!(cur_digit == 0 && i == max(n, m)))
					result.number.push_back(cur_digit);
			}

			return result;
		}
		else
		{
			if (sign == negative)
				return a - (-(*this));
			else
				return *this - (-a);
		}
	}

	BigInt operator - (const BigInt & a) const
	{
		if (*this == a)
			return 0;

		if (sign == a.sign)
		{
			if (a.sign == negative)
				return (-a) - (-(*this));

			BigInt result;

			BigInt fir = *this;
			BigInt sec = a;
			if (fir < sec)
			{
				swap(fir, sec);
				result.sign = negative;
			}

			int carry = 0;
			int n = sz(fir);
			int m = sz(sec);

			forn(i, max(n, m))
			{
				int cur_digit = i < n ? fir.number[i] : 0;
				cur_digit -= i < m ? sec.number[i] : 0;
				cur_digit -= carry;

				if (cur_digit < 0)
				{
					cur_digit += base;
					carry = 1;
				}
				else
					carry = 0;

				result.number.push_back(cur_digit);
			}

			result.delete_zeros();

			return result;
		}
		else
		{
			if (sign == negative)
				return -((-(*this)) + a);
			else
				return *this + (-a);
		}
	}

	BigInt operator * (const BigInt & a) const
	{
		BigInt result;

		result.number.resize(size() + a.size());

		int n = size();
		int m = a.size();

		

		

		

		

		


		

		

		

		

		

		

		


		

		


		

		


		

		


		

		


		for (int i = 0; i < n; ++i)
		{
			for (int j = 0, carry = 0; j < m || carry; ++j)
			{
				ll cur = result.number[i + j] + number[i] * 1LL * (j < m ? a.number[j] : 0) + carry;
				result.number[i + j] = (int)(cur % base);
				carry = (int)(cur / base);
			}
		}

		result.delete_zeros();

		if (sign != a.sign)
			result.sign = negative;

		return result;
	}

	BigInt operator / (const BigInt & a) const
	{
		BigInt result;

		if (sign != a.sign)
			result.sign = negative;

		BigInt sec = a;
		sec.sign = positive;

		int n = size();

		BigInt cur_value;
		rofn(i, n)
		{
			cur_value.number.insert(cur_value.number.begin(), number[i]);
			cur_value.delete_zeros();

			int bin_left = 0, bin_right = base;

			while (bin_right - bin_left > 1)
			{
				int bin_middle = (bin_left + bin_right) / 2;

				if (sec * bin_middle <= cur_value)
					bin_left = bin_middle;
				else
					bin_right = bin_middle;
			}

			cur_value = cur_value - sec * bin_left;

			result.number.push_back(bin_left);
		}

		reverse(ALL(result.number));

		result.delete_zeros();

		return result;
	}

	BigInt operator % (const BigInt & a) const
	{
		return *this - a * (*this / a);
	}

	int operator()() const
	{
		ll ret = 0;
		for (int i = 0; i < int(number.size()); ++i)
			ret = base * ret + number[i];

		return ret;
	}

	void delete_zeros()
	{
		while (number.size() > 1 && number.back() == 0)
			number.pop_back();

		if (*this == 0)
			sign = positive;
	}

	friend istream & operator >> (istream & in, BigInt & a);
	friend ostream & operator << (ostream & out, const BigInt & a);
	friend BigInt abs(const BigInt & a);
};

istream & operator >> (istream & in, BigInt & a)
{
	string tmp;
	in >> tmp;
	a = BigInt(tmp);

	return in;
}

ostream & operator << (ostream & out, const BigInt & a)
{
	if (a.sign == BigInt::negative)
		out << "-";

	vi tmp = a.number;
	reverse(ALL(tmp));

	

	


	out << tmp[0];
	FOR(i, 1, sz(tmp))
		out << to_string(1000000000 + tmp[i]).substr(1);


	return out;
}

BigInt abs(const BigInt & a)
{
	BigInt result = a;
	result.sign = BigInt::positive;

	return result;
}

ll BigInt::count_num_operations = 0;










int main()
{

	ifstream in(PREF_TASK"in"SUFF_TASK);
	ofstream out(PREF_TASK"out"SUFF_TASK);


	scid(N);




	ll c = 2;
	cout << 2 << endl;
	FOR(i, 3LL, N + 2)
	{
		


		ll k = i - 1;

		


		


		


		



		

		

		

		

		

		

		

		

		


		


		


		


		

		
		ll ii = i;
		ll ww = (2 - i) + ii * ii * (ii - 1);
		c = i * (i - 1);

		

		printf("%lld\n", ww);
		

	}


	in.close();
	out.close();

	return 0;
}
