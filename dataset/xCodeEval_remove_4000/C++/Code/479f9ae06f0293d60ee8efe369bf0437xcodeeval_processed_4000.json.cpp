






























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
struct node {
	int cate;
	int lev, from, to;
} orig[maxn];
int transx[maxn * 4], transy[maxn * 4], lx, ly;
int n;

ll ans[maxn], cnt = 1;
int fa[maxn];
vector <pii> eventx[maxn], eventy[maxn];

int getfa(int no) {
	if(fa[no] == -1) return no;
	return fa[no] = getfa(fa[no]);
}
void uni(int a, int b) {
	a = getfa(a), b = getfa(b);
	if(a == b) return;
	fa[a] = b;
}



set <int> rts;
struct segment_node{
	int be, en;
	int add, sum;
	mpii have;
} tree[N * 4];

	inline int gleft(int no) {return no << 1;}
	inline int gright(int no) {return (no << 1) + 1;}
	inline int gfa(int no) {return no >> 1;}

	void build(int no, int l, int r){
		if(l > r) r = l;
		if(l == r){
			tree[no].be = tree[no].en = l;
			tree[no].add = 0;
			tree[no].sum = 0;
			return;
		}
		tree[no].be = l; tree[no].en = r;
		int mid = (l + r) / 2;
		build(gleft(no), l, mid);
		build(gright(no), mid + 1, r);
		tree[no].sum = 0;
		tree[no].add = 0;
	}
	inline void relax(int no) {
		if(tree[gleft(no)].sum) {
			tree[gleft(no)].add = tree[no].add;
			tree[gleft(no)].have.clear();
			tree[gleft(no)].have.insert(mpr(tree[no].add, tree[gleft(no)].sum));
		}
		if(tree[gright(no)].sum) {
			tree[gright(no)].add = tree[no].add;
			tree[gright(no)].have.clear();
			tree[gright(no)].have.insert(mpr(tree[no].add, tree[gright(no)].sum));
		}
		tree[no].add = 0;
	}
	mpii down(int l, int r, int no, int ranadd){
		mpii reans;
		if(tree[no].sum == 0) return reans;
		if(l > r) return reans;
		if(l <= tree[no].be && r >= tree[no].en){
			reans = tree[no].have;
			mpii :: iterator it;
			for(it = reans.begin(); it != reans.end(); it++)
				it->second = -it->second;
			tree[no].add = ranadd;
			tree[no].have.clear();
			tree[no].have.insert(mpr(ranadd, tree[no].sum));
			reans[ranadd] += tree[no].sum;
			return reans;
		}
		if(tree[no].add && tree[no].be != tree[no].en) relax(no);
		int mid = (tree[no].be + tree[no].en) / 2;
		if(r >= tree[no].be && l <= mid) {
			mpii rrans = down(l, r, gleft(no), ranadd);
			mpii :: iterator it;
			for(it = rrans.begin(); it != rrans.end(); it++)
				reans[it->first] += it->second;
		}
		if(r >= mid + 1 && l <= tree[no].en) {
			mpii rrans = down(l, r, gright(no), ranadd);
			mpii :: iterator it;
			for(it = rrans.begin(); it != rrans.end(); it++)
				reans[it->first] += it->second;
		}
		mpii :: iterator it, it1;
		for(it = reans.begin(); it != reans.end(); ) {
			it1 = tree[no].have.find(it->first);
			if(it1 == tree[no].have.end()) {


				tree[no].have.insert(*it);
			} else {
				it1->second += it->second;


				if(it1->second == 0)
					tree[no].have.erase(it1);
			}
			it1 = it;
			it++;
			if(it1->second == 0) reans.erase(it1);
		}
		return reans;
	}
	void down1(int loc, int no, int ranadd) {
		if(tree[no].en == tree[no].be){


			tree[no].sum = 1;
			tree[no].have.insert(mpr(ranadd, 1));
			return;
		}
		if(tree[no].add && tree[no].be != tree[no].en) relax(no);
		int mid = (tree[no].be + tree[no].en) / 2;
		if(loc <= mid) down1(loc, gleft(no), ranadd);
		else down1(loc, gright(no), ranadd);
		tree[no].sum++;
		mpii :: iterator it = tree[no].have.find(ranadd);
		if(it == tree[no].have.end())
			tree[no].have.insert(mpr(ranadd, 1));
		else it->second++;
	}
	int down2(int loc, int no) {
		if(tree[no].en == tree[no].be){
			tree[no].sum = 0;
			int rr = tree[no].have.begin()->first;
			tree[no].have.clear();
			return rr;
		}
		if(tree[no].add && tree[no].be != tree[no].en) relax(no);
		int mid = (tree[no].be + tree[no].en) / 2;
		int pp;
		if(loc <= mid) pp = down2(loc, gleft(no));
		else pp = down2(loc, gright(no));
		tree[no].sum--;
		mpii :: iterator it = tree[no].have.find(pp);
		if(it->second == 1) tree[no].have.erase(it);
		else it->second--;

		return pp;
	}
	int getsum(int l, int r, int no){
		if(l <= tree[no].be && r >= tree[no].en) {
			set <int> s;
			mpii ::iterator it = tree[no].have.begin();
			for(; it != tree[no].have.end(); it++)
				rts.insert(getfa(it->first));
			return tree[no].sum;
		}
		if(tree[no].add && tree[no].be != tree[no].en) relax(no);
		int ans = 0;
		int mid = (tree[no].be + tree[no].en) / 2;
		if(r >= tree[no].be && l <= mid) ans += getsum(l, r, gleft(no));
		if(r >= mid + 1 && l <= tree[no].en) ans += getsum(l, r, gright(no));
		return ans;
	}


