#include <bits/stdc++.h>


static struct FASTIO {

  char READ_CHARACTER; bool REMAINING_CHARACTER = false;

  inline void ignore(); inline void flush();

  template <typename T> inline bool READ_INT(T &x); template <typename T> inline bool READ_STRING(T &x); 
  template<size_t N> inline bool READ_CHAR_ARRAY(char (&x)[N]); template<size_t N> inline bool READ_VAR(char (&x)[N]);
  template <typename T> inline bool READ_CHAR(T &x); inline bool READ_CHAR_ARRAY(char*& x); inline bool READ_GETLINE(std::string &x);
  template <typename T> inline bool READ_FLOAT(T &x); template <typename T> inline bool READ_DOUBLE(T &x);
  template<std::size_t N> inline bool READ_BITSET(std::bitset<N> &bit); template<std::size_t N> inline bool READ_VAR(std::bitset<N> &bit);
  inline bool READ_VAR(bool &x); inline bool READ_VAR(short int &x); inline bool READ_VAR(int &x); 
  inline bool READ_VAR(long int &x); inline bool READ_VAR(long long int &x); inline bool READ_VAR(unsigned short int &x);
  inline bool READ_VAR(unsigned int &x); inline bool READ_VAR(unsigned long &x); inline bool READ_VAR(unsigned long long &x);
  inline bool READ_VAR(std::string &x); inline bool READ_VAR(char &x); inline bool READ_VAR(char*& x); inline bool READ_VAR(float &x);
  inline bool READ_VAR(double &x); inline bool READ_VAR(long double &x); template <typename T> inline void WRITE_INT(T x);
  inline void WRITE_STRING(std::string &x); inline void WRITE_CHAR(char x); inline void WRITE_CHAR_ARRAY(const char *x);
  inline void WRITE_FLOAT(float x); template <typename T> inline void WRITE_DOUBLE(T x); inline void WRITE_VAR(bool x);
  inline void WRITE_VAR(short int x); inline void WRITE_VAR(int x); inline void WRITE_VAR(long int x); inline void WRITE_VAR(long long int x);
  inline void WRITE_VAR(unsigned short int x); inline void WRITE_VAR(unsigned int x); inline void WRITE_VAR(unsigned long x);
  inline void WRITE_VAR(unsigned long long x); inline void WRITE_VAR(char x); inline void WRITE_VAR(const char *x); 
  inline void WRITE_VAR(std::string &x); inline void WRITE_VAR(float x); inline void WRITE_VAR(double x); inline void WRITE_VAR(long double x);
  template<std::size_t N> inline void WRITE_VAR(std::bitset<N> &bit); template<std::size_t N> inline void WRITE_BITSET(std::bitset<N> &bit);

} FIO;
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

class HLD {
public:
  void init(int n) {
    

    sz.resize(n);
    in.resize(n);
    out.resize(n);
    rin.resize(n);
    p.resize(n);
    edges.resize(n);
    nxt.resize(n);
    h.resize(n);
  }

  void addEdge(int u, int v) {
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  void setRoot(int n) {
    t = 0;
    p[n] = n;
    h[n] = 0;
    prep(n, n);
    nxt[n] = n;
    hld(n);
  }

  int getLCA(int u, int v) {
    while(!inSubtree(nxt[u], v)) {
      u = p[nxt[u]];
    }
    while(!inSubtree(nxt[v], u)) {
      v = p[nxt[v]];
    }
    return in[u] < in[v] ? u : v;
  }

  bool inSubtree(int u, int v) {
    

    return in[u] <= in[v] && in[v] < out[u];
  }

  std::vector<std::pair<int, int>> getPathtoAncestor(int u, int anc) {
    

    std::vector<std::pair<int, int>> ans;
    

    while(nxt[u] != nxt[anc]) {
      ans.emplace_back(in[nxt[u]], in[u] + 1);
      u = p[nxt[u]];
    }
    

    ans.emplace_back(in[anc], in[u] + 1);
    return ans;
  }


  std::vector<int> in, out, p, rin, sz, nxt, h;
  std::vector<std::vector<int>> edges;
  int t;

  void prep(int on, int par) {
    sz[on] = 1;
    p[on] = par;
    for(int i = 0; i < (int) edges[on].size(); i++) {
      int &u = edges[on][i];
      if(u == par) {
        std::swap(u, edges[on].back());
        edges[on].pop_back();
        i--;
      } else {
        h[u] = 1 + h[on];
        prep(u, on);
        sz[on] += sz[u];
        if(sz[u] > sz[edges[on][0]]) {
          std::swap(edges[on][0], u);
        }
      }
    }
  }

  void hld(int on) {
    in[on] = t++;
    rin[in[on]] = on;
    for(auto u : edges[on]) {
      nxt[u] = (u == edges[on][0] ? nxt[on] : u);
      hld(u);
    }
    out[on] = t;
  }
};

template <class Info = int>
class ColorUpdate {
public:
  struct Range {
    Range(int ll = 0) { this->l = ll; }
    Range(int ll, int rr, Info vv) {
      this->l = ll;
      this->r = rr;
      this->v = vv;
    }
    int l, r;
    Info v;

