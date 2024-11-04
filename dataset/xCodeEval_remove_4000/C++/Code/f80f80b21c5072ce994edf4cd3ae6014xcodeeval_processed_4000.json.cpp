



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
const int AL = 26;

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

int cnt[AL];

void solve() {
	memset(cnt, 0, sizeof(cnt));
	forn(i, n) ++cnt[s[i] - 'a'];
	if (cnt[s[0] - 'a'] == n){
		puts(s.c_str());
		return;
	}
	forn(i, AL) if (cnt[i] == 1){
		printf("%c", 'a' + i);
		--cnt[i];
		forn(j, AL) while (cnt[j]){
			printf("%c", 'a' + j);
			--cnt[j];
		}
		puts("");
		return;
	}
	int mn = *min_element(all(s)) - 'a';
	
	if ((cnt[mn] - 2) * 2 > n - 2){
		int num = 0;
		forn(i, AL) num += cnt[i] > 0;
		assert(num >= 2);
		string ans = "";
		forn(i, AL) if (sz(ans) < 2 && cnt[i] > 0){
			ans += 'a' + i;
			--cnt[i];
		}
		if (num > 2){
			while (cnt[mn] > 0){
				ans += mn + 'a';
				--cnt[mn];
			}
			bool fl = 0;
			fore(i, mn + 1, AL) if (cnt[i] > 0){
				if (fl){
					ans += i + 'a';
					--cnt[i];
					break;
				}
				else{
					fl = true;
				}
			}
			fore(i, mn + 1, AL) while (cnt[i] > 0){
				ans += i + 'a';
				--cnt[i];
			}
		}
		else{
			fore(i, mn + 1, AL) while (cnt[i] > 0){
				ans += i + 'a';
				--cnt[i];
			}
			while (cnt[mn] > 0){
				ans += mn + 'a';
				--cnt[mn];
			}
		}
		puts(ans.c_str());
	}
	else{
		string ans(2, mn + 'a');
		cnt[mn] -= 2;
		int j = mn + 1;
		while (j < AL || cnt[mn] > 0){
			if (ans.back() == mn + 'a' || cnt[mn] == 0){
				while (j < AL && cnt[j] == 0) ++j;
				assert(j < AL || cnt[mn] == 0);
				if (j == AL) break;
				--cnt[j];
				ans += j + 'a';
			}
			else{
				--cnt[mn];
				ans += mn + 'a';
			}
		}
		puts(ans.c_str());
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