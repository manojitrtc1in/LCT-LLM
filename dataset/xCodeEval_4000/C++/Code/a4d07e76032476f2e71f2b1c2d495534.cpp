#include <bits/stdc++.h>



using namespace std;

#define vt vector 
#define ar array 
#define pr pair 

#define f first 
#define s second

#define pb push_back
#define eb emplace_back

#define fr(i,a,b) for(int i = a; i < b; ++i)
#define rf(i,a,b) for(int i = a-1; i >= b; --i)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))

namespace IN{
  template<class T> void re(vector<T> &A);
  template<class S,class T> void re(pair<S,T> &A);
  template<class T,size_t N> void re(array<T,N> &A);

  template<class T> void re(T& x){ 
    cin >> x;}
  template<class H, class... T> void re(H& h, T&... t){ 
    re(h); re(t...);}

  template<class T> void re(vector<T> &A){ 
    for(auto& x : A) re(x);}
  template<class S,class T> void re(pair<S,T> &A){ 
      re(A.first); re(A.second);}
  template<class T,size_t N> void re(array<T,N> &A){
    for(int i = 0; i < N; ++i)  re(A[i]);}
}

namespace OUT{
  template<class T>
  void __p(const T& a){ cout<<a; }
  template<class T, class F>
  void __p(const pair<T, F>& a){ cout<<"{"; __p(a.first); cout<<","; __p(a.second); cout<<"}\n"; }
  template<class T, size_t N>
  void __p(const array<T,N>& a){ cout<<"{"; for(int i=0;i<N;++i)__p(a[i]),cout<<",}\n"[i+1==N]; }
  template<class T>
  void __p(const vector<T>& a){
    cout<<"{";for(auto it=a.begin();it<a.end();it++)__p(*it),cout<<",}\n"[it+1==a.end()]; }
  template<class T, class ...Arg>
  void __p(T a1, Arg ...a){__p(a1); __p(a...); }
  template<class Arg1>
  void __f(const char *s, Arg1 &&arg1){ cout<<s<<" : "; __p(arg1); cout<<endl; }
  template<class Arg1, class ... Args>
  void __f(const char *ss, Arg1 &&arg1, Args &&... args){
    int b=0,i=0; do{ if(ss[i]=='(') b++; if(ss[i]==')') b--; i++;}while(!(ss[i]==','&&b==0));
    const char *comma=ss+i; cout.write(ss,comma-ss)<<" : ";__p(arg1);cout<<" | ";__f(comma+1,args...);}
  #define trace(...) cout<<"Line:"<<__LINE__<<"  ", __f(#__VA_ARGS__, __VA_ARGS__)
}


namespace FUN{
  void IO(string s = ""){
    ios_base::sync_with_stdio(NULL); 
    cin.tie(nullptr); 
    cout.precision(20); 
    cout << fixed;
    if(!s.empty()){
      freopen((s+".in").c_str(),"r",stdin);
      freopen((s+".out").c_str(),"w",stdout);
    }
  }

  const auto start_time = chrono::high_resolution_clock::now();
  void output_run_time(){
    

#ifndef ONLINE_JUDGE
    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end_time-start_time;
      cout << "\n\n\nTime Taken : " << diff.count();
#endif
  }

  template<class T> bool ckmin(T& a, const T& b){ 
    return b < a ? a = b, true : false; }
    
  template<class T> bool ckmax(T& a, const T& b){ 
    return a < b ? a = b, true : false; }

  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  int my_rand(int L, int R){ 
    return uniform_int_distribution<int>(L,R)(rng); }
  
  template<class T> int sz(const T& x){ 
    return int(x.size()); }

  template<class T> int lb(const vector<T>& vec,const T& val){
    return int(lower_bound(vec.begin(), vec.end(),val) - vec.begin()); }

  template<class T> int ub(const vector<T>& vec,const T& val){
    return int(upper_bound(vec.begin(), vec.end(),val) - vec.begin()); }

  constexpr int  dx[4] = {1,0,-1,0};
  constexpr int  dy[4] = {0,1,0,-1};
  constexpr char dr[4] = {'D','R','U','L'};

  constexpr long long INFLL1 = 1e16, INFLL2 = 9e18;
  constexpr int INF = 2e9;

  template<class T>
  vector<T> V(int n,T val){
    return vector<T> (n,val);
  }

  template<class T>
  vector<vector<T>> V(int n,int m,T val){
    return vector<vector<T>> (n,vector<T> (m,val));
  }

  template<class T>
  vector<vector<vector<T>>> V(int n,int m,int k,T val){
    return vector<vector<vector<T>>> (n,vector<vector<T>> (m,vector<T> (k,val)));
  }
}


using namespace IN;
using namespace OUT;
using namespace FUN;


















template<const unsigned &MOD>
struct _m_uint {
  unsigned val;
 
