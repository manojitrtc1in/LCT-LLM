

#ifndef BIG_INT_H
#define BIG_INT_H

#include <limits>
#include <utility>
#include <climits>
#include <assert.h>
#include <memory.h>
#if defined(_MSC_VER) && _MSC_VER >= 1500
	#include <intrin.h>  

#endif
#ifndef BIGINT_EXCLUDE_STRINGS
	#include <iostream>
	#include <sstream>
	#include <string>
#endif

#ifndef C_ASSERT
#define ASSERT_CONCAT_(a, b) a##b
#define ASSERT_CONCAT(a, b) ASSERT_CONCAT_(a, b)
#define C_ASSERT(e) typedef char ASSERT_CONCAT(assert_line_, __LINE__)[(e)?1:-1]
#endif
#define BIGINT_ASSERT(expr) assert(expr)

#if defined(BIGINT_NO_STATICS) || defined(MULTITHREADED) || defined(_MT)
	#define STATIC_UNLESS_MULTITHREADED
#else
	#define STATIC_UNLESS_MULTITHREADED static
#endif
#define BASE_MAX (std::numeric_limits<typename ubigint_t::BIGINT_BASE>::max)()
#define NUM_MANTISSA_BITS (std::numeric_limits<T>::digits)

#ifdef BIGINT_RUN_WITHOUT_MATHLIB
template <typename T>
inline T Frexp(T x, int *y) {
	int exponent = 0;
	while (x >= (const T)(static_cast<T>(~0U) + static_cast<T>(1))) {
		x *= (const T)(static_cast<T>(1) / (static_cast<T>(~0U) + static_cast<T>(1)));
		exponent += sizeof(int)*CHAR_BIT;
	}
	unsigned int shift = sizeof(int)*CHAR_BIT;
	T frac = T(1);
	do {
		T frac2 = frac * (T)(unsigned int)(1U << (shift-1));
		if (x >= frac2) {
			frac = T(2) * frac2;
			exponent += shift;
		}
		shift >>= 1;
	} while (shift > 0);
	x *= static_cast<T>(1) / frac;
	*y = exponent;
	return x;
}
template <typename T>
inline T Ldexp(T x, int y) {
	unsigned int uy = (unsigned int)y;
	while (uy >= sizeof(int)*CHAR_BIT) {
		x *= (const T)(static_cast<T>(~0U) + static_cast<T>(1));
		uy -= sizeof(int)*CHAR_BIT;
	}
	x *= (T)(unsigned int)(1U << uy);
	return x;
}
#else
#include <cmath>
#define Frexp frexp
#define Ldexp ldexp
#endif

template<typename T> struct bigintPopCounter {
	static int popCount(T v) {
		int count = 0;
		while (v) {
			v &= v - 1;
			++count;
		}
		return count;
	}
};

#if defined(__GNUG__)
template<> struct bigintPopCounter<unsigned int> {
	static int popCount(unsigned int v) { return __builtin_popcount(v); }
};
template<> struct bigintPopCounter<unsigned long long> {
	static int popCount(unsigned long long v) { return static_cast<int>(__builtin_popcountll(v)); }
};
#elif defined(_MSC_VER) && _MSC_VER >= 1500 

template<> struct bigintPopCounter<unsigned int> {
	static int popCount(unsigned int v) { return __popcnt(v); }
};
template<> struct bigintPopCounter<unsigned long long> {
#if _M_AMD64
	static int popCount(unsigned long long v) { return static_cast<int>(__popcnt64(v)); }
#else
	static int popCount(unsigned long long v) { return __popcnt((unsigned int)v) + __popcnt((unsigned int)(v>>32)); }
#endif
};
#endif

template<int> class sbigint;

template <int BIGINT_TOTAL_BITS>
class ubigint
{
protected:
#if _M_AMD64 || defined(BIGINT_USE_64BIT)
	typedef unsigned long long BIGINT_BASE;
	typedef unsigned int BIGINT_SHORT;
#elif defined(BIGINT_USE_16BIT)
	typedef unsigned short BIGINT_BASE;
	typedef unsigned char BIGINT_SHORT;
#else
	typedef unsigned int BIGINT_BASE;
	typedef unsigned short BIGINT_SHORT;
#endif
	typedef ubigint<BIGINT_TOTAL_BITS> ubigint_t;
	typedef sbigint<BIGINT_TOTAL_BITS> sbigint_t;

	enum constants {
		BASE_BITS = sizeof(BIGINT_BASE) * CHAR_BIT,
		HALF_BASE_BITS = BASE_BITS / 2,
		LOWER_HALF_MASK = (int)((((1U << (HALF_BASE_BITS-1)) - 1) << 1) + 1),
		BIGINTSIZE = (BIGINT_TOTAL_BITS / BASE_BITS),
		LSBINDEX = 0,
		MSBINDEX = BIGINTSIZE-1,
	};

	C_ASSERT((BIGINT_TOTAL_BITS & (BASE_BITS - 1)) == 0);
	C_ASSERT(sizeof(BIGINT_SHORT)*2 == sizeof(BIGINT_BASE));

	#define BASE_INDEX(x) (x)
	#define BACKWARDS_LOOP(x) for (int x = BIGINTSIZE-1; x >= 0; --x)
	#define FORWARDS_LOOP(x) for (int x = 0; x < BIGINTSIZE; ++x)

	BIGINT_BASE data[BIGINTSIZE];

	template <typename T> void internalInitialise(T x, const int Fill = 0) {
		if (sizeof(x) <= sizeof(data)) {
			memcpy(data, &x, sizeof(x));
			memset(reinterpret_cast<char*>(data) + sizeof(x), Fill, sizeof(data) - sizeof(x));
		} else {
			memcpy(data, &x, sizeof(data));
		}
	}

	template <typename T> void internalExtract(T &x, const int Fill = 0) const {
		if (sizeof(x) <= sizeof(data)) {
			memcpy(&x, data, sizeof(x));
		} else {
			memcpy(&x, data, sizeof(data));
			memset(reinterpret_cast<char*>(&x) + sizeof(data), Fill, sizeof(x) - sizeof(data));
		}
	}

	template <typename T> void internalInitialiseFromFloating(T f, bool isSigned) {
		*this = 0;
		if (f-f != static_cast<T>(0.0)) { 

#ifdef __GNUC__
			if (isSigned)
#endif
				this->bitSet(BIGINT_TOTAL_BITS-1);
			return;
		}
		bool neg = false;
		if (f < static_cast<T>(0.0)) {
			f = -f;
			neg = true;
		}
		if (f < static_cast<T>(1.0))
			return;
#ifdef _MSC_VER
		STATIC_UNLESS_MULTITHREADED const BIGINT_BASE HALF_BASE_MAX = (BASE_MAX>>1) + 1;
#endif
		if (f < static_cast<T>(BASE_MAX)) {
#ifdef _MSC_VER
			if (sizeof(BIGINT_BASE) > 4 && f >= T(HALF_BASE_MAX)) {
				data[LSBINDEX] = HALF_BASE_MAX | static_cast<BIGINT_BASE>(f - (static_cast<T>(HALF_BASE_MAX)));
			} else
#endif
				data[LSBINDEX] = static_cast<BIGINT_BASE>(f);
		} else {
			int e;
			T mant = Frexp(f, &e);
			int numBits = 1 + (e + BASE_BITS-1) % BASE_BITS;
			int chunk = (e + BASE_BITS-1) / BASE_BITS;
			if (chunk > BIGINTSIZE) { 

#ifdef __GNUC__
			if (isSigned)
#endif
					this->bitSet(BIGINT_TOTAL_BITS-1);
				return;
			}
			while (mant > static_cast<T>(0.0) && chunk > 0) {
				mant = Ldexp(mant, numBits);
				BIGINT_BASE val;
#ifdef _MSC_VER
				if (sizeof(BIGINT_BASE) > 4 && mant >= T(HALF_BASE_MAX)) {
					val = HALF_BASE_MAX | static_cast<BIGINT_BASE>(mant - (static_cast<T>(HALF_BASE_MAX)));
				} else
#endif
					val = static_cast<BIGINT_BASE>(mant);
				mant -= val;
				numBits = BASE_BITS;
				--chunk;
				data[BASE_INDEX(chunk)] = val;
			}
		}
		if (this->highBitSet() && (neg || isSigned)) {
			*this = 0;
#ifdef __GNUC__
			if (isSigned)
#endif
				this->bitSet(BIGINT_TOTAL_BITS-1);
			return;
		}
		if (neg)
			*this = -*this;
	}

