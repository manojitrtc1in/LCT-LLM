
























using namespace std;




















































typedef short id2;
typedef int PRODUCT_TYPE;
static const id2 BASE = 10000;
static const id2 id5 = 9999;
static const id2 id0 = 4;
static const int powersOfTen[] = { 1, 10, 100, 1000};


typedef int id2;
typedef long long PRODUCT_TYPE;
static const id2 BASE = 1000000000;
static const id2 id5 = 999999999;
static const id2 id0 = 9;
static const int powersOfTen[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };



class id3: public std::exception
{
public:
    id3(const std::string& txt) throw ();
    ~id3() throw ();
    const char* what() const throw ();
private:
    std::string txt;
};

id3::id3(const std::string& txt) throw () :
std::exception(), txt(txt)
{
}

id3::~id3() throw ()
{
}

const char* id3::what() const throw ()
{
    return txt.c_str();
}


class InfInt
{
    friend std::ostream& operator<<(std::ostream &s, const InfInt &n);
    friend std::istream& operator>>(std::istream &s, InfInt &val);

public:
    
    static const InfInt zero;
    static const InfInt one;
    static const InfInt two;

    
    InfInt();
    InfInt(const char* c);
    InfInt(const std::string& s);
    InfInt(int l);
    InfInt(long l);
    InfInt(long long l);
    InfInt(unsigned int l);
    InfInt(unsigned long l);
    InfInt(unsigned long long l);

    
    const InfInt& operator=(const char* c);
    const InfInt& operator=(const std::string& s);
    const InfInt& operator=(int l);
    const InfInt& operator=(long l);
    const InfInt& operator=(long long l);
    const InfInt& operator=(unsigned int l);
    const InfInt& operator=(unsigned long l);
    const InfInt& operator=(unsigned long long l);

    
    const InfInt& operator++();
    const InfInt& operator--();
    InfInt operator++(int);
    InfInt operator--(int);

    
    const InfInt& operator+=(const InfInt& rhs);
    const InfInt& operator-=(const InfInt& rhs);
    const InfInt& operator*=(const InfInt& rhs);
    const InfInt& operator/=(const InfInt& rhs); 

    const InfInt& operator%=(const InfInt& rhs); 

    const InfInt& operator*=(id2 rhs);

    
    InfInt operator-() const;
    InfInt operator+(const InfInt& rhs) const;
    InfInt operator-(const InfInt& rhs) const;
    InfInt operator*(const InfInt& rhs) const;
    InfInt operator/(const InfInt& rhs) const; 

    InfInt operator%(const InfInt& rhs) const; 

    InfInt operator*(id2 rhs) const;

    
    bool operator==(const InfInt& rhs) const;
    bool operator!=(const InfInt& rhs) const;
    bool operator<(const InfInt& rhs) const;
    bool operator<=(const InfInt& rhs) const;
    bool operator>(const InfInt& rhs) const;
    bool operator>=(const InfInt& rhs) const;

    
    InfInt intSqrt() const; 


    
    char digitAt(size_t i) const; 

    size_t numberOfDigits() const;

    
    size_t size() const;

    
    std::string toString() const;

    
    int toInt() const; 

    long toLong() const; 

    long long toLongLong() const; 

    unsigned int toUnsignedInt() const; 

    unsigned long toUnsignedLong() const; 

    unsigned long long toUnsignedLongLong() const; 


private:
    static id2 dInR(const InfInt& R, const InfInt& D);
    static void multiplyByDigit(id2 factor, std::vector<id2>& val);

    void correct(bool id4 = false, bool id1 = false);
    void fromString(const std::string& s);
    void optimizeSqrtSearchBounds(InfInt& lo, InfInt& hi) const;
    void truncateToBase();
    bool equalizeSigns();
    void removeLeadingZeros();

    std::vector<id2> val; 

    bool pos; 

};

const InfInt InfInt::zero = 0;
const InfInt InfInt::one = 1;
const InfInt InfInt::two = 2;

inline InfInt::InfInt() : pos(true)
{
    val.push_back((id2) 0);
}

inline InfInt::InfInt(const char* c)
{
    fromString(c);
}

inline InfInt::InfInt(const std::string& s)
{
    fromString(s);
}

