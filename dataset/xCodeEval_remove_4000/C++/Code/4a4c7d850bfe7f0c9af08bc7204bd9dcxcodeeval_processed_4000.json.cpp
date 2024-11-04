




























using namespace std;



using uint = unsigned int;
constexpr int MOD = 998244353;

template<typename T>
class assignment_hook {
public:
    assignment_hook(T &value, function<void(const T &, const T &)> hook) : ref_(value), hook_(hook) {}

    assignment_hook &operator=(const T &rhs) {
        T prev = ref_;
        ref_ = rhs;
        hook_(prev, rhs);
        return *this;
    }

    operator T() const { return ref_; }

    template<typename _T=T>
    assignment_hook &operator+=(const _T &rhs) { return *this = (ref_ + rhs); }

    template<typename _T=T>
    assignment_hook &operator-=(const _T &rhs) { return *this = (ref_ - rhs); }

    template<typename _T=T>
    assignment_hook &operator/=(const _T &rhs) { return *this = (ref_ / rhs); }

    template<typename _T=T>
    assignment_hook &operator*=(const _T &rhs) { return *this = (ref_ * rhs); }

    template<typename _T=T>
    T operator++(int) {
        T prev = *this;
        *this = ref_ + 1;
        return prev;
    }

    template<typename _T=T>
    T operator--(int) {
        T prev = *this;
        *this = ref_ - 1;
        return prev;
    }

private:
    T &ref_;
    function<void(const T &, const T &)> hook_; 

};






