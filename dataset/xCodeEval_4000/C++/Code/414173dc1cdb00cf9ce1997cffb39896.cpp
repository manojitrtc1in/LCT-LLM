#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
typedef	long long ll;
#define all(v) ((v).begin()),((v).end())
#define clr(v,val) memset(v,val,sizeof v)
#define endl "\n"
void file(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 

#endif
}
void fast(){
	std::ios_base::sync_with_stdio(0); cin.tie(NULL);
}
const int N = 1e5 + 20;

const double PI = acos(-1.0);
const double EPS = 1e-9;
template<class T>
istream& operator>> (istream& is, complex<T>& p) {
	T value;
	is >> value;
	p.real(value);
	is >> value;
	p.imag(value);
	return is;
}
double toRadians(double degree){
	return (degree * PI) / 180.0;
}
int dcmp(long double x, long double y) {
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}
double fixAngle(double A) {
	return A > 1 ? 1 : (A < -1 ? -1 : A);
}




typedef complex<double> point;  

#define X real()   

#define Y imag()
#define angle(a)  (atan2((a).imag(), (a).real())) 

#define dist(a)   (hypot((a).imag(), (a).real())) 

#define vec(a,b)  ((b)-(a)) 

#define rotateO(p,ang)    ((p)*exp(point(0,ang)))  

#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)

#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS) 

#define dp(a,b)   ( (conj(a)*(b)).real() )	

#define cp(a,b)   ( (conj(a)*(b)).imag() )	

#define norm(a)  (norm(a))  

#define reflectO(v,m)  (conj((v)/(m))*(m))
#define normalize(a)            (a)/dist(a)
point translate(point p, point v) { 

	return point(p.X + v.X, p.Y + v.Y);
}
point scale(point v, double s) { 

	return point(v.X * s, v.Y * s);
} 



bool cmp(point a, point b){
	if (fabs(a.X - b.X) < EPS) {
		return a.Y < b.Y;
	}
	return a.X < b.X;
}
point reflect(point p, point p0, point p1) {
	point z = p - p0, w = p1 - p0;
	return conj(z / w) * w + p0;  

}




double angleO(point a, point O, point b) {
	point v1(a - O), v2(b - O);
	return acos(fixAngle(dp(v1, v2) / dist(v1) / dist(v2)));
}
double getAng(point &a, point &b, point &c) 

{
	double ang = angle(vec(b, c)) - angle(vec(b, a));
	

	ang += 2 * PI;
	return ang;
}


double getAngle_A_abc(double a, double b, double c){
	return acos(fixAngle((b*b + c*c - a*a) / (2.0 * b*c)));
}
bool is_between(point p, point q, point c) {
	return c.X < max(p.X, q.X) + EPS
		&& c.X + EPS > min(p.X, q.X)
		&& c.Y < max(p.Y, q.Y) + EPS
		&& c.Y + EPS > min(p.Y, q.Y);
}


struct line {
	double a, b, c;
};
void pointsToLine(point p1, point p2, line &l) {
	if (fabs(p1.X - p2.X) < EPS) { 

		l.a = 1.0; l.b = 0.0; l.c = -p1.X; 

	}
	else {
		l.a = -(double)(p1.Y - p2.Y) / (p1.X - p2.X);
		l.b = 1.0; 

		l.c = -(double)(l.a * p1.X) - p1.Y;
	}
}
void pointsToLine(double a, double b, double c, line &l){
	if (b != 0) {
		a = a / b;
		c = c / b;
		b = 1;
	}
	else {
		c = c / a;
		a = 1;
		b = 0;
	}
	l.a = a, l.b = b, l.c = c;
}
bool areParallel(line l1, line l2) { 

	return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}
bool areSame(line l1, line l2) { 

	return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}
bool areIntersect(line l1, line l2, point &p) {
	if (areParallel(l1, l2) && !areSame(l1, l2)) return false; 

	

	p.real((l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b));
	

	if (fabs(l1.b) > EPS) p.imag(-(l1.a * p.X + l1.c));
	else p.imag(-(l2.a * p.X + l2.c));
	return true;
}
bool isCollinear(point a, point b, point c) {
	return fabs(cp(b - a, c - a)) < EPS;
}
bool isPointOnRay(point p0, point p1, point p2) {
	if (dist(p2 - p0) < EPS) return true;
	return same(normalize(p1 - p0), normalize(p2 - p0));
}
bool isPointOnSegment(point a, point b, point c) {
	return isPointOnRay(a, b, c) && isPointOnRay(b, a, c);
}
double distToLine(point p0, point p1, point p2) {
	return fabs(cp(p1 - p0, p2 - p0) / dist(p0 - p1)); 

}


