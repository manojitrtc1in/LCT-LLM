

    

    
    
    







































namespace config
{
    const auto start_time{std::chrono::system_clock::now()};
    int64_t elapsed()
    {
        using namespace std::chrono;
        const auto end_time{system_clock::now()};
        return duration_cast<milliseconds>(end_time - start_time).count();
    }
    __attribute__((constructor)) void setup()
    {
        using namespace std;
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout << fixed << setprecision(15);
    
        atexit([]{ ofstream cnsl("CON"); char bufc; if(cin >> bufc) cnsl << "\n\033[1;35mwarning\033[0m: buffer not empty.\n\n"; });
    
    }
    unsigned cases(void), caseid = 1;
    template <class C> void main() { for(const unsigned total = cases(); caseid <= total; ++caseid) C(); }
} 


namespace std
{
    template <class T, class U> istream &operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
    template <class T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p) { return os << p.first << ' ' << p.second; }
    template <class tuple_t, size_t index> struct tupleis { static istream &apply(istream &is, tuple_t &t) { tupleis<tuple_t, index - 1>::apply(is, t); return is >> get<index>(t); } };
    template <class tuple_t> struct tupleis<tuple_t, SIZE_MAX> { static istream &apply(istream &is, tuple_t &t) { return is; } };
    template <class... T> istream &operator>>(istream &is, tuple<T...> &t) { return tupleis<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(is, t); }
    template <> istream &operator>>(istream &is, tuple<> &t) { return is; }
    template <class tuple_t, size_t index> struct tupleos { static ostream &apply(ostream &os, const tuple_t &t) { tupleos<tuple_t, index - 1>::apply(os, t); return os << ' ' << get<index>(t); } };
    template <class tuple_t> struct tupleos<tuple_t, 0> { static ostream &apply(ostream &os, const tuple_t &t) { return os << get<0>(t); } };
    template <class... T> ostream &operator<<(ostream &os, const tuple<T...> &t) { return tupleos<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(os, t); }
    template <> ostream &operator<<(ostream &os, const tuple<> &t) { return os; }
    template <class Container, typename Value = typename Container::value_type, enable_if_t<!is_same<decay_t<Container>, string>::value, nullptr_t> = nullptr>
    istream& operator>>(istream& is, Container &cont) { for(auto&& e : cont) is >> e; return is; }
    template <class Container, typename Value = typename Container::value_type, enable_if_t<!is_same<decay_t<Container>, string>::value, nullptr_t> = nullptr>
    ostream& operator<<(ostream& os, const Container &cont) { bool flag = 1; for(auto&& e : cont) flag ? flag = 0 : (os << ' ', 0), os << e; return os; }
} 


namespace workspace {


template <class T = void>
struct read
{
    typename std::remove_const<T>::type value;
    template <class... types>
    read(types... args) : value(args...) { std::cin >> value; }
    operator T() const { return value; }
};
template <>
struct read<void>
{
    template <class T>
    operator T() const { T value; std::cin >> value; return value; }
};
} 


