#ifdef DEBUG
    #define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("Ofast")
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <complex>
#include <iomanip>
#include <bitset>
#include <random>
#include <chrono>

#define stdin_filepath "stdin.txt"
#define stdout_filepath "stdout.txt"
#define stderr_filepath "stderr.txt"
#define debug_stream std::cerr
#define iostream_untie true
#define __precision__ 10

#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define mkp make_pair
#define mkt make_tuple
#define popcnt __builtin_popcountll

using i64 = int_fast64_t;
using pii = std::pair<int, int>;
using pll = std::pair<int_fast64_t, int_fast64_t>;
template <class T> using heap = std::priority_queue<T>;
template <class T> using minheap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class T> constexpr T inf = std::numeric_limits<T>::max() / (T)2 - (T)1123456;
constexpr int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
constexpr int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};

namespace execution
{
    std::chrono::system_clock::time_point start_time, end_time;
    void print_elapsed_time()
    {
        end_time = std::chrono::system_clock::now();
        std::cerr << "\n----- Exec time : ";
        std::cerr << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        std::cerr << " ms -----\n";
    }
    struct setupper
    {
        setupper()
        {
            if(iostream_untie)
            {
                std::ios::sync_with_stdio(false);
                std::cin.tie(nullptr);
                

                

            }
            std::cout << std::fixed << std::setprecision(__precision__);
            std::cerr << std::fixed << std::setprecision(__precision__);
    #ifdef LOCAL
            if(!freopen(stdout_filepath, "wt", stdout))
            {
                freopen("CON", "wt", stdout);
                std::cerr << "Failed to open the stdout file\n\n";
            }
            if(!freopen(stdin_filepath, "rt", stdin))
            {
                freopen("CON", "rt", stdin);
                std::cerr << "Failed to open the stdin file\n\n";
            }
            if(!freopen(stderr_filepath, "wt", stderr))
            {
                freopen("CON", "wt", stderr);
                std::cerr << "Failed to open the stderr file\n\n";
            }
            std::cout << "", std::cerr << "";
    #endif
    #if defined(LOCAL) || defined(DEBUG)
            atexit(print_elapsed_time);
            start_time = std::chrono::system_clock::now();
    #endif
        }
    } __setupper;
}

struct myclock_t
{
    std::chrono::system_clock::time_point built_pt, last_pt;
    int built_ln, last_ln;
    std::string built_func, last_func;
    bool is_built;
    myclock_t() : is_built(false) {}
    void build(int crt_ln, const std::string &crt_func)
    {
        is_built = true;
        last_pt = built_pt = std::chrono::system_clock::now();
        last_ln = built_ln = crt_ln, last_func = built_func = crt_func;
    }
    void set(int crt_ln, const std::string &crt_func)
    {
        if(is_built)
        {
            last_pt = std::chrono::system_clock::now();
            last_ln = crt_ln, last_func = crt_func;
        }
        else
        {
            debug_stream << "[ " << crt_ln << " : " << crt_func << " ] " << "myclock_t::set failed (yet to be built clock!)\n";
        }
    }
    void get(int crt_ln, const std::string &crt_func) {
        if(is_built) 
        {
            std::chrono::system_clock::time_point crt_pt(std::chrono::system_clock::now());
            int64_t diff = std::chrono::duration_cast<std::chrono::milliseconds>(crt_pt - last_pt).count();
            debug_stream << diff << " ms elapsed from" << " [ " <<  last_ln << " : " << last_func << " ]";
            if(last_ln == built_ln) debug_stream << " (when built)";
            debug_stream << " to" << " [ " << crt_ln << " : " << crt_func << " ]" << "\n";
            last_pt = built_pt, last_ln = built_ln, last_func = built_func;
        }
        else
        {
            debug_stream << "[ " << crt_ln << " : " << crt_func << " ] " << "myclock_t::get failed (yet to be built clock!)\n";
        }
    }
};
#if defined(LOCAL) || defined(DEBUG)
    myclock_t myclock;
    #define build_clock() myclock.build(__LINE__, __func__)
    #define set_clock() myclock.set(__LINE__, __func__)
    #define get_clock() myclock.get(__LINE__, __func__)