inline InfInt::InfInt(int l) : pos(l >= 0)
{
    if (!pos)
    {
        l = -l;
    }
    do
    {
        div_t dt = div(l, BASE);
        val.push_back((id2) dt.rem);
        l = dt.quot;
    } while (l > 0);
}

inline InfInt::InfInt(long l) : pos(l >= 0)
{
    if (!pos)
    {
        l = -l;
    }
    do
    {
        ldiv_t dt = ldiv(l, BASE);
        val.push_back((id2) dt.rem);
        l = dt.quot;
    } while (l > 0);
}

inline InfInt::InfInt(long long l) : pos(l >= 0)
{
    if (!pos)
    {
        l = -l;
    }
    do
    {

        lldiv_t dt = lldiv(l, BASE);
        val.push_back((id2) dt.rem);
        l = dt.quot;

        val.push_back((id2) (l % BASE));
        l = l / BASE;

    } while (l > 0);
}

inline InfInt::InfInt(unsigned int l) : pos(true)
{
    do
    {
        val.push_back((id2) (l % BASE));
        l = l / BASE;
    } while (l > 0);
}

inline InfInt::InfInt(unsigned long l) : pos(true)
{
    do
    {
        val.push_back((id2) (l % BASE));
        l = l / BASE;
    } while (l > 0);
}

inline InfInt::InfInt(unsigned long long l) : pos(true)
{
    do
    {
        val.push_back((id2) (l % BASE));
        l = l / BASE;
    } while (l > 0);
}

inline const InfInt& InfInt::operator=(const char* c)
{
    fromString(c);
    return *this;
}

inline const InfInt& InfInt::operator=(const std::string& s)
{
    fromString(s);
    return *this;
}

inline const InfInt& InfInt::operator=(int l)
{
    pos = l >= 0;
    val.clear();
    if (!pos)
    {
        l = -l;
    }
    do
    {
        div_t dt = div(l, BASE);
        val.push_back((id2) dt.rem);
        l = dt.quot;
    } while (l > 0);
    return *this;
}

inline const InfInt& InfInt::operator=(long l)
{
    pos = l >= 0;
    val.clear();
    if (!pos)
    {
        l = -l;
    }
    do
    {
        ldiv_t dt = ldiv(l, BASE);
        val.push_back((id2) dt.rem);
        l = dt.quot;
    } while (l > 0);
    return *this;
}

inline const InfInt& InfInt::operator=(long long l)
{
    pos = l >= 0;
    val.clear();
    if (!pos)
    {
        l = -l;
    }
    do
    {

        lldiv_t dt = lldiv(l, BASE);
        val.push_back((id2) dt.rem);
        l = dt.quot;

        val.push_back((id2) (l % BASE));
        l = l / BASE;

    } while (l > 0);
    return *this;
}

inline const InfInt& InfInt::operator=(unsigned int l)
{
    pos = true;
    val.clear();
    do
    {
        val.push_back((id2) (l % BASE));
        l = l / BASE;
    } while (l > 0);
    return *this;
}

inline const InfInt& InfInt::operator=(unsigned long l)
{
    pos = true;
    val.clear();
    do
    {
        val.push_back((id2) (l % BASE));
        l = l / BASE;
    } while (l > 0);
    return *this;
}

inline const InfInt& InfInt::operator=(unsigned long long l)
{
    pos = true;
    val.clear();
    do
    {
        val.push_back((id2) (l % BASE));
        l = l / BASE;
    } while (l > 0);
    return *this;
}

inline const InfInt& InfInt::operator++()
{
    val[0] += (pos ? 1 : -1);
    this->correct(false, true);
    return *this;
}

inline const InfInt& InfInt::operator--()
{
    val[0] -= (pos ? 1 : -1);
    this->correct(false, true);
    return *this;
}

inline InfInt InfInt::operator++(int)
{
    InfInt result = *this;
    val[0] += (pos ? 1 : -1);
    this->correct(false, true);
    return result;
}

inline InfInt InfInt::operator--(int)
{
    InfInt result = *this;
    val[0] -= (pos ? 1 : -1);
    this->correct(false, true);
    return result;
}

