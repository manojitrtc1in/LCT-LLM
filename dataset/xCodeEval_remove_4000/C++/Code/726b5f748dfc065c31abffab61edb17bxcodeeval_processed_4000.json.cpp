



    


    
    


    





    

    




























namespace std
{
    

    template <class T> size_t id2(size_t seed, T const &key) { return seed ^ (hash<T>()(key) + 0x9e3779b9 + (seed << 6) + (seed >> 2)); }
    template <class T, class U> struct hash<pair<T, U>> { size_t operator()(pair<T, U> const &pr) const { return id2(id2(0, pr.first), pr.second); } };
    template <class tuple_t, size_t index = tuple_size<tuple_t>::value - 1> struct tuple_hash_calc { static size_t apply(size_t seed, tuple_t const &t) { return id2(tuple_hash_calc<tuple_t, index - 1>::apply(seed, t), get<index>(t)); } };
    template <class tuple_t> struct tuple_hash_calc<tuple_t, 0> { static size_t apply(size_t seed, tuple_t const &t) { return id2(seed, get<0>(t)); } };
    template <class... T> struct hash<tuple<T...>> { size_t operator()(tuple<T...> const &t) const { return tuple_hash_calc<tuple<T...>>::apply(0, t); } };
    

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


namespace setting
{
    using namespace std;
    using namespace chrono;
    system_clock::time_point start_time, end_time;
    long long id4() { end_time = system_clock::now(); return duration_cast<milliseconds>(end_time - start_time).count(); }
    void id3() { cerr << "\n----- Exec time : " << id4() << " ms -----\n\n"; }
    void buffer_check() { char bufc; if(cin >> bufc) cerr << "\n\033[1;35mwarning\033[0m: buffer not empty.\n"; }
    struct setupper
    {
        setupper()
        {
            if(iostream_untie) ios::sync_with_stdio(false), cin.tie(nullptr);
            cout << fixed << setprecision(__precision__);
    
            if(freopen(stderr_path, "a", stderr)) cerr << fixed << setprecision(__precision__);
    
    
            cerr << boolalpha << "\n----- stderr at LOCAL -----\n\n";
    
    
            atexit(buffer_check);
    
    
            start_time = system_clock::now();
            atexit(id3);
    
        }
    } id5; 

} 



    

    
    
    



    

    



template <class T, class... types> T read(types... args) noexcept { typename std::remove_const<T>::type obj(args...); std::cin >> obj; return obj; }



template <class T> inline bool chmin(T &x, const T &y) { return x > y ? x = y, true : false; }


template <class T> inline bool chmax(T &x, const T &y) { return x < y ? x = y, true : false; }


template <class iter_type, class pred_type>
iter_type binary(iter_type __ok, iter_type __ng, pred_type pred)
{
    std::ptrdiff_t dist(__ng - __ok);
    while(std::abs(dist) > 1)
    {
        iter_type mid(__ok + dist / 2);
        if(pred(mid)) __ok = mid, dist -= dist / 2;
        else __ng = mid, dist /= 2;
    }
    return __ok;
}


template <class pred_type>
long double binary(long double __ok, long double __ng, const long double eps, pred_type pred)
{
    while(std::abs(__ok - __ng) > eps)
    {
        long double mid{(__ok + __ng) / 2};
        (pred(mid) ? __ok : __ng) = mid;
    }
    return __ok;
}


template <class A, size_t N> size_t size(A (&array)[N]) { return N; }


template <class T, class A, size_t N> void init(A (&array)[N], const T &val) { std::fill((T*)array, (T*)(array + N), val); }



using namespace std;
using i32 = int_least32_t; using i64 = int_least64_t; using u32 = uint_least32_t; using u64 = uint_least64_t;
using p32 = pair<i32, i32>; using p64 = pair<i64, i64>;
template <class T, class Comp = less<T>> using heap = priority_queue<T, vector<T>, Comp>;
template <class T> using hashset = unordered_set<T>;
template <class Key, class Value> using hashmap = unordered_map<Key, Value>;







template <class monoid>
class segment_tree
{
    using size_type = typename std::vector<monoid>::size_type;

    class unique_queue
    {
        size_type *que, *begin, *end;
        bool *in;

    public:
        unique_queue() : que(), begin(), end(), in() {}
        unique_queue(size_type n) : que(new size_type[n]), begin(que), end(que), in(new bool[n]{}) {}
        ~unique_queue() { delete[] que; delete[] in; }

        void clear() { begin = end = que; }
        bool empty() const { return begin == end; }
        bool push(size_type index)
        {
            if(in[index]) return false;
            return in[*end++ = index] = true;
        }
        size_type pop() { return in[*begin] = false, *begin++; }
    }; 


    size_type size_orig, height, size_ext;
    std::vector<monoid> data;
    unique_queue que;

    void recalc(const size_type node) { data[node] = data[node << 1] + data[node << 1 | 1]; }

    void rebuild()
    {
        while(!que.empty())
        {
            const size_type index = que.pop() >> 1;
            if(index && que.push(index)) recalc(index);
        }
        que.clear();
    }

    template <class pred_type>
    size_type id0(size_type index, const pred_type pred, monoid mono) const
    {
        assert(index);
        while(index < size_ext)
        {
            const monoid tmp = data[(index <<= 1) | 1] + mono;
            if(pred(tmp)) mono = tmp;
            else ++index;
        }
        return ++index -= size_ext;
    }

