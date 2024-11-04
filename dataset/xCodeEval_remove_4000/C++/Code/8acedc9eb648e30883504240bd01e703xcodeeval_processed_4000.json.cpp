








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
    struct id9 {
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
        id9() : t0(GetMicroSecond()) {}
        void stop() {
            t1 = GetMicroSecond();
            cout << "\ntime cost = " << (t1 - t0) / 10000.0 << " ms\nmemory cost = " << (GetMemory() >> 20) << " MB\n ";
            t0 = t1;
        }
        ~id9() { stop(); }
    };
    return id9();


    return 0;

}();
using LL = long long;
namespace OY {
    template <typename _Tp = int>
    class Discretizer : public std::vector<_Tp> {
        using std::vector<_Tp>::vector, std::vector<_Tp>::begin, std::vector<_Tp>::end, std::vector<_Tp>::insert, std::vector<_Tp>::push_back, std::vector<_Tp>::resize;

    public:
        Discretizer &operator<<(const _Tp &__item) {
            push_back(__item);
            return *this;
        }
        Discretizer &operator<<(const std::vector<_Tp> &__items) {
            insert(end(), __items.begin(), __items.end());
            return *this;
        }
        Discretizer &operator<<(const std::vector<std::vector<_Tp>> &__items) {
            for (auto &each : __items) *this << each;
            return *this;
        }
        void prepare() {
            std::sort(begin(), end());
            resize(std::unique(begin(), end()) - begin());
        }
        int rank(const _Tp &__item) {
            return lower_bound(__item);
        }
        int lower_bound(const _Tp &__item) {
            return std::lower_bound(begin(), end(), __item) - begin();
        }
        int upper_bound(const _Tp &__item) {
            return std::upper_bound(begin(), end(), __item) - begin();
        }
    };
}
namespace OY {
    template <typename _Tp, int batch = 1 << 15>
    struct MemoryPool {
        static inline std::vector<_Tp *> s_pool;
        static inline std::vector<_Tp *> s_gc;
        static inline _Tp *s_cursor = nullptr;
        static inline _Tp *s_end = nullptr;
        static void _reserve(int __count = batch) {
            s_pool.push_back((_Tp *)malloc(__count * sizeof(_Tp)));
            s_cursor = s_pool.back();
            s_end = s_cursor + __count;
        }
        static void *operator new(size_t) {
            if (s_gc.size()) {
                auto it = s_gc.back();
                s_gc.pop_back();
                return it;
            } else if (s_cursor == s_end)
                _reserve();
            return s_cursor++;
        }
        static void operator delete(void *it) { s_gc.push_back((_Tp *)it); }
        static void recycle(_Tp *it) { s_gc.push_back(it); }
    };
}
namespace OY {
    template <typename _Tp, typename _Operation = std::plus<_Tp>>
    struct id0 {
        struct id6 : MemoryPool<id6> {
            _Tp val;
            id6 *lchild;
            id6 *rchild;
            id6(_Tp _val, id6 *_lchild, id6 *_rchild) : val(_val), lchild(_lchild), rchild(_rchild) {}
        };
        std::vector<id6 *> m_roots;
        int m_length;
        _Operation m_op;
        _Tp m_defaultValue;
        void _check() {
            

        }
        id6 *lchild(id6 *cur) {
            if (!cur->lchild)
                cur->lchild = new id6(m_defaultValue, nullptr, nullptr);
            return cur->lchild;
        }
        id6 *rchild(id6 *cur) {
            if (!cur->rchild)
                cur->rchild = new id6(m_defaultValue, nullptr, nullptr);
            return cur->rchild;
        }
        id6 *_update(id6 *cur) {
            cur->val = m_op(cur->lchild ? cur->lchild->val : m_defaultValue, cur->rchild ? cur->rchild->val : m_defaultValue);
            return cur;
        }
        id6 *_root(int version) const { return ~version ? m_roots[version] : m_roots.back(); }
        void _clear() { m_roots.clear(); }
        static void setBufferSize(int __count) { MemoryPool<id6>::_reserve(__count); }
        id0(int __n = 0, _Operation __op = _Operation(), _Tp id1 = _Tp()) : m_op(__op), m_defaultValue(id1) {
            _check();
            resize(__n);
        }
        template <typename _Iterator>
        id0(_Iterator __first, _Iterator __last, _Operation __op = _Operation(), _Tp id1 = _Tp()) : m_op(__op), m_defaultValue(id1) {
            _check();
            reset(__first, __last);
        }
        void resize(int __n) {
            _clear();
            if (m_length = __n) m_roots.push_back(new id6(m_defaultValue, nullptr, nullptr));
        }
        template <typename _Iterator>
        void reset(_Iterator __first, _Iterator __last) {
            _clear();
            m_length = __last - __first;
            auto dfs = [&](auto self, _Iterator first, _Iterator last) -> id6 * {
                if (first + 1 == last)
                    return new id6(*first, nullptr, nullptr);
                else
                    return _update(new id6(*first, self(self, first, first + (last - first + 1) / 2), self(self, first + (last - first + 1) / 2, last)));
            };
            m_roots.push_back(dfs(dfs, __first, __last));
        }
        void copyVersion(int id4) {
            m_roots.push_back(_root(id4));
        }
        void update(int id4, int __i, _Tp __val) {
            auto dfs = [&](auto self, id6 *prev, int left, int right) -> id6 * {
                id6 *cur = prev ? new id6(*prev) : new id6(m_defaultValue, nullptr, nullptr);
                if (left == right)
                    cur->val = __val;
                else {
                    if (__i <= (left + right) / 2)
                        cur->lchild = self(self, cur->lchild, left, (left + right) / 2);
                    else
                        cur->rchild = self(self, cur->rchild, (left + right) / 2 + 1, right);
                    _update(cur);
                }
                return cur;
            };
            m_roots.push_back(dfs(dfs, _root(id4), 0, m_length - 1));
        }
        void add(int id4, int __i, _Tp __inc) {
            auto dfs = [&](auto self, id6 *prev, int left, int right) -> id6 * {
                id6 *cur = prev ? new id6(*prev) : new id6(m_defaultValue, nullptr, nullptr);
                if (left == right)
                    cur->val = m_op(cur->val, __inc);
                else {
                    if (__i <= (left + right) / 2)
                        cur->lchild = self(self, cur->lchild, left, (left + right) / 2);
                    else
                        cur->rchild = self(self, cur->rchild, (left + right) / 2 + 1, right);
                    _update(cur);
                }
                return cur;
            };
            m_roots.push_back(dfs(dfs, _root(id4), 0, m_length - 1));
        }
        _Tp query(int __version, int __i) const {
            auto dfs = [&](auto self, id6 *cur, int left, int right) {
                if (left == right)
                    return cur->val;
                else if (__i <= (left + right) / 2)
                    return cur->lchild ? self(self, cur->lchild, left, (left + right) / 2) : m_defaultValue;
                else
                    return cur->rchild ? self(self, cur->rchild, (left + right) / 2 + 1, right) : m_defaultValue;
            };
            return dfs(dfs, _root(__version), 0, m_length - 1);
        }
        _Tp query(int __version, int __left, int __right) const {
            auto dfs = [&](auto self, id6 *cur, int left, int right) {
                if (left >= __left && right <= __right)
                    return cur->val;
                else if (__right <= (left + right) / 2)
                    return cur->lchild ? self(self, cur->lchild, left, (left + right) / 2) : m_defaultValue;
                else if (__left > (left + right) / 2)
                    return cur->rchild ? self(self, cur->rchild, (left + right) / 2 + 1, right) : m_defaultValue;
                else
                    return m_op(cur->lchild ? self(self, cur->lchild, left, (left + right) / 2) : m_defaultValue, cur->rchild ? self(self, cur->rchild, (left + right) / 2 + 1, right) : m_defaultValue);
            };
            return dfs(dfs, _root(__version), 0, m_length - 1);
        }
        _Tp queryAll(int __version) const {
            return _root(__version)->val;
        }
        int kth(int __version, _Tp __k) const {
            auto dfs = [&](auto self, id6 *cur, int left, int right, int k) {
                if (left == right) return left;
                if (cur->lchild) {
                    if (cur->lchild->val > k)
                        return self(self, cur->lchild, left, (left + right) / 2, k);
                    else
                        return self(self, cur->rchild, (left + right) / 2 + 1, right, k - cur->lchild->val);
                } else
                    return self(self, cur->rchild, (left + right) / 2 + 1, right, k);
            };
            return dfs(dfs, _root(__version), 0, m_length - 1, __k);
        }
        _Tp periodQuery(int id3, int id2, int __i) const {
            if (id3 == 0) return query(id2, __i);
            auto dfs = [&](auto self, id6 *root1, id6 *root2, int left, int right) {
                if (root1 == root2) return 0;
                if (left == right)
                    return root1 ? root2->val - root1->val : root2->val;
                else if (__i <= (left + right) / 2)
                    return self(self, root1 ? root1->lchild : nullptr, root2->lchild, left, (left + right) / 2);
                else
                    return self(self, root1 ? root1->rchild : nullptr, root2->rchild, (left + right) / 2 + 1, right);
            };
            return dfs(dfs, _root(id3 - 1), _root(id2), 0, m_length - 1);
        }
        _Tp periodQuery(int id3, int id2, int __left, int __right) const {
            if (id3 == 0) return query(id2, __left, __right);
            auto dfs = [&](auto self, id6 *root1, id6 *root2, int left, int right) -> _Tp {
                if (root1 == root2) return 0;
                if (left >= __left && right <= __right)
                    return root1 ? root2->val - root1->val : root2->val;
                else if (__right <= (left + right) / 2)
                    return self(self, root1 ? root1->lchild : nullptr, root2->lchild, left, (left + right) / 2);
                else if (__left > (left + right) / 2)
                    return self(self, root1 ? root1->rchild : nullptr, root2->rchild, (left + right) / 2 + 1, right);
                else
                    return self(self, root1 ? root1->lchild : nullptr, root2->lchild, left, (left + right) / 2) + self(self, root1 ? root1->rchild : nullptr, root2->rchild, (left + right) / 2 + 1, right);
            };
            return dfs(dfs, _root(id3 - 1), _root(id2), 0, m_length - 1);
        }
        int periodKth(int id3, int id2, _Tp __k) const {
            if (id3 == 0) return kth(id2, __k);
            auto dfs = [&](auto self, id6 *root1, id6 *root2, int left, int right, int k) {
                if (left == right) return left;
                if (!root1 || !root1->lchild) {
                    if (!root2->lchild)
                        return self(self, root1 && root1->rchild ? root1->rchild : nullptr, root2->rchild, (left + right) / 2 + 1, right, k);
                    else if (root2->lchild->val > k)
                        return self(self, nullptr, root2->lchild, left, (left + right) / 2, k);
                    else
                        return self(self, root1 && root1->rchild ? root1->rchild : nullptr, root2->rchild, (left + right) / 2 + 1, right, k - root2->lchild->val);
                } else if (root2->lchild->val - root1->lchild->val > k)
                    return self(self, root1->lchild, root2->lchild, left, (left + right) / 2, k);
                else
                    return self(self, root1->rchild, root2->rchild, (left + right) / 2 + 1, right, k - root2->lchild->val + root1->lchild->val);
            };
            return dfs(dfs, _root(id3 - 1), _root(id2), 0, m_length - 1, __k);
        }
        int versionCount() const { return m_roots.size(); }
    };
    template <typename _Tp = int64_t>
    id0(int, const _Tp &(*)(const _Tp &, const _Tp &), _Tp = _Tp()) -> id0<_Tp, const _Tp &(*)(const _Tp &, const _Tp &)>;
    template <typename _Tp = int64_t>
    id0(int, _Tp (*)(_Tp, _Tp), _Tp = _Tp()) -> id0<_Tp, _Tp (*)(_Tp, _Tp)>;
    template <typename _Operation = std::plus<int64_t>, typename _Tp = std::decay_t<typename decltype(std::mem_fn(&_Operation::operator()))::result_type>>
    id0(int = 0, _Operation = _Operation(), _Tp = _Tp()) -> id0<_Tp, _Operation>;
    template <typename _Iterator, typename _Tp = typename std::iterator_traits<_Iterator>::value_type>
    id0(_Iterator, _Iterator, const _Tp &(*)(const _Tp &, const _Tp &), _Tp = _Tp()) -> id0<_Tp, const _Tp &(*)(const _Tp &, const _Tp &)>;
    template <typename _Iterator, typename _Tp = typename std::iterator_traits<_Iterator>::value_type>
    id0(_Iterator, _Iterator, _Tp (*)(_Tp, _Tp), _Tp = _Tp()) -> id0<_Tp, _Tp (*)(_Tp, _Tp)>;
    template <typename _Iterator, typename _Tp = typename std::iterator_traits<_Iterator>::value_type, typename _Operation = std::plus<_Tp>>
    id0(_Iterator, _Iterator, _Operation = _Operation(), _Tp = _Tp()) -> id0<_Tp, _Operation>;
}
namespace OY {
    template <typename _Tp, bool id8 = true>
    struct id5 {
        id0<uint32_t, std::plus<uint32_t>> m_tree;
        std::vector<uint32_t> m_versions;
        std::vector<_Tp> m_items;
        template <typename _Iterator>
        id5(_Iterator __first, _Iterator __last, uint32_t __range = 0) : m_tree(__last - __first) {
            if constexpr (id8) {
                m_items.assign(__first, __last);
                std::sort(m_items.begin(), m_items.end());
                m_items.erase(std::unique(m_items.begin(), m_items.end()), m_items.end());
                __range = std::max<uint32_t>(__range, m_items.size());
            } else
                __range = std::max<uint32_t>(__range, *std::max_element(__first, __last));
            uint32_t first[__range], next[m_tree.m_length];
            std::fill_n(first, __range, -1);
            for (uint32_t i = 0; i < m_tree.m_length; i++) {
                uint32_t item = mapped(__first[i]);
                next[i] = first[item];
                first[item] = i;
            }
            m_versions.reserve(__range);
            for (uint32_t i = 0; i < __range; i++) {
                for (uint32_t x = first[i]; ~x; x = next[x]) m_tree.add(-1, x, 1);
                m_versions.push_back(m_tree.versionCount() - 1);
            }
        }
        uint32_t mapped(_Tp __item) const {
            if constexpr (id8)
                return std::lower_bound(m_items.begin(), m_items.end(), __item) - m_items.begin();
            else
                return __item;
        }
        uint32_t queryFirstBigger(uint32_t __left, uint32_t __right, _Tp __item) const {
            auto dfs = [&](auto self, id0<uint32_t, std::plus<uint32_t>>::id6 *cur, uint32_t left, uint32_t right) -> uint32_t {
                if (cur->val == right - left + 1)
                    return -1;
                else if (__right <= (left + right) / 2)
                    return cur->lchild ? self(self, cur->lchild, left, (left + right) / 2) : std::max(__left, left);
                else if (__left > (left + right) / 2)
                    return cur->rchild ? self(self, cur->rchild, (left + right) / 2 + 1, right) : __left;
                else if (uint32_t res = cur->lchild ? self(self, cur->lchild, left, (left + right) / 2) : std::max(__left, left); ~res)
                    return res;
                else
                    return cur->rchild ? self(self, cur->rchild, (left + right) / 2 + 1, right) : (left + right) / 2 + 1;
            };
            return dfs(dfs, m_tree.m_roots[m_versions[mapped(__item)]], 0, m_tree.m_length - 1);
        }
        uint32_t queryLastBigger(uint32_t __left, uint32_t __right, _Tp __item) const {
            auto dfs = [&](auto self, id0<uint32_t, std::plus<uint32_t>>::id6 *cur, uint32_t left, uint32_t right) -> uint32_t {
                if (cur->val == right - left + 1)
                    return -1;
                else if (__right <= (left + right) / 2)
                    return cur->lchild ? self(self, cur->lchild, left, (left + right) / 2) : (left + right) / 2;
                else if (__left > (left + right) / 2)
                    return cur->rchild ? self(self, cur->rchild, (left + right) / 2 + 1, right) : std::max(__right, right);
                else if (uint32_t res = cur->rchild ? self(self, cur->rchild, (left + right) / 2 + 1, right) : std::min(__right, right); ~res)
                    return res;
                else
                    return cur->lchild ? self(self, cur->lchild, left, (left + right) / 2) : (left + right) / 2;
            };
            return dfs(dfs, m_tree.m_roots[m_versions[mapped(__item)]], 0, m_tree.m_length - 1);
        }
        uint32_t queryFirstSmaller(uint32_t __left, uint32_t __right, _Tp __item) const {
            auto dfs = [&](auto self, id0<uint32_t, std::plus<uint32_t>>::id6 *cur, uint32_t left, uint32_t right) -> uint32_t {
                if (cur->val == right - left + 1)
                    return std::max(__left, left);
                else if (__right <= (left + right) / 2)
                    return cur->lchild ? self(self, cur->lchild, left, (left + right) / 2) : -1;
                else if (__left > (left + right) / 2)
                    return cur->rchild ? self(self, cur->rchild, (left + right) / 2 + 1, right) : -1;
                else if (uint32_t res = cur->lchild ? self(self, cur->lchild, left, (left + right) / 2) : -1; ~res)
                    return res;
                else
                    return cur->rchild ? self(self, cur->rchild, (left + right) / 2 + 1, right) : -1;
            };
            uint32_t item = mapped(__item);
            return item ? dfs(dfs, m_tree.m_roots[m_versions[item - 1]], 0, m_tree.m_length - 1) : -1;
        }
        uint32_t queryLastSmaller(uint32_t __left, uint32_t __right, _Tp __item) const {
            auto dfs = [&](auto self, id0<uint32_t, std::plus<uint32_t>>::id6 *cur, uint32_t left, uint32_t right) -> uint32_t {
                if (cur->val == right - left + 1)
                    return std::min(__right, right);
                else if (__right <= (left + right) / 2)
                    return cur->lchild ? self(self, cur->lchild, left, (left + right) / 2) : -1;
                else if (__left > (left + right) / 2)
                    return cur->rchild ? self(self, cur->rchild, (left + right) / 2 + 1, right) : -1;
                else if (uint32_t res = cur->rchild ? self(self, cur->rchild, (left + right) / 2 + 1, right) : -1; ~res)
                    return res;
                else
                    return cur->lchild ? self(self, cur->lchild, left, (left + right) / 2) : -1;
            };
            uint32_t item = mapped(__item);
            return item ? dfs(dfs, m_tree.m_roots[m_versions[item - 1]], 0, m_tree.m_length - 1) : -1;
        }
    };
}
namespace OY {
    template <typename _Tp = int64_t, typename _Operation = std::plus<_Tp>>
    class id7 {
        std::vector<_Tp> m_sub;
        int m_length;
        int m_depth;
        _Operation m_op;
        _Tp m_defaultValue;
        void _check() {
            

        }
        void _update(int cur) {
            m_sub[cur] = m_op(m_sub[cur * 2], m_sub[cur * 2 + 1]);
        }

