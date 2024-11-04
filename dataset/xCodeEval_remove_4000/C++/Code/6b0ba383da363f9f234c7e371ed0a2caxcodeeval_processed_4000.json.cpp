





































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






int mod = MOD;
template <typename t> struct matrix{
	const static int maxn = 5;
	int row, col;
	t mat[maxn][maxn];

	matrix(int r = 0, int c = 0){
		row = r; col = c;
		for(int i = 0; i < row; i++) for(int j = 0; j < col; j++) mat[i][j] = 0;
	}
	const t * operator[] (int i) const {
		return mat[i];
	}
	t * operator[] (int i) {
		return mat[i];
	}
	bool danweiju(){
		if(row != col) return 0;
		for(int i = 0; i < row; i++) for(int j = 0; j < col; j++) mat[i][j] = bool (i == j);
		return 1;
	}
	matrix operator * (const matrix& b) const{
		int i, j, k;
		matrix <t> c(row, b.col);
		memset(c.mat, 0, sizeof(c.mat));
		for (i = 0; i < c.row; i++) for (k = 0; k < col; k++)
			if(mat[i][k])
				for (j = 0; j < c.col; j++){
					c.mat[i][j] += mat[i][k] * b.mat[k][j];
					c.mat[i][j] %= mod;
				}
		return c;
	}
	matrix operator + (const matrix& b) const{
		matrix <t> c(max1(row, b.row), max1(col, b.col));
		for(int i = 0; i < c.row; i++) for(int j = 0; j < c.col; j++){
			t a = 0; if(i < row && j < col) a = mat[i][j];
			t b1 = 0; if(i < b.row && j < b.col) b1 = b.mat[i][j];
			c.mat[i][j] = a + b1;
			c.mat[i][j] %= mod;
		}
		return c;
	}
	matrix operator - (const matrix& b) const{
		matrix <t> c(max1(row, b.row), max1(col, b.col));
		for(int i = 0; i < c.row; i++) for(int j = 0; j < c.col; j++){
			t a = 0; if(i < row && j < col) a = mat[i][j];
			t b1 = 0; if(i < b.row && j < b.col) b1 = b.mat[i][j];
			c.mat[i][j] = a - b1;
		}
		return c;
	}
	inline void operator = (const matrix & b){
		memcpy(mat, b.mat, sizeof(mat));
		col = b.col;  row = b.row;
	}
	matrix pow(long long n){
		matrix <t> ans(row, col), temp = *this;

		ans.danweiju();
		while(n){
			if(n & 1) ans = ans * temp;
			temp = temp * temp;
			n >>= 1;
		}
		return ans;
	}
	matrix addpow(long long n) {

		n++;
		matrix <t> ans(row, col), temp = *this, temp1(row, col), ans1(row, col);

		ans.danweiju(); temp1.danweiju();
		while(n){
			if(n & 1){
				ans1 = ans1 + ans * temp1;
				temp1 = temp * temp1;
			}
			ans = ans + ans * temp;
			temp = temp * temp;
			n >>= 1;
		}
		return ans1;
	}
	int inv(){
		int i, j, k, is[maxn], js[maxn];
		double t1;

		if (row != col) return 0;
		for(k = 0; k < row; k++){
			for(t1 = 0,i = k; i < row; i++) for(j = k; j < row; j++)
				if(fabs(mat[i][j]) > t1)
					t1=fabs(mat[is[k] = i][js[k] = j]);
			if (fabs(t1 - 0) < 1e-9) return 0;
			if (is[k] != k) for(j = 0; j < row; j++)
				t1 = mat[k][j], mat[k][j] = mat[is[k]][j], mat[is[k]][j] = t1;
			if (js[k] != k) for (i = 0; i < row; i++)
				t1 = mat[i][k], mat[i][k] = mat[i][js[k]], mat[i][js[k]] = t1;
			mat[k][k] = 1 / mat[k][k];
			for(j = 0; j < row; j++) if (j != k)
				mat[k][j] *= mat[k][k];
			for (i = 0; i < row; i++)	if (i != k)
				for (j = 0; j < row; j++) if (j != k)
					mat[i][j] -= mat[i][k] * mat[k][j];
			for (i = 0;i < row; i++) if (i != k)
				mat[i][k] *= -mat[k][k];
		}
		for (k = row-1; k >= 0; k--){
			for (j = 0; j < row; j++) if (js[k] != k)
					t1 = mat[k][j], mat[k][j] = mat[js[k]][j], mat[js[k]][j]=t1;
			for (i = 0; i < row; i++) if (is[k] != k)
				t1 = mat[i][k], mat[i][k] = mat[i][is[k]], mat[i][is[k]] = t1;
		}
		return 1;
	}
	double det(){
		int i, j, k, sign = 0;
		double b[maxn][maxn], ret = 1, t1;

		if (row != col) return 0;
		for (i = 0; i < row; i++) for (j = 0; j < col; j++)
			b[i][j] = mat[i][j];
		for (i = 0; i < row; i++){
			if (fabs(b[i][i] - 0) < 1e-9){
				for (j = i + 1; j < row; j++)
					if (fabs(b[j][i] - 0) > 1e-9) break;
					if (j == row) return 0;
					for (k = i; k < row; k++)
						t1 = b[i][k], b[i][k] = b[j][k], b[j][k] = t1;
					sign++;
			}
			ret *= b[i][i];
			for (k = i + 1; k < row; k++) b[i][k] /= b[i][i];
			for (j = i + 1; j < row; j++) for (k = i + 1; k < row; k++)
				b[j][k] -= b[j][i] * b[i][k];
		}
		if (sign & 1) ret = -ret;
		return ret;
	}
};

