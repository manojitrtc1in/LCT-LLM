









using namespace std;











typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
long long keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
long long keyCount = sizeof(keymod) / sizeof(long long);



template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcountll(s); }



auto TimeStart = chrono::steady_clock::now();
auto TimeEnd = chrono::steady_clock::now();








void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();



i64 n, m, k, Base, bucket; vi a, ps;
vector<long long> ans;
vector<ppi> Query;
vi Map(1048576, 0);
vector<vector<ppi>> Bucket;



bool querysort(ppi x, ppi y) {
	return (x.fi.se < y.fi.se);
}

void Input() {
	cin >> n >> m >> k; Base = sqrt(n); a.rsz(n+1); Query.rsz(m); ps.rsz(n+1, 0);
	bucket = n / Base + 1; Bucket.rsz(bucket); Map[0]++; ans.rsz(m, 0);
	for (i64 i=1; i<=n; i++) cin >> a[i];
	for (i64 i=0; i<m; i++) {
		cin >> Query[i].fi.fi >> Query[i].fi.se; Query[i].se = i;
		Bucket[Query[i].fi.fi / Base].pub(Query[i]);
	}
}

void Solve() {
	for (i64 i=0; i<bucket; i++) sort(Bucket[i].begin(), Bucket[i].end(), querysort);
	for (i64 i=1; i<=n; i++) {ps[i] = ps[i-1] ^ a[i]; Map[ps[i]]++;}
	if (k == 0) {
		for (i64 x=0; x<bucket; x++) {
			for (auto &z: Map) z = 0;
			i64 st = max(x * Base - 1, 0), petr = st;
			long long res = 0;
			for (auto Q: Bucket[x]) {
				i64 L = Q.fi.fi, R = Q.fi.se, id = Q.se;
				while (petr <= R) {
					res += Map[ps[petr]];
					Map[ps[petr]]++; petr = petr + 1;
				}
				for (i64 i=st; i<L-1; i++) {
					Map[ps[i]]--; res -= Map[ps[i]];
				}
				ans[id] = res;
				for (i64 i=L-2; i>=st; i--) {
					res += Map[ps[i]]; Map[ps[i]]++;
				}
			}
		}
		for (auto x: ans) cout << x << endl; return;
	}
	for (i64 x=0; x<bucket; x++) {
		for (auto &z: Map) z = 0;
		i64 st = max(x * Base - 1, 0), petr = st;
		long long res = 0;
		for (auto Q: Bucket[x]) {
			i64 L = Q.fi.fi, R = Q.fi.se, id = Q.se;
			while (petr <= R) {
				res += Map[k ^ ps[petr]];
				Map[ps[petr]]++; petr = petr + 1;
			}
			for (i64 i=st; i<L-1; i++) {
				res -= Map[k ^ ps[i]];
				Map[ps[i]]--;
			}
			ans[id] = res;
			for (i64 i=L-2; i>=st; i--) {
				res += Map[k ^ ps[i]];
				Map[ps[i]]++;
			}
		}
	}
	for (auto x: ans) cout << x << endl;
}



int main(int argc, char* argv[]) {
	ControlIO(argc, argv);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	
		Input(); TimerStart();
		Solve(); TimerStop();
	
		int T; cin >> T; TimerStart();
		while(T--) {Input(); Solve();}
		TimerStop();
	
	return 0;
}



void ControlIO(int argc, char* argv[]) {
	
	time_t t = time(0);
	tm* now = localtime(&t);
	cout << "Source code by 
	cout << "Current time: ";
	cout << (now->tm_year + 1900) << '-' 
	     << (now->tm_mon + 1) << '-'
	     <<  now->tm_mday << " | "
	     <<  now->tm_hour << ":"
	     <<  now->tm_min << ":"
	     <<  now->tm_sec
	     << "\n\n";
	if (argc > 1) assert(freopen(argv[1], "r", stdin));
	if (argc > 2) assert(freopen(argv[2], "w", stdout));
	
	freopen("FILENAME.INP", "r", stdin);
	freopen("FILENAME.OUT", "w", stdout);
	
}

void TimerStart() {
	
	TimeStart = chrono::steady_clock::now();
	
}

void TimerStop() {
	
	TimeEnd = chrono::steady_clock::now();
	auto ElapsedTime = TimeEnd - TimeStart;
	cout << "\n\nTime elapsed: " << chrono::duration<double>(ElapsedTime).count() << " seconds.\n";
	
}

void Exit() {
	TimerStop(); exit(0);
}


