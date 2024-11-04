









using namespace std;


typedef long long i64;









typedef long double T;








const T PI = acos(-1.0);
const T EPS = 1e-8;
const T eps = 1e-10;

int cmp(T a, T b) {
	return a < b-eps ? -1 : a > b+eps ? 1: 0;
}

int sig(T a) {
	return cmp(a, 0);
}

T eq(T a, T b) {
	return abs(a-b) <= eps;
}

T mod(T a, T b) {
	return a - floor(a/b + EPS) * b;
}




T gcd(T a, T b){
	return sig(a)==0 ? b : gcd(mod(b, a), a);
}

T sqr(T a) {
	return a*a;
}



int between(T x, T a, T b, int ex_end=0) {
	return cmp(x,a) >= 0 && cmp(x,b) < 1-ex_end;
}




T id6(T d) {
	return PI*d/180;
}

T id5(T r) {
	return r*180/PI;
}




struct point {
	T x, y;
	point(T x=0, T y=0): x(x), y(y) {}
};

struct line {
	

	T a, b, c;
	line(T a=0, T b=0, T c=0): a(a), b(b), c(c) {}
};

struct mat {
	point a, b; 

	mat(T a=0, T b=0, T c=0, T d=0): a(a,b), b(c,d) {}
	mat(const point &a, const point &b): a(a), b(b) {}
	mat t() const { return mat(a.x, b.x, a.y, b.y); }
};

struct circle {
	point c;
	T r;
	circle() {}
	circle(const point &c, T r): c(c), r(r) {}
};







ostream &operator<<(ostream &os, const point &p) {
	return os << '(' << p.x << ',' << p.y << ')';
}

istream &operator>>(istream &is, point &p) {
	return is >> p.x >> p.y;
}


point operator+(const point &a, const point &b) {
	return { a.x+b.x, a.y+b.y };
}

point operator-(const point &a, const point &b) {
	return { a.x-b.x, a.y-b.y };
}

point operator*(const point &a, T r) {
	return { a.x*r, a.y*r };
}

point operator*(T r, const point &a) {
	return { a.x*r, a.y*r };
}

T operator*(const point &a, const point &b) {
	return a.x*b.x + a.y*b.y;
}

T cross(const point &a, const point &b) {
	return a.x * b.y - a.y * b.x;
}

T id9(const point &a) {
	return a*a;
}

T id8(const point &a, const point &b) {
	return id9(a-b);
}

bool operator<(const point &a, const point &b) {
	int k = cmp(a.x, b.x);
	if (k==0) return cmp(a.y, b.y) < 0;
	else return k < 0;
}

bool operator==(const point &a, const point &b) {
	return cmp(a.x, b.x)==0 && cmp(a.y, b.y)==0;
}

T dot(const point &a, const point &b, const point &c) {
	return (a-c)*(b-c);
}

T cross(const point &a, const point &b, const point &c) {
	return cross(a-c, b-c);
}


point operator/(const point &a, T r) {
	return { a.x/r, a.y/r };
}

T norm(const point &a) {
	return sqrt(a*a);
}

T dist(const point &a, const point &b) {
	return norm(a-b);
}






ostream &operator<<(ostream &os, const mat &m) {
	return os << '[' << m.a << ';' << m.b << ']';
}

mat operator+(const mat &m, const mat &n) {
	return mat(m.a + n.a, m.b + n.b);
}

mat operator-(const mat &m, const mat &n) {
	return { m.a - n.a, m.b - n.b };
}

mat operator*(const mat &m, T r) {
	return { m.a*r, m.b*r };
}

mat operator*(const mat &m, const mat &n) {
	mat t = n.t();
	return mat(m.a*t.a, m.a*t.b, m.b*t.a, m.b*t.b);
}

point operator*(const mat &m, const point &v) {
	return {m.a*v, m.b*v};
}

point operator*(const point &v, const mat &m) {
	return point(point(m.a.x, m.b.x)*v, point(m.a.y, m.b.y)*v);
}

T mat_det(const mat &m) {
	return cross(m.a, m.b);
}


mat operator/(const mat &m, T r) {
	return { m.a/r, m.b/r };
}

int mat_inv(const mat &m, mat &i) {
	T d = mat_det(m);
	if (eq(d, 0)) return 0;
	i = mat(m.b.y/d, -m.a.y/d, -m.b.x/d, m.a.x/d);
	return 1;
}







