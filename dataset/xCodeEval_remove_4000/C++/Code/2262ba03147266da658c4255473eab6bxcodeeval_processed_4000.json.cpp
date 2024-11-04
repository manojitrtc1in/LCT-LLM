

















typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed long int32_t;
typedef unsigned long uint32_t;
typedef signed long long int64_t;
typedef unsigned long long uint64_t;

typedef stdext::hash_set<size_t>    hash_set_size_t;






typedef long double double_t;
typedef std::string string8_t;

typedef std::vector<size_t> vector_size_t;
typedef std::set<size_t> set_size_t;
typedef std::multiset<size_t> multiset_size_t;

typedef std::vector<string8_t> vector_string8_t;
typedef std::set<string8_t> set_string8_t;
typedef std::multiset<std::string> multiset_string8_t;







template<typename T> inline T Abs(const T a) { return a < 0 ? -a : a; }
template<typename T> inline T Min(const T a, const T b) {return a < b ? a : b;}
template<typename T> inline T Max(const T a, const T b) {return a > b ? a : b;}

static const double_t eps = 1.0e-09;
template<typename T> inline bool IsEqual(const T a, const T b) { return Abs(a - b) < eps; }
template<typename T> inline bool IsGreater(const T a, const T b) { return a > b + eps; }
template<typename T> inline bool IsLess(const T a, const T b) { return a + eps < b; }

template<typename T> inline string8_t ToStr(const T& val) { std::ostringstream ostr; ostr << val; return ostr.str(); }
template<typename T> inline bool FromStr(const string8_t& str, T& val) {std::istringstream istr(str); istr >> val; return !!istr; }


template<size_t id> class StopWatch { };







class id5
{
protected:
    id5() {}
    ~id5() {}
private:
    id5& operator=(const id5&);
    id5(const id5&);
};

template<typename ValueType>
struct ICombineFunction : public std::binary_function<ValueType, ValueType, ValueType>
{
    typedef ValueType value_type_t;
    virtual value_type_t operator()(const value_type_t& l, const value_type_t& r) const = 0;
    virtual value_type_t GetDefaultValue() const = 0;
    virtual ~ICombineFunction() {}
};


template<typename value_type_t>
class SegmentTree : public id5
{
public:
    typedef std::vector<value_type_t> values_t;
    typedef ICombineFunction<value_type_t> combine_function_t;

    explicit SegmentTree(const values_t& inputData, combine_function_t* funcPtr)
        : m_funcPtr(funcPtr), m_func(*m_funcPtr), m_defaultValue(m_func.GetDefaultValue())
    {
        Preprocess(inputData);
    }

    

    value_type_t CalculateForRange(size_t idxBegin, size_t idxEnd) const
    {
        if (idxBegin == idxEnd)
            return m_defaultValue;

        const size_t len = m_resultTree[0].size();
        const size_t curPow = m_resultTree.size()-1;
        return CalculateForRangeRecPart(0, len, curPow, idxBegin, idxEnd);
    }

private:
    typedef std::vector<values_t> combined_result_tree_t;

    value_type_t CalculateForRangeRecPart(size_t disp, size_t len, size_t id1, size_t idxBegin, size_t idxEnd) const
    {
        

        const size_t l = disp;
        const size_t r = disp + len;

        if (id1 == 0)
        {
            return m_resultTree[id1][disp];
        }

        if (l == idxBegin && r == idxEnd)
        {
            return m_resultTree[id1][disp / len];
        }

        const size_t mid = disp + len / 2;

        if (mid <= idxBegin)
        {
            return CalculateForRangeRecPart(mid, len / 2, id1 - 1, idxBegin, idxEnd);
        }
        else if (mid >= idxEnd)
        {
            return CalculateForRangeRecPart(disp, len / 2, id1 - 1, idxBegin, idxEnd);
        }
        else
        {
            const value_type_t v1 = CalculateForRangeRecPart(disp, len / 2, id1 - 1, idxBegin, mid);
            const value_type_t v2 = CalculateForRangeRecPart(mid, len / 2, id1 - 1, mid, idxEnd);
            return m_func(v1, v2);
        }
    }

    void Preprocess(const values_t& inputData)
    {
        const size_t n = inputData.size();

        size_t id12 = 1;
        while (id12 < n) {id12 *= 2;}

        m_resultTree.push_back(inputData);
        m_resultTree[0].resize(id12);
        std::fill(m_resultTree[0].begin() + inputData.size(), m_resultTree[0].end(), m_defaultValue);

        size_t pow2 = 1;
        size_t multiplier = 2;

        while (multiplier <= id12)
        {
            const size_t lineSize = id12 / multiplier;
            const values_t& prevLine = m_resultTree[pow2-1];
            values_t nextLine(lineSize, m_defaultValue);

            for (size_t i = 0; i < lineSize; i++)
            {
                nextLine[i] = m_func(prevLine[2*i], prevLine[2*i + 1]);
            }

            m_resultTree.push_back(nextLine);

            pow2 += 1;
            multiplier *= 2;
        }
    }

