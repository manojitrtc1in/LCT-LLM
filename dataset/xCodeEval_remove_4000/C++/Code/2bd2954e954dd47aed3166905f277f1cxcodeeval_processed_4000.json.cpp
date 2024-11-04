



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
const li INF64 = li(8e18);
const int MOD = INF + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 300 * 1000 + 13;
const int P = 600;

int n;
pair<int, pt> q[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n){
		scanf("%d%d", &q[i].x, &q[i].y.x);
		if (q[i].x == 1)
			scanf("%d", &q[i].y.y);
	}
	return true;
}

struct line {
	int m, c;
	li eval(int x) { return m * li(x) + c; }
};

li ans[N];
multiset<pt, greater<pt>> cur;
multiset<pt> tmp;

void rebuild(int l, int r){
	vector<pt> qr;
	fore(i, l, r) if (q[i].x == 3)
		qr.pb(mp(q[i].y.x, i));
	sort(all(qr));
	
	fore(i, l, r) if (q[i].x == 2 && q[i].y.x - 1 < l){
		cur.erase(cur.find(q[q[i].y.x - 1].y));
		tmp.insert(q[q[i].y.x - 1].y);
	}
	
	deque<line> dq;
	for (auto it : cur){
		line cur = {it.x, it.y};
		while (dq.size() >= 2 && (cur.c - dq[0].c) * li(dq[1].m - dq[0].m) >= (dq[0].c - dq[1].c) * li(dq[0].m - cur.m))
			dq.pop_front();
		dq.push_front(cur);
	}
	
	if (cur.empty()) return;
	
	reverse(all(qr));
	forn(i, sz(qr)){
		while (dq.size() >= 2 && dq.back().eval(qr[i].x) <= dq[dq.size() - 2].eval(qr[i].x))
			dq.pop_back();
		li f = dq.back().eval(qr[i].x);
		ans[qr[i].y] = max(ans[qr[i].y], f);
	}
}

void solve() {
	forn(i, n) ans[i] = -INF64;
	tmp.clear();
	cur.clear();
	forn(i, n){
		if (i % P == 0){
			for (auto it : tmp)
				cur.insert(it);
			tmp.clear();
			rebuild(i, min(n, i + P));
		}
		if (q[i].x == 3){
			for (auto it : tmp)
				ans[i] = max(ans[i], it.x * li(q[i].y.x) + it.y);
			if (ans[i] < -INF64 / 2)
				puts("EMPTY SET");
			else
				printf("%lld\n", ans[i]);
		}
		else if (q[i].x == 1){
			tmp.insert(q[i].y);
		}
		else{
			tmp.erase(tmp.find(q[q[i].y.x - 1].y));
		}
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