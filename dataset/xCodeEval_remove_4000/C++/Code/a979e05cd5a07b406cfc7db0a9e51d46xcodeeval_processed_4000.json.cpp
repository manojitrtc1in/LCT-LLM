




































using namespace std;





using namespace tr1;









using namespace __gnu_pbds;


typedef __gnu_pbds::priority_queue<int, greater<int>, pairing_heap_tag> pq_type;


typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> tree_type;



typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <double, double> pdd;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <double> vd;
typedef vector <string> vs;
typedef map <string, int> mpsi;
typedef map <double, int> mpdi;
typedef map <int, int> mpii;

const double pi = acos(0.0) * 2.0;
const long double eps = 1e-10;
const int step[8][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};

template <class T> inline T abs1(T a) {return a < 0 ? -a : a;}


template <class T> inline T max1(T a, T b) { return b < a ? a : b; }
template <class T> inline T max1(T a, T b, T c) { return max1(max1(a, b), c); }
template <class T> inline T max1(T a, T b, T c, T d) { return max1(max1(a, b, c), d); }
template <class T> inline T max1(T a, T b, T c, T d, T e) { return max1(max1(a, b, c, d), e); }
template <class T> inline T min1(T a, T b) { return a < b ? a : b; }
template <class T> inline T min1(T a, T b, T c) { return min1(min1(a, b), c); }
template <class T> inline T min1(T a, T b, T c, T d) { return min1(min1(a, b, c), d); }
template <class T> inline T min1(T a, T b, T c, T d, T e) { return min1(min1(a, b, c, d), e); }

template <typename t, typename t1>
t min1(t a, t1 b) { return a < b ? a : b; }
template <typename t, typename... arg>
t min1(t a, arg... arr) { return min1(a, min1(arr...)); }
template <typename t, typename t1>
t max1(t a, t1 b) { return a > b ? a : b; }
template <typename t, typename... arg>
t max1(t a, arg... arr) { return max1(a, max1(arr...)); }


inline int jud(double a, double b){
	if(abs(a) < eps && abs(b) < eps) return 0;
	else if(abs1(a - b) / abs1(a) < eps) return 0;
	if(a < b) return -1;
	return 1;
}
template <typename t> inline int jud(t a, t b){
	if(a < b) return -1;
	if(a == b) return 0;
	return 1;
}



template <typename it, typename t1>
inline int find(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1){
	if(na == 0) return 0;
	int be = 0, en = na - 1;
	if(*a <= *(a + na - 1)){
		if(f_lb == 0) while(be < en){
			int mid = (be + en + 1) / 2;
			if(jud(*(a + mid), val) != 1) be = mid;
			else en = mid - 1;
		}else while(be < en){
			int mid = (be + en) / 2;
			if(jud(*(a + mid), val) != -1) en = mid;
			else be = mid + 1;
		}
		if(f_small && jud(*(a + be), val) == 1) be--;
		if(!f_small && jud(*(a + be), val) == -1) be++;
	} else {
		if(f_lb) while(be < en){
			int mid = (be + en + 1) / 2;
			if(jud(*(a + mid), val) != -1) be = mid;
			else en = mid - 1;
		}else while(be < en){
			int mid = (be + en) / 2;
			if(jud(*(a + mid), val) != 1) en = mid;
			else be = mid + 1;
		}
		if(!f_small && jud(*(a + be), val) == -1) be--;
		if(f_small && jud(*(a + be), val) == 1) be++;
	}
	return be;
}

template <class T> inline T lowb(T num) {return num & (-num); }

inline int bitnum(ui nValue) { return __builtin_popcount(nValue); }
inline int bitnum(int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(ull nValue) { return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32); }
inline int bitnum(ll nValue) { return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32); }
inline int id1(ui a) { if(a == 0) return 0; return 32 - __builtin_clz(a); }
inline int id1(int a) { if(a == 0) return 0; return 32 - __builtin_clz(a); }
inline int id1(ull a) { int temp = a >> 32; if(temp) return 32 - __builtin_clz(temp) + 32; return id1(int(a)); }
inline int id1(ll a) { int temp = a >> 32; if(temp) return 32 - __builtin_clz(temp) + 32; return id1(int(a)); }



long long pow(long long n, long long m, long long mod = 0){
	if(m < 0) return 0;
	long long ans = 1;
	long long k = n;
	while(m){
		if(m & 1) {
			ans *= k;
			if(mod) ans %= mod;
		}
		k *= k;
		if(mod) k %= mod;
		m >>= 1;
	}
	return ans;
}


