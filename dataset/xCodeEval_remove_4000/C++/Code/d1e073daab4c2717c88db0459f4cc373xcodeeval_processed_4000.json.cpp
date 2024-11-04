




using namespace std;




template <class Blk>
class id21 {
public:
	typedef unsigned int Index;
	static const unsigned int N;
	Index cap;
	Index len;
	Blk *blk;
	id21(Index c) : cap(c), len(0) {
		blk = (cap > 0) ? (new Blk[cap]) : NULL;
	}
	
	id21() : cap(0), len(0) {
		blk = NULL;
	}
	~id21() {
		delete[] blk;
	}
	
	void allocate(Index c);
	
	void allocateAndCopy(Index c);
	id21(const id21<Blk> &x);
	void operator=(const id21<Blk> &x);
	id21(const Blk *b, Index blen);
	Index getCapacity()     const { return cap; }
	Index getLength()       const { return len; }
	Blk   getBlock(Index i) const { return blk[i]; }
	bool  isEmpty()         const { return len == 0; }
	
	bool operator ==(const id21<Blk> &x) const;
	bool operator !=(const id21<Blk> &x) const {
		return !operator ==(x);
	}
};

template <class Blk>
const unsigned int id21<Blk>::N = 8 * sizeof(Blk);
template <class Blk>
void id21<Blk>::allocate(Index c) {
	if (c > cap) {
		delete[] blk;
		cap = c;
		blk = new Blk[cap];
	}
}
template <class Blk>
void id21<Blk>::allocateAndCopy(Index c) {
	if (c > cap) {
		Blk *oldBlk = blk;
		cap = c;
		blk = new Blk[cap];
		Index i;
		for (i = 0; i < len; i++)
			blk[i] = oldBlk[i];
		delete[] oldBlk;
	}
}
template <class Blk>
id21<Blk>::id21(const id21<Blk> &x)
	: len(x.len) {
	cap = len;
	blk = new Blk[cap];
	Index i;
	for (i = 0; i < len; i++)
		blk[i] = x.blk[i];
}
template <class Blk>
void id21<Blk>::operator=(const id21<Blk> &x) {
	
	if (this == &x)
		return;
	len = x.len;
	allocate(len);
	Index i;
	for (i = 0; i < len; i++)
		blk[i] = x.blk[i];
}
template <class Blk>
id21<Blk>::id21(const Blk *b, Index blen)
	: cap(blen), len(blen) {
	blk = new Blk[cap];
	Index i;
	for (i = 0; i < len; i++)
		blk[i] = b[i];
}
template <class Blk>
bool id21<Blk>::operator ==(const id21<Blk> &x) const {
	if (len != x.len)
		return false;
	else {
		Index i;
		for (i = 0; i < len; i++)
			if (blk[i] != x.blk[i])
				return false;
		return true;
	}
}

class BigUnsigned : protected id21<unsigned long> {
public:
	enum CmpRes { less = -1, equal = 0, greater = 1 };
	typedef unsigned long Blk;
	typedef id21<Blk>::Index Index;
	id21<Blk>::N;
protected:
	BigUnsigned(int, Index c) : id21<Blk>(0, c) {}
	void zapLeadingZeros() {
		while (len > 0 && blk[len - 1] == 0)
			len--;
	}
public:
	BigUnsigned() : id21<Blk>() {}
	BigUnsigned(const BigUnsigned &x) : id21<Blk>(x) {}
	void operator=(const BigUnsigned &x) {
		id21<Blk>::operator =(x);
	}
	BigUnsigned(const Blk *b, Index blen) : id21<Blk>(b, blen) {
		zapLeadingZeros();
	}
	~BigUnsigned() {}
	BigUnsigned(unsigned long  x);
	BigUnsigned(long  x);
	BigUnsigned(unsigned int   x);
	BigUnsigned(int   x);
	BigUnsigned(unsigned short x);
	BigUnsigned(short x);
protected:
	template <class X> void id19(X x);
	template <class X> void id0(X x);
public:
	
	unsigned long  toUnsignedLong() const;
	long           toLong() const;
	unsigned int   toUnsignedInt() const;
	int            toInt() const;
	unsigned short toUnsignedShort() const;
	short          toShort() const;
protected:
	template <class X> X id8() const;
	template <class X> X id12() const;
public:
	id21<Blk>::getCapacity;
	id21<Blk>::getLength;
	
	Blk getBlock(Index i) const { return i >= len ? 0 : blk[i]; }
	
	void setBlock(Index i, Blk newBlock);
	bool isZero() const { return id21<Blk>::isEmpty(); }
	
	Index bitLength() const;
	
	bool getBit(Index bi) const {
		return (getBlock(bi / N) & (Blk(1) << (bi % N))) != 0;
	}
	
	void setBit(Index bi, bool newBit);
	CmpRes compareTo(const BigUnsigned &x) const;
	bool operator ==(const BigUnsigned &x) const {
		return id21<Blk>::operator ==(x);
	}
	bool operator !=(const BigUnsigned &x) const {
		return id21<Blk>::operator !=(x);
	}
	bool operator < (const BigUnsigned &x) const { return compareTo(x) == less; }
	bool operator <=(const BigUnsigned &x) const { return compareTo(x) != greater; }
	bool operator >=(const BigUnsigned &x) const { return compareTo(x) != less; }
	bool operator > (const BigUnsigned &x) const { return compareTo(x) == greater; }
	
	void add(const BigUnsigned &a, const BigUnsigned &b);
	void subtract(const BigUnsigned &a, const BigUnsigned &b);
	void multiply(const BigUnsigned &a, const BigUnsigned &b);
	void bitAnd(const BigUnsigned &a, const BigUnsigned &b);
	void bitOr(const BigUnsigned &a, const BigUnsigned &b);
	void bitXor(const BigUnsigned &a, const BigUnsigned &b);
	
