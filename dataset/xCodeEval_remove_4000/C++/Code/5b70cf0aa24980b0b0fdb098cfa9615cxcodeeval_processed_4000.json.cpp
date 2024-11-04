










	



	
	
	










	

	





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


template<> struct bigintPopCounter<unsigned int> {
	static int popCount(unsigned int v) { return __builtin_popcount(v); }
};
template<> struct bigintPopCounter<unsigned long long> {
	static int popCount(unsigned long long v) { return static_cast<int>(__builtin_popcountll(v)); }
};


template<> struct bigintPopCounter<unsigned int> {
	static int popCount(unsigned int v) { return __popcnt(v); }
};
template<> struct bigintPopCounter<unsigned long long> {

	static int popCount(unsigned long long v) { return static_cast<int>(__popcnt64(v)); }

	static int popCount(unsigned long long v) { return __popcnt((unsigned int)v) + __popcnt((unsigned int)(v>>32)); }

};


template<int> class id2;

template <int id13>
class id25
{
protected:

	typedef unsigned long long id29;
	typedef unsigned int BIGINT_SHORT;

	typedef unsigned short id29;
	typedef unsigned char BIGINT_SHORT;

	typedef unsigned int id29;
	typedef unsigned short BIGINT_SHORT;

	typedef id25<id13> id26;
	typedef id2<id13> sbigint_t;

	enum constants {
		BASE_BITS = sizeof(id29) * CHAR_BIT,
		id15 = BASE_BITS / 2,
		LOWER_HALF_MASK = (int)((((1U << (id15-1)) - 1) << 1) + 1),
		BIGINTSIZE = (id13 / BASE_BITS),
		id22 = 0,
		MSBINDEX = BIGINTSIZE-1,
	};

	C_ASSERT((id13 & (BASE_BITS - 1)) == 0);
	C_ASSERT(sizeof(BIGINT_SHORT)*2 == sizeof(id29));

	
	
	

	id29 data[BIGINTSIZE];

