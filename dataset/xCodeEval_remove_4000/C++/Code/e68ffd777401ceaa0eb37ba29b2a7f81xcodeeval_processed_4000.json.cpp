



using namespace std;

void*wmem;
char memarr[96000000];
template<class T> inline void id5(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void id5(T **arr, int x1, int x2, void **mem = &wmem){
  id5(arr, x2-x1, mem);
  (*arr) -= x1;
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
inline int id12(){
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
    k = id12();
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
    k = id12();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
struct id11{
  char buf[1048576];
  int s;
  int e;
  id11(){
    s = 0;
    e = 1048576;
  }
  ~id11(){
    if(s){
      fwrite(buf, 1, s, stdout);
    }
  }
}
;
id11 id23;
void my_putchar(int a){
  if(id23.s == id23.e){
    fwrite(id23.buf, 1, id23.s, stdout);
    id23.s = 0;
  }
  id23.buf[id23.s++] = a;
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
inline void wt_L(unsigned x){
  int s=0;
  char f[10];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
inline void wt_L(long long x){
  int s=0;
  int m=0;
  char f[20];
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
inline void wt_L(unsigned long long x){
  int s=0;
  char f[21];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
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
int id18 = 15;
inline int id6(){
  return id18;
}
inline void id6(int d){
  id18 = d;
}
inline void wt_L(double x){
  const int d = id18;
  int k;
  int r;
  double v;
  if(x!=x || (x==x+1 && x==2*x)){
    my_putchar('E');
    my_putchar('r');
    my_putchar('r');
    return;
  }
  if(x < 0){
    my_putchar('-');
    x = -x;
  }
  x += 0.5 * pow(0.1, d);
  r = 0;
  v = 1;
  while(x >= 10*v){
    v *= 10;
    r++;
  }
  while(r >= 0){
    r--;
    k = floor(x / v);
    if(k >= 10){
      k = 9;
    }
    if(k <= -1){
      k = 0;
    }
    x -= k * v;
    v *= 0.1;
    my_putchar(k + '0');
  }
  if(d > 0){
    my_putchar('.');
    v = 1;
    for(r=(0);r<(d);r++){
      v *= 0.1;
      k = floor(x / v);
      if(k >= 10){
        k = 9;
      }
      if(k <= -1){
        k = 0;
      }
      x -= k * v;
      my_putchar(k + '0');
    }
  }
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
inline void wt_L(string &x){
  int i=0;
  for(i=0;x[i]!='\0';i++){
    my_putchar(x[i]);
  }
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
template<class T> struct Comb{
  int mem_fact;
  T*factri;
  T*ifactri;
  int id2;
  T*id13;
  int id17;
  int id3;
  int id10;
  int id19;
  T*id14;
  T*id9;
  T*id4;
  T*id16;
  int id8;
  int id22;
  int id21;
  T*id7;
  T*id15;
  T*id20;
  Comb(){
    mem_fact = 0;
    id2 = 0;
    id17 = id3 = id10 = id19 = 0;
    id8 = id22 = id21 = 0;
  }
  inline void expand_fact(int k){
    int i;
    if(k <= mem_fact){
      return;
    }
    chmax(k, 2 * mem_fact);
    if(mem_fact == 0){
      factri = (T*)malloc(k * sizeof(T));
      ifactri = (T*)malloc(k * sizeof(T));
      factri[0] = 1;
      for(i=(1);i<(k);i++){
        factri[i] = i * factri[i-1];
      }
      ifactri[k-1] = 1 / factri[k-1];
      for(i=(k-1)-1;i>=(0);i--){
        ifactri[i] = (i+1) * ifactri[i+1];
      }
    }
    else{
      factri = (T*)realloc(factri, k * sizeof(T));
      ifactri = (T*)realloc(ifactri, k * sizeof(T));
      for(i=(mem_fact);i<(k);i++){
        factri[i] = i * factri[i-1];
      }
      ifactri[k-1] = 1 / factri[k-1];
      for(i=(k-1)-1;i>=(mem_fact);i--){
        ifactri[i] = (i+1) * ifactri[i+1];
      }
    }
    mem_fact = k;
  }
  inline T fac(int k){
    if(mem_fact < k+1){
      expand_fact(k+1);
    }
    return factri[k];
  }
  inline T ifac(int k){
    if(mem_fact < k+1){
      expand_fact(k+1);
    }
    return ifactri[k];
  }
  inline T C(int a, int b){
    if(b < 0 || b > a){
      return 0;
    }
    if(mem_fact < a+1){
      expand_fact(a+1);
    }
    return factri[a] * ifactri[b] * ifactri[a-b];
  }
  inline T P(int a, int b){
    if(b < 0 || b > a){
      return 0;
    }
    if(mem_fact < a+1){
      expand_fact(a+1);
    }
    return factri[a] * ifactri[a-b];
  }
  inline T H(int a, int b){
    if(a==0 && b==0){
      return 1;
    }
    if(a <= 0 || b < 0){
      return 0;
    }
    if(mem_fact < a+b){
      expand_fact(a+b);
    }
    return C(a+b-1, b);
  }
  inline T Multinomial(int sz, int a[]){
    int i;
    int s = 0;
    T res;
    for(i=(0);i<(sz);i++){
      s += a[i];
    }
    if(mem_fact < s+1){
      expand_fact(s+1);
    }
    res = factri[s];
    for(i=(0);i<(sz);i++){
      res *= ifactri[a[i]];
    }
    return res;
  }
  inline T Multinomial(int a){
    return 1;
  }
  inline T Multinomial(int a, int b){
    if(mem_fact < a+b+1){
      expand_fact(a+b+1);
    }
    return factri[a+b] * ifactri[a] * ifactri[b];
  }
  inline T Multinomial(int a, int b, int c){
    if(mem_fact < a+b+c+1){
      expand_fact(a+b+c+1);
    }
    return factri[a+b+c] * ifactri[a] * ifactri[b] * ifactri[c];
  }
  inline T Multinomial(int a, int b, int c, int d){
    if(mem_fact < a+b+c+d+1){
      expand_fact(a+b+c+d+1);
    }
    return factri[a+b+c+d] * ifactri[a] * ifactri[b] * ifactri[c] * ifactri[d];
  }
  inline T Catalan(int n){
    if(n < 0){
      return 0;
    }
    if(mem_fact < 2*n+1){
      expand_fact(2*n+1);
    }
    return factri[2*n] * ifactri[n] * ifactri[n+1];
  }
  inline T C_s(long long a, long long b){
    long long i;
    T res;
    if(b < 0 || b > a){
      return 0;
    }
    if(b > a - b){
      b = a - b;
    }
    res = 1;
    for(i=(0);i<(b);i++){
      res *= a - i;
      res /= i + 1;
    }
    return res;
  }
  inline T P_s(long long a, long long b){
    long long i;
    T res;
    if(b < 0 || b > a){
      return 0;
    }
    res = 1;
    for(i=(0);i<(b);i++){
      res *= a - i;
    }
    return res;
  }
  inline T per_s(long long n, long long k){
    T d;
    int m;
    if(n < 0 || k < 0){
      return 0;
    }
    if(n == k  &&  k == 0){
      return 1;
    }
    if(n == 0 || k == 0){
      return 0;
    }
    if(k==1){
      return 1;
    }
    if(k==2){
      d = n / 2;
      return d;
    }
    if(k==3){
      d = (n-1) / 6;
      m = (n-1) % 6;
      if(m==0){
        return 3 * d * d + d;
      }
      if(m==1){
        return 3 * d * d + 2 * d;
      }
      if(m==2){
        return 3 * d * d + 3 * d + 1;
      }
      if(m==3){
        return 3 * d * d + 4 * d + 1;
      }
      if(m==4){
        return 3 * d * d + 5 * d + 2;
      }
      if(m==5){
        return 3 * d * d + 6 * d + 3;
      }
    }
    assert(0 && "per_s should be k <= 3");
    return -1;
  }
  inline void expand_dfact(int k){
    int i;
    if(k <= id2){
      return;
    }
    chmax(k, 3);
    chmax(k, 2 * id2);
    if(id2==0){
      id13 = (T*)malloc(k * sizeof(T));
      id13[0] = id13[1] = 1;
      for(i=(2);i<(k);i++){
        id13[i] = i * id13[i-2];
      }
    }
    else{
      id13 = (T*)realloc(id13, k * sizeof(T));
      for(i=(id2);i<(k);i++){
        id13[i] = i * id13[i-2];
      }
    }
    id2 = k;
  }
  inline void expand_pw2(int k){
    int i;
    if(k <= id17){
      return;
    }
    chmax(k, 2 * id17);
    if(id17==0){
      id14 = (T*)malloc(k * sizeof(T));
      id14[0] = 1;
      for(i=(1);i<(k);i++){
        id14[i] = 2 * id14[i-1];
      }
    }
    else{
      id14 = (T*)realloc(id14, k * sizeof(T));
      for(i=(id17);i<(k);i++){
        id14[i] = 2 * id14[i-1];
      }
    }
    id17 = k;
  }
  inline void expand_ipw2(int k){
    int i;
    if(k <= id8){
      return;
    }
    chmax(k, 2);
    chmax(k, 2 * id8);
    if(id8==0){
      id7 = (T*)malloc(k * sizeof(T));
      id7[0] = 1;
      id7[1] = id7[0] / 2;
      for(i=(1);i<(k);i++){
        id7[i] = id7[1] * id7[i-1];
      }
    }
    else{
      id7 = (T*)realloc(id7, k * sizeof(T));
      for(i=(id8);i<(k);i++){
        id7[i] = id7[1] * id7[i-1];
      }
    }
    id8 = k;
  }
  inline void expand_pw3(int k){
    int i;
    if(k <= id3){
      return;
    }
    chmax(k, 2 * id3);
    if(id3==0){
      id9 = (T*)malloc(k * sizeof(T));
      id9[0] = 1;
      for(i=(1);i<(k);i++){
        id9[i] = 3 * id9[i-1];
      }
    }
    else{
      id9 = (T*)realloc(id9, k * sizeof(T));
      for(i=(id3);i<(k);i++){
        id9[i] = 3 * id9[i-1];
      }
    }
    id3 = k;
  }
  inline void expand_ipw3(int k){
    int i;
    if(k <= id22){
      return;
    }
    chmax(k, 2);
    chmax(k, 2 * id22);
    if(id22==0){
      id15 = (T*)malloc(k * sizeof(T));
      id15[0] = 1;
      id15[1] = id15[0] / 3;
      for(i=(1);i<(k);i++){
        id15[i] = id15[1] * id15[i-1];
      }
    }
    else{
      id15 = (T*)realloc(id15, k * sizeof(T));
      for(i=(id22);i<(k);i++){
        id15[i] = id15[1] * id15[i-1];
      }
    }
    id22 = k;
  }
  inline void expand_pw10(int k){
    int i;
    if(k <= id10){
      return;
    }
    chmax(k, 2 * id10);
    if(id10==0){
      id4 = (T*)malloc(k * sizeof(T));
      id4[0] = 1;
      for(i=(1);i<(k);i++){
        id4[i] = 10 * id4[i-1];
      }
    }
    else{
      id4 = (T*)realloc(id4, k * sizeof(T));
      for(i=(id10);i<(k);i++){
        id4[i] = 10 * id4[i-1];
      }
    }
    id10 = k;
  }
  inline void expand_ipw10(int k){
    int i;
    if(k <= id21){
      return;
    }
    chmax(k, 2);
    chmax(k, 2 * id21);
    if(id21==0){
      id20 = (T*)malloc(k * sizeof(T));
      id20[0] = 1;
      id20[1] = id20[0] / 10;
      for(i=(1);i<(k);i++){
        id20[i] = id20[1] * id20[i-1];
      }
    }
    else{
      id20 = (T*)realloc(id20, k * sizeof(T));
      for(i=(id21);i<(k);i++){
        id20[i] = id20[1] * id20[i-1];
      }
    }
    id21 = k;
  }
  inline void expand_rep1(int k){
    int i;
    if(k <= id19){
      return;
    }
    chmax(k, 2 * id19);
    if(id19==0){
      id16 = (T*)malloc(k * sizeof(T));
      id16[0] = 0;
      for(i=(1);i<(k);i++){
        id16[i] = 10 * id16[i-1] + 1;
      }
    }
    else{
      id16 = (T*)realloc(id16, k * sizeof(T));
      for(i=(id19);i<(k);i++){
        id16[i] = 10 * id16[i-1] + 1;
      }
    }
    id19 = k;
  }
  inline T dfac(int k){
    if(k >= 0){
      if(id2 < k+1){
        expand_dfact(k+1);
      }
      return id13[k];
    }
    if(k==-1){
      return 1;
    }
    k = - k - 2;
    if(k % 4 == 1){
      return 1 / (-dfac(k));
    }
    return 1 / dfac(k);
  }
  inline T pw2(int k){
    if(k >= 0){
      if(id17 < k+1){
        expand_pw2(k+1);
      }
      return id14[k];
    }
    else{
      k = -k;
      if(id8 < k+1){
        expand_ipw2(k+1);
      }
      return id7[k];
    }
  }
  inline T pw3(int k){
    if(k >= 0){
      if(id3 < k+1){
        expand_pw3(k+1);
      }
      return id9[k];
    }
    else{
      k = -k;
      if(id22 < k+1){
        expand_ipw3(k+1);
      }
      return id15[k];
    }
  }
  inline T pw10(int k){
    if(k >= 0){
      if(id10 < k+1){
        expand_pw10(k+1);
      }
      return id4[k];
    }
    else{
      k = -k;
      if(id21 < k+1){
        expand_ipw10(k+1);
      }
      return id20[k];
    }
  }
  inline T repunit(int k){
    if(id19 < k+1){
      expand_rep1(k+1);
    }
    return id16[k];
  }
}
;
template<> inline Modint Comb<Modint>::C_s(long long a, long long b){
  long long i;
  Modint res;
  Modint d;
  if(b < 0 || b > a){
    return 0;
  }
  if(b > a - b){
    b = a - b;
  }
  res = d = 1;
  for(i=(0);i<(b);i++){
    res *= a - i;
    d *= i + 1;
  }
  return res / d;
}
int N;
int K;
int A[200000+1];
int ind[200000+1];
Comb<Modint> c;
int main(){
  int id1, i;
  wmem = memarr;
  int m = 0;
  int b = 1073709056;
  Modint res;
  rd(N);
  rd(K);
  {
    int id0;
    for(id0=(0);id0<(N);id0++){
      rd(A[id0]);
    }
  }
  for(i=(0);i<(N);i++){
    ind[A[i]] = i;
  }
  ind[N] = -1;
  for(id1=(0);id1<(N);id1++){
    auto&i = A[id1];
    if(ind[i+1] < b){
      m++;
    }
    b = ind[i+1];
  }
  wt_L(c.H(N+1,K-m));
  wt_L('\n');
  return 0;
}





































