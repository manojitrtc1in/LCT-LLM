


using namespace std;



using namespace __gnu_pbds;
template <class Key>
using rb_tree_set = tree<Key, null_type, less<Key>, rb_tree_tag, tree_order_statistics_node_update>;
template <class Key, class T>
using rb_tree_map = tree<Key, T, less<Key>, rb_tree_tag, tree_order_statistics_node_update>;











    if (exp != act) {    \
        DUMP(exp);       \
        DUMP(act);       \
        assert(false);   \
    }



template <typename T> inline T INF() { assert(false); };
template <typename T> inline T EPS() { assert(false); };


using i32 = int32_t;
template <> i32 INF() { return 1 << 28; };
template <> i32 EPS() { return 1; };
using i64 = int64_t;
template <> i64 INF() { return 1LL << 60; };
template <> i64 EPS() { return 1; };


using u32 = uint32_t;
template <> u32 INF() { return 1 << 28; };
template <> u32 EPS() { return 1; };
using u64 = uint64_t;
template <> u64 INF() { return 1LL << 60; };
template <> u64 EPS() { return 1; };


using f64 = double;
template <> f64 INF() { return 1e16; };
template <> f64 EPS() { return 1e-8; };
using f128 = long double;
template <> f128 INF() { return 1e16; };
template <> f128 EPS() { return 1e-8; };



template <typename T = i64> struct _range {
    struct iterator {
        T v;
        const T stop, step;
        iterator &operator++() {
            v = step > 0 ? min(v + step, stop) : max(v + step, stop);
            return *this;
        }
        T &operator*() { return v; }
        bool operator!=(iterator &itr) { return v != itr.v; }
    };
    iterator i, n;
    _range(T i, T n, T step = 1) : i({i, n, step}), n({n, n, step}){};
    _range(T n) : _range(0, n){};
    iterator &begin() { return i; }
    iterator &end() { return n; }
};
using range = _range<>;



template <size_t I = 0, typename F, typename... Args>
inline typename enable_if<(I == sizeof...(Args)), void>::type for_each(const tuple<Args...> &t, F f) {}
template <size_t I = 0, typename F, typename... Args>
inline typename enable_if<(I < sizeof...(Args)), void>::type for_each(const tuple<Args...> &t, F f) {
    f(I, get<I>(t));
    for_each<I + 1, F, Args...>(t, f);
}
template <size_t I = 0, typename F, typename... Args>
inline typename enable_if<(I == sizeof...(Args)), void>::type for_each(tuple<Args...> &t, F f) {}
template <size_t I = 0, typename F, typename... Args>
inline typename enable_if<(I < sizeof...(Args)), void>::type for_each(tuple<Args...> &t, F f) {
    f(I, get<I>(t));
    for_each<I + 1, F, Args...>(t, f);
}





template <typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) {
    return is >> p.first >> p.second;
}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    return os << p.first << " " << p.second;
}


template <typename... Args> istream &operator>>(istream &is, std::tuple<Args...> &t) {
    for_each(t, [&](auto, auto &v) { is >> v; });
    return is;
}
template <typename... Args> ostream &operator<<(ostream &os, const tuple<Args...> &t) {
    string delem = "";
    for_each(t, [&](auto, auto t) { os << exchange(delem, " ") << t; });
    return os;
}


template <typename It> istream &iterReader(istream &is, const It &first, const It &last) {
    for (auto it = first; it != last; ++it) is >> *it;
    return is;
}
template <typename T> istream &operator>>(istream &is, vector<T> &as) { return iterReader(is, ALL(as)); }
template <typename It> ostream &iterWriter(ostream &os, const It &first, const It &last, const string &sep) {
    string delem = "";
    for (auto it = first; it != last; ++it) { os << exchange(delem, sep) << *it; }
    return os;
}
template <typename T> ostream &operator<<(ostream &os, const set<T> &ss) { return iterWriter(os, ALL(ss), " "); }
template <typename K, typename V> ostream &operator<<(ostream &os, const map<K, V> &m) {
    return iterWriter(os, ALL(m), "\n");
}
template <typename T> ostream &operator<<(ostream &os, const vector<T> &as) { return iterWriter(os, ALL(as), " "); }
template <typename T> ostream &operator<<(ostream &os, const vector<vector<T>> &as) {
    return iterWriter(os, ALL(as), "\n");
}

