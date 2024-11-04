#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))
#define all(x) (x).begin(), (x).end()



LL get_time() {
    return chrono::duration_cast<chrono::nanoseconds>(
        chrono::steady_clock::now().time_since_epoch())
        .count();
}



LL randint(LL l, LL r) {
	#if DEBUG && !ONLINE_JUDGE
	static mt19937_64 gen; 

	#else
	static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
	#endif
	return uniform_int_distribution<LL>(l, r)(gen);
}

template <typename Iterator>
string print_iterable(Iterator begin, Iterator end, string bef, string aft,
        function<string(typename iterator_traits<Iterator>::value_type)>* f = nullptr) {
    stringstream res;
    res << bef;
    bool is_first = true;
    for (Iterator it = begin; it != end; ++it) {
        if (!is_first) res << ", ";
        if (f != nullptr) res << (*f)(*it);
        else res << *it;
        is_first = false;
    }
    res << aft;
    return res.str();
}

template <typename S, typename T>
ostream& operator <<(ostream& out, const pair<S, T>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

#define _define_print_container(Container, bef, aft)        \
template <typename T>                                       \
ostream& operator <<(ostream& out, const Container<T>& v) { \
    out << print_iterable(v.begin(), v.end(), bef, aft);    \
    return out;                                             \
}                                                           \

_define_print_container(vector, "[", "]");
_define_print_container(set, "{", "}");
_define_print_container(unordered_set, "{", "}");
_define_print_container(multiset, "{", "}");
_define_print_container(unordered_multiset, "{", "}");
_define_print_container(deque, "[", "]");

#define _define_print_dictionary(Dictionary, bef, aft)                      \
template <typename T1, typename T2>                                         \
ostream& operator <<(ostream& out, const Dictionary<T1, T2>& v) {           \
    out << print_iterable(v.begin(), v.end(), bef, aft);                    \
    return out;                                                             \
}                                                                           \

_define_print_dictionary(map, "{", "}");
_define_print_dictionary(unordered_map, "{", "}");

#define _define_print_container_adaptor(Adaptor, OP)                        \
template <typename T>                                                       \
ostream& operator <<(ostream& out, Adaptor<T> a) {                          \
    vector<T> v;                                                            \
    while (!a.empty()) v.push_back(a.OP()), a.pop();                        \
    out << v;                                                               \
    return out;                                                             \
}                                                                           \

_define_print_container_adaptor(stack, top)
_define_print_container_adaptor(queue, front)
_define_print_container_adaptor(priority_queue, top)

template<class TH>
void _dbg(const char* name, TH val){
    clog << name << ": " << val << endl;
}
template<class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
    while(*names != ',') clog << *names++;
    clog << ": " << curr_val << ", ";
    _dbg(names+1, vals...);
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) \
    clog << #x << ": " << print_iterable(x, x+len, "[", "]") << endl;
    #define dbg_arr1(x, len) \
    clog << #x << ": " << print_iterable(x+1, x+len+1, "[", "]") << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
    #define dbg_arr1(x, len)
#endif










LL Inverse(LL n, LL m) {
    n %= m;
    if (n <= 1) return n; 

    return m - ((m * Inverse(m, n) - 1) / n);
}