namespace workspace {
std::ostream &casefmt(std::ostream& os) { return os << "Case 
} 


namespace workspace {


template <class lambda_type>
class fixed_point
{
    lambda_type func;
public:
    fixed_point(lambda_type &&f) : func(std::move(f)) {}
    template <class... Args> auto operator()(Args &&... args) const { return func(*this, std::forward<Args>(args)...); }
};
} 


namespace workspace {
template <class T, class Comp = std::less<T>> bool chle(T &x, const T &y, Comp comp = Comp()) { return comp(y, x) ? x = y, true : false; }
template <class T, class Comp = std::less<T>> bool chge(T &x, const T &y, Comp comp = Comp()) { return comp(x, y) ? x = y, true : false; }
} 


namespace workspace {


template <class iter_type, class pred_type, std::enable_if_t<std::is_convertible_v<std::invoke_result_t<pred_type, iter_type>, bool>, std::nullptr_t> = nullptr>
iter_type binary_search(iter_type ok, iter_type ng, pred_type pred)
{
    assert(ok != ng);
    intmax_t dist(ng - ok);
    while(std::abs(dist) > 1)
    {
        iter_type mid(ok + dist / 2);
        if(pred(mid)) ok = mid, dist -= dist / 2;
        else ng = mid, dist /= 2;
    }
    return ok;
}


template <class real_type, class pred_type, std::enable_if_t<std::is_convertible_v<std::invoke_result_t<pred_type, real_type>, bool>, std::nullptr_t> = nullptr>
real_type binary_search(real_type ok, real_type ng, const real_type eps, pred_type pred)
{
    assert(ok != ng);
    while(std::abs(ok - ng) > eps)
    {
        real_type mid{(ok + ng) / 2};
        (pred(mid) ? ok : ng) = mid;
    }
    return ok;
}
} 


using namespace std; using namespace __gnu_cxx;
using i32 = int_least32_t; using i64 = int_least64_t;
using p32 = pair<i32, i32>; using p64 = pair<i64, i64>;
template <class T, class Comp = less<T>> using heap = priority_queue<T, vector<T>, Comp>;
template <class T> using hashset = unordered_set<T>;
template <class Key, class Value> using hashmap = unordered_map<Key, Value>;

namespace workspace { struct solver; } int main() { config::main<workspace::solver>(); }
unsigned config::cases() {
    

    

    return 1;
}

template <size_t depth, class int_type = int_least64_t>
class id0
{
    struct node
    {
        bool tag;
        node *par, *lft, *rgt;
        size_t digit;
        size_t cnt, typ;
        node() : tag(), par(), lft(), rgt(), digit(depth), cnt(), typ() {}
        node(bool _tag, node *p) : tag(_tag), par(p), lft(), rgt(), digit((int)p->digit - 1), cnt(), typ() {}
    
        friend node *alloc(bool _tag, node *p)
        {
            constexpr size_t id1 = 1.5e6;
            static node stock[id1];
            static size_t node_cnt = 0;
            return &(stock[node_cnt++] = node(_tag, p));
        }
    

        friend bool valid(node *p) { return p and p->cnt; }
    } *const root;

    

    static_assert(depth != 0, "depth must be a positive integer.");
    int_type power[depth];
    bool bit(int_type x, size_t i) const { return x & power[i]; }

public:
    id0() : root(new node) { power[depth - 1] = 1; for(size_t i = depth - 1; i--; ) power[i] = power[i + 1] << 1; }
    ~id0() { delete root; }

    size_t size() const { return root->cnt; }
    size_t type() const { return root->typ; }

    bool insert(int_type x)
    {
        node *p = root;
        for(size_t i = 0; i < depth; ++i)
        {
            p->cnt++;
            if(bit(x, i))
            {
                if(not p->rgt) p->rgt = alloc(1, p);
                p = p->rgt;
            }
            else
            {
                if(not p->lft) p->lft = alloc(0, p);
                p = p->lft;
            }
        }
        if(p->cnt++) return false;
        while(p)
        {
            p->typ++;
            p = p->par;
        }
        return true;
    }

    size_t erase(int_type x, size_t k = 1)
    {
        node *p = root;
        for(size_t i = 0; i < depth; ++i)
        {
            if(bit(x, i))
            {
                if(not p->rgt) return 0;
                p = p->rgt;
            }
            else
            {
                if(not p->lft) return 0;
                p = p->lft;
            }
        }
        bool uni_typ = k >= p->cnt;
        if(uni_typ) k = p->cnt;
        while(p)
        {
            p->cnt -= k;
            p->typ -= uni_typ;
            p = p->par;
        }
        return k;
    }

    size_t count(int_type x) const
    {
        node *p = root;
        for(size_t i = 0; i < depth; ++i)
        {
            if(bit(x, i))
            {
                if(not p->rgt) return 0;
                p = p->rgt;
            }
            else
            {
                if(not p->lft) return 0;
                p = p->lft;
            }
        }
        return p->cnt;
    }

    int_type closest(int_type x) const
    {
        assert(size());
        node *p = root;
        int_type ret = 0;
        for(size_t i = 0; i != depth; ++i)
        {
            if(bit(x, i))
            {
                if(valid(p->rgt))
                {
                    p = p->rgt;
                    ret += power[i];
                }
                else
                {
                    p = p->lft;
                }
            }
            else
            {
                if(p->lft && p->lft->cnt)
                {
                    p = p->lft;
                }
                else
                {
                    p = p->rgt;
                    ret += power[i];
                }
            }
        }
        return ret;
    }