void run();

i32 main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(20);
    run();
    return 0;
}















constexpr i32 isp_size = 200000;
struct id2 {
    constexpr id2() : vs() {
        for (i32 i = 0; i < isp_size; i++) vs[i] = true;
        for (i32 i = 2; i * i < isp_size; i++)
            if (vs[i]) {
                for (i32 j = i * i; j < isp_size; j += i) vs[j] = false;
            }
        vs[0] = vs[1] = false;
    }
    constexpr bool operator[](int i) const { return vs[i]; }
    bool vs[isp_size];
};
constexpr auto isp = id2();

const vector<i32> pvec = []() {
    vector<i32> res;
    for (i32 i = 2; i < isp_size; i++)
        if (isp[i]) { res.push_back(i); }
    return res;
}();





template <typename Int> struct vecmap {
    struct myiterator {
        typedef typename vector<Int>::iterator viterator;
        typedef typename unordered_map<u32, Int>::iterator miterator;
        vector<Int> &vec;
        unordered_map<u32, Int> &m;
        viterator vit;
        miterator mit;
        myiterator(vector<Int> &vec, unordered_map<u32, Int> &m) : vec(vec), m(m) {}
        myiterator(vector<Int> &vec, unordered_map<u32, Int> &m, viterator vit, miterator mit)
            : vec(vec), m(m), vit(vit), mit(mit) {}
        bool operator==(const myiterator &itr) const { return vit == itr.vit && mit == itr.mit; }
        bool operator!=(const myiterator &itr) const { return !(*this == itr); }
        myiterator &operator++() {
            if (vit != vec.end())
                vit++;
            else
                mit++;
            return *this;
        }
        pair<const u32, Int> &operator*() {
            return vit != vec.end() ? make_pair(distance(vec.begin(), vit), *vit) : (*mit);
        }
    };
    myiterator begin() noexcept { return myiterator(vec, m, vec.begin(), m.begin()); }
    myiterator end() noexcept { return myiterator(vec, m, vec.end(), m.end()); }

    struct id0 {
        typedef typename vector<Int>::const_iterator viterator;
        typedef typename unordered_map<u32, Int>::const_iterator miterator;
        const vector<Int> *vec;
        const unordered_map<u32, Int> *m;
        viterator vit;
        miterator mit;
        pair<u32, Int> ptr;
        id0(const vector<Int> *vec, const unordered_map<u32, Int> *m) : vec(vec), m(m) {}
        id0(const vector<Int> *vec, const unordered_map<u32, Int> *m, const viterator vit,
                         const miterator mit)
            : vec(vec), m(m), vit(vit), mit(mit) {
            set_ptr();
        }
        void set_ptr() {
            if (vit != vec->end())
                ptr = make_pair(distance(vec->begin(), vit), *vit);
            else if (mit != m->end())
                ptr = *mit;
        }
        inline bool operator==(const id0 &itr) const { return vit == itr.vit && mit == itr.mit; }
        inline bool operator!=(const id0 &itr) const { return !(*this == itr); }
        id0 &operator++() {
            if (vit != vec->end()) {
                ++vit;
            } else {
                ++mit;
            }
            set_ptr();
            return *this;
        }
        const pair<u32, Int> &operator*() const { return ptr; }
    };
    id0 begin() const noexcept { return id0(&vec, &m, vec.begin(), m.begin()); }
    id0 end() const noexcept { return id0(&vec, &m, vec.end(), m.end()); }

    vector<Int> vec;            

    unordered_map<u32, Int> m;  

    constexpr vecmap(u32 size = 0) { vec = vector<Int>(size); }
    constexpr Int &operator[](const u32 i) {
        if (i < vec.size()) return vec[i];
        return m[i];
    }
    const Int __zero = 0;
    constexpr const Int &at(const u32 &i) const {
        if (i < vec.size()) return vec.at(i);
        return m.count(i) ? m.at(i) : __zero;
    }
};