  _m_uint(int64_t v = 0){
    if(v < 0) v = v % MOD + MOD;
    if(v >= MOD) v %= MOD;
    val = unsigned(v);
  }
 
  _m_uint(uint64_t v){
    if(v >= MOD) v %= MOD;
    val = unsigned(v);
  }
 
  _m_uint(int v) : _m_uint(int64_t(v)) {}
  _m_uint(unsigned v) : _m_uint(uint64_t(v)) {}
 
  explicit operator unsigned() const { return val; }
  explicit operator int64_t() const { return val; }
  explicit operator uint64_t() const { return val; }
  explicit operator double() const { return val; }
  explicit operator long double() const { return val; }
 
  _m_uint& operator+=(const _m_uint &other){
    val = val < MOD - other.val ? val + other.val : val - (MOD - other.val);
    return *this;
  }
 
  _m_uint& operator-=(const _m_uint &other){
    val = val < other.val ? val + (MOD - other.val) : val - other.val;
    return *this;
  }
 
  static unsigned fast_mod(uint64_t x, unsigned m = MOD){
    return unsigned(x % m);
  }
 
  _m_uint& operator*=(const _m_uint &other){
    val = fast_mod(uint64_t(val) * other.val);
    return *this;
  }
 
  _m_uint& operator/=(const _m_uint &other){
    return *this *= other.inv();
  }
 
  friend _m_uint operator+(const _m_uint &a, const _m_uint &b){ return _m_uint(a) += b; }
  friend _m_uint operator-(const _m_uint &a, const _m_uint &b){ return _m_uint(a) -= b; }
  friend _m_uint operator*(const _m_uint &a, const _m_uint &b){ return _m_uint(a) *= b; }
  friend _m_uint operator/(const _m_uint &a, const _m_uint &b){ return _m_uint(a) /= b; }
 
  _m_uint& operator++(){
    val = val == MOD - 1 ? 0 : val + 1;
    return *this;
  }
 
  _m_uint& operator--(){
    val = val == 0 ? MOD - 1 : val - 1;
    return *this;
  }
    
  _m_uint operator++(int){ _m_uint before = *this; ++*this; return before; }
  _m_uint operator--(int){ _m_uint before = *this; --*this; return before; }
      
  _m_uint operator-() const {
    return val == 0 ? 0 : MOD - val;
  }
 
  friend bool operator==(const _m_uint &a, const _m_uint &b) { return a.val == b.val; }
  friend bool operator!=(const _m_uint &a, const _m_uint &b) { return a.val != b.val; }
  friend bool operator<(const _m_uint &a, const _m_uint &b) { return a.val < b.val; }
  friend bool operator>(const _m_uint &a, const _m_uint &b) { return a.val > b.val; }
  friend bool operator<=(const _m_uint &a, const _m_uint &b) { return a.val <= b.val; }
  friend bool operator>=(const _m_uint &a, const _m_uint &b) { return a.val >= b.val; }
 
  static const int SAVE_INV = int(1e6) + 5;
  static _m_uint save_inv[SAVE_INV];
 
  static void prepare_inv(){
    

    for(int64_t p = 2; p * p <= MOD; p += p % 2 + 1){
      assert(MOD % p != 0);
    } 
      
    save_inv[0] = 0;
    save_inv[1] = 1;
 
    for (int i = 2; i < SAVE_INV; i++){
      save_inv[i] = save_inv[MOD % i] * (MOD - MOD / i);
    }
  }
 
  _m_uint inv() const {
    if(save_inv[1] == 0)  
      prepare_inv();
 
    if(val < SAVE_INV)  
      return save_inv[val];
 
    _m_uint product = 1;
    unsigned v = val;
 
    while(v >= SAVE_INV){
      product *= MOD - MOD / v;
      v = MOD % v;
    }
    return product * save_inv[v];
  }
 
  _m_uint pow(int64_t p) const {
    if(p < 0)  
      return inv().pow(-p);
    _m_uint a = *this, result = 1;
    while(p > 0){
      if(p & 1) 
        result *= a;
      p >>= 1;
      if(p > 0) 
        a *= a;
    }
    return result;
  }
 
  friend ostream& operator<<(ostream &os, const _m_uint &m){
    return os << m.val;
  }
};
 
template<const unsigned &MOD> _m_uint<MOD> _m_uint<MOD>::save_inv[_m_uint<MOD>::SAVE_INV];

const unsigned MOD = 998244353;
using mint = _m_uint<MOD>;







template<typename T>
struct Matrix{
  int rows, cols;
  vector<vector<T>> mat;

  Matrix() : rows(-1), cols(-1) {}

  Matrix(int r,int c) : rows(r), cols(c), mat(vector<vector<T>> (r,vector<T> (c))) {}