using ll = long long int;
using ull = unsigned long long int;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vvvi = std::vector<vvi>;
using vvvvi = std::vector<vvvi>;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using pi = std::pair<int, int>;
using vpi = std::vector<pi>;
using vvpi = std::vector<vpi>;
using pll = std::pair<ll, ll>;
using vpll = std::vector<pll>;
using vvpll = std::vector<vpll>;
template<typename T> void mk_unique(std::vector<T>& l) { if (!std::is_sorted(all(l))) std::sort(all(l)); auto it = std::unique(l.begin(), l.end()); auto d = std::distance(l.begin(), it); l.resize(d); }
template<typename T> T &smax(T& l, const T&r) { if(l<r) l=r; return l; }
template<typename T> T &smin(T& l, const T&r) { if(r < l) l=r; return l; }
template<typename T>bool array_equal(const std::vector<T> &a, const std::vector<T> &b){
if(a.size() != b.size())return false;
return std::equal(all(a), b.begin());
}
template<typename T>bool array_equal(const std::vector<std::vector<T>> &a, const std::vector<std::vector<T>> &b){
if(a.size() != b.size())return false;
for(int i = 0 ; i < a.size(); i++) if(!array_equal(a[i], b[i])) return false;
return true;
}
template<class Fun>
class id32 {Fun fun_;public:
    template<class T>explicit id32(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args>decltype(auto) operator()(Args &&...args) {return fun_(std::ref(*this), std::forward<Args>(args)...);}
};
template<class Fun>decltype(auto) id14(Fun &&fun) {return id32<std::decay_t<Fun>>(std::forward<Fun>(fun));}

const double PI = 3.14159265358979323846264338327950288419716939937510;
namespace math{
template<int MOD>
class mod_int{
using mi=mod_int<MOD>;
int v=0;
public:


mod_int(ll v_){if(v_<0)v_=v_%MOD+MOD;if(v_>=MOD)v_%=MOD;v=int(v_);}
mod_int(ull v_){if(v_>=MOD)v_%=MOD;v=int(v_);}
mod_int(int v_): mod_int(ll(v_)){}
mod_int(unsigned v_): mod_int(ull(v_)){}
mod_int()=default;
mod_int(const mi& o)=default;
mod_int(mi&& o)=default;


inline mi& operator=(const mi& o)=default;
inline mi& operator=(mi&& o)=default;


explicit operator int()const{return v;}
explicit operator unsigned()const{return v;}
explicit operator ll()const{return v;}
explicit operator ull()const{return v;}


inline mi& operator++(){v=v==(MOD-1)?0:v+1;return*this;}
inline mi& operator--(){v=v==0?MOD-1:v-1;return*this;}
inline mi operator++(int){mi t=*this;++(*this);return t;}
inline mi operator--(int){mi t=*this;--(*this);return t;}
inline mi operator-()const{mi t;t.v=MOD-v;return t;}


inline bool friend operator==(const mi&lhs,const mi&rhs){return lhs.v==rhs.v;}
inline bool friend operator!=(const mi&lhs,const mi&rhs){return lhs.v!=rhs.v;}
template<typename T>inline bool friend operator==(const mi&lhs,const T&rhs){return lhs==mi(rhs);}
template<typename T>inline bool friend operator!=(const mi&lhs,const T&rhs){return lhs!=mi(rhs);}


template<typename T>inline mi friend operator+(const mi&lhs,const T&rhs){return mi(lhs)+=rhs;}
template<typename T>inline mi friend operator-(const mi&lhs,const T&rhs){return mi(lhs)-=rhs;}
template<typename T>inline mi friend operator*(const mi&lhs,const T&rhs){return mi(lhs)*=rhs;}
template<typename T>inline mi friend operator/(const mi&lhs,const T&rhs){return mi(lhs)/=rhs;}


inline mi& operator+=(const mi&rhs){v+=rhs.v;if(v>=MOD)v-=MOD;return*this;}
inline mi& operator-=(const mi&rhs){v-=rhs.v;if(v<0)v+=MOD;return*this;}
inline mi& operator*=(const mi&rhs){v=(ll(v)*rhs.v)%MOD;return*this;}
inline mi& operator/=(const mi&rhs){return*this*=rhs.inv();}


inline mi pow(ll pw)const{
if(pw<0)return inv().pow(-pw);
mi res=1,val=*this;while(pw){if(pw&1)res*=val;val*=val;pw>>=1;}return res;}


inline friend istream& operator>>(istream& in,const mi&rhs){ll v;in>>v;rhs={v};return in;}
inline friend ostream& operator<<(ostream& out,const mi&rhs){out<<rhs.v;return out;}







mi inv()const{
static const int SAVE_INV=min(int(1e6+5),MOD);
static mi save_inv[SAVE_INV];
if(save_inv[1]==0){


save_inv[0]=0,save_inv[1]=1;
for(int i=2;i<SAVE_INV;i++)save_inv[i]=save_inv[MOD%i]*(MOD-MOD/i);
}

if(v<SAVE_INV)return save_inv[v];
mi product=1;int val=v;
while(val>=SAVE_INV){product*=MOD-MOD/val;val=MOD%val;}
return product*save_inv[val];
}



static mi factorial(int n){
static vector<mi>mem;static mi last;if(mem.empty())mem.push_back(last=1);
while(n>=int(mem.size())){mem.push_back(mem.back()*last++);}return mem[n];
}
static mi n_choose_k(int n,int k){assert(n>=0 && k>=0 && k<=n);return factorial(n)/(factorial(k)*factorial(n-k));}
};
using mi=mod_int<MOD>;
}
inline ll pow_mod(ll a, ll b, const ll mod) {
    ll res = 1;
    for (; b; b /= 2, a = (a * a) % mod)
        if (b & 1)
            res = (res * a) % mod;
    return res;
}

inline ll mod_inv(const ll a, const ll mod) { return pow_mod(a, mod - 2, mod); }

template<typename T>
inline T gcd(T a, T b) {
    T t;
    while (a != 0)t = a, a = b % a, b = t;
    return b;
}

template<typename T>
ll lcm(const T a, const T b) {
    assert(a != 0 && b != 0);
    return a / gcd(a, b) * ll(b);
}

namespace {const size_t RFC = chrono::high_resolution_clock::now().time_since_epoch().count();}

template<typename T>
class chash {
    hash<T> h;
public:
    size_t operator()(const T &x) const { return h(x) ^ RFC; }
};



using namespace __gnu_pbds;

template<typename _Key, typename _Tp, typename _Hash=chash<_Key>>
class hash_map : public gp_hash_table<_Key, _Tp, _Hash> {
    using gp_hash_table<_Key, _Tp, _Hash>::gp_hash_table;
};

using mi = math::mi;
using vmi = vector<mi>;
using vvmi = vector<std::vector<mi>>;
namespace io{class input_reader{
void throw_error(){throw std::runtime_error("No more inputs while reading number");}
template<typename T>inline void id21(T&f){
bool positive=true;f=0;char c;
if(!in.get(c))throw_error();
while(c<'0'||c>'9'){if(c=='-')positive=false;if(!in.get(c))throw_error();}
while(c>='0'&&c<='9'){f=(f<<3)+(f<<1)+(c&15);if(!in.get(c))break;}
if(!positive)f*=-1;}
public:
std::istream&in;
explicit input_reader(std::istream&in):in(in){}
inline void read(int&f){id21(f);}
inline void read(short&f){id21(f);}
inline void read(long int&f){id21(f);}
inline void read(long long int&f){id21(f);}
inline void read(unsigned int&f){id21(f);}
inline void read(unsigned short&f){id21(f);}
inline void read(unsigned long int&f){id21(f);}
inline void read(unsigned long long int&f){id21(f);}
template<typename T>inline void read(T&f){in>>f;}
template<typename T,size_t N>inline void read(std::array<T,N>&res){for(auto&i:res)read(i);}
template<typename T>inline void read(std::vector<T>&f){for(auto&i:f)read(i);}
template<typename T1,typename T2>inline void read(std::pair<T1,T2>&p){read(p.first,p.second);}
template<typename T,typename...Args>inline void read(T&t,Args&...args){read(t),read(args...);}
template<typename T>inline void readArray(int n,T*res){while(n--)read(*(res++));}
template<typename T>inline input_reader&operator>>(T&t){return read(t),*this;}
};}
namespace io{class output_writer{
std::ostream&out;
template<typename T>inline void id28(T x){if(x>=10)id28(x/10);out.put(x%10+48);}
template<typename T>inline void printInteger(T x){if(x<0)out.put('-'),x=-x;id28(x);}
template<typename T>inline void printArray(T&ar,char sep=' '){int c=0;for(auto&t:ar){if(c++){print(sep);}print(t);}}
public:
explicit output_writer(std::ostream&out):out(out){}
inline void flush(){out.flush();}
inline void print(){}
inline void print(char x){out.put(x);}
inline void print(short x){printInteger(x);}
inline void print(int x){printInteger(x);}
inline void print(long int x){printInteger(x);}
inline void print(long long int x){printInteger(x);}
inline void print(unsigned short x){printInteger(x);}
inline void print(unsigned int x){printInteger(x);}
inline void print(unsigned long int x){printInteger(x);}
inline void print(unsigned long long int x){printInteger(x);}
template<typename T1>inline void print(const T1&t1){out<<t1;}
template<typename T1,typename T2>inline void print(const std::pair<T1,T2>&t1){print(t1.first,' ',t1.second);}
template<typename T1>inline void print(const std::vector<T1>&t1){printArray(t1);}
template<typename T1,std::size_t N>inline void print(const std::array<T1,N>&t1){printArray(t1);}
template<typename T1,std::size_t N,std::size_t M>inline void print(const std::array<std::array<T1,M>,N>&t1){printArray(t1,'\n');}
template<typename T1>inline void print(const std::vector<std::vector<T1>>&t1){printArray(t1,'\n');}
template<typename T,typename...Args>inline void print(const T&t,const Args&...args){print(t),print(args...);}
template<typename...Args>inline void println(const Args&...args){print(args...),print('\n');}
template<typename T>output_writer&operator<<(const T&t){return print(t),*this;}
};}
std::mt19937 id39() { return std::mt19937(std::random_device()()); }

template<typename T=int>
T myrand(T id17 = std::numeric_limits<T>::max()) {
    assert(id17 > 0);
    static std::mt19937 random_engine = id39();
    return std::uniform_int_distribution<T>(0, id17 - 1)(random_engine);
}


template<typename T=int>
T randrange(T low, T high) {
    assert(low < high);
    static std::mt19937 random_engine = id39();
    return std::uniform_int_distribution<T>(low, high)(random_engine);
}

bool randbool() { return myrand(2); }








namespace {
    vi id19(vi a) {
        shuffle(all(a), id39());
        return a;
    }
}
const vi MODS = id19({
                                    1000000007, 1000000009, 1000000021, 1000000033, 1000000087, 1000000093, 1000000097,
                                    1000000103,
                                    1000000123, 1000000181, 1000000207, 1000000223, 1000000241, 1000000271, 1000000289,
                                    1000000297,
                                    1000000321, 1000000349, 1000000363, 1000000403, 1000000409, 1000000411, 1000000427,
                                    1000000433,
                                    1000000439, 1000000447, 1000000453, 1000000459, 1000000483, 1000000513, 1000000531,
                                    1000000579,
                                    1000000607, 1000000613, 1000000637, 1000000663, 1000000711, 1000000753, 1000000787,
                                    1000000801,
                                    1000000829, 1000000861, 1000000871, 1000000891, 1000000901, 1000000919, 1000000931,
                                    1000000933,
                                    1000000993, 1000001011, 1000001021, 1000001053, 1000001087, 1000001099, 1000001137,
                                    1000001161,
                                    1000001203, 1000001213, 1000001237, 1000001263, 1000001269, 1000001273, 1000001279,
                                    1000001311,
                                    1000001329, 1000001333, 1000001351, 1000001371, 1000001393, 1000001413, 1000001447,
                                    1000001449,
                                    1000001491, 1000001501, 1000001531, 1000001537, 1000001539, 1000001581, 1000001617,
                                    1000001621,
                                    1000001633, 1000001647, 1000001663, 1000001677, 1000001699, 1000001759, 1000001773,
                                    1000001789,
                                    1000001791, 1000001801, 1000001803, 1000001819, 1000001857, 1000001887, 1000001917,
                                    1000001927,
                                    1000001957, 1000001963, 1000001969, 1000002043, 1000002089, 1000002103, 1000002139,
                                    1000002149,
                                    1000002161, 1000002173, 1000002187, 1000002193, 1000002233, 1000002239, 1000002277,
                                    1000002307,
                                    1000002359, 1000002361, 1000002431, 1000002449, 1000002457, 1000002499, 1000002571,
                                    1000002581,
                                    1000002607, 1000002631, 1000002637, 1000002649, 1000002667, 1000002727, 1000002791,
                                    1000002803,
                                    1000002821, 1000002823, 1000002827, 1000002907, 1000002937, 1000002989, 1000003009,
                                    1000003013,
                                    1000003051, 1000003057, 1000003097, 1000003111, 1000003133, 1000003153, 1000003157,
                                    1000003163,
                                    1000003211, 1000003241, 1000003247, 1000003253, 1000003267, 1000003271, 1000003273,
                                    1000003283,
                                    1000003309, 1000003337, 1000003351, 1000003357, 1000003373, 1000003379, 1000003397,
                                    1000003469,
                                    1000003471, 1000003513, 1000003519, 1000003559, 1000003577, 1000003579, 1000003601,
                                    1000003621,
                                    1000003643, 1000003651, 1000003663, 1000003679, 1000003709, 1000003747, 1000003751,
                                    1000003769,
                                    1000003777, 1000003787, 1000003793, 1000003843, 1000003853, 1000003871, 1000003889,
                                    1000003891,
                                    1000003909, 1000003919, 1000003931, 1000003951, 1000003957, 1000003967, 1000003987,
                                    1000003999,
                                    1000004023, 1000004059, 1000004099, 1000004119, 1000004123, 1000004207, 1000004233,
                                    1000004249
                            });

namespace std {
    template<typename T, typename HASH=chash<T>, size_t HASH_COUNT = 3>
    struct hashable_list {
        size_t to_hash() const {
            size_t res = 0;
            fori(i, HASH_COUNT) res ^= _hashes[i];
            return res;
        }

