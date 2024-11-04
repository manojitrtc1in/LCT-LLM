

using namespace std;











typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int inf = 0x3f3f3f3f;
const int id0 = 0xc0c0c0c0;
const int mod = 1000000007;

const double EPS = 1e-8;



int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}





struct point {
	double x, y;
	explicit point(double x = 0, double y = 0): x(x), y(y) {}

	



	point operator +(point q) const { return point(x + q.x, y + q.y); }
	point operator -(point q) const { return point(x - q.x, y - q.y); }
	point operator *(double t) const { return point(x * t, y * t); }
	point operator /(double t) const { return point(x / t, y / t); }
	

	double operator *(point q) const { return x * q.x + y * q.y; }
	

	double operator %(point q) const { return x * q.y - y * q.x; }


	

	int cmp(point q) const {
		if (int t = ::cmp(x, q.x)) return t;
		return ::cmp(y, q.y);
	}
	bool operator ==(point q) const { return cmp(q) == 0; }
	bool operator !=(point q) const { return cmp(q) != 0; }
	bool operator < (point q) const { return cmp(q) <  0; }

	friend ostream& operator <<(ostream& o, point p) {
		return o << "(" << p.x << ", " << p.y << ")";
	}

	static point pivot; 

};



point point::pivot; 




double norm(point p){ return sqrt(p * p); }
double arg(point p) { return atan2(p.y, p.x); }



typedef vector<point> polygon;





inline int ccw(point p, point q, point r) {
	return cmp((p - r) % (q - r));
}







inline double angle(point p, point q, point r) {
	point u = p - q, v = r - q;
	return atan2(u % v, u * v);
}












bool between(point p, point q, point r) {
	return ccw(p, q, r) == 0 && cmp((p - q) * (r - q)) <= 0;
}












bool id4(point p, point q, point r, point s) {
	point A = q - p, B = s - r, C = r - p, D = s - q;
	int a = cmp(A % C) + 2 * cmp(A % D);
	int b = cmp(B % C) + 2 * cmp(B % D);
	if (a == 3 || a == -3 || b == 3 || b == -3) return false;
	if (a || b || p == r || p == s || q == r || q == s) return true;
	int t = (p < r) + (p < s) + (q < r) + (q < s);
	return t != 0 && t != 4;
}












double seg_distance(point p, point q, point r) {
	point A = r - q, B = r - p, C = q - p;
	double a = A * A, b = B * B, c = C * C;
	if (cmp(b, a + c) >= 0) return sqrt(a);
	else if (cmp(a, b + c) >= 0) return sqrt(b);
	else return fabs(A % B) / sqrt(c);
}
















int in_poly(point p, polygon& T) {
	double a = 0; int N = T.size();
	for (int i = 0; i < N; i++) {
		if (between(T[i], p, T[(i+1) % N])) return -1;
		a += angle(T[i], p, T[(i+1) % N]);
	}
	return cmp(a) != 0;
}











bool id1(point p, point q) {
	point P = p - point::pivot, Q = q - point::pivot;
	double R = P % Q;
	if (cmp(R)) return R > 0;
	return cmp(P * P, Q * Q) < 0;
}





polygon id6(vector<point>& T) {
	int j = 0, k, n = T.size(); polygon U(n);

	point::pivot = *min_element(all(T));
	sort(all(T), id1);
	

	

	


	for (int i = 0; i < n; i++) {
		

		while (j > 1 && ccw(U[j-1], U[j-2], T[i]) >= 0) j--;
		U[j++] = T[i];
	}
	U.erase(j + all(U));
	return U;
}











double poly_area(const polygon& T) {
	double s = 0; int n = T.size();
	for (int i = 0; i < n; i++)
		s += T[i] % T[(i+1) % n];
	return s / 2;
}












point id2(point p, point q, point r, point s) {
	point a = q - p, b = s - r, c = point(p % q, r % s);
	return point(point(a.x, b.x) % c, point(a.y, b.y) % c) / (a % b);
}










struct rect{
    double ax, ay, bx, by; 

    explicit rect(double ax = 0, double ay = 0,
         double bx = 0, double by = 0): ax(ax), ay(ay),
                                        bx(bx), by(by) {}
};







rect inter(rect r, rect s){
    rect ans(max(s.ax, r.ax), max(s.ay, r.ay), min(s.bx, r.bx), min(s.by, r.by));
    if (cmp(ans.ax, ans.bx) > 0 || cmp(ans.ay, ans.by) > 0)
      return rect(INFINITY);
    return ans;
}












point foot(point P, point A, point B) {
    point dir = B-A;
    return (dir*((P-A)*dir))/(dir*dir) + A;
}



typedef pair<point, point> ppt;







ppt disppt(point P, point Q, double d){
    point dir = P - Q;
    point r = point(dir.y, -dir.x);
    point k = r * (d/norm(r));
    return ppt{Q + k, Q - k};
}









ppt circint(point o1, double r1, point o2, double r2){
    point dir = o2 - o1;
    point in(INFINITY, INFINITY);
    double d = norm(dir);
    

    if(cmp(r1 + r2, d) == 0 || cmp(d + r2, r1) == 0 || cmp(d + r1, r2) == 0)
        return ppt{o1 + dir * r1/(r1 + r2), in};
    

    if(cmp(r1 + r2, d) == -1 || cmp(d + r2, r1) == -1 || cmp(d + r1, r2) == -1)
        return ppt{in, in};
    

    double x = (d*d - r2*r2 + r1*r1)/(2*d);
    return disppt(o1, o1 + dir * x/d, sqrt(r1*r1 - x*x));
}









