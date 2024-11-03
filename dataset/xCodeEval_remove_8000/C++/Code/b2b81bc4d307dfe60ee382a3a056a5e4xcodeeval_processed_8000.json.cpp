








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



i64 k, n, q; string s;
vector<vi> Tree, Lazy; vb deleted;



void Update(i64 id, i64 node, i64 st, i64 en, i64 L, i64 R, i64 x) {
	if (Lazy[id][node] != 0) {
		Tree[id][node] += (en - st + 1) * Lazy[id][node];
		if (st != en) {
			Lazy[id][node*2+0] += Lazy[id][node];
			Lazy[id][node*2+1] += Lazy[id][node];
		}
		Lazy[id][node] = 0;
	}
	if (st > en || R < st || en < L) return;
	if (L <= st && en <= R) {
		Tree[id][node] += (en - st + 1) * x;
		if (st != en) {
			Lazy[id][node*2+0] += x;
			Lazy[id][node*2+1] += x;
		}
		return;
	}
	Update(id, node*2, st, (st+en)/2, L, R, x);
	Update(id, node*2+1, (st+en)/2+1, en, L, R, x);
	Tree[id][node] = Tree[id][node*2], Tree[id][node*2+1];
}

i64 Get(i64 id, i64 node, i64 st, i64 en, i64 L, i64 R) {
	if (st > en) return 0;
	if (Lazy[id][node] != 0) {
		Tree[id][node] += (en - st + 1) * Lazy[id][node];
		if (st != en) {
			Lazy[id][node*2+0] += Lazy[id][node];
			Lazy[id][node*2+1] += Lazy[id][node];
		}
		Lazy[id][node] = 0;
	}
	if (R < st || en < L) return 0;
	if (L <= st && en <= R) return Tree[id][node];
	i64 p1 = Get(id, node*2, st, (st+en)/2, L, R);
	i64 p2 = Get(id, node*2+1, (st+en)/2+1, en, L, R);
	return (p1 + p2);
}

i64 seekPos(i64 p, char c) {
	i64 top = 0, bot = n*k-1, res = -1;
	i64 id = c - 'a';
	while (top <= bot) {
		i64 mid = (top + bot) / 2;
		if (Get(id, 1, 0, n*k-1, mid, mid) >= p) {
			res = mid; bot = mid - 1;
		}
		else top = mid + 1;
	}
	return res;
}

void Input() {
	cin >> k >> s >> q; n = s.size(); deleted.rsz(n*k, false);
	Tree.rsz(26, vi(n*k*4, 0)); Lazy.rsz(26, vi(n*k*4, 0));
}

void Solve() {
	for (i64 i=0; i<n; i++) {
		i64 id = s[i] - 'a';
		for (i64 j=0; j<k; j++) {
			Update(id, 1, 0, n*k-1, i+j*n, n*k-1, +1);
		}
	}
	while (q--) {
		i64 p; char c; cin >> p >> c;
		i64 pos = seekPos(p, c), id = c - 'a';
		deleted[pos] = true; Update(id, 1, 0, n*k-1, pos, n*k-1, -1);
	}
	for (i64 i=0; i<n*k; i++) if (!deleted[i]) cout << s[i % n];
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


