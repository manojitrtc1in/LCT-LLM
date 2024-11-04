



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
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 200 * 1000 + 13;

int n;
int a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n){
		scanf("%d", &a[i]);
		--a[i];
	}
	return true;
}

vector<int> pos[N];

void solve() {
	forn(i, n) pos[i].clear();
	forn(i, n) pos[a[i]].pb(i);
	queue<int> q;
	forn(i, n) if (sz(pos[i]) > 1) q.push(i);
	int cnt = n;
	forn(i, n) if (pos[i].empty()){
		--cnt;
		int j = q.front();
		q.pop();
		if (pos[j].back() == i)
			swap(pos[j].back(), pos[j][sz(pos[j]) - 2]);
		a[pos[j].back()] = i;
		pos[j].pop_back();
		if (sz(pos[j]) > 1)
			q.push(j);
	}
	printf("%d\n", cnt);
	forn(i, n) printf("%d ", a[i] + 1);
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

	while(read()) {	

		solve();
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();


	}
}