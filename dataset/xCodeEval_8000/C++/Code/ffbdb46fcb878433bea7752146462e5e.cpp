


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



i64 n, offset; vector<vc> A, A2, R; vector<pii> Pieces;





void Input() {
	cin >> n; offset = n - 1;
	A.rsz(n, vc(n, '.')); A2.rsz(n, vc(n, '.'));
	R.rsz(offset*2+1, vc(offset*2+1, '.'));
	R[offset][offset] = 'o';
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<n; j++) {
			cin >> A[i][j];
			if (A[i][j] == 'o') {
				Pieces.pub(mp(i, j));
				A2[i][j] = 'o';
			}
		}
	}
}

void Solve() {
	vector<pii> Dir;
	for (i64 x=-offset; x<=offset; x++) {
		for (i64 y=-offset; y<=offset; y++) {
			if (x == 0 && y == 0) continue;
			i64 cnt = 0, outbound = 0;
			for (auto z: Pieces) {
				i64 i = z.fi, j = z.se;
				if (i+x < 0 || i+x >= n || j+y < 0 || j+y >= n) {
					outbound++; continue;
				}
				if (A[i+x][j+y] != '.') cnt++;
			}
			if (cnt + outbound != Pieces.size()) continue;
			R[x+offset][y+offset] = 'x'; Dir.pub(mp(x, y));
		}
	}
	for (auto z: Pieces) {
		i64 i = z.fi, j = z.se;
		for (auto z1: Dir) {
			i64 x = z1.fi, y = z1.se;
			if (i+x >= 0 && i+x < n && j+y >= 0 && j+y < n && A[i+x][j+y] != 'o') {
				A2[i+x][j+y] = 'x';
			}
		}
	}
	if (A2 != A) {cout << "NO"; return;}
	cout << "YES\n";
	for (auto r: R) {
		for (auto z: r) {
			cout << z;
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
	#ifdef Akikaze
	time_t t = time(0);
	tm* now = localtime(&t);
	cout << "Source code by #Team4T-Akikaze.\n";
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
	#elif OImode
	freopen("FILENAME.INP", "r", stdin);
	freopen("FILENAME.OUT", "w", stdout);
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


