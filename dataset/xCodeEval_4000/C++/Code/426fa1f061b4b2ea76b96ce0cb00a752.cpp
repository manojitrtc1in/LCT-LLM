#ifndef _LOCAL
#	define NDEBUG
#	define dprint(...)
#endif

#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;
typedef long long ll;


#include <cstring>
#include <cmath>
#include <assert.h>


template<int base>
class BigIntT
{
	template<int Y, int X>
	struct PowerOf
	{
		

		

		

		template<int B = Y, int A = X>
		static constexpr typename std::enable_if<B != 1 && A != 1 && B%A == 0, int>::type
		solve()
		{
			return PowerOf<B/A,A>::solve() + 2;
		}

		template<int B = Y, int A = X>
		static constexpr typename std::enable_if<B == 1 || A == 1 || B%A != 0, int>::type
		solve()
		{
			return B == 1 ? 1: 0;
		}
	};

public:
	std::vector<int> dig;
	int sign;

	int len() const
	{
		return (int)dig.size();
	}
	
	bool is_zero() const
	{
		return !len();
	}
	
	void reserve_digits(int k)
	{
		dig.resize(k, 0);
	}
	
	void correct()
	{
		while(len() > 0 && !dig.back())
			dig.pop_back();
		if(dig.empty())
			sign = 1;
	}
	
	static void sum_unsigned(BigIntT &a, const BigIntT &b)
	{
		int i;
		int x,y;

		if(a.len() < b.len())
		{
			a.reserve_digits(b.len());
		}

		for(i=0,x=0; i<b.len(); i++)
		{
			y = a.dig[i] + b.dig[i] + x;
			a.dig[i] = y % base;
			x = y / base;
		}

		for(; x && i<a.len(); i++)
		{
			y = a.dig[i] + x;
			a.dig[i] = y % base;
			x = y / base;
		}

		if(x)
			a.dig.push_back(x);
	}
	
	static void sub_unsigned(BigIntT &a, const BigIntT &b, int shifta = 0)
	{
		assert(!less_unsigned(a,b));
		int i;
		int x,y;
		assert(b.len() <= (a.len()-shifta));
		
		for(i=0,x=0; i<b.len(); ++i)
		{
			y = base + a.dig[i+shifta] - b.dig[i] - x;
			assert(0 <= y);
			a.dig[i+shifta] = y % base;
			x = 1 - y / base;
			assert(x == 0 || x == 1);
		}

		i += shifta;
		for(; x && i<a.len(); ++i)
		{
			y = base + a.dig[i] - x;
			assert(0 <= y);
			a.dig[i] = y % base;
			x = 1 - y / base;
		}
		assert(x == 0);
		
		a.correct();
	}

	static bool less_unsigned(const BigIntT &a, const BigIntT &b)
	{
		if(a.len() != b.len())
			return a.len() < b.len();

		for(int i=a.len()-1; 0<=i; --i)
			if(a.dig[i] != b.dig[i])
				return a.dig[i] < b.dig[i];

		return false;
	}
	
	static void div_(const BigIntT &a, const BigIntT &b, BigIntT *ax, BigIntT *dx)
	{
		assert(!b.is_zero());
		assert(dx);
		if(ax) *ax = 0;
		*dx = a;
		BigIntT &c = *dx;
		c.sign = 1;
		
		for(int i=c.len()-1; b.len()-1<=i; --i)
		{
			if(ax) *ax *= base;
			
			while(i < c.len())
			{
				long long y = (c.get_dig(i+1)*1LL*base + c.dig[i]);
				int q = (int)(y / (b.dig.back() + 1));
				assert(0 <= q);
				if(q == 0)
					break;
				if(ax) *ax += q;
				sub_unsigned(c, b*q, i-b.len()+1);
			}
			assert(c.get_dig(i+1) == 0);
		}
		if(b <= c)
		{
			c -= b;
			if(ax) *ax += 1;
		}
		
		if(ax)
		{
			ax->sign = a.sign * b.sign;
		}
		assert(c < b);
	}