#else
    #define build_clock()
    #define set_clock()
    #define get_clock()
#endif

namespace std
{
    template <class RAitr> void rsort(RAitr __first, RAitr __last) { sort(__first, __last, greater<>()); }
    template <class T> size_t hash_combine(size_t seed, T const &key) { return seed ^ (hash<T>()(key) + 0x9e3779b9 + (seed << 6) + (seed >> 2)); }
    template <class T, class U> struct hash<pair<T,U>> { size_t operator()(pair<T,U> const &pr) const { return hash_combine(hash_combine(0, pr.first), pr.second); } };
    template <class tuple_t, size_t index = tuple_size<tuple_t>::value - 1>
    struct tuple_hash_calc { static size_t apply(size_t seed, tuple_t const &t) { return hash_combine(tuple_hash_calc<tuple_t, index - 1>::apply(seed, t), get<index>(t)); } };
    template <class tuple_t> struct tuple_hash_calc<tuple_t, 0> { static size_t apply(size_t seed, tuple_t const &t) { return hash_combine(seed, get<0>(t)); } };
    template <class ...T> struct hash<tuple<T...>> { size_t operator()(tuple<T...> const &t) const { return tuple_hash_calc<tuple<T...>>::apply(0, t); } };
    template <class T, class U> istream &operator>> (std::istream &s, pair<T,U> &p) { return s >> p.first >> p.second; }
    template <class T, class U> ostream &operator<< (std::ostream &s, const pair<T,U> p) { return s << p.first << " " << p.second; }
    template <class T> istream &operator>> (istream &s, vector<T> &v) { for(T &e : v) { s >> e; } return s; }
    template <class T> ostream &operator<< (ostream &s, const vector<T> &v) { for(size_t i = 0; i < v.size(); ++i) { s << (i ? " " : "") << v[i]; } return s; }
    template <class tuple_t, size_t index>
    struct tupleos
    {
        static ostream &apply(ostream &s, const tuple_t &t)
        {
            tupleos<tuple_t,index - 1>::apply(s,t);
            return s << " " << get<index>(t);
        }
    };
    template <class tuple_t>
    struct tupleos<tuple_t, 0>
    {
        static ostream &apply(ostream &s, const tuple_t &t)
        {
            return s << get<0>(t);
        }
    };
    template <class ...T> ostream &operator<< (ostream &s, const tuple<T...> &t)
    {
        return tupleos<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(s,t);
    }
    template <> ostream &operator<< (ostream &s, const tuple<> &t) { return s; }
}


#if defined(LOCAL) || defined(DEBUG)
    #define dump(...) debug_stream << " [ " << __LINE__ << " : " << __FUNCTION__ << " ] " << #__VA_ARGS__ << " : ", dump_func(__VA_ARGS__)
#else
    #define dump(...)
#endif
template <class T> void dump_func(const T &x) { debug_stream << x << '\n'; }
template <class T,class ...Rest> void dump_func(const T &x, Rest ... rest) { debug_stream << x << ","; dump_func(rest...); }
template <class T> void write(const T &x) { std::cout << x << '\n'; }
template <class T, class ...Rest> void write(const T &x, Rest ... rest) { std::cout << x << ' '; write(rest...); }
void writeln() {}
template <class T, class ...Rest> void writeln(const T &x, Rest ... rest) { std::cout << x << '\n'; writeln(rest...); }
#define esc(...) writeln(__VA_ARGS__), exit(0)
template <class P> void read_range(P __first, P __second) { for(P i = __first; i != __second; ++i) std::cin >> *i; }