double distToSegment(point p0, point p1, point p2, point &p4) {
	double d1, d2;
	point v1 = p1 - p0, v2 = p2 - p0;
	if ((d1 = dp(v1, v2)) <= 0)	{
		p4 = p0;
		return dist(p2 - p0);
	}
	if ((d2 = dp(v1, v1)) <= d1){
		p4 = p1;
		return dist(p2 - p1);
	}
	double t = d1 / d2;
	p4 = (p0 + v1*t);  

	return dist(p2 - (p0 + v1*t));
}
bool intersectSegments(point a, point b, point c, point d, point & intersect) {
	double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
	if (fabs(d1) < EPS)
		return false;  


	double t1 = (double)d2 / d1, t2 = d3 / d1;
	intersect = a + (b - a) * t1;

	if (t1 > 1 + EPS || t1 < -EPS || t2 < -EPS || t2 > 1 + EPS)
		return false;  

	return true;
}








int ccw(point a, point b, point c) {
	point v1(b - a), v2(c - a);
	double t = cp(v1, v2);

	if (t > +EPS)
		return 1;
	if (t < -EPS)
		return -1;
	if (v1.X * v2.X < -EPS || v1.Y * v2.Y < -EPS)
		return -1;
	if (norm(v1) < norm(v2) - EPS)
		return +1;
	return 0;
}
bool intersect(point p1, point p2, point p3, point p4) {
	

	bool x = (p1 == p2), y = (p3 == p4);
	if (x && y)  return p1 == p3;
	if (x)   return ccw(p3, p4, p1) == 0;
	if (y)   return ccw(p1, p2, p3) == 0;

	return  ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
		ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
}








bool is_insideCircle(point center, point b, double r){
	double d1 = (b.X - center.X);
	double d2 = (b.Y - center.Y);
	return (d1*d1 + d2*d2) <= r*r;
}
bool circle2PtsRad(point p1, point p2, double r, point &c) {
	double d2 = (p1.X - p2.X) * (p1.X - p2.X) +
		(p1.Y - p2.Y) * (p1.Y - p2.Y);
	double det = r * r / d2 - 0.25;
	if (det < 0.0) return false;
	double h = sqrt(det);
	c.real((p1.X + p2.X) * 0.5 + (p1.Y - p2.Y) * h);
	c.imag((p1.Y + p2.Y) * 0.5 + (p2.X - p1.X) * h);
	return true;
	

}
pair<double, point> findCircle(point a, point b, point c) {
	

	point m1 = (b + a)*0.5, v1 = b - a, pv1 = point(v1.Y, -v1.X);
	point m2 = (b + c)*0.5, v2 = b - c, pv2 = point(v2.Y, -v2.X);
	point end1 = m1 + pv1, end2 = m2 + pv2, center;
	intersectSegments(m1, end1, m2, end2, center);
	return make_pair(dist(a - center), center);
}
vector<point> intersectLineCircle(point p0, point p1, point C, double r) {
	double a = dp(p1 - p0, p1 - p0), b = 2 * dp(p1 - p0, p0 - C),
		c = dp(p0 - C, p0 - C) - r*r;
	double f = b*b - 4 * a*c;

	vector<point> v;
	if (dcmp(f, 0) >= 0) {
		if (dcmp(f, 0) == 0)	f = 0;
		double t1 = (-b + sqrt(f)) / (2 * a);
		double t2 = (-b - sqrt(f)) / (2 * a);
		v.push_back(p0 + t1*(p1 - p0));
		if (dcmp(f, 0) != 0)	v.push_back(p0 + t2*(p1 - p0));
	}
	return v;
}
vector<point> intersectCircleCircle(point c1, double r1, point c2, double r2) {
	

	if (same(c1, c2) && dcmp(r1, r2) == 0 && dcmp(r1, 0) > 0)
		return vector<point>(3, c1);    


	

	double ang1 = angle(c2 - c1), ang2 = getAngle_A_abc(r2, r1, dist(c2 - c1));

	if ((ang2)<0) 

		ang2 = 0; 


	vector<point> v(1, polar(r1, ang1 + ang2) + c1);

	

	if (dcmp(dp(v[0] - c1, v[0] - c1), r1*r1) != 0 ||
		dcmp(dp(v[0] - c2, v[0] - c2), r2*r2) != 0)
		return vector<point>();

	v.push_back(polar(r1, ang1 - ang2) + c1);
	if (same(v[0], v[1]))  

		v.pop_back();
	return v;
}
bool is_intersect_circles(double x1, double y1, double r1, double x2, double y2, double r2){
	double x = x1 - x2;
	double y = y1 - y2;
	double dist = sqrt(x*x + y*y);
	return dist < (r1 + r2) && (abs(r1 - r2) <= dist);
}


