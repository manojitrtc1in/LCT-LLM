









































using namespace std;

char string_in_buffer[(int)260];


void fast_scan(int &x) { scanf("%d", &x); }
void fast_scan(long long &x) { scanf("%lld", &x); }
void fast_scan(unsigned long long &x) { scanf("%llu", &x); }
void fast_scan(double &x) { scanf("%lf", &x); }
void fast_scan(long double &x) { scanf("%Lf", &x); }
void fast_scan(char &x) { 
	scanf("%c", &x); 
	if (x == '\n') {
		fast_scan(x);
	}
}
void fast_scan(string &x) {
	scanf("%s", string_in_buffer);
	x = string(string_in_buffer);
}

template<class TFirst, class TSecond>
void fast_scan(pair<TFirst, TSecond> &p) {
	fast_scan(p.first);
	fast_scan(p.second);
}

template <class T>
void fast_scan(vector<T> &v) {
	for (auto &x : v) fast_scan(x);
}

void fast_print(const int &x) { printf("%d", x); }
void fast_print(const long long &x) { printf("%lld", x); }
void fast_print(const unsigned long long &x) { printf("%llu", x); }
void fast_print(const double &x) { printf("%.15lf", x); }
void fast_print(const long double &x) { printf("%.15Lf", x); }
void fast_print(const char &x) { printf("%c", x); };
void fast_print(const string &x) { printf("%s", x.c_str());}

template<class TFirst, class TSecond>
void fast_print(const pair<TFirst, TSecond> &p) {
	fast_print(p.first);
	fast_print(' ');
	fast_print(p.second);
}

template <class T>
void fast_print(const vector<T> &v) {
	if (v.empty()) return;
	fast_print(v[0]);
	for (int i = 1; i < v.size(); i++) {
		fast_print(" ");
		fast_print(v[i]);
	}
}

template <class T>
void fast_print(const vector<vector<T>> &v) {
	if (v.empty()) return;
	fast_print(v[0]);
	for (int i = 1; i < v.size(); i++) {
		fast_print("\n");
		fast_print(v[i]);
	}
}



using namespace std;


namespace smart_io {
	string print_start = "";
	string sep = " ";
	bool first_print = false;

	void id6() {
		fast_print(print_start);
		print_start = "\n";
		first_print = true;
	}
} 



template <class T>
ostream &operator,(ostream &os, const T &object) {
	if (!smart_io::first_print) {
		fast_print(smart_io::sep);
	} else {
		smart_io::first_print = false;
	}
	fast_print(object);
	return os;
}

template <class T>
istream &operator,(istream &is, T &object) {
	fast_scan(object);
	return is;
}

namespace typedefs {
	typedef long long ll;
	typedef unsigned long long ull;
	typedef pair<int, int> pii;
}

namespace numbers_operation {
	template<class T>
	T floor_mod(T a, T b) {
		if (a % b == 0) return 0;
		if (a >= 0 && b >= 0) return a % b;
		if (a <= 0 && b <= 0) return a % b;
		return abs(b) - (abs(a) % abs(b));
	}
}

using namespace numbers_operation;
using namespace typedefs;


smart_io::id6(); \
cout,




namespace geo {


const double EPS = 0.0000001;


double id9(double ang_deg) {
	return (ang_deg * M_PI / 180.0);
}

double id2(double ang_rad) {
	return (ang_rad * 180.0 / M_PI);
}

bool eq(double a, double b = 0) {
	return abs(a - b) <= EPS;
}


class line;
class point;


class point {
public:
	double x, y;
	
	inline point() {}

	inline point(double _x, double _y):x(_x), y(_y) {}
	
	void set_polar(double _angle, double _dist) {
		x = cos(_angle) * _dist;
		y = sin(_angle) * _dist;
	}

	double length() {
		return hypot(x, y);
		

	}

	double angle() {
		return atan2(y, x);
	}

	friend istream &operator>>(istream &is, point &p) {
		is >> p.x >> p.y;
		return is;
	}

