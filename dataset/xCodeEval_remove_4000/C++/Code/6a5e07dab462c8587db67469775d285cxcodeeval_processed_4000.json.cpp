







































struct id4
{
    id4(): counter(0) {}
    ~id4() { std::cout << std::endl << "DIAG: " << (counter == 0 ? "OK" : "!!!") << " Asserts count: " << counter << std::endl; }
    void Increment() { counter++; }
    uint32_t counter;
};
id4 id8;







typedef std::string string8_t;
typedef long double ld_t;

typedef std::vector<size_t> vector_size_t;
typedef std::vector<int32_t> vector_int32_t;
typedef std::vector<uint32_t> vector_uint32_t;
typedef std::vector<int64_t> vector_int64_t;
typedef std::vector<uint64_t> vector_uint64_t;
typedef std::vector<string8_t> vector_string8_t;

typedef std::vector<vector_size_t> vector_2d_size_t;
typedef std::vector<vector_int32_t> vector_2d_int32_t;
typedef std::vector<vector_uint32_t> vector_2d_uint32_t;
typedef std::vector<vector_int64_t> vector_2d_int64_t;
typedef std::vector<vector_uint64_t> vector_2d_uint64_t;

typedef std::set<size_t> set_size_t;
typedef std::set<int32_t> set_int32_t;
typedef std::set<uint32_t> set_uint32_t;
typedef std::set<int64_t> set_int64_t;
typedef std::set<uint64_t> set_uint64_t;
typedef std::set<string8_t> set_string8_t;

typedef std::multiset<size_t> multiset_size_t;
typedef std::multiset<string8_t> multiset_string8_t;





template<typename T> void UpdateMin(T& a, const T b) {a = std::min(a, b);}
template<typename T> void UpdateMax(T& a, const T b) {a = std::max(a, b);}

static const ld_t Eps = 1.0e-09;
template<typename T> bool IsEqual(const T a, const T b) { return std::abs(a - b) < Eps; }
template<typename T> bool IsGreater(const T a, const T b) { return a > b + Eps; }
template<typename T> bool IsLess(const T a, const T b) { return a + Eps < b; }

template<typename T> string8_t ToStr(const T& val) { std::ostringstream ostr; ostr << val; return ostr.str(); }
template<typename T> bool FromStr(const string8_t& str, T& val) {std::istringstream istr(str); istr >> val; return !!istr; }

template<typename T> std::istream& operator>>(std::istream& ist, std::vector<T>& data)
{
    LOCAL_ASSERT(!!ist);
    for (size_t i = 0; i < data.size(); i++) { ist >> data[i]; }
    return ist;
}

template<typename T> T Read(std::istream& ist)
{
    LOCAL_ASSERT(!!ist);
    T val; ist >> val; return val;
}

template<typename T> std::ostream& operator<<(std::ostream& ost, const std::vector<T>& data)
{
    for (size_t i = 0; i < data.size(); i++) { if (i != 0) { ost << ' '; } ost << data[i]; }
    return ost;
}


template<size_t id> class StopWatch { };



library::random::Rand id5;


template<uint32_t Base>
struct BaseTraits
{
    typedef uint32_t digit_t;
    static const uint32_t Value = Base;
    static const size_t Length = BaseTraits<Base / 10>::Length + 1;
};

template<>
struct BaseTraits<1>
{
    typedef uint32_t digit_t;
    static const uint32_t Value = 1;
    static const size_t Length = 0;
};

template<>
struct BaseTraits<0> { };


template<uint32_t Base>
class BigInteger
{
public:
    static const size_t BaseLength = BaseTraits<Base>::Length;
    typedef typename BaseTraits<Base>::digit_t digit_t;
    typedef std::vector<digit_t> vector_digits_t;

    ~BigInteger()
    {
        LOCAL_ASSERT(IsNormalized());
    }

    BigInteger(): id9(false)
    {
    }

    BigInteger(const BigInteger& rv): m_digits(rv.m_digits), id9(rv.id9)
    {
    }

    explicit BigInteger(const vector_digits_t& digits): m_digits(digits), id9(false)
    {
    }

    explicit BigInteger(const vector_digits_t& digits, const bool isNegative): m_digits(digits), id9(isNegative)
    {
    }

