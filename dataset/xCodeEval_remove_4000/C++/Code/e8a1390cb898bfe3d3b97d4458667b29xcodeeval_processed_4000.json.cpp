

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
template<class S, class T> inline auto min_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a <= (typename cLtraits_common_type<S,T>::type) b ? a : b;
}
template<class S, class T> inline auto max_L(S a, T b)
-> typename cLtraits_common_type<S,T>::type{
  return (typename cLtraits_common_type<S,T>::type) a >= (typename cLtraits_common_type<S,T>::type) b ? a : b;
}
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
template<class T1> void id12(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
}
inline int id7(){
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
    k = id7();
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
    k = id7();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void rd(long long &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = id7();
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
    k = id7();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
struct id6{
  char buf[1048576];
  int s;
  int e;
  id6(){
    s = 0;
    e = 1048576;
  }
  ~id6(){
    if(s){
      fwrite(buf, 1, s, stdout);
    }
  }
}
;
id6 id16;
void my_putchar(int a){
  if(id16.s == id16.e){
    fwrite(id16.buf, 1, id16.s, stdout);
    id16.s = 0;
  }
  id16.buf[id16.s++] = a;
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template<class T, class S> struct maxflow{
  int node;
  int st;
  int ed;
  int*es;
  int*emem;
  int**edge;
  int**rev;
  int*level;
  int*qq;
  T**flow;
  T eps;
  void malloc(int N){
    int i;
    es = (int*)std::malloc(N*sizeof(int));
    emem = (int*)std::malloc(N*sizeof(int));
    level = (int*)std::malloc(N*sizeof(int));
    qq = (int*)std::malloc(N*sizeof(int));
    edge = (int**)std::malloc(N*sizeof(int*));
    rev = (int**)std::malloc(N*sizeof(int*));
    flow = (T**)std::malloc(N*sizeof(T*));
    for(i=(0);i<(N);i++){
      emem[i] = 0;
      edge[i] = rev[i] = NULL;
      flow[i] = NULL;
    }
  }
  void walloc(int N, void**mem = &wmem){
    int i;
    id3(&es, N, mem);
    id3(&emem, N, mem);
    id3(&level, N, mem);
    id3(&qq, N, mem);
    id3(&edge, N, mem);
    id3(&rev, N, mem);
    id3(&flow, N, mem);
    (*mem) = (flow + N);
  }
  void levelize(void){
    int i;
    int j;
    int k;
    int t;
    int q_st = 0;
    int q_ed = 1;
    for(i=(0);i<(node);i++){
      level[i] = -1;
    }
    level[st] = 0;
    qq[0] = st;
    while(q_st != q_ed){
      i = qq[q_st++];
      t = level[i] + 1;
      for(j=(0);j<(es[i]);j++){
        if(flow[i][j] > eps){
          k = edge[i][j];
          if(level[k]!=-1){
            continue;
          }
          level[k] = t;
          qq[q_ed++] = k;
          if(k==ed){
            return;
          }
        }
      }
    }
  }
  S pushflow(int i, S lim){
    int j;
    int k;
    int ji;
    S s;
    S t;
    S res = 0;
    if(i==ed){
      return lim;
    }
    for(j=(0);j<(es[i]);j++){
      if(flow[i][j] > eps){
        k = edge[i][j];
        if(level[k] != level[i]+1){
          continue;
        }
        s =min_L(lim, (S)flow[i][j]);
        t = pushflow(k, s);
        if(!t){
          continue;
        }
        res += t;
        lim -= t;
        ji = rev[i][j];
        flow[i][j] -= t;
        flow[k][ji] += t;
        if(!lim){
          break;
        }
      }
    }
    if(lim){
      level[i] = -1;
    }
    return res;
  }
  S solve(int st_, int ed_){
    S res = 0;
    st = st_;
    ed = ed_;
    for(;;){
      levelize();
      if(level[ed] == -1){
        break;
      }
      res += pushflow(st, numeric_limits<S>::max());
    }
    return res;
  }
  void init(int N){
    int i;
    node = N;
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    eps = (T)1e-9;
  }
  void memoryExpand(int i, int sz){
    if(sz <= emem[i]){
      return;
    }
    sz =max_L(sz,max_L(3, emem[i]*2));
    emem[i]=sz;
    edge[i] = (int*)realloc(edge[i], sz*sizeof(int));
    rev[i] = (int*)realloc(rev[i], sz*sizeof(int));
    flow[i] = (T*)realloc(flow[i], sz*sizeof(T));
  }
  void addEdge(int n1, int n2, T f1, T f2 = 0){
    int s1 = es[n1]++;
    int s2 = es[n2]++;
    if(s1 >= emem[n1]){
      memoryExpand(n1, es[n1]);
    }
    if(s2 >= emem[n2]){
      memoryExpand(n2, es[n2]);
    }
    edge[n1][s1]=n2;
    edge[n2][s2]=n1;
    flow[n1][s1]=f1;
    flow[n2][s2]=f2;
    rev[n1][s1]=s2;
    rev[n2][s2]=s1;
  }
  void addEdgeAdv(int n1, int n2, T f1, T f2 = 0){
    int s1 = es[n1]++;
    int s2 = es[n2]++;
    edge[n1][s1]=n2;
    edge[n2][s2]=n1;
    flow[n1][s1]=f1;
    flow[n2][s2]=f2;
    rev[n1][s1]=s2;
    rev[n2][s2]=s1;
  }
  void setGraph(int N, int M, int n1[], int n2[], T f1[], T f2[]){
    int i;
    node = N;
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[n1[i]]++;
      es[n2[i]]++;
    }
    for(i=(0);i<(N);i++){
      memoryExpand(i, es[i]);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      addEdgeAdv(n1[i], n2[i], f1[i], f2[i]);
    }
    eps = (T)1e-9;
  }
  void setGraph_w(int N, int M, int n1[], int n2[], T f1[], T f2[], void **mem = wmem){
    int i;
    int j;
    int k;
    node = N;
    for(i=(0);i<(N);i++){
      es[i] = emem[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[n1[i]]++;
      es[n2[i]]++;
    }
    edge[0] = (int*)(*mem);
    int id1 = N;
    for(i=(1);i<(id1);i++){
      edge[i] = edge[i-1] + es[i-1];
    }
    rev[0] = edge[N-1] + es[N-1];
    int id15 = N;
    for(i=(1);i<(id15);i++){
      rev[i] = rev[i-1] + es[i-1];
    }
    flow[0] = (T*)(rev[N-1] + es[N-1]);
    int id0 = N;
    for(i=(1);i<(id0);i++){
      flow[i] = flow[i-1] + es[i-1];
    }
    *mem = (void*)(flow[N-1] + es[N-1]);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      addEdgeAdv(n1[i], n2[i], f1[i], f2[i]);
    }
    eps = (T)1e-9;
  }
}
;
int N;
int M;
int K;
int A[100000];
int B[100000];
long long X[50];
long long Y[50];
int cs;
int command[50];
int t[50];
int tt[50];
int ress;
int res[100];
int ok1[50];
int ok2[50];
maxflow<int,int> flow;
int matchcnt(void){
  int i;
  int node;
  int st;
  int ed;
  node = 2*N;
  st = node++;
  ed = node++;
  flow.init(node);
  for(i=(0);i<(N);i++){
    flow.addEdge(st, i, 1);
  }
  for(i=(0);i<(N);i++){
    flow.addEdge(i+N, ed, 1);
  }
  for(i=(0);i<(M);i++){
    if(ok1[A[i]] && ok2[B[i]]){
      flow.addEdge(A[i], B[i]+N, 1);
    }
  }
  return flow.solve(st, ed);
}
int main(){
  int id14;
  wmem = memarr;
  int i;
  int j;
  int k;
  int cnt;
  long long opt;
  long long tmp;
  rd(N);
  rd(M);
  rd(K);
  {
    int id9;
    for(id9=(0);id9<(M);id9++){
      rd(A[id9]);A[id9] += (-1);
      rd(B[id9]);B[id9] += (-1);
    }
  }
  {
    int id4;
    for(id4=(0);id4<(K);id4++){
      rd(X[id4]);
      rd(Y[id4]);
    }
  }
  flow.malloc(100000);
  for(i=(0);i<(K);i++){
    chmin(Y[i], X[i]);
  }
  for(i=(0);i<(N);i++){
    ok1[i] = ok2[i] = 1;
  }
  cnt = matchcnt();
  while(cnt){
    for(i=(0);i<(N);i++){
      if(ok1[i]){
        ok1[i] = 0;
        tmp = matchcnt();
        if(tmp == cnt-1){
          cnt = tmp;
          command[cs++] = i+1;
          goto APIVbQlN;
        }
        ok1[i] = 1;
      }
    }
    for(i=(0);i<(N);i++){
      if(ok2[i]){
        ok2[i] = 0;
        tmp = matchcnt();
        if(tmp == cnt-1){
          cnt = tmp;
          command[cs++] = -(i+1);
          goto APIVbQlN;
        }
        ok2[i] = 1;
      }
    }
    APIVbQlN:;
  }
  for(id14=(0);id14<(N-1-K);id14++){
    if(cs > 0){
      cs--;
    }
  }
  for(i=(0);i<(cs);i++){
    int id2;
    remove_reference<decltype(Y[id2])>::type id13;
    int id10 = 0;
    int id8;
    if((0) > ((K-i)-1)){
      id13 = 0;
    }
    else{
      for(id2 = 0; id2 <= (K-i)-1; id2++){
        if(id10 == 0){
          id13 = Y[id2];
          id8 = id2;
          id10 = 1;
          continue;
        }
        const auto id5 = Y[id2];
        if(id13 > id5){
          id13 = id5;
          id8 = id2;
        }
      }
    }
    tt[i] = t[i] =id8;
  }
  opt = 0;
  for(i=(0);i<(cs);i++){
    opt += Y[t[i]];
  }
  for(k=(0);k<(K);k++){
    tmp = X[k];
    for(i=(0);i<(cs);i++){
      if(K-1-i < k){
        tmp += Y[tt[i]];
      }
    }
    if(tmp < opt){
      for(i=(0);i<(cs);i++){
        t[i] = tt[i];
      }
      for(i=(0);i<(cs);i++){
        if(K-1-i >= k){
          t[i] = k;
        }
      }
      opt = tmp;
    }
  }
  id12(cs, t);
  j = 0;
  for(i=(0);i<(K);i++){
    while(j < cs && t[j] == i){
      res[ress++] = command[j];
      j++;
    }
    res[ress++] = 0;
  }
  wt_L(ress);
  wt_L('\n');
  {
    int id11;
    if(ress==0){
      wt_L('\n');
    }
    else{
      for(id11=(0);id11<(ress-1);id11++){
        wt_L(res[id11]);
        wt_L(' ');
      }
      wt_L(res[id11]);
      wt_L('\n');
    }
  }
  return 0;
}





































































































































































