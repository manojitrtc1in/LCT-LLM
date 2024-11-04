

















using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;






















const int mod = 1e9 + 7;





const long long INF = 2e18 + 10;




    vector<int> x(n); \
    for (auto &i : x) \
        cin >> i;

std::ostream& operator << (std::ostream& stream, const std::string& str)
    {
    stream << str.c_str();
    return stream;
    }

std::wostream& operator << (std::wostream& stream, const std::wstring& str)
    {
    stream << str.c_str();
    return stream;
    }

template <template <typename... Args> class ContainerT, typename... Args>
std::ostream& operator << (std::ostream& stream, const ContainerT <Args...> & container)
    {
    for (auto&& elem : container){

         cout<<" ";
         stream << elem;


       }
    stream<<endl;
    return stream;
    }

template <template <typename T, size_t N, typename... Args> class ContainerT, typename T, size_t N, typename... Args>
std::ostream& operator << (std::ostream& stream, const ContainerT <T, N, Args...> & container)
    {
    for (auto&& elem : container){

        cout<<" ";
        stream << elem;


    }
    stream<<endl;
    return stream;
    }

template<typename T1, typename T2>
std::ostream& operator << (std::ostream& stream, const std::pair <T1, T2> & val)
    {
    stream << val.first << " " << val.second ;
    stream<<endl;
    return stream;
    }


template <typename T>
    using v = vector<T>;

template <typename T>
    using vv = vector<vector<T>>;

template <typename T>
    using vvv = vector<vector<vector<T>>>;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<vector<vector<vector<int>>>> vvvvi;
typedef vector<vector<double>> vvd;


typedef pair<int, int> pii;

template <typename T1, typename T2>
bool id3(pair<T1, T2> a, pair<T1, T2> b)
{
    return make_pair(a.se, a.fi) < make_pair(b.se, b.fi);
}

int multiply(int a, int b, int in_mod) { return (int)(1LL * a * b % in_mod); }


int mult_identity(int a) { return 1; }




const double PI = acosl(-1);



vector<vector<int> > multiply(vector<vector<int>> a, vector<vector<int>> b, int in_mod)
{
    int n = a.size();
    int l = b.size();
    int m = b[0].size();
    vector<vector<int> > result(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<l;k++)
            {
                result[i][j] = (result[i][j] + a[i][k]*b[k][j])%in_mod;
                result[i][j] += in_mod;
                result[i][j] %= in_mod;
            }
        }
    }
    return result;
}
vector<vector<int>> operator%(vector<vector<int>> a, int in_mod)
{
    for(auto &i:a)
        for(auto &j:i)
        {
            j%=in_mod;
            j += in_mod;
            j %= in_mod;
        }
    return a;
}
vector<vector<int>> mult_identity(vector<vector<int>> a)
{
    int n=a.size();
    vector<vector<int>> output(n, vector<int> (n));
    for(int i=0;i<n;i++)
        output[i][i]=1;
    return output;
}

vector<int> id2(vector<vector<int>> a, vector<int> b, int in_mod)
{
    int n =a.size();

    vector<int> output(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            output[i]+=a[i][j]*b[j];
            output[i]%=in_mod;
            output[i] += in_mod;
            output[i] %= in_mod;
        }
    }
    return output;
}




auto power(auto a, auto b, int in_mod)
{

    auto prod = mult_identity(a);
    auto mult = a % in_mod;
    while (b != 0)
    {
        if (b % 2)
        {
            prod = multiply(prod, mult, in_mod);
        }
        if(b/2)
        mult = multiply(mult, mult, in_mod);
        b /= 2;
    }
    return prod;
}
int mod_inv(int q, int in_mod)
{
    return power(q, in_mod - 2, in_mod);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());






namespace algebra {
    const int inf = 1e9;
    const int magic = 500; 


    namespace fft {
        const int maxn = 1 << 21;

        typedef double ftype;
        typedef complex<ftype> point;