	void bitShiftLeft(const BigUnsigned &a, int b);
	void bitShiftRight(const BigUnsigned &a, int b);
	
	void divideWithRemainder(const BigUnsigned &b, BigUnsigned &q);
	
	BigUnsigned operator +(const BigUnsigned &x) const;
	BigUnsigned operator -(const BigUnsigned &x) const;
	BigUnsigned operator *(const BigUnsigned &x) const;
	BigUnsigned operator /(const BigUnsigned &x) const;
	BigUnsigned operator %(const BigUnsigned &x) const;
	
	BigUnsigned operator &(const BigUnsigned &x) const;
	BigUnsigned operator |(const BigUnsigned &x) const;
	BigUnsigned operator ^(const BigUnsigned &x) const;
	BigUnsigned operator <<(int b) const;
	BigUnsigned operator >>(int b) const;
	void operator +=(const BigUnsigned &x);
	void operator -=(const BigUnsigned &x);
	void operator *=(const BigUnsigned &x);
	void operator /=(const BigUnsigned &x);
	void operator %=(const BigUnsigned &x);
	void operator &=(const BigUnsigned &x);
	void operator |=(const BigUnsigned &x);
	void operator ^=(const BigUnsigned &x);
	void operator <<=(int b);
	void operator >>=(int b);
	
	void operator ++();
	void operator ++(int);
	void operator --();
	void operator --(int);
	friend Blk id4(const BigUnsigned &num, Index x,
		unsigned int y);
	template <class X>
	friend X id13(const BigUnsigned &a);
};


template <class X>
void BigUnsigned::id19(X x) {
	if (x == 0)
		; 
	else {
		cap = 1;
		blk = new Blk[1];
		len = 1;
		blk[0] = Blk(x);
	}
}

template <class X>
void BigUnsigned::id0(X x) {
	if (x < 0)
		throw "BigUnsigned constructor: "
		"Cannot construct a BigUnsigned from a negative number";
	else
		id19(x);
}

template <class X>
X BigUnsigned::id12() const {
	if (len == 0)
		return 0;
	else if (len == 1) {
		X x = X(blk[0]);
		if (Blk(x) == blk[0])
			return x;
	}
	throw "BigUnsigned::to<Primitive>: "
		"Value is too big to fit in the requested type";
}

template <class X>
X BigUnsigned::id8() const {
	X x = id12<X>();
	if (x >= 0)
		return x;
	else
		throw "BigUnsigned::to(Primitive): "
		"Value is too big to fit in the requested type";
}

class BigInteger {
public:
	typedef BigUnsigned::Blk Blk;
	typedef BigUnsigned::Index Index;
	typedef BigUnsigned::CmpRes CmpRes;
	static const CmpRes
		less = BigUnsigned::less,
		equal = BigUnsigned::equal,
		greater = BigUnsigned::greater;
	enum Sign { negative = -1, zero = 0, positive = 1 };
protected:
	Sign sign;
	BigUnsigned mag;
public:
	BigInteger() : sign(zero), mag() {}
	BigInteger(const BigInteger &x) : sign(x.sign), mag(x.mag) {};
	void operator=(const BigInteger &x);
	BigInteger(const Blk *b, Index blen, Sign s);
	BigInteger(const Blk *b, Index blen) : mag(b, blen) {
		sign = mag.isZero() ? zero : positive;
	}
	BigInteger(const BigUnsigned &x, Sign s);
	BigInteger(const BigUnsigned &x) : mag(x) {
		sign = mag.isZero() ? zero : positive;
	}
	BigInteger(unsigned long  x);
	BigInteger(long  x);
	BigInteger(unsigned int   x);
	BigInteger(int   x);
	BigInteger(unsigned short x);
	BigInteger(short x);
	
	unsigned long  toUnsignedLong() const;
	long           toLong() const;
	unsigned int   toUnsignedInt() const;
	int            toInt() const;
	unsigned short toUnsignedShort() const;
	short          toShort() const;
protected:
	template <class X> X id16() const;
	template <class X, class UX> X id8() const;
public:
	Sign getSign() const { return sign; }
	
	const BigUnsigned &getMagnitude() const { return mag; }
	Index getLength() const { return mag.getLength(); }
	Index getCapacity() const { return mag.getCapacity(); }
	Blk getBlock(Index i) const { return mag.getBlock(i); }
	bool isZero() const { return sign == zero; } 
	CmpRes compareTo(const BigInteger &x) const;
	bool operator ==(const BigInteger &x) const {
		return sign == x.sign && mag == x.mag;
	}
	bool operator !=(const BigInteger &x) const { return !operator ==(x); };
	bool operator < (const BigInteger &x) const { return compareTo(x) == less; }
	bool operator <=(const BigInteger &x) const { return compareTo(x) != greater; }
	bool operator >=(const BigInteger &x) const { return compareTo(x) != less; }
	bool operator > (const BigInteger &x) const { return compareTo(x) == greater; }
	void add(const BigInteger &a, const BigInteger &b);
	void subtract(const BigInteger &a, const BigInteger &b);
	void multiply(const BigInteger &a, const BigInteger &b);
	
	void divideWithRemainder(const BigInteger &b, BigInteger &q);
	void negate(const BigInteger &a);
	
	BigInteger operator +(const BigInteger &x) const;
	BigInteger operator -(const BigInteger &x) const;
	BigInteger operator *(const BigInteger &x) const;
	BigInteger operator /(const BigInteger &x) const;
	BigInteger operator %(const BigInteger &x) const;
	BigInteger operator -() const;
	void operator +=(const BigInteger &x);
	void operator -=(const BigInteger &x);
	void operator *=(const BigInteger &x);
	void operator /=(const BigInteger &x);
	void operator %=(const BigInteger &x);
	void flipSign();
	void operator ++();
	void operator ++(int);
	void operator --();
	void operator --(int);
};