	template <typename T> T internalExtractToFloating() const {
		STATIC_UNLESS_MULTITHREADED const T multiplier = (static_cast<T>(BASE_MAX) + static_cast<T>(1.0));
		T result = 0;
		int first = findHighestBitSet(*this);
		if (first >= 0) {
			const ubigint_t *pVal = this;
			STATIC_UNLESS_MULTITHREADED ubigint_t temp;
#ifdef BIGINT_ACT_LIKE_BUILTIN
			STATIC_UNLESS_MULTITHREADED ubigint_t temp2;
			if (first - findLowestBitSet(*this) == DBL_MANT_DIG) {
				temp2 = (*this >> (first-DBL_MANT_DIG-1)) << (first-DBL_MANT_DIG-1);
				pVal = &temp2;
			} else if (first > DBL_MANT_DIG) {
				temp2 = (*this >> (first-DBL_MANT_DIG)) << (first-DBL_MANT_DIG);
				pVal = &temp2;
			}
#endif
			int shift = first - NUM_MANTISSA_BITS;
			if (shift > 0 && pVal->bitTest(shift) && shift > findLowestBitSet(*pVal)) {
				temp = *pVal >> shift;
				++temp;
				temp <<= shift;
				if (!!temp)
					pVal = &temp;
			}
			BACKWARDS_LOOP(i)
				result = result * multiplier + pVal->data[i];
		}
		return result;
	}

#ifndef BIGINT_EXCLUDE_STRINGS
	template <typename ostream_t>
	static ostream_t& output(ostream_t &os, const ubigint &a, const bool isSigned) {
		typedef typename ostream_t::char_type char_t;
		typedef std::basic_string<char_t, std::char_traits<char_t>, std::allocator<char_t> > tstring;
		ubigint b;
		bool neg = isSigned && (a.highBitSet());
		if (neg)
			b = -a;
		else
			b = a;

		BIGINT_SHORT base = 10;
		int baseIdentLen = 0;
		char_t hexChar = (char_t)'a' - 0xA;
		if (os.flags() & std::ios::hex) {
			base = 16;
			if (os.flags() & std::ios::showbase) {
				(os << (char_t)'0') << (char_t)'x';
				baseIdentLen = 2;
			}
			if (os.flags() & std::ios::uppercase)
				hexChar = (char_t)'A' - 0xA;
		} else if (os.flags() & std::ios::oct) {
			base = 8;
			if (os.flags() & std::ios::showbase) {
				os << (char_t)'0';
				baseIdentLen = 1;
			}
		}

		tstring s;
		BIGINT_SHORT base2 = base*base;
		for (;;) {
			BIGINT_SHORT digits, digit1, digit2;
			DivRem_short(b, base2, b, &digits);
			digit1 = digits / base;
			digit2 = digits - digit1 * base;
			s.push_back(char_t(digit2 + ((digit2 < 0xA) ? (char_t)'0' : hexChar)));
			if (!b) {
				if (digit1 > 0)
					s.push_back(char_t(digit1 + ((digit1 < 0xA) ? (char_t)'0' : hexChar)));
				break;
			}
			s.push_back(char_t(digit1 + ((digit1 < 0xA) ? (char_t)'0' : hexChar)));
		}

		std::streamsize width =(std::streamsize)os.width(0) - (std::streamsize)s.length() - baseIdentLen;
		if (neg || (os.flags() & std::ios::showpos))
			--width;

		if (os.flags() & std::ios::right)
			for (std::streamsize i = width; i > 0; --i)
				os << os.fill();

		if (neg)
			os << (char_t)'-';
		else if (os.flags() & std::ios::showpos)
			os << (char_t)'+';

		if (os.flags() & std::ios::internal)
			for (std::streamsize i = width; i > 0; --i)
				os << os.fill();

		for (typename tstring::size_type i = s.length(); i > 0;)
			os << s[--i];

		if (os.flags() & std::ios::left)
			for (std::streamsize i = width; i > 0; --i)
				os << os.fill();
		return os;
	}

	template <typename istream_t>
	static istream_t& input(istream_t &is, ubigint &val) {
		typedef typename istream_t::char_type char_t;
		using std::swap;
		STATIC_UNLESS_MULTITHREADED ubigint a;
		a = 0;
		bool negative = false, gotValue = false;
		char_t ch;
		BIGINT_BASE aa = 0, mult = 1;
		BIGINT_BASE base = 10, limit = ~BIGINT_BASE(0U) / 10;
		if (is.flags() & std::ios::hex)
			base = 16, limit = ~BIGINT_BASE(0U) / 16;
		else if (is.flags() & std::ios::oct)
			base = 8, limit = ~BIGINT_BASE(0U) / 8;

		std::ios::iostate except(is.exceptions());
		is.exceptions(std::ios::goodbit);

		if (is >> ch) {
			if (ch == (char_t)'-' || ch == (char_t)'+') {
				negative = (ch == (char_t)'-');
				is.get(ch);
			}
			for (;;) {
				if (is.eof()) {
					if (gotValue)
						is.clear(std::ios::eofbit);
					break;
				} else if (ch >= (char_t)'0' && (ch <= (char_t)'7' || (ch <= (char_t)'9' && base >= 10))) {
					aa *= base;
					aa += ch - (char_t)'0';
				} else if (ch >= (char_t)'A' && ch <= (char_t)'F' && base > 10) {
					aa *= base;
					aa += ch - ((char_t)'A' - 0xA);
				} else if (ch >= (char_t)'a' && ch <= (char_t)'f' && base > 10) {
					aa *= base;
					aa += ch - ((char_t)'a' - 0xA);
				} else {
					is.putback(ch);
					if (!gotValue)
						is.setstate(std::ios::failbit);
					break;
				}
				gotValue = true;
				mult *= base;
				if (mult >= limit) {
					a.Mul_int(mult);
					a += aa;
					mult = 1;
					aa = 0;
				}
				is.get(ch);
			}
			if (!is.fail()) {
				a.Mul_int(mult);
				a += aa;
				if (negative)
					a = -a;
				swap(val, a);
			}
		}

		is.exceptions(except);
		return is;
	}
#endif

	friend void DivRem_short(const ubigint &a, BIGINT_SHORT b, ubigint &quotient, BIGINT_SHORT *remainder) {
		if (!b) {
			BIGINT_ASSERT(false);
			b = BIGINT_SHORT(1) / b;
			return;
		}
		const BIGINT_SHORT *u = (const BIGINT_SHORT*)a.data;
		int m = BIGINTSIZE*2;
		while (m > 0 && u[m-1] == 0) --m;

		BIGINT_SHORT *q = (BIGINT_SHORT*)quotient.data;
		BIGINT_BASE k = 0;
		for (int j = m - 1; j >= 0; --j) {
			BIGINT_BASE fullWord = (k<<HALF_BASE_BITS) + u[j];
			q[j] = static_cast<BIGINT_SHORT>(fullWord / b);
			k = fullWord - q[j] * b;
		}
		for (int i = m; i < BIGINTSIZE*2; ++i)
			q[i] = 0U;
		if (remainder != NULL)
			*remainder = static_cast<BIGINT_SHORT>(k);
	}

#if !defined(SIMPLE_DIVISION)
	friend void DivRem_Unsigned(const ubigint &a, const ubigint &b, ubigint &quotient, ubigint *remainder) {
		if (&a == &b && !!a) {
			quotient = 1;
			if (remainder != NULL)
				*remainder = 0;
			return;
		}
		const BIGINT_BASE lower_half_mask = static_cast<BIGINT_BASE>((unsigned)LOWER_HALF_MASK);
		const BIGINT_SHORT *v = (const BIGINT_SHORT*)b.data;
		BIGINT_SHORT vn[BIGINTSIZE*2];
		BIGINT_SHORT un[BIGINTSIZE*2+1];

		int n = BIGINTSIZE*2;
		while (n > 0 && v[n-1] == 0) --n;

		if (!n) {
			BIGINT_ASSERT(false);
			n = BIGINT_SHORT(1) / v[0];
			return;
		}

		const BIGINT_SHORT *u = (const BIGINT_SHORT*)a.data;
		int m = BIGINTSIZE*2;
		while (m > 0 && u[m-1] == 0) --m;

		if (m < n) {
			quotient = 0U;
			if (remainder != NULL)
				*remainder = a;
			return;
		}

		BIGINT_SHORT *q = (BIGINT_SHORT*)quotient.data;
		if (n == 1){
			BIGINT_BASE k = 0, v0 = v[0];
			for (int j = m - 1; j >= 0; --j) {
				BIGINT_BASE fullWord = (k<<HALF_BASE_BITS) + u[j];
				q[j] = static_cast<BIGINT_SHORT>(fullWord / v0);
				k = fullWord - q[j] * v0;
			}
			for (int i = m; i < BIGINTSIZE*2; ++i)
				q[i] = 0U;
			if (remainder != NULL)
				*remainder = static_cast<BIGINT_SHORT>(k);
			return;
		}

		int s = -HALF_BASE_BITS;
		int tempShift = HALF_BASE_BITS;
		BIGINT_BASE temp = v[n-1], mask = lower_half_mask;
		do {
			if (temp <= mask) { s += tempShift; temp <<= tempShift; }
			tempShift >>= 1;
			mask |= (mask << tempShift);
		} while (tempShift > 0);

		for (int i = n - 1; i > 0; --i)
			vn[i] = (v[i] << s) | (static_cast<BIGINT_BASE>(v[i-1]) >> (HALF_BASE_BITS-s));
		vn[0] = v[0] << s;

		un[m] = static_cast<BIGINT_BASE>(u[m-1]) >> (HALF_BASE_BITS-s);
		for (int i = m - 1; i > 0; --i)
			un[i] = (u[i] << s) | (static_cast<BIGINT_BASE>(u[i-1]) >> (HALF_BASE_BITS-s));
		un[0] = u[0] << s;

		for (int j = m - n; j >= 0; --j){
			BIGINT_BASE fullWord = (static_cast<BIGINT_BASE>(un[j+n])<<HALF_BASE_BITS) + un[j+n-1];
			BIGINT_BASE qhat = fullWord / vn[n-1];
			BIGINT_BASE rhat = fullWord - qhat*vn[n-1];

			do{
				if ((qhat > lower_half_mask) ||
					qhat*vn[n-2] > (rhat << HALF_BASE_BITS) + un[j+n-2])
				{
					--qhat;
					rhat += static_cast<BIGINT_BASE>(vn[n-1]);
					if (rhat <= lower_half_mask) continue;
				}
			} while (false);

			BIGINT_BASE k = 0;
			for (int i = 0; i < n; ++i) {
				BIGINT_BASE p = qhat * vn[i];
				BIGINT_BASE t = un[i+j] - k - (p & lower_half_mask);
				un[i+j] = static_cast<BIGINT_SHORT>(t);
				k = p >> HALF_BASE_BITS;
				if ((t >> HALF_BASE_BITS) > 0)
					k -= (t >> HALF_BASE_BITS) | (lower_half_mask << HALF_BASE_BITS);
			}
			bool negative = un[j+n] < k;
			un[j+n] -= static_cast<BIGINT_SHORT>(k);

			q[j] = static_cast<BIGINT_SHORT>(qhat);
			if (negative){
				--q[j];
				k = 0;
				for (int i = 0; i < n; ++i) {
					k += static_cast<BIGINT_BASE>(un[i+j]) + vn[i];
					un[i+j] = static_cast<BIGINT_SHORT>(k);
					k >>= HALF_BASE_BITS;
				}
				un[j+n] += static_cast<BIGINT_SHORT>(k);
			}
		}
		for (int i = m - n + 1; i < BIGINTSIZE*2; ++i)
			q[i] = 0U;
		if (remainder != NULL) {
			*remainder = 0U;
			BIGINT_SHORT *r = (BIGINT_SHORT*)remainder->data;
			for (int i = 0; i < n; ++i)
				r[i] = (un[i] >> s) | (static_cast<BIGINT_BASE>(un[i+1]) << (HALF_BASE_BITS-s));
		}
	}
#else
	friend void DivRem_Unsigned(const ubigint &u, const ubigint &v, ubigint &quotient, ubigint *remainder) {
		int shiftcnt = 0;

		if (!v) {
			BIGINT_ASSERT(false);
			shiftcnt = 1 / shiftcnt;
			return;
		}

		STATIC_UNLESS_MULTITHREADED ubigint a2, b2;
		a2 = u;
		b2 = v;
		quotient = 0U;
		shiftcnt = findHighestBitSet(a2) - findHighestBitSet(b2);
		if (shiftcnt > 0)
			b2 <<= shiftcnt;

		if (b2 > a2){
			b2 >>= 1;
			--shiftcnt;
		}
		while (shiftcnt >= 0) {
			int result = compare(a2, b2);
			if (result >= 0){
				a2 -= b2;
				quotient.bitSet(shiftcnt);
				if (!result) break;
			}
			b2 >>= 1;
			--shiftcnt;
		}

		if (remainder != NULL)
			*remainder = a2;
	}
#endif

