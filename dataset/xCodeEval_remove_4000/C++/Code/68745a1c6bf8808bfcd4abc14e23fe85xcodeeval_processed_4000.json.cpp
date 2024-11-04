



using namespace std;









stringstream output;


inline void eOP();












using namespace std;




vector<unsigned int> primes;
unsigned int id2 = 1;

template <typename N>
inline N id1(N a, N b);

template <typename N>
inline N id1(N a, N b, N& x, N& y);

template <typename N>
inline N lcm(N a, N b);

namespace std
{
	template <typename N>
    inline N pow(N b, unsigned long long e);

	inline size_t reverse(size_t n);
}

template <typename N>
inline void id0(N n);




template <typename N>
inline N id1(N a, N b)
{
	while (a != N(0))
	{
        b %= a;
        swap(a, b);
	}
	return b;
}

template <typename N>
inline N id1(N a, N b, N& x, N& y)
{
    

    


    N l[3] = {a, 1, 0};
    N r[3] = {b, 0, 1};

    while (l[0] != 0)
    {
    	N n = r[0] / l[0];
    	for (int i = 0; i < 3; ++i)
		{
            r[i] -= l[i] * n;
            swap(l[i], r[i]);
		}
    }

    x = r[1];
    y = r[2];
    return r[0];
}

template <typename N>
inline N lcm(N a, N b)
{
    return a / gcd(a, b) * b;
}

template <typename N>
inline N std::pow(N b, unsigned long long e)
{
	N result = 1;

    while (e)
	{
        if (e & 1)
		{
			result *= b;
		}
		e >>= 1;
		b *= b;
	}

	return result;
}

inline size_t std::reverse(size_t x)
{
    unsigned int tmp1 = (x&0xAAAAAAAA)>>1;
    unsigned int tmp2 = (x&0x55555555)<<1;
    size_t n = tmp1|tmp2;

    tmp1 = (n&0xCCCCCCCC)>>2;
    tmp2 = (n&0x33333333)<<2;
    n = tmp1|tmp2;

    tmp1 = (n&0xF0F0F0F0)>>4;
    tmp2 = (n&0x0F0F0F0F)<<4;
    n = tmp1|tmp2;

    tmp1 = (n&0xFF00FF00)>>8;
    tmp2 = (n&0x00FF00FF)<<8;
    n = tmp1|tmp2;

    tmp1 = (n&0xFFFF0000)>>16;
    tmp2 = (n&0x0000FFFF)<<16;
    n = tmp1|tmp2;
    return n;
}

