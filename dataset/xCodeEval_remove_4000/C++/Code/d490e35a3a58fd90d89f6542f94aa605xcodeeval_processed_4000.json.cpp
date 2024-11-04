
using namespace std;

using ull = unsigned long long;
using ll = long long;



















ll qp(ll a, ll b, int mo) { ll ans = 1; do { if (b & 1) ans = 1ll * ans * a % mo; a = 1ll * a * a % mo; } while (b >>= 1); return ans; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll temp = gcd(a, b); return temp ? (a / temp * b) : 0; }
int mDays[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dx8[] = { 1, -1, 0, 0, 1, 1, -1, -1 }, dy8[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

template <typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }
template <typename T, typename... Ts>
auto make_v(size_t a, size_t b, Ts... ts) { return vector<decltype(make_v<T>(b, ts...))>(a, make_v<T>(b, ts...)); }
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }
template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v) { for (auto &e : t) fill_v(e, v); }





const ll INF_LL = (1ll << 60);
const int INF_INT = (int)1e9;
const ll MOD_CONST = (ll)(1e9 + 7);

template <typename T>
vector<T> pows(int b, int n) {
    vector<T> ret;
    T x = 1;
    while (ret.size() < n) {
        ret.push_back(x);
        x *= b;
    }
    return ret;
}


void strReplace(std::string& str, const std::string& from, const std::string& to) {
	std::string::size_type pos = 0;
	while (pos = str.find(from, pos), pos != std::string::npos) {
		str.replace(pos, from.length(), to);
		pos += to.length();
	}
}
template <class T>
bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T>
bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

inline tuple<ll, ll> rotate45(tuple<ll, ll> point) { ll x = get<0>(point), y = get<1>(point); return tuple<ll, ll>(x + y, x - y); }
inline bool id2(int nx, int ny, int Width, int Height) { return nx >= 0 and nx < Width and ny >= 0 and ny < Height; }

template <typename T>
vector<T> INPA(ll n) {
	vector<T> x;
	REP(i, n) {
		T tmp; cin >> tmp;
		x.push_back(tmp);
	}
	return move(x);
}
template <typename T>
void out(T o) { cout << o << endl; }
template <typename T>
void out(vector<T> &out) { REP(i, (int)out.size()) { cout << out[i]; if (i == (int)out.size() - 1) cout << endl; else cout << " "; } }
template <typename T>
void out(vector<vector<T>> o) { REP(i, o.size()) out(o[i]); }
void YesNo(bool f) { cout << (f?"Yes":"No") << endl; }
void YESNO(bool f) { cout << (f?"YES":"NO") << endl; }




string id0(vector<string>& strs) {
    int n = INT_MAX;
    if (strs.size() <= 0) {
        return "";
    }
    if (strs.size() == 1) {
        return strs[0];
    }
    

    for (int i = 0; i < strs.size(); i ++) {
        n = strs[i].length() < n ? strs[i].length() : n ;
    }
    for (int i = 0; i < n; i ++) { 

        for (int j = 1; j < strs.size(); j ++) {
            if (strs[j][i] != strs[j - 1][i]) { 

                return strs[0].substr(0, i);
            }
        }
    }
    

    return strs[0].substr(0, n);
}

namespace PrimeLib {
	

	template<typename T, std::enable_if_t<std::is_unsigned<T>::value, std::nullptr_t> = nullptr>
	bool is_prime(const T n) {
		if (n < 4) return n == 2 || n == 3;
		if (n % 2 == 0 || n % 3 == 0 || (n % 6 != 1 && n % 6 != 5)) return false;
		for (T i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return false;
		return true;
	}
	

	

	vector<ll> primeTable(ll n) {
		vector<bool> table(n - 1);
		vector<ll> ret;
		for (ll i = 0; i < n - 1; ++i) {
			if (table[i] == false) {
				ll num = i + 2;
				ret.push_back(i + 2);
				for (int j = i + num; j < n - 1; j += num)
					table[j] = true;	
			}
		}
		return ret;
	}
	vector<ll> factorize(ll n, vector<ll> &pt) {
		vector<ll> ret;
		int pos = 0;
		ll c = n;
		while (c != 1) {
			ll p = pt[pos];
			ret.push_back(0);
			while (c % p == 0) {
				ret[pos]++;
				c /= p;
			}
			pos++; if (pos >= pt.size()) break;
		}
		

		

		

		if (c != 1 ) ret.push_back(1);
		return ret;
	}
}

ll p_base(ll base, ll x) {
	ll ans = 1;
	REP(i, x) {
		ans *= base;
		ans %= MOD_CONST;
	}
	return ans;
}

class ListG {
public:
	vector<vector<int>> to;