inline BigInteger BigInteger::operator +(const BigInteger &x) const {
	BigInteger ans;
	ans.add(*this, x);
	return ans;
}
inline BigInteger BigInteger::operator -(const BigInteger &x) const {
	BigInteger ans;
	ans.subtract(*this, x);
	return ans;
}
inline BigInteger BigInteger::operator *(const BigInteger &x) const {
	BigInteger ans;
	ans.multiply(*this, x);
	return ans;
}
inline BigInteger BigInteger::operator /(const BigInteger &x) const {
	if (x.isZero()) throw "BigInteger::operator /: division by zero";
	BigInteger q, r;
	r = *this;
	r.divideWithRemainder(x, q);
	return q;
}
inline BigInteger BigInteger::operator %(const BigInteger &x) const {
	if (x.isZero()) throw "BigInteger::operator %: division by zero";
	BigInteger q, r;
	r = *this;
	r.divideWithRemainder(x, q);
	return r;
}
inline BigInteger BigInteger::operator -() const {
	BigInteger ans;
	ans.negate(*this);
	return ans;
}

inline void BigInteger::operator +=(const BigInteger &x) {
	add(*this, x);
}
inline void BigInteger::operator -=(const BigInteger &x) {
	subtract(*this, x);
}
inline void BigInteger::operator *=(const BigInteger &x) {
	multiply(*this, x);
}
inline void BigInteger::operator /=(const BigInteger &x) {
	if (x.isZero()) throw "BigInteger::operator /=: division by zero";
	
	BigInteger q;
	divideWithRemainder(x, q);
	*this = q;
}
inline void BigInteger::operator %=(const BigInteger &x) {
	if (x.isZero()) throw "BigInteger::operator %=: division by zero";
	BigInteger q;
	divideWithRemainder(x, q);
}
inline void BigInteger::flipSign() {
	sign = Sign(-sign);
}

inline BigUnsigned BigUnsigned::operator +(const BigUnsigned &x) const {
	BigUnsigned ans;
	ans.add(*this, x);
	return ans;
}
inline BigUnsigned BigUnsigned::operator -(const BigUnsigned &x) const {
	BigUnsigned ans;
	ans.subtract(*this, x);
	return ans;
}
inline BigUnsigned BigUnsigned::operator *(const BigUnsigned &x) const {
	BigUnsigned ans;
	ans.multiply(*this, x);
	return ans;
}
inline BigUnsigned BigUnsigned::operator /(const BigUnsigned &x) const {
	if (x.isZero()) throw "BigUnsigned::operator /: division by zero";
	BigUnsigned q, r;
	r = *this;
	r.divideWithRemainder(x, q);
	return q;
}
inline BigUnsigned BigUnsigned::operator %(const BigUnsigned &x) const {
	if (x.isZero()) throw "BigUnsigned::operator %: division by zero";
	BigUnsigned q, r;
	r = *this;
	r.divideWithRemainder(x, q);
	return r;
}
inline BigUnsigned BigUnsigned::operator &(const BigUnsigned &x) const {
	BigUnsigned ans;
	ans.bitAnd(*this, x);
	return ans;
}
inline BigUnsigned BigUnsigned::operator |(const BigUnsigned &x) const {
	BigUnsigned ans;
	ans.bitOr(*this, x);
	return ans;
}
inline BigUnsigned BigUnsigned::operator ^(const BigUnsigned &x) const {
	BigUnsigned ans;
	ans.bitXor(*this, x);
	return ans;
}
inline BigUnsigned BigUnsigned::operator <<(int b) const {
	BigUnsigned ans;
	ans.bitShiftLeft(*this, b);
	return ans;
}
inline BigUnsigned BigUnsigned::operator >>(int b) const {
	BigUnsigned ans;
	ans.bitShiftRight(*this, b);
	return ans;
}
inline void BigUnsigned::operator +=(const BigUnsigned &x) {
	add(*this, x);
}
inline void BigUnsigned::operator -=(const BigUnsigned &x) {
	subtract(*this, x);
}
inline void BigUnsigned::operator *=(const BigUnsigned &x) {
	multiply(*this, x);
}
inline void BigUnsigned::operator /=(const BigUnsigned &x) {
	if (x.isZero()) throw "BigUnsigned::operator /=: division by zero";
	
	BigUnsigned q;
	divideWithRemainder(x, q);
	*this = q;
}
inline void BigUnsigned::operator %=(const BigUnsigned &x) {
	if (x.isZero()) throw "BigUnsigned::operator %=: division by zero";
	BigUnsigned q;
	divideWithRemainder(x, q);
}
inline void BigUnsigned::operator &=(const BigUnsigned &x) {
	bitAnd(*this, x);
}
inline void BigUnsigned::operator |=(const BigUnsigned &x) {
	bitOr(*this, x);
}
inline void BigUnsigned::operator ^=(const BigUnsigned &x) {
	bitXor(*this, x);
}
inline void BigUnsigned::operator <<=(int b) {
	bitShiftLeft(*this, b);
}
inline void BigUnsigned::operator >>=(int b) {
	bitShiftRight(*this, b);
}
void BigInteger::operator =(const BigInteger &x) {
	if (this == &x)
		return;
	sign = x.sign;
	mag = x.mag;
}
BigInteger::BigInteger(const Blk *b, Index blen, Sign s) : mag(b, blen) {
	switch (s) {
	case zero:
		if (!mag.isZero())
			throw "BigInteger::BigInteger(const Blk *, Index, Sign): Cannot use a sign of zero with a nonzero magnitude";
		sign = zero;
		break;
	case positive:
	case negative:
		sign = mag.isZero() ? zero : s;
		break;
	default:
		
		throw "BigInteger::BigInteger(const Blk *, Index, Sign): Invalid sign";
	}
}
BigInteger::BigInteger(const BigUnsigned &x, Sign s) : mag(x) {
	switch (s) {
	case zero:
		if (!mag.isZero())
			throw "BigInteger::BigInteger(const BigUnsigned &, Sign): Cannot use a sign of zero with a nonzero magnitude";
		sign = zero;
		break;
	case positive:
	case negative:
		sign = mag.isZero() ? zero : s;
		break;
	default:
		
		throw "BigInteger::BigInteger(const BigUnsigned &, Sign): Invalid sign";
	}
}

