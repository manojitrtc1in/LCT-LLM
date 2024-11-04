









































using namespace std;





using namespace tr1;










using namespace __gnu_pbds;
using namespace __gnu_cxx;


typedef __gnu_pbds::priority_queue<int, greater<int>, pairing_heap_tag> pq_type;






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
	else if(abs1(a - b) / max(abs1(a), abs1(b)) < eps) return 0;
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
inline int id0(ui a) { if(a == 0) return 0; return 32 - __builtin_clz(a); }
inline int id0(int a) { if(a == 0) return 0; return 32 - __builtin_clz(a); }
inline int id0(ull a) { int temp = a >> 32; if(temp) return 32 - __builtin_clz(temp) + 32; return id0(int(a)); }
inline int id0(ll a) { int temp = a >> 32; if(temp) return 32 - __builtin_clz(temp) + 32; return id0(int(a)); }



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





const int maxn = 1001000;
int n;
pii orig[maxn];
vi idx[maxn];
vector<vi*> rall[maxn * 2];
vector<vi*>* all = rall + maxn;






struct SegmentNode{
	int be, en;
	NODE_VAL_TYPE sum, add, maxv, minv;
};
struct SegmentTree{
	int l;
	SegmentNode tree[SEGMENT_TREE_MAXN * 3];

	inline int GetLeft(int no) {return no << 1;}
	inline int GetRight(int no) {return (no << 1) + 1;}
	inline int GetFa(int no) {return no >> 1;}
	inline SegmentTree(){ l = 0; }

	void Build(int no, int l, int r){
		if(l > r) r = l;
		if(l == r){
			tree[no].be = tree[no].en = l;
			tree[no].add = 0;
			tree[no].maxv = -maxn * 2;
			tree[no].minv = maxn * 2;
			tree[no].sum = 0;
			all[l].clear();
			return;
		}
		tree[no].be = l; tree[no].en = r;
		int mid = l + (r - l) / 2;
		Build(GetLeft(no), l, mid);
		Build(GetRight(no), mid + 1, r);
		tree[no].add = 0;
		PushUp(no);
	}
	inline void PushUp(int no) {
		tree[no].maxv = max1(tree[GetLeft(no)].maxv, tree[GetRight(no)].maxv);
		tree[no].minv = min1(tree[GetLeft(no)].minv, tree[GetRight(no)].minv);
		tree[no].sum = tree[GetLeft(no)].sum + tree[GetRight(no)].sum;
	}
	inline void PushDown(int no) {
		int le = GetLeft(no), ri = GetRight(no);
		tree[le].add += tree[no].add;
		tree[le].minv += tree[no].add;
		tree[le].maxv += tree[no].add;
		tree[ri].add += tree[no].add;
		tree[ri].minv += tree[no].add;
		tree[ri].maxv += tree[no].add;
		tree[no].add = 0;
	}
	void Insert(int loc, int no, vi* new_node, NODE_VAL_TYPE val) {
		if(loc <= tree[no].be && loc >= tree[no].en){
			tree[no].sum++;
			tree[no].maxv = max(tree[no].maxv, val);
			tree[no].minv = min(tree[no].minv, val);
			all[loc].push_back(new_node);
			return;
		}
		if(tree[no].add && tree[no].be != tree[no].en) PushDown(no);
		int mid = tree[no].be + ((tree[no].en - tree[no].be) >> 1);
		if(loc <= mid) Insert(loc, GetLeft(no), new_node, val);
		else Insert(loc, GetRight(no), new_node, val);
		PushUp(no);
	}
	pair<int, vi*> Del(int cnt, int no, int is_last) {
		if(tree[no].be == tree[no].en){
			tree[no].sum--;
			vi* ans = all[tree[no].be].back();
			all[tree[no].be].pop_back();
			if (tree[no].sum == 0) {
				tree[no].maxv = -maxn * 2;
				tree[no].minv = maxn * 2;
			} else {
				if (is_last) tree[no].minv++;
				else tree[no].maxv--;
			}
			return mpr(tree[no].be, ans);
		}
		if(tree[no].add && tree[no].be != tree[no].en) PushDown(no);
		pair<int, vi*> ans;
		if(cnt <= tree[GetLeft(no)].sum) ans = Del(cnt, GetLeft(no), is_last);
		else ans = Del(cnt - tree[GetLeft(no)].sum, GetRight(no), is_last);
		PushUp(no);
		return ans;
	}
	void Upd(int l, int r, int no, NODE_VAL_TYPE ranadd){
		if(l <= tree[no].be && r >= tree[no].en){
			tree[no].add += ranadd;
			tree[no].maxv += ranadd;
			tree[no].minv += ranadd;
			return;
		}
		if(tree[no].add && tree[no].be != tree[no].en) PushDown(no);
		int mid = tree[no].be + ((tree[no].en - tree[no].be) >> 1);
		if(r >= tree[no].be && l <= mid) Upd(l, r, GetLeft(no), ranadd);
		if(r >= mid + 1 && l <= tree[no].en) Upd(l, r, GetRight(no), ranadd);
		PushUp(no);
	}
	NODE_VAL_TYPE GetSum(int l, int r, int no){
		if(l > r) return 0;
		if(l <= tree[no].be && r >= tree[no].en)
			return tree[no].sum;
		NODE_VAL_TYPE ans = 0;
		int mid = tree[no].be + ((tree[no].en - tree[no].be) >> 1);
		if(r >= tree[no].be && l <= mid) ans += GetSum(l, r, GetLeft(no));
		if(r >= mid + 1 && l <= tree[no].en) ans += GetSum(l, r, GetRight(no));
		return ans;
	}
	NODE_VAL_TYPE GetLast0(int no){
		if(tree[no].be == tree[no].en)
			return tree[no].be;
		if (tree[no].minv != 0) return -n;
		if(tree[no].add && tree[no].be != tree[no].en) PushDown(no);
		if(tree[GetRight(no)].minv == 0) return GetLast0(GetRight(no));
		return GetLast0(GetLeft(no));
	}
	NODE_VAL_TYPE GetFirstN(int n, int no){
		if(tree[no].be == tree[no].en)
			return tree[no].be;
		if (tree[no].maxv < n) return n;
		if(tree[no].add && tree[no].be != tree[no].en) PushDown(no);
		if(tree[GetLeft(no)].maxv >= n) return GetFirstN(n, GetLeft(no));
		return GetFirstN(n, GetRight(no));
	}
} sgt;