    int_type operator[](size_t idx) const
    {
        assert(idx < size());
        node *p = root;
        int_type ret = 0;
        for(size_t i = 0; i < depth; ++i)
        {
            size_t thr = p->lft ? p->lft->cnt : 0;
            if(idx < thr)
            {
                p = p->lft;
            }
            else
            {
                idx -= thr;
                p = p->rgt;
                ret += power[i];
            }
        }
        return ret;
    }

    struct iterator_type : std::iterator<std::bidirectional_iterator_tag, int_type, std::ptrdiff_t, node *, int_type>
    {
        id0 *const trie_ptr;
        node *node_ptr;
        int_type s;
        size_t type_idx, size_idx;

        iterator_type()
            : trie_ptr(), node_ptr(), s(), type_idx(-1), size_idx(-1)
        {}

        iterator_type(const iterator_type &itr)
            : trie_ptr(itr.trie_ptr), node_ptr(itr.node_ptr), s(itr.s),
            type_idx(itr.type_idx), size_idx(itr.size_idx)
        {}

        iterator_type(id0 *_trie_ptr, size_t _type_idx)
            : trie_ptr(_trie_ptr), node_ptr(), s(), type_idx(_type_idx),
            size_idx()
        {
            if(_type_idx < trie_ptr->type())
            {
                node *&p = (node_ptr = trie_ptr->root);
                for(size_t i = 0; i < depth; ++i)
                {
                    if(valid(p->lft))
                    {
                        if(_type_idx < p->lft->typ)
                        {
                            p = p->lft;
                        }
                        else
                        {
                            _type_idx -= p->lft->typ;
                            size_idx += p->lft->cnt;
                            p = p->rgt;
                            s += trie_ptr->power[i];
                        }
                    }
                    else
                    {
                        p = p->rgt;
                        s += trie_ptr->power[i];
                    }
                }
            }
            else
            {
                size_idx = trie_ptr->size();
            }
        }

        iterator_type(id0 *_trie_ptr, node *_node_ptr, int_type _s,
                            size_t _type_idx, size_t _size_idx)
            : trie_ptr(_trie_ptr), node_ptr(_node_ptr), s(_s),
            type_idx(_type_idx), size_idx(_size_idx)
        {}

        node *operator->() const { return node_ptr; }

        int_type operator*() const { return s; }

        bool operator==(const iterator_type &itr) const
        {
            return trie_ptr == itr.trie_ptr and type_idx == itr.type_idx;
        }

        bool operator!=(const iterator_type &itr) const { return not(*this == itr); }

        iterator_type &operator++()
        {
            size_idx += count();
            node *p = node_ptr;
            size_t i = depth;
            while(i--)
            {
                bool t = p->tag;
                p = p->par;
                if(t)
                {
                    s -= trie_ptr->power[i];
                }
                else if(valid(p->rgt))
                {
                    s += trie_ptr->power[i];
                    p = p->rgt;
                    break;
                }
            }
            if(p->digit == depth)
            {
                node_ptr = nullptr;
            }
            else
            {
                while(++i < depth)
                {
                    if(valid(p->lft))
                    {
                        p = p->lft;
                    }
                    else
                    {
                        p = p->rgt;
                        s += trie_ptr->power[i];
                    }
                }
                node_ptr = p;
            }
            ++type_idx;
            return *this;
        }

        iterator_type &operator++(int)
        {
            iterator_type ret = *this;
            return ++(*this), ret;
        }

        iterator_type &operator--()
        {
            if(*this == trie_ptr->end())
            {
                node *p = trie_ptr->root;
                if(valid(p))
                {
                    for(size_t i = 0; i < depth; ++i)
                    {
                        if(valid(p->rgt))
                        {
                            p = p->rgt;
                            s += trie_ptr->power[i];
                        }
                        else
                        {
                            p = p->lft;
                        }
                    }
                    node_ptr = p;
                }
            }
            else
            {
                node *p = node_ptr;
                size_t i = depth;
                while(i--)
                {
                    bool t = p->tag;
                    p = p->par;
                    if(t)
                    {
                        s -= trie_ptr->power[i];
                        if(valid(p->lft))
                        {
                            p = p->lft;
                            break;
                        }
                    }
                }

                if(p->digit == depth)
                {
                    node_ptr = nullptr;
                }
                else
                {
                    while(++i < depth)
                    {
                        if(valid(p->rgt))
                        {
                            p = p->rgt;
                            s += trie_ptr->power[i];
                        }
                        else
                        {
                            p = p->lft;
                        }
                    }
                    node_ptr = p;
                }
            }
            --type_idx;
            if(node_ptr)
                size_idx -= node_ptr->cnt;
            else
                size_idx = -1;
            return *this;
        }

