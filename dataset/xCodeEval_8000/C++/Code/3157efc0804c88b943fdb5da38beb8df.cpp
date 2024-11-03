


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



#undef Interactive 


void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();
string cppstr_infile = "FILE.IN";
string cppstr_outfile = "FILE.OUT";



vi x(4), y(4), a(4), b(4);
vector<vi> vx(4, vi(4)); vector<vi> vy(4, vi(4));



bool isSquare(set<pii> Points) {
	vector<pii> A; vi Perm;
	for (auto it=Points.begin(); it!=Points.end(); it++) A.pub(*it);
	for (i64 i=0; i<4; i++) Perm.pub(i);
	do {
		vector<pii> vec; bool flag = true;
		for (i64 i=0; i<4; i++) {
			vec.pub(mp(A[Perm[(i+1)%4]].fi - A[Perm[i]].fi, A[Perm[(i+1)%4]].se - A[Perm[i]].se));
			if (i == 1 && vec[0].fi * vec[1].fi + vec[0].se * vec[1].se != 0) {flag = false;}
			if (i > 1 && (vec[i].fi != -vec[i-2].fi || vec[i].se != -vec[i-2].se)) {flag = false;}
		}
		if (vec[0].fi * vec[0].fi + vec[0].se * vec[0].se != vec[1].fi * vec[1].fi + vec[1].se * vec[1].se) flag = false;
		if (flag) return true;
	} while (next_permutation(Perm.begin(), Perm.end()));
	return false;
}

void Input() {
	x.clear(); y.clear(); a.clear(); b.clear();
	x.rsz(4); y.rsz(4); a.rsz(4); b.rsz(4);
	vx.clear(); vy.clear(); vx.rsz(4, vi(4)); vy.rsz(4, vi(4));
	for (i64 i=0; i<4; i++) {
		cin >> x[i] >> y[i] >> a[i] >> b[i];
		vx[i][0] = x[i] - a[i]; vy[i][0] = y[i] - b[i];
		for (i64 j=1; j<4; j++) {
			vx[i][j] = -vy[i][j-1]; vy[i][j] = vx[i][j-1];
		}
	}
}

void Solve() {
	i64 ans = LINF;
	for (i64 i=0; i<4; i++) {
		for (i64 j=0; j<4; j++) {
			for (i64 k=0; k<4; k++) {
				for (i64 l=0; l<4; l++) {
					set<pii> Set;
					Set.insert(mp(a[0]+vx[0][i], b[0]+vy[0][i]));
					Set.insert(mp(a[1]+vx[1][j], b[1]+vy[1][j]));
					Set.insert(mp(a[2]+vx[2][k], b[2]+vy[2][k]));
					Set.insert(mp(a[3]+vx[3][l], b[3]+vy[3][l]));
					if (Set.size() != 4) continue;
					if (isSquare(Set)) {
						ans = min(ans, i + j + k + l);
					}
				}
			}
		}
	}
	if (ans == LINF) cout << "-1\n";
	else cout << ans << endl;
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


