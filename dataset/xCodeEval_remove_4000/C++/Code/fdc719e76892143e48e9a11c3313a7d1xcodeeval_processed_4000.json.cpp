







































struct id3
{
    id3(): counter(0) {}
    ~id3() { std::cout << std::endl << "DIAG: " << (counter == 0 ? "OK" : "FAIL!!!") << " Asserts count: " << counter << std::endl; }
    void Increment() { counter++; }
    uint32_t counter;
};
id3 id6;



volatile bool id11 = 0;




bool id0 = (bool)(LOCAL_TEST);



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

const ld_t Pi = std::atan(1.0L) * 4.0L;
static const ld_t Eps = 1.0e-09;
template<typename T> bool IsEqual(const T a, const T b) { return std::abs(a - b) < Eps; }
template<typename T> bool IsGreater(const T a, const T b) { return a > b + Eps; }
template<typename T> bool IsLess(const T a, const T b) { return a + Eps < b; }
template<typename T> bool id10(const T a, const T b) { return !IsLess(a, b); }
template<typename T> bool id8(const T a, const T b) { return !IsGreater(a, b); }

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



library::random::Rand id4;


template<typename T>
struct SumFunc
{
    typedef T value_type_t;
    value_type_t Add(const value_type_t& l, const value_type_t& r) const { return l + r; }
    value_type_t Subtract(const value_type_t& l, const value_type_t& r) const { return l - r; }
    value_type_t GetZero() const { return 0; }
};

template<typename T, typename FuncType>
class id13
{
public:
    typedef T value_type_t;

    explicit id13(const FuncType& func = FuncType()): m_func(func) { }
    explicit id13(const size_t n, const FuncType& func = FuncType()): m_func(func), m_data(n, func.GetZero()) { }

    size_t GetSize() const { return m_data.size(); }

    void Update(const size_t idx, const value_type_t& val)
    {
        size_t i = idx;
        while (i < m_data.size())
        {
            m_data[i] = m_func.Add(m_data[i], val);
            i |= (i + 1);
        }
    }

    value_type_t Get(const size_t id12) const
    {
        value_type_t res = m_func.GetZero();
        size_t rem = id12;
        while (rem != 0)
        {
            rem -= 1;
            LOCAL_ASSERT(rem < m_data.size());
            res = m_func.Add(res, m_data[rem]);
            rem &= (rem + 1);
        }
        return res;
    }

    value_type_t Get(const size_t l, const size_t r) const
    {
        return m_func.Subtract(Get(r), Get(l));
    }

    void PushBack(const value_type_t& val)
    {
        const size_t idx = GetSize();
        const value_type_t prefSum = m_func.Subtract(Get(idx), Get(idx & (idx + 1))); 

        m_data.push_back(m_func.Add(prefSum, val));
    }

    void PopBack()
    {
        m_data.pop_back();
    }
    
private:
    const FuncType m_func;
    std::vector<value_type_t> m_data;
};

typedef id13<int32_t, SumFunc<int32_t> > FenwickTreeSum32;

struct point_t
{
    point_t() { x = y = 0; } 

    bool operator<(const point_t& rv) const
    {
        if (x != rv.x)
            return x < rv.x;
        return y < rv.y;
    }

    int32_t x;
    int32_t y;
};

struct range_t
{
    range_t() { b = e = 0; }
    range_t(int32_t b_, int32_t e_): b(b_), e(e_) { }

    bool operator<(const range_t& rv) const
    {
        return b < rv.b;
    }

    int32_t b;
    int32_t e;
};

typedef std::vector<range_t> vector_range_t;
typedef std::map<int32_t, vector_range_t> map_ranges_t;


struct op_t
{
    op_t(int32_t x_, int32_t d_): x(x_), d(d_) { }

    bool operator<(const op_t& rv) const
    {
        if (x != rv.x)
            return x < rv.x;

        return d > rv.d;
    }

    int32_t x;
    int32_t d;
};

typedef std::vector<op_t> vector_op_t;

