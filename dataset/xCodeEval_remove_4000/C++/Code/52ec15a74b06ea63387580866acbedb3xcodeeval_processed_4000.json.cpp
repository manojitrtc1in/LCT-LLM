






























using namespace std;
using namespace tr1;


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










template <class t> struct segment_node{
	int be, en;
	t maxv, add;
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
			return;
		}
		tree[no].be = l; tree[no].en = r;
		int mid = (l + r) / 2;
		build(gleft(no), l, mid, orig, a);
		build(gright(no), mid + 1, r, orig, a);
		tree[no].add = 0;
		tree[no].maxv = max1(tree[gleft(no)].maxv, tree[gright(no)].maxv);
	}
	inline void relax(int no) {
		tree[gleft(no)].add = max(tree[gleft(no)].add, tree[no].add);
		tree[gleft(no)].maxv = max(tree[gleft(no)].maxv, tree[no].add);
		tree[gright(no)].add = max(tree[gright(no)].add, tree[no].add);
		tree[gright(no)].maxv = max(tree[gright(no)].maxv, tree[no].add);
		tree[no].add = 0;
	}
	void down(int l, int r, int no, t ranadd){
		if(l <= tree[no].be && r >= tree[no].en){
			tree[no].add = max(tree[no].add, ranadd);
			tree[no].maxv = max(tree[no].maxv, ranadd);
			return;
		}
		if(tree[no].add && tree[no].be != tree[no].en) relax(no);
		int mid = (tree[no].be + tree[no].en) / 2;
		if(r >= tree[no].be && l <= mid) down(l, r, gleft(no), ranadd);
		if(r >= mid + 1 && l <= tree[no].en) down(l, r, gright(no), ranadd);
		tree[no].maxv = max1(tree[gleft(no)].maxv, tree[gright(no)].maxv);
	}
	t getv(int loc, int no){
		if(loc <= tree[no].be && loc >= tree[no].en)
			return tree[no].maxv;
		if(tree[no].add && tree[no].be != tree[no].en) relax(no);
		t ans = 0;
		int mid = (tree[no].be + tree[no].en) / 2;
		if(loc <= mid) ans = getv(loc, gleft(no));
		else ans = getv(loc, gright(no));
		return ans;
	}
};
segment_tree <int> sgt;

const int maxn = 2010;
int mp[maxn][maxn];
int last[maxn], ans[maxn];
int minl[maxn][maxn], maxl[maxn][maxn];
pii loc[maxn];
int have[maxn], lhave, in[maxn];
pii infere[maxn][maxn];
int lin[maxn], rin[maxn];
int maxbe[maxn], maxbeno[maxn];
int ans0[maxn];
int rst[maxn];
bool flag[maxn];
int n, m, k;

inline int getbe(int x, int y, int xx, int yy, int rx) {
	int a1 = y + rx - xx, a2 = yy;
	return min(m, max(a1, a2));
}
inline int getl(int x0, int y0, int x1, int y1) {
	return min1(max(abs(x0 - x1), abs(y1 - y0)), y1 + 1, x1 + 1);
}

