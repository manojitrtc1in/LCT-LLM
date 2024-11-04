#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
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
int **mat;
long long dp[8];
long long nx[8];
long long now[8];
int main(){
  int FmcKpFmN;
  wmem = memarr;
  int i;
  int j;
  int k;
  long long res = 1;
  long long t1;
  long long t2;
  long long t3;
  rd(N);
  rd(M);
  walloc2d(&mat,N,N);
  for(i=(0);i<(N);i++){
    for(j=(0);j<(N);j++){
      mat[i][j] = 0;
    }
  }
  for(FmcKpFmN=(0);FmcKpFmN<(M);FmcKpFmN++){
    rd(i);i += (-1);
    rd(j);j += (-1);
    mat[i][j] = mat[j][i] = 1;
  }
  dp[0] = 1;
  {
    int *arr;
    int sz;
    unionFind uf;
    int **smat;
    walloc1d(&arr, N);
    uf.walloc(N);
    uf.init(N);
    for(i=(0);i<(N);i++){
      for(j=(0);j<(N);j++){
        if(mat[i][j]){
          uf(i,j);
        }
      }
    }
    for(i=(0);i<(N);i++){
      if(uf(i) != uf(0)){
        break;
      }
    }
    res = 1;
    for(i=(0);i<(N);i++){
      sz = 0;
      for(j=(0);j<(N);j++){
        if(uf(j)==i){
          arr[sz++] = j;
        }
      }
      if(sz==0){
        continue;
      }
      walloc2d(&smat, sz, sz);
      for(j=(0);j<(sz);j++){
        for(k=(0);k<(sz);k++){
          smat[j][k] = mat[arr[j]][arr[k]];
        }
      }
      if(sz==1){
        for(j=(0);j<(8);j++){
          now[j] = 0;
        }
        now[0] = 2;
      }
      else{
        t1 = 1LL<<sz;
        t2 = solve1(sz, smat, wmem);
        t3 = solve2(sz, smat, wmem);
        now[0] = 0;
        now[1] = 1;
        now[2] = t3;
        now[4] = 1;
        now[3] = t2 - now[1] - now[2];
        now[6] = t2 - now[1] - now[2];
        now[5] = 0;
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
          now[7] = (1LL<<sz) -WYIGIcGE;
        }
      }
      for(j=(0);j<(8);j++){
        nx[j] = 0;
      }
      for(j=(0);j<(8);j++){
        for(k=(0);k<(8);k++){
          nx[j|k] += dp[j] * now[k];
        }
      }
      for(j=(0);j<(8);j++){
        dp[j] = nx[j];
      }
    }
  }
  res = dp[7];
  wt_L(res);
  wt_L('\n');
  return 0;
}













































































































































































































































































































