	ubigint& Mul_short(const BIGINT_SHORT rhs) {
		STATIC_UNLESS_MULTITHREADED ubigint result;
		BIGINT_SHORT *w = (BIGINT_SHORT*)result.data;
		const BIGINT_SHORT *u = (const BIGINT_SHORT*)data;
		result = 0;
		BIGINT_BASE k = 0;
		int m = BIGINTSIZE*2;
		while (m > 0 && u[m-1] == 0)
			w[--m] = 0U;
		for (int i = 0; i < m; ++i) {
			k += static_cast<BIGINT_BASE>(u[i])*rhs + w[i];
			w[i] = static_cast<BIGINT_SHORT>(k);
			k >>= HALF_BASE_BITS;
		}
		if (k > 0 && m < BIGINTSIZE*2)
			w[m] = static_cast<BIGINT_SHORT>(k);
		return *this = result;
	}

	ubigint& Mul_int(const BIGINT_BASE rhs) {
		STATIC_UNLESS_MULTITHREADED ubigint result;
		BIGINT_SHORT *w = (BIGINT_SHORT*)result.data;
		const BIGINT_SHORT *u = (const BIGINT_SHORT*)data;
		const BIGINT_SHORT *v = (const BIGINT_SHORT*)&rhs;
		result = 0;
		int jMax = 2;
		while (jMax > 0 && v[jMax-1] == 0) --jMax;
		for (int j = 0; j < jMax; ++j) {
			BIGINT_BASE k = 0, vj = v[j];
			const int iMax = BIGINTSIZE*2-j;
			for (int i = 0; i < iMax; ++i) {
				const int ij = i + j;
				k += static_cast<BIGINT_BASE>(u[i])*vj + w[ij];
				w[ij] = static_cast<BIGINT_SHORT>(k);
				k >>= HALF_BASE_BITS;
			}
		}
		return *this = result;
	}

	static void Multiply(const ubigint &a, const ubigint &b, ubigint &result) {
		if (&a == &b) {
			result = sqr(a);
			return;
		}
		BIGINT_ASSERT(&result != &a && &result != &b);
		BIGINT_SHORT *w = (BIGINT_SHORT*)result.data;
		const BIGINT_SHORT *u = (const BIGINT_SHORT*)a.data;
		const BIGINT_SHORT *v = (const BIGINT_SHORT*)b.data;
		result = 0;
		int jMax = BIGINTSIZE*2;
		while (jMax > 0 && v[jMax-1] == 0) --jMax;
		for (int j = 0; j < jMax; ++j) {
			BIGINT_BASE k = 0, vj = v[j];
			const int iMax = BIGINTSIZE*2-j;
			for (int i = 0; i < iMax; ++i) {
				const int ij = i + j;
				k += u[i]*vj + w[ij];
				w[ij] = static_cast<BIGINT_SHORT>(k);
				k >>= HALF_BASE_BITS;
			}
		}
	}

public:

	friend ubigint sqr(const ubigint &x) {
		STATIC_UNLESS_MULTITHREADED ubigint result, sqrPart;
		BIGINT_SHORT *w = (BIGINT_SHORT*)result.data;
		const BIGINT_SHORT *u = (const BIGINT_SHORT*)x.data;
		result = 0;

		int jMax = BIGINTSIZE*2;
		while (jMax > 0 && u[jMax-1] == 0) --jMax;
		for (int j = 1; j < jMax; ++j) {
			BIGINT_BASE k = 0, uj = u[j];
			const int iMax = j < BIGINTSIZE ? j : BIGINTSIZE*2-j;
			for (int i = 0; i < iMax; ++i) {
				const int ij = i + j;
				k += u[i]*uj + w[ij];
				w[ij] = static_cast<BIGINT_SHORT>(k);
				k >>= HALF_BASE_BITS;
			}
			if (j < BIGINTSIZE)
				w[j+j] = static_cast<BIGINT_SHORT>(k);
		}
		result <<= 1;

		int j = 0, jMax2 = jMax < BIGINTSIZE ? jMax : BIGINTSIZE;
		while (j < jMax2) {
			BIGINT_BASE uj = u[j];
			sqrPart.data[j++] = uj*uj;
		}
		while (j < BIGINTSIZE)
			sqrPart.data[j++] = 0;
		result += sqrPart;
		return result;
	}

	ubigint() {}
	ubigint(char x)               { this->internalInitialise(x, (x >= 0) ? 0 : 0xFF); }
	ubigint(signed char x)        { this->internalInitialise(x, (x >= 0) ? 0 : 0xFF); }
	ubigint(short x)              { this->internalInitialise(x, (x >= 0) ? 0 : 0xFF); }
	ubigint(int x)                { this->internalInitialise(x, (x >= 0) ? 0 : 0xFF); }
	ubigint(long x)               { this->internalInitialise(x, (x >= 0) ? 0 : 0xFF); }
	ubigint(long long x)          { this->internalInitialise(x, (x >= 0) ? 0 : 0xFF); }
	ubigint(unsigned char x)      { this->internalInitialise(x); }
	ubigint(unsigned short x)     { this->internalInitialise(x); }
	ubigint(unsigned int x)       { this->internalInitialise(x); }
	ubigint(unsigned long x)      { this->internalInitialise(x); }
	ubigint(unsigned long long x) { this->internalInitialise(x); }

	template <int OTHER_BIGINT_TOTAL_BITS>
	ubigint(const ubigint<OTHER_BIGINT_TOTAL_BITS>& x) {
		this->internalInitialise(x);
	}

	template <int OTHER_BIGINT_TOTAL_BITS>
	ubigint(const sbigint<OTHER_BIGINT_TOTAL_BITS>& x) {
		this->internalInitialise(x, (x >= 0) ? 0 : 0xFF);
	}

#ifndef BIGINT_EXCLUDE_STRINGS
	ubigint(const std::string &s) {
		std::stringstream ss;
		ss << s.c_str();
		ss >> *this;
	}

	ubigint(const std::wstring &ws) {
		std::wstringstream wss;
		wss << ws.c_str();
		wss >> *this;
	}
#endif

	ubigint(float f) {
		this->internalInitialiseFromFloating(f, false);
	}

	ubigint(double d) {
		this->internalInitialiseFromFloating(d, false);
	}

	ubigint(long double ld) {
		this->internalInitialiseFromFloating(ld, false);
	}

	operator char() const               { char x;               this->internalExtract(x); return x; }
	operator signed char() const        { signed char x;        this->internalExtract(x); return x; }
	operator short() const              { short x;              this->internalExtract(x); return x; }
	operator int() const                { int x;                this->internalExtract(x); return x; }
	operator long() const               { long x;               this->internalExtract(x); return x; }
	operator long long() const          { long long x;          this->internalExtract(x); return x; }
	operator unsigned char() const      { unsigned char x;      this->internalExtract(x); return x; }
	operator unsigned short() const     { unsigned short x;     this->internalExtract(x); return x; }
	operator unsigned int() const       { unsigned int x;       this->internalExtract(x); return x; }
	operator unsigned long() const      { unsigned long x;      this->internalExtract(x); return x; }
	operator unsigned long long() const { unsigned long long x; this->internalExtract(x); return x; }