    const std::auto_ptr<const combine_function_t> m_funcPtr;
    const combine_function_t& m_func;
    const value_type_t m_defaultValue;
    combined_result_tree_t m_resultTree;
};



typedef size_t vertex_index_t;
typedef uint32_t weight_t;
typedef uint32_t distance_t;

typedef stdext::hash_set<vertex_index_t> vertex_set_t;
typedef std::vector<vertex_set_t> vertex_sets_t;

struct edge_t
{
    vertex_index_t a;
    vertex_index_t b;

    edge_t(): a(0), b(0) {}
    edge_t(vertex_index_t a_, vertex_index_t b_): a(a_), b(b_) {}

    bool operator<(const edge_t& rval) const
    {
        if (a < rval.a)
            return true;
        if (rval.a < a)
            return false;
        return b < rval.b;
    }

    bool operator==(const edge_t& rval) const
    {
        return a == rval.a && b == rval.b;
    }
};


typedef std::vector<vertex_index_t> vertex_sequence_t;
typedef std::vector<vertex_sequence_t> vertex_sequences_t;

typedef std::vector<edge_t> edge_list_t;

typedef std::vector<vertex_index_t> link_list_t;
typedef std::vector<vertex_index_t> vertex_index_list_t;
typedef std::vector<link_list_t> link_lists_t;

typedef std::vector<distance_t> distances_t;
typedef std::vector<distances_t> distance_matrix_t;

typedef std::vector<uint8_t> binary_vector_t;

struct id9
{
    

    vertex_sequence_t walkingSequence;
    

    binary_vector_t wasHere;
    distances_t deep;
    vertex_sequence_t parentNode;

    id9() {}
    id9(size_t n): wasHere(n), deep(n), parentNode(n) {}
};

class BridgeFind
{
    struct Stats
    {
        bool wasHere;
        vertex_index_t tIn;
        vertex_index_t fUp;

        Stats(): wasHere(false), tIn(0), fUp(0) {}
    };

    typedef std::vector<Stats> vector_stats_t;

public:
    

    void FindBridges(const link_lists_t& links, edge_list_t& bridges) const
    {
        bridges.clear();
        vector_stats_t stats(links.size());
        uint32_t timeCounter = 0;
        FindBridgesRecPart(0, UINT_MAX, links, stats, timeCounter, bridges);
    }

    edge_list_t FindBridges(const link_lists_t& links) const
    {
        edge_list_t bridges;
        FindBridges(links, bridges);
        return bridges;
    }

private:
    void FindBridgesRecPart(const vertex_index_t v, const vertex_index_t prev, const link_lists_t& links, vector_stats_t& stats, uint32_t& timeCounter, edge_list_t& bridges) const
    {
        Stats& vStats = stats[v];

        vStats.wasHere = true;
        vStats.tIn = timeCounter;
        vStats.fUp = timeCounter;
        timeCounter++;

        const link_list_t& nextLink = links[v];
        for (size_t i = 0; i < nextLink.size(); i++)
        {
            const vertex_index_t to = nextLink[i];
            if (to != prev)
            { 
                Stats& toStats = stats[to];
                if (toStats.wasHere)
                {
                    vStats.fUp = Min(vStats.fUp, toStats.tIn);
                }
                else
                {
                    FindBridgesRecPart(to, v, links, stats, timeCounter, bridges);
                    vStats.fUp = Min(vStats.fUp, toStats.fUp);
                    if (vStats.tIn < toStats.fUp)
                    {
                        const edge_t bridge(Min(v, to), Max(v, to));
                        bridges.push_back(bridge);
                    }
                }
            }
        }
    }
};

class id8
{
public:
    

    id8(const link_lists_t& links, const vertex_index_t id6)
    {
        Preprocess(links, id6);
    }

    vertex_index_t GetLCA(vertex_index_t a, vertex_index_t b) const
    {
        vertex_index_t aFirst = m_first[a];
        vertex_index_t bFirst = m_first[b];

        if (aFirst > bFirst)
            std::swap(aFirst, bFirst);

        const size_t orderIndex = m_segmentTree->CalculateForRange(aFirst, bFirst+1);
        return m_order[orderIndex];
    }

    const distances_t& GetDeeps() const
    {
        return id0.deep;
    }

    const id9& GetSpanningTree() const
    {
        return id0;
    }

private:
    void PerformWalk(const link_lists_t& links, const vertex_index_t startIndex, const distance_t deep)
    {
        id0.deep[startIndex] = deep;
        id0.wasHere[startIndex] = 1;
        id0.walkingSequence.push_back(startIndex);
        m_order.push_back(startIndex);
        for (size_t i = 0; i < links[startIndex].size(); i++)
        {
            const vertex_index_t nextIndex = links[startIndex][i];
            if (!id0.wasHere[nextIndex])
            {
                id0.parentNode[nextIndex] = startIndex;
                PerformWalk(links, nextIndex, deep + 1);
                m_order.push_back(startIndex);
            }
        }
    }

    void FillIndex(const size_t n)
    {
        binary_vector_t wasFound(n);
        for (size_t i = 0; i < m_order.size(); i++)
        {
            vertex_index_t idx = m_order[i];
            if (!wasFound[idx])
            {
                wasFound[idx] = true;
                m_first[idx] = i;
            }
        }
    }