BigInteger::BigInteger(unsigned long  x) : mag(x) { sign = mag.isZero() ? zero : positive; }
BigInteger::BigInteger(unsigned int   x) : mag(x) { sign = mag.isZero() ? zero : positive; }
BigInteger::BigInteger(unsigned short x) : mag(x) { sign = mag.isZero() ? zero : positive; }
namespace {
	template <class X, class UX>
	BigInteger::Blk magOf(X x) {
		
		return BigInteger::Blk(x < 0 ? UX(-x) : x);
	}
	template <class X>
	BigInteger::Sign signOf(X x) {
		return (x == 0) ? BigInteger::zero
			: (x > 0) ? BigInteger::positive
			: BigInteger::negative;
	}
}
BigInteger::BigInteger(long  x) : sign(signOf(x)), mag(magOf<long, unsigned long >(x)) {}
BigInteger::BigInteger(int   x) : sign(signOf(x)), mag(magOf<int, unsigned int  >(x)) {}
BigInteger::BigInteger(short x) : sign(signOf(x)), mag(magOf<short, unsigned short>(x)) {}

template <class X>
inline X id13(const BigUnsigned &a) {
	return a.id12<X>();
}
template <class X>
X BigInteger::id16() const {
	if (sign == negative)
		throw "BigInteger::to<Primitive>: "
		"Cannot convert a negative integer to an unsigned type";
	else
		return id13<X>(mag);
}

template <class X, class UX>
X BigInteger::id8() const {
	if (sign == zero)
		return 0;
	else if (mag.getLength() == 1) {
		Blk b = mag.getBlock(0);
		if (sign == positive) {
			X x = X(b);
			if (x >= 0 && Blk(x) == b)
				return x;
		}
		else {
			X x = -X(b);
			
			if (x < 0 && Blk(UX(-x)) == b)
				return x;
		}
	}
	throw "BigInteger::to<Primitive>: "
		"Value is too big to fit in the requested type";
}
unsigned long  BigInteger::toUnsignedLong() const { return id16<unsigned long >(); }
unsigned int   BigInteger::toUnsignedInt() const { return id16<unsigned int  >(); }
unsigned short BigInteger::toUnsignedShort() const { return id16<unsigned short>(); }
long           BigInteger::toLong() const { return id8  <long, unsigned long>(); }
int            BigInteger::toInt() const { return id8  <int, unsigned int>(); }
short          BigInteger::toShort() const { return id8  <short, unsigned short>(); }
BigInteger::CmpRes BigInteger::compareTo(const BigInteger &x) const {
	if (sign < x.sign)
		return less;
	else if (sign > x.sign)
		return greater;
	else switch (sign) {
	case zero:
		return equal; 
	case positive:
		return mag.compareTo(x.mag);
	case negative:
		return CmpRes(-mag.compareTo(x.mag));
	default:
		throw "BigInteger internal error";
	}
}


	if (cond) { \
		BigInteger tmpThis; \
		tmpThis.op; \
		*this = tmpThis; \
		return; \
	}
void BigInteger::add(const BigInteger &a, const BigInteger &b) {
	DTRT_ALIASED(this == &a || this == &b, add(a, b));
	if (a.sign == zero)
		operator =(b);
	else if (b.sign == zero)
		operator =(a);
	else if (a.sign == b.sign) {
		sign = a.sign;
		mag.add(a.mag, b.mag);
	}
	else {
		switch (a.mag.compareTo(b.mag)) {
		case equal:
			mag = 0;
			sign = zero;
			break;
		case greater:
			sign = a.sign;
			mag.subtract(a.mag, b.mag);
			break;
		case less:
			sign = b.sign;
			mag.subtract(b.mag, a.mag);
			break;
		}
	}
}
void BigInteger::subtract(const BigInteger &a, const BigInteger &b) {
	DTRT_ALIASED(this == &a || this == &b, subtract(a, b));
	if (a.sign == zero) {
		mag = b.mag;
		sign = Sign(-b.sign);
	}
	else if (b.sign == zero)
		operator =(a);
	else if (a.sign != b.sign) {
		sign = a.sign;
		mag.add(a.mag, b.mag);
	}
	else {
		switch (a.mag.compareTo(b.mag)) {
		case equal:
			mag = 0;
			sign = zero;
			break;
		case greater:
			sign = a.sign;
			mag.subtract(a.mag, b.mag);
			break;
		case less:
			sign = Sign(-b.sign);
			mag.subtract(b.mag, a.mag);
			break;
		}
	}
}
void BigInteger::multiply(const BigInteger &a, const BigInteger &b) {
	DTRT_ALIASED(this == &a || this == &b, multiply(a, b));
	if (a.sign == zero || b.sign == zero) {
		sign = zero;
		mag = 0;
		return;
	}
	sign = (a.sign == b.sign) ? positive : negative;
	mag.multiply(a.mag, b.mag);
}