	operator float() const {
		return this->internalExtractToFloating<float>();
	}

	operator double() const {
		return this->internalExtractToFloating<double>();
	}

	operator long double() const {
		return this->internalExtractToFloating<long double>();
	}

	friend void swap(ubigint &a, ubigint &b) {
		using std::swap;
		for (int i = 0; i < BIGINTSIZE; ++i)
			swap(a.data[i], b.data[i]);
	}

	template <int OTHER_BIGINT_TOTAL_BITS>
	ubigint& operator = (const ubigint<OTHER_BIGINT_TOTAL_BITS> &x) {
		this->internalInitialise(x);
		return *this;
	}

	template <int OTHER_BIGINT_TOTAL_BITS>
	ubigint& operator = (const sbigint<OTHER_BIGINT_TOTAL_BITS>& x) {
		this->internalInitialise(x, (x >= 0) ? 0 : 0xFF);
		return *this;
	}

	friend void minVal(ubigint &v) {
		for (int i = 0; i < BIGINTSIZE; ++i)
			v.data[i] = 0U;
	}

	friend void maxVal(ubigint &v) {
		for (int i = 0; i < BIGINTSIZE; ++i)
			v.data[i] = BASE_MAX;
	}

#ifndef BIGINT_EXCLUDE_STRINGS
	std::string toString() const {
		return *this;
	}

	std::wstring toWString() const {
		return *this;
	}

	operator std::string() const {
		std::stringstream ss;
		ss << *this;
		return ss.str();
	}

	operator std::wstring() const {
		std::wstringstream wss;
		wss << *this;
		return wss.str();
	}

	friend std::ostream& operator << (std::ostream &os, const ubigint &a) {
		return ubigint_t::output(os, a, false);
	}

	friend std::wostream& operator << (std::wostream &wos, const ubigint &a) {
		return ubigint_t::output(wos, a, false);
	}

	friend std::istream& operator >> (std::istream &is, ubigint &val) {
		return ubigint_t::input(is, val.asSigned());
	}

	friend std::wistream& operator >> (std::wistream &wis, ubigint &val) {
		return ubigint_t::input(wis, val.asSigned());
	}
#endif

	const sbigint_t& asSigned() const
	{ return reinterpret_cast<const sbigint_t&>(*this); }
	sbigint_t& asSigned()
	{ return reinterpret_cast<sbigint_t&>(*this); }

	void bitClear(int b) {
		unsigned int bit = b;
		if (bit < BIGINT_TOTAL_BITS) {
			data[bit/BASE_BITS] &= ~(BIGINT_BASE(1)<<(bit%BASE_BITS));
		} else
			BIGINT_ASSERT(false);
	}

	void bitSet(int b) {
		unsigned int bit = b;
		if (bit < BIGINT_TOTAL_BITS) {
			data[bit/BASE_BITS] |= BIGINT_BASE(1)<<(bit%BASE_BITS);
		} else
			BIGINT_ASSERT(false);
	}

	void bitToggle(int b) {
		unsigned int bit = b;
		if (bit < BIGINT_TOTAL_BITS) {
			data[bit/BASE_BITS] ^= BIGINT_BASE(1)<<(bit%BASE_BITS);
		} else
			BIGINT_ASSERT(false);
	}

	bool bitTest(int b) const {
		unsigned int bit = b;
		if (bit < BIGINT_TOTAL_BITS) {
			return (data[bit/BASE_BITS] & (BIGINT_BASE(1)<<(bit%BASE_BITS))) != 0;
		} else {
			BIGINT_ASSERT(false);
			return false;
		}
	}

	bool highBitSet() const {
		return data[MSBINDEX] >> (BASE_BITS-1) != 0U;
	}

	bool lowBitSet() const {
		return (data[LSBINDEX] & 1U) != 0U;
	}

	ubigint& operator &=(const ubigint &x) {
		for (int i = 0; i < BIGINTSIZE; ++i)
			data[i] &= x.data[i];
		return *this;
	}

	ubigint& operator |=(const ubigint &x) {
		for (int i = 0; i < BIGINTSIZE; ++i)
			data[i] |= x.data[i];
		return *this;
	}

	ubigint& operator ^=(const ubigint &x) {
		for (int i = 0; i < BIGINTSIZE; ++i)
			data[i] ^= x.data[i];
		return *this;
	}

	ubigint& operator>>=(int shift) {
		unsigned int ushift = shift;
		ushift %= BIGINT_TOTAL_BITS;
		if (ushift != 0) {
			int source = ushift / BASE_BITS;
			int remaindershift = ushift & (BASE_BITS-1);
			int othershift = BASE_BITS - remaindershift;

			FORWARDS_LOOP(i) {
				if (source < BIGINTSIZE) {
					data[i] = data[BASE_INDEX(source)] >> remaindershift;
					if (++source < BIGINTSIZE && othershift < BASE_BITS)
						data[i] |= data[BASE_INDEX(source)] << othershift;
				} else {
					data[i] = 0U;
				}
			}
		}
		return *this;
	}

	ubigint& operator<<=(int shift) {
		unsigned int ushift = shift;
		ushift %= BIGINT_TOTAL_BITS;
		if (ushift != 0) {
			int source = BIGINTSIZE-1 - ushift / BASE_BITS;
			int remaindershift = ushift & (BASE_BITS-1);
			int othershift = BASE_BITS - remaindershift;

			BACKWARDS_LOOP(i) {
				if (source >= 0) {
					data[i] = data[BASE_INDEX(source)] << remaindershift;
					if (--source >= 0 && othershift < BASE_BITS)
						data[i] |= data[BASE_INDEX(source)] >> othershift;
				} else {
					data[i] = 0U;
				}
			}
		}
		return *this;
	}

	ubigint& operator +=(const ubigint &x) {
		BIGINT_BASE carry = 0U;

		FORWARDS_LOOP(i) {
			data[i] += x.data[i] + carry;
			if (!carry) {
				carry = (data[i] <  x.data[i]);
			} else {
				carry = (data[i] <= x.data[i]);
			}
		}
		return *this;
	}

	ubigint& operator -=(const ubigint &x) {
		BIGINT_BASE borrow = 0U, prevdigit;

		FORWARDS_LOOP(i) {
			prevdigit = data[i];
			data[i] -= x.data[i] + borrow;
			if (!borrow) {
				borrow = (prevdigit <  x.data[i]);
			} else {
				borrow = (prevdigit <= x.data[i]);
			}
		}
		return *this;
	}

	ubigint& operator *=(const ubigint &x) {
		STATIC_UNLESS_MULTITHREADED ubigint result;
		ubigint_t::Multiply(*this, x, result);
		return *this = result;
	}

	ubigint& operator /=(const ubigint &x) {
		DivRem_Unsigned(*this, x, *this, NULL);
		return *this;
	}

	ubigint& operator %=(const ubigint &x) {
		STATIC_UNLESS_MULTITHREADED ubigint quotient;
		DivRem_Unsigned(*this, x, quotient, this);
		return *this;
	}

	friend int compare(const ubigint &a, const ubigint &b) {
		if (&a != &b) {
			BACKWARDS_LOOP(i) {
				if (a.data[i] < b.data[i])
					return -1;
				if (a.data[i] > b.data[i])
					return 1;
			}
		}
		return 0;
	}

	friend bool operator ==(const ubigint &a, const ubigint &b) {
		if (&a != &b) {
			for (int i = 0; i < BIGINTSIZE; ++i)
				if (a.data[i] != b.data[i])
					return false;
		}
		return true;
	}

	friend bool operator !=(const ubigint &a, const ubigint &b) {
		return !(a == b);
	}

	friend bool operator < (const ubigint &a, const ubigint &b)
	{ return compare(a, b) < 0; }

	friend bool operator > (const ubigint &a, const ubigint &b)
	{ return compare(a, b) > 0; }

	friend bool operator <= (const ubigint &a, const ubigint &b)
	{ return compare(a, b) <= 0; }

	friend bool operator >= (const ubigint &a, const ubigint &b)
	{ return compare(a, b) >= 0; }

	ubigint operator>> (int shift) const {
		STATIC_UNLESS_MULTITHREADED ubigint result;
		result = *this;
		result >>= shift;
		return result;
	}

	ubigint operator<< (int shift) const {
		STATIC_UNLESS_MULTITHREADED ubigint result;
		result = *this;
		result <<= shift;
		return result;
	}

	friend ubigint operator & (const ubigint &a, const ubigint &b) {
		STATIC_UNLESS_MULTITHREADED ubigint result;
		for (int i = 0; i < BIGINTSIZE; ++i)
			result.data[i] = a.data[i] & b.data[i];
		return result;
	}

	friend ubigint operator | (const ubigint &a, const ubigint &b) {
		STATIC_UNLESS_MULTITHREADED ubigint result;
		for (int i = 0; i < BIGINTSIZE; ++i)
			result.data[i] = a.data[i] | b.data[i];
		return result;
	}

	friend ubigint operator ^ (const ubigint &a, const ubigint &b) {
		STATIC_UNLESS_MULTITHREADED ubigint result;
		for (int i = 0; i < BIGINTSIZE; ++i)
			result.data[i] = a.data[i] ^ b.data[i];
		return result;
	}

	friend ubigint operator + (const ubigint &a, const ubigint &b) {
		STATIC_UNLESS_MULTITHREADED ubigint result;
		result = a;
		result += b;
		return result;
	}

