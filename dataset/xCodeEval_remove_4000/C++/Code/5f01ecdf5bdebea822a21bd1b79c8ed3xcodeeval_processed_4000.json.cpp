



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

const int N = 100 * 1000 + 13;

int n;
int p[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n){
		scanf("%d", &p[i]);
		--p[i];
	}
	return true;
}

bool used[N];

void solve() {
	forn(i, n) if (p[i] == i){
		puts("YES");
		forn(j, n) if (j != i)
			printf("%d %d\n", i + 1, j + 1);
		return;
	}
	
	vector<vector<int>> loops;
	memset(used, 0, sizeof(used));
	vector<int> tmp2;
	vector<pt> res;
	forn(i, n) if (!used[i]){
		used[i] = true;
		int v = p[i];
		vector<int> tmp(1, i);
		while (v != i){
			tmp.pb(v);
			used[v] = true;
			v = p[v];
		}
		if (sz(tmp) % 2 == 1){
			puts("NO");
			return;
		}
		if (sz(tmp) > 2 || !tmp2.empty()){
			loops.pb(tmp);
		}
		else{
			res.pb(mp(tmp[0], tmp[1]));
			tmp2 = tmp;
		}
	}
	if (tmp2.empty()){
		puts("NO");
		return;
	}
	for (auto it : loops){
		forn(i, sz(it))
			res.pb(mp(tmp2[i % 2], it[i]));
	}
	
	puts("YES");
	forn(i, n - 1) printf("%d %d\n", res[i].x + 1, res[i].y + 1);
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