	friend point operator-(point p1, point p2) {
		return point(p1.x - p2.x, p1.y - p2.y);
	}

	void operator-=(const point &p) {
		x -= p.x;
		y -= p.y;
	}

	point operator/(double d) {
		return point(x / d, y / d);
	}

	point operator*(double d) {
		return point(x * d, y * d);
	}

	void operator/=(double d) {
		x /= d;
		y /= d;
	}

	void operator*=(double d) {
		x *= d;
		y *= d;
	}

	point rotate90() {
		return point(-y, x);
	}

	point invert() {
		return point(-x, -y);
	}

	void set_length(double l) {
		double cur_len = length();
		x /= cur_len;
		y /= cur_len;
		x *= l;
		y *= l;
	}

	double operator*(const point &p) {
		return (x * p.x + y * p.y);
	}

	double operator^(const point &p) {
		return (x * p.y - y * p.x);
	}

	point operator+(point p) {
		return point(x + p.x, y + p.y);
	}

	void operator+=(point p) {
		x += p.x;
		y += p.y;
	}
	
	friend ostream &operator<<(ostream &os, const point &p) {
		os << p.x << " " << p.y;
		return os;
	}

	bool operator==(point p) {
		return eq(x, p.x) && eq(y, p.y);
	}

	bool operator<(const point &p) const {
		return vector<double>{x, y} < vector<double>{p.x, p.y};
	}

	double angle_to(point p) {
		return acos(((*this) * p) / (p.length() * length()));
	}
};


class line {
public:
	double a, b, c;

	line() {}

	line(double _a, double _b, double _c):a(_a), b(_b), c(_c) {}

	line(point p1, point p2) {
		set_abc(p1, p2);
	}

	void set_abc(point p1, point p2) {
		point p = p1 - p2;
		a = p.y;
		b = -p.x;
		c = -(a * p1.x + b * p1.y);	
	}

	double equate(point p) const {
		return a * p.x + b * p.y + c;
	}

	double distance(point p) {
		return abs((a * p.x + b * p.y + c) / (point(a, b).length()));
	}

	point intersect(line l) {
		double x = (-l.b * c + l.c * b) / (a * l.b - b * l.a);
		double y = (-a * l.c + c * l.a) / (-b * l.a + a * l.b);
		

		

		return point(x, y);
	}

	

		

	


	double get_x(double y) {
		return (-b * y - c) / a;
	}

	double get_y(double x) {
		return (-a * x - c) / b;
	}

	bool parallel(line other) {
		return a * other.b == other.a * b;
	}

	bool equal(line other) {
		if (!parallel(other)) return false;
		if (!eq(b)) {
			return get_y(0) == other.get_y(0) && get_y(1) == other.get_y(1);
		} else if (!eq(a)) {
			return get_x(0) == other.get_x(0) && get_x(1) == other.get_x(1);
		} else {
			assert(false);
		}
		return other.c * point(a, b).length() == c * point(other.a, other.b).length();
	}
	
	void move(point dp) {
		

		

		


		

		

		

		


		point id4;
		point id3;
		if (!eq(b)) {
			assert(!eq(b));
			id4 = point(0, get_y(0));
			id3 = point(1, get_y(1));
		} else {
			assert(!eq(a));
			id4 = point(get_x(0), 0);
			id3 = point(get_x(1), 1);
		}
		id4 += dp;
		id3 += dp;
		set_abc(id4, id3);
	}


	friend ostream &operator<<(ostream &os, line &l) {
		os << l.a << " " << l.b << " " << l.c;
		return os;
	}

	friend istream &operator>>(istream &is, line &l) {
		is >> l.a >> l.b >> l.c;
		return is;
	}
};

class segment {
public:
	point first, second;

	segment() {}
	
	segment(point _first, point _second): first(_first), second(_second) {}

	double distance(point p) {
		double cos1 = ((first - second) * (p - second)) / ((first - second).length() * (p - second).length());
		double cos2 = ((second - first) * (p - first)) / ((second - first).length() * (p - first).length());
		

		if (cos1 >= 0 && cos2 >= 0) {
			return (line(first, second)).distance(p);
		} else {
			return min((first - p).length(), (second - p).length());
		}
	}

