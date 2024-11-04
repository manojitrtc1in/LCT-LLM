



 
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 





 
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
  Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
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
  typename enable_if<is_same<typename Modular<U>::Type, long long>::value, Modular>::type& operator*=(const Modular& rhs) {
    long long q = static_cast<long long>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }
 
  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }
 
  friend const Type& abs(const Modular& x) { return x.value; }
 
  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
 
  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
 
  template <typename V, typename U>
  friend V& operator>>(V& stream, Modular<U>& number);
 
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
 


template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
  return stream << number();
}
 


template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, long long>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}
 

 
constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
 

 
template<typename T> void _print(T x){cerr << x << " ";}
template<typename T1,typename T2> void _print(pair<T1,T2> x){cerr << "{ ";_print(x.first);cerr << ", "; _print(x.second);cerr << "} ";}
template<typename T> void _print(vector<T>&v){cerr << "[ ";for(auto  x:v)_print(x);cerr << "]\n";}
template<typename T>void _print(vector<vector<T>>&v){cerr << "\n{\n";for(auto x:v){cerr << " ";_print(x);}cerr << "}";}
template<typename T> void _print(set<T>&s){cerr << "[ ";for(auto  x:s)_print(x);cerr << "]\n";}
template<typename T> void _print(unordered_set<T>&s){cerr << "[ ";for(auto  x:s)_print(x);cerr << "]\n";}
template<typename T1,typename T2> void _print(map<T1,T2>&s){cerr << "\n[\n";for(auto  x:s){cerr << " ";_print(x.first);cerr << ": ";_print(x.second);cerr << "\n";}cerr << "]\n";}
template<typename T1,typename T2> void _print(unordered_map<T1,T2>&s){cerr << "\n[\n";for(auto  x:s){cerr << " ";_print(x.first);cerr << ": ";_print(x.second);cerr << "\n";}cerr << "]\n";}
 



























int mpow(int base, int exp);
 class naruto{
public:
int N = 1e5+5;
vector<int>tree;
vector<int>arr;
void build(int node,int l,int r)
{
    if(l==r){tree[node]=arr[l];return;}
    int mid = (l+r)/2;
    build(2*node,l,mid);
    build(2*node +1,mid+1,r);
    tree[node] = min(tree[2*node],tree[2*node+1]);
}
 
void update(int node,int l, int r,int idx,int val)
{
    if(l==r){tree[node] = val; return;}
    int mid = (l+r)/2;
    if(idx<=mid)
    update(2*node,l,mid,idx,val);
    else
    update(2*node+1,mid+1,r,idx,val);
    tree[node] = min(tree[2*node],tree[2*node+1]);
}
int query(int node,int l,int r,int left,int right)
{
    if(left<=l and right>=r)return tree[node];
    else if(l>r or left>r or right<l)return INT_MAX;
    int mid = (l+r)/2;
    return min(query(2*node,l,mid,left,right)
    ,query(2*node+1,mid+1,r,left,right));
 
}
 
void solve()
{
    int n = 1e3+5;
    arr.resize(N);
    int m = 1e3+5;
    tree.resize(4*N);
    for(int i=1;i<=n;i++)arr[i]=i;
        build(1,1,n);
    while(m--){
        int a = rand()%10000;
            int b=1+rand()%(n-1);
        int c = a;
            update(1,1,n,b+1,c);
    }
    

}
};
 
class sasuke
{
public:
   int v[1000001];
  void debugg(int flag)
  {
    if(!flag)cout<<"NO";
    else cout<<"YES";
  }
  int check(int mid,int k,int x)
  {
    int ans = 0;
    mid-=1;
    if(mid<=k)
    {
      ans = ((mid*(mid+1))/2);
    }
    else
    {
      ans = ((k*(k+1))/2);
      mid = (2*k-1 -mid);
      ans+=(k*(k-1)/2 - ((mid*(mid+1)))/2);
    }
    if(x>ans)return 1;
    else return 0;
  }
  void solve()
  {
   int n; cin >> n;
   vector<int>v(n);
   for(auto&it:v)cin >> it;
    vector<int>red,blue;
  string s; cin >> s;
   for(int i=0;i<n;i++)
   {
    if(s[i]=='R')red.push_back(v[i]);
    else blue.push_back(v[i]);
   }
   if(red.size())
   sort(red.rbegin(),red.rend());
   if(blue.size())
   sort(blue.begin(), blue.end());
   int flag = 1;
   for(int i=0;i<blue.size();i++)
   {
    if(blue[i]<i+1)flag = 0;
   }
  for(int i=0;i<red.size();i++)
   {
    if(red[i]>n-i)flag = 0;
   }
   debugg(flag);
  }
};
int32_t main()
{
   

   

 
                ONIIICHAANYAAAMETTEEEEKUDASAAAI
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        naruto zoro;
        sasuke luffy;
        luffy.solve();
        

        cout<<endl;
    }
    return 0;
}