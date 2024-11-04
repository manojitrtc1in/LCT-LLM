










































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


inline int jud(double a, double b) {
	if (abs(a) < eps && abs(b) < eps) return 0;
	else if (abs1(a - b) / max(abs1(a), abs1(b)) < eps) return 0;
	if (a < b) return -1;
	return 1;
}
template <typename t> inline int jud(t a, t b) {
	if(a < b) return -1;
	if(a == b) return 0;
	return 1;
}



template <typename it, typename t1>
inline int RangeFind(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1) {
	if(na == 0) return 0;
	int be = 0, en = na - 1;
	if(*a <= *(a + na - 1)) {
		if(f_lb == 0) while(be < en) {
			int mid = (be + en + 1) / 2;
			if(jud(*(a + mid), val) != 1) be = mid;
			else en = mid - 1;
		} else while(be < en) {
			int mid = (be + en) / 2;
			if(jud(*(a + mid), val) != -1) en = mid;
			else be = mid + 1;
		}
		if (f_small && jud(*(a + be), val) == 1) be--;
		if (!f_small && jud(*(a + be), val) == -1) be++;
	} else {
		if(f_lb) while (be < en) {
			int mid = (be + en + 1) / 2;
			if (jud(*(a + mid), val) != -1) be = mid;
			else en = mid - 1;
		} else while (be < en) {
			int mid = (be + en) / 2;
			if(jud(*(a + mid), val) != 1) en = mid;
			else be = mid + 1;
		}
		if (!f_small && jud(*(a + be), val) == -1) be--;
		if (f_small && jud(*(a + be), val) == 1) be++;
	}
	return be;
}

template <class T> inline T lowb(T num) {return num & (-num); }

