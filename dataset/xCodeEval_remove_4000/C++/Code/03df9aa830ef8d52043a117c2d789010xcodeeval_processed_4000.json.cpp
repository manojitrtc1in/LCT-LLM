









template <typename _Tp, typename _Fp, typename _Compare = std::less<void>>
bool chmax(_Tp &a, const _Fp &b, _Compare __comp = _Compare()) { return __comp(a, b) ? a = b, true : false; }
template <typename _Tp, typename _Fp, typename _Compare = std::less<void>>
bool chmin(_Tp &a, const _Fp &b, _Compare __comp = _Compare()) { return __comp(b, a) ? a = b, true : false; }
using std::cin, std::cout, std::endl;
namespace OY {
    template <typename _Sequence>
    struct id3 {
        _Sequence &m_sequence;
        id3(_Sequence &__sequence) : m_sequence(__sequence) {}
        auto &operator()(uint32_t __index) const { return m_sequence[__index]; }
    };
    template <typename _Mapping, typename _Compare = std::less<void>>
    struct id0 {
        std::vector<uint32_t> m_heap;
        std::vector<uint32_t> m_pos;
        _Mapping m_map;
        _Compare m_comp;
        id0(uint32_t __n, _Mapping __map, _Compare __comp = _Compare()) : m_pos(__n, -1), m_map(__map), m_comp(__comp) { m_heap.reserve(__n); }
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
    id0(uint32_t, std::vector<_Tp> &, _Compare) -> id0<id3<std::vector<_Tp>>, _Compare>;
    template <typename _Tp, uint32_t _N, typename _Compare>
    id0(uint32_t, _Tp (&)[_N], _Compare) -> id0<id3<_Tp[_N]>, _Compare>;
}
auto tam = [] {


    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    struct id4 {
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
        id4() : t0(GetMicroSecond()) {}
        void stop() {
            t1 = GetMicroSecond();
            cout << "\ntime cost = " << (t1 - t0) / 10000.0 << " ms\nmemory cost = " << (GetMemory() >> 20) << " MB\n ";
            t0 = t1;
        }
        ~id4() { stop(); }
    };
    return id4();


    return 0;

}();
namespace OY {
    template <typename _ModType, _ModType _P>
    struct Modular {
        static constexpr _ModType mod() { return _P; }
        static constexpr _ModType mod(uint64_t __a) { return __a % _P; }
        static constexpr _ModType plus(_ModType __a, _ModType __b) {
            if (__a += __b; __a >= _P) __a -= _P;
            return __a;
        }
        static constexpr _ModType minus(_ModType __a, _ModType __b) {
            if (__a += _P - __b; __a >= _P) __a -= _P;
            return __a;
        }
        static constexpr _ModType multiply(uint64_t __a, uint64_t __b) {
            if constexpr (std::is_same_v<_ModType, uint64_t>)
                return multiply_ld(__a, __b);
            else
                return multiply_64(__a, __b);
        }
        static constexpr _ModType multiply_64(uint64_t __a, uint64_t __b) {
            

            return mod(__a * __b);
        }
        static constexpr _ModType multiply_128(uint64_t __a, uint64_t __b) { return __uint128_t(__a) * __b % _P; }
        static constexpr _ModType multiply_ld(uint64_t __a, uint64_t __b) {
            

            if (std::__countl_zero(__a) + std::__countl_zero(__b) >= 64) return multiply_64(__a, __b);
            int64_t res = __a * __b - uint64_t(1.L / _P * __a * __b) * _P;
            if (res < 0)
                res += _P;
            else if (res >= _P)
                res -= _P;
            return res;
        }
        static constexpr _ModType pow(uint64_t __a, uint64_t __n) {
            if constexpr (std::is_same_v<_ModType, uint64_t>)
                return pow_ld(__a, __n);
            else
                return pow_64(__a, __n);
        }
        static constexpr _ModType pow_64(uint64_t __a, uint64_t __n) {
            

            _ModType res = 1, b = mod(__a);
            while (__n) {
                if (__n & 1) res = multiply_64(res, b);
                b = multiply_64(b, b);
                __n >>= 1;
            }
            return res;
        }
        static constexpr _ModType pow_128(uint64_t __a, uint64_t __n) {
            _ModType res = 1, b = mod(__a);
            while (__n) {
                if (__n & 1) res = multiply_128(res, b);
                b = multiply_128(b, b);
                __n >>= 1;
            }
            return res;
        }
        static constexpr _ModType pow_ld(uint64_t __a, uint64_t __n) {
            _ModType res = 1, b = mod(__a);
            while (__n) {
                if (__n & 1) res = multiply_ld(res, b);
                b = multiply_ld(b, b);
                __n >>= 1;
            }
            return res;
        }
        template <typename _Tp>
        static constexpr _Tp divide(_Tp __a) { return __a / _P; }
        template <typename _Tp>
        static constexpr std::pair<_Tp, _Tp> divmod(_Tp __a) {
            _Tp quo = __a / _P, rem = __a - quo * _P;
            return {quo, rem};
        }
    };
    template <uint32_t _P>
    using Modular32 = Modular<uint32_t, _P>;
    template <uint64_t _P>
    using Modular64 = Modular<uint64_t, _P>;
}
namespace OY {
    template <typename _ModType>
    struct Barrett {
        _ModType m_P;
        __uint128_t id6;
        constexpr Barrett() = default;
        constexpr explicit Barrett(_ModType __P) : m_P(__P), id6(-uint64_t(__P) / __P + 1) {}
        constexpr _ModType mod() const { return m_P; }
        constexpr _ModType mod(uint64_t __a) const {
            __a -= uint64_t(id6 * __a >> 64) * m_P + m_P;
            if (__a >= m_P) __a += m_P;
            return __a;
        }
        constexpr _ModType plus(_ModType __a, _ModType __b) {
            if (__a += __b; __a >= m_P) __a -= m_P;
            return __a;
        }
        constexpr _ModType minus(_ModType __a, _ModType __b) {
            if (__a += m_P - __b; __a >= m_P) __a -= m_P;
            return __a;
        }
        constexpr _ModType multiply(uint64_t __a, uint64_t __b) const {
            if constexpr (std::is_same_v<_ModType, uint64_t>)
                return multiply_ld(__a, __b);
            else
                return multiply_64(__a, __b);
        }
        constexpr _ModType multiply_64(uint64_t __a, uint64_t __b) const {
            

            return mod(__a * __b);
        }
        constexpr _ModType multiply_128(uint64_t __a, uint64_t __b) const {
            if (std::__countl_zero(__a) + std::__countl_zero(__b) >= 64) return multiply_64(__a, __b);
            return __uint128_t(__a) * __b % m_P;
        }
        constexpr _ModType multiply_ld(uint64_t __a, uint64_t __b) const {
            

            if (std::__countl_zero(__a) + std::__countl_zero(__b) >= 64) return multiply_64(__a, __b);
            int64_t res = __a * __b - uint64_t(1.L / m_P * __a * __b) * m_P;
            if (res < 0)
                res += m_P;
            else if (res >= m_P)
                res -= m_P;
            return res;
        }
        constexpr _ModType pow(uint64_t __a, uint64_t __n) const {
            if constexpr (std::is_same_v<_ModType, uint64_t>)
                return pow_ld(__a, __n);
            else
                return pow_64(__a, __n);
        }
        constexpr _ModType pow_64(uint64_t __a, uint64_t __n) const {
            

            _ModType res = 1, b = mod(__a);
            while (__n) {
                if (__n & 1) res = multiply_64(res, b);
                b = multiply_64(b, b);
                __n >>= 1;
            }
            return res;
        }
        constexpr _ModType pow_128(uint64_t __a, uint64_t __n) const {
            _ModType res = 1, b = mod(__a);
            while (__n) {
                if (__n & 1) res = multiply_128(res, b);
                b = multiply_128(b, b);
                __n >>= 1;
            }
            return res;
        }
        constexpr _ModType pow_ld(uint64_t __a, uint64_t __n) const {
            _ModType res = 1, b = mod(__a);
            while (__n) {
                if (__n & 1) res = multiply_ld(res, b);
                b = multiply_ld(b, b);
                __n >>= 1;
            }
            return res;
        }
        template <typename _Tp>
        constexpr _Tp divide(_Tp __a) const {
            if (__a < m_P) return 0;
            _Tp res = id6 * __a >> 64;
            if (__a - res * m_P >= m_P) res++;
            return res;
        }
        template <typename _Tp>
        constexpr std::pair<_Tp, _Tp> divmod(_Tp __a) const {
            _Tp quo = (__a * id6) >> 64, rem = __a - quo * m_P;
            if (rem >= m_P) {
                quo++;
                rem -= m_P;
            }
            return {quo, rem};
        }
    };
    using Barrett32 = Barrett<uint32_t>;
    using Barrett64 = Barrett<uint64_t>;
}
namespace OY {
    template <typename _ModType>
    struct _MontgomeryTag;
    template <>
    struct _MontgomeryTag<uint32_t> {
        using long_type = uint64_t;
        static constexpr uint32_t limit = (1u << 30) - 1;
        static constexpr uint32_t inv_loop = 4;
        static constexpr uint32_t length = 32;
    };
    template <>
    struct _MontgomeryTag<uint64_t> {
        using long_type = __uint128_t;
        static constexpr uint64_t limit = (1ull << 63) - 1;
        static constexpr uint32_t inv_loop = 5;
        static constexpr uint32_t length = 64;
    };
    template <typename _ModType>
    struct Montgomery {
        using _FastType = _ModType;
        using _LongType = typename _MontgomeryTag<_ModType>::long_type;
        _ModType m_P;
        _ModType id6;
        _ModType m_Ninv;
        Barrett<_ModType> m_brt;
        constexpr Montgomery() = default;
        constexpr explicit Montgomery(_ModType __P) : m_P(__P), id6(__P), m_Ninv(-_LongType(__P) % __P), m_brt(__P) {
            for (int i = 0; i < _MontgomeryTag<_ModType>::inv_loop; i++) id6 *= _ModType(2) - __P * id6;
        }
        constexpr _ModType mod() const { return m_brt.mod(); }
        constexpr _ModType mod(uint64_t __a) const { return m_brt.mod(__a); }
        constexpr _FastType init(uint64_t __a) const { return reduce(_LongType(mod(__a)) * m_Ninv); }
        constexpr _FastType raw_init(uint64_t __a) const { return reduce(_LongType(__a) * m_Ninv); }
        constexpr _FastType reduce(_LongType __a) const {
            _FastType res = (__a >> _MontgomeryTag<_ModType>::length) - _ModType(_LongType(_ModType(__a) * id6) * m_P >> _MontgomeryTag<_ModType>::length);
            if (res >= mod()) res += mod();
            return res;
        }
        constexpr _ModType reduce(_FastType __a) const {
            _ModType res = -_ModType(_LongType(__a * id6) * m_P >> _MontgomeryTag<_ModType>::length);
            if (res >= mod()) res += mod();
            return res;
        }
        constexpr _FastType plus(_FastType __a, _FastType __b) const {
            if (__a += __b; __a >= m_P) __a -= m_P;
            return __a;
        }
        constexpr _FastType minus(_FastType __a, _FastType __b) const {
            if (__a += m_P - __b; __a >= m_P) __a -= m_P;
            return __a;
        }
        constexpr _FastType multiply(_FastType __a, _FastType __b) const { return reduce(_LongType(__a) * __b); }
        constexpr _FastType pow(_FastType __a, uint64_t __n) const {
            _FastType res = reduce(_LongType(1) * m_Ninv);
            while (__n) {
                if (__n & 1) res = multiply(res, __a);
                __a = multiply(__a, __a);
                __n >>= 1;
            }
            return res;
        }
        template <typename _Tp>
        constexpr _Tp divide(_Tp __a) const { return m_brt.divide(__a); }
        template <typename _Tp>
        constexpr std::pair<_Tp, _Tp> divmod(_Tp __a) const { return m_brt.divmod(__a); }
    };
    using Montgomery32 = Montgomery<uint32_t>;
    using Montgomery64 = Montgomery<uint64_t>;
}
namespace OY {
    template <typename _Elem>
    constexpr bool isPrime(_Elem n) {
        if (std::is_same_v<_Elem, uint32_t> || n <= UINT32_MAX) {
            if (n <= 1) return false;
            if (n == 2 || n == 7 || n == 61) return true;
            if (n % 2 == 0) return false;
            Barrett32 brt(n);
            uint32_t d = (n - 1) >> std::__countr_zero(n - 1);
            for (auto &&a : {2, 7, 61}) {
                uint32_t s = d, y = brt.pow_64(a, s);
                while (s != n - 1 && y != 1 && y != n - 1) {
                    y = brt.multiply_64(y, y);
                    s <<= 1;
                }
                if (y != n - 1 && s % 2 == 0) return false;
            }
            return true;
        } else {
            

            if (n % 2 == 0) return false;
            Montgomery64 mg(n);
            uint64_t d = (n - 1) >> std::__countr_zero(n - 1), one = mg.init(1);
            for (auto &&a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
                uint64_t s = d, y = mg.pow(mg.init(a), s), t = mg.init(n - 1);
                while (s != n - 1 && y != one && y != t) {
                    y = mg.multiply(y, y);
                    s <<= 1;
                }
                if (y != t && s % 2 == 0) return false;
            }
            return true;
        }
    }
    constexpr auto id1 = isPrime<uint32_t>;
    constexpr auto id5 = isPrime<uint64_t>;
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
    struct SizeBalancedTreeSetTag {
        static constexpr bool multi_key = false;
        static constexpr bool is_map = false;
    };
    struct SizeBalancedTreeMultisetTag {
        static constexpr bool multi_key = true;
        static constexpr bool is_map = false;
    };
    struct SizeBalancedTreeMapTag {
        static constexpr bool multi_key = false;
        static constexpr bool is_map = true;
    };
    template <typename _Tp, typename _Fp, bool is_map>
    struct _SizeBalancedTreeNode {
        _Tp key;
        mutable _Fp value;
    };
    template <typename _Tp, typename _Fp>
    struct _SizeBalancedTreeNode<_Tp, _Fp, false> { _Tp key; };
    template <typename _Tp, typename _Fp = bool, typename _Compare = std::less<_Tp>, typename _Tag = SizeBalancedTreeMultisetTag>
    class id2 {
        struct node : _SizeBalancedTreeNode<_Tp, _Fp, _Tag::is_map> {
            int subtree_weight;
            node *lchild;
            node *rchild;
            static void *operator new(size_t count) { return MemoryPool<node>::operator new(count); }
            static void operator delete(void *p) { MemoryPool<node>::recycle((node *)p); }
        };
        node *m_root;
        _Compare m_comp;
        static int subtree_weight(node *p) { return p ? p->subtree_weight : 0; }
        static int lchild_weight(node *p) { return p && p->lchild ? p->lchild->subtree_weight : 0; }
        static int rchild_weight(node *p) { return p && p->rchild ? p->rchild->subtree_weight : 0; }
        static node *update(node *p) {
            p->subtree_weight = 1 + subtree_weight(p->lchild) + subtree_weight(p->rchild);
            return p;
        }
        static node *rrotate(node *p) {
            node *q = p->lchild;
            p->lchild = q->rchild;
            q->rchild = update(p);
            return q;
        }
        static node *lrotate(node *p) {
            node *q = p->rchild;
            p->rchild = q->lchild;
            q->lchild = update(p);
            return q;
        }
        static node *lrrotate(node *p) {
            node *q = p->lchild;
            node *r = q->rchild;
            q->rchild = r->lchild;
            p->lchild = r->rchild;
            r->lchild = update(q);
            r->rchild = update(p);
            return r;
        }
        static node *rlrotate(node *p) {
            node *q = p->rchild;
            node *r = q->lchild;
            q->lchild = r->rchild;
            p->rchild = r->lchild;
            r->rchild = update(q);
            r->lchild = update(p);
            return r;
        }
        static node *lbalance(node *cur) {
            if (!cur) return cur;
            if (subtree_weight(cur->lchild) < lchild_weight(cur->rchild))
                cur = rlrotate(cur);
            else if (subtree_weight(cur->lchild) < rchild_weight(cur->rchild))
                cur = lrotate(cur);
            else
                return update(cur);
            cur->lchild = rbalance(cur->lchild);
            cur->rchild = lbalance(cur->rchild);
            return rbalance(lbalance(cur));
        }
        static node *rbalance(node *cur) {
            if (!cur) return cur;
            if (subtree_weight(cur->rchild) < rchild_weight(cur->lchild))
                cur = lrrotate(cur);
            else if (subtree_weight(cur->rchild) < lchild_weight(cur->lchild))
                cur = rrotate(cur);
            else
                return update(cur);
            cur->lchild = rbalance(cur->lchild);
            cur->rchild = lbalance(cur->rchild);
            return rbalance(lbalance(cur));
        }
        static node *deleteMin(node *cur, node *&res) {
            if (!cur) return nullptr;
            if (!cur->lchild) {
                res = cur;
                return cur->rchild;
            } else {
                cur->lchild = deleteMin(cur->lchild, res);
                return update(cur);
            }
        }

