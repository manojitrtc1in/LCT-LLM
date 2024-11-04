





















typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed long int32_t;
typedef unsigned long uint32_t;
typedef signed long long int64_t;
typedef unsigned long long uint64_t;




namespace stdext = __gnu_cxx;
















typedef long double double_t;
typedef std::string string8_t;

typedef std::vector<size_t> vector_size_t;
typedef std::vector<uint64_t> vector_uint64_t;
typedef std::vector<int32_t> vector_int32_t;
typedef std::vector<vector_size_t> vector_2d_size_t;
typedef std::vector<string8_t> vector_string8_t;
typedef std::set<size_t> set_size_t;
typedef std::set<string8_t> set_string8_t;
typedef stdext::hash_set<size_t> hash_set_size_t;
typedef std::multiset<string8_t> multiset_string8_t;





template<typename T> inline T Abs(const T a) { return a < 0 ? -a : a; }
template<typename T> inline T Min(const T a, const T b) {return a < b ? a : b;}
template<typename T> inline T Max(const T a, const T b) {return a > b ? a : b;}
template<typename T> inline void UpdateMin(T& a, const T b) {a = Min(a, b);}
template<typename T> inline void UpdateMax(T& a, const T b) {a = Max(a, b);}

static const double_t eps = 1.0e-09;
template<typename T> inline bool IsEqual(const T a, const T b) { return Abs(a - b) < eps; }
template<typename T> inline bool IsGreater(const T a, const T b) { return a > b + eps; }
template<typename T> inline bool IsLess(const T a, const T b) { return a + eps < b; }

template<typename T> inline string8_t ToStr(const T& val) { std::ostringstream ostr; ostr << val; return ostr.str(); }
template<typename T> inline bool FromStr(const string8_t& str, T& val) {std::istringstream istr(str); istr >> val; return !!istr; }


template<size_t id> class StopWatch { };






typedef std::vector<uint32_t> vector_uint32_t;

struct id3
{
    uint32_t mod;
    uint32_t base;
    uint32_t baseRev;
    vector_uint32_t basePows;
    vector_uint32_t basePowsRev;

    id3(const size_t maxLength, const uint32_t hashMod = 0x7FFFFFFF, const uint32_t hashBase = 53):
    mod(hashMod),
        base(hashBase),
        baseRev( 1823335172), 

        basePows(GetPows(maxLength, hashBase)),
        basePowsRev(GetPows(maxLength, baseRev))
    {
    }

    static uint32_t GetReverseElement(const uint32_t mod, const uint32_t elem)
    {
        for (uint64_t i = 0; i < mod; i++)
        {
            uint64_t r = i * elem;
            r %= mod;
            if (r == 1)
                return (uint32_t)i;
        }
        return 0;
    }

    vector_uint32_t GetPows(const size_t maxPower, const uint32_t base)
    {
        vector_uint32_t pows(maxPower + 1);
        pows[0] = 1;
        for (size_t i = 1; i <= maxPower; i++)
        {
            const uint64_t v = (uint64_t)pows[i - 1] * base;
            pows[i] = (uint32_t)(v % mod);
        }
        return pows;
    }
};

class id0
{
public:
    id0(): m_hashes(1)
    { 
    }

    id0(const string8_t& s): m_hashes(1) 
    { 
        Append(s);
    }

    const string8_t& GetValue() const
    {
        return m_value;
    }

    const uint32_t GetHash() const
    {
        return m_hashes[m_value.size()];
    }

    const uint32_t GetPartHash(const size_t i, const size_t len) const
    {
        LOCAL_ASSERT(i + len <= m_value.size());
        const uint32_t fullHash = m_hashes[i + len];
        const uint32_t prefixHash = m_hashes[i];

        const uint64_t diffHash = (fullHash + (gData.mod - prefixHash)) % gData.mod;
        const uint32_t res = (uint32_t)((diffHash * gData.basePowsRev[i]) % gData.mod);
        return res;
    }

    const uint32_t GetTailHash(size_t i) const
    {
        LOCAL_ASSERT(i < m_value.size());
        return GetPartHash(i, m_value.size() - i);
    }

    void Append(const char ch)
    {
        const size_t n = m_value.size();
        const uint32_t prevHash = m_hashes[n];
        const uint32_t charPow = gData.basePows[n];
        const uint64_t charHash = (uint64_t)(ch - 'a' + 1) * charPow;
        const uint64_t newHash = (charHash + prevHash) % gData.mod;

        LOCAL_ASSERT(newHash < gData.mod);      
        m_value.push_back(ch);
        m_hashes.push_back((uint32_t)newHash);
    }

