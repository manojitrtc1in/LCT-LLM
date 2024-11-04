








template <typename _Tp, typename _Fp, typename _Compare = std::less<void>>
bool chmax(_Tp &a, const _Fp &b, _Compare __comp = _Compare()) { return __comp(a, b) ? a = b, true : false; }
template <typename _Tp, typename _Fp, typename _Compare = std::less<void>>
bool chmin(_Tp &a, const _Fp &b, _Compare __comp = _Compare()) { return __comp(b, a) ? a = b, true : false; }

    if (condition)       \
        cout << "YES\n"; \
    else                 \
        cout << "NO\n";
using std::cin, std::cout, std::endl;
auto tam = [] {
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    struct id11 {
        static auto GetMicroSecond() {
            static FILETIME ft;
            GetSystemTimeAsFileTime(&ft);
            return ft.dwLowDateTime;
        };
        static auto GetMemory() {
            PROCESS_MEMORY_COUNTERS pmc;
            GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
            return pmc.WorkingSetSize;
        }
        uint32_t t0, t1;
        id11() : t0(GetMicroSecond()) {}
        void stop() {
            t1 = GetMicroSecond();
            cout << "\ntime cost = " << (t1 - t0) / 10000.0 << " ms\nmemory cost = " << (GetMemory() >> 20) << " MB\n ";
            t0 = t1;
        }
        ~id11() { stop(); }
    };
    return id11();


    return 0;

}();
using LL = long long;
namespace OY {
    template <typename _Sequence>
    struct id9 {
        _Sequence &m_sequence;
        id9(_Sequence &__sequence) : m_sequence(__sequence) {}
        auto &operator()(uint32_t __index) const { return m_sequence[__index]; }
    };
    template <typename _Mapping, typename _Compare = std::less<void>>
    struct id4 {
        std::vector<uint32_t> m_heap;
        std::vector<uint32_t> m_pos;
        _Mapping m_map;
        _Compare m_comp;
        id4(uint32_t __n, _Mapping __map, _Compare __comp = _Compare()) : m_pos(__n, -1), m_map(__map), m_comp(__comp) { m_heap.reserve(__n); }
        void siftUp(uint32_t __i) {
            uint32_t curpos = m_pos[__i];
            auto curvalue = m_map(__i);
            for (uint32_t p; curpos && m_comp(m_map(p = m_heap[curpos - 1 >> 1]), curvalue); curpos = curpos - 1 >> 1) m_heap[m_pos[p] = curpos] = p;
            m_heap[m_pos[__i] = curpos] = __i;
        }
        void siftDown(uint32_t __i) {
            uint32_t curpos = m_pos[__i];
            auto curvalue = m_map(__i);
            for (uint32_t c; (c = curpos * 2 + 1) < m_heap.size(); curpos = c) {
                if (c + 1 < m_heap.size() && m_comp(m_map(m_heap[c]), m_map(m_heap[c + 1]))) c++;
                if (!m_comp(curvalue, m_map(m_heap[c]))) break;
                m_pos[m_heap[curpos] = m_heap[c]] = curpos;
            }
            m_heap[m_pos[__i] = curpos] = __i;
        }
        void push(uint32_t __i) {
            if (!~m_pos[__i]) {
                m_pos[__i] = m_heap.size();
                m_heap.push_back(__i);
            }
            siftUp(__i);
        }
        uint32_t top() const { return m_heap.front(); }
        void pop() {
            m_pos[m_heap.front()] = -1;
            if (m_heap.size() > 1) {
                m_pos[m_heap.back()] = 0;
                m_heap.front() = m_heap.back();
                m_heap.pop_back();
                siftDown(m_heap.front());
            } else
                m_heap.pop_back();
        }
        bool empty() const { return m_heap.empty(); }
        uint32_t size() const { return m_heap.size(); }
    };
    template <typename _Tp, typename _Compare>
    id4(uint32_t, std::vector<_Tp> &, _Compare) -> id4<id9<std::vector<_Tp>>, _Compare>;
    template <typename _Tp, uint32_t _N, typename _Compare>
    id4(uint32_t, _Tp (&)[_N], _Compare) -> id4<id9<_Tp[_N]>, _Compare>;
}
namespace OY {
    struct Hungarian {
        struct _Edge {
            uint32_t a, b;
        };
        std::vector<_Edge> m_edges;
        std::vector<uint32_t> m_adj, m_starts, m_leftMatch, m_rightMatch;
        uint32_t m_leftNum, m_rightNum;
        Hungarian(uint32_t id1, uint32_t id0, uint32_t id10) : m_starts(id1 + 1), m_leftNum(id1), m_rightNum(id0) { m_edges.reserve(id10); }
        void addEdge(uint32_t __a, uint32_t __b) { m_edges.push_back({__a, __b}); }
        void prepare() {
            for (auto &[a, b] : m_edges) m_starts[a + 1]++;
            std::partial_sum(m_starts.begin(), m_starts.end(), m_starts.begin());
            m_adj.resize(m_starts.back());
            uint32_t cursor[m_leftNum];
            std::copy(m_starts.begin(), m_starts.begin() + m_leftNum, cursor);
            for (uint32_t index = 0; index < m_edges.size(); index++) {
                auto &[a, b] = m_edges[index];
                m_adj[cursor[a]++] = b;
            }
        }
        uint32_t calc() {
            m_leftMatch.resize(m_leftNum, -1);
            m_rightMatch.resize(m_rightNum, -1);
            std::vector<uint32_t> visit(m_leftNum, -1);
            uint32_t dfn = 0, res = 0;
            auto dfs = [&](auto self, uint32_t a) {
                visit[a] = dfn;
                for (uint32_t cur = m_starts[a], end = m_starts[a + 1]; cur < end; cur++)
                    if (uint32_t b = m_adj[cur]; !~m_rightMatch[b]) {
                        m_rightMatch[b] = a;
                        m_leftMatch[a] = b;
                        return true;
                    }
                for (uint32_t cur = m_starts[a], end = m_starts[a + 1]; cur < end; cur++)
                    if (uint32_t b = m_adj[cur]; visit[m_rightMatch[b]] != dfn && self(self, m_rightMatch[b])) {
                        m_rightMatch[b] = a;
                        m_leftMatch[a] = b;
                        return true;
                    }
                return false;
            };
            while (true) {
                uint32_t augument = 0;
                for (uint32_t a = 0; a < m_leftNum; a++)
                    if (!~m_leftMatch[a] && dfs(dfs, a)) augument++;
                if (!augument) break;
                res += augument;
                dfn++;
            }
            return res;
        }
    };
}
namespace OY {
    struct id2 {
        struct _Edge {
            uint32_t a, b;
        };
        std::vector<_Edge> m_edges;
        std::vector<uint32_t> m_adj, m_starts, m_leftMatch, m_rightMatch;
        uint32_t m_leftNum, m_rightNum;
        id2(uint32_t id1, uint32_t id0, uint32_t id10) : m_starts(id1 + 1), m_leftNum(id1), m_rightNum(id0) { m_edges.reserve(id10); }
        void addEdge(uint32_t __a, uint32_t __b) { m_edges.push_back({__a, __b}); }
        void prepare() {
            for (auto &[a, b] : m_edges) m_starts[a + 1]++;
            std::partial_sum(m_starts.begin(), m_starts.end(), m_starts.begin());
            m_adj.resize(m_starts.back());
            uint32_t cursor[m_leftNum];
            std::copy(m_starts.begin(), m_starts.begin() + m_leftNum, cursor);
            for (uint32_t index = 0; index < m_edges.size(); index++) {
                auto &[a, b] = m_edges[index];
                m_adj[cursor[a]++] = b;
            }
        }
        uint32_t calc() {
            std::vector<uint32_t> dist(m_leftNum), queue(m_leftNum), visit(m_leftNum, -1);
            uint32_t dfn = 0, res = 0;
            auto bfs = [&] {
                std::fill_n(dist.data(), m_leftNum, -1);
                uint32_t head = 0, tail = 0;
                for (uint32_t a = 0; a < m_leftNum; a++)
                    if (!~m_leftMatch[a]) dist[a] = 0, queue[tail++] = a;
                while (head < tail)
                    for (uint32_t a = queue[head++], cur = m_starts[a], end = m_starts[a + 1]; cur < end; cur++)
                        if (uint32_t a2 = m_rightMatch[m_adj[cur]]; ~a2 && chmin(dist[a2], dist[a] + 1)) queue[tail++] = a2;
            };
            auto dfs = [&](auto &&self, uint32_t a) {
                visit[a] = dfn;
                for (uint32_t cur = m_starts[a], end = m_starts[a + 1]; cur < end; cur++)
                    if (uint32_t b = m_adj[cur]; !~m_rightMatch[b]) {
                        m_rightMatch[b] = a;
                        m_leftMatch[a] = b;
                        return true;
                    }
                for (uint32_t cur = m_starts[a], end = m_starts[a + 1]; cur < end; cur++)
                    if (uint32_t b = m_adj[cur]; visit[m_rightMatch[b]] != dfn && dist[m_rightMatch[b]] == dist[a] + 1 && self(self, m_rightMatch[b])) {
                        m_rightMatch[b] = a;
                        m_leftMatch[a] = b;
                        return true;
                    }
                return false;
            };
            m_leftMatch.resize(m_leftNum, -1);
            m_rightMatch.resize(m_rightNum, -1);
            while (true) {
                bfs();
                uint32_t augument = 0;
                for (uint32_t a = 0; a < m_leftNum; a++)
                    if (!~m_leftMatch[a] && dfs(dfs, a)) augument++;
                if (!augument) break;
                res += augument;
                dfn++;
            }
            return res;
        }
    };
}
namespace OY {
    template <typename _Tp>
    struct Dinic {
        struct _RawEdge {
            uint32_t from, to;
            _Tp cap;
        };
        struct _Edge {
            uint32_t to, rev;
            _Tp cap;
            bool operator>(const _Edge &other) const { return cap > other.cap; }
        };
        std::vector<_RawEdge> m_rawEdges;
        std::vector<_Edge> m_edges;
        std::vector<uint32_t> m_starts;
        uint32_t id6;
        Dinic(uint32_t id8, uint32_t id10) : m_starts(id8 + 1, 0), id6(id8) { m_rawEdges.reserve(id10); }
        void addEdge(uint32_t __a, uint32_t __b, _Tp __cap) { m_rawEdges.push_back({__a, __b, __cap}); }
        void prepare() {
            for (auto &[from, to, cap] : m_rawEdges)
                if (from != to) {
                    m_starts[from + 1]++;
                    m_starts[to + 1]++;
                }
            std::partial_sum(m_starts.begin(), m_starts.end(), m_starts.begin());
            m_edges.resize(m_starts.back());
            uint32_t cursor[id6];
            std::copy(m_starts.begin(), m_starts.begin() + id6, cursor);
            for (auto &[from, to, cap] : m_rawEdges)
                if (from != to) {
                    m_edges[cursor[from]] = _Edge{to, cursor[to], cap};
                    m_edges[cursor[to]++] = _Edge{from, cursor[from]++, 0};
                }
        }
        template <typename _Compare = std::greater<_Edge>>
        void prepareSorted(_Compare __comp = _Compare()) {
            prepare();
            for (uint32_t i = 0; i < id6; i++) {
                uint32_t start = m_starts[i], end = m_starts[i + 1];
                std::sort(m_edges.begin() + start, m_edges.begin() + end, __comp);
                for (uint32_t j = start; j < end; j++) m_edges[m_edges[j].rev].rev = j;
            }
        }
        _Tp calc(uint32_t __source, uint32_t __target, _Tp id5 = std::numeric_limits<_Tp>::max() / 2) {
            uint32_t queue[id6], depth[id6], it[id6], end[id6];
            _Tp res = 0;
            for (uint32_t i = 0; i < id6; i++) end[i] = m_starts[i + 1];
            auto dfs = [&](auto self, uint32_t i, _Tp _cap) {
                if (i == __target || !_cap) return _cap;
                _Tp flow = 0, f;
                for (uint32_t &cur = it[i]; cur != end[i]; cur++)
                    if (auto &[to, rev, cap] = m_edges[cur]; depth[i] + 1 == depth[to] && (f = self(self, to, std::min(_cap, cap))))
                        if (flow += f, _cap -= f, cap -= f, m_edges[rev].cap += f; !_cap) break;
                return flow;
            };
            while (true) {
                std::fill(depth, depth + id6, -1);
                uint32_t head = 0, tail = 0;
                depth[__source] = 0;
                queue[tail++] = __source;
                while (head < tail)
                    for (uint32_t from = queue[head++], cur = m_starts[from], end = m_starts[from + 1]; cur < end; cur++)
                        if (auto &[to, rev, cap] = m_edges[cur]; cap && chmin(depth[to], depth[from] + 1)) queue[tail++] = to;
                if (!~depth[__target]) break;
                for (uint32_t i = 0; i < id6; i++) it[i] = m_starts[i];
                while (_Tp flow = dfs(dfs, __source, id5)) res += flow;
            }
            return res;
        }
    };
}
namespace OY {
    template <template <typename...> typename _Solver = Dinic>
    struct FlowMatcher : _Solver<int> {
        std::vector<uint32_t> m_leftMatch, m_rightMatch;
        uint32_t m_leftNum, m_rightNum;
        FlowMatcher(uint32_t id1, uint32_t id0, uint32_t id10) : _Solver<int>(id1 + id0 + 2, id10 + id1 + id0), m_leftNum(id1), m_rightNum(id0) {}
        void addEdge(uint32_t __a, uint32_t __b) { _Solver<int>::addEdge(__a, m_leftNum + __b, 1); }
        void prepare() {
            for (uint32_t i = 0; i < m_leftNum; i++) _Solver<int>::addEdge(m_leftNum + m_rightNum, i, 1);
            for (uint32_t i = 0; i < m_rightNum; i++) _Solver<int>::addEdge(m_leftNum + i, m_leftNum + m_rightNum + 1, 1);
            _Solver<int>::prepare();
        }
        template <bool _GetPath = false>
        uint32_t calc() {
            uint32_t res = _Solver<int>::calc(m_leftNum + m_rightNum, m_leftNum + m_rightNum + 1);
            if constexpr (_GetPath) {
                uint32_t cursor[_Solver<int>::id6];
                std::copy(_Solver<int>::m_starts.begin(), _Solver<int>::m_starts.begin() + _Solver<int>::id6, cursor);
                m_leftMatch.resize(m_leftNum, -1);
                m_rightMatch.resize(m_rightNum, -1);
                for (uint32_t i = 0, iend = _Solver<int>::m_rawEdges.size() - m_leftNum - m_rightNum; i < iend; i++) {
                    auto &[from, to, cap] = _Solver<int>::m_rawEdges[i];
                    if (_Solver<int>::m_edges[cursor[to]++].cap) {
                        m_leftMatch[from] = to - m_leftNum;
                        m_rightMatch[to - m_leftNum] = from;
                    }
                    cursor[from]++;
                }
            }
            return res;
        }
    };
}
namespace OY {
    template <typename _Tp>
    struct ISAP {
        struct _RawEdge {
            uint32_t from, to;
            _Tp cap;
        };
        struct _Edge {
            uint32_t to, rev;
            _Tp cap;
            bool operator>(const _Edge &other) const { return cap > other.cap; }
        };
        std::vector<_RawEdge> m_rawEdges;
        std::vector<_Edge> m_edges;
        std::vector<uint32_t> m_starts;
        uint32_t id6;
        ISAP(uint32_t id8, uint32_t id10) : m_starts(id8 + 1, 0), id6(id8) { m_rawEdges.reserve(id10); }
        void addEdge(uint32_t __a, uint32_t __b, _Tp __cap) { m_rawEdges.push_back({__a, __b, __cap}); }
        void prepare() {
            for (auto &[from, to, cap] : m_rawEdges)
                if (from != to) {
                    m_starts[from + 1]++;
                    m_starts[to + 1]++;
                }
            std::partial_sum(m_starts.begin(), m_starts.end(), m_starts.begin());
            m_edges.resize(m_starts.back());
            uint32_t cursor[id6];
            std::copy(m_starts.begin(), m_starts.begin() + id6, cursor);
            for (auto &[from, to, cap] : m_rawEdges)
                if (from != to) {
                    m_edges[cursor[from]] = _Edge{to, cursor[to], cap};
                    m_edges[cursor[to]++] = _Edge{from, cursor[from]++, 0};
                }
        }
        template <typename _Compare = std::greater<_Edge>>
        void prepareSorted(_Compare __comp = _Compare()) {
            prepare();
            for (uint32_t i = 0; i < id6; i++) {
                uint32_t start = m_starts[i], end = m_starts[i + 1];
                std::sort(m_edges.begin() + start, m_edges.begin() + end, __comp);
                for (uint32_t j = start; j < end; j++) m_edges[m_edges[j].rev].rev = j;
            }
        }
        _Tp calc(uint32_t __source, uint32_t __target, _Tp id5 = std::numeric_limits<_Tp>::max() / 2) {
            uint32_t queue[id6], depth[id6], head = 0, tail = 0, num[id6 + 1], point[id6], prev[id6], len = 0, it[id6], end[id6];
            _Tp res = 0;
            std::fill(depth, depth + id6, id6);
            depth[__target] = 0;
            queue[tail++] = __target;
            while (head < tail)
                for (uint32_t from = queue[head++], cur = m_starts[from], end = m_starts[from + 1]; cur < end; cur++)
                    if (auto &[to, rev, cap] = m_edges[cur]; m_edges[rev].cap && chmin(depth[to], depth[from] + 1)) queue[tail++] = to;
            if (depth[__source] == id6) return res;
            std::fill(num, num + id6 + 1, 0);
            for (uint32_t i = 0; i < id6; i++) num[depth[i]]++;
            for (uint32_t i = 0; i < id6; i++) it[i] = m_starts[i];
            for (uint32_t i = 0; i < id6; i++) end[i] = m_starts[i + 1];
            point[len++] = __source;
            while (depth[__source] < id6)
                if (uint32_t x = point[len - 1]; x == __target) {
                    _Tp flow = id5;
                    for (uint32_t i = 1; i < len; i++) chmin(flow, m_edges[prev[i]].cap);
                    for (uint32_t i = 1; i < len; i++) {
                        auto &[to, rev, cap] = m_edges[prev[i]];
                        cap -= flow;
                        m_edges[rev].cap += flow;
                    }
                    res += flow;
                    len = 1;
                } else {
                    for (uint32_t &cur = it[x]; cur != end[x]; cur++)
                        if (auto &[to, rev, cap] = m_edges[cur]; cap && depth[x] == depth[to] + 1) {
                            point[len] = to;
                            prev[len++] = cur;
                            break;
                        }
                    if (x == point[len - 1]) {
                        if (!--num[depth[x]]) break;
                        depth[x] = id6;
                        for (uint32_t cur = m_starts[x], end = m_starts[x + 1]; cur < end; cur++)
                            if (auto &[to, rev, cap] = m_edges[cur]; cap) chmin(depth[x], depth[to] + 1);
                        num[depth[x]]++;
                        it[x] = m_starts[x];
                        if (len > 1) len--;
                    }
                }
            return res;
        }
    };
}
namespace OY {
    template <typename _Tp>
    struct id7 {
        struct _RawEdge {
            uint32_t from, to;
            _Tp cap;
        };
        struct _Edge {
            uint32_t to, rev;
            _Tp cap;
            bool operator>(const _Edge &other) const { return cap > other.cap; }
        };
        std::vector<_RawEdge> m_rawEdges;
        std::vector<_Edge> m_edges;
        std::vector<uint32_t> m_starts;
        uint32_t id6;
        id7(uint32_t id8, uint32_t id10) : m_starts(id8 + 1, 0), id6(id8) { m_rawEdges.reserve(id10); }
        void addEdge(uint32_t __a, uint32_t __b, _Tp __cap) { m_rawEdges.push_back({__a, __b, __cap}); }
        void prepare() {
            for (auto &[from, to, cap] : m_rawEdges)
                if (from != to) {
                    m_starts[from + 1]++;
                    m_starts[to + 1]++;
                }
            std::partial_sum(m_starts.begin(), m_starts.end(), m_starts.begin());
            m_edges.resize(m_starts.back());
            uint32_t cursor[id6];
            std::copy(m_starts.begin(), m_starts.begin() + id6, cursor);
            for (auto &[from, to, cap] : m_rawEdges)
                if (from != to) {
                    m_edges[cursor[from]] = _Edge{to, cursor[to], cap};
                    m_edges[cursor[to]++] = _Edge{from, cursor[from]++, 0};
                }
        }
        template <typename _Compare = std::greater<_Edge>>
        void prepareSorted(_Compare __comp = _Compare()) {
            prepare();
            for (uint32_t i = 0; i < id6; i++) {
                uint32_t start = m_starts[i], end = m_starts[i + 1];
                std::sort(m_edges.begin() + start, m_edges.begin() + end, __comp);
                for (uint32_t j = start; j < end; j++) m_edges[m_edges[j].rev].rev = j;
            }
        }
        _Tp calc(uint32_t __source, uint32_t __target, _Tp id5 = std::numeric_limits<_Tp>::max() / 2) {
            std::vector<bool> visit(id6, false);
            _Tp res = 0;
            auto dfs = [&](auto self, uint32_t i, _Tp _cap) {
                if (i == __target || !_cap) return _cap;
                visit[i] = true;
                _Tp flow = 0, f;
                for (uint32_t cur = m_starts[i], end = m_starts[i + 1]; cur < end; cur++)
                    if (auto &[to, rev, cap] = m_edges[cur]; !visit[to] && (f = self(self, to, std::min(_cap, cap))))
                        if (flow += f, _cap -= f, cap -= f, m_edges[rev].cap += f; !_cap) break;
                return flow;
            };
            while (_Tp flow = dfs(dfs, __source, id5)) {
                res += flow;
                std::fill(visit.begin(), visit.end(), false);
            }
            return res;
        }
    };
}
namespace OY {
    template <typename _Tp>
    struct id3 {
        struct _RawEdge {
            uint32_t from, to;
            _Tp cap;
        };
        struct _Edge {
            uint32_t to, rev;
            _Tp cap;
            bool operator>(const _Edge &other) const { return cap > other.cap; }
        };
        std::vector<_RawEdge> m_rawEdges;
        std::vector<_Edge> m_edges;
        std::vector<uint32_t> m_starts;
        uint32_t id6;
        id3(uint32_t id8, uint32_t id10) : m_starts(id8 + 1, 0), id6(id8) { m_rawEdges.reserve(id10); }
        void addEdge(uint32_t __a, uint32_t __b, _Tp __cap) { m_rawEdges.push_back({__a, __b, __cap}); }
        void prepare() {
            for (auto &[from, to, cap] : m_rawEdges)
                if (from != to) {
                    m_starts[from + 1]++;
                    m_starts[to + 1]++;
                }
            std::partial_sum(m_starts.begin(), m_starts.end(), m_starts.begin());
            m_edges.resize(m_starts.back());
            uint32_t cursor[id6];
            std::copy(m_starts.begin(), m_starts.begin() + id6, cursor);
            for (auto &[from, to, cap] : m_rawEdges)
                if (from != to) {
                    m_edges[cursor[from]] = _Edge{to, cursor[to], cap};
                    m_edges[cursor[to]++] = _Edge{from, cursor[from]++, 0};
                }
        }
        template <typename _Compare = std::greater<_Edge>>
        void prepareSorted(_Compare __comp = _Compare()) {
            prepare();
            for (uint32_t i = 0; i < id6; i++) {
                uint32_t start = m_starts[i], end = m_starts[i + 1];
                std::sort(m_edges.begin() + start, m_edges.begin() + end, __comp);
                for (uint32_t j = start; j < end; j++) m_edges[m_edges[j].rev].rev = j;
            }
        }
        _Tp calc(uint32_t __source, uint32_t __target, _Tp id5 = std::numeric_limits<_Tp>::max() / 2) {
            uint32_t queue[id6], fromEdge[id6], prev[id6];
            _Tp res = 0, flow[id6], f;
            while (true) {
                std::fill(flow, flow + id6, 0);
                uint32_t head = 0, tail = 0;
                flow[__source] = id5;
                queue[tail++] = __source;
                while (head < tail)
                    for (uint32_t from = queue[head++], cur = m_starts[from], end = m_starts[from + 1]; cur < end; cur++)
                        if (auto &[to, rev, cap] = m_edges[cur]; cap && !flow[to]) {
                            flow[to] = std::min(flow[from], cap);
                            fromEdge[to] = cur;
                            prev[to] = from;
                            queue[tail++] = to;
                        }
                if (!flow[__target]) break;
                res += f = flow[__target];
                for (uint32_t cur = __target; cur != __source; cur = prev[cur]) {
                    auto &[to, rev, cap] = m_edges[fromEdge[cur]];
                    cap -= f;
                    m_edges[rev].cap += f;
                }
            }
            return res;
        }
    };
}
namespace OY {
    template <typename _Tp>
    struct MPM {
        struct _RawEdge {
            uint32_t from, to;
            _Tp cap;
        };
        struct _Edge {
            uint32_t from, to, rev;
            _Tp cap;
            bool operator>(const _Edge &other) const { return cap > other.cap; }
        };
        std::vector<_RawEdge> m_rawEdges;
        std::vector<_Edge> m_edges;
        std::vector<uint32_t> m_starts;
        uint32_t id6;
        MPM(uint32_t id8, uint32_t id10) : m_starts(id8 + 1, 0), id6(id8) { m_rawEdges.reserve(id10); }
        void addEdge(uint32_t __a, uint32_t __b, _Tp __cap) { m_rawEdges.push_back({__a, __b, __cap}); }
        void prepare() {
            for (auto &[from, to, cap] : m_rawEdges)
                if (from != to) {
                    m_starts[from + 1]++;
                    m_starts[to + 1]++;
                }
            std::partial_sum(m_starts.begin(), m_starts.end(), m_starts.begin());
            m_edges.resize(m_starts.back());
            uint32_t cursor[id6];
            std::copy(m_starts.begin(), m_starts.begin() + id6, cursor);
            for (auto &[from, to, cap] : m_rawEdges)
                if (from != to) {
                    m_edges[cursor[from]] = _Edge{from, to, cursor[to], cap};
                    m_edges[cursor[to]++] = _Edge{to, from, cursor[from]++, 0};
                }
        }
        template <typename _Compare = std::greater<_Edge>>
        void prepareSorted(_Compare __comp = _Compare()) {
            prepare();
            for (uint32_t i = 0; i < id6; i++) {
                uint32_t start = m_starts[i], end = m_starts[i + 1];
                std::sort(m_edges.begin() + start, m_edges.begin() + end, __comp);
                for (uint32_t j = start; j < end; j++) m_edges[m_edges[j].rev].rev = j;
            }
        }
        _Tp calc(uint32_t __source, uint32_t __target, _Tp id5 = std::numeric_limits<_Tp>::max() / 2) {
            _Tp res = 0, in_flow[id6], out_flow[id6], flow[id6], ex[id6];
            uint32_t queue[id6], depth[id6], head, tail, in_prev[m_edges.size() + id6], in_next[m_edges.size() + id6], out_prev[m_edges.size() + id6], out_next[m_edges.size() + id6];
            auto mapping = [&](uint32_t i) { return flow[i]; };
            id4 heap(id6, mapping, std::greater<_Tp>{});
            for (uint32_t i = 0; i < id6; i++) heap.m_heap.push_back(heap.m_pos[i] = i);
            auto insert = [&](uint32_t e, uint32_t i, uint32_t prev[], uint32_t next[]) {
                prev[e] = m_edges.size() + i;
                next[e] = next[m_edges.size() + i];
                prev[next[e]] = next[prev[e]] = e;
            };
            auto erase = [&](uint32_t e, uint32_t prev[], uint32_t next[]) {
                next[prev[e]] = next[e];
                prev[next[e]] = prev[e];
            };
            auto update_flow = [&](uint32_t i) {if (chmin(flow[i], std::min(in_flow[i], out_flow[i]))) heap.siftUp(i); };
            auto remove_node = [&](uint32_t i) {
                for (uint32_t index = in_next[m_edges.size() + i]; index < m_edges.size(); index = in_next[index]) {
                    auto &[from, to, rev, cap] = m_edges[index];
                    erase(index, out_prev, out_next);
                    out_flow[from] -= cap;
                    update_flow(from);
                }
                for (uint32_t index = out_next[m_edges.size() + i]; index < m_edges.size(); index = out_next[index]) {
                    auto &[from, to, rev, cap] = m_edges[index];
                    erase(index, in_prev, in_next);
                    in_flow[to] -= cap;
                    update_flow(to);
                }
            };
            auto push = [&](uint32_t i, _Tp f, uint32_t end, bool forward) {
                std::fill(ex, ex + id6, 0);
                ex[i] = f;
                head = tail = 0;
                queue[tail++] = i;
                while (head < tail) {
                    uint32_t cur = queue[head++];
                    if (cur == end) break;
                    auto &index = forward ? out_next[m_edges.size() + cur] : in_next[m_edges.size() + cur];
                    for (_Tp must = ex[cur]; must;) {
                        auto &[from, to, rev, cap] = m_edges[index];
                        _Tp pushed = std::min(must, cap);
                        out_flow[from] -= pushed;
                        in_flow[to] -= pushed;
                        update_flow(from);
                        update_flow(to);
                        uint32_t other = forward ? to : from;
                        if (!ex[other]) queue[tail++] = other;
                        ex[other] += pushed;
                        cap -= pushed;
                        m_edges[rev].cap += pushed;
                        must -= pushed;
                        if (cap) break;
                        if (forward) {
                            erase(index, in_prev, in_next);
                            erase(index, out_prev, out_next);
                        } else {
                            erase(index, out_prev, out_next);
                            erase(index, in_prev, in_next);
                        }
                    }
                }
            };
            while (true) {
                std::fill(depth, depth + id6, -1);
                head = tail = 0;
                depth[__source] = 0;
                queue[tail++] = __source;
                while (head < tail && !~depth[__target])
                    for (uint32_t from = queue[head++], cur = m_starts[from], end = m_starts[from + 1]; cur < end; cur++)
                        if (auto &[from, to, rev, cap] = m_edges[cur]; cap && chmin(depth[to], depth[from] + 1)) queue[tail++] = to;
                if (!~depth[__target]) break;
                std::fill(in_flow, in_flow + id6, 0);
                std::fill(out_flow, out_flow + id6, 0);
                for (uint32_t i = 0; i < id6; i++) in_prev[m_edges.size() + i] = in_next[m_edges.size() + i] = out_prev[m_edges.size() + i] = out_next[m_edges.size() + i] = m_edges.size() + i;
                for (uint32_t index = 0; index < m_edges.size(); index++)
                    if (auto &[from, to, rev, cap] = m_edges[index]; cap && depth[from] + 1 == depth[to] && (depth[to] < depth[__target] || to == __target)) {
                        insert(index, to, in_prev, in_next);
                        insert(index, from, out_prev, out_next);
                        in_flow[to] += cap;
                        out_flow[from] += cap;
                    }
                in_flow[__source] = out_flow[__target] = id5;
                std::fill(flow, flow + id6, id5);
                for (uint32_t i = 0; i < id6; i++) update_flow(i);
                while (true) {
                    uint32_t critical = heap.top();
                    if (flow[critical] == id5) break;
                    if (_Tp f = flow[critical]) {
                        res += f;
                        push(critical, f, __source, false);
                        push(critical, f, __target, true);
                    }
                    flow[critical] = id5;
                    heap.siftDown(critical);
                    remove_node(critical);
                }
            }
            return res;
        }
    };
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        LL D1[n], D2[n];
        for (auto &a : D1) cin >> a;
        for (auto &a : D2) cin >> a;
        std::map<LL, std::vector<std::pair<int, int>>> mp;
        for (int j = 0; j < n; j++) {
            LL sum = D1[0] + D2[j];
            mp[sum].emplace_back(0, j);
            LL dif = std::abs(D1[0] - D2[j]);
            if (dif != sum) mp[dif].emplace_back(0, j);
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                LL sum = D1[i] + D2[j];
                if (auto find = mp.find(sum); find != mp.end()) find->second.emplace_back(i, j);
                LL dif = std::abs(D1[i] - D2[j]);
                if (dif != sum) {
                    if (auto find = mp.find(dif); find != mp.end()) find->second.emplace_back(i, j);
                }
            }
        }
        bool flag = false;
        for (auto &[k, edges] : mp) {
            if (edges.size() >= n) {
                std::bitset<1000> vis;
                for (auto &[a, b] : edges) vis.set(a), vis.set(b);
                if (vis.count() < n) continue;
                OY::Hungarian hk(n, n, edges.size());
                for (auto &[a, b] : edges) hk.addEdge(a, b);
                hk.prepare();
                int res = hk.calc();
                if (res == n) {
                    LL p1 = 0, p2 = k, h[n];
                    for (int i = 0; i < n; i++) {
                        int j = hk.m_leftMatch[i];
                        if (D1[i] + D2[j] == k)
                            h[i] = D1[i];
                        else if (D1[i] > D2[j])
                            h[i] = D1[i];
                        else
                            h[i] = -D1[i];
                    }
                    LL mi = std::min(*std::min_element(h, h + n), 0ll);
                    LL mx = std::max(*std::max_element(h, h + n), k);
                    if (mx > mi + 2000000000) continue;
                    LL d = mi < 0 ? -mi : 0;
                    cout << "YES\n";
                    for (int i = 0; i < n; i++) cout << h[i] + d << ' ';
                    cout << '\n'
                         << p1 + d << ' ' << p2 + d << '\n';
                    flag = true;
                    break;
                }
            }
        }
        if (!flag) cout << "NO\n";
    }
}