    explicit BigInteger(const string8_t& str)
    {
        id3(str.begin(), str.end(), id9, m_digits);
    }

    explicit BigInteger(const int64_t val)
    {
        InitFromValue(val, id9, m_digits);
    }

    explicit BigInteger(const int32_t val)
    {
        InitFromValue((int64_t)val, id9, m_digits);
    }

    explicit BigInteger(const uint64_t val): id9(false)
    {
        InitFromValue(val, m_digits);
    }

    explicit BigInteger(const uint32_t val): id9(false)
    {
        InitFromValue((uint64_t)val, m_digits);
    }

    void Swap(BigInteger& rv)
    {
        std::swap(m_digits, rv.m_digits);
        std::swap(id9, rv.id9);
    }

    BigInteger& operator=(const BigInteger& rv) { return id0(rv); }
    BigInteger& operator=(const vector_digits_t& digits) { return id0(digits); }
    BigInteger& operator=(const string8_t& str) { return id0(str); }
    BigInteger& operator=(const int64_t val) { return id0(val); }
    BigInteger& operator=(const uint64_t val) { return id0(val); }

    int32_t Sign() const
    {
        if (m_digits.empty())
            return 0;
        return id9 ? -1 : +1;
    }

    BigInteger Abs() const
    {
        return BigInteger(m_digits);
    }

    template<typename value_type_t>
    value_type_t id7() const
    {
        value_type_t r = 0;
        for (size_t i = 0; i < m_digits.size(); i++)
        {
            r *= Base;
            r += m_digits[m_digits.size() - 1 - i];
        }
        return r;
    }

    const vector_digits_t& GetDigits() const
    {
        return m_digits;
    }

    bool operator==(const BigInteger& rv) const
    {
        if (Sign() != rv.Sign())
            return false;
        if (!IsEqual(m_digits, rv.m_digits))
            return false;
        return true;
    }

    bool operator!=(const BigInteger& rv) const
    {
        return !this->operator==(rv);
    }

    bool operator<(const BigInteger& rv) const
    {
        const int32_t s = Sign();
        const int32_t sr = rv.Sign();
        if (s != sr)
            return s < sr;
        if (s > 0)
            return IsLess(m_digits, rv.m_digits);
        else
            return IsLess(rv.m_digits, m_digits);
    }

    bool operator>(const BigInteger& rv) const
    {
        const int32_t s = Sign();
        const int32_t sr = rv.Sign();
        if (s != sr)
            return s > sr;
        if (s > 0)
            return IsGreater(m_digits, rv.m_digits);
        else
            return IsGreater(rv.m_digits, m_digits);
    }

    bool operator<=(const BigInteger& rv) const
    {
        return !this->operator>(rv);
    }

    bool operator>=(const BigInteger& rv) const
    {
        return !this->operator<(rv);
    }

    BigInteger operator-() const
    {
        BigInteger mv(m_digits, m_digits.empty() ? false : !id9);
        return mv;
    };

    BigInteger& operator+=(const BigInteger& rv)
    {
        if (rv.Sign() == 0)
            return *this;

        if (Sign() == rv.Sign())
        {
            ImplaceAdd(m_digits, rv.m_digits);
        }
        else 
        {
            if (!IsLess(m_digits, rv.m_digits))
            {
                ImplaceSubtract(m_digits, rv.m_digits);
            }
            else
            {
                vector_digits_t rvd(rv.m_digits);
                ImplaceSubtract(rvd, m_digits);
                m_digits.swap(rvd);
                id9 = rv.id9;
            }
        }

        if (m_digits.empty())
            id9 = false;

        return *this;
    }
    
    BigInteger& operator-=(const BigInteger& rv)
    {
        if (rv.Sign() == 0)
            return *this;

        if (Sign() == 0)
        {
            m_digits = rv.m_digits;
            id9 = !rv.id9;
        }
        else if (Sign() == rv.Sign())
        {
            if (!IsLess(m_digits, rv.m_digits))
            {
                ImplaceSubtract(m_digits, rv.m_digits);
            }
            else
            {
                vector_digits_t rvd(rv.m_digits);
                ImplaceSubtract(rvd, m_digits);
                m_digits.swap(rvd);
                id9 = !id9;
            }

            if (m_digits.empty())
                id9 = false;
        }
        else
        {
            ImplaceAdd(m_digits, rv.m_digits);
        }

        return *this;
    }