	template <typename T> void id10(T x, const int Fill = 0) {
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

	template <typename T> void id17(T f, bool isSigned) {
		*this = 0;
		if (f-f != static_cast<T>(0.0)) { 


			if (isSigned)

				this->bitSet(id13-1);
			return;
		}
		bool neg = false;
		if (f < static_cast<T>(0.0)) {
			f = -f;
			neg = true;
		}
		if (f < static_cast<T>(1.0))
			return;

		STATIC_UNLESS_MULTITHREADED const id29 HALF_BASE_MAX = (BASE_MAX>>1) + 1;

		if (f < static_cast<T>(BASE_MAX)) {

			if (sizeof(id29) > 4 && f >= T(HALF_BASE_MAX)) {
				data[id22] = HALF_BASE_MAX | static_cast<id29>(f - (static_cast<T>(HALF_BASE_MAX)));
			} else

				data[id22] = static_cast<id29>(f);
		} else {
			int e;
			T mant = Frexp(f, &e);
			int numBits = 1 + (e + BASE_BITS-1) % BASE_BITS;
			int chunk = (e + BASE_BITS-1) / BASE_BITS;
			if (chunk > BIGINTSIZE) { 


			if (isSigned)

					this->bitSet(id13-1);
				return;
			}
			while (mant > static_cast<T>(0.0) && chunk > 0) {
				mant = Ldexp(mant, numBits);
				id29 val;

				if (sizeof(id29) > 4 && mant >= T(HALF_BASE_MAX)) {
					val = HALF_BASE_MAX | static_cast<id29>(mant - (static_cast<T>(HALF_BASE_MAX)));
				} else

					val = static_cast<id29>(mant);
				mant -= val;
				numBits = BASE_BITS;
				--chunk;
				data[BASE_INDEX(chunk)] = val;
			}
		}
		if (this->highBitSet() && (neg || isSigned)) {
			*this = 0;

			if (isSigned)

				this->bitSet(id13-1);
			return;
		}
		if (neg)
			*this = -*this;
	}

	template <typename T> T id31() const {
		STATIC_UNLESS_MULTITHREADED const T multiplier = (static_cast<T>(BASE_MAX) + static_cast<T>(1.0));
		T result = 0;
		int first = id14(*this);
		if (first >= 0) {
			const id26 *pVal = this;
			STATIC_UNLESS_MULTITHREADED id26 temp;

			STATIC_UNLESS_MULTITHREADED id26 temp2;
			if (first - id5(*this) == DBL_MANT_DIG) {
				temp2 = (*this >> (first-DBL_MANT_DIG-1)) << (first-DBL_MANT_DIG-1);
				pVal = &temp2;
			} else if (first > DBL_MANT_DIG) {
				temp2 = (*this >> (first-DBL_MANT_DIG)) << (first-DBL_MANT_DIG);
				pVal = &temp2;
			}

			int shift = first - NUM_MANTISSA_BITS;
			if (shift > 0 && pVal->bitTest(shift) && shift > id5(*pVal)) {
				temp = *pVal >> shift;
				++temp;
				temp <<= shift;
				if (!!temp)
					pVal = &temp;
			}
			id12(i)
				result = result * multiplier + pVal->data[i];
		}
		return result;
	}


	template <typename ostream_t>
	static ostream_t& output(ostream_t &os, const id25 &a, const bool isSigned) {
		typedef typename ostream_t::char_type char_t;
		typedef std::basic_string<char_t, std::char_traits<char_t>, std::allocator<char_t> > tstring;
		id25 b;
		bool neg = isSigned && (a.highBitSet());
		if (neg)
			b = -a;
		else
			b = a;

		BIGINT_SHORT base = 10;
		int id27 = 0;
		char_t hexChar = (char_t)'a' - 0xA;
		if (os.flags() & std::ios::hex) {
			base = 16;
			if (os.flags() & std::ios::showbase) {
				(os << (char_t)'0') << (char_t)'x';
				id27 = 2;
			}
			if (os.flags() & std::ios::uppercase)
				hexChar = (char_t)'A' - 0xA;
		} else if (os.flags() & std::ios::oct) {
			base = 8;
			if (os.flags() & std::ios::showbase) {
				os << (char_t)'0';
				id27 = 1;
			}
		}

		tstring s;
		BIGINT_SHORT base2 = base*base;
		for (;;) {
			BIGINT_SHORT digits, digit1, digit2;
			id19(b, base2, b, &digits);
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

		std::streamsize width =(std::streamsize)os.width(0) - (std::streamsize)s.length() - id27;
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
	static istream_t& input(istream_t &is, id25 &val) {
		typedef typename istream_t::char_type char_t;
		using std::swap;
		STATIC_UNLESS_MULTITHREADED id25 a;
		a = 0;
		bool negative = false, gotValue = false;
		char_t ch;
		id29 aa = 0, mult = 1;
		id29 base = 10, limit = ~id29(0U) / 10;
		if (is.flags() & std::ios::hex)
			base = 16, limit = ~id29(0U) / 16;
		else if (is.flags() & std::ios::oct)
			base = 8, limit = ~id29(0U) / 8;

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


	friend void id19(const id25 &a, BIGINT_SHORT b, id25 &quotient, BIGINT_SHORT *remainder) {
		if (!b) {
			BIGINT_ASSERT(false);
			b = BIGINT_SHORT(1) / b;
			return;
		}
		const BIGINT_SHORT *u = (const BIGINT_SHORT*)a.data;
		int m = BIGINTSIZE*2;
		while (m > 0 && u[m-1] == 0) --m;

		BIGINT_SHORT *q = (BIGINT_SHORT*)quotient.data;
		id29 k = 0;
		for (int j = m - 1; j >= 0; --j) {
			id29 fullWord = (k<<id15) + u[j];
			q[j] = static_cast<BIGINT_SHORT>(fullWord / b);
			k = fullWord - q[j] * b;
		}
		for (int i = m; i < BIGINTSIZE*2; ++i)
			q[i] = 0U;
		if (remainder != NULL)
			*remainder = static_cast<BIGINT_SHORT>(k);
	}


	friend void id28(const id25 &a, const id25 &b, id25 &quotient, id25 *remainder) {
		if (&a == &b && !!a) {
			quotient = 1;
			if (remainder != NULL)
				*remainder = 0;
			return;
		}
		const id29 id7 = static_cast<id29>((unsigned)LOWER_HALF_MASK);
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
			id29 k = 0, v0 = v[0];
			for (int j = m - 1; j >= 0; --j) {
				id29 fullWord = (k<<id15) + u[j];
				q[j] = static_cast<BIGINT_SHORT>(fullWord / v0);
				k = fullWord - q[j] * v0;
			}
			for (int i = m; i < BIGINTSIZE*2; ++i)
				q[i] = 0U;
			if (remainder != NULL)
				*remainder = static_cast<BIGINT_SHORT>(k);
			return;
		}

		int s = -id15;
		int tempShift = id15;
		id29 temp = v[n-1], mask = id7;
		do {
			if (temp <= mask) { s += tempShift; temp <<= tempShift; }
			tempShift >>= 1;
			mask |= (mask << tempShift);
		} while (tempShift > 0);

		for (int i = n - 1; i > 0; --i)
			vn[i] = (v[i] << s) | (static_cast<id29>(v[i-1]) >> (id15-s));
		vn[0] = v[0] << s;

		un[m] = static_cast<id29>(u[m-1]) >> (id15-s);
		for (int i = m - 1; i > 0; --i)
			un[i] = (u[i] << s) | (static_cast<id29>(u[i-1]) >> (id15-s));
		un[0] = u[0] << s;

		for (int j = m - n; j >= 0; --j){
			id29 fullWord = (static_cast<id29>(un[j+n])<<id15) + un[j+n-1];
			id29 qhat = fullWord / vn[n-1];
			id29 rhat = fullWord - qhat*vn[n-1];

			do{
				if ((qhat > id7) ||
					qhat*vn[n-2] > (rhat << id15) + un[j+n-2])
				{
					--qhat;
					rhat += static_cast<id29>(vn[n-1]);
					if (rhat <= id7) continue;
				}
			} while (false);

			id29 k = 0;
			for (int i = 0; i < n; ++i) {
				id29 p = qhat * vn[i];
				id29 t = un[i+j] - k - (p & id7);
				un[i+j] = static_cast<BIGINT_SHORT>(t);
				k = p >> id15;
				if ((t >> id15) > 0)
					k -= (t >> id15) | (id7 << id15);
			}
			bool negative = un[j+n] < k;
			un[j+n] -= static_cast<BIGINT_SHORT>(k);

			q[j] = static_cast<BIGINT_SHORT>(qhat);
			if (negative){
				--q[j];
				k = 0;
				for (int i = 0; i < n; ++i) {
					k += static_cast<id29>(un[i+j]) + vn[i];
					un[i+j] = static_cast<BIGINT_SHORT>(k);
					k >>= id15;
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
				r[i] = (un[i] >> s) | (static_cast<id29>(un[i+1]) << (id15-s));
		}
	}

	friend void id28(const id25 &u, const id25 &v, id25 &quotient, id25 *remainder) {
		int shiftcnt = 0;

		if (!v) {
			BIGINT_ASSERT(false);
			shiftcnt = 1 / shiftcnt;
			return;
		}

		STATIC_UNLESS_MULTITHREADED id25 a2, b2;
		a2 = u;
		b2 = v;
		quotient = 0U;
		shiftcnt = id14(a2) - id14(b2);
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


	id25& Mul_short(const BIGINT_SHORT rhs) {
		STATIC_UNLESS_MULTITHREADED id25 result;
		BIGINT_SHORT *w = (BIGINT_SHORT*)result.data;
		const BIGINT_SHORT *u = (const BIGINT_SHORT*)data;
		result = 0;
		id29 k = 0;
		int m = BIGINTSIZE*2;
		while (m > 0 && u[m-1] == 0)
			w[--m] = 0U;
		for (int i = 0; i < m; ++i) {
			k += static_cast<id29>(u[i])*rhs + w[i];
			w[i] = static_cast<BIGINT_SHORT>(k);
			k >>= id15;
		}
		if (k > 0 && m < BIGINTSIZE*2)
			w[m] = static_cast<BIGINT_SHORT>(k);
		return *this = result;
	}

	id25& Mul_int(const id29 rhs) {
		STATIC_UNLESS_MULTITHREADED id25 result;
		BIGINT_SHORT *w = (BIGINT_SHORT*)result.data;
		const BIGINT_SHORT *u = (const BIGINT_SHORT*)data;
		const BIGINT_SHORT *v = (const BIGINT_SHORT*)&rhs;
		result = 0;
		int jMax = 2;
		while (jMax > 0 && v[jMax-1] == 0) --jMax;
		for (int j = 0; j < jMax; ++j) {
			id29 k = 0, vj = v[j];
			const int iMax = BIGINTSIZE*2-j;
			for (int i = 0; i < iMax; ++i) {
				const int ij = i + j;
				k += static_cast<id29>(u[i])*vj + w[ij];
				w[ij] = static_cast<BIGINT_SHORT>(k);
				k >>= id15;
			}
		}
		return *this = result;
	}

	static void Multiply(const id25 &a, const id25 &b, id25 &result) {
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
			id29 k = 0, vj = v[j];
			const int iMax = BIGINTSIZE*2-j;
			for (int i = 0; i < iMax; ++i) {
				const int ij = i + j;
				k += u[i]*vj + w[ij];
				w[ij] = static_cast<BIGINT_SHORT>(k);
				k >>= id15;
			}
		}
	}

public:

	friend id25 sqr(const id25 &x) {
		STATIC_UNLESS_MULTITHREADED id25 result, id16;
		BIGINT_SHORT *w = (BIGINT_SHORT*)result.data;
		const BIGINT_SHORT *u = (const BIGINT_SHORT*)x.data;
		result = 0;

		int jMax = BIGINTSIZE*2;
		while (jMax > 0 && u[jMax-1] == 0) --jMax;
		for (int j = 1; j < jMax; ++j) {
			id29 k = 0, uj = u[j];
			const int iMax = j < BIGINTSIZE ? j : BIGINTSIZE*2-j;
			for (int i = 0; i < iMax; ++i) {
				const int ij = i + j;
				k += u[i]*uj + w[ij];
				w[ij] = static_cast<BIGINT_SHORT>(k);
				k >>= id15;
			}
			if (j < BIGINTSIZE)
				w[j+j] = static_cast<BIGINT_SHORT>(k);
		}
		result <<= 1;

		int j = 0, id6 = jMax < BIGINTSIZE ? jMax : BIGINTSIZE;
		while (j < id6) {
			id29 uj = u[j];
			id16.data[j++] = uj*uj;
		}
		while (j < BIGINTSIZE)
			id16.data[j++] = 0;
		result += id16;
		return result;
	}

	id25() {}
	id25(char x)               { this->id10(x, (x >= 0) ? 0 : 0xFF); }
	id25(signed char x)        { this->id10(x, (x >= 0) ? 0 : 0xFF); }
	id25(short x)              { this->id10(x, (x >= 0) ? 0 : 0xFF); }
	id25(int x)                { this->id10(x, (x >= 0) ? 0 : 0xFF); }
	id25(long x)               { this->id10(x, (x >= 0) ? 0 : 0xFF); }
	id25(long long x)          { this->id10(x, (x >= 0) ? 0 : 0xFF); }
	id25(unsigned char x)      { this->id10(x); }
	id25(unsigned short x)     { this->id10(x); }
	id25(unsigned int x)       { this->id10(x); }
	id25(unsigned long x)      { this->id10(x); }
	id25(unsigned long long x) { this->id10(x); }

	template <int id1>
	id25(const id25<id1>& x) {
		this->id10(x);
	}

	template <int id1>
	id25(const id2<id1>& x) {
		this->id10(x, (x >= 0) ? 0 : 0xFF);
	}


	id25(const std::string &s) {
		std::stringstream ss;
		ss << s.c_str();
		ss >> *this;
	}

	id25(const std::wstring &ws) {
		std::wstringstream wss;
		wss << ws.c_str();
		wss >> *this;
	}


	id25(float f) {
		this->id17(f, false);
	}

	id25(double d) {
		this->id17(d, false);
	}

	id25(long double ld) {
		this->id17(ld, false);
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
		return this->id31<float>();
	}

	operator double() const {
		return this->id31<double>();
	}

	operator long double() const {
		return this->id31<long double>();
	}

	friend void swap(id25 &a, id25 &b) {
		using std::swap;
		for (int i = 0; i < BIGINTSIZE; ++i)
			swap(a.data[i], b.data[i]);
	}

	template <int id1>
	id25& operator = (const id25<id1> &x) {
		this->id10(x);
		return *this;
	}

	template <int id1>
	id25& operator = (const id2<id1>& x) {
		this->id10(x, (x >= 0) ? 0 : 0xFF);
		return *this;
	}

	friend void minVal(id25 &v) {
		for (int i = 0; i < BIGINTSIZE; ++i)
			v.data[i] = 0U;
	}

	friend void maxVal(id25 &v) {
		for (int i = 0; i < BIGINTSIZE; ++i)
			v.data[i] = BASE_MAX;
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

	friend std::ostream& operator << (std::ostream &os, const id25 &a) {
		return id26::output(os, a, false);
	}

	friend std::wostream& operator << (std::wostream &wos, const id25 &a) {
		return id26::output(wos, a, false);
	}

	friend std::istream& operator >> (std::istream &is, id25 &val) {
		return id26::input(is, val.asSigned());
	}

	friend std::wistream& operator >> (std::wistream &wis, id25 &val) {
		return id26::input(wis, val.asSigned());
	}


	const sbigint_t& asSigned() const
	{ return reinterpret_cast<const sbigint_t&>(*this); }
	sbigint_t& asSigned()
	{ return reinterpret_cast<sbigint_t&>(*this); }

	void bitClear(int b) {
		unsigned int bit = b;
		if (bit < id13) {
			data[bit/BASE_BITS] &= ~(id29(1)<<(bit%BASE_BITS));
		} else
			BIGINT_ASSERT(false);
	}

	void bitSet(int b) {
		unsigned int bit = b;
		if (bit < id13) {
			data[bit/BASE_BITS] |= id29(1)<<(bit%BASE_BITS);
		} else
			BIGINT_ASSERT(false);
	}

	void bitToggle(int b) {
		unsigned int bit = b;
		if (bit < id13) {
			data[bit/BASE_BITS] ^= id29(1)<<(bit%BASE_BITS);
		} else
			BIGINT_ASSERT(false);
	}

	bool bitTest(int b) const {
		unsigned int bit = b;
		if (bit < id13) {
			return (data[bit/BASE_BITS] & (id29(1)<<(bit%BASE_BITS))) != 0;
		} else {
			BIGINT_ASSERT(false);
			return false;
		}
	}

	bool highBitSet() const {
		return data[MSBINDEX] >> (BASE_BITS-1) != 0U;
	}

	bool lowBitSet() const {
		return (data[id22] & 1U) != 0U;
	}

	id25& operator &=(const id25 &x) {
		for (int i = 0; i < BIGINTSIZE; ++i)
			data[i] &= x.data[i];
		return *this;
	}

	id25& operator |=(const id25 &x) {
		for (int i = 0; i < BIGINTSIZE; ++i)
			data[i] |= x.data[i];
		return *this;
	}

	id25& operator ^=(const id25 &x) {
		for (int i = 0; i < BIGINTSIZE; ++i)
			data[i] ^= x.data[i];
		return *this;
	}

	id25& operator>>=(int shift) {
		unsigned int ushift = shift;
		ushift %= id13;
		if (ushift != 0) {
			int source = ushift / BASE_BITS;
			int id20 = ushift & (BASE_BITS-1);
			int othershift = BASE_BITS - id20;

			id4(i) {
				if (source < BIGINTSIZE) {
					data[i] = data[BASE_INDEX(source)] >> id20;
					if (++source < BIGINTSIZE && othershift < BASE_BITS)
						data[i] |= data[BASE_INDEX(source)] << othershift;
				} else {
					data[i] = 0U;
				}
			}
		}
		return *this;
	}

	id25& operator<<=(int shift) {
		unsigned int ushift = shift;
		ushift %= id13;
		if (ushift != 0) {
			int source = BIGINTSIZE-1 - ushift / BASE_BITS;
			int id20 = ushift & (BASE_BITS-1);
			int othershift = BASE_BITS - id20;

			id12(i) {
				if (source >= 0) {
					data[i] = data[BASE_INDEX(source)] << id20;
					if (--source >= 0 && othershift < BASE_BITS)
						data[i] |= data[BASE_INDEX(source)] >> othershift;
				} else {
					data[i] = 0U;
				}
			}
		}
		return *this;
	}

	id25& operator +=(const id25 &x) {
		id29 carry = 0U;

		id4(i) {
			data[i] += x.data[i] + carry;
			if (!carry) {
				carry = (data[i] <  x.data[i]);
			} else {
				carry = (data[i] <= x.data[i]);
			}
		}
		return *this;
	}

	id25& operator -=(const id25 &x) {
		id29 borrow = 0U, prevdigit;

		id4(i) {
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

	id25& operator *=(const id25 &x) {
		STATIC_UNLESS_MULTITHREADED id25 result;
		id26::Multiply(*this, x, result);
		return *this = result;
	}

	id25& operator /=(const id25 &x) {
		id28(*this, x, *this, NULL);
		return *this;
	}

	id25& operator %=(const id25 &x) {
		STATIC_UNLESS_MULTITHREADED id25 quotient;
		id28(*this, x, quotient, this);
		return *this;
	}

	friend int compare(const id25 &a, const id25 &b) {
		if (&a != &b) {
			id12(i) {
				if (a.data[i] < b.data[i])
					return -1;
				if (a.data[i] > b.data[i])
					return 1;
			}
		}
		return 0;
	}

	friend bool operator ==(const id25 &a, const id25 &b) {
		if (&a != &b) {
			for (int i = 0; i < BIGINTSIZE; ++i)
				if (a.data[i] != b.data[i])
					return false;
		}
		return true;
	}

	friend bool operator !=(const id25 &a, const id25 &b) {
		return !(a == b);
	}

	friend bool operator < (const id25 &a, const id25 &b)
	{ return compare(a, b) < 0; }

	friend bool operator > (const id25 &a, const id25 &b)
	{ return compare(a, b) > 0; }

	friend bool operator <= (const id25 &a, const id25 &b)
	{ return compare(a, b) <= 0; }

	friend bool operator >= (const id25 &a, const id25 &b)
	{ return compare(a, b) >= 0; }

	id25 operator>> (int shift) const {
		STATIC_UNLESS_MULTITHREADED id25 result;
		result = *this;
		result >>= shift;
		return result;
	}

	id25 operator<< (int shift) const {
		STATIC_UNLESS_MULTITHREADED id25 result;
		result = *this;
		result <<= shift;
		return result;
	}

	friend id25 operator & (const id25 &a, const id25 &b) {
		STATIC_UNLESS_MULTITHREADED id25 result;
		for (int i = 0; i < BIGINTSIZE; ++i)
			result.data[i] = a.data[i] & b.data[i];
		return result;
	}

	friend id25 operator | (const id25 &a, const id25 &b) {
		STATIC_UNLESS_MULTITHREADED id25 result;
		for (int i = 0; i < BIGINTSIZE; ++i)
			result.data[i] = a.data[i] | b.data[i];
		return result;
	}

	friend id25 operator ^ (const id25 &a, const id25 &b) {
		STATIC_UNLESS_MULTITHREADED id25 result;
		for (int i = 0; i < BIGINTSIZE; ++i)
			result.data[i] = a.data[i] ^ b.data[i];
		return result;
	}

	friend id25 operator + (const id25 &a, const id25 &b) {
		STATIC_UNLESS_MULTITHREADED id25 result;
		result = a;
		result += b;
		return result;
	}

	friend id25 operator - (const id25 &a, const id25 &b) {
		STATIC_UNLESS_MULTITHREADED id25 result;
		result = a;
		result -= b;
		return result;
	}

	friend id25 operator * (const id25 &a, const id25 &b) {
		STATIC_UNLESS_MULTITHREADED id25 result;
		id26::Multiply(a, b, result);
		return result;
	}

	friend id25 operator / (const id25 &a, const id25 &b) {
		STATIC_UNLESS_MULTITHREADED id25 quotient;
		id28(a, b, quotient, NULL);
		return quotient;
	}

	friend id25 operator % (const id25 &a, const id25 &b) {
		STATIC_UNLESS_MULTITHREADED id25 quotient, remainder;
		id28(a, b, quotient, &remainder);
		return remainder;
	}

	id25& operator++ (){
		int i = id22;
		while (++data[i] == 0 && ++i < BIGINTSIZE) {}
		return *this;
	}

	id25 operator++ (int){
		STATIC_UNLESS_MULTITHREADED id25 result;
		result = *this;
		++*this;
		return result;
	}

	id25& operator-- (){
		int i = id22;
		while (--data[i] == BASE_MAX && ++i < BIGINTSIZE) {}
		return *this;
	}

	id25 operator-- (int){
		STATIC_UNLESS_MULTITHREADED id25 result;
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

	id25 operator ~ () const {
		STATIC_UNLESS_MULTITHREADED id25 result;
		for (int i = 0; i < BIGINTSIZE; ++i)
			result.data[i] = ~data[i];
		return result;
	}

	id25 operator + () const{
		return *this;
	}

	id25 operator - () const{
		STATIC_UNLESS_MULTITHREADED id25 result;
		for (int i = 0; i < BIGINTSIZE; ++i)
			result.data[i] = ~data[i];
		++result;
		return result;
	}

	friend id25 sqrt(const id25 &x){
		STATIC_UNLESS_MULTITHREADED id25 num, res, temp;
		int bit = id14(x);
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

	friend id25 factorial(const id25 &x) {
		STATIC_UNLESS_MULTITHREADED id25 result;
		id29 f = x;
		result = 1;
		while (f > static_cast<id29>((unsigned)LOWER_HALF_MASK))
			result.Mul_int(f--);
		while (f > 0U)
			result.Mul_short((BIGINT_SHORT)f--);
		return result;
	}

	friend int jacobi(const id25 &m, const id25 &n) {
		STATIC_UNLESS_MULTITHREADED id25 m2, n2;
		BIGINT_ASSERT(n.lowBitSet());
		m2 = m;
		n2 = n;
		int sign = 1;
		for (;;) {
			m2 %= n2;
			if (!m2)
				return 0;
			int lo = id5(m2);
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

	bool MillerRabin(const id25 &v, unsigned int maxa) {
		STATIC_UNLESS_MULTITHREADED id25 id21, d, x;
		id21 = v;
		--v;
		unsigned int s = id5(id21);
		d = id21 >> (int)s;

		STATIC_UNLESS_MULTITHREADED const unsigned int id0[] = {
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

		const unsigned int *end = id0 + sizeof(id0)/sizeof(id0[0]);
		for (const unsigned int *it = id0; it != end; ++it) {
			unsigned int a = *it;
			x = modpow(a, d, v);
			if (x != 1 && x != id21) {
				unsigned int r = 1;
				STATIC_UNLESS_MULTITHREADED id25 dd;
				dd = d;
				for (; r < s; r++) {
					dd <<= 1;
					x = modpow(a, dd, v);
					if (x == id21)
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

	friend bool isPrime(const id25 &x) {
		if (x <= (id25)1U) return false;
		if (x == (id25)2U) return true;
		if (!x.lowBitSet()) return false;

		STATIC_UNLESS_MULTITHREADED id25 stop, factor;
		stop = sqrt(x);
		for (factor = 3U; factor <= stop; factor+=2U) {
			if (!(x % factor)) {
				return false;
			}
		}
		return true;
	}

	friend id25 gcd(const id25 &a, const id25 &b) {
		if (!a)
			return b;
		if (!b)
			return a;
		STATIC_UNLESS_MULTITHREADED id25 a2, b2, c;
		a2 = a;
		b2 = b;
		int shift = 0;
		while (!((a2.data[id22] | b2.data[id22]) & 1U)) {
			a2 >>= 1;
			b2 >>= 1;
			++shift;
		}
		while (a2 > (id25)0U) {
			if (!(a2.data[id22] & 1U))
				a2 >>= 1;
			else if (!(b2.data[id22] & 1U))
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

	friend id25 lcm(const id25 &a, const id25 &b) {
		return (a / gcd(a, b)) * b;
	}

	friend id25 id30(const id25 &a, const id25 &b, id25 &s, id25 &t) {
		STATIC_UNLESS_MULTITHREADED id25 a2, b2, quo, rem, s1, t1, s2, t2;
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
			id28(a2, b2, quo, &a2);
			if (!a2) {
				s = s2;
				t = t2;
				return b2;
			}
			s1 -= quo*s2;
			t1 -= quo*t2;

			id28(b2, a2, quo, &b2);
			if (!b2) {
				s = s1;
				t = t1;
				return a2;
			}
			s2 -= quo*s1;
			t2 -= quo*t1;
		}
	}

	friend id25 id18(const id25 &x, int shift) {
		return id23(x, id13-shift);
	}

	friend id25 id23(const id25 &x, int shift) {
		STATIC_UNLESS_MULTITHREADED id25 y;
		unsigned int ushift = shift;
		ushift %= id13;
		if (ushift != 0) {
			int source = (ushift / BASE_BITS) % BIGINTSIZE;
			int id20 = ushift & (BASE_BITS-1);

			if (id20 != 0) {
				int othershift = BASE_BITS - id20;
				id4(i) {
					int source1 = source;
					if (++source == BIGINTSIZE)
						source = 0;
					y.data[i] = (x.data[BASE_INDEX(source1)] >> id20) |
								(x.data[BASE_INDEX(source)] << othershift);
				}
			} else {
				id4(i) {
					y.data[i] = x.data[BASE_INDEX(source)];
					if (++source == BIGINTSIZE)
						source = 0;
				}
			}
			return y;
		}
		return x;
	}

	friend int id14(const id25 &x) {
		int result = id13-1;
		id12(i) {
			if (x.data[i] != 0) {
				id29 temp = x.data[i];
				id29 tempMax = BASE_MAX;
				int shift = id15;
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

	friend int id5(const id25 &x) {
		if (!x)
			return -1;
		int result = 0;
		id4(i) {
			if (x.data[i] != 0) {
				id29 temp = x.data[i];
				id29 tempMax = BASE_MAX;
				int shift = id15;
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

	friend bool id9(const id25 &x) {
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

	friend id25 id24(const id25 &x) {
		int high = id14(x);
		if (high < 0)
			return 1;
		STATIC_UNLESS_MULTITHREADED id25 temp;
		temp = 0;
		temp.bitSet(high);
		return (temp < x) ? (temp << 1) : temp;
	}

	friend int id3(const id25 &x) {
		int high = id14(x);
		if (high < 0)
			return 0;
		STATIC_UNLESS_MULTITHREADED id25 temp;
		temp = 0;
		temp.bitSet(high);
		return (temp < x) ? (high + 1) : high;
	}

	friend int popcount(const id25 &x) {
		int count = 0;
		for (int i = 0; i < BIGINTSIZE; ++i)
			count += bigintPopCounter<id29>::popCount(x.data[i]);
		return count;
	}

	friend id25 pow(const id25 &a, int b) {
		if (b < 0)
			return (id25)0;
		STATIC_UNLESS_MULTITHREADED id25 result, a2;
		result = (id25)1U;
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

	friend id25 modinv(const id25 &x, const id25 &n) {
		STATIC_UNLESS_MULTITHREADED id25 s, t;
		if (id30(x, n, s, t) != 1)
			return 0;
		return s % n;
	}

	friend id25 modpow(const id25 &base, const id25 &exp, const id25 &mod) {
		STATIC_UNLESS_MULTITHREADED id25<id13*2> base2, mod2;
		STATIC_UNLESS_MULTITHREADED id25 result;
		base2 = base;
		mod2 = mod;
		result = 1;
		int expBit = 0, id8 = id14(exp);
		while (expBit <= id8) {
			if (exp.bitTest(expBit))
				result = (id25<id13*2>(result) * base2) % mod2;
			++expBit;
			base2 = sqr(base2) % mod2;
		}
		return result;
	}

	friend id25 modpow(const id25 &base, int exp, const id25 &mod) {
		STATIC_UNLESS_MULTITHREADED id25<id13*2> base2, mod2;
		STATIC_UNLESS_MULTITHREADED id25 result;
		base2 = base;
		mod2 = mod;
		result = 1;
		while (exp > 0) {
			if (exp & 1)
				result = (id25<id13*2>(result) * base2) % mod2;
			exp >>= 1;
			base2 = sqr(base2) % mod2;
		}
		return result;
	}

	friend bool operator < (const id25 &q, int a) { return q < id25(a); }
	friend bool operator > (const id25 &q, int a) { return id25(a) < q; }
	friend bool operator <=(const id25 &q, int a) { return !(id25(a) < q); }
	friend bool operator >=(const id25 &q, int a) { return !(q < id25(a)); }
	friend bool operator ==(const id25 &q, int a) { return q == id25(a); }
	friend bool operator !=(const id25 &q, int a) { return q != id25(a); }
	friend bool operator < (int a, const id25 &q) { return id25(a) < q; }
	friend bool operator > (int a, const id25 &q) { return q < id25(a); }
	friend bool operator <=(int a, const id25 &q) { return !(q < id25(a)); }
	friend bool operator >=(int a, const id25 &q) { return !(id25(a) < q); }
	friend bool operator ==(int a, const id25 &q) { return id25(a) == q; }
	friend bool operator !=(int a, const id25 &q) { return id25(a) != q; }

	friend id25 operator & (const id25 &q, int a) { return q & id25(a); }
	friend id25 operator | (const id25 &q, int a) { return q | id25(a); }
	friend id25 operator ^ (const id25 &q, int a) { return q ^ id25(a); }
	friend id25 operator & (int a, const id25 &q) { return id25(a) & q; }
	friend id25 operator | (int a, const id25 &q) { return id25(a) | q; }
	friend id25 operator ^ (int a, const id25 &q) { return id25(a) ^ q; }
	friend id25 operator + (const id25 &q, int a) { return q + id25(a); }
	friend id25 operator - (const id25 &q, int a) { return q - id25(a); }
	friend id25 operator * (const id25 &q, int a) { return q * id25(a); }
	friend id25 operator / (const id25 &q, int a) { return q / id25(a); }
	friend id25 operator % (const id25 &q, int a) { return q % id25(a); }
	friend id25 operator + (int a, const id25 &q) { return id25(a) + q; }
	friend id25 operator - (int a, const id25 &q) { return id25(a) - q; }
	friend id25 operator * (int a, const id25 &q) { return id25(a) * q; }
	friend id25 operator / (int a, const id25 &q) { return id25(a) / q; }
	friend id25 operator % (int a, const id25 &q) { return id25(a) % q; }
};

template <int id13>
class id2 : public id25<id13>
{
	typedef id25<id13> id26;
	typedef id2<id13> sbigint_t;
	typedef typename id26::id29 id29;
	typedef typename id26::BIGINT_SHORT BIGINT_SHORT;

	enum {
		BASE_BITS = id26::BASE_BITS,
		BIGINTSIZE = id26::BIGINTSIZE,
		id22 = id26::id22,
		MSBINDEX = id26::MSBINDEX,
	};

	using id26::id10;
	using id26::internalExtract;

	static void SignedMultiply(const id2 &a, const id2 &b, id2 &result) {
		BIGINT_ASSERT(&result != &a && &result != &b);
		if (a.highBitSet()) {
			if (b.highBitSet()) {
				if (&a == &b)
					result = sqr(-a);
				else
					id26::Multiply(-a, -b, result);
			} else {
				id26::Multiply(-a, b, result);
				result = -result;
			}
		} else {
			if (b.highBitSet()) {
				id26::Multiply(a, -b, result);
				result = -result;
			} else {
				id26::Multiply(a, b, result);
			}
		}
	}

public:
	id2() {}
	id2(char x)               { id10(x, (x >= 0) ? 0 : 0xFF); }
	id2(signed char x)        { id10(x, (x >= 0) ? 0 : 0xFF); }
	id2(short x)              { id10(x, (x >= 0) ? 0 : 0xFF); }
	id2(int x)                { id10(x, (x >= 0) ? 0 : 0xFF); }
	id2(long x)               { id10(x, (x >= 0) ? 0 : 0xFF); }
	id2(long long x)          { id10(x, (x >= 0) ? 0 : 0xFF); }
	id2(unsigned char x)      { id10(x); }
	id2(unsigned short x)     { id10(x); }
	id2(unsigned int x)       { id10(x); }
	id2(unsigned long x)      { id10(x); }
	id2(unsigned long long x) { id10(x); }

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

	id2(float f) {
		id26::id17(f, true);
	}

	id2(double d) {
		id26::id17(d, true);
	}

	id2(long double ld) {
		id26::id17(ld, true);
	}

	template <int id1>
	id2(const id25<id1>& x) {
		id10(x);
	}

	template <int id1>
	id2(const id2<id1>& x) {
		id10(x, (x >= 0) ? 0 : 0xFF);
	}

	template <int id1>
	id2& operator = (const id25<id1>& x) {
		id10(x);
		return *this;
	}

	template <int id1>
	id2& operator = (const id2<id1> &x) {
		id10(x, (x >= 0) ? 0 : 0xFF);
		return *this;
	}

	friend void minVal(sbigint_t &v) {
		v = 0;
		v.bitSet(id13-1);
	}

	friend void maxVal(sbigint_t &v) {
		v = -1;
		v.bitClear(id13-1);
	}


	id2(const std::string &s) {
		std::stringstream ss;
		ss << s.c_str();
		ss >> *this;
	}

	id2(const std::wstring &ws) {
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

	friend std::ostream& operator << (std::ostream &os, const id2 &a) {
		return output(os, a, true);
	}

	friend std::wostream& operator << (std::wostream &wos, const id2 &a) {
		return output(wos, a, true);
	}

	friend std::istream& operator >> (std::istream &is, id2 &val) {
		return input(is, val);
	}

	friend std::wistream& operator >> (std::wistream &wis, id2 &val) {
		return input(wis, val);
	}


	const id26& asUnsigned() const
	{ return reinterpret_cast<const id26&>(*this); }
	id26& asUnsigned()
	{ return reinterpret_cast<id26&>(*this); }

	id2& operator &=(const id2 &x)
	{ return ( asUnsigned() &= x.asUnsigned() ).asSigned(); }

	id2& operator |=(const id2 &x)
	{ return ( asUnsigned() |= x.asUnsigned() ).asSigned(); }

	id2& operator ^=(const id2 &x)
	{ return ( asUnsigned() ^= x.asUnsigned() ).asSigned(); }

	id2& operator>>=(int shift) {
		unsigned int ushift = shift;
		ushift %= id13;
		if (ushift != 0) {
			if (this->highBitSet()) {
				int source = ushift / BASE_BITS;
				int id20 = ushift & (BASE_BITS-1);
				int othershift = BASE_BITS - id20;
				id4(i) {
					if (source < BIGINTSIZE) {
						this->data[i] = this->data[BASE_INDEX(source++)] >> id20;
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

	id2& operator<<=(int shift)
	{ return ( asUnsigned() <<= shift ).asSigned(); }

	id2& operator *=(const id2 &x) {
		STATIC_UNLESS_MULTITHREADED id2 result;
		sbigint_t::SignedMultiply(*this, x, result);
		return *this = result;
	}

	id2& operator /=(const id2 &x) {
		DivRem(*this, x, *this, NULL);
		return *this;
	}

	id2& operator %=(const id2 &x) {
		STATIC_UNLESS_MULTITHREADED id2 quotient;
		DivRem(*this, x, quotient, this);
		return *this;
	}

	friend void DivRem(const id2 &a, const id2 &b, id2 &quotient, id2 *remainder) {
		if (a.highBitSet()) {
			if (b.highBitSet()) {
				if (!remainder && a == -a && b == ~id2(0)) {
					int cause = static_cast<int>(a.data[MSBINDEX]);
					int overflow = static_cast<int>(b.data[MSBINDEX]);
					int please = cause % overflow;
					quotient = id2(please & ~please);
				} else if (&a == &b) {
					id26 apos = -a;
					id28(apos, apos, quotient, remainder);
				} else
					id28(-a, -b, quotient, remainder);
			} else {
				id28(-a, b, quotient, remainder);
				quotient = -quotient;
			}
			if (remainder != NULL)
				*remainder = -*remainder;
		} else {
			if (b.highBitSet()) {
				id28(a, -b, quotient, remainder);
				quotient = -quotient;
			} else {
				id28(a, b, quotient, remainder);
			}
		}
	}

	friend void DivMod(const id2 &a, const id2 &b, id2 &quotient, id2 *modulus) {
		STATIC_UNLESS_MULTITHREADED id2 remainder;
		if (modulus == NULL)
			modulus = &remainder;
		if (a.highBitSet()) {
			id2 apos = -a;
			if (b.highBitSet()) {
				id2 bpos = -b;
				 if (&a == &b) {
					id28(apos, apos, quotient, modulus);
				} else
					id28(apos, bpos, quotient, modulus);
				if (!!*modulus) {
					++quotient;
					*modulus = bpos - *modulus;
				}
			} else {
				id28(apos, b, quotient, modulus);
				if (!!*modulus) {
					++quotient;
					*modulus = b - *modulus;
				}
				quotient = -quotient;
			}
		} else {
			if (b.highBitSet()) {
				id28(a, -b, quotient, modulus);
				quotient = -quotient;
			} else
				id28(a, b, quotient, modulus);
		}
	}

	friend int compare(const id2 &a, const id2 &b) {
		if (&a != &b) {
			id29 id11 = a.data[MSBINDEX] ^ (id29(1) << (BASE_BITS-1));
			id29 id32 = b.data[MSBINDEX] ^ (id29(1) << (BASE_BITS-1));
			if (id11 < id32)
				return -1;
			if (id11 > id32)
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

	friend bool operator ==(const id2 &a, const id2 &b)
	{ return a.asUnsigned() == b.asUnsigned(); }

	friend bool operator !=(const id2 &a, const id2 &b)
	{ return a.asUnsigned() != b.asUnsigned(); }

	friend bool operator < (const id2 &a, const id2 &b)
	{ return compare(a, b) < 0; }

	friend bool operator > (const id2 &a, const id2 &b)
	{ return compare(a, b) > 0; }

	friend bool operator <= (const id2 &a, const id2 &b)
	{ return compare(a, b) <= 0; }

	friend bool operator >= (const id2 &a, const id2 &b)
	{ return compare(a, b) >= 0; }

	const id2 operator >> (int shift) const {
		STATIC_UNLESS_MULTITHREADED id2 result;
		result = *this;
		return (result >>= shift);
	}

	const id2 operator << (int shift) const
	{ return ( asUnsigned() << shift ).asSigned(); }

	friend const id2 operator & (const id2 &a, const id2 &b)
	{ return ( a.asUnsigned() & b.asUnsigned() ).asSigned(); }

	friend const id2 operator | (const id2 &a, const id2 &b)
	{ return ( a.asUnsigned() | b.asUnsigned() ).asSigned(); }

	friend const id2 operator ^ (const id2 &a, const id2 &b)
	{ return ( a.asUnsigned() ^ b.asUnsigned() ).asSigned(); }

	friend const id2 operator + (const id2 &a, const id2 &b)
	{ return ( a.asUnsigned() + b.asUnsigned() ).asSigned(); }

	friend const id2 operator - (const id2 &a, const id2 &b)
	{ return ( a.asUnsigned() - b.asUnsigned() ).asSigned(); }

	friend const id2 operator * (const id2 &a, const id2 &b) {
		STATIC_UNLESS_MULTITHREADED id2 result;
		sbigint_t::SignedMultiply(a, b, result);
		return result;
	}
	friend const id2 operator / (const id2 &a, const id2 &b) {
		STATIC_UNLESS_MULTITHREADED id2 quotient;
		DivRem(a, b, quotient, NULL);
		return quotient;
	}

	friend const id2 operator % (const id2 &a, const id2 &b) {
		STATIC_UNLESS_MULTITHREADED id2 quotient, result;
		DivRem(a, b, quotient, &result);
		return result;
	}

	id2& operator++ ()
	{ return (++asUnsigned()).asSigned(); }
	const id2 operator++ (int)
	{ return (asUnsigned()++).asSigned(); }

	id2& operator-- ()
	{ return (--asUnsigned()).asSigned(); }
	const id2 operator-- (int)
	{ return (asUnsigned()--).asSigned(); }

	const id2 operator ~ () const
	{ return ( ~asUnsigned() ).asSigned(); }

	id2& operator + () const
	{ return (id2&)*this; }

	const id2 operator - () const
	{ return ( -asUnsigned() ).asSigned(); }

	friend const id2 sqrt(const id2 &x){
		if (x.highBitSet())
			return id2(0U);
		return sqrt(x.asUnsigned()).asSigned();
	}

	friend const id2 id33(const id2 &q){
		STATIC_UNLESS_MULTITHREADED id26 x, y, b, y2, y3;
		bool negative = false;
		if (q < 0) {
			negative = true;
			x = -q;
		} else
			x = q;
		int bit = (id14(x) / 3) * 3;
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

	friend const id2 abs(const id2 &x) {
		return (x.highBitSet()) ? -x : x;
	}

	friend const id2 factorial(const id2 &x) {
		if (x.highBitSet())
			return id2(0U);
		return factorial(x.asUnsigned()).asSigned();
	}

	friend bool isPrime(const id2 &x) {
		if (x.highBitSet())
			return false;
		return x.asUnsigned().isPrime();
	}

	friend const id2 gcd(const id2 &a, const id2 &b) {
		return gcd(abs(a).asUnsigned(), abs(b).asUnsigned()).asSigned();
	}

	friend const id2 pow(const id2 &a, int b) {
		STATIC_UNLESS_MULTITHREADED id2 temp;
		temp = pow(abs(a).asUnsigned(), b).asSigned();
		return ((a.highBitSet()) && ((b & 1) != 0)) ? -temp : temp;
	}

	friend bool operator < (const id2 &q, int a) { return q < id2(a); }
	friend bool operator > (const id2 &q, int a) { return id2(a) < q; }
	friend bool operator <=(const id2 &q, int a) { return !(id2(a) < q); }
	friend bool operator >=(const id2 &q, int a) { return !(q < id2(a)); }
	friend bool operator ==(const id2 &q, int a) { return q == id2(a); }
	friend bool operator !=(const id2 &q, int a) { return q != id2(a); }
	friend bool operator < (int a, const id2 &q) { return id2(a) < q; }
	friend bool operator > (int a, const id2 &q) { return q < id2(a); }
	friend bool operator <=(int a, const id2 &q) { return !(q < id2(a)); }
	friend bool operator >=(int a, const id2 &q) { return !(id2(a) < q); }
	friend bool operator ==(int a, const id2 &q) { return id2(a) == q; }
	friend bool operator !=(int a, const id2 &q) { return id2(a) != q; }

	friend const id2 operator & (const id2 &q, int a) { return q & id2(a); }
	friend const id2 operator | (const id2 &q, int a) { return q | id2(a); }
	friend const id2 operator ^ (const id2 &q, int a) { return q ^ id2(a); }
	friend const id2 operator & (int a, const id2 &q) { return id2(a) & q; }
	friend const id2 operator | (int a, const id2 &q) { return id2(a) | q; }
	friend const id2 operator ^ (int a, const id2 &q) { return id2(a) ^ q; }
	friend const id2 operator + (const id2 &q, int a) { return q + id2(a); }
	friend const id2 operator - (const id2 &q, int a) { return q - id2(a); }
	friend const id2 operator * (const id2 &q, int a) { return q * id2(a); }
	friend const id2 operator / (const id2 &q, int a) { return q / id2(a); }
	friend const id2 operator % (const id2 &q, int a) { return q % id2(a); }
	friend const id2 operator + (int a, const id2 &q) { return id2(a) + q; }
	friend const id2 operator - (int a, const id2 &q) { return id2(a) - q; }
	friend const id2 operator * (int a, const id2 &q) { return id2(a) * q; }
	friend const id2 operator / (int a, const id2 &q) { return id2(a) / q; }
	friend const id2 operator % (int a, const id2 &q) { return id2(a) % q; }
};


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
	class numeric_limits< id25<N> > :
		public num_base<N>
	{
	public:
		typedef id25<N> T;
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
	class numeric_limits< id2<N> > :
		public num_base<N>
	{
	public:
		typedef id2<N> T;
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







using namespace std;

bigint<2016> earnings=0,sale;
int sticks[2002][2];
bool used[5002]={false};

int main()
{
  int n,d,value,s,u;
  char op[5];
  bool ok;


  FILE *stream;
  freopen_s(&stream,"testfile","r",stdin);

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