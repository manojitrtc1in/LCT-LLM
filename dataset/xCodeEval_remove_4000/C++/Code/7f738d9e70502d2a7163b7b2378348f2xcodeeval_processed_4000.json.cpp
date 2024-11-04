



using namespace std;

void*wmem;
char memarr[96000000];
template<class T> inline void id3(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void id3(T **arr, int x1, int x2, void **mem = &wmem){
  id3(arr, x2-x1, mem);
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
id8 id19;
void my_putchar(int a){
  if(id19.s == id19.e){
    fwrite(id19.buf, 1, id19.s, stdout);
    id19.s = 0;
  }
  id19.buf[id19.s++] = a;
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
  int id0;
  T*id10;
  int id14;
  int id1;
  int id7;
  int id15;
  T*id11;
  T*id6;
  T*id2;
  T*id13;
  int id5;
  int id18;
  int id17;
  T*id4;
  T*id12;
  T*id16;
  Comb(){
    mem_fact = 0;
    id0 = 0;
    id14 = id1 = id7 = id15 = 0;
    id5 = id18 = id17 = 0;
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
    if(k <= id0){
      return;
    }
    chmax(k, 3);
    chmax(k, 2 * id0);
    if(id0==0){
      id10 = (T*)malloc(k * sizeof(T));
      id10[0] = id10[1] = 1;
      for(i=(2);i<(k);i++){
        id10[i] = i * id10[i-2];
      }
    }
    else{
      id10 = (T*)realloc(id10, k * sizeof(T));
      for(i=(id0);i<(k);i++){
        id10[i] = i * id10[i-2];
      }
    }
    id0 = k;
  }
  inline void expand_pw2(int k){
    int i;
    if(k <= id14){
      return;
    }
    chmax(k, 2 * id14);
    if(id14==0){
      id11 = (T*)malloc(k * sizeof(T));
      id11[0] = 1;
      for(i=(1);i<(k);i++){
        id11[i] = 2 * id11[i-1];
      }
    }
    else{
      id11 = (T*)realloc(id11, k * sizeof(T));
      for(i=(id14);i<(k);i++){
        id11[i] = 2 * id11[i-1];
      }
    }
    id14 = k;
  }
  inline void expand_ipw2(int k){
    int i;
    if(k <= id5){
      return;
    }
    chmax(k, 2);
    chmax(k, 2 * id5);
    if(id5==0){
      id4 = (T*)malloc(k * sizeof(T));
      id4[0] = 1;
      id4[1] = id4[0] / 2;
      for(i=(1);i<(k);i++){
        id4[i] = id4[1] * id4[i-1];
      }
    }
    else{
      id4 = (T*)realloc(id4, k * sizeof(T));
      for(i=(id5);i<(k);i++){
        id4[i] = id4[1] * id4[i-1];
      }
    }
    id5 = k;
  }
  inline void expand_pw3(int k){
    int i;
    if(k <= id1){
      return;
    }
    chmax(k, 2 * id1);
    if(id1==0){
      id6 = (T*)malloc(k * sizeof(T));
      id6[0] = 1;
      for(i=(1);i<(k);i++){
        id6[i] = 3 * id6[i-1];
      }
    }
    else{
      id6 = (T*)realloc(id6, k * sizeof(T));
      for(i=(id1);i<(k);i++){
        id6[i] = 3 * id6[i-1];
      }
    }
    id1 = k;
  }
  inline void expand_ipw3(int k){
    int i;
    if(k <= id18){
      return;
    }
    chmax(k, 2);
    chmax(k, 2 * id18);
    if(id18==0){
      id12 = (T*)malloc(k * sizeof(T));
      id12[0] = 1;
      id12[1] = id12[0] / 3;
      for(i=(1);i<(k);i++){
        id12[i] = id12[1] * id12[i-1];
      }
    }
    else{
      id12 = (T*)realloc(id12, k * sizeof(T));
      for(i=(id18);i<(k);i++){
        id12[i] = id12[1] * id12[i-1];
      }
    }
    id18 = k;
  }
  inline void expand_pw10(int k){
    int i;
    if(k <= id7){
      return;
    }
    chmax(k, 2 * id7);
    if(id7==0){
      id2 = (T*)malloc(k * sizeof(T));
      id2[0] = 1;
      for(i=(1);i<(k);i++){
        id2[i] = 10 * id2[i-1];
      }
    }
    else{
      id2 = (T*)realloc(id2, k * sizeof(T));
      for(i=(id7);i<(k);i++){
        id2[i] = 10 * id2[i-1];
      }
    }
    id7 = k;
  }
  inline void expand_ipw10(int k){
    int i;
    if(k <= id17){
      return;
    }
    chmax(k, 2);
    chmax(k, 2 * id17);
    if(id17==0){
      id16 = (T*)malloc(k * sizeof(T));
      id16[0] = 1;
      id16[1] = id16[0] / 10;
      for(i=(1);i<(k);i++){
        id16[i] = id16[1] * id16[i-1];
      }
    }
    else{
      id16 = (T*)realloc(id16, k * sizeof(T));
      for(i=(id17);i<(k);i++){
        id16[i] = id16[1] * id16[i-1];
      }
    }
    id17 = k;
  }
  inline void expand_rep1(int k){
    int i;
    if(k <= id15){
      return;
    }
    chmax(k, 2 * id15);
    if(id15==0){
      id13 = (T*)malloc(k * sizeof(T));
      id13[0] = 0;
      for(i=(1);i<(k);i++){
        id13[i] = 10 * id13[i-1] + 1;
      }
    }
    else{
      id13 = (T*)realloc(id13, k * sizeof(T));
      for(i=(id15);i<(k);i++){
        id13[i] = 10 * id13[i-1] + 1;
      }
    }
    id15 = k;
  }
  inline T dfac(int k){
    if(k >= 0){
      if(id0 < k+1){
        expand_dfact(k+1);
      }
      return id10[k];
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
      if(id14 < k+1){
        expand_pw2(k+1);
      }
      return id11[k];
    }
    else{
      k = -k;
      if(id5 < k+1){
        expand_ipw2(k+1);
      }
      return id4[k];
    }
  }
  inline T pw3(int k){
    if(k >= 0){
      if(id1 < k+1){
        expand_pw3(k+1);
      }
      return id6[k];
    }
    else{
      k = -k;
      if(id18 < k+1){
        expand_ipw3(k+1);
      }
      return id12[k];
    }
  }
  inline T pw10(int k){
    if(k >= 0){
      if(id7 < k+1){
        expand_pw10(k+1);
      }
      return id2[k];
    }
    else{
      k = -k;
      if(id17 < k+1){
        expand_ipw10(k+1);
      }
      return id16[k];
    }
  }
  inline T repunit(int k){
    if(id15 < k+1){
      expand_rep1(k+1);
    }
    return id13[k];
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
Comb<Modint> c;
int main(){
  int i;
  wmem = memarr;
  int N;
  rd(N);
  Modint res = 0;
  Modint tmp;
  for(i=(N%2);i<(N);i+=(2)){
    tmp = c.C(N-i,i);
    res += tmp * c.fac(N-1-i);
  }
  res *= 2*N;
  wt_L(res);
  wt_L('\n');
  return 0;
}





























