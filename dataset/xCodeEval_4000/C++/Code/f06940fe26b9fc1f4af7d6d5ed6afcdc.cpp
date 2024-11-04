




#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;



#define int long long
typedef long long ll;


#define vec vector
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int, int>
#define vii vector<ii>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ALL(x) begin(x),end(x)
#define SZ(x) ((int)(x).size())
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORE(i, a, b) for(int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)


#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),(x))-c.begin())
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define RESET(X, y) memset(X, y, sizeof(X))
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define max3(a, b, c) max({a, b, c})
#define min3(a, b, c) min({a, b, c})



void __print(int x) {cout << x;}
void __print(long x) {cout << x;}


void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif




const long long INF64 = 1e18; const int INF32 = 1e9; const int BIG = (int)(1e9 + 239);
const int MOD = 1000000007; 

const double PI = 2.0*acos(0.0); 

const double EPS = static_cast<double>(1e-10);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int dx[4] = {0, 1, 0, -1}; const int dy[4] = {1, 0, -1, 0};



mt19937 rnd(239); 


typedef vector<vector<int>> matrix;   






void FILEIO() {  freopen("in.txt", "r", stdin);  freopen("out.txt", "w", stdout); }





#define odd(x) ((x) & 1)
#define even(x) !((x) & 1)

int mostSignDigit(int n) { double k = log10(n); return pow(10, k-floor(k));}
int numOfDigits(int n) {return floor(log10(n)) + 1;}
bool isPowerOfTwo(int x) {return x && (!(x&(x-1)));} 


bool allPositive(vector<int> &a) {return all_of(begin(a), end(a), [](int x){return x > 0;});} 

bool anyPositive(vector<int> &a) {return any_of(begin(a), end(a), [](int x){return x > 0;});} 

bool nonePositive(vector<int> &a) {return none_of(begin(a), end(a), [](int x){return x > 0;});} 






struct Point {
	int x, y;
	Point() : x(0), y(0) {}
	Point(int x, int y) : x(x), y(y) {}
	Point(const Point & p) : x(p.x), y(p.y) {}
	bool operator< (const Point & p) const {return make_pair(x,y) < make_pair(p.x, p.y);}
	bool operator == (const Point & p) const {return make_pair(x,y) == make_pair(p.x, p.y);}
	bool operator != (const Point & p) const {return ! (*this == p); }
    Point operator = (const Point & p) { x = p.x, y = p.y;  return *this; }
    Point operator + (const Point & p) const { return Point(x+p.x, y+p.y);}
    Point operator - (const Point & p) const { return Point(x-p.x, y-p.y);}
    Point operator * (int c) const { return Point(x*c, y*c);}
};
int cross(Point p, Point q) {return p.x * q.y - p.y * q.x;}
int dot(Point p, Point q) {return (int)p.x*q.x + (int)p.y*q.y;}
int dist2(Point p, Point q) {return dot(p-q, p-q);}  

double dist(Point p, Point q) {return sqrt(dot(p-q, p-q)); }
int area2(Point a, Point b, Point c) {return abs(cross(b-a, c-a)); } 





void show(vec<pair<Point, int>> & vp) {
	FOR(i, 0, SZ(vp)) cout << vp[i].F.x << "," << vp[i].F.y << ";" << vp[i].S <<" ";
	cout << endl;
}





















































































bool comp2(Point A, Point B, Point C, Point D) {

	long double d1 = dot(A, B); 

	long double d2 = dot(C, D); 

	Point O(0.0, 0.0);
	long double ab = dist(O, A) * dist(O, B); ab *= d2;
	long double cd = dist(O, C) * dist(O, D); cd *= d1;
	return ( cd > ab );
}





















bool top(Point p) {
    return p.y < 0 || (p.y == 0 && p.x < 0);
}








































































#define double long double 

double angle(Point a) { 

	if(a.x==0) if(a.y>0) return PI/2.0; else return 3.0*PI/2.0;
	if(a.y==0) if(a.x>0) return 0; else return PI;
	double res=atan((double)a.y/(double)a.x);
	if(a.x<0) return res+PI; if(a.y<0) return res+2.0*PI;
	return res;
}
bool polarLess(Point a, Point b) {
	return angle(a) < angle(b);
}
bool comp(pair<Point, int> pa, pair<Point, int> pb) {
	if (polarLess(pa.F, pb.F)) return true;
	return false; 

}
bool angleLess(const Point& a1, const Point& b1, const Point& a2, const Point& b2) {
	double db1 = angle(b1), da1=angle(a1), db2=angle(b2), da2=angle(a2);
	double dif1 = fabs(db1-da1), dif2 = fabs(db2-da2);
    return min(dif1, 2*PI - dif1) < min(dif2, 2*PI - dif2);
}

void solve() {
	int n; cin >> n;
	vec<pair<Point, int>> vp(n); FOR(i, 0, n) {cin >> vp[i].F.x >> vp[i].F.y; vp[i].S=i+1;}




	sort(ALL(vp), comp);




	int idx1=0, idx2=1;


	FOR(i, 0, n) {
		Point A = vp[idx1].F, B = vp[idx2].F, C = vp[i].F, D = vp[(i+1)%n].F;




		if( angleLess(C, D, A, B) )  idx1=i, idx2=(i+1)%n; 







	}











	cout << vp[idx1].S << " " << vp[idx2].S << endl;
}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie();









  {




	  solve();
  }






  return 0;
}