	static void div(const BigIntT &a, BigIntT b, BigIntT *ax, BigIntT *dx)
	{
		if(256 < a.len() - b.len())
		{
			int m = (a.len() - b.len()) / 2;
			BigIntT aa(a.dig.begin()+m, a.dig.end());
			BigIntT q;
			

			

			

			div(aa, b, &q, dx);
			

			
			BigIntT c = a;
			c.sign = 1;
			

			sub_unsigned(c, b*q, m);
			

			div(c, b, ax, dx);
			if(ax)
			{
				*ax += q.shifted(m);
				ax->sign = a.sign * b.sign;
			}
			return;
		}
		
		assert(!b.is_zero());
		assert(dx);
		if(ax) *ax = 0;
		*dx = a;
		BigIntT &c = *dx;
		c.sign = 1;
		
		assert(1 < b.len());
		long long x = b.dig.back()*1.0*base + b.dig[b.len()-2] + 1;
		
		for(int i=c.len()-1; b.len()-1<=i; --i)
		{
			if(ax) *ax *= base;
			
			while(i < c.len())
			{
				

				

				double y = (c.get_dig(i+1)*1LL*base + c.dig[i])*1.0*base;
				int q = (int)floor(y/x);

				assert(0 <= q);
				if(q == 0)
					break;
				if(ax) *ax += q;
				sub_unsigned(c, b*q, i-b.len()+1);
			}
			assert(c.get_dig(i+1) == 0);
		}
		if(b <= c)
		{
			c -= b;
			if(ax) *ax += 1;
		}
		
		if(ax)
		{
			ax->sign = a.sign * b.sign;
		}
		assert(c < b);
	}

	BigIntT shifted(int k) const
	{
		BigIntT res(0);
		res.reserve_digits(len()+k);
		
		for(int i=res.len()-1; k<=i; --i)
		{
			res.dig[i] = dig[i-k];
		}
		
		return res;
	}
	
	void read_from_compatible_base(int sbase, const char *s, int slen)
	{
		assert(dig.empty());
		
		int x = 0, spw = 1;
		for(const char *c = s+slen-1; s<=c; --c)
		{
			int d = *c - '0';
			assert(0 <= d && d < sbase);
			x += spw * d;
			spw *= sbase;
			if(spw == base || s == c)
			{
				dig.push_back(x);
				x = 0;
				spw = 1;
			}
		}
		
		correct();
	}
	
	void read_from_any_base(int sbase, const char *s)
	{
		assert(dig.empty());
		
		for(; *s;)
		{
			int x = 0, p10 = 1, max_int = 1<<30;
			for(int j=0; *s && sbase <= max_int; ++s,++j)
			{
				int d = *s - '0';
				if(10 < sbase && 'a' <= *s && *s <= 'z')
					d = 10 + *s - 'a';
				else if(10 < sbase && 'A' <= *s && *s <= 'Z')
					d = 10 + *s - 'A';
				assert(0 <= d && d < sbase);
				x = sbase*x + d;
				p10 *= sbase;
				max_int /= sbase;
			}
			
			*this *= p10;
			*this += x;
		}
	}
	
	static constexpr bool is_base_power_of_10()
	{
		return PowerOf<base,10>::solve() & 1;
		

	}
	
	static constexpr int base_log10()
	{
		return PowerOf<base,10>::solve() >> 1;
	}
	
public:
	BigIntT()
		: sign(1)
	{
	}

	BigIntT(int x)
	{
		sign = 1;
		if(x < 0)
		{
			x = -x;
			sign = -1;
		}
		for(; x; x/=base)
			dig.push_back(x % base);
		correct();
	}

	BigIntT(long long x)
	{
		sign = 1;
		if(x < 0)
		{
			x = -x;
			sign = -1;
		}
		for(; x; x/=base)
			dig.push_back(x % base);
		correct();
	}
	
	BigIntT(const std::string &s)
		: sign(1)
	{
		read(10, s.c_str());
	}
	
	BigIntT(const char *s)
		: sign(1)
	{
		read(10, s);
	}
	
	template<typename Iterator>
	BigIntT(const Iterator dig_beg, const Iterator dig_end)
		: sign(1)
		, dig(dig_beg, dig_end)
	{
		correct();
	}
	

	
	explicit operator int() const
	{
		int res = 0;
		for(int i=len(); i--;)
		{
			assert(res*1LL*base < 2000000000);
			res *= base;
			res += dig[i];
		}
		return res;
	}
	
	BigIntT& operator+=(const BigIntT &b)
	{
		BigIntT &a = *this;
		if(sign == b.sign)
		{
			sum_unsigned(a, b);
		}
		else
		{
			if(less_unsigned(a, b))
			{
				BigIntT c = b;
				sub_unsigned(c, a);
				a.swap(c);
			}
			else
			{
				sub_unsigned(a, b);
			}
		}
		
		return a;
	}

	BigIntT operator+(const BigIntT &b) const
	{
		BigIntT r = *this;
		return r += b;
	}

	BigIntT operator-() const
	{
		if(is_zero())
			return *this;
		BigIntT r = *this;
		r.sign = -r.sign;
		return r;
	}