point id11(point a) {
	return {-a.y, a.x};
}

point id7(point a) {
	return {-a.x, -a.y};
}

point id3(point a) {
	return {a.y, -a.x};
}

T id2(point a, point b) {
	return cross(a, b);
}



T id10(point a, point b) {
	return cross(a,b);
}


point vec_rotate(point a, T r) {
	mat m = {{cos(r), -sin(r)}, 
	         {sin(r),  cos(r)}};
	return m * a;
}

T vec_area(point a, point b) {
	return cross(a, b)/2.0;
}

T vec_angle(point a, point b) {
	T n = norm(a)*norm(b);
	

	return acos(a*b/n);
}






ostream &operator<<(ostream &os, const line &l) {
	return os << '{' << l.a << ',' << l.b << ',' << l.c << '}';
}

line id13(point a, point v) {
	return {v.y, -v.x, v.x*a.y - a.x*v.y};
}

line id1(point a, point b) {
	return id13(a, b-a);
}

T line_eval(line l, point a) {
	return l.a * a.x + l.b * a.y + l.c;
}



int id4(line l, point a, point b) {
	T s1 = line_eval(l, a);
	T s2 = line_eval(l, b);
	return cmp(s1, 0) * cmp(s2, 0);
}


line id14(point a, point b) {
	point mid = (a + b)/2.0;
	point perp = id11(b - a);
	return id13(mid, perp);
}

int line_inter(line a, line b, point &c) {
	mat m(a.a, a.b, b.a, b.b), i;
	if (!mat_inv(m, i)) return 0;
	c = i * point(-a.c, -b.c);
	return 1;
}






ostream &operator<<(ostream &os, const circle &c) {
	return os << '[' << c.c << ':' << c.r << ']';
}


int id0(point a, point b, point c, circle &cc) {
	line l1 = id14(a, b);
	line l2 = id14(b, c);
	point o;
	if (!line_inter(l1, l2, o)) return 0;
	cc = circle(o, dist(a, o));
	return 1;
}





template<class A,class B, class C, class D>
struct gmat {
	A a;
	B b;
	C c;
	D d;
	gmat(): a(), b(), c(), d() {}
	gmat(A a, B b, C c, D d): a(a), b(b), c(c), d(d) {}
	gmat(const point &a, const point &b): a(a), b(b) {}
	gmat t() const { return gmat(a.x, b.x, a.y, b.y); }
};

template<class A,class B, class C, class D>
ostream &operator<<(ostream &os, const gmat<A,B,C,D> &m) {
	return os << '[' << m.a << ',' << m.b << ';' << m.c << ',' << m.d << ']';
}

template<class mat>
mat operator+(const mat &m, const mat &n) {
	return mat(m.a + n.a, m.b + n.b, m.c + n.c, m.d + n.d);
}

template<class mat>
mat operator-(const mat &m, const mat &n) {
	return mat(m.a - n.a, m.b - n.b, m.c - n.c, m.d - n.d);
}

template<class mat>
mat operator*(const mat &m, const mat &n) {
	return mat(m.a*n.a+m.b*n.c, m.a*n.b+m.b*n.d, m.c*n.a+m.d*n.c, m.c*n.b+m.d*n.d); 
}

template<class mat>
mat operator*(const mat &m, T r) {
	return mat(m.a * r, m.b * r, m.c * r, m.d * r);
}

template<class A,class B, class C, class D>
point operator*(const gmat<A,B,C,D> &m, const point &v) {
	return point(v.x*m.a + v.y*m.b, v.x*m.c + v.y*m.d);
}

template<class A,class B, class C, class D>
point operator*(const point &v, const gmat<A,B,C,D> &m) {
	return point(v.x*m.a + v.y*m.c, v.x*m.b + v.y*m.d);
}

template<class mat>
T mat_det(const mat &m) {
	return cross(m.a, m.b);
}




typedef gmat<mat,point,point,T> tmat;



tmat linear_transform(T rotate=0, T scale=1, point translate=0) {
	T c = cos(rotate), s = sin(rotate);
	return tmat(mat(c, -s, s, c) * scale, translate, 0, 1);
}





template<class T>
struct node_min {
	T val;
	node_min(): val(numeric_limits<T>::max()) {}
	node_min(T val): val(val) {}
	node_min operator+(const node_min &o) {
		return node_min(min(val, o.val));
	}
};