        vector<point> w;
        const ftype pi = acos(-1);
        bool initiated = 0;
        void init() {
            if(!initiated) {
                w.resize(maxn);
                for(int i = 1; i < maxn; i *= 2) {
                    for(int j = 0; j < i; j++) {
                        w[i + j] = polar(ftype(1),2* pi * j / i);
                    }
                }
                initiated = 1;
            }
        }
        template<typename T>
        void fft(T *in, point *out, int n) {

            for (int i = 1, j = 0; i < n; i++) {
                int bit = n >> 1;
                for (; j & bit; bit >>= 1)
                    j ^= bit;
                j ^= bit;

                if (i < j)
                    swap(in[i], in[j]);
            }

            for (int len = 2; len <= n; len <<= 1) {
                for (int i = 0; i < n; i += len) {
                    for (int j = 0; j < len / 2; j++) {
                        point u = in[i+j], v = in[i+j+len/2] * w[j  + len];
                        in[i+j] = u + v;
                        in[i+j+len/2] = u - v;
                    }
                }
            }

            for(int i= 0;i<n;i++)
                out[i] = in[i];

        }

        template<typename T>
        void id1(vector<T> &a, const vector<T> &b) {
            vector<T> res(a.size() + b.size() - 1);
            for(size_t i = 0; i < a.size(); i++) {
                for(size_t j = 0; j < b.size(); j++) {
                    res[i + j] += a[i] * b[j];
                }
            }
            a = res;
        }


        template<typename T>
        void mul(vector<T> &a, const vector<T> &b) {
            if(min(a.size(), b.size()) < magic) {
                id1(a, b);
                return;
            }
            init();
            static const int shift = 15, mask = (1 << shift) - 1;
            size_t n = a.size() + b.size() - 1;
            while(__builtin_popcount(n) != 1) {
                n++;
            }
            a.resize(n);
            static point* A = new point[maxn], *B = new point[maxn];
            static point* C = new point[maxn], *D = new point[maxn];
            for(size_t i = 0; i < n; i++) {
                A[i] = point(a[i] & mask, a[i] >> shift);
                if(i < b.size()) {
                    B[i] = point(b[i] & mask, b[i] >> shift);
                } else {
                    B[i] = 0;
                }
            }
            fft(A, C, n); fft(B, D, n);
            for(size_t i = 0; i < n; i++) {
                point c0 = C[i] + conj(C[(n - i) % n]);
                point c1 = C[i] - conj(C[(n - i) % n]);
                point d0 = D[i] + conj(D[(n - i) % n]);
                point d1 = D[i] - conj(D[(n - i) % n]);
                A[i] = c0 * d0 - point(0, 1) * c1 * d1;
                B[i] = c0 * d1 + d0 * c1;
            }
            fft(A, C, n); fft(B, D, n);
            reverse(C + 1, C + n);
            reverse(D + 1, D + n);
            int t =4*  n;
            for(size_t i = 0; i < n; i++) {
                int64_t A0 = llround(real(C[i]) / t);
                T A1 = llround(imag(D[i]) / t);
                T A2 = llround(imag(C[i]) / t);
                a[i] = A0 + (A1 << shift) + (A2 << 2 * shift);
            }
            return;
        }
    }
    template<typename T>
    T bpow(T x, size_t n) {
        return n ? n % 2 ? x * bpow(x, n - 1) : bpow(x * x, n / 2) : T(1);
    }
    template<typename T>
    T bpow(T x, size_t n, T m) {
        return n ? n % 2 ? x * bpow(x, n - 1, m) % m : bpow(x * x % m, n / 2, m) : T(1);
    }
    template<typename T>
    T gcd(const T &a, const T &b) {
        return b == T(0) ? a : gcd(b, a % b);
    }
    template<typename T>
    T nCr(T n, int r) { 

        T res(1);
        for(int i = 0; i < r; i++) {
            res *= (n - T(i));
            res /= (i + 1);
        }
        return res;
    }

    template<int m>
    struct modular {
        int64_t r;
        modular() : r(0) {}
        modular(int64_t rr) : r(rr) {if(abs(r) >= m) r %= m; if(r < 0) r += m;}
        modular inv() const {return bpow(*this, m - 2);}
        modular operator * (const modular &t) const {return (r * t.r) % m;}
        modular operator / (const modular &t) const {return *this * t.inv();}
        modular operator += (const modular &t) {r += t.r; if(r >= m) r -= m; return *this;}
        modular operator -= (const modular &t) {r -= t.r; if(r < 0) r += m; return *this;}
        modular operator + (const modular &t) const {return modular(*this) += t;}
        modular operator - (const modular &t) const {return modular(*this) -= t;}
        modular operator *= (const modular &t) {return *this = *this * t;}
        modular operator /= (const modular &t) {return *this = *this / t;}

