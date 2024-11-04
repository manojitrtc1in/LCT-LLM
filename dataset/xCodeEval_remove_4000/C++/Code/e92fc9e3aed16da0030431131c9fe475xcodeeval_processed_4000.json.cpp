








template <typename _Tp, typename _Fp, typename _Compare = std::less<void>>
bool chmax(_Tp &a, const _Fp &b, _Compare __comp = _Compare()) { return __comp(a, b) ? a = b, true : false; }
template <typename _Tp, typename _Fp, typename _Compare = std::less<void>>
bool chmin(_Tp &a, const _Fp &b, _Compare __comp = _Compare()) { return __comp(b, a) ? a = b, true : false; }

using std::cin,std::cout,std::endl;auto tam = [] {std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


    freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);struct id6 {static auto GetMicroSecond() {static FILETIME ft;GetSystemTimeAsFileTime(&ft);return ft.dwLowDateTime;};static auto GetMemory() {PROCESS_MEMORY_COUNTERS pmc;GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));return pmc.WorkingSetSize;}uint32_t t0, t1;id6() : t0(GetMicroSecond()) {}void stop() {t1 = GetMicroSecond();cout << "\ntime cost = " << (t1 - t0) / 10000.0 << " ms\nmemory cost = " << (GetMemory() >> 20) << " MB\n ";t0 = t1;}~id6() { stop(); }};return id6();


    return 0;

}();
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
    class id0 {
        struct id5 : MemoryPool<id5> {
            _Tp val;
            id5 *lchild;
            id5 *rchild;
            id5(_Tp _val, id5 *_lchild, id5 *_rchild) : val(_val), lchild(_lchild), rchild(_rchild) {}
        };
        std::vector<id5 *> m_roots;
        int m_length;
        _Operation m_op;
        _Tp m_defaultValue;
        void _check() {
            

        }
        id5 *lchild(id5 *cur) {
            if (!cur->lchild)
                cur->lchild = new id5(m_defaultValue, nullptr, nullptr);
            return cur->lchild;
        }
        id5 *rchild(id5 *cur) {
            if (!cur->rchild)
                cur->rchild = new id5(m_defaultValue, nullptr, nullptr);
            return cur->rchild;
        }
        id5 *_update(id5 *cur) {
            cur->val = m_op(cur->lchild ? cur->lchild->val : m_defaultValue, cur->rchild ? cur->rchild->val : m_defaultValue);
            return cur;
        }
        id5 *_root(int version) const { return ~version ? m_roots[version] : m_roots.back(); }
        void _clear() { m_roots.clear(); }

    public:
        static void setBufferSize(int __count) { MemoryPool<id5>::_reserve(__count); }
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
            if (m_length = __n) m_roots.push_back(new id5(m_defaultValue, nullptr, nullptr));
        }
        template <typename _Iterator>
        void reset(_Iterator __first, _Iterator __last) {
            _clear();
            m_length = __last - __first;
            auto dfs = [&](auto self, _Iterator first, _Iterator last) -> id5 * {
                if (first + 1 == last)
                    return new id5(*first, nullptr, nullptr);
                else
                    return _update(new id5(*first, self(self, first, first + (last - first + 1) / 2), self(self, first + (last - first + 1) / 2, last)));
            };
            m_roots.push_back(dfs(dfs, __first, __last));
        }
        void copyVersion(int id4) {
            m_roots.push_back(_root(id4));
        }
        void update(int id4, int __i, _Tp __val) {
            auto dfs = [&](auto self, id5 *prev, int left, int right) -> id5 * {
                id5 *cur = prev ? new id5(*prev) : new id5(m_defaultValue, nullptr, nullptr);
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
            auto dfs = [&](auto self, id5 *prev, int left, int right) -> id5 * {
                id5 *cur = prev ? new id5(*prev) : new id5(m_defaultValue, nullptr, nullptr);
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
            auto dfs = [&](auto self, id5 *cur, int left, int right) {
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
            auto dfs = [&](auto self, id5 *cur, int left, int right) {
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
            auto dfs = [&](auto self, id5 *cur, int left, int right, int k) {
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
            auto dfs = [&](auto self, id5 *root1, id5 *root2, int left, int right) {
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
            auto dfs = [&](auto self, id5 *root1, id5 *root2, int left, int right) -> _Tp {
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
            auto dfs = [&](auto self, id5 *root1, id5 *root2, int left, int right, int k) {
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

int main() {
    int t;cin>>t;
    OY::id0<long long>::setBufferSize(1000000);
    while(t--){
        int n,q;cin>>n>>q;
        std::vector<std::pair<int,int>>A(n);
        for(int i=0;i<n;i++){
            cin>>A[i].first>>A[i].second;
        }
        std::sort(all(A));
        OY::id0<long long>T(100001);
        for(auto&[i,j]:A){
            T.add(-1,j,i*j);
        }
        for(int i=0;i<q;i++){
            int w1,b1,w2,b2;cin>>w1>>b1>>w2>>b2;
            if(w1+1==w2 or b1+1==b2){
                cout<<0<<'\n';
                continue;
            }
            int a=std::upper_bound(all(A),std::pair<int,int>(w1,10000))-A.begin();
            int b=std::lower_bound(all(A),std::pair<int,int>(w2,-1))-A.begin();
            long long s=T.periodQuery(a+1,b,b1+1,b2-1);
            cout<<s<<'\n';
            continue;
        }

    }

    CHECKTIME;
}