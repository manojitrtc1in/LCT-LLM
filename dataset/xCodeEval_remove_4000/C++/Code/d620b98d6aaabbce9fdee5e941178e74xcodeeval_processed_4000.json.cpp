












using namespace std;





using namespace tr1;










using namespace __gnu_pbds;


typedef __gnu_pbds::priority_queue<int, greater<int>, pairing_heap_tag> pq_type;


typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> tree_type;



typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef __uint128_t ulll;
typedef __int128_t lll;
std::istream& operator >>(std::istream &src, __uint128_t& tmp) {
	std::istream::sentry s(src);
	if (s) {
		char buffer[128];
		src >> buffer;
		char* ptr = buffer;
		tmp = 0;
		while (*ptr <= '9' && *ptr >= '0') {
			tmp = tmp * 10 + (*ptr - '0');
			++ptr;
		}
		if (buffer[0] == '-') tmp = -tmp;
	}
	return src;
}
std::istream& operator >>(std::istream &src, __int128_t& tmp) {
	std::istream::sentry s(src);
	if (s) {
		char buffer[128];
		src >> buffer;
		char* ptr = buffer;
		if (*ptr == '-') ++ptr;
		tmp = 0;
		while (*ptr <= '9' && *ptr >= '0') {
			tmp = tmp * 10 + (*ptr - '0');
			++ptr;
		}
		if (buffer[0] == '-') tmp = -tmp;
	}
	return src;
}
std::ostream& operator <<(std::ostream &dest, __uint128_t tmp) {
	std::ostream::sentry s(dest);
	if (s) {
		char buffer[128];
		char *d = std::end(buffer);
		do {
			--d;
			*d = "0123456789"[tmp % 10];
			tmp /= 10;
		} while (tmp != 0);
		int len = std::end(buffer) - d;
		if (dest.rdbuf()->sputn(d, len) != len) {
			dest.setstate(std::ios_base::badbit);
		}
	}
	return dest;
}
std::ostream& operator<<(std::ostream &dest, __int128_t value) {
	std::ostream::sentry s(dest);
	if (s) {
		if (value < 0) dest << "-";
		__uint128_t tmp = value < 0 ? -value : value;
		dest << tmp;
	}
	return dest;
}
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef map<string, int> mpsi;
typedef map<double, int> mpdi;
typedef map<int, int> mpii;

const double pi = acos(0.0) * 2.0;
const long double eps = 1e-10;
const int step[8][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 1 }, {
		1, 1 }, { 1, -1 }, { -1, -1 } };

template<class T> inline T abs1(T a) {
	return a < 0 ? -a : a;
}


template <class T> inline T max1(T a, T b) { return b < a ? a : b; }
template <class T> inline T max1(T a, T b, T c) { return max1(max1(a, b), c); }
template <class T> inline T max1(T a, T b, T c, T d) { return max1(max1(a, b, c), d); }
template <class T> inline T max1(T a, T b, T c, T d, T e) { return max1(max1(a, b, c, d), e); }
template <class T> inline T min1(T a, T b) { return a < b ? a : b; }
template <class T> inline T min1(T a, T b, T c) { return min1(min1(a, b), c); }
template <class T> inline T min1(T a, T b, T c, T d) { return min1(min1(a, b, c), d); }
template <class T> inline T min1(T a, T b, T c, T d, T e) { return min1(min1(a, b, c, d), e); }

template<typename t, typename t1>
t min1(t a, t1 b) {
	return a < b ? a : b;
}
template<typename t, typename ... arg>
t min1(t a, arg ... arr) {
	return min1(a, min1(arr...));
}
template<typename t, typename t1>
t max1(t a, t1 b) {
	return a > b ? a : b;
}
template<typename t, typename ... arg>
t max1(t a, arg ... arr) {
	return max1(a, max1(arr...));
}


