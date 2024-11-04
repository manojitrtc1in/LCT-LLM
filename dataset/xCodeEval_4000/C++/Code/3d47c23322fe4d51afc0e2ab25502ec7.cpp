





#include <quadmath.h>
#include <functional>
#include <type_traits>
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;






#define int long long

#define all(X) (X).begin(), (X).end()

#define pb push_back
#define endl '\n'
#define fi first
#define se second



const int mod = 1e9 + 7;





const long long INF = 2e18 + 10;



#define readv(x, n)   \
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
typedef vector<vector<double>> vvd;


typedef pair<int, int> pii;

template <typename T1, typename T2>
bool sort_by_sec(pair<T1, T2> a, pair<T1, T2> b)
{
    return make_pair(a.se, a.fi) < make_pair(b.se, b.fi);
}

int multiply(int a, int b, int in_mod) { return (int)(1LL * a * b % in_mod); }


int mult_identity(int a) { return 1; }



template<typename T>
array<T, 2> multiply(const array<T, 2> &a, const array<T, 2> &b, int mod);
template<typename T>
array<T, 2> mult_identity(array<T, 2> a) { return {1}; }

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
            }
        }
    }
    return result;
}
vector<vector<int>> operator%(vector<vector<int>> a, int in_mod)
{
    for(auto &i:a)
        for(auto &j:i)
            j%=in_mod;
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

vector<int> mat_vector_product(vector<vector<int>> a, vector<int> b, int in_mod)
{
    int n =a.size();

    vector<int> output(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            output[i]+=a[i][j]*b[j];
            output[i]%=in_mod;
        }
    }
    return output;
}




auto power(int a, auto b, int in_mod)
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
#define stp cout << fixed << setprecision(20);



#ifdef int
      #undef int
#endif


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
#ifdef _WIN32
    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
    asm(
      "divl %4; \n\t"
      : "=a" (d), "=d" (m)
      : "d" (xh), "a" (xl), "r" (mod())
    );
    value = m;
#else
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
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

#define int long long

vvi tables;

void generate(int n, auto c, vi table)
{
    if( n== 0)
    {
        tables.pb(table);
        return;
    }

    for(int j= 0;j<=c[n-1];j++)
    {
        vi nt = table;
        nt.pb(j);
        generate(n-1, c, nt);
    }


}


double val(int n, auto a, auto b)
{
    v<double> aa(a.begin(), a.end());
    const int maxt = 10000000;
    for(int t = 0; t<=maxt;t++)
    {
        int i= rng()%(n-1);

        double ta = aa[i];
        double tb = aa[i+1];
        aa[i] = min(ta, (ta + tb - b[i])/2);
        aa[i + 1] = max(tb, (ta + tb + b[i])/2);


    }
    cout<<aa<<endl;
    cout<<b<<endl;
    cout<<flush;
    return aa[0];
}

void brute(int n, auto c, auto b, int x)
{
    generate(n, c);

    b.insert(b.begin(),0);



    for(int i= 1;i<n;i++)
        b[i] += b[i-1];
    int cnt = 0;
    for(auto t:tables)
    {
        double mn = INF;

        for(int i = 0;i<n;i++)
        {
            

        }




    }
}
const int maxn = 1000000;

void solve(int n, auto c, auto b, int x)
{


    b.insert(b.begin(),0);
    for(int i= 1;i<n;i++)
        b[i] += b[i-1];



    v<Mint> dp(2*maxn, 0);
    v<Mint> pref(2*maxn, 1);

    dp[0] = 1;

    Mint ans = 0;

    for(int i= 0;i<n;i++){
        for(int j =0;j<2*maxn;j++)
        {
            


            int last = j - (c[i]-x - b[i]);

            int end =  j - (-x - b[i]);


            if( end <2*maxn && last <2*maxn)
            {
                dp[j] = ((end>=0  )?pref[end]:0)  - ((last>0)?pref[last-1]:0);
            }



        }

        Mint hold = 0;
        for(int i= maxn;i<2*maxn;i++)
        {
            hold += dp[i];
            dp[i] = 0;
        }
        for(int k= i+1;k<n;k++)
            hold *= c[k] + 1;

        ans += hold;



        pref[0] = dp[0];
        for(int j = 1;j<2*maxn;j++)
        {
            pref[j] = pref[j-1] + dp[j];
        }
        fill(all(dp),0);
    }

        ans += pref[2*maxn-1];
    cout<<ans<<endl;
}


v<int> gen(int n)
{
    v<int> t;
    for(int i= 0;i<n;i++)
    {
        t.pb(rng()%100);
    }
    return t;
}
void test()
{
    int n;
    n = rng()% 100 + 1;
    auto a = gen(n);
    auto b= gen(n-1);
    n = 3;
    a = {0, 100, 300};
    b = {20, 1};
    double t = val(n, a, b);

    double mn = INF;
    b.insert(b.begin(),0);
    for(int i= 1;i<n;i++)
    {
        b[i] += b[i-1];
    }

    for(int i= 1;i<n;i++)
    {
        b[i] += b[i-1];
    }

    for(int i = 0;i<n;i++)
    {
        if(i)
        a[i] += a[i-1];
        mn = min(mn, (a[i] - b[i]) * 1.0 /(i+1));

    }
    stp;
    cout<<n<<endl;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<t<<endl;
    cout<<mn<<endl;
    cout<<flush;
    assert(abs(t-mn) < 1e-6);

}

void comp()
{
    int n= 100;
    vi c(100, 100);
    vi b(99,100);
    vi x{-4949};

    for(auto j:x)
        solve(n, c, b, j);
    exit(0);
}
void solve()
{
    


    

    int n;
    cin>>n;
    readv(c,n);
    readv(b,n-1);
    int q;
    cin>>q;

    readv(x,q);


    for(auto j:x)
        solve(n, c, b, j);
}





signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cerr.tie(NULL);

#ifndef ONLINE_JUDGE
    if (fopen("INPUT.txt", "r"))
    {
        freopen("INPUT.txt", "r", stdin);
        freopen("OUTPUT.txt", "w", stdout);

        

    }
#else
    #ifdef ASC
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
    #endif
#endif
    auto clk = clock();
    


    signed t = 1;
    


    for (signed test = 1; test <= t; test++)
    {
        

        


        solve();
    }

    


    clk = clock() - clk;

    #ifndef ONLINE_JUDGE
    cerr << fixed << setprecision(6) << "\nTime: " << ((float)clk) / CLOCKS_PER_SEC << "\n";
    #endif
    return 0;
}