template <typename N>
inline void id0(N n)
{
	while (id2 < n)
	{
		++id2;
        bool isPrime = true;
        for (unsigned int i: primes)
		{
            if (!(id2 % i))
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
		{
			primes.push_back(id2);
		}
	}
}











template <typename T1, typename T2>
inline T1 operator +(const T1& a, const T2& b);
template <typename T1, typename T2>
inline T1 operator -(const T1& a, const T2& b);
template <typename T>
inline T operator +(const T& a);
template <typename T1, typename T2>
inline T1 operator *(const T1& a, const T2& b);
template <typename T1, typename T2>
inline T1 operator /(const T1& a, const T2& b);
template <typename T1, typename T2>
inline T1 operator %(const T1& a, const T2& b);
template <typename T>
inline T& operator ++(T& a);
template <typename T>
inline T operator ++(T& a, int);
template <typename T>
inline T& operator --(T& a);
template <typename T>
inline T operator --(T& a, int);



template <typename T1, typename T2>
inline bool operator>(const T1& a,const T2& b);
template <typename T1, typename T2>
inline bool operator<=(const T1& a,const T2& b);
template <typename T1, typename T2>
inline bool operator>=(const T1& a,const T2& b);



template <typename T1, typename T2>
inline T1 operator &(const T1& a, const T2& b);
template <typename T1, typename T2>
inline T1 operator |(const T1& a, const T2& b);
template <typename T1, typename T2>
inline T1 operator ^(const T1& a, const T2& b);
template <typename T>
inline T operator <<(const T& a, const T& b);
template <typename T>
inline T operator >>(const T& a, const T& b);



template <typename T1, typename T2>
inline T1& operator -=(T1& a, const T2& b);
template <typename T1, typename T2>
inline T1& operator %=(T1& a, const T2& b);
template <typename T1, typename T2>
inline T1& operator ^=(T1& a, const T2& b);
template <typename T>
inline T& operator >>=(T& a, const T& b);



template <typename T1, typename T2>
inline T1 operator +(const T1& a, const T2& b)
{
	T1 result = a;
	return result += b;
}

template <typename T1, typename T2>
inline T1 operator -(const T1& a, const T2& b)
{
	T1 result = a;
	return result -= b;
}

template <typename T>
inline T operator +(const T& a)
{
	return a;
}

template <typename T1, typename T2>
inline T1 operator *(const T1& a, const T2& b)
{
	T1 result = a;
	return result *= b;
}

template <typename T1, typename T2>
inline T1 operator /(const T1& a, const T2& b)
{
	T1 result = a;
	return result /= b;
}

template <typename T1, typename T2>
inline T1 operator %(const T1& a, const T2& b)
{
	T1 result = a;
	return result %= b;
}

template <typename T>
inline T& operator ++(T& a)
{
	return a += 1;
}

template <typename T>
inline T operator ++(T& a, int)
{
	T result = a;
	++a;
	return result;
}

template <typename T>
inline T& operator --(T& a)
{
	return a -= 1;
}

template <typename T>
inline T operator --(T& a, int)
{
	T result = a;
	--a;
	return result;
}



template <typename T1, typename T2>
inline bool operator!=(const T1& a,const T2& b)
{
	return !(a == b);
}

template <typename T1, typename T2>
inline bool operator>(const T1& a,const T2& b)
{
	return b < a;
}

template <typename T1, typename T2>
inline bool operator<=(const T1& a,const T2& b)
{
	return !(a > b);
}

template <typename T1, typename T2>
inline bool operator>=(const T1& a,const T2& b)
{
	return !(a < b);
}




template <typename T1, typename T2>
inline T1 operator &(const T1& a, const T2& b)
{
	T1 result = a;
	return result &= b;
}

template <typename T1, typename T2>
inline T1 operator |(const T1& a, const T2& b)
{
	T1 result = a;
	return result |= b;
}

template <typename T1, typename T2>
inline T1 operator ^(const T1& a, const T2& b)
{
	T1 result = a;
	return result ^= b;
}

template <typename T>
inline T operator <<(const T& a, const T& b)
{
	T result = a;
	return result <<= b;
}

template <typename T>
inline T operator >>(const T& a, const T& b)
{
	T result = a;
	return result >>= b;
}




template <typename T1, typename T2>
inline T1& operator -=(T1& a, const T2& b)
{
	return a += -b;
}

template <typename T1, typename T2>
inline T1& operator %=(T1& a, const T2& b)
{
	return a -= a / b * b;
}

template <typename T1, typename T2>
inline T1& operator ^=(T1& a, const T2& b)
{
	return a = ~(a & b) & (a | b);
}

template <typename T>
inline T& operator >>=(T& a, const T& b)
{
	return a <<= -b;
}





int MOD = 998244353;

class id3
{
public:
    long long value;
    id3(long long = 0);
};

inline id3 operator + (const id3 & l, const id3 & r);

inline id3 operator - (const id3 & l, const id3 & r);

inline id3 operator * (const id3 & l, const id3 & r);

inline id3 operator / (const id3 & l, const id3 & r);

inline id3 & operator++(id3 & r);

inline id3 operator++(id3 & r, int);

inline id3 & operator--(id3 & r);

inline id3 operator--(id3 & r, int);

inline id3 operator + (const id3 & r);

inline id3 operator - (const id3 & r);

inline id3 & operator += (id3 & l, const id3 & r);

inline id3 & operator -= (id3 & l, const id3 & r);

inline id3 & operator *= (id3 & l, const id3 & r);

inline id3 & operator /= (id3 & l, const id3 & r);

inline bool operator == (const id3 & l, const id3 & r);

inline bool operator < (const id3 & l, const id3 & r);



template <typename charT, typename traits>
inline std::basic_ostream<charT,traits> & operator << (std::basic_ostream<charT,traits> & os, const id3 & o);



template <typename charT, typename traits>
inline std::basic_istream<charT,traits> & operator >> (std::basic_istream<charT,traits> & is, id3 & o);



namespace std
{
	template<>
	struct hash<id3>
	{
		size_t operator()(const id3& s) const noexcept;
	};
}



inline id3::id3(long long r)
{
    value = r;
	value %= MOD;
	if (value < 0)
	{
		value += MOD;
	}
}

inline id3 operator + (const id3 & l, const id3 & r) 

{
   id3 oResult(l.value + r.value);
   return oResult ;
}

inline id3 operator - (const id3 & l, const id3 & r) 

{
   id3 oResult(l.value - r.value);
   return oResult ;
}

inline id3 operator * (const id3 & l, const id3 & r) 

{
   id3 oResult(l.value * r.value);
   return oResult ;
}

inline id3 operator / (const id3 & l, const id3 & r) 

{
	long long x, y;
	gcd(r.value, static_cast<long long>(MOD), x, y);
   id3 oResult(l * x);
   return oResult ;
}

inline id3 & operator++(id3 & r) 

{
   r += 1;
   return r ;
}

inline id3 operator++(id3 & r, int) 

{
   id3 oCopy(r);
   r += 1;
   return oCopy ;
}

inline id3 & operator--(id3 & r) 

{
   r -= 1;
   return r ;
}

inline id3 operator--(id3 & r, int) 

{
   id3 oCopy(r);
   r -= 1;
   return oCopy ;
}

inline id3 operator + (const id3 & r) 

{
   return r ;
}

inline id3 operator - (const id3 & r) 

{
	id3 temp(-(r.value));
   return temp;
}

inline id3 & operator += (id3 & l, const id3 & r) 

{
   l = l + r;

   return l ;
}

inline id3 & operator -= (id3 & l, const id3 & r) 

{
   l = l - r;

   return l ;
}

inline id3 & operator *= (id3 & l, const id3 & r) 

{
   l = l * r;

   return l ;
}

inline id3 & operator /= (id3 & l, const id3 & r) 

{
   l = l / r;

   return l ;
}

inline bool operator == (const id3 & l, const id3 & r) 

{
   return l.value == r.value ;
}

inline bool operator < (const id3 & l, const id3 & r) 

{
   return l.value < r.value ;
}



template <typename charT, typename traits>
inline std::basic_ostream<charT,traits> & operator << (std::basic_ostream<charT,traits> & os, const id3 & o)
{
   os << o.value;
   return os ;
}



template <typename charT, typename traits>
inline std::basic_istream<charT,traits> & operator >> (std::basic_istream<charT,traits> & is, id3 & o)
{
   is >> o.value;
   o = id3(o);
   return is ;
}

size_t hash<id3>::operator()(const id3& s) const noexcept
{
	return s.value;
}




typedef id3 R;

unordered_map<int,unordered_map<int,unordered_map<bool,R>>> F;

R f(int n, int k, bool d)
{
	if (n <= 0 || k <= 0)
	{
		return 0;
	}

	if (F[n][k].find(d) != F[n][k].end())
	{
        return F[n][k][d];
	}

    R r;

    if (d)
	{
		r =
			f(n - 1, k, 1) +
			(f(n - 1, k - 1, 0) * 2) +
			f(n - 1, k - 2, 1);
	}
	else
	{
		r =
			f(n - 1, k, 0) +
			(f(n - 1, k, 1) * 2) +
			f(n - 1, k - 1, 0);
	}

	F[n][k][d] = r;

	return r;
}

inline void solve()
{
    F[1][1][0] = 2;
    F[1][1][1] = 0;
    F[1][2][0] = 0;
    F[1][2][1] = 2;

	int n = 1000, k = 2000;
	cin >> n >> k;

	output << (f(n, k, 0) + f(n, k, 1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	size_t t = 1;
	

	rep (i, t)
	{
		solve();
	}

	eOP();
}

inline void eOP()
{
	cout << output.str();
	output.str(string());
	exit(0);
}
