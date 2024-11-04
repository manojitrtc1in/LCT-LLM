
 



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
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;
typedef pair<pii, int> ppi;
const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
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



int n, p; string s; vector<vector<int>> A;
vector<vector<int>> PrefixSum; vector<vector<int>> charList;



int RangeSum(int id, int L, int R) {
	int sum = PrefixSum[id][R];
	if (L > 0) sum -= PrefixSum[id][L-1];
	return sum;
}

int DFS(int z, vi &val, vb &checked, vb &allowed) {
	int res = val[z];
	checked[z] = true;
	for (int i=0; i<p; i++) {
		if (getbit(z, i)) continue;
		int newmask = z | (1 << i);
		if (!allowed[newmask]) continue;
		if (checked[newmask]) continue;
		res = min(res, DFS(newmask, val, checked, allowed));
	}
	return res;
}

void Spray(int z, int x, int y, vector<vector<vb>> &vis, vb &allowed) {
	vis[x][y][z] = true; vis[y][x][z] = true;
	allowed[z] = false;
	for (int i=0; i<p; i++) {
		if (i == x || i == y) continue;
		if (getbit(z, i)) continue;
		int newmask = z | (1 << i);
		if (vis[x][y][newmask]) continue;
		Spray(newmask, x, y, vis, allowed);
	}
}

void Input() {
	cin >> n >> p >> s; A.rsz(p, vector<int>(p));
	PrefixSum.rsz(p, vector<int>(n, 0)); charList.rsz(p);
	for (int i=0; i<p; i++) {
		for (int j=0; j<p; j++) {
			cin >> A[i][j];
		}
	}
	for (int i=0; i<n; i++) {
		int id = s[i] - 'a';
		charList[id].pub(i);
		PrefixSum[id][i]++;
	}
	for (int i=0; i<p; i++) {
		for (int j=1; j<n; j++) {
			PrefixSum[i][j] += PrefixSum[i][j-1];
		}
	}
}

void Solve() {
	vector<int> val(1 << p, n); vb allowed(1 << p, true);
	vector<vector<vb>> vis(p, vector<vb>(p, vb(1 << p, false)));
	for (int mask=0; mask<(1<<p); mask++) {
		for (int i=0; i<p; i++) {
			if (!getbit(mask, i)) continue;
			val[mask] -= charList[i].size();
		}
	}
	for (int i=0; i<p; i++) {
		for (int j=0; j<p; j++) {
			if (A[i][j]) continue;
			int ptr1 = 0, ptr2 = 0;
			while (ptr1 < charList[i].size()) {
				while (ptr2 < charList[j].size() && charList[i][ptr1] >= charList[j][ptr2]) ptr2++;
				if (ptr2 == charList[j].size()) break;
				while (ptr1+1 < charList[i].size() && charList[i][ptr1+1] < charList[j][ptr2]) ptr1++;
				if (ptr1 == charList[i].size()) break;
				int L = charList[i][ptr1], R = charList[j][ptr2];
				if (L + 1 >= R) {ptr1++; continue;}
				int mask = 0;
				for (int x=0; x<p; x++) {
					if (RangeSum(x, L+1, R-1) == 0) continue;
					mask |= (1 << x);
				}
				allowed[mask] = false; ptr1++;
				if (!vis[i][j][mask]) Spray(mask, i, j, vis, allowed);
			}
		}
	}
	vb checked(1 << p, false);
	cout << DFS(0, val, checked, allowed) << endl;
}



int main(int argc, char* argv[]) {
	ControlIO(argc, argv);

	#ifndef Interactive
		

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


