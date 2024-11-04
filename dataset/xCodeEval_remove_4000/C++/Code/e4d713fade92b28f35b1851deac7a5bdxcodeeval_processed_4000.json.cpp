














































using namespace std;



















template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){if(a>b) {a=b; return true;} else return false;}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){if(a<b) {a=b; return true;} else return false;}



typedef tuple<ll,int,int> T;
typedef vector<int> vec;
typedef vector<vector<int>> mat;
 
namespace atcoder {
 
namespace internal {
 




int id0(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}
 




int bsf(unsigned int n) {

    unsigned long index;
    _BitScanForward(&index, n);
    return index;

    return __builtin_ctz(n);

}
 
}  

 
}  

 
namespace atcoder {
 
template <class S,
          class F,
          S (*op)(S, S),
          S (*mapping)(S, F),
          F (*composition)(F, F),
          S (*e)(),
          F (*id)()>
struct id1 {
  public:
    id1() : id1(0) {}
    id1(int n) : id1(std::vector<S>(n, e())) {}
    id1(const std::vector<S>& v) : _n((int)v.size()) {
        log = internal::id0(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }
 
    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }
 
    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }
 
    S query(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();
 
        l += size;
        r += size;
 
        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push(r >> i);
        }
 
        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
 
        return op(sml, smr);
    }
 
    S all_prod() { return d[1]; }
 
    void update(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(d[p], f);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void update(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;
 
        l += size;
        r += size;
 
        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
 
        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }
 
        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }
 
    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }
 
    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }
 
  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;
 
    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(d[k], f);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};
 
}  

 
T ei(){return T(0,0,0);}
ll ti(){return -1;}
 
T f(T a, T b){
  int t,u,y,z;
  ll s,x;
  tie(s,t,u) = a;
  tie(x,y,z) = b; 
  return T(s+x,t+y,max(u,z));
}
 
T g(T a, ll b){
  int x,y,z;
  tie(x,y,z) = a; 
  if(~b) return T(b*y,y,b);
  else return a;
}
 
ll h(ll a, ll b){
  return max(a,b);
}

void solve(){
  int N,Q;
  cin >> N >> Q;
 
  vector<T> a(N);
  REP(i,N){
    int x; cin >> x;
    a[i] = T(x,1,x);
  }
 
  atcoder::id1<T,ll,f,g,h,ei,ti> seg(a);
 
  REP(_,Q){
    int q,x,y; cin >> q >> x >> y; 
    if(q==1){
      auto check = [&](T k){
        return get<2>(k) <= y;
      };
      int l = seg.min_left(N,check);
      if(l<x) seg.update(l,x,y);
    }
    else{
      x--;
      int ans = 0;
      while(x<N){
        auto check = [&](T k){
          return get<0>(k) <= y; 
        };
        int id = seg.max_right(x,check);
        y -= get<0>(seg.query(x,id));
        ans += id-x;
        if(id==N) break;
        auto check2 = [&](T k){
          return get<2>(k) <= y;
        };
        x = seg.min_left(N,check2);
      }
      cout << ans << "\n";
    }
    

  }
 
}
 
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int T = 1;
  

 
  while(T--) solve();
 
  return 0;
}