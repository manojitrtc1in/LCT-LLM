



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
template<class T> inline void id7(T ***arr, int x, int y, void **mem = &wmem){
  int i;
  id3(arr, x, mem);
  for(i=(0);i<(x);i++){
    id3(&((*arr)[i]), y, mem);
  }
}
template<class T> inline void id7(T ***arr, int x1, int x2, int y1, int y2, void **mem = &wmem){
  int i;
  id3(arr, x1, x2, mem);
  for(i=(x1);i<(x2);i++){
    id3(&((*arr)[i]), y1, y2, mem);
  }
}
template<class T1, class T2> void id9(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2>*arr;
  id3(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second = b[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second;
  }
}
template<class T1, class T2, class T3> void id9(int N, T1 a[], T2 b[], T3 c[], void *mem = wmem){
  int i;
  pair<T1, pair<T2, T3> >*arr;
  id3(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second.first = b[i];
    arr[i].second.second = c[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second.first;
    c[i] = arr[i].second.second;
  }
}
inline int id6(){
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
    k = id6();
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
    k = id6();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void rd(char &c){
  int i;
  for(;;){
    i = id6();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i;
  int sz = 0;
  for(;;){
    i = id6();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = id6();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
}
struct id5{
  char buf[1048576];
  int s;
  int e;
  id5(){
    s = 0;
    e = 1048576;
  }
  ~id5(){
    if(s){
      fwrite(buf, 1, s, stdout);
    }
  }
}
;
id5 id8;
void my_putchar(int a){
  if(id8.s == id8.e){
    fwrite(id8.buf, 1, id8.s, stdout);
    id8.s = 0;
  }
  id8.buf[id8.s++] = a;
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
template<class S> inline void arrInsert(const int k, int &sz, S a[], const S aval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  a[k] = aval;
}
template<class S, class T> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  a[k] = aval;
  b[k] = bval;
}
template<class S, class T, class U> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
}
template<class S, class T, class U, class V> inline void arrInsert(const int k, int &sz, S a[], const S aval, T b[], const T bval, U c[], const U cval, V d[], const V dval){
  int i;
  sz++;
  for(i=sz-1;i>k;i--){
    a[i] = a[i-1];
  }
  for(i=sz-1;i>k;i--){
    b[i] = b[i-1];
  }
  for(i=sz-1;i>k;i--){
    c[i] = c[i-1];
  }
  for(i=sz-1;i>k;i--){
    d[i] = d[i-1];
  }
  a[k] = aval;
  b[k] = bval;
  c[k] = cval;
  d[k] = dval;
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
struct graph{
  int N;
  int*es;
  int**edge;
  void setDirectEdge(int N__, int M, int A[], int B[], void **mem = &wmem){
    int i;
    N = N__;
    id3(&es, N, mem);
    id3(&edge, N, mem);
    id3(&edge[0], M, mem);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[A[i]]++;
    }
    for(i=(0);i<(N);i++){
      id3(&edge[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]++] = B[i];
    }
  }
  graph reverse(void **mem = &wmem){
    int i;
    int j;
    int k;
    graph g;
    g.N = N;
    id3(&g.es, N, mem);
    id3(&g.edge, N, mem);
    for(i=(0);i<(N);i++){
      g.es[i] = 0;
    }
    for(i=(0);i<(N);i++){
      for(j=(0);j<(es[i]);j++){
        g.es[edge[i][j]]++;
      }
    }
    for(i=(0);i<(N);i++){
      id3(&g.edge[i], g.es[i], mem);
    }
    for(i=(0);i<(N);i++){
      g.es[i] = 0;
    }
    for(i=(0);i<(N);i++){
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        g.edge[k][g.es[k]++] = i;
      }
    }
    return g;
  }
  graph reduce(int tn, int ind[], int self_e = 0, int dep_e = 0, void **mem = &wmem){
    int i;
    int j;
    int k;
    int M = 0;
    int x;
    int y;
    graph g;
    void*tmem;
    pair<int,int>*A;
    for(i=(0);i<(N);i++){
      M += es[i];
    }
    tmem = ((char*)(*mem)) + sizeof(int**) * N + sizeof(int*) * N + sizeof(int) * M + 16 * (N+2);
    id3(&A, M, &tmem);
    M = 0;
    for(i=(0);i<(N);i++){
      x = ind[i];
      if(x < 0){
        continue;
      }
      for(j=(0);j<(es[i]);j++){
        y = ind[edge[i][j]];
        if(y < 0){
          continue;
        }
        if(self_e==0 && x==y){
          continue;
        }
        A[M++] = make_pair(x, y);
      }
    }
    if(dep_e==0){
      sort(A, A+M);
      k = 0;
      for(i=(0);i<(M);i++){
        if(k && A[k-1]==A[i]){
          continue;
        }
        A[k++] = A[i];
      }
      M = k;
    }
    g.N = tn;
    id3(&g.es, tn, mem);
    id3(&g.edge, tn, mem);
    for(i=(0);i<(tn);i++){
      g.es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      g.es[A[i].first]++;
    }
    for(i=(0);i<(tn);i++){
      id3(&g.edge[i], g.es[i], mem);
    }
    for(i=(0);i<(tn);i++){
      g.es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      j = A[i].first;
      k = A[i].second;
      g.edge[j][g.es[j]++] = k;
    }
    return g;
  }
  inline int sccDFS(int num[], int st, int mx){
    int i;
    int j;
    num[st]=-2;
    for(i=(0);i<(es[st]);i++){
      j=edge[st][i];
      if(num[j]==-1){
        mx=sccDFS(num,j,mx);
      }
    }
    num[st]=mx;
    return mx+1;
  }
  int scc(int res[], void *mem = wmem){
    int i;
    int j;
    int k;
    int ret=0;
    graph r;
    int*st;
    int st_size;
    int*num;
    int*nrv;
    r = reverse(&mem);
    id3(&st, N, &mem);
    id3(&num, N, &mem);
    id3(&nrv, N, &mem);
    for(i=(0);i<(N);i++){
      res[i] = num[i] = -1;
    }
    k = 0;
    for(i=(0);i<(N);i++){
      if(num[i]==-1){
        k = sccDFS(num,i,k);
      }
    }
    for(i=(0);i<(N);i++){
      nrv[num[i]] = i;
    }
    for(k=N-1;k>=0;k--){
      i=nrv[k];
      if(res[i]>=0){
        continue;
      }
      res[i]=ret;
      st_size=0;
      st[st_size++]=i;
      while(st_size){
        i=st[--st_size];
        for(j=(0);j<(r.es[i]);j++){
          if(res[r.edge[i][j]]==-1){
            res[r.edge[i][j]]=ret;
            st[st_size++]=r.edge[i][j];
          }
        }
      }
      ret++;
    }
    return ret;
  }
  int TopologicalSort(int res[], void *mem=wmem){
    int i;
    int j;
    int k;
    int rs;
    int*deg;
    int*q;
    int qs = 0;
    int qe = 0;
    id3(&deg, N, &mem);
    id3(&q, N, &mem);
    rs = 0;
    for(i=(0);i<(N);i++){
      deg[i] = 0;
    }
    for(i=(0);i<(N);i++){
      for(j=(0);j<(es[i]);j++){
        deg[edge[i][j]]++;
      }
    }
    for(i=(0);i<(N);i++){
      if(deg[i]==0){
        q[qe++] = i;
      }
    }
    while(qs < qe){
      i = q[qs++];
      res[rs++] = i;
      for(j=(0);j<(es[i]);j++){
        k = edge[i][j];
        deg[k]--;
        if(deg[k]==0){
          q[qe++] = k;
        }
      }
    }
    if(rs==N){
      return 1;
    }
    return 0;
  }
}
;
int X;
int Y;
int A[400000];
char**S;
int**ns;
int node;
int mm;
int aa[2000000];
int bb[2000000];
int nd[500000];
int con[500000];
int deg[500000];
int n1;
graph g;
graph tg;
int mn[500000];
int mx[500000];
int done[500000];
int nd1[500000];
int tpo[500000];
void dfs(int n, int cv){
  int i;
  chmin(mn[n], cv);
  chmax(mx[n], cv);
  for(i=(0);i<(tg.es[n]);i++){
    dfs(tg.edge[n][i], cv);
  }
}
int main(){
  int id4;
  wmem = memarr;
  int i;
  int j;
  int k;
  int x;
  int y;
  int z;
  int cnt;
  rd(X);
  rd(Y);
  id7(&S,X,Y+2);
  id7(&ns,X,Y+2);
  {
    int id2;
    for(id2=(0);id2<(X);id2++){
      rd(S[id2]);
    }
  }
  {
    int id0;
    for(id0=(0);id0<(Y);id0++){
      rd(A[id0]);
    }
  }
  for(j=(0);j<(Y);j++){
    k = A[j];
    for(i=(X)-1;i>=(0);i--){
      if(k && S[i][j]=='
        k--;
        S[i][j] = '@';
      }
    }
  }
  for(i=(0);i<(X);i++){
    for(j=(0);j<(Y);j++){
      ns[i][j] = -1;
    }
  }
  for(i=(0);i<(X);i++){
    for(j=(0);j<(Y);j++){
      if(S[i][j] != '.'){
        ns[i][j] = node++;
      }
    }
  }
  for(j=(0);j<(Y);j++){
    x = y = z = -1;
    for(i=(X)-1;i>=(0);i--){
      if(j-1 >= 0 && ns[i][j-1] >= 0){
        x = ns[i][j-1];
      }
      if(j+1 <  Y && ns[i][j+1] >= 0){
        y = ns[i][j+1];
      }
      if(ns[i][j] >= 0){
        if(x >= 0){
          arrInsert(mm, mm, aa, ns[i][j], bb, x);
        }
        if(y >= 0){
          arrInsert(mm, mm, aa, ns[i][j], bb, y);
        }
        if(z >= 0){
          arrInsert(mm, mm, aa, ns[i][j], bb, z);
        }
        if(i-1 >= 0 && ns[i-1][j] >= 0){
          arrInsert(mm, mm, aa, ns[i][j], bb, ns[i-1][j]);
        }
        z = ns[i][j];
      }
    }
  }
  for(i=(0);i<(X);i++){
    for(j=(0);j<(Y);j++){
      if(S[i][j]=='@'){
        nd[ns[i][j]] = 1;
      }
    }
  }
  g.setDirectEdge(node, mm, aa, bb);
  n1 = g.scc(con);
  tg = g.reduce(n1, con);
  for(i=(0);i<(node);i++){
    if(nd[i]){
      nd1[con[i]] = 1;
    }
  }
  for(i=(0);i<(n1);i++){
    for(j=(0);j<(tg.es[i]);j++){
      deg[tg.edge[i][j]]++;
    }
  }
  for(i=(0);i<(n1);i++){
    mn[i] = 1073709056;
    mx[i] = -1;
  }
  cnt = 0;
  for(j=(0);j<(Y);j++){
    for(i=(0);i<(X);i++){
      if(ns[i][j] >= 0){
        k = con[ns[i][j]];
        if(done[k] || deg[k]){
          break;
        }
        done[k] = 1;
        mn[k] = mx[k] = cnt;
        cnt++;
        break;
      }
    }
  }
  tg.TopologicalSort(tpo);
  for(id4=(0);id4<(n1);id4++){
    int id1;
    auto&i = tpo[id4];
    for(id1=(0);id1<(tg.es[i]);id1++){
      auto&j = tg.edge[i][id1];
      chmin(mn[j], mn[i]);
      chmax(mx[j], mx[i]);
    }
  }
  int res = 0;
  id9(n1, mx, mn, nd1);
  k = -1;
  for(i=(0);i<(n1);i++){
    if(nd1[i]){
      if(mn[i] <= k){
        continue;
      }
      res++;
      k = mx[i];
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}













































































































































































