




using namespace std;
const int MOD = 1e9 + 7, MN = 1e6 + 44;
const bool local = 

true;

false;














using LL=long long;using LD=long double;using VI=vector<int>;using PII=pair<int,int>;using SI=set<int>;using MII=map<int,int>;ymd(LD)
using TII=pair<PII,int>;using QII=pair<PII,PII>;using ULL=unsigned long long;ymd(ULL)ymd(VI)ymd(LL)ymd(PII)ymd(PLL)ymd(PLD)ymd(PULL)ymd(SI)
ymd(TII)ymd(TLL)ymd(TLD)ymd(QII)ymd(QLL)ymd(QLD)ymd(QULL)ymd(TULL)using UI=unsigned int;ymd(UI)ymd(PUI)ymd(VUI)ymd(TUI)ymd(QUI)ymd(VVI)
bvt(popc,__builtin_popcount)bvt(ctz,__builtin_ctz)bvt(clz,__builtin_clz)bvt(bit_parity,__builtin_parity)ymd(SLL)ymd(VLL)ymd(VULL)ymd(SULL)




sim,class N>bool mini(T&o,N h){if(o>h)ros=h,1;return 0;}sim,class N>bool maxi(T&o,N h){if(o<h)ros=h,1;return 0;}



sim,class N oor pair<T,N>u){ros<<"<"<<u.f<<", "<<u.s<<">" bnt pta{using t=T;};sim,int N>struct pta<T[N]>{using t=T*;};
sim,typename=typename enable_if<!is_same<T,string>::value,urs(T().end())>::type oor
T u){int c=0;o<<"{";for(auto e:u)o<<", "+2*!c++<<e;ros<<"}";}
int mpow(int b, int e) {int o = 1; while (e) {if (e & 1)o = o * 1ll * b % MOD;b = b * 1ll * b % MOD;e /= 2;}ros;}
void dor(){cerr<<dec<<"\033[0m"<<endl;}sim,class...N>void dor(T x,N...y){cerr<<boolalpha<<x<<"; ";dor(y...);} const bool deb =

  sim> typename enable_if<is_arithmetic<T>::value, N>::type operator O(T o, N x) {return N(o) O x;} \
  sim> typename enable_if<is_arithmetic<T>::value || is_same<T,N>::value, N&>::type operator O

true;



