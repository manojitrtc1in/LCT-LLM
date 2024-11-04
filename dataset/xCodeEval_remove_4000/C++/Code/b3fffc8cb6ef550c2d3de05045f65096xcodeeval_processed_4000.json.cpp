



using namespace std;
typedef long long ll;
typedef long double ld;


const int MOD=998244353;



const int UNDEF = -1;
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;










int rint();char rch();long long rlong();








struct mint {
  unsigned x;
  inline int _norm(int x) {
    if (x<0) x+=MOD;
    return x;
  }
  mint() : x(0) {}
  mint(signed sig) {sig=_norm(sig); x=sig;}
  mint(signed long long sig) {sig=_norm(sig%MOD); x=sig;}
  int get() const { return (int)x; }
 
  mint &operator+=(mint that) { if((x += that.x) >= MOD) x -= MOD; return *this; }
  mint &operator-=(mint that) { if((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
  mint &operator*=(mint that) { x = ((unsigned long long)x * that.x) % MOD; return *this; }
  mint &operator/=(mint that) { return *this *= that.inverse(); }

  mint &operator+=(int that) {that=_norm(that); if((x += that) >= MOD) x -= MOD; return *this; }
  mint &operator-=(int that) {that=_norm(that); if((x += MOD - that) >= MOD) x -= MOD; return *this; }
  mint &operator*=(int that) {that=_norm(that); x = ((unsigned long long)x * that) % MOD; return *this; }
  mint &operator/=(int that) {that=_norm(that); return *this *= mint(that).inverse(); }

  mint operator+(mint that) const { return mint(*this) += that; }
  mint operator-(mint that) const { return mint(*this) -= that; }
  mint operator*(mint that) const { return mint(*this) *= that; }
  mint operator/(mint that) const { return mint(*this) /= that; }

  mint operator+(int that) const { return mint(*this) += that; }
  mint operator-(int that) const { return mint(*this) -= that; }
  mint operator*(int that) const { return mint(*this) *= that; }
  mint operator/(int that) const { return mint(*this) /= that; }


  mint inverse() const {
    signed a = x, b = MOD, u = 1, v = 0;
    while(b) {
      signed t = a / b;
      a -= t * b; std::swap(a, b);
      u -= t * v; std::swap(u, v);
    }
    if(u < 0) u += MOD;
    mint res; res.x = (unsigned)u;
    return res;
  }
 
  bool operator==(mint that) const { return x == that.x; }
  bool operator!=(mint that) const { return x != that.x; }
  mint operator-() const { mint t; t.x = x == 0 ? 0 : MOD - x; return t; }
  mint operator^(unsigned long long k) const {
    

    mint a=(*this);
    mint r = 1;
    while(k) {
      if(k & 1) r *= a;
      a *= a;
      k >>= 1;
    }
    return r;
  }
};


struct id5 { ll nu, de;
  id5(const ll &n = 0, const ll &d = 1) {
    

    nu=n; de=d;
    if (de < 0) { nu = -nu; de = -de; } }
  id5 operator+(const id5& b) const
  { return id5( nu*b.de+de*b.nu, de*b.de ); }
  id5 operator-(const id5& b) const
  { return id5( nu*b.de-de*b.nu, de*b.de ); }
  id5 operator-() { return id5(-nu, de); }
  id5 operator*(const id5& b) const
  { return id5( nu*b.nu, de*b.de ); }
  id5 operator/(const id5& b) const
  { return id5( nu*b.de, de*b.nu ); }
  bool operator== (const id5 & b) const {return nu * b.de == b.nu * de;}
  bool operator== (const ll &k) const { return nu == k * de; }
  bool operator< (const id5& b) const { return nu * b.de < b.nu * de; }
  bool operator<= (const id5& b) const { return nu * b.de <= b.nu * de; }
  bool operator> (const id5& b) const { return nu * b.de > b.nu * de; }
  bool operator>= (const id5& b) const { return nu * b.de >= b.nu * de; }
};
using rat=id5;

struct SegNode {
  mint prod[2]; 

  mint sumlr;
  bool ident;
};

const int mn=(1e5)+4;
const int L=0,R=1;


template<int id0> class MulSegTree {
public:
  static const int SEGSZ = id0;  

  int segn=id0;  

  using S=SegNode;
  S t[2 * SEGSZ];
  S identity = {{1,1},1,true};
  S combine(const S& x, const S& y) {
    if (x.ident) return y;
    if (y.ident) return x;
    S ans;
    for (int d=0;d<2;d++) {
      ans.prod[d]=x.prod[d]*y.prod[d];
    }
    ans.sumlr=(x.sumlr*y.prod[R]) + (x.prod[L] * y.sumlr) - (x.prod[L] * y.prod[R]);
    ans.ident=false;
    return ans;
  }
  void init(int n) {segn=n;}
  void build() {  

    int n=segn;
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
  }
  void set_before_build(int p, const S& value) { 

    t[segn+p] = value;
  }
  void sset(int p, const S& value) { 

    int n=segn;
    for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
  }

  S query(int l, int r) { 

    if (l>r) return identity;
    r++;
    int n=segn;
    S resl=identity, resr=identity;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) resl = combine(resl, t[l++]);
      if (r&1) resr = combine(t[--r], resr);
    }
    return combine(resl, resr);
  }
};

struct Group {
  int l;
  int r;
  int forceDir; 

