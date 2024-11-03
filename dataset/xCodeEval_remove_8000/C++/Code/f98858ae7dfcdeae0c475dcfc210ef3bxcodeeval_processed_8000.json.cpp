









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



i64 n, m, t, l, r, x; i64 a[100000];
i64 Tree[20][400000], Lazy[20][400000];



void Update(i64 node, i64 st, i64 en, i64 d, i64 L, i64 R) {
	if (st > en) return;
	if (Lazy[d][node] > 0) {
		Tree[d][node] = (en - st + 1) - Tree[d][node];
		if (st != en) {
			Lazy[d][node*2+0] ^= 1;
			Lazy[d][node*2+1] ^= 1;
		}
		Lazy[d][node] = 0;
	}
	if (R < st || en < L) return;
	if (L <= st && en <= R) {
		Tree[d][node] = (en - st + 1) - Tree[d][node];
		if (st != en) {
			Lazy[d][node*2+0] ^= 1;
			Lazy[d][node*2+1] ^= 1;
		}
		return;
	}
	Update(node*2, st, (st+en)/2, d, L, R);
	Update(node*2+1, (st+en)/2+1, en, d, L, R);
	Tree[d][node] = Tree[d][node*2] + Tree[d][node*2+1];
}

i64 Get(i64 node, i64 st, i64 en, i64 d, i64 L, i64 R) {
	if (st > en) return 0;
	if (Lazy[d][node] > 0) {
		Tree[d][node] = (en - st + 1) - Tree[d][node];
		if (st != en) {
			Lazy[d][node*2+0] ^= 1;
			Lazy[d][node*2+1] ^= 1;
		}
		Lazy[d][node] = 0;
	}
	if (R < st || en < L) return 0;
	if (L <= st && en <= R) return Tree[d][node];
	i64 p1 = Get(node*2, st, (st+en)/2, d, L, R);
	i64 p2 = Get(node*2+1, (st+en)/2+1, en, d, L, R);
	return (p1 + p2);
}

void Input() {
	cin >> n;
	for (i64 i=0; i<n; i++) {
		cin >> a[i];
		for (i64 j=0; j<20; j++) {
			if ((a[i] & (1LL << j)) == 0) continue;
			Update(1, 0, n-1, j, i, i);
		}
	}
}

void Solve() {
	cin >> m;
	while (m--) {
		cin >> t >> l >> r; l--; r--;
		if (t == 1) {
			i64 res = 0;
			for (i64 i=0; i<20; i++) res += (Get(1, 0, n-1, i, l, r)) * (1LL << i);
			cout << res << endl;
		}
		else if (t == 2) {
			cin >> x;
			for (i64 i=0; i<20; i++) {
				if ((x & (1LL << i)) == 0) continue;
				Update(1, 0, n-1, i, l, r);
			}
		}
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