    BigInteger& operator*=(const BigInteger& rv)
    {
        vector_digits_t absRes = Multiply(this->m_digits, rv.m_digits);
        id9 = absRes.empty() ? false : (this->id9 ^ rv.id9);
        m_digits.swap(absRes);
        return *this;
    }

    BigInteger& operator/=(const digit_t d)
    {
        LOCAL_ASSERT(d != 0 && d < Base);
        ImplaceDivideDigit(m_digits, d);
        Normalize();
        return *this;
    }

    BigInteger& operator/=(const BigInteger& rv)
    {
        LOCAL_ASSERT(rv.IsNormalized());
        LOCAL_ASSERT(rv.Sign() != 0);

        vector_digits_t div;
        vector_digits_t rem;
        Divide(this->m_digits, rv.m_digits, div, rem);
        id9 = div.empty() ? false : (this->id9 ^ rv.id9);
        m_digits.swap(div);
        return *this;
    }

    BigInteger& operator%=(const digit_t d)
    {
        LOCAL_ASSERT(d != 0 && d < Base);
        const digit_t rem = GetRemainder(m_digits, d);
        InitFromValue(rem, m_digits);
        Normalize();
        return *this;
    }

    BigInteger& operator%=(const BigInteger& rv)
    {
        LOCAL_ASSERT(rv.IsNormalized());
        LOCAL_ASSERT(rv.Sign() != 0);

        vector_digits_t div;
        vector_digits_t rem;
        Divide(this->m_digits, rv.m_digits, div, rem);
        id9 = rem.empty() ? false : this->id9;
        m_digits.swap(rem);
        return *this;
    }

    string8_t ToString() const
    {
        if (m_digits.empty())
            return string8_t("0");

        std::ostringstream ostr;
        if (id9)
            ostr << "-";
        ostr << std::setfill('0');
        for (typename vector_digits_t::const_reverse_iterator pd = m_digits.rbegin(); pd != m_digits.rend(); ++pd)
        {           
            if (pd != m_digits.rbegin())
                ostr << std::setw(BaseLength);
            ostr << *pd;
        }

        return ostr.str();
    }

private:
    template<typename T>
    BigInteger& id0(const T& rv)
    {
        BigInteger v(rv);
        this->Swap(v);
        return *this;
    }

    void Normalize()
    {
        Normalize(m_digits);
        if (m_digits.empty())
            id9 = false;
    }

    bool IsNormalized() const
    {
        if (!IsNormalized(m_digits))
            return false;
        if (m_digits.empty() && id9)
            return false;
        return true;
    }

    

    static bool IsNormalized(const vector_digits_t& digits)
    {
        if (digits.empty())
            return true;
        const digit_t firstDigit = *digits.rbegin();
        return firstDigit != 0;
    }

    static void Normalize(vector_digits_t& digits)
    {
        while (!digits.empty() && (*digits.rbegin() == 0))
            digits.pop_back();
    }

    template<typename iterator_type_t>
    static digit_t id10(const iterator_type_t sBegin, const iterator_type_t sEnd)
    {
        LOCAL_ASSERT(std::distance(sBegin, sEnd) <= BaseLength);
        digit_t digit = 0;
        for (iterator_type_t p = sBegin; p != sEnd; ++p)
        {
            digit *= 10;
            LOCAL_ASSERT(*p >= '0' && *p <= '9')
            digit += (digit_t)(*p - '0');
        }
        return digit;
    }

    template<typename iterator_type_t>
    static void id1(const iterator_type_t sBegin, const iterator_type_t sEnd, vector_digits_t& digits)
    {
        digits.clear();
        iterator_type_t pFirst = sBegin;
        while ((pFirst != sEnd) && (*pFirst == '0'))
            ++pFirst;

        const size_t charsCount = std::distance(pFirst, sEnd);
        const size_t tailSize = charsCount % BaseLength;
        size_t digitsCount = (charsCount + BaseLength - 1) / BaseLength;
        
        digits.resize(digitsCount);
        
        iterator_type_t id11 = pFirst;
        if (tailSize != 0)
        {
            digits[digitsCount - 1] = id10(id11, id11 + tailSize);
            id11 += tailSize;
            digitsCount--;
        }

        while (digitsCount > 0)
        {
            LOCAL_ASSERT(id11 + BaseLength <= sEnd);
            digits[digitsCount - 1] = id10(id11, id11 + BaseLength);
            id11 += BaseLength;
            digitsCount--;
        }
    }

