








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
string id2 = "FILE.IN";
string id7 = "FILE.OUT";



i64 n, q, l, r; vi p, d, Log2;
vector<vi> adj, Table, id4;



void DFS(i64 z, i64 last) {
	if (z != 0) d[z] = d[last] + 1;
	for (auto t: adj[z]) {
		if (t == last) continue;
		DFS(t, z); Table[t].pub(z);
	}
}

void id10() {
	Table.rsz(n); d.rsz(n, 0); DFS(0, -1);
	for (i64 j=1; j<17; j++) {
		for (i64 i=0; i<n; i++) {
			if (Table[i].size() < j) continue;
			if (Table[Table[i][j-1]].size() < j) continue;
			Table[i].pub(Table[Table[i][j-1]][j-1]);
		}
	}
}

i64 LCA(i64 x, i64 y) {
	if (x == y) return x;
	if (d[x] == d[y]) {
		i64 id = 0, Init = min(Table[x].size(), Table[y].size()-1);
		for (i64 i=Init; i>=0; i--) {
			if (Table[x][i] != Table[y][i]) {id = i; break;}
		}
		return LCA(Table[x][id], Table[y][id]);
	}
	if (d[x] < d[y]) {
		i64 mul = 1, id = 0;
		while (d[x] < d[y] - mul * 2) {
			mul *= 2; id++;
		}
		return LCA(x, Table[y][id]);
	}
	if (d[x] > d[y]) {
		i64 mul = 1, id = 0;
		while (d[y] < d[x] - mul * 2) {
			mul *= 2; id++;
		}
		return LCA(Table[x][id], y);
	}
}

void id3() {
	id4.rsz(n);
	for (i64 i=0; i<n; i++) id4[i].pub(i);
	for (i64 j=1; j<17; j++) {
		for (i64 i=0; i<n; i++) {
			if (id4[i].size() < j) continue;
			if (i + (1LL << (j - 1)) >= n) continue;
			if (id4[i+(1LL << (j-1))].size() < j) continue;
			id4[i].pub(LCA(id4[i][j-1], id4[i+(1LL << (j-1))][j-1]));
		}
	}
}

i64 id5(i64 L, i64 R) {
	i64 x = log2(R - L + 1);
	return LCA(id4[L][x], id4[R-(1LL<<x)+1][x]);
}

i64 id1(i64 L, i64 R, i64 Anc) {
	i64 top = L, bot = R, ans = L;
	while (top <= bot) {
		i64 mid = (top + bot) / 2;
		if (id5(L, mid) == Anc) {
			ans = mid; bot = mid - 1;
		}
		else top = mid + 1;
	}
	return ans;
}

i64 id6(i64 L, i64 R, i64 Anc) {
	i64 top = L, bot = R, ans = R;
	while (top <= bot) {
		i64 mid = (top + bot) / 2;
		if (id5(mid, R) == Anc) {
			ans = mid; top = mid + 1;
		}
		else bot = mid - 1;
	}
	return ans;
}

i64 ProceedAnswer(i64 L, i64 R, i64 x) {
	if (L < x && x < R) return LCA(id5(L, x-1), id5(x+1, R));
	if (L == x) return id5(x+1, R); return id5(L, x-1);
}

void Input() {
	cin >> n >> q; p.rsz(n, -1); adj.rsz(n);
	for (i64 i=1; i<n; i++) {
		cin >> p[i]; p[i]--;
		adj[p[i]].pub(i); adj[i].pub(p[i]);
	}
}

void Solve() {
	id10(); id3();
	while (q--) {
		cin >> l >> r; l--; r--; i64 id9 = id5(l, r);
		i64 l1 = id1(l, r, id9), r1 = id6(l, r, id9);
		i64 id8 = ProceedAnswer(l, r, l1), id0 = ProceedAnswer(l, r, r1);
		if (d[id8] > d[id0]) cout << l1+1 << " " << d[id8] << endl;
		else cout << r1+1 << " " << d[id0] << endl;
	}
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
	char* infile = new char[id2.size()+1];
	char* outfile = new char[id7.size()+1];
	strcpy(infile, id2.c_str());
	strcpy(outfile, id7.c_str());
	
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


