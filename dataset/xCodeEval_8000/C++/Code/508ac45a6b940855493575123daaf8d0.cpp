#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#ifdef OY_LOCAL
#include <windows.h>


#include <psapi.h>
#endif
#define all(a) std::begin(a), std::end(a)
#define rall(a) std::rbegin(a), std::rend(a)
template <typename _Tp, typename _Fp, typename _Compare = std::less<void>>
bool chmax(_Tp &a, const _Fp &b, _Compare __comp = _Compare()) { return __comp(a, b) ? a = b, true : false; }
template <typename _Tp, typename _Fp, typename _Compare = std::less<void>>
bool chmin(_Tp &a, const _Fp &b, _Compare __comp = _Compare()) { return __comp(b, a) ? a = b, true : false; }
using std::cin, std::cout, std::endl;
namespace OY {
    template <typename _Sequence>
    struct SiftGetter {
        _Sequence &m_sequence;
        SiftGetter(_Sequence &__sequence) : m_sequence(__sequence) {}
        auto &operator()(uint32_t __index) const { return m_sequence[__index]; }
    };
    template <typename _Mapping, typename _Compare = std::less<void>>
    struct SiftHeap {
        std::vector<uint32_t> m_heap;
        std::vector<uint32_t> m_pos;
        _Mapping m_map;
        _Compare m_comp;
        SiftHeap(uint32_t __n, _Mapping __map, _Compare __comp = _Compare()) : m_pos(__n, -1), m_map(__map), m_comp(__comp) { m_heap.reserve(__n); }
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
    SiftHeap(uint32_t, std::vector<_Tp> &, _Compare) -> SiftHeap<SiftGetter<std::vector<_Tp>>, _Compare>;
    template <typename _Tp, uint32_t _N, typename _Compare>
    SiftHeap(uint32_t, _Tp (&)[_N], _Compare) -> SiftHeap<SiftGetter<_Tp[_N]>, _Compare>;
}
auto tam = [] {
#ifdef OY_LOCAL
#define CHECKTIME tam.stop()
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    struct TIME_AND_MEMORY {
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
        TIME_AND_MEMORY() : t0(GetMicroSecond()) {}
        void stop() {
            t1 = GetMicroSecond();
            cout << "\ntime cost = " << (t1 - t0) / 10000.0 << " ms\nmemory cost = " << (GetMemory() >> 20) << " MB\n ";
            t0 = t1;
        }
        ~TIME_AND_MEMORY() { stop(); }
    };
    return TIME_AND_MEMORY();
#else
#define CHECKTIME
    return 0;
#endif
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
        __uint128_t m_Pinv;
        constexpr Barrett() = default;
        constexpr explicit Barrett(_ModType __P) : m_P(__P), m_Pinv(-uint64_t(__P) / __P + 1) {}
        constexpr _ModType mod() const { return m_P; }
        constexpr _ModType mod(uint64_t __a) const {
            __a -= uint64_t(m_Pinv * __a >> 64) * m_P + m_P;
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
            _Tp res = m_Pinv * __a >> 64;
            if (__a - res * m_P >= m_P) res++;
            return res;
        }
        template <typename _Tp>
        constexpr std::pair<_Tp, _Tp> divmod(_Tp __a) const {
            _Tp quo = (__a * m_Pinv) >> 64, rem = __a - quo * m_P;
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
        _ModType m_Pinv;
        _ModType m_Ninv;
        Barrett<_ModType> m_brt;
        constexpr Montgomery() = default;
        constexpr explicit Montgomery(_ModType __P) : m_P(__P), m_Pinv(__P), m_Ninv(-_LongType(__P) % __P), m_brt(__P) {
            for (int i = 0; i < _MontgomeryTag<_ModType>::inv_loop; i++) m_Pinv *= _ModType(2) - __P * m_Pinv;
        }
        constexpr _ModType mod() const { return m_brt.mod(); }
        constexpr _ModType mod(uint64_t __a) const { return m_brt.mod(__a); }
        constexpr _FastType init(uint64_t __a) const { return reduce(_LongType(mod(__a)) * m_Ninv); }
        constexpr _FastType raw_init(uint64_t __a) const { return reduce(_LongType(__a) * m_Ninv); }
        constexpr _FastType reduce(_LongType __a) const {
            _FastType res = (__a >> _MontgomeryTag<_ModType>::length) - _ModType(_LongType(_ModType(__a) * m_Pinv) * m_P >> _MontgomeryTag<_ModType>::length);
            if (res >= mod()) res += mod();
            return res;
        }
        constexpr _ModType reduce(_FastType __a) const {
            _ModType res = -_ModType(_LongType(__a * m_Pinv) * m_P >> _MontgomeryTag<_ModType>::length);
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
    constexpr auto isPrime32 = isPrime<uint32_t>;
    constexpr auto isPrime64 = isPrime<uint64_t>;
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
    struct BTreeSetTag {
        static constexpr bool is_map = false;
        static constexpr bool multi_key = false;
    };
    struct BTreeMultisetTag {
        static constexpr bool is_map = false;
        static constexpr bool multi_key = true;
    };
    struct BTreeMapTag {
        static constexpr bool is_map = true;
        static constexpr bool multi_key = false;
    };
    template <typename _Tp, typename _Fp, bool is_map>
    struct _BTreeNode {
        _Tp key;
        mutable _Fp value;
    };
    template <typename _Tp, typename _Fp>
    struct _BTreeNode<_Tp, _Fp, false> { _Tp key; };
    template <typename _Tp, typename _Fp = int, typename _Compare = std::less<_Tp>, typename _Tag = BTreeMultisetTag, int _K = 3>
    class BTree {
        using node = _BTreeNode<_Tp, _Fp, _Tag::is_map>;
        struct block : MemoryPool<block> {
            node keys[_K * 2 - 1];
            int keyNum;
            node min;
            node max;
            int weight;
            block *child[_K * 2];
            block() { child[0] = nullptr; }
            void push_front(node key, block *p) {
                std::copy_backward(keys, keys + keyNum, keys + keyNum + 1);
                if (child[0]) std::copy_backward(child, child + keyNum + 1, child + keyNum + 2);
                keys[0] = key;
                child[0] = p;
                keyNum++;
            }
            void push_back(node key, block *p) {
                keys[keyNum] = key;
                child[keyNum + 1] = p;
                keyNum++;
            }
            void pop_front() {
                std::copy(keys + 1, keys + keyNum, keys);
                bool is_leaf = !child[0];
                std::copy(child + 1, child + keyNum + 1, child);
                if (is_leaf) child[0] = nullptr;
                keyNum--;
            }
            void pop_back() { keyNum--; }
            void updateMinMax() {
                if (!child[0]) {
                    min = keys[0];
                    max = keys[keyNum - 1];
                } else {
                    min = child[0]->min;
                    max = child[keyNum]->max;
                }
            }
        };
        _Compare m_comp;
        block *m_root;
        static void getLeftLast(block *parent, int pos) {
            block *left = parent->child[pos - 1];
            block *right = parent->child[pos];
            bool is_leaf = !right->child[0];
            right->push_front(parent->keys[pos - 1], is_leaf ? nullptr : left->child[left->keyNum]);
            parent->keys[pos - 1] = left->keys[left->keyNum - 1];
            left->pop_back();
            int w = is_leaf ? 1 : right->child[0]->weight + 1;
            left->max = is_leaf ? left->keys[left->keyNum - 1] : left->child[left->keyNum]->max;
            right->min = is_leaf ? right->keys[0] : right->child[0]->min;
            left->weight -= w;
            right->weight += w;
        }
        static void getRightFirst(block *parent, int pos) {
            block *left = parent->child[pos];
            block *right = parent->child[pos + 1];
            bool is_leaf = !right->child[0];
            left->push_back(parent->keys[pos], right->child[0]);
            parent->keys[pos] = right->keys[0];
            right->pop_front();
            int w = is_leaf ? 1 : left->child[left->keyNum]->weight + 1;
            left->max = is_leaf ? left->keys[left->keyNum - 1] : left->child[left->keyNum]->max;
            right->min = is_leaf ? right->keys[0] : right->child[0]->min;
            left->weight += w;
            right->weight -= w;
        }
        static void mergeAt(block *parent, int pos) {
            block *left = parent->child[pos];
            block *right = parent->child[pos + 1];
            left->keys[left->keyNum] = parent->keys[pos];
            std::copy(right->keys, right->keys + right->keyNum, left->keys + left->keyNum + 1);
            std::copy(right->child, right->child + right->keyNum + 1, left->child + left->keyNum + 1);
            left->keyNum = _K * 2 - 1;
            left->max = right->max;
            left->weight += right->weight + 1;
            delete right;
            std::copy(parent->keys + pos + 1, parent->keys + parent->keyNum, parent->keys + pos);
            std::copy(parent->child + pos + 2, parent->child + parent->keyNum + 1, parent->child + pos + 1);
            parent->keyNum--;
        }
        static void splitAt(block *parent, int pos) {
            block *left = parent->child[pos];
            block *right = new block;
            left->keyNum = right->keyNum = _K - 1;
            std::copy(left->keys + _K, left->keys + (_K * 2 - 1), right->keys);
            if (left->child[0]) {
                int w = _K - 1;
                for (int i = 0; i < _K; i++) {
                    right->child[i] = left->child[_K + i];
                    w += right->child[i]->weight;
                }
                right->min = right->child[0]->min;
                right->max = left->max;
                right->weight = w;
                left->max = left->child[_K - 1]->max;
                left->weight -= w + 1;
            } else {
                right->min = right->keys[0];
                right->max = left->max;
                right->weight = _K - 1;
                left->max = left->keys[_K - 2];
                left->weight -= _K;
            }
            parent->child[pos + 1] = right;
            parent->keys[pos] = left->keys[_K - 1];
            parent->keyNum++;
        }
        const node *key_lower_bound(const node *first, const node *last, _Tp __val) const {
            int len = last - first;
            while (len) {
                int half = len / 2;
                const node *mid = first + half;
                if (m_comp(mid->key, __val)) {
                    first = mid + 1;
                    len -= half + 1;
                } else
                    len = half;
            }
            return first;
        }
        const node *key_upper_bound(const node *first, const node *last, _Tp __val) const {
            int len = last - first;
            while (len) {
                int half = len / 2;
                const node *mid = first + half;
                if (m_comp(__val, mid->key))
                    len = half;
                else {
                    first = mid + 1;
                    len -= half + 1;
                }
            }
            return first;
        }
        block *_insert(block *cur, const node &item, bool &res) {
            int pos = key_upper_bound(cur->keys, cur->keys + cur->keyNum, item.key) - cur->keys;
            if constexpr (!_Tag::multi_key)
                if (pos && !m_comp(cur->keys[pos - 1].key, item.key)) return cur;
            if (!cur->child[0]) {
                std::copy_backward(cur->keys + pos, cur->keys + cur->keyNum, cur->keys + cur->keyNum + 1);
                cur->keys[pos] = item;
                cur->keyNum++;
                res = true;
            } else {
                if (cur->child[pos]->keyNum == _K * 2 - 1) {
                    std::copy_backward(cur->keys + pos, cur->keys + cur->keyNum, cur->keys + cur->keyNum + 1);
                    std::copy_backward(cur->child + pos + 1, cur->child + cur->keyNum + 1, cur->child + cur->keyNum + 2);
                    splitAt(cur, pos);
                    if (m_comp(cur->keys[pos].key, item.key)) pos++;
                }
                _insert(cur->child[pos], item, res);
            }
            if (res) {
                cur->weight++;
                if (m_comp(item.key, cur->min.key)) cur->min = item;
                if (m_comp(cur->max.key, item.key)) cur->max = item;
            }
            return cur;
        }
        block *_erase(block *cur, _Tp key, bool &res) {
            int pos = key_lower_bound(cur->keys, cur->keys + cur->keyNum, key) - cur->keys;
            if (pos == cur->keyNum || m_comp(key, cur->keys[pos].key)) {
                if (!cur->child[0]) return cur;
                if (cur->child[pos]->keyNum == _K - 1) {
                    if (pos && cur->child[pos - 1]->keyNum >= _K)
                        getLeftLast(cur, pos);
                    else if (pos < cur->keyNum && cur->child[pos + 1]->keyNum >= _K)
                        getRightFirst(cur, pos);
                    else {
                        if (pos) pos--;
                        mergeAt(cur, pos);
                        if (!cur->keyNum) {
                            m_root = _erase(cur->child[0], key, res);
                            delete cur;
                            return m_root;
                        }
                    }
                }
                cur->child[pos] = _erase(cur->child[pos], key, res);
                if (res) {
                    cur->weight--;
                    cur->min = cur->child[0]->min;
                    cur->max = cur->child[cur->keyNum]->max;
                }
                return cur;
            } else {
                res = true;
                if (!--cur->weight) {
                    delete cur;
                    return nullptr;
                }
                if (!cur->child[0]) {
                    std::copy(cur->keys + pos + 1, cur->keys + cur->keyNum, cur->keys + pos);
                    cur->keyNum--;
                    cur->updateMinMax();
                } else if (cur->child[pos]->keyNum >= _K) {
                    node leftMax = cur->child[pos]->max;
                    cur->keys[pos] = leftMax;
                    cur->child[pos] = _erase(cur->child[pos], leftMax.key, res);
                } else if (cur->child[pos + 1]->keyNum >= _K) {
                    node rightMin = cur->child[pos + 1]->min;
                    cur->keys[pos] = rightMin;
                    cur->child[pos + 1] = _erase(cur->child[pos + 1], rightMin.key, res);
                } else {
                    mergeAt(cur, pos);
                    if (!cur->keyNum) {
                        m_root = _erase(cur->child[0], key, res);
                        delete cur;
                        return m_root;
                    }
                    cur->child[pos] = _erase(cur->child[pos], key, res);
                }
                return cur;
            }
        }

    public:
        static void setBufferSize(int __count) { block::_reserve(__count); }
        BTree(_Compare __comp = _Compare()) : m_root(nullptr), m_comp(__comp) {}
        void clear() { m_root = nullptr; }
        template <typename... Args>
        void insert(_Tp __key, Args... __args) {
            node item = node{__key, __args...};
            bool res = false;
            if (!m_root) {
                m_root = new block;
                m_root->min = m_root->max = m_root->keys[0] = item;
                m_root->keyNum = m_root->weight = 1;
            } else {
                if (m_root->keyNum == _K * 2 - 1) {
                    block *p = new block;
                    p->keyNum = 0;
                    p->child[0] = m_root;
                    p->weight = m_root->weight;
                    splitAt(p, 0);
                    m_root = _insert(p, item, res);
                } else
                    m_root = _insert(m_root, item, res);
            }
        }
        void update(_Tp __key, _Fp __value) {
            static_assert(_Tag::is_map);
            if (auto p = find(__key); p)
                p->value = __value;
            else
                insert(__key, __value);
        }
        bool erase(_Tp __key) {
            bool res = false;
            if (m_root) m_root = _erase(m_root, __key, res);
            return res;
        }
        void erase(_Tp __key, int __count) {
            while (__count-- && erase(__key))
                ;
        }
        int rank(_Tp __key) const {
            block *cur = m_root;
            int ord = 0;
            while (cur) {
                int pos = key_lower_bound(cur->keys, cur->keys + cur->keyNum, __key) - cur->keys;
                ord += pos;
                if (!cur->child[0]) break;
                for (int i = 0; i < pos; i++) ord += cur->child[i]->weight;
                cur = cur->child[pos];
            }
            return ord;
        }
        const node *kth(int k) const {
            block *cur = m_root;
            for (int i; cur->child[0]; cur = cur->child[i])
                for (i = 0; k >= cur->child[i]->weight; i++) {
                    k -= cur->child[i]->weight;
                    if (!k--) return cur->keys + i;
                }
            return cur->keys + k;
        }
        const node *find(_Tp __key) const {
            block *cur = m_root;
            if (!cur) return nullptr;
            node *res = nullptr;
            for (int i;; cur = cur->child[i]) {
                if (i = key_lower_bound(cur->keys, cur->keys + cur->keyNum, __key) - cur->keys; i < cur->keyNum && !m_comp(__key, cur->keys[i].key)) return cur->keys + i;
                if (!cur->child[0]) break;
            }
            return res;
        }
        const node *smaller_bound(_Tp __key) const {
            block *cur = m_root;
            if (!cur) return nullptr;
            node *res = nullptr;
            for (int i;; cur = cur->child[i]) {
                if (i = key_lower_bound(cur->keys, cur->keys + cur->keyNum, __key) - cur->keys) res = cur->keys + i - 1;
                if (!cur->child[0]) break;
            }
            return res;
        }
        const node *lower_bound(_Tp __key) const {
            block *cur = m_root;
            if (!cur) return nullptr;
            node *res = nullptr;
            for (int i; cur; cur = i ? cur->child[i - 1] : nullptr) {
                if (i = key_lower_bound(cur->keys, cur->keys + cur->keyNum, __key) - cur->keys; i < cur->keyNum) res = cur->keys + i;
                if (!cur->child[0]) break;
            }
            return res;
        }
        const node *upper_bound(_Tp __key) const {
            block *cur = m_root;
            if (!cur) return nullptr;
            node *res = nullptr;
            for (int i; cur; cur = cur->child[i]) {
                if (i = key_upper_bound(cur->keys, cur->keys + cur->keyNum, __key) - cur->keys; i < cur->keyNum) res = cur->keys + i;
                if (!cur->child[0]) break;
            }
            return res;
        }
        int size() const { return m_root ? m_root->weight : 0; }
        bool empty() const { return !size(); }
        int count(_Tp __key) const {
            auto it1 = lower_bound(__key);
            if (!it1) return 0;
            auto it2 = upper_bound(__key);
            if constexpr (!_Tag::multi_key)
                return it2 != it1;
            else {
                if (!it2)
                    return size() - rank(__key);
                else
                    return rank(it2->key) - rank(__key);
            }
        }
    };
    namespace BTreeContainer {
        template <typename _Tp, typename _Compare = std::less<_Tp>, int _K = 28>
        using Set = BTree<_Tp, bool, _Compare, BTreeSetTag, _K>;
        template <typename _Tp, typename _Compare = std::less<_Tp>, int _K = 28>
        using Multiset = BTree<_Tp, bool, _Compare, BTreeMultisetTag, _K>;
        template <typename _Tp, typename _Fp, typename _Compare = std::less<_Tp>, int _K = 28>
        using Map = BTree<_Tp, _Fp, _Compare, BTreeMapTag, _K>;
    }
}

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
            if (n % i == 0 and OY::isPrime32(i)) B.push_back(n / i);
        std::vector<std::vector<long long>> S;
        OY::BTreeContainer::Multiset<long long> T;
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