



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

int l1, r1, l2, r2;
int k;

bool read () {
	if (scanf("%d%d%d%d%d", &l1, &r1, &l2, &r2, &k) != 5)
		return false;
	return true;
}

int calc(int x){
	string s = to_string(x);
	int cur = 1 << (sz(s) - 1);
	int ans = cur * 2 - 1;
	bool fl = true;
	forn(i, sz(s)){
		if (s[i] > '7')
			ans += 2 * cur;
		else if (s[i] > '4')
			ans += cur;
		if (s[i] != '7' && s[i] != '4'){
			fl = false;
			break;
		}
		cur >>= 1;
	}
	ans += fl;
	return ans;
}

vector<int> nums;

void brute(int x, int num){
	nums.pb(num);
	if (x == 9) return;
	brute(x + 1, num * 10 + 4);
	brute(x + 1, num * 10 + 7);
}

void solve() {
	nums.clear();
	brute(0, 0);
	sort(all(nums));
	li tot = (r1 - l1 + 1) * li(r2 - l2 + 1);
	

	li ok = 0;
	fore(i, 1, sz(nums) - k + 1){
		int l = nums[i];
		int r = nums[i + k - 1];
		int pl = nums[i - 1] + 1;
		int pr = (i + k == sz(nums) ? INF + 7 : nums[i + k] - 1);
		if (l1 <= l && r <= r2){
			int ll = max(l1, pl);
			int rr = min(r2, pr);
			ok += max(0, min(l, r1) - ll + 1) * li(max(0, rr - max(r, l2) + 1));
		}
		if (l2 <= l && r <= r1){
			int ll = max(l2, pl);
			int rr = min(r1, pr);
			ok += max(0, min(l, r2) - ll + 1) * li(max(0, rr - max(r, l1) + 1));
		} 
	}
	if (k == 1){
		for (auto it : nums)
			ok -= l1 <= it && it <= r1 && l2 <= it && it <= r2;
	}
	
	printf("%.15Lf\n", ok / ld(tot));
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