







































struct id6
{
    id6(): counter(0) {}
    ~id6() { std::cout << std::endl << "DIAG: " << (counter == 0 ? "OK" : "FAIL!!!") << " Asserts count: " << counter << std::endl; }
    void Increment() { counter++; }
    uint32_t counter;
};
id6 id10;



volatile bool id14 = 0;




bool id2 = (bool)(LOCAL_TEST);



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
template<typename T> bool id13(const T a, const T b) { return !IsLess(a, b); }
template<typename T> bool id11(const T a, const T b) { return !IsGreater(a, b); }

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



library::random::Rand id7;


typedef uint64_t weight_t;
struct id12
{
    id12() { a = 0; b = 0; w = 0; }

    size_t a;
    size_t b;
    weight_t w;
};

struct id9
{
    size_t id;
    weight_t w;

    id9(): id(0), w(0) {}
    id9(size_t id_, weight_t w_): id(id_), w(w_) {}
};

typedef std::vector<id12> vector_weighted_edge_t;
typedef std::vector<id9> vector_weighted_link_t;
typedef std::vector<vector_weighted_link_t> vector_2d_weighted_link_t;

typedef std::vector<weight_t> vector_weight_t;
typedef std::vector<vector_weight_t> vector_2d_weight_t;

class MinimumSpanningTreeFind
{
public:
    vector_weighted_edge_t GetUsingPrim(const size_t n, const vector_weighted_edge_t& edges) const
    {
        if (edges.empty())
            return edges;

        struct IsLessWeight
        {
            bool operator()(const id12& e1, const id12& e2) const { return e1.w < e2.w; }
        };

        typedef std::multiset<id12, IsLessWeight> set_edge_t;

        vector_2d_size_t links(n);
        for (size_t i = 0; i < edges.size(); i++)
        {
            const id12& e = edges[i];
            links[e.a].push_back(i);
            links[e.b].push_back(i);
        }

        set_edge_t edgesPool;
        vector_size_t id0(n);

        vector_weighted_edge_t minEdges;
        size_t current = 0;
        for (size_t i = 1; i < n; i++)
        {
            LOCAL_ASSERT(!id0[current]);
            id0[current] = 1;

            for (size_t j = 0; j < links[current].size(); j++)
            {
                const id12& e = edges[links[current][j]];
                if (!id0[e.a] || !id0[e.b])
                    edgesPool.insert(e);
            }

            set_edge_t::iterator pe = edgesPool.begin();
            while (pe != edgesPool.end())
            {
                if (!id0[pe->a] || !id0[pe->b])
                    break;
                edgesPool.erase(pe++);
            }

            LOCAL_ASSERT(pe != edgesPool.end());
            LOCAL_ASSERT(!id0[pe->a] || !id0[pe->b]);
            current = !id0[pe->a] ? pe->a : pe->b;
            minEdges.push_back(*pe);
        }

        return minEdges;
    }

    vector_weighted_edge_t GetUsingPrim(const vector_weighted_edge_t& edges) const
    {
        if (edges.empty())
            return edges;
        const vector_weighted_edge_t::const_iterator id15 = std::max_element(edges.begin(), edges.end(), [](const id12& e1, const id12& e2) { return std::max(e1.a, e1.b) < std::max(e2.a, e2.b); } );
        const size_t n = std::max(id15->a, id15->b) + 1;
        return GetUsingPrim(n, edges);
    }
};

struct MaxFunc64
{
    typedef weight_t value_type_t;
    value_type_t CombineValues(const value_type_t& l, const value_type_t& r) const { return std::max(l, r); }
    value_type_t GetDefaultValue() const { return (value_type_t)std::numeric_limits<value_type_t>::min(); }
};

template<typename WeightCombineFunc>
class id3
{
public:
    id3(const vector_weighted_edge_t& id1, const size_t id4, const WeightCombineFunc& func = WeightCombineFunc()): m_weightFunc(func)
    {
        vector_2d_weighted_link_t links(id1.size() + 1);
        for (size_t i = 0; i < id1.size(); i++)
        {
            const id12& e = id1[i];
            links[e.a].push_back(id9(e.b, e.w));
            links[e.b].push_back(id9(e.a, e.w));
        }
        
        Init(links, id4);
    }

    size_t GetLca(const size_t v1, const size_t v2) const
    {
        if (v1 == v2)
            return v1;

        if (IsUpper(v1, v2))
            return v1;

        if (IsUpper(v2, v1))
            return v2;

        size_t lca = v1;
        const size_t upSize = m_up[v1].size();
        for (size_t ri = upSize; ri > 0 ; ri--)
        {
            const size_t i = ri - 1;
            if (!IsUpper(m_up[lca][i], v2))
            {
                lca = m_up[lca][i];
            }
        }

        LOCAL_ASSERT(!(IsUpper(lca, v1) && IsUpper(lca, v2)));
        lca = m_up[lca][0];
        LOCAL_ASSERT(IsUpper(lca, v1));
        LOCAL_ASSERT(IsUpper(lca, v2));
        return lca;
    }

    

