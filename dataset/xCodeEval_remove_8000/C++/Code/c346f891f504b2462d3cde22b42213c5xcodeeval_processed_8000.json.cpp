


























using namespace std;
using ll = long long int;
using int64 = long long int;
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int INF = 1LL << 29;
const ll LONGINF = 1LL << 60;
const ll MOD = 1000000007LL;












template <typename value_type = int,
          uint64_t ln_big = 10, uint64_t id0 = 4>
struct id1 {
private:
    size_t n, n_big, n_sml, n_blk, ln_blk;
    vector<value_type> big, sml, bit;
    
    int popcount(value_type b) const {
        return __builtin_popcountll(b); 

    }
    void build(vector<value_type> vec);

public:
    

    id1();
    id1(vector<value_type> vec);
    id1(vector<value_type> vec, int k);
    

    size_t size() const;
    

    int count() const;
    

    int value(size_t k) const;
    

    int rank(size_t k) const;
    

    int rank(size_t l, size_t r) const;
    

    int select1(int r, int k) const;
    int select0(int r, int k) const;
    

    int select1_nxt(size_t k) const;
    int select0_nxt(size_t k) const;
    

    int select1_pre(size_t k) const;
    int select0_pre(size_t k) const;
    

    int at(size_t k) const;
    int operator[](size_t k) const;

    

    void show() const {
        cerr << "
        for(size_t i=0; i<big.size(); i++) {
            cerr << big[i] << " ";
        }
        cerr << endl;
        cerr << "
        for(size_t i=0; i<sml.size(); i++) {
            cerr << sml[i] << " ";
        }
        cerr << endl;
        cerr << "
        for(size_t i=0; i<bit.size(); i++) {
            cerr << bit[i] << " ";
        }
        cerr << endl;
    }
};

template <typename value_type, uint64_t ln_big, uint64_t id0>
void id1<value_type, ln_big, id0>::build(vector<value_type> vec) {
    big.resize(((n + n_big - 1) >> ln_big) + 1); 

    sml.resize(big.size() << ln_blk); 

    bit.resize(big.size() << ln_blk); 

    for(size_t i=0; i<n; i++) {
        size_t b = i >> ln_big;
        big[b+1] += vec[i];
        size_t s = i >> id0, m = i & (n_sml - 1);
        sml[s] += vec[i];
        bit[s] |= (static_cast<value_type>(vec[i]) << m);
    }

    

    for(size_t i=1; i<big.size(); i++) big[i] += big[i-1];
    for(size_t i=0; i<big.size(); i++) {
        for(size_t j=1; j<n_blk; j++) {
            sml[(i << ln_blk) + j] += sml[(i << ln_blk) + j - 1];
        }
    }
}

template <typename value_type, uint64_t ln_big, uint64_t id0>
id1<value_type, ln_big, id0>::id1() {}

template <typename value_type, uint64_t ln_big, uint64_t id0>
id1<value_type, ln_big, id0>::id1(vector<value_type> vec)
    : n(vec.size()), n_big(1ULL << ln_big), n_sml(1ULL << id0),
      n_blk(n_big >> id0), ln_blk(ln_big - id0) {
    build(vec);
}

template <typename value_type, uint64_t ln_big, uint64_t id0>
id1<value_type, ln_big, id0>::id1(vector<value_type> vec, int k)
    : n(vec.size()), n_big(1ULL << ln_big), n_sml(1ULL << id0),
      n_blk(n_big >> id0), ln_blk(ln_big - id0) {
    vector<value_type> n_vec;
    for(auto e : vec) n_vec.emplace_back(e >> k & 1);
    build(n_vec);
}

template <typename value_type, uint64_t ln_big, uint64_t id0>
size_t id1<value_type, ln_big, id0>::size() const {
    return n;
}

template <typename value_type, uint64_t ln_big, uint64_t id0>
int id1<value_type, ln_big, id0>::count() const {
    return rank(n-1);
}

template <typename value_type, uint64_t ln_big, uint64_t id0>
int id1<value_type, ln_big, id0>::value(size_t k) const {
    if(k >= n) return 0;
    size_t m = k & (n_sml - 1);
    return bit[k >> id0] >> m & 1;
}

