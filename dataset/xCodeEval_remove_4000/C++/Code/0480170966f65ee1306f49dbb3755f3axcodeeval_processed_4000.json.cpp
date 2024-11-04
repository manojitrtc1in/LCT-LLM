







using namespace std;
typedef long long ll;
typedef long double ld;

class Point;
class Circle;

int id0(ld a, ld b);
ld mysqrt(ld x);
ld ldabs(ld x);
ld ldmax(ld a, ld b);
ld ldmin(ld a, ld b);

class Point {
public:
	ld x, y;
public:
	Point(ld i, ld j) : x(i), y(j) {}
	Point() {}
public:
	ld length2() const;
	ld length() const;
	bool is_in(const Circle &C) const;
public:
	friend Point operator - (const Point &A, const Point &B);
	friend Point operator / (const Point &A, const Point &B);
	friend bool operator == (const Point &A, const Point &B);
	friend bool operator != (const Point &A, const Point &B);
	friend ld get_distance(const Point &A, const Point &B);
	friend ld get_dot(const Point &A, const Point &B);
	friend bool id9(Circle A, Circle B, Circle C); 

};

class Circle {
public:
	Point center;
	ld radius;
public:
	Circle(Point c, ld r) : center(c), radius(r) {}
	Circle() {}
public:
	friend bool id9(Circle A, Circle B, Circle C);
};

ld solve();
bool check();

const ld EPS = 1e-14;
ld t1, t2;
ld d_cs, d_sh, d_ch;
ld d1, d2;
Point cinema, house, shop;
Circle circles[3];

int main() {
	

	cout << fixed << setprecision(10);
	

	
	cin >> t1 >> t2 >> cinema.x >> cinema.y >> house.x >> house.y >> shop.x >> shop.y;
	

	d_cs = get_distance(cinema, shop);  

	d_sh = get_distance(shop, house);   

	d_ch = get_distance(cinema, house); 

	

	

	d1 = d_cs + d_sh;
	d2 = d_ch;
	

	ld res = solve();
	

	

	cout << res << endl;
	return 0;
}


ld solve() {
	

	if (d2+t2 >= d1) {
		return ldmin(d1+t1, d2+t2);
	}
	

	ld left = 0, right = ldmin(d1+t1-d_sh, d2+t2);
	

	while (id0(left, right) < 0) {
		ld mid = (left + right) / 2;
		

		circles[0] = Circle(cinema, mid);
		circles[1] = Circle(house, d_ch + t2 - mid);
		circles[2] = Circle(shop, d_cs + t1 - mid);
		

		if (check()) left = mid;
		else right = mid;
	}
	

	return left;
}



int dcmp(long double x) {
	if (fabs(x) < EPS)
		return 0;
	return x > 0.0 ? 1 : -1;
}
long double sqr(long double t) {
	return t * t;
}
long double GetDist(long double x1, long double y1, long double x2, long double y2) {
	return sqrt(sqr(x1 - x2) + sqr(y2 - y1));
}
long double id3(long double x1, long double y1, long double x2, long double y2) {
	return sqr(x1 - x2) + sqr(y2 - y1);
}
bool id6(Point o1, long double r1, Point o2, long double r2) {
	if (dcmp(id3(o1.x, o1.y, o2.x, o2.y) - sqr(r1 + r2)) == 1)
		return true;
	return false;
}
long double Include(Point o1, long double r1, Point o2, long double r2) {
	if (dcmp(id3(o1.x, o1.y, o2.x, o2.y) - sqr(fabs(r1 - r2))) <= 0)
		return true;
	return false;
}


