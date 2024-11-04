






using namespace std;



























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

















i64 n, m, p; string CBS; string cmd;
i64 firstElement = 0;
vi Next, Previous, pairing;





void VarInput() {
	

	cin >> n >> m >> p; Next.resize(n);
	Previous = Next; pairing = Next; p--;
	for (i64 i=0; i<n; i++) {
		if (i == 0) Previous[i] = -1;
		else Previous[i] = i - 1;
		if (i == n-1) Next[i] = -1;
		else Next[i] = i+1;
	}
	cin >> CBS >> cmd;
	stack<i64> S; S.push(0);
	for (i64 i=1; i<n; i++) {
		if (CBS[i] == ')') {
			pairing[i] = S.top();
			pairing[S.top()] = i;
			S.pop();
		}
		else S.push(i);
	}
}

void ProSolve() {
	

	for (i64 i=0; i<m; i++) {
		if (cmd[i] == 'L') {
			p = Previous[p];


		}
		else if (cmd[i] == 'R') {
			p = Next[p];


		}
		else if (cmd[i] == 'D') {
			i64 a[2]; a[0] = p; a[1] = pairing[p]; sort(a, a+2);
			if (Next[a[1]] == -1) p = Previous[a[0]]; else p = Next[a[1]];
			if (a[0] > 0) Next[Previous[a[0]]] = Next[a[1]];
			if (a[1] < n-1) Previous[Next[a[1]]] = Previous[a[0]];
			if (Previous[a[0]] == -1) firstElement = Next[a[1]];
			i64 pos = firstElement;












		}
	}
	i64 pos = firstElement;
	while (pos != -1) {
		cout << CBS[pos];
		pos = Next[pos];
	}
}


int main() {
	

	

	ios_base::sync_with_stdio(0); cin.tie(NULL);
	VarInput();
	

	ProSolve(); 

	return 0;
}




