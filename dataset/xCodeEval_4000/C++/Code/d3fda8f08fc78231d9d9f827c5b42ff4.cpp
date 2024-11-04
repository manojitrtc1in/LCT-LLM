#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define DEBUG


#define INF 0x3f3f3f3f3f3f3f3f
#define IOS std::ios::sync_with_stdio(false);std::cin.tie(0);


#define mod 1000000007
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define Base 233
#define eps 0.000000001
#define sj srand((unsigned)time(NULL)); 








#define endl "\n"


#define NO cout<<"NO"<<endl
#define YES cout<<"YES"<<endl
#define No cout<<"No"<<endl
#define Yes cout<<"Yes"<<endl

#define mst(x) memset(x,0,sizeof(x))
#define debug(x) cout<<"DEBUG "<<#x<<" : "<<x<<endl
#define div(x,y)  (x)/(y) + ((x)%(y) != 0)
#define _up(x) (int)ceil(1.0*x)
#define _down(x) (int)floor(1.0*x)

#define range(x,y) 1

#define baoliu(x,y) cout<<fixed<<setprecision(y)<<x
typedef long long ll;

using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a%b) : a; }
inline long long lcm(long long a, long long b) { return a * b / gcd(a, b); }


inline long long _qpow(long long a, long long b, long long m) { a %= m; long long res = 1; while (b > 0) { if (b & 1) res = res * a % m;    a = a * a % m; b >>= 1; }return res; }

inline long long ksm(long long a, long long b, long long m) { a %= m; long long res = 1; while (b > 0) { if (b & 1) res = res * a % m;    a = a * a % m; b >>= 1; }return res; }


template <class S, S(*op)(S, S), S(*e)()>
class segtree {
private:
    vector<S>node;

    vector<S>d;

    int _n;
    void build(int rt, int L, int R) {
        if (L == R) {
            node[rt] = d[L];
            return;
        }
        int mid = (L + R) / 2;
        build(2 * rt, L, mid);
        build(2 * rt + 1, mid + 1, R);
        node[rt] = op(node[2 * rt], node[2 * rt + 1]);
    }
    S que(int rt, int L, int R, int que_L, int que_R) {
        if (L > que_R || R < que_L)return e();
        if (que_L <= L && R <= que_R)return node[rt];
        int mid = (L + R) / 2;
        return op(
            que(2 * rt, L, mid, que_L, que_R),
            que(2 * rt + 1, mid + 1, R, que_L, que_R)
        );
    }

    void upd(int rt, int L, int R, int id, S x) {
        if (L == R) {
            node[rt] = x;
            return;
        }
        int mid = (L + R) / 2;
        if (id <= mid)upd(2 * rt, L, mid, id, x);
        else upd(2 * rt + 1, mid + 1, R, id, x);
        node[rt] = op(node[2 * rt], node[2 * rt + 1]);
    }

public:
    segtree() {

    }
    segtree(int n) {
        _n = n;
        d = vector<S>(n + 1, e());
        node = vector<S>(4 * n, e());
        build(1, 1, n);
    }

    segtree(S *a, int n) {
        _n = n;
        d = vector<S>(n + 1, e());
        node = vector<S>(4 * n, e());
        for (int i = 1; i <= n; i++)d[i] = a[i];
        build(1, 1, n);
    }

    S que(int L, int R) {
        return que(1, 1, _n, L, R);
    }

    S que(int id) {
        return que(id, id);
    }

    void upd(int id, S x) {
        upd(1, 1, _n, id, x);
    }
};


template<int T>
struct ModInt {
    const static int MD = T;
    int x;
    ModInt(ll x = 0) : x(x % MD) {}
    int get() { return x; }
    ModInt operator + (const ModInt &that) const { int x0 = x + that.x; return ModInt(x0 < MD ? x0 : x0 - MD); }
    ModInt operator - (const ModInt &that) const { int x0 = x - that.x; return ModInt(x0 < MD ? x0 + MD : x0); }
    ModInt operator * (const ModInt &that) const { return ModInt((long long)x * that.x % MD); }
    ModInt operator / (const ModInt &that) const { return *this * that.inverse(); }
    void operator += (const ModInt &that) { x += that.x; if (x >= MD) x -= MD; }
    void operator -= (const ModInt &that) { x -= that.x; if (x < 0) x += MD; }
    void operator *= (const ModInt &that) { x = (long long)x * that.x % MD; }
    void operator /= (const ModInt &that) { *this = *this / that; }
    ModInt inverse() const {
        int a = x, b = MD, u = 1, v = 0;
        while (b) {
            int t = a / b;
            a -= t * b; std::swap(a, b);
            u -= t * v; std::swap(u, v);
        }
        if (u < 0) u += MD;
        return u;
    }
};
typedef ModInt<mod> mint;


