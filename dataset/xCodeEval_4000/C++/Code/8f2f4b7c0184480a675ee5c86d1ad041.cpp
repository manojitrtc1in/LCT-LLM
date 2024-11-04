#include <bits/stdc++.h>

using namespace std;


#define MEMSET_INF 127 

#define set0(a) memset(a,0,sizeof(a));
#define setminus1(a) memset(a,-1,sizeof(a));
#define setinf(a) memset(a,MEMSET_INF,sizeof(a));



#define mp make_pair
#define pb push_back







#define REP(i,n) for(int i = 0;i < (int)(n); i++)
#define REP1(i,a,b) for(int i = (int)(a);i <= (int)(b); i++)
#define REPMAP(i,mm) for(auto i = mm.begin();i !=mm.end(); i++)



#define sortvec(vec) sort(vec.begin(), sort.end())



#define LSOne(i) (i & (-i))	




#define mod %
#define NUM 1000000007


#define LMAX LONG_LONG_MAX
#define LMIN LONG_LONG_MIN
#define IMAX INT_MAX
#define IMIN INT_MIN
#define M_PI		3.14159265358979323846
#define EPS 1e-9
#define INF 1e9



typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<int, int> mii;

#define MAX_N 100005
#define DEG_TO_RAD(x) (x * (M_PI/180.0))
#define RAD_TO_DEG(x) (x * (180.0/M_PI))

bool equal(double a, double b) {
	return (fabs(a - b) < EPS);
}
struct point_i {
	int x, y;
	point_i() {
		x = y = 0;
	}
	point_i(int _x, int _y) :
			x(_x), y(_y) {
	}
};
struct point {
	double x, y;
	point() {
		x = y = 0.0;
	}
	point(double _x, double _y) :
			x(_x), y(_y) {
	}
	bool operator<(point other) const {
		if (equal(x, other.x)) {
			return y < other.y;
		}
		return x < other.x;
	}
	bool operator ==(point other) const {
		return (equal(x, other.x) && equal(y, other.y));
	}
};
double dist(point a, point b) {
	return hypot(a.x - b.x, a.y - b.y);
}
point rotate(point p, double theta) { 

	double rad = DEG_TO_RAD(theta);
	double c = cos(rad);
	double s = sin(rad);
	return point(p.x * c - p.y * s, p.x * s + p.y * c);
}
struct line { 

	double a, b, c;
	line(double _a, double _b, double _c) {
		if (equal(_b, 0.0)) {
			a = 1.0;
			b = 0.0;
			c = _c / _a;
		} else {
			b = 1.0;
			a = _a / _b;
			c = _c / _b;
		}
	}
	double angle(){
		double z = atan2(-a,b);
		if( z < 0)
			z += M_PI;
		return z;
	}
	line(){

	}
};
void pointsToLine(point p1, point p2, line & l) {
	if (equal(p1.x, p2.x)) {
		l.a = 1.0;
		l.b = 0.0;
		l.c = -p1.x;
	} else {
		l.b = 1.0;
		l.a = -(double) (p1.y - p2.y) / (p1.x - p2.x);
		l.c = -(double) (l.a * p1.x) - p1.y;
	}
}
bool areParallel(line l1, line l2) {
	return (equal(l1.a, l2.a) && equal(l1.b, l2.b));
}
bool areSame(line l1, line l2) {
	return (areParallel(l1, l2) && equal(l1.b, l2.b));
}
bool areIntersect(line l1, line l2, point & p) {
	if (areParallel(l1, l2))
		return false;
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	if (!equal(l1.b, 0.0))
		p.y = -(l1.a * p.x + l1.c);
	else
		p.y = -(l2.a * p.x + l2.c);
	return true;
}
struct vec {
	double x, y;
	vec(double _x, double _y) :
			x(_x), y(_y) {
	}
};
vec toVec(point a, point b) { 

	return vec(b.x - a.x, b.y - a.y);
}
vec scale(vec v, double s) {
	return vec(v.x * s, v.y * s);
}
point translate(point p, vec v) {
	return point(p.x + v.x, p.y + v.y);
}
double dot(vec a, vec b) {
	return (a.x * b.x + a.y * b.y);
}
double norm_sq(vec v) {
	return v.x * v.x + v.y * v.y;
}
double magnitude(vec v) {
	return sqrt(norm_sq(v));
}
double distToLine(point p, point a, point b, point &c) {


	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	

	c = translate(a, scale(ab, u)); 

	return dist(p, c);
}
double distToLineSegment(point p, point a, point b, point &c) {
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	if (u < 0.0) {
		c = point(a.x, a.y);
		return dist(p, a);
	}
	if (u > 1.0) {
		c = point(b.x, b.y); 

		return dist(p, b);
	} 

	c = translate(a, scale(ab, u)); 

	return dist(p, c);
}
double angle(point a, point o, point b) { 

	vec oa = toVec(o, a), ob = toVec(o, b);
	return (acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))));
}
double cross(vec a, vec b) {
	return a.x * b.y - a.y * b.x;
}




bool ccw(point p, point q, point r) {
	return cross(toVec(p, q), toVec(p, r)) > 0;
}


bool collinear(point p, point q, point r) {
	return equal(cross(toVec(p, q), toVec(p, r)), 0.0);
}


bool lineIntersectLineSegment(line l, point a, point b, point &c) {
	line l1;
	pointsToLine(a, b, l1);
	bool res = areIntersect(l, l1, c);
	if (!res)
		return res;
	if (equal(dist(a, b), dist(a, c) + dist(b, c)))
		return true;
	return false;
}
struct circle {
	double r, x, y;
};
int pointCircle(point p, circle c) {
	double dx = p.x - c.x, dy = p.y - c.y;
	double e = dx * dx + dy * dy - c.r * c.r;
	if (equal(e, 0.0))
		return 0; 

	else if (e < 0.0)
		return -1; 

	else
		return 1; 

}

