	ListG(int s) : root(-1) {
		size = s;
		to = make_v<vector<int>>(size);
	}

	void addDirectedEdge(int f, int t) {
		to[f].push_back(t);
	}
	void addIndirectedEdge(int v1, int v2) {
		addDirectedEdge(v1, v2);
		addDirectedEdge(v2, v1);
	}

	void dfs(int x) {
		

	}

	void makeTree(int r) {
		root = r;
		p = make_v<int>(size);
		p[root] = -1;
		depth = make_v<int>(size);
		mtdfs(root, 0);
		

		auto idxs = make_v<int>(size);
		iota(all(idxs), 0);
		leaf_idx = set<int>(all(idxs));
		FOR(i, 1, size)
			leaf_idx.erase(p[i]);
	}

	void makeEulerTour() {
		assert(root >= 0);
		et_begin = make_v<int>(size);
		et_end = make_v<int>(size);
		tmp_k = 0;
		etdfs(root, -1);
	}

	int size, root;
	vector<int> p; 

	vector<int> depth; 

	vector<int> euler_tour;
	vector<int> et_begin, et_end;
	set<int> leaf_idx;

	int tmp_k;
private:	
	void mtdfs(int c, int d) {
		depth[c] = d;
		REP(i, to[c].size()) {
			int next = to[c][i];
			if (p[c] == next) continue;
			p[next] = c;
			mtdfs(next, d + 1);
		}
	}
	void etdfs(int vidx, int pidx) {
		et_begin[vidx] = tmp_k;
		euler_tour.push_back(vidx);
		tmp_k++;
		REP(i, to[vidx].size()) {
			if (to[vidx][i] != pidx) {
				etdfs(to[vidx][i], vidx);
				euler_tour.push_back(vidx);
				tmp_k++;
			}
		}
		et_end[vidx] = tmp_k;
	}
};

template <typename T>
class id4 {
public:
	int size;
	vector<T> data;

	id4(int s, T initial_value = T(0)) {
		size = s;
		data = make_v<T>(size+1);
		fill_v(data, initial_value);
	}
	
	void add(int idx, T value) {
		while (idx <= size) {
			data[idx] += value;
			idx += idx & -idx;
		}
	}

	T sum(int idx) {
		T s = 0;
		while (idx > 0) {
			s += data[idx];
			idx -= idx & -idx;
		}
		return s;
	}
};







class id3 {
public:
	int size;
	bool id1;
	vector<ll> minimum, lazy;
	
	id3(int s, ll initial_value = 0ll, bool take_mod = false) {
		size = 1;
		id1 = take_mod;
		while (size < s)
			size <<= 1;
		minimum = make_v<ll>(2 * size);
		fill_v(minimum, initial_value);
		lazy = make_v<ll>(2 * size);
		fill_v(lazy, initial_value);
	}

	

	void update(int l, int r, ll addValue) {
		update(l, r, 0, 0, size, addValue);
	}

	

	ll query(int l, int r) {
		return query(l, r, 0, 0, size);
	}
private:
	ll query(int l, int r, int k, int lc, int rc) {
		lazy_eval(k);
		if (rc <= l or r <= lc)
			return INT64_MAX;
		else if (l <= lc and rc <= r) {
			return minimum[k];
		} else {
			int lcidx = k * 2 + 1, pidx = (lc + rc) / 2;
			return min(
				query(l, r, lcidx, lc, pidx),
				query(l, r, lcidx + 1, pidx, rc)
			);
		}
	}

