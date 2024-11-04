#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

















#define pb               push_back
#define mp(x,y)          make_pair(x,y)
#define all(x)           x.begin(), x.end()
#define allr(x)          x.rbegin(), x.rend()
#define leftmost_bit(x)  (63-__builtin_clzll(x))
#define rightmost_bit(x) __builtin_ctzll(x) 

#define set_bits(x)      __builtin_popcountll(x) 
#define pow2(i)          (1LL << (i))
#define is_on(x, i)      ((x) & pow2(i)) 

#define set_on(x, i)     ((x) | pow2(i)) 

#define set_off(x, i)    ((x) & ~pow2(i)) 

#define fi               first
#define se               second

typedef long long int ll;
typedef long double ld;

const int MOD = 1e9+7; 

const int MX = 2e5+5;
const ll INF = 1e18; 

const ld PI = acos((ld)-1);
const ld EPS = 1e-8;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; 






struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <typename T1, typename T2> 

using safe_map = unordered_map<T1, T2, custom_hash>;
 


template<typename T1, typename T2> 

istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T1, typename T2> 

ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }

template<typename T> 

istream& operator>>(istream &istream, array<T, 2> &p) { return (istream >> p[0] >> p[1]); }
template<typename T> 

ostream& operator<<(ostream &ostream, const array<T, 2> &p) { return (ostream << p[0] << " " << p[1]); }

template<typename T> 

istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v) cin >> it; return istream;}
template<typename T> 

ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

ll power(ll x, ll n, ll m = MOD){
    if (x == 0 && n == 0) return 0; 

    ll res = 1;
    while (n > 0){
        if (n % 2)
            res = (res * x) % m;
        x = (x * x) % m;
        n /= 2;
    }
    return res;
}

clock_t startTime;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
double getCurrentTime()           {return (double)(clock() - startTime) / CLOCKS_PER_SEC;}
string to_string(string s)        {return '"' + s + '"';} 
string to_string(const char* s)   {return to_string((string) s);}
string to_string(bool b)          {return (b ? "true" : "false");}
int inv(int x, int m = MOD)       {return power(x, m - 2, m);}
int getRandomNumber(int l, int r) { uniform_int_distribution<int> dist(l, r); return dist(rng);}



template <typename A, typename B>
string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL_DEBUG
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
	#define debug(...) ;
#endif



#define endl '\n' 


typedef vector<int> vi;
typedef pair<int, int> pii;
typedef array<int,2> edge; 



#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>


#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  


}  



namespace atcoder {

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
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


using namespace atcoder;

struct S {ll mx, sum, size;};
S op(S a, S b){ return {max(a.mx, b.mx), a.sum + b.sum, a.size + b.size}; }
S e(){ return {0, 0, 1};}
struct F{ll add;};
S mapping(F f, S x){ return {x.mx + f.add, x.sum + x.size*f.add, x.size};}
F compose(F f1, F f2){ return {f1.add + f2.add};}
F id(){ return {0};}

struct cut_stick{
private:
    int N;
    lazy_segtree<S, op, e, F ,mapping, compose, id> left_label;
    lazy_segtree<S, op, e, F ,mapping, compose, id> right_label;
    
public:
    cut_stick(int n){
        assert(0 <= n && n <= 1e8);

        N = n;
        left_label  = lazy_segtree<S, op, e, F ,mapping, compose, id>(n);
        right_label = lazy_segtree<S, op, e, F ,mapping, compose, id>(n);
    }

    pair<int,int> getEndPoints(int i){
        assert(0 <= i && i < N);

        int l = i - left_label. prod(i, i+1).sum;
        int r = i + right_label.prod(i, i+1).sum;

        return {l, r};
    }

    void merge(int i){
        assert(0 <= i && i < N);

        auto [l1, r1] = getEndPoints(i);
        if(r1 == N-1) return;

        auto [l2, r2] = getEndPoints(r1+1);

        left_label. apply(l2, r2+1, {r1-l1+1});
        right_label.apply(l1, r1+1, {r2-l2+1});
    }

    void cut(int i){
        assert(0 <= i && i < N);

        auto [l, r] = getEndPoints(i);
        if(i == r) return;

        left_label. apply(i+1, r+1, {-(i-l+1)});
        right_label.apply(l, i+1, {-(r-i)});
    }

	ll getNumberOfSubarrays(int x, int y){
		assert(0 <= x && x <= y && y < N);

		auto [l, r] = getEndPoints(x);
		ll ans = left_label.prod(x, y+1).sum + (y-x+1);		
		ans -= ( (x-l) * 1ll * (min(r,y)-x+1) );

		return ans;
	}

	int getLongestSubarrayLength(int x, int y){
		assert(0 <= x && x <= y && y < N);

		auto [l, r] = getEndPoints(x);
		if(r >= y) return y-x+1;

		int t = left_label.prod(r+1, y+1).mx+1;
		return max(r-x+1, t);
	}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
	cin >> N >> Q;
    
	vi vec(N);
    for(int &i: vec) cin >> i;

	cut_stick cs(N);
	for(int i = 0; i < N-1; i++){
		if(vec[i] <= vec[i+1]) cs.merge(i);
	}

	int t, l, r;
	while(Q--){
		cin >> t >> l >> r;
		if(t == 1){
			l--;
			
			if(l != 0) cs.cut(l-1);
			if(l != N-1) cs.cut(l);

			vec[l] = r;

			if(l != 0 && vec[l-1] <= vec[l]) cs.merge(l-1);
			if(l != N-1 && vec[l] <= vec[l+1]) cs.merge(l);
		}
		else{
			l--;r--;
			cout << cs.getNumberOfSubarrays(l, r) << endl;
		}
	}
    return 0;
}