    typedef SegmentTree<vertex_index_t> CustomSegmentTree;

    class id3 : 
        public ICombineFunction<vertex_index_t>,
        public id5
    {
    public:
        id3(const vertex_sequence_t& order, const distances_t& deep)
            : m_order(order), m_deep(deep)
        {           
        }

        virtual value_type_t operator()(const value_type_t& l, const value_type_t& r) const
        {
            return (m_deep[m_order[l]] < m_deep[m_order[r]]) ? l : r;
        }

        virtual value_type_t GetDefaultValue() const
        {
            return 0;
        }
    private:
        const vertex_sequence_t& m_order;
        const distances_t& m_deep;
    };

    void Preprocess(const link_lists_t& links, const vertex_index_t id6)
    {
        const size_t n = links.size();
        id0 = id9(n);
        id0.parentNode[id6] = id6;
        m_first.resize(n);
        PerformWalk(links, id6, 0);
        FillIndex(n);

        vertex_index_list_t orderIndexes;
        orderIndexes.reserve(m_order.size());
        for (size_t i = 0; i < m_order.size(); i++)
        {
            orderIndexes.push_back(i);
        }
        m_segmentTree.reset(new CustomSegmentTree(orderIndexes, new id3(m_order, id0.deep)));
    }

    id9 id0;

    vertex_sequence_t m_order;
    vertex_index_list_t m_first;

    std::auto_ptr<CustomSegmentTree> m_segmentTree;
};

void id10(const size_t partIndex, const link_lists_t& links, const vertex_index_t startIndex, binary_vector_t& wasHere, const vertex_sets_t& id7, vertex_index_list_t& reverseIndex)
{
    wasHere[startIndex] = 1;
    reverseIndex[startIndex] = partIndex;
    for (size_t i = 0; i < links[startIndex].size(); i++)
    {
        const vertex_index_t nextIndex = links[startIndex][i];
        if (!wasHere[nextIndex])
        {
            if (id7[startIndex].find(nextIndex) == id7[startIndex].end())
            {
                id10(partIndex, links, nextIndex, wasHere, id7, reverseIndex);
            }
        }
    }
}

void id4(const link_lists_t& links, binary_vector_t& wasHere, const edge_list_t& bridges, const vertex_sets_t& id7, link_lists_t& newLinks, vertex_index_list_t& reverseIndex)
{
    const size_t n = links.size();
    size_t partIndex = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (!wasHere[i])
        {
            id10(partIndex, links, i, wasHere, id7, reverseIndex);
            partIndex++;
        }
    }

    newLinks.resize(partIndex); 

    for (edge_list_t::const_iterator pi = bridges.begin(); pi != bridges.end(); ++pi)
    {
        const edge_t& bridge = *pi;
        const vertex_index_t a = reverseIndex[bridge.a];
        const vertex_index_t b = reverseIndex[bridge.b];
        newLinks[a].push_back(b);
        newLinks[b].push_back(a);
    }
}


bool Solve(std::istream& ist, std::ostream& ost, const bool id13)
{
    StopWatch<1> sw;

    

    

    size_t n, m;
    ist >> n >> m;

    


    if (id13 && !ist)
    {
        return false;
    }

    

    

    link_lists_t links(n);
    for (size_t i = 0; i < m; i++)
    {
        vertex_index_t a, b;
        ist >> a >> b;
        --a; --b;
        links[a].push_back(b);
        links[b].push_back(a);
    }

    size_t k;
    ist >> k;
    edge_list_t paths(k);
    for (size_t i = 0; i < k; i++)
    {
        vertex_index_t a, b;
        ist >> a >> b;
        --a; --b;
        paths[i] = edge_t(a,b);
    }

    const edge_list_t& bridges = BridgeFind().FindBridges(links);
    vertex_sets_t id7(n);
    for (size_t i = 0; i < bridges.size(); i++)
    {
        const edge_t& bridge = bridges[i];
        id7[bridge.a].insert(bridge.b);
        id7[bridge.b].insert(bridge.a);
    }

    binary_vector_t wasHere(n);
    vertex_index_list_t reverseIndex(n);
    link_lists_t id2;
    id4(links, wasHere, bridges, id7, id2, reverseIndex);

    vector_size_t answer(k);

    const id8 id11(id2, 0);
    const id9& id14 = id11.GetSpanningTree();
    const distances_t& deep = id14.deep;

    for (size_t i = 0; i < k; i++)
    {
        const vertex_index_t a = reverseIndex[paths[i].a];
        const vertex_index_t b = reverseIndex[paths[i].b];
        const vertex_index_t lca = id11.GetLCA(a, b);
        
        const distance_t len = deep[a] - deep[lca] + deep[b] - deep[lca];
        answer[i] = len;
    }

    for (size_t i = 0; i < k; i++)
    {
        ost << answer[i] << std::endl;
    }

    


    return id13;
}

int main()
{
    std::istream& ist = std::cin;
    std::ostream& ost = std::cout;

    Solve(ist, ost, false);

    while(Solve(ist, ost, true)) {};

}