void BigInteger::divideWithRemainder(const BigInteger &b, BigInteger &q) {
	if (this == &q)
		throw "BigInteger::divideWithRemainder: Cannot write quotient and remainder into the same variable";
	if (this == &b || &q == &b) {
		BigInteger tmpB(b);
		divideWithRemainder(tmpB, q);
		return;
	}
	if (b.sign == zero) {
		q.mag = 0;
		q.sign = zero;
		return;
	}
	if (sign == zero) {
		q.mag = 0;
		q.sign = zero;
		return;
	}
	if (sign == b.sign) {
		q.sign = positive;
	}
	else {
		q.sign = negative;
		mag--;
		
	}
	mag.divideWithRemainder(b.mag, q.mag);
	if (sign != b.sign) {
		q.mag++;
		mag.subtract(b.mag, mag);
		mag--;
	}
	sign = b.sign;
	if (mag.isZero())
		sign = zero;
	if (q.mag.isZero())
		q.sign = zero;
}
void BigInteger::negate(const BigInteger &a) {
	DTRT_ALIASED(this == &a, negate(a));
	mag = a.mag;
	sign = Sign(-a.sign);
}
void BigInteger::operator ++() {
	if (sign == negative) {
		mag--;
		if (mag == 0)
			sign = zero;
	}
	else {
		mag++;
		sign = positive; 
	}
}
void BigInteger::operator ++(int) {
	operator ++();
}
void BigInteger::operator --() {
	if (sign == positive) {
		mag--;
		if (mag == 0)
			sign = zero;
	}
	else {
		mag++;
		sign = negative;
	}
}
void BigInteger::operator --(int) {
	operator --();
}
BigUnsigned::BigUnsigned(unsigned long  x) { id19(x); }
BigUnsigned::BigUnsigned(unsigned int   x) { id19(x); }
BigUnsigned::BigUnsigned(unsigned short x) { id19(x); }
BigUnsigned::BigUnsigned(long  x) { id0(x); }
BigUnsigned::BigUnsigned(int   x) { id0(x); }
BigUnsigned::BigUnsigned(short x) { id0(x); }
unsigned long  BigUnsigned::toUnsignedLong() const { return id12      <unsigned long >(); }
unsigned int   BigUnsigned::toUnsignedInt() const { return id12      <unsigned int  >(); }
unsigned short BigUnsigned::toUnsignedShort() const { return id12      <unsigned short>(); }
long           BigUnsigned::toLong() const { return id8<         long >(); }
int            BigUnsigned::toInt() const { return id8<         int  >(); }
short          BigUnsigned::toShort() const { return id8<         short>(); }
void BigUnsigned::setBlock(Index i, Blk newBlock) {
	if (newBlock == 0) {
		if (i < len) {
			blk[i] = 0;
			zapLeadingZeros();
		}
	}
	else {
		if (i >= len) {
			allocateAndCopy(i + 1);
			for (Index j = len; j < i; j++)
				blk[j] = 0;
			len = i + 1;
		}
		blk[i] = newBlock;
	}
}

BigUnsigned::Index BigUnsigned::bitLength() const {
	if (isZero())
		return 0;
	else {
		Blk id14 = getBlock(len - 1);
		Index id18 = 0;
		while (id14 != 0) {
			id14 >>= 1;
			id18++;
		}
		return id18 + (len - 1) * N;
	}
}
void BigUnsigned::setBit(Index bi, bool newBit) {
	Index blockI = bi / N;
	Blk block = getBlock(blockI), mask = Blk(1) << (bi % N);
	block = newBit ? (block | mask) : (block & ~mask);
	setBlock(blockI, block);
}
BigUnsigned::CmpRes BigUnsigned::compareTo(const BigUnsigned &x) const {
	if (len < x.len)
		return less;
	else if (len > x.len)
		return greater;
	else {
		Index i = len;
		while (i > 0) {
			i--;
			if (blk[i] == x.blk[i])
				continue;
			else if (blk[i] > x.blk[i])
				return greater;
			else
				return less;
		}
		return equal;
	}
}


	if (cond) { \
		BigUnsigned tmpThis; \
		tmpThis.op; \
		*this = tmpThis; \
		return; \
	}
void BigUnsigned::add(const BigUnsigned &a, const BigUnsigned &b) {
	DTRT_ALIASED(this == &a || this == &b, add(a, b));
	if (a.len == 0) {
		operator =(b);
		return;
	}
	else if (b.len == 0) {
		operator =(a);
		return;
	}
	bool carryIn, carryOut;
	Blk temp;
	Index i;
	const BigUnsigned *a2, *b2;
	if (a.len >= b.len) {
		a2 = &a;
		b2 = &b;
	}
	else {
		a2 = &b;
		b2 = &a;
	}
	len = a2->len + 1;
	allocate(len);
	for (i = 0, carryIn = false; i < b2->len; i++) {
		temp = a2->blk[i] + b2->blk[i];
		carryOut = (temp < a2->blk[i]);
		if (carryIn) {
			temp++;
			carryOut |= (temp == 0);
		}
		blk[i] = temp; 
		carryIn = carryOut; 
	}
	for (; i < a2->len && carryIn; i++) {
		temp = a2->blk[i] + 1;
		carryIn = (temp == 0);
		blk[i] = temp;
	}
	for (; i < a2->len; i++)
		blk[i] = a2->blk[i];
	if (carryIn)
		blk[i] = 1;
	else
		len--;
}
void BigUnsigned::subtract(const BigUnsigned &a, const BigUnsigned &b) {
	DTRT_ALIASED(this == &a || this == &b, subtract(a, b));
	if (b.len == 0) {
		operator =(a);
		return;
	}
	else if (a.len < b.len)
		throw "BigUnsigned::subtract: "
		"Negative result in unsigned calculation";
	bool borrowIn, borrowOut;
	Blk temp;
	Index i;
	len = a.len;
	allocate(len);
	for (i = 0, borrowIn = false; i < b.len; i++) {
		temp = a.blk[i] - b.blk[i];
		borrowOut = (temp > a.blk[i]);
		if (borrowIn) {
			borrowOut |= (temp == 0);
			temp--;
		}
		blk[i] = temp; 
		borrowIn = borrowOut; 
	}
	for (; i < a.len && borrowIn; i++) {
		borrowIn = (a.blk[i] == 0);
		blk[i] = a.blk[i] - 1;
	}
	
	if (borrowIn) {
		len = 0;
		throw "BigUnsigned::subtract: Negative result in unsigned calculation";
	}
	else
		for (; i < a.len; i++)
			blk[i] = a.blk[i];
	zapLeadingZeros();
}