        bool operator == (const modular &t) const {return r == t.r;}
        bool operator != (const modular &t) const {return r != t.r;}

        operator int64_t() const {return r;}
    };
    template<int T>
    istream& operator >> (istream &in, modular<T> &x) {
        return in >> x.r;
    }


    template<typename T>
    struct poly {
        vector<T> a;

        void normalize() { 

            while(!a.empty() && a.back() == T(0)) {
                a.pop_back();
            }
        }

        poly(){}
        poly(T a0) : a{a0}{normalize();}
        poly(vector<T> t) : a(t){normalize();}

        poly operator += (const poly &t) {
            a.resize(max(a.size(), t.a.size()));
            for(size_t i = 0; i < t.a.size(); i++) {
                a[i] += t.a[i];
            }
            normalize();
            return *this;
        }
        poly operator -= (const poly &t) {
            a.resize(max(a.size(), t.a.size()));
            for(size_t i = 0; i < t.a.size(); i++) {
                a[i] -= t.a[i];
            }
            normalize();
            return *this;
        }
        poly operator + (const poly &t) const {return poly(*this) += t;}
        poly operator - (const poly &t) const {return poly(*this) -= t;}

        poly mod_xk(size_t k) const { 

            k = min(k, a.size());
            return vector<T>(begin(a), begin(a) + k);
        }
        poly mul_xk(size_t k) const { 

            poly res(*this);
            res.a.insert(begin(res.a), k, 0);
            return res;
        }
        poly div_xk(size_t k) const { 

            k = min(k, a.size());
            return vector<T>(begin(a) + k, end(a));
        }
        poly substr(size_t l, size_t r) const { 

            l = min(l, a.size());
            r = min(r, a.size());
            return vector<T>(begin(a) + l, begin(a) + r);
        }
        poly inv(size_t n) const { 

            assert(!is_zero());
            poly ans = a[0].inv();
            size_t a = 1;
            while(a < n) {
                poly C = (ans * mod_xk(2 * a)).substr(a, 2 * a);
                ans -= (ans * C).mod_xk(a).mul_xk(a);
                a *= 2;
            }
            return ans.mod_xk(n);
        }

        poly operator *= (const poly &t) {fft::mul(a, t.a); normalize(); return *this;}
        poly operator * (const poly &t) const {return poly(*this) *= t;}

        poly reverse(size_t n, bool rev = 0) const { 

            poly res(*this);
            if(rev) { 

                res.a.resize(max(n, res.a.size()));
            }
            std::reverse(res.a.begin(), res.a.end());
            return res.mod_xk(n);
        }

        pair<poly, poly> divmod_slow(const poly &b) const { 

            vector<T> A(a);
            vector<T> res;
            while(A.size() >= b.a.size()) {
                res.push_back(A.back() / b.a.back());
                if(res.back() != T(0)) {
                    for(size_t i = 0; i < b.a.size(); i++) {
                        A[A.size() - i - 1] -= res.back() * b.a[b.a.size() - i - 1];
                    }
                }
                A.pop_back();
            }
            std::reverse(begin(res), end(res));
            return {res, A};
        }

        pair<poly, poly> divmod(const poly &b) const { 

            if(deg() < b.deg()) {
                return {poly{0}, *this};
            }
            int d = deg() - b.deg();
            if(min(d, b.deg()) < magic) {
                return divmod_slow(b);
            }
            poly D = (reverse(d + 1) * b.reverse(d + 1).inv(d + 1)).mod_xk(d + 1).reverse(d + 1, 1);
            return {D, *this - D * b};
        }

