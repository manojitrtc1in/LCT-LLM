


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



i64 m, h1, a1, x1, y1, h2, a2, x2, y2; vi vis1, vis2;





void Input() {
	cin >> m >> h1 >> a1 >> x1 >> y1;
	cin >> h2 >> a2 >> x2 >> y2;
	vis1.rsz(m, -1); vis2.rsz(m, -1);
}

void Solve() {
	vis1[h1] = 0;
	i64 cycleStart1 = -1, cycleLen1 = -1;
	while (true) {
		i64 z = (h1 * x1 + y1) % m;
		if (vis1[z] != -1) {
			cycleStart1 = vis1[z];
			cycleLen1 = (vis1[h1] + 1) - vis1[z];
			break;
		}
		else vis1[z] = vis1[h1] + 1;
		h1 = z;
	}
	vis2[h2] = 0;
	i64 cycleStart2 = -1, cycleLen2 = -1;
	while (true) {
		i64 z = (h2 * x2 + y2) % m;
		if (vis2[z] != -1) {
			cycleStart2 = vis2[z];
			cycleLen2 = (vis2[h2] + 1) - vis2[z];
			break;
		}
		else vis2[z] = vis2[h2] + 1;
		h2 = z;
	}
	if (vis1[a1] == -1 || vis2[a2] == -1) {cout << "-1"; return;}
	if (vis1[a1] < cycleStart1 && vis2[a2] < cycleStart2) {
		if (vis1[a1] == vis2[a2]) cout << vis1[a1];
		else cout << "-1"; return;
	}
	if (vis1[a1] >= cycleStart1 && vis2[a2] >= cycleStart2) {
		i64 ans = -1;
		for (i64 i=0; i<=1000000; i++) {
			i64 expected = vis1[a1] + cycleLen1 * i;
			if ((expected - vis2[a2]) % cycleLen2 == 0 && (expected - vis2[a2]) / cycleLen2 >= 0) {
				ans = expected; break;
			}
		}
		cout << ans; return;
	}
	if (vis1[a1] < cycleStart1 && vis2[a2] >= cycleStart2) {
		if ((vis1[a1] - vis2[a2]) % cycleLen2 == 0 && (vis1[a1] - vis2[a2]) / cycleLen2 >= 0) cout << vis1[a1];
		else cout << "-1"; return;
	}
	if (vis1[a1] >= cycleStart1 && vis2[a2] < cycleStart2) {
		if ((vis2[a2] - vis1[a1]) % cycleLen1 == 0 && (vis2[a2] - vis1[a1]) / cycleLen1 >= 0) cout << vis2[a2];
		else cout << "-1"; return;
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


