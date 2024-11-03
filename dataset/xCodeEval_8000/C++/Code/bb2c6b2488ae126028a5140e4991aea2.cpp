




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



i64 n, s; vi Min, Max;





void Input() {
	cin >> n >> s;
	Min.rsz(n); Max.rsz(n);
	for (i64 i=1; i<n; i++) {
		i64 Max_LeafLevel = (n - i) + 1;
		Max[i] = (n - i + 1) * (n - i) / 2;
		Max[i] += Max_LeafLevel * i;
		if (i == 1) {Min[i] = Max[i]; continue;}
		i64 LevelCount = 1, TotalCount = 0, Level = 1;
		while (TotalCount < n) {
			i64 picked = min(LevelCount, n - TotalCount);
			Min[i] += Level * picked;
			LevelCount *= i; Level++; TotalCount += picked;
		}
	}
}

void Solve() {
	vi p(n, -1), children(n, 0), lvl(n, 0); i64 coef = 1;
	for (; coef < n; coef++) {
		if (Min[coef] <= s && s <= Max[coef]) break;
	}
	if (coef == n) {cout << "No\n"; return;}
	priority_queue<pii> Heap;
	set<pii> Available; lvl[0] = 1;
	for (i64 i=1; i<n-coef; i++) {
		p[i] = i - 1;
		children[i-1]++;
		lvl[i] = i + 1;
		Available.insert(mp(i, i-1));
	}
	for (i64 i=n-coef; i<n; i++) {
		p[i] = n-coef-1;
		lvl[i] = n-coef+1;
		children[n-coef-1]++;
		Heap.push(mp(n-coef+1, i));
		Available.insert(mp(n-coef+1, i));
	}
	i64 cursum = Max[coef];
	while (cursum > s) {
		i64 toMoveUpID = Heap.top().se;
		i64 toMoveUpLvl = Heap.top().fi;
		i64 toReceiveID = Available.begin()->se;
		i64 toReceiveLvl = Available.begin()->fi;
		if (cursum - (toMoveUpLvl - (toReceiveLvl + 1)) <= s) {
			for (auto it=Available.begin(); it!=Available.end(); it++) {
				toReceiveID = it->se; toReceiveLvl = it->fi;
				if (cursum - (toMoveUpLvl - (toReceiveLvl + 1)) == s) break;
			}
		}
		Heap.pop(); children[p[toMoveUpID]]--; Available.erase(mp(toMoveUpLvl, toMoveUpID));
		if (children[p[toMoveUpID]] == coef-1) Available.insert(mp(lvl[p[toMoveUpID]], p[toMoveUpID]));
		if (children[p[toMoveUpID]] == 0) Heap.push(mp(lvl[p[toMoveUpID]], p[toMoveUpID]));
		p[toMoveUpID] = toReceiveID; children[toReceiveID]++; lvl[toMoveUpID] = toReceiveLvl + 1;
		cursum -= (toMoveUpLvl - (toReceiveLvl + 1));
		if (children[toReceiveID] == coef) Available.erase(mp(lvl[toReceiveID], toReceiveID));
		Heap.push(mp(lvl[toMoveUpID], toMoveUpID)); Available.insert(mp(lvl[toMoveUpID], toMoveUpID));
	}
	cout << "Yes\n";
	for (i64 i=1; i<n; i++) cout << p[i] + 1 << " "; cout << endl;
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