int n, m;



const int maxn = N;
int s[maxn];
struct segment_node{
	int be, en;
	ll mat[2][2];
};
struct segment_tree{
	int l;
	segment_node tree[N * 4];

	inline int gleft(int no) {return no << 1;}
	inline int gright(int no) {return (no << 1) + 1;}
	inline int gfa(int no) {return no >> 1;}
	inline segment_tree(){ l = 0; }

	inline void pushup(segment_node *fa, segment_node *le, segment_node *ri) {
		if(le->be == le->en && ri->be == ri->en) {
			fa->mat[1][0] = le->mat[0][0];
			fa->mat[1][1] = le->mat[0][1];
			fa->mat[0][0] = ri->mat[0][0] * le->mat[0][0] + ri->mat[0][1];
			fa->mat[0][1] = ri->mat[0][0] * le->mat[0][1];
		} else if(le->be == le->en && ri->be != ri->en) {
			fa->mat[1][0] = ri->mat[1][0] * le->mat[0][0] + ri->mat[1][1];
			fa->mat[1][1] = ri->mat[1][0] * le->mat[0][1];
			fa->mat[0][0] = ri->mat[0][0] * le->mat[0][0] + ri->mat[0][1];
			fa->mat[0][1] = ri->mat[0][0] * le->mat[0][1];
		} else if(le->be != le->en && ri->be == ri->en) {
			fa->mat[1][0] = le->mat[0][0];
			fa->mat[1][1] = le->mat[0][1];
			fa->mat[0][0] = ri->mat[0][0] * le->mat[0][0] + ri->mat[0][1] * le->mat[1][0];
			fa->mat[0][1] = ri->mat[0][0] * le->mat[0][1] + ri->mat[0][1] * le->mat[1][1];
		} else {
			fa->mat[0][0] = ri->mat[0][0] * le->mat[0][0] + ri->mat[0][1] * le->mat[1][0];
			fa->mat[0][1] = ri->mat[0][0] * le->mat[0][1] + ri->mat[0][1] * le->mat[1][1];
			fa->mat[1][0] = ri->mat[1][0] * le->mat[0][0] + ri->mat[1][1] * le->mat[1][0];
			fa->mat[1][1] = ri->mat[1][0] * le->mat[0][1] + ri->mat[1][1] * le->mat[1][1];
		}
		fa->mat[0][0] %= mod;
		fa->mat[0][1] %= mod;
		fa->mat[1][0] %= mod;
		fa->mat[1][1] %= mod;
		fa->be = le->be;
		fa->en = ri->en;
	}
	void build(int no, int l, int r){
		if(l > r) r = l;
		if(l == r){
			tree[no].be = tree[no].en = l;
			tree[no].mat[0][0] = s[(l - 1 + n) % n];
			tree[no].mat[0][1] = s[(l - 2 + n) % n];
			tree[no].mat[1][0] = 1;
			tree[no].mat[1][1] = 0;
			return;
		}
		tree[no].be = l; tree[no].en = r;
		int mid = (l + r) / 2;
		build(gleft(no), l, mid);
		build(gright(no), mid + 1, r);
		pushup(tree + no, tree + gleft(no), tree + gright(no));
	}
	segment_node getsum(int l, int r, int no){
		if(l > r) {
			segment_node ans;
			ans.mat[0][0] = 1; ans.mat[0][1] = 0;
			ans.mat[1][0] = 0; ans.mat[1][1] = 1;
			return ans;
		}
		if(l <= tree[no].be && r >= tree[no].en)
			return tree[no];
		segment_node ans;
		int mid = (tree[no].be + tree[no].en) >> 1;
		if(r >= tree[no].be && l <= mid) {
			ans = getsum(l, r, gleft(no));
			if(r >= mid + 1 && l <= tree[no].en) {
				segment_node le = ans, ri = getsum(l, r, gright(no));
				pushup(&ans, &le, &ri);
			}
			return ans;
		} else
			return getsum(l, r, gright(no));
	}
};

