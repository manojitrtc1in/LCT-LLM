



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

const int N = 8;

vector<int> a[N];

bool read () {
	forn(i, N) a[i].resize(4);
	if (scanf("%d%d%d", &a[0][0], &a[0][1], &a[0][2]) != 3)
		return false;
	fore(i, 1, N){
		scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
		a[i][3] = i;
	}
	return true;
}

li sdist(vector<int> &a, vector<int> &b){
	li res = 0;
	forn(i, 3) res += sqr(li(a[i] - b[i]));
	return res;
}

bool used[N];
vector<vector<int>> cur;

void brute(int x){
	if (sz(cur) == 4){
		auto tmp = cur;
		sort(all(cur));
		
		do{
			li len = sdist(cur[0], cur[1]);
			if (len != sdist(cur[0], cur[2]) || len != sdist(cur[0], cur[3]) || len == 0)
				continue;
			if (sdist(cur[1], cur[2]) != 2 * len || sdist(cur[2], cur[3]) != 2 * len || sdist(cur[3], cur[1]) != 2 * len)
				continue;
			
			forn(i, N){
				if (used[i]) continue;
				do{
					if (!used[i] && sdist(cur[0], a[i]) == 2 * len && sdist(cur[1], a[i]) == len && sdist(cur[2], a[i]) == len){
						used[i] = true;
						cur.pb(a[i]);
					}
				} while (next_permutation(a[i].begin(), a[i].begin() + 3));
				if (used[i]) break;
			}
			forn(i, N){
				if (used[i]) continue;
				do{
					if (!used[i] && sdist(cur[0], a[i]) == 2 * len && sdist(cur[1], a[i]) == len && sdist(cur[3], a[i]) == len){
						used[i] = true;
						cur.pb(a[i]);
					}
				} while (next_permutation(a[i].begin(), a[i].begin() + 3));
				if (used[i]) break;
			}
			forn(i, N){
				if (used[i]) continue;
				do{
					if (!used[i] && sdist(cur[0], a[i]) == 2 * len && sdist(cur[2], a[i]) == len && sdist(cur[3], a[i]) == len){
						used[i] = true;
						cur.pb(a[i]);
					}
				} while (next_permutation(a[i].begin(), a[i].begin() + 3));
				if (used[i]) break;
			}
			forn(i, N){
				if (used[i]) continue;
				do{
					if (!used[i] && sdist(cur[1], a[i]) == 2 * len && sdist(cur[2], a[i]) == 2 * len && sdist(cur[3], a[i]) == 2 * len){
						used[i] = true;
						cur.pb(a[i]);
					}
				} while (next_permutation(a[i].begin(), a[i].begin() + 3));
				if (used[i]) break;
			}
			
			if (sz(cur) == N){
				sort(all(cur), [](vector<int> a, vector<int> b){
					return a[3] < b[3];
				});
				puts("YES");
				forn(i, N)
					printf("%d %d %d\n", cur[i][0], cur[i][1], cur[i][2]);
				exit(0);
			}
			
			while (sz(cur) > 4){
				used[cur.back()[3]] = false;
				cur.pop_back();
			}
		} while (next_permutation(all(cur)));
		cur = tmp;
		return;
	}
	
	if (x == N)
		return;
	
	brute(x + 1);
	
	do{
		used[x] = true;
		cur.pb(a[x]);
		brute(x + 1);
		cur.pop_back();
		used[x] = false;
	} while (next_permutation(a[x].begin(), a[x].begin() + 3));
}

void solve() {
	forn(i, N) sort(a[i].begin(), a[i].begin() + 3);
	
	brute(0);
	puts("NO");
}

int main() {

	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	

	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

	if(read()) {	
		solve();
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();


	}
}