    bool operator < (const Range &b) const { return l < b.l; }
  };

  std::vector<Range> upd(int l, int r, Info v) {
    std::vector<Range> ans;
    if(l >= r) return ans;
    auto it = ranges.lower_bound(l);
    if(it != ranges.begin()) {
      it--;
      if(it->r > l) {
        auto cur = *it;
        ranges.erase(it);
        ranges.insert(Range(cur.l, l, cur.v));
        ranges.insert(Range(l, cur.r, cur.v));
      }
    }
    it = ranges.lower_bound(r);
    if(it != ranges.begin()) {
      it--;
      if(it->r > r) {
        auto cur = *it;
        ranges.erase(it);
        ranges.insert(Range(cur.l, r, cur.v));
        ranges.insert(Range(r, cur.r, cur.v));
      }
    }
    for(it = ranges.lower_bound(l); it != ranges.end() && it->l < r; it++) {
      ans.push_back(*it);
    }
    ranges.erase(ranges.lower_bound(l), ranges.lower_bound(r));
    ranges.insert(Range(l, r, v));
    return ans;
  }
private:
  std::set<Range> ranges;
};

std::vector<int> a;

const int MOD = 998244353;

std::pair<long long, long long> dp(int on, int par, std::vector<std::vector<int>> &edges) {
  std::pair<long long, long long> ans(1, 0);
  if(a[on]) {
    std::swap(ans.first, ans.second);
  }
  for(auto to : edges[on]) {
    assert(to != par);
    auto t = dp(to, on, edges);
    std::pair<long long, long long> nxt(ans.first * (t.first + t.second) % MOD, 0);
    nxt.second = (t.second + t.first) * ans.second % MOD;
    nxt.second = (nxt.second + t.second * ans.first) % MOD;
    ans = nxt;
  }
  

  return ans;
}

int main() {
  0; 0;
  int n, k;
  FIO.READ_VAR(n), FIO.READ_VAR(k);
  a.resize(n);
  for(int i = 0; i < n; i++) {
    FIO.READ_VAR(a[i]);
  }
  HLD hld;
  hld.init(n);
  for(int i = 1; i < n; i++) {
    int u, v;
    FIO.READ_VAR(u), FIO.READ_VAR(v);
    u--;v--;
    hld.addEdge(u, v);
  }
  hld.setRoot(0);
  std::vector<int> b(k, -1);
  int root = -1;
  for(int i = 0; i < n; i++) {
    if(a[i]) {
      if(root == -1) {
        root = i;
      }
      root = hld.getLCA(root, i);
      if(b[a[i]-1] == -1) {
        b[a[i]-1] = i;
      }
      b[a[i]-1] = hld.getLCA(b[a[i]-1], i);
    }
  }
  ColorUpdate<int> col;
  col.upd(0, n, 0);
  for(int i = 0; i < n; i++) {
    if(a[i] == 0) continue;
    auto path = hld.getPathtoAncestor(i, b[a[i]-1]);
    for(auto r : path) {
      auto v = col.upd(r.first, r.second, a[i]);
      bool run = true;
      for(auto e : v) {
        if(e.v != 0 && e.v != a[i]) {
          FIO.WRITE_VAR("0\n");
          return 0;
        }
        if(e.v == a[i]) {
          run = false;
        }
      }
      if(!run) break;
    }
  }
  {
    auto v = col.upd(0, n, -1);
    for(auto r : v) {
      for(int i = r.l; i < r.r; i++) {
        a[hld.rin[i]] = r.v;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    

  }
  root = 0;
  FIO.WRITE_VAR(dp(root, root, hld.edges).second), FIO.WRITE_VAR('\n');
}


inline void FASTIO::ignore() {
  if(REMAINING_CHARACTER == true) REMAINING_CHARACTER = false; else READ_CHARACTER = getchar();
}

inline void FASTIO::flush() {
  fflush(stdout);
}




template <typename T>
inline bool FASTIO::READ_INT(T &x) {
  x = 0; T sig = 1;
  if(!REMAINING_CHARACTER) READ_CHARACTER = getchar(), REMAINING_CHARACTER = true; else REMAINING_CHARACTER = false;
  while (!isdigit(READ_CHARACTER) && READ_CHARACTER != EOF) sig = (READ_CHARACTER == '-' ? -sig : sig), READ_CHARACTER = getchar();
  if(READ_CHARACTER == EOF) return REMAINING_CHARACTER = false, false;
  while (isdigit(READ_CHARACTER)) x = x * 10 + READ_CHARACTER - '0', READ_CHARACTER = getchar();
  x *= sig; REMAINING_CHARACTER = true;
  return true;
}

template <typename T>
inline bool FASTIO::READ_STRING(T &x) {
  x = "";
  if(!REMAINING_CHARACTER) READ_CHARACTER = getchar(), REMAINING_CHARACTER = true; else REMAINING_CHARACTER = false;
  while ((READ_CHARACTER == '\n' || READ_CHARACTER == '\t' || READ_CHARACTER == ' ')) READ_CHARACTER = getchar();
  if(READ_CHARACTER == EOF) return REMAINING_CHARACTER = false, false;
  while ((READ_CHARACTER != '\n' && READ_CHARACTER != '\t' && READ_CHARACTER != ' ' && READ_CHARACTER != EOF)) x += READ_CHARACTER, READ_CHARACTER = getchar();
  REMAINING_CHARACTER = true;
  return true;
}

inline bool FASTIO::READ_GETLINE(std::string &x) {
  x = "";
  if(!REMAINING_CHARACTER) READ_CHARACTER = getchar(), REMAINING_CHARACTER = true; else REMAINING_CHARACTER = false;
  if(READ_CHARACTER == EOF) return REMAINING_CHARACTER = false, false;
  while ((READ_CHARACTER != '\n' && READ_CHARACTER != EOF)) x += READ_CHARACTER, READ_CHARACTER = getchar();
  REMAINING_CHARACTER = false;
  return true;
}

template <typename T>
inline bool FASTIO::READ_CHAR(T &x) {
  if(!REMAINING_CHARACTER) READ_CHARACTER = getchar(), REMAINING_CHARACTER = true; else REMAINING_CHARACTER = false;
  if(READ_CHARACTER == EOF) return REMAINING_CHARACTER = false, false;
  while ((READ_CHARACTER == '\n' || READ_CHARACTER == '\t' || READ_CHARACTER == ' ')) READ_CHARACTER = getchar();
  x = READ_CHARACTER; REMAINING_CHARACTER = false;
  return true;
}


template<size_t N>
inline bool FASTIO::READ_CHAR_ARRAY(char (&x)[N]) {
  if(!REMAINING_CHARACTER) READ_CHARACTER = getchar(), REMAINING_CHARACTER = true; else REMAINING_CHARACTER = false;
  while ((READ_CHARACTER == '\n' || READ_CHARACTER == '\t' || READ_CHARACTER == ' ')) READ_CHARACTER = getchar();
  if(READ_CHARACTER == EOF) return REMAINING_CHARACTER = false, false;
  char *ptr = &x[0];
  while ((READ_CHARACTER != '\n' && READ_CHARACTER != '\t' && READ_CHARACTER != ' ' && READ_CHARACTER != EOF)) *ptr++ = READ_CHARACTER, READ_CHARACTER = getchar();
  *ptr = '\0', REMAINING_CHARACTER = true;
  return true;
}

inline bool FASTIO::READ_CHAR_ARRAY(char*& x) {
  std::string y;
  if(READ_STRING(y) == false)
    return false;
  x = new char[(int)y.size() + 1];
  strcpy(x, y.c_str());
  return true;
}

template <typename T>
inline bool FASTIO::READ_FLOAT(T &x) {
  return (scanf("%f", &x) != EOF);
}

template <typename T>
inline bool FASTIO::READ_DOUBLE(T &x) {
  double y;
  if(scanf("%lf", &y) == EOF) return false;
  x = y;
  return true;
}

template<std::size_t N>
inline bool FASTIO::READ_BITSET(std::bitset<N> &x) {
  if(!REMAINING_CHARACTER) READ_CHARACTER = getchar(), REMAINING_CHARACTER = true; else REMAINING_CHARACTER = false;
  while ((READ_CHARACTER == '\n' || READ_CHARACTER == '\t' || READ_CHARACTER == ' ')) READ_CHARACTER = getchar();
  if(READ_CHARACTER == EOF) return REMAINING_CHARACTER = false, false;
  int i = 0; REMAINING_CHARACTER = true;
  while (READ_CHARACTER == '0' || READ_CHARACTER == '1') x[i++] = READ_CHARACTER - '0', READ_CHARACTER = getchar();
  return true;
}

inline bool FASTIO::READ_VAR(short int &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(int &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(long int &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(long long int &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(unsigned short int &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(unsigned int &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(unsigned long &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(unsigned long long &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(std::string &x) {
  return READ_STRING(x);    
}

inline bool FASTIO::READ_VAR(char &x) {
  return READ_CHAR(x);
}

template<size_t N>
inline bool FASTIO::READ_VAR(char (&x)[N]) {
  return READ_CHAR_ARRAY(x);
}

inline bool FASTIO::READ_VAR(char*& x) {
  return READ_CHAR_ARRAY(x);
}

inline bool FASTIO::READ_VAR(float &x) {
  return READ_FLOAT(x);
}

inline bool FASTIO::READ_VAR(double &x) {
  return READ_DOUBLE(x);
}

inline bool FASTIO::READ_VAR(long double &x) {
  return READ_DOUBLE(x);
}

template<std::size_t N>
inline bool FASTIO::READ_VAR(std::bitset<N> &x) {
  return READ_BITSET(x);
}




template <typename T>
inline void FASTIO::WRITE_INT(T x) {
  if (x < 0) {putchar('-'); x = -x; }
  char writeBuffer[20], *writePtr = writeBuffer;
  do {
    *writePtr++ = '0' + x % 10;
    x /= 10;
  }
  while (x);
  do  { putchar(*--writePtr); }
  while (writePtr > writeBuffer);
}

inline void FASTIO::WRITE_CHAR(char x) {
  putchar(x);
}

inline void FASTIO::WRITE_CHAR_ARRAY(const char *x) {
  while(*x != '\0')
    putchar(*x++);
}

inline void FASTIO::WRITE_STRING(std::string &x) {
  for(char c: x) 
    putchar(c);
}

inline void FASTIO::WRITE_FLOAT(float x) {
  printf("%f", x);
}

template <typename T>
inline void FASTIO::WRITE_DOUBLE(T x) {
  printf("%lf", (double)x);
}

template<std::size_t N>
inline void FASTIO::WRITE_BITSET(std::bitset<N> &x) {
  for(int i = (int)x.size() - 1; i >= 0; i--)
    putchar(x[i] + 48);
}

inline void FASTIO::WRITE_VAR(bool x) {
  WRITE_INT(x);
}

inline void FASTIO::WRITE_VAR(short int x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(int x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(long int x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(long long int x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(unsigned short int x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(unsigned int x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(unsigned long x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(unsigned long long x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(std::string &x) {
  WRITE_STRING(x);    
}

inline void FASTIO::WRITE_VAR(char x) {
  WRITE_CHAR(x);
}

inline void FASTIO::WRITE_VAR(const char *x) {
  WRITE_CHAR_ARRAY(x);
}

inline void FASTIO::WRITE_VAR(float x) {
  WRITE_FLOAT(x);
}

inline void FASTIO::WRITE_VAR(double x) {
  WRITE_DOUBLE(x);
}

inline void FASTIO::WRITE_VAR(long double x) {
  WRITE_DOUBLE(x);
}

template<std::size_t N>
inline void FASTIO::WRITE_VAR(std::bitset<N> &x) {
  WRITE_BITSET(x);
}  



