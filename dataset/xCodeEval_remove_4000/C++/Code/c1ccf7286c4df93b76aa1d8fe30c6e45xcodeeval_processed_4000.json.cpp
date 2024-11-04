



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

const int N = 5000 + 7;

int n, m;
pair<pt, pt> q[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, m){
		scanf("%d%d%d%d", &q[i].x.x, &q[i].x.y, &q[i].y.x, &q[i].y.y);
		--q[i].x.y;
	}
	return true;
}

bool used[N];
int val[N];

void solve(){
	memset(used, 0, sizeof(used));
	fill(val, val + n, -INF);
	for (int j = m - 1; j >= 0; --j){
		int l = q[j].x.y, r = q[j].y.x;
		int x = q[j].y.y;
		if (q[j].x.x == 1){
			fore(i, l, r) if (used[i])
				val[i] -= x;
		}
		else{
			fore(i, l, r){
				if (!used[i]){
					val[i] = x;
					used[i] = true;
				}
				else
					val[i] = min(val[i], x);
			}
		}
	}
	
	vector<int> ans(val, val + n);
	forn(j, m){
		int l = q[j].x.y, r = q[j].y.x;
		int x = q[j].y.y;
		if (q[j].x.x == 1){
			fore(i, l, r)
				val[i] += x;
		}
		else{
			int mx = val[l];
			fore(i, l, r)
				mx = max(mx, val[i]);
			if (mx != x){
				puts("NO");
				return;
			}
		}
	}
	
	puts("YES");
	forn(i, n)
		printf("%d ", ans[i]);
	puts("");
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