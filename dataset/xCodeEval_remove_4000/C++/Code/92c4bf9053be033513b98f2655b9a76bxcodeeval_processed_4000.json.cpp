
 













using namespace std;
const int N = int(1e5) + 1, mod = 998244353, inf = int(1e9);
const long long INF = 9223372036854775807;
const double long PI = 3.14159265358979323846;
 
void init_code() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
}
 
void id0() {
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w", stdout);	
}

void shuffleFirst(vector<int> &a) {
	int n = a.size() / 2;
	for (int i = 0; i < n; ++i) {
		swap(a[2 * i], a[2 * i + 1]);
	}
}

void shuffleSecond(vector<int> &a) {
	int n = a.size() / 2;
	for (int i = 0; i < n; ++i) {
		swap(a[i], a[i + n]);
	}
} 

void solve() {
	int n; scanf ("%d", &n);

	vector<int> a(n * 2);
	for (int &x : a) scanf ("%d", &x);

	vector<int> b = a;
	sort(all(b));

	if (a == b) {
		printf ("0\n");
		return;
	}

	if (n % 2 == 0) {
		vector<int> a2 = a;
		shuffleFirst(a2);
		if (a2 == b) {
			printf ("1\n");
			return;
		}
		a2 = a;
		shuffleSecond(a2);
		if (a2 == b) {
			printf ("1\n");
			return;
		}
		a2 = a;
		shuffleFirst(a2);
		shuffleSecond(a2);
		if (a2 == b) {
			printf ("2\n");
			return;
		}
		printf ("-1\n");
		return;
	}

	vector<int> a2 = a;

	int ans = inf;
	for (int it = 0; it < 1000; ++it) {
		if (it % 2 == 0) {
			shuffleFirst(a);
			if (a == b) ans = min(ans, it + 1);
		} else {
			shuffleSecond(a);
			if (a == b) ans = min(ans, it + 1);
		}
	}

	a = a2;

	for (int it = 0; it < 1000; ++it) {
		if (it % 2 == 0) {
			shuffleSecond(a);
			if (a == b) ans = min(ans, it + 1);
		} else {
			shuffleFirst(a);
			if (a == b) ans = min(ans, it + 1);
		}
	}

	if (ans == inf) ans = -1;

	printf ("%d\n", ans);
}



int main() {
	fast_io;
	init_code();
	int tt;
	tt = 1;
	for (int i = 1; i <= tt; i++) {
		solve();
	}
}