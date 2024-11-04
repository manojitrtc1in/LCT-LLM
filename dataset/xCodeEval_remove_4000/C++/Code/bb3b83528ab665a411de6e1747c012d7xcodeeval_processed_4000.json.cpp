

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
inline int id8(){
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
    k = id8();
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
    k = id8();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
struct id7{
  char buf[1048576];
  int s;
  int e;
  id7(){
    s = 0;
    e = 1048576;
  }
  ~id7(){
    if(s){
      fwrite(buf, 1, s, stdout);
    }
  }
}
;
id7 id14;
void my_putchar(int a){
  if(id14.s == id14.e){
    fwrite(id14.buf, 1, id14.s, stdout);
    id14.s = 0;
  }
  id14.buf[id14.s++] = a;
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
template<class EnterExit> class id10{
  public:
  EnterExit* a;
  int* L;
  int* R;
  int* E;
  int* IDX;
  int qsz;
  int lmt;
  int blocksz;
  int _init;
  int cur;
  int solid_state;
  int _update;
  void init(bool id1, int isupdated){
    int i;
    _update = 0;
    _init = 1;
    if(isupdated){
      _update = 1;
    }
    if(id1){
      id5(&L, qsz, &wmem);
      id5(&R, qsz, &wmem);
      if(isupdated){
        id5(&E, qsz, &wmem);
      }
      id5(&IDX, qsz, &wmem);
      this->solid_state = 1;
    }
    else{
      L = new int[qsz];
      R = new int[qsz];
      if(isupdated){
        E = new int[qsz];
      }
      IDX = new int[qsz];
      this->solid_state = 0;
    }
    for(i=(0);i<(qsz);i++){
      L[i] = R[i]   = 0;
    }
    if(isupdated){
      E[i] = 0;
    }
  }
  id10(){
    a = new EnterExit();
    this-> _init = 0;
  }
  void sinit(int qsz, int blocksz, int allow_update){
    if(this->_init){
      return;
    }
    this->cur = 0;
    this->qsz = qsz;
    this->blocksz = blocksz;
    this->lmt = 0;
    this->solid_state = 0;
    init(true, allow_update);
  }
  void hinit(int qsz, int blocksz, int allow_update){
    if(this->_init){
      return;
    }
    this-> _init = 0;
    this->cur = 0;
    this->qsz = qsz;
    this->blocksz = blocksz;
    this->lmt = 0;
    this->solid_state = 0;
    init(false, allow_update);
  }
  void clear(){
    if(!this->solid_state && this->_init){
      this->_init = 0;
      delete [] L;
      delete [] R;
      if(_update){
        delete [] E;
      }
      delete [] IDX;
      L = R = E = IDX = NULL;
    }
  }
  ~id10(){
    delete a;
    clear();
  }
  void transfer(int sz, int * L, int * R, int * E){
    int i;
    for(i=(0);i<(sz);i++){
      this->IDX[i] = i;
    }
    if(E != NULL){
      _update = 1;
    }
    if(!_update){
      sort(this->IDX, this->IDX+sz, [&](const int & lhs, const int & rhs){
                if(L[lhs]/blocksz != L[rhs]/blocksz) return L[lhs] < L[rhs];
                return R[lhs] < R[rhs];
            });
    }
    else{
      sort(this->IDX, this->IDX+sz, [&](const int & lhs, const int & rhs){
                if(L[lhs]/blocksz != L[rhs]/blocksz) return L[lhs] < L[rhs];
                if(R[lhs]/blocksz != R[rhs]/blocksz) return R[lhs] < R[rhs];
                return E[lhs] < E[rhs];
            });
    }
    for(i=(0);i<(sz);i++){
      this->L[i] = L[this->IDX[i]];
      this->R[i] = R[this->IDX[i]];
    }
    if(_update){
      for(i=(0);i<(sz);i++){
        this->E[i] = E[this->IDX[i]];
      }
    }
    this->cur = 0;
    this->lmt = sz;
  }
  int next(int & l, int & r, int & cl, int & cr){
    if(this->cur >= this->lmt){
      return -1;
    }
    int i = this->cur;
    while(l < L[i]){
      a->change(l, -1);
      ++l;
    }
    while(l > L[i]){
      a->change(l-1, 1);
      --l;
    }
    while(r < R[i]){
      a->change(r+1,1);
      ++r;
    }
    while(r > R[i]){
      a->change(r,-1);
      --r;
    }
    auto id13 = ((L[i]));
    auto id12 = ((R[i]));
    cl=id13;
    cr=id12;
    ++this->cur;
    return IDX[i];
  }
  int next(int & l, int & r, int cl, int & cr, int & t){
    if(this->cur >= this->lmt){
      return -1;
    }
    int i = this->cur;
    while(t < E[i]){
      a->modify(t+1,1, l, r);
      ++t;
    }
    while(t > E[i]){
      a->modify(t,-1, l, r);
      --t;
    }
    return next(l,r,cl,cr);
  }
}
;
const int MN = 100000+10;
int n;
int m;
int a[MN];
int L[MN];
int R[MN];
int E[MN];
int osz;
int K[MN];
int P[MN];
int V[MN];
int C[MN];
int csz;
int cnt[MN];
int g[MN];
int ans[MN];
int lb[5*MN];
int rb[5*MN];
int b[MN];
int xord[5*MN];
int* ord = xord + MN;
int* slb = lb+3;
int* srb = rb+3;
class id11{
  public:
  int mx;
  id11(){
    mx = 0;
  }
  int& ct(int x){
  }
  int& glb(int x){
    return lb[x+3];
  }
  int& grb(int x){
    return rb[x+3];
  }
  int len(int x){
    return grb(x)-glb(x)+1;
  }
  int plen(int x){
    if(len(x) > 0){
      return grb(x)-glb(x)+1;
    }
    return 0;
  }
  void addval(int x){
    int c = g[x];
    ++ord[glb(c)];
    grb(c+1) = glb(c);
    if(glb(c+1) == n){
      glb(c+1) = glb(c);
    }
    if(glb(c) == grb(c)){
      glb(c) = n-1;
    }
    ++glb(c);
    ++g[x];
  }
  void delval(int x){
    int c = g[x];
    --ord[grb(c)];
    if(glb(c-1) == n){
      grb(c-1) = grb(c);
    }
    glb(c-1) = grb(c);
    if(glb(c) == grb(c)){
      glb(c) = n;
    }
    --grb(c);
    --g[x];
  }
  void change(int pos, int x){
    if(x == 1){
      x = a[pos];
      addval(x);
    }
    else{
      x = a[pos];
      delval(x);
    }
  }
  void modify(int pos, int x, int l, int r){
    if(x == 1){
      x = P[pos];
      if(l <= x  &&  x <= r){
        delval(a[x]);
      }
      a[x] = C[pos];
      if(l <= x  &&  x <= r){
        addval(a[x]);
      }
    }
    else{
      x = P[pos];
      if(l <= x  &&  x <= r){
        delval(a[x]);
      }
      a[x] = V[pos];
      if(l <= x  &&  x <= r){
        addval(a[x]);
      }
    }
  }
  int computeAns(int l, int r, int k){
    int res = n;
    int i = 0;
    int j = 0;
    int su = 0;
    while(i < n && ord[i] > 0){
      while(j < n && ord[j] > 0 && su < k){
        su += len(ord[j]);
        j = grb(ord[j])+1;
      }
      if(su >= k){
        chmin(res, ord[i] - ord[j-1]);
      }
      su -= len(ord[i]);
      i = grb(ord[i]) + 1;
    }
    if(res == n){
      return -1;
    }
    return res;
  }
  void reset(){
    int i;
    glb(0) = 0;
    grb(0) = n-1;
    for(i=(1);i<(n);i++){
      glb(i) =  n;
      grb(i) = 0;
    }
  }
}
;
int main(){
  int i;
  wmem = memarr;
  rd(n);
  rd(m);
  {
    int id6;
    for(id6=(0);id6<(n);id6++){
      rd(a[id6]);
    }
  }
  for(i=(0);i<(m);i++){
    int type;
    rd(type);
    if(type == 1){
      int l;
      rd(l);
      int r;
      rd(r);
      int k;
      rd(k);
      auto id2 = ((l-1));
      auto id0 = ((r-1));
      auto id9 = ((k));
      L[osz]=id2;
      R[osz]=id0;
      K[osz]=id9;
      E[osz] = csz;
      ++osz;
    }
    else{
      int p;
      rd(p);
      int x;
      rd(x);
      ++csz;
      auto id3 = ((p-1));
      auto id4 = ((x));
      P[csz]=id3;
      C[csz]=id4;
    }
  }
  for(i=(1);i<(csz+1);i++){
    V[i] = a[P[i]];
    a[P[i]] = C[i];
  }
  int l = 0;
  int r = -1;
  int cl = 0;
  int cr = 0;
  int t = csz;
  int px = 0;
  id10<id11> sqde;
  sqde.sinit(osz+10, (int)pow(n,2.0/3.0), 1);
  sqde.transfer(osz, L, R, E);
  sqde.a->reset();
  while( (px = sqde.next(l,r,cl,cr, t) ) != -1){
    int ret = sqde.a->computeAns(L[px],R[px], K[px]);
    ans[px] = ret;
  }
  for(i=(0);i<(osz);i++){
    wt_L(ans[i]);
    wt_L('\n');
  }
  return 0;
}


























































































































































































































































