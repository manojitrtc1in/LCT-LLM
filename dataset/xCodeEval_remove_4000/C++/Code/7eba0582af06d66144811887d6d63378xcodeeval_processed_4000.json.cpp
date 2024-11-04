

using namespace std;













typedef long long LL;
LL MOD = 1000000007;

const double eps = 1e-8;
const double PI = acos(-1);

bool zero(double d = 0){
	return abs(d) < eps;
}
struct point{
	double x, y;
	

	double dist2(point p = {0, 0}){		
		return (p.x - x) * (p.x - x) + (p.y - y) * (p.y - y);
	}
	

	double dist(point p = {0, 0}) {
		return sqrt(dist2(p));
	}

	point operator + (const point & p) const {
		return {x + p.x, y + p.y};
	}

	point operator - (const point & p) const {
		return {x - p.x, y - p.y};
	}
	point operator * (const double mul) const {
		return {x * mul, y * mul};
	}

	bool operator < (const point& p) const{
		if(p.x == x) return y < p.y;
		return x < p.x;
	}
	bool operator == (const point & p) const{
		return x == p.x && y == p.y;
	}

	

	point rotate(point b, double t){
		double xx = b.x - x;
		double yy = b.y - y;
		return {xx * cos(t) - yy * sin(t) + x,
				yy * cos(t) + xx * sin(t) + y};
	}
};

double cross(point a, point b){
	return a.x * b.y - a.y * b.x;
}



double area(point a, point b, point c, bool f = 0){
	double ar = a.x * b.y - b.x * a.y;
	ar += b.x * c.y - c.x * b.y;
	ar += c.x * a.y - a.x * c.y;
	if(!f) ar = abs(ar);
	return ar;
}

struct line{
	double a, b, c;
	

	

	vector<point> intersect(line l){
		double p = l.a, q = l.b, r = l.c;
		if(zero(b * p - a * q)){
			if(zero(b * r - c * q)) return {(point){0, 0}, (point){0, 0}};
			return {};
		}
		return {(point){(b*r-c*q)/(a*q-b*p),(c*p-a*r)/(a*q-b*p)}};
	}
	

	double dist(point p){
		double num = a * p.x + b * p.y + c;
		double den = sqrt(a * a + b * b);
		num = abs(num);
		return num / den;
	}

	

	line perp(point p){
		return (line){b, -a, a * p.y - b * p.x};
	}
	

	vector<point> points_at_d(point p, double d){
		point dir = {-b, a};
		return {p + dir * (d / dir.dist()) , p - dir * (d / dir.dist())};
	}

	

	

	bool same_side(point p1, point p2){
		double p = p1.x * a + b * p1.y + c;
		double q = p2.x * a + b * p2.y + c;
		if(p < 0) p *= -1, q *= -1;
		return q > 0;
	}
};

struct line_segment{
	point a, b;
	

	line perp_bisec(){
		point mid = (a + b) * 0.5;
		double l = a.x - b.x;
		double m = a.y - b.y;
		double n = -(mid.y * m + l * mid.x);
		return (line){l, m, n};
	}
	

	line get_line(){
		double l = b.y - a.y;
		double m = a.x - b.x;
		double n = -(a.y * m + a.x * l);
		return (line){l, m, n};
	}
	

	bool inside(point c){
		if(!zero((b.y - a.y) * (c.x - a.x) - (b.x - a.x) * (c.y - a.y))) return 0;
		if(c.x < min(a.x, b.x) || c.x > max(a.x, b.x)) return 0;
		if(c.y < min(a.y, b.y) || c.y > max(a.y, b.y)) return 0;
		return 1;
	}

	

	bool intersect(line_segment s){
		line l1 = get_line();
		line l2 = s.get_line();
		vector<point> v = l1.intersect(l2);
		if(v.empty()) return 0;
		if(v.size() > 1) {
			return (s.inside(a) || s.inside(b) || inside(s.a) || inside(s.b));
		}
		return s.inside(v[0]) && inside(v[0]);
	}
};

struct circle
{
	double xc, yc, r;
	

