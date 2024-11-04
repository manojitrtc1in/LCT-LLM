#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <random>
#include <set>
#include <queue>

#ifdef TEPAMID
#define debug(x) cerr << #x << " = " << x << endl;
#define debug_p(x)                                    \
    {                                                 \
        auto [a, b] = x;                              \
        cerr << #x << " = " << a << "," << b << endl; \
    }
#define debug_v(v)            \
    {                         \
        cerr << #v << " = ";  \
        for (auto x : v)      \
            cerr << x << " "; \
        cerr << endl;         \
    }
#define debug_vp(v)                       \
    {                                     \
        cerr << #v << " = ";              \
        for (auto [x, y] : v)             \
            cerr << x << "," << y << " "; \
        cerr << endl;                     \
    }
#else
#define debug(x) 0;
#define debug_v(x) 0;
#define debug_p(x) 0;
#define debug_vp(x) 0;
#endif 


using namespace std;






#define fo(i, n) for (int i = 0; i < n; ++i)
#define foback(i, n) for (int i = n - 1; i >= 0; --i)
#define fo1(i, n) for (ll i = 1; i <= n; ++i)

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define makeunique(x) sort(all(x)), (x).resize(unique(all(x)) - (x).begin())

typedef long long ll;

void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void one();

int main()
{
    fastio();

    int t = 1;
    cin >> t;
    fo1(TEST, t)
    {
        debug(TEST)
        one();
    }

    return 0;
}






#include <cassert>
template <typename T>
T inverse(T a, T m)
{
    T u = 0, v = 1;
    while (a != 0)
    {
        T t = m / a;
        m -= t * a;
        swap(a, m);
        u -= t * v;
        swap(u, v);
    }
    assert(m == 1);
    return u;
}

template <typename T>
class Modular
{
public:
    using Type = typename decay<decltype(T::value)>::type;

    constexpr Modular() : value() {}
    template <typename U>
    Modular(const U &x)
    {
        value = normalize(x);
    }

    template <typename U>
    static Type normalize(const U &x)
    {
        Type v;
        if (-mod() <= x && x < mod())
            v = static_cast<Type>(x);
        else
            v = static_cast<Type>(x % mod());
        if (v < 0)
            v += mod();
        return v;
    }

    const Type &operator()() const { return value; }
    template <typename U>
    explicit operator U() const { return static_cast<U>(value); }
    constexpr static Type mod() { return T::value; }

    Modular &operator+=(const Modular &other)
    {
        if ((value += other.value) >= mod())
            value -= mod();
        return *this;
    }
    Modular &operator-=(const Modular &other)
    {
        if ((value -= other.value) < 0)
            value += mod();
        return *this;
    }
    template <typename U>
    Modular &operator+=(const U &other) { return *this += Modular(other); }
    template <typename U>
    Modular &operator-=(const U &other) { return *this -= Modular(other); }
    Modular &operator++() { return *this += 1; }
    Modular &operator--() { return *this -= 1; }
    Modular operator++(int)
    {
        Modular result(*this);
        *this += 1;
        return result;
    }
    Modular operator--(int)
    {
        Modular result(*this);
        *this -= 1;
        return result;
    }
    Modular operator-() const { return Modular(-value); }

    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type &operator*=(const Modular &rhs)
    {
#ifdef _WIN32
        uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
        uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
        asm(
            "divl %4; \n\t"
            : "=a"(d), "=d"(m)
            : "d"(xh), "a"(xl), "r"(mod()));
        value = m;
#else
        value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
        return *this;
    }
    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, long long>::value, Modular>::type &operator*=(const Modular &rhs)
    {
        long long q = static_cast<long long>(static_cast<long double>(value) * rhs.value / mod());
        value = normalize(value * rhs.value - q * mod());
        return *this;
    }
    template <typename U = T>
    typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type &operator*=(const Modular &rhs)
    {
        value = normalize(value * rhs.value);
        return *this;
    }

    Modular &operator/=(const Modular &other) { return *this *= Modular(inverse(other.value, mod())); }

    friend const Type &abs(const Modular &x) { return x.value; }

    template <typename U>
    friend bool operator==(const Modular<U> &lhs, const Modular<U> &rhs);

    template <typename U>
    friend bool operator<(const Modular<U> &lhs, const Modular<U> &rhs);

    template <typename V, typename U>
    friend V &operator>>(V &stream, Modular<U> &number);

private:
    Type value;
};

template <typename T>
bool operator==(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value == rhs.value; }
template <typename T, typename U>
bool operator==(const Modular<T> &lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U>
bool operator==(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) == rhs; }