        poly operator / (const poly &t) const {return divmod(t).first;}
        poly operator % (const poly &t) const {return divmod(t).second;}
        poly operator /= (const poly &t) {return *this = divmod(t).first;}
        poly operator %= (const poly &t) {return *this = divmod(t).second;}
        poly operator *= (const T &x) {
            for(auto &it: a) {
                it *= x;
            }
            normalize();
            return *this;
        }
        poly operator /= (const T &x) {
            for(auto &it: a) {
                it /= x;
            }
            normalize();
            return *this;
        }
        poly operator * (const T &x) const {return poly(*this) *= x;}
        poly operator / (const T &x) const {return poly(*this) /= x;}

        void print() const {
            for(auto it: a) {
                cout << it << ' ';
            }
            cout << endl;
        }
        T eval(T x) const { 

            T res(0);
            for(int i = int(a.size()) - 1; i >= 0; i--) {
                res *= x;
                res += a[i];
            }
            return res;
        }

        T& lead() { 

            return a.back();
        }
        int deg() const { 

            return a.empty() ? -inf : a.size() - 1;
        }
        bool is_zero() const { 

            return a.empty();
        }
        T operator [](int idx) const {
            return idx >= (int)a.size() || idx < 0 ? T(0) : a[idx];
        }

        T& coef(size_t idx) { 

            return a[idx];
        }
        bool operator == (const poly &t) const {return a == t.a;}
        bool operator != (const poly &t) const {return a != t.a;}

        poly deriv() { 

            vector<T> res;
            for(int i = 1; i <= deg(); i++) {
                res.push_back(T(i) * a[i]);
            }
            return res;
        }
        poly integr() { 

            vector<T> res = {0};
            for(int i = 0; i <= deg(); i++) {
                res.push_back(a[i] / T(i + 1));
            }
            return res;
        }
        size_t leading_xk() const { 

            if(is_zero()) {
                return inf;
            }
            int res = 0;
            while(a[res] == T(0)) {
                res++;
            }
            return res;
        }
        poly log(size_t n) { 

            assert(a[0] == T(1));
            return (deriv().mod_xk(n) * inv(n)).integr().mod_xk(n);
        }
        poly exp(size_t n) { 

            if(is_zero()) {
                return T(1);
            }
            assert(a[0] == T(0));
            poly ans = T(1);
            size_t a = 1;
            while(a < n) {
                poly C = ans.log(2 * a).div_xk(a) - substr(a, 2 * a);
                ans -= (ans * C).mod_xk(a).mul_xk(a);
                a *= 2;
            }
            return ans.mod_xk(n);

        }