int main(){
	ios_base::sync_with_stdio(0);
	

	freopen("input.txt", "r", stdin);
	int id0 = 256 << 20; 

	char *__p__ = (char*)malloc(id0) + id0;
	__asm__("movl %0, %%esp\n" :: "r"(__p__));
	

	ll rans = 0;
	time_t be = clock();
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		transx[lx++] = a; transx[lx++] = c;
		transy[ly++] = b; transy[ly++] = d;
		if(a == c) {
			orig[i].cate = 0;
			orig[i].lev = a;
			if(b > d) swap(b, d);
			orig[i].from = b;
			orig[i].to = d;
		} else {
			orig[i].cate = 1;
			orig[i].lev = b;
			if(a > c) swap(a, c);
			rans = max(rans, 0ll + c - a);
			orig[i].from = a;
			orig[i].to = c;
		}
	}
	sort(transx, transx + lx);
	sort(transy, transy + ly);
	lx = unique(transx, transx + lx) - transx;
	ly = unique(transy, transy + ly) - transy;
	if(lx > ly) {
		for(int i = 0; i < lx; i++) swap(transx[i], transy[i]);
		swap(lx, ly);
		for(int i = 0; i < n; i++) orig[i].cate = 1 - orig[i].cate;
	}
	build(1, 0, lx);
	memset(fa, -1, sizeof(fa));
	for(int i = 0; i < n; i++) {
		if(orig[i].cate == 0) {
			orig[i].lev = find(orig[i].lev, transx, lx);
			orig[i].from = find(orig[i].from, transy, ly);
			orig[i].to = find(orig[i].to, transy, ly);
			eventy[orig[i].from].push_back(mpr(orig[i].lev, 1 + i));
			eventy[orig[i].to].push_back(mpr(orig[i].lev, -1 - i));
		} else {
			orig[i].lev = find(orig[i].lev, transy, ly);
			orig[i].from = find(orig[i].from, transx, lx);
			orig[i].to = find(orig[i].to, transx, lx);
			eventx[orig[i].lev].push_back(mpr(orig[i].from, orig[i].to));
		}
	}
	for(int i = 0; i < ly; i++) {
		for(int j = 0; j < (int)eventy[i].size(); j++) if(eventy[i][j].second > 0){
			down1(eventy[i][j].first, 1, cnt);
			int no = eventy[i][j].second - 1;
			ans[cnt] += transy[orig[no].to] - transy[orig[no].from];
			cnt++;
		}
		for(int j = 0; j < (int)eventx[i].size(); j++) {
			int from = eventx[i][j].first, to = eventx[i][j].second;
			rts.clear();
			int tans = getsum(from, to, 1);
			int rno = *rts.begin();
			rno = getfa(rno);
			ans[rno] += transx[to] - transx[from];
			set <int> ::iterator it = rts.begin();
			for(; it != rts.end(); it++) {
				int no = *it;
				if(no != rno)  {
					ans[rno] += ans[no];
					uni(no, rno);
				}
			}
			ans[rno] -= tans - rts.size();
			down(from, to, 1, rno);
		}
		for(int j = 0; j < (int)eventy[i].size(); j++) if(eventy[i][j].second < 0){
			down2(eventy[i][j].first, 1);
		}
	}
	for(int i = 1; i <= cnt; i++) rans = max(ans[i], rans);
	cout << rans << endl;
	time_t en = clock();
	cerr << double(en - be) / CLOCKS_PER_SEC << endl;

    return 0;
}