vector_range_t Unite(const vector_range_t& ranges)
{
    vector_op_t ops;
    for(size_t i = 0; i < ranges.size(); i++)
    {
        ops.push_back(op_t(ranges[i].b, +1));
        ops.push_back(op_t(ranges[i].e, -1));
    }
    std::sort(ops.begin(), ops.end());

    vector_range_t newRanges;

    size_t i = 0;
    while (i < ops.size())
    {
        int32_t s = 0;
        LOCAL_ASSERT(ops[i].d == 1);
        int32_t xb = ops[i].x;
        int32_t xe = xb;
        do
        {
            s += ops[i].d;
            xe = ops[i].x;
            LOCAL_ASSERT(i < ops.size());
            i++;
        } while(s != 0);

        newRanges.push_back(range_t(xb, xe));
    }

    return newRanges;
}

uint64_t id9(const map_ranges_t& rs)
{
    uint64_t ans = 0;
    for (map_ranges_t::const_iterator p = rs.begin(); p != rs.end(); ++p)
    {
        const vector_range_t& v = p->second;
        for (size_t i = 0; i < v.size(); i++)
        {
            LOCAL_ASSERT(v[i].e > v[i].b);
            ans += v[i].e - v[i].b;
        }
    }
    return ans;
}

size_t IndexOf(const vector_int32_t& coords, const int32_t x)
{
    const size_t i = std::lower_bound(coords.begin(), coords.end(), x) - coords.begin();
    LOCAL_ASSERT(i < coords.size());
    LOCAL_ASSERT(coords[i] == x);


    return i;
}

vector_range_t id14(const vector_int32_t& coords, const vector_range_t& ranges)
{
    vector_range_t cr;
    for (size_t i = 0; i < ranges.size(); i++)
    {
        cr.push_back(range_t(IndexOf(coords, ranges[i].b), IndexOf(coords, ranges[i].e)));
    }
    return cr;
}

struct id2
{
    id2(int32_t x_, int32_t y_, int32_t d_): x(x_), d(d_), y(y_) { }
    id2(int32_t y_, const range_t& range_): x(0), d(0), y(y_), r(range_) { }

    static int32_t ToOrder(const int32_t d)
    {
        if (d == 1)
            return 0;
        if (d == -1)
            return 1;
        return 2;
    }

    bool operator<(const id2& rv) const
    {
        if (y != rv.y)
            return y < rv.y;

        return ToOrder(d) < ToOrder(rv.d);
    }

    int32_t x;
    int32_t d;
    int32_t y;
    range_t r;
};

typedef std::vector<id2> vector_op_ex_t;


uint64_t id7(const map_ranges_t& vc, const map_ranges_t& hc)
{
    uint64_t ans = 0;
    for (map_ranges_t::const_iterator pv = vc.begin(); pv != vc.end(); ++pv)
    {
        const int32_t x1 = pv->first;
        for (size_t i = 0; i < pv->second.size(); i++)
        {
            const range_t yr1 = pv->second[i];

            for (map_ranges_t::const_iterator ph = hc.begin(); ph != hc.end(); ++ph)
            {
                const int32_t y2 = ph->first;
                for (size_t j = 0; j < ph->second.size(); j++)
                {
                    const range_t xr2 = ph->second[j];

                    if (x1 < xr2.b || x1 >= xr2.e)
                        continue;
                    if (y2 < yr1.b || y2 >= yr1.e)
                        continue;
                    ans++;

                    LOCAL_PRINT() << " -> V " << x1 << "[" << yr1.b << "," << yr1.e << "] vs H " << y2 << "[" << xr2.b << "," << xr2.e << "]" << std::endl;
                }
            }
        }
    }
    return ans;
}


