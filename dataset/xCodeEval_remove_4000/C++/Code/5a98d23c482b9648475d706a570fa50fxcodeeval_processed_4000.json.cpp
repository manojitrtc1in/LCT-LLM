



using namespace std;











typedef __int128 li;
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
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 200 * 1000 + 13;

int n;
long long s;
pt a[N];

bool read () {
	if (scanf("%d%lld", &n, &s) != 2)
		return false;
	forn(i, n)
		scanf("%d%d", &a[i].x, &a[i].y);
	return true;
}

struct Line {
    li k, m;
    mutable li p;
    bool operator<(const Line& o) const {
        return k < o.k;
    }
    bool operator<(const li&x) const {
        return p < x;
    }
};
 
struct LineContainer : multiset<Line, less<>> {
    

    const li inf = li(1) << 126;
    li div(li a, li b) { 

        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool isect(iterator x, iterator y) {
        if (y == end()) { x->p = inf; return false; }
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(li k, li m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    li query(li x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};

LineContainer hull;
li lst;

li get(li val){
	li l = lst, r = INF64;
	li res = -1;
	while (l <= r){
		li m = (l + r) / 2;
		li x = hull.query(m);
		if (x >= val){
			res = m;
			r = m - 1;
		}
		else{
			l = m + 1;
		}
	}
	assert(res != -1);
	lst = res;
	return res;
}

void solve() {
	hull.clear();
	hull.add(0, 0);
	sort(a, a + n, [](const pt &a, const pt &b){
		if (a.y != b.y)
			return a.y < b.y;
		return a.x < b.x;
	});
	lst = 0;
	forn(i, n){
		if (a[i].y >= s) break;
		li res = get(a[i].y);
		hull.add(a[i].x, hull.query(res) - a[i].y - a[i].x * res);
	}
	printf("%lld\n", (long long)get(s));
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