template <class t1, class t2>
inline void add(t1 &a, t2 b, int mod = -1) {
	if(mod == -1) mod = MOD;
	a += b;
	while(a >= mod) a -= mod;
	while(a < 0) a += mod;
}
template <class t>
void output1(t arr) {
	for(int i = 0; i < (int)arr.size(); i++)
		cerr << arr[i] << ' ';
	cerr << endl;
}
template <class t>
void output2(t arr) {
	for(int i = 0; i < (int)arr.size(); i++)
		output1(arr[i]);
}







template <class t> struct segment_node{
	int be, en;
	t maxv, add, sum;
};
template <class t> struct segment_tree{
	int l;
	segment_node <t> tree[N * 4];

	inline int gleft(int no) {return no << 1;}
	inline int gright(int no) {return (no << 1) + 1;}
	inline int gfa(int no) {return no >> 1;}
	inline segment_tree(){ l = 0; }

	void build(int no, int l, int r, t orig = 0, t *a = NULL){
		if(l > r) r = l;
		if(l == r){
			tree[no].be = tree[no].en = l;
			tree[no].add = 0;
			if(a == NULL) tree[no].maxv = orig;
			else tree[no].maxv = a[l];
			tree[no].add = 0;
			tree[no].sum = tree[no].maxv;
			return;
		}
		tree[no].be = l; tree[no].en = r;
		int mid = (l + r) / 2;
		build(gleft(no), l, mid, orig, a);
		build(gright(no), mid + 1, r, orig, a);
		tree[no].sum = tree[gleft(no)].sum + tree[gright(no)].sum;
		tree[no].add = 0;
		tree[no].maxv = max1(tree[gleft(no)].maxv, tree[gright(no)].maxv);
	}
	inline void relax(int no) {
		int le = gleft(no), ri = gright(no);
		tree[le].add += tree[no].add;
		tree[le].sum += tree[no].add * (tree[le].en - tree[le].be + 1);
		tree[le].maxv += tree[no].add;
		tree[ri].add += tree[no].add;
		tree[ri].sum += tree[no].add * (tree[ri].en - tree[ri].be + 1);
		tree[ri].maxv += tree[no].add;
		tree[no].add = 0;
	}
	void down(int l, int r, int no, t ranadd){
		if(r < l) return;
		if(l <= tree[no].be && r >= tree[no].en){
			tree[no].add += ranadd;
			tree[no].sum += ranadd * (tree[no].en - tree[no].be + 1);
			tree[no].maxv += ranadd;
			return;
		}
		if(tree[no].add && tree[no].be != tree[no].en) relax(no);
		int mid = (tree[no].be + tree[no].en) >> 1;
		if(r >= tree[no].be && l <= mid) down(l, r, gleft(no), ranadd);
		if(r >= mid + 1 && l <= tree[no].en) down(l, r, gright(no), ranadd);
		tree[no].sum = tree[gleft(no)].sum + tree[gright(no)].sum;
		tree[no].maxv = max1(tree[gleft(no)].maxv, tree[gright(no)].maxv);
	}
	void setno(int loc, int no, t ranadd){
		if(loc <= tree[no].be && loc >= tree[no].en){
			tree[no].sum = max(ranadd, tree[no].sum);
			tree[no].maxv = tree[no].sum;
			return;
		}
		if(tree[no].add && tree[no].be != tree[no].en) relax(no);
		int mid = (tree[no].be + tree[no].en) >> 1;
		if(loc <= mid) setno(loc, gleft(no), ranadd);
		else setno(loc, gright(no), ranadd);
		tree[no].sum = tree[gleft(no)].sum + tree[gright(no)].sum;
		tree[no].maxv = max1(tree[gleft(no)].maxv, tree[gright(no)].maxv);
	}
	t getmax(int l, int r, int no){
		if(l > r) return 0;
		if(l <= tree[no].be && r >= tree[no].en)
			return tree[no].maxv;
		if(tree[no].add && tree[no].be != tree[no].en) relax(no);
		t ans = 0;
		int mid = (tree[no].be + tree[no].en) >> 1;
		if(r >= tree[no].be && l <= mid) ans = max(ans, getmax(l, r, gleft(no)));
		if(r >= mid + 1 && l <= tree[no].en) ans = max(ans, getmax(l, r, gright(no)));
		return ans;
	}
};