        friend bool
        operator==(const hashable_list<T, HASH, HASH_COUNT> &lhs, const hashable_list<T, HASH, HASH_COUNT> &rhs) {
            return lhs._hashes == rhs._hashes;
        }

    protected:
        void _update_hashes(int index, const T &from, const T &to) {
            fori(hash_i, HASH_COUNT) {
                ll hf = _hash_op(from), ht = _hash_op(to), cur = _hashes[hash_i],
                        coef = pow_mod(MODS[HASH_COUNT], index, MODS[hash_i]);
                cur = (cur + (ht - hf) * coef) % MODS[hash_i];
                if (cur < 0) cur += MODS[hash_i];
                _hashes[hash_i] = cur;
            }
        }

    private:
        array<size_t, HASH_COUNT> _hashes{};
        HASH _hash_op{};
    };

    template<typename T, typename H, size_t HC>
    struct hash<hashable_list<T, H, HC>> : public unary_function<const hashable_list<T, H, HC> &, size_t> {
        size_t operator()(const hashable_list<T, H, HC> &cur) const noexcept { return cur.to_hash(); }
    };

        template<typename T, size_t N, typename HASH=hash<T>, size_t HASH_COUNT = 3>
    struct id36 : public hashable_list<T, HASH, HASH_COUNT> {
        id36() = default;