inline int bitnum(ui nValue) { return __builtin_popcount(nValue); }
inline int bitnum(int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(ull nValue) { return __builtin_popcountll(nValue); }
inline int bitnum(ll nValue) { return __builtin_popcountll(nValue); }
inline int id0(ui a) { if(a == 0) return 0; return 32 - __builtin_clz(a); }
inline int id0(int a) { if(a == 0) return 0; return 32 - __builtin_clz(a); }
inline int id0(ull a) { if(a == 0) return 0; return 64 - __builtin_clzll(a); }
inline int id0(ll a) { if(a == 0) return 0; return 64 - __builtin_clzll(a); }



long long pow(long long n, long long m, long long mod = 0) {
	if(m < 0) return 0;
	long long ans = 1;
	long long k = n;
	while (m) {
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
	while (a >= mod) a -= mod;
	while (a < 0) a += mod;
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








struct SegmentNode{
	int be, en;
	NODE_VAL_TYPE peak, sec_peak, sum, cnt_peak, cnt;
	NODE_VAL_TYPE lazy_add;
};
class SegmentTree{
 public:
	int l;
	NODE_VAL_TYPE inf;
	SegmentNode tree[id3 * 4];
	function<bool(const NODE_VAL_TYPE&, const NODE_VAL_TYPE&)> comp;

	inline int GetLeft(int no) {return no << 1;}
	inline int GetRight(int no) {return (no << 1) + 1;}
	inline int GetFa(int no) {return no >> 1;}
	SegmentTree(function<bool(const NODE_VAL_TYPE&, const NODE_VAL_TYPE&)> func) {
		l = 0;
		comp = func;
		if (comp(std::numeric_limits<NODE_VAL_TYPE>::min(),
				std::numeric_limits<NODE_VAL_TYPE>::max())) {
			inf = std::numeric_limits<NODE_VAL_TYPE>::max();
		} else {
			inf = std::numeric_limits<NODE_VAL_TYPE>::min();
		}
	}

	void Build(int no, int l, int r){
		if(l > r) r = l;
		if(l == r){
			tree[no].be = tree[no].en = l;
			tree[no].lazy_add = 0;
			tree[no].sum = tree[no].cnt = 0;
			tree[no].peak = tree[no].sec_peak = inf;
			tree[no].cnt_peak = 0;
			return;
		}
		tree[no].be = l; tree[no].en = r;
		int mid = (l + r) / 2;
		Build(GetLeft(no), l, mid);
		Build(GetRight(no), mid + 1, r);
		tree[no].lazy_add = 0;
		PushUp(no);
	}
	inline void PushUp(int no) {
		int le = GetLeft(no), ri = GetRight(no);
		tree[no].sum = tree[le].sum + tree[ri].sum;
		tree[no].cnt = tree[le].cnt + tree[ri].cnt;
		if (comp(tree[le].peak, tree[ri].peak)) {
			tree[no].peak = tree[le].peak;
			tree[no].cnt_peak = tree[le].cnt_peak;
			tree[no].sec_peak =
					comp(tree[le].sec_peak, tree[ri].peak) ?
							tree[le].sec_peak : tree[ri].peak;
		} else if (comp(tree[ri].peak, tree[le].peak)) {
			tree[no].peak = tree[ri].peak;
			tree[no].cnt_peak = tree[ri].cnt_peak;
			tree[no].sec_peak =
					comp(tree[ri].sec_peak, tree[le].peak) ?
							tree[ri].sec_peak : tree[le].peak;
		} else {
			tree[no].peak = tree[le].peak;
			tree[no].cnt_peak = tree[le].cnt_peak + tree[ri].cnt_peak;
			tree[no].sec_peak =
					comp(tree[ri].sec_peak, tree[le].sec_peak) ?
							tree[ri].sec_peak : tree[le].sec_peak;
		}
		tree[no].lazy_add = 0;
	}
	inline void PushDown(int no) {
		int le = GetLeft(no), ri = GetRight(no);
		if (tree[no].lazy_add) {
			tree[le].lazy_add += tree[no].lazy_add;
			tree[le].sum += tree[no].lazy_add * tree[le].cnt;
			if (tree[le].peak != inf) tree[le].peak += tree[no].lazy_add;
			if (tree[le].sec_peak != inf)tree[le].sec_peak += tree[no].lazy_add;
			tree[ri].lazy_add += tree[no].lazy_add;
			tree[ri].sum += tree[no].lazy_add * tree[ri].cnt;
			if (tree[ri].peak != inf) tree[ri].peak += tree[no].lazy_add;
			if (tree[ri].sec_peak != inf) tree[ri].sec_peak += tree[no].lazy_add;
		}
		if (comp(tree[le].peak, tree[no].peak)) {
			tree[le].sum -= tree[le].cnt_peak * (tree[le].peak - tree[no].peak);
			tree[le].peak = tree[no].peak;
		}
		if (comp(tree[ri].peak, tree[no].peak)) {
			tree[ri].sum -= tree[ri].cnt_peak * (tree[ri].peak - tree[no].peak);
			tree[ri].peak = tree[no].peak;
		}
		tree[no].lazy_add = 0;
	}
	void UpdTo(int l, int r, int no, NODE_VAL_TYPE bound ){
		if (l > r) return;
		if(l <= tree[no].be && r >= tree[no].en && !comp(tree[no].sec_peak, bound)) {
			if (comp(tree[no].peak, bound)) {
				tree[no].sum -= tree[no].cnt_peak * (tree[no].peak - bound);
				tree[no].peak = bound;
			}
			return;
		}
		if (tree[no].be != tree[no].en) PushDown(no);
		int mid = (tree[no].be + tree[no].en) >> 1;
		if (r >= tree[no].be && l <= mid) UpdTo(l, r, GetLeft(no), bound);
		if (r >= mid + 1 && l <= tree[no].en) UpdTo(l, r, GetRight(no), bound);
		PushUp(no);
	}
	void UpdAdd(int l, int r, int no, NODE_VAL_TYPE ranadd) {
		if (l > r) return;
		if (l <= tree[no].be && r >= tree[no].en){
			tree[no].lazy_add += ranadd;
			tree[no].sum += ranadd * tree[no].cnt;
			if (comp(tree[no].peak, inf)) tree[no].peak += ranadd;
			if (comp(tree[no].sec_peak, inf)) tree[no].sec_peak += ranadd;
			return;
		}
		if (tree[no].be != tree[no].en) PushDown(no);
		int mid = (tree[no].be + tree[no].en) >> 1;
		if (r >= tree[no].be && l <= mid) UpdAdd(l, r, GetLeft(no), ranadd);
		if (r >= mid + 1 && l <= tree[no].en) UpdAdd(l, r, GetRight(no), ranadd);
		PushUp(no);
	}
	void AddNewVal(int loc, int no, NODE_VAL_TYPE new_val) {
		if (loc <= tree[no].be && loc >= tree[no].en) {
			tree[no].cnt = 1;
			tree[no].sum = new_val;
			tree[no].peak = new_val;
			tree[no].cnt_peak = 1;
			tree[no].lazy_add = 0;
			return;
		}
		if (tree[no].be != tree[no].en) PushDown(no);
		int mid = (tree[no].be + tree[no].en) >> 1;
		if (loc <= mid) AddNewVal(loc, GetLeft(no), new_val);
		else AddNewVal(loc, GetRight(no), new_val);
		PushUp(no);
	}
	NODE_VAL_TYPE GetSum(int l, int r, int no){
		if (l > r) return 0;
		if (l <= tree[no].be && r >= tree[no].en)
			return tree[no].sum;
		if (tree[no].be != tree[no].en) PushDown(no);
		NODE_VAL_TYPE ans = 0;
		int mid = (tree[no].be + tree[no].en) >> 1;
		if (r >= tree[no].be && l <= mid) ans += GetSum(l, r, GetLeft(no));
		if (r >= mid + 1 && l <= tree[no].en) ans += GetSum(l, r, GetRight(no));
		return ans;
	}
	int GetRank(int rank, int no){
		if (rank > tree[no].sum) return -1;
		if (tree[no].be == tree[no].en) return tree[no].be;
		if (tree[no].be != tree[no].en) PushDown(no);
		if (rank <= tree[GetLeft(no)].sum) return GetRank(rank, GetLeft(no));
		return GetRank(rank - tree[GetLeft(no)].sum, GetRight(no));
	}
	inline int GetSectionRank(int l, int r, int rank){
		return GetRank(rank + GetSum(0, l - 1, 1), 1);
	}
};

SegmentTree id2([](const ll& a, const ll& b) {return a > b;});
SegmentTree id1([](const ll& a, const ll& b) {return a < b;});

const int maxn = id3;
int n;
int orig[maxn], loc[maxn], rk[maxn];



template <class t> struct tree_array{
	t num[N], n, bigwei;
	void init(int nn = N){
		n = nn;
		while(lowb(nn) != nn) nn -= lowb(nn);
		bigwei = nn;
		n = bigwei * 2;
	}
	void upd(int no, t add){
		while(no <= n){
			num[no] += add;
			no += lowb(no);
		}
	}
	t que(int no){
		t ans = 0;
		while(no){
			ans += num[no];
			no -= lowb(no);
		}
		return ans;
	}
	 int getrank(t x){
		 int ans = 0, ranwei = bigwei; t rank = 0;
		 while(ranwei){
			 if(rank + num[ranwei + ans] < x){
				 ans += ranwei;
				 rank += num[ans];
			 }
			 ranwei >>= 1;
		 }
		 return ans + 1;
	 }
};
tree_array<int> ta;

int main() {




	ios_base::sync_with_stdio(0);
	

	freopen("input.txt", "r", stdin);
	


	scanf("%d", &n);
	ta.init(n + 10);
	for (int i = 0; i < n; i++) {
		scanf("%d", orig + i);
		loc[orig[i]] = i;
		rk[orig[i]] = ta.que(orig[i]) + 1;
		ta.upd(orig[i], 1);
	}
	id2.Build(1, 0, n - 1);
	id1.Build(1, 0, n - 1);
	for (int i = 1; i <= n; i++) {
		id2.AddNewVal(loc[i], 1, i);
		id1.AddNewVal(loc[i], 1, 0);
		id2.UpdAdd(loc[i] + 1, n - 1, 1, 1);
		id1.UpdAdd(loc[i] + 1, n - 1, 1, 1);
		id2.UpdTo(0, loc[i] - 1, 1, rk[i] - 1);
		id1.UpdTo(loc[i] + 1, n - 1, 1, rk[i]);
		printf("%I64d\n", id2.GetSum(0, n - 1, 1) - id1.GetSum(0, n - 1, 1));
	}


	return 0;
}