template <typename Int> struct primemap : vecmap<Int> {
    constexpr primemap() {}
    constexpr primemap(Int v, u32 size = 0) : vecmap<Int>(size) {
        assert(v >= 1);
        for (Int i : pvec) {
            if (!(i * i <= v)) break;
            while (v % i == 0) {
                v /= i;
                (*this)[i]++;
            }
        }
        if (v > 1) (*this)[v]++;
    }
    constexpr primemap &operator*=(const primemap &pm) {
        for (auto &p : pm) (*this)[p.first] += p.second;
        return *this;
    }
    constexpr primemap &operator/=(const primemap &pm) {
        for (auto &p : pm) {
            

            (*this)[p.first] -= p.second;
        }
        return *this;
    }
    template <class C> constexpr primemap &id4(const C &pm) {
        for (auto &p : pm)
            if (this->at(p.first) < pm.at(p.first)) (*this)[p.first] = pm.at(p.first);
        return *this;
    }
    constexpr primemap &gcdE(const primemap &pm) {
        for (auto &p : *this)
            if (this->at(p.first) > pm.at(p.first)) (*this)[p.first] = pm.at(p.first);
        return *this;
    }
    constexpr primemap &operator*(const primemap &pm) const { return primemap(*this) *= pm; }
    constexpr primemap &operator/(const primemap &pm) const { return primemap(*this) /= pm; }
    constexpr primemap &gcd(const primemap &pm) const { return primemap(*this).gcdE(pm); }
    constexpr primemap &lcm(const primemap &pm) const { return primemap(*this).id4(pm); }

    constexpr bool divisible(const primemap &pm) const {
        for (const auto &p : pm)
            if (!(this->at(p.first) >= p.second)) return false;

        return true;
    }
    constexpr Int to_int() const {
        Int res = 1;
        for (auto &p : (*this))
            for (Int i : range(p.second)) res *= p.first;
        return res;
    }
    const Int __zero = 0;
    

};








































constexpr u32 id3 = 1000001;


const vector<vector<i32>> id1 = []() {
    vector<i32> vals(id3);
    iota(ALL(vals), 0);
    vector<vector<i32>> res(id3);
    for (int p : pvec) {
        if (!(p * p <= id3)) break;
        for (int i : range(p, id3, p))
            while (vals[i] % p == 0) vals[i] /= p, res[i].emplace_back(p);
    }
    for (int i : range(1, id3))
        if (vals[i] > 1) res[i].emplace_back(vals[i]);
    return res;
}();









template <class ForwardIterator, class BinaryPredicate> struct diff_range {
    struct const_iterator {
        ForwardIterator cur, pcur, last;
        BinaryPredicate pred;
        const_iterator(ForwardIterator cur, ForwardIterator last, BinaryPredicate pred)
            : cur(cur), pcur(cur), last(last), pred(pred) {
            if (cur == last) return;
            (*this)++;
        }
        const_iterator operator++(int) { return ++(*this); }
        const_iterator &operator++() {
            pcur = cur;
            if (cur == last) return *this;
            while (cur + 1 != last && pred(*cur, *(cur + 1))) cur++;
            cur++;
            return *this;
        }
        const pair<ForwardIterator, ForwardIterator> operator*() const { return make_pair(pcur, cur); }
        bool operator!=(const_iterator &itr) { return pcur != itr.pcur; }
    };
    const const_iterator first, last;
    const_iterator tmp;
    diff_range(ForwardIterator first, ForwardIterator last, BinaryPredicate pred)
        : first(const_iterator(first, last, pred)),
          last(const_iterator(last, last, pred)),
          tmp(const_iterator(first, last, pred)) {}
    const_iterator begin() const { return first; }
    const_iterator end() const { return last; }
};

void run() {
    vector<int> vs(10000);
    for (const auto &[l, r] : diff_range(ALL(vs), [](i32 p, i32 q) { return p == q; })) {
        cerr << distance(l, r) << endl;
        cerr << *l << " " << *r << endl;
    }

    i32 N, k;
    cin >> N >> k;
    vector<i32> as(N);
    cin >> as;
    sort(ALL(as)), as.erase(unique(ALL(as)), as.end());

    map<u32, i32> M;
    


    

    


    for (i32 v : as) {
        for (const auto &[l, r] : diff_range(ALL(id1[v]), [](i32 p, i32 q) { return p == q; })) {
            

            M[*l] = max(M[*l], (i32)distance(l, r));
        }
    }

    bool ok = true;
    for (const auto &[l, r] : diff_range(ALL(id1[k]), [](i32 p, i32 q) { return p == q; })) {
        

        ok &= M[*l] >= distance(l, r);
    }
    cout << (ok ? "Yes" : "No") << endl;
}