        poly pow_slow(size_t k, size_t n) { 

            return k ? k % 2 ? (*this * pow_slow(k - 1, n)).mod_xk(n) : (*this * *this).mod_xk(n).pow_slow(k / 2, n) : T(1);
        }
        poly pow(size_t k, size_t n) { 

            if(is_zero()) {
                return *this;
            }
            if(k < magic) {
                return pow_slow(k, n);
            }
            int i = leading_xk();
            T j = a[i];
            poly t = div_xk(i) / j;
            return bpow(j, k) * (t.log(n) * T(k)).exp(n).mul_xk(i * k).mod_xk(n);
        }
        poly mulx(T x) { 

            T cur = 1;
            poly res(*this);
            for(int i = 0; i <= deg(); i++) {
                res.coef(i) *= cur;
                cur *= x;
            }
            return res;
        }
        poly mulx_sq(T x) { 

            T cur = x;
            T total = 1;
            T xx = x * x;
            poly res(*this);
            for(int i = 0; i <= deg(); i++) {
                res.coef(i) *= total;
                total *= cur;
                cur *= xx;
            }
            return res;
        }
        vector<T> chirpz_even(T z, int n) { 

            int m = deg();
            if(is_zero()) {
                return vector<T>(n, 0);
            }
            vector<T> vv(m + n);
            T zi = z.inv();
            T zz = zi * zi;
            T cur = zi;
            T total = 1;
            for(int i = 0; i <= max(n - 1, m); i++) {
                if(i <= m) {vv[m - i] = total;}
                if(i < n) {vv[m + i] = total;}
                total *= cur;
                cur *= zz;
            }
            poly w = (mulx_sq(z) * vv).substr(m, m + n).mulx_sq(z);
            vector<T> res(n);
            for(int i = 0; i < n; i++) {
                res[i] = w[i];
            }
            return res;
        }
        vector<T> chirpz(T z, int n) { 

            auto even = chirpz_even(z, (n + 1) / 2);
            auto odd = mulx(z).chirpz_even(z, n / 2);
            vector<T> ans(n);
            for(int i = 0; i < n / 2; i++) {
                ans[2 * i] = even[i];
                ans[2 * i + 1] = odd[i];
            }
            if(n % 2 == 1) {
                ans[n - 1] = even.back();
            }
            return ans;
        }
        template<typename iter>
        vector<T> eval(vector<poly> &tree, int v, iter l, iter r) { 

            if(r - l == 1) {
                return {eval(*l)};
            } else {
                auto m = l + (r - l) / 2;
                auto A = (*this % tree[2 * v]).eval(tree, 2 * v, l, m);
                auto B = (*this % tree[2 * v + 1]).eval(tree, 2 * v + 1, m, r);
                A.insert(end(A), begin(B), end(B));
                return A;
            }
        }
        vector<T> eval(vector<T> x) { 

            int n = x.size();
            if(is_zero()) {
                return vector<T>(n, T(0));
            }
            vector<poly> tree(4 * n);
            build(tree, 1, begin(x), end(x));
            return eval(tree, 1, begin(x), end(x));
        }
        template<typename iter>
        poly inter(vector<poly> &tree, int v, iter l, iter r, iter ly, iter ry) { 

            if(r - l == 1) {
                return {*ly / a[0]};
            } else {
                auto m = l + (r - l) / 2;
                auto my = ly + (ry - ly) / 2;
                auto A = (*this % tree[2 * v]).inter(tree, 2 * v, l, m, ly, my);
                auto B = (*this % tree[2 * v + 1]).inter(tree, 2 * v + 1, m, r, my, ry);
                return A * tree[2 * v + 1] + B * tree[2 * v];
            }
        }
    };
    template<typename T>
    poly<T> operator * (const T& a, const poly<T>& b) {
        return b * a;
    }

    template<typename T>
    poly<T> xk(int k) { 

        return poly<T>{1}.mul_xk(k);
    }

    template<typename T>
    T resultant(poly<T> a, poly<T> b) { 

        if(b.is_zero()) {
            return 0;
        } else if(b.deg() == 0) {
            return bpow(b.lead(), a.deg());
        } else {
            int pw = a.deg();
            a %= b;
            pw -= a.deg();
            T mul = bpow(b.lead(), pw) * T((b.deg() & a.deg() & 1) ? -1 : 1);
            T ans = resultant(b, a);
            return ans * mul;
        }
    }
    template<typename iter>
    poly<typename iter::value_type> kmul(iter L, iter R) { 

        if(R - L == 1) {
            return vector<typename iter::value_type>{-*L, 1};
        } else {
            iter M = L + (R - L) / 2;
            return kmul(L, M) * kmul(M, R);
        }
    }
    template<typename T, typename iter>
    poly<T> build(vector<poly<T>> &res, int v, iter L, iter R) { 

        if(R - L == 1) {
            return res[v] = vector<T>{-*L, 1};
        } else {
            iter M = L + (R - L) / 2;
            return res[v] = build(res, 2 * v, L, M) * build(res, 2 * v + 1, M, R);
        }
    }
    template<typename T>
    poly<T> inter(vector<T> x, vector<T> y) { 

        int n = x.size();
        vector<poly<T>> tree(4 * n);
        return build(tree, 1, begin(x), end(x)).deriv().inter(tree, 1, begin(x), end(x), begin(y), end(y));
    }
};

using namespace algebra;

typedef modular<mod> base;
typedef poly<base> polyn;

using namespace algebra;




      



template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}

template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;

  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }

  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }

  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }

  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(signed) { Modular result(*this); *this += 1; return result; }
  Modular operator--(signed) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }

  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {

    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
    asm(
      "divl %4; \n\t"
      : "=a" (d), "=d" (m)
      : "d" (xh), "a" (xl), "r" (mod())
    );
    value = m;

    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));

    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
    int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }

  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

  template <typename U>
  friend const Modular<U>& abs(const Modular<U>& v) { return v; }

  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename U>
  friend std::istream& operator>>(std::istream& stream, Modular<U>& number);

 private:
  Type value;
};

