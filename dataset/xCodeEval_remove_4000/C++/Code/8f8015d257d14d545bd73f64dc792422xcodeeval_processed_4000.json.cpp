











































using namespace std;

namespace Main {
  inline namespace Source {
    typedef   signed int dint; typedef short   signed int hd; typedef long   signed int ld; typedef long long   signed int lld;
    typedef unsigned int uint; typedef short unsigned int hu; typedef long unsigned int lu; typedef long long unsigned int llu;
    typedef long double lf;
    template <typename _t> static inline constexpr _t& amin(_t& a, const _t& b) noexcept { return a = min(a, b); }
    template <typename _t> static inline constexpr _t& amax(_t& a, const _t& b) noexcept { return a = max(a, b); }
    template <typename _t> static inline constexpr auto adif(const _t& a, const _t& b) noexcept { return a < b ? b - a : a - b; }
    template <typename _t> static inline constexpr auto mdif(const _t& a, const _t& b) noexcept { return a < b ? _t() : a - b; }
    template <typename int_t> static inline constexpr auto lowbit(const int_t& x) noexcept { return x bitand (~x + 1); }
    using std::abs;
    static inline constexpr uint abs(const uint x) noexcept { return x; }
    static inline constexpr hu   abs(const hu   x) noexcept { return x; }
    static inline constexpr lu   abs(const lu   x) noexcept { return x; }
    static inline constexpr llu  abs(const llu  x) noexcept { return x; }
    inline namespace IO {
      inline namespace File {
        static inline void id3(const char* const f) noexcept {
          static char g[1 << 8];
          assert(freopen(strcat(strcpy(g, f), ".in"), "r", stdin)), assert(freopen(strcat((g[strlen(f)] = '\0', g), ".out"), "w", stdout));
        }
      }
      inline namespace Buf {
        static char ibuf[1 << 16], obuf[1 << 16]; static const char *il, *ir; static char* op(obuf);
        static inline bool flush_i() noexcept
        { return ir = (il = ibuf) + fread(ibuf, sizeof(char), sizeof ibuf / sizeof(char), stdin), il != ir; }
        static inline void flush_o() noexcept { op -= fwrite(obuf, sizeof(char), op - obuf, stdout); }
        static inline char getchar() noexcept { return il == ir && !flush_i() ? EOF : *il++; }
        static inline char& getchar(char& ch) noexcept { return ch = getchar(); }
        static inline void putchar(const char ch) noexcept
        { *op++ = ch; { static bool f; if (not f) atexit(flush_o), f = true; } if (op == obuf + sizeof obuf / sizeof(char)) flush_o(); }
        static inline char* gets(char* const) noexcept;
        static inline void puts(const char*) noexcept;
      }
      static inline char getns() noexcept { static char ch; while (isspace(getchar(ch))); return ch; }
      static inline char& getns(char& ch) noexcept { return ch = getns(); }
      template <typename int_t>
        static inline int_t get() noexcept {
          static char ch; hd pn(1);
          while (not isdigit(getns(ch))) switch (ch) { case '+': pn = +pn; break; case '-': pn = -pn; break; case EOF: return int_t(); }
          int_t r{}; while (r = r * 10 + (ch - '0') * pn, isdigit(getchar(ch))); return r;
        }
      template <typename _t> static inline _t& get(_t& a) noexcept { return a = get<_t>(); }
      template <typename int_t>
        static inline pair<int_t, const bool> get_s() noexcept {
          static char ch; hd pn(1);
          while (not isdigit(getns(ch))) switch (ch)
          { case '+': pn = +pn; break; case '-': pn = -pn; break; case EOF: return make_pair(int_t(), false); }
          int_t r{}; while (r = r * 10 + (ch - '0') * pn, isdigit(getchar(ch))); return make_pair(r, true);
        }
      template <typename _t> static inline pair<_t, const bool> get_s(_t& a) noexcept
      { const auto t(get_s<_t>()); a = t.first; return make_pair(a, t.second); }
      template <typename int_t>
        static inline void put(int_t x, const char sp = '\0') noexcept {
          if (x < int_t()) putchar('-');
          static char s[1 << 10]; hd lg(-1); while (s[++lg] = abs(x % 10) + '0', x = x / 10); while (putchar(s[lg]), lg--);
          if (sp) putchar(sp);
        }
      template <> inline void put(const char ch, const char sp) noexcept { putchar(ch); if (sp) putchar(sp); }
      template <typename float_t>
        static inline void putf(float_t x, const hu p = 6, const char sp = '\0') noexcept {
          if (x < float_t()) putchar('-'), x = -x;
          static hd lg(-1); while (++lg, (x = x / 10) >= 1); while (putchar((x = x * 10) + '0'), x -= floor(x), lg--);
          putchar('.'); for (hu i{}; i < p; ++i) putchar((x = x * 10) + '0'), x -= floor(x); if (sp) putchar(sp);
        }
      static inline void put(const double x, const hu p = 6, const char sp = '\0') noexcept { putf(x, p, sp); }
      static inline void put(const float x, const hu p = 3, const char sp = '\0') noexcept { putf(x, p, sp); }
      static inline void put(const lf x, const hu p = 12, const char sp = '\0') noexcept { putf(x, p, sp); }
      static inline void put(const double x, const char sp) noexcept { put(x, 6, sp); }
      static inline void put(const float x, const char sp) noexcept { put(x, 3, sp); }
      static inline void put(const lf x, const char sp) { put(x, 12, sp); }
      struct iostream {
        template <typename _t> inline constexpr iostream operator>>(const _t& a) const noexcept { return get(a), iostream(); }
        template <typename _t> inline constexpr iostream operator>>(      _t& a) const noexcept { return get(a), iostream(); }
        template <typename _t> inline constexpr iostream operator<<(const _t& x) const noexcept { return put(x), iostream(); }
        template <typename _t> inline constexpr iostream operator<<(      _t& x) const noexcept { return put(x), iostream(); }
      } const constexpr io;
      inline namespace Buf {
        static inline char* gets(char* const s) noexcept
        { lu len{}; char ch(getns()); while (!isspace(ch) and ch != EOF) s[len++] = ch, getchar(ch); return s[len] = '\0', s; }
        static inline void puts(const char* s) noexcept { while (*s) putchar(*s++); putchar('\n'); }
      }
    }
    inline namespace Data_Structure {
      template <typename val_t, typename comp_t = less<val_t>, typename modify_t = void, typename size_type = uint>
        class id0 {
          struct node {
            val_t val; size_type dist; node* d[2]; modify_t lazy; size_type size;
            constexpr node(const val_t& val = val_t()) noexcept : val(val), dist(1), d{}, lazy(), size(1) {}
            compl node() noexcept { for (const hu i: { 0, 1 }) if (d[i]) delete d[i]; }
            inline void clear() noexcept { val = val_t(), dist = 0, memset(d, 0x00, sizeof d), lazy = modify_t(), size = 0; }
            inline void correct() noexcept {
              size = 1; for (const hu i: { 0, 1 }) if (d[i]) size += d[i]->size;
              if (d[1] and (!d[0] or d[0]->dist < d[1]->dist)) swap(d[0], d[1]);
              dist = (d[1] ? d[1]->dist : 0) + 1;
            }
            inline constexpr void modify(const modify_t& t) noexcept { val = t(val), lazy = t(lazy); }
            inline constexpr void down() noexcept { for (const hu i: { 0, 1 }) if (d[i]) d[i]->modify(lazy); lazy = modify_t(); }
            static node* merge(node* x, node* y) {
              if (!x or !y) return y ? y : x;
              if (comp_t()(y->val, x->val)) swap(x, y);
              x->down(), x->d[1] = merge(x->d[1], y), x->correct(); return x;
            }
          }* root;
          public:
          constexpr id0() noexcept : root() {} compl id0() noexcept { if (root) delete root, root = nullptr; }
          inline void push(const val_t& val) noexcept { root = node::merge(root, new node (val)); }
          inline constexpr void modify(const modify_t& t) noexcept { if (root) root->modify(t); }
          inline constexpr bool empty() const noexcept { return not root; }
          inline constexpr size_type size() const noexcept { return root ? root->size : 0; }
          inline constexpr void clear() noexcept { if (root) delete root, root = nullptr; }
          inline constexpr val_t top() const noexcept { return root ? root->val : val_t(); }
          inline val_t pop() noexcept {
            if (root) {
              const val_t r(root->val); root->down();
              node* const t(node::merge(root->d[0], root->d[1])); root->clear(), delete root, root = t;
              return r;
            }
            return val_t();
          }
          inline void join(id0& t) noexcept { root = node::merge(root, t.root), t.root = nullptr; }
        };
      template <typename val_t, typename comp_t, typename size_type>
        class id0<val_t, comp_t, void, size_type> {
          struct node {
            val_t val; size_type dist; node* d[2]; size_type size;
            constexpr node(const val_t& val = val_t()) noexcept : val(val), dist(1), d{}, size(1) {}
            compl node() noexcept { for (const hu i: { 0, 1 }) if (d[i]) delete d[i]; }
            inline void clear() noexcept { val = val_t(), dist = 0, memset(d, 0x00, sizeof d), size = 0; }
            inline void correct() noexcept {
              size = 1; for (const hu i: { 0, 1 }) if (d[i]) size += d[i]->size;
              if (d[1] and (!d[0] or d[0]->dist < d[1]->dist)) swap(d[0], d[1]);
              dist = (d[1] ? d[1]->dist : 0) + 1;
            }
            static node* merge(node* x, node* y) noexcept {
              if (!x or !y) return y ? y : x;
              if (comp_t()(y->val, x->val)) swap(x, y);
              x->d[1] = merge(x->d[1], y), x->correct(); return x;
            }
          }* root;
          public:
          constexpr id0() noexcept : root() {} compl id0() noexcept { if (root) delete root, root = nullptr; }
          inline void push(const val_t& val) noexcept { root = node::merge(root, new node (val)); }
          inline constexpr bool empty() const noexcept { return not root; }
          inline constexpr size_type size() const noexcept { return root ? root->size : 0; }
          inline constexpr void clear() noexcept { if (root) delete root, root = nullptr; }
          inline constexpr val_t top() const noexcept { return root ? root->val : val_t(); }
          inline val_t pop() noexcept {
            if (root) {
              const val_t r(root->val); node* const t(node::merge(root->d[0], root->d[1]));
              root->clear(), delete root, root = t;
              return r;
            }
            return val_t();
          }
          inline void join(id0& t) noexcept { root = node::merge(root, t.root), t.root = nullptr; }
        };
      template <typename val_t, typename size_type, const size_type size>
        class id2 {
          val_t* tree;
          public:
          id2() noexcept : tree(new val_t[size] () - 1) {} compl id2() noexcept { delete[](tree + 1); }
          inline void add(size_type x, const val_t& val) noexcept { if (0 < x) while (x <= size) tree[x] += val, x += lowbit(x); }
          inline val_t get_sum(size_type x) noexcept
          { val_t r{}; if (0 <= x and x <= size) while (x) r += tree[x], x ^= lowbit(x); return r; }
          inline val_t get_sum(const size_type& l, const size_type& r) noexcept { return get_sum(r) - get_sum(l - 1); }
        };
      template <typename size_type, const size_type size>
        class id1 {
          struct node {
            size_type sz; node* mo; constexpr node() noexcept : sz(1), mo() {}
            inline node* g() noexcept
            { node* r(this); while (r->mo) r = r->mo; node* t(this); while (t != r and t->mo != r)
            { node* const u(t); t = t->mo, u->mo = r; } return r; }
          } n[size];
          public:
          id1() noexcept { fill(n, n + sizeof n / sizeof(node), node()); }
          inline void clear() noexcept { fill(n, n + sizeof n / sizeof(node), node()); }
          inline size_type find(const lu x) noexcept { return n[x].g() - n; }
          inline bool union_set(const lu x, const lu y) noexcept {
            node *g(n[x].g()), *h(n[y].g()); if (g == h) return false; if (g->sz < h->sz) swap(g, h);
            (h->mo = g)->sz += h->sz, h->sz = 0; return true;
          }
          inline bool query(const lu x, const lu y) noexcept { return find(x) == find(y); }
        };
    }
  }
  namespace Main { static inline void main() noexcept; }
}