inline const InfInt& InfInt::operator+=(const InfInt& rhs)
{
    if (rhs.val.size() > val.size())
    {
        val.resize(rhs.val.size(), 0);
    }
    for (size_t i = 0; i < val.size(); ++i)
    {
        val[i] = (pos ? val[i] : -val[i]) + (i < rhs.val.size() ? (rhs.pos ? rhs.val[i] : -rhs.val[i]) : 0);
    }
    correct();
    return *this;
}

inline const InfInt& InfInt::operator-=(const InfInt& rhs)
{
    if (rhs.val.size() > val.size())
    {
        val.resize(rhs.val.size(), 0);
    }
    for (size_t i = 0; i < val.size(); ++i)
    {
        val[i] = (pos ? val[i] : -val[i]) - (i < rhs.val.size() ? (rhs.pos ? rhs.val[i] : -rhs.val[i]) : 0);
    }
    correct();
    return *this;
}

inline const InfInt& InfInt::operator*=(const InfInt& rhs)
{
    

    *this = *this * rhs;
    return *this;
}

inline const InfInt& InfInt::operator/=(const InfInt& rhs)
{
    if (rhs == zero)
    {

        throw id3("division by zero");

        std::cerr << "Division by zero!" << std::endl;
        return *this;

    }
    InfInt R, D = (rhs.pos ? rhs : -rhs), N = (pos ? *this : -*this);
    bool oldpos = pos;
    val.clear();
    val.resize(N.val.size(), 0);
    for (int i = (int) N.val.size() - 1; i >= 0; --i)
    {
        R.val.insert(R.val.begin(), (id2) 0);
        R.val[0] = N.val[i];
        R.correct(true);
        id2 cnt = dInR(R, D);
        R -= D * cnt;
        val[i] += cnt;
    }
    correct();
    pos = (val.size() == 1 && val[0] == 0) ? true : (oldpos == rhs.pos);
    return *this;
}

inline const InfInt& InfInt::operator%=(const InfInt& rhs)
{
    if (rhs == zero)
    {

        throw id3("division by zero");

        std::cerr << "Division by zero!" << std::endl;
        return zero;

    }
    InfInt D = (rhs.pos ? rhs : -rhs), N = (pos ? *this : -*this);
    bool oldpos = pos;
    val.clear();
    for (int i = (int) N.val.size() - 1; i >= 0; --i)
    {
        val.insert(val.begin(), (id2) 0);
        val[0] = N.val[i];
        correct(true);
        *this -= D * dInR(*this, D);
    }
    correct();
    pos = (val.size() == 1 && val[0] == 0) ? true : oldpos;
    return *this;
}

inline const InfInt& InfInt::operator*=(id2 rhs)
{
    id2 factor = rhs < 0 ? -rhs : rhs;
    bool oldpos = pos;
    multiplyByDigit(factor, val);
    correct();
    pos = (val.size() == 1 && val[0] == 0) ? true : (oldpos == (rhs >= 0));
    return *this;
}

inline InfInt InfInt::operator-() const
{

    InfInt result = *this;
    result.pos = !pos;
    return result;
}

inline InfInt InfInt::operator+(const InfInt& rhs) const
{

    InfInt result;
    result.val.resize(val.size() > rhs.val.size() ? val.size() : rhs.val.size(), 0);
    for (size_t i = 0; i < val.size() || i < rhs.val.size(); ++i)
    {
        result.val[i] = (i < val.size() ? (pos ? val[i] : -val[i]) : 0) + (i < rhs.val.size() ? (rhs.pos ? rhs.val[i] : -rhs.val[i]) : 0);
    }
    result.correct();
    return result;
}

inline InfInt InfInt::operator-(const InfInt& rhs) const
{

    InfInt result;
    result.val.resize(val.size() > rhs.val.size() ? val.size() : rhs.val.size(), 0);
    for (size_t i = 0; i < val.size() || i < rhs.val.size(); ++i)
    {
        result.val[i] = (i < val.size() ? (pos ? val[i] : -val[i]) : 0) - (i < rhs.val.size() ? (rhs.pos ? rhs.val[i] : -rhs.val[i]) : 0);
    }
    result.correct();
    return result;
}