        id36(const id36 &) = default;

        id36(id36 &&) = default;

        id36 &operator=(const id36 &) = default;

        id36 &operator=(id36 &&) = default;

        size_t size() const { return arr.size(); }

        T operator[](int i) const { return arr[i]; }

        assignment_hook<T> operator[](int i) {
            return assignment_hook(arr[i], [&, i](auto prev, auto cur) {
                this->_update_hashes(i, prev, cur);
            });
        }

    private:
        array<T, N> arr{};
    };

    template<typename T, typename HASH=hash<T>, size_t HASH_COUNT = 3>
    struct id34 : public hashable_list<T, HASH, HASH_COUNT> {
        id34() = default;

        id34(size_t n, T _val = T()) : arr(n, _val) {}

        id34(const id34 &) = default;

        id34(id34 &&) = default;

        id34 &operator=(const id34 &) = default;

        id34 &operator=(id34 &&) = default;

        size_t size() const { return arr.size(); }

        void push_back(const T &val) const { return arr.push_back(val); }

        assignment_hook<T> back() { return (*this)[size() - 1]; }

        void pop_back() const { return arr.pop_back(); }

        T operator[](int i) const { return arr[i]; }

        assignment_hook<T> operator[](const int i) {
            return assignment_hook<T>(arr[i], [&, i](auto prev, auto cur) {
                this->_update_hashes(i, prev, cur);
            });
        }

    private:
        vector<T> arr;
    };
}








namespace hashes {
    class hashed_string {
    public:
        const int length;
    private:
        static constexpr int by = 256;
        std::vector<std::shared_ptr<std::vector<long long>>> id37;
        const int shift;

        static long long pow_mod(long long a, long long b, long long MOD) {
            if (b == 0)return 1;
            if (b == 1)return a;
            long long side = 1;
            while (b != 1) {
                if (1 & b)side = side * a % MOD;
                a = a * a % MOD;
                b >>= 1;
            }
            return a * side % MOD;
        }

        long long get_hash(int i) const {
            long long res = (*id37[i])[shift + length];
            if (shift != 0) {
                long long id30 = (*id37[i])[shift] * pow_mod(by, length, MODS[i]) % MODS[i];
                res -= id30;
                if (res < 0)res += MODS[i];
            }
            return res;
        }

        hashed_string(std::vector<std::shared_ptr<std::vector<long long int>>> id37, int pos, int n) :
                length(n), id37(id37), shift(pos) {}

        static inline int min(int a, int b) { return a < b ? a : b; }

    public:
        hashed_string(std::string &s, int id24 = 2) : length(s.size()), shift(0) {
            id37.reserve(id24);
            for (int i = 0; i < id24; ++i) {
                id37.push_back(std::make_shared<std::vector<long long>>(length + 1));
                auto &hs = *(id37[i]);
                for (int j = 0; j < length; j++)hs[j + 1] = (hs[j] * by + s[j]) % MODS[i];
            }
        }

        hashed_string substr(int pos, int n = -1) const {
            if (n == -1) { n = length - pos; }
            return hashed_string(id37, pos + shift, n);
        }

        bool operator==(const hashed_string &lhs) const {
            if (length != lhs.length)return false;
            int id3 = min(id37.size(), lhs.id37.size());
            for (int i = 0; i < id3; ++i)if (get_hash(i) != lhs.get_hash(i))return false;
            return true;
        }

        bool operator!=(const hashed_string &lhs) const { return !(*this == lhs); }
    };
}





namespace {
    template<typename trie_node, typename TRANSITION>
    int id22(vector<trie_node> &trie, int cur, TRANSITION t) {
        auto &x = trie[cur]._trans[t];
        int res = x;
        if (x == 0) {
            res = x = int(trie.size());
            trie.emplace_back();
        }
        return res;
    }

    template<typename trie_node, typename It>
    

    vector<trie_node> id7(It first, It last) {
        vector<trie_node> trie;
        trie.emplace_back(); 

        for (; first != last; first++) {
            int cur = 0;
            for (auto t : *first)
                cur = id22(trie, cur, t);
            trie[cur].leaf++;
        }
        return trie;
    }