	friend ubigint operator - (const ubigint &a, const ubigint &b) {
		STATIC_UNLESS_MULTITHREADED ubigint result;
		result = a;
		result -= b;
		return result;
	}

	friend ubigint operator * (const ubigint &a, const ubigint &b) {
		STATIC_UNLESS_MULTITHREADED ubigint result;
		ubigint_t::Multiply(a, b, result);
		return result;
	}

	friend ubigint operator / (const ubigint &a, const ubigint &b) {
		STATIC_UNLESS_MULTITHREADED ubigint quotient;
		DivRem_Unsigned(a, b, quotient, NULL);
		return quotient;
	}

	friend ubigint operator % (const ubigint &a, const ubigint &b) {
		STATIC_UNLESS_MULTITHREADED ubigint quotient, remainder;
		DivRem_Unsigned(a, b, quotient, &remainder);
		return remainder;
	}

	ubigint& operator++ (){
		int i = LSBINDEX;
		while (++data[i] == 0 && ++i < BIGINTSIZE) {}
		return *this;
	}

	ubigint operator++ (int){
		STATIC_UNLESS_MULTITHREADED ubigint result;
		result = *this;
		++*this;
		return result;
	}

	ubigint& operator-- (){
		int i = LSBINDEX;
		while (--data[i] == BASE_MAX && ++i < BIGINTSIZE) {}
		return *this;
	}

	ubigint operator-- (int){
		STATIC_UNLESS_MULTITHREADED ubigint result;
		result = *this;
		--*this;
		return result;
	}

	bool operator ! () const{
		bool Result = true;
		for (int i = 0; i < BIGINTSIZE; ++i)
			Result &= !data[i];
		return Result;
	}

	ubigint operator ~ () const {
		STATIC_UNLESS_MULTITHREADED ubigint result;
		for (int i = 0; i < BIGINTSIZE; ++i)
			result.data[i] = ~data[i];
		return result;
	}

	ubigint operator + () const{
		return *this;
	}

	ubigint operator - () const{
		STATIC_UNLESS_MULTITHREADED ubigint result;
		for (int i = 0; i < BIGINTSIZE; ++i)
			result.data[i] = ~data[i];
		++result;
		return result;
	}

	friend ubigint sqrt(const ubigint &x){
		STATIC_UNLESS_MULTITHREADED ubigint num, res, temp;
		int bit = findHighestBitSet(x);
		bit -= (bit & 1);
		num = x;
		res = 0;
		while (bit >= 0) {
			temp = res;
			temp.bitSet(bit);
			res >>= 1;
			if (num >= temp) {
				num -= temp;
				res.bitSet(bit);
			}
			bit -= 2;
		}
		return res;
	}

	friend ubigint factorial(const ubigint &x) {
		STATIC_UNLESS_MULTITHREADED ubigint result;
		BIGINT_BASE f = x;
		result = 1;
		while (f > static_cast<BIGINT_BASE>((unsigned)LOWER_HALF_MASK))
			result.Mul_int(f--);
		while (f > 0U)
			result.Mul_short((BIGINT_SHORT)f--);
		return result;
	}

	friend int jacobi(const ubigint &m, const ubigint &n) {
		STATIC_UNLESS_MULTITHREADED ubigint m2, n2;
		BIGINT_ASSERT(n.lowBitSet());
		m2 = m;
		n2 = n;
		int sign = 1;
		for (;;) {
			m2 %= n2;
			if (!m2)
				return 0;
			int lo = findLowestBitSet(m2);
			if (lo > 0) {
				m2 >>= lo;
				if ((lo & 1) != 0 && ((1 << static_cast<int>(n2&7)) & ((1<<3) | (1<<5))) != 0)
					sign = -sign;
			}
			if (m2 == 1)
				return sign;
			if ((3 == static_cast<int>(n2&3)) && (3 == static_cast<int>(m2&3)))
				sign = -sign;
			swap(m2, n2);
		}
	}

	bool MillerRabin(const ubigint &v, unsigned int maxa) {
		STATIC_UNLESS_MULTITHREADED ubigint vMinus1, d, x;
		vMinus1 = v;
		--v;
		unsigned int s = findLowestBitSet(vMinus1);
		d = vMinus1 >> (int)s;

		STATIC_UNLESS_MULTITHREADED const unsigned int primesUnder1000[] = {
			  2,   3,   5,   7,  11,  13,  17,  19,  23,  29,
			 31,  37,  41,  43,  47,  53,  59,  61,  67,  71,
			 73,  79,  83,  89,  97, 101, 103, 107, 109, 113,
			127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
			179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
			233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
			283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
			353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
			419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
			467, 479, 487, 491, 499, 503, 509, 521, 523, 541,
			547, 557, 563, 569, 571, 577, 587, 593, 599, 601,
			607, 613, 617, 619, 631, 641, 643, 647, 653, 659,
			661, 673, 677, 683, 691, 701, 709, 719, 727, 733,
			739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
			811, 821, 823, 827, 829, 839, 853, 857, 859, 863,
			877, 881, 883, 887, 907, 911, 919, 929, 937, 941,
			947, 953, 967, 971, 977, 983, 991, 997,
		};

		const unsigned int *end = primesUnder1000 + sizeof(primesUnder1000)/sizeof(primesUnder1000[0]);
		for (const unsigned int *it = primesUnder1000; it != end; ++it) {
			unsigned int a = *it;
			x = modpow(a, d, v);
			if (x != 1 && x != vMinus1) {
				unsigned int r = 1;
				STATIC_UNLESS_MULTITHREADED ubigint dd;
				dd = d;
				for (; r < s; r++) {
					dd <<= 1;
					x = modpow(a, dd, v);
					if (x == vMinus1)
						break;
				}
				if (r >= s)
					return false;
			}
			if (a >= maxa)
				break;
		}
		return true;
	}

	friend bool isPrime(const ubigint &x) {
		if (x <= (ubigint)1U) return false;
		if (x == (ubigint)2U) return true;
		if (!x.lowBitSet()) return false;

		STATIC_UNLESS_MULTITHREADED ubigint stop, factor;
		stop = sqrt(x);
		for (factor = 3U; factor <= stop; factor+=2U) {
			if (!(x % factor)) {
				return false;
			}
		}
		return true;
	}

	friend ubigint gcd(const ubigint &a, const ubigint &b) {
		if (!a)
			return b;
		if (!b)
			return a;
		STATIC_UNLESS_MULTITHREADED ubigint a2, b2, c;
		a2 = a;
		b2 = b;
		int shift = 0;
		while (!((a2.data[LSBINDEX] | b2.data[LSBINDEX]) & 1U)) {
			a2 >>= 1;
			b2 >>= 1;
			++shift;
		}
		while (a2 > (ubigint)0U) {
			if (!(a2.data[LSBINDEX] & 1U))
				a2 >>= 1;
			else if (!(b2.data[LSBINDEX] & 1U))
				b2 >>= 1;
			else {
				c = (abs(a2.asSigned() - b2.asSigned()) >> 1).asUnsigned();
				if (a2 < b2)
					b2 = c;
				else
					a2 = c;
			}
		}
		return b2 << shift;
	}

	friend ubigint lcm(const ubigint &a, const ubigint &b) {
		return (a / gcd(a, b)) * b;
	}

	friend ubigint gcdext(const ubigint &a, const ubigint &b, ubigint &s, ubigint &t) {
		STATIC_UNLESS_MULTITHREADED ubigint a2, b2, quo, rem, s1, t1, s2, t2;
		if (!b) {
			s = 1;
			t = 0;
			return a;
		}
		a2 = a;
		b2 = b;
		s1 = t2 = 1;
		quo = t1 = s2 = 0;

		for (;;) {
			DivRem_Unsigned(a2, b2, quo, &a2);
			if (!a2) {
				s = s2;
				t = t2;
				return b2;
			}
			s1 -= quo*s2;
			t1 -= quo*t2;

			DivRem_Unsigned(b2, a2, quo, &b2);
			if (!b2) {
				s = s1;
				t = t1;
				return a2;
			}
			s2 -= quo*s1;
			t2 -= quo*t1;
		}
	}

	friend ubigint bitRotateLeft(const ubigint &x, int shift) {
		return bitRotateRight(x, BIGINT_TOTAL_BITS-shift);
	}

	friend ubigint bitRotateRight(const ubigint &x, int shift) {
		STATIC_UNLESS_MULTITHREADED ubigint y;
		unsigned int ushift = shift;
		ushift %= BIGINT_TOTAL_BITS;
		if (ushift != 0) {
			int source = (ushift / BASE_BITS) % BIGINTSIZE;
			int remaindershift = ushift & (BASE_BITS-1);

			if (remaindershift != 0) {
				int othershift = BASE_BITS - remaindershift;
				FORWARDS_LOOP(i) {
					int source1 = source;
					if (++source == BIGINTSIZE)
						source = 0;
					y.data[i] = (x.data[BASE_INDEX(source1)] >> remaindershift) |
								(x.data[BASE_INDEX(source)] << othershift);
				}
			} else {
				FORWARDS_LOOP(i) {
					y.data[i] = x.data[BASE_INDEX(source)];
					if (++source == BIGINTSIZE)
						source = 0;
				}
			}
			return y;
		}
		return x;
	}

	friend int findHighestBitSet(const ubigint &x) {
		int result = BIGINT_TOTAL_BITS-1;
		BACKWARDS_LOOP(i) {
			if (x.data[i] != 0) {
				BIGINT_BASE temp = x.data[i];
				BIGINT_BASE tempMax = BASE_MAX;
				int shift = HALF_BASE_BITS;
				do {
					tempMax <<= shift;
					if ((temp & tempMax) == 0) {
						result -= shift;
						temp <<= shift;
					}
				} while ((shift >>= 1) > 0);
				break;
			}
			result -= BASE_BITS;
		}
		return result;
	}