    template <class pred_type>
    size_type id1(size_type index, const pred_type pred, monoid mono) const
    {
        assert(index);
        while(index < size_ext)
        {
            const monoid tmp = mono + data[index <<= 1];
            if(pred(tmp)) ++index, mono = tmp;
        }
        return (index -= size_ext) < size_orig ? index : size_orig;
    }

public:
    segment_tree(const size_type n = 0) : size_orig{n}, height(n > 1 ? 32 - __builtin_clz(n - 1) : 0), size_ext{1u << height}, data(size_ext << 1), que(size_ext << 1) {}

    segment_tree(const size_type n, const monoid &init) : segment_tree(n)
    {
        std::fill(std::next(std::begin(data), size_ext), std::end(data), init);
        for(size_type i{size_ext}; --i; ) recalc(i);
    }

    template <class iter_type, class value_type = typename std::iterator_traits<iter_type>::value_type>
    segment_tree(iter_type first, iter_type last)
        : size_orig(std::distance(first, last)), height(size_orig > 1 ? 32 - __builtin_clz(size_orig - 1) : 0), size_ext{1u << height}, data(size_ext << 1), que(size_ext << 1)
    {
        static_assert(std::is_constructible<monoid, value_type>::value, "monoid(iter_type::value_type) is not constructible.");
        for(auto iter{std::next(std::begin(data), size_ext)}; iter != std::end(data) && first != last; ++iter, ++first) *iter = monoid{*first};
        for(size_type i{size_ext}; --i; ) recalc(i);
    }

    template <class container_type, typename = typename container_type::value_type>
    segment_tree(const container_type &cont) : segment_tree(std::begin(cont), std::end(cont)) {}

    size_type size() const { return size_orig; }
    size_type capacity() const { return size_ext; }

    

    typename decltype(data)::reference operator[](size_type index)
    {
        assert(index < size_orig);
        que.push(index |= size_ext);
        return data[index];
    }

    

    typename decltype(data)::const_reference operator[](size_type index) const
    {
        assert(index < size_orig);
        return data[index |= size_orig];
    }

    monoid fold(size_type first, size_type last)
    {
        assert(last <= size_orig);
        rebuild();
        monoid leftval{}, rightval{};
        first += size_ext, last += size_ext;
        while(first < last)
        {
            if(first & 1) leftval = leftval + data[first++];
            if(last & 1) rightval = data[--last] + rightval;
            first >>= 1, last >>= 1;
        }
        return leftval + rightval;
    }

    monoid fold() { return fold(0, size_orig); }

    template <class pred_type>
    size_type left_search(size_type right, const pred_type pred)
    {
        assert(right <= size_orig);
        rebuild();
        right += size_ext;
        monoid mono{};
        for(size_type left{size_ext}; left != right; left >>= 1, right >>= 1)
        {
            if((left & 1) != (right & 1))
            {
                const monoid tmp = data[--right] + mono;
                if(!pred(tmp)) return id0(right, pred, mono);
                mono = tmp;
            }
        }
        return 0;
    }

    template <class pred_type>
    size_type right_search(size_type left, const pred_type pred)
    {
        assert(left <= size_orig);
        rebuild();
        left += size_ext;
        monoid mono{};
        for(size_type right{size_ext << 1}; left != right; left >>= 1, right >>= 1)
        {
            if((left & 1) != (right & 1))
            {
                const monoid tmp = mono + data[left];
                if(!pred(tmp)) return id1(left, pred, mono);
                mono = tmp;
                ++left;
            }
        }
        return size_orig;
    }
}; 






template <class T> void _main();
struct solver;
int main() { _main<solver>(); }

template <class solver>
void _main()
{
    unsigned t;

    t = 1;

    t = 1; 


    

    


    while(t--) solver();
}

struct mono_type
{
    i64 val=-1e18;
    mono_type() {}
    mono_type(i64 v) : val(v) {}

    

    mono_type operator+(const mono_type& rhs) const { return mono_type{*this} += rhs; }

    

    mono_type &operator+=(const mono_type &rhs)
    {
        chmax(val,rhs.val);
        return *this;
    }
};

struct solver
{

    solver()
    {
        const i64 inf=1e18;
        int n,m; cin>>n>>m;

        vector dp(m+n+1, vector<i64>(1+n,-inf));
        for(auto &v:dp) v[0]=0;
        vector dp2(m+n+1,0LL);

        vector<int> l(n),s(n),c(n+m); cin>>l>>s>>c;
        c.insert(begin(c),0);
        reverse(__all(l));
        reverse(__all(s));


        segment_tree<mono_type> seg(n+m+1);
        




        for(int i=0;i<n;++i)
        {
            int agg=l[i];
            int cost=s[i];

            

            

            

            

            

            


            

            

            

            

            


            

            for(int i=n;i--;)
            {
                i64 now=dp[agg][i]+c[agg]-cost;
                

                for(int ii=i,k=agg;;ii>>=1)
                {
                    if(ii&1)
                    {
                        now+=c[++k];
                    }
                    else break;
                }
                int k=0;
                for(int ii=i+1;ii;k++,ii>>=1)
                {
                    

                    chmax(dp[k+agg][ii],now);
                    

                }

                seg[k+agg]+=now; 

            }

            for(int k=agg;k<=n+m;++k)
            {
                chmax(dp[k][0],seg.fold(0,k+1).val);
            }

            

            

            

        }

        

        i64 ans=-inf;
        for(auto &v:dp)
        {
            for(auto e:v)
            {
                chmax(ans,e);
            }
        }
        cout << ans << "\n";
    }
};