template <typename value_type, uint64_t ln_big, uint64_t id0>
int id1<value_type, ln_big, id0>::rank(size_t k) const {
    if(k >= n) return 0; 

    size_t m = k & (n_sml - 1), mask = (1ULL << n_sml) - (1ULL << (m+1));
    return big[k >> ln_big] + sml[k >> id0] - popcount(bit[k >> id0] & mask);
}

template <typename value_type, uint64_t ln_big, uint64_t id0>
int id1<value_type, ln_big, id0>::rank(size_t l, size_t r) const {
    if(l >= r) return 0;
    return rank(r-1) - rank(l-1);
}

template <typename value_type, uint64_t ln_big, uint64_t id0>
int id1<value_type, ln_big, id0>::select1(int r, int k) const {
    int ub = n+1, lb = -1;
    while(ub - lb > 1) {
        int mid = (ub + lb) / 2;
        if(rank(mid) > r) ub = mid;
        else lb = mid;
    }
    return (ub < k) ? ub : -1;
}

template <typename value_type, uint64_t ln_big, uint64_t id0>
int id1<value_type, ln_big, id0>::select0(int r, int k) const {
    int ub = n+1, lb = -1;
    while(ub - lb > 1) {
        int mid = (ub + lb) / 2;
        if(mid + 1 - rank(mid) > r) ub = mid;
        else lb = mid;
    }
    return (ub < k) ? ub : -1;
}

template <typename value_type, uint64_t ln_big, uint64_t id0>
int id1<value_type, ln_big, id0>::select1_nxt(size_t k) const {
    return select1(rank(k), n);
}

template <typename value_type, uint64_t ln_big, uint64_t id0>
int id1<value_type, ln_big, id0>::select0_nxt(size_t k) const {
    return select0(rank(k), n);
}

template <typename value_type, uint64_t ln_big, uint64_t id0>
int id1<value_type, ln_big, id0>::select1_pre(size_t k) const {
    return select1(rank(k) - 1 - value(k), k);
}

template <typename value_type, uint64_t ln_big, uint64_t id0>
int id1<value_type, ln_big, id0>::select0_pre(size_t k) const {
    return select0(rank(k) - 1 - value(k), k);
}

template <typename value_type, uint64_t ln_big, uint64_t id0>
int id1<value_type, ln_big, id0>::at(size_t k) const {
    return bit[k >> id0] >> (k & (n_sml - 1)) & 1;
}

template <typename value_type, uint64_t ln_big, uint64_t id0>
int id1<value_type, ln_big, id0>::operator[](size_t k) const {
    return at(k);
}









template <uint64_t word_size = 30, typename value_type = int,
          uint64_t ln_big = 10, uint64_t id0 = 4>
struct WaveletMatrix {
private:
    using BitVector = id1<value_type, ln_big, id0>;
    array<BitVector, word_size> vecs;

    

    int n;
    

    vector<value_type> sort_kth_bit(const vector<value_type>& vec, int k) const;

    

    

    pair<int, int> rank_range(int l, int r, value_type x) const;    

public:
    

    

    WaveletMatrix(vector<value_type> vec);

    

    

    value_type at(int k) const;
    value_type operator[](int k) const;

    

    

    

    

    tuple<int, int, int> rank_tuple(int l, int r, value_type x) const;
    tuple<int, int, int> rank_tuple(value_type x) const;
    
    

    

    value_type quantile(int l, int r, value_type mi, value_type ma, int k) const;
    value_type quantile(int l, int r, int k) const;
    value_type quantile(int k) const;

    

    

    int freq_less(int l, int r, value_type m) const;
    int freq_less(value_type m) const;
    int freq_greater(int l, int r, value_type m) const;
    int freq_greater(value_type m) const;
    
    

    

    

    

    int freq(int l, int r, value_type mi, value_type ma) const;
    int freq(int l, int r, value_type x) const;
    int freq(value_type mi, value_type ma) const;
    
    

    

    value_type min_value(int l, int r, value_type mi, value_type ma) const;
    value_type min_value(int l, int r) const;
    value_type min_value() const;

    