    template<typename iterator_type_t>
    static void id3(const iterator_type_t sBegin, const iterator_type_t sEnd, bool& isNegative, vector_digits_t& digits)
    {
        isNegative = false;
        digits.clear();
        if (sBegin == sEnd)
            return;

        iterator_type_t id2 = sBegin;
        if (*id2 == '-')
        {
            isNegative = true;
            ++id2;
        }
        else if (*id2 == '+')
        {
            ++id2;
        }

        id1(id2, sEnd, digits);
    }

    static void InitFromValue(const uint64_t& val, vector_digits_t& digits)
    {
        digits.clear();
        uint64_t v = val;
        while (v != 0)
        {
            digits.push_back((digit_t)(v % Base));
            v /= Base;
        }
    }

    static void InitFromValue(const int64_t& val, bool& isNegative, vector_digits_t& digits)
    {
        isNegative = false;
        if (val < 0)
        {
            isNegative = true;
            const uint64_t absVal = (val != std::numeric_limits<int64_t>::min()) ? 
                (uint64_t)(-val) : 
                ((uint64_t)std::numeric_limits<int64_t>::max() + 1);
            InitFromValue(absVal, digits);
        }
        else
        {
            InitFromValue((uint64_t)val, digits);
        }
    }

    static bool IsEqual(const vector_digits_t& a, const vector_digits_t& b)
    {
        LOCAL_ASSERT(IsNormalized(a) && IsNormalized(b));
        return a == b;
    }

    static bool IsLess(const vector_digits_t& a, const vector_digits_t& b)
    {
        LOCAL_ASSERT(IsNormalized(a) && IsNormalized(b));
        if (a.size() != b.size())
            return a.size() < b.size();
        typename vector_digits_t::const_reverse_iterator pa = a.rbegin();
        typename vector_digits_t::const_reverse_iterator pb = b.rbegin();
        while (pa != a.rend())
        {
            if (*pa != *pb)
                return *pa < *pb;
            ++pa;
            ++pb;
        }
        return false;
    }

    static bool IsGreater(const vector_digits_t& a, const vector_digits_t& b)
    {
        LOCAL_ASSERT(IsNormalized(a) && IsNormalized(b));
        if (a.size() != b.size())
            return a.size() > b.size();
        typename vector_digits_t::const_reverse_iterator pa = a.rbegin();
        typename vector_digits_t::const_reverse_iterator pb = b.rbegin();
        while (pa != a.rend())
        {
            if (*pa != *pb)
                return *pa > *pb;
            ++pa;
            ++pb;
        }
        return false;
    }

    static void ImplaceAdd(vector_digits_t& a, const vector_digits_t& b)
    {
        LOCAL_ASSERT(IsNormalized(a) && IsNormalized(b));
        if (a.size() < b.size())
            a.resize(b.size());
        
        digit_t c = 0;
        for (size_t i = 0; i < a.size(); i++)
        {
            const digit_t d = i < b.size() ? b[i] : 0;
            digit_t s = a[i] + d + c;
            c = 0;
            if (s >= Base)
            {
                s -= Base;
                LOCAL_ASSERT(s < Base);
                c = 1;
            }
            a[i] = s;

            if ((c == 0) && (i >= b.size()))
                break;
        }

        if (c != 0)
            a.push_back(c);
    }

    static void ImplaceSubtract(vector_digits_t& a, const vector_digits_t& b)
    {
        LOCAL_ASSERT(IsNormalized(a) && IsNormalized(b));
        LOCAL_ASSERT(!IsLess(a, b));
        
        int32_t br = 0;
        for (size_t i = 0; i < a.size(); i++)
        {
            const digit_t d = i < b.size() ? b[i] : 0;
            int32_t s = (int32_t)a[i] - (int32_t)d - br;
            br = 0;
            if (s < 0)
            {
                br = 1;
                s += Base;
            }
            a[i] = s;

            if ((br == 0) && i >= b.size())
                break;
        }

        Normalize(a);
    }

