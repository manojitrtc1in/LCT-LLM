








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



i64 n; vi a, Log2; vector<vi> id0, TableMin;
i64 len; vi ID, Tmp;



void BuildTable() {
	Log2.rsz(n+1, 0);
	id0.rsz(n); TableMin.rsz(n);
	for (i64 i=0; i<=n; i++) {
		for (i64 j=20; j>=0; j--) {
			if ((1LL << j) <= i) {
				Log2[i] = j;
				break;
			}
		}
	}
	for (i64 i=0; i<n; i++) {
		id0[i].pub(a[i]);
		TableMin[i].pub(a[i]);
	}
	for (i64 j=1; j<=20; j++) {
		for (i64 i=0; i<n; i++) {
			if (id0[i].size() < j) continue;
			if (i + (1LL << (j - 1)) >= n) continue;
			if (id0[i + (1LL << (j - 1))].size() < j) continue;
			id0[i].pub(__gcd(id0[i][j-1], id0[i + (1LL << (j - 1))][j-1]));
		}
	}
	for (i64 j=1; j<=20; j++) {
		for (i64 i=0; i<n; i++) {
			if (TableMin[i].size() < j) continue;
			if (i + (1LL << (j - 1)) >= n) continue;
			if (TableMin[i + (1LL << (j - 1))].size() < j) continue;
			TableMin[i].pub(min(TableMin[i][j-1], TableMin[i + (1LL << (j - 1))][j-1]));
		}
	}
}

i64 id1(i64 L, i64 R) {
	i64 res = 0;
	while (L <= R) {
		i64 dist = R - L + 1;
		res = __gcd(res, id0[L][Log2[dist]]);
		L += (1LL << Log2[dist]);
	}
	return res;
}

i64 GetMin(i64 L, i64 R) {
	i64 res = LINF;
	while (L <= R) {
		i64 dist = R - L + 1;
		res = min(res, TableMin[L][Log2[dist]]);
		L += (1LL << Log2[dist]);
	}
	return res;
}

void calculate(i64 siz) {
	Tmp.clear();
	for (i64 i=0; i<=n-siz; i++) {
		if (GetMin(i, i+siz-1) == id1(i, i+siz-1)) {
			Tmp.pub(i+1);
		}
	}
}

void binsearch(i64 top, i64 bot) {
	while (top <= bot) {
		i64 mid = (top + bot) / 2;
		calculate(mid);
		if (!Tmp.empty()) {len = mid-1; ID = Tmp; top = mid + 1;}
		else bot = mid - 1;
	}
}

void Input() {
	cin >> n; a.rsz(n);
	for (i64 i=0; i<n; i++) cin >> a[i];
}

void Solve() {
	BuildTable(); binsearch(1, n);
	cout << ID.size() << " " << len << endl;
	for (auto x: ID) cout << x << " ";
}



int main(int argc, char* argv[]) {
	ControlIO(argc, argv);

	
		ios_base::sync_with_stdio(0); cin.tie(NULL);
	
		ios_base::sync_with_stdio(0);
	
	
	
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


