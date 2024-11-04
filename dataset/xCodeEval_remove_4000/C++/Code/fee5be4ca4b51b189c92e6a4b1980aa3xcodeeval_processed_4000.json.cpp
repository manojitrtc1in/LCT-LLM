





using namespace std;





enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return {i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {

~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (c it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}

sim dor(const c&) { ris; }

};




template <typename A, typename B>
using unordered_map2 = __gnu_pbds::gp_hash_table<A, B>;
using namespace __gnu_pbds;
template <typename T> using ordered_set =
  __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag,
                   __gnu_pbds::tree_order_statistics_node_update>;







using ld = long double;
using ll = long long;

constexpr int mod = 1000 * 1000 * 1000 + 7;
constexpr int id1 = (mod + 1) / 2;

void id14(int& a, int b) { a -= b; if (a < 0) a += mod; }
int id10(int a, int b) { id14(a, b); return a; }
void id6(int& a, int b) { a += b; if (a >= mod) a -= mod; }
int Dodaj(int a, int b) { id6(a, b); return a; }
int id0(int a, int b) { return (ll) a * b % mod; }
void id7(int& a, int b) { a = id0(a, b); }
int Pot(int a, ll b) { int res = 1; while (b) { if (b % 2 == 1) id7(res, a); a = id0(a, a); b /= 2; } return res; }
int Odw(int a) { return Pot(a, mod - 2); }
void id15(int& a, int b) { id7(a, Odw(b)); }
int Podziel(int a, int b) { return id0(a, Odw(b)); }
int id9(ll x) { x %= mod; if (x < 0) x += mod; return x; }

template <typename T> T Maxi(T& a, T b) { return a = max(a, b); }
template <typename T> T Mini(T& a, T b) { return a = min(a, b); }

using T = long long;
bool iszero(T v) { return !v;  }
struct Flow {
  struct E { int dest; T orig, *lim, *rev; };
  int zr, uj, n = 0;
  vector<unique_ptr<T>> ts;
  vector<vector<E>> graf;
  vector<int> ptr, odl;
  void vert(int v) {
    n = max(n, v + 1);
    graf.resize(n); ptr.resize(n); odl.resize(n);
  }
  void bfs() {
    fill(odl.begin(), odl.end(), 0);
    vector<int> kol = {zr};
    odl[zr] = 1;
    for (int i = 0; i < (int) kol.size(); i++) {
      for (E& e : graf[kol[i]]) {
        if (!odl[e.dest] and !iszero(*e.lim)) {
          odl[e.dest] = odl[kol[i]] + 1;
          kol.push_back(e.dest);
        }
      }
    }
  }
  T dfs(int v, T lim) {
    if (v == uj) return lim;
    T ret = 0, wez;
    for (int& i = ptr[v]; i < (int) graf[v].size(); i++) {
      E& e = graf[v][i];
      if (odl[e.dest] == odl[v] + 1 and !iszero(*e.lim) and
          !iszero(wez = dfs(e.dest, min(*e.lim, lim)))) {
        ret += wez; *e.lim -= wez; *e.rev += wez; lim -= wez;
        if (iszero(lim)) break;
      }
    }
    return ret;
  }
  void add_edge(int u, int v, T lim, bool bi = false ) {
    vert(max(u, v));
    T *a = new T(lim), *b = new T(lim * bi);
    ts.emplace_back(a); ts.emplace_back(b);
    graf[u].push_back(E{v, lim,      a, b});
    graf[v].push_back(E{u, lim * bi, b, a});
  }
  T dinic(int zr_, int uj_) {
    zr = zr_; uj = uj_;
    vert(max(zr, uj));
    T ret = 0;
    while (true) {
      bfs();
      fill(ptr.begin(), ptr.end(), 0);
      const T sta = dfs(zr, numeric_limits<T>::max());  

      if (iszero(sta)) break;                           

      ret += sta;                                       

    }
    return ret;
  }
  vector<int> cut() {
    vector<int> ret;
    bfs();
    for (int i = 0; i < n; i++) if (odl[i]) ret.push_back(i);
    return ret;
  }
  map<pair<int, int>, T> get_flowing() {  

    map<pair<int, int>, T> ret;           

    for (int i = 0; i < n; i++) for (E& e : graf[i])
        if (*e.lim < e.orig) ret[make_pair(i, e.dest)] += e.orig - *e.lim;
    for (auto& i : ret) {
      const pair<int, int> rev{i.first.second, i.first.first};
      const T x = min(i.second, ret[rev]);
      i.second -= x;
      ret[rev] -= x;
    }
    return ret;
  }
};

using Type = ll;

Type K(Type x) {
  return x * x;
}

struct P {
  Type x, y;

  P operator+(const P& p) const { return P{x + p.x, y + p.y}; }
  P operator-(const P& p) const { return P{x - p.x, y - p.y}; }

  Type operator*(const P& p) const { return x * p.y - y * p.x; }
  Type operator%(const P& p) const { return x * p.x + y * p.y; }

  bool operator==(const P& p) const { return x == p.x and y == p.y; }
  bool operator!=(const P& p) const { return x != p.x or y != p.y; }

  P perp() const {
    return P{-y, x};
  }

  Type DistSquared() const {
    return K(x) + K(y);
  }

  bool DistanceLessThan(Type r) const {
    return DistSquared() < K(r);
  }

  bool gora() const {
    return y > 0 or (y == 0 and x > 0);
  }
};

struct L {
  

  Type A, B, C;

  L(const P& a, const P& b) {
    A = a.y - b.y;
    B = b.x - a.x;
    C = A * a.x + B * a.y;
    assert(A * a.x + B * a.y == C);
    assert(A * b.x + B * b.y == C);
    assert(DistanceTo(a) == 0);
    assert(DistanceTo(b) == 0);
  }

  Type DistanceTo(const P& p) const {
    return abs(A * p.x + B * p.y - C);
  }

  bool DistanceLessThan(const P& p, Type r) const {
    const Type d = DistanceTo(p);
    return K(d) < K(r) * (K(A) + K(B));
  }
};

debug& operator<<(debug& deb, const P& p) {
  return deb << "(" << p.x << ", " << p.y << ")";
}

bool OnSegment(const P& a, const P& b, const P& p) {
  if ((p - a) * (p - b) != 0) {
    return false;
  }
  return (p - a) % (b - a) >= 0 and (p - b) % (a - b) >= 0;
}

Type w;

int n;
vector<P> polygon;

int Next(int i) {
  assert(0 <= i and i < n);
  if (i == n - 1) {
    return 0;
  }
  return i + 1;
}

bool InPolygon(const P& p) {
  for (int i = 0; i < n; i++) {
    const int j = Next(i);
    if (OnSegment(polygon[i], polygon[j], p)) {
      return true;
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    const int j = Next(i);
    if (polygon[i].x == polygon[j].x and polygon[i].x == p.x) {
      

      return false;
    }
    int a = i;
    int b = j;
    if (polygon[a].x > polygon[b].x) {
      swap(a, b);
    }
    if (polygon[a].x < p.x and p.x <= polygon[b].x) {
      if ((polygon[b] - polygon[a]) * (p - polygon[a]) < 0) {
        cnt++;
      }
    }
  }
  debug() << imie(cnt);
  assert(0 <= cnt and cnt <= 2);
  return cnt == 1;
}

bool id13(const P& a, const P& b, const P& p, Type r) {
  if ((p - a) % (b - a) >= 0 and (p - b) % (a - b) >= 0) {
    

    return L(a, b).DistanceLessThan(p, r);
  }
  return (p - a).DistanceLessThan(r) or (p - b).DistanceLessThan(r);
}

Type id5(const P& p, Type r) {
  

  if (InPolygon(p)) {
    

    return true;
  }
  debug() << "OUTSIDE";
  for (int i = 0; i < n; i++) {
    const int j = Next(i);
    if (id13(polygon[i], polygon[j], p, r)) {
      

      return true;
    }
    

  }
  return false;
}

Type id4() {
  Type x = numeric_limits<Type>::max();
  for (const P& p : polygon) {
    Mini(x, p.x);
  }
  debug() << "id4() = " << x;
  return x;
}

Type id8() {
  Type x = numeric_limits<Type>::min();
  for (const P& p : polygon) {
    Maxi(x, p.x);
  }
  debug() << "id8() = " << x;
  return x;
}

int m;
vector<pair<P, Type>> jelly;

bool Zle(const P& a, const P& b, Type r) {
  
  debug() << "POINT " << a.x << " " << a.y;
  debug() << "POINT " << b.x << " " << b.y;
  for (int i = 0; i < n; i++) {
    const int j = Next(i);
    P I = polygon[i] + a;
    P J = polygon[j] + a;
    debug() << "COLOR 0 0 1";
    debug() << "LINE " << I.x << " " << I.y << " " << J.x << " " << J.y;
    debug() << "CIRCLE " << I.x << " " << I.y << " " << r;

    P prosto = (I - J).perp();
    const ld length = sqrt(ld(K(prosto.x) + K(prosto.y)));
    const ld x = prosto.x * r / length;
    const ld y = prosto.y * r / length;
    debug() << "LINE " << I.x + x << " " << I.y + y
            << " " << J.x + x << " " << J.y + y;
  }
  
  return id5(b - a, r);
}

bool id11(const P& p, Type r) {
  return p.x + id4() - r < 0;
}

bool id12(const P& p, Type r) {
  return w < p.x + id8() + r;
}

void Algos() {
  debug() << imie(polygon);
  cin >> m;
  jelly.resize(m);
  for (pair<P, Type>& j : jelly) {
    cin >> j.first.x >> j.first.y >> j.second;
    debug() << "COLOR 0 0 0";
    debug() << "CIRCLE " << j.first.x << " " << j.first.y << " " << j.second;
  }

  Flow flow;
  const int s = 2 * m;
  const int t = 2 * m + 1;
  for (int i = 0; i < m; i++) {
    flow.add_edge(2 * i + 0, 2 * i + 1, 1, false);
  }

  vector<pair<int, int>> zle;

  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      const bool ij = Zle(jelly[i].first, jelly[j].first,
                          jelly[i].second + jelly[j].second);






      if (ij) {
        debug() << "ZLE" imie(i) imie(j);
        flow.add_edge(2 * i + 1, 2 * j + 0, 2, false);
        flow.add_edge(2 * j + 1, 2 * i + 0, 2, false);
        zle.emplace_back(i, j);
      }
    }
  }
  for (int i = 0; i < m; i++) {
    if (id11(jelly[i].first, jelly[i].second)) {
      flow.add_edge(s, 2 * i + 0, 2, false);
      debug() << "ZLE LEFT" imie(i);
      zle.emplace_back(i, m);
    }
    if (id12(jelly[i].first, jelly[i].second)) {
      flow.add_edge(2 * i + 1, t, 2, false);
      debug() << "ZLE RIGHT" imie(i);
      zle.emplace_back(i, m + 1);
    }
  }
  cout << flow.dinic(s, t) << endl;









}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> w;

  debug() << "FLIP_AXIS 1 -1";

  vector<P> punkty(n);
  for (P& p : punkty) {
    cin >> p.x >> p.y;
  }

  
  debug() << "RECTANGLE -30 -30 30 60";
  debug() << "RECTANGLE " << w << " -30 30 60";
  for (int i = 0; i < n; i++) {
    const int j = Next(i);
    debug() << "COLOR 1 0 0";
    debug() << "LINE " << punkty[i].x << " " << punkty[i].y << " "
            << punkty[j].x << " " << punkty[j].y;
  }
  debug() << "COLOR 0 0 1";
  debug() << "POINT 0 0";
  debug() << "COLOR 1 0 0";
  

  for (const P& a : punkty) {
    for (const P& b : punkty) {
      if (a != b) {
        polygon.push_back(a - b);
        debug() << "POINT " << polygon.back().x << " " << polygon.back().y;
      }
    }
  }

  P id3 = polygon[0];
  for (const P& p : polygon) {
    if (p.y < id3.y or (p.y == id3.y and p.x < id3.x)) {
      id3 = p;
    }
  }

  vector<P> katowo;
  for (const P& p : polygon) {
    if (p != id3) {
      katowo.push_back(p - id3);
    }
  }
  sort(katowo.begin(), katowo.end(), [](const P& a, const P& b) -> bool {
    if (a.gora() != b.gora()) {
      return a.gora();
    }
    const Type x = a * b;
    if (x == 0) {
      return a.DistSquared() < b.DistSquared();
    } else {
      return x > 0;
    }
  });
  debug() << imie(katowo);

  vector<P> id2;
  id2.push_back(P{0, 0});
  for (const P& p : katowo) {
    while ((int) id2.size() >= 2 and
           (p - id2.back()) * (id2.back() - id2.end()[-2]) >= 0) {
      id2.pop_back();
    }
    id2.push_back(p);
  }
  if ((int) id2.size() >= 2 and id2.back() * id2.end()[-2] == 0) {
    id2.pop_back();
  }

  polygon.clear();
  for (const P& p : id2) {
    polygon.push_back(p + id3);
  }
  n = (int) polygon.size();

  
  for (int i = 0; i < n; i++) {
    const int j = Next(i);
    debug() << "COLOR 0 1 0";
    debug() << "LINE " << polygon[i].x << " " << polygon[i].y << " "
            << polygon[j].x << " " << polygon[j].y;
  }
  

  Algos();
  return 0;
}