	bool in_segment(point p) {
		

		

		return abs((first - second).length() -
			(first - p).length() - (second - p).length()) < EPS;
	}

	bool intersect(segment s) {
		point p = line(s.first, s.second).intersect(line(first, second));
		return this->in_segment(p) && s.in_segment(p);
	}

	friend istream&operator>>(istream &is, segment &s) {
		is >> s.first >> s.second;
		return is;
	}
};

class circle {
public:
	double radius;
	point center;


	circle() {}
	circle(point _center, double _radius): center(_center), radius(_radius) {}
	

	double equate(point p) {
		

		double x = p.x;
		double y = p.y;
		return x * x + y * y - radius * radius;
	}

	vector<point> tangent(point p) {
		assert(radius > 0);
		p -= center;
		if (p.length() < radius) {
			

			

			return vector<point>();
		}
		if (p.length() == radius) {
			vector<point> rez;
			rez.push_back(p + center);
			return rez;
		}
		vector<point> rez;
		

		double id5 = sqrt(p.length() * p.length() - radius * radius);
		double alpha = asin(radius / p.length());
		

		

		point sub_center = point(p.x, p.y);
		point inter;
		inter.set_polar(sub_center.angle() + alpha, id5);
		

		rez.push_back(p - inter + center);
		inter.set_polar(sub_center.angle() - alpha, id5);
		rez.push_back(p - inter + center);
		return rez;
	}

	vector<point> intersects_with_equasion(line l) {
		l.move(center.invert());
		

		double a = l.b * l.b + l.a * l.a;
		double b = 2 * l.b * l.c;
		double c = l.c * l.c - l.a * l.a * radius * radius;
		double descr = b * b - 4 * a * c;
		if (descr < 0) return {};
		double root1 = (-b + sqrt(descr)) / (2 * a);
		double root2 = (-b - sqrt(descr)) / (2 * a);
		vector<point> rez;
		auto check_root = [&rez, l, descr](double root, circle _circle){
			double x = sqrt(_circle.radius * _circle.radius - root * root);
			double y = root;
			x = (-l.b * y - l.c) / l.a;
			

			double id10 = x * x + y * y;
			double id14 = _circle.radius * _circle.radius;
			

			

			if (eq(_circle.equate(point(x, y))) && 
				eq(l.equate(point(x, y)))) {
				rez.push_back(_circle.center + 
					point(x, y));
			}
		};

		check_root(root1, *this);
		check_root(root2, *this);
		if (rez.size() > 1) {
			if (eq(rez[0].x, rez[1].x) && eq(rez[0].y, rez[1].y)) {
				rez.ppb();
			}
		}
		return rez;
	}

	vector<point> intersects(line l) {
		l.move(center.invert());
		double min_dist = l.distance(point(0, 0));
		point pt_normal(l.a, l.b);
		pt_normal /= pt_normal.length();
		pt_normal *= min_dist;
		if (!eq(l.equate(pt_normal))) {
			pt_normal = pt_normal.invert();
		}
		if (pt_normal.length() > radius) {
			return {};
		}
		if (eq(min_dist, radius)) {
			return {center + pt_normal};
		}
		double d = sqrt(radius * radius - min_dist * min_dist);
		point inline_pt(-l.b, l.a);
		inline_pt.set_length(d);
		vector<point> rez;
		rez.push_back(center + pt_normal + inline_pt);
		rez.push_back(center + pt_normal - inline_pt);
		return rez;
	}