  Matrix(vector<vector<T>> M) : rows(M.size()), cols(M[0].size()), mat(M) {}

  void fill(T val){
    for(int i = 0; i < rows; ++i){
      for(int j = 0; j < cols; ++j){
        mat[i][j] = val;
      }
    }
  }

  void setID(){
    assert(rows == cols);
    fill(0);
    for(int i = 0; i < rows; ++i)
      mat[i][i] = 1;
  }

  Matrix<T> operator-(){
    Matrix<T> res(rows,cols);
    for(int i = 0; i < rows; ++i){
      for(int j = 0; j < cols; ++j){
        res.mat[i][j] = -1 * mat[i][j];
      }
    }
    return res;
  }

  Matrix operator+(const Matrix& a) const {
    assert(rows == a.rows && cols == a.cols);
    Matrix<T> res(rows,cols);
    for(int i = 0; i < rows; ++i)
      for(int j = 0; j < cols; ++j)
        res.mat[i][j] = mat[i][j] + a.mat[i][j];
    return res;
  }

  Matrix operator-(const Matrix& a) const {
    assert(rows == a.rows && cols == a.cols);
    Matrix<T> res(rows,cols);
    for(int i = 0; i < rows; ++i)
      for(int j = 0; j < cols; ++j)
        res.mat[i][j] = mat[i][j] - a.mat[i][j];
    return res;
  }

  Matrix operator*(const Matrix& a) const {
    assert(cols == a.rows);
    Matrix<T> res(rows,a.cols);
    for(int i = 0; i < rows; ++i)
      for(int j = 0; j < a.cols; ++j){
        res.mat[i][j] = 0;
        for(int k = 0; k < cols; ++k){
          res.mat[i][j] += mat[i][k] * a.mat[k][j];
        }
      }
    return res;
  }

  Matrix operator*(const T& val) const {
    Matrix<T> res(mat);
    for(int i = 0; i < rows; ++i){
      for(int j = 0; j < cols; ++j){
        res[i][j] *= val;
      }
    }
    return res;
  }

  void operator+=(const Matrix& a){ *this = *this + a; }
  void operator-=(const Matrix& a){ *this = *this - a; }
  void operator*=(const Matrix& a){ *this = *this * a; }

  Matrix pow(long long n){
    Matrix<T> res(rows,cols);
    res.setID();

    Matrix<T> a = *this;

    while(n){
      if(n&1)
        res *= a;
      a = a * a;
      n >>= 1;
    }

    return res;
  }

  

  

  

  


  

  

  

  


  


  

  

  

  

  


  

  

  

  

  

  

  


  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  


  

  


  


  


  


  

  

  

  

  

  

  

  

  

  

  

  

  


  

  

  

  

  

  

  

  

  


  

  

  

  

  


  

  

  

  

  

  

  


    
    
  


  

  

  


  


  


  


  

  

  

  

  


  

  



  vector<T>& operator[](int i){
    return mat[i];
  }

  const vector<T>& operator[](int i) const {
    return mat[i];
  }

  friend ostream& operator<<(ostream &out,const Matrix<T> &M){
    for(int i = 0; i < M.rows; ++i){
      for(int j = 0; j < M.cols; ++j){
        out << M[i][j] << " ";
      }
      out << "\n";
    }
    return out;
  }
};


signed main(){
  IO();

  int n,m,k;
  re(n,m,k);

  Matrix<mint> A(n,n), I(n,n), D(n,n);

  A.fill(0);
  I.setID();
  D.fill(0);

  fr(e,0,m){
    int u,v; 
    re(u,v);
    --u,--v;
    A[u][v] = A[v][u] = 1;
    D[u][u] += 1;
    D[v][v] += 1;
  }

  Matrix<mint> M(2*n,2*n);

  Matrix<mint> tmp = I - D;

  fr(i,0,n){
    fr(j,0,n){
      M[0+i][0+j] = A[i][j];
    }
  }

  fr(i,0,n){
    fr(j,0,n){
      M[0+i][n+j] = tmp[i][j];
    }
  }

  fr(i,0,n){
    fr(j,0,n){
      M[n+i][0+j] = I[i][j];
    }
  }

  fr(i,0,n){
    fr(j,0,n){
      M[n+i][n+j] = 0;
    }
  }  

  Matrix<mint> V(2*n,n);

  tmp = A*A - D;

  fr(i,0,n){
    fr(j,0,n){
      V[0+i][0+j] = tmp[i][j];
    }
  }

  fr(i,0,n){
    fr(j,0,n){
      V[n+i][0+j] = A[i][j];
    }
  }

  if(k == 1){
    cout << "0";
    return 0;
  }

  auto out = M.pow(k-2) * V;


  mint ans = 0;

  fr(i,0,n){
    ans += out[i][i];
  }

  cout << ans;







  
  output_run_time();
  return 0;
}

















