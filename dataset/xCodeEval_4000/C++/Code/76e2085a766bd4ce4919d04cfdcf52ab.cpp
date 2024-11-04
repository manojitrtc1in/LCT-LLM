


#pragma comment(linker, "/stack:225450978")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")



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

#undef OImode 

#undef MultiTest 


void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();



string s; i64 n; vs A;





void Input() {
	cin >> s; n = s.size();
}

void Solve() {
	vector<vb> vis2(26, vb(26, false));
	vector<vector<vb>> vis3(26, vector<vb>(26, vb(26, false)));
	vector<vector<vb>> dp2(n, vector<vb>(26, vb(26, false)));
	vector<vector<vector<vb>>> dp3(n, vector<vector<vb>>(26, vector<vb>(26, vb(26, false))));
	vi possiblePrefix(n, 0LL); possiblePrefix[n-1] = 1;
	for (i64 i=n-1; i>=0; i--) {
		if (!possiblePrefix[i]) continue;
		if (i - 2 >= 4) {
			i64 x = s[i-1] - 'a', y = s[i] - 'a';
			if (dp2[i][x][y] < possiblePrefix[i]) {
				possiblePrefix[i-2]++;
				vis2[x][y] = true;
				dp2[i-2][x][y] = true;
			}
		}
		if (i - 3 >= 4) {
			i64 x = s[i-2] - 'a', y = s[i-1] - 'a', z = s[i] - 'a';
			if (dp3[i][x][y][z] < possiblePrefix[i]) {
				possiblePrefix[i-3]++;
				vis3[x][y][z] = true;
				dp3[i-3][x][y][z] = true;
			}
		}
	}
	for (i64 i=0; i<26; i++) {
		for (i64 j=0; j<26; j++) {
			for (i64 k=0; k<26; k++) {
				if (!vis3[i][j][k]) continue;
				string str = "";
				str += char(97+i);
				str += char(97+j);
				str += char(97+k);
				A.pub(str);
			}
		}
	}
	for (i64 i=0; i<26; i++) {
		for (i64 j=0; j<26; j++) {
			if (!vis2[i][j]) continue;
			string str = "";
			str += char(97+i);
			str += char(97+j);
			A.pub(str);
		}
	}
	sort(A.begin(), A.end());
	cout << A.size() << endl;
	for (auto x: A) cout << x << endl;
}



int main(int argc, char* argv[]) {
	ControlIO(argc, argv);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
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