segment_tree sgt;
ll k, p;

pll nots[maxn];
map <ll, ll> mp;

matrix <ll> get(ll be, ll en) {
	be++;
	matrix <ll> ans(2, 2);
	if(en / n == be / n) {
		segment_node m = sgt.getsum(be % n, en % n, 1);
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				ans[i][j] = m.mat[i][j];
	} else {
		segment_node l = sgt.getsum(be % n, n - 1, 1);
		segment_node t = sgt.getsum(0, n - 1, 1);
		segment_node r = sgt.getsum(0, en % n, 1);
		matrix <ll> temp(2, 2), temp1(2, 2), temp2(2, 2);
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++) {
				temp[i][j] = r.mat[i][j];
				temp1[i][j] = t.mat[i][j];
				temp2[i][j] = l.mat[i][j];
			}
		ans = temp * temp1.pow(en / n - be / n - 1) * temp2;
	}
	return ans;
}

inline ll gc(ll loc) {
	if(mp.find(loc) != mp.end())
		return mp[loc];
	return s[loc % n];
}
int main() {




	ios_base::sync_with_stdio(0);
	

	freopen("input.txt", "r", stdin);
	int id0 = 256 << 20; 

	char *__p__ = (char*)malloc(id0) + id0;
	__asm__("movl %0, %%esp\n" :: "r"(__p__));
	


	cin >> k >> p;
	mod = p;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> s[i];
	if(n == 1) {
		s[n] = s[0];
		n = 2;
	}
	cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> nots[i].first >> nots[i].second;
		mp[nots[i].first] = nots[i].second;
	}
	sort(nots, nots + m);
	sgt.build(1, 0, n - 1);

	if(k < 2) {
		if(k == 1) cout << 1 % mod << endl;
		else cout << 0 << endl;
		return 0;
	}

	ll st = 2;
	matrix <ll> ans(2, 2);
	ans[0][0] = s[1]; ans[0][1] = s[0];
	ans[1][0] = 1; ans[1][1] = 0;
	nots[m++] = mpr(k + 1, -1);
	for(int i = 0; i < m; i++) {
		if(nots[i].first >= k) {
			matrix <ll> temp(2, 2);
			for(ll en = st + 3; st < en && st < k; ) {
				temp[1][0] = ans[0][0];
				temp[1][1] = ans[0][1];
				temp[0][0] = ans[0][0] * gc(st) + ans[1][0] * gc(st - 1);
				temp[0][1] = ans[0][1] * gc(st) + ans[1][1] * gc(st - 1);
				for(int ii = 0; ii < 2; ii++) for(int jj = 0; jj < 2; jj++)
					temp[ii][jj] %= mod;
				st++;
				ans = temp;
			}
			if(st != k)
				ans = get(st, k) * ans;
			st = k;
			break;
		} else {
			matrix <ll> temp(2, 2);
			for(ll en = st + 3; st < en && st < nots[i].first; ) {
				temp[1][0] = ans[0][0];
				temp[1][1] = ans[0][1];
				temp[0][0] = ans[0][0] * gc(st) + ans[1][0] * gc(st - 1);
				temp[0][1] = ans[0][1] * gc(st) + ans[1][1] * gc(st - 1);
				for(int ii = 0; ii < 2; ii++) for(int jj = 0; jj < 2; jj++)
					temp[ii][jj] %= mod;
				st++;
				ans = temp;
			}
			if(st != nots[i].first)
				ans = get(st, nots[i].first) * ans;
			st = nots[i].first;
		}
	}
	cout << ans[0][0] << endl;

    return 0;
}