	BigIntT& operator-=(const BigIntT &b)
	{
		BigIntT &a = *this;
		if(sign != b.sign)
		{
			sum_unsigned(a, b);
		}
		else
		{
			if(less_unsigned(a, b))
			{
				BigIntT c = b;
				sub_unsigned(c, a);
				a.swap(c);
				a.sign = -a.sign;
			}
			else
			{
				sub_unsigned(a, b);
			}
		}

		return a;
	}

	BigIntT operator-(const BigIntT &b) const
	{
		BigIntT r = *this;
		return r -= b;
	}

	BigIntT& operator*=(const BigIntT &b)
	{
		BigIntT &a = *this;
		a = a*b;
		return a;
	}

	BigIntT karatsuba_multiply(const BigIntT &b) const
	{
		const BigIntT &a=*this;
		int m = std::max(a.len(), b.len()) / 2;
		
		BigIntT x1(a.dig.begin() + std::min(m,a.len()), a.dig.end());
		BigIntT x2(a.dig.begin(), a.dig.begin() + std::min(m,a.len()));
		BigIntT y1(b.dig.begin() + std::min(m,b.len()), b.dig.end());
		BigIntT y2(b.dig.begin(), b.dig.begin() + std::min(m,b.len()));
		
		BigIntT f = x1*y1;
		BigIntT g = x2*y2;
		x1 += x2;
		y1 += y2;
		BigIntT h = x1*y1;
		h -= f;
		h -= g;
		g += f.shifted(m+m);
		g += h.shifted(m);
		g.sign = sign * b.sign;
		return g;
	}
	
	BigIntT operator*(const BigIntT &b) const
	{
		if(b.len() <= 1)
			return *this * int(b);

		if(32 < std::min(len(), b.len()))
			return karatsuba_multiply(b);
		
		const BigIntT &a=*this;
		BigIntT c;

		c.reserve_digits(a.len() + b.len());

		for(int i=0; i<a.len(); ++i)
		{
			int x = 0;
			for(int j=0; j<b.len(); ++j)
			{
				long long y = c.dig[i+j] + a.dig[i]*1LL*b.dig[j] + x;
				c.dig[i+j] = y % base;
				x = (int)(y / base);
			}
			c.dig[i+b.len()] += x;
		}

		c.sign = a.sign * b.sign;

		c.correct();

		return c;
	}

	BigIntT operator*(int b) const
	{
		BigIntT r = *this;
		return r *= b;
	}

	BigIntT &operator*=(int b)
	{
		if(b == 0)
			return *this = BigIntT(0);

		if(b < 0)
		{
			sign = -sign;
			b = -b;
		}

		if(b == 1)
			return *this;

		int x = 0;
		for(int i=0; i<len(); i++)
		{
			long long y = dig[i]*1LL*b + x;
			dig[i] = y % base;
			x = y / base;
		}

		assert(x < base);
		if(x)
			dig.push_back(x % base);
		
		correct();
		return *this;
	}

	BigIntT operator/(int b) const
	{
		BigIntT r = *this;
		return r /= b;
	}

	BigIntT &operator/=(int b)
	{
		assert(b);
		if(b < 0)
		{
			b = -b;
			sign = -sign;
		}
		
		if(b == 1)
			return *this;

		int x = 0;
		for(int i=len()-1; 0<=i; --i)
		{
			long long y = (x*1LL*base + dig[i]);
			assert(base > y/b);
			dig[i] = (int)(y / b);
			x = y % b;
		}

		correct();

		return *this;
	}

	int get_dig(int i)
	{
		if(i < len())
			return dig[i];
		return 0;
	}
	
	BigIntT& operator/=(const BigIntT &b)
	{
		BigIntT &a = *this;
		a = a/b;
		return a;
	}

	BigIntT operator/(const BigIntT &b) const
	{
		if(b.len() <= 1)
			return *this / int(b);
		
		BigIntT cx;
		BigIntT dx = *this;
		div(*this, b, &cx, &dx);
		
		return cx;
	}
	
	BigIntT& operator%=(const BigIntT &b)
	{
		BigIntT &a = *this;
		return a = a%b;
	}

	BigIntT operator%(const BigIntT &b) const
	{
		if(b.len() <= 1)
			return *this % int(b);
		
		BigIntT dx = *this;
		div(*this, b, nullptr, &dx);
		return dx;
	}
	
	BigIntT& operator%=(int b)
	{
		BigIntT &a = *this;
		return a = a%b;
	}

	int operator%(int b) const
	{
		assert(0 < b);
		if(b < 0)
			b = -b;
		
		if(len() && base % b == 0)
			return dig[0] % b;

		int x = 0;
		for(int i=len()-1; 0<=i; --i)
		{
			x = (x*1LL*base + dig[i]) % b;
		}

		return x;
	}