    public:
        static void setBufferSize(int __count) { MemoryPool<node>::_reserve(__count); }
        id2(_Compare __comp = _Compare()) : m_root(nullptr), m_comp(__comp) {}
        void clear() { m_root = nullptr; }
        template <typename... Args>
        void insert(_Tp __key, Args... __args) {
            bool res = false;
            auto dfs = [&](auto self, node *cur) {
                if (!cur) {
                    res = true;
                    return new node{__key, __args..., 1, nullptr, nullptr};
                } else if (m_comp(__key, cur->key)) {
                    cur->lchild = self(self, cur->lchild);
                    return _Tag::multi_key || res ? rbalance(cur) : cur;
                } else {
                    if constexpr (!_Tag::multi_key)
                        if (!m_comp(cur->key, __key)) return cur;
                    cur->rchild = self(self, cur->rchild);
                    return _Tag::multi_key || res ? lbalance(cur) : cur;
                };
            };
            m_root = dfs(dfs, m_root);
        }
        void update(_Tp __key, _Fp __value) {
            static_assert(_Tag::is_map);
            if (auto p = find(__key))
                p->value = __value;
            else
                insert(__key, __value);
        }
        bool erase(_Tp __key) {
            auto dfs = [&](auto self, node *cur) -> node * {
                if (!cur)
                    return nullptr;
                else if (m_comp(__key, cur->key)) {
                    cur->lchild = self(self, cur->lchild);
                } else if (m_comp(cur->key, __key)) {
                    cur->rchild = self(self, cur->rchild);
                } else if (!cur->rchild) {
                    delete cur;
                    return cur->lchild;
                } else {
                    node *res;
                    cur->rchild = deleteMin(cur->rchild, res);
                    res->lchild = cur->lchild;
                    res->rchild = cur->rchild;
                    delete cur;
                    cur = res;
                }
                return update(cur);
            };
            int old_weight = size();
            m_root = dfs(dfs, m_root);
            return old_weight != size();
        }
        void erase(_Tp __key, int __count) {
            static_assert(_Tag::multi_key);
            while (__count-- && erase(__key))
                ;
        }
        int rank(_Tp __key) const {
            int ord = 0;
            for (node *cur = m_root; cur;)
                if (!m_comp(cur->key, __key))
                    cur = cur->lchild;
                else {
                    ord += subtree_weight(cur->lchild);
                    if (m_comp(cur->key, __key)) {
                        ord++;
                        cur = cur->rchild;
                    } else
                        break;
                }
            return ord;
        }
        const node *kth(int __k) const {
            node *cur = m_root;
            while (__k >= 0)
                if (int l_count = subtree_weight(cur->lchild); __k < l_count)
                    cur = cur->lchild;
                else if (__k -= subtree_weight(cur->lchild) + 1; __k >= 0)
                    cur = cur->rchild;
            return cur;
        }
        const node *find(_Tp __key) const {
            for (node *cur = m_root; cur;) {
                if (m_comp(__key, cur->key))
                    cur = cur->lchild;
                else if (m_comp(cur->key, __key))
                    cur = cur->rchild;
                else
                    return cur;
            }
            return nullptr;
        }
        const node *lower_bound(_Tp __key) const {
            node *res = nullptr;
            for (node *cur = m_root; cur;) {
                if (m_comp(__key, cur->key)) {
                    res = cur;
                    cur = cur->lchild;
                } else if (m_comp(cur->key, __key))
                    cur = cur->rchild;
                else
                    return cur;
            }
            return res;
        }
        const node *upper_bound(_Tp __key) const {
            node *res = nullptr;
            for (node *cur = m_root; cur;) {
                if (m_comp(__key, cur->key)) {
                    res = cur;
                    cur = cur->lchild;
                } else
                    cur = cur->rchild;
            }
            return res;
        }
        const node *smaller_bound(_Tp __key) const {
            node *res = nullptr;
            for (node *cur = m_root; cur;) {
                if (m_comp(cur->key, __key)) {
                    res = cur;
                    cur = cur->rchild;
                } else
                    cur = cur->lchild;
            }
            return res;
        }
        int size() const { return subtree_weight(m_root); }
        bool empty() const { return !size(); }
        int count(_Tp __key) const {
            auto it1 = lower_bound(__key);
            if (!it1) return 0;
            auto it2 = upper_bound(__key);
            if (!it2)
                return size() - rank(__key);
            else
                return rank(it2->key) - rank(__key);
        }
    };
    namespace SizeBalancedTreeContainer {
        template <typename _Tp, typename _Compare = std::less<_Tp>>
        using Set = id2<_Tp, bool, _Compare, SizeBalancedTreeSetTag>;
        template <typename _Tp, typename _Compare = std::less<_Tp>>
        using Multiset = id2<_Tp, bool, _Compare, SizeBalancedTreeMultisetTag>;
        template <typename _Tp, typename _Fp, typename _Compare = std::less<_Tp>>
        using Map = id2<_Tp, _Fp, _Compare, SizeBalancedTreeMapTag>;
    }
}
using SET=OY::SizeBalancedTreeContainer::Multiset<long long>;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        int A[n];
        for (auto &a : A) cin >> a;
        std::vector<int> B;
        for (int i = 2; i <= n; i++)
            if (n % i == 0 and OY::id1(i)) B.push_back(n / i);
        std::vector<std::vector<long long>> S;
        SET T;
        for (int d : B) {
            S.push_back({});
            S.back().reserve(d);
            for (int i = 0; i < d; i++) {
                long long k = 0;
                for (int j = i; j < n; j += d) k += A[j];
                S.back().push_back(k * d);
                T.insert(k * d);
            }
        }

        for (int i = 0; i <= q; i++) {
            if (i) {
                int idx, val;
                cin >> idx >> val;
                idx--;
                long long inc = val - A[idx];
                A[idx] = val;
                for (int i = 0; i < B.size(); i++) {
                    int d = B[i];
                    long long &cur = S[i][idx % d];
                    T.erase(cur);
                    cur += inc * d;
                    T.insert(cur);
                }
            }
            cout << T.kth(T.size() - 1)->key << '\n';
        }
    }

    CHECKTIME;
}