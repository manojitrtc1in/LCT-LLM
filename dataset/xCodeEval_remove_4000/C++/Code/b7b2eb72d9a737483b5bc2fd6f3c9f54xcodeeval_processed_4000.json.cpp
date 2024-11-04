









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



i64 n, m, cl, ce, v, q, x1, y1, x2, y2; vi l, e;



i64 id3(i64 x) {
	if (cl == 0) return -LINF;
	if (x <= l[0]) return -LINF;
	i64 id = lower_bound(l.begin(), l.end(), x) - l.begin() - 1;
	return l[id];
}

i64 id1(i64 x) {
	if (ce == 0) return -LINF;
	if (x <= e[0]) return -LINF;
	i64 id = lower_bound(e.begin(), e.end(), x) - e.begin() - 1;
	return e[id];
}

i64 id0(i64 x) {
	if (cl == 0) return LINF;
	if (x >= l[cl-1]) return LINF;
	i64 id = upper_bound(l.begin(), l.end(), x) - l.begin();
	return l[id];
}

i64 id2(i64 x) {
	if (ce == 0) return LINF;
	if (x >= e[ce-1]) return LINF;
	i64 id = upper_bound(e.begin(), e.end(), x) - e.begin();
	return e[id];
}

bool id5(i64 L, i64 R) {
	i64 id1 = lower_bound(l.begin(), l.end(), L) - l.begin();
	i64 id2 = upper_bound(l.begin(), l.end(), R) - l.begin();
	return (id1 < id2);
}

bool id4(i64 L, i64 R) {
	i64 id1 = lower_bound(e.begin(), e.end(), L) - e.begin();
	i64 id2 = upper_bound(e.begin(), e.end(), R) - e.begin();
	return (id1 < id2);
}

void Input() {
	cin >> n >> m >> cl >> ce >> v; l.rsz(cl); e.rsz(ce);
	for (i64 i=0; i<cl; i++) cin >> l[i];
	for (i64 i=0; i<ce; i++) cin >> e[i];
}

void Solve() {
	cin >> q;
	while (q--) {
		cin >> x1 >> y1 >> x2 >> y2; i64 ans = LINF;
		if (x1 > x2) swap(x1, x2); if (y1 > y2) swap(y1, y2);
		if (x1 == x2) ans = min(ans, y2-y1);
		if (id3(y1) != -LINF) ans = min(ans, (y2-y1)+(x2-x1)+2*(y1-id3(y1)));
		if (id1(y1) != -LINF) ans = min(ans, (y2-y1)+(x2-x1)/v+((x2-x1)%v>0)+2*(y1-id1(y1)));
		if (id0(y2) != LINF) ans = min(ans, (y2-y1)+(x2-x1)+2*(id0(y2)-y2));
		if (id2(y2) != LINF) ans = min(ans, (y2-y1)+(x2-x1)/v+((x2-x1)%v>0)+2*(id2(y2)-y2));
		if (id5(y1, y2)) ans = min(ans, (y2-y1)+(x2-x1));
		if (id4(y1, y2)) ans = min(ans, (y2-y1)+(x2-x1)/v+((x2-x1)%v>0));
		cout << ans << endl;
	}
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