inline BigUnsigned::Blk id4(const BigUnsigned &num,
	BigUnsigned::Index x, unsigned int y) {
	BigUnsigned::Blk part1 = (x == 0 || y == 0) ? 0 : (num.blk[x - 1] >> (BigUnsigned::N - y));
	BigUnsigned::Blk part2 = (x == num.len) ? 0 : (num.blk[x] << y);
	return part1 | part2;
}
void BigUnsigned::multiply(const BigUnsigned &a, const BigUnsigned &b) {
	DTRT_ALIASED(this == &a || this == &b, multiply(a, b));
	if (a.len == 0 || b.len == 0) {
		len = 0;
		return;
	}
	
	Index i, j, k;
	unsigned int i2;
	Blk temp;
	bool carryIn, carryOut;
	len = a.len + b.len;
	allocate(len);
	for (i = 0; i < len; i++)
		blk[i] = 0;
	for (i = 0; i < a.len; i++) {
		for (i2 = 0; i2 < N; i2++) {
			if ((a.blk[i] & (Blk(1) << i2)) == 0)
				continue;
			
			for (j = 0, k = i, carryIn = false; j <= b.len; j++, k++) {
				
				temp = blk[k] + id4(b, j, i2);
				carryOut = (temp < blk[k]);
				if (carryIn) {
					temp++;
					carryOut |= (temp == 0);
				}
				blk[k] = temp;
				carryIn = carryOut;
			}
			for (; carryIn; k++) {
				blk[k]++;
				carryIn = (blk[k] == 0);
			}
		}
	}
	if (blk[len - 1] == 0)
		len--;
}

void BigUnsigned::divideWithRemainder(const BigUnsigned &b, BigUnsigned &q) {
	
	if (this == &q)
		throw "BigUnsigned::divideWithRemainder: Cannot write quotient and remainder into the same variable";
	
	if (this == &b || &q == &b) {
		BigUnsigned tmpB(b);
		divideWithRemainder(tmpB, q);
		return;
	}
	
	if (b.len == 0) {
		q.len = 0;
		return;
	}
	
	if (len < b.len) {
		q.len = 0;
		return;
	}
	
	Index i, j, k;
	unsigned int i2;
	Blk temp;
	bool borrowIn, borrowOut;
	
	Index origLen = len; 
						 
	allocateAndCopy(len + 1);
	len++;
	blk[origLen] = 0; 
	Blk *subtractBuf = new Blk[len];
	q.len = origLen - b.len + 1;
	q.allocate(q.len);
	for (i = 0; i < q.len; i++)
		q.blk[i] = 0;
	i = q.len;
	while (i > 0) {
		i--;
		q.blk[i] = 0;
		i2 = N;
		while (i2 > 0) {
			i2--;
			
			for (j = 0, k = i, borrowIn = false; j <= b.len; j++, k++) {
				temp = blk[k] - id4(b, j, i2);
				borrowOut = (temp > blk[k]);
				if (borrowIn) {
					borrowOut |= (temp == 0);
					temp--;
				}
				subtractBuf[k] = temp;
				borrowIn = borrowOut;
			}
			for (; k < origLen && borrowIn; k++) {
				borrowIn = (blk[k] == 0);
				subtractBuf[k] = blk[k] - 1;
			}
			
			if (!borrowIn) {
				q.blk[i] |= (Blk(1) << i2);
				while (k > i) {
					k--;
					blk[k] = subtractBuf[k];
				}
			}
		}
	}
	if (q.blk[q.len - 1] == 0)
		q.len--;
	zapLeadingZeros();
	delete[] subtractBuf;
}

