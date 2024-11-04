



#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <memory.h>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <string.h>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>




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




#define EXTRA_MEMORY 3

#define FOR(i, s, f) for (auto (i) = (s); (i) < (f); ++(i))
#define ROF(i, f, s) for (auto (i) = (f) - 1; (i) >= (s); --(i))

#define forn(i, f) FOR((i), 0LL, (f))
#define rofn(i, f) ROF((i), (f), 0LL)

#define rep(i, s, f) FOR((i), (s), (f) + 1)
#define per(i, s, f) ROF((i), (f) + 1, (s))

#define forit(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

#define ALL(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

#define PREF_TASK ""
#define SUFF_TASK ""



























#define sci(a) scanf("%d", &(a))
#define scii(a, b) scanf("%d%d", &(a), &(b))
#define sciii(a, b, c) scanf("%d%d%d", &(a), &(b), &(c))

#define scid(a) int (a); sci(a)
#define sciid(a, b) int (a), (b); scii((a), (b))
#define sciiid(a, b, c) int (a), (b), (c); sciii((a), (b), (c))

#define scvi(a) forn(it_for_scaning, sz(a)) sci((a)[it_for_scaning])
#define scvin(a, n) forn(it_for_scaning, (n)) sci((a)[it_for_scaning])
#define scvind(a, n) vi a(n); scvin((a), (n))
#define scvinds(a, n) vi a((n) + EXTRA_MEMORY); scvin((a), (n))

#define scvivi(a) forn(it_for_scaning, min(sz(a), sz(b))) scii((a)[it_for_scaning], (b)[it_for_scaning])
#define scvivin(a, b, n) forn(it_for_scaning, (n)) scii((a)[it_for_scaning], (b)[it_for_scaning])
#define scvivind(a, b, n) vi a(n), b(n); scvivin((a), (b), (n))
#define scvivinds(a, b, n) vi a((n) + EXTRA_MEMORY), b((n) + EXTRA_MEMORY); scvivin((a), (b), (n))

#define scsin(a, n) forn(it_for_insertion, (n)) (a).insert(next_int())

#define prnl printf("\n")

#define pri(a) printf("%d ", (a))
#define prii(a, b) printf("%d %d ", (a), (b))
#define priii(a, b, c) printf("%d %d %d ", (a), (b), (c))

#define prinl(a) printf("%d\n", (a))
#define priinl(a, b) printf("%d %d\n", (a), (b))
#define priiinl(a, b, c) printf("%d %d %d\n", (a), (b), (c))

#define prvi(a) forn(it_for_printing, sz(a)) pri((a)[it_for_printing])
#define prvinl(a) forn(it_for_printing, sz(a)) prinl((a)[it_for_printing])
#define prvin(a, n) forn(it_for_printing, (n)) pri((a)[it_for_printing])
#define prvinnl(a, n) forn(it_for_printing, (n)) prinl((a)[it_for_printing])

#define FILL(a, x) memset((a), (x), sizeof(a))
#define FILLN(a, n, x) memset((a), (x), (n) * sizeof(*(a)))
#define cl(a) FILL((a), 0)
#define cln(a, n) FILLN((a), (n), 0)

#define rmin(a, b) (a) = min((a), (b))
#define rmax(a, b) (a) = max((a), (b))

#define modFix(a, MOD) ((((a) % (MOD)) + (MOD)) % (MOD))
#define modSum(a, b, MOD) modFix(((a) + (b)), (MOD))


#define modSub(a, b, MOD) modFix(((a) - (b)), (MOD))
#define modMul(a, b, MOD) modFix(((ll)(a) * (ll)(b)), (MOD))

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define cout_prec cout.precision(30);




template<class T, class U> inline void relax_min(T &a, U b) { a = min(a, b); }
template<class T, class U> inline void relax_max(T &a, U b) { a = max(a, b); }

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




cint MAXN1 = (int)1e5 + EXTRA_MEMORY;
cint MAXN2 = (int)2e5 + EXTRA_MEMORY;
cint MAXN3 = (int)3e5 + EXTRA_MEMORY;
cint MAXN4 = (int)4e5 + EXTRA_MEMORY;
cint MAXN5 = (int)5e5 + EXTRA_MEMORY;



cint INF = (int)1e9 + 7;
cint INF2 = 1 << 30;
cll INFLL = (ll)4e18 + 7;
cll INFLL2 = 1LL << 60;

cld Pi = acos(-1.0);
cld eps = 1e-7;

cint mod = (int)1e9 + 7;










#include <time.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR(i, s, f) for (int i = (s); i < (f); ++i)
#define ROF(i, f, s) for (int i = (f) - 1; i >= (s); --i)
#define forn(i, f) FOR(i, 0, f)
#define rofn(i, f) ROF(i, f, 0)
#define forit(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)
#define ALL(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())


typedef const int cint;
typedef long long ll;
typedef vector < int > vi;


cint MAX_NUMBER = 1e2;
cint MAX_N = 200;


#define EJUDGE

#ifdef EJUDGE
#include <iostream>
cint NUM_TESTS = 1;
#else
#include <fstream>
cint NUM_TESTS = 40;
#define cin fin
#define cout fout
#endif


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
#ifdef FILEIO
	ifstream in(PREF_TASK"in"SUFF_TASK);
	ofstream out(PREF_TASK"out"SUFF_TASK);
#endif

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

#ifdef FILEIO
	in.close();
	out.close();
#endif
	return 0;
}