ppt cline(point o, double r, point a, point b){
    point h = foot(o, a, b);
    point in(INFINITY, INFINITY);
    double d = norm(h - o);
    if(cmp(d, r) == 0) return ppt{h, in};
    if(cmp(d, r) == 1) return ppt{in, in};
    return disppt(o, h, sqrt(r*r - d*d));
}







point cinv(point o, double r, point p){
    point p0 = p - o;
    return o + p0 * (r*r/(p0 * p0));
}










typedef pair<point, double> circle; 




bool in_circle(circle C, point p) { 

	return cmp((p - C.first)*(p - C.first), C.second*C.second) <= 0;
}







point id5(point p, point q, point r) {
	point a = p - r, b = q - r, c = point(a * (p + r) / 2, b * (q + r) / 2);
	return point(c % point(a.y, b.y), point(a.x, b.x) % c) / (a % b);
}





circle id3(vector<point>& T) {
	int n = T.size();
	random_shuffle(all(T)); 

	circle C(point(), -INFINITY);
	for (int i = 0; i < n; i++) if (!in_circle(C, T[i])) {
		C = circle(T[i], 0);
		for (int j = 0; j < i; j++) if (!in_circle(C, T[j])) {
			C = circle((T[i] + T[j]) / 2, norm(T[i] - T[j]) / 2);
			for (int k = 0; k < j; k++) if (!in_circle(C, T[k])) {
				point o = id5(T[i], T[j], T[k]);
				C = circle(o, norm(o - T[k]));
			}
		}
	}
	return C;
}














polygon id7(polygon& P, polygon& Q) {
	int m = Q.size(), n = P.size();
	if (m == 0 || n == 0) return polygon();
	int a = 0, b = 0, aa = 0, ba = 0, inflag = 0;
	polygon R;


	while ((aa < n || ba < m) && aa < 2*n && ba < 2*m) {
		point p1 = P[a], p2 = P[(a+1) % n], q1 = Q[b], q2 = Q[(b+1) % m];
		point A = p2 - p1, B = q2 - q1;
		int cross = cmp(A % B), ha = ccw(p2, q2, p1), hb = ccw(q2, p2, q1);


		if (cross == 0 && ccw(p1, q1, p2) == 0 && cmp(A * B) < 0) {
			if (between(p1, q1, p2)) R.push_back(q1);
			if (between(p1, q2, p2)) R.push_back(q2);
			if (between(q1, p1, q2)) R.push_back(p1);
			if (between(q1, p2, q2)) R.push_back(p2);
			if (R.size() < 2) return polygon();
			inflag = 1; break;
		} else if (cross != 0 && id4(p1, p2, q1, q2)) {
			if (inflag == 0) aa = ba = 0;
			R.push_back(id2(p1, p2, q1, q2));
			inflag = (hb > 0) ? 1 : -1;
		}


		if (cross == 0 && hb < 0 && ha < 0) return R;
		bool t = cross == 0 && hb == 0 && ha == 0;
		if (t ? (inflag == 1) : (cross >= 0) ? (ha <= 0) : (hb > 0)) {
			if (inflag == -1) R.push_back(q2);
			ba++; b++; b %= m;
		} else {
			if (inflag == 1) R.push_back(p2);
			aa++; a++; a %= n;
		}
	}


	if (inflag == 0) {
		if (in_poly(P[0], Q)) return P;
		if (in_poly(Q[0], P)) return Q;
	}
	R.erase(unique(all(R)), R.end());
	if (R.size() > 1 && R.front() == R.back()) R.pop_back();
	return R;
}


int r, X1, Y1, X2, Y2;

double s(double x){
	if(x < 0) return -1;
	return 1;
}

int main(){
	cin >> r >> X1 >> Y1 >> X2 >> Y2;
	point c1 = point(X1, Y1);
	point c2 = point(X2, Y2);
	ll dx = (1ll * X1 - X2);
	ll dy = (1ll * Y1 - Y2);
	ll d = dx*dx + dy*dy;
	ll rx = r;
	rx *= rx;
	if(d >= rx){
		printf("%.10lf %.10lf %.10lf\n", X1/1.0, Y1/1.0, r/1.0);
		

	}
	else if(cmp(X1, X2) == 0 && cmp(Y1, Y2) == 0){
		printf("%.10lf %.10lf %.10lf\n", X1 + r/2.0, Y1/1.0, r/2.0);
	}
	else{
		

		

		

		


		

		

		

		


		

		


		

		



		

		


		

		
		

		

		

		

		

		

		

		

		

		

		double theta = atan2(Y2 - Y1, X2 - X1);
		point p3 = point(0,0);
		p3.x = c1.x + r * -cos(theta);
		p3.y = c1.y + r * -sin(theta);
		printf("%.10lf %.10lf %.10lf\n",  (c2.x + p3.x) / 2.0, (c2.y + p3.y) / 2.0, norm(p3 - c2) / 2.0);
	}
	


	

	return 0;
}