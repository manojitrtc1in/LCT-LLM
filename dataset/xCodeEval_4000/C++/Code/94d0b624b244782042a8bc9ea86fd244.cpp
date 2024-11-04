




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



i64 n, k; vs a; map<string, int> Map;



bool isVowel(char c) {
	if (c == 'a') return true;
	if (c == 'e') return true;
	if (c == 'i') return true;
	if (c == 'o') return true;
	if (c == 'u') return true;
	return false;
}

void Input() {
	cin >> n >> k; n *= 4; a.rsz(n);
	for (auto &x: a) cin >> x;
}

void Solve() {
	vs suffix(n); i64 id = 0;
	for (auto str: a) {
		i64 i = str.size() - 1, cnt = 0;
		while (i >= 0 && cnt < k) {
			if (isVowel(str[i])) cnt++;
			i = i - 1;
		}
		if (cnt < k) {cout << "NO"; return;}
		suffix[id] = str.substr(i+1); id++;
		Map[str.substr(i+1)] = Map.size() + 1;
	}
	bool aaaa = true, aabb = true, abab = true, abba = true;
	for (i64 i=0; i<n; i+=4) {
		if (suffix[i] != suffix[i+1]) {aaaa = false; break;}
		if (suffix[i+1] != suffix[i+2]) {aaaa = false; break;}
		if (suffix[i+2] != suffix[i+3]) {aaaa = false; break;}
	}
	for (i64 i=0; i<n; i+=4) {
		if (suffix[i] != suffix[i+1]) {aabb = false; break;}
		if (suffix[i+2] != suffix[i+3]) {aabb = false; break;}
	}
	for (i64 i=0; i<n; i+=4) {
		if (suffix[i] != suffix[i+2]) {abab = false; break;}
		if (suffix[i+1] != suffix[i+3]) {abab = false; break;}
	}
	for (i64 i=0; i<n; i+=4) {
		if (suffix[i] != suffix[i+3]) {abba = false; break;}
		if (suffix[i+1] != suffix[i+2]) {abba = false; break;}
	}
	if (aaaa) {cout << "aaaa\n"; return;}
	if (aabb) {cout << "aabb\n"; return;}
	if (abab) {cout << "abab\n"; return;}
	if (abba) {cout << "abba\n"; return;}
	cout << "NO\n";
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