namespace lazyseg {
    int ceil_pow2(int n) {
        int x = 0;
        while ((1U << x) < (unsigned int)(n)) x++;
        return x;
    }
    template <class S,
        S(*op)(S, S),
        S(*e)(),
        class F,
        S(*mapping)(F, S),
        F(*composition)(F, F),
        F(*id)()>
        struct lazy_segtree {
        public:
            lazy_segtree() : lazy_segtree(0) {}
            explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
            explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
                log = ceil_pow2(_n);
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

            S prod(int l, int r) {
                assert(0 <= l && l <= r && r <= _n);
                if (l == r) return e();

                l += size;
                r += size;

                for (int i = log; i >= 1; i--) {
                    if (((l >> i) << i) != l) push(l >> i);
                    if (((r >> i) << i) != r) push((r - 1) >> i);
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

            void apply(int p, F f) {
                assert(0 <= p && p < _n);
                p += size;
                for (int i = log; i >= 1; i--) push(p >> i);
                d[p] = mapping(f, d[p]);
                for (int i = 1; i <= log; i++) update(p >> i);
            }
            void apply(int l, int r, F f) {
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

            template <bool(*g)(S)> int max_right(int l) {
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

            template <bool(*g)(S)> int min_left(int r) {
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
                d[k] = mapping(f, d[k]);
                if (k < size) lz[k] = composition(f, lz[k]);
            }
            void push(int k) {
                all_apply(2 * k, lz[k]);
                all_apply(2 * k + 1, lz[k]);
                lz[k] = id();
            }
    };

}














const int MAXN = 1e6 + 5;;


struct S {
    ll cnt;
    ll sum;
};
S op(S a, S b) {
    return { a.cnt + b.cnt , a.sum + b.sum };
}
S e() { return { 0,0 }; }

typedef int F;
S mp(F f, S x) {
    return { x.cnt, x.sum + f * x.cnt };
}

F cmp(F f, F g) { return f + g; }

F id() { return 0; }

int n, d;
int i;
bool vis[MAXN];
const int N = 2e5 + 5;
lazyseg::lazy_segtree<S, op, e, F, mp, cmp, id>atc_seg(3e5 + 5);


struct seg_node
{
    void upd(int L, int R, F f) {
        L = max(1, L), R = min(R,(int) 2e5);
        L--, R--;
        R++;
        atc_seg.apply(L, R, f);
    }

    S que(int L, int R) {
        L = max(1, L), R = min(R, (int) 2e5);
        L--, R--;
        R++;
        return atc_seg.prod(L, R);
    }

    void upd(int pos, S x) {
        pos--;
        atc_seg.set(pos, x);
    }
}seg;


void slove() {
    cin >> n >> d;
    ll ans = 0;
    while(n--) {
        cin >> i;
        if (!vis[i]) {
            vis[i] = 1;
            ll cL = seg.que(i - d, i - 1).cnt;
            ans += cL * (cL - 1) / 2;
            ll cR = seg.que(i + 1, i + d).cnt;
            ans += cR * (cR - 1) / 2;
            ans += seg.que(i - d, i - 1).sum - seg.que(i - d, i - 1).cnt * seg.que(1, i).cnt;
            seg.upd(i - d, 2e5, 1);
            seg.upd(i, { 1,seg.que(1,i + d).cnt + 1 });

        }
        else {
            vis[i] = 0;
            ll cL = seg.que(i - d, i - 1).cnt;
            ans -= cL * (cL - 1) / 2;
            ll cR = seg.que(i + 1, i + d).cnt;
            ans -= cR * (cR - 1) / 2;
            ans -= seg.que(i - d, i - 1).sum - seg.que(i - d, i - 1).cnt * seg.que(1, i).cnt;
            seg.upd(i - d, 2e5, -1);
            seg.upd(i, { 0,0 });
        }
        cout << ans << endl;
    }
}




signed main()
{
    IOS;
    slove();
}