	void lazy_eval(int k) {
		ll lk = lazy[k];
		minimum[k] += lk; if (id1) minimum[k] %= MOD_CONST;
		if (k < size - 1) {
			int lcidx = 2 * k + 1;
			lazy[lcidx] += lk; if (id1) lazy[lcidx] %= MOD_CONST;
			lazy[lcidx + 1] += lk; if (id1) lazy[lcidx + 1] %= MOD_CONST;
		}
		lazy[k] = 0;
	}
	void update(int l, int r, int k, int lc, int rc, ll addValue) {
		if (rc <= l or r <= lc)
			return;
		else if (l <= lc and rc <= r) {
			lazy[k] += addValue; if (id1) lazy[k] %= MOD_CONST;
			lazy_eval(k);
		} else {
			lazy_eval(k);
			int lcidx = k * 2 + 1, pidx = (lc + rc) / 2;
			update(l, r, lcidx, lc, pidx, addValue);
			update(l, r, lcidx + 1, pidx, rc, addValue);
			if (lazy[lcidx] != 0) lazy_eval(lcidx);
			if (lazy[lcidx+1] != 0) lazy_eval(lcidx+1);
			minimum[k] = min(minimum[lcidx], minimum[lcidx + 1]);
		}
	}
};

template <typename T,typename E>
struct SegmentTree{
  typedef function<T(T,E)> G;
  typedef function<T(E,E)> H;
  int n;
  G g;
  H h;
  T d1;
  E d0;
  vector<T> dat;
  vector<E> laz;
  SegmentTree(int n_,G g,H h,T d1,E d0,
	      vector<T> v=vector<T>()){
    this->g=g;
    this->h=h;
    this->d1=d1;
    this->d0=d0;
    init(n_);
    if(n_==(int)v.size()) build(n_,v);
  }
  void init(int n_){
    n=1;
    while(n<n_) n*=2;
    dat.clear();
    dat.resize(n,d1);
    laz.clear();
    laz.resize(2*n-1,d0);
  }
  void build(int n_, vector<T> v){
    for(int i=0;i<n_;i++) dat[i]=v[i];
  }
  void update(int a,int b,E x,int k,int l,int r){
    if(r<=a||b<=l) return;
    if(a<=l&&r<=b){
      laz[k]=h(laz[k],x) % MOD_CONST;
      return;
    }
    update(a,b,x,k*2+1,l,(l+r)/2);
    update(a,b,x,k*2+2,(l+r)/2,r);
  }
  void update(int a,int b,E x){
    update(a,b,x,0,0,n);
  }
  T query(int k){
    T c=dat[k];
    k+=n-1;
    E x=laz[k];
    while(k>0){
      k=(k-1)/2;
      x=h(x,laz[k]) % MOD_CONST;
    }
    return g(c,x) % MOD_CONST;
  }
};

int main(void)
{
    cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(20);

	IN1(N);
	ListG lg(N);
	REP(i, N-1) {
		IN1(v); v--;
		lg.addIndirectedEdge(v, i + 1);
	}
	lg.makeTree(0);
	lg.makeEulerTour();
	int n = lg.euler_tour.size();	


	SegmentTree<ll, ll> ps(n,
			   [](int a,int b){return a+b;},
			   [](int a,int b){return a+b;},
			   0,0);
	SegmentTree<ll, ll> ms(n,
			   [](int a,int b){return a+b;},
			   [](int a,int b){return a+b;},
			   0,0);
	IN1(Q);
	REP(i, Q) {
		IN1(t); IN1(v); v--;
		if (t == 1) {
			IN1(x); IN1(k);
			ll p = (x + k * lg.depth[v]) % MOD_CONST;
			ps.update(lg.et_begin[v], lg.et_end[v], p);
			ms.update(lg.et_begin[v], lg.et_end[v], k);
		} else {
			int bidx = lg.et_begin[v];
			ll p = ps.query(bidx) % MOD_CONST;

			ll m = (lg.depth[v] * ms.query(bidx)) % MOD_CONST;

			ll ans = (((p - m)%MOD_CONST) + MOD_CONST) % MOD_CONST;
			out(ans);
		}
	}

	return 0;
}