    template<typename trie_node, typename It>
    

    vector<trie_node> id31(It first, It last, bool id33 = false) {
        typedef typename It::value_type::const_iterator TIt;
        struct pointer_for_aho {
            TIt it;
            TIt eit;
            int cur_node;
            int longest_suffix_parent_node;
        };

        vector<trie_node> trie;
        trie.emplace_back(); 

        deque<pointer_for_aho> q;
        for (; first != last; ++first)
            q.push_back(
                    pointer_for_aho{.it=first->begin(), .eit=first->end(), .cur_node=0, .longest_suffix_parent_node=-1});

        vector<pi> id12;
        

        while (!q.empty()) {
            auto p = q.front();
            q.pop_front();

            if (p.longest_suffix_parent_node != -1)
                p.longest_suffix_parent_node = trie[p.longest_suffix_parent_node][*p.it];
            else p.longest_suffix_parent_node = 0;
            p.cur_node = id22(trie, p.cur_node, *p.it);

            id12.emplace_back(p.cur_node, p.longest_suffix_parent_node);
            ++p.it;
            if (p.it != p.eit) q.push_back(p);
            else
                trie[p.cur_node].leaf++;
        }

        for (auto p: id12) {
            trie[p.first].add_missing_transitions_from(trie[p.second]);

            if (id33) trie[p.first].leaf += trie[p.second].leaf;
        }

        return trie;
    }
}
namespace trie_unknown_range {
    template<typename TRANSITIONS_=char>
    struct trie_node {
        typedef TRANSITIONS_ TRANSITIONS;
        hash_map<TRANSITIONS, int> _trans;
        int leaf;

        int operator[](TRANSITIONS i) const {
            auto f = _trans.find(i);
            if (f == _trans.find_end()) return 0;
            return f->second;
        }

        void add_missing_transitions_from(const trie_node<TRANSITIONS> &other) {
            for (auto p : other._trans) {
                auto &x = _trans[p.first];
                if (x == 0) x = p.second;
            }
        }
    };

    template<typename TRANSITIONS=char, typename It>
    

    vector<trie_node<TRANSITIONS>> id35(It first, It last) {
        return id7<trie_node<TRANSITIONS>, It>(first, last);
    }

    template<typename TRANSITIONS=char, typename It>
    

    vector<trie_node<TRANSITIONS>> id6(It first, It last) {
        return id31<trie_node<TRANSITIONS>, It>(first, last);
    }
}

namespace trie_known_range {
    template<int range_start = 'a', int id25 = 'z'>
    struct trie_node {
        struct arr {
            int mem[id25 - range_start + 1];

            int &operator[](int i) {
                return mem[i - range_start];
            }

            int operator[](int i) const { return mem[i - range_start]; }
        };

        arr _trans;
        int leaf;

        int operator[](int i) const { return _trans[i]; }

        void add_missing_transitions_from(const trie_node<range_start, id25> &other) {
            for (int i = range_start; i <= id25; i++) {
                int &x = _trans[i];
                if (x == 0) {
                    x = other._trans[i];
                }
            }
        }
    };

    template<int range_start = 'a', int id25 = 'z', typename It>
    

    vector<trie_node<range_start, id25>> id35(It first, It last) {
        return id7<trie_node<range_start, id25>, It>(first, last);
    }

    template<int range_start = 'a', int id25 = 'z', typename It>
    

    vector<trie_node<range_start, id25>> id6(It first, It last) {
        return id31<trie_node<range_start, id25>, It>(first, last);
    }
}






namespace range_update {

    
    template<typename T>
    class ranges_array {
        const int n;
        const binary_function<T, T, T> _op;
        mutable std::vector<optional<T>> vec;

        void op(const optional<T> lhs, const T rhs) { return lhs ? _op(lhs, rhs) : rhs; }

        void update_index_down(int i) const {
            if (!vec[i]) return;
            vec[i * 2] = op(vec[i * 2], vec[i]);
            vec[i * 2 + 1] = op(vec[i * 2], vec[i]);
            vec[i] = nullopt;
        }

        static size_t close_power_of_2(int n) {
            int i = 1;
            while (i < n)i *= 2;
            return i;
        }

    public:

        ranges_array(int n, binary_function<T, T, T> op, optional<T> default_value = nullopt)
                : n(close_power_of_2(n)), _op(op), vec(2 * this->n) {
            assert(n > 0);
            if (default_value)
                for (int i = 0, j = n; i < n; i++, j++)
                    vec[j] = default_value;
        }

        ranges_array(const std::vector<T> &v, binary_function<T, T, T> op) : ranges_array(int(v.size()), op) {
            for (int i = 0, j = n; i < int(v.size()); i++, j++)
                vec[j] = v[i];
        }

        void update_range(int l, int r, const T val) {
            assert(l <= r);
            id14([&](auto self, int i, int cur_l, int cur_r) {
                if (cur_r < l || r < cur_l) return;
                if (l <= cur_l && cur_r <= r) vec[i] = op(vec[i], val);
                else {
                    int cur_m = (cur_l + cur_r) / 2;
                    update_index_down(i);
                    self(i * 2, cur_l, cur_m), self(i * 2 + 1, cur_m + 1, cur_r);
                }
            })(1, 0, n - 1);
        }