vi* Merge(vi* a, vi* b) {
	if (a->size() > b->size()) {
		return Merge(b, a);
	}
	for (auto it : *a) {
		b->push_back(it);
	}
	return b;
}

int main() {




	ios_base::sync_with_stdio(0);
	

	freopen("input.txt", "r", stdin);
	


	int ncase;
	scanf("%d", &ncase);
	for (int i1 = 0; i1 < ncase; i1++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &orig[i].first);
			orig[i].second = i + 1;
		}
		for (int i = 0; i < n; i++) if (orig[i].first == 0) {
			printf("1\n%d\n", i + 1);
			goto st_label;
		}
 		sort(orig, orig + n);
		sgt.Build(1, orig[0].first, orig[n - 1].first);
		for (int i = 0; i < n; i++) {


			idx[i].push_back(orig[i].second);
			sgt.Insert(orig[i].first, 1, idx + i, orig[i].first + (n - i - 1));
		}
		for (int i = 0; i < n; i++) {
			auto p2 = sgt.GetFirstN(n - i - 1, 1);
			auto p1 = sgt.GetLast0(1);
			auto be = sgt.Del(1, 1, 0);
			auto en = sgt.Del(n - i - 1, 1, 1);
			if (be.first + en.first == 0) {
				auto rans = Merge(be.second, en.second);
				printf("%d\n", rans->size());
				for (auto it : *rans) {
					printf("%d ", it);
				}
				puts("");
				break;
			}
			if (p1 == be.first && sgt.tree[1].minv != 0) {
				int mid = be.first + en.first;
				int bef_sum = sgt.GetSum(be.first, mid, 1);
				sgt.Insert(mid, 1, Merge(be.second, en.second), mid - bef_sum + n - i - 2);
				sgt.Upd(mid + 1, en.first, 1, -1);
			} else if (p2 == en.first && sgt.tree[1].maxv != n - i - 1) {
				int mid = be.first + en.first;
				int bef_sum = sgt.GetSum(be.first, mid, 1);
				sgt.Insert(mid, 1, Merge(be.second, en.second), mid - bef_sum + n - i - 2);
				sgt.Upd(mid + 1, en.first, 1, -1);
			} else {
				if (en.first > p1 && en.first < p2) {
					sgt.Insert(en.first, 1, en.second, en.first);
				} else if (be.first > p1 && be.first < p2) {
					sgt.Insert(be.first, 1, be.second, be.first + n - i - 1);
					sgt.Upd(be.first, en.first, 1, -1);
				} else {
					int mid = be.first + en.first;
					int bef_sum = sgt.GetSum(be.first, mid, 1);
					sgt.Insert(mid, 1, Merge(be.second, en.second), mid - bef_sum + n - i - 2);
					sgt.Upd(mid + 1, en.first, 1, -1);
				}
			}
  		}
		for (int i = orig[0].first; i <= orig[n - 1].first; i++) {
			all[i].clear();
		}
		for (int i = 0; i < n; i++) {
			idx[i].clear();
		}
		st_label:
		continue;
 	}

	return 0;
}