    static vector_digits_t Multiply(const vector_digits_t& a, const vector_digits_t& b)
    {
        LOCAL_ASSERT(IsNormalized(a) && IsNormalized(b));
        
        vector_digits_t r(a.size() + b.size());
        for (size_t i = 0; i < a.size(); i++)
        {
            const digit_t da = a[i];
            digit_t c = 0;
            for (size_t j = 0; j < b.size() || c; j++)
            {
                const digit_t db = (j < b.size() ? b[j] : 0);
                digit_t& dc = r[i + j];
                const uint64_t r = dc + (uint64_t)da * db + c;
                dc = (digit_t)(r % Base);
                c = (digit_t)(r / Base);
            }
        }

        Normalize(r);
        return r;
    }

    static void ImplaceDivideDigit(vector_digits_t& a, const digit_t b)
    {
        LOCAL_ASSERT(IsNormalized(a));
        LOCAL_ASSERT(b != 0 && b < Base);
        digit_t c = 0;
        for (size_t i = 0; i < a.size(); i++)
        {
            digit_t& da = a[a.size() - 1 - i];
            const uint64_t r = (uint64_t)c * Base + da;
            da = (digit_t)(r / b);
            c = (digit_t)(r % b);
        }
        Normalize(a);
    }

    static digit_t GetRemainder(const vector_digits_t& a, const digit_t b)
    {
        LOCAL_ASSERT(IsNormalized(a));
        LOCAL_ASSERT(b != 0 && b < Base);
        digit_t c = 0;
        for (size_t i = 0; i < a.size(); i++)
        {
            const digit_t& da = a[a.size() - 1 - i];
            const uint64_t r = (uint64_t)c * Base + da;
            c = (digit_t)(r % b);
        }
        return c;
    }

    static void Divide(const vector_digits_t& a, const vector_digits_t& b, vector_digits_t& div, vector_digits_t& rem)
    {
        vector_digits_t One;
        One.push_back(1);

        

        vector_digits_t l; 
        vector_digits_t r = a;
        ImplaceAdd(r, One);

        

        while (IsLess(l, r))
        {
            

            vector_digits_t m(r);
            ImplaceSubtract(m, l);
            ImplaceDivideDigit(m, 2);
            ImplaceAdd(m, l);

            const vector_digits_t mult = Multiply(m, b);
            if (IsLess(a, mult))
            {
                r = m;
            }
            else
            {
                l = m;
                ImplaceAdd(l, One);
            }
        }

        ImplaceSubtract(l, One);
        div.swap(l);
        
        rem = a;
        const vector_digits_t mult = Multiply(div, b);
        LOCAL_ASSERT(!IsLess(rem, mult));
        ImplaceSubtract(rem, mult);
    }

    

    vector_digits_t m_digits;
    bool id9;
};

template<uint32_t Base>
inline BigInteger<Base> operator+(const BigInteger<Base>& lv, const BigInteger<Base>& rv)
{
    BigInteger<Base> z(lv); z += rv; return z;
}
template<uint32_t Base>
inline BigInteger<Base> operator+(const BigInteger<Base>& lv, const uint64_t rv)
{
    BigInteger<Base> z(lv); z += BigInteger<Base>(rv); return z;
}


template<uint32_t Base>
inline BigInteger<Base> operator-(const BigInteger<Base>& lv, const BigInteger<Base>& rv)
{
    BigInteger<Base> z(lv); z -= rv; return z;
}

template<uint32_t Base>
inline BigInteger<Base> operator*(const BigInteger<Base>& lv, const BigInteger<Base>& rv)
{
    BigInteger<Base> z(lv); z *= rv; return z;
}

template<uint32_t Base>
inline BigInteger<Base> operator*(const BigInteger<Base>& lv, const uint64_t rv)
{
    BigInteger<Base> z(lv); z *= BigInteger<Base>(rv); return z;
}

