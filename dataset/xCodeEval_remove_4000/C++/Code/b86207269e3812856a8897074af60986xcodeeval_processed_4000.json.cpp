







using namespace std;









const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9, GOLD = ((1+sqrt(5))/2);
typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;


template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }







i64 n; map<ppi, i64> vis;
vector<vi> stone;
map<pii, vector<pii>> Map;





void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n; stone.resize(n, vi(3, 0));
	for (i64 i=0; i<n; i++) {
		for (i64 j=0; j<3; j++) {
			cin >> stone[i][j];
		}
		for (i64 x=0; x<3; x++) {
			for (i64 y=x+1; y<3; y++) {
				i64 z = stone[i][x], t = stone[i][y];
				if (z > t) swap(z, t);
				if (vis[mp(mp(z,t), i)]) continue;
				i64 u = 0;
				if (x == 0 || y == 0) {
					if (x == 1 || y == 1) u = 2;
					else u = 1;
				}
				Map[mp(z,t)].pub(mp(stone[i][u], i));
				vis[mp(mp(z,t), i)]++;
			}
		}
	}
}

void ProSolve() {
	vi ans; i64 mx = 0;
	for (auto it=Map.begin(); it!=Map.end(); it++) {
		

		pii z = it->first; vector<pii> v = it->second;
		sort(v.begin(), v.end(), greater<pii>());
		if (v.size() == 1) {
			vi q(1, v[0].se);
			i64 tmp = min(min(z.fi, z.se), v[0].fi);
			if (tmp > mx) {
				mx = tmp; ans = q;
			}
		}
		else {
			vi q(2, v[0].se); q[1] = v[1].se;
			i64 tmp = min(min(z.fi, z.se), v[0].fi+v[1].fi);
			if (tmp > mx) {
				mx = tmp; ans = q;
			}
		}
	}
	cout << ans.size() << endl;
	for (i64 i=0; i<ans.size(); i++) cout << (ans[i] + 1) << " ";
}


int main() {
			
			

			

			
	VarInput();
			
			auto TIME1 = chrono::steady_clock::now();
			
	ProSolve();
			
			auto TIME2 = chrono::steady_clock::now();
			auto DIFF = TIME2 - TIME1;
			cout << "\n\nTime elapsed: " << chrono::duration<double>(DIFF).count() << " seconds.";
			
	return 0;
}




