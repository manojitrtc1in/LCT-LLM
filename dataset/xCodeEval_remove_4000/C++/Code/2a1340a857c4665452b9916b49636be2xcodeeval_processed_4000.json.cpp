


using namespace std;













using LL=long long;using LD=long double;using VI=vector<int>;using PII=pair<int,int>;using SI=set<int>;using MII=map<int,int>;ymd(LD)
using TII=pair<PII,int>;using QII=pair<PII,PII>;using ULL=unsigned long long;ymd(ULL)ymd(VI)ymd(LL)ymd(PII)ymd(PLL)ymd(PLD)ymd(PULL)ymd(SI)
ymd(TII)ymd(TLL)ymd(TLD)ymd(QII)ymd(QLL)ymd(QLD)ymd(QULL)ymd(TULL)using UI=unsigned int;ymd(UI)ymd(PUI)ymd(VUI)ymd(TUI)ymd(QUI)
bvt(popc,__builtin_popcount)bvt(ctz,__builtin_ctz)bvt(clz,__builtin_clz)bvt(bit_parity,__builtin_parity)




sim,class N>bool mini(T&o,N h){if(o>h)ros=h,1;return 0;}sim,class N>bool maxi(T&o,N h){if(o<h)ros=h,1;return 0;}



sim,class N oor pair<T,N>u){ros<<"<"<<u.f<<", "<<u.s<<">" bnt pta{using t=T;};sim,int N>struct pta<T[N]>{using t=T*;};
sim,typename=typename enable_if<!is_same<T,string>::value,urs(T().end())>::type oor
T u){int c=0;o<<"{";for(auto e:u)o<<", "+2*!c++<<e;ros<<"}";}
const int MOD = 1e9 + 7;
int mpow(int b, int e) {int o = 1; while (e) {if (e & 1)o = o * 1ll * b % MOD;b = b * 1ll * b % MOD;e /= 2;}ros;}
void dor(){cerr<<dec<<"\033[0m"<<endl;}sim,class...N>void dor(T x,N...y){cerr<<boolalpha<<x<<"; ";dor(y...);} const bool deb =

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


  ((j+1)%5?", ":"; ");}ros+"\n";}
void nfl() {for (auto &s : lif)cerr << "  " << s.str() << endl;} ckx(+) ckx(-) ckx(!) ckx(~) avc(bte) avc(ema)

  sim> typename enable_if<is_arithmetic<T>::value, N>::type operator O(T o, N x) {return N(o) + x;} \
  sim> typename enable_if<is_arithmetic<T>::value || is_same<T,N>::value, N>::type 

false;






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
const int MN = 1 << 17;
VI graf[MN];
int in[MN], out[MN];
int tree[MN];
int size[MN];
void add(int x, int val) {
  while (x < MN) {
    tree[x] += val;
    x += x & -x;
  }
}
int pref(int x) {
  debug(imie(x));
  int ans = 0;
  while (x > 0) {
    debug(arr(tree, x));
    ans += tree[x];
    x -= x & -x;
  }
  debug(imie(ans));
  return ans;
}
int parent[MN], dep[MN];
void dfs(int x, int y = 0, int d = 0) {
  static int timer = 0;
  size[x] = 1;
  parent[x] = y;
  dep[x] = d;
  in[x] = timer++;
  for (auto v : graf[x])
    if (v != y) {
      dfs(v, x, d + 1);
      size[x] += size[v];
    }
  out[x] = timer++;
}

int nr_in_dec[MN];
int top[MN];
void dfs2(int x) {
  debug(imie(x));
  static int enumer = 1;
  VI next;
  int wh = x;
  nr_in_dec[x] = enumer++;
  top[x] = x;
  while (true) {
    debug(imie(wh));
    PII best = MP(0, 0);
    for (auto v : graf[wh])
      if (v != parent[wh]) {
        maxi(best, MP(size[v], v));
      }
    debug(imie(best));
    if (best.s == 0) break;
    nr_in_dec[best.s] = enumer++;
    top[best.s] = x;
    for (auto v : graf[wh])
      if (v != parent[wh] && v != best.s)
        next.PB(v);
    wh = best.s;
  }
  debug(imie(x), imie(next));
  for (auto c : next)
    dfs2(c);
}

int read_range(int l, int r) {
  assert(l <= r);
  debug(imie(l), imie(r));
  return pref(r) - pref(l - 1);
}
void mark_vertex(int nr, int val) {
  debug(imie(nr), imie(val));
  add(nr_in_dec[nr], val);
}
bool under(int x, int y) {
  return in[x] >= in[y] && out[x] <= out[y];
}
int read_path(int a, int b) {
  int ans = 0;
  debug(imie(a), imie(b));


  REP(_, 2) {
    while (true) {
      int aa = top[a];
      if (!under(b, aa)) {
        debug("include", imie(aa), imie(a));
        ans += read_range(nr_in_dec[aa], nr_in_dec[a]);
        a = parent[aa];
      }
      else
        break;
    }
    swap(a, b);
  }
  debug("left with", imie(a), imie(b));
  if (dep[a] < dep[b])
    swap(a, b);
  assert(top[a] == top[b]);
  ans += read_range(nr_in_dec[b], nr_in_dec[a]);
  return ans;
}
const int MV = 1e7 + 1;

int div[MV];
VTII queries[MV]; 

sim> void iter_divs(int x, T fun) {
  debug(imie(x));
  while (x > 1) {
    int p = div[x];
    int pow = 1;
    while (x % p == 0) {
      pow *= p;
      x /= p;
      debug("call ", imie(pow));
      fun(pow);
    }
  }
}
VI divisible[MV];
LL ans[MN];
int main() {
  debug(imie(MV));
  FOR(p, 2, MV - 1) {
    if (div[p] == 0) {
      for (int k = p; k < MV; k += p)
        div[k] = p;
    }
  }
  debug(range(div, 1, 20));
  int n;
  scanf("%d", &n);
  FOR(i, 1, n - 1) {
    int a, b;
    scanf("%d%d", &a, &b);
    graf[a].PB(b);
    graf[b].PB(a);
  }
  dfs(1);
  dfs2(1);
  debug(range(top, 1, n));
  debug(range(nr_in_dec, 1, n));
  FOR(i, 1, n) {
    int x;
    scanf("%d", &x);
    iter_divs(x, [i](int p){divisible[p].PB(i);});
  }
  int q;
  scanf("%d", &q);
  REP(i, q) {
    int a, b, x;
    scanf("%d%d%d", &a, &b, &x);

    iter_divs(x, [a, b, i](int p){queries[p].PB(MT(a, b, i));});
    ans[i] = 1;
  }
  FOR(p, 2, MV - 1) {
    if (div[p] == p) {
      for (LL pow = p; pow < MV; pow *= p) {
        if (divisible[pow].empty() || queries[pow].empty())
          break;
        for (auto x : divisible[pow])
          mark_vertex(x, 1);
        for (auto x : queries[pow]) {
          int a = x.f.f;
          int b = x.f.s;
          int i = x.s;
          int cou = read_path(a, b);
          debug(imie(pow), imie(cou), imie(a), imie(b), imie(i), arr(ans, i));
          ans[i] *= mpow(p, cou);
          ans[i] %= MOD;
          debug(arr(ans, i));
        }
        for (int x : divisible[pow]) {
          mark_vertex(x, -1);
        }
      }
    }
  }

  REP(i, q)
    printf("%lld\n", ans[i]);
}
