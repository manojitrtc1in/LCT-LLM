




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



i64 n, x, y, a; vector<ppi> A;
vi dp, slope, coeff; vector<ppi> Stack; i64 Size = 0;



i64 f(pii Func, i64 x) {
	i64 a = Func.fi, b = Func.se;
	return (a * x + b);
}

i64 binsearch(i64 x) {
	i64 top = 0, bot = Size-1, ans = Size-1;
	while (top <= bot) {
		i64 mid = (top + bot) / 2;
		i64 L = Stack[mid].fi.fi, R = Stack[mid].fi.se;
		if (L <= x && x <= R) return Stack[mid].se;
		if (R < x) bot = mid - 1;
		else top = mid + 1;
	}
	return Stack[ans].se;
}

void UpdateStack(i64 id) {
	while (Size > 0) {
		i64 Topxl = Stack[Size-1].fi.fi, Topxr = Stack[Size-1].fi.se, TopID = Stack[Size-1].se;
		if (f(mp(slope[TopID], coeff[TopID]), Topxr) <= f(mp(slope[id], coeff[id]), Topxr)) {Size--; continue;}
		i64 top = -INF*3, bot = Topxr, res = Topxl;
		while (top <= bot) {
			i64 mid = (top + bot) / 2;
			if (f(mp(slope[TopID], coeff[TopID]), mid) < f(mp(slope[id], coeff[id]), mid)) {
				res = mid; top = mid + 1;
			}
			else bot = mid - 1;
		}
		Stack[Size-1].fi.fi = min(res + 1, INF*3); break;
	}
	if (Size == 0) {Stack[Size++] = mp(mp(-INF*3, +INF*3), id); return;}
	Stack[Size] = mp(mp(-INF*3, Stack[Size-1].fi.fi-1), id); Size++;
}

void Input() {
	cin >> n; A.rsz(n);
	for (auto &Rect: A) {
		cin >> x >> y >> a;
		Rect = mp(mp(x, y), a);
	}
}

void Solve() {
	sort(A.begin(), A.end());
	dp.rsz(n, 0); slope.rsz(n); coeff.rsz(n);
	dp[0] = A[0].fi.fi * A[0].fi.se - A[0].se;
	slope[0] = -A[0].fi.fi; coeff[0] = dp[0];
	Stack.rsz(n); Size = 1; Stack[0] = mp(mp(-INF*3, +INF*3), 0);
	for (i64 i=1; i<n; i++) {




		i64 id = binsearch(A[i].fi.se);
		dp[i] = max(f(mp(slope[id], coeff[id]), A[i].fi.se), 0LL);
		dp[i] += A[i].fi.fi * A[i].fi.se - A[i].se;
		slope[i] = -A[i].fi.fi; coeff[i] = dp[i];
		UpdateStack(i);
	}


	cout << *max_element(dp.begin(), dp.end());
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



