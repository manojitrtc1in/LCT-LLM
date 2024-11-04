









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




i64 n, k; vector<vi> chain;



void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();



void Input() {
	cin >> n >> k; chain.rsz(k);
	for (i64 i=0; i<k; i++) {
		i64 m; cin >> m; chain[i].rsz(m);
		for (i64 j=0; j<m; j++) cin >> chain[i][j];
	}
}

void Solve() {
	sort(chain.begin(), chain.end()); i64 ans = 0;
	i64 id0 = LINF, id2 = -LINF, id1 = 0;
	for (i64 i=0; i<k; i++) {
		vi A = chain[i];
		i64 N = A.size(); id1 += N;
		id0 = min(id0, A[0]);
		id2 = max(id2, A[N-1]);
		if (i == 0) {
			i64 z = 0;
			while (z < N && A[z] == z+1) {
				z++; id0++; id1--;
			}
			ans += (N - z);
		}
		if (id2 - id0 + 1 != id1) {if (i>0) ans += (N - 1);}
		else {
			if (i > 0) ans += (N - 1);
			if (id0 > 1) ans += id1;
			else if (i > 0) ans += (id1 - 1);
			id0 = LINF; id2 = -LINF; id1 = 0;
		}
	}
	cout << ans;
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


































































































































































































































































