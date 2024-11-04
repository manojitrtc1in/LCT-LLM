











using namespace std;
typedef long long ll;








template<int Y, int X>
struct PowerOf
{
	template<int B = Y, int A = X>
	static constexpr typename std::enable_if<B != 1 && A != 1 && B%A == 0, bool>::type
	id1()
	{
		return PowerOf<B/A,A>::id1();
	}

	template<int B = Y, int A = X>
	static constexpr typename std::enable_if<B == 1 || A == 1 || B%A != 0, bool>::type
	id1()
	{
		return B == 1;
	}
	
	
	template<int B = Y, int A = X>
	static constexpr typename std::enable_if<B != 1 && A != 1 && B%A == 0, bool>::type
	get_power()
	{
		return PowerOf<B/A,A>::get_power() + 1;
	}

	template<int B = Y, int A = X>
	static constexpr typename std::enable_if<B == 1 || A == 1 || B%A != 0, bool>::type
	get_power()
	{
		

		return 0;
	}
};


template<int base>
class id2
{
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
	
	static void sum_unsigned(id2 &a, const id2 &b)
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
	
	static void sub_unsigned(id2 &a, const id2 &b, int id3 = 0)
	{
		assert(!less_unsigned(a,b));
		int i;
		int x,y;
		assert(b.len() <= (a.len()-id3));
		
		for(i=0,x=0; i<b.len(); ++i)
		{
			y = base + a.dig[i+id3] - b.dig[i] - x;
			assert(0 <= y);
			a.dig[i+id3] = y % base;
			x = 1 - y / base;
			assert(x == 0 || x == 1);
		}

		i += id3;
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

	static bool less_unsigned(const id2 &a, const id2 &b)
	{
		if(a.len() != b.len())
			return a.len() < b.len();

		for(int i=a.len()-1; 0<=i; --i)
			if(a.dig[i] != b.dig[i])
				return a.dig[i] < b.dig[i];

		return false;
	}
	
	static void div(const id2 &a, const id2 &b, id2 *ax, id2 *dx)
	{
		assert(!b.is_zero());
		assert(dx);
		if(ax) *ax = 0;
		*dx = a;
		id2 &c = *dx;
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

	id2 shifted(int k) const
	{
		id2 res(0);
		res.reserve_digits(len()+k);
		
		for(int i=res.len()-1; k<=i; --i)
		{
			res.dig[i] = dig[i-k];
		}
		
		return res;
	}
	
public:
	id2()
		: sign(1)
	{
	}

	id2(int x)
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

	id2(long long x)
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
	
	id2& operator+=(const id2 &b)
	{
		id2 &a = *this;
		if(sign == b.sign)
		{
			sum_unsigned(a, b);
		}
		else
		{
			if(less_unsigned(a, b))
			{
				id2 c = b;
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

	id2 operator+(const id2 &b) const
	{
		id2 r = *this;
		return r += b;
	}

	id2 operator-() const
	{
		if(is_zero())
			return *this;
		id2 r = *this;
		r.sign = -r.sign;
		return r;
	}

	id2& operator-=(const id2 &b)
	{
		id2 &a = *this;
		if(sign != b.sign)
		{
			sum_unsigned(a, b);
		}
		else
		{
			if(less_unsigned(a, b))
			{
				id2 c = b;
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

	id2 operator-(const id2 &b) const
	{
		id2 r = *this;
		return r -= b;
	}

	id2& operator*=(const id2 &b)
	{
		id2 &a = *this;
		a = a*b;
		return a;
	}

	id2 operator*(const id2 &b) const
	{
		int i,j;
		int x=0;
		long long y;
		const id2 &a=*this;
		id2 c;

		c.reserve_digits(a.len() + b.len());

		for(i=0; i<a.len(); i++)
		{
			x = 0;
			for(j=0; j<b.len(); j++)
			{
				y = c.dig[i+j] + a.dig[i]*1LL*b.dig[j] + x;
				c.dig[i+j] = y % base;
				x = (int)(y / base);
			}
			c.dig[i+j] += x;
		}

		c.sign = a.sign * b.sign;

		c.correct();

		return c;
	}

	id2 operator*(int b) const
	{
		id2 r = *this;
		return r *= b;
	}

	id2 &operator*=(int b)
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

	id2 operator/(int b) const
	{
		id2 r = *this;
		return r /= b;
	}

	id2 &operator/=(int b)
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
	
	id2& operator/=(const id2 &b)
	{
		id2 &a = *this;
		a = a/b;
		return a;
	}

	id2 operator/(const id2 &b) const
	{
		id2 cx;
		id2 dx = *this;
		div(*this, b, &cx, &dx);
		
		return cx;
	}
	
	id2& operator%=(const id2 &b)
	{
		id2 &a = *this;
		return a = a%b;
	}

	id2 operator%(const id2 &b) const
	{
		id2 dx = *this;
		div(*this, b, nullptr, &dx);
		return dx;
	}
	
	id2& operator%=(int b)
	{
		id2 &a = *this;
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

	bool operator==(const id2 &b) const
	{
		if(sign != b.sign || len() != b.len())
			return false;

		for(int i=0; i<len(); ++i)
			if(dig[i] != b.dig[i])
				return false;
		return true;
	}

	bool operator!=(const id2 &b) const
	{
		return !(*this == b);
	}
	
	bool operator<(const id2 &b) const
	{
		if(sign != b.sign)
			return sign < b.sign;
		bool less = less_unsigned(*this, b);
		if(sign < 0)
			return !less;
		return less;
	}

	bool operator<=(const id2 &b) const
	{
		return !(b < *this);
	}
	
	bool operator>(const id2 &b) const
	{
		return b < *this;
	}
	
	bool operator>=(const id2 &b) const
	{
		return !(*this < b);
	}
	
	id2& operator &=(const id2 &b)
	{
		static_assert(base & (base-1) == 0,
			"Bitwise operations implemented only for base = 2^^k");
		

		return *this;
	}
	
	static constexpr bool is_power10_based()
	{
		return PowerOf<base,10>::id1();
		

	}
	
	static constexpr int base_log10()
	{
		return PowerOf<base,10>::get_power();
	}
	
	

	

	


	

	

	


	template<int sbase>
	void id0(const char *s, int slen)
	{
		assert(dig.empty());
		
		int x = 0, spw = 1;
		for(const char *c = s+slen-1; s<=c; --c)
		{
			x = sbase*x + (*c - '0') ;
			spw *= sbase;
			if(spw == base)
			{
				dig.push_back(x);
				x = 0;
				spw = 1;
			}
		}
	}
	
	void read(std::istream& is)
	{
		*this = id2(0);

		std::string s;
		is >> s;
		if(s.empty())
			return;
		
		int i = 0;
		if(!s.empty() && s[0] == '-')
		{
			sign = -1;
			++i;
		}
		
		if(is_power10_based())
		{
			return id0<10>(s.c_str()+i, s.size()-i);
		}
		
		for(; i<s.size();)
		{
			int x = 0, p10 = 1;
			for(int j=0; j<9 && i<s.size() && p10 != base; ++i,++j)
			{
				int d = s[i] - '0';
				assert(0 <= d && d <= 9);
				x = 10*x + d;
				p10 *= 10;
			}
			
			*this *= p10;
			*this += x;
		}
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
		
		id2 a(*this);
		std::string d;
		int i = 0;
		while(i < a.len())
		{
			int ndig = 9;
			int x;
			if(is_power10_based())
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

	void swap(id2 &b)
	{
		std::swap(dig, b.dig);
		std::swap(sign, b.sign);
	}	
};

template<int base>
std::istream& operator>>(std::istream& s, id2<base> &a)
{
	a.read(s);
	return s;
}

template<int base>
std::ostream& operator<<(std::ostream& s, const id2<base> &a)
{
	a.write(s);
	return s;
}

template<int base>
bool operator<(long long b, const id2<base> &a)
{
	return (id2<base>(b) < a);
}

template<int base>
bool operator<=(long long b, const id2<base> &a)
{
	return !(a < b);
}

template<int base>
bool operator>(long long b, const id2<base> &a)
{
	return (a < b);
}

template<int base>
bool operator>=(long long b, const id2<base> &a)
{
	return (a <= b);
}

template<int base>
bool operator==(long long b, const id2<base> &a)
{
	return (a == b);
}

template<int base>
bool operator!=(long long b, const id2<base> &a)
{
	return (a != b);
}

typedef id2<10> BigInt;


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
	BigInt x;
	cin >> len >> x;
	dprint(x);
	BigInt p10 = 1;
	BigInt ans = x;
	int len1, len2;
	for(len1=len/2; 0<len1 && 0 == x.get_dig(len1-1); --len1);
	for(len2=len/2+1; len2<len && 0 == x.get_dig(len2-1); ++len2);
		
	for(int i=len1; i<=len2; i+=len2-len1)
	{
		

		

		

		BigInt low, high;
		high.dig = std::vector<int>(x.dig.begin() + i, x.dig.end());
		low.dig = std::vector<int>(x.dig.begin(), x.dig.begin() + i);
		if(high.len() + low.len() != x.len())
			continue;
		ans = min(ans, low+high);
	}
	
	cout << ans << "\n";

	return 0;
}
