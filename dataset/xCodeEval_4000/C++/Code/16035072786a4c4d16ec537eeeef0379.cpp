#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void walloc2d(T ***arr, int x, int y, void **mem = &wmem){
  int i;
  walloc1d(arr, x, mem);
  for(i=(0);i<(x);i++){
    walloc1d(&((*arr)[i]), y, mem);
  }
}
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2> *arr;
  walloc1d(&arr, N, &mem);
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
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = getchar();
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
    k = getchar();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void wt_L(char a){
  putchar(a);
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
    putchar('-');
  }
  while(s--){
    putchar(f[s]+'0');
  }
}
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
struct unionFind{
  int *d;
  int N;
  int M;
  inline void malloc(const int n){
    d = (int*)std::malloc(n*sizeof(int));
    M = n;
  }
  inline void free(void){
    std::free(d);
  }
  inline void walloc(const int n, void **mem=&wmem){
    walloc1d(&d, n, mem);
    M = n;
  }
  inline void init(const int n){
    int i;
    N = n;
    for(i=(0);i<(n);i++){
      d[i] = -1;
    }
  }
  inline void init(void){
    init(M);
  }
  inline int get(int a){
    int t = a;
    int k;
    while(d[t]>=0){
      t=d[t];
    }
    while(d[a]>=0){
      k=d[a];
      d[a]=t;
      a=k;
    }
    return a;
  }
  inline int connect(int a, int b){
    if(d[a]>=0){
      a=get(a);
    }
    if(d[b]>=0){
      b=get(b);
    }
    if(a==b){
      return 0;
    }
    if(d[a] < d[b]){
      d[a] += d[b];
      d[b] = a;
    }
    else{
      d[b] += d[a];
      d[a] = b;
    }
    return 1;
  }
  inline int operator()(int a){
    return get(a);
  }
  inline int operator()(int a, int b){
    return connect(a,b);
  }
  inline int& operator[](const int a){
    return d[a];
  }
  inline int size(int a){
    a = get(a);
    return -d[a];
  }
  inline int sizeList(int res[]){
    int i;
    int sz=0;
    for(i=(0);i<(N);i++){
      if(d[i]<0){
        res[sz++] = -d[i];
      }
    }
    return sz;
  }
}
;
struct graph{
  int N;
  int *es;
  int **edge;
  void setEdge(int N__, int M, int A[], int B[], void **mem = &wmem){
    int i;
    N = N__;
    walloc1d(&es, N, mem);
    walloc1d(&edge, N, mem);
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      es[A[i]]++;
      es[B[i]]++;
    }
    for(i=(0);i<(N);i++){
      walloc1d(&edge[i], es[i], mem);
    }
    for(i=(0);i<(N);i++){
      es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      edge[A[i]][es[A[i]]++] = B[i];
      edge[B[i]][es[B[i]]++] = A[i];
    }
  }
  graph reduce(int tn, int ind[], int self_e = 0, int dep_e = 0, void **mem = &wmem){
    int i;
    int j;
    int k;
    int M = 0;
    int x;
    int y;
    graph g;
    void *tmem;
    pair<int,int> *A;
    for(i=(0);i<(N);i++){
      M += es[i];
    }
    tmem = ((char*)(*mem)) + sizeof(int**) * N + sizeof(int*) * N + sizeof(int) * M + 16 * (N+2);
    walloc1d(&A, M, &tmem);
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
    walloc1d(&g.es, tn, mem);
    walloc1d(&g.edge, tn, mem);
    for(i=(0);i<(tn);i++){
      g.es[i] = 0;
    }
    for(i=(0);i<(M);i++){
      g.es[A[i].first]++;
    }
    for(i=(0);i<(tn);i++){
      walloc1d(&g.edge[i], g.es[i], mem);
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
  void articulationDFS(int n, int b, int &k, int od[], int lw[], int vs[], int &ress, int res[]){
    int i;
    int j;
    int a = 0;
    int c = 0;
    vs[n] = 1;
    lw[n] = od[n] = k++;
    for(i=(0);i<(es[n]);i++){
      j = edge[n][i];
      if(j==b){
        continue;
      }
      if(!vs[j]){
        c++;
        articulationDFS(j, n, k, od, lw, vs, ress, res);
        chmin(lw[n], lw[j]);
        if(b != -1 && od[n] <= lw[j]){
          a = 1;
        }
      }
      else{
        chmin(lw[n], od[j]);
      }
    }
    if(b == -1 && c >= 2){
      a = 1;
    }
    if(a){
      res[ress++] = n;
    }
  }
  int articulation(int res[], void *mem=wmem){
    int i;
    int k = 0;
    int ress = 0;
    int *od;
    int *lw;
    int *vs;
    walloc1d(&od, N, &mem);
    walloc1d(&lw, N, &mem);
    walloc1d(&vs, N, &mem);
    for(i=(0);i<(N);i++){
      vs[i] = 0;
    }
    for(i=(0);i<(N);i++){
      if(!vs[i]){
        articulationDFS(i, -1, k, od, lw, vs, ress, res);
      }
    }
    return ress;
  }
  long long countIndependenceSet(void *mem = wmem, int skip = 0){
    int i;
    int j;
    int k;
    int x;
    long long res;
    int *deg;
    int *ind;
    long long *pr;
    graph g;
    unionFind uf;
    void *tmem;
    if(N == 0){
      return 1;
    }
    if(N == 1){
      return 2;
    }
    walloc1d(&deg, N, &mem);
    walloc1d(&ind, N, &mem);
    walloc1d(&pr, N, &mem);
    if(!skip){
      k = 0;
      uf.walloc(N, &mem);
      uf.init(N);
      for(i=(0);i<(N);i++){
        for(j=(0);j<(es[i]);j++){
          k += uf(i,edge[i][j]);
        }
      }
      if(k < N-1){
        res = 1;
        for(i=(0);i<(N);i++){
          deg[i] = 0;
        }
        for(i=(0);i<(N);i++){
          deg[uf(i)]++;
        }
        for(x=(0);x<(N);x++){
          if(deg[x]){
            k = 0;
            for(i=(0);i<(N);i++){
              if(uf(i)!=x){
                ind[i] = -1;
                continue;
              }
              ind[i] = k++;
            }
            tmem = mem;
            g = reduce(k, ind, 1, 1, &mem);
            res *= g.countIndependenceSet(mem, 1);
            mem = tmem;
          }
        }
        return res;
      }
    }
    k = articulation(ind);
    for(i=(0);i<(N);i++){
      pr[i] = 0;
    }
    for(i=(0);i<(k);i++){
      pr[ind[i]] += (1LL<<40);
    }
    for(i=(0);i<(N);i++){
      for(j=(0);j<(es[i]);j++){
        pr[i] += (1LL<<20) - es[edge[i][j]];
      }
    }
    {
      int KrdatlYV;
      int ao_dF3pO = 0;
      long long tU__gIr_;
      long long a2conNHc;
      int hCmBdyQB;
      for(KrdatlYV=(0);KrdatlYV<(((N)-1)+1);KrdatlYV++){
        a2conNHc = pr[KrdatlYV];
        if(ao_dF3pO==0 || tU__gIr_<a2conNHc){
          tU__gIr_ = a2conNHc;
          ao_dF3pO = 1;
          hCmBdyQB = KrdatlYV;
        }
      }
      x =hCmBdyQB;
    }
    res = 0;
    k = 0;
    for(i=(0);i<(N);i++){
      if(i == x){
        ind[i] = -1;
        continue;
      }
      ind[i] = k++;
    }
    tmem = mem;
    g = reduce(k, ind, 1, 1, &mem);
    res += g.countIndependenceSet(mem);
    mem = tmem;
    k = 0;
    for(i=(0);i<(N);i++){
      deg[i] = 0;
    }
    deg[x] = 1;
    for(j=(0);j<(es[x]);j++){
      deg[edge[x][j]] = 1;
    }
    for(i=(0);i<(N);i++){
      if(deg[i]){
        ind[i] = -1;
        continue;
      }
      ind[i] = k++;
    }
    g = reduce(k, ind, 1, 1, &mem);
    res += g.countIndependenceSet(mem);
    return res;
  }
  int bipartite(int res[] = NULL, void *mem = wmem){
    int i;
    int j;
    int k;
    int *st;
    int sts;
    if(res==NULL){
      walloc1d(&res, N, &mem);
    }
    walloc1d(&st, N, &mem);
    for(i=(0);i<(N);i++){
      res[i] = -1;
    }
    for(i=(0);i<(N);i++){
      if(res[i]==-1){
        res[i] = 0;
        sts = 0;
        st[sts++] = i;
        while(sts){
          i = st[--sts];
          for(j=(0);j<(es[i]);j++){
            k = edge[i][j];
            if(res[k]==-1){
              res[k] = 1 - res[i];
              st[sts++] = k;
            }
            if(res[i] + res[k] != 1){
              return 0;
            }
          }
        }
      }
    }
    return 1;
  }
}
;
long long solve1(int n, int **mat, void *mem){
  int i;
  int j;
  int k;
  int m;
  int *arr;
  int sz;
  long long res;
  unionFind uf;
  int **smat;
  int *deg;
  if(n == 0){
    return 1;
  }
  if(n == 1){
    return 2;
  }
  walloc1d(&deg, n, &mem);
  walloc1d(&arr, n, &mem);
  uf.walloc(n, &mem);
  uf.init(n);
  for(i=(0);i<(n);i++){
    for(j=(0);j<(n);j++){
      if(mat[i][j]){
        uf(i,j);
      }
    }
  }
  for(i=(0);i<(n);i++){
    if(uf(i) != uf(0)){
      break;
    }
  }
  if(i < n){
    res = 1;
    for(i=(0);i<(n);i++){
      sz = 0;
      for(j=(0);j<(n);j++){
        if(uf(j)==i){
          arr[sz++] = j;
        }
      }
      if(sz==0){
        continue;
      }
      walloc2d(&smat, sz, sz, &mem);
      for(j=(0);j<(sz);j++){
        for(k=(0);k<(sz);k++){
          smat[j][k] = mat[arr[j]][arr[k]];
        }
      }
      res *= solve1(sz, smat, mem);
    }
    return res;
  }
  for(i=(0);i<(n);i++){
    deg[i] = 0;
  }
  for(i=(0);i<(n);i++){
    for(j=(0);j<(n);j++){
      deg[i] += mat[i][j];
    }
  }
  {
    int KL2GvlyY;
    int Q5VJL1cS = 0;
    int e98WHCEY;
    int cTE1_r3A;
    int RZTsC2BF;
    for(KL2GvlyY=(0);KL2GvlyY<(((n)-1)+1);KL2GvlyY++){
      cTE1_r3A = deg[KL2GvlyY];
      if(Q5VJL1cS==0 || e98WHCEY<cTE1_r3A){
        e98WHCEY = cTE1_r3A;
        Q5VJL1cS = 1;
        RZTsC2BF = KL2GvlyY;
      }
    }
    m =RZTsC2BF;
  }
  res = 0;
  sz = 0;
  for(j=(0);j<(n);j++){
    if(j != m && mat[m][j] == 0){
      arr[sz++] = j;
    }
  }
  walloc2d(&smat, sz, sz, &mem);
  for(j=(0);j<(sz);j++){
    for(k=(0);k<(sz);k++){
      smat[j][k] = mat[arr[j]][arr[k]];
    }
  }
  res += solve1(sz, smat, mem);
  sz = 0;
  for(j=(0);j<(n);j++){
    if(j != m){
      arr[sz++] = j;
    }
  }
  walloc2d(&smat, sz, sz, &mem);
  for(j=(0);j<(sz);j++){
    for(k=(0);k<(sz);k++){
      smat[j][k] = mat[arr[j]][arr[k]];
    }
  }
  res += solve1(sz, smat, mem);
  return res;
}
long long solve2(int n, int **mat, void *mem){
  int i;
  int j;
  int k;
  int *arr;
  int sz;
  int *col;
  long long res;
  unionFind uf;
  int **smat;
  int *deg;
  walloc1d(&deg, n, &mem);
  walloc1d(&arr, n, &mem);
  uf.walloc(n, &mem);
  uf.init(n);
  for(i=(0);i<(n);i++){
    for(j=(0);j<(n);j++){
      if(mat[i][j]){
        uf(i,j);
      }
    }
  }
  for(i=(0);i<(n);i++){
    if(uf(i) != uf(0)){
      break;
    }
  }
  if(i < n){
    res = 1;
    for(i=(0);i<(n);i++){
      sz = 0;
      for(j=(0);j<(n);j++){
        if(uf(j)==i){
          arr[sz++] = j;
        }
      }
      if(sz==0){
        continue;
      }
      walloc2d(&smat, sz, sz, &mem);
      for(j=(0);j<(sz);j++){
        for(k=(0);k<(sz);k++){
          smat[j][k] = mat[arr[j]][arr[k]];
        }
      }
      res *= solve2(sz, smat, mem);
    }
    return res;
  }
  walloc1d(&col, n, &mem);
  for(i=(0);i<(n);i++){
    col[i] = -1;
  }
  col[0] = 0;
  for(;;){
    int fg = 0;
    for(i=(0);i<(n);i++){
      if(col[i]!=-1){
        for(j=(0);j<(n);j++){
          if(mat[i][j]){
            if(col[j]==-1){
              col[j] = 1 - col[i];
              fg++;
            }
            if(col[i] + col[j] != 1){
              return 0;
            }
          }
        }
      }
    }
    if(!fg){
      break;
    }
  }
  return 2;
}
int N;
int M;
int A[1000];
int B[1000];
int ind[40];
long long dp[8];
long long nx[8];
long long now[8];
int main(){
  int x;
  wmem = memarr;
  int i;
  int j;
  int k;
  unionFind uf;
  graph og;
  graph g;
  rd(N);
  rd(M);
  {
    int FmcKpFmN;
    for(FmcKpFmN=(0);FmcKpFmN<(M);FmcKpFmN++){
      rd(A[FmcKpFmN]);A[FmcKpFmN] += (-1);
      rd(B[FmcKpFmN]);B[FmcKpFmN] += (-1);
    }
  }
  og.setEdge(N,M,A,B);
  uf.malloc(N);
  uf.init(N);
  for(i=(0);i<(M);i++){
    uf(A[i],B[i]);
  }
  dp[0] = 1;
  for(x=(0);x<(N);x++){
    k = 0;
    for(i=(0);i<(N);i++){
      if(uf(i)!=x){
        ind[i] = -1;
      }
      else{
        ind[i] = k++;
      }
    }
    if(!k){
      continue;
    }
    if(k==1){
      for(i=(0);i<(8);i++){
        now[i] = 0;
      }
      now[0] = 2;
    }
    else{
      g = og.reduce(k, ind, 1, 1);
      now[0] = now[5] = 0;
      now[1] = now[4] = 1;
      now[2] = 2 * g.bipartite();
      now[3] = now[6] = g.countIndependenceSet() - 1 - now[2];
      {
        int xr20shxY;
        long long WYIGIcGE;
        if(7==0){
          WYIGIcGE = 0;
        }
        else{
          WYIGIcGE = now[0];
          for(xr20shxY=(1);xr20shxY<(7);xr20shxY++){
            WYIGIcGE += now[xr20shxY];
          }
        }
        now[7] = (1LL<<k) -WYIGIcGE;
      }
    }
    for(i=(0);i<(8);i++){
      nx[i] = 0;
    }
    for(i=(0);i<(8);i++){
      for(j=(0);j<(8);j++){
        nx[i|j] += dp[i] * now[j];
      }
    }
    for(i=(0);i<(8);i++){
      dp[i] = nx[i];
    }
  }
  wt_L(dp[7]);
  wt_L('\n');
  return 0;
}































































































































































































































































