template<class T>
struct node_max {
	T val;
	node_max(): val(numeric_limits<T>::min()) {}
	node_max(T val): val(val) {}
	node_max operator+(const node_max &o) {
		return node_max(max(val, o.val));
	}
};

template<class T1, class T2>
struct node_pair {
	T1 v1;
	T2 v2;
	node_pair() {};
	node_pair(T1 v1, T2 v2): v1(v1), v2(v2) {};
	node_pair operator+(const node_pair &o) {
		return node_pair(v1 + o.v1, v2 + o.v2);
	};
};

template<class T>
class segment_tree {
public:
	int n;
	int start;
	int cap;
	T *a;
	T sum_at(int i, int l, int r, int s, int t) {
		if (i >= cap || s>=r || t<=l) return T();
		if (s<=l && t>=r) return a[i];
		int m = (l+r)/2;
		return sum_at(i*2+1, l, m, s, t) + sum_at(i*2+2, m, r, s, t);
	}
	segment_tree(int n): n(n) {
		int len;
		for (len=1; len<=n; len*=2);
		start = len-1;
		cap = start + n;
		a = new T[cap];
	}
	~segment_tree() {
		delete[] a;
	}
	int size() {
		return n;
	}
	void update(int i, T x) {
		int p = start + i;
		a[p] = x;
		while (p) {
			int f = (p-1)/2;
			int lc = f*2+1, rc = lc+1;
			a[f] = rc < cap ? a[lc] + a[rc]: a[lc];
			p = f;
		}
	}
	T get(int i) {
		return a[start + i];
	}
	T range_sum(int s, int t) {
		return sum_at(0, 0, start+1, s, t);
	}
};

template<class T>
class id12: public segment_tree<T> {
	T *b;
	void add_at(int i, int l, int r, int s, int t, T x) {
		if (i >= this.cap || s>=r || t<=l) return;
		if (s<=l && t>=r) {
			b[i] = x;
			return;
		}
		int m = (l+r)/2;
		add_at(i*2+1,   l, m, s, t, x);
		add_at(i*2+2, m, r, s, t, x);
	}
	T sum_at(int i, int l, int r, int s, int t) {
		if (i >= this.cap || s>=r || t<=l) return T();

		int k = min(r,t)-max(l,s);
		T add = b[i] * k;
		if (s<=l && t>=r) return this.a[i] + add;

		int m = (l+r)/2;
		return sum_at(i*2+1, l, m, s, t) + sum_at(i*2+2, m, r, s, t) + add;
	}
public:
	id12(int n): segment_tree<T>(n) {
		b = new T[this.cap];
	}
	~id12() {
		~segment_tree<T>();
		delete[] b;
	}
	T get(int i) {
		return range_sum(i, i+1);
	}
	void range_add(int s, int t, T x) {
		return add_at(0, 0, this.start+1, s, t, x);
	}
	T range_sum(int s, int t) {
		return sum_at(0, 0, this.start+1, s, t);
	}
};





struct arm {
	T r;
	point t;
	arm(T r=0, point t=0): r(r), t(t) {};
	void stretch(int len) {
		t = t + t * len/norm(t);
	}
	void rotate(int deg) {
		T dr = id6(360-deg);
		r = r + dr;
		t = vec_rotate(t, dr);
	}
	point pos() {
		return t;
	}
	arm operator+(const arm &o) {
		return arm(r + o.r, t + vec_rotate(o.t, r));
	}
};



segment_tree<arm> *robot;

int n, m;

int input() {
	if (scanf("%d %d", &n, &m)!=2) return 0;
	return 1;
}

void init() {
	robot = new segment_tree<arm>(n);
	for (int i=0; i<n; i++) {
		

		arm a(0, point(1,0));
		robot->update(i, a);
	}
}

int solve() {
	for (int i=0; i<m; i++) {
		int op, k, v;
		scanf("%d %d %d", &op, &k, &v);
		

		k--;
		arm a = robot->get(k);
		if (op==1)
			a.stretch(v);
		else
			a.rotate(v);
		robot->update(k, a);
		point p = robot->a[0].pos();
		printf("%.10lf %.10lf\n", (double)p.x, (double)p.y);

		
	}
	return 1;
}

void output(int ans) {
}

void cleanup() {
	delete robot;
}

int main() {
	

	

	while (input()) {
		init();
		output(solve());
		cleanup();
		

	}
}