    public:
        id7(int __n = 0, _Operation __op = _Operation(), _Tp id1 = _Tp()) : m_op(__op), m_defaultValue(id1) {
            _check();
            resize(__n);
        }
        template <typename _Iterator>
        id7(_Iterator __first, _Iterator __last, _Operation __op = _Operation(), _Tp id1 = _Tp()) : m_op(__op), m_defaultValue(id1) {
            _check();
            reset(__first, __last);
        }
        void resize(int __n) {
            if (!__n) return;
            m_length = __n;
            m_depth = 32 - (m_length > 1 ? std::__countl_zero<uint32_t>(m_length - 1) : 32);
            m_sub.assign(1 << (m_depth + 1), m_defaultValue);
        }
        template <typename _Iterator>
        void reset(_Iterator __first, _Iterator __last) {
            m_length = __last - __first;
            m_depth = 32 - (m_length > 1 ? std::__countl_zero<uint32_t>(m_length - 1) : 32);
            m_sub.resize(1 << (m_depth + 1));
            std::copy(__first, __last, m_sub.begin() + (1 << m_depth));
            std::fill(m_sub.begin() + (1 << m_depth) + m_length, m_sub.end(), m_defaultValue);
            for (int i = 1 << m_depth; --i;) _update(i);
        }
        void update(int __i, _Tp __val) {
            __i += 1 << m_depth;
            m_sub[__i] = __val;
            while (__i >>= 1) _update(__i);
        }
        void add(int __i, _Tp __inc) {
            __i += 1 << m_depth;
            m_sub[__i] = m_op(m_sub[__i], __inc);
            while (__i >>= 1) _update(__i);
        }
        _Tp query(int __i) const {
            return m_sub[(1 << m_depth) + __i];
        }
        _Tp query(int __left, int __right) const {
            if (__left == __right) return m_sub[(1 << m_depth) + __left];
            __left += 1 << m_depth;
            __right += 1 << m_depth;
            _Tp res = m_sub[__left];
            int j = 31 - std::__countl_zero<uint32_t>(__left ^ __right);
            for (int i = 0; i < j; i++)
                if (!(__left >> i & 1)) res = m_op(res, m_sub[__left >> i ^ 1]);
            for (int i = j - 1; i >= 0; i--)
                if (__right >> i & 1) res = m_op(res, m_sub[__right >> i ^ 1]);
            return m_op(res, m_sub[__right]);
        }
        _Tp queryAll() const {
            return m_sub[1];
        }
        int kth(_Tp __k) const {
            int i = 1;
            while (i < 1 << m_depth)
                if (m_sub[i *= 2] <= __k) __k -= m_sub[i++];
            return i - (1 << m_depth);
        }
    };
    template <typename _Tp = int64_t>
    id7(int, const _Tp &(*)(const _Tp &, const _Tp &), _Tp = _Tp(), _Tp = _Tp()) -> id7<_Tp, const _Tp &(*)(const _Tp &, const _Tp &)>;
    template <typename _Tp = int64_t>
    id7(int, _Tp (*)(_Tp, _Tp), _Tp = _Tp(), _Tp = _Tp()) -> id7<_Tp, _Tp (*)(_Tp, _Tp)>;
    template <typename _Operation = std::plus<int64_t>, typename _Tp = std::decay_t<typename decltype(std::mem_fn(&_Operation::operator()))::result_type>>
    id7(int = 0, _Operation = _Operation(), _Tp = _Tp(), _Tp = _Tp()) -> id7<_Tp, _Operation>;
    template <typename _Iterator, typename _Tp = typename std::iterator_traits<_Iterator>::value_type>
    id7(_Iterator, _Iterator, const _Tp &(*)(const _Tp &, const _Tp &), _Tp = _Tp(), _Tp = _Tp()) -> id7<_Tp, const _Tp &(*)(const _Tp &, const _Tp &)>;
    template <typename _Iterator, typename _Tp = typename std::iterator_traits<_Iterator>::value_type>
    id7(_Iterator, _Iterator, _Tp (*)(_Tp, _Tp), _Tp = _Tp(), _Tp = _Tp()) -> id7<_Tp, _Tp (*)(_Tp, _Tp)>;
    template <typename _Iterator, typename _Tp = typename std::iterator_traits<_Iterator>::value_type, typename _Operation = std::plus<_Tp>>
    id7(_Iterator, _Iterator, _Operation = _Operation(), _Tp = _Tp(), _Tp = _Tp()) -> id7<_Tp, _Operation>;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        LL A[n + 1];
        for (int i = 1; i <= n; i++) cin >> A[i];
        LL S[n + 1];
        for (int i = 0; i <= n; i++) S[i] = i ? S[i - 1] + A[i] : 0;
        OY::Discretizer<LL> D;
        for (int i = 0; i <= n; i++) D << S[i];
        D.prepare();
        int S2[n + 1];
        for (int i = 0; i <= n; i++) S2[i] = D.rank(S[i]);
        OY::id5<int, true> fbs(S2, S2 + n + 1, n + 1);