    weight_t GetWeightFuncValue(const size_t v1, const size_t v2, size_t *pLcaIndex = NULL) const
    {
        const size_t lca = GetLca(v1, v2);
        const weight_t w1 = GetWeightFuncValueForVertical(v1, lca);
        const weight_t w2 = GetWeightFuncValueForVertical(v2, lca);
        weight_t id5 = std::max(w1, w2);
        if (pLcaIndex)
            *pLcaIndex = lca;
        return id5;
    }

private:
    weight_t GetWeightFuncValueForVertical(const size_t vLow, const size_t vHigh) const
    {
        if (vLow == vHigh)
            return 0;
        LOCAL_ASSERT(IsUpper(vHigh, vLow));

        size_t v = vLow;
        weight_t id5 = 0;
        const size_t upSize = m_up[vLow].size();
        for (size_t ri = upSize; ri > 0 ; ri--)
        {
            const size_t i = ri - 1;
            if (!IsUpper(m_up[v][i], vHigh))
            {
                id5 = std::max(id5, m_weightFuncValue[v][i]);
                v = m_up[v][i];
            }
        }

        return id5;
    }

    void Init(const vector_2d_weighted_link_t& links, const size_t id4)
    {
        const size_t vertexCount = links.size();
        size_t upSize = 0;
        while ((1U << upSize) <= (vertexCount - 1))
            upSize += 1;
        
        if (vertexCount == 1)
            upSize = 1;

        vector_2d_size_t(vertexCount, vector_size_t(upSize)).swap(m_up);
        vector_2d_weight_t(vertexCount, vector_weight_t(upSize)).swap(m_weightFuncValue);
        m_timeIn.resize(vertexCount);
        m_timeOut.resize(vertexCount);

        size_t timer = 0;
        Dfs(id4, id4, 0, links, timer);
    }

    

    bool IsUpper(const size_t v1, const size_t v2) const
    {
        if (v1 != v2)
        {
            LOCAL_ASSERT(m_timeIn[v1] != m_timeIn[v2]);
            LOCAL_ASSERT(m_timeOut[v1] != m_timeOut[v2]);
        }

        if ((m_timeIn[v1] < m_timeIn[v2]) && (m_timeOut[v1] > m_timeOut[v2]))
            return true;
        return false;
    }

    void Dfs(const size_t startIndex, size_t prevIndex, weight_t weight , const vector_2d_weighted_link_t& links, size_t& timer)
    {
        m_timeIn[startIndex] = ++timer;

        m_up[startIndex][0] = prevIndex;
        m_weightFuncValue[startIndex][0] = weight;
        for (size_t i = 1; i < m_up[startIndex].size(); i++)
        {
            const size_t upperIndex = m_up[startIndex][i-1];
            m_up[startIndex][i] = m_up[upperIndex][i-1];
            m_weightFuncValue[startIndex][i] = std::max(m_weightFuncValue[upperIndex][i-1], m_weightFuncValue[startIndex][i-1]);
        }

        for (size_t i = 0; i < links[startIndex].size(); i++)
        {
            const size_t nextIndex = links[startIndex][i].id;
            const weight_t nextWeight = links[startIndex][i].w;
            if (nextIndex != prevIndex)
            {
                Dfs(nextIndex, startIndex, nextWeight, links, timer);
            }
        }

        m_timeOut[startIndex] = ++timer;
    }

    const WeightCombineFunc m_weightFunc;
    vector_2d_size_t m_up; 

    vector_2d_weight_t m_weightFuncValue; 

    vector_size_t m_timeIn;
    vector_size_t m_timeOut;
};


bool Solve(std::istream& ist, std::ostream& ost, const bool id8)
{
    StopWatch<1> sw; (void)sw;

    

    size_t n, m;
    ist >> n >> m;

    if (id8 && !ist)
        return false;

    LOCAL_PRINT() << std::endl << "Next test: n = " << n << ", m = " << m << std::endl;
    


    vector_weighted_edge_t edges(m);
    for (size_t i = 0; i < m; i++)
    {
        id12& e = edges[i];
        ist >> e.a >> e.b >> e.w;
        --e.a; --e.b;
    }

    const vector_weighted_edge_t id1 = MinimumSpanningTreeFind().GetUsingPrim(n, edges);
    const uint64_t sum = std::accumulate(id1.begin(), id1.end(), 0ULL, [](const uint64_t x, const id12& e) { return x + e.w; });

    id3<MaxFunc64> lca(id1, 0);

    vector_uint64_t ans(m);
    for (size_t i = 0; i < m; i++)
    {
        const id12& e = edges[i];
        const weight_t maxW = lca.GetWeightFuncValue(e.a, e.b);
        LOCAL_ASSERT_EQ(maxW, lca.GetWeightFuncValue(e.b, e.a));
        ans[i] = sum - maxW + e.w;
    }

    for (size_t i = 0; i < m; i++)
    {
        ost << ans[i] << "\n";
    }

    return id8;
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