signed int main() { Main::Main::main(); return 0; }

namespace Main { namespace Main {
  static constexpr const lu mod(1e9 + 7); 

  static constexpr const lu nmx(2e5); static constexpr const hu id4(30);
  static lu fact[nmx + 1];
  static inline lu qpow(llu a, llu n)
  { lu r(1); a %= mod; while (n) { if (n bitand 1) r = r * a % mod; a = a * a % mod, n >>= 1; } return r; }
  static inline lu inv(const llu x) { return qpow(x, mod - 2); }
  static inline lu frac(const llu a, const llu b) { return a % mod * inv(b) % mod; }
  static inline lu c(const lu n, const lu k) { return frac(fact[n], 1ull * fact[k] * fact[n - k]); }
  static lu n, a[nmx + 1]; static lu cnt[id4 + 1]; static lu ans;
  static inline lu solve(const hu l) {
    lu a(cnt[l]), b{}; for (hu i(l + 1); i <= id4; ++i) b += cnt[i];
    lu res{}; for (lu i(2); i <= a; i += 2) res = (res + c(a, i)) % mod;
    return res = 1ull * res * qpow(2, b) % mod;
  }
  static inline void main() noexcept {
    fact[0] = 1; for (lu i(1); i <= nmx; ++i) fact[i] = 1ull * fact[i - 1] * i % mod;
    get(n); for (lu i(1); i <= n; ++i) get(a[i]);
    for (lu i(1); i <= n; ++i) { lu t(a[i]); hu u{}; while (not(t bitand 1)) ++u, t >>= 1; ++cnt[u]; }
    ans = 1ull * (qpow(2, cnt[0]) + mod - 1) * qpow(2, n - cnt[0]) % mod;
    for (lu i(1); i <= id4; ++i) ans = (ans + solve(i)) % mod;
    put(ans, '\n');
  }
}}