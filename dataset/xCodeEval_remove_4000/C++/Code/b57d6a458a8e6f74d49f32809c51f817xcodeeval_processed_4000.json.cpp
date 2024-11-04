











using namespace std;
typedef long long ll;








template<int base>
class id1
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
	
	static void sum_unsigned(id1 &a, const id1 &b)
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
	
	static void sub_unsigned(id1 &a, const id1 &b, int id2 = 0)
	{
		assert(!less_unsigned(a,b));
		int i;
		int x,y;
		assert(b.len() <= (a.len()-id2));
		
		for(i=0,x=0; i<b.len(); ++i)
		{
			y = base + a.dig[i+id2] - b.dig[i] - x;
			assert(0 <= y);
			a.dig[i+id2] = y % base;
			x = 1 - y / base;
			assert(x == 0 || x == 1);
		}

		i += id2;
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

	static bool less_unsigned(const id1 &a, const id1 &b)
	{
		if(a.len() != b.len())
			return a.len() < b.len();

		for(int i=a.len()-1; 0<=i; --i)
			if(a.dig[i] != b.dig[i])
				return a.dig[i] < b.dig[i];

		return false;
	}
	
	static void div(const id1 &a, const id1 &b, id1 *ax, id1 *dx)
	{
		assert(!b.is_zero());
		assert(dx);
		if(ax) *ax = 0;
		*dx = a;
		id1 &c = *dx;
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

	id1 shifted(int k) const
	{
		id1 res(0);
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
			x += spw*(*c - '0') ;
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
			int x = 0, p10 = 1, max_int = 1000000000;
			for(int j=0; *s && sbase <= max_int; ++s,++j)
			{
				int d = *s - '0';
				assert(0 <= d && d < sbase);
				x = sbase*x + d;
				p10 *= sbase;
				max_int /= sbase;
			}
			
			*this *= p10;
			*this += x;
		}
	}
	
	void read(int sbase, const char *s)
	{
		if(*s == 0)
			return;
		
		int i = 0;
		if(*s && s[0] == '-')
		{
			sign = -1;
			++i;
		}

		if(is_base_power_of_10())
			return read_from_compatible_base(sbase, s+i, strlen(s)-i);
		else
			return read_from_any_base(sbase, s+i);
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
	id1()
		: sign(1)
	{
	}

	id1(int x)
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

	id1(long long x)
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
	
	id1(const std::string &s)
		: sign(1)
	{
		read(10, s.c_str());
	}
	
	id1(const char *s)
		: sign(1)
	{
		read(10, s);
	}
	
	template<typename Iterator>
	id1(const Iterator id0, const Iterator dig_end)
		: sign(1)
		, dig(id0, dig_end)
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
	
	id1& operator+=(const id1 &b)
	{
		id1 &a = *this;
		if(sign == b.sign)
		{
			sum_unsigned(a, b);
		}
		else
		{
			if(less_unsigned(a, b))
			{
				id1 c = b;
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

	id1 operator+(const id1 &b) const
	{
		id1 r = *this;
		return r += b;
	}

	id1 operator-() const
	{
		if(is_zero())
			return *this;
		id1 r = *this;
		r.sign = -r.sign;
		return r;
	}

	id1& operator-=(const id1 &b)
	{
		id1 &a = *this;
		if(sign != b.sign)
		{
			sum_unsigned(a, b);
		}
		else
		{
			if(less_unsigned(a, b))
			{
				id1 c = b;
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

	id1 operator-(const id1 &b) const
	{
		id1 r = *this;
		return r -= b;
	}

	id1& operator*=(const id1 &b)
	{
		id1 &a = *this;
		a = a*b;
		return a;
	}

	id1 karatsuba_multiply(const id1 &b) const
	{
		const id1 &a=*this;
		int m = std::max(a.len(), b.len()) / 2;
		
		id1 x1(a.dig.begin() + std::min(m,a.len()), a.dig.end());
		id1 x2(a.dig.begin(), a.dig.begin() + std::min(m,a.len()));
		id1 y1(b.dig.begin() + std::min(m,b.len()), b.dig.end());
		id1 y2(b.dig.begin(), b.dig.begin() + std::min(m,b.len()));
		
		id1 f = x1*y1;
		id1 g = x2*y2;
		x1 += x2;
		y1 += y2;
		id1 h = x1*y1;
		h -= f;
		h -= g;
		g += f.shifted(m+m);
		g += h.shifted(m);
		g.sign = sign * b.sign;
		return g;
	}
	
	id1 operator*(const id1 &b) const
	{
		if(32 < std::min(len(), b.len()))
			return karatsuba_multiply(b);
		
		const id1 &a=*this;
		id1 c;

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

	id1 operator*(int b) const
	{
		id1 r = *this;
		return r *= b;
	}

	id1 &operator*=(int b)
	{
		if(b < 0)
		{
			sign = -sign;
			b = -b;
		}

		if(b == 1)
			return *this;

		int i;
		int x = 0;
		long long y;

		for(i=0; i<len(); i++)
		{
			y = dig[i]*1LL*b + x;
			dig[i] = y % base;
			x = y / base;
		}

		while(x)
		{
			dig.push_back(x % base);
			x /= base;
		}
		
		correct();
		return *this;
	}

	id1 operator/(int b) const
	{
		id1 r = *this;
		return r /= b;
	}

	id1 &operator/=(int b)
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
	
	id1& operator/=(const id1 &b)
	{
		id1 &a = *this;
		a = a/b;
		return a;
	}

	id1 operator/(const id1 &b) const
	{
		id1 cx;
		id1 dx = *this;
		div(*this, b, &cx, &dx);
		
		return cx;
	}
	
	id1& operator%=(const id1 &b)
	{
		id1 &a = *this;
		return a = a%b;
	}

	id1 operator%(const id1 &b) const
	{
		id1 dx = *this;
		div(*this, b, nullptr, &dx);
		return dx;
	}
	
	id1& operator%=(int b)
	{
		id1 &a = *this;
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

	bool operator==(const id1 &b) const
	{
		if(sign != b.sign || len() != b.len())
			return false;

		for(int i=0; i<len(); ++i)
			if(dig[i] != b.dig[i])
				return false;
		return true;
	}

	bool operator!=(const id1 &b) const
	{
		return !(*this == b);
	}
	
	bool operator<(const id1 &b) const
	{
		if(sign != b.sign)
			return sign < b.sign;
		bool less = less_unsigned(*this, b);
		if(sign < 0)
			return !less;
		return less;
	}

	bool operator<=(const id1 &b) const
	{
		return !(b < *this);
	}
	
	bool operator>(const id1 &b) const
	{
		return b < *this;
	}
	
	bool operator>=(const id1 &b) const
	{
		return !(*this < b);
	}
	
	id1& operator &=(const id1 &b)
	{
		static_assert(base & (base-1) == 0,
			"Bitwise operations implemented only for base = 2^^k");
		

		return *this;
	}
	
	void read(std::istream& is)
	{
		std::string s;
		is >> s;
		read(10, s.c_str());
	}
	
	void write(std::ostream& s) const
	{
		if(len() == 0)
		{
			s << '0';
			return;
		}

		if(sign < 0)
			s << "-";
		
		id1 a(*this);
		std::string d;
		int i = 0;
		while(i < a.len())
		{
			int ndig = 9;
			int x;
			if(is_base_power_of_10())
			{
				ndig = base_log10();
				x = a.dig[i++];
			}
			else
			{
				x = a % 1000000000;
				a /= 1000000000;
			}
			
			for(int i=0; i<ndig; ++i)
			{
				d += '0' + (x%10);
				x /= 10;
			}
		}

		while(!d.empty() && d.back() == '0')
			d.pop_back();

		std::reverse(d.begin(), d.end());
		s << d;
	}

	void swap(id1 &b)
	{
		std::swap(dig, b.dig);
		std::swap(sign, b.sign);
	}	
};

template<int base>
std::istream& operator>>(std::istream& s, id1<base> &a)
{
	a.read(s);
	return s;
}

template<int base>
std::ostream& operator<<(std::ostream& s, const id1<base> &a)
{
	a.write(s);
	return s;
}

template<int base>
bool operator<(long long b, const id1<base> &a)
{
	return (id1<base>(b) < a);
}

template<int base>
bool operator<=(long long b, const id1<base> &a)
{
	return !(a < b);
}

template<int base>
bool operator>(long long b, const id1<base> &a)
{
	return (a < b);
}

template<int base>
bool operator>=(long long b, const id1<base> &a)
{
	return (a <= b);
}

template<int base>
bool operator==(long long b, const id1<base> &a)
{
	return (a == b);
}

template<int base>
bool operator!=(long long b, const id1<base> &a)
{
	return (a != b);
}

typedef id1<1000000000> BigInt;


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
		
	for(int i=len1; i<=len2; i+=len2-len1)
	{
		

		

		

		BigInt low(x.substr(i, len-i)), high(x.substr(0, i));
		ans = min(ans, low+high);
	}
	
	cout << ans << "\n";

	return 0;
}