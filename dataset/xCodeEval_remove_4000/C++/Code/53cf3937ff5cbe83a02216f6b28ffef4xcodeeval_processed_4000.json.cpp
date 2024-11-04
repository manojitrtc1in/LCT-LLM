









using namespace std;



using ll = long long; 

using pii = pair<int, int>;	using pll = pair<ll, ll>;	using pil = pair<int, ll>;	using pli = pair<ll, int>;
using vi = vector<int>;		using vvi = vector<vi>;		using vvvi = vector<vvi>;
using vl = vector<ll>;		using vvl = vector<vl>;		using vvvl = vector<vvl>;
using vb = vector<bool>;	using vvb = vector<vb>;		using vvvb = vector<vvb>;
using vc = vector<char>;	using vvc = vector<vc>;		using vvvc = vector<vvc>;
using vd = vector<double>;	using vvd = vector<vd>;		using vvvd = vector<vvd>;
template <class T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;
using Graph = vvi;



const double PI = 3.14159265359;
const double DEG = PI / 180.; 

const vi dx4 = { 1, 0, -1, 0 }; 

const vi dy4 = { 0, 1, 0, -1 };
const vi dx8 = { 1, 1, 0, -1, -1, -1, 0, 1 }; 

const vi dy8 = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int INF = 1001001001; const ll INFL = 2002002002002002002LL;
const double EPS = 1e-10; 




struct fast_io { fast_io() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); } } id1;




























template <class T> inline ll pow(T n, int k) { ll v = 1; rep(i, k) v *= n; return v; }
template <class T> inline bool chmax(T& M, const T& x) { if (M < x) { M = x; return true; } return false; } 

template <class T> inline bool chmin(T& m, const T& x) { if (m > x) { m = x; return true; } return false; } 




template <class T, class U> inline istream& operator>> (istream& is, pair<T, U>& p) { is >> p.first >> p.second; return is; }
template <class T, class U> inline ostream& operator<< (ostream& os, const pair<T, U>& p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template <class T, class U, class V> inline istream& operator>> (istream& is, tuple<T, U, V>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t); return is; }
template <class T, class U, class V> inline ostream& operator<< (ostream& os, const tuple<T, U, V>& t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; return os; }
template <class T, class U, class V, class W> inline istream& operator>> (istream& is, tuple<T, U, V, W>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t); return is; }
template <class T, class U, class V, class W> inline ostream& operator<< (ostream& os, const tuple<T, U, V, W>& t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << "," << get<3>(t) << ")"; return os; }
template <class T> inline istream& operator>> (istream& is, vector<T>& v) { repea(x, v) is >> x; return is; }
template <class T> inline ostream& operator<< (ostream& os, const vector<T>& v) { repe(x, v) os << x << " "; return os; }
template <class T> inline ostream& operator<< (ostream& os, const set<T>& s) { repe(x, s) os << x << " "; return os; }
template <class T> inline ostream& operator<< (ostream& os, const unordered_set<T>& s) { repe(x, s) os << x << " "; return os; }
template <class T, class U> inline ostream& operator<< (ostream& os, const map<T, U>& m) { repe(p, m) os << p << " "; return os; }
template <class T, class U> inline ostream& operator<< (ostream& os, const unordered_map<T, U>& m) { repe(p, m) os << p << " "; return os; }
template <class T> inline ostream& operator<< (ostream& os, stack<T> s) { while (!s.empty()) { os << s.top() << " "; s.pop(); } return os; }
template <class T> inline ostream& operator<< (ostream& os, queue<T> q) { while (!q.empty()) { os << q.front() << " "; q.pop(); } return os; }
template <class T> inline ostream& operator<< (ostream& os, deque<T> q) { while (!q.empty()) { os << q.front() << " "; q.pop_front(); } return os; }
template <class T> inline ostream& operator<< (ostream& os, priority_queue<T> q) { while (!q.empty()) { os << q.top() << " "; q.pop(); } return os; }