	double get_theta(point p){ 

		double t = atan2(p.y - yc, p.x - xc);
		if(t < 0) t += 2.0 * PI;
		return t;
	}
	

	vector<point> line_intersect(line l){
		double a = l.a, b = l.b, c = l.c;
		vector<point> ans;
		double d = l.dist({xc, yc});
		if(d > r + eps) return ans;
		

		line bis = l.perp((point){xc, yc});
		if(zero(d - r)) {
			return bis.intersect(l);
		}
		

		point mid = bis.intersect(l)[0];
		double dd = r * r - d * d;
		dd = sqrt(dd);
		return l.points_at_d(mid, dd);
	}

	

	vector<point> intersect(circle c){
		double x1 = xc, y1 = yc, r1 = r;
		double x2 = c.xc, y2 = c.yc, r2 = c.r;

		if(r1 < r2) return c.intersect((circle){x1, y1, r1});

		point c1 = {x1, y1};
		point c2 = {x2, y2};

		double d = c1.dist(c2);

		

		if(zero(c1.dist2(c2) - (r1+r2)*(r1+r2)) || zero(c1.dist2(c2) - (r1-r2)*(r1-r2))){
			return {{x1 + (x2-x1) * r1 / d,
					y1 + (y2-y1) * r1 / d}};
		}

		

		if(c1.dist2(c2)+eps > (r1+r2)*(r1+r2) || c1.dist2(c2) < (r1-r2)*(r1-r2) + eps){
			return {};
		}

		double Cos_t = (r1*r1 + d*d - r2*r2)*0.5/d/r1;
		double t = acos(Cos_t);

		point p = {x1 + (x2-x1)*r1/d,
					y1 + (y2-y1)*r1/d};

		point p1 = c1.rotate(p, t);
		point p2 = c1.rotate(p, -t);
		return {p1, p2};
	}

	

	bool intersect(line_segment l){
		if(l.a.dist2({xc, yc}) < r*r - eps || l.b.dist2({xc, yc}) < r*r - eps) 
			return 1;
		return line_intersect(l.get_line()).size() > 1;
	}

	

	

	vector <point> tangent_points(point p){
		if(zero(p.dist2({xc, yc}) - r*r)) return {p};
		if(p.dist2({xc, yc}) < r*r + eps) return {};
		double d = p.dist({xc, yc});
		point cen = {xc, yc};
		double t = acos(min((double)1, r / d));
		double x1 = xc + (p.x - xc) * r / d;
		double y1 = yc + (p.y - yc) * r / d;
		point pp = {x1, y1};
		vector<point> ans;
		ans.push_back(cen.rotate(pp, t));
		ans.push_back(cen.rotate(pp, -t));
		
		return ans;
	}

	

	

	

	vector<line_segment> cross_tangents(circle c){
		double x1 = xc, y1 = yc, r1 = r;
		double x2 = c.xc, y2 = c.yc, r2 = c.r;

		point c1 = {x1, y1};
		point c2 = {x2, y2};

		

		if(zero(c1.dist2(c2) - (r1+r2)*(r1+r2))){
			c1 = intersect(c)[0];
			return {{c1, c1}};
		}

		

		if(c1.dist2(c2) <= (r1+r2)*(r1+r2) + eps){
			return {};
		}
		

		double d = c1.dist(c2);
		point p1 = {x1 + (x2 - x1) * r1 / d,
				   y1 + (y2 - y1) * r1 / d};
		point p2 = {x2 + (x1 - x2) * r2 / d,
					y2 + (y1 - y2) * r2 / d};

		p1 = c1.rotate(p1, PI/6.0);
		p2 = c2.rotate(p2, PI/6.0);
		
		line l1 = (line_segment){p1, p2}.get_line();
		line l2 = (line_segment){c1, c2}.get_line();

		vector<point> pts = l1.intersect(l2);
		vector<point> v1 = tangent_points(pts[0]);
		vector<point> v2 = c.tangent_points(pts[0]);

		if(l2.same_side(v1[0], v2[0])) swap(v1[0], v1[1]);

		vector<line_segment > ans;
		ans.push_back((line_segment){v1[0], v2[0]});
		ans.push_back((line_segment){v1[1], v2[1]});
		return ans;
	}

	

	

	

