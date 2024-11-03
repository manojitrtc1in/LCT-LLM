
 



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



i64 n, m, q; vector<vi> Queries, adj; vi ans;



void DFS(i64 z, vector<vb> &Mat, vi &cnt, vi &flipped, i64 &res) {
	ans[z] = res;
	if (z < q) {
		vi Quer = Queries[z];
		i64 id = Quer[0];
		if (id < 4) {
			i64 PreviousIJ = -1;
			if (id <= 2) {
				i64 i = Quer[1], j = Quer[2];
				i64 oldval = Mat[i][j]; cnt[i] -= oldval;
				PreviousIJ = oldval;
				if (flipped[i]) oldval = 1 - oldval;
				res -= oldval; Mat[i][j] = flipped[i];
				if (id == 1) {
					Mat[i][j] = flipped[i] ^ 1;
					res++; cnt[i] += Mat[i][j];
				}
				else {
					Mat[i][j] = flipped[i];
					cnt[i] += Mat[i][j];
				}
			}
			else {
				i64 i = Quer[1];
				if (!flipped[i]) {res -= cnt[i]; res += (m - cnt[i]);}
				else {res += cnt[i]; res -= (m - cnt[i]);}
				flipped[i] ^= 1;
			}
			DFS(z+1, Mat, cnt, flipped, res);
			if (id <= 2) {
				i64 i = Quer[1], j = Quer[2];
				i64 oldval = Mat[i][j]; cnt[i] -= oldval;
				if (flipped[i]) oldval = 1 - oldval;
				res -= oldval; Mat[i][j] = flipped[i];
				Mat[i][j] = PreviousIJ;
				cnt[i] += PreviousIJ;
				res += PreviousIJ ^ flipped[i];
			}
			else {
				i64 i = Quer[1];
				if (!flipped[i]) {res -= cnt[i]; res += (m - cnt[i]);}
				else {res += cnt[i]; res -= (m - cnt[i]);}
				flipped[i] ^= 1;
			}
		}
	}
	for (auto t: adj[z]) {
		if (t < q) DFS(t, Mat, cnt, flipped, res);
		else ans[t] = res;
	}
}

void Input() {
	cin >> n >> m >> q; adj.rsz(q+1);
	Queries.rsz(q, vi(1)); ans.rsz(q+1, -1);
	for (i64 x=0; x<q; x++) {
		cin >> Queries[x][0];
		if (Queries[x][0] <= 2) {
			i64 i, j; cin >> i >> j; i--; j--;
			Queries[x].pub(i); Queries[x].pub(j);
		}
		else {
			i64 z; cin >> z;
			if (Queries[x][0] == 3) z--;
			Queries[x].pub(z);
		}
		if (Queries[x][0] == 4) {
			i64 y = Queries[x][1];
			if (y < x+1) adj[y].pub(x+1);
		}
	}
	vector<vb> Mat(n, vb(m, false)); vi cnt(n, 0), flipped(n, 0); i64 res = 0;
	DFS(0, Mat, cnt, flipped, res);
	for (i64 i=1; i<=q; i++) cout << ans[i] << endl;
}

void Solve() {
	
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


