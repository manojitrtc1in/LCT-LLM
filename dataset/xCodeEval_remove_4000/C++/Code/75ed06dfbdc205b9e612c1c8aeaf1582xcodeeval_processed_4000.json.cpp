
    
    






    
    


    

    






    
    













typedef long double ld;

const int INF = INT_MAX / 2;
const ll LINF = (ll)2e18 + 666, M1 = 1e9 + 7, M2 = 1e9 + 9, M = 1e9 + 7;
const ld EPS = 1e-8;


    const ld M_PI = acos(-1);



using namespace std;


    using namespace __gnu_cxx;
    using namespace __gnu_pbds;

    template<class K, class T, class Cmp = less<K>>
    using ordered_map = tree<K, T, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

    template<class T, class Cmp = less<T>>
    using ordered_set = ordered_map<T, null_type, Cmp>;


void run();

template<class T1, class T2>
inline bool mini(T1 &a, T2 b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T1, class T2>
inline bool maxi(T1 &a, T2 b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

mt19937 rnd(0);

signed main() {
    
        freopen(FILENAME".in", "r", stdin);
        freopen(FILENAME".out", "w", stdout);
    

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
        int temp, *ptr = new int;
        rnd.seed(time(0) ^ hash<string>()(__FILE__) ^ hash<string>()(__TIME__) ^
        temp ^ reinterpret_cast<size_t>(ptr) ^ 
        hash<string>()(
            string("ksdhfkshdfkshdfhdfkshdf") +
            "fdskhjfhsdkfhsdkfhsdkfjfsdhkjfhksdfhskdfhskdhfksdhfksdhfddjff" +
            "Hack my random, if you can!"));
    
    cout << setprecision(11) << fixed;
    
        auto start = clock();
    
    run();
    
        cout << "\ntime = " << (double)(clock() - start) / CLOCKS_PER_SEC << "\n";
    
    return 0;
}



template<ll Mod = M, class T = ll>
struct mod {
    T operator()(T x, T y) {
        return x * y % Mod;
    }
};

template<class T, ll Mod>
inline T identity_element(mod<Mod, T>) {
    return T(1);
}

template<class T>
struct is_continer {
 private:
    static void detect(...);
    template<class U>
    static decltype(declval<U>().begin()) detect(const U&);
 public:
    static const bool value = !is_same<decltype(detect(declval<T>())), void>::value;
};

template<class T>
struct is_std_array {
    static const bool value = 0;
};

template<class T, size_t sz>
struct is_std_array<array<T, sz>> {
    static const bool value = 1;
};

template<class T>
typename enable_if<is_continer<T>::value && !is_same<T, string>::value, ostream>::type&
operator<<(ostream &out, const T &arr) {
    for (const auto &x : arr)
        out << x << " ";
    out << "\n";
    return out;
}

template<class T>
typename enable_if<is_continer<T>::value && !is_same<T, string>::value, istream>::type&
operator>>(istream &in, T &arr) {
    for (auto &x : arr)
        in >> x;
    return in;
}

template<class T, size_t pos>
void read_tuple(istream &in, T &x) {
    if constexpr (pos == tuple_size<T>::value)
        return;
    else {
        in >> get<pos>(x);
        read_tuple<T, pos + 1>(in, x);
    }
}

template<class T, size_t pos = 0>
typename enable_if<(bool)tuple_size<T>::value && !is_std_array<T>::value, istream>::type&
operator>>(istream &in, T &x) {
    read_tuple<T, 0>(in, x);
    return in;
}

template<class T, size_t pos>
void write_tuple(ostream &out, const T &x) {
    if constexpr (pos == tuple_size<T>::value)
        return;
    else {
        if constexpr (pos != 0)
            out << " ";
        out << get<pos>(x);
        write_tuple<T, pos + 1>(out, x);
    }
}

template<class T>
typename enable_if<(bool)tuple_size<T>::value && !is_std_array<T>::value, ostream>::type&
operator<<(ostream &out, const T &x) {
    write_tuple<T, 0>(out, x);
    return out;
}





template<class T>
void debug(const T &x) {
    cout << x << endl;
}

template<class T, class... Args>
void debug(const T &x, const Args & ...args) {
    cout << x << " ";
    debug(args...);
}

template<class T>
void debugs(const T &x) {
    cout << x << " ";
}

template<class T, class... Args>
void debugs(const T &x, const Args & ...args) {
    cout << x << " ";
    debugs(args...);
}











struct Seq {
    int o, c;
    Seq(int o = 0, int c = 0): o(o), c(c) {}
    Seq operator+(const Seq &other) {
        int mn = min(o, other.c); 
        return Seq(o + other.o - mn, c + other.c - mn);
    }
    bool good() const {
        return o == 0 && c == 0;
    }
};
 
template<class T>
struct Segtree {
    int n;
    vector<T> a;
    Segtree(int n = 0): n(n), a(n * 4) {}
    void upd(int p, const T &x, int v = 0, int l = 0, int r = -1) {
        if (r == -1)
            r = n;
        if (r - l == 1) {
            a[v] = x;
            return;
        }
        int c = (l + r) / 2;
        if (p < c)
            upd(p, x, v * 2 + 1, l, c);
        else
            upd(p, x, v * 2 + 2, c, r);
        a[v] = a[v * 2 + 1] + a[v * 2 + 2];
    }
    T get(int ql, int qr, int v = 0, int l = 0, int r = -1) {
        if (r == -1)
            r = n;
        if (l >= qr || ql >= r) {
            return T();
        } else if (l >= ql && r <= qr) {
            return a[v];
        }
        int c = (l + r) / 2;
        return get(ql, qr, v * 2 + 1, l, c) + get(ql, qr, v * 2 + 2, c, r);
    }
};

const int N = 1e5 + 100, K = 16;
alignas(32) int a[N * 2], b[N * 2], e[N * 4];
int bpos[N / 8];
__m256i vset[N / 8][2], vget[N / 8][2], set_mask[N / 8][2], get_mask[N / 8][2];
uint8_t bad[N / 8];




void make(int l) {
    bpos[l / K] = b[l];
    int err = 0;
    int gets[K], sets[K], smask[K] = {}, gmask[K] = {};
    for (int i = l; i < l + K; ++i) {
        mini(bpos[l / K], b[i]);
    }
    for (int i = l; i < l + K; ++i) {
        int ai = a[i], bi = b[i];
        if (ai < 0) {
            if (smask[bi - bpos[l / K]]) {
                err += (e[bi + N] != -ai);
                smask[bi - bpos[l / K]] = 0;
            } else {
                gets[bi - bpos[l / K]] = -a[i];
                gmask[bi - bpos[l / K]] = -1;
            }
        } else {
            sets[bi - bpos[l / K]] = a[i];
            smask[bi - bpos[l / K]] = -1;
            e[bi + N] = ai;
        }
    }
    if (err) {
        bad[l / K] = 1;
    } else {
        bad[l / K] = 0;
    }
    vset[l / K][0] = _mm256_lddqu_si256(reinterpret_cast<__m256i *>(sets));
    vset[l / K][1] = _mm256_lddqu_si256(reinterpret_cast<__m256i *>(sets) + 1);
    vget[l / K][0] = _mm256_lddqu_si256(reinterpret_cast<__m256i *>(gets));
    vget[l / K][1] = _mm256_lddqu_si256(reinterpret_cast<__m256i *>(gets) + 1);
    set_mask[l / K][0] = _mm256_lddqu_si256(reinterpret_cast<__m256i *>(smask));
    set_mask[l / K][1] = _mm256_lddqu_si256(reinterpret_cast<__m256i *>(smask) + 1);
    get_mask[l / K][0] = _mm256_lddqu_si256(reinterpret_cast<__m256i *>(gmask));
    get_mask[l / K][1] = _mm256_lddqu_si256(reinterpret_cast<__m256i *>(gmask) + 1);
}

void run() {
    int n, k;
    cin >> n >> k;
    Segtree<Seq> st(n);
    int cur_b = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        
        cin >> x;
        
        if (cur_b == 0) {
            x = 1;
        } else if (cur_b == n - i) {
            x = -1;
        } else {
            x = (int) (rnd() % 2 * 2) - 1;
        }
        cur_b += x;
        
        a[i] = x;
        Seq s;
        b[i + 1] = b[i];
        if (a[i] < 0) {
            ++s.c;
            b[i]--;
            b[i + 1]--;
        } else {
            ++s.o;
            b[i + 1]++;
        }
        st.upd(i, s);
    }
    for (int i = 0; i + K <= n; i += K) {
        make(i);
    }
    int q;
    cin >> q;
    while (q--) {
        int t;
        
        cin >> t;
        
        t = 2;
        
        if (t == 1) {
            int i, x;
            
            cin >> i >> x;
            
            i = 1;
            x = 1;
            
            Seq s;
            --i;
            if (x < 0)
                ++s.c;
            else
                ++s.o;
            st.upd(i, s);
            if ((a[i] < 0) != (x < 0)) {
                __m256i add;
                if (x < 0) {
                    

                    add = _mm256_set1_epi32(-2);
                }
                else {
                    

                    add = _mm256_set1_epi32(2);
                }
                b[i] += (x < 0 ? -1 : 1);
                int j = i + 1;
                while (j % K) {
                    b[j] += (x < 0 ? -2 : 2);
                    ++j;
                }
                for (; j < n; j += 8) {
                    *reinterpret_cast<__m256i *>(b + j) =
                        _mm256_add_epi32(*reinterpret_cast<__m256i *>(b + j), add);
                }
                int ni = i / K;
                if (ni < n / K) {
                    int add;
                    if (x < 0)
                        add = -2;
                    else
                        add = 2;
                    for (int j = ni + 1; j < n / K; ++j) {
                        bpos[j] += add;
                    }
                }
            }
            a[i] = x;
            if (i / K < n / K)
                make(i - i % K);
        } else {
            int l, r;
            
            cin >> l >> r;
            
            l = 1;
            r = n;
            
            --l;
            if (!st.get(l, r).good()) {
                cout << "NO\n";
                continue;
            }
            int err = 0;
            if (r - l < 512) {
                for (int i = l; i < r; ++i) {
                    int ai = a[i], bi = b[i];
                    if (ai < 0) {
                        err += (e[bi + N] != -ai);
                    } else {
                        e[bi + N] = ai;
                    }
                }
                

            } else {
                __m256i errm = _mm256_setzero_si256();
                int i;
                for (i = l / K + bool(l % K); i + 32 <= r / K; i += 32) {
                    __m256i ai = _mm256_lddqu_si256(reinterpret_cast<__m256i *>(bad + i));
                    errm = _mm256_add_epi32(errm, ai);
                }
                int errs[8] = {};
                _mm256_storeu_si256(reinterpret_cast<__m256i *>(errs), errm);
                for (auto x : errs)
                    err += x;
                for (; i < r / K; ++i) {
                    err += bad[i];
                }
                for (int i = l; i % K; ++i) {
                    int ai = a[i], bi = b[i];
                    if (ai < 0) {
                        err += (e[bi + N] != -ai);
                    } else {
                        e[bi + N] = ai;
                    }
                }
                debug(err);
                errm = _mm256_setzero_si256();
                __m256i id0 = _mm256_setzero_si256();
                for (int i = l / K + bool(l % K); i < r / K; ++i) {
                    
                    IACA_START;
                    
                    __m256i ev0 = _mm256_lddqu_si256(
                        reinterpret_cast<__m256i *>(e + N + bpos[i]));
                    __m256i ev1 = _mm256_lddqu_si256(
                        reinterpret_cast<__m256i *>(e + N + bpos[i]) + 1);
                    errm = _mm256_or_si256(errm,
                        _mm256_and_si256(_mm256_xor_si256(vget[i][0], ev0), get_mask[i][0]));
                    id0 = _mm256_or_si256(id0,
                        _mm256_and_si256(_mm256_xor_si256(vget[i][1], ev1), get_mask[i][1]));
                    _mm256_maskstore_epi32(e + N + bpos[i], set_mask[i][0], vset[i][0]);
                    _mm256_maskstore_epi32(e + N + bpos[i] + 8, set_mask[i][1], vset[i][1]);
                    
                    IACA_END;
                    
                }
                _mm256_storeu_si256(reinterpret_cast<__m256i *>(errs), errm);
                for (auto x : errs)
                    err += x;
                _mm256_storeu_si256(reinterpret_cast<__m256i *>(errs), id0);
                for (auto x : errs)
                    err += x;
                debug(err);
                for (int i = r - r % K; i < r; ++i) {
                    int ai = a[i], bi = b[i];
                    if (ai < 0) {
                        err += (e[bi + N] != -ai);
                    } else {
                        e[bi + N] = ai;
                    }
                }
            }
            if (!err) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
}