	vector<line_segment> top_tangents(circle c){
		double x1 = xc, y1 = yc, r1 = r;
		double x2 = c.xc, y2 = c.yc, r2 = c.r;

		point c1 = {x1, y1};
		point c2 = {x2, y2};

		

		if(zero(c1.dist2(c2) - (r1-r2)*(r1-r2))){
			c1 = intersect(c)[0];
			return {{c1, c1}};
		}

		

		if(c1.dist2(c2) + eps < (r1-r2)*(r1-r2)){
			return {};
		}

		if(abs(r1 - r2) <= eps){ 

			line ll = (line_segment){c1, c2}.get_line();
			line l1 = ll.perp(c1);
			line l2 = ll.perp(c2);
			vector<point> v1 = l1.points_at_d(c1, r1);
			vector<point> v2 = l2.points_at_d(c2, r2);
			if(!zero(v1[0].dist2(v2[0]) - c1.dist2(c2))) {
				swap(v1[0], v1[1]);
			}
			vector<line_segment > ans;
			ans.push_back((line_segment){v1[0], v2[0]});
			ans.push_back((line_segment){v1[1], v2[1]});
			return ans;
		}

		double d = c1.dist(c2);
		point p1 = {x1 + (x2 - x1) * r1 / d,
				   y1 + (y2 - y1) * r1 / d};
		point p2 = {x2 + (x1 - x2) * r2 / d,
					y2 + (y1 - y2) * r2 / d};
		
		p1 = c1.rotate(p1, PI/6.0);
		p2 = c2.rotate(p2, 7.0*PI/6.0);

		line l1 = (line_segment){p1, p2}.get_line();
		line l2 = (line_segment){c1, c2}.get_line();

		vector<point> pts = l1.intersect(l2);
		vector<point> v1 = tangent_points(pts[0]);
		vector<point> v2 = c.tangent_points(pts[0]);

		if(!l2.same_side(v1[0], v2[0])) swap(v1[0], v1[1]);

		vector<line_segment > ans;
		ans.push_back((line_segment){v1[0], v2[0]});
		ans.push_back((line_segment){v1[1], v2[1]});
		return ans;
	}
};

struct arc
{
	circle c;
	double t1, t2;
	

	bool on(point p){
		double t = c.get_theta(p);
		if(t1 < t2) {
			return t1 < t+eps && t < t2+eps;
		}
		else {
			return t1 < t+eps || t < t2+eps;
		}
	}

	

	double length(){
		if(t1 < t2) return (t2 - t1) * c.r;
		return (2.0*PI + t2 - t1) * c.r;
	}

	

	

	bool intersect(circle cr){
		vector<point> v = c.intersect(cr);
		if(v.size() < 2) return 0;
		double s1 = c.get_theta(v[0]);
		double s2 = c.get_theta(v[1]);
		if(on(v[0]) && !zero(s1 - t1) && !zero(s1 - t2)) return 1;
		if(on(v[1]) && !zero(s2 - t1) && !zero(s2 - t2)) return 1;
		return 0;
	}
};





struct polygon{
	vector<point> pts;

	

	double area(bool f = 0)
	{
		double ans = 0;
		for(int i = 0; i + 1 < pts.size(); ++i){
			ans += pts[i].x * pts[i+1].y - pts[i+1].x * pts[i].y;
		}
		if(!f) ans = abs(ans);
		return ans;
	}

	bool on(point p)
	{
		for(int i = 0; i + 1 < pts.size(); ++i){
			if((line_segment){pts[i], pts[i+1]}.inside(p)) return 1;
		}
		return 0;
	}