sim>string bte(T u){stringstream o;o<<u;ros.str()bnt nep;sim>T yyo(nep<T>);sim>nep<T>ngy(T v,string c,int m=0);sim>T yyo(T o){ros bnt
nep{T v;string c;int m; nep<T>mask(){return ngy(v,c,1);}

template<zub([],v[yyo(u)],N)c+"["+bte(u)+"]",rcu};sim>nep<T>ngy(T v,string c,int m){return nep<T>{v,c,m};}
sim>T yyo(nep<T> o){ros.v;}sim>int uhn(T){return 0;}sim>int uhn(nep<T>o){ros.m;}

ccy(,bitset<8*sizeof(T)>(u))ccy(!,u)sim,class N> string ema(pair<T,N> o) {return "<" + ema(o.f) + ", " + ema(o.s) + ">";}

sim>string bte(nep<T>o){ros.c+" = "+(o.m?ema(o.v):bte(o.v));}sim oor nep<T>m){ros<<bte(rcu sim>nep<T>ngy(nep<T>o,string c="",int m=0){ros;}








vector <stringstream> lif;struct prux {prux() {lif.EB();}~prux() {lif.pop_back();}};



void siw(){};sim, class...N> void siw(T x, N...y) {lif.back() << x << "; ";siw(y...);}


sim> struct tqaz{T a;int u,d,l,r;};sim> tqaz<T> zaqt(T a,int u,int d,int l,int r){return tqaz<T>{a,u,d,l,r};}


stringstream o;VI M;FOR(j,x.l,x.r){int m=0;FOR(i,x.u,x.d)maxi(m, siz(t[i][j]));M.PB(m);}FOR(i,x.u,x.d){o<<"\n\t["<<i<<"] ";\
FOR(j,x.l,x.r){REP(_, M[j-x.l]-siz(t[i][j]))o<<" ";o<<t[i][j]<<((j+1)%5?", ":"; ");}}ros.str() + "\n";}
void nfl() {for (auto &s : lif)cerr << "  " << s.str() << endl;} ckx(+) ckx(-) ckx(!) ckx(~) avc(bte) avc(ema)
struct zet_p {int o;LD v;zet_p(LL x):o(x%MOD),v(x){} zet_p(LL x, LD y):o(x%MOD),v(y){} int get(){ros>0?o:o+MOD;}
  zet_p operator+(zet_p a) {return zet_p(o+a.o,v+a.v);}
  zet_p operator-(zet_p a) {return zet_p(o-a.o,v-a.v);}
  zet_p operator*(zet_p a) {return zet_p(o*1ll*a.o,v*a.v);}
  zet_p operator/(zet_p a) {assert(a.o != 0); return zet_p(o*1ll*mpow(a.o, MOD-2),v/a.v);}
  bool operator==(zet_p a) {return (o-a.o)%MOD == 0;}};
ostream&operator<<(ostream &o, zet_p u) {ros<<"["<<u.o<<" @ "<<u.v<<"]";}using frac_mod = zet_p;

false;
struct zet_p {int o;int get(){ros>0?o:o+MOD;}zet_p(LL x):o(x%MOD){}zet_p(int x):o(x%MOD){}
  zet_p operator+(zet_p a) {return zet_p(o+a.o);}
  zet_p operator-(zet_p a) {return zet_p(o-a.o);}
  zet_p operator*(zet_p a) {return zet_p(o*1ll*a.o);}
  zet_p operator/(zet_p a) {return zet_p(o*1ll*mpow(a.o, MOD - 2));}
  bool operator==(zet_p a) {return (o-a.o)%MOD == 0;}};
struct frac_mod {int o,m;int get(){return (o*1ll*mpow(m,MOD-2)%MOD+MOD)%MOD;}frac_mod(int x):o(x%MOD),m(1){}frac_mod(LL x):o(x%MOD),m(1){}
  frac_mod(LL a,LL b):o(a),m(b){}
  frac_mod operator+(frac_mod a){return frac_mod(o*1ll*a.m+m*1ll*a.o,m*a.m);}
  frac_mod operator-(frac_mod a){return frac_mod(o*1ll*a.m-m*1ll*a.o,m*a.m);}
  frac_mod operator*(frac_mod a){return frac_mod(o*1ll*a.o,m*1ll*a.m);}
  frac_mod operator/(frac_mod a){return frac_mod(o*1ll*a.m,m*1ll*a.o);}
  bool operator==(frac_mod a) {return (o * 1ll * a.m - m * 1ll * a.o) % MOD == 0;}};
acv(frac_mod, +) acv(frac_mod, -) acv(frac_mod, *) acv(frac_mod, /)




acv(zet_p, +) acv(zet_p, -) acv(zet_p, *) acv(zet_p, /)


sim,class S,class N,class=typename enable_if<!is_base_of<ios_base,typename remove_reference<T>::type>::value>::type>nok\
(o,T,pair<S u N>, p o y.first, p o y.second) sim, class S, class N> nok(o, pair<S u N>, T, p.first o y, p.second o y)

	pair <T,S> & operator r
	sim, class S, class N> pair <T,S> &operator r


clp(+) clp(-) clp(*) clp(/) clp(%) clp(^) clp(|) clp(>>) clp(<<) clp(&) pcg(&&) pcg(||) syd(-) syd(+) syd(~) syd(!)

sim, class N> using gyv = T;
namespace std {sim, class N> struct hash<pair<T,N> > {size_t operator()(const pair<T,N>&u) const {
      return hash<T>()(u.f) * 440624741ULL ^ hash<N>()(u.s);}};
  sim> struct hash<gyv<T, decltype(((T*)0)->end())>> {size_t operator()(const T& u) const {size_t o = 505347433;
for (auto e : u)o = hash<urs(e)>()(e) ^ o * 277953755ULL;ros;}};}
MII cou;
int sum = 0;
int n;
int board[4][4];
void go(int num, int i, int j);
void backtrack(int i, int j) {
  mark_stack(imie(i), imie(j), matr(board, 0, 3, 0, 3));
  if (i == 3 && j == 0) {
    REP(i, n)
      REP(j, n)
        printf("%2d%c", board[i][j], j == n - 1 ? '\n' : ' ');
    print_stack();
    exit(0);
  }
  if (j == 3) {
    int s = sum;
    REP(x, 3)
      s -= board[i][x];
    go(s, i, j);
    return;
  }
  if (i == 3) {
    assert(false);
    int s = sum;
    REP(x, 3)
      s -= board[x][j];
    go(s, i, j);
    return;
  }
  if (i == 2 && j == 1) {
    go(board[0][0] + board[1][0] + board[2][0] - board[1][2] - board[0][3], i, j);
    return;
  }
  if (i == 2 && j == 2) {
    int o = board[0][3] + board[1][3] + sum - board[2][0] - board[2][1] - board[0][0] - board[1][1];
    if (o % 2 == 0)
    go(o / 2, i, j);
    return;
  }
  if (i == 1 && j == 0) {
    for (auto x : cou) {
      if (x.f > board[0][1])
        break;
      go(x.f, i, j);
    }
    return;
  }
  for (auto x : cou)
    go(x.f, i, j);
}
void go(int num, int i, int j) {
  mark_stack(imie(num), imie(i), imie(j), imie(cou));
  auto it = cou.find(num);
  if (it == cou.end() || it -> s == 0) return;
  int under = -1;
  if (i == 2) {
    under = sum - board[0][j] - board[1][j] - num;
    if (under == num) {
      if (it -> s < 2) return;
      it -> s--;
    }
    else {
      auto it = cou.find(under);
      if (it == cou.end() || it -> s == 0) return;
      it -> s--;
    }
    board[3][j] = under;
  }
  mark_stack(imie(under));
  it -> s--;
  board[i][j] = num;
  if (j == 3)
    backtrack(i + 1, 0);
  else
    backtrack(i, j + 1);
  it -> s++;
  if (i == 2) {
    assert(cou.count(under));
    cou[under]++;
  }
}
int main() {
  scanf("%d", &n);
  VI nums;
  REP(_, n * n) {
    int x;
    scanf("%d", &x);
    cou[x]++;
    sum += x;
    nums.PB(x);
  }
  assert(sum % n == 0);
  sum /= n;
  printf("%d\n", sum);
  if (n <= 3) {
    sort(ALL(nums));
    do {
      bool good = true;
      REP(i, n) {
        int s1 = 0, s2 = 0;
        REP(j, n) {
          s1 += nums[i * n + j];
          s2 += nums[j * n + i];
        }
        if (s1 != sum || s2 != sum)
          good = false;
      }
      int s1 = 0, s2 = 0;
      REP(i, n) {
        s1 += nums[i * n + i];
        s2 += nums[i * n + n - i - 1];
      }
      if (s1 != sum || s2 != sum)
        good = false;
      if (good) {
        REP(i, n * n)
          printf("%d%c", nums[i], i % n == n - 1 ? '\n' : ' ');
        return 0;
      }
    }
    while (next_permutation(ALL(nums)));
  }
  backtrack(0, 0);
}