inline int jud(double a, double b) {
	if (abs(a) < eps && abs(b) < eps)
		return 0;
	else if (abs1(a - b) / max(abs1(a), abs1(b)) < eps) return 0;
	if (a < b) return -1;
	return 1;
}
template<typename t> inline int jud(t a, t b) {
	if (a < b) return -1;
	if (a == b) return 0;
	return 1;
}



template<typename it, typename t1>
inline int RangeFind(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1) {
	if (na == 0) return 0;
	int be = 0, en = na - 1;
	if (*a <= *(a + na - 1)) {
		if (f_lb == 0)
			while (be < en) {
				int mid = (be + en + 1) / 2;
				if (jud(*(a + mid), val) != 1)
					be = mid;
				else
					en = mid - 1;
			}
		else
			while (be < en) {
				int mid = (be + en) / 2;
				if (jud(*(a + mid), val) != -1)
					en = mid;
				else
					be = mid + 1;
			}
		if (f_small && jud(*(a + be), val) == 1) be--;
		if (!f_small && jud(*(a + be), val) == -1) be++;
	} else {
		if (f_lb)
			while (be < en) {
				int mid = (be + en + 1) / 2;
				if (jud(*(a + mid), val) != -1)
					be = mid;
				else
					en = mid - 1;
			}
		else
			while (be < en) {
				int mid = (be + en) / 2;
				if (jud(*(a + mid), val) != 1)
					en = mid;
				else
					be = mid + 1;
			}
		if (!f_small && jud(*(a + be), val) == -1) be--;
		if (f_small && jud(*(a + be), val) == 1) be++;
	}
	return be;
}

template<class T> inline T lowb(T num) { return num & (-num); }