	friend int findLowestBitSet(const ubigint &x) {
		if (!x)
			return -1;
		int result = 0;
		FORWARDS_LOOP(i) {
			if (x.data[i] != 0) {
				BIGINT_BASE temp = x.data[i];
				BIGINT_BASE tempMax = BASE_MAX;
				int shift = HALF_BASE_BITS;
				do {
					tempMax >>= shift;
					if ((temp & tempMax) == 0) {
						result += shift;
						temp >>= shift;
					}
				} while ((shift>>=1) > 0);
				break;
			}
			result += BASE_BITS;
		}
		return result;
	}

	friend bool isPow2(const ubigint &x) {
		bool found = false;
		for (int i = 0; i < BIGINTSIZE; ++i) {
			if (x.data[i] != 0) {
				if (found)
					return false;
				if ((x.data[i] & (x.data[i]-1)) != 0)
					return false;
				found = true;
			}
		}
		return true;
	}

	friend ubigint nextPow2(const ubigint &x) {
		int high = findHighestBitSet(x);
		if (high < 0)
			return 1;
		STATIC_UNLESS_MULTITHREADED ubigint temp;
		temp = 0;
		temp.bitSet(high);
		return (temp < x) ? (temp << 1) : temp;
	}

	friend int ceillog2(const ubigint &x) {
		int high = findHighestBitSet(x);
		if (high < 0)
			return 0;
		STATIC_UNLESS_MULTITHREADED ubigint temp;
		temp = 0;
		temp.bitSet(high);
		return (temp < x) ? (high + 1) : high;
	}

	friend int popcount(const ubigint &x) {
		int count = 0;
		for (int i = 0; i < BIGINTSIZE; ++i)
			count += bigintPopCounter<BIGINT_BASE>::popCount(x.data[i]);
		return count;
	}

	friend ubigint pow(const ubigint &a, int b) {
		if (b < 0)
			return (ubigint)0;
		STATIC_UNLESS_MULTITHREADED ubigint result, a2;
		result = (ubigint)1U;
		if (a == result)
			return result;
		a2 = a;
		while (b) {
			if (b & 1)
				result *= a2;
			b >>= 1;
			a2 *= a2;
		}
		return result;
	}

	friend ubigint modinv(const ubigint &x, const ubigint &n) {
		STATIC_UNLESS_MULTITHREADED ubigint s, t;
		if (gcdext(x, n, s, t) != 1)
			return 0;
		return s % n;
	}

	friend ubigint modpow(const ubigint &base, const ubigint &exp, const ubigint &mod) {
		STATIC_UNLESS_MULTITHREADED ubigint<BIGINT_TOTAL_BITS*2> base2, mod2;
		STATIC_UNLESS_MULTITHREADED ubigint result;
		base2 = base;
		mod2 = mod;
		result = 1;
		int expBit = 0, lastExpBit = findHighestBitSet(exp);
		while (expBit <= lastExpBit) {
			if (exp.bitTest(expBit))
				result = (ubigint<BIGINT_TOTAL_BITS*2>(result) * base2) % mod2;
			++expBit;
			base2 = sqr(base2) % mod2;
		}
		return result;
	}

	friend ubigint modpow(const ubigint &base, int exp, const ubigint &mod) {
		STATIC_UNLESS_MULTITHREADED ubigint<BIGINT_TOTAL_BITS*2> base2, mod2;
		STATIC_UNLESS_MULTITHREADED ubigint result;
		base2 = base;
		mod2 = mod;
		result = 1;
		while (exp > 0) {
			if (exp & 1)
				result = (ubigint<BIGINT_TOTAL_BITS*2>(result) * base2) % mod2;
			exp >>= 1;
			base2 = sqr(base2) % mod2;
		}
		return result;
	}

	friend bool operator < (const ubigint &q, int a) { return q < ubigint(a); }
	friend bool operator > (const ubigint &q, int a) { return ubigint(a) < q; }
	friend bool operator <=(const ubigint &q, int a) { return !(ubigint(a) < q); }
	friend bool operator >=(const ubigint &q, int a) { return !(q < ubigint(a)); }
	friend bool operator ==(const ubigint &q, int a) { return q == ubigint(a); }
	friend bool operator !=(const ubigint &q, int a) { return q != ubigint(a); }
	friend bool operator < (int a, const ubigint &q) { return ubigint(a) < q; }
	friend bool operator > (int a, const ubigint &q) { return q < ubigint(a); }
	friend bool operator <=(int a, const ubigint &q) { return !(q < ubigint(a)); }
	friend bool operator >=(int a, const ubigint &q) { return !(ubigint(a) < q); }
	friend bool operator ==(int a, const ubigint &q) { return ubigint(a) == q; }
	friend bool operator !=(int a, const ubigint &q) { return ubigint(a) != q; }

	friend ubigint operator & (const ubigint &q, int a) { return q & ubigint(a); }
	friend ubigint operator | (const ubigint &q, int a) { return q | ubigint(a); }
	friend ubigint operator ^ (const ubigint &q, int a) { return q ^ ubigint(a); }
	friend ubigint operator & (int a, const ubigint &q) { return ubigint(a) & q; }
	friend ubigint operator | (int a, const ubigint &q) { return ubigint(a) | q; }
	friend ubigint operator ^ (int a, const ubigint &q) { return ubigint(a) ^ q; }
	friend ubigint operator + (const ubigint &q, int a) { return q + ubigint(a); }
	friend ubigint operator - (const ubigint &q, int a) { return q - ubigint(a); }
	friend ubigint operator * (const ubigint &q, int a) { return q * ubigint(a); }
	friend ubigint operator / (const ubigint &q, int a) { return q / ubigint(a); }
	friend ubigint operator % (const ubigint &q, int a) { return q % ubigint(a); }
	friend ubigint operator + (int a, const ubigint &q) { return ubigint(a) + q; }
	friend ubigint operator - (int a, const ubigint &q) { return ubigint(a) - q; }
	friend ubigint operator * (int a, const ubigint &q) { return ubigint(a) * q; }
	friend ubigint operator / (int a, const ubigint &q) { return ubigint(a) / q; }
	friend ubigint operator % (int a, const ubigint &q) { return ubigint(a) % q; }
};

template <int BIGINT_TOTAL_BITS>
class sbigint : public ubigint<BIGINT_TOTAL_BITS>
{
	typedef ubigint<BIGINT_TOTAL_BITS> ubigint_t;
	typedef sbigint<BIGINT_TOTAL_BITS> sbigint_t;
	typedef typename ubigint_t::BIGINT_BASE BIGINT_BASE;
	typedef typename ubigint_t::BIGINT_SHORT BIGINT_SHORT;

	enum {
		BASE_BITS = ubigint_t::BASE_BITS,
		BIGINTSIZE = ubigint_t::BIGINTSIZE,
		LSBINDEX = ubigint_t::LSBINDEX,
		MSBINDEX = ubigint_t::MSBINDEX,
	};

	using ubigint_t::internalInitialise;
	using ubigint_t::internalExtract;

	static void SignedMultiply(const sbigint &a, const sbigint &b, sbigint &result) {
		BIGINT_ASSERT(&result != &a && &result != &b);
		if (a.highBitSet()) {
			if (b.highBitSet()) {
				if (&a == &b)
					result = sqr(-a);
				else
					ubigint_t::Multiply(-a, -b, result);
			} else {
				ubigint_t::Multiply(-a, b, result);
				result = -result;
			}
		} else {
			if (b.highBitSet()) {
				ubigint_t::Multiply(a, -b, result);
				result = -result;
			} else {
				ubigint_t::Multiply(a, b, result);
			}
		}
	}

public:
	sbigint() {}
	sbigint(char x)               { internalInitialise(x, (x >= 0) ? 0 : 0xFF); }
	sbigint(signed char x)        { internalInitialise(x, (x >= 0) ? 0 : 0xFF); }
	sbigint(short x)              { internalInitialise(x, (x >= 0) ? 0 : 0xFF); }
	sbigint(int x)                { internalInitialise(x, (x >= 0) ? 0 : 0xFF); }
	sbigint(long x)               { internalInitialise(x, (x >= 0) ? 0 : 0xFF); }
	sbigint(long long x)          { internalInitialise(x, (x >= 0) ? 0 : 0xFF); }
	sbigint(unsigned char x)      { internalInitialise(x); }
	sbigint(unsigned short x)     { internalInitialise(x); }
	sbigint(unsigned int x)       { internalInitialise(x); }
	sbigint(unsigned long x)      { internalInitialise(x); }
	sbigint(unsigned long long x) { internalInitialise(x); }

	operator char() const               { char x;               internalExtract(x); return x; }
	operator signed char() const        { signed char x;        internalExtract(x); return x; }
	operator short() const              { short x;              internalExtract(x, this->highBitSet() ? 0xFF : 0U); return x; }
	operator int() const                { int x;                internalExtract(x, this->highBitSet() ? 0xFF : 0U); return x; }
	operator long() const               { long x;               internalExtract(x, this->highBitSet() ? 0xFF : 0U); return x; }
	operator long long() const          { long long x;          internalExtract(x, this->highBitSet() ? 0xFF : 0U); return x; }
	operator unsigned char() const      { unsigned char x;      internalExtract(x); return x; }
	operator unsigned short() const     { unsigned short x;     internalExtract(x); return x; }
	operator unsigned int() const       { unsigned int x;       internalExtract(x); return x; }
	operator unsigned long() const      { unsigned long x;      internalExtract(x); return x; }
	operator unsigned long long() const { unsigned long long x; internalExtract(x); return x; }

