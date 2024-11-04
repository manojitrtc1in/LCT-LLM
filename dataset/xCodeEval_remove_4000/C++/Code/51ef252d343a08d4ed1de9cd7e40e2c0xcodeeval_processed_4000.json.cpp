



using namespace std;

template<class T> struct cLtraits_identity{
  using type = T;
}
;
template<class T> using cLtraits_try_make_signed =
  typename conditional<
    is_integral<T>::value,
    make_signed<T>,
    cLtraits_identity<T>
    >::type;
template <class S, class T> struct cLtraits_common_type{
  using tS = typename cLtraits_try_make_signed<S>::type;
  using tT = typename cLtraits_try_make_signed<T>::type;
  using type = typename common_type<tS,tT>::type;
}
;
void*wmem;
char memarr[96000000];
template<class S, class T> inline auto max_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a >= (typename cLtraits_common_type<S,T>::type) b ? a : b;
}
template<class T> inline void id4(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void id4(T **arr, int x1, int x2, void **mem = &wmem){
  id4(arr, x2-x1, mem);
  (*arr) -= x1;
}
template<class T1, class T2, class T3> inline T1 id13(const T1 a, const T2 b, const T3 c){
  if(a <= b){
    if(b <= c){
      return b;
    }
    if(c <= a){
      return a;
    }
    return c;
  }
  if(a <= c){
    return a;
  }
  if(c <= b){
    return b;
  }
  return c;
}
struct Modint{
  unsigned val;
  Modint(){
    val=0;
  }
  Modint(int a){
    val = ord(a);
  }
  Modint(unsigned a){
    val = ord(a);
  }
  Modint(long long a){
    val = ord(a);
  }
  Modint(unsigned long long a){
    val = ord(a);
  }
  inline unsigned ord(unsigned a){
    return a%MD;
  }
  inline unsigned ord(int a){
    a %= (int)MD;
    if(a < 0){
      a += MD;
    }
    return a;
  }
  inline unsigned ord(unsigned long long a){
    return a%MD;
  }
  inline unsigned ord(long long a){
    a %= (int)MD;
    if(a < 0){
      a += MD;
    }
    return a;
  }
  inline unsigned get(){
    return val;
  }
  inline Modint &operator++(){
    val++;
    if(val >= MD){
      val -= MD;
    }
    return *this;
  }
  inline Modint &operator--(){
    if(val == 0){
      val = MD - 1;
    }
    else{
      --val;
    }
    return *this;
  }
  inline Modint operator++(int a){
    Modint res(*this);
    val++;
    if(val >= MD){
      val -= MD;
    }
    return res;
  }
  inline Modint operator--(int a){
    Modint res(*this);
    if(val == 0){
      val = MD - 1;
    }
    else{
      --val;
    }
    return res;
  }
  inline Modint &operator+=(Modint a){
    val += a.val;
    if(val >= MD){
      val -= MD;
    }
    return *this;
  }
  inline Modint &operator-=(Modint a){
    if(val < a.val){
      val = val + MD - a.val;
    }
    else{
      val -= a.val;
    }
    return *this;
  }
  inline Modint &operator*=(Modint a){
    val = ((unsigned long long)val*a.val)%MD;
    return *this;
  }
  inline Modint &operator/=(Modint a){
    return *this *= a.inverse();
  }
  inline Modint operator+(Modint a){
    return Modint(*this)+=a;
  }
  inline Modint operator-(Modint a){
    return Modint(*this)-=a;
  }
  inline Modint operator*(Modint a){
    return Modint(*this)*=a;
  }
  inline Modint operator/(Modint a){
    return Modint(*this)/=a;
  }
  inline Modint operator+(int a){
    return Modint(*this)+=Modint(a);
  }
  inline Modint operator-(int a){
    return Modint(*this)-=Modint(a);
  }
  inline Modint operator*(int a){
    return Modint(*this)*=Modint(a);
  }
  inline Modint operator/(int a){
    return Modint(*this)/=Modint(a);
  }
  inline Modint operator+(long long a){
    return Modint(*this)+=Modint(a);
  }
  inline Modint operator-(long long a){
    return Modint(*this)-=Modint(a);
  }
  inline Modint operator*(long long a){
    return Modint(*this)*=Modint(a);
  }
  inline Modint operator/(long long a){
    return Modint(*this)/=Modint(a);
  }
  inline Modint operator-(void){
    Modint res;
    if(val){
      res.val=MD-val;
    }
    else{
      res.val=0;
    }
    return res;
  }
  inline operator bool(void){
    return val!=0;
  }
  inline operator int(void){
    return get();
  }
  inline operator long long(void){
    return get();
  }
  inline Modint inverse(){
    int a = val;
    int b = MD;
    int u = 1;
    int v = 0;
    int t;
    Modint res;
    while(b){
      t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    if(u < 0){
      u += MD;
    }
    res.val = u;
    return res;
  }
  inline Modint pw(unsigned long long b){
    Modint a(*this);
    Modint res;
    res.val = 1;
    while(b){
      if(b&1){
        res *= a;
      }
      b >>= 1;
      a *= a;
    }
    return res;
  }
  inline bool operator==(int a){
    return ord(a)==val;
  }
  inline bool operator!=(int a){
    return ord(a)!=val;
  }
}
;
inline Modint operator+(int a, Modint b){
  return Modint(a)+=b;
}
inline Modint operator-(int a, Modint b){
  return Modint(a)-=b;
}
inline Modint operator*(int a, Modint b){
  return Modint(a)*=b;
}
inline Modint operator/(int a, Modint b){
  return Modint(a)/=b;
}
inline Modint operator+(long long a, Modint b){
  return Modint(a)+=b;
}
inline Modint operator-(long long a, Modint b){
  return Modint(a)-=b;
}
inline Modint operator*(long long a, Modint b){
  return Modint(a)*=b;
}
inline Modint operator/(long long a, Modint b){
  return Modint(a)/=b;
}
inline int id9(){
  static char buf[1048576];
  static int s = 1048576;
  static int e = 1048576;
  if(s == e && e == 1048576){
    e = fread(buf, 1, 1048576, stdin);
    s = 0;
  }
  if(s == e){
    return EOF;
  }
  return buf[s++];
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = id9();
    if(k=='-'){
      m=1;
      break;
    }
    if('0'<=k&&k<='9'){
      x=k-'0';
      break;
    }
  }
  for(;;){
    k = id9();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
struct id8{
  char buf[1048576];
  int s;
  int e;
  id8(){
    s = 0;
    e = 1048576;
  }
  ~id8(){
    if(s){
      fwrite(buf, 1, s, stdout);
    }
  }
}
;
id8 id14;
void my_putchar(int a){
  if(id14.s == id14.e){
    fwrite(id14.buf, 1, id14.s, stdout);
    id14.s = 0;
  }
  id14.buf[id14.s++] = a;
}
inline void wt_L(char a){
  my_putchar(a);
}
inline void wt_L(int x){
  int s=0;
  int m=0;
  char f[10];
  if(x<0){
    m=1;
    x=-x;
  }
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  if(m){
    my_putchar('-');
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
inline void wt_L(Modint x){
  int i;
  i = (int)x;
  wt_L(i);
}
template<class T> struct id10{
  int n;
  int mem;
  T*d;
  T& operator[](int a){
    return d[a];
  }
  void sort(){
    reset();
    std::sort(d, d+n);
  }
  int id3;
  int id11;
  T*id5;
  void setSum(void){
    int i;
    id3 = 1;
    if(id11 < n+1){
      delete[] id5;
      id5 = new T[n+1];
      id11 = n+1;
    }
    id5[0] = 0;
    for(i=(0);i<(n);i++){
      id5[i+1] = id5[i] + d[i];
    }
  }
  T getSum(int i, int j){
    if(id3==0){
      setSum();
    }
    return id5[j+1] - id5[i];
  }
  void reset(){
    id3 = 0;
  }
  void constructor(){
    n = mem = 0;
    d = NULL;
    id3 = 0;
    id11 = 0;
    id5 = NULL;
  }
  void destructor(){
    delete[] d;
    d = NULL;
    mem = n = 0;
    id3 = 0;
    id11 = 0;
    delete[] id5;
    id5 = NULL;
  }
  void constructor(int nn){
    constructor();
    malloc(nn);
  }
  void memory_expand(int nn){
    if(mem < nn){
      delete[] d;
      d = new T[nn];
      mem = nn;
    }
  }
  void malloc(int nn){
    reset();
    memory_expand(nn);
    n = nn;
  }
  void setN(int nn){
    reset();
    memory_expand(nn);
    n = nn;
  }
  void setN(int nn, T val){
    int i;
    reset();
    memory_expand(nn);
    n = nn;
    for(i=(0);i<(n);i++){
      d[i] = val;
    }
  }
  void set(vector<T> &a){
    int i;
    int nn = a.size();
    setN(nn);
    for(i=(0);i<(nn);i++){
      d[i] = a[i];
    }
  }
  void set(int nn, T a[]){
    int i;
    setN(nn);
    for(i=(0);i<(nn);i++){
      d[i] = a[i];
    }
  }
  void free(){
    destructor();
  }
  id10(){
    constructor();
  }
  id10(int nn){
    constructor(nn);
  }
  ~id10(){
    destructor();
  }
}
;
int N;
int Q;
int X;
id10<int> C;
id10<int> B;
Modint dp[101][10001];
Modint s[10002];
Modint res[6000];
int main(){
  int id6;
  wmem = memarr;
  int lm;
  int st = 0;
  rd(N);
  C.malloc(N);
  {
    int id0;
    for(id0=(0);id0<(N);id0++){
      rd(C[id0]);
    }
  }
  B.malloc(N-1);
  {
    int id1;
    for(id1=(0);id1<(N-1);id1++){
      rd(B[id1]);
    }
  }
  rd(Q);
  dp[0][0] = 1;
  for(X=(102)-1;X>=(-5000);X--){
    int k;
    lm = 0;
    for(k=(0);k<(N);k++){
      lm += X + B.getSum(0, k-1);
      if(lm > 10000+1){
        lm = 0;
      }
    }
    if(lm == 10000+1){
      continue;
    }
    lm = 0;
    for(k=(0);k<(st);k++){
      lm += X + B.getSum(0, k-1);
      if(lm > 10000+1){
        lm = 0;
      }
    }
    for(k=(st);k<(N);k++){
      int i;
      lm += X + B.getSum(0, k-1);
      if(lm > 10000+1){
        lm = 10000+1;
      }
      s[0] = 0;
      for(i=(0);i<(10000+1);i++){
        s[i+1] = s[i] + dp[k][i];
      }
      for(i=(0);i<(lm);i++){
        dp[k+1][i] = 0;
      }
      for(i=(lm);i<(10000+1);i++){
        dp[k+1][i] = s[i+1] - s[max_L(0, i-C[k])];
      }
      if(X <= -100 && lm <= 0){
        st = k + 1;
      }
    }
    int id7;
    cLtraits_try_make_signed<remove_reference<decltype((*((Modint*)NULL)))>::type>::type id12;
    if(10000+1==0){
      id12 = 0;
    }
    else{
      id12 = dp[N][0];
      for(id7=(1);id7<(10000+1);id7++){
        id12 += dp[N][id7];
      }
    }
    res[X+5000] =id12;
  }
  int id2 = Q;
  for(id6=(0);id6<(id2);id6++){
    rd(X);
    X =id13(-5000, X, 101);
    wt_L(res[X+5000]);
    wt_L('\n');
  }
  return 0;
}

































































