template <class T> bool chmin(T &x, const T &y) { return x > y ? x = y, true : false; }
template <class T> bool chmax(T &x, const T &y) { return x < y ? x = y, true : false; }
template <class T> constexpr T minf(const T &x, const T &y) { return std::min(x,y); }
template <class T> constexpr T maxf(const T &x, const T &y) { return std::max(x,y); }
constexpr bool odd(int_fast64_t n) { return n & 1; }
constexpr bool even(int_fast64_t n) { return (int)odd(n) ^ 1; }
constexpr bool bit(int_fast64_t n, int e) { return (n >> e) & 1; }
constexpr int_fast64_t mask(int_fast64_t n, int e) { return n & ((1 << e) - 1); }
constexpr int_fast64_t ilog(int_fast64_t x, int_fast64_t b = 2) { return x ? 1 + ilog(x / b, b) : -1; }
constexpr int_fast64_t gcd(int_fast64_t x, int_fast64_t y)
{
    x = x > 0 ? x : -x, y = y > 0 ? y : -y;
    while(y) x ^= y ^= (x %= y) ^= y;
    return x;
}
constexpr int_fast64_t lcm(int_fast64_t x, int_fast64_t y) { return x ? x / gcd(x, y) * y : 0; }
int_fast64_t binry(int_fast64_t ok, int_fast64_t ng, const std::function<bool(int_fast64_t)> &fn)
{
    while (std::abs(ok - ng) > 1)
    {
        int_fast64_t mid = (ok + ng) / 2;
        (fn(mid) ? ok : ng) = mid;
    }
    return ok;
}
template <class A, size_t N, class T> void init(A (&array)[N], const T &val) { std::fill((T*)array, (T*)(array + N), val); }
template <class A, size_t N> void init(A (&array)[N]) { memset(array, 0, sizeof(array)); }
template <class T> std::vector<int> cmprs(const std::vector<T> &v)
{
    std::vector<T> tmp = v; std::vector<int> ret;
    std::sort(tmp.begin(), tmp.end());
    tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());
    for(const T &i : v) ret.emplace_back(std::lower_bound(tmp.begin(), tmp.end() ,i) - tmp.begin());
    return ret;
}
template <class T> std::vector<int> cmprs(const T *__first, const T *__last) { return cmprs(std::vector<T>(__first, __last)); }
void for_subset(int_fast64_t s, const std::function<void(int_fast64_t)> &fn) { int_fast64_t t = s; do { fn(t); } while((--t &= s) != s); }





signed main()
{
    void solve();
    void input();
    void init();

    int t = 1;

#ifdef LOCAL
    t = 1;
#endif

    


    while(t--)
    {
        init();
        input();
        solve();
    }
}

template <class T, class seq_t>
struct Aho_Corasick;

template <class T, class seq_t = std::vector<T>>
struct Trie
{
    struct node
    {
        const T tag;
        const bool tag_set, is_ter, is_root;
        node* const par, *ter;
        std::map<T, node*> child;
        std::size_t cnt, typ;

        explicit node() : tag(), tag_set(), is_ter(), is_root(true), par(), ter(), child(), cnt(), typ()
        {}

        explicit node(node* const p) : tag(), tag_set(), is_ter(true), is_root(), par(p), ter(), child(), cnt(), typ()
        {}

        explicit node(const T &_tag, node* const p) : tag(_tag), tag_set(true), is_ter(), is_root(), par(p), ter(), child(), cnt(), typ()
        {}

        ~node()
        {
            delete ter;
            for(auto &e : child) delete e.second;
        }

        node *add(const T &x)
        {
            node* &p = child[x];
            return p ? p : p = new node(x, this);
        }

        node *add() { return sfx_wrd++, ter ? ter : ter = new node(this); }

        friend bool valid(const node* const p) { return p and p->cnt and p->typ; }

        friend class Aho_Corasick<T, seq_t>;

    private:
        node *failure = nullptr;
        
        std::size_t sfx_wrd = 0;
    };

    using dict_t = std::map<T, node*>;

    node* const root;

    explicit Trie() : root(new node) {}

#if defined(LOCAL) or defined(DEBUG)
    ~Trie() { delete root; }
#endif

    std::size_t size() const { return root->cnt; }

    std::size_t type() const { return root->typ; }

    node *insert(const seq_t &s)
    {
        node *p = root;
        p->cnt++;
        for(const T &x : s)
        {
            (p = p->add(x))->cnt++;
        }
        node *ret = p = p->add();
        if(not p->cnt++)
        {
            while(p)
            {
                p->typ++;
                p = p->par;
            }
        }
        return ret;
    }