inline InfInt InfInt::operator*(const InfInt& rhs) const
{

    InfInt result;
    result.val.resize(val.size() + rhs.val.size(), 0);
    PRODUCT_TYPE carry = 0;
    size_t digit = 0;
    for (;; ++digit)
    {

        

        


        PRODUCT_TYPE oldcarry = carry;
        carry /= BASE;
        result.val[digit] = (id2) (oldcarry - carry * BASE);

        bool found = false;
        for (size_t i = digit < rhs.val.size() ? 0 : digit - rhs.val.size() + 1; i < val.size() && i <= digit; ++i)
        {

            PRODUCT_TYPE pval = result.val[digit] + val[i] * (PRODUCT_TYPE) rhs.val[digit - i];
            if (pval >= BASE || pval <= -BASE)
            {

                

                


                PRODUCT_TYPE quot = pval / BASE;
                carry += quot;
                pval -= quot * BASE;
            }
            result.val[digit] = (id2) pval;
            found = true;
        }
        if (!found)
        {

            break;
        }
    }
    for (; carry > 0; ++digit)
    {

        result.val[digit] = (id2) (carry % BASE);
        carry /= BASE;
    }
    result.correct();
    result.pos = (result.val.size() == 1 && result.val[0] == 0) ? true : (pos == rhs.pos);
    return result;
}

inline InfInt InfInt::operator/(const InfInt& rhs) const
{

    if (rhs == zero)
    {

        throw id3("division by zero");

        std::cerr << "Division by zero!" << std::endl;
        return zero;

    }
    InfInt Q, R, D = (rhs.pos ? rhs : -rhs), N = (pos ? *this : -*this);
    Q.val.resize(N.val.size(), 0);
    for (int i = (int) N.val.size() - 1; i >= 0; --i)
    {

        R.val.insert(R.val.begin(), (id2) 0);
        R.val[0] = N.val[i];
        R.correct(true);
        id2 cnt = dInR(R, D);
        R -= D * cnt;
        Q.val[i] += cnt;
    }
    Q.correct();
    Q.pos = (Q.val.size() == 1 && Q.val[0] == 0) ? true : (pos == rhs.pos);
    return Q;
}

inline InfInt InfInt::operator%(const InfInt& rhs) const
{

    if (rhs == zero)
    {

        throw id3("division by zero");

        std::cerr << "Division by zero!" << std::endl;
        return zero;

    }
    InfInt R, D = (rhs.pos ? rhs : -rhs), N = (pos ? *this : -*this);
    for (int i = (int) N.val.size() - 1; i >= 0; --i)
    {
        R.val.insert(R.val.begin(), (id2) 0);
        R.val[0] = N.val[i];
        R.correct(true);
        R -= D * dInR(R, D);
    }
    R.correct();
    R.pos = (R.val.size() == 1 && R.val[0] == 0) ? true : pos;
    return R;
}

inline InfInt InfInt::operator*(id2 rhs) const
{

    InfInt result = *this;
    id2 factor = rhs < 0 ? -rhs : rhs;
    multiplyByDigit(factor, result.val);
    result.correct();
    result.pos = (result.val.size() == 1 && result.val[0] == 0) ? true : (pos == (rhs >= 0));
    return result;
}

inline bool InfInt::operator==(const InfInt& rhs) const
{

    if (pos != rhs.pos || val.size() != rhs.val.size())
    {
        return false;
    }
    for (int i = (int) val.size() - 1; i >= 0; --i)
    {
        if (val[i] != rhs.val[i])
        {
            return false;
        }
    }
    return true;
}

inline bool InfInt::operator!=(const InfInt& rhs) const
{

    if (pos != rhs.pos || val.size() != rhs.val.size())
    {
        return true;
    }
    for (int i = (int) val.size() - 1; i >= 0; --i)
    {
        if (val[i] != rhs.val[i])
        {
            return true;
        }
    }
    return false;
}

inline bool InfInt::operator<(const InfInt& rhs) const
{

    if (pos && !rhs.pos)
    {
        return false;
    }
    if (!pos && rhs.pos)
    {
        return true;
    }
    if (val.size() > rhs.val.size())
    {
        return pos ? false : true;
    }
    if (val.size() < rhs.val.size())
    {
        return pos ? true : false;
    }
    for (int i = (int) val.size() - 1; i >= 0; --i)
    {
        if (val[i] < rhs.val[i])
        {
            return pos ? true : false;
        }
        if (val[i] > rhs.val[i])
        {
            return pos ? false : true;
        }
    }
    return false;
}

