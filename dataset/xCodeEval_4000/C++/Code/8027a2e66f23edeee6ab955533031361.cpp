



#define USETR1
#define CPPELEVEN
#define GPP




#include <bits/stdc++.h>

using namespace std;

#ifndef CPPELEVEN
#ifdef USETR1
#include <tr1/unordered_map>
#include <tr1/unordered_set>
using namespace tr1;
#endif
#else
#include <unordered_map>
#include <unordered_set>
#endif

#ifdef USEPB_DS
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


typedef __gnu_pbds::priority_queue<int, greater<int>, pairing_heap_tag> pq_type;


typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> tree_type;
#endif

#define mpr make_pair
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

#ifndef CPPELEVEN
template <class T> inline T max1(T a, T b) { return b < a ? a : b; }
template <class T> inline T max1(T a, T b, T c) { return max1(max1(a, b), c); }
template <class T> inline T max1(T a, T b, T c, T d) { return max1(max1(a, b, c), d); }
template <class T> inline T max1(T a, T b, T c, T d, T e) { return max1(max1(a, b, c, d), e); }
template <class T> inline T min1(T a, T b) { return a < b ? a : b; }
template <class T> inline T min1(T a, T b, T c) { return min1(min1(a, b), c); }
template <class T> inline T min1(T a, T b, T c, T d) { return min1(min1(a, b, c), d); }
template <class T> inline T min1(T a, T b, T c, T d, T e) { return min1(min1(a, b, c, d), e); }
#else
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
#endif

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
#ifdef GPP
inline int bitnum(ui nValue) { return __builtin_popcount(nValue); }
inline int bitnum(int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(ull nValue) { return __builtin_popcountll(nValue); }
inline int bitnum(ll nValue) { return __builtin_popcountll(nValue); }
inline int bitmaxl(ui a) { if (a == 0) return 0; return 32 - __builtin_clz(a); }
inline int bitmaxl(int a) { if (a == 0) return 0; return 32 - __builtin_clz(a); }
inline int bitmaxl(ull a) { if (a == 0) return 0; return 64 - __builtin_clzll(a); }
inline int bitmaxl(ll a) { if (a == 0) return 0; return 64 - __builtin_clzll(a); }
#else
#endif

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

#define  MOD 1000000007
template<class t1, class t2>
inline void add(t1 &a, t2 b, int mod = -1) {
	if (mod == -1) mod = MOD;
	a += b;
	while (a >= mod) a -= mod;
	while (a < 0) a += mod;
}
template<class t>
void output1(t arr) {
	for (int i = 0; i < (int) arr.size(); i++) cerr << arr[i] << ' ';
	cerr << endl;
}
template<class t>
void output2(t arr) {
	for (int i = 0; i < (int) arr.size(); i++) output1(arr[i]);
}




#ifndef SEGMENT_TREE_MAXN
#define SEGMENT_TREE_MAXN 200100
#define NODE_VAL_TYPE ll
#endif
struct SegmentNode{
	int be, en;
	NODE_VAL_TYPE add, sum;
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
			if(a == NULL) tree[no].sum = orig;
			else tree[no].sum = a[l];
			tree[no].add = 0;
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
	}
	inline void PushDown(int no) {
		int le = GetLeft(no), ri = GetRight(no);
		tree[le].add += tree[no].add;
		tree[le].sum += tree[no].add * (tree[le].en - tree[le].be + 1);
		tree[ri].add += tree[no].add;
		tree[ri].sum += tree[no].add * (tree[ri].en - tree[ri].be + 1);
		tree[no].add = 0;
	}
	void Upd(int l, int r, int no, NODE_VAL_TYPE ranadd){
		if (l > r) return;
		if(l <= tree[no].be && r >= tree[no].en){
			tree[no].add += ranadd;
			tree[no].sum += ranadd * (tree[no].en - tree[no].be + 1);
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
} sgt0, sgt1;

const int maxn = SEGMENT_TREE_MAXN;
int n, nq;
int arr[maxn], loc[maxn];
vector<pii> q[maxn * 5];
pii range[maxn];
vector<pii> p[maxn];
set<int> have;
vector<pii> event[maxn];
ll ans[maxn * 5];

int main() {




	ios_base::sync_with_stdio(0);
#ifdef DEBUG 

	freopen("input.txt", "r", stdin);
#endif 


	scanf("%d%d", &n, &nq);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		arr[i]--;
		loc[arr[i]] = i;
	}
	for (int i = 0; i < nq; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		q[a].push_back(mpr(b, i));
	}

	have.insert(-1);
	have.insert(n);
	for (int i = n - 1; i >= 0; i--) {
		auto it = have.upper_bound(loc[i]);
		range[i].second = *it - 1;
		it--;
		range[i].first = *it + 1;
		have.insert(loc[i]);
	}
	for (ll i = 1; i <= n; i++) for (ll j = i + 1; j * i <= n; j++) {
		if (loc[i - 1] >= range[i * j - 1].first &&
				loc[i - 1] <= range[i * j - 1].second &&
				loc[j - 1] >= range[i * j - 1].first &&
				loc[j - 1] <= range[i * j - 1].second) {
			int a = loc[i - 1], b = loc[j - 1];
			if (a > b) swap(a, b);
			if (a > loc[i * j - 1]) a = loc[i * j - 1];
			if (b < loc[i * j - 1]) b = loc[i * j - 1];
			p[i * j - 1].push_back(mpr(a, b));
		}
	}
	for (int i = 0; i < n; i++) {
		sort(p[i].begin(), p[i].end());
		for (int j = p[i].size() - 1, smallest = n; j >= 0; j--) {
			smallest = min(smallest, p[i][j].second);
			p[i][j].second = smallest;
		}
		int sz = min(1, (int)p[i].size());
		for (int j = 1; j < (int)p[i].size(); j++) {
			if (p[i][j].second == p[i][j - 1].second) p[i][sz - 1] = p[i][j];
			else if (p[i][j].first == p[i][j - 1].first) continue;
			else p[i][sz++] = p[i][j];
		}
		p[i].resize(sz);
		for (int j = 0; j < sz; j++) {
			event[p[i][j].first].push_back(mpr(i, j));
		}
		if (range[i].first) {
			event[range[i].first - 1].push_back(mpr(i, -1));
		}
		p[i].push_back(mpr(range[i].second + 1, range[i].second + 1));
	}

	sgt0.Build(1, 0, n - 1);
	sgt1.Build(1, 0, n - 1);

	for (int i = n - 1; i >= 0; i--) {
		for (const auto& it : event[i]) {
			auto [no, idx] = it;
			if (idx == -1) {
				for (int ridx = 0; ridx < (int)p[no].size() - 1; ridx++) {
					int from = p[no][ridx].second, to = p[no][ridx + 1].second - 1;
					sgt0.Upd(from, to, 1, -(i));
					sgt1.Upd(from, to, 1, -1);
				}
			} else {
				int from = p[no][idx].second, to = p[no][idx + 1].second - 1;
				sgt0.Upd(from, to, 1, p[no][idx].first);
				sgt1.Upd(from, to, 1, 1);
			}
		}
		for (const auto& [to, qno] : q[i]) {
			ans[qno] = sgt0.GetSum(i, to, 1) - sgt1.GetSum(i, to, 1) * (i - 1);
		}
	}

	for (int i = 0; i < nq; i++) printf("%lld\n", ans[i]);

	return 0;
}