    std::size_t erase(const seq_t &s, std::size_t k = 1)
    {
        node *p = root;
        for(const T &x : s)
        {
            p = p->child[x];
            if(not p) return 0;
        }
        p = p->ter;
        if(not p) return 0;
        bool ext = k >= p->cnt;
        if(ext)
        {
            k = p->cnt;
            p->par->suf_wrd--;
        }
        while(p)
        {
            p->cnt -= k;
            p->typ -= ext;
            p = p->par;
        }
        return k;
    }

    std::size_t erase(std::size_t idx)
    {
        if(idx >= size()) return 0;
        node *p = root;
        while(true)
        {
            if(p->ter)
            {
                std::size_t here = p->ter->cnt;
                if(idx < here)
                {
                    p = p->ter;
                    break;
                }
                idx -= here;
            }
            node *nx = nullptr;
            for(const auto &e : p->child)
            {
                T x; node *t; tie(x, t) = e;
                std::size_t here = t ? t->cnt : 0;
                if(idx < here)
                {
                    nx = t;
                    break;
                }
                else
                {
                    idx -= here;
                }
            }
            p = nx;
        }
        bool uni_typ = not --p->ter->cnt;
        while(p) {
            p->cnt--;
            p->typ -= uni_typ;
            p = p->par;
        }
        return 1;
    }

    std::size_t count(const seq_t &s) const
    {
        node *p = root;
        for(const T &x : s)
        {
            p = p->child[x];
            if(!p->child[x]) return 0;
        }
        p = p->ter;
        return p ? p->cnt : 0;
    }

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    seq_t operator[](std::size_t idx) const
    {
        assert(idx < size());
        node *p = root;
        seq_t ret = seq_t();
        while(true)
        {
            if(p->ter)
            {
                std::size_t here = p->ter->cnt;
                if(idx < here) break;
                idx -= here;
            }
            node *nx = nullptr;
            for(const auto &e : p->child)
            {
                T x; node *t; std::tie(x, t) = e;
                std::size_t here = t ? t->cnt : 0;
                if(idx < here)
                {
                    ret.push_back(x);
                    nx = t; break;
                }
                idx -= here;
            }
            p = nx;
        }
        return ret;
    }

    struct iterator_t : std::iterator<std::bidirectional_iterator_tag, seq_t, std::ptrdiff_t, node*, seq_t>
    {
        Trie* const trie_ptr;
        node *node_ptr;
        seq_t s;
        std::size_t type_idx, size_idx;

        explicit iterator_t()
            : trie_ptr(), node_ptr(), s(), type_idx(-1), size_idx(-1)
        {}

        iterator_t(const iterator_t &itr)
            : trie_ptr(itr.trie_ptr), node_ptr(itr.node_ptr), s(itr.s), type_idx(itr.type_idx), size_idx(itr.size_idx)
        {}

        explicit iterator_t(Trie *_trie_ptr, std::size_t _type_idx)
            : trie_ptr(_trie_ptr), node_ptr(), s(), type_idx(_type_idx), size_idx()
        {
            if(_type_idx < trie_ptr->type())
            {
                node* &p = (node_ptr = trie_ptr->root);
                while(p)
                {
                    std::size_t here_typ = p->ter ? p->ter->typ : 0;
                    std::size_t here_cnt = p->ter ? p->ter->cnt : 0;
                    if(_type_idx < here_typ)
                    {
                        p = p->ter; break;
                    }
                    _type_idx -= here_typ;
                    size_idx += here_cnt;
                    node *nx = nullptr;
                    for(const auto &e : p->child)
                    {
                        T x; node *t; std::tie(x, t) = e;
                        here_typ = t ? t->typ : 0;
                        here_cnt = t ? t->cnt : 0;
                        if(_type_idx < here_typ)
                        {
                            s.push_back(x);
                            nx = t; break;
                        }
                        _type_idx -= here_typ;
                        size_idx += here_cnt;
                    }
                    p = nx;
                }
            }
            else
            {
                size_idx = trie_ptr->size();
            }
        }