        T operator[](const int index) const {
            int i = 1, l = 0, r = n - 1;
            while (l < r) {
                update_index_down(i);
                int m = (l + r) / 2;
                if (index <= m) r = m, i *= 2;
                else l = m + 1, i = i * 2 + 1;
            }
            return vec[i];
        }
    };

    template<typename T>
    class id4 : public ranges_array<T> {
    public:
        explicit id4(const std::vector<T> &v)
                : ranges_array<T>(v, [](T u, T v) { return u + v; }) {}

        explicit id4(int n, optional<T> default_value = nullopt)
                : ranges_array<T>(n, [](T u, T v) { return u + v; }, default_value) {}
    };


    template<typename T>
    class id9 : public ranges_array<T> {
    public:
        explicit id9(const std::vector<T> &v)
                : ranges_array<T>(v, [](T u, T v) { return v; }) {}

        explicit id9(int n, optional<T> default_value = nullopt)
                : ranges_array<T>(n, [](T u, T v) { return v; }, default_value) {}
    };

    template<typename T>
    class id2 : public ranges_array<T> {
    public:
        explicit id2(const std::vector<T> &v)
                : ranges_array<T>(v, [](T u, T v) { return max(u, v); }) {}

        explicit id2(int n, optional<T> default_value = nullopt)
                : ranges_array<T>(n, [](T u, T v) { return max(u, v); }, default_value) {}
    };

    template<typename T>
    class id29 : public ranges_array<T> {
    public:
        explicit id29(const std::vector<T> &v)
                : ranges_array<T>(v, [](T u, T v) { return min(u, v); }) {}

        explicit id29(int n, optional<T> default_value = nullopt)
                : ranges_array<T>(n, [](T u, T v) { return min(u, v); }, default_value) {}
    };
}





namespace range_query {


	

	

	

	

	

	template<typename T, typename Operator, bool id11 = false>
	class id1 {
		const Operator op;
		std::vector<std::vector<T>> vec;

		static int largest_bit(int x) { return 31 - __builtin_clz(x); }

	public:
		id1(std::vector<T> v, Operator op) : op(op) {
			vec.push_back(v);
			const int n = v.size();
			int id10 = 1;
			while (id10 * 2 <= n) {
				for (int i = 0; i + id10 * 2 <= n; ++i) {
					v[i] = op(v[i], v[i + id10]);
				}
				id10 <<= 1;
				vec.emplace_back(v.begin(), v.begin() + (n - id10) + 1);
			}
		}

		explicit id1(const std::vector<T> &v) : id1(v, Operator()) {}

		T query(int l, int r) const {
			assert(l <= r);
			if (!id11) {
				int len = r - l + 1;
				int level = 0;
				while ((1 << (level + 1)) <= len) level++;
				int level_window = 1 << level;
				r = r - level_window + 1;
				return op(vec[level][l], vec[level][r]);
			} else {
				int dif = r - l + 1;
				int i = largest_bit(dif);
				T res = vec[i][l];
				l += 1 << i;
				dif -= 1 << i;
				i = largest_bit(dif);
				for (; dif; i = largest_bit(dif)) {
					res = op(res, vec[i][l]);
					l += 1 << i;
					dif -= 1 << i;
				}
				return res;
			}
		}
	};


	template<typename T, typename Comparator = std::less<T>>
	class id26 : public id1<T, std::function<T(T, T)>> {
	public:
		id26(const std::vector<T> &v, Comparator comp) :
				id1<T, std::function<T(T, T)>>(v, [=](const T &u, const T &v) {
					return comp(u, v) ? u : v;
				}) {}

		explicit id26(const std::vector<T> &v)
				: id26(v, Comparator()) {}
	};


	template<typename T, typename Comparator = std::less<T>>
	class id0 : public id1<T, std::function<T(T, T)>> {
	public:
		id0(const std::vector<T> &v, Comparator comp) :
				id1<T, std::function<T(T, T)>>(v, [=](const T &u, const T &v) {
					return comp(u, v) ? v : u;
				}) {}

		explicit id0(const std::vector<T> &v)
				: id0(v, Comparator()) {}
	};

