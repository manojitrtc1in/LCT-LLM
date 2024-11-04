





#include <bits/stdc++.h>
using namespace std;


#define endl '\n'
#define i64 long long
#define u64 unsigned long long
#define ld long double
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define mmap multimap
#define mset multiset
#define umap unordered_map
#define uset unordered_set
#define ummap unordered_multimap
#define umset unordered_multiset
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define REcheck cout << "RE here?\n"
#define tracker1(i) cout << "working at " << i << endl;
#define tracker2(i,j) cout << "working at " << i << "-" << j << endl;
#define tracker3(i,j,k) cout << "working at " << i << "-" << j << "-" << k << endl;
#define dout(x,y) cout << fixed << setprecision(x) << y << endl;



const long double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;
const long long MOD = 1000000007LL;
const long long INF = 1e9;
const long long LINF = 1e18;
const long double EPS = 1e-9;
const long double GOLD = ((1+sqrt(5))/2);
typedef vector<i64> vi;
typedef vector<vector<i64>> vvi;
typedef vector<ld> vd;
typedef vector<vector<ld>> vvd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;
typedef vector<pii> vp;




template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }

















i64 n; vi a; vi cc(100009, 0), sum(100009, 0);
bool oddAvail = false;





void VarInput() {
	

	cin >> n; a.resize(n);
	for (i64 i=0; i<n; i++) {
		cin >> a[i]; cc[a[i]]++;
	}
	i64 z = *max_element(a.begin(), a.end());
	for (i64 i=1; i<z; i++) {
		sum[i] = sum[i-1] + cc[i];
		if (sum[i] % 2 != 0) {
			oddAvail = true; break;
		}
	}
}

void ProSolve() {
	

	i64 turns = 0;
	for (i64 i=100008; i>=0; i--) {
		if (cc[i] == 0) continue;
		if (cc[i] % 2 == 1) {cout << "Conan"; return;}
		else {
			if (oddAvail) cout << "Conan";
			else cout << "Agasa";
			return;
		}
	}
}


int main() {
	

	

	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput();
	

	ProSolve(); 

	return 0;
}