        int indexes[n + 1];
        std::iota(indexes, indexes + n + 1, 0);
        auto get_max = [&](int x, int y) {
            if (S[x] != S[y])
                return S[x] < S[y] ? y : x;
            else
                return x < y ? y : x;
        };
        OY::id7 T(indexes, indexes + n + 1, get_max);
        auto get_min = [&](int x, int y) {
            if (S[x] != S[y])
                return S[x] < S[y] ? x : y;
            else
                return x < y ? x : y;
        };
        OY::id7 T2(indexes, indexes + n + 1, get_min);

        int l = k, r = k, stop = 0;
        while (true) {
            if (l == 1 or r == n) break;
            int r_bound = fbs.queryFirstSmaller(r + 1, n, S2[l - 1]);
            if (!~r_bound) {
                r = n;
                break;
            }
            if (r_bound > r + 1) {
                int r2 = T.query(r + 1, r_bound - 1);
                if (S[r2] < S[r]) r2 = r;
                if (r != r2) {
                    r = r2;
                    stop = 0;
                } else if (++stop == 2)
                    break;
            } else if (++stop == 2)
                break;

            int l_bound = fbs.queryLastBigger(0, l - 2, S2[r]);
            if (!~l_bound) {
                l = 1;
                break;
            }
            if (l_bound < l - 2) {
                int l2 = T2.query(l_bound + 1, l - 2);
                if (S[l2] > S[l - 1]) l2 = l - 1;
                if (l != l2 + 1) {
                    l = l2 + 1;
                    stop = 0;
                } else if (++stop == 2)
                    break;
            } else if (++stop == 2)
                break;
        }
        YESNO(l == 1 or r == n);
    }
}