	template<typename T>
	class id38 : public id1<T, std::function<T(T, T)>, true> {
	public:
		explicit id38(const std::vector<T> &v) :
				id1<T, std::function<T(T, T)>>(v, [](const T &u, const T &v) {
					return v + u;
				}) {}
	};
}




namespace range_query {

template<typename T, typename Operator = std::function<T(const T &, const T &)>>
class ranges_array {
const int n{};const Operator op;std::vector<T> vec;

void update_up_range(int l, int r) { int range=(vec.size()-1)<<1;
while (l>>=1,r>>=1,range>>=1,l) {for(int i=l;i<=r;++i){ vec[i]=vec[i*2]; if(i*2<range)vec[i]=op(vec[i],vec[i*2+1]);}}}

void update_up(int i) {int range=(vec.size()-1)<<1;
while (i>>=1,range>>=1,i) {T new_v=vec[i*2]; if(i*2<range)new_v=op(new_v,vec[i*2+1]);
if(vec[i]==new_v){return;}vec[i]=new_v;}}

public:
ranges_array(const std::vector<T> &v, Operator op) : n(v.size()), op(op), vec(v.size()*2+1) {
std::copy(v.begin(), v.end(), vec.begin() + n + 1); update_up_range(vec.size() - n, vec.size() - 1);}

explicit ranges_array(const std::vector<T> &v) : ranges_array(v, Operator()) {}
ranges_array(int n, Operator op) : n(n), op(op), vec(n*2+1) {}
explicit ranges_array(int n) : ranges_array(n, Operator()) {}

T query(int l, int r) const {


assert(0 <= l && l < n && 0 <= r && r < n && l <= r);
T res; bool first = true;l += n + 1, r += n + 1; if (l == r) return vec[l];
auto update_res = [&](const T &t1) {res = first ? t1 : op(res, t1);first = false;};
do{if ((l & 1) == 1) update_res(vec[l++]);if ((r & 1) == 0) update_res(vec[r--]);} while(l>>=1, r>>=1, l<r);
if (l == r) update_res(vec[l]);
return res;
}

T query() { return query(0, n - 1); }


class id18 {T t;ranges_array &rq;const int index;
public:
id18(ranges_array &rq, const int index):t(rq.vec[index]), rq(rq), index(index) {}
id18&operator=(const T&val){t=val;rq.vec[index]=val;rq.update_up(index);return *this;}
operator T() const { return t; }
};

id18 operator[](int index) { return id18(*this, n+1+index); }
};

template<typename T, typename Comparator>struct get_min : public std::binary_function<T, T, T> {Comparator cmp;
get_min() = default;
explicit get_min(Comparator cmp) : cmp(cmp) {}
T operator()(const T &__x, const T &__y) const { return cmp(__x, __y) ? __x : __y; }
};

template<typename T>struct get_sum : public std::binary_function<T, T, T> {
T operator()(const T &__x, const T &__y) const { return __x + __y; }
};

template<typename T, typename Comparator = std::less<T>>struct id27 : public ranges_array<T, get_min<T, Comparator>> {
using ranges_array_ = ranges_array<T, get_min<T, Comparator>>;
id27(const std::vector<T> &v, Comparator cmp) : ranges_array_(v, get_min<T, Comparator>(cmp)) {}
explicit id27(const std::vector<T> &v) : ranges_array_(v) {}
id27(int n, Comparator cmp) : ranges_array_(n, get_min<T, Comparator>(cmp)) {}
explicit id27(int n) : ranges_array_(n) {}
};

template<typename T>struct id16 : public ranges_array<T, get_sum<T>> {
using ranges_array_ = ranges_array<T, get_sum<T>>;
explicit id16(const std::vector<T> &v) : ranges_array_(v) {}
explicit id16(int n) : ranges_array_(n) {}
};
}




namespace range_query {

    template<typename K, typename T, typename Operator = std::function<T(const T &, const T &)>>
    class id8 {
        const Operator op;

        class Node {
            const K l, r;
            T val;
            Node *left, *right;
        public:
            Node(K l, K r) : l(l), r(r), val(), left(nullptr), right(nullptr) {}

            ~Node() {
                if (left) delete left;
                if (right)delete right;
            }

            void set(const K i, const T v, const Operator &op) {
                const K m = (l + r) / 2;
                if (l == r) val = v;
                else {
                    if (i <= m) {
                        if (left == nullptr) left = new Node(l, m);
                        left->set(i, v, op);
                    } else {
                        if (right == nullptr) right = new Node(m + 1, r);
                        right->set(i, v, op);
                    }
                    update(op);
                }
            }

            void update(const Operator &op) {
                if (left == nullptr) {
                    if (right != nullptr) {
                        val = right->val;
                    }
                } else {
                    if (right == nullptr) val = left->val;
                    else val = op(left->val, right->val);
                }
            }

            T get(K l1, K r1, const Operator &op) const {
                if (l1 < l) l1 = l;
                if (r1 > r) r1 = r;
                if (l1 == l && r1 == r) return val;
                const K m = (l + r) / 2;
                bool left_ok = l1 <= m && left != nullptr;
                bool right_ok = r1 > m && right != nullptr;
                if (left_ok && right_ok) return op(left->get(l1, r1, op), right->get(l1, r1, op));
                if (left_ok) return left->get(l1, r1, op);
                if (right_ok) return right->get(l1, r1, op);
                else return T();
            }
        };

        Node root;

    public:
        id8(K l, K r, Operator op) : root(l, r), op(op) {}

        explicit id8(K l, K r) : id8(l, r, Operator()) {}

        class id18 {
            id8<K, T, Operator> &rq;
            const K index;
        public:
            id18(id8<K, T, Operator> &rq, const K index) : rq(rq), index(index) {}

            id18 &operator=(const T &val) {
                rq.root.set(index, val, rq.op);
                return *this;
            }
        };

        id18 operator[](const K index) {
            return id18(*this, index);
        }

        const T &operator[](const K index) const {
            return root.get(index, index, op);
        }

        T query(K l, K r) const {
            assert(l <= r);
            return root.get(l, r, op);
        }

        T query() {
            return root.val;
        }
    };


    template<typename K, typename T, typename Comparator = std::less<T>>
    class id15 : public id8<K, T, std::function<T(T, T)>> {
    public:
        id15(K l, K r, Comparator comp) :
                id8<K, T, std::function<T(T, T)>>(l, r, [=](const T &u, const T &v) {
                    return comp(u, v) ? u : v;
                }) {}

        explicit id15(K l, K r)
                : id15(l, r, Comparator()) {}
    };