    void Append(const string8_t& str)
    {
        for (size_t i = 0; i < str.size(); i++)
        {
            Append(str[i]);
        }
    }

    void PopBack(const size_t charCount)
    {
        const size_t n = m_value.size();
        LOCAL_ASSERT(n + 1 == m_hashes.size());

        LOCAL_ASSERT(charCount <= n);

        m_value.resize(n - charCount);
        m_hashes.resize(n + 1 - charCount);
    }

    bool IsTailEqualTo(const id0& rv) const
    {
        const size_t n = m_value.size();
        const size_t rvSize = rv.GetValue().size();

        if (n < rvSize)
            return false;

        const size_t tailStart = n - rvSize;
        const uint32_t tailHash = GetTailHash(tailStart);
        const uint32_t rvHash = rv.GetHash();

        LOCAL_ASSERT(GetPartHash(tailStart, rvSize) == tailHash);

        if (tailHash != rvHash)
        {
            LOCAL_ASSERT((GetValue().substr(tailStart) != rv.GetValue()));
            return false;
        }

        const size_t id4 = 6;
        for (size_t partsCount = 2; partsCount <= id4; partsCount++)
        {
            const size_t partSize = rvSize / partsCount;
            if (partSize == 0)
                break;

            for (size_t i = 0; i + partSize <= rvSize; i += partSize)
            {
                const uint32_t id9 = GetPartHash(tailStart + i, partSize);
                const uint32_t id5 = rv.GetPartHash(i, partSize);
                if (id9 != id5)
                {
                    LOCAL_ASSERT((GetValue().substr(tailStart + i, partSize) != rv.GetValue().substr(i, partSize)));
                    return false;
                }
            }

            for (size_t i = rvSize % partSize; i + partSize <= rvSize; i += partSize)
            {
                const uint32_t id9 = GetPartHash(tailStart + i, partSize);
                const uint32_t id5 = rv.GetPartHash(i, partSize);
                if (id9 != id5)
                {
                    LOCAL_ASSERT((GetValue().substr(tailStart + i, partSize) != rv.GetValue().substr(i, partSize)));
                    return false;
                }
            }
        }

        LOCAL_ASSERT((GetValue().substr(tailStart) == rv.GetValue()));
        return true;
    }

    size_t GetSize() const
    {
        return m_value.size();
    }

private:
    static const id3 gData;
    string8_t m_value;
    vector_uint32_t m_hashes;
};

const id3 id0::gData(3000);

struct rule_t
{
    string8_t s;
    id0 hs;
    size_t a;
    size_t b;

    rule_t()
    {
        a = b = 0;
    }
};

typedef std::vector<rule_t> vector_rule_t;

bool id1(const string8_t& ss, const rule_t& rule)
{
    const string8_t& p = rule.s;

    size_t count = 0;
    size_t pos = 0;
    while (pos < p.size())
    {
        pos = p.find(ss, pos);
        if (pos == std::string::npos)
            break;
        pos += 1;
        count += 1;

        if (count > rule.b)
            return false;
    }

    return count >= rule.a && count <= rule.b;
}

uint64_t id6(const string8_t& s, const vector_rule_t& rules)
{
    set_string8_t ans;
    for (size_t i = 0; i < s.size(); i++)
    {
        for (size_t j = i; j < s.size(); j++)
        {
            bool isOk = true;
            const string8_t& ss = s.substr(i, j + 1 - i);
            for (size_t r = 0; r < rules.size(); r++)
            {
                if (!id1(ss, rules[r]))
                {
                    isOk = false;
                    break;
                }
            }

            if (isOk)
            {
                ans.insert(ss);
            }
        }
    }

    return ans.size();
}

struct triple_hash_t
{
    uint32_t h1;
    uint32_t h2;



    bool operator<(const triple_hash_t& rv) const
    {
        if (h1 < rv.h1)
            return true;
        if (h1 > rv.h1)
            return false;

        if (h2 < rv.h2)
            return true;
        if (h2 > rv.h2)
            return false;





        return false;
    }

    bool operator==(const triple_hash_t& rv) const
    {
        return h1 == rv.h1 && h2 == rv.h2;
    }
};

namespace stdext
{

    size_t hash_value(const triple_hash_t& _Keyval)
    {   

        return _Keyval.h1 ^ _Keyval.h2 ;
    }
}

