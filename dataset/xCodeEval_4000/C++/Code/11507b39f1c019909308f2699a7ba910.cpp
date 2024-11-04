








#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;


#define endl '\n'
#define i64 long long
#define ld long double
#define pub push_back
#define mp make_pair
#define fi first
#define se second
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9, GOLD = ((1+sqrt(5))/2);
typedef vector<i64> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<i64, i64> pii;
typedef pair<i64, pii> pip;
typedef pair<pii, i64> ppi;

int cmp(double A, double B) {
    if (A - B < -EPS) return -1;

    if (A - B > EPS) return 1;

    return 0;

}


template<class T> int getbit(T s, int i) { return (s >> 1) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s); }




struct point{
    double x;
    double y;
    point(double _x = 0, double _y = 0) {
    x = _x; y = _y;
    }
    bool operator == (const point& that) const{
        return (cmp(x, that.x) == 0 && cmp(y, that.y) == 0);
    }
    bool operator < (const point& that) const {
        if(cmp(x, that.x) != 0) return cmp(x, that.x) < 0;
        return cmp(y, that.y) < 0;
    }
};


int n; point a[1111];


int ccw(point a, point b, point c) {
    return cmp(a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y), 0);
}

int isRealCut(point p0, point p1, point p2, point p3){
    return ccw(p0,p1,p2)*ccw(p0,p1,p3)<0 &&
    ccw(p2,p3,p0)*ccw(p2,p3,p1)<0;
}

int segmentPos(point p0, point p1, point p2){
    if(p1 == p2) return -2;
    else if(ccw(p0,p1,p2) != 0) return -1; 

    else if (p2 < p1) swap(p1,p2);
    if(p0 < p1) return 1; 

    else if(p2 < p0) return 2; 

    return 0; 

}

int insidePolygon(point P[], int n, point p0){
    P[n] = P[0];
    

    for (int i = 0; i < n; i++)
        if(segmentPos(p0, P[i], P[i+1]) == 0) return 1;
    int dem = 0;
    point Z; Z.x = 1000000007; Z.y = 1000000008;
    while(1){
        int ok = 1;
        for (int i = 0; i < n; i++) if(ccw(Z,P[i],P[i+1]) == 0) {
            ok = 0;
            Z.y++;
        }
        if(ok == 1) break;
    }
    for (int i = 0; i < n; i++) if(isRealCut(p0,Z,P[i],P[i+1])) dem++;
    return (dem%2);
    

    int x1 = 0, x2 = 0;
    for (int i = 0; i < n; i++){
        if(ccw(P[i], P[i + 1], p0) == 0) return 0;
        else if(ccw(P[i], P[i + 1], p0) == -1) x1++;
        else x2++;
    }
    return (!x1 || !x2);
}


void VarInput() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n;
	for (i64 i=0; i<n; i++) {
	    cin >> a[i].x >> a[i].y;
	    a[i].x *= 2; a[i].y *= 2;
	}
}

void ProSolve() {
    i64 ans = 0;
    for (i64 i=1; i<n; i++) {
        char direct = 'N';
        if (a[i-1].x < a[i].x) direct = 'E';
        if (a[i-1].x > a[i].x) direct = 'W';
        if (a[i-1].y > a[i].y) direct = 'S';
        point z = a[i];
        if (direct == 'N') z.y++;
        else if (direct == 'E') z.x++;
        else if (direct == 'W') z.x--;
        else if (direct == 'S') z.y--;
        if (insidePolygon(a, n, z)) ans++;
    }
    cout << ans;
}


int main() {
			#ifdef Akikaze
			

			

			#endif
	VarInput();
			#ifdef Akikaze
			auto TIME1 = chrono::steady_clock::now();
			#endif
	ProSolve();
			#ifdef Akikaze
			auto TIME2 = chrono::steady_clock::now();
			auto DIFF = TIME2 - TIME1;
			cout << "\n\nTime elapsed: " << chrono::duration<double>(DIFF).count() << " seconds.";
			#endif
	return 0;
}