


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



int n, m, t, l, r, x; int a[100000];
int Tree[20][400000], Lazy[20][400000];



void Update(int node, int st, int en, int d, int L, int R) {
	if (st > en) return;
	if (Lazy[d][node] > 0) {
		Tree[d][node] = (en - st + 1) - Tree[d][node];
		if (st != en) {
			Lazy[d][node*2+0] ^= 1;
			Lazy[d][node*2+1] ^= 1;
		}
		Lazy[d][node] = 0;
	}
	if (R < st || en < L) return;
	if (L <= st && en <= R) {
		Tree[d][node] = (en - st + 1) - Tree[d][node];
		if (st != en) {
			Lazy[d][node*2+0] ^= 1;
			Lazy[d][node*2+1] ^= 1;
		}
		return;
	}
	Update(node*2, st, (st+en)/2, d, L, R);
	Update(node*2+1, (st+en)/2+1, en, d, L, R);
	Tree[d][node] = Tree[d][node*2] + Tree[d][node*2+1];
}

int Get(int node, int st, int en, int d, int L, int R) {
	if (st > en) return 0;
	if (Lazy[d][node] > 0) {
		Tree[d][node] = (en - st + 1) - Tree[d][node];
		if (st != en) {
			Lazy[d][node*2+0] ^= 1;
			Lazy[d][node*2+1] ^= 1;
		}
		Lazy[d][node] = 0;
	}
	if (R < st || en < L) return 0;
	if (L <= st && en <= R) return Tree[d][node];
	int p1 = Get(node*2, st, (st+en)/2, d, L, R);
	int p2 = Get(node*2+1, (st+en)/2+1, en, d, L, R);
	return (p1 + p2);
}

void Input() {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		for (int j=0; j<20; j++) {
			if ((a[i] & (1LL << j)) == 0) continue;
			Update(1, 0, n-1, j, i, i);
		}
	}
}

void Solve() {
	cin >> m;
	while (m--) {
		cin >> t >> l >> r; l--; r--;
		if (t == 1) {
			i64 res = 0;
			for (int i=0; i<20; i++) res += (i64)(Get(1, 0, n-1, i, l, r)) * (1LL << i);
			cout << res << endl;
		}
		else if (t == 2) {
			cin >> x;
			for (int i=0; i<20; i++) {
				if ((x & (1LL << i)) == 0) continue;
				Update(1, 0, n-1, i, l, r);
			}
		}
	}
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


