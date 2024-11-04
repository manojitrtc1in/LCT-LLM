



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

const int N = 100 * 1000 + 13;

int n;
string s;

bool read () {
	static char buf[N];
	if (scanf("%s", buf) != 1)
		return false;
	s = buf;
	n = sz(s);
	return true;
}














struct suffix_array {
	vector<int> c, pos;
	vector<pair<pt, int>> p, nw;
	vector<int> cnt;
	int n;
	
	void radix_sort(int max_al) {
		cnt.assign(max_al, 0);
		forn(i, n) ++cnt[p[i].x.y];
		fore(i, 1, max_al) cnt[i] += cnt[i - 1];
		nw.resize(n);
		forn(i, n) nw[--cnt[p[i].x.y]] = p[i];
		cnt.assign(max_al, 0);
		forn(i, n) ++cnt[nw[i].x.x];
		fore(i, 1, max_al) cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; --i) p[--cnt[nw[i].x.x]] = nw[i];
	}
	
	vector<int> lcp;
	
	suffix_array(const string &s) {
		n = sz(s);
		c = vector<int>(all(s));
		int max_al = *max_element(all(c)) + 1;
		p.resize(n);
		for (int k = 1; k < n; k <<= 1) {
			for (int i = 0, j = k; i < n; ++i, j = (j + 1 == n ? 0 : j + 1))
				p[i] = mp(mp(c[i], c[j]), i);
			radix_sort(max_al);
			c[p[0].y] = 0;
			fore(i, 1, n) c[p[i].y] = c[p[i - 1].y] + (p[i].x != p[i - 1].x);
			max_al = c[p.back().y] + 1;
		}
		lcp.resize(n);
		int l = 0;
		forn(i, n) {
			l = max(0, l - 1);
			if (c[i] == n - 1)
				continue;
			while (i + l < n && p[c[i] + 1].y + l < n && s[i + l] == s[p[c[i] + 1].y + l])
				++l;
			lcp[c[i]] = l;
		}
		pos.resize(n);
		forn(i, n)
			pos[i] = p[i].y;
	}
};

void solve() {
	li ans = n * li(n + 1) / 2;
	suffix_array S(s + char('a' - 1));
	vector<pt> st;
	li sum = 0;
	forn(i, n){
		if (!st.empty() && st.back().x == S.lcp[i])
			++st.back().y;
		else
			st.pb(mp(S.lcp[i], 1));
		sum += st.back().x;
		while (sz(st) > 1 && st[sz(st) - 1].x <= st[sz(st) - 2].x){
			sum -= st[sz(st) - 2].y * li(st[sz(st) - 2].x - st[sz(st) - 1].x);
			st[sz(st) - 1].y += st[sz(st) - 2].y;
			st[sz(st) - 2] = st.back();
			st.pop_back();
		}
		ans += sum;
	}
	printf("%lld\n", ans);
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