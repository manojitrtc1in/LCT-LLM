



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

const int N = 50 * 1000 + 13;

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



 






 
struct id0 {
	vector<vector<int>> st;
	vector<int> pw;
	
	id0() {}
	
	id0(const vector<int> &a) {
		int n = sz(a);
		int logn = 32 - __builtin_clz(n);
		st.resize(logn, vector<int>(n));
		forn(i, n)
			st[0][i] = a[i];
		fore(j, 1, logn) forn(i, n) {
			st[j][i] = st[j - 1][i];
			if (i + (1 << (j - 1)) < n)
				st[j][i] = min(st[j][i], st[j - 1][i + (1 << (j - 1))]);
		}
		pw.resize(n + 1);
		pw[0] = pw[1] = 0;
		fore(i, 2, n + 1)
			pw[i] = pw[i >> 1] + 1;
	}
	
	int get(int l, int r) {
		if (l >= r) return INF;
		int len = pw[r - l];
		return min(st[len][l], st[len][r - (1 << len)]);
	}
};

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
	id0 st;
	
	int get_lcp(int l, int r) {
		l = c[l], r = c[r];
		if (l > r) swap(l, r);
		return st.get(l, r);
	}
	
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
		st = id0(lcp);
	}
};
 
void solve(){
	bool fl = false;
	suffix_array s1(s + " ");
	reverse(all(s));
	suffix_array s2(s + " ");
	reverse(all(s));
	fore(k, 1, sz(s) / 2 + 1){
		if (fl){
			s1 = suffix_array(s + " ");
			reverse(all(s));
			s2 = suffix_array(s + " ");
			reverse(all(s));
			fl = false;
		}
		vector<int> pos;
		int cnt = n / k;
		forn(i, cnt){
			int j = i;
			while (j + 1 < cnt && s1.get_lcp(j * k, (j + 1) * k) >= k)
				++j;
			int cur = j - i + 1;
			int lensu = s2.get_lcp(n - (i * k), n - ((i + 1) * k));
			if (lensu + s1.get_lcp(j * k, (j + 1) * k) >= k)
				++cur;
			if (cur > 1){
				pos.pb(i * k - lensu);
				forn(_, cur - 2) pos.pb(pos.back() + k);
			}
			i = j;
		}
		

		if (pos.empty())
			continue;
		string t = "";
		int j = 0;
		forn(i, n){
			if (j < sz(pos) && pos[j] == i){
				i += k - 1;
				++j;
				continue;
			}
			t += s[i];
		}
		s = t;
		n = sz(s);
		fl = true;
	}
	puts(s.c_str());
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