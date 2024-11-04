












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
inline int id2(ui a) { if (a == 0) return 0; return 32 - __builtin_clz(a); }
inline int id2(int a) { if (a == 0) return 0; return 32 - __builtin_clz(a); }
inline int id2(ull a) { if (a == 0) return 0; return 64 - __builtin_clzll(a); }
inline int id2(ll a) { if (a == 0) return 0; return 64 - __builtin_clzll(a); }



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




const int maxn = 300100;
int n, m;

int id0[maxn];
int id3(int no) {
	if (id0[no] == -1) return no;
	else return id0[no] = id3(id0[no]);
}
int Uni(int a, int b) {
	a = id3(a);
	b = id3(b);
	if (a != b) {
		id0[b] = a;
		return true;
	}
	return false;
}

vi tree_e[maxn];
pair<int, pii> e[maxn];
int cant[maxn];
int arr[maxn], larr, loc[maxn];
pii range[maxn];


int fa[maxn][22], deep[maxn];

inline void initfa() {
	for(int i = 1; i <= 20; i++) {
		for(int j = 0; j < n; j++) {
			if(fa[j][i - 1] == -1) fa[j][i] = -1;
			else fa[j][i] = fa[fa[j][i - 1]][i - 1];
		}
	}
}
inline int getfa(int no, int l) {
	for(int i = 0; l; l >>= 1, i++)
		if(l & 1) no = fa[no][i];
	return no;
}
inline int id1(int a, int b) {
	if(deep[a] > deep[b]) swap(a, b);
	b = getfa(b, deep[b] - deep[a]);
	if(b == a) return a;
	for(int i = 20; i >= 0; i--)
		if(fa[a][i] != fa[b][i]){
			a = fa[a][i];
			b = fa[b][i];
		}
	return fa[a][0];
}
inline int getl(int a, int b) {
	int faa = id1(a, b);
	return deep[a] + deep[b] - deep[faa] * 2;
}


void Dfs(int no, int rdeep) {
	range[no].first = larr;
	arr[larr++] = no;
	deep[no] = rdeep;
	for (const auto& it : tree_e[no]) if (it != fa[no][0]) {
		fa[it][0] = no;
		Dfs(it, rdeep + 1);
	}
	range[no].second = larr - 1;
}





struct SegmentNode{
	int be, en;
	NODE_VAL_TYPE maxv, add, sum;
};
struct SegmentTree{
	int l;
	SegmentNode tree[SEGMENT_TREE_MAXN * 4];

	inline int GetLeft(int no) {return no << 1;}
	inline int GetRight(int no) {return (no << 1) + 1;}
	inline int GetFa(int no) {return no >> 1;}
	inline SegmentTree(){ l = 0; }

	void Build(int no, int l, int r, NODE_VAL_TYPE orig = 0, NODE_VAL_TYPE *a = NULL){
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
		Build(GetLeft(no), l, mid, orig, a);
		Build(GetRight(no), mid + 1, r, orig, a);
		tree[no].add = 0;
		PushUp(no);
	}
	inline void PushUp(int no) {
		tree[no].sum = tree[GetLeft(no)].sum + tree[GetRight(no)].sum;
		tree[no].maxv = max1(tree[GetLeft(no)].maxv, tree[GetRight(no)].maxv);
	}
	inline void PushDown(int no) {
		int le = GetLeft(no), ri = GetRight(no);
		tree[le].add += tree[no].add;
		tree[le].sum += tree[no].add * (tree[le].en - tree[le].be + 1);
		tree[le].maxv += tree[no].add;
		tree[ri].add += tree[no].add;
		tree[ri].sum += tree[no].add * (tree[ri].en - tree[ri].be + 1);
		tree[ri].maxv += tree[no].add;
		tree[no].add = 0;
	}
	void Upd(int l, int r, int no, NODE_VAL_TYPE ranadd){
		if(l <= tree[no].be && r >= tree[no].en){
			tree[no].add += ranadd;
			tree[no].sum += ranadd * (tree[no].en - tree[no].be + 1);
			tree[no].maxv += ranadd;
			return;
		}
		if(tree[no].add && tree[no].be != tree[no].en) PushDown(no);
		int mid = (tree[no].be + tree[no].en) >> 1;
		if(r >= tree[no].be && l <= mid) Upd(l, r, GetLeft(no), ranadd);
		if(r >= mid + 1 && l <= tree[no].en) Upd(l, r, GetRight(no), ranadd);
		PushUp(no);
	}
	NODE_VAL_TYPE GetSum(int l, int r, int no){
		if(l > r) return 0;
		if(l <= tree[no].be && r >= tree[no].en)
			return tree[no].sum;
		if(tree[no].add && tree[no].be != tree[no].en) PushDown(no);
		NODE_VAL_TYPE ans = 0;
		int mid = (tree[no].be + tree[no].en) >> 1;
		if(r >= tree[no].be && l <= mid) ans += GetSum(l, r, GetLeft(no));
		if(r >= mid + 1 && l <= tree[no].en) ans += GetSum(l, r, GetRight(no));
		return ans;
	}
} sgt;

int main() {




	ios_base::sync_with_stdio(0);


	freopen("input.txt", "r", stdin);



	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		e[i] = mpr(i, mpr(a, b));
	}
	memset(id0, -1, sizeof(id0));
	for (int i = 0; i < m; i++) {
		int a = e[i].second.first, b = e[i].second.second;
		if (id3(a) != id3(b)) {
			Uni(a, b);
			tree_e[a].push_back(b);
			tree_e[b].push_back(a);
		} else {
			cant[i] = 1;
		}
	}
	memset(fa, -1, sizeof(fa));
	Dfs(0, 0);
	initfa();























	sgt.Build(1, 0, n - 1);
	for (int i = 0; i < m; i++) if (cant[i]) {
		int a = e[i].second.first, b = e[i].second.second;
		if (deep[a] < deep[b]) swap(a, b);
		int rfa = id1(a, b);
		if (rfa == b) {
			b = getfa(a, deep[a] - deep[b] - 1);
	 		sgt.Upd(range[b].first, range[b].second, 1, 1);
	 		sgt.Upd(range[a].first, range[a].second, 1, -1);
		} else {
	 		sgt.Upd(0, n - 1, 1, 1);
	 		sgt.Upd(range[a].first, range[a].second, 1, -1);
	 		sgt.Upd(range[b].first, range[b].second, 1, -1);
		}
	}
	for (int i = 0; i < n; i++) {
		if (sgt.GetSum(range[i].first, range[i].first, 1)) printf("0");
		else printf("1");
	}
	puts("");

	return 0;

}