double dist1(double x1, double y1, double x2, double y2){
	double x11 = (x1 - x2);
	double y11 = (y1 - y2);
	return (x11*x11) + (y11*y11);
}
pair<double, double> center(double x1, double y1, double x2, double y2, double rr) {
	double ab = dist1(x1, y1, x2, y2);
	double k = sqrt(rr / ab - 0.25);
	pair<double, double> o;
	o.first = (x1 + x2) / 2.0 + k * (y2 - y1);
	o.second = (y1 + y2) / 2.0 + k * (x1 - x2);
	return o;
}







double perimeter_triangle(double a, double b, double c){
	return a + b + c;
}
double area_triangle(double a, double b, double c){
	double s = 0.5 * perimeter_triangle(a, b, c);
	return sqrt(s * (s - a) * (s - b)*(s - c));
}
double rInCircle(double ab, double bc, double ca) {
	return area_triangle(ab, bc, ca) / (0.5 * perimeter_triangle(ab, bc, ca));
}
double rInCircle(point a, point b, point c) {
	return rInCircle(dist(a - b), dist(b - c), dist(c - a));
}








int inCircle(point p1, point p2, point p3, point &ctr, double &r) {
	r = rInCircle(p1, p2, p3);
	if (fabs(r) < EPS) return 0; 

	line l1, l2; 

	double ratio = dist(p1 - p2) / dist(p1 - p3);
	point p = translate(p2, scale(vec(p2, p3), ratio / (1 + ratio)));
	pointsToLine(p1, p, l1);
	ratio = dist(p2 - p1) / dist(p2 - p3);
	p = translate(p1, scale(vec(p1, p3), ratio / (1 + ratio)));
	pointsToLine(p2, p, l2);
	areIntersect(l1, l2, ctr); 

	return 1;
}
double rCircumCircle(double ab, double bc, double ca) {
	return ab * bc * ca / (4.0 * area_triangle(ab, bc, ca));
}
double rCircumCircle(point a, point b, point c) {
	return rCircumCircle(dist(a - b), dist(b - c), dist(c - a));
}

double polygon_area(vector<point>points){
	double area = 0;
	for (int i = 0; i < points.size() - 1; i++){
		area += cp(vec(points[0], points[i]), vec(points[0], points[i + 1]));
		

		

		

		

	}
	return abs(area / 2.0);
}
bool lineLineIntersection(point  A, point B, double a2, double b2, double c2, point &inters)
{
	double a1 = B.Y - A.Y;
	double b1 = A.X - B.X;
	double c1 = a1*(A.Y) + b1*(A.Y);
	double determinant = a1*b2 - a2*b1;
	if (determinant == 0){
		return 0;
	}
	else
	{
		double x = 0;
		double y = 0;
		if ((b2*c1 - b1*c2) != 0){
			x = (b2*c1 - b1*c2) / determinant;
		}
		if ((a1*c2 - a2*c1) != 0){
			y = (a1*c2 - a2*c1) / determinant;
		}
		cout << x << " " << y << endl;
		inters = point(x, y);
		return 1;
	}
}

int main()
{
	file();
	fast();

	point home, uni;
	cin >> home >> uni;
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++){
		ll a, b, c;
		cin >> a >> b >> c;
		ll s1 = home.X *a + home.Y*b + c;
		ll s2 = uni.X *a + uni.Y*b + c;
		if ((s1<0 && s2>0) || (s1>0 && s2 < 0)){
			cnt++;
		}
	}
	cout << cnt << endl;
}