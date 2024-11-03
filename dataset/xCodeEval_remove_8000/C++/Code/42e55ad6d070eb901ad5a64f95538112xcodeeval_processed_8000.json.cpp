








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
string id1 = "FILE.IN";
string id2 = "FILE.OUT";



i64 n, s, l; vi a, Log2; vector<vi> TableMin, TableMax;
vi dpTree, dpLazy;



void id0() {
	for (i64 i=0; i<=n; i++) {
		for (i64 j=20; j>=0; j--) {
			if ((1LL << j) <= i) {
				Log2[i] = j;
				break;
			}
		}
	}
	for (i64 i=0; i<=n; i++) {TableMin[i].pub(a[i]); TableMax[i].pub(a[i]);}
	for (i64 j=1; j<=20; j++) {
		for (i64 i=0; i<=n; i++) {
			if (TableMin[i].size() < j) continue;
			if (i + (1LL << (j - 1)) > n) continue;
			if (TableMin[i+(1LL<<(j-1))].size() < j) continue;
			i64 NextMin = min(TableMin[i][j-1], TableMin[i+(1LL<<(j-1))][j-1]);
			i64 NextMax = max(TableMax[i][j-1], TableMax[i+(1LL<<(j-1))][j-1]);
			TableMin[i].pub(NextMin); TableMax[i].pub(NextMax);
		}
	}
}

i64 GetMin(i64 L, i64 R) {
	i64 len = R - L + 1, depth = Log2[len];
	return min(TableMin[L][depth], TableMin[R-(1LL<<depth)+1][depth]);
}

i64 GetMax(i64 L, i64 R) {
	i64 len = R - L + 1, depth = Log2[len];
	return max(TableMax[L][depth], TableMax[R-(1LL<<depth)+1][depth]);
}

void Propagate(i64 node, i64 st, i64 en) {
	dpTree[node] = min(dpTree[node], dpLazy[node]);
	if (st != en) {
		dpLazy[node*2+0] = min(dpLazy[node*2+0], dpLazy[node]);
		dpLazy[node*2+1] = min(dpLazy[node*2+1], dpLazy[node]);
	}
	dpLazy[node] = LINF;
}

void UpdateTree(i64 node, i64 st, i64 en, i64 L, i64 R, i64 val) {
	if (dpLazy[node] != LINF) Propagate(node, st, en);
	if (st > en || en < L || R < st) return;
	if (L <= st && en <= R) {
		dpLazy[node] = val;
		Propagate(node, st, en); return;
	}
	UpdateTree(node*2, st, (st+en)/2, L, R, val);
	UpdateTree(node*2+1, (st+en)/2+1, en, L, R, val);
	dpTree[node] = min(dpTree[node*2], dpTree[node*2+1]);
}

i64 GetTree(i64 node, i64 st, i64 en, i64 L, i64 R) {
	if (dpLazy[node] != LINF) Propagate(node, st, en);
	if (st > en || en < L || R < st) return LINF;
	if (L <= st && en <= R) return dpTree[node];
	i64 p1 = GetTree(node*2, st, (st+en)/2, L, R);
	i64 p2 = GetTree(node*2+1, (st+en)/2+1, en, L, R);
	return min(p1, p2);
}

i64 dp(i64 x) {
	return GetTree(1, 0, n, x, x);
}

i64 valid(i64 L, i64 R) {
	i64 Max = GetMax(L, R), Min = GetMin(L, R);
	return (Max - Min <= s);
}

i64 binsearch(i64 i) {
	i64 top = i+l-1, bot = n, ans = -1;
	while (top <= bot) {
		i64 mid = (top + bot) / 2;
		if (valid(i, mid)) {ans = mid; top = mid + 1;}
		else bot = mid - 1;
	}
	return ans;
}

void Input() {
	cin >> n >> s >> l; a.rsz(n+1);
	Log2.rsz(n+1); TableMin.rsz(n+1); TableMax.rsz(n+1);
	dpTree.rsz(n*4+4, LINF); dpLazy.rsz(n*4+4, LINF);
	for (i64 i=1; i<=n; i++) cin >> a[i];
}

void Solve() {
	id0();
	UpdateTree(1, 0, n, 0, 0, 0);
	for (i64 i=1; i<=n; i++) {
		if (dp(i-1) == LINF) continue;
		i64 deepest = binsearch(i);
		if (deepest == -1) continue;
		UpdateTree(1, 0, n, i+l-1, deepest, dp(i-1) + 1);
	}
	if (dp(n) == LINF) cout << "-1";
	else cout << dp(n);
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
	char* infile = new char[id1.size()+1];
	char* outfile = new char[id2.size()+1];
	strcpy(infile, id1.c_str());
	strcpy(outfile, id2.c_str());
	
		time_t t = time(0);
		tm* now = localtime(&t);
		cout << "Source code by 
		cout << "Current time: ";
		cout << (now->tm_year + 1900) << '-' 
			 << ((now->tm_mon < 9) ? "0" : "") << (now->tm_mon + 1) << '-'
			 << ((now->tm_mday < 10) ? "0" : "") <<  now->tm_mday << " | "
			 << ((now->tm_hour < 10) ? "0" : "") <<  now->tm_hour << ":"
			 << ((now->tm_min < 10) ? "0" : "") <<  now->tm_min << ":"
			 << ((now->tm_sec < 10) ? "0" : "") <<  now->tm_sec
			 << "\n\n";
		
		
			cout << "OI-Mode: ON\n";
			cout << "Input file: " << infile << endl;
			cout << "Output file: " << outfile << endl;
			cout << "\n";
		
			cout << "OI-Mode: OFF\n";
			cout << "Input file: NULL\n";
			cout << "Output file: NULL\n";
			cout << "\n";
		
		
		
			cout << "MultiTest-Mode: ON\n";
		
			cout << "MultiTest-Mode: OFF\n";
		
		
		
			cout << "Interactive-Mode: ON\n\n";
		
			cout << "Interactive-Mode: OFF\n\n";
		
		
		if (argc > 1) assert(freopen(argv[1], "r", stdin));
		if (argc > 2) assert(freopen(argv[2], "w", stdout));
	
		freopen(infile, "r", stdin);
		freopen(outfile, "w", stdout);
	
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


