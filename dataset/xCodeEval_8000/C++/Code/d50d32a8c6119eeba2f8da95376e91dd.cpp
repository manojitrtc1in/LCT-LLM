


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



i64 n, m, S; vector<vi> A;
vector<set<i64>> adjSend, adjReceive;
vi DSUpar, DSUsize;



i64 linearid(i64 x, i64 y) {
	return (x * m + y);
}

pii extractCoor(i64 i) {
	i64 x = i / m;
	i64 y = i % m;
	return mp(x, y);
}

i64 DSUfind(i64 x) {
	while (DSUpar[x] != -1) x = DSUpar[x];
	return x;
}

void DSUmerge(i64 a, i64 b) {
	i64 x = DSUfind(a), y = DSUfind(b);
	if (x == y) return;
	if (DSUsize[x] < DSUsize[y]) swap(x, y);
	DSUsize[x] += DSUsize[y]; DSUpar[y] = x;
}

void Input() {
	cin >> n >> m; S = n * m;
	A.rsz(n, vi(m, 0)); adjSend.rsz(S);
	adjReceive.rsz(S);
	DSUpar.rsz(S, -1); DSUsize.rsz(S, +1);
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m; j++) {
			cin >> A[i][j];
		}
	}
}

void Solve() {
	for (i64 i=0; i<n; i++) {
		vector<pii> Tmp;
		for (i64 j=0; j<m; j++) {
			pii z = mp(A[i][j], 0LL);
			z.se = linearid(i, j);
			Tmp.pub(z);
		}
		sort(Tmp.begin(), Tmp.end());
		for (i64 X1=0; X1<m; X1++) {
			i64 Y1 = X1;
			while (Y1+1 < m && Tmp[Y1+1].fi == Tmp[X1].fi) {
				Y1++; DSUmerge(Tmp[X1].se, Tmp[Y1].se);
			}
			X1 = Y1;
		}
	}
	for (i64 j=0; j<m; j++) {
		vector<pii> Tmp;
		for (i64 i=0; i<n; i++) {
			pii z = mp(A[i][j], 0LL);
			z.se = linearid(i, j);
			Tmp.pub(z);
		}
		sort(Tmp.begin(), Tmp.end());
		for (i64 X1=0; X1<n; X1++) {
			i64 Y1 = X1;
			while (Y1+1 < n && Tmp[Y1+1].fi == Tmp[X1].fi) {
				Y1++; DSUmerge(Tmp[X1].se, Tmp[Y1].se);
			}
			X1 = Y1;
		}
	}
	for (i64 i=0; i<n; i++) {
		vector<pii> Tmp;
		for (i64 j=0; j<m; j++) {
			pii z = mp(A[i][j], 0LL);
			z.se = linearid(i, j);
			Tmp.pub(z);
		}
		sort(Tmp.begin(), Tmp.end());
		for (i64 X1=0; X1<m; X1++) {
			i64 Y1 = X1;
			while (Y1+1 < m && Tmp[Y1+1].fi == Tmp[X1].fi) Y1++;
			if (Y1 == m-1) break;
			adjSend[DSUfind(Tmp[X1].se)].insert(DSUfind(Tmp[Y1+1].se));
			adjReceive[DSUfind(Tmp[Y1+1].se)].insert(DSUfind(Tmp[X1].se));
			X1 = Y1;
		}
	}
	for (i64 j=0; j<m; j++) {
		vector<pii> Tmp;
		for (i64 i=0; i<n; i++) {
			pii z = mp(A[i][j], 0LL);
			z.se = linearid(i, j);
			Tmp.pub(z);
		}
		sort(Tmp.begin(), Tmp.end());
		for (i64 X1=0; X1<n; X1++) {
			i64 Y1 = X1;
			while (Y1+1 < n && Tmp[Y1+1].fi == Tmp[X1].fi) Y1++;
			if (Y1 == n-1) break;
			adjSend[DSUfind(Tmp[X1].se)].insert(DSUfind(Tmp[Y1+1].se));
			adjReceive[DSUfind(Tmp[Y1+1].se)].insert(DSUfind(Tmp[X1].se));
			X1 = Y1;
		}
	}
	vi Compressed(S, 1); vb vis(S, false);
	priority_queue<ppi> Q;
	for (i64 i=0; i<S; i++) {
		if (!adjReceive[i].empty()) continue;
		if (adjSend[i].empty()) continue;
		pii Coor = extractCoor(i);
		i64 x = Coor.fi, y = Coor.se;
		Q.push(mp(mp(Compressed[i], -A[x][y]), i));
	}
	while (!Q.empty()) {
		ppi Data = Q.top(); Q.pop();
		i64 comp = Data.fi.fi, id = Data.se;
		if (vis[id]) continue; vis[id] = true;
		for (auto it=adjSend[id].begin(); it!=adjSend[id].end(); it++) {
			i64 dest = *it; if (vis[dest]) continue;
			adjReceive[dest].erase(id); Compressed[dest] = max(Compressed[dest], comp+1);
			if (adjReceive[dest].empty()) {
				pii Coor = extractCoor(dest);
				i64 x = Coor.fi, y = Coor.se;
				Q.push(mp(mp(Compressed[dest], -A[x][y]), dest));
			}
		}
	}
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<m; j++) {
			cout << Compressed[DSUfind(linearid(i, j))] << " ";
		}
		cout << endl;
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