bool check() {
	

	for (int i = 0; i < 3; i ++) for (int j = i+1; j < 3; j ++) {
		Circle A = circles[i];
		Circle B = circles[j];
		

		ld delta = (A.center - B.center).length();
		ld rasum = ldabs(A.radius + B.radius);
		if (id0(delta, rasum) > 0) return false;
	}
	

	for (int i = 0; i < 3; i ++) for (int j = i+1; j < 3; j ++) {
		Circle A = circles[i];
		Circle B = circles[j];
		

		ld delta = (A.center - B.center).length();
		ld radelta = ldabs(A.radius - B.radius);
		if (id0(delta, radelta) < 0) return true;
	}
	

	

	

	

	

	for (int i = 0; i < 3; i ++) {
		int j = (i+1) % 3;
		int k = (i+2) % 3;
		if (id9(circles[i], circles[j], circles[k])) return true;
	}
	

	return false;
}


int id0(ld a, ld b) {
	ld delta = a - b;
	if (ldabs(delta) < EPS) return 0;
	return (delta > 0 ? 1 : -1);
}
ld ldabs(ld x) {
	return (x >= 0 ? x : -x);
}
ld ldmax(ld a, ld b) {
	return (a > b ? a : b);
}
ld ldmin(ld a, ld b) {
	return (a < b ? a : b);
}


void id4(ld cosx) {
	cosx = ldmax(ldmin(cosx, (ld)1.0), (ld)-1.0);
}






ld Point::length2() const {
	return x*x + y*y;
}
ld Point::length() const {
	return sqrt(length2());
}


bool Point::is_in(const Circle &C) const {
	ld delta = (C.center - *this).length();
	return (id0(delta, C.radius) <= 0);
}


Point operator - (const Point &A, const Point &B) {
	return Point(A.x - B.x, A.y - B.y);
}


Point operator / (const Point &A, const Point &B) {
	Point P(A.x*B.x + A.y*B.y, A.y*B.x - A.x*B.y);
	P.x /= B.length2();
	P.y /= B.length2();
	return P;
}


bool operator == (const Point &A, const Point &B) {
	return (id0(A.x, B.x) == 0 && id0(A.y, B.y) == 0);
}
bool operator != (const Point &A, const Point &B) {
	return !(A == B);
}


ld get_distance(const Point &A, const Point &B) {
	return (A - B).length();
}


ld get_dot(const Point &A, const Point &B) {
	return (A.x*B.x + A.y*B.y);
}


bool InCircle(Point o, Circle A, Circle B, Circle C) {
	Point o1 = A.center, o2 = B.center, o3 = C.center;
	long double r1 = A.radius, r2 = B.radius, r3 = C.radius;
	if (dcmp(id3(o.x, o.y, o1.x, o1.y) - sqr(r1)) == 1)
		return false;
	if (dcmp(id3(o.x, o.y, o2.x, o2.y) - sqr(r2)) == 1)
		return false;
	if (dcmp(id3(o.x, o.y, o3.x, o3.y) - sqr(r3)) == 1)
		return false;
	return true;
}