double perimeter(const vector<point> &P) {
	double result = 0.0;
	for (int i = 0; i < (int) P.size() - 1; i++)
		result += dist(P[i], P[i + 1]);
	return result;
}

double area(const vector<point> &P) {
	double result = 0.0, x1, y1, x2, y2;
	for (int i = 0; i < (int) P.size() - 1; i++) {
		x1 = P[i].x;
		x2 = P[i + 1].x;
		y1 = P[i].y;
		y2 = P[i + 1].y;
		result += (x1 * y2 - x2 * y1);
	}
	return fabs(result) / 2.0;
}
bool isConvex(const vector<point> &P) {
	int sz = (int) P.size();
	if (sz <= 3)
		return false;
	bool isLeft = ccw(P[0], P[1], P[2]);
	for (int i = 1; i < sz - 1; i++)
		if (ccw(P[i], P[i + 1], P[(i + 2) == sz ? 1 : i + 2]) != isLeft)
			return false;
	return true;
}


bool inPolygon(point pt, const vector<point> &P) {
	if ((int) P.size() == 0)
		return false;
	double sum = 0;
	for (int i = 0; i < (int) P.size() - 1; i++) {
		if (ccw(pt, P[i], P[i + 1]))
			sum += angle(P[i], pt, P[i + 1]);
		else
			sum -= angle(P[i], pt, P[i + 1]);
	}
	return fabs(fabs(sum) - 2 * M_PI) < EPS;
}


point lineIntersectSeg(point p, point q, point A, point B) {
	double a = B.y - A.y;
	double b = A.x - B.x;
	double c = B.x * A.y - A.x * B.y;
	double u = fabs(a * p.x + b * p.y + c);
	double v = fabs(a * q.x + b * q.y + c);
	return point((p.x * v + q.x * u) / (u + v), (p.y * v + q.y * u) / (u + v));
}






vector<point> cutPolygon(point a, point b, const vector<point> &Q) {
	vector<point> P;
	for (int i = 0; i < (int) Q.size(); i++) {
		double left1 = cross(toVec(a, b), toVec(a, Q[i])), left2 = 0;
		if (i != (int) Q.size() - 1)
			left2 = cross(toVec(a, b), toVec(a, Q[i + 1]));
		if (left1 > -EPS)
			P.push_back(Q[i]); 

		if (left1 * left2 < -EPS)
			

			P.push_back(lineIntersectSeg(Q[i], Q[i + 1], a, b));
	}
	if (!P.empty() && !(P.back() == P.front()))
		P.push_back(P.front());
	

	return P;
}



point pivot(0, 0);
bool angleCmp(point a, point b) { 

	if (collinear(pivot, a, b)) 

		return dist(pivot, a) < dist(pivot, b); 

	double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
	double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
	return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}
vector<point> CH(vector<point> P) {
	int i, j, n = (int) P.size();
	if (n <= 3) {
		if (!(P[0] == P[n - 1]))
			P.push_back(P[0]);
		return P;
	} 



	int P0 = 0;
	for (i = 1; i < n; i++)
		if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
			P0 = i;
	point temp = P[0];
	P[0] = P[P0];
	P[P0] = temp; 



	pivot = P[0]; 

	sort(++P.begin(), P.end(), angleCmp); 

	vector<point> S;
	S.push_back(P[n - 1]);
	S.push_back(P[0]);
	S.push_back(P[1]); 

	i = 2; 

	while (i < n) {
		j = (int) S.size() - 1;

		if(j == 0){ 

			S.clear();
			S.push_back(P[n - 1]);
			S.push_back(P[0]);
			S.push_back(P[n - 1]);
			return S;
		}
		if (ccw(S[j - 1], S[j], P[i]))
			S.push_back(P[i++]); 

		else
			S.pop_back();
	} 

	return S;
}


void solve(){
	point vv;
	int px,py,vx,vy;
	int a,b,c,d;
	cin>>px>>py>>vx>>vy>>a>>b>>c>>d;
	double len = sqrt(vx * vx + vy * vy);
	vv.x = (double)vx/len;
	vv.y = (double)vy/len;
	point p(px,py);
	point ans[7];
	ans[0] = p;
	ans[0] = translate(ans[0],vec(vv.x * b , vv.y * b));
	vv = rotate(vv,90);

	ans[1] = p;
	ans[1] = translate(ans[1],vec((vv.x * a)/2.0 , (vv.y * a)/2.0));
	ans[2] = p;
	ans[2] = translate(ans[2],vec((vv.x * c)/2.0 , (vv.y * c)/2.0));
	vv = rotate(vv,180);
	ans[5] = p;
	ans[5] = translate(ans[5],vec((vv.x * c)/2.0 , (vv.y * c)/2.0));
	ans[6] = p;
	ans[6] = translate(ans[6],vec((vv.x * a)/2.0 , (vv.y * a)/2.0));


	vv = rotate(vv,270);
	ans[3] = ans[2];
	ans[3] = translate(ans[3],vec((vv.x * d) , (vv.y * d)));
	ans[4] = ans[5];
	ans[4] = translate(ans[4],vec((vv.x * d) , (vv.y * d)));

	REP(i,7){
		printf("%.10f %.10f\n",ans[i].x,ans[i].y);
	}

}

int main(){











	int TC = 1;


	for(int ZZ=1;ZZ<=TC;ZZ++){


		solve();


	}
	return 0;
}