int main(){
	ios_base::sync_with_stdio(0);
	

	freopen("input.txt", "r", stdin);








	

	memset(mp, 0x3f, sizeof(mp));
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < n; i++) {
		char str[maxn];
		scanf("%s", str);
		for(int j = 0; j < m; j++)  if(str[j] == 'X')
			mp[i][j] = 0;
	}
	for(int i = 0; i < k; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		loc[i].first = a;
		loc[i].second = b;
		mp[a][b] = i + 1;
	}
	for(int i = 0; i < n; i++) {
		minl[i][m] = m;
		for(int j = m - 1; j >= 0; j--) {
			minl[i][j] = minl[i][j + 1];
			if(mp[i][j] == 0) minl[i][j] = j;
		}
	}
	for(int i = 0; i < n; i++) {
		maxl[i][0] = -1;
		if(mp[i][0] == 0) maxl[i][0] = 0;
		for(int j = 1; j < m; j++) {
			maxl[i][j] = maxl[i][j - 1];
			if(mp[i][j] == 0) maxl[i][j] = j;
		}
	}
	lhave = 0;
	memset(last, -1, sizeof(last));
	memset(rst, -1, sizeof(rst));
	sgt.build(1, 0, k + 1);
	for(int i = 0; i <= k; i++) maxbe[i] = m;
	for(int i = 0; i < n; i++) {
		

		memset(flag, 0, sizeof(flag));
		for(int j = 0; j < m; j++) if(mp[i][j] > 0 && mp[i][j] <= k) {
			int no = mp[i][j] - 1;
			for(int ri = 0; ri < i; ri++)
				infere[no][ri] = mpr(minl[ri][j + 1], ri);
			for(int t = 0; t < lhave; t++) {
				if(loc[have[t]].second > loc[no].second) {
					if(have[t] < no) {
						if(infere[no][loc[have[t]].first].first > loc[have[t]].second)
							infere[no][loc[have[t]].first].first = loc[have[t]].second;
					} else rst[have[t]] = max(rst[have[t]], j);
				} else if(maxbe[have[t]] > loc[no].second && have[t] > no){
					maxbe[have[t]] = loc[no].second;
					maxbeno[have[t]] = no;
				}
			}
			lin[no] = 0, rin[no] = 0;
			for(int ri = 0; ri < i; ri++) {
				while(rin[no] != lin[no] && infere[no][rin[no] - 1].first >= infere[no][ri].first)
					rin[no]--;
				infere[no][rin[no]++] = infere[no][ri];
			}
			have[lhave++] = no;
		}
		

		int q[maxn], lq = 0, rq = 0;
		for(int j = 0; j < m; j++) {
			if(mp[i][j] == 0) last[j] = i;
			while(lq != rq && last[q[rq - 1]] < last[j]) rq--;
			q[rq++] = j;
			while(lq < rq - 1 && getbe(last[q[lq]], q[lq], last[q[lq + 1]], q[lq + 1], i) <= j)
				lq++;
			ans0[j] = getl(last[q[lq]], q[lq] , i, j);
		}
		

		for(int j = 0; j < lhave; j++) {
			int no = have[j];
			if(maxbe[no] > minl[i][loc[no].second]) {
				maxbe[no] = minl[i][loc[no].second];
				maxbeno[no] = 0;
			}
		}
		

		for(int j = 0; j < lhave; j++) {
			int no = have[j];
			rst[no] = max(rst[no], maxl[i][loc[no].second]);
		}
		

		set <int> s; vi start[maxn], end[maxn];
		int rans[maxn];
		for(int j = 0; j <= k; j++) rans[j] = 0;
		for(int j = 0; j < lhave; j++) {
			int no = have[j];
			int rbe = getbe(i, rst[no], loc[no].first, loc[no].second, i);
			int ren = m;
			if(lin[no] != rin[no]) {
				ren = getbe(loc[no].first, loc[no].second, infere[no][lin[no]].second, infere[no][lin[no]].first, i);
				for(; lin[no] < rin[no] - 1; lin[no]++) {
					int ren1 = getbe(loc[no].first, loc[no].second, infere[no][lin[no] + 1].second, infere[no][lin[no] + 1].first, i);
					if(ren1 > ren) break;
					ren = ren1;
				}
			}
			if(maxbe[no] < ren) {
				ren = min(ren, maxbe[no]);
				flag[no] = 1;
			}
			if(rbe < ren) {
				start[rbe].push_back(no);
				end[ren].push_back(no);
			}
		}
		for(int j = 0; j <= m - 1; j++)
			sort(end[j].begin(), end[j].end());
		s.insert(-1); s.insert(k);
		for(int j = 0; j < m; j++) {
			for(int rk = 0; rk < (int)end[j].size(); rk++) {
				int no = end[j][rk];
				set <int> :: iterator it = s.find(no);
				s.erase(it);
			}
			for(int rk = 0; rk < (int)start[j].size(); rk++) {
				int no = start[j][rk];
				s.insert(no);
			}
			set <int> :: iterator it = s.begin(), it1; it++;
			int rp = *it;
			rans[rp] = max(rans[rp], ans0[j]);
			for(int rk = 0; rk < (int)end[j + 1].size(); rk++) {
				int no = end[j + 1][rk];
				set <int> :: iterator it = s.find(no), it1 = it;
				it1++;
				int rl = getl(loc[no].first, loc[no].second, i, j);
				sgt.down(no + 1, *it1, 1, rl);
			}
			for(int rk = 0; rk < (int)start[j + 1].size(); rk++) {
				int no = start[j + 1][rk];
				set <int> :: iterator it = s.lower_bound(no + 1), it1;
				it1 = it; it1--;
				int rl;
				if(*it1 == -1) rl = ans0[j];
				else rl = getl(loc[*it1].first, loc[*it1].second, i, j);
				sgt.down(no + 1, *it, 1, rl);
			}
		}
		for(int j = k; j >= 0; j--) {
			rans[j] = max(rans[j + 1], rans[j]);
			ans[j] = max(ans[j], rans[j]);
		}
	}
	for(int i = 1; i <= k; i++)
		printf("%d\n", max(ans[i], sgt.getv(i, 1)));

    return 0;
}