template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }

template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}

template <typename T>
bool IsZero(const Modular<T>& number) {
  return number() == 0;
}

template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
  return stream << number();
}

template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, int64_t>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}



constexpr int md = mod;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

Mint pwr(Mint a, int k) {
    Mint ans = 1;
    while(k) {
        if(k & 1) ans = ans * a;
        a = a * a;
        k >>= 1;
    }
    return ans;
}




const int MAXN=4e6+10;
vector<Mint> fac(MAXN);
vector<Mint> infac(MAXN);
void id0()
{
    fac[0]=1;
    infac[0]=1;
    for(int i=1;i<MAXN;i++)
    {
        fac[i]=(fac[i-1]*i);
        infac[i]=infac[i-1]/i;
    }
}
Mint ncr(int n, int r)
{
    if(n<r)
        return 0;
    return 1LL*fac[n] * infac[r]  * infac[n-r];
}




void solv()
{
    id0();

    int n;
    cin>>n;


    v<Mint> d(3 *n + 10 );

    Mint one  = 1;
    d[0] = one ;
    d[1] = -1 * one;
    int sgn = 1;
    for(int i = 2;i<=3*n + 1;i+=6)
    {
        d[i] = 2 * sgn;
        sgn *=-1;

        d[i+1] = -1;
        d[i+2] = 1;
        d[i+4] = -1;
        d[i+5] = 1;
    }
    Mint div = 1;

    div/=3;
    Mint prod = div;

    for(int i = 0;i<=3*n+1;i++)
    {
        if(i%2 == 0 && i)

            prod*=div;
        d[i] *= prod;
    }

    Mint mult = 3;
    prod = 1;

    v<Mint> compute(3*n + 2);
    for(int i= 1;i<=3*n + 1;i++){
        if(i%2 == 0 && i)
            prod *= mult;

        compute[i] = ncr(3*(n+1), i) * prod;

        if(i>=12)
            compute[i] += compute[i-12];

    }
    prod  = 1;

    v<Mint> compute2(3*n + 2);
    for(int i= 1;i<=3*n + 1;i++){
        if(i%2 == 1)
            prod *= mult;
        compute2[i] = ncr(3*(n+1), i) * prod;

        if(i>=12)
            compute2[i] += compute2[i-12];

    }

    v<Mint> terms = {1, -1, 2, -1, 1, 0, -1, 1, -2, 1, -1, 0 };

    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        x++;
        Mint sm = 0;

        for(int j= 0;j<12;j++)
        {
            if(x>=j)
            {
                if(x%2 == 0)
                    sm += terms[j] * compute2[x -j ] ;
                else
                {
                    sm += terms[j] * compute[ x- j];
                }

            }


        }
        sm/=pwr(3, x/2 + 1);



        cout<<sm  <<endl;
    }
}

void solve()
{

    

    int t = 1;
    

    for(int T  =1;T<=t;T++)
    {
        solv();
    }



}



signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cerr.tie(NULL);


    if (fopen("INPUT.txt", "r"))
    {
        freopen("INPUT.txt", "r", stdin);
        freopen("OUTPUT.txt", "w", stdout);

    }

    
    namespace fs = std::filesystem;
    std::string path = "./";
    string filename;
    for (const auto & entry : fs::directory_iterator(path)){
        if( entry.path().extension().string() == ".in"){
            filename = entry.path().filename().stem().string();
        }
    }
    if(filename != ""){
        string input_file = filename +".in";
        string output_file = filename +".out";
        if (fopen(input_file.c_str(), "r"))
        {
            freopen(input_file.c_str(), "r", stdin);
            freopen(output_file.c_str(), "w", stdout);
        }
    }
    

    auto clk = clock();
    


    signed t = 1;
    


    for (signed test = 1; test <= t; test++)
    {
        

        


        solve();
    }

    


    clk = clock() - clk;

    
    cerr << fixed << setprecision(6) << "\nTime: " << ((float)clk) / CLOCKS_PER_SEC << "\n";
    
    return 0;
}
