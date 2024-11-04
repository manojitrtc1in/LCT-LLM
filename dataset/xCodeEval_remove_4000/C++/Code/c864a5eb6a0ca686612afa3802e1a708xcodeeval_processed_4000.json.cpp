



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
template<class T> inline void id2(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void id2(T **arr, int x1, int x2, void **mem = &wmem){
  id2(arr, x2-x1, mem);
  (*arr) -= x1;
}
template<class T> inline void id9(T ***arr, int x, int y, void **mem = &wmem){
  int i;
  id2(arr, x, mem);
  for(i=(0);i<(x);i++){
    id2(&((*arr)[i]), y, mem);
  }
}
template<class T> inline void id9(T ***arr, int x1, int x2, int y1, int y2, void **mem = &wmem){
  int i;
  id2(arr, x1, x2, mem);
  for(i=(x1);i<(x2);i++){
    id2(&((*arr)[i]), y1, y2, mem);
  }
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
inline int id5(){
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
    k = id5();
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
    k = id5();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline int rd_int(void){
  int x;
  rd(x);
  return x;
}
struct id4{
  char buf[1048576];
  int s;
  int e;
  id4(){
    s = 0;
    e = 1048576;
  }
  ~id4(){
    if(s){
      fwrite(buf, 1, s, stdout);
    }
  }
}
;
id4 id10;
void my_putchar(int a){
  if(id10.s == id10.e){
    fwrite(id10.buf, 1, id10.s, stdout);
    id10.s = 0;
  }
  id10.buf[id10.s++] = a;
}
template<class T> inline void wt_L(vector<T> x);
template<class T> inline void wt_L(set<T> x);
template<class T> inline void wt_L(multiset<T> x);
template<class T1, class T2> inline void wt_L(pair<T1,T2> x);
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
double id6 = 1e-9;
template<class T> int id1(int R, int C, T **A, T *b, T *x, void *mem = wmem){
  int i;
  int j;
  int p;
  int rr = 0;
  int cc;
  T tmp;
  T tmp2;
  T**aa;
  T*bb;
  id9(&aa, R, C, &mem);
  id2(&bb, R, &mem);
  for(i=(0);i<(R);i++){
    for(j=(0);j<(C);j++){
      aa[i][j] = A[i][j];
    }
  }
  for(i=(0);i<(R);i++){
    bb[i] = b[i];
  }
  for(cc=(0);cc<(C);cc++){
    if(rr < R){
      tmp = -1;
      for(p=(rr);p<(R);p++){
        tmp2 = abs(aa[p][cc]);
        if(tmp < tmp2){
          tmp = tmp2;
          i = p;
        }
      }
      if(tmp < id6){
        continue;
      }
      if(i != rr){
        for(j=(cc);j<(C);j++){
          swap(aa[rr][j], aa[i][j]);
        }
        swap(bb[rr], bb[i]);
      }
      for(i=(rr+1);i<(R);i++){
        if(aa[i][cc]){
          tmp = aa[i][cc] / aa[rr][cc];
          for(j=(cc);j<(C);j++){
            aa[i][j] -= tmp * aa[rr][j];
          }
          bb[i] -= tmp * bb[rr];
        }
      }
      rr++;
    }
  }
  for(i=(rr);i<(R);i++){
    if(abs(bb[i]) >= id6){
      return -1;
    }
  }
  for(i=(0);i<(C);i++){
    x[i] = 0;
  }
  for(i=(rr)-1;i>=(0);i--){
    int k;
    for(j=(0);j<(C);j++){
      if(aa[i][j] >= id6){
        break;
      }
    }
    x[j] = bb[i];
    for(k=(j+1);k<(C);k++){
      x[j] -= x[k] * aa[i][k];
    }
    x[j] /= aa[i][j];
  }
  return C - rr;
}
template<class T> int id12(int R, int C, T **A, T *b, T *x, void *mem = wmem){
  int i;
  int j;
  int rr = 0;
  int cc;
  T tmp;
  T**aa;
  T*bb;
  id9(&aa, R, C, &mem);
  id2(&bb, R, &mem);
  for(i=(0);i<(R);i++){
    for(j=(0);j<(C);j++){
      aa[i][j] = A[i][j];
    }
  }
  for(i=(0);i<(R);i++){
    bb[i] = b[i];
  }
  for(cc=(0);cc<(C);cc++){
    if(rr < R){
      for(i=(rr);i<(R);i++){
        if(aa[i][cc]){
          break;
        }
      }
      if(i == R){
        continue;
      }
      if(i != rr){
        for(j=(cc);j<(C);j++){
          swap(aa[rr][j], aa[i][j]);
        }
        swap(bb[rr], bb[i]);
      }
      for(i=(rr+1);i<(R);i++){
        if(aa[i][cc]){
          tmp = aa[i][cc] / aa[rr][cc];
          for(j=(cc);j<(C);j++){
            aa[i][j] -= tmp * aa[rr][j];
          }
          bb[i] -= tmp * bb[rr];
        }
      }
      rr++;
    }
  }
  for(i=(rr);i<(R);i++){
    if(bb[i]){
      return -1;
    }
  }
  for(i=(0);i<(C);i++){
    x[i] = 0;
  }
  for(i=(rr)-1;i>=(0);i--){
    int k;
    for(j=(0);j<(C);j++){
      if(aa[i][j]){
        break;
      }
    }
    x[j] = bb[i];
    for(k=(j+1);k<(C);k++){
      x[j] -= x[k] * aa[i][k];
    }
    x[j] /= aa[i][j];
  }
  return C - rr;
}
template<class T> int LinearEquation(int R, int C, T **A, T *b, T *x, void *mem = wmem){
  return id1(R, C, A, b, x, mem);
}
int LinearEquation(int R, int C, Modint **A, Modint *b, Modint *x, void *mem = wmem){
  return id12(R, C, A, b, x, mem);
}
int main(){
  int id0;
  wmem = memarr;
  Modint**aa;
  Modint*b;
  Modint*x;
  id9(&aa, 10000, 257);
  id2(&b, 10000);
  id2(&x, 257);
  int id11 = rd_int();
  for(id0=(0);id0<(id11);id0++){
    int i;
    int N;
    rd(N);
    int M;
    rd(M);
    int A[M];
    int B[M];
    int C[M];
    int ind[M];
    int m[N][N];
    int r = 0;
    int c = 0;
    int xx;
    int yy;
    int zz;
    int v;
    {
      int id7;
      for(id7=(0);id7<(M);id7++){
        rd(A[id7]);A[id7] += (-1);
        rd(B[id7]);B[id7] += (-1);
        rd(C[id7]);C[id7] += (-1);
      }
    }
    for(i=(0);i<(N);i++){
      int j;
      for(j=(0);j<(N);j++){
        m[i][j] = -1;
      }
    }
    for(i=(0);i<(M);i++){
      m[A[i]][B[i]] = m[B[i]][A[i]] = i;
    }
    for(i=(0);i<(M);i++){
      if(C[i] < 0){
        ind[i] = c++;
      }
    }
    for(i=(0);i<(N);i++){
      int j;
      for(j=(i+1);j<(N);j++){
        int k;
        for(k=(j+1);k<(N);k++){
          if(m[i][j]>=0 && m[i][k]>=0 && m[j][k]>=0){
            int l;
            auto id3 = ((m[i][j]));
            auto id13 = (( m[i][k]));
            auto id14 = (( m[j][k]));
            xx=id3;
            yy=id13;
            zz=id14;
            v =max_L(0, C[xx])+max_L(0, C[yy])+max_L(0, C[zz]);
            if(C[xx] >= 0 && C[yy] >= 0 && C[zz] >= 0){
              if(v%3){
                wt_L(-1);
                wt_L('\n');
                goto Q5VJL1cS;
              }
            }
            for(l=(0);l<(c);l++){
              aa[r][l] = 0;
            }
            if(C[xx] < 0){
              aa[r][ind[xx]] = 1;
            }
            if(C[yy] < 0){
              aa[r][ind[yy]] = 1;
            }
            if(C[zz] < 0){
              aa[r][ind[zz]] = 1;
            }
            b[r] = -v;
            r++;
          }
        }
      }
    }
    if(LinearEquation(r,c,aa,b,x) == -1){
      wt_L(-1);
      wt_L('\n');
      continue;
    }
    for(i=(0);i<(M);i++){
      if(C[i] < 0){
        C[i] = (int)x[ind[i]];
      }
    }
    {
      int id8;
      if(M==0){
        wt_L('\n');
      }
      else{
        for(id8=(0);id8<(M-1);id8++){
          wt_L(C[id8]+1);
          wt_L(' ');
        }
        wt_L(C[id8]+1);
        wt_L('\n');
      }
    }
    Q5VJL1cS:;
  }
  return 0;
}
template<class T> inline void wt_L(vector<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(set<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T> inline void wt_L(multiset<T> x){
  int fg = 0;
  for(auto a : x){
    if(fg){
      my_putchar(' ');
    }
    fg = 1;
    wt_L(a);
  }
}
template<class T1, class T2> inline void wt_L(pair<T1,T2> x){
  wt_L(x.first);
  my_putchar(' ');
  wt_L(x.second);
}



































































