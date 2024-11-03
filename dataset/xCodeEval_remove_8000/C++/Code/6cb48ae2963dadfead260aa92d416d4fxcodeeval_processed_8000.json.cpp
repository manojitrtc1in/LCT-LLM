








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
    struct id14 {
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
        id14() : t0(GetMicroSecond()) {}
        void stop() {
            t1 = GetMicroSecond();
            cout << "\ntime cost = " << (t1 - t0) / 10000.0 << " ms\nmemory cost = " << (GetMemory() >> 20) << " MB\n ";
            t0 = t1;
        }
        ~id14() { stop(); }
    };
    return id14();


    return 0;

}();
using LL = long long;
namespace OY {
    template <typename _Sequence>
    struct id12 {
        _Sequence &m_sequence;
        id12(_Sequence &__sequence) : m_sequence(__sequence) {}
        auto &operator()(uint32_t __index) const { return m_sequence[__index]; }
    };
    template <typename _Mapping, typename _Compare = std::less<void>>
    struct id5 {
        std::vector<uint32_t> m_heap;
        std::vector<uint32_t> m_pos;
        _Mapping m_map;
        _Compare m_comp;
        id5(uint32_t __n, _Mapping __map, _Compare __comp = _Compare()) : m_pos(__n, -1), m_map(__map), m_comp(__comp) { m_heap.reserve(__n); }
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
    id5(uint32_t, std::vector<_Tp> &, _Compare) -> id5<id12<std::vector<_Tp>>, _Compare>;
    template <typename _Tp, uint32_t _N, typename _Compare>
    id5(uint32_t, _Tp (&)[_N], _Compare) -> id5<id12<_Tp[_N]>, _Compare>;
}
namespace OY {
    struct Hungarian {
        struct _Edge {
            uint32_t a, b;
        };
        std::vector<_Edge> m_edges;
        std::vector<uint32_t> m_adj, m_starts, m_leftMatch, m_rightMatch;
        uint32_t id10, id6;
        Hungarian(uint32_t id1, uint32_t id0, uint32_t id13) : m_starts(id1 + 1), id10(id1), id6(id0) { m_edges.reserve(id13); }
        void addEdge(uint32_t __a, uint32_t __b) { m_edges.push_back({__a, __b}); }
        void prepare() {
            for (auto &[a, b] : m_edges) m_starts[a + 1]++;
            std::partial_sum(m_starts.begin(), m_starts.end(), m_starts.begin());
            m_adj.resize(m_starts.back());
            uint32_t cursor[id10];
            std::copy(m_starts.begin(), m_starts.begin() + id10, cursor);
            for (uint32_t index = 0; index < m_edges.size(); index++) {
                auto &[a, b] = m_edges[index];
                m_adj[cursor[a]++] = b;
            }
        }
        uint32_t calc() {
            m_leftMatch.resize(id10, -1);
            m_rightMatch.resize(id6, -1);
            std::vector<uint32_t> visit(id10, -1);
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
                for (uint32_t a = 0; a < id10; a++)
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
        _Edge m_edges[1000000];
        uint32_t m_adj[2000000], m_starts[1001], m_leftMatch[1001], m_rightMatch[1001];
        uint32_t id10, id6, id3, cnt;
        id2(uint32_t id1, uint32_t id0, uint32_t id13) {}
        void reset(uint32_t id1, uint32_t id0, uint32_t id13) {
            id10 = id1;
            id6 = id0;
            id3 = id13;
            cnt = 0;
        }
        void addEdge(uint32_t __a, uint32_t __b) { m_edges[cnt++] = {__a, __b}; }
        void prepare() {
            std::fill(m_starts, m_starts + id10 + 1, 0);
            for (uint32_t i = 0; i < cnt; i++) {
                auto &[a, b] = m_edges[i];
                m_starts[a + 1]++;
            }
            std::partial_sum(m_starts, m_starts + id10 + 1, m_starts);
            static uint32_t cursor[1001];
            std::copy(m_starts, m_starts + id10, cursor);
            for (uint32_t index = 0; index < id3; index++) {
                auto &[a, b] = m_edges[index];
                m_adj[cursor[a]++] = b;
            }
        }
        uint32_t calc() {
            static uint32_t dist[1000], queue[1000], visit[1000];
            uint32_t dfn = 0, res = 0;
            auto bfs = [&] {
                std::fill_n(dist, id10, -1);
                uint32_t head = 0, tail = 0;
                for (uint32_t a = 0; a < id10; a++)
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
            std::fill_n(m_leftMatch, id10, -1);
            std::fill_n(m_rightMatch, id6, -1);
            std::fill_n(visit, id6, -1);
            while (true) {
                bfs();
                uint32_t augument = 0;
                for (uint32_t a = 0; a < id10; a++)
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
        uint32_t id8;
        Dinic(uint32_t id11, uint32_t id13) : m_starts(id11 + 1, 0), id8(id11) { m_rawEdges.reserve(id13); }
        void addEdge(uint32_t __a, uint32_t __b, _Tp __cap) { m_rawEdges.push_back({__a, __b, __cap}); }
        void prepare() {
            for (auto &[from, to, cap] : m_rawEdges)
                if (from != to) {
                    m_starts[from + 1]++;
                    m_starts[to + 1]++;
                }
            std::partial_sum(m_starts.begin(), m_starts.end(), m_starts.begin());
            m_edges.resize(m_starts.back());
            uint32_t cursor[id8];
            std::copy(m_starts.begin(), m_starts.begin() + id8, cursor);
            for (auto &[from, to, cap] : m_rawEdges)
                if (from != to) {
                    m_edges[cursor[from]] = _Edge{to, cursor[to], cap};
                    m_edges[cursor[to]++] = _Edge{from, cursor[from]++, 0};
                }
        }
        template <typename _Compare = std::greater<_Edge>>
        void prepareSorted(_Compare __comp = _Compare()) {
            prepare();
            for (uint32_t i = 0; i < id8; i++) {
                uint32_t start = m_starts[i], end = m_starts[i + 1];
                std::sort(m_edges.begin() + start, m_edges.begin() + end, __comp);
                for (uint32_t j = start; j < end; j++) m_edges[m_edges[j].rev].rev = j;
            }
        }
        _Tp calc(uint32_t __source, uint32_t __target, _Tp id7 = std::numeric_limits<_Tp>::max() / 2) {
            uint32_t queue[id8], depth[id8], it[id8], end[id8];
            _Tp res = 0;
            for (uint32_t i = 0; i < id8; i++) end[i] = m_starts[i + 1];
            auto dfs = [&](auto self, uint32_t i, _Tp _cap) {
                if (i == __target || !_cap) return _cap;
                _Tp flow = 0, f;
                for (uint32_t &cur = it[i]; cur != end[i]; cur++)
                    if (auto &[to, rev, cap] = m_edges[cur]; depth[i] + 1 == depth[to] && (f = self(self, to, std::min(_cap, cap))))
                        if (flow += f, _cap -= f, cap -= f, m_edges[rev].cap += f; !_cap) break;
                return flow;
            };
            while (true) {
                std::fill(depth, depth + id8, -1);
                uint32_t head = 0, tail = 0;
                depth[__source] = 0;
                queue[tail++] = __source;
                while (head < tail)
                    for (uint32_t from = queue[head++], cur = m_starts[from], end = m_starts[from + 1]; cur < end; cur++)
                        if (auto &[to, rev, cap] = m_edges[cur]; cap && chmin(depth[to], depth[from] + 1)) queue[tail++] = to;
                if (!~depth[__target]) break;
                for (uint32_t i = 0; i < id8; i++) it[i] = m_starts[i];
                while (_Tp flow = dfs(dfs, __source, id7)) res += flow;
            }
            return res;
        }
    };
}
namespace OY {
    template <template <typename...> typename _Solver = Dinic>
    struct FlowMatcher : _Solver<int> {
        std::vector<uint32_t> m_leftMatch, m_rightMatch;
        uint32_t id10, id6;
        FlowMatcher(uint32_t id1, uint32_t id0, uint32_t id13) : _Solver<int>(id1 + id0 + 2, id13 + id1 + id0), id10(id1), id6(id0) {}
        void addEdge(uint32_t __a, uint32_t __b) { _Solver<int>::addEdge(__a, id10 + __b, 1); }
        void prepare() {
            for (uint32_t i = 0; i < id10; i++) _Solver<int>::addEdge(id10 + id6, i, 1);
            for (uint32_t i = 0; i < id6; i++) _Solver<int>::addEdge(id10 + i, id10 + id6 + 1, 1);
            _Solver<int>::prepare();
        }
        template <bool _GetPath = false>
        uint32_t calc() {
            uint32_t res = _Solver<int>::calc(id10 + id6, id10 + id6 + 1);
            if constexpr (_GetPath) {
                uint32_t cursor[_Solver<int>::id8];
                std::copy(_Solver<int>::m_starts.begin(), _Solver<int>::m_starts.begin() + _Solver<int>::id8, cursor);
                m_leftMatch.resize(id10, -1);
                m_rightMatch.resize(id6, -1);
                for (uint32_t i = 0, iend = _Solver<int>::m_rawEdges.size() - id10 - id6; i < iend; i++) {
                    auto &[from, to, cap] = _Solver<int>::m_rawEdges[i];
                    if (_Solver<int>::m_edges[cursor[to]++].cap) {
                        m_leftMatch[from] = to - id10;
                        m_rightMatch[to - id10] = from;
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
        uint32_t id8;
        ISAP(uint32_t id11, uint32_t id13) : m_starts(id11 + 1, 0), id8(id11) { m_rawEdges.reserve(id13); }
        void addEdge(uint32_t __a, uint32_t __b, _Tp __cap) { m_rawEdges.push_back({__a, __b, __cap}); }
        void prepare() {
            for (auto &[from, to, cap] : m_rawEdges)
                if (from != to) {
                    m_starts[from + 1]++;
                    m_starts[to + 1]++;
                }
            std::partial_sum(m_starts.begin(), m_starts.end(), m_starts.begin());
            m_edges.resize(m_starts.back());
            uint32_t cursor[id8];
            std::copy(m_starts.begin(), m_starts.begin() + id8, cursor);
            for (auto &[from, to, cap] : m_rawEdges)
                if (from != to) {
                    m_edges[cursor[from]] = _Edge{to, cursor[to], cap};
                    m_edges[cursor[to]++] = _Edge{from, cursor[from]++, 0};
                }
        }
        template <typename _Compare = std::greater<_Edge>>
        void prepareSorted(_Compare __comp = _Compare()) {
            prepare();
            for (uint32_t i = 0; i < id8; i++) {
                uint32_t start = m_starts[i], end = m_starts[i + 1];
                std::sort(m_edges.begin() + start, m_edges.begin() + end, __comp);
                for (uint32_t j = start; j < end; j++) m_edges[m_edges[j].rev].rev = j;
            }
        }
        _Tp calc(uint32_t __source, uint32_t __target, _Tp id7 = std::numeric_limits<_Tp>::max() / 2) {
            uint32_t queue[id8], depth[id8], head = 0, tail = 0, num[id8 + 1], point[id8], prev[id8], len = 0, it[id8], end[id8];
            _Tp res = 0;
            std::fill(depth, depth + id8, id8);
            depth[__target] = 0;
            queue[tail++] = __target;
            while (head < tail)
                for (uint32_t from = queue[head++], cur = m_starts[from], end = m_starts[from + 1]; cur < end; cur++)
                    if (auto &[to, rev, cap] = m_edges[cur]; m_edges[rev].cap && chmin(depth[to], depth[from] + 1)) queue[tail++] = to;
            if (depth[__source] == id8) return res;
            std::fill(num, num + id8 + 1, 0);
            for (uint32_t i = 0; i < id8; i++) num[depth[i]]++;
            for (uint32_t i = 0; i < id8; i++) it[i] = m_starts[i];
            for (uint32_t i = 0; i < id8; i++) end[i] = m_starts[i + 1];
            point[len++] = __source;
            while (depth[__source] < id8)
                if (uint32_t x = point[len - 1]; x == __target) {
                    _Tp flow = id7;
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
                        depth[x] = id8;
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
    struct id9 {
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
        uint32_t id8;
        id9(uint32_t id11, uint32_t id13) : m_starts(id11 + 1, 0), id8(id11) { m_rawEdges.reserve(id13); }
        void addEdge(uint32_t __a, uint32_t __b, _Tp __cap) { m_rawEdges.push_back({__a, __b, __cap}); }
        void prepare() {
            for (auto &[from, to, cap] : m_rawEdges)
                if (from != to) {
                    m_starts[from + 1]++;
                    m_starts[to + 1]++;
                }
            std::partial_sum(m_starts.begin(), m_starts.end(), m_starts.begin());
            m_edges.resize(m_starts.back());
            uint32_t cursor[id8];
            std::copy(m_starts.begin(), m_starts.begin() + id8, cursor);
            for (auto &[from, to, cap] : m_rawEdges)
                if (from != to) {
                    m_edges[cursor[from]] = _Edge{to, cursor[to], cap};
                    m_edges[cursor[to]++] = _Edge{from, cursor[from]++, 0};
                }
        }
        template <typename _Compare = std::greater<_Edge>>
        void prepareSorted(_Compare __comp = _Compare()) {
            prepare();
            for (uint32_t i = 0; i < id8; i++) {
                uint32_t start = m_starts[i], end = m_starts[i + 1];
                std::sort(m_edges.begin() + start, m_edges.begin() + end, __comp);
                for (uint32_t j = start; j < end; j++) m_edges[m_edges[j].rev].rev = j;
            }
        }
        _Tp calc(uint32_t __source, uint32_t __target, _Tp id7 = std::numeric_limits<_Tp>::max() / 2) {
            std::vector<bool> visit(id8, false);
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
            while (_Tp flow = dfs(dfs, __source, id7)) {
                res += flow;
                std::fill(visit.begin(), visit.end(), false);
            }
            return res;
        }
    };
}
namespace OY {
    template <typename _Tp>
    struct id4 {
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
        uint32_t id8;
        id4(uint32_t id11, uint32_t id13) : m_starts(id11 + 1, 0), id8(id11) { m_rawEdges.reserve(id13); }
        void addEdge(uint32_t __a, uint32_t __b, _Tp __cap) { m_rawEdges.push_back({__a, __b, __cap}); }
        void prepare() {
            for (auto &[from, to, cap] : m_rawEdges)
                if (from != to) {
                    m_starts[from + 1]++;
                    m_starts[to + 1]++;
                }
            std::partial_sum(m_starts.begin(), m_starts.end(), m_starts.begin());
            m_edges.resize(m_starts.back());
            uint32_t cursor[id8];
            std::copy(m_starts.begin(), m_starts.begin() + id8, cursor);
            for (auto &[from, to, cap] : m_rawEdges)
                if (from != to) {
                    m_edges[cursor[from]] = _Edge{to, cursor[to], cap};
                    m_edges[cursor[to]++] = _Edge{from, cursor[from]++, 0};
                }
        }
        template <typename _Compare = std::greater<_Edge>>
        void prepareSorted(_Compare __comp = _Compare()) {
            prepare();
            for (uint32_t i = 0; i < id8; i++) {
                uint32_t start = m_starts[i], end = m_starts[i + 1];
                std::sort(m_edges.begin() + start, m_edges.begin() + end, __comp);
                for (uint32_t j = start; j < end; j++) m_edges[m_edges[j].rev].rev = j;
            }
        }
        _Tp calc(uint32_t __source, uint32_t __target, _Tp id7 = std::numeric_limits<_Tp>::max() / 2) {
            uint32_t queue[id8], fromEdge[id8], prev[id8];
            _Tp res = 0, flow[id8], f;
            while (true) {
                std::fill(flow, flow + id8, 0);
                uint32_t head = 0, tail = 0;
                flow[__source] = id7;
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
        uint32_t id8;
        MPM(uint32_t id11, uint32_t id13) : m_starts(id11 + 1, 0), id8(id11) { m_rawEdges.reserve(id13); }
        void addEdge(uint32_t __a, uint32_t __b, _Tp __cap) { m_rawEdges.push_back({__a, __b, __cap}); }
        void prepare() {
            for (auto &[from, to, cap] : m_rawEdges)
                if (from != to) {
                    m_starts[from + 1]++;
                    m_starts[to + 1]++;
                }
            std::partial_sum(m_starts.begin(), m_starts.end(), m_starts.begin());
            m_edges.resize(m_starts.back());
            uint32_t cursor[id8];
            std::copy(m_starts.begin(), m_starts.begin() + id8, cursor);
            for (auto &[from, to, cap] : m_rawEdges)
                if (from != to) {
                    m_edges[cursor[from]] = _Edge{from, to, cursor[to], cap};
                    m_edges[cursor[to]++] = _Edge{to, from, cursor[from]++, 0};
                }
        }
        template <typename _Compare = std::greater<_Edge>>
        void prepareSorted(_Compare __comp = _Compare()) {
            prepare();
            for (uint32_t i = 0; i < id8; i++) {
                uint32_t start = m_starts[i], end = m_starts[i + 1];
                std::sort(m_edges.begin() + start, m_edges.begin() + end, __comp);
                for (uint32_t j = start; j < end; j++) m_edges[m_edges[j].rev].rev = j;
            }
        }
        _Tp calc(uint32_t __source, uint32_t __target, _Tp id7 = std::numeric_limits<_Tp>::max() / 2) {
            _Tp res = 0, in_flow[id8], out_flow[id8], flow[id8], ex[id8];
            uint32_t queue[id8], depth[id8], head, tail, in_prev[m_edges.size() + id8], in_next[m_edges.size() + id8], out_prev[m_edges.size() + id8], out_next[m_edges.size() + id8];
            auto mapping = [&](uint32_t i) { return flow[i]; };
            id5 heap(id8, mapping, std::greater<_Tp>{});
            for (uint32_t i = 0; i < id8; i++) heap.m_heap.push_back(heap.m_pos[i] = i);
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
                std::fill(ex, ex + id8, 0);
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
                std::fill(depth, depth + id8, -1);
                head = tail = 0;
                depth[__source] = 0;
                queue[tail++] = __source;
                while (head < tail && !~depth[__target])
                    for (uint32_t from = queue[head++], cur = m_starts[from], end = m_starts[from + 1]; cur < end; cur++)
                        if (auto &[from, to, rev, cap] = m_edges[cur]; cap && chmin(depth[to], depth[from] + 1)) queue[tail++] = to;
                if (!~depth[__target]) break;
                std::fill(in_flow, in_flow + id8, 0);
                std::fill(out_flow, out_flow + id8, 0);
                for (uint32_t i = 0; i < id8; i++) in_prev[m_edges.size() + i] = in_next[m_edges.size() + i] = out_prev[m_edges.size() + i] = out_next[m_edges.size() + i] = m_edges.size() + i;
                for (uint32_t index = 0; index < m_edges.size(); index++)
                    if (auto &[from, to, rev, cap] = m_edges[index]; cap && depth[from] + 1 == depth[to] && (depth[to] < depth[__target] || to == __target)) {
                        insert(index, to, in_prev, in_next);
                        insert(index, from, out_prev, out_next);
                        in_flow[to] += cap;
                        out_flow[from] += cap;
                    }
                in_flow[__source] = out_flow[__target] = id7;
                std::fill(flow, flow + id8, id7);
                for (uint32_t i = 0; i < id8; i++) update_flow(i);
                while (true) {
                    uint32_t critical = heap.top();
                    if (flow[critical] == id7) break;
                    if (_Tp f = flow[critical]) {
                        res += f;
                        push(critical, f, __source, false);
                        push(critical, f, __target, true);
                    }
                    flow[critical] = id7;
                    heap.siftDown(critical);
                    remove_node(critical);
                }
            }
            return res;
        }
    };
}

OY::id2 hk(1000, 1000, 1000000);
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
                hk.reset(n, n, edges.size());
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