    template<typename K, typename T, typename Comparator = std::less<T>>
    class id23 : public id8<K, T, std::function<T(T, T)>> {
    public:
        id23(const K l, const K r, Comparator comp) :
                id8<K, T, std::function<T(T, T)>>(l, r, [=](const T &u, const T &v) {
                    return comp(u, v) ? v : u;
                }) {}

        explicit id23(const std::vector<T> &v)
                : id23(v, Comparator()) {}
    };

    template<typename K, typename T>
    class id5 : public id8<K, T, std::function<T(T, T)>> {
    public:
        explicit id5(const K l, const K r) :
                id8<K, T, std::function<T(T, T)>>(l, r, [](const T &u, const T &v) {
                    return v + u;
                }) {}
    };
}



namespace range_query {
using namespace std;

template<typename T>
class fenwick {
int n;std::vector<T> arr;std::vector<T> origin;T total;
public:
explicit fenwick(int n) : n(n), arr(n + 1), origin(n + 1), total(0) {}
explicit fenwick(const std::vector<T> &v) : fenwick(int(v.size())) { for (int i = 0; i < n; ++i) add(v[i], i); }
void add(T diff, int i) {i++;total+=diff;origin[i] += diff;for(;i<=n;i+=(i) & (-i)) arr[i] += diff;}



T query() const {return total;}

T query(int i) const
{i++;T ans=0; for(;i;i-=(i) & (-i)){ans+=arr[i];}return ans;}



T query(int l, int r) const {
    T res = query(r);
    if(l) {
        res -= query(l - 1);
    }
    return res;}

const T& get(int i) const {i++;return origin[i];}
void set(T val, int i) {add(val - get(i), i);}
size_t size() { return n; }

const T& operator[](size_t i) const{return get(i);}

class id20{
    fenwick& fen;
    const int index;
public:
    id20(fenwick& fen, int index): fen(fen), index(index){}
    id20& operator=(T new_val){fen.set(new_val, index); return *this; }
};
id20 operator[](int i){return {*this, i};}

int lower_bound(T val) {

if(total < val) return n;
int i = 1;
while (i * 2 <= n && arr[i * 2] < val) i <<= 1;
T sum = arr[i];

for (int ind = i >> 1; ind != 0; ind >>= 1) {
if (i + ind > n) continue;
if (sum + arr[i + ind] < val) {
i += ind;
sum += arr[i];
}
}
return i;
}
};
}









using namespace std;

class ETestsRenumeration {
    class Solver {
    public:
        io::input_reader in;
        io::output_writer out;

        Solver(std::istream &in, std::ostream &out) : in(in), out(out) {}

        set<int> free;
        vector<pair<string, string>> ans;

        int n;
        int cnt_e;
        vector<pair<string, int>> states, nonrel;

        static int to_int(const string &s) {
            if (s.front() == '0' && s.size() != 1) return -1;
            for (auto c: s) if (c < '0' || '9' < c) return -1;
            return stoi(s);
        }

        void filter_finished_and_nonrel_names() {
            vector<pair<string, int>> id13;
            for (auto &p : states) {
                int cur = to_int(p.first);
                if (0 < cur && cur <= n) {
                    if ((p.second == 1) == (cur <= cnt_e)) {
                        cerr << p.first << '\n';
                        

                    } else {
                        id13.push_back(p);
                    }
                    free.erase(cur);
                } else {
                    nonrel.push_back(p);
                }
            }
            swap(states, id13);
        }

        void add_move(const pair<string, int> &p, const int to) { add_move(p, to_string(to)); }

        void add_move(const pair<string, int> &p, const string &to) {
            ans.emplace_back(p.first, to);
            int prev = to_int(p.first);
            if (1 <= prev && prev <= n) free.insert(prev);
            int cur = to_int(to);
            if (cur == -1) {
                nonrel.emplace_back(to, p.second);
            } else {
                free.erase(cur);
            }
        }

        bool handle(const pair<string, int> &p) {
            auto it = free.begin();
            if (p.second) {
                if (cnt_e < *it) return false;
            } else {
                it = free.lower_bound(cnt_e + 1);
                if (it == free.end()) return false;
            }
            add_move(p, *it);
            return true;
        }

        void handle_all_states() {
            vector<vector<pair<string, int>>> s(2);
            for (const auto &p: states) s[p.second].push_back(p);
            states.clear();
            while (!s[0].empty() || !s[1].empty()) {
                fori(i, 2) if (!s[i].empty() && handle(s[i].back())) s[i].pop_back();
            }
        }

        void handle_all_nonrel() {
            for (auto &p: nonrel) {
                bool res = handle(p);
                assert(res);
            }
            nonrel.clear();
        }

        void solve() {
            

            in >> n;
            nonrel.clear(), states.resize(n);
            in >> states;

            ans.clear(), free.clear();
            fori(i, n) free.insert(i + 1);

            cnt_e = 0;
            fori(i, n) cnt_e += states[i].second;

            filter_finished_and_nonrel_names();

            if (nonrel.empty() && !states.empty()) {
                auto back = states.back();
                states.pop_back();
                add_move(back, "a");
            }

            handle_all_states();
            handle_all_nonrel();

            

            out.println(ans.size());
            for (auto &p:ans) {
                out.println("move ", p.first, " ", p.second);
            }
        }
    };

public:
    static void solve(std::istream &in, std::ostream &out) {
        Solver(in, out).solve();
    }
};

int main() {
	std::ios_base::sync_with_stdio(false), cin.tie(0);
	ETestsRenumeration solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
