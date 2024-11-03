


#pragma comment(linker, "/stack:225450978")
#pragma GCC optimize("Ofast")



#include <bits/stdc++.h>
using namespace std;



#define endl '\n'
#define i64 int
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



i64 n; string s1, s2;





void Input() {
	cin >> n >> s1 >> s2;
}

void Solve() {
	i64 cnt1_11 = 0, cnt2_11 = 0;
	i64 cnt1_10 = 0, cnt2_10 = 0;
	i64 cnt1_01 = 0, cnt2_01 = 0;
	i64 cnt1_00 = 0, cnt2_00 = 0;
	for (i64 i=0; i<n*2; i++) {
		string d12 = "", d21 = "";
		d12 += s1[i]; d12 += s2[i];
		d21 += s2[i]; d21 += s1[i];
		cnt1_11 += (d12 == "11"); cnt2_11 += (d21 == "11");
		cnt1_10 += (d12 == "10"); cnt2_10 += (d21 == "10");
		cnt1_01 += (d12 == "01"); cnt2_01 += (d21 == "01");
		cnt1_00 += (d12 == "00"); cnt2_00 += (d21 == "00");
	}
	i64 turn = 1, Ichi1 = 0, Ichi2 = 0;
	while (cnt1_11 > 0 || cnt1_10 > 0 || cnt1_01 > 0 || cnt1_00 > 0) {
		if (turn == 1) {
			if (cnt1_11) {cnt1_11--; cnt2_11--; Ichi1++;}
			else if (cnt1_10) {cnt1_10--; cnt2_01--; Ichi1++;}
			else if (cnt1_01) {cnt1_01--; cnt2_10--;}
			else {cnt1_00--; cnt2_00--;}
		}
		else if (turn == 2) {
			if (cnt2_11) {cnt2_11--; cnt1_11--; Ichi2++;}
			else if (cnt2_10) {cnt2_10--; cnt1_01--; Ichi2++;}
			else if (cnt2_01) {cnt2_01--; cnt1_10--;}
			else {cnt2_00--; cnt1_00--;}
		}
		turn = 3 - turn;
	}
	if (Ichi1 > Ichi2) cout << "First";
	else if (Ichi1 < Ichi2) cout << "Second";
	else cout << "Draw";
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


