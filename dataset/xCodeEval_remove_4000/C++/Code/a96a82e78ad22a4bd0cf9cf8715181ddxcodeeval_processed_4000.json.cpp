




































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




const int maxn = 300100;

pii orig[maxn];
int wh[maxn];
int trans[maxn], lt;














int n, m;
int mn, mx;


bool flag = 1;
struct edge {
	int to, nxt;
} e[maxn * 2];
int head[maxn], le;
int cate[maxn], used[maxn];
pii range[maxn];
int lr;
vi loc[maxn];

























































































inline void addedge(int a, int b) {
	e[le].to = b;
	e[le].nxt = head[a];
	head[a] = le++;
}

void dfs(int no, pii &a, pii &b, int rcate) {
	if(cate[no] != -1) {
		if(cate[no] != rcate) {
			flag = 0;
			a = mpr(lt + 1, -1);
			b = mpr(lt + 1, -1);
		}
		return;
	}
	cate[no] = rcate;
	a.first = max(a.first, orig[no].first);
	a.second = min(a.second, orig[no].second);
	for(int j = head[no]; j != -1; j = e[j].nxt)
		dfs(e[j].to, b, a, rcate ^ 1);
	orig[no].first = max(orig[no].first, a.first);
	orig[no].second = max(orig[no].second, a.second);
}


int main() {




	ios_base::sync_with_stdio(0);
	

	freopen("input.txt", "r", stdin);
	int id0 = 256 << 20; 

	char *__p__ = (char*)malloc(id0) + id0;
	__asm__("movl %0, %%esp\n" :: "r"(__p__));
	



	scanf("%d%d", &mn, &mx);
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &orig[i].first, &orig[i].second);
		trans[i * 2] = orig[i].first;
		trans[i * 2 + 1] = orig[i].second;
	}
	trans[2 * n] = 0;
	trans[2 * n + 1] = MOD;
	sort(trans, trans + 2 * n + 2);
	lt = unique(trans, trans + 2 * n + 2) - trans;
	int minr = mx / 2, maxl = mn / 2;
	for(int i = 0; i < n; i++) {
		orig[i].first = find(orig[i].first, trans, lt);
		orig[i].second = find(orig[i].second, trans, lt);
		minr = min(minr, trans[orig[i].second]);
		maxl = max(maxl, trans[orig[i].first]);
	}
	memset(head, -1, sizeof(head));
	for(int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		addedge(a, b);
		addedge(b, a);
	}
	memset(cate, -1, sizeof(cate));
	lr = 0;
	for(int i = 0; i < n; i++) if(cate[i] == -1) {
		range[lr] = range[lr + 1] = mpr(0, lt - 1);
		dfs(i, range[lr], range[lr + 1], lr);
		if(!flag) break;
		loc[range[lr].first].push_back(lr);
		loc[range[lr + 1].first].push_back(lr + 1);
		lr += 2;
	}

	if(!flag) {
		puts("IMPOSSIBLE");
		return 0;
	}

	multiset <int> be, en;
	int cnt = 0;
	for(int i = 0; i < lt && trans[i] <= minr; i++) {
		for(int j = 0; j < (int)loc[i].size(); j++) {
			used[loc[i][j]] = 1;
			if(used[loc[i][j] ^ 1] == 0) {
				cnt++;
				be.insert(trans[range[loc[i][j] ^ 1].first]);
				en.insert(trans[range[loc[i][j] ^ 1].second]);
			} else {
				en.erase(en.find(trans[range[loc[i][j]].second]));
				en.insert(max(trans[range[loc[i][j] ^ 1].second], trans[range[loc[i][j]].second]));
			}
		}
		if(cnt == lr / 2) {
			pii rr = mpr(*be.rbegin(), *en.begin());
			rr.first = max1(rr.first, mn - trans[i], trans[i]);
			rr.second = min(rr.second, mx - trans[i]);
			if(rr.first <= rr.second) {
				puts("POSSIBLE");
				printf("%d %d\n", trans[i], rr.first);

				for(int j = 0; j < lr; j += 2) {
					used[j] = 1;
					used[j ^ 1] = 2;
					if(trans[range[j].first] > trans[i] ||
					   trans[range[j].second] < trans[i] ||
					   trans[range[j ^ 1].first] > rr.first ||
					   trans[range[j ^ 1].second] < rr.first) {
						used[j] = 2;
						used[j ^ 1] = 1;
					}
				}
				for(int i = 0; i < n; i++) {
					if(used[cate[i]] == 1) printf("1");
					else printf("2");
				}
				puts("");
				return 0;
			}
		}
	}

	be.clear(), en.clear(), cnt = 0;
	memset(used, 0, sizeof(used));
	for(int i = lt - 1; i >= 0 && trans[i] >= maxl; i--) {
		for(int j = 0; j < (int)loc[i].size(); j++) {
			used[loc[i][j]] = 1;
			if(used[loc[i][j] ^ 1] == 0) {
				cnt++;
				be.insert(trans[range[loc[i][j] ^ 1].first]);
				en.insert(trans[range[loc[i][j] ^ 1].second]);
			} else {
				be.erase(be.find(trans[range[loc[i][j]].first]));
				be.insert(min(trans[range[loc[i][j] ^ 1].first], trans[range[loc[i][j]].first]));
			}
		}
		if(cnt == lr / 2) {
			pii rr = mpr(*be.rbegin(), *en.begin());
			rr.first = max1(rr.first, mn - trans[i]);
			rr.second = min1(rr.second, mx - trans[i], trans[i]);
			if(rr.first <= rr.second) {
				puts("POSSIBLE");
				printf("%d %d\n", trans[i], rr.first);

				for(int j = 0; j < lr; j += 2) {
					used[j] = 1;
					used[j ^ 1] = 2;
					if(trans[range[j].first] > trans[i] ||
					   trans[range[j].second] < trans[i] ||
					   trans[range[j ^ 1].first] > rr.first ||
					   trans[range[j ^ 1].second] < rr.first) {
						used[j] = 2;
						used[j ^ 1] = 1;
					}
				}
				for(int i = 0; i < n; i++) {
					if(used[cate[i]] == 1) printf("1");
					else printf("2");
				}
				puts("");
				return 0;
			}
		}
	}

	puts("IMPOSSIBLE");






















































































    return 0;
}
