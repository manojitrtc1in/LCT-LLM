




























using namespace std;


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
const double eps = 1e-12;
const int step[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

template <class T> inline T abs1(T a) {return a < 0 ? -a : a;}

template <class T> inline T max1(T a, T b) { return a > b ? a : b; }
template <class T> inline T max1(T a, T b, T c) { return max1(max1(a, b), c); }
template <class T> inline T max1(T a, T b, T c, T d) { return max1(max1(a, b, c), d); }
template <class T> inline T max1(T a, T b, T c, T d, T e) { return max1(max1(a, b, c, d), e); }
template <class T> inline T min1(T a, T b) { return a < b ? a : b; }
template <class T> inline T min1(T a, T b, T c) { return min1(min1(a, b), c); }
template <class T> inline T min1(T a, T b, T c, T d) { return min1(min1(a, b, c), d); }
template <class T> inline T min1(T a, T b, T c, T d, T e) { return min1(min1(a, b, c, d), e); }

template <class T> inline T lowb(T num) {return num & (-num); }

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






inline void out(vector <pii> arr) {
	for(int i = 0; i < (int)arr.size(); i++) cerr << arr[i].first << '|' << arr[i].second << ' ';
	cerr << endl;
}























































































































































































vector <pii> init[2][N];
struct node {
	int deep, eno, no;
	node(int a = 0, int b = 0, int c = 0) :
		deep(a), eno(b), no(c) {}
	bool operator < (const node &a) const {
		return deep < a.deep;
	}
};
template <class t> struct segment_node{
	int be, en;
	t minv;
};
struct segment_tree{
	int l;
	segment_node <node> tree[N * 4];

	inline int gleft(int no) {return no << 1;}
	inline int gright(int no) {return (no << 1) + 1;}
	inline int gfa(int no) {return no >> 1;}
	inline segment_tree(){ l = 0; }

	void build(int no, int l, int r, vector <pii> *a){
		if(l > r) r = l;
		if(l == r){
			tree[no].be = tree[no].en = l;
			tree[no].minv = node(10000000, 0, l);
			if(a[l].size()) tree[no].minv = node(a[l][0].first, a[l][0].second, l);
			return;
		}
		tree[no].be = l; tree[no].en = r;
		int mid = (l + r) / 2;
		build(gleft(no), l, mid, a);
		build(gright(no), mid + 1, r, a);
		tree[no].minv = min(tree[gleft(no)].minv, tree[gright(no)].minv);
	}
	void down(int loc, int no, vector <pii> *a){
		if(loc <= tree[no].be && loc >= tree[no].en){
			tree[no].minv = node(100000000, 0, tree[no].be);
			a[loc].erase(a[loc].begin());
			if(a[loc].size()) tree[no].minv = node(a[loc][0].first, a[loc][0].second, tree[no].be);
			return;
		}
		int mid = (tree[no].be + tree[no].en) / 2;
		if(loc <= mid) down(loc, gleft(no), a);
		else down(loc, gright(no), a);
		tree[no].minv = min1(tree[gleft(no)].minv, tree[gright(no)].minv);
	}
	node getmin(int l, int r, int no){
		if(l > r) return 0;
		if(l <= tree[no].be && r >= tree[no].en)
			return tree[no].minv;
		node ans = node(100000000, 0, -1);
		int mid = (tree[no].be + tree[no].en) / 2;
		if(r >= tree[no].be && l <= mid)
			ans = min(getmin(max1(l, tree[no].be), min1(r, mid), gleft(no)), ans);
		if(r >= mid + 1 && l <= tree[no].en)
			ans = min(getmin(max1(l, mid + 1), min1(r, tree[no].en), gright(no)), ans);
		return ans;
	}
} sgt[2];

const int maxn = N;
int fa[2][maxn][22], deep[2][maxn];
int n;
inline void initfa() {
	for(int t = 0; t < 2; t++)
		for(int i = 1; i <= 20; i++) {
			for(int j = 0; j < n; j++) {
				if(fa[t][j][i - 1] == -1) fa[t][j][i] = -1;
				else fa[t][j][i] = fa[t][fa[t][j][i - 1]][i - 1];
			}
		}
}
inline int getfa(int cate, int no, int l) {
	for(int i = 0; l; l >>= 1, i++)
		if(l & 1) no = fa[cate][no][i];
	return no;
}
inline int id0(int cate, int a, int b) {
	if(deep[cate][a] > deep[cate][b]) swap(a, b);
	b = getfa(cate, b, deep[cate][b] - deep[cate][a]);
	if(b == a) return a;
	for(int i = 20; i >= 0; i--)
		if(fa[cate][a][i] != fa[cate][b][i]){
			a = fa[cate][a][i];
			b = fa[cate][b][i];
		}
	return fa[cate][a][0];
}

int range[2][maxn][2];
struct edge {
	int to, nxt;
} e[2][maxn * 2];
int le[2], head[2][maxn];
int arr[2][maxn], larr[2], loc[2][maxn];
int q[2][maxn], lq[2];
bool flag[2][maxn];

inline void addedge(int cate, int a, int b) {
	e[cate][le[cate]].to = b;
	e[cate][le[cate]].nxt = head[cate][a];
	head[cate][a] = le[cate]++;
}
void dfs(int cate, int no) {
	range[cate][no][0] = larr[cate];
	loc[cate][no] = larr[cate];
	arr[cate][larr[cate]++] = no;
	for(int i = head[cate][no]; i != -1; i = e[cate][i].nxt)
		if(e[cate][i].to != fa[cate][no][0]){
			fa[cate][e[cate][i].to][0] = no;
			deep[cate][e[cate][i].to] = deep[cate][no] + 1;
			dfs(cate, e[cate][i].to);
		}
	range[cate][no][1] = larr[cate] - 1;
}
inline int getpoint(int cate, int edgeno) {
	int a = e[cate][edgeno].to,
		b = e[cate][edgeno + 1].to;
	if(fa[cate][a][0] != b) a = b;
	return a;
}
inline void add(int cate, int no, int deep, int eno) {
	init[cate][loc[cate][no]].push_back(mpr(deep, eno));
}

int main(){
    ios_base::sync_with_stdio(0);
	

	freopen("input.txt", "r", stdin);
	

	memset(head, -1, sizeof(head));
	le[0] = le[1] = 0;
	scanf("%d", &n);
	for(int t = 0; t < 2; t++) {
		for(int i = 1; i < n; i++) {
			int no;
			scanf("%d", &no);
			no--;
			addedge(t, i, no);
			addedge(t, no, i);
		}
	}
	larr[0] = larr[1] = 0;
	fa[0][0][0] = fa[1][0][0] = -1;
	dfs(0, 0); dfs(1, 0);
	initfa();

 	for(int now = 0; now < 2; now++) {
		int nxt = 1 - now;
		for(int i = 0; i < le[now]; i += 2) {
			int a = e[now][i].to, b = e[now][i + 1].to;
			int rfa = id0(nxt, a, b);
			add(nxt, a, deep[nxt][rfa], i / 2 + 1);
			add(nxt, b, deep[nxt][rfa], i / 2 + 1);
		}
		for(int i = 0; i < n; i++) sort(init[nxt][i].begin(), init[nxt][i].end());
		sgt[nxt].build(1, 0, n - 1, init[nxt]);
	}
	int edgeno;
	scanf("%d", &edgeno);
	flag[0][edgeno] = 1;
	q[0][lq[0]++] = edgeno;
	for(int now = 0, nxt = 1; lq[now]; swap(now, nxt)) {










		if(now & 1) puts("Red");
		else puts("Blue");
		for(int i = 0; i < lq[now]; i++) printf("%d ", q[now][i]);
		printf("\n");
		vector <pii> arr1;
		for(int i = 0; i < lq[now]; i++) {
			int k = getpoint(now, (q[now][i] - 1) * 2);
			node a;
			while((a = sgt[now].getmin(range[now][k][0], range[now][k][1], 1)).deep <= deep[now][k] - 1) {
				sgt[now].down(a.no, 1, init[now]);
				if(flag[nxt][a.eno] == 0) {
					flag[nxt][a.eno] = 1;
					arr1.push_back(mpr(a.deep, a.eno));
				}
			}
		}
		lq[nxt] = 0;
		for(int i = 0; i < (int)arr1.size(); i++)  q[nxt][lq[nxt]++] = arr1[i].second;
		sort(q[nxt], q[nxt] + lq[nxt]);
		lq[nxt] = unique(q[nxt], q[nxt] + lq[nxt]) - q[nxt];
	}

    return 0;
}









