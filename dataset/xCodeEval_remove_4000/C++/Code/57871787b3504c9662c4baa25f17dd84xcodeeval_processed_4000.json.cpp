



using namespace std;











typedef long long li;
typedef long double ld;

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

const int N = 400 * 1000 + 13;

struct pt{
	int x, y, id, dir;
	pt(){}
	pt(int x, int y, int id, int dir) : x(x), y(y), id(id), dir(dir) {}
};

int n;
vector<pt> a;

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	a.resize(n);
	forn(i, n){
		int x, y;
		scanf("%d%d", &x, &y);
		if (x >= 0 && y >= 0)
			a[i] = pt(x, y, i, 0);
		else if (x < 0 && y >= 0)
			a[i] = pt(-x, y, i, 1);
		else if (x >= 0 && y < 0)
			a[i] = pt(x, -y, i, 2);
		else
			a[i] = pt(-x, -y, i, 3);
	}
	return true;
}

struct cmp_x {
    bool operator()(const pt & a, const pt & b) const {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
};

struct cmp_y {
    bool operator()(const pt & a, const pt & b) const {
        return a.y < b.y;
    }
};

double mindist;
pair<pair<int, int>, pair<int, int>> best_pair;

void upd_ans(const pt & a, const pt & b) {
    double dist = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
    if (dist < mindist) {
        mindist = dist;
        best_pair = {{a.id, a.dir}, {b.id, b.dir}};
    }
}

vector<pt> t;

void rec(int l, int r) {
    if (r - l <= 3) {
        for (int i = l; i < r; ++i) {
            for (int j = i + 1; j < r; ++j) {
                upd_ans(a[i], a[j]);
            }
        }
        sort(a.begin() + l, a.begin() + r, cmp_y());
        return;
    }

    int m = (l + r) >> 1;
    int midx = a[m].x;
    rec(l, m);
    rec(m, r);

    merge(a.begin() + l, a.begin() + m, a.begin() + m, a.begin() + r, t.begin(), cmp_y());
    copy(t.begin(), t.begin() + r - l, a.begin() + l);

    int tsz = 0;
    for (int i = l; i < r; ++i) {
        if (abs(a[i].x - midx) < mindist) {
            for (int j = tsz - 1; j >= 0 && a[i].y - t[j].y < mindist; --j)
                upd_ans(a[i], t[j]);
            t[tsz++] = a[i];
        }
    }
}

void solve() {
	

	

	t.resize(n);
	sort(a.begin(), a.end(), cmp_x());
	mindist = 1E20;
	rec(0, n);
	int x = best_pair.x.x;
	int xd = best_pair.x.y;
	int y = best_pair.y.x;
	int yd = best_pair.y.y;
	printf("%d %d %d %d\n", x + 1, xd + 1, y + 1, (yd ^ 3) + 1);
}

int main() {

	freopen("input.txt", "r", stdin);


	
	int tt = clock();

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	
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