template<uint32_t Base>
inline BigInteger<Base> operator/(const BigInteger<Base>& lv, const BigInteger<Base>& rv)
{
    BigInteger<Base> z(lv); z /= rv; return z;
}

template<uint32_t Base>
inline BigInteger<Base> operator%(const BigInteger<Base>& lv, const BigInteger<Base>& rv)
{
    BigInteger<Base> z(lv); z %= rv; return z;
}

template<uint32_t Base>
inline BigInteger<Base> operator/(const BigInteger<Base>& lv, const typename BigInteger<Base>::digit_t d)
{
    BigInteger<Base> z(lv); z /= d; return z;
}

template<uint32_t Base>
inline BigInteger<Base> operator%(const BigInteger<Base>& lv, const typename BigInteger<Base>::digit_t d)
{
    BigInteger<Base> z(lv); z %= d; return z;
}

typedef BigInteger<1000000000> BigIntegerG;

struct ans_t
{
    ans_t(): n(0), m(0) { }
    ans_t(const uint64_t n_, const uint64_t m_): n(n_), m(m_) { }

    bool operator<(const ans_t& rv) const
    {
        if (n != rv.n)
            return n < rv.n;
        return m < rv.m;
    }

    uint64_t n;
    uint64_t m;
};

typedef std::set<ans_t> set_ans_t;

const uint64_t Inf = std::numeric_limits<uint64_t>::max();
const uint64_t Limit = 2642000;

uint64_t GetCount(uint64_t n, uint64_t m)
{
    if (n > m)
        std::swap(n, m);

    const BigIntegerG vn((uint64_t)n);
    const BigIntegerG vm((uint64_t)m);

    BigIntegerG va = vn * vn * vm + vn * vm + vn * (vn + 1) * (vn * 2 + 1) / 6 - (vn + vm) * vn * (vn + 1) / 2;
    if (va > BigIntegerG(Inf))
        return Inf;
    uint64_t ans = va.id7<uint64_t>();
    return ans;
}

template<typename ArgType, typename ResultType, typename Func>
ArgType LowerBound(const ArgType& firstX, const ArgType& lastX, const ResultType& y, const Func& func)
{
    ArgType l = firstX;
    ArgType r = lastX;

    while (l < r)
    {
        const ArgType m = l + (r - l) / 2;
        if (func(m) < y)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }

    return l;
}

bool Solve(std::istream& ist, std::ostream& ost, const bool id6)
{
    StopWatch<1> sw; (void)sw;

    

    uint64_t x;
    ist >> x;

    if (id6 && !ist)
        return false;


    ost << std::endl << "Next test" << std::endl;


    set_ans_t answers;

    for (uint64_t n = 1; n <= Limit; n++)
    {
        if ((6 * x) % n != 0)
            continue;

        const uint64_t lowVal = LowerBound(1ULL, x + 1, true, [&](const uint64_t m) -> bool
        {
            const uint64_t cnt = GetCount(n, m);
            return cnt >= x;
        });

        if (GetCount(n, lowVal) == x)
        {
            answers.insert(ans_t(n, lowVal));
            answers.insert(ans_t(lowVal, n));
        }
    }

    ost << answers.size() << std::endl;
    for (set_ans_t::const_iterator pa = answers.begin(); pa != answers.end(); ++pa)
    {
        ost << pa->n <<  ' ' << pa->m << "\n";
    }
    
    return id6;
}



void Test()
{
    using namespace library::random;
    const auto genVector = GenFactory::CreateGenVector(GenRange<size_t>(2, 10), GenRange<int32_t>(-100, +200));

    for (size_t t = 0; t < 10; t++)
    {
        const vector_int32_t data = genVector();
        

    }
}


int main(int argc, const char *argv[])
{

    Test();


    std::ios_base::sync_with_stdio(false);
    std::istream* ist = &std::cin;
    std::ostream* ost = &std::cout;
    
    std::unique_ptr<std::istream> fileInput;
    
    if (argc > 1)
    {
        fileInput.reset(new std::ifstream(argv[1]));
        if (!(*fileInput))
        {
            std::cout << "File not found: " << argv[1] << std::endl;
        }
        ist = fileInput.get();
    }    
    

    Solve(*ist, *ost, false);

    while(Solve(*ist, *ost, true)) {};

}