inline int lsb(unsigned int n) { unsigned long i; _BitScanForward(&i, n); return i; } 

inline int id4(unsigned long long n) { unsigned long i; _BitScanForward64(&i, n); return i; }
inline int msb(unsigned int n) { unsigned long i; _BitScanReverse(&i, n); return i; } 

inline int id3(unsigned long long n) { unsigned long i; _BitScanReverse64(&i, n); return i; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }



























































template <typename T> 

T binary_search(T ok, T ng, function<bool(T)>& okQ) {
	

	while (abs(ok - ng) > 1) {
		

		T mid = (ok + ng) / 2;

		

		if (okQ(mid)) {
			ok = mid;
		}
		else {
			ng = mid;
		}
	}
	return ok;
}



void WA() {
	int t;
	cin >> t;

	rep(hoge, t) {
		int n, m;
		cin >> n >> m;

		vvi a(n, vi(m));
		cin >> a;

		function<bool(int)> okQ = [&](int th) {
			vvb l(n, vb(m)), r(n, vb(m));
			rep(i, n) l[i][0] = a[i][0] <= th;
			rep(i, n) {
				repi(j, 1, m - 1) {
					l[i][j] = l[i][j - 1] | (a[i][j] <= th);
				}
			}
			rep(i, n) r[i][m - 1] = a[i][m - 1] <= th;
			rep(i, n) {
				repir(j, m - 2, 0) {
					r[i][j] = r[i][j + 1] | (a[i][j] <= th);
				}
			}

			repi(j, 0, m - 2) {
				rep(i, n) {
					if (l[i][j] && r[i][j + 1]) {
						goto NEXT_LOOP;
					}
				}
				return true;
			NEXT_LOOP:;
			}
			return false;
		};

		int th = binary_search(0, (int)1e6, okQ);
		dump(th);

		vc col(n);
		int border = -1;
		bool b_flag = false, r_flag = false;

		rep(i, n) {
			col[i] = (a[i][0] <= th ? 'B' : 'R');
			if (col[i] == 'B') b_flag = true;
			else r_flag = true;
		}
		dump(col);
		if (!(b_flag && r_flag)) {
			cout << "NO\n";
			goto LOOP_END;
		}

		repi(j, 1, m - 1) {
			if ((a[0][j] <= th) != (col[0] == 'B')) {
				if (border == -1) {
					border = j;
				}
			}

			rep(i, n) {
				if (border == -1) {
					if ((a[i][j] <= th) != (col[i] == 'B')) {
						cout << "NO\n";
						goto LOOP_END;
					}
				}
				else {
					if ((a[i][j] <= th) != (col[i] == 'R')) {
						cout << "NO\n";
						goto LOOP_END;
					}
				}
			}
		}

		cout << "YES\n";
		rep(i, n) cout << col[i];
		cout << " " << border << "\n";

	LOOP_END:;
	}
}



