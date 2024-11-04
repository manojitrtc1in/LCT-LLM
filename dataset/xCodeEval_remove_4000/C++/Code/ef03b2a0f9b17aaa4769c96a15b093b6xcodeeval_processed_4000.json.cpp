






using namespace std;






using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;






















bool id0;

const int mod = 1e9 + 7;









const int INF=2e9+10;



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

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;


typedef pair<int, int> pii;

template <typename T1, typename T2>
bool id3(pair<T1, T2> a, pair<T1, T2> b)
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





template<typename T>
T power(T a, int b, int in_mod)
{

    T prod = mult_identity(a);
    T mult = a ;
    

    while (b != 0)
    {
        if (b % 2)
        {
            prod = multiply(prod, mult, in_mod);
        }
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




const int MAXN=4e5+100;
vector<int> fac(MAXN);
vector<int> infac(MAXN);
void id1()
{
    fac[0]=1;
    infac[0]=1;
    for(int i=1;i<MAXN;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
        infac[i]=mod_inv(fac[i], mod);
    }
}

int t[4*MAXN];

int query(int v, int tl, int tr, int l, int r, int x) {
    if (l > r)
        return -INF;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    int t1 = query(v*2, tl, tm, l, min(r, tm), x);
    int t2 = query(v*2+1, tm+1, tr, max(l, tm+1), r, x);
    return max(t1, t2);
}

void update(int v, int tl, int tr, int val, int pos)
{

    t[v] = max(t[v], val);

    if( tl == tr)
    {
        return ;
    }

    int tm = tl + tr>>1;
    if( tm>=pos)
        update(2*v, tl, tm, val, pos);
    else update(2*v + 1, tm+1, tr, val, pos);


}

void solve()
{
    int n;
    cin>>n;
    readv(a,n);
    readv(b,n);

    set<int> header;
    for(auto i:a)
        header.insert(i);

    for(auto i:b)
        header.insert(i);

    vector<int> tt;
    for(auto i:header)
        tt.pb(i);

    sort(all(tt));


    map<int, int> mp;
    map<int, int> rmp;

    for(int i= 0;i<tt.size();i++)
    {
        mp[tt[i]] = i;
        rmp[i] = tt[i];
    }

    for(auto &i:a)
    {
        i = mp[i];

    }
    for(auto &i:b)
        i = mp[i];

    v<pair<int, int>> lubba;
    for(int i= 0;i<n;i++)
        lubba.pb({a[i], b[i]});


    sort(all(lubba));

    int offset = 0;

    for(int i= 0;i<n;i++)
    {
        int a = lubba[i].fi;
        int b= lubba[i].se;

        if(a<= b)
        {
            update(1, 0, 2*n, b, a);
            continue;

        }

        int best_case = query(1, 0, 2*n, 0, b, a);

        int hold = (rmp[a] - rmp[b]);
        if(best_case!=-INF)
            offset = max(offset, min(rmp[best_case] -rmp[b], hold));

        int id2 = query(1, 0, 2*n, 0, b, INF);

        if(id2!=-INF && id2>=a)
            offset = max(offset, rmp[a] - rmp[b]);


    }

    for(auto &i: ::t)
        i = -INF;

    v<pair<int, int>> t;
    for(auto i:lubba)
        t.pb({i.se, i.fi});

    sort(all(t));

 

    swap(lubba,t);


    for(int i= 0;i<n;i++)
    {
        int a = lubba[i].fi;
        int b= lubba[i].se;
        if(a<= b)
        {
            update(1, 0, 2*n, b, a);
            continue;

        }

        int best_case = query(1, 0, 2*n, 0, b, a);

        int hold = (rmp[a] - rmp[b]);
        if(best_case!=-INF)
            offset = max(offset, min(rmp[best_case] -rmp[b], hold));

        int id2 = query(1, 0, 2*n, 0, b, INF);

        if(id2!=-INF && id2 >=a)
            offset = max(offset, rmp[a] - rmp[b]);


    }
    long long  sm = 0;
    for(int i= 0;i<n;i++)
    {
        sm += abs(rmp[a[i]] - rmp[b[i]]);

    }
    cout<<sm - 2*offset<<endl;


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
        for (const auto & entry : fs::directory_iterator(path))
        {
            if( entry.path().extension().string() == ".in")
            {
                filename = entry.path().filename().stem().string();

            }

        }
        if(filename != "")
        {

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
