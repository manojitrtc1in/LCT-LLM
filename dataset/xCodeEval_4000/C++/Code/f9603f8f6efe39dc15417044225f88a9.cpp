

#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

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

const int N = 50 * 1000 + 13;

struct point{
	int x, y, z, i;
	point() : x(INF), y(INF), z(INF), i(-1) {}
};

int n;
point a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n){
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
		a[i].i = i;
	}
	return true;
}

bool operator <(const point &a, const point &b){
	if (a.x != b.x)
		return a.x < b.x;
	if (a.y != b.y)
		return a.y < b.y;
	return a.z < b.z;
}

void solve() {
	sort(a, a + n);
	point lstx;
	forn(ix, n){
		int jx = ix;
		while (jx + 1 < n && a[jx + 1].x == a[ix].x)
			++jx;
		point lsty;
		fore(iy, ix, jx + 1){
			int jy = iy;
			while (jy + 1 <= jx && a[jy + 1].y == a[iy].y)
				++jy;
			for (int ky = iy; ky + 1 <= jy; ky += 2)
				printf("%d %d\n", a[ky].i + 1, a[ky + 1].i + 1);
			if ((jy - iy) % 2 == 0){
				if (lsty.i != -1){
					printf("%d %d\n", lsty.i + 1, a[jy].i + 1);
					lsty = point();
				}
				else{
					lsty = a[jy];
				}
			}
			iy = jy;
		}
		if (lsty.i != -1){
			if (lstx.i != -1){
				printf("%d %d\n", lstx.i + 1, lsty.i + 1);
				lstx = point();
			}
			else{
				lstx = lsty;
			}
		}
		ix = jx;
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	
#endif
	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

	while(read()) {	
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}