void WA2() {
	int t;
	cin >> t;

	rep(hoge, t) {
		int n, m;
		cin >> n >> m;

		vvi a(n, vi(m));
		cin >> a;

		function<bool(int)> okQ = [&](int th) {
			vvb l(n, vb(m)), r(n, vb(m));
			rep(i, n) l[i][0] = (a[i][0] <= th);
			rep(i, n) {
				repi(j, 1, m - 1) {
					l[i][j] = l[i][j - 1] | (a[i][j] <= th);
				}
			}
			rep(i, n) r[i][m - 1] = (a[i][m - 1] <= th);
			rep(i, n) {
				repir(j, m - 2, 0) {
					r[i][j] = r[i][j + 1] | (a[i][j] <= th);
				}
			}

			repi(j, 0, m - 2) {
				rep(i, n) {
					if (l[i][j] && r[i][j + 1]) {
						goto NEXT_LOOP;
					}
				}
				return true;
			NEXT_LOOP:;
			}
			return false;
		};

		function<bool(int)> id5 = [&](int th) {
			vvb l(n, vb(m)), r(n, vb(m));
			rep(i, n) l[i][0] = (a[i][0] > th);
			rep(i, n) {
				repi(j, 1, m - 1) {
					l[i][j] = l[i][j - 1] | (a[i][j] > th);
				}
			}
			rep(i, n) r[i][m - 1] = (a[i][m - 1] > th);
			rep(i, n) {
				repir(j, m - 2, 0) {
					r[i][j] = r[i][j + 1] | (a[i][j] > th);
				}
			}

			repi(j, 0, m - 2) {
				rep(i, n) {
					if (l[i][j] && r[i][j + 1]) {
						goto NEXT_LOOP;
					}
				}
				return true;
			NEXT_LOOP:;
			}
			return false;
		};

		int th = binary_search(0, (int)1e6, okQ);
		dump(th);
		int th2 = binary_search((int)1e6, 0, id5);
		dump(th2);

		if (th < th2) {
			cout << "NO\n";
			continue;
		}

		vc col(n);
		int border = -1;
		bool b_flag = false, r_flag = false;

		rep(i, n) {
			col[i] = (a[i][0] <= th ? 'B' : 'R');
			if (col[i] == 'B') b_flag = true;
			else r_flag = true;
		}
		dump(col);
		if (!(b_flag && r_flag)) {
			cout << "NO\n";
			continue;
		}

		repi(j, 1, m - 1) {
			if ((a[0][j] <= th) != (col[0] == 'B')) {
				border = j;
				break;
			}
		}

		cout << "YES\n";
		rep(i, n) cout << col[i];
		cout << " " << border << "\n";
	}
}


int main() {
	input_from_file("input.txt");



	int t;
	cin >> t;

	rep(hoge, t) {
		int n, m;
		cin >> n >> m;

		vvi a(n, vi(m));
		cin >> a;

		vector<pii> tmp(n);
		rep(i, n) tmp[i] = { a[i][0], i };
		sort(all(tmp));

		vi id(n);
		rep(i, n) id[i] = tmp[i].second;
		dump(id);

		vvi id7(n, vi(m)), id2(n, vi(m));
		rep(j, m) id7[0][j] = id2[0][j] = a[id[0]][j];
		repi(i, 1, n - 1) {
			rep(j, m) {
				id7[i][j] = min(id7[i - 1][j], a[id[i]][j]);
				id2[i][j] = max(id2[i - 1][j], a[id[i]][j]);
			}
		}
		dumpel(id7);
		dumpel(id2);

		vvi id10(n, vi(m)), id8(n, vi(m));
		rep(j, m) id10[n - 1][j] = id8[n - 1][j] = a[id[n - 1]][j];
		repir(i, n - 2, 0) {
			rep(j, m) {
				id10[i][j] = min(id10[i + 1][j], a[id[i]][j]);
				id8[i][j] = max(id8[i + 1][j], a[id[i]][j]);
			}
		}
		dumpel(id10);
		dumpel(id8);

		int col_sp = -1, lr_sp = -1;
		repi(i, 0, n - 2) {
			int l = 0;
			int id9 = -INF, id6 = INF;
			while (l <= m - 2) {
				chmax(id9, id2[i][l]);
				chmin(id6, id10[i + 1][l]);

				if (id9 >= id6) {
					break;
				}

				l++;
			}

			int r = m - 1;
			int id0 = INF, id11 = -INF;
			while (r >= 1) {
				chmin(id0, id7[i][r]);
				chmax(id11, id8[i + 1][r]);

				if (id0 <= id11) {
					break;
				}

				r--;
			}

			if (r < l) {
				col_sp = i;
				lr_sp = l;
				break;
			}
		}

		if (col_sp == -1) {
			cout << "NO\n";
			continue;
		}

		vc col(n);
		rep(i, n) {
			if (i <= col_sp) col[id[i]] = 'B';
			else col[id[i]] = 'R';
		}

		cout << "YES\n";
		rep(i, n) cout << col[i];
		cout << " " << lr_sp << "\n";
	}
}
