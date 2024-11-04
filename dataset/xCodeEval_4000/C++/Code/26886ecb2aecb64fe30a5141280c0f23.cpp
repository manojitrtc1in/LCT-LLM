





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

















string s, s2; i64 n, ans = 0;





void VarInput() {
	

	cin >> s; n = s.size();
}

void ProSolve() {
	

	for (i64 i=0; i<n; i++) {
		i64 diff = 0, q = 0, o = 0, c = 0;
		bool valid = true;
		for (i64 j=i; j<n; j++) {
			

			if (s[j] == '?') {
				q++; if (diff > 0) diff--;
			}
			else if (s[j] == '(') {
				o++; diff++;
			}
			else if (s[j] == ')') {
				c++; if (diff > 0) diff--;
			}
			if (q + o < c) valid = false;
			if (diff == 0 && valid && (j - i) % 2 != 0) {
				

				ans++;
			}
		}
	}
	cout << ans;
}


int main() {
	

	

	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput();
	

	ProSolve(); 

	return 0;
}



