



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

const int N = 100 * 1000 + 13;

int h, m;
pair<int, pt> q[N];

bool read () {
	if (scanf("%d%d", &h, &m) != 2)
		return false;
	static char buf[10];
	forn(i, m){
		scanf("%s", buf);
		if (buf[0] == 'd')
			q[i].x = 0;
		else{
			q[i].x = 1;
			scanf("%d%d", &q[i].y.x, &q[i].y.y);
		}
	}
	return true;
}

map<int, int> val;
map<int, li> sum;

int getval(int x){
	return (val.count(x) ? val[x] : 0);
}

li getsum(int x){
	return (sum.count(x) ? sum[x] : 0);
}

ld calc(){
	li res = 0;
	int cur = 1;
	li mx = 0;
	int tot = (1 << h);
	
	while (cur < (1 << h)){
		int x = getval(cur);
		li s1 = getsum(cur * 2) + x;
		li s2 = getsum(cur * 2 + 1) + x;
		
		if (s1 > s2){
			res += max(mx, s1) * (tot / 2);
			mx = max(mx, s2);
			cur = cur * 2;
		}
		else{
			res += max(mx, s2) * (tot / 2);
			mx = max(mx, s1);
			cur = cur * 2 + 1;
		}
			
		tot /= 2;
	}
	
	res += max(mx, getsum(cur));
	
	return res / ld(1 << h);
}

void add(int x, int y){
	val[x] += y;
	while (x){
		sum[x] += y;
		x /= 2;
	}
}

void solve() {
	val.clear();
	sum.clear();
	
	forn(i, m){
		if (q[i].x == 0)
			printf("%.15Lf\n", calc());
		else{
			add(q[i].y.x, q[i].y.y);
		}
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