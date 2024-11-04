






























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







const int mod = MOD;
typedef pair <pair <ll, ll>, ll> node;
node operator + (const node &a, const node &b) {
	node c;
	c.first.first = a.first.first + b.first.first;
	c.first.second = a.first.second + b.first.second;
	c.second = a.second + b.second;
	if(c.first.first >= mod) c.first.first -= mod;
	if(c.first.second >= mod) c.first.second -= mod;
	if(c.second >= mod) c.second -= mod;
	return c;
}

template <typename t> struct matrix{
	const static int maxn = 4;
	int row, col;
	t mat[maxn][maxn];

	matrix(int r = 0, int c = 0){
		row = r; col = c;
		for(int i = 0; i < row; i++) for(int j = 0; j < col; j++) mat[i][j] = 0;
	}
	bool danweiju(){
		if(row != col) return 0;
		for(int i = 0; i < row; i++) for(int j = 0; j < col; j++) mat[i][j] = bool (i == j);
		return 1;
	}
	t * operator[] (int i) {
		return mat[i];
	}
	const t * operator[] (int i) const {
		return mat[i];
	}
	matrix operator * (const matrix& b) const{
		int i, j, k;
		matrix <t> c(row, b.col);
		memset(c.mat, 0, sizeof(c.mat));
		for (i = 0; i < c.row; i++) for (k = 0; k < col; k++)
			if(mat[i][k])
				for (j = 0; j < c.col; j++){
					add(c.mat[i][j], mat[i][k] * b.mat[k][j] % mod);
				}
		return c;
	}
	matrix operator + (const matrix& b) const{
		matrix <t> c(max1(row, b.row), max1(col, b.col));
		for(int i = 0; i < c.row; i++) for(int j = 0; j < c.col; j++){
			t a = 0; if(i < row && j < col) a = mat[i][j];
			t b1 = 0; if(i < b.row && j < b.col) b1 = b.mat[i][j];
			c.mat[i][j] = (a + b1) % mod;
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




template <class t> struct segment_node{
	int be, en;
	t add, sum1, sum2, sum, sum3;
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
			tree[no].add = 0;
			tree[no].sum = a[l];
			return;
		}
		tree[no].be = l; tree[no].en = r;
		int mid = (l + r) / 2;
		build(gleft(no), l, mid, orig, a);
		build(gright(no), mid + 1, r, orig, a);
		tree[no].sum = tree[gleft(no)].sum + tree[gright(no)].sum;
		tree[no].add = 0;
	}
	void down(int l, int r, int no, t ranadd){
		if(l <= tree[no].be && r >= tree[no].en){
			tree[no].add += ranadd;
			tree[no].sum += ranadd * (tree[no].en - tree[no].be + 1);
			return;
		}
		int mid = (tree[no].be + tree[no].en) / 2;
		if(r >= tree[no].be && l <= mid) down(l, r, gleft(no), ranadd);
		if(r >= mid + 1 && l <= tree[no].en) down(l, r, gright(no), ranadd);
		tree[no].sum = tree[gleft(no)].sum + tree[gright(no)].sum;
	}
	void down1(int loc, int no, pair <pair <t, t>, t> ranadd){
		if(loc <= tree[no].be && loc >= tree[no].en){
			add(tree[no].sum1, ranadd.first.first);
			add(tree[no].sum2, ranadd.first.second);
			add(tree[no].sum3, ranadd.second);
			return;
		}
		int mid = (tree[no].be + tree[no].en) / 2;
		if(loc >= tree[no].be && loc <= mid) down1(loc, gleft(no), ranadd);
		else down1(loc, gright(no), ranadd);
		tree[no].sum1 = tree[gleft(no)].sum1 + tree[gright(no)].sum1;
		if(tree[no].sum1 >= mod) tree[no].sum1 -= mod;
		tree[no].sum2 = tree[gleft(no)].sum2 + tree[gright(no)].sum2;
		if(tree[no].sum2 >= mod) tree[no].sum2 -= mod;
		tree[no].sum3 = tree[gleft(no)].sum3 + tree[gright(no)].sum3;
		if(tree[no].sum3 >= mod) tree[no].sum3 -= mod;
	}
	t getsum(int l, int r, int no){
		if(l > r) return 0;
		if(l <= tree[no].be && r >= tree[no].en)
			return tree[no].sum;
		t ans = 0;
		int mid = (tree[no].be + tree[no].en) / 2;
		if(r >= tree[no].be && l <= mid) ans += getsum(max1(l, tree[no].be), min1(r, mid), gleft(no));
		if(r >= mid + 1 && l <= tree[no].en) ans += getsum(max1(l, mid + 1), min1(r, tree[no].en), gright(no));
		return ans % mod;
	}
	pair <pair <ll, ll>, ll> getsum1(int l, int r, int no) {
		if(l > r) return mpr(mpr(0, 0), 0);
		if(l <= tree[no].be && r >= tree[no].en)
			return mpr(mpr(tree[no].sum1, tree[no].sum2), tree[no].sum3);
		pair <pair <ll, ll>, ll> ans = mpr(mpr(0, 0), 0);
		int mid = (tree[no].be + tree[no].en) / 2;
		if(r >= tree[no].be && l <= mid) ans = ans + getsum1(max1(l, tree[no].be), min1(r, mid), gleft(no));
		if(r >= mid + 1 && l <= tree[no].en) ans = ans + getsum1(max1(l, mid + 1), min1(r, tree[no].en), gright(no));
		return ans;
	}
};
segment_tree <ll> sgt;

const int maxn = N;
ll arr[maxn];
int n, nq;
matrix <ll> m1(3, 3), m2(3, 3), rm1[maxn], rm2[maxn];

ll id1(int l) {
	if(l < 0) return 0;
	pair <pair <ll, ll>, ll> rp = sgt.getsum1(0, l, 1);
	ll a = rp.first.first, b = rp.first.second, c = rp.second;
	return (a * rm2[n - l][0][2] % mod + b * rm2[n - l][0][1] % mod + c * rm2[n - l][0][0] % mod) % mod;
}
int main(){
    ios_base::sync_with_stdio(0);
	

	freopen("input.txt", "r", stdin);
	

	scanf("%d%d", &n, &nq);
	for(int i = 0; i < n; i++) scanf("%I64d", arr + i);
	sgt.build(1, 0, n + 2, 0, arr);

	m1[0][0] = 1, m1[0][1] = 1, m1[0][2] = 1;
	m1[1][0] = 0, m1[1][1] = 1; m1[1][2] = 1;
	m1[1][0] = 0, m1[2][1] = 1; m1[2][2] = 0;
	m2[0][0] = 1, m2[0][1] = mod - 1, m2[0][2] = 0;
	m2[1][0] = 0, m2[1][1] = 0; m2[1][2] = 1;
	m2[1][0] = 0, m2[2][1] = 1; m2[2][2] = mod - 1;
	rm1[0].row = rm1[0].col = rm2[0].col = rm2[0].row = 3;
	rm1[0].danweiju(), rm2[0].danweiju();
	for(int i = 1; i <= n + 1; i++) {
		rm1[i] = rm1[i - 1] * m1;
		rm2[i] = rm2[i - 1] * m2;
	}

	for(int i = 0; i < nq; i++) {
		int cate, l, r;
		scanf("%d%d%d", &cate, &l, &r);
		l--; r--;
		if(cate == 1) {
			matrix <ll> rm = rm1[n - l];
			sgt.down1(l, 1, mpr(mpr(rm[2][0] + rm[2][1], rm[1][0] + rm[1][1]), rm[0][0] + rm[0][1]));
			rm = rm1[n - r - 1];
			ll ra = rm1[r - l + 1][2][1],
			  rb = rm1[r - l + 1][1][1],
			  rc = rb;
			ll rra, rrb, rrc;
			rra = rm[2][0] * rc % mod + rm[2][1] * rb % mod + rm[2][2] * ra % mod;
			rra %= mod;
			rrb = rm[1][0] * rc % mod + rm[1][1] * rb % mod + rm[1][2] * ra % mod;
			rrb %= mod;
			rrc = rm[0][0] * rc % mod + rm[0][1] * rb % mod + rm[0][2] * ra % mod;
			rrc %= mod;
			sgt.down1(r + 1, 1, mpr(mpr(mod - rra, mod - rrb), mod - rrc));
		} else {
			printf("%I64d\n", (id1(r) - id1(l - 1) + mod + sgt.getsum(l, r, 1)) % mod);
		}
	}

    return 0;
}