inline bool InfInt::operator<=(const InfInt& rhs) const
{

    if (pos && !rhs.pos)
    {
        return false;
    }
    if (!pos && rhs.pos)
    {
        return true;
    }
    if (val.size() > rhs.val.size())
    {
        return pos ? false : true;
    }
    if (val.size() < rhs.val.size())
    {
        return pos ? true : false;
    }
    for (int i = (int) val.size() - 1; i >= 0; --i)
    {
        if (val[i] < rhs.val[i])
        {
            return pos ? true : false;
        }
        if (val[i] > rhs.val[i])
        {
            return pos ? false : true;
        }
    }
    return true;
}

inline bool InfInt::operator>(const InfInt& rhs) const
{

    if (pos && !rhs.pos)
    {
        return true;
    }
    if (!pos && rhs.pos)
    {
        return false;
    }
    if (val.size() > rhs.val.size())
    {
        return pos ? true : false;
    }
    if (val.size() < rhs.val.size())
    {
        return pos ? false : true;
    }
    for (int i = (int) val.size() - 1; i >= 0; --i)
    {
        if (val[i] < rhs.val[i])
        {
            return pos ? false : true;
        }
        if (val[i] > rhs.val[i])
        {
            return pos ? true : false;
        }
    }
    return false;
}

inline bool InfInt::operator>=(const InfInt& rhs) const
{

    if (pos && !rhs.pos)
    {
        return true;
    }
    if (!pos && rhs.pos)
    {
        return false;
    }
    if (val.size() > rhs.val.size())
    {
        return pos ? true : false;
    }
    if (val.size() < rhs.val.size())
    {
        return pos ? false : true;
    }
    for (int i = (int) val.size() - 1; i >= 0; --i)
    {
        if (val[i] < rhs.val[i])
        {
            return pos ? false : true;
        }
        if (val[i] > rhs.val[i])
        {
            return pos ? true : false;
        }
    }
    return true;
}

inline void InfInt::optimizeSqrtSearchBounds(InfInt& lo, InfInt& hi) const
{

    InfInt hdn = one;
    for (int i = (int) this->numberOfDigits() / 2; i >= 2; --i)
    {
        hdn *= 10;
    }
    if (lo < hdn)
    {
        lo = hdn;
    }
    hdn *= 100;
    if (hi > hdn)
    {
        hi = hdn;
    }
}

inline InfInt InfInt::intSqrt() const
{

    if (*this <= zero)
    {

        throw id3("intSqrt called for non-positive integer");

        std::cerr << "intSqrt called for non-positive integer: " << *this << std::endl;
        return zero;

    }
    InfInt hi = *this / two + one, lo = zero, mid, mid2;
    optimizeSqrtSearchBounds(lo, hi);
    do
    {
        mid = (hi + lo) / two; 

        mid2 = mid * mid; 

        if (mid2 == *this)
        {
            lo = mid;
            break;
        }
        else if (mid2 < *this)
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    } while (lo < hi - one && mid2 != *this);
    return lo;
}

inline char InfInt::digitAt(size_t i) const
{

    if (numberOfDigits() <= i)
    {

        throw id3("invalid digit index");

        std::cerr << "Invalid digit index: " << i << std::endl;
        return -1;

    }
    return (val[i / id0] / powersOfTen[i % id0]) % 10;
}

inline size_t InfInt::numberOfDigits() const
{

    return (val.size() - 1) * id0

    + (val.back() > 999 ? 4 : (val.back() > 99 ? 3 : (val.back() > 9 ? 2 : 1)));

    + (val.back() > 99999999 ? 9 : (val.back() > 9999999 ? 8 : (val.back() > 999999 ? 7 : (val.back() > 99999 ? 6 :
                                                                                           (val.back() > 9999 ? 5 : (val.back() > 999 ? 4 : (val.back() > 99 ? 3 : (val.back() > 9 ? 2 : 1))))))));

}

inline std::string InfInt::toString() const
{

    std::ostringstream oss;
    oss << *this;
    return oss.str();
}

inline size_t InfInt::size() const
{

    return val.size() * sizeof(id2) + sizeof(bool);
}

