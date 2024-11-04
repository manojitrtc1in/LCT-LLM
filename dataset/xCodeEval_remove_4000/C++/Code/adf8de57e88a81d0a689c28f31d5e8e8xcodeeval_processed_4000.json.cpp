
    


































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
    void id4()
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
    
    
            atexit(id4);
            start_time = std::chrono::system_clock::now();
    
        }
    } id6;
}

struct id1
{
    std::chrono::system_clock::time_point built_pt, last_pt;
    int built_ln, last_ln;
    std::string built_func, last_func;
    bool id3;
    id1() : id3(false) {}
    void build(int crt_ln, const std::string &crt_func)
    {
        id3 = true;
        last_pt = built_pt = std::chrono::system_clock::now();
        last_ln = built_ln = crt_ln, last_func = built_func = crt_func;
    }
    void set(int crt_ln, const std::string &crt_func)
    {
        if(id3)
        {
            last_pt = std::chrono::system_clock::now();
            last_ln = crt_ln, last_func = crt_func;
        }
        else
        {
            debug_stream << "[ " << crt_ln << " : " << crt_func << " ] " << "id1::set failed (yet to be built clock!)\n";
        }
    }
    void get(int crt_ln, const std::string &crt_func) {
        if(id3) 
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
            debug_stream << "[ " << crt_ln << " : " << crt_func << " ] " << "id1::get failed (yet to be built clock!)\n";
        }
    }
};

    id1 myclock;
    
    
    

    
    
    


namespace std
{
    template <class RAitr> void rsort(RAitr __first, RAitr __last) { sort(__first, __last, greater<>()); }
    template <class T> size_t id2(size_t seed, T const &key) { return seed ^ (hash<T>()(key) + 0x9e3779b9 + (seed << 6) + (seed >> 2)); }
    template <class T, class U> struct hash<pair<T,U>> { size_t operator()(pair<T,U> const &pr) const { return id2(id2(0, pr.first), pr.second); } };
    template <class tuple_t, size_t index = tuple_size<tuple_t>::value - 1>
    struct tuple_hash_calc { static size_t apply(size_t seed, tuple_t const &t) { return id2(tuple_hash_calc<tuple_t, index - 1>::apply(seed, t), get<index>(t)); } };
    template <class tuple_t> struct tuple_hash_calc<tuple_t, 0> { static size_t apply(size_t seed, tuple_t const &t) { return id2(seed, get<0>(t)); } };
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



    

    

template <class T> void dump_func(const T &x) { debug_stream << x << '\n'; }
template <class T,class ...Rest> void dump_func(const T &x, Rest ... rest) { debug_stream << x << ","; dump_func(rest...); }
template <class T> void write(const T &x) { std::cout << x << '\n'; }
template <class T, class ...Rest> void write(const T &x, Rest ... rest) { std::cout << x << ' '; write(rest...); }
void writeln() {}
template <class T, class ...Rest> void writeln(const T &x, Rest ... rest) { std::cout << x << '\n'; writeln(rest...); }

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


    t = 1;


    


    while(t--)
    {
        init();
        input();
        solve();
    }
}

template <class T, class seq_t>
struct id0;

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

        node *add() { return ter ? ter : ter = new node(this); }

        friend bool valid(const node* const p) { return p and p->cnt and p->typ; }

        friend id0<T, seq_t>;

        node *failure = nullptr;
        
        std::size_t sfx_wrd = 0;
    };

    using dict_t = std::map<T, node*>;

    node* const root;

    explicit Trie() : root(new node) {}


    ~Trie() { delete root; }


    std::size_t size() const { return root->cnt; }

    std::size_t type() const { return root->typ; }

    bool insert(const seq_t &s)
    {
        node *p = root;
        p->cnt++;
        for(const T &x : s)
        {
            (p = p->add(x))->cnt++;
        }
        p = p->add();
        p->par->sfx_wrd++;
        if(p->cnt++) return false;
        while(p)
        {
            p->typ++;
            p = p->par;
        }
        return true;
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
                    auto id5 = p->par->child.rend();
                    id5 = std::reverse_iterator<typename dict_t::iterator>(p->par->child.lower_bound(p->tag));
                    s.pop_back();
                    p = p->par;
                    while(id5 != p->child.rend() and not valid(id5->second)) ++id5;
                    if(id5 != p->child.rend())
                    {
                        p = id5->second;
                        s.push_back(id5->first);
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
                            auto id5 = p->child.rbegin();
                            while(id5 != p->child.rend() and not valid(id5->second)) ++id5;
                            if(id5 != p->child.rend())
                            {
                                s.push_back(id5->first);
                                p = id5->second;
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
struct id0
{
    using node = typename Trie<T, seq_t>::node;
    node *root, *now;

    id0() : root(), now() {}

    id0(const Trie<T, seq_t> &trie)
    {
        build(trie);
    }

    void build(const Trie<T, seq_t> &trie)
    {
        now = root = trie.root;
        std::queue<node*> que;
        que.emplace(now);
        while(not que.empty())
        {
            node* const p = que.front(); que.pop();
            for(const auto &e : p->child)
            {
                T x; node *t, *_p = p; std::tie(x, t) = e;
                do
                {
                    _p = _p->failure;
                } while(_p and not _p->child[x]);
                t->failure = _p ? _p->child[x] : trie.root;
                t->sfx_wrd += t->failure->sfx_wrd;
                que.emplace(t);
            }
        }
    }

    void next(const T &x)
    {
        while(now and not now->child[x])
        {
            now = now->failure;
        }
        now = now ? now->child[x] : root;
    }

    std::size_t suffix_count()
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
    id0<char,string> aho;
    aho.build(trie);
    for(int i=0; i<m; ++i)
    {
        x[i]=aho.suffix_count();
        aho.next(t[i]);
    }
}