	bool inside(point p)
	{
		

		


	}

	
	bool convex_on(point p){
		int l = 0, r = pts.size() - 2, m;
		point p0 = pts.front();
		if((line_segment){pts[0], pts[1]}.inside(p)) return 1;
		if((line_segment){pts[r], pts[r+1]}.inside(p)) return 1;
		while(r - l > 1){
			m = (l+r) / 2;
			point p1 = pts[m];
			point p2 = pts[m+1];
			if((p.y - p0.y)*(p1.x - p0.x) < (p1.y-p0.y) * (p.x-p0.x)) r = m;
			else if((p2.y - p0.y)*(p.x-p0.x) < (p.y-p0.y)*(p2.x-p0.x)) l = m;
			else {
				return (line_segment){pts[m], pts[m+1]}.inside(p);
			}
		}
		if((line_segment){pts[l], pts[l+1]}.inside(p)) return 1;
		if((line_segment){pts[r], pts[r+1]}.inside(p)) return 1;
		return 0;
	}

	
	bool on_same_side(point a, point b, point p, point q){
		a = a - p, b = b - p;
		q = q - p, p = p - p;
		if(b.y * q.x < q.y * b.x) return 0;
		if(q.y * a.x < a.y * q.x) return 0;
		a = a - q; b = b - q;
		if(a.x * b.y < b.x * a.y) return 0;
		return 1;
	}

	
	bool convex_inside(point p, bool f = 0) {	
		if(convex_on(p)) return !f;
		if(p.x <= pts[0].x) return 0;
		
		int l = 0, r = pts.size() - 2, m;
		point p0 = pts.front();
		while(r - l > 1){
			m = (l+r) / 2;
			point p1 = pts[m];
			point p2 = pts[m+1];
			if((p.y - p0.y)*(p1.x - p0.x) < (p1.y-p0.y) * (p.x-p0.x)) r = m;
			else if((p2.y - p0.y)*(p.x-p0.x) < (p.y-p0.y)*(p2.x-p0.x)) l = m;
			else {
				return on_same_side(pts[m], pts[m+1], p0, p);
			}
		}
		if(on_same_side(pts[l], pts[l+1], p0, p)) return 1;
		if(on_same_side(pts[r], pts[r+1], p0, p)) return 1;
		return 0;
	}

	point centroid()
	{
		


	}

};

point a0;
bool cmp(const point & a, const point& b){
	double x = (a.y - a0.y) * (b.x - a0.x);
	double y = (b.y - a0.y) * (a.x - a0.x);
	if(x == y) return a.x + a.y < b.x + b.y;
	return x < y;
}



polygon id2(vector<point> pts, bool f = 0){
	sort(pts.begin(), pts.end());
	pts.resize(unique(pts.begin(), pts.end()) - pts.begin());
	a0 = pts[0];
	sort(pts.begin()+1, pts.end(), cmp);
	polygon hull;
	hull.pts.push_back(a0);
	pts.push_back(a0);
	for(int i = 1; i < pts.size(); ++i){
		while(hull.pts.size() > 1){
			int h = hull.pts.size();
			double signed_area = area(hull.pts[h-2], hull.pts[h-1], pts[i], 1);
			if(f ? (signed_area < 0) : (signed_area <= 0)) hull.pts.pop_back();
			else break;
		}
		hull.pts.push_back(pts[i]);
	}
	return hull;
}

circle id1(vector<point> &pts)
{

}

void test(){
	double x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	circle c1 = {x1, y1, r1};
	circle c2 = {x2, y2, r2};
	vector<point> ans = c1.intersect(c2);
	for(auto & l : ans){
		cerr << l.x << " " << l.y << "\n";
		

	}
	return ;
}

int main()
{
	int n, m;
	scanf("%d", &n);
	vector<point> A(n);
	rep(i, n) scanf("%lf %lf", &A[i].x, &A[i].y);
	polygon hull = id2(A);
	scanf("%d", &m);
	A.resize(m+n);
	rep(i, m) scanf("%lf %lf", &A[i+n].x, &A[i+n].y);
	polygon id0 = id2(A);
	if(hull.pts == id0.pts){
		for(int i = n; i < n + m; ++i){
			if(hull.convex_on(A[i])){
				puts("NO");
				return 0;
			}
		}
		puts("YES");
	}
	else puts("NO");
	return 0;
}
