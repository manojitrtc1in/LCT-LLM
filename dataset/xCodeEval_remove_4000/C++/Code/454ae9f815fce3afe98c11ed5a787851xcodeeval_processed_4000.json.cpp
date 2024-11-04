



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

const int N = (1 << 21) + 13;

int h, g;
int a[N], d[N];

bool read () {
	if (scanf("%d%d", &h, &g) != 2)
		return false;
	forn(i, 2 << h)
		a[i] = d[i] = 0;
	fore(i, 1, 1 << h)
		scanf("%d", &a[i]);
	return true;
}

void init(int v, int x){
	if (x == h){
		d[v] = 1;
		return;
	}
	init(v * 2, x + 1);
	init(v * 2 + 1, x + 1);
	d[v] = d[v * 2] + 1;
}

void upd(int v){
	if (a[v * 2] == 0 && a[v * 2 + 1] == 0){
		a[v] = 0;
		d[v] = 0;
	}
	else{
		if (a[v * 2] > a[v * 2 + 1]){
			a[v] = a[v * 2];
			upd(v * 2);
		}
		else{
			a[v] = a[v * 2 + 1];
			upd(v * 2 + 1);
		}
		if (a[v * 2] > a[v * 2 + 1]){
			d[v] = d[v * 2] + 1;
		}
		else{
			d[v] = d[v * 2 + 1] + 1;
		}
	}
}

void solve() {
	init(1, 0);
	int cur = 0;
	set<pt, greater<pt>> tmp;
	tmp.insert(mp(a[1], 1));
	
	vector<int> ans;
	li sum = accumulate(a + 1, a + (1 << h), 0ll);
	int cnt = (1 << h) - (1 << g);
	while (cnt > 0){
		while (!tmp.empty() && cnt > 0){
			int v = tmp.begin()->y;
			tmp.erase(tmp.begin());
			if (cur + d[a[v * 2] > a[v * 2 + 1] ? v * 2 : v * 2 + 1] >= g){
				sum -= a[v];
				upd(v);
				ans.pb(v);
				--cnt;
				if (a[v]){
					tmp.insert(mp(a[v], v));
				}
			}
		}
		++cur;
		assert(cnt == 0 || cur != h);
		for (int i = 1 << cur; i < (2 << cur); ++i) if (a[i])
			tmp.insert(mp(a[i], i));
	}
	
	printf("%lld\n", sum);
	for (auto it : ans)
		printf("%d ", it);
	puts("");
}

int main() {

	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	

	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

	int tc;
	scanf("%d", &tc);
	while(tc--){
		read();
		solve();
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();


	}
}