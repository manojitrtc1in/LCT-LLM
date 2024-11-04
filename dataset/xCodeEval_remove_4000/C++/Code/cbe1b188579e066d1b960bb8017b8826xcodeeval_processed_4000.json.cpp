



using namespace std;











typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template <class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template <class A> ostream& operator << (ostream& out, const vector<A> &v) {
	out << "[";
	forn(i, sz(v)) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}

mt19937 rnd(time(NULL));

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 200 * 1000 + 13;
const int P = 500;

int n, m;
int a[N], b[N];
vector<int> g[N];
pair<int, pt> q[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n)
		g[i].clear();
	fore(i, 1, n){
		int p;
		scanf("%d", &p);
		g[p - 1].pb(i);
	}
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, n)
		scanf("%d", &b[i]);
	forn(i, m){
		scanf("%d%d", &q[i].x, &q[i].y.x);
		--q[i].y.x;
		if (q[i].x == 1)
			scanf("%d", &q[i].y.y);
	}
	return true;
}

typedef pair<li, li> point;

li dot(point a, point b) {
	return a.x * li(b.x) + a.y * li(b.y);
}

li cross(point a, point b){
	return a.x * li(b.y) - a.y * li(b.x);
}

point operator -(const point &a, const point &b){
	return mp(a.x - b.x, a.y - b.y);
}

void add_line(vector<point> &hull, vector<point> &vecs, li k, li b) {
	point nw({k, b});
	while (!vecs.empty() && dot(vecs.back(), nw - hull.back()) < 0){
		hull.pop_back();
		vecs.pop_back();
	}
	if (!hull.empty()){
		point p = nw - hull.back();
		vecs.push_back(mp(-p.y, p.x));
	}
	hull.push_back(nw);
}

li get(vector<point> &hull, vector<point> &vecs, li x) {
	point query({x, 1});
	auto it = lower_bound(vecs.begin(), vecs.end(), query, [](point a, point b){
		return cross(a, b) > 0;
	});
	assert(!hull.empty());
	return dot(query, hull[it - vecs.begin()]);
}

int tin[N], tout[N], T;
int val[N];
int sum[N];

void dfs(int v, int x, int y){
	tin[v] = T++;
	x += b[v];
	y += a[v];
	val[tin[v]] = abs(x);
	sum[tin[v]] = y;
	for (auto u : g[v])
		dfs(u, x, y);
	tout[v] = T - 1;
}

int add[N], fr[N];
vector<point> hull[N], vecs[N];

void rebuild(int x){
	fr[x] = 2 * INF;
	
	vector<point> ord;
	fore(i, x * P, min(n, (x + 1) * P)){
		sum[i] += add[x];
		if (sum[i] < 0) fr[x] = min(fr[x], -sum[i]);
		ord.pb(mp((sum[i] < 0 ? 1 : -1) * val[i], -abs(sum[i]) * li(val[i])));
	}
	add[x] = 0;
	
	hull[x].clear();
	vecs[x].clear();
	sort(all(ord));
	
	assert(!ord.empty());
	int lst = ord[0].x - 1;
	for (auto it : ord){
		int k = it.x;
		li b = it.y;
		if (lst == k)
			continue;
		lst = k;
		add_line(hull[x], vecs[x], k, b);
	}
}

void upd(int l, int r, int x){
	if (l % P != 0){
		int bl = l / P;
		while (l <= r && l % P != 0){
			sum[l] += x;
			++l;
		}
		rebuild(bl);
		if (l > r) return;
	}
	
	if (r != n - 1 && r % P != P - 1){
		int bl = r / P;
		while (r >= 0 && r % P != P - 1){
			sum[r] += x;
			--r;
		}
		rebuild(bl);
		if (l > r) return;
	}
	
	assert(l % P == 0 && (r == n - 1 || r % P == P - 1));
	while (l <= r){
		int bl = l / P;
		add[bl] += x;
		if (add[bl] > fr[bl])
			rebuild(bl);
		l += P;
	}
}

li get(int l, int r){
	li ans = 0;
	for (; l <= r;){
		if (l % P == 0 && l + P <= r + 1){
			ans = max(ans, -get(hull[l / P], vecs[l / P], add[l / P]));
			l += P;
		}
		else{
			ans = max(ans, abs(sum[l] + add[l / P]) * li(val[l]));
			++l;
		}
	}
	return ans;
}

void solve(){
	T = 0;
	dfs(0, 0, 0);
	
	memset(add, 0, sizeof(add));
	forn(i, n / P) rebuild(i);
	
	forn(i, m){
		if (q[i].x == 1)
			upd(tin[q[i].y.x], tout[q[i].y.x], q[i].y.y);
		else
			printf("%lld\n", get(tin[q[i].y.x], tout[q[i].y.x]));
	}
}

int main() {

	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	

	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

	while(read()) {	
		solve();
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();


	}
}