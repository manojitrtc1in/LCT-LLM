


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



i64 n; vi x, y;





void Input() {
	cin >> n; x.rsz(n); y.rsz(n);
	for (i64 i=0; i<n; i++) cin >> x[i] >> y[i];
}

void Solve() {
	i64 minx = *min_element(x.begin(), x.end());
	i64 maxx = *max_element(x.begin(), x.end());
	i64 miny = *min_element(y.begin(), y.end());
	i64 maxy = *max_element(y.begin(), y.end());
	i64 ymin_fromcritx = LINF, ymax_fromcritx = -LINF;
	i64 xmin_fromcrity = LINF, xmax_fromcrity = -LINF;
	pii MinX, MaxX, MinY, MaxY; vector<vs> Mask(n); i64 Init = 0;
	for (i64 i=0; i<n; i++) {
		if (x[i] == minx) {Mask[i].pub("minx"); MinX = mp(x[i], y[i]); ymin_fromcritx = min(ymin_fromcritx, y[i]); ymax_fromcritx = max(ymax_fromcritx, y[i]);}
		if (x[i] == maxx) {Mask[i].pub("maxx"); MaxX = mp(x[i], y[i]); Init = (i + 1) % n; ymin_fromcritx = min(ymin_fromcritx, y[i]); ymax_fromcritx = max(ymax_fromcritx, y[i]);}
		if (y[i] == miny) {Mask[i].pub("miny"); MinY = mp(x[i], y[i]); xmin_fromcrity = min(xmin_fromcrity, x[i]); xmax_fromcrity = max(xmax_fromcrity, x[i]);}
		if (y[i] == maxy) {Mask[i].pub("maxy"); MaxY = mp(x[i], y[i]); xmin_fromcrity = min(xmin_fromcrity, x[i]); xmax_fromcrity = max(xmax_fromcrity, x[i]);}
	}
	bool filledby3 = false;
	for (i64 i=0; i<n; i++) {
		if (Mask[i].size() > 1) {
			filledby3 = true;
			break;
		}
	}
	if (filledby3) {
		for (i64 i=3; i<=n; i++) cout << (maxx - minx + maxy - miny) * 2 << " ";
		return;
	}
	i64 res3 = -LINF; string statex = "min", statey = "max";
	res3 = max(res3, (maxx - minx) * 2 + (maxy - ymin_fromcritx) * 2);
	res3 = max(res3, (maxx - minx) * 2 + (ymax_fromcritx - miny) * 2);
	res3 = max(res3, (maxy - miny) * 2 + (maxx - xmin_fromcrity) * 2);
	res3 = max(res3, (maxy - miny) * 2 + (xmax_fromcrity - minx) * 2);
	for (i64 z=Init; z<Init+n; z++) {
		i64 i = z % n;
		if (!Mask[i].empty()) {
			if (statex == "min" && statey == "max") statex = "max";
			else if (statex == "max" && statey == "max") statey = "min";
			else if (statex == "max" && statey == "min") statex = "min";
			else if (statex == "min" && statey == "min") statey = "max";
			continue;
		}
		if (statex == "min" && statey == "max") res3 = max(res3, ((max(MaxY.fi, x[i]) - minx)) * 2 + (maxy - min(MinX.se, y[i])) * 2);
		else if (statex == "max" && statey == "max") res3 = max(res3, ((maxx - min(MaxY.fi, x[i]))) * 2 + (maxy - min(MinX.se, y[i])) * 2);
		else if (statex == "max" && statey == "min") res3 = max(res3, ((maxx - min(MaxY.fi, x[i]))) * 2 + (max(MinX.se, y[i]) - miny) * 2);
		else if (statex == "min" && statey == "min") res3 = max(res3, ((max(MaxY.fi, x[i]) - minx)) * 2 + (max(MinX.se, y[i]) - miny) * 2);
	}
	cout << res3 << " ";
	for (i64 i=4; i<=n; i++) cout << (maxx - minx + maxy - miny) * 2 << " ";
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


