



using namespace std;














typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template <class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template <class A> ostream& operator << (ostream& out, const vector<A> &v) {
	out << "[";
	forn(i, sz(v)) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}

mt19937 rnd(time(NULL));

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 1000 * 1000 + 13;

int n, m;
string s, t;

bool read () {
	static char buf[N];
	if (scanf("%s", buf) != 1)
		return false;
	s = buf;
	n = sz(s);
	scanf("%s", buf);
	t = buf;
	m = sz(t);
	return true;
}

int cnts[10], cntt[10];

vector<int> zfunction(const string& s) {
	int n = sz(s);
	vector<int> z(n);
	int l = 0, r = 0;
	fore(i, 1, n) {
		if (i <= r) z[i] = min(z[i - l], r - i + 1);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}

void solve() {
	if (t == "0" && (s == "01" || s == "10")){
		puts("0");
		return;
	}
	memset(cnts, 0, sizeof(cnts));
	memset(cntt, 0, sizeof(cntt));
	forn(i, n) ++cnts[s[i] - '0'];
	forn(i, m) ++cntt[t[i] - '0'];
	forn(i, 10) cnts[i] -= cntt[i];
	fore(len, 1, n + 1){
		string x = to_string(len);
		if (n != len + sz(x))
			continue;
		bool ok = true;
		forn(i, sz(x)){
			--cnts[x[i] - '0'];
			ok &= cnts[x[i] - '0'] >= 0;
		}
		assert(ok);
		string ns = "";
		forn(i, 10) ns += string(cnts[i], '0' + i);
		string ans = "z";
		if (t[0] != '0')
			ans = t + ns;
		if (ns[0] == '0'){
			forn(i, sz(ns)) if (ns[i] != '0'){
				char c = ns[i];
				ns.erase(ns.begin() + i);
				ns.insert(ns.begin(), c);
				break;
			}
		}
		if (cnts[0] == n - sz(x) - m){
			assert(t[0] != '0');
			ns = t + ns;
		}
		else{
			auto z = zfunction(t + "
			int lst = sz(ns);
			int chg = sz(ns);
			forn(i, sz(ns) + 1){
				if (i == 0 && t[0] == '0') continue;
				int pos = sz(t) + i + 1;
				if (i == sz(ns) || i + z[pos] >= sz(ns))
					lst = min(lst, i);
				if (i < sz(ns) && i + z[pos] < sz(ns) && ns[i + z[pos]] > t[z[pos]])
					chg = min(chg, i + z[pos]);

			}
			if (chg != sz(ns)){
				forn(i, sz(ns) + 1){
					if (i == 0 && t[0] == '0') continue;
					int pos = sz(t) + i + 1;
					if (i == sz(ns) || i + z[pos] >= sz(ns))
						lst = min(lst, i);
					if (i < sz(ns) && i + z[pos] < sz(ns) && ns[i + z[pos]] > t[z[pos]] && (i + z[pos] == chg || i + z[pos] == chg - 1)){
						ans = min(ans, ns.substr(0, i) + t + ns.substr(i));
					}
				}
			}
			ans = min({ans, ns.substr(0, lst) + t + ns.substr(lst), ns + t});
		}
		puts(ans.c_str());
		break;
	}
}

int main() {

	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	

	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;


	int tc;
	scanf("%d", &tc);
	while(tc--){
		read();

	while(read()) {	

		solve();
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();


	}
}