inline int bitnum(ui nValue) { return __builtin_popcount(nValue); }
inline int bitnum(int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(ull nValue) { return __builtin_popcountll(nValue); }
inline int bitnum(ll nValue) { return __builtin_popcountll(nValue); }
inline int id1(ui a) { if (a == 0) return 0; return 32 - __builtin_clz(a); }
inline int id1(int a) { if (a == 0) return 0; return 32 - __builtin_clz(a); }
inline int id1(ull a) { if (a == 0) return 0; return 64 - __builtin_clzll(a); }
inline int id1(ll a) { if (a == 0) return 0; return 64 - __builtin_clzll(a); }



long long pow(long long n, long long m, long long mod = 0) {
	if (m < 0) return 0;
	long long ans = 1;
	long long k = n;
	while (m) {
		if (m & 1) {
			ans *= k;
			if (mod) ans %= mod;
		}
		k *= k;
		if (mod) k %= mod;
		m >>= 1;
	}
	return ans;
}


template<class t1, class t2>
inline void add(t1 &a, t2 b, int mod = -1) {
	if (mod == -1) mod = MOD;
	a += b;
	while (a >= mod) a -= mod;
	while (a < 0) a += mod;
}
template<class t>
void output1(t arr) {
	for (const auto& it : arr) cerr << it << ' ';
	cerr << endl;
}
template<class t>
void output2(t arr) {
	for (const auto& it : arr) output1(it);
}




const int mod = 998244353;





using MaxvT = pair<NODE_VAL_TYPE, pii>;
struct SegmentNode{
	int be, en;
	NODE_VAL_TYPE add;
	MaxvT maxv;
};
struct SegmentTree{
	int l;
	SegmentNode tree[id3 * 4];

	inline int GetLeft(int no) {return no << 1;}
	inline int GetRight(int no) {return (no << 1) + 1;}
	inline int GetFa(int no) {return no >> 1;}
	inline SegmentTree(){ l = 0; }

	void Build(int no, int l, int r){
		if(l > r) r = l;
		if(l == r){
			tree[no].be = tree[no].en = l;
			tree[no].add = 0;
			tree[no].maxv = DefaultV();
			return;
		}
		tree[no].be = l; tree[no].en = r;
		int mid = (l + r) / 2;
		Build(GetLeft(no), l, mid);
		Build(GetRight(no), mid + 1, r);
		tree[no].add = 0;
		PushUp(no);
	}
	static inline MaxvT DefaultV() {
		return  mpr(-id3 * 10, mpr(-id3, 0));
	}
	inline void PushUp(int no) {
		tree[no].maxv = max1(tree[GetLeft(no)].maxv, tree[GetRight(no)].maxv);
	}
	inline void PushDown(int no) {
		int le = GetLeft(no), ri = GetRight(no);
		tree[le].add += tree[no].add;
		tree[le].maxv.first += tree[no].add;
		tree[ri].add += tree[no].add;
		tree[ri].maxv.first += tree[no].add;
		tree[no].add = 0;
	}
	void Upd(int l, int r, int no, NODE_VAL_TYPE ranadd){
		if (l > r) return;
		if(l <= tree[no].be && r >= tree[no].en){
			tree[no].add += ranadd;
			tree[no].maxv.first += ranadd;
			return;
		}
		if(tree[no].add && tree[no].be != tree[no].en) PushDown(no);
		int mid = (tree[no].be + tree[no].en) >> 1;
		if(r >= tree[no].be && l <= mid) Upd(l, r, GetLeft(no), ranadd);
		if(r >= mid + 1 && l <= tree[no].en) Upd(l, r, GetRight(no), ranadd);
		PushUp(no);
	}
	void UpdTo(int loc, int no, MaxvT ranadd){
		if(tree[no].be == tree[no].en) {
			tree[no].maxv = ranadd;
			return;
		}
		if(tree[no].add && tree[no].be != tree[no].en) PushDown(no);
		int mid = (tree[no].be + tree[no].en) >> 1;
		if(loc <= mid) UpdTo(loc, GetLeft(no), ranadd);
		else UpdTo(loc, GetRight(no), ranadd);
		PushUp(no);
	}
	MaxvT GetMaxv(int l, int r, int no){
		if(l > r) return DefaultV();
		if(l <= tree[no].be && r >= tree[no].en)
			return tree[no].maxv;
		if(tree[no].add && tree[no].be != tree[no].en) PushDown(no);
		MaxvT ans = DefaultV();
		int mid = (tree[no].be + tree[no].en) >> 1;
		if(r >= tree[no].be && l <= mid) ans = max(ans, GetMaxv(l, r, GetLeft(no)));
		if(r >= mid + 1 && l <= tree[no].en) ans = max(ans, GetMaxv(l, r, GetRight(no)));
		return ans;
	}
} sgt[2];

const int maxn = id3;
int n;
int orig[maxn];
int cate[maxn];
pii arr[2][maxn];
ll cnt[2][maxn];
int larr[2];

int main() {




	ios_base::sync_with_stdio(0);


	freopen("input.txt", "r", stdin);



	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", orig + i);
	for (int i = 0; i < n; i++) scanf("%d", cate + i);
	for (int i = 0; i < n; i++) {
		arr[cate[i]][larr[cate[i]]++].first = orig[i];
	}
	sort(arr[0], arr[0] + larr[0]);
	sort(arr[1], arr[1] + larr[1]);
	for (int cate = 0; cate < 2; cate++) {
		int rl = larr[cate];
		larr[cate] = 0;
		for (int i = 0; i < rl; i++) {
			if (larr[cate] == 0 || arr[cate][larr[cate] - 1].first != arr[cate][i].first) {
				larr[cate]++;
				arr[cate][larr[cate] - 1].first = arr[cate][i].first;
				arr[cate][larr[cate] - 1].second = 0;
			}
			arr[cate][larr[cate] - 1].second++;
		}
	}
	sort(orig, orig + n);
	if (orig[n - 1] == orig[0]) {
		ll ans = 1;
		for (int i = 2; i <= n; i++) ans = ans * i % mod;
		printf("%lld\n", ans);
		return 0;
	}
	if (!larr[1]) {
		puts("0");
		return 0;
	}
	if (larr[0] && arr[0][0].first < arr[1][0].first) {
		puts("0");
		return 0;
	}

	int idx0 = 0, idx1 = 0, sum = 0;
	for (; idx0 < larr[0] && idx1 < larr[1]; ) {
		if (arr[0][idx0] <= arr[1][idx1]) cnt[0][idx0] += sum;
		int add0 = 0, add1 = 0;
		if (arr[0][idx0] <= arr[1][idx1]) add0++, sum += arr[0][idx0].second;
		if (arr[0][idx0] >= arr[1][idx1]) add1++, sum += arr[1][idx1].second;

		idx0 += add0, idx1 += add1;
	}
	for (; idx0 < larr[0]; idx0++) {
		cnt[0][idx0] += sum;
		sum += arr[0][idx0].second;
	}

	idx0 = larr[0] - 1, idx1 = larr[1] - 1, sum = 0;
	for (; idx0 >= 0 && idx1 >= 0; ) {
		if (arr[0][idx0] <= arr[1][idx1]) cnt[1][idx1] += sum;
		int add0 = 0, add1 = 0;
		if (arr[0][idx0] >= arr[1][idx1]) add0--, sum += arr[0][idx0].second;
		if (arr[0][idx0] <= arr[1][idx1]) add1--, sum += arr[1][idx1].second;

		idx0 += add0, idx1 += add1;
	}
	for (; idx1 >= 0; idx1--) {
		cnt[1][idx1] += sum;
		sum += arr[1][idx1].second;
	}


	for (int cate = 0; cate < 2; cate++) {
		for (int i = 0; i < larr[cate]; i++) {
			cerr << "{" << arr[cate][i].first << ", " << arr[cate][i].second << "} ";
		}
		cerr << endl;
		for (int i = 0; i < larr[cate]; i++) {
			cerr << cnt[cate][i] << ", ";
		}
		cerr << endl;
	}


	bool can = 1;
	ll ans = 1;
	int tov = cnt[1][0] + arr[1][0].first;
	if (arr[1][larr[1] - 1].first == tov) {
		for (int i = 0; i < arr[1][larr[1] - 1].second; i++) {
			ans = ans * (n - i) % mod;
		}
		larr[1]--;
	}

	for (int cate = 0; cate < 2; cate++) {
		sgt[cate].Build(1, arr[1][0].first, tov);
		for (int i = 0; i < larr[cate]; i++) {
			int val = arr[cate][i].first + cnt[cate][i];
			if (cate == 0) val = -val;
			if (val > (cate == 0 ? -tov : tov) || arr[cate][i].first < arr[1][0].first) {
				can = 0;
				break;
			}
			sgt[cate].UpdTo(arr[cate][i].first, 1, {val, {arr[cate][i].first, arr[cate][i].second}});
		}
	}



	for (; can;) {
		auto id0 = sgt[0].tree[1].maxv;
		auto id2 = sgt[1].tree[1].maxv;
		if (id0.first < -id3 * 2 && id2.first < -id3 * 2) {
			break;
		}
		if (id0.first != -tov && id2.first != tov) {
			can = 0;
			break;
		}
		if (id0.first > -tov || id2.first > tov) {
			can = 0;
			break;
		}
		pair<int, pii> val = mpr(-1, mpr(-1, -1));
		if (id0.first == -tov) val = max(val, mpr(id0.second.first, mpr(0, id0.second.second)));
		if (id2.first == tov) val = max(val, mpr(id2.second.first, mpr(1, id2.second.second)));
		sgt[0].Upd(val.first + 1, tov, 1, 1);
		sgt[1].Upd(val.first, tov - 1, 1, 1);
		if (!val.second.first) {
			ans *= id0.second.second;
			ans %= mod;
			id0.second.second--;
			if (id0.second.second == 0) id0 = SegmentTree::DefaultV();
			sgt[0].UpdTo(val.first, 1, id0);
		} else {
			ans *= id2.second.second;
			ans %= mod;
			id2.second.second--;
			if (val.first != id2.first) id2.first++;
			if (id2.second.second == 0) id2 = SegmentTree::DefaultV();
			sgt[1].UpdTo(val.first, 1, id2);
		}
	}

	if (!can) puts("0");
	else printf("%lld\n", ans);

	return 0;
}