        explicit iterator_t(Trie *_trie_ptr, node *_node_ptr, const seq_t &_s, std::size_t _type_idx, std::size_t _size_idx)
            : trie_ptr(_trie_ptr), node_ptr(_node_ptr), s(_s), type_idx(_type_idx), size_idx(_size_idx)
        {}

        node *operator->() const { return node_ptr; }

        seq_t operator*() const { return s; }

        bool operator==(const iterator_t &itr) const
        {
            return trie_ptr == itr.trie_ptr and type_idx == itr.type_idx;
        }

        bool operator!=(const iterator_t &itr) const { return not (*this == itr); }

        iterator_t &operator++()
        {
            size_idx += count();
            node *p = node_ptr;
            while(p->par)
            {
                auto dict_itr = p->par->child.begin();
                if(not p->is_ter)
                {
                    dict_itr = p->par->child.upper_bound(p->tag);
                    s.pop_back();
                }
                p = p->par;
                while(dict_itr != p->child.end() and not valid(dict_itr->second)) ++dict_itr;
                if(dict_itr != p->child.end())
                {
                    p = dict_itr->second;
                    s.push_back(p->tag);
                    break;
                }
            }
            if(p->is_root)
            {
                node_ptr = nullptr;
            }
            else
            {
                while(not valid(p->ter))
                {
                    node *nx = nullptr;
                    for(const auto &e : p->child)
                    {
                        T x; node *t; std::tie(x, t) = e;
                        if(valid(t))
                        {
                            s.push_back(x);
                            nx = t; break;
                        }
                    }
                    p = nx;
                }
                node_ptr = p->ter;
            }
            ++type_idx;
            return *this;
        }

        iterator_t operator++(int)
        {
            iterator_t ret = *this; return ++(*this), ret;
        }

        iterator_t &operator--()
        {
            if(*this == trie_ptr->end())
            {
                node *p = trie_ptr->root;
                if(p->typ)
                {
                    while(not p->is_ter)
                    {
                        auto dict_itr = p->child.rbegin();
                        while(dict_itr != p->child.rend() and not valid(dict_itr->second))
                        {
                            ++dict_itr;
                        }
                        if(dict_itr != p->child.rend())
                        {
                            p = dict_itr->second;
                            s.push_back(p->tag);
                        }
                        else
                        {
                            p = p->ter;
                        }
                    }
                    node_ptr = p;
                }
            }
            else
            {
                bool is_prefix = false;
                node *p = node_ptr->par;
                while(p->par)
                {
                    auto map_ritr = p->par->child.rend();
                    map_ritr = std::reverse_iterator<typename dict_t::iterator>(p->par->child.lower_bound(p->tag));
                    s.pop_back();
                    p = p->par;
                    while(map_ritr != p->child.rend() and not valid(map_ritr->second)) ++map_ritr;
                    if(map_ritr != p->child.rend())
                    {
                        p = map_ritr->second;
                        s.push_back(map_ritr->first);
                        break;
                    }
                    else if(p->ter and p->ter->typ)
                    {
                        is_prefix = true; break;
                    }
                }
                if(is_prefix)
                {
                    node_ptr = p->ter;
                }
                else
                {
                    if(p->is_root)
                    {
                        node_ptr = nullptr;
                    }
                    else
                    {
                        while(not p->is_ter)
                        {
                            auto map_ritr = p->child.rbegin();
                            while(map_ritr != p->child.rend() and not valid(map_ritr->second)) ++map_ritr;
                            if(map_ritr != p->child.rend())
                            {
                                s.push_back(map_ritr->first);
                                p = map_ritr->second;
                            }
                            else
                            {
                                p = p->ter;
                            }
                        }
                        node_ptr = p;
                    }
                }
            }
            --type_idx;
            if(node_ptr) size_idx -= node_ptr->cnt;
            else size_idx = -1;
            return *this;
        }

        iterator_t operator--(int)
        {
            iterator_t ret = *this; return --(*this), ret;
        }

        std::size_t count() const { return node_ptr ? node_ptr->cnt : 0; }
    };

    friend iterator_t;

    iterator_t begin() { return iterator_t(this, 0); }

    iterator_t end() { return iterator_t(this, type()); }

    std::reverse_iterator<iterator_t> rbegin() { return std::reverse_iterator<iterator_t>(end()); }