	vector<point> intersects(circle c) {
		double id13 = (center - c.center).length();
		
		if (c.center == center && radius == c.radius)
			throw "To More Intersections";

		if (id13 > c.radius + radius)
			return {};

		if (id13 + radius < c.radius)
			return {};

		if (id13 + c.radius < radius) 
			return {};

		if (eq(id13 + c.radius, radius)) {
			point pt(c.center - center);
			pt.set_length(pt.length() + c.radius);
			return {center + pt};
		}

		if (eq(id13 + radius, c.radius)) {
			point pt(center - c.center);
			pt.set_length(pt.length() + radius);
			return {c.center + pt};
		}

		if (eq(id13, c.radius + radius)) {
			point pt(c.center - center);
			pt.set_length(radius);
			return {center + pt};
		}
		double cx = c.radius;
		double b = (c.center - center).length();
		double a = radius;
		double alpha = (a * a + b * b - cx * cx) / (2 * a * b);
		double d = radius * alpha;
		double norm_d = sqrt(radius * radius - d * d);
		

		

		point pt = c.center - center;
		pt.set_length(d);
		point norm_pt = pt.rotate90();
		norm_pt.set_length(norm_d);
		vector<point> rez;
		rez.pb(center + pt + norm_pt);
		rez.pb(center + pt - norm_pt);
		if (eq(rez[0].x, rez[1].x) && eq(rez[0].y, rez[1].y)) {
			rez.ppb();
		}
		return rez;
	}

	friend istream &operator>>(istream &is, circle &c) {
		is >> c.center >> c.radius;
		return is;
	}
};

template<class T>
T id8(T x) {
	if (x > (T)0) {
		return (T)1;
	} elif(x < (T)0) {
		return (T)-1;
	}
	return (T)0;
}

class polygon {
public:
	vector<point> points;
	
	polygon(vector<point> _points):points(_points) {}

	bool in_side(point p) {
		double sangle = 0;
		for (int i = 0; i < len(points); i++) {
			point f = points[i];
			point s = points[(i + 1) % len(points)];
			
			segment sg(f, s);
			if (sg.in_segment(p)) return true;
			point subf = (f - p);
			point subs = (s - p);
			double angle = atan2(subf ^ subs, subf * subs);
			

			sangle += angle;
		}
		return abs(sangle) > (M_PI / 2);
	}

	bool in_side_with_ray(point p) {
		point magic_point(123456, 666666);
		

		segment s(p, magic_point);
		int cnt = 0;
		for (int i = 0; i < points.size(); i++) {
			segment edge(points[i], points[(i + 1) % points.size()]);
			if (edge.in_segment(p)) {
				return true;
			}
			cnt += edge.intersect(s);
		}
		

		return cnt & 1;
	}

	bool is_convex() {
		int n = points.size();
		double last_turn = 0;
		for (int i = 0; i < n; i++) {
			point p1 = points[i];
			point p2 = points[(i + 1) % n];
			point p3 = points[(i + 2) % n];
			point p = p1 - p2;
			point q = p3 - p2;
			double sin_alpha = (p ^ q) / (p.length() * q.length());
			if (last_turn == 0) {
				last_turn = id8(sin_alpha);
				continue;
			}
			if (last_turn != id8(sin_alpha)) {
				return false;
			}
		}
		return true;
	}