	operator float() const {
		if (this->highBitSet()) {
			return -(float)(-*this).asUnsigned();
		} else {
			return (float)asUnsigned();
		}
	}

	operator double() const {
		if (this->highBitSet()) {
			return -(double)(-*this).asUnsigned();
		} else {
			return (double)asUnsigned();
		}
	}

	operator long double() const {
		if (this->highBitSet()) {
			return -(long double)(-*this).asUnsigned();
		} else {
			return (long double)asUnsigned();
		}
	}

	sbigint(float f) {
		ubigint_t::internalInitialiseFromFloating(f, true);
	}

	sbigint(double d) {
		ubigint_t::internalInitialiseFromFloating(d, true);
	}

	sbigint(long double ld) {
		ubigint_t::internalInitialiseFromFloating(ld, true);
	}

	template <int OTHER_BIGINT_TOTAL_BITS>
	sbigint(const ubigint<OTHER_BIGINT_TOTAL_BITS>& x) {
		internalInitialise(x);
	}

	template <int OTHER_BIGINT_TOTAL_BITS>
	sbigint(const sbigint<OTHER_BIGINT_TOTAL_BITS>& x) {
		internalInitialise(x, (x >= 0) ? 0 : 0xFF);
	}

	template <int OTHER_BIGINT_TOTAL_BITS>
	sbigint& operator = (const ubigint<OTHER_BIGINT_TOTAL_BITS>& x) {
		internalInitialise(x);
		return *this;
	}

	template <int OTHER_BIGINT_TOTAL_BITS>
	sbigint& operator = (const sbigint<OTHER_BIGINT_TOTAL_BITS> &x) {
		internalInitialise(x, (x >= 0) ? 0 : 0xFF);
		return *this;
	}

	friend void minVal(sbigint_t &v) {
		v = 0;
		v.bitSet(BIGINT_TOTAL_BITS-1);
	}

	friend void maxVal(sbigint_t &v) {
		v = -1;
		v.bitClear(BIGINT_TOTAL_BITS-1);
	}

#ifndef BIGINT_EXCLUDE_STRINGS
	sbigint(const std::string &s) {
		std::stringstream ss;
		ss << s.c_str();
		ss >> *this;
	}

	sbigint(const std::wstring &ws) {
		std::wstringstream wss;
		wss << ws.c_str();
		wss >> *this;
	}

	std::string toString() const {
		return *this;
	}

	std::wstring toWString() const {
		return *this;
	}

	operator std::string() const {
		std::stringstream ss;
		ss << *this;
		return ss.str();
	}

	operator std::wstring() const {
		std::wstringstream wss;
		wss << *this;
		return wss.str();
	}

	friend std::ostream& operator << (std::ostream &os, const sbigint &a) {
		return output(os, a, true);
	}

	friend std::wostream& operator << (std::wostream &wos, const sbigint &a) {
		return output(wos, a, true);
	}

	friend std::istream& operator >> (std::istream &is, sbigint &val) {
		return input(is, val);
	}

	friend std::wistream& operator >> (std::wistream &wis, sbigint &val) {
		return input(wis, val);
	}
#endif

	const ubigint_t& asUnsigned() const
	{ return reinterpret_cast<const ubigint_t&>(*this); }
	ubigint_t& asUnsigned()
	{ return reinterpret_cast<ubigint_t&>(*this); }

	sbigint& operator &=(const sbigint &x)
	{ return ( asUnsigned() &= x.asUnsigned() ).asSigned(); }

	sbigint& operator |=(const sbigint &x)
	{ return ( asUnsigned() |= x.asUnsigned() ).asSigned(); }

	sbigint& operator ^=(const sbigint &x)
	{ return ( asUnsigned() ^= x.asUnsigned() ).asSigned(); }

	sbigint& operator>>=(int shift) {
		unsigned int ushift = shift;
		ushift %= BIGINT_TOTAL_BITS;
		if (ushift != 0) {
			if (this->highBitSet()) {
				int source = ushift / BASE_BITS;
				int remaindershift = ushift & (BASE_BITS-1);
				int othershift = BASE_BITS - remaindershift;
				FORWARDS_LOOP(i) {
					if (source < BIGINTSIZE) {
						this->data[i] = this->data[BASE_INDEX(source++)] >> remaindershift;
						if (othershift < BASE_BITS)
							this->data[i] |= ((source < BIGINTSIZE) ? this->data[BASE_INDEX(source)] : BASE_MAX) << othershift;
					} else {
						this->data[i] = BASE_MAX;
					}
				}
			} else
				asUnsigned() >>= shift;
		}
		return *this;
	}

	sbigint& operator<<=(int shift)
	{ return ( asUnsigned() <<= shift ).asSigned(); }

	sbigint& operator *=(const sbigint &x) {
		STATIC_UNLESS_MULTITHREADED sbigint result;
		sbigint_t::SignedMultiply(*this, x, result);
		return *this = result;
	}

	sbigint& operator /=(const sbigint &x) {
		DivRem(*this, x, *this, NULL);
		return *this;
	}

	sbigint& operator %=(const sbigint &x) {
		STATIC_UNLESS_MULTITHREADED sbigint quotient;
		DivRem(*this, x, quotient, this);
		return *this;
	}

	friend void DivRem(const sbigint &a, const sbigint &b, sbigint &quotient, sbigint *remainder) {
		if (a.highBitSet()) {
			if (b.highBitSet()) {
				if (!remainder && a == -a && b == ~sbigint(0)) {
					int cause = static_cast<int>(a.data[MSBINDEX]);
					int overflow = static_cast<int>(b.data[MSBINDEX]);
					int please = cause % overflow;
					quotient = sbigint(please & ~please);
				} else if (&a == &b) {
					ubigint_t apos = -a;
					DivRem_Unsigned(apos, apos, quotient, remainder);
				} else
					DivRem_Unsigned(-a, -b, quotient, remainder);
			} else {
				DivRem_Unsigned(-a, b, quotient, remainder);
				quotient = -quotient;
			}
			if (remainder != NULL)
				*remainder = -*remainder;
		} else {
			if (b.highBitSet()) {
				DivRem_Unsigned(a, -b, quotient, remainder);
				quotient = -quotient;
			} else {
				DivRem_Unsigned(a, b, quotient, remainder);
			}
		}
	}

	friend void DivMod(const sbigint &a, const sbigint &b, sbigint &quotient, sbigint *modulus) {
		STATIC_UNLESS_MULTITHREADED sbigint remainder;
		if (modulus == NULL)
			modulus = &remainder;
		if (a.highBitSet()) {
			sbigint apos = -a;
			if (b.highBitSet()) {
				sbigint bpos = -b;
				 if (&a == &b) {
					DivRem_Unsigned(apos, apos, quotient, modulus);
				} else
					DivRem_Unsigned(apos, bpos, quotient, modulus);
				if (!!*modulus) {
					++quotient;
					*modulus = bpos - *modulus;
				}
			} else {
				DivRem_Unsigned(apos, b, quotient, modulus);
				if (!!*modulus) {
					++quotient;
					*modulus = b - *modulus;
				}
				quotient = -quotient;
			}
		} else {
			if (b.highBitSet()) {
				DivRem_Unsigned(a, -b, quotient, modulus);
				quotient = -quotient;
			} else
				DivRem_Unsigned(a, b, quotient, modulus);
		}
	}

	friend int compare(const sbigint &a, const sbigint &b) {
		if (&a != &b) {
			BIGINT_BASE lhsHighChunk = a.data[MSBINDEX] ^ (BIGINT_BASE(1) << (BASE_BITS-1));
			BIGINT_BASE rhsHighChunk = b.data[MSBINDEX] ^ (BIGINT_BASE(1) << (BASE_BITS-1));
			if (lhsHighChunk < rhsHighChunk)
				return -1;
			if (lhsHighChunk > rhsHighChunk)
				return 1;
			for (int i = BIGINTSIZE-2; i >= 0; --i)
			{
				if (a.data[i] < b.data[i])
					return -1;
				if (a.data[i] > b.data[i])
					return 1;
			}
		}
		return 0;
	}

	friend bool operator ==(const sbigint &a, const sbigint &b)
	{ return a.asUnsigned() == b.asUnsigned(); }

	friend bool operator !=(const sbigint &a, const sbigint &b)
	{ return a.asUnsigned() != b.asUnsigned(); }

	friend bool operator < (const sbigint &a, const sbigint &b)
	{ return compare(a, b) < 0; }

	friend bool operator > (const sbigint &a, const sbigint &b)
	{ return compare(a, b) > 0; }

	friend bool operator <= (const sbigint &a, const sbigint &b)
	{ return compare(a, b) <= 0; }

	friend bool operator >= (const sbigint &a, const sbigint &b)
	{ return compare(a, b) >= 0; }

	const sbigint operator >> (int shift) const {
		STATIC_UNLESS_MULTITHREADED sbigint result;
		result = *this;
		return (result >>= shift);
	}

	const sbigint operator << (int shift) const
	{ return ( asUnsigned() << shift ).asSigned(); }

	friend const sbigint operator & (const sbigint &a, const sbigint &b)
	{ return ( a.asUnsigned() & b.asUnsigned() ).asSigned(); }

	friend const sbigint operator | (const sbigint &a, const sbigint &b)
	{ return ( a.asUnsigned() | b.asUnsigned() ).asSigned(); }