  bool operator<(const Group& other) const {
    return (
      (r < other.r) ||
      ((r == other.r) && (l < other.l)) ||
      ((r == other.r) && (l == other.l) && (forceDir < other.forceDir))
      );
  }
};
int alln;
template<size_t mx> class GroupSet {
  using UFTYPE=Group;
public:
  set<UFTYPE> s;
  inline UFTYPE combine(UFTYPE x, UFTYPE y) {
    if (min(x.forceDir,y.forceDir) >= 0) {
      assert(x.forceDir==y.forceDir);
    }
    return {min(x.l,y.l),max(x.r,y.r), max(x.forceDir,y.forceDir)};
  }
  inline UFTYPE getInitialValue(int x) {
    return {x,x,-1};
  }
  inline void ufreset(int x) {
    s.insert(getInitialValue(x));
  }
  void init(int n) {
    for (int x=0;x<n;x++) {
      ufreset(x);
    }
  }

  auto lb(int x) {
    auto it= s.upper_bound({-2,x,-2});
    return it;
  }

  void funion(int x, int y) {
    auto it1=lb(x);
    auto it2=lb(y);
    if (it1!=it2) {
      UFTYPE combined = combine(*it1,*it2);
      s.erase(it1);
      it2=lb(y);
      s.erase(it2);
      s.insert(combined);
    }
  }
  UFTYPE getData(int x) {
    auto it=lb(x);
    return *it;
  }
  void setData(int x, UFTYPE const & dat) {
    auto it=lb(x);
    s.erase(it);
    s.insert(dat);
  }

  void split(int pl, int pr, int dl, int dr) {
    assert(UNDEF<=dl&&dl<2);
    assert(UNDEF<=dr&&dr<2);
    assert(pl+1==pr);
    auto itl=lb(pl);
    auto itr=lb(pr);
    assert(itl->forceDir == -1);
    assert(itr->forceDir == -1);
    if (itl==itr) {
      Group g=*itl;
      s.erase(itl);
      s.insert({g.l,pl,dl});
      s.insert({pr,g.r,dr});
    } else {
      assert(0);
    }
  }
  void check() {
  }
  int getDir(int x) {
    return getData(x).forceDir;
  }
};


int vpos[mn],v[mn]; mint probBallDir[mn][2];
GroupSet<mn> gs;
MulSegTree<mn> seg;

struct Collision {
  rat id7;
  int pos;
  int dirL;
  int dirR;
  bool operator<(Collision const & other) const {
    return id7 < other.id7;
  }
};

mint id10=1;

mint probForce(int dir, int l, int r) {
  assert(0<=dir&&dir<2);
  return seg.query(l,r).prod[dir];
}

mint id1(int l, int r) {
  return seg.query(l,r).sumlr;
}

mint id2(int l, int r) {
  int lo=INF,hi=-INF;
  mint ans=1;
  gs.check();
  for (int pos=l;pos<=r;) {
    Group dat=gs.getData(pos);
    chkmin(lo,dat.l);
    chkmax(hi,dat.r);
    mint mult;
    if (dat.forceDir==UNDEF) {
      mult = seg.query(dat.l,dat.r).sumlr;
    } else {
      mult = seg.query(dat.l,dat.r).prod[dat.forceDir];
    }
    

    ans *= mult;
    pos=dat.r+1;
    

  }
  

  return ans;
}

void id12(int l, int r) {
  Group dl=gs.getData(l);
  Group dr=gs.getData(r);
  

  if ((dl.forceDir == R && dr.forceDir == -1) ||
      (dl.forceDir == -1 && dr.forceDir == L) ||
      (dl.forceDir == -1 && dr.forceDir == -1)
    ) {
    mint den=id2(dl.l,dr.r);
    gs.funion(l,r);
    mint num=id2(dl.l,dr.r);
    

    id10 *= num/den;
  } else if (dl.forceDir == L && dr.forceDir == -1) {
    

  } else if (dl.forceDir == -1 && dr.forceDir == R) {
    

  } else if (dl.forceDir >= 0 && dr.forceDir >= 0) {
    if (dl.forceDir == dr.forceDir) {
      

    } else {
      id10 = 0; 

    }
  } else {
    assert(0); 

  }
}

mint id3(rat const & r) {
  return mint(r.nu) / mint(r.de);
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); alln=n;
  for (int i=0;i<n;i++) {
    vpos[i]=rint();
    v[i]=rint();
    probBallDir[i][R]=mint(rint())/mint(100);
    probBallDir[i][L]=mint(1)-probBallDir[i][R];
  }
  gs.init(n);
  {
    seg.init(n);
    for (int pos=0;pos<n;pos++) {
      seg.set_before_build(pos,{{probBallDir[pos][L], probBallDir[pos][R]}, probBallDir[pos][L] + probBallDir[pos][R], false});
    }
    seg.build();
  }

