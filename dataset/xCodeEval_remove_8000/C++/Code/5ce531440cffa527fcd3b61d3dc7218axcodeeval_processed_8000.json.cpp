









using namespace std;











typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9, GOLD = ((1+sqrt(5))/2);
i64 keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
vi HashMod(keymod, keymod + sizeof(keymod) / sizeof(i64));



template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }



auto TimeStart = chrono::steady_clock::now();
auto TimeEnd = chrono::steady_clock::now();




i64 n, x, y; vs label; vi p; vi A; vector<vi> adj;



void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();



void Input() {
	cin >> n; p.rsz(n, -1);
	A.rsz(n, 0); label.rsz(n);
	adj.rsz(n);
}

void Solve() {
	for (i64 i=0; i<n; i++) {
		cin >> label[i];
		if (label[i] == "IN") {cin >> A[i]; continue;}
		if (label[i] == "AND" || label[i] == "OR" || label[i] == "XOR") {
			cin >> x >> y; x--; y--;
			if (label[i] == "AND") A[i] = 1;
			adj[i].pub(x); adj[i].pub(y);
			p[x] = i; p[y] = i; continue;
		}
		if (label[i] == "NOT") {
			cin >> x; x--;
			adj[i].pub(x);
			p[x] = i; continue;
		}
	}
	queue<i64> Q; stack<i64> S; Q.push(0);
	while (!Q.empty()) {
		i64 z = Q.front(); Q.pop(); S.push(z);
		for (auto t: adj[z]) Q.push(t);
	}
	vector<vi> changed(n);
	while (!S.empty()) {
		i64 z = S.top(); S.pop();
		if (p[z] != -1) {
			if (label[p[z]] == "AND") {
				A[p[z]] = (A[p[z]] & A[z]);
			}
			else if (label[p[z]] == "OR") {
				A[p[z]] = (A[p[z]] | A[z]);
			}
			else if (label[p[z]] == "XOR") {
				A[p[z]] = (A[p[z]] ^ A[z]);
			}
			else if (label[p[z]] == "NOT") {
				A[p[z]] = 1 - A[z];
			}
		}
		if (adj[z].empty()) continue;
		if (label[z] == "AND") {
			if (A[z] == 1) {
				changed[z].pub(adj[z][0]);
				changed[z].pub(adj[z][1]);
			}
			else if (A[z] == 0 && (A[adj[z][0]] || A[adj[z][1]])) {
				if (!A[adj[z][0]]) changed[z].pub(adj[z][0]);
				if (!A[adj[z][1]]) changed[z].pub(adj[z][1]);
			}
		}
		else if (label[z] == "OR") {
			if (A[z] == 1 && (!A[adj[z][0]] || !A[adj[z][1]])) {
				if (A[adj[z][0]]) changed[z].pub(adj[z][0]);
				if (A[adj[z][1]]) changed[z].pub(adj[z][1]);
			}
			if (A[z] == 0) {
				changed[z].pub(adj[z][0]);
				changed[z].pub(adj[z][1]);
			}
		}
		else if (label[z] == "XOR") {
			changed[z].pub(adj[z][0]);
			changed[z].pub(adj[z][1]);
		}
		else if (label[z] == "NOT") changed[z].pub(adj[z][0]);
	}
	queue<i64> QQ; QQ.push(0LL);
	vb chosen(n, false); chosen[0] = true;
	while (!QQ.empty()) {
		i64 z = QQ.front(); QQ.pop();
		for (auto t: changed[z]) {
			QQ.push(t); chosen[t] = true;
		}
	}
	for (i64 i=1; i<n; i++) {
		if (chosen[i] && label[i] == "IN") cout << (1 - A[0]);
		else if (label[i] == "IN") cout << A[0];
	}
}



int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	ControlIO(argc, argv);
	Input(); TimerStart();
	Solve(); TimerStop();
	return 0;
}



void ControlIO(int argc, char* argv[]) {
	
	if (argc > 1) assert(freopen(argv[1], "r", stdin));
	if (argc > 2) assert(freopen(argv[2], "w", stdout));
	
	freopen("filename.inp", "r", stdin);
	freopen("filename.out", "w", stdout);
	
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



































































































































































































































































