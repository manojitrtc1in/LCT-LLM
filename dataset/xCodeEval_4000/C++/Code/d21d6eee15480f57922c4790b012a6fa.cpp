
 



#pragma GCC optimize("Ofast")



#include <bits/stdc++.h>
using namespace std;



#define y0 withindarkness
#define y1 apinklotusbloomed
#define yn carryingapurplesoul
#define j1 togetherformingtheTeam



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
const long long Mod = 2100003221LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
long long keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
long long keyCount = sizeof(keymod) / sizeof(long long);
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());



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



string ot, rt, sb, se; i64 n; map<pii, i64> Map;
vi HashValue, PowBase, InvPow; i64 Base = 29;



vi Z_Algo(string S) {
	vi z(S.size()); i64 x = 0, y = 0;
	for (i64 i=1; i<S.size(); i++) {
		z[i] = max(0LL, min(z[i-x], y-i+1));
		while (i+z[i] < S.size() && S[z[i]] == S[i+z[i]]) {
			x = i; y = i + z[i]; z[i]++;
		}
	}
	return z;
}

vi stringMatching(string str, string target) {
	i64 N = str.size(), M = target.size();
	string Token = target; Token += '#'; Token += str;
	vi Z = Z_Algo(Token), List(0);
	for (i64 i=M+1; i<Z.size(); i++) {
		if (Z[i] == M) List.pub(i-M-1);
	}
	return List;
}

i64 modPow(i64 a, i64 b) {
	i64 res = 1;
	while (b > 0) {
		if (b % 2) {res *= a; res %= Mod; b--;}
		else {a *= a; a %= Mod; b /= 2;}
	}
	return res;
}

void PreprocessHashing() {
	HashValue.rsz(n, (ot[0] - 'a'));
	PowBase.rsz(n, 1); InvPow.rsz(n, 1);
	i64 Inv = modPow(Base, Mod-2);
	for (i64 i=1; i<n; i++) PowBase[i] = (PowBase[i-1] * Base) % Mod;
	for (i64 i=1; i<n; i++) InvPow[i] = (InvPow[i-1] * Inv) % Mod;
	for (i64 i=1; i<n; i++) HashValue[i] = (HashValue[i-1] + PowBase[i] * (ot[i] - 'a')) % Mod;
}

i64 HashVal(i64 L, i64 R) {
	i64 res = HashValue[R];
	if (L > 0) {res -= HashValue[L-1]; res %= Mod; if (res < 0) res += Mod;}
	res *= InvPow[L]; res %= Mod; return res;
}

void Input() {
	cin >> ot >> sb >> se; n = ot.size();
	rt = ot; reverse(rt.begin(), rt.end());
	reverse(se.begin(), se.end());
}

void Solve() {
	PreprocessHashing();
	vi ListPrefix = stringMatching(ot, sb);
	vi ListSuffix = stringMatching(rt, se);
	for (auto &z: ListSuffix) z = n - 1 - z;
	i64 ans = 0;
	for (auto i: ListPrefix) {
		for (auto j: ListSuffix) {
			i64 mi = sb.size(), mj = se.size();
			if (i + mi - 1 > j) continue;
			if (j - mj + 1 < i) continue;
			Map[mp(j-i+1, HashVal(i, j))]++;
		}
	}
	cout << Map.size() << endl;
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