inline int InfInt::toInt() const
{

    if (*this > INT_MAX || *this < INT_MIN)

        throw id3("out of bounds");

    std::cerr << "Out of INT bounds: " << *this << std::endl;

    int result = 0;
    for (int i = (int) val.size() - 1; i >= 0; --i)
    {
        result = result * BASE + val[i];
    }
    return pos ? result : -result;
}

inline long InfInt::toLong() const
{

    if (*this > LONG_MAX || *this < LONG_MIN)

        throw id3("out of bounds");

    std::cerr << "Out of LONG bounds: " << *this << std::endl;

    long result = 0;
    for (int i = (int) val.size() - 1; i >= 0; --i)
    {
        result = result * BASE + val[i];
    }
    return pos ? result : -result;
}

inline long long InfInt::toLongLong() const
{

    if (*this > LONG_LONG_MAX || *this < LONG_LONG_MIN)

        throw id3("out of bounds");

    std::cerr << "Out of LLONG bounds: " << *this << std::endl;

    long long result = 0;
    for (int i = (int) val.size() - 1; i >= 0; --i)
    {
        result = result * BASE + val[i];
    }
    return pos ? result : -result;
}

inline unsigned int InfInt::toUnsignedInt() const
{

    if (!pos || *this > UINT_MAX)

        throw id3("out of bounds");

    std::cerr << "Out of UINT bounds: " << *this << std::endl;

    unsigned int result = 0;
    for (int i = (int) val.size() - 1; i >= 0; --i)
    {
        result = result * BASE + val[i];
    }
    return result;
}

inline unsigned long InfInt::toUnsignedLong() const
{

    if (!pos || *this > ULONG_MAX)

        throw id3("out of bounds");

    std::cerr << "Out of ULONG bounds: " << *this << std::endl;

    unsigned long result = 0;
    for (int i = (int) val.size() - 1; i >= 0; --i)
    {
        result = result * BASE + val[i];
    }
    return result;
}

inline unsigned long long InfInt::toUnsignedLongLong() const
{

    if (!pos || *this > ULONG_LONG_MAX)

        throw id3("out of bounds");

    std::cerr << "Out of ULLONG bounds: " << *this << std::endl;

    unsigned long long result = 0;
    for (int i = (int) val.size() - 1; i >= 0; --i)
    {
        result = result * BASE + val[i];
    }
    return result;
}

inline void InfInt::truncateToBase()
{

    for (size_t i = 0; i < val.size(); ++i) 

    {
        if (val[i] >= BASE || val[i] <= -BASE)
        {

            div_t dt = div(val[i], BASE);
            val[i] = dt.rem;
            if (i + 1 >= val.size())
            {

                val.push_back(dt.quot);
            }
            else
            {

                val[i + 1] += dt.quot;
            }
        }
    }
}

inline bool InfInt::equalizeSigns()
{

    bool isPositive = true;
    int i = (int) ((val.size())) - 1;
    for (; i >= 0; --i)
    {
        if (val[i] != 0)
        {
            isPositive = val[i--] > 0;
            break;
        }
    }

    if (isPositive)
    {
        for (; i >= 0; --i)
        {
            if (val[i] < 0)
            {
                int k = 0, index = i + 1;
                for (; (size_t)(index) < val.size() && val[index] == 0; ++k, ++index); 

                

                { 

                    val[index] -= 1;
                    val[i] += BASE;
                    for (; k > 0; --k)
                    {
                        val[i + k] = id5;
                    }
                }
            }
        }
    }
    else
    {
        for (; i >= 0; --i)
        {
            if (val[i] > 0)
            {
                int k = 0, index = i + 1;
                for (; (size_t)(index) < val.size() && val[index] == 0; ++k, ++index); 

                

                { 

                    val[index] += 1;
                    val[i] -= BASE;
                    for (; k > 0; --k)
                    {
                        val[i + k] = -id5;
                    }
                }
            }
        }
    }

    return isPositive;
}

inline void InfInt::removeLeadingZeros()
{

    for (int i = (int) (val.size()) - 1; i > 0; --i) 

    {
        if (val[i] != 0)
        {
            return;
        }
        else
        {
            val.erase(val.begin() + i);
        }
    }
}