void BigUnsigned::bitAnd(const BigUnsigned &a, const BigUnsigned &b) {
	DTRT_ALIASED(this == &a || this == &b, bitAnd(a, b));
	len = (a.len >= b.len) ? b.len : a.len;
	allocate(len);
	Index i;
	for (i = 0; i < len; i++)
		blk[i] = a.blk[i] & b.blk[i];
	zapLeadingZeros();
}
void BigUnsigned::bitOr(const BigUnsigned &a, const BigUnsigned &b) {
	DTRT_ALIASED(this == &a || this == &b, bitOr(a, b));
	Index i;
	const BigUnsigned *a2, *b2;
	if (a.len >= b.len) {
		a2 = &a;
		b2 = &b;
	}
	else {
		a2 = &b;
		b2 = &a;
	}
	allocate(a2->len);
	for (i = 0; i < b2->len; i++)
		blk[i] = a2->blk[i] | b2->blk[i];
	for (; i < a2->len; i++)
		blk[i] = a2->blk[i];
	len = a2->len;
}
void BigUnsigned::bitXor(const BigUnsigned &a, const BigUnsigned &b) {
	DTRT_ALIASED(this == &a || this == &b, bitXor(a, b));
	Index i;
	const BigUnsigned *a2, *b2;
	if (a.len >= b.len) {
		a2 = &a;
		b2 = &b;
	}
	else {
		a2 = &b;
		b2 = &a;
	}
	allocate(a2->len);
	for (i = 0; i < b2->len; i++)
		blk[i] = a2->blk[i] ^ b2->blk[i];
	for (; i < a2->len; i++)
		blk[i] = a2->blk[i];
	len = a2->len;
	zapLeadingZeros();
}
void BigUnsigned::bitShiftLeft(const BigUnsigned &a, int b) {
	DTRT_ALIASED(this == &a, bitShiftLeft(a, b));
	if (b < 0) {
		if (b << 1 == 0)
			throw "BigUnsigned::bitShiftLeft: "
			"Pathological shift amount not implemented";
		else {
			bitShiftRight(a, -b);
			return;
		}
	}
	Index shiftBlocks = b / N;
	unsigned int shiftBits = b % N;
	len = a.len + shiftBlocks + 1;
	allocate(len);
	Index i, j;
	for (i = 0; i < shiftBlocks; i++)
		blk[i] = 0;
	for (j = 0, i = shiftBlocks; j <= a.len; j++, i++)
		blk[i] = id4(a, j, shiftBits);
	if (blk[len - 1] == 0)
		len--;
}
void BigUnsigned::bitShiftRight(const BigUnsigned &a, int b) {
	DTRT_ALIASED(this == &a, bitShiftRight(a, b));
	if (b < 0) {
		if (b << 1 == 0)
			throw "BigUnsigned::bitShiftRight: "
			"Pathological shift amount not implemented";
		else {
			bitShiftLeft(a, -b);
			return;
		}
	}
	Index id15 = (b + N - 1) / N;
	unsigned int id2 = N * id15 - b;
	if (id15 >= a.len + 1) {
		len = 0;
		return;
	}
	len = a.len + 1 - id15;
	allocate(len);
	Index i, j;
	for (j = id15, i = 0; j <= a.len; j++, i++)
		blk[i] = id4(a, j, id2);
	if (blk[len - 1] == 0)
		len--;
}
void BigUnsigned::operator ++() {
	Index i;
	bool carry = true;
	for (i = 0; i < len && carry; i++) {
		blk[i]++;
		carry = (blk[i] == 0);
	}
	if (carry) {
		allocateAndCopy(len + 1);
		len++;
		blk[i] = 1;
	}
}
void BigUnsigned::operator ++(int) {
	operator ++();
}
void BigUnsigned::operator --() {
	if (len == 0)
		throw "BigUnsigned::operator --(): Cannot decrement an unsigned zero";
	Index i;
	bool borrow = true;
	for (i = 0; borrow; i++) {
		borrow = (blk[i] == 0);
		blk[i]--;
	}
	if (blk[len - 1] == 0)
		len--;
}
void BigUnsigned::operator --(int) {
	operator --();
}

class id24 : protected id21<unsigned short> {
public:
	typedef unsigned short Digit;
	typedef Digit Base;
protected:
	Base base;
	id24(int, Index c) : id21<Digit>(0, c) {}
	void zapLeadingZeros() {
		while (len > 0 && blk[len - 1] == 0)
			len--;
	}
public:
	id24() : id21<Digit>(), base(2) {}
	id24(const id24 &x) : id21<Digit>(x), base(x.base) {}
	void operator =(const id24 &x) {
		id21<Digit>::operator =(x);
		base = x.base;
	}
	id24(const Digit *d, Index l, Base base);
	~id24() {}
	id24(const BigUnsigned &x, Base base);
	operator BigUnsigned() const;
	
	operator std::string() const;
	id24(const std::string &s, Base base);
public:
	Base getBase() const { return base; }
	id21<Digit>::getCapacity;
	id21<Digit>::getLength;
	
	Digit getDigit(Index i) const { return i >= len ? 0 : blk[i]; }
	bool isZero() const { return id21<Digit>::isEmpty(); }
	
	bool operator ==(const id24 &x) const {
		return base == x.base && id21<Digit>::operator ==(x);
	}
	bool operator !=(const id24 &x) const { return !operator ==(x); }
};
id24::id24(const Digit *d, Index l, Base base)
	: id21<Digit>(d, l), base(base) {
	if (base < 2)
		throw "id24::id24(const Digit *, Index, Base): The base must be at least 2";
	for (Index i = 0; i < l; i++)
		if (blk[i] >= base)
			throw "id24::id24(const Digit *, Index, Base): A digit is too large for the specified base";
	zapLeadingZeros();
}
namespace {
	unsigned int bitLen(unsigned int x) {
		unsigned int len = 0;
		while (x > 0) {
			x >>= 1;
			len++;
		}
		return len;
	}
	unsigned int id10(unsigned int a, unsigned int b) {
		return (a + b - 1) / b;
	}
}
id24::id24(const BigUnsigned &x, Base base) {
	if (base < 2)
		throw "id24(BigUnsigned, Base): The base must be at least 2";
	this->base = base;
	int id22 = x.getLength() * BigUnsigned::N;
	int id9 = bitLen(base) - 1;
	int id5 = id10(id22, id9);
	len = id5; 
	allocate(len); 
	BigUnsigned x2(x), buBase(base);
	Index digitNum = 0;
	while (!x2.isZero()) {
		BigUnsigned lastDigit(x2);
		lastDigit.divideWithRemainder(buBase, x2);
		blk[digitNum] = lastDigit.toUnsignedShort();
		digitNum++;
	}
	len = digitNum;
}
id24::operator BigUnsigned() const {
	BigUnsigned ans(0), buBase(base), temp;
	Index digitNum = len;
	while (digitNum > 0) {
		digitNum--;
		temp.multiply(ans, buBase);
		ans.add(temp, BigUnsigned(blk[digitNum]));
	}
	return ans;
}
id24::id24(const std::string &s, Base base) {
	if (base > 36)
		throw "id24(std::string, Base): The default string conversion routines use the symbol set 0-9, A-Z and therefore support only up to base 36.  You tried a conversion with a base over 36; write your own string conversion routine.";
	this->base = base;
	len = Index(s.length());
	allocate(len);
	Index digitNum, id17;
	for (digitNum = 0; digitNum < len; digitNum++) {
		id17 = len - 1 - digitNum;
		char theSymbol = s[id17];
		if (theSymbol >= '0' && theSymbol <= '9')
			blk[digitNum] = theSymbol - '0';
		else if (theSymbol >= 'A' && theSymbol <= 'Z')
			blk[digitNum] = theSymbol - 'A' + 10;
		else if (theSymbol >= 'a' && theSymbol <= 'z')
			blk[digitNum] = theSymbol - 'a' + 10;
		else
			throw "id24(std::string, Base): Bad symbol in input.  Only 0-9, A-Z, a-z are accepted.";
		if (blk[digitNum] >= base)
			throw "id24::id24(const Digit *, Index, Base): A digit is too large for the specified base";
	}
	zapLeadingZeros();
}
id24::operator std::string() const {
	if (base > 36)
		throw "id24 ==> std::string: The default string conversion routines use the symbol set 0-9, A-Z and therefore support only up to base 36.  You tried a conversion with a base over 36; write your own string conversion routine.";
	if (len == 0)
		return std::string("0");
	char *s = new char[len + 1];
	s[len] = '\0';
	Index digitNum, id17;
	for (id17 = 0; id17 < len; id17++) {
		digitNum = len - 1 - id17;
		Digit theDigit = blk[digitNum];
		if (theDigit < 10)
			s[id17] = char('0' + theDigit);
		else
			s[id17] = char('A' + theDigit - 10);
	}
	std::string s2(s);
	delete[] s;
	return s2;
}

