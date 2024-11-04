



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
const int MOD = INF + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 1000 + 7;

struct func{
	int name;
	vector<int> tp;
};

map<string, int> nmf;
map<string, int> nmv;
map<string, int> tp;

int getf(string a){
	if (nmf.count(a))
		return nmf[a];
	int k = sz(nmf);
	nmf[a] = k;
	return k++;
}

int getv(string a){
	if (nmv.count(a))
		return nmv[a];
	int k = sz(nmv);
	nmv[a] = k;
	return k++;
}

int gettp(string a){
	if (tp.count(a))
		return tp[a];
	int k = sz(tp);
	tp[a] = k;
	return k++;
}

int n;
func f[N];

int m;
pt v[N];

int k;
func q[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	tp["T"] = -1;
	static char buf[N];
	gets(buf);
	forn(i, n){
		gets(buf);
		string s = buf;
		string t = "";
		while (s[0] == ' ') s = s.substr(1);
		int pos1 = s.find(' ');
		s = s.substr(pos1);
		while (s[0] == ' ') s = s.substr(1);
		forn(j, sz(s)) if (s[j] != ' ')
			t += s[j];
		s = t;
		pos1 = s.find('(');
		
		f[i].name = getf(s.substr(0, pos1));
		
		s = s.substr(pos1);
		s = s.substr(1, sz(s) - 2);
		s += ',';
		
		string lst = "";
		forn(j, sz(s)){
			if (s[j] == ','){
				f[i].tp.pb(gettp(lst));
				lst = "";
			}
			else{
				lst += s[j];
			}
		}
	}
	scanf("%d", &m);
	gets(buf);
	forn(i, m){
		gets(buf);
		string s = buf;
		while (s[0] == ' ') s = s.substr(1);
		int pos1 = s.find(' ');
		v[i].x = gettp(s.substr(0, pos1));
		s = s.substr(pos1);
		while (s[0] == ' ') s = s.substr(1);
		while (s.back() == ' ') s.pop_back();
		v[i].y = getv(s);
	}
	scanf("%d", &k);
	gets(buf);
	forn(i, k){
		gets(buf);
		string s = buf;
		string t = "";
		while (s[0] == ' ') s = s.substr(1);
		forn(j, sz(s)) if (s[j] != ' ')
			t += s[j];
		s = t;
		int pos1 = s.find('(');
		
		q[i].name = getf(s.substr(0, pos1));
		
		s = s.substr(pos1);
		s = s.substr(1, sz(s) - 2);
		s += ',';
		
		string lst = "";
		forn(j, sz(s)){
			if (s[j] == ','){
				q[i].tp.pb(v[getv(lst)].x);
				lst = "";
			}
			else{
				lst += s[j];
			}
		}
	}
	return true;
}

void solve() {
	forn(i, k){
		int cnt = 0;
		forn(j, n){
			if (q[i].name != f[j].name) continue;
			if (sz(q[i].tp) != sz(f[j].tp)) continue;
			bool ok = true;
			forn(t, sz(q[i].tp))
				ok &= (f[j].tp[t] == -1 || f[j].tp[t] == q[i].tp[t]);
			cnt += ok;
		}
		printf("%d\n", cnt);
	}
}

int main() {

	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	

	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

	while(read()) {	
		solve();
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();


	}
}