inline void InfInt::correct(bool id4, bool id1)
{

    if (!id4)
    {
        truncateToBase();

        if (equalizeSigns())
        {
            pos = ((val.size() == 1 && val[0] == 0) || !id1) ? true : pos;
        }
        else
        {
            pos = id1 ? !pos : false;
            for (size_t i = 0; i < val.size(); ++i)
            {
                val[i] = abs(val[i]);
            }
        }
    }

    removeLeadingZeros();
}

inline void InfInt::fromString(const std::string& s)
{

    pos = true;
    val.clear();
    

    val.reserve(s.size() / id0 + 1);
    int i = (int) s.size() - id0;
    for (; i >= 0; i -= id0)
    {
        val.push_back(atoi(s.substr(i, id0).c_str()));
    }
    if (i > -id0)
    {
        std::string ss = s.substr(0, i + id0);
        if (ss.size() == 1 && ss[0] == '-')
        {
            pos = false;
        }
        else
        {
            val.push_back(atoi(ss.c_str()));
        }
    }
    if (val.back() < 0)
    {
        val.back() = -val.back();
        pos = false;
    }
    correct(true);
}

inline id2 InfInt::dInR(const InfInt& R, const InfInt& D)
{

    id2 min = 0, max = id5;
    while (max - min > 0)
    {
        id2 avg = max + min;
        

        

        id2 havg = avg / 2;
        avg = (avg - havg * 2) ? (havg + 1) : havg;
        InfInt prod = D * avg;
        if (R == prod)
        {

            return avg;
        }
        else if (R > prod)
        {

            min = avg;
        }
        else
        {

            max = avg - 1;
        }
    }
    return min;
}

inline void InfInt::multiplyByDigit(id2 factor, std::vector<id2>& val)
{

    id2 carry = 0;
    for (size_t i = 0; i < val.size(); ++i)
    {
        PRODUCT_TYPE pval = val[i] * (PRODUCT_TYPE) factor + carry;
        if (pval >= BASE || pval <= -BASE)
        {
            

            


            carry = (id2) (pval / BASE);
            pval -= carry * BASE;
        }
        else
        {
            carry = 0;
        }
        val[i] = (id2) pval;
    }
    if (carry > 0)
    {
        val.push_back(carry);
    }
}





inline std::istream& operator>>(std::istream &s, InfInt &n)
{

    std::string str;
    s >> str;
    n.fromString(str);
    return s;
}

inline std::ostream& operator<<(std::ostream &s, const InfInt &n)
{

    if (!n.pos)
    {
        s << '-';
    }
    bool first = true;
    for (int i = (int) n.val.size() - 1; i >= 0; --i)
    {
        if (first)
        {
            s << n.val[i];
            first = false;
        }
        else
        {
            s << std::setfill('0') << std::setw(id0) << n.val[i];
        }
    }
    return s;
}



typedef InfInt ll ;
const double EPS = (1e-9);

string s ;
bitset<30> bits ;
int cnt ;
char leading ;
bool lead = 1 ;
ll res ;

ll alpha(int n);
ll beta(int n);
ll power(ll n , int p);

int main()

{
    fast ;

    cin >> s ;

    leading = s[0] ;

    if(isdigit(leading))
        lead = 0 ;

    for(int i = 0 ; i < s.size() ; ++i){
        if(isalpha(s[i]))bits[ s[i] - 'A' ] = 1 ;
        else if( s[i] == '?' )++cnt ;
    }

    if( !lead ){
        res = alpha(bits.count()) * power(10,cnt);
    }
    else{
        if(leading == '?')
            res = alpha(bits.count()) * power(10,cnt-1)*9;
        else
            res = beta(bits.count()) * power(10,cnt);
    }

    cout<<res ;

    return 0;
}

ll alpha(int n)
{
    ll cnt = 10LL , res = 1LL ;
    for(int i = 0 ; i < min(n,11) ; ++i){
        res*=cnt ;
        cnt = max(--cnt,InfInt(0));
    }
    return res ;
}

ll beta(int n)
{
    ll cnt = 9LL , res = 9LL ;
    for(int i = 0 ; i < min(n-1,11) ; ++i){
        res*=cnt ;
        cnt = max(--cnt,InfInt(0));
    }
    return res ;
}

ll power(ll n , int p)
{
    if( p <= 0 )return 1 ;

    ll x = power(n,p/2);

    if(p&1)return x*x*n ;
    else return x*x ;
}