segment_tree <int> sgt, have;

const int maxn = N;
int trans[maxn], lt;

int n, r;
pii orig[maxn];

pii ev[maxn * 5];
int lev, rhave[maxn];

int main() {




	ios_base::sync_with_stdio(0);
	

	freopen("input.txt", "r", stdin);
	int id0 = 256 << 20; 

	char *__p__ = (char*)malloc(id0) + id0;
	__asm__("movl %0, %%esp\n" :: "r"(__p__));
	


	scanf("%d%d", &n, &r);
	int rn = n;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &orig[i].first, &orig[i].second);
		if(orig[i].first < 0) orig[i].first = 0;
		if(orig[i].second < 0) {


			i--;


			n--;
			continue;
		}
		if(orig[i].second - orig[i].first >= 2 * r) {
			n--;
			ans++;
			i--;
			continue;
		}
	}
	sort(orig, orig + n);
	for(int i = 0; i < n; i++) {
		if(orig[i].second - orig[i].first >= r) {
			ev[lev++] = mpr(orig[i].first - r, 2 + i);
			ev[lev++] = mpr(orig[i].second - r + 1, -i - 2 * maxn);
			ev[lev++] = mpr(orig[i].first + r, 0);
		} else {
			ev[lev++] = mpr(orig[i].first, 1);
			ev[lev++] = mpr(min(orig[i].second + 1, orig[i].first + r), 0);
			ev[lev++] = mpr(orig[i].first - r, 2 + i);
			ev[lev++] = mpr(orig[i].second - r + 1, -i - 2 * maxn);
		}
		ev[lev++] = mpr(orig[i].first + r, - i - 1);
		trans[i] = orig[i].first % r;
	}
	if(r == 1 || n == 0) {
		printf("%d\n", ans + n);
		return 0;
	}






















	sort(ev, ev + lev);
	sort(trans, trans + n);
	lt = unique(trans, trans + n) - trans;

	sgt.build(1, 0, lt - 1);
	have.build(1, 0, n - 1);
	int yu = 0, radd = 0;
	for(int i = 0; i < lev; i++) {
		if(i) {
			int last = ev[i - 1].first, now = ev[i].first;
			if(now - last > 0 && radd) {
				now--;
				int rl = last, rn = now;
				last = find(last % r, trans, lt, 0, 1);
				now = find(now % r, trans, lt, 1, 0);
				if(!(last > now && rl % r <= rn % r)) {
					if(last > now) {
						sgt.down(last, lt - 1, 1, radd);
						sgt.down(0, now, 1, radd);
					} else
						sgt.down(last, now, 1, radd);
				}
			}
		}
		if(ev[i].second == 0)
			radd--;
		else if(ev[i].second == 1)
			radd++;
		else if(ev[i].second >= 2 && ev[i].second < 2 * maxn) {
			yu++;
			int no = ev[i].second - 2;
			int rp = find(mpr(orig[no].first, -MOD), orig, n, 1, 0);
			int rp1 = find(mpr(orig[no].first - r, MOD), orig, n, 1, 0);
			have.down(0, rp, 1, 1);
			have.setno(no, 1, max(sgt.tree[1].maxv + yu, have.getmax(0, rp1, 1)));
			rhave[no] =  max(sgt.tree[1].maxv + yu, have.getmax(0, rp1, 1));
		} else if(ev[i].second >= - maxn){
			int no = -ev[i].second - 1;
			sgt.setno(find(ev[i].first % r, trans, lt), 1, rhave[no]);
		} else {
			int no = -ev[i].second - 2 * maxn;
			if(orig[no].second - orig[no].first >= r) {
				radd++;
				int last = orig[no].first, now = ev[i].first - 1;
				int rl = last, rn = now;
				last = find(last % r, trans, lt, 0, 1);
				now = find(now % r, trans, lt, 1, 0);
				if(!(last > now && rl % r <= rn % r)) {
					if(last > now) {
						sgt.down(last, lt - 1, 1, 1);
						sgt.down(0, now, 1, 1);
					} else
						sgt.down(last, now, 1, 1);
				}
			}
			int rp = find(mpr(orig[no].first - 1, MOD), orig, n, 1, 0);
			have.down(0, rp, 1, -1);
			yu--;
		}
	}
	cout << sgt.tree[1].maxv + ans << endl;

















    return 0;
}
