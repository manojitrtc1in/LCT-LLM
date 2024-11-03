

using namespace std;
void*wmem;
char memarr[96000000];
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
template<class T> inline void id27(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T> inline void id27(T **arr, int x1, int x2, void **mem = &wmem){
  id27(arr, x2-x1, mem);
  (*arr) -= x1;
}
template<class T1> void id11(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
}
template<class T1, class T2> void id11(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2>*arr;
  id27(&arr, N, &mem);
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
inline int id38(){
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
    k = id38();
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
    k = id38();
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
    k = id38();
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
    k = id38();
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
struct id17{
  char buf[1048576];
  int s;
  int e;
  id17(){
    s = 0;
    e = 1048576;
  }
  ~id17(){
    if(s){
      fwrite(buf, 1, s, stdout);
    }
  }
}
;
id17 id22;
void my_putchar(int a){
  if(id22.s == id22.e){
    fwrite(id22.buf, 1, id22.s, stdout);
    id22.s = 0;
  }
  id22.buf[id22.s++] = a;
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
template<class T> struct id31{
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
  int id1;
  int id35;
  T*id29;
  void setSum(void){
    int i;
    id1 = 1;
    if(id35 < n+1){
      delete[] id29;
      id29 = new T[n+1];
      id35 = n+1;
    }
    id29[0] = 0;
    for(i=(0);i<(n);i++){
      id29[i+1] = id29[i] + d[i];
    }
  }
  T getSum(int i, int j){
    if(id1==0){
      setSum();
    }
    return id29[j+1] - id29[i];
  }
  int id19;
  int id18;
  int*id5;
  void setConstLenLeft(void){
    int i;
    id19 = 1;
    if(id18 < n){
      delete[] id5;
      id5 = new int[n];
      id18 = n;
    }
    for(i=(0);i<(n);i++){
      id5[i] = 1;
    }
    for(i=(1);i<(n);i++){
      if(d[i]==d[i-1]){
        id5[i] = id5[i-1] + 1;
      }
    }
  }
  int ConstLenLeft(int st, T val){
    if(!id19){
      setConstLenLeft();
    }
    if(val != d[st]){
      return 0;
    }
    return id5[st];
  }
  int ConstLenLeft(int st){
    if(!id19){
      setConstLenLeft();
    }
    return id5[st];
  }
  int ConstLenLeftCyclic(int st, T val){
    if(!id19){
      setConstLenLeft();
    }
    st %= n;
    if(st < 0){
      st += n;
    }
    if(val != d[st]){
      return 0;
    }
    if(id5[st] != st+1 || d[st] != d[n-1]){
      return id5[st];
    }
    if(id5[n-1] == n){
      return 1073709056;
    }
    return id5[st] + id5[n-1];
  }
  int ConstLenLeftCyclic(int st){
    if(!id19){
      setConstLenLeft();
    }
    st %= n;
    if(st < 0){
      st += n;
    }
    if(id5[st] != st+1 || d[st] != d[n-1]){
      return id5[st];
    }
    if(id5[n-1] == n){
      return 1073709056;
    }
    return id5[st] + id5[n-1];
  }
  int id39;
  int id24;
  int*id36;
  void setConstLenRight(void){
    int i;
    id39 = 1;
    if(id24 < n){
      delete[] id36;
      id36 = new int[n];
      id24 = n;
    }
    for(i=(0);i<(n);i++){
      id36[i] = 1;
    }
    for(i=(n-1)-1;i>=(0);i--){
      if(d[i]==d[i+1]){
        id36[i] = id36[i+1] + 1;
      }
    }
  }
  int ConstLenRight(int st, T val){
    if(!id39){
      setConstLenRight();
    }
    if(val != d[st]){
      return 0;
    }
    return id36[st];
  }
  int ConstLenRight(int st){
    if(!id39){
      setConstLenRight();
    }
    return id36[st];
  }
  int ConstLenRightCyclic(int st, T val){
    if(!id39){
      setConstLenRight();
    }
    if(val != d[st]){
      return 0;
    }
    st %= n;
    if(st < 0){
      st += n;
    }
    if(id36[st] != n-st || d[st] != d[0]){
      return id36[st];
    }
    if(id36[0] == n){
      return 1073709056;
    }
    return id36[st] + id36[0];
  }
  int ConstLenRightCyclic(int st){
    if(!id39){
      setConstLenRight();
    }
    st %= n;
    if(st < 0){
      st += n;
    }
    if(id36[st] != n-st || d[st] != d[0]){
      return id36[st];
    }
    if(id36[0] == n){
      return 1073709056;
    }
    return id36[st] + id36[0];
  }
  int id6;
  int id28;
  int*dhist;
  int*dhists;
  T id16;
  T id20;
  void setDHist(void){
    int i;
    int len;
    id6 = 1;
    if(n==0){
      return;
    }
    id16 = id20 = d[0];
    for(i=(1);i<(n);i++){
      if(id16 > d[i]){
        id16 = d[i];
      }
      if(id20 < d[i]){
        id20 = d[i];
      }
    }
    len = id20 - id16 + 1;
    if(id28 < len){
      delete[] dhist;
      dhist = new int[len];
      delete[] dhists;
      dhists = new int[len+1];
      id28 = len;
    }
    for(i=(0);i<(len);i++){
      dhist[i] = 0;
    }
    for(i=(0);i<(n);i++){
      dhist[d[i] - id16]++;
    }
    dhists[0] = 0;
    for(i=(0);i<(len);i++){
      dhists[i+1] = dhists[i] + dhist[i];
    }
  }
  int dHist(T x){
    if(id6==0){
      setDHist();
    }
    if(n == 0 || x < id16 || x > id20){
      return 0;
    }
    return dhist[x - id16];
  }
  int dHist(T x, T y){
    if(id6==0){
      setDHist();
    }
    if(x < id16){
      x = id16;
    }
    if(y > id20){
      y = id20;
    }
    if(n == 0 || x > y){
      return 0;
    }
    return dhists[y-id16+1] - dhists[x-id16];
  }
  int id14;
  int id21;
  T*shist;
  void setSHist(void){
    int i;
    id14 = 1;
    if(id21 < n){
      delete[] shist;
      shist = new T[n];
      id21 = n;
    }
    for(i=(0);i<(n);i++){
      shist[i] = d[i];
    }
    std::sort(shist, shist + n);
  }
  int sHist(T x){
    if(id14==0){
      setSHist();
    }
    auto r = equal_range(shist, shist+n, x);
    return r.second - r.first;
  }
  int sHist(T x, T y){
    if(id14==0){
      setSHist();
    }
    return upper_bound(shist, shist+n, y) - lower_bound(shist, shist+n, x);
  }
  int id40;
  int id25;
  int*prevLE;
  int setPrevLE(void *mem = wmem){
    int i;
    int s = 0;
    int*st;
    id40 = 1;
    if(id25 < n){
      delete[] prevLE;
      prevLE = new int[n];
      id25 = n;
    }
    id27(&st, n, &mem);
    for(i=(0);i<(n);i++){
      while(s && d[st[s-1]] > d[i]){
        s--;
      }
      if(s==0){
        prevLE[i] = -1;
      }
      else{
        prevLE[i] = st[s-1];
      }
      st[s++] = i;
    }
  }
  int PrevLE(int i){
    if(id40==0){
      setPrevLE();
    }
    return prevLE[i];
  }
  int id41;
  int id9;
  int*prevLT;
  int setPrevLT(void *mem = wmem){
    int i;
    int s = 0;
    int*st;
    id41 = 1;
    if(id9 < n){
      delete[] prevLT;
      prevLT = new int[n];
      id9 = n;
    }
    id27(&st, n, &mem);
    for(i=(0);i<(n);i++){
      while(s && d[st[s-1]] >= d[i]){
        s--;
      }
      if(s==0){
        prevLT[i] = -1;
      }
      else{
        prevLT[i] = st[s-1];
      }
      st[s++] = i;
    }
  }
  int PrevLT(int i){
    if(id41==0){
      setPrevLT();
    }
    return prevLT[i];
  }
  int id12;
  int id2;
  int*prevGE;
  int setPrevGE(void *mem = wmem){
    int i;
    int s = 0;
    int*st;
    id12 = 1;
    if(id2 < n){
      delete[] prevGE;
      prevGE = new int[n];
      id2 = n;
    }
    id27(&st, n, &mem);
    for(i=(0);i<(n);i++){
      while(s && d[st[s-1]] < d[i]){
        s--;
      }
      if(s==0){
        prevGE[i] = -1;
      }
      else{
        prevGE[i] = st[s-1];
      }
      st[s++] = i;
    }
  }
  int PrevGE(int i){
    if(id12==0){
      setPrevGE();
    }
    return prevGE[i];
  }
  int id0;
  int id37;
  int*prevGT;
  int setPrevGT(void *mem = wmem){
    int i;
    int s = 0;
    int*st;
    id0 = 1;
    if(id37 < n){
      delete[] prevGT;
      prevGT = new int[n];
      id37 = n;
    }
    id27(&st, n, &mem);
    for(i=(0);i<(n);i++){
      while(s && d[st[s-1]] <= d[i]){
        s--;
      }
      if(s==0){
        prevGT[i] = -1;
      }
      else{
        prevGT[i] = st[s-1];
      }
      st[s++] = i;
    }
  }
  int PrevGT(int i){
    if(id0==0){
      setPrevGT();
    }
    return prevGT[i];
  }
  int id26;
  int id8;
  int*nextLE;
  int setNextLE(void *mem = wmem){
    int i;
    int s = 0;
    int*st;
    id26 = 1;
    if(id8 < n){
      delete[] nextLE;
      nextLE = new int[n];
      id8 = n;
    }
    id27(&st, n, &mem);
    for(i=(n)-1;i>=(0);i--){
      while(s && d[st[s-1]] > d[i]){
        s--;
      }
      if(s==0){
        nextLE[i] = n;
      }
      else{
        nextLE[i] = st[s-1];
      }
      st[s++] = i;
    }
  }
  int NextLE(int i){
    if(id26==0){
      setNextLE();
    }
    return nextLE[i];
  }
  int id33;
  int id3;
  int*nextLT;
  int setNextLT(void *mem = wmem){
    int i;
    int s = 0;
    int*st;
    id33 = 1;
    if(id3 < n){
      delete[] nextLT;
      nextLT = new int[n];
      id3 = n;
    }
    id27(&st, n, &mem);
    for(i=(n)-1;i>=(0);i--){
      while(s && d[st[s-1]] >= d[i]){
        s--;
      }
      if(s==0){
        nextLT[i] = n;
      }
      else{
        nextLT[i] = st[s-1];
      }
      st[s++] = i;
    }
  }
  int NextLT(int i){
    if(id33==0){
      setNextLT();
    }
    return nextLT[i];
  }
  int id10;
  int id42;
  int*nextGE;
  int setNextGE(void *mem = wmem){
    int i;
    int s = 0;
    int*st;
    id10 = 1;
    if(id42 < n){
      delete[] nextGE;
      nextGE = new int[n];
      id42 = n;
    }
    id27(&st, n, &mem);
    for(i=(n)-1;i>=(0);i--){
      while(s && d[st[s-1]] < d[i]){
        s--;
      }
      if(s==0){
        nextGE[i] = n;
      }
      else{
        nextGE[i] = st[s-1];
      }
      st[s++] = i;
    }
  }
  int NextGE(int i){
    if(id10==0){
      setNextGE();
    }
    return nextGE[i];
  }
  int id23;
  int id34;
  int*nextGT;
  int setNextGT(void *mem = wmem){
    int i;
    int s = 0;
    int*st;
    id23 = 1;
    if(id34 < n){
      delete[] nextGT;
      nextGT = new int[n];
      id34 = n;
    }
    id27(&st, n, &mem);
    for(i=(n)-1;i>=(0);i--){
      while(s && d[st[s-1]] <= d[i]){
        s--;
      }
      if(s==0){
        nextGT[i] = n;
      }
      else{
        nextGT[i] = st[s-1];
      }
      st[s++] = i;
    }
  }
  int NextGT(int i){
    if(id23==0){
      setNextGT();
    }
    return nextGT[i];
  }
  void reset(){
    id1 = 0;
    id19 = 0;
    id39 = 0;
    id6 = 0;
    id40 = id41 = id12 = id0 = 0;
    id26 = id33 = id10 = id23 = 0;
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
  void constructor(){
    n = mem = 0;
    d = NULL;
    id1 = 0;
    id35 = 0;
    id29 = NULL;
    id19 = 0;
    id18 = 0;
    id5 = NULL;
    id39 = 0;
    id24 = 0;
    id36 = NULL;
    id6 = 0;
    id28 = 0;
    dhist = NULL;
    dhists = NULL;
    id14 = 0;
    id21 = 0;
    shist = NULL;
    id40 = id41 = id12 = id0 = 0;
    id25 = id9 = id2 = id37 = 0;
    prevLE = prevLT = prevGE = prevGT = NULL;
    id26 = id33 = id10 = id23 = 0;
    id8 = id3 = id42 = id34 = 0;
    nextLE = nextLT = nextGE = nextGT = NULL;
  }
  void constructor(int nn){
    constructor();
    malloc(nn);
  }
  void destructor(){
    delete[] d;
    d = NULL;
    mem = n = 0;
    id1 = 0;
    id35 = 0;
    delete[] id29;
    id29 = NULL;
    id19 = 0;
    id18 = 0;
    delete[] id5;
    id5 = NULL;
    id39 = 0;
    id24 = 0;
    delete[] id36;
    id36 = NULL;
    id6 = 0;
    id28 = 0;
    delete[] dhist;
    delete[] dhists;
    dhist = NULL;
    id14 = 0;
    id21 = 0;
    delete[] shist;
    shist = NULL;
    id40 = id41 = id12 = id0 = 0;
    id25 = id9 = id2 = id37 = 0;
    delete[] prevLE;
    delete[] prevLT;
    delete[] prevGE;
    delete[] prevGT;
    prevLE = prevLT = prevGE = prevGT = NULL;
    id26 = id33 = id10 = id23 = 0;
    id8 = id3 = id42 = id34 = 0;
    delete[] nextLE;
    delete[] nextLT;
    delete[] nextGE;
    delete[] nextGT;
    nextLE = nextLT = nextGE = nextGT = NULL;
  }
  id31(){
    constructor();
  }
  id31(int nn){
    constructor(nn);
  }
  ~id31(){
    destructor();
  }
}
;
int N;
int C;
int Q;
int A[30000];
int X;
long long Y;
long long cnt[5][30000+2];
int sz;
int lis[5];
int ind[5];
int usz[30000+2];
int ulis[30000+2][5];
int dsz[30000+2];
int dlis[30000+2][5];
id31<__int128_t> skip[5];
int main(){
  int id30;
  wmem = memarr;
  int i;
  int j;
  int k;
  int c;
  for(i=(0);i<(5);i++){
    cnt[i][0] = 1;
  }
  for(i=(0);i<(5);i++){
    for(k=(0);k<(30000);k++){
      for(j=(0);j<(min_L(k, i)+1);j++){
        cnt[i][k+1] += cnt[i-j][k-j];
        if(cnt[i][k+1] > 2000000000000000000LL){
          cnt[i][k+1] = 2000000000000000000LL;
        }
      }
    }
  }
  int id4 = rd_int();
  for(id30=(0);id30<(id4);id30++){
    int id13;
    rd(N);
    rd(C);
    rd(Q);
    {
      int id15;
      for(id15=(0);id15<(N);id15++){
        rd(A[id15]);
      }
    }
    for(k=(0);k<(N);k++){
      sz = 0;
      for(i=(0);i<(C+1);i++){
        if(k+i < N){
          arrInsert(sz, sz, ind, i, lis, A[k+i]);
        }
      }
      id11(sz, lis, ind);
      j = usz[k] = dsz[k] = 0;
      for(i=(0);i<(sz);i++){
        if(ind[i] == 0){
          j++;
          continue;
        }
        if(j==0){
          ulis[k][usz[k]++] = ind[i];
        }
        if(j==1){
          dlis[k][dsz[k]++] = ind[i];
        }
      }
    }
    for(c=(0);c<(C+1);c++){
      skip[c].setN(N);
      for(k=(0);k<(N);k++){
        skip[c][k] = 0;
        for(i=(0);i<(usz[k]);i++){
          if(c >= ulis[k][i]){
            skip[c][k] += cnt[c-ulis[k][i]][N-k-ulis[k][i]-1];
          }
        }
      }
    }
    for(id13=(0);id13<(Q);id13++){
      rd(X);X += (-1);
      rd(Y);Y += (-1);
      if(Y >= cnt[C][N]){
        wt_L(-1);
        wt_L('\n');
        continue;
      }
      c = C;
      for(k=(0);k<(N);k++){
        int id43;
        int id32;
        int id7;
        id43 = k-1;
        id32 = N-1;
        while(id43 < id32){
          if((id43 + id32)%2==0){
            id7 = (id43 + id32) / 2;
          }
          else{
            id7 = (id43 + id32 + 1) / 2;
          }
          if(skip[c].getSum(k,id7) <= Y  &&  Y < skip[c].getSum(k,id7) + cnt[c][N-id7-1]){
            id43 = id7;
          }
          else{
            id32 = id7 - 1;
          }
        }
        i =id32+ 1;
        if(X < i){
          wt_L(A[X]);
          wt_L('\n');
          break;
        }
        Y -= skip[c].getSum(k, i-1);
        k = i;
        for(i=(0);i<(usz[k]);i++){
          if(c >= ulis[k][i]){
            if(Y < cnt[c-ulis[k][i]][N-k-ulis[k][i]-1]){
              if(X <= k + ulis[k][i]){
                wt_L(A[k+ulis[k][i]-(X-k)]);
                wt_L('\n');
                goto aTqQ6rt8;
              }
              c -= ulis[k][i];
              k += ulis[k][i];
              goto zT28qSmp;
            }
            else{
              Y -= cnt[c-ulis[k][i]][N-k-ulis[k][i]-1];
            }
          }
        }
        if(Y < cnt[c][N-k-1]){
          if(X == k){
            wt_L(A[k]);
            wt_L('\n');
            break;
          }
          continue;
        }
        else{
          Y -= cnt[c][N-k-1];
        }
        for(i=(0);i<(dsz[k]);i++){
          if(c >= dlis[k][i]){
            if(Y < cnt[c-dlis[k][i]][N-k-dlis[k][i]-1]){
              if(X <= k + dlis[k][i]){
                wt_L(A[k+dlis[k][i]-(X-k)]);
                wt_L('\n');
                goto aTqQ6rt8;
              }
              c -= dlis[k][i];
              k += dlis[k][i];
              goto zT28qSmp;
            }
            else{
              Y -= cnt[c-dlis[k][i]][N-k-dlis[k][i]-1];
            }
          }
        }
        zT28qSmp:;
      }
      aTqQ6rt8:;
    }
  }
  return 0;
}































































































































