	double square() {
		double sq = 0;
		for (int i = 0; i < points.size(); i++) {
			point first = points[i];
			point second = points[(i + 1) % points.size()];
			double w = second.x - first.x;
			double up_h = second.y - first.y;
			sq += w * first.y + (w * up_h / 2);
		}
		return abs(sq);
	};
};

line id0(point norm, point id11) {
	double a = norm.x;
	double b = norm.y;
	double c = -(a * id11.x + b * id11.y);
	return line(a, b, c);
}



vector<point> id12(vector<point> points, int id7 = 8) {
	point down = points[0];
	int n = points.size();
	if (n == 1) {
		return vector<point>{points[0]};
	}
	int down_ind = 0;
	for (int i = 1; i < n; i++) {
		point p = points[i];
		if (p.y == down.y) {
			if (p.x > down.x) {
				down = p;
				down_ind = i;
			}
		} elif(p.y < down.y) {
			down = p;
			down_ind = i;
		}
	}
	tie(points[down_ind], points[n - 1]) 
		= mt(points[n - 1], points[down_ind]);
	points.ppb();
	

	for (auto x : points) {
		

	}
	

	

	

	

	n = points.size();
	sort(points.begin(), points.end(), [&down, &id7](point a, point b){
		point p = a - down;
		point q = b - down;
		if (p.angle() == q.angle()) {
			

			

			

			

			return p.length() < q.length();
		}
		return p.angle() < q.angle();
	});
	

	vector<point> rez;
	rez.pb(down);
	rez.pb(points[0]);
	

	

	for (int i = 1; i < n; i++) {
		bool need_iter = true;

		need_iter = true;
		point p1 = rez[rez.size() - 2], p2 = rez[rez.size() - 1];
		point p = p1 - p2;
		point q = points[i] - p2;
		

		while (((rez.size() >= 2)) && (p ^ q) >= 0) {
			

			rez.ppb();
			p1 = rez[rez.size() - 2], p2 = rez[rez.size() - 1];
			p = p1 - p2;
			q = points[i] - p2;
		}

		rez.pb(points[i]);
	}
	point p1 = rez[rez.size() - 2], p2 = rez[rez.size() - 1];
	point p = p1 - p2;
	point q = down - p2;
	while ((rez.size() >= 3) && (p ^ q) >= 0) {
		rez.ppb();
		p1 = rez[rez.size() - 2], p2 = rez[rez.size() - 1];
		p = p1 - p2;
		q = down - p2;
	}
	return rez;
}
} 



using namespace geo;


signed main(signed argc, char *argv[]) {
	

	

	int n;
	scan n;
	point cap_low;
	point cap_high;
	double x, y;
	scan x, y;
	cap_low = point(x, y);
	scan x, y;
	cap_high = point(x, y);

	


	vector<point> starts(n);
	vector<point> speed(n);
	for (int i = 0; i < n; i++) {
		scan x, y;
		starts[i] = point(x, y);
		scan x, y;
		speed[i] = point(x, y);
	}

	vector<segment> sides;
	sides.pb(segment(cap_low, point(cap_low.x, cap_high.y)));
	sides.pb(segment(point(cap_low.x, cap_high.y), cap_high));
	sides.pb(segment(cap_high, point(cap_high.x, cap_low.y)));
	sides.pb(segment(cap_low, point(cap_high.x, cap_low.y)));

	polygon pl({
		cap_low,
		point(cap_low.x, cap_high.y),
		cap_high,
		point(cap_high.x, cap_low.y)		
	});

	double min_time = 0, max_time = 1e9;
	for (int i = 0; i < n; i++) {
		if (speed[i] == point(0, 0)) {
			if (pl.in_side_with_ray(starts[i])) {
				for (segment s : sides) {
					if (s.in_segment(starts[i])) {
						print -1;
						return 0;
					}
				}
				continue;
			}
			print -1;
			return 0;
		}
		line l(starts[i], starts[i] + speed[i]);
		double _sub_min = 1e9;
		double _sub_max = -1e9;
		bool id1 = false;
		if (pl.in_side_with_ray(starts[i])) {
			_sub_min = 0;
		}

		bool two_factor = false;
		for (segment s : sides) {
			line sub(s.first, s.second);
			if (l.parallel(sub)) {
				if (l.equal(sub)) {
					two_factor = true;
				}
				continue;
			}
			point inter = l.intersect(sub);
			if (s.in_segment(inter) && (speed[i] * (inter - starts[i])) > 0) {
				double dist = (inter - starts[i]).length();
				if (speed[i].length() == 0) {
					_sub_min = -1e9;
					_sub_max = 1e9;
					id1 = true;
				} else {
					double time = dist / speed[i].length();
					_sub_min = min(_sub_min, time);
					_sub_max = max(_sub_max, time);
					id1 = true;
				}
			}
		}
		if (!id1 || _sub_min == _sub_max || two_factor) {
			print -1;
			return 0;
		} else {
			min_time = max(min_time, _sub_min);
			max_time = min(max_time, _sub_max);
		}
	}


	if (min_time > max_time - 0.0000000001) {
		print -1;
		return 0;
	}
	print min_time;

}