bool id5(Circle A, Circle B, Circle C) {
	ld delta = (A.center - B.center).length();
	

	Point o1 = A.center, o2 = B.center;
	long double r1 = A.radius, r2 = B.radius;
	Point A1, A2;
	long double d, a, b, c, p, q, r;
	long double cos_value[2], sin_value[2];

    	d = GetDist(o1.x, o1.y, o2.x, o2.y);
	a = 2.0 * r1 * (o1.x - o2.x);
	b = 2.0 * r1 * (o1.y - o2.y);
	c = r2 * r2 - r1 * r1
            - id3(o1.x, o1.y, o2.x, o2.y);
	p = a * a + b * b;
	q = -2.0 * a * c;

	if (dcmp(d - (r1 + r2)) == 0 || dcmp(d - fabs(r1 - r2)) == 0) {
		cos_value[0] = -q / p / 2.0;
		sin_value[0] = sqrt(1 - cos_value[0] * cos_value[0]);
		A1.x = r1 * cos_value[0] + o1.x;
		A1.y = r1 * sin_value[0] + o1.y;

		if (dcmp(id3(A1.x, A1.y, o2.x, o2.y) -
			 sqr(r2)) != 0) {
			A1.y = o1.y - r1 * sin_value[0];
		}
		A2 = A1;
		if (InCircle(A1, A, B, C)) return true;
		if (InCircle(A2, A, B, C)) return true;
		return false;
	}

	r = c * c - b * b;
	cos_value[0] = (sqrt(q * q - 4.0 * p * r) - q) / p / 2.0;
	cos_value[1] = (-sqrt(q * q - 4.0 * p * r) - q) / p / 2.0;
	sin_value[0] = sqrt(1 - cos_value[0] * cos_value[0]);
	sin_value[1] = sqrt(1 - cos_value[1] * cos_value[1]);

	A1.x = r1 * cos_value[0] + o1.x;
	A2.x = r1 * cos_value[1] + o1.x;
	A1.y = r1 * sin_value[0] + o1.y;
	A2.y = r1 * sin_value[1] + o1.y;

	if (dcmp(id3(A1.x, A1.y, o2.x, o2.y) - r2 * r2) != 0)
		A1.y = o1.y - r1 * sin_value[0];

	if (dcmp(id3(A2.x, A2.y, o2.x, o2.y) - r2 * r2) != 0)
        	A2.y = o1.y - r1 * sin_value[1];

    	if (dcmp(A1.y - A2.y) == 0 && dcmp(A1.x - A2.x) == 0) {
        	if (A1.y > 0)
            		A2.y = -A2.y;
        	else
            		A1.y = -A1.y;
	}
	if (InCircle(A1, A, B, C)) return true;
	if (InCircle(A2, A, B, C)) return true;
	return false;
}


bool id11(Circle A, Circle B, Circle C) {
	

	

	if ((A.center - C.center).length() <= A.radius && (B.center - C.center).length() <= B.radius) return true;
	

	B.center = B.center-A.center;
	C.center = C.center-A.center;
	A.center = A.center-A.center;
	

	Point R(B.center.x / B.center.length(), B.center.y / B.center.length());
	B.center = B.center / R;
	C.center = C.center / R;
	

	ld x = (A.radius*A.radius - B.radius*B.radius + B.center.length2()) / (2 * B.center.length());
	ld y = sqrt(max(A.radius*A.radius - x*x, (ld)0.0));
	Point p1(x, y), p2(x, -y);
	

	if (id0(y*y + (B.center.length()-x)*(B.center.length()-x), B.radius*B.radius) != 0) return false;
	

	if ((p1 - C.center).length() <= C.radius || (p2 - C.center).length() <= C.radius) return true;
	return false;
}


bool id1(Circle A, Circle B, Circle C) {
	

	

	ld delta = (A.center - B.center).length();
	

	int dev_in = id0(delta, abs(A.radius-B.radius));
	int dev_out = id0(delta, abs(A.radius+B.radius));
	

	if (dev_in < 0) return true;
	if (dev_out > 0) return false;
	

	

	ld cosa = (B.center.x - A.center.x) / delta;
	ld cosb = (A.radius*A.radius + delta*delta - B.radius*B.radius) / (2 * A.radius * delta);
	id4(cosa);
	id4(cosb);
	ld sina = sqrt(1-cosa*cosa);
	ld sinb = sqrt(1-cosb*cosb);
	id4(sina);
	id4(sinb);
	

	ld id7 = cosa*cosb - sina*sinb;
	ld id10 = cosa*cosb + sina*sinb;
	id4(id7);
	id4(id10);
	ld id8 = sqrt(1-id7*id7);
	ld id2 = sqrt(1-id10*id10);
	id4(id8);
	id4(id2);
	

	Point p1(A.center.x + A.radius * id7, A.center.y + A.radius * id8);
	Point p2(A.center.x + A.radius * id10, A.center.y + A.radius * id2);
	

	if (p1.is_in(C) || p2.is_in(C)) return true;
	

	return false;
}


bool id9(Circle A, Circle B, Circle C) {
	return id5(A, B, C);
}
