



using namespace std;
void*wmem;
char memarr[96000000];
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
struct Rand{
  unsigned x;
  unsigned y;
  unsigned z;
  unsigned w;
  Rand(void){
    x=123456789;
    y=362436069;
    z=521288629;
    w=(unsigned)time(NULL);
  }
  Rand(unsigned seed){
    x=123456789;
    y=362436069;
    z=521288629;
    w=seed;
  }
  inline unsigned get(void){
    unsigned t;
    t = (x^(x<<11));
    x=y;
    y=z;
    z=w;
    w = (w^(w>>19))^(t^(t>>8));
    return w;
  }
  inline double getUni(void){
    return get()/4294967296.0;
  }
  inline int get(int a){
    return (int)(a*getUni());
  }
  inline int get(int a, int b){
    return a+(int)((b-a+1)*getUni());
  }
  inline long long get(long long a){
    return(long long)(a*getUni());
  }
  inline long long get(long long a, long long b){
    return a+(long long)((b-a+1)*getUni());
  }
  inline double get(double a, double b){
    return a+(b-a)*getUni();
  }
  inline int getExp(int a){
    return(int)(exp(getUni()*log(a+1.0))-1.0);
  }
  inline int getExp(int a, int b){
    return a+(int)(exp(getUni()*log((b-a+1)+1.0))-1.0);
  }
}
;
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
id5 id7;
void my_putchar(int a){
  if(id7.s == id7.e){
    fwrite(id7.buf, 1, id7.s, stdout);
    id7.s = 0;
  }
  id7.buf[id7.s++] = a;
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
struct unionFind{
  int*d;
  int N;
  int M;
  inline void malloc(const int n){
    d = (int*)std::malloc(n*sizeof(int));
    M = n;
  }
  inline void malloc(const int n, const int fg){
    d = (int*)std::malloc(n*sizeof(int));
    M = n;
    if(fg){
      init(n);
    }
  }
  inline void free(void){
    std::free(d);
  }
  inline void walloc(const int n, void **mem=&wmem){
    id4(&d, n, mem);
    M = n;
  }
  inline void walloc(const int n, const int fg, void **mem=&wmem){
    id4(&d, n, mem);
    M = n;
    if(fg){
      init(n);
    }
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
  inline int comp(int res[], void *mem = wmem){
    int i;
    int sz=0;
    int*cnt;
    id4(&cnt, N, &mem);
    for(i=(0);i<(N);i++){
      cnt[i] = 0;
    }
    for(i=(0);i<(N);i++){
      cnt[get(i)] = 1;
    }
    for(i=(0);i<(N);i++){
      if(cnt[i]){
        cnt[i] = sz++;
      }
    }
    for(i=(0);i<(N);i++){
      res[i] = cnt[get(i)];
    }
    return sz;
  }
}
;
int N;
int M[2];
int A[2][100000];
int B[2][100000];
int ress;
int res1[100000];
int res2[100000];
vector<int> g[2][100000];
set<int> s[2];
unionFind uf[2];
int sz;
int arr[100000];
int con(int ind, int x, int y){
  int i;
  int z;
  x = uf[ind](x);
  y = uf[ind](y);
  if(x==y){
    return 0;
  }
  uf[ind](x, y);
  z = uf[ind](x);
  if(z==y){
    swap(x,y);
  }
  s[ind].erase(y);
  for(i=(0);i<(g[ind][y].size());i++){
    g[ind][z].push_back(g[ind][y][i]);
  }
  return 1;
}
int main(){
  int id9;
  wmem = memarr;
  int i;
  int j;
  int ind;
  rd(N);
  {
    int id2;
    for(id2=(0);id2<(2);id2++){
      rd(M[id2]);
    }
  }
  {
    int id1;
    for(id1=(0);id1<(M[0]);id1++){
      rd(A[0][id1]);A[0][id1] += (-1);
      rd(B[0][id1]);B[0][id1] += (-1);
    }
  }
  {
    int id0;
    for(id0=(0);id0<(M[1]);id0++){
      rd(A[1][id0]);A[1][id0] += (-1);
      rd(B[1][id0]);B[1][id0] += (-1);
    }
  }
  for(ind=(0);ind<(2);ind++){
    uf[ind].walloc(N,1);
    for(i=(0);i<(N);i++){
      s[ind].insert(i);
    }
    for(i=(0);i<(N);i++){
      g[ind][i].push_back(i);
    }
    for(i=(0);i<(M[ind]);i++){
      con(ind,A[ind][i],B[ind][i]);
    }
  }
  Rand rnd;
  for(id9=(0);id9<(1000000);id9++){
    i = rnd.get(N);
    j = rnd.get(N);
    if(uf[0](i) == uf[0](j)){
      continue;
    }
    if(uf[1](i) == uf[1](j)){
      continue;
    }
    con(0,i,j);
    con(1,i,j);
    arrInsert(ress, ress, res1, i, res2, j);
  }
  for(i=(0);i<(N);i++){
    int id8;
    if(i && uf[0](i)==uf[0](i-1) && uf[1](i)==uf[1](i-1)){
      continue;
    }
    if(uf[0].size(i) >= uf[1].size(i)){
      ind =0;
    }
    else{
      ind =1;
    }
    sz = 0;
    for(int ss : s[ind]){
      int id3;
      if(uf[ind](ss) == uf[ind](i)){
        continue;
      }
      for(id3=(0);id3<(g[ind][ss].size());id3++){
        auto&j = g[ind][ss][id3];
        arr[sz++] = j;
      }
    }
    for(id8=(0);id8<(sz);id8++){
      auto&j = arr[id8];
      if(uf[0](i) == uf[0](j)){
        continue;
      }
      if(uf[1](i) == uf[1](j)){
        continue;
      }
      con(0,i,j);
      con(1,i,j);
      arrInsert(ress, ress, res1, i, res2, j);
    }
  }
  wt_L(ress);
  wt_L('\n');
  for(i=(0);i<(ress);i++){
    wt_L(res1[i]+1);
    wt_L(' ');
    wt_L(res2[i]+1);
    wt_L('\n');
  }
  return 0;
}





































































































