template <typename T>
bool operator!=(const Modular<T> &lhs, const Modular<T> &rhs) { return !(lhs == rhs); }
template <typename T, typename U>
bool operator!=(const Modular<T> &lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U>
bool operator!=(U lhs, const Modular<T> &rhs) { return !(lhs == rhs); }

template <typename T>
bool operator<(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value < rhs.value; }

template <typename T>
Modular<T> operator+(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U>
Modular<T> operator+(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U>
Modular<T> operator+(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }

template <typename T>
Modular<T> operator-(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U>
Modular<T> operator-(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U>
Modular<T> operator-(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T>
Modular<T> operator*(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U>
Modular<T> operator*(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U>
Modular<T> operator*(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T>
Modular<T> operator/(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U>
Modular<T> operator/(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U>
Modular<T> operator/(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }

template <typename T, typename U>
Modular<T> power(const Modular<T> &a, const U &b)
{
    assert(b >= 0);
    Modular<T> x = a, res = 1;
    U p = b;
    while (p > 0)
    {
        if (p & 1)
            res *= x;
        x *= x;
        p >>= 1;
    }
    return res;
}

template <typename T>
bool IsZero(const Modular<T> &number)
{
    return number() == 0;
}

template <typename T>
string to_string(const Modular<T> &number)
{
    return to_string(number());
}



template <typename U, typename T>
U &operator<<(U &stream, const Modular<T> &number)
{
    return stream << number();
}



template <typename U, typename T>
U &operator>>(U &stream, Modular<T> &number)
{
    typename common_type<typename Modular<T>::Type, long long>::type x;
    stream >> x;
    number.value = Modular<T>::normalize(x);
    return stream;
}



constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md> >;

vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);

void fillUpTo(int n) {
    while ((int)fact.size() < n + 1)
    {
        fact.push_back(fact.back() * (int)fact.size());
        inv_fact.push_back(1 / fact.back());
    }
}

Mint C(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }

    fillUpTo(n);
   
    return fact[n] * inv_fact[k] * inv_fact[n - k];
}

Mint multiC(const vector<int>& a) {
    int n = 0;
    for(auto x : a) n+=x;

    fillUpTo(n);

    auto cur = C(n,0) * fact[n];
    for(auto x : a) cur *= inv_fact[x];
    return cur;
}

void factorize(ll z, vector<ll>& factors) {
    for(ll x=2; x*x <= z; x++) {
        if (z % x == 0) {
            factors.push_back(x);
        }

        while (z % x == 0) {
            

            z/=x;
        }
    }
    
    if (z > 1) {
        factors.push_back(z);
        

    }
}


void one1()
{
    int n; cin >> n;
    ll m; cin>>m;

    vector<ll> g(n);
    fo(i,n) {
        cin>>g[i];
    }

    Mint dp = 1; 



    for(int i=1; i<n; i++) {
        debug(g[i])

        ll cnt=0;

        for(ll x=1; x<=m; x++) {
            

            if ( gcd(x, g[i-1]) == g[i]) {
                debug(x)
                cnt++;
            }
        }

        debug(cnt)

        dp *= cnt;
    }

    cout << dp << endl;
}

void one()
{
    int n;
    cin >> n;

    ll m; cin>>m;

    vector<ll> g(n);
    fo(i,n) {
        cin>>g[i];
    }

    

    

    

    

    


    

    

    

    

    

    

    


    Mint dp = 1; 


    for(int i=1; i<n; i++) {
        debug(g[i])
        


        

        

        

        

        

        

        


        

        

        

        

        

        {
            ll cntDivisible = m / g[i];

            

            

            

            {
                if (g[i-1] % g[i] > 0) {
                    cout << 0 << "\n";
                    return;
                }

                

                

                

                


                ll remg = (g[i-1] / g[i]);
                vector<ll> factors;
                factorize(remg, factors);
                int fn = factors.size();

                

                debug_v(factors)

                ll cur = cntDivisible; 

                for(int i1=0; i1<fn; i1++) {
                    cur -= cntDivisible / factors[i1];

                     for(int i2=i1+1; i2<fn; i2++) {
                        cur += cntDivisible / (factors[i1] * factors[i2]);

                        for(int i3=i2+1; i3<fn; i3++) {
                            cur -= cntDivisible / (factors[i1] * factors[i2] * factors[i3]);

                            for(int i4=i3+1; i4<fn; i4++) {
                                cur += cntDivisible / (factors[i1] * factors[i2] * factors[i3]* factors[i4]);

                                for(int i5=i4+1; i5<fn; i5++) {
                                    cur -= cntDivisible / (factors[i1] * factors[i2] * factors[i3]*factors[i4]*factors[i5]);

                                    for(int i6=i5+1; i6<fn; i6++) {
                                        cur += cntDivisible / (factors[i1] * factors[i2] * factors[i3]*factors[i4]*factors[i5]*factors[i6]);

                                        for(int i7=i6+1; i7<fn; i7++) {
                                            cur -= cntDivisible / (factors[i1] * factors[i2] * factors[i3]*factors[i4]*factors[i5]*factors[i6]*factors[i7]);

                                            for(int i8=i7+1; i8<fn; i8++) {
                                                cur += cntDivisible / (factors[i1] * factors[i2] * factors[i3]*factors[i4]*factors[i5]*factors[i6]*factors[i7]*factors[i8]);

                                                for(int i9=i8+1; i9<fn; i9++) {
                                                    cur -= cntDivisible / (factors[i1] * factors[i2] * factors[i3]*factors[i4]*factors[i5]*factors[i6]*factors[i7]*factors[i8]*factors[i9]);

                                                    for(int iA=i9+1; iA<fn; iA++) {
                                                        cur += cntDivisible / (factors[i1] * factors[i2] * factors[i3]*factors[i4]*factors[i5]*factors[i6]*factors[i7]*factors[i8]*factors[i9]*factors[iA]);

                                                        for(int iB=iA+1; iB<fn; iB++) {
                                                            cur -= cntDivisible / (factors[i1] * factors[i2] * factors[i3]*factors[i4]*factors[i5]*factors[i6]*factors[i7]*factors[i8]*factors[i9]*factors[iA]*factors[iB]);

                                                            for(int iC=iB+1; iC<fn; iC++) {
                                                                exit(1);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                

                

                

                

                

            
                

                

                

                

                

                

                

            

                

                


                

                dp *= cur;
                debug(dp)
            }
        }
    }

    

    

    

    

    

    


    

    

    

    


    

    

    

    

    


    


    cout << dp << "\n";
}



