    std::reverse_iterator<iterator_t> rend() { return std::reverse_iterator<iterator_t>(begin()); }

    iterator_t lower_bound(const seq_t &key)
    {
        std::size_t size_idx = 0, type_idx = 0;
        seq_t s;
        node *p = root;
        bool go_back = false;
        for(const T &x : key)
        {
            if(p->ter)
            {
                size_idx += p->ter->cnt;
                type_idx += p->ter->typ;
            }
            node *nx = nullptr;
            for(const auto &e : p->child)
            {
                T y; node *t; std::tie(y, t) = e;
                if(valid(t))
                {
                    if(y < x)
                    {
                        size_idx += t->cnt;
                        type_idx += t->typ;
                    }
                    else if(t->typ)
                    {
                        s.push_back(y);
                        nx = t; break;
                    }
                }
            }
            if(not nx)
            {
                go_back = true; break;
            }
            p = nx;
            if(p->tag > x) break;
        }
        if(go_back)
        {
            while(not p->is_root)
            {
                p = p->par;
                auto dict_itr = p->child.upper_bound(s.back());
                s.pop_back();
                while(dict_itr != p->child.end() and not valid(dict_itr->second)) ++dict_itr;
                if(dict_itr != p->child.end())
                {
                    p = dict_itr->second;
                    s.push_back(dict_itr->first);
                    break;
                }
            }
            if(p->is_root) return end();
        }
        while(not p->is_ter)
        {
            if(valid(p->ter))
            {
                p = p->ter;
            }
            else
            {
                auto dict_itr = p->child.begin();
                while(dict_itr != p->child.end() and not valid(dict_itr->second)) ++dict_itr;
                p = dict_itr->second; s.push_back(dict_itr->first);
            }
        }
        return iterator_t(this, p, s, type_idx, size_idx);
    }

    iterator_t upper_bound(const seq_t &key)
    {
        auto itr = lower_bound(key);
        if(*itr == key) ++itr;
        return itr;
    }
};

template <class T, class seq_t = std::vector<T>>
struct Aho_Corasick
{
    using node = typename Trie<T, seq_t>::node;
    node *root;

    Aho_Corasick() : root() {}

    Aho_Corasick(const Trie<T, seq_t> &trie)
    {
        build(trie);
    }

    node *build(const Trie<T, seq_t> &trie)
    {
        root = trie.root;
        std::queue<node*> que;
        que.emplace(root);
        while(not que.empty())
        {
            node* const now = que.front(); que.pop();
            for(const auto &e : now->child)
            {
                T x; node *t, *p = now; std::tie(x, t) = e;
                do { p = p->failure; } while(p and not p->child[x]);
                t->failure = p ? p->child[x] : root;
                t->sfx_wrd += t->failure->sfx_wrd;
                que.emplace(t);
            }
        }
        return root;
    }

    node *next(node *now, const T &x)
    {
        while(now and not now->child[x])
        {
            now = now->failure;
        }
        return now = now ? now->child[x] : root;
    }

    std::size_t query(node *now)
    {
        return now->sfx_wrd;
    }
};




using namespace std;

int n,m;
string t,s[1<<18];

void init()
{}

void input()
{
    std::cin >> t >> n;
    read_range(s, s+n);
    m = t.size();
}


void solve()
{
    void calc(vector<int>&);

    vector<int> lft,rgt;

    calc(lft);

    reverse(all(t));
    for(int i=0; i<n; ++i)
    {
        reverse(all(s[i]));
    }

    calc(rgt);

    i64 ans=0;
    for(int i=1; i<m; ++i)
    {
        ans+=(i64)lft[i]*rgt[m-i];
    }
    std::cout << ans << "\n";
}


void calc(vector<int> &x)
{
    x.resize(m);
    Trie<char,string> trie;
    for(int i=0; i<n; ++i)
    {
        trie.insert(s[i]);
    }

    Aho_Corasick<char,string> aho;
    auto now=aho.build(trie);

    for(int i=0; i<m; ++i)
    {
        x[i]=aho.query(now);
        now=aho.next(now,t[i]);
    }
}