LL pow(LL x, LL e, LL mod) {
    LL res = 1;
    for (; e >= 1; e >>= 1) {
        if (e & 1) res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}



















struct FastMod {
    ULL mod;
    ULL inv;
    FastMod(ULL mod) : mod(mod), inv(-1ULL / mod) {}
    ULL operator()(ULL x) {
        ULL q = (ULL)((__uint128_t(inv) * x) >> 64);
        ULL r = x - q * mod;
        return r - mod * (r >= mod);
    }
};































struct ModularInteger {
    static int mod;
    static __uint128_t inv_mod; 

    int n; 

    static void set_mod(int _mod) {
        mod = _mod;
        inv_mod = -1ULL / mod;
    }
    ModularInteger(): n(0) {}
    ModularInteger(LL _n): n(_n % mod) {
        n += (n<0)*mod;
    }
    LL get() const { return n; }
    static int fast_mod(ULL x) { 

        ULL q = (inv_mod * x) >> 64;
        int m = x - q * mod;
        m -= mod * (m >= mod);
        return m;
    }

    ModularInteger operator-() const { return n?mod-n:0; }
};
int ModularInteger::mod;
__uint128_t ModularInteger::inv_mod;

ModularInteger operator +(const ModularInteger& A, const ModularInteger& B) {
    ModularInteger C;
    C.n = A.n + B.n;
    C.n -= (C.n >= ModularInteger::mod)*ModularInteger::mod;
    return C;
}

void operator +=(ModularInteger& A, const ModularInteger& B) {
    A.n += B.n;
    A.n -= (A.n >= ModularInteger::mod)*ModularInteger::mod;
}

ModularInteger operator -(const ModularInteger& A, const ModularInteger& B) {
    ModularInteger C;
    C.n = A.n - B.n;
    C.n += (C.n < 0)*ModularInteger::mod;
    return C;
}

void operator -=(ModularInteger& A, const ModularInteger& B) {
    A.n -= B.n;
    A.n += (A.n < 0)*ModularInteger::mod;
}

ModularInteger operator *(const ModularInteger& A, const ModularInteger& B) {
    ModularInteger C;
    C.n = ModularInteger::fast_mod(((ULL)A.n) * B.n);
    return C;
}

void operator *=(ModularInteger& A, const ModularInteger& B) {
    A.n = ModularInteger::fast_mod(((ULL)A.n) * B.n);
}



ModularInteger operator /(const ModularInteger& A, const ModularInteger& B) {
    return A * Inverse(B.n, ModularInteger::mod);
}



void operator/=(ModularInteger& A, const ModularInteger& B) {
    A *= Inverse(B.n, ModularInteger::mod);
}

ModularInteger power(ModularInteger A, ULL e) {
    ModularInteger res = 1;
    for (; e >= 1; e >>= 1) {
        if (e & 1) res *= A;
        A *= A;
    }
    return res;
}

bool operator ==(const ModularInteger& A, const ModularInteger& B) {
    return A.n == B.n;
}
bool operator !=(const ModularInteger& A, const ModularInteger& B) {
    return A.n != B.n;
}
bool operator <(const ModularInteger& A, const ModularInteger& B) {
    return A.n < B.n;
}
bool operator >(const ModularInteger& A, const ModularInteger& B) {
    return A.n > B.n;
}
bool operator <=(const ModularInteger& A, const ModularInteger& B) {
    return A.n <= B.n;
}
bool operator >=(const ModularInteger& A, const ModularInteger& B) {
    return A.n >= B.n;
}

ostream& operator <<(ostream& out, const ModularInteger& A) {
    out << A.n;
    return out;
}

istream& operator >>(istream& in, ModularInteger& A) {
  LL a;
  in >> a;
  A = ModularInteger(a);
  return in;
}

typedef ModularInteger mint;



















LL FindElementWithGivenOrder(LL mod, LL order) {
    assert((mod-1)%order == 0);
    vector<LL> primes; 

    LL n = order;
    for (LL p = 2; p*p <= n; p++) {
        if (n % p == 0) {
            primes.push_back(p);
            while (n % p == 0) n /= p;
        }
    }
    if (n != 1) primes.push_back(n);
    for (LL x = 2; x < mod; x++) {
        LL y = pow(x, (mod-1)/order, mod);
        if (pow(y, order, mod) != 1) continue;
        bool works = true;
        for (LL p : primes) {
            if (pow(y, order/p, mod) == 1) {
                works = false;
                break;
            }
        }
        if (works) return y;
    }
    assert(0);
    return -1;
}

































template <typename T>
void _FFT_Precompute(int N, vector<int>& rev, vector<T>& roots) {
    static_assert(std::is_same<T, ModularInteger>::value
                  or std::is_same<T, complex<double>>::value);
    assert(N > 0 and !(N&(N-1)));
    rev.resize(N);
    roots.resize(N);
    rev[0] = 0;
    for (int i = 1; i < N; i++) rev[i] = (rev[i>>1]>>1) ^ ((i&1)?(N>>1):0);
    
    

    

    if constexpr (std::is_same<T, ModularInteger>::value) {
        ModularInteger primitive_root =
            FindElementWithGivenOrder(ModularInteger::mod, N);
        for (int k = 1; k < N; k<<=1) {
            

            ModularInteger z = power(primitive_root, N/(2*k)); 
            ModularInteger r = 1;
            for (int i = 0; i < k; i++) {
                roots[k+i] = r;
                r *= z;
            }
        }
    } else {
        for (int k = 1; k < N; k<<=1) {
            for (int i = 0; i < k; i++) {
                double theta = M_PI*i/k;
                roots[k+i] = cos(theta) + 1i * sin(theta);
            }
        }
    }
}





























template <typename T>
void FFT(vector<T>& a, bool inverse=false) {
    static_assert(std::is_same<T, ModularInteger>::value
                  or std::is_same<T, complex<double>>::value);
    static vector<int> rev;
    static vector<T> roots;
    int N = a.size();
    assert(N > 0 and !(N&(N-1)));
    if ((int)rev.size() < N) _FFT_Precompute(N, rev, roots);

    int offset = 0;
    while ((1<<offset) < (int)rev.size()/N) offset++;

    for (int i = 0; i < N; i++) if (i < (rev[i]>>offset)) {
        swap(a[i], a[rev[i]>>offset]);
    }
    
    for (int k = 1; k < N; k<<=1) {
        for (int i = 0; i < N; i+=2*k) {
            for (int j = 0; j < k; j++) {
                T x = a[i+j], y = a[i+k+j] * roots[k+j];
                a[i+j] = x + y;
                a[i+k+j] = x - y;
            }
        }
    }

    if (inverse) {
        reverse(a.begin()+1, a.end());
        T invN = static_cast<T>(1) / static_cast<T>(N);
        for (auto& val : a) val *= invN;
    }
}














template<typename T>
vector<T> Convolution(vector<T> a, vector<T> b) {
    const static int small_len = 64;
    int alen = a.size(), blen = b.size();
    assert(1 <= alen and 1 <= blen);

    

    

    if (alen < small_len or blen < small_len) {
        vector<T> c(alen + blen-1, 0);
        for (int i = 0; i < alen; i++) for (int j = 0; j < blen; j++)
            c[i + j] += a[i] * b[j];
        return c;
    }
    
    int sz = 1;
    while (sz < alen + blen - 1) sz *= 2;
    a.resize(sz, 0);
    b.resize(sz, 0);
    FFT(a);
    FFT(b);
    for (int i = 0; i < sz; i++) a[i] *= b[i];
    FFT(a, true);
    a.resize(alen + blen - 1);
    return a;
}









const int MAXN = 300200;
mint fact[MAXN];
mint ifact[MAXN];

int main() {
    mint::set_mod(998244353);

    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) fact[i] = i * fact[i-1];
    ifact[MAXN-1] = mint(1) / fact[MAXN-1];
    for (int i = MAXN-2; i >= 0; i--) ifact[i] = ifact[i+1] * (i+1);
    
    int n;
    cin >> n;
    int m = n/2;

    vector<mint> A(n+2, 0);
    vector<mint> B(n+2, 0);
    vector<mint> C(n+2, 0);
    for (int i = m; i <= n-2; i++) A[i] = fact[i];
    for (int i = 0; i <= n; i++) B[i] = ifact[n-i];
    for (int i = 0; i <= n-2-m; i++) C[i] = fact[i];

    auto AB = Convolution(A, B);
    auto CB = Convolution(C, B);
    


    mint last_ris2 = 0;
    for (int i = 1; i <= n; i++) {
        if (i > m+1) {
            cout << 0 << " ";
            continue;
        }
        mint ris1 = 0;
        

        

        ris1 = AB[n+i-2];
        ris1 *= (i-1) * fact[n-i];

        mint ris2 = 0;
        if (i == 1) {
            for (int j = i+1; j <= n-m; j++) {
                mint ris3 = 0;
                

                

                ris3 = CB[n-2+j] * fact[n-j];
                

                ris2 += ris3;
            }
        } else {
            ris2 = last_ris2 - CB[n-2+i] * fact[n-i];
        }
        last_ris2 = ris2;
        cout << fact[n-1] - ris1 - ris2 << " ";
    }
}