	friend const sbigint operator ^ (const sbigint &a, const sbigint &b)
	{ return ( a.asUnsigned() ^ b.asUnsigned() ).asSigned(); }

	friend const sbigint operator + (const sbigint &a, const sbigint &b)
	{ return ( a.asUnsigned() + b.asUnsigned() ).asSigned(); }

	friend const sbigint operator - (const sbigint &a, const sbigint &b)
	{ return ( a.asUnsigned() - b.asUnsigned() ).asSigned(); }

	friend const sbigint operator * (const sbigint &a, const sbigint &b) {
		STATIC_UNLESS_MULTITHREADED sbigint result;
		sbigint_t::SignedMultiply(a, b, result);
		return result;
	}
	friend const sbigint operator / (const sbigint &a, const sbigint &b) {
		STATIC_UNLESS_MULTITHREADED sbigint quotient;
		DivRem(a, b, quotient, NULL);
		return quotient;
	}

	friend const sbigint operator % (const sbigint &a, const sbigint &b) {
		STATIC_UNLESS_MULTITHREADED sbigint quotient, result;
		DivRem(a, b, quotient, &result);
		return result;
	}

	sbigint& operator++ ()
	{ return (++asUnsigned()).asSigned(); }
	const sbigint operator++ (int)
	{ return (asUnsigned()++).asSigned(); }

	sbigint& operator-- ()
	{ return (--asUnsigned()).asSigned(); }
	const sbigint operator-- (int)
	{ return (asUnsigned()--).asSigned(); }

	const sbigint operator ~ () const
	{ return ( ~asUnsigned() ).asSigned(); }

	sbigint& operator + () const
	{ return (sbigint&)*this; }

	const sbigint operator - () const
	{ return ( -asUnsigned() ).asSigned(); }

	friend const sbigint sqrt(const sbigint &x){
		if (x.highBitSet())
			return sbigint(0U);
		return sqrt(x.asUnsigned()).asSigned();
	}

	friend const sbigint cbrt(const sbigint &q){
		STATIC_UNLESS_MULTITHREADED ubigint_t x, y, b, y2, y3;
		bool negative = false;
		if (q < 0) {
			negative = true;
			x = -q;
		} else
			x = q;
		int bit = (findHighestBitSet(x) / 3) * 3;
		y = 0;
		y2 = 0;
		while (bit >= 0) {
			y2 <<= 2;
			y <<= 1;
			y3 = y2 + y;
			b = (y3<<1) + y3;
			++b;
			b <<= bit;
			if (x >= b) {
				x -= b;
				y2 += (y<<1);
				++y2;
				++y;
			}
			bit -= 3;
		}
		return negative ? -y : y;
	}

	friend const sbigint abs(const sbigint &x) {
		return (x.highBitSet()) ? -x : x;
	}

	friend const sbigint factorial(const sbigint &x) {
		if (x.highBitSet())
			return sbigint(0U);
		return factorial(x.asUnsigned()).asSigned();
	}

	friend bool isPrime(const sbigint &x) {
		if (x.highBitSet())
			return false;
		return x.asUnsigned().isPrime();
	}

	friend const sbigint gcd(const sbigint &a, const sbigint &b) {
		return gcd(abs(a).asUnsigned(), abs(b).asUnsigned()).asSigned();
	}

	friend const sbigint pow(const sbigint &a, int b) {
		STATIC_UNLESS_MULTITHREADED sbigint temp;
		temp = pow(abs(a).asUnsigned(), b).asSigned();
		return ((a.highBitSet()) && ((b & 1) != 0)) ? -temp : temp;
	}

	friend bool operator < (const sbigint &q, int a) { return q < sbigint(a); }
	friend bool operator > (const sbigint &q, int a) { return sbigint(a) < q; }
	friend bool operator <=(const sbigint &q, int a) { return !(sbigint(a) < q); }
	friend bool operator >=(const sbigint &q, int a) { return !(q < sbigint(a)); }
	friend bool operator ==(const sbigint &q, int a) { return q == sbigint(a); }
	friend bool operator !=(const sbigint &q, int a) { return q != sbigint(a); }
	friend bool operator < (int a, const sbigint &q) { return sbigint(a) < q; }
	friend bool operator > (int a, const sbigint &q) { return q < sbigint(a); }
	friend bool operator <=(int a, const sbigint &q) { return !(q < sbigint(a)); }
	friend bool operator >=(int a, const sbigint &q) { return !(sbigint(a) < q); }
	friend bool operator ==(int a, const sbigint &q) { return sbigint(a) == q; }
	friend bool operator !=(int a, const sbigint &q) { return sbigint(a) != q; }

	friend const sbigint operator & (const sbigint &q, int a) { return q & sbigint(a); }
	friend const sbigint operator | (const sbigint &q, int a) { return q | sbigint(a); }
	friend const sbigint operator ^ (const sbigint &q, int a) { return q ^ sbigint(a); }
	friend const sbigint operator & (int a, const sbigint &q) { return sbigint(a) & q; }
	friend const sbigint operator | (int a, const sbigint &q) { return sbigint(a) | q; }
	friend const sbigint operator ^ (int a, const sbigint &q) { return sbigint(a) ^ q; }
	friend const sbigint operator + (const sbigint &q, int a) { return q + sbigint(a); }
	friend const sbigint operator - (const sbigint &q, int a) { return q - sbigint(a); }
	friend const sbigint operator * (const sbigint &q, int a) { return q * sbigint(a); }
	friend const sbigint operator / (const sbigint &q, int a) { return q / sbigint(a); }
	friend const sbigint operator % (const sbigint &q, int a) { return q % sbigint(a); }
	friend const sbigint operator + (int a, const sbigint &q) { return sbigint(a) + q; }
	friend const sbigint operator - (int a, const sbigint &q) { return sbigint(a) - q; }
	friend const sbigint operator * (int a, const sbigint &q) { return sbigint(a) * q; }
	friend const sbigint operator / (int a, const sbigint &q) { return sbigint(a) / q; }
	friend const sbigint operator % (int a, const sbigint &q) { return sbigint(a) % q; }
};

#ifndef BIGINT_EXCLUDE_NUMERIC_LIMITS
template<int N>
class num_base
{
	static const bool is_specialized = true;

	static const int digits = N;
	static const int digits10 = int(N * 0.30102999566398120);
	static const int max_digits10 = 0;
	static const bool is_integer = true;
	static const bool is_exact = true;
	static const int radix = 2;

	static const int  min_exponent = 0;
	static const int  min_exponent10 = 0;
	static const int  max_exponent = 0;
	static const int  max_exponent10 = 0;

	static const bool has_infinity = false;
	static const bool has_quiet_NaN = false;
	static const bool has_signaling_NaN = false;
	static const std::float_denorm_style has_denorm = std::denorm_absent;
	static const bool has_denorm_loss = false;

	static const bool is_iec559 = false;
	static const bool is_bounded = true;
	static const bool is_modulo = true;

	static const bool traps = false;
	static const bool tinyness_before = false;
	static const std::float_round_style round_style = std::round_toward_zero;
};

namespace std {
	template<int N>
	class numeric_limits< ubigint<N> > :
		public num_base<N>
	{
	public:
		typedef ubigint<N> T;
		static T (min)() throw() { return T(0); }
		static T (max)() throw() { T m; maxVal(m); return m; }
		static T lowest() throw() { return T(0); }

		static const bool is_signed = false;
		static T epsilon() throw() { return T(0); }
		static T round_error() throw() { return T(0); }

		static T infinity() throw() { return T(0); }
		static T quiet_NaN() throw() { return T(0); }
		static T signaling_NaN() throw() { return T(0); }
		static T denorm_min() throw() { return T(0); }
	};

	template<int N>
	class numeric_limits< sbigint<N> > :
		public num_base<N>
	{
	public:
		typedef sbigint<N> T;
		static T (min)() throw() { T m; minVal(m); return m; }
		static T (max)() throw() { T m; maxVal(m); return m; }
		static T lowest() throw() { T m; minVal(m); return m; }

		static const bool is_signed = true;
		static T epsilon() throw() { return T(0); }
		static T round_error() throw() { return T(0); }

		static T infinity() throw() { return T(0); }
		static T quiet_NaN() throw() { return T(0); }
		static T signaling_NaN() throw() { return T(0); }
		static T denorm_min() throw() { return T(0); }
	};
}
#endif

#define bigint sbigint

#endif

#include <iostream>
using namespace std;

bigint<2016> earnings=0,sale;
int sticks[2002][2];
bool used[5002]={false};

int main()
{
  int n,d,value,s,u;
  char op[5];
  bool ok;

#ifndef ONLINE_JUDGE
  FILE *stream;
  freopen_s(&stream,"testfile","r",stdin);
#endif
  cin >> n;
  memset(sticks,-1,16016);
  for(d=1;d<=n;d++){
    cin >> op >> value;
    if(op[0]=='w' && sticks[value][1]==-1) sticks[value][0]=d;
    else if(op[0]=='s' && sticks[value][0]>-1) sticks[value][1]=d;
  }
  for(s=2000;s>=0;s--){
    if(sticks[s][0]>-1 && sticks[s][1]>-1){
      ok=true;
      for(u=sticks[s][0];u<sticks[s][1];u++){
        if(used[u]){
          ok=false;
          break;
        }
      }
      if(ok){
        for(u=sticks[s][0];u<sticks[s][1];u++) used[u]=true;
        sale=2;
        earnings+=pow(sale,s);
      }
    }
  }
  cout << earnings << '\n';
  return 0;
}