	bool operator==(const BigIntT &b) const
	{
		if(sign != b.sign || len() != b.len())
			return false;

		for(int i=0; i<len(); ++i)
			if(dig[i] != b.dig[i])
				return false;
		return true;
	}

	bool operator!=(const BigIntT &b) const
	{
		return !(*this == b);
	}
	
	bool operator<(const BigIntT &b) const
	{
		if(sign != b.sign)
			return sign < b.sign;
		bool less = less_unsigned(*this, b);
		if(sign < 0)
			return !less;
		return less;
	}

	bool operator<=(const BigIntT &b) const
	{
		return !(b < *this);
	}
	
	bool operator>(const BigIntT &b) const
	{
		return b < *this;
	}
	
	bool operator>=(const BigIntT &b) const
	{
		return !(*this < b);
	}
	
	BigIntT& operator &=(const BigIntT &b)
	{
		static_assert(base & (base-1) == 0,
			"Bitwise operations implemented only for base = 2^^k");
		

		return *this;
	}
	
	void read(int sbase, const char *s)
	{
		sign = 1;
		dig.clear();

		if(*s == 0)
			return;
		
		int i = 0;
		if(*s && s[0] == '-')
			++i;

		if(sbase == 10 && is_base_power_of_10())
			read_from_compatible_base(sbase, s+i, strlen(s)-i);
		else
			read_from_any_base(sbase, s+i);
			
		if(*s && s[0] == '-')
			sign = -1;
	}
	
	void read(std::istream& is)
	{
		std::string s;
		is >> s;
		read(10, s.c_str());
	}
	
	std::string write(int sbase) const
	{
		std::string s;

		if(len() == 0)
		{
			s += '0';
			return s;
		}

		int mod = 1;
		int ndig0 = 0;
		if(!(sbase == 10 && is_base_power_of_10()))
		{
			while(mod*1LL*sbase <= (1<<30))
			{
				mod *= sbase;
				++ndig0;
			}
		}
		
		BigIntT a(*this);
		int i = 0;
		while(i < a.len())
		{
			int ndig = ndig0;
			int x;
			if(sbase == 10 && is_base_power_of_10())
			{
				ndig = base_log10();
				x = a.dig[i++];
			}
			else
			{
				x = a % mod;
				a /= mod;
			}
			
			for(int i=0; i<ndig; ++i)
			{
				int d = x%sbase;
				if(d < 10)
					s += '0' + d;
				else
					s += 'A' + d-10;
				x /= sbase;
			}
		}

		while(!s.empty() && s.back() == '0')
			s.pop_back();

		if(sign < 0)
			s += "-";		

		std::reverse(s.begin(), s.end());
		return s;
	}
	
	void write(std::ostream& s) const
	{
		s << write(10);
	}

	void swap(BigIntT &b)
	{
		std::swap(dig, b.dig);
		std::swap(sign, b.sign);
	}	
};

template<int base>
std::istream& operator>>(std::istream& s, BigIntT<base> &a)
{
	a.read(s);
	return s;
}

template<int base>
std::ostream& operator<<(std::ostream& s, const BigIntT<base> &a)
{
	a.write(s);
	return s;
}

template<int base>
bool operator<(long long b, const BigIntT<base> &a)
{
	return (BigIntT<base>(b) < a);
}

template<int base>
bool operator<=(long long b, const BigIntT<base> &a)
{
	return !(a < b);
}

template<int base>
bool operator>(long long b, const BigIntT<base> &a)
{
	return (a < b);
}

template<int base>
bool operator>=(long long b, const BigIntT<base> &a)
{
	return (a <= b);
}

template<int base>
bool operator==(long long b, const BigIntT<base> &a)
{
	return (a == b);
}

template<int base>
bool operator!=(long long b, const BigIntT<base> &a)
{
	return (a != b);
}

typedef BigIntT<1000000000> BigInt;


template<class T>
T pow(T x, int power)
{
	T res = 1;

	for(T b=x; power; power/=2)
	{
		if(power%2)
			res *= b;
		b *= b;
	}

	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	
	int len;
	string x;
	cin >> len >> x;
	BigInt p10 = 1;
	BigInt ans(x);
	int len1, len2;
	for(len1=len/2; 0<len1 && '0' == x[len1]; --len1);
	for(len2=len/2+1; len2<len && '0' == x[len2]; ++len2);
	
	BigInt a(x);
	for(int i=len1; i<=len2; i+=len2-len1)
	{
		p10 = pow(BigInt(10), len-i);
		BigInt high = a / p10;
		BigInt low = a % p10;
		

		ans = min(ans, low+high);
	}
	
	cout << ans << "\n";

	return 0;
}