std::string id23(const BigUnsigned &x);
std::string id11(const BigInteger &x);
BigUnsigned id20(const std::string &s);
BigInteger id25(const std::string &s);
template <class T>
BigInteger id6(const T* data, BigInteger::Index length, BigInteger::Sign sign);
std::ostream &operator <<(std::ostream &os, const BigUnsigned &x);
std::ostream &operator <<(std::ostream &os, const BigInteger &x);
template <class T>
BigInteger id6(const T* data, BigInteger::Index length, BigInteger::Sign sign) {
	unsigned int id1 = 8 * sizeof(T);
	unsigned int id7 = sizeof(BigInteger::Blk) / sizeof(T);
	unsigned int numBlocks = (length + id7 - 1) / id7;
	BigInteger::Blk *blocks = new BigInteger::Blk[numBlocks];
	BigInteger::Index blockNum, pieceNum, id3;
	for (blockNum = 0, pieceNum = 0; blockNum < numBlocks; blockNum++) {
		BigInteger::Blk curBlock = 0;
		for (id3 = 0; id3 < id7 && pieceNum < length;
		id3++, pieceNum++)
			curBlock |= (BigInteger::Blk(data[pieceNum]) << (id1 * id3));
		blocks[blockNum] = curBlock;
	}
	BigInteger x(blocks, numBlocks, sign);
	delete[] blocks;
	return x;
}
std::string id23(const BigUnsigned &x) {
	return std::string(id24(x, 10));
}
std::string id11(const BigInteger &x) {
	return (x.getSign() == BigInteger::negative)
		? (std::string("-") + id23(x.getMagnitude()))
		: (id23(x.getMagnitude()));
}
BigUnsigned id20(const std::string &s) {
	return BigUnsigned(id24(s, 10));
}
BigInteger id25(const std::string &s) {
	return (s[0] == '-') ? BigInteger(id20(s.substr(1, s.length() - 1)), BigInteger::negative)
		: (s[0] == '+') ? BigInteger(id20(s.substr(1, s.length() - 1)))
		: BigInteger(id20(s));
}
std::ostream &operator <<(std::ostream &os, const BigUnsigned &x) {
	id24::Base base;
	long osFlags = os.flags();
	if (osFlags & os.dec)
		base = 10;
	else if (osFlags & os.hex) {
		base = 16;
		if (osFlags & os.showbase)
			os << "0x";
	}
	else if (osFlags & os.oct) {
		base = 8;
		if (osFlags & os.showbase)
			os << '0';
	}
	else
		throw "std::ostream << BigUnsigned: Could not determine the desired base from output-stream flags";
	std::string s = std::string(id24(x, base));
	os << s;
	return os;
}
std::ostream &operator <<(std::ostream &os, const BigInteger &x) {
	if (x.getSign() == BigInteger::negative)
		os << '-';
	os << x.getMagnitude();
	return os;
}
BigInteger gcd(BigInteger a, BigInteger b, BigInteger & x, BigInteger & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	BigInteger x1, y1;
	BigInteger d = gcd(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
int main() {
	string a, b, c;
	bool ia = false, ib = false, ic = false;
	cin >> a;
	cin >> b;
	cin >> c;

	BigInteger aBig = id25(a);
	BigInteger bBig = id25(b);
	BigInteger cBig = id25(c);
	if (cBig > 0) {
		aBig = -aBig;
		bBig = -bBig;
	}
	else {
		cBig = -cBig;
	}

	if (aBig < 0) {
		ia = true;
		aBig = -aBig;
	}
	if (bBig < 0) {
		ib = true;
		bBig = -bBig;
	}
	BigInteger x0(1);
	BigInteger y0(1);
	BigInteger g = gcd(aBig, bBig, x0, y0);
	if (cBig % g != 0) {
		cout << "-1";
		exit(0);
	}
	x0 = x0 * (cBig / g);
	y0 = y0 * (cBig / g);
	if (ia)   x0 *= -1;
	if (ib)   y0 *= -1;
	cout << x0 << " " << y0;
	return 0;
}