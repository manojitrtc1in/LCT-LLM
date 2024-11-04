


#pragma comment(linker, "/stack:225450978")
#pragma GCC optimize("Ofast")



#include <bits/stdc++.h>
using namespace std;



#define endl '\n'
#define i64 long long
#define ld long double
#define rsz resize
#define pub push_back
#define mp make_pair
#define fi first
#define se second
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
#define OImode 227420978
#define MultiTest 227420978
#define Interactive 227420978

#undef OImode 

#undef MultiTest 

#undef Interactive 


void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();
string cppstr_infile = "FILE.IN";
string cppstr_outfile = "FILE.OUT";



i64 n, q, l, r; vi p, d, Log2;
vector<vi> adj, Table, TableLCA;



void DFS(i64 z, i64 last) {
	if (z != 0) d[z] = d[last] + 1;
	for (auto t: adj[z]) {
		if (t == last) continue;
		DFS(t, z); Table[t].pub(z);
	}
}

void PreprocessNormal() {
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

void PreprocessTableLCA() {
	TableLCA.rsz(n);
	for (i64 i=0; i<n; i++) TableLCA[i].pub(i);
	for (i64 j=1; j<17; j++) {
		for (i64 i=0; i<n; i++) {
			if (TableLCA[i].size() < j) continue;
			if (i + (1LL << (j - 1)) >= n) continue;
			if (TableLCA[i+(1LL << (j-1))].size() < j) continue;
			TableLCA[i].pub(LCA(TableLCA[i][j-1], TableLCA[i+(1LL << (j-1))][j-1]));
		}
	}
}

i64 LCASegment(i64 L, i64 R) {
	i64 x = log2(R - L + 1);
	return LCA(TableLCA[L][x], TableLCA[R-(1LL<<x)+1][x]);
}

i64 binsearch_prefix(i64 L, i64 R, i64 Anc) {
	i64 top = L, bot = R, ans = L;
	while (top <= bot) {
		i64 mid = (top + bot) / 2;
		if (LCASegment(L, mid) == Anc) {
			ans = mid; bot = mid - 1;
		}
		else top = mid + 1;
	}
	return ans;
}

i64 binsearch_suffix(i64 L, i64 R, i64 Anc) {
	i64 top = L, bot = R, ans = R;
	while (top <= bot) {
		i64 mid = (top + bot) / 2;
		if (LCASegment(mid, R) == Anc) {
			ans = mid; top = mid + 1;
		}
		else bot = mid - 1;
	}
	return ans;
}

void Input() {
	cin >> n >> q; p.rsz(n, -1); adj.rsz(n);
	for (i64 i=1; i<n; i++) {
		cin >> p[i]; p[i]--;
		adj[p[i]].pub(i); adj[i].pub(p[i]);
	}
}

void Solve() {
	PreprocessNormal(); PreprocessTableLCA();
	while (q--) {
		cin >> l >> r; l--; r--;
		i64 TotalLCA = LCASegment(l, r);
		i64 l1 = binsearch_prefix(l, r, TotalLCA);
		i64 r1 = binsearch_suffix(l, r, TotalLCA);
		i64 LCA_l1 = -1, LCA_r1 = -1;
		if (l < l1 && l1 < r) LCA_l1 = LCA(LCASegment(l, l1-1), LCASegment(l1+1, r));
		else if (l == l1) LCA_l1 = LCASegment(l1+1, r);
		else if (l1 == r) LCA_l1 = LCASegment(l, l1-1);
		if (l < r1 && r1 < r) LCA_r1 = LCA(LCASegment(l, r1-1), LCASegment(r1+1, r));
		else if (l == r1) LCA_r1 = LCASegment(r1+1, r);
		else if (r1 == r) LCA_r1 = LCASegment(l, r1-1);
		if (d[LCA_l1] > d[LCA_r1]) cout << l1+1 << " " << d[LCA_l1] << endl;
		else cout << r1+1 << " " << d[LCA_r1] << endl;
	}
}



int main(int argc, char* argv[]) {
	ControlIO(argc, argv);

	#ifndef Interactive
		ios_base::sync_with_stdio(0); cin.tie(NULL);
	#else
		ios_base::sync_with_stdio(0);
	#endif
	
	#ifndef MultiTest
		Input(); TimerStart();
		Solve(); TimerStop();
	#else
		int T; cin >> T; TimerStart();
		while(T--) {Input(); Solve();}
		TimerStop();
	#endif

	return 0;
}



void ControlIO(int argc, char* argv[]) {
	char* infile = new char[cppstr_infile.size()+1];
	char* outfile = new char[cppstr_outfile.size()+1];
	strcpy(infile, cppstr_infile.c_str());
	strcpy(outfile, cppstr_outfile.c_str());
	#ifdef Akikaze
		time_t t = time(0);
		tm* now = localtime(&t);
		cout << "Source code by #Team4T-Akikaze.\n";
		cout << "Current time: ";
		cout << (now->tm_year + 1900) << '-' 
			 << ((now->tm_mon < 9) ? "0" : "") << (now->tm_mon + 1) << '-'
			 << ((now->tm_mday < 10) ? "0" : "") <<  now->tm_mday << " | "
			 << ((now->tm_hour < 10) ? "0" : "") <<  now->tm_hour << ":"
			 << ((now->tm_min < 10) ? "0" : "") <<  now->tm_min << ":"
			 << ((now->tm_sec < 10) ? "0" : "") <<  now->tm_sec
			 << "\n\n";
		
		#ifdef OImode
			cout << "OI-Mode: ON\n";
			cout << "Input file: " << infile << endl;
			cout << "Output file: " << outfile << endl;
			cout << "\n";
		#else
			cout << "OI-Mode: OFF\n";
			cout << "Input file: NULL\n";
			cout << "Output file: NULL\n";
			cout << "\n";
		#endif
		
		#ifdef MultiTest
			cout << "MultiTest-Mode: ON\n";
		#else
			cout << "MultiTest-Mode: OFF\n";
		#endif
		
		#ifdef Interactive
			cout << "Interactive-Mode: ON\n\n";
		#else
			cout << "Interactive-Mode: OFF\n\n";
		#endif
		
		if (argc > 1) assert(freopen(argv[1], "r", stdin));
		if (argc > 2) assert(freopen(argv[2], "w", stdout));
	#elif OImode
		freopen(infile, "r", stdin);
		freopen(outfile, "w", stdout);
	#endif
}

void TimerStart() {
	#ifdef Akikaze
		TimeStart = chrono::steady_clock::now();
	#endif
}

void TimerStop() {
	#ifdef Akikaze
		TimeEnd = chrono::steady_clock::now();
		auto ElapsedTime = TimeEnd - TimeStart;
		cout << "\n\nTime elapsed: " << chrono::duration<double>(ElapsedTime).count() << " seconds.\n";
	#endif
}

void Exit() {
	TimerStop(); exit(0);
}