        iterator_type &operator--(int)
        {
            iterator_type ret = *this;
            return --(*this), ret;
        }

        size_t count() const
        {
            return node_ptr ? node_ptr->cnt : 0;
        }
    }; 


    friend iterator_type;

    iterator_type begin() { return iterator_type(this, 0); }
    iterator_type end() { return iterator_type(this, type()); }
    std::reverse_iterator<iterator_type> rbegin() { return std::reverse_iterator<iterator_type>(end()); }
    std::reverse_iterator<iterator_type> rend() { return std::reverse_iterator<iterator_type>(begin()); }

    iterator_type lower_bound(int_type key)
    {
        size_t size_idx = 0, type_idx = 0, i = 0;
        node *p = root;
        int_type s = 0;
        bool go_back = false;
        for(; i < depth; ++i)
        {
            if(bit(key, i))
            {
                if(valid(p->lft))
                {
                    size_idx += p->lft->cnt;
                    type_idx += p->lft->typ;
                }
                if(valid(p->rgt))
                {
                    p = p->rgt;
                    s += power[i];
                }
                else
                {
                    go_back = true;
                    break;
                }
            }
            else
            {
                if(valid(p->lft))
                {
                    p = p->lft;
                }
                else
                {
                    if(valid(p->rgt))
                    {
                        s += power[i];
                        p = p->rgt;
                        break;
                    }
                    else
                    {
                        go_back = true;
                        break;
                    }
                }
            }
        }
        if(go_back)
        {
            while(i--)
            {
                bool t = p->tag;
                p = p->par;
                if(t)
                {
                    s -= power[i];
                }
                else if(valid(p->rgt))
                {
                    s += power[i];
                    p = p->rgt;
                    break;
                }
            }
            if(p->digit == depth) return end();
        }
        while(++i < depth)
        {
            if(valid(p->lft))
            {
                p = p->lft;
            }
            else
            {
                p = p->rgt;
                s += power[i];
            }
        }
        return iterator_type(this, p, s, type_idx, size_idx);
    }

    iterator_type upper_bound(int_type key)
    {
        auto itr = lower_bound(key);
        if(*itr == key) ++itr;
        return itr;
    }
}; 



struct workspace::solver { 



solver()
{
    const int n=read(),m=read(),k=read();
    const string s=read(),t=read();

    vector<p32> swp(n);
    for(auto& [a,b]:swp)
    {
        cin>>a>>b;
        a--,b--;
    }

    vector<int> info(n);
    vector<int> rp;
    vector<int> lp;

    {
        vector<int> p(k);
        iota(begin(p), end(p), 0);
        for(auto i=begin(swp);;++i)
        {
            auto ns=s;
            for(int i=0;i<k;i++)
            {
                ns[p[i]]=s[i];
            }
            lp.emplace_back(stoi(ns,0,2));
            auto nt=t;
            for(int i=0;i<k;i++)
            {
                nt[p[i]]=t[i];
            }
            rp.emplace_back(stoi(nt,0,2));
            if(i==end(swp)) break;
            auto [a,b]=*i;
            swap(p[a],p[b]);
        }
    }

    vector<int> l(1<<k,n),r(1<<k,-1);
    for(int i=0;i<=n;i++)
    {
        r[rp[i]]=i;
    }
    for(int i=n;i>=0;i--)
    {
        l[lp[i]]=i;
    }

    for(int i=0;i<k;i++)
    {
        for(int s=0;s<1<<k;s++)
        {
            if(s>>i&1)
            {
                chle(l[s^1<<i],l[s]);
                chge(r[s^1<<i],r[s]);
            }
        }
    }
    int ans=-1,tl=-1,tr=-1;
    for(int s=0;s<1<<k;s++)
    {
        if(l[s]+m>r[s]) continue;
        if(chge(ans,__builtin_popcount(s)))
        {
            tl=l[s],tr=r[s];
        }
    }
    int cnst=0;
    for(char c:s) cnst+=c=='0';
    for(char c:t) cnst-=c=='1';
    cout<<ans*2+cnst<<"\n"<<tl+1<<" "<<tr<<"\n";
}};