    value_type max_value(int l, int r, value_type mi, value_type ma) const;
    value_type max_value(int l, int r) const;
    value_type max_value() const;

    

    int select(int l, int r, int k, value_type x) const;
    int select(int k, value_type x) const;

    

    int next_idx(int k) const;
    int prev_idx(int k) const;

    

    

    value_type next_val(int l, int r, value_type x) const;
    value_type prev_val(int l, int r, value_type x) const;
};

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
vector<value_type> WaveletMatrix<word_size, value_type, ln_big, id0>::sort_kth_bit(const vector<value_type>& vec, int k) const {
    vector<value_type> v0, v1;
    v0.reserve(vec.size()), v1.reserve(vec.size());
    for(size_t i=0; i<vec.size(); i++) {
        ((vec[i] >> k & 1) ? v1 : v0).emplace_back(vec[i]);
    }
    v0.insert(v0.end(), v1.begin(), v1.end());
    return v0;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
pair<int, int> WaveletMatrix<word_size, value_type, ln_big, id0>::rank_range(int l, int r, value_type x) const {
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(r-1) - vecs[i].rank(l-1), cnt0 = r - l - cnt1;
        if(x >> (word_size - i - 1) & 1) {
            l = all0 + vecs[i].rank(l-1), r = l + cnt1;
        }
        else {
            l = l - vecs[i].rank(l-1), r = l + cnt0;
        }
    }
    return make_pair(l, r);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
WaveletMatrix<word_size, value_type, ln_big, id0>::WaveletMatrix(vector<value_type> vec) : n(vec.size()) {
    vecs[0] = BitVector(vec, word_size - 1);
    for(size_t i=1; i<word_size; i++) {
        vec = sort_kth_bit(vec, word_size - i);
        vecs[i] = BitVector(vec, word_size - i - 1);
    }
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
value_type WaveletMatrix<word_size, value_type, ln_big, id0>::at(int k) const {
    int b = k; value_type res = 0;
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(b), cnt0 = b + 1 - cnt1;
        if(vecs[i][b] == 1) {
            res |= (1ULL << (word_size - 1 - i));
            b = all0 + cnt1 - 1;
        }
        else {
            b = cnt0 - 1;
        }
    }
    return res;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
value_type WaveletMatrix<word_size, value_type, ln_big, id0>::operator[](int k) const {
    return at(k);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
tuple<int, int, int> WaveletMatrix<word_size, value_type, ln_big, id0>::rank_tuple(int l, int r, value_type x) const {
    int small = 0, equal = 0, big = 0;
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(r-1) - vecs[i].rank(l-1), cnt0 = r - l - cnt1;
        if(x >> (word_size - i - 1) & 1) {
            small += cnt0;
            l = all0 + vecs[i].rank(l-1), r = l + cnt1;
        }
        else {
            big += cnt1;
            l = l - vecs[i].rank(l-1), r = l + cnt0;
        }
    }
    equal = r - l;
    return make_tuple(small, equal, big);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
tuple<int, int, int> WaveletMatrix<word_size, value_type, ln_big, id0>::rank_tuple(value_type x) const {
    return rank_tuple(0, n, x);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
value_type WaveletMatrix<word_size, value_type, ln_big, id0>::quantile(int l, int r, value_type mi, value_type ma, int k) const {
    int cnt_less = freq_less(l, r, mi), id2 = freq_greater(l, r, ma);
    if(r - l - cnt_less - id2 < k) return -1;
    return quantile(l, r, k + cnt_less);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
value_type WaveletMatrix<word_size, value_type, ln_big, id0>::quantile(int l, int r, int k) const {
    if(r - l < k) return -1;
    value_type res = 0;
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(r-1) - vecs[i].rank(l-1), cnt0 = r - l - cnt1;
        if(cnt0 >= k) {
            l = l - vecs[i].rank(l-1), r = l + cnt0;
        }
        else {
            k -= cnt0;
            res |= 1ULL << (word_size - 1 - i);
            l = all0 + vecs[i].rank(l-1), r = l + cnt1;
        }
    }
    return res;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
value_type WaveletMatrix<word_size, value_type, ln_big, id0>::quantile(int k) const {
    return quantile(0, n, k);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
int WaveletMatrix<word_size, value_type, ln_big, id0>::freq_less(int l, int r, value_type m) const {
    int res = 0;
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(r-1) - vecs[i].rank(l-1), cnt0 = r - l - cnt1;
        if(m >> (word_size - 1 - i) & 1) {
            res += cnt0;
            l = all0 + vecs[i].rank(l-1), r = l + cnt1;
        }
        else {
            l = l - vecs[i].rank(l-1), r = l + cnt0;
        }
    }
    return res;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
int WaveletMatrix<word_size, value_type, ln_big, id0>::freq_less(value_type m) const {
    return freq_less(0, n, m);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
int WaveletMatrix<word_size, value_type, ln_big, id0>::freq_greater(int l, int r, value_type m) const {
    int res = 0;
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(r-1) - vecs[i].rank(l-1), cnt0 = r - l - cnt1;
        if(m >> (word_size - 1 - i) & 1) {
            l = all0 + vecs[i].rank(l-1), r = l + cnt1;
        }
        else {
            res += cnt1;
            l = l - vecs[i].rank(l-1), r = l + cnt0;
        }
    }
    return res;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
int WaveletMatrix<word_size, value_type, ln_big, id0>::freq_greater(value_type m) const {
    return freq_greater(0, n, m);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
int WaveletMatrix<word_size, value_type, ln_big, id0>::freq(int l, int r, value_type mi, value_type ma) const {
    return r - l - freq_less(l, r, mi) - freq_greater(l, r, ma);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
int WaveletMatrix<word_size, value_type, ln_big, id0>::freq(int l, int r, value_type x) const {
    return freq(l, r, x, x);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
int WaveletMatrix<word_size, value_type, ln_big, id0>::freq(value_type mi, value_type ma) const {
    return freq(0, n, mi, ma);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
value_type WaveletMatrix<word_size, value_type, ln_big, id0>::min_value(int l, int r, value_type mi, value_type ma) const {
    return quantile(l, r, mi, ma, 1);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
value_type WaveletMatrix<word_size, value_type, ln_big, id0>::min_value(int l, int r) const {
    return quantile(l, r, 1);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
value_type WaveletMatrix<word_size, value_type, ln_big, id0>::min_value() const {
    return min_value(0, n);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
value_type WaveletMatrix<word_size, value_type, ln_big, id0>::max_value(int l, int r, value_type mi, value_type ma) const {
    return quantile(l, r, mi, ma, freq(l, r, mi, ma));
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
value_type WaveletMatrix<word_size, value_type, ln_big, id0>::max_value(int l, int r) const {
    return quantile(l, r, r - l);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
value_type WaveletMatrix<word_size, value_type, ln_big, id0>::max_value() const {
    return max_value(0, n);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
int WaveletMatrix<word_size, value_type, ln_big, id0>::select(int l, int r, int k, value_type x) const {
    if(k <= 0) return -1;
    tie(l, r) = rank_range(l, r, x);
    if(r - l < k) return -1;

    int pos = l + k - 1;
    for(size_t i=0; i<word_size; i++) {
        int b = x >> i & 1;
        int cnt1 = vecs[word_size - 1 - i].rank(n-1), cnt0 = n - cnt1;
        if(b == 0) {
            int m = pos;
            pos = vecs[word_size - 1 - i].select0(m, n);
        }
        else {
            int m = pos - cnt0;
            pos = vecs[word_size - 1 - i].select1(m, n);
        }
    }
    return pos;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
int WaveletMatrix<word_size, value_type, ln_big, id0>::select(int k, value_type x) const {
    return select(0, n, k, x);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
int WaveletMatrix<word_size, value_type, ln_big, id0>::next_idx(int k) const {
    int m = freq(0, k+1, at(k));
    return select(m+1, at(k));
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
int WaveletMatrix<word_size, value_type, ln_big, id0>::prev_idx(int k) const {
    int m = freq(0, k+1, at(k));
    return select(m-1, at(k));
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
value_type WaveletMatrix<word_size, value_type, ln_big, id0>::next_val(int l, int r, value_type x) const {
    int k = r - l - freq_greater(l, r, x) + 1;
    return quantile(l, r, k);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t id0>
value_type WaveletMatrix<word_size, value_type, ln_big, id0>::prev_val(int l, int r, value_type x) const {
    return quantile(l, r, freq_less(l, r, x));
}










constexpr int SIZE = 1000010;
constexpr int LOGS = 21;

template <typename T>
struct SparseTable_max {
    T a[SIZE];
    int table[SIZE][LOGS], log_table[SIZE];
    int n;
    void init(vector<T> p) {
        n = (int)p.size();
        for(int i=0; i<n; i++) {
            a[i] = p[i];
            table[i][0] = i;
        }
        for(int i=2; i<=n; i++) {
            log_table[i] = log_table[i>>1] + 1;
        }

        for(int k=1; (1<<k)<=n; k++) {
            for(int i=0; i+(1<<(k-1))<=n; i++) {
                int x = table[i           ][k-1];
                int y = table[i+(1<<(k-1))][k-1];
                if(a[x] <= a[y]) table[i][k] = y;
                else table[i][k] = x;
            }
        }
    }

    

    int query(int l, int r) {
        int d = log_table[r - l];
        int x = table[l       ][d];
        int y = table[r-(1<<d)][d];
        if(a[x] <= a[y]) return y;
        else return x;
    }
};

template <typename T>
struct SparseTable_min {
    T a[SIZE];
    int table[SIZE][LOGS], log_table[SIZE];
    int n;
    void init(vector<T> p) {
        n = (int)p.size();
        for(int i=0; i<n; i++) {
            a[i] = p[i];
            table[i][0] = i;
        }
        for(int i=2; i<=n; i++) {
            log_table[i] = log_table[i>>1] + 1;
        }

        for(int k=1; (1<<k)<=n; k++) {
            for(int i=0; i+(1<<(k-1))<=n; i++) {
                int x = table[i           ][k-1];
                int y = table[i+(1<<(k-1))][k-1];
                if(a[x] <= a[y]) table[i][k] = x;
                else table[i][k] = y;
            }
        }
    }

    

    int query(int l, int r) {
        int d = log_table[r - l];
        int x = table[l       ][d];
        int y = table[r-(1<<d)][d];
        if(a[x] <= a[y]) return x;
        else return y;
    }
};

SparseTable_min<ll> smin;
SparseTable_max<ll> smax;

int main() {
    int N; scanf("%d", &N);
    vector<ll> A(N);
    for(int i=0; i<N; i++) scanf("%d", &A[i]);

    ll ans = 0;
    

    smin.init(A);
    smax.init(A);
    for(int i=0; i<N; i++) {
        

        

        


        ll l, r;
        {
            ll lb = -1, ub = i;
            while(ub - lb > 1) {
                ll mid = (ub + lb) / 2;
                

                ll x = smin.query(mid, i);
                if(A[x] >= A[i]) ub = mid;
                else lb = mid;
            }
            l = ub;
        }

        {
            ll lb = i + 1, ub = N + 1;
            while(ub - lb > 1) {
                ll mid = (ub + lb) / 2;
                

                ll x = smin.query(i+1, mid);
                if(A[x] > A[i]) lb = mid;
                else ub = mid;
            }
            r = lb;
        }

        
        ans -= (r - i) * (i - l + 1) * A[i];

        

        

        

        {
            ll lb = -1, ub = i;
            while(ub - lb > 1) {
                ll mid = (ub + lb) / 2;
                


                ll x = smax.query(mid, i);
                if(A[x] <= A[i]) ub = mid;
                else lb = mid;
            }
            l = ub;
        }
        {
            ll lb = i+1, ub = N+1;
            while(ub - lb > 1) {
                ll mid = (ub + lb) / 2;
                


                ll x = smax.query(i+1, mid);
                if(A[x] < A[i]) lb = mid;
                else ub = mid;
            }
            r = lb;
        }
        
        ans += (r - i) * (i - l + 1) * A[i];
    }
    cout << ans << endl;
    return 0;
}