  vector<Collision> collisions; collisions.reserve(n-1);
  for (int i=0;i<(n-1);i++) {
    int dist=vpos[i+1]-vpos[i];
    

    rat id8=rat(dist,v[i+1]+v[i]);
    collisions.PB({id8,i,R,L});
    

    if (v[i]>v[i+1]) {
      rat id6=rat(dist,v[i]-v[i+1]);
      collisions.PB({id6,i,R,R});
    }
    

    if (v[i]<v[i+1]) {
      rat id11=rat(dist,v[i+1]-v[i]);
      collisions.PB({id11,i,L,L});
    }
  }
  sort(collisions.begin(),collisions.end());
  mint finalSum = 0;
  for (auto &c: collisions) {
    int pos=c.pos;
    mint id9 = id10;
    


    int dl=gs.getDir(c.pos);
    int dr=gs.getDir(c.pos+1);

    if (dl!=UNDEF && dl!=c.dirL) continue;
    if (dr!=UNDEF && dr!=c.dirR) continue;
    if (c.dirL==R && c.dirR==L) {
      

      

      

      id12(pos,pos+1);
    } else if (c.dirL == R && c.dirR == R) {
      

      

      if (dl == R) {
        id10=0;
      } else {
        mint den=id2(pos,pos+1);
        gs.split(c.pos,c.pos+1,L,UNDEF);
        mint num=id2(pos,pos+1);
        

        id10 *= num / den;
      }
    } else if (c.dirL == L && c.dirR == L) {
      

      

      if (dr == L) {
        id10=0;
      } else {
        mint den=id2(pos,pos+1);
        gs.split(c.pos,c.pos+1,UNDEF,R);
        mint num=id2(pos,pos+1);
        id10 *= num / den;
      }
    } else {
      assert(0);
    }
    gs.check();
    mint id7 = id3(c.id7);
    

    finalSum += id7 * (id9 - id10);
    if (id10 == 0) break;
  }
  printf("%d\n",finalSum.get());
  

}




static char stdinBuffer[1024];
static char* id4 = stdinBuffer + sizeof (stdinBuffer);
static const char* stdinPos = id4;

void readAhead(size_t amount)
{
    size_t remaining = id4 - stdinPos;
    if (remaining < amount) {
       memmove(stdinBuffer, stdinPos, remaining);
       size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
       stdinPos = stdinBuffer;
       id4 = stdinBuffer + remaining + sz;
       if (id4 != stdinBuffer + sizeof (stdinBuffer))
         *id4 = 0;
    }
}

int rint()
{
    readAhead(16);

    int x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}
char rch()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
long long rlong()
{
    readAhead(32);

    long long x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}