namespace std
{

template<>
class hash<triple_hash_t>
    : public std::unary_function<triple_hash_t, size_t>
{   

public:
    size_t operator()(const triple_hash_t& _Keyval) const
    {
        return _Keyval.h1 ^ _Keyval.h2 ;
    }
};

}






typedef std::unordered_set<triple_hash_t> hash_set_triple_hash_t;
typedef std::unordered_map<triple_hash_t, uint32_t> hash_map_triple_hash_t;

typedef std::vector<hash_map_triple_hash_t> vector_hash_map_triple_hash_t;

bool IsOk(const size_t len, const rule_t& rule, const triple_hash_t& th)
{
    uint32_t count = 0;
    for (size_t i = 0; i + len <= rule.s.size(); i++)
    {
        if (rule.hs.GetPartHash(i, len) != th.h1)
            continue;
        if (rule.hs.GetPartHash(i, len / 2) != th.h2)
            continue;





        count += 1;
        if (count > rule.b)
            return false;
    }

    return count >= rule.a && count <= rule.b;
}

bool id2(const triple_hash_t& th, const hash_map_triple_hash_t& hm, uint32_t a, uint32_t b)
{
    uint32_t count = 0;
    hash_map_triple_hash_t::const_iterator pi = hm.find(th);
    if (pi != hm.end())
    {
        count = pi->second;
    }

    return count >= a && count <= b;
}

uint64_t GetCount(const id0& hs, const vector_rule_t& rules)
{
    hash_set_triple_hash_t id10(1UL << 22);




    for (size_t i = 0; i < hs.GetSize(); i++)
    {
        for (size_t j = i; j < hs.GetSize(); j++)
        {
            
            const size_t b = i;
            const size_t len = j + 1 - i;

            triple_hash_t th;
            th.h1 = hs.GetPartHash(b, len);
            th.h2 = hs.GetPartHash(b, len / 2);



            if (id10.find(th) != id10.end())
                continue;

            id10.insert(th);
        }
    }

    for (size_t r = 0; r < rules.size(); r++)
    {
        const uint32_t a = rules[r].a;
        const uint32_t b = rules[r].b;
        const id0& rh = rules[r].hs;

        hash_map_triple_hash_t hHashes(1UL << 22);
        for (size_t b = 0; b < rh.GetSize(); b++)
        {
            for (size_t len = 1; b + len <= rh.GetSize(); len++)
            {
                triple_hash_t th;
                th.h1 = rh.GetPartHash(b, len);
                th.h2 = rh.GetPartHash(b, len / 2);


                hHashes[th] += 1;
            }
        }

        for (hash_set_triple_hash_t::const_iterator pi = id10.begin(); pi != id10.end();)
        {
            const triple_hash_t& th = *pi;
            if (!id2(th, hHashes, a, b))
            {
                id10.erase(pi++);
                continue;
            }
            ++pi;
        }
    }

    return id10.size();
}

bool Solve(std::istream& ist, std::ostream& ost, const bool id8)
{
    StopWatch<1> sw;

    

    string8_t s;
    ist >> s;

    if (id8 && !ist)
        return false;

    

    size_t n;
    ist >> n;

    vector_rule_t rules(n);
    for (size_t i = 0; i < n; i++)
    {
        ist >> rules[i].s >> rules[i].a >> rules[i].b;
        rules[i].hs.Append(rules[i].s);
    }

    id0 hs(s);
    const uint64_t ans = GetCount(hs, rules);

    

    



    ost << ans << std::endl;

    return id8;
}

string8_t id7(const size_t sz)
{
    string8_t s(sz, 'a');
    for (size_t i = 0; i < sz; i++)
    {
        s[i] = 'a' + rand() % 26;
    }
    return s;
}

void GenTest()
{
    const size_t testCount = 5;
    const size_t maxSize = 2000;

    std::ostream& ost = std::cout;

    for (size_t t = 0; t < testCount; t++)
    {
        const size_t sz = maxSize - rand() % 20;
        ost << id7(sz) << std::endl;
        ost << 10 << std::endl;
        for (size_t r = 0; r < 10; r++)
        {
            ost << id7(sz + r + 1) << ' ' << r << ' ' << 10 << std::endl;
        }
        ost << std::endl;
    }
};

int main()
{

    srand(0);



    std::ios_base::sync_with_stdio(false);
    std::istream& ist = std::cin;
    std::ostream& ost = std::cout;

    Solve(ist, ost, false);

    while(Solve(ist, ost, true)) {};

}
