

using namespace std;
void*wmem;
char memarr[96000000];
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
template<class T> inline void id1(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void id1(T **arr, int x1, int x2, void **mem = &wmem){
  id1(arr, x2-x1, mem);
  (*arr) -= x1;
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
id4 id11;
void my_putchar(int a){
  if(id11.s == id11.e){
    fwrite(id11.buf, 1, id11.s, stdout);
    id11.s = 0;
  }
  id11.buf[id11.s++] = a;
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
template<class SVAL, class SFUN> struct segtree_rh{
  int N;
  int logN;
  int trueN;
  SVAL*val;
  SFUN*fun;
  char*id7;
  void malloc(int maxN, int once = 0);
  void walloc(int maxN, int once = 0, void **mem = &wmem);
  void free(void);
  SVAL& operator[](int i);
  void setN(int n, int id2 = 1, int dobuild = 1);
  void build(void);
  inline void push_one(int a);
  inline void push(int a);
  inline void build(int a);
  inline void change(int a, int b, SFUN f);
  inline SVAL get(int a, int b);
  template<bool (*f)(SVAL)> int max_right(int a, int mx);
  template<bool (*f)(SVAL)> int max_right(int a);
  template<bool (*f)(SVAL)> int min_left(int b, int mn);
  template<bool (*f)(SVAL)> int min_left(int b);
}
;
int N;
int Q;
int T;
int X;
int Y;
int A[200000];
struct sval{
  int sz;
  long long sm;
  long long mn;
}
;
sval id9(sval a, sval b){
  return {a.sz+b.sz, a.sm+b.sm,min_L(a.mn, b.mn)};
}
sval id0(long long f, sval a){
  return {a.sz, a.sz * f, f};
}
long long id8(long long f, long long g){
  return f;
}
bool search_min(sval a){
  return a.mn > Y;
}
bool search_sum(sval a){
  return a.sm <= Y;
}
segtree_rh<sval, long long> t;
int main(){
  int id6;
  wmem = memarr;
  int i;
  int j;
  int k;
  rd(N);
  rd(Q);
  {
    int id10;
    for(id10=(0);id10<(N);id10++){
      rd(A[id10]);
    }
  }
  t.walloc(N);
  t.setN(N);
  for(i=(0);i<(N);i++){
    t[i] = {1, A[i], A[i]};
  }
  t.build();
  for(id6=(0);id6<(Q);id6++){
    rd(T);
    rd(X);X += (-1);
    rd(Y);
    if(T==1){
      i = t.max_right<search_min>(0,X+1);
      if(i < X+1){
        t.change(i,X+1,Y);
      }
    }
    if(T==2){
      int res = 0;
      while(X < N){
        i = t.max_right<search_sum>(X);
        if(X < i){
          Y -= t.get(X,i).sm;
        }
        res += i - X;
        X = i;
        i = t.max_right<search_min>(X);
        X = i;
      }
      wt_L(res);
      wt_L('\n');
    }
  }
  return 0;
}
template<class SVAL, class SFUN> void segtree_rh<SVAL, SFUN>::malloc(int maxN, int once ){
  int i;
  for(i=1;i<maxN;i*=2){
    ;
  }
  val = new SVAL[2*i];
  fun = new SFUN[i];
  id7 = new char[i];
  if(once){
    setN(maxN);
  }
}
template<class SVAL, class SFUN> void segtree_rh<SVAL, SFUN>::walloc(int maxN, int once , void **mem ){
  int i;
  for(i=1;i<maxN;i*=2){
    ;
  }
  id1(&val, 2*i, mem);
  id1(&fun, i, mem);
  id1(&id7, i, mem);
  if(once){
    setN(maxN);
  }
}
template<class SVAL, class SFUN> void segtree_rh<SVAL, SFUN>::free(void){
  delete [] val;
  delete [] fun;
}
template<class SVAL, class SFUN> SVAL& segtree_rh<SVAL, SFUN>::operator[](int i){
  return val[N+i];
}
template<class SVAL, class SFUN> void segtree_rh<SVAL, SFUN>::setN(int n, int id2 , int dobuild ){
  int i;
  for(i=1,logN=0;i<n;i*=2,logN++){
    ;
  }
  trueN = n;
  N = i;
  if(dobuild){
    build();
  }
}
template<class SVAL, class SFUN> void segtree_rh<SVAL, SFUN>::build(void){
  int i;
  for(i=N-1;i;i--){
    val[i] = id9(val[2*i], val[2*i+1]);
  }
  int id3 = N;
  for(i=(1);i<(id3);i++){
    id7[i] = 0;
  }
}
template<class SVAL, class SFUN> inline void segtree_rh<SVAL, SFUN>::push_one(int a){
  if(id7[a]){
    if(2*a < N){
      if(id7[2*a]){
        fun[2*a] = id8(fun[a], fun[2*a]);
      }
      else{
        fun[2*a] = fun[a];
        id7[2*a] = 1;
      }
    }
    val[2*a] = id0(fun[a], val[2*a]);
    if(2*a+1 < N){
      if(id7[2*a+1]){
        fun[2*a+1] = id8(fun[a], fun[2*a+1]);
      }
      else{
        fun[2*a+1] = fun[a];
        id7[2*a+1] = 1;
      }
    }
    val[2*a+1] = id0(fun[a], val[2*a+1]);
    id7[a] = 0;
  }
}
template<class SVAL, class SFUN> inline void segtree_rh<SVAL, SFUN>::push(int a){
  int i;
  for(i=logN;i;i--){
    push_one(a>>i);
  }
}
template<class SVAL, class SFUN> inline void segtree_rh<SVAL, SFUN>::build(int a){
  while(a > 1){
    a /= 2;
    val[a] = id9(val[2*a], val[2*a+1]);
    if(id7[a]){
      val[a] = id0(fun[a], val[a]);
    }
  }
}
template<class SVAL, class SFUN> inline void segtree_rh<SVAL, SFUN>::change(int a, int b, SFUN f){
  int aa;
  int bb;
  if(a >= b){
    return;
  }
  aa = (a += N);
  bb = (b += N);
  push(a);
  push(b-1);
  if(a%2){
    val[a] = id0(f, val[a]);
    a++;
  }
  if(b%2){
    b--;
    val[b] = id0(f, val[b]);
  }
  a /= 2;
  b /= 2;
  while(a < b){
    if(a%2){
      val[a] = id0(f, val[a]);
      if(id7[a]){
        fun[a] = id8(f, fun[a]);
      }
      else{
        fun[a] = f;
        id7[a] = 1;
      }
      a++;
    }
    if(b%2){
      b--;
      val[b] = id0(f, val[b]);
      if(id7[b]){
        fun[b] = id8(f, fun[b]);
      }
      else{
        fun[b] = f;
        id7[b] = 1;
      }
    }
    a /= 2;
    b /= 2;
  }
  build(aa);
  build(bb-1);
}
template<class SVAL, class SFUN> inline SVAL segtree_rh<SVAL, SFUN>::get(int a, int b){
  SVAL res;
  SVAL tmp;
  int fga = 0;
  int fgb = 0;
  a += N;
  b += N;
  push(a);
  push(b-1);
  while(a < b){
    if(a%2){
      if(fga){
        res = id9(res, val[a]);
      }
      else{
        res = val[a];
        fga = 1;
      }
      a++;
    }
    if(b%2){
      b--;
      if(fgb){
        tmp = id9(val[b], tmp);
      }
      else{
        tmp = val[b];
        fgb = 1;
      }
    }
    a /= 2;
    b /= 2;
  }
  if(fga==1 && fgb==0){
    return res;
  }
  if(fga==0 && fgb==1){
    return tmp;
  }
  if(fga==1 && fgb==1){
    return id9(res, tmp);
  }
  return res;
}
template<class SVAL, class SFUN> template<bool (*f)(SVAL)> int segtree_rh<SVAL, SFUN>::max_right(int a, int mx){
  int fg = 0;
  int ta = a;
  int sz = 1;
  SVAL cur;
  SVAL tmp;
  if(a>=mx){
    return mx;
  }
  a += N;
  push(a);
  for(;;){
    while(a%2==0){
      a /= 2;
      sz *= 2;
    }
    if(ta + sz <= mx){
      if(fg==0){
        tmp = val[a];
      }
      else{
        tmp = id9(cur, val[a]);
      }
    }
    if(ta + sz > mx || !f(tmp)){
      while(a < N){
        push_one(a);
        a *= 2;
        sz /= 2;
        if(ta + sz <= mx){
          if(fg==0){
            tmp = val[a];
          }
          else{
            tmp = id9(cur, val[a]);
          }
        }
        if(ta + sz <= mx && f(tmp)){
          fg = 1;
          cur = tmp;
          a++;
          ta += sz;
        }
      }
      return a - N;
    }
    fg = 1;
    cur = tmp;
    if((a & (a+1)) == 0){
      break;
    }
    a++;
    ta += sz;
  }
  return mx;
}
template<class SVAL, class SFUN> template<bool (*f)(SVAL)> int segtree_rh<SVAL, SFUN>::max_right(int a){
  return max_right<f>(a, trueN);
}
template<class SVAL, class SFUN> template<bool (*f)(SVAL)> int segtree_rh<SVAL, SFUN>::min_left(int b, int mn){
  int fg = 0;
  int tb = b;
  int sz = 1;
  SVAL cur;
  SVAL tmp;
  if(b <= mn){
    return mn;
  }
  b += N;
  push(b-1);
  for(;;){
    while(b%2==0){
      b /= 2;
      sz *= 2;
    }
    if(tb - sz >= mn){
      if(fg==0){
        tmp = val[b-1];
      }
      else{
        tmp = id9(val[b-1], cur);
      }
    }
    if(tb - sz < mn || !f(tmp)){
      while(b-1 < N){
        push_one(b-1);
        b *= 2;
        sz /= 2;
        if(tb - sz >= mn){
          if(fg==0){
            tmp = val[b-1];
          }
          else{
            tmp = id9(val[b-1], cur);
          }
        }
        if(tb - sz >= mn && f(tmp)){
          fg = 1;
          cur = tmp;
          b--;
          tb -= sz;
        }
      }
      return b - N;
    }
    fg = 1;
    cur = tmp;
    b--;
    tb -= sz;
    if(tb <= mn){
      break;
    }
  }
  return mn;
}
template<class SVAL, class SFUN> template<bool (*f)(SVAL)> int segtree_rh<SVAL, SFUN>::min_left(int b){
  return min_left<f>(b, 0);
}





















































































