uint64_t id1(const map_ranges_t& vc, const map_ranges_t& hc)
{
    int32_t xMax = 0;

    vector_op_ex_t ops;
    for (map_ranges_t::const_iterator pv = vc.begin(); pv != vc.end(); ++pv)
    {
        const int32_t x = pv->first;
        const vector_range_t& rs = pv->second;
        for (size_t i = 0; i < rs.size(); i++)
        {
            ops.push_back(id2(x, rs[i].b, +1));
            ops.push_back(id2(x, rs[i].e, -1));
            UpdateMax(xMax, x + 1);
        }
    }

    for (map_ranges_t::const_iterator ph = hc.begin(); ph != hc.end(); ++ph)
    {
        const int32_t y = ph->first;
        const vector_range_t& rs = ph->second;
        for (size_t i = 0; i < rs.size(); i++)
        {
            ops.push_back(id2(y, rs[i]));
            UpdateMax(xMax, rs[i].b);
            UpdateMax(xMax, rs[i].e);
        }
    }

    std::sort(ops.begin(), ops.end());


    const uint64_t ansRef = id7(vc, hc);


    uint64_t ans = 0;
    FenwickTreeSum32 tr((size_t)(xMax + 1));

    for (size_t i = 0; i < ops.size(); i++)
    {
        const id2& op = ops[i];
        if (op.d == 0)
        {
            const int32_t delta = tr.Get(op.r.b, op.r.e);
            LOCAL_PRINT() << " -> H " << op.y << "[" << op.r.b << "," << op.r.e << "] has " << delta << " ints" << std::endl;
            ans += delta;
        }
        else
        {
            LOCAL_ASSERT(op.d == -1 || op.d == +1);
            tr.Update(op.x, op.d);
        }
    }

    LOCAL_ASSERT_EQ(ansRef, ans);
    return ans;
}

bool Solve(std::istream& ist, std::ostream& ost, const bool id5)
{
    StopWatch<1> sw; (void)sw;

    

    size_t n;
    ist >> n;

    if (id5 && !ist)
        return false;

    LOCAL_PRINT() << std::endl << "Next test" << std::endl;
    


    map_ranges_t v;
    map_ranges_t h;
    for (size_t i = 0; i < n; i++)
    {
        int32_t x1, y1, x2, y2;
        ist >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2)
            std::swap(x1, x2);
        if (y1 > y2)
            std::swap(y1, y2);

        if (x1 == x2)
        {
            v[x1].push_back(range_t(y1, y2 + 1));
        }
        else if (y1 == y2)
        {
            h[y1].push_back(range_t(x1, x2 + 1));
        }
    }

    map_ranges_t vu;
    for (map_ranges_t::iterator p = v.begin(); p != v.end(); ++p)
    {
        const vector_range_t& r = p->second;
        const vector_range_t u = Unite(r);
        vu.insert(map_ranges_t::value_type(p->first, u));
    }

    map_ranges_t hu;
    for (map_ranges_t::iterator p = h.begin(); p != h.end(); ++p)
    {
        const vector_range_t& r = p->second;
        const vector_range_t u = Unite(r);
        hu.insert(map_ranges_t::value_type(p->first, u));
    }

    uint64_t totalPoints = 0;
    totalPoints += id9(vu);
    totalPoints += id9(hu);

    vector_int32_t coords;
    for (map_ranges_t::iterator p = vu.begin(); p != vu.end(); ++p)
    {
        coords.push_back(p->first);
        for (vector_range_t::const_iterator pc = p->second.begin(); pc != p->second.end(); ++pc)
        {
            coords.push_back(pc->b);
            coords.push_back(pc->e);
        }
    }
    for (map_ranges_t::iterator p = hu.begin(); p != hu.end(); ++p)
    {
        coords.push_back(p->first);
        for (vector_range_t::const_iterator pc = p->second.begin(); pc != p->second.end(); ++pc)
        {
            coords.push_back(pc->b);
            coords.push_back(pc->e);
        }
    }
    std::sort(coords.begin(), coords.end());
    coords.erase(std::unique(coords.begin(), coords.end()), coords.end());


    map_ranges_t vc;
    for (map_ranges_t::iterator p = vu.begin(); p != vu.end(); ++p)
    {
        vc.insert(map_ranges_t::value_type(IndexOf(coords, p->first), id14(coords, p->second)));
    }
    map_ranges_t hc;
    for (map_ranges_t::iterator p = hu.begin(); p != hu.end(); ++p)
    {
        hc.insert(map_ranges_t::value_type(IndexOf(coords, p->first), id14(coords, p->second)));
    }

    const uint64_t intersectionCount = id1(vc, hc);

    ost << (totalPoints - intersectionCount) << std::endl;

    return id5;
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