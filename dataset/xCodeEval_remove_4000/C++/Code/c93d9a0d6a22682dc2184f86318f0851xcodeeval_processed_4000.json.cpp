

















 
































using namespace std;

class vec2 {
	
public:

	double x, y;

	vec2() : x(0), y(0) { }

	vec2(double x, double y) : x(x), y(y) { }

	vec2 operator+(const vec2& v) const {
		return { x + v.x, y + v.y };
	}

	vec2 operator-(const vec2& v) const {
		return { x - v.x, y - v.y };
	}

	vec2 operator*(double v) const {
		return { x * v, y * v };
	}

	vec2 operator/(double v) const {
		return { x / v, y / v };
	}

	double operator*(const vec2& v) const {
		return x * v.x + y * v.y;
	}

	double operator^(const vec2& v) const {
		return x * v.y - y * v.x;
	}

	bool operator==(const vec2& v) const {
		return eq(x, v.x) && eq(y, v.y);
	}

	double mag() const {
		return sqrt(x * x + y * y);
	}

	double mag_2() const {
		return x * x + y * y;
	}

	double dist(const vec2& v) const {
		return (*this - v).mag();
	}

	

	vec2 rotate(double a) const {
		return { x * cos(a) - y * sin(a), x * sin(a) + y * cos(a) };
	}
	
	double atan() const {
		return atan2(y, x);
	}
};

class line {
	
public:

	vec2 pt;
	vec2 dir;

	line() { };

	line(const vec2& p, const vec2& d) : pt(p), dir(d) { }

	bool operator==(const line& l) const {
		return eq(dir ^ l.dir, 0) && eq(dir ^ (pt - l.pt), 0);
	}
	
	

	

	

	int relative_location(const vec2& p) const {
		double cp = dir ^ (p - pt);
		return (cp > 0) - (cp < 0);
	}

	

	

	

	virtual int location(const vec2& p) const {
		return (dir.x > 0 || (dir.x == 0 && dir.y < 0) ? 1 : -1) * relative_location(p);
	}

	bool parallel(const line& l) const {
		return eq(dir ^ l.dir, 0);
	}

	vec2 intersect_point(const line& l) const {
		vec2 epnt = pt + dir;
		double s1 = (pt - l.pt) ^ l.dir;
		double s2 = (epnt - l.pt) ^ l.dir;
		return ((epnt * s1) - (pt * s2)) / (s1 - s2);
	}

	double dist(const vec2& p) const {
		return abs((p - pt) ^ (p - pt + dir)) / dir.mag();
	}
};

class line_segment : public line {
	
public:

	vec2 ep;

	line_segment() : line() { };

	line_segment(const vec2& a, const vec2& b) : line(a, a - b), ep(b) { }

	

	

	

	

	int location(const vec2& p) const override {
		int r = line::location(p);
		if (r != 0) return r;
		return ((p - pt) * (p - ep) > 0) * -2;
	}

	bool intersect(const line_segment& ls) const {
		return max(pt.x, ep.x) >= min(ls.pt.x, ls.ep.x) &&
			max(ls.pt.x, ls.ep.x) >= min(pt.x, ep.x) &&
			max(pt.y, ep.y) >= min(ls.pt.y, ls.ep.y) &&
			max(ls.pt.y, ls.ep.y) >= min(pt.y, ep.y) &&
			((ls.pt - pt) ^ dir) * ((ls.ep - pt) ^ dir) <= 0 &&
			((pt - ls.pt) ^ ls.dir) * ((ep - ls.pt) ^ ls.dir) <= 0;
	}
};

class polygon {
	
public:

	int s;

	vec2* pts;

	polygon() { };

	polygon(vec2* pts, int s) : s(s) {
		this->pts = pts;
		this->pts[s] = pts[0];
	}

	double perimeter() const {
		double sum = 0;
		for (int i = 0; i < s; ++i) sum += pts[i + 1].dist(pts[i]);
		return sum;
	}

	double area() const {
		double sum = 0;
		for (int i = 0; i < s; ++i) sum += pts[i + 1] ^ pts[i];
		return abs(sum) / 2;
	}

	

	

	

	

	int contain(const vec2& p) const {
		line_segment ls = line_segment(p, vec2(MAX, MAX * M_SQRT1_2));
		int ts = 0;
		for (int i = 0; i < s; ++i) {
			if (pts[i] == p) return -2;
			line_segment tl = line_segment(pts[i + 1], pts[i]);
			if (eq(tl.location(p), 0)) return -1;
			ts += ls.intersect(tl);
		}
		return ts % 2;
	}
};

class id3 : public polygon {
	
public:

	id3() : polygon() { };

	id3(vec2* pts, int s) : polygon() {
		sort(pts, pts + s, [](const vec2& a, const vec2& b) {
			return !eq(a.x, b.x) ? a.x < b.x : a.y < b.y;
		});
		int* ps = new int[s];
		int pi = 0;
		for (int i = 0; i < s; ++i) {
			while (pi > 1 && ((pts[ps[pi - 1]] - pts[ps[pi - 2]]) ^ (pts[i] - pts[ps[pi - 2]])) <= 0) --pi;
			ps[pi++] = i;
		}
		int k = pi;
		for (int i = s - 2; i >= 0; --i) {
			while (pi > k && ((pts[ps[pi - 1]] - pts[ps[pi - 2]]) ^ (pts[i] - pts[ps[pi - 2]])) <= 0) --pi;
			ps[pi++] = i;
		}
		this->pts = new vec2[pi];
		for (int i = 0; i < pi; ++i) this->pts[i] = pts[ps[i]];
		this->s = pi - 1;
	}

	int next(int x) const {
		return (x + 1) % s;
	}

	double diameter() const {
		double maxi = 0;
		for (int i = 0, j = 1; i < s; ++i) {
			vec2 cur = pts[next(i)] - pts[i];
			while ((cur ^ (pts[j] - pts[i])) < (cur ^ (pts[next(j)] - pts[i]))) j = next(j);
			maxi = max(maxi, max(pts[i].dist(pts[j]), pts[next(i)].dist(pts[next(j)])));
		}
		return maxi;
	}
};

class id0 {
	
public:

	class id2 {
		
	public:

		vec2 c; 

		vec2 p; 

		vec2 r; 


		id2(const vec2& c, const vec2& p) : c(c), p(p), r(p - c) { }

		bool operator<(const id2& d) const {
			vec2 b = d.p - c;
			double a = r.atan() - b.atan();
			return abs(a) > 0.1 ? a < 0 : (r ^ b) > 0;
		}
	};
	
	typedef multiset<id2>::iterator mdi;

	vec2 c;

	multiset<id2> t;

	id0() { };

	id0(vec2* pts, int s) {
		c = (pts[0] + pts[1] + pts[2]) / 3;
		for (int i = 0; i < 3; ++i) t.insert(id2(c, pts[i]));
		for (int i = 3; i < s; ++i) insert(pts[i]);
	}

	void next(mdi& it) const {
		++it;
		if (it == t.end()) it = t.begin();
	}

	void prev(mdi& it) const {
		if (it == t.begin()) it = t.end();
		--it;
	}

	void insert(const vec2& p) {
		mdi it = t.insert(id2(c, p));
		mdi ni = it;
		next(ni);
		mdi pi = it;
		prev(pi);
		if (((pi->p - ni->p) ^ (p - ni->p)) <= 0) {
			t.erase(it);
			return;
		}
		vector<mdi> del;
		mdi past = ni;
		next(ni);
		while (((past->p - it->p) ^ (ni->p - past->p)) <= 0) {
			del.push_back(past);
			past = ni;
			next(ni);
		}
		past = pi;
		prev(pi);
		while (((past->p - it->p) ^ (pi->p - past->p)) >= 0) {
			del.push_back(past);
			past = pi;
			prev(pi);
		}
		for (auto& i : t) t.erase(i);
	}

	

	

	bool contain(const vec2& p) const {
		mdi it = t.lower_bound(id2(c, p));
		if (it == t.end()) it = t.begin();
		vec2 v = it->p;
		prev(it);
		return ((it->p - v) ^ (p - v)) <= 0;
	}

	double perimater() const {
		double sum = 0;
		mdi it = t.begin();
		mdi past = it;
		++it;
		do {
			sum += it->p.dist(past->p);
			past = it;
			next(it);
		} while (past != t.begin());
		return sum;
	}

	double area() const {
		double sum = 0;
		mdi it = t.begin();
		mdi past = it;
		++it;
		do {
			sum += it->p ^ past->p;
			past = it;
			next(it);
		} while (past != t.begin());
		return abs(sum) / 2;
	}
};




























































































































class circle {
	
public:

	vec2 c; 


	double r = 0; 


	circle() { };

	circle(vec2 c, double r) : c(c), r(r) { }

	circle(vec2 p1, vec2 p2, vec2 p3) {
		vec2 b(p2.mag_2() - p1.mag_2(), p3.mag_2() - p1.mag_2());
		c = vec2(vec2(p1.y - p3.y, p2.y - p1.y) * b, vec2(p3.x - p1.x, p1.x - p2.x) * b) /
			(2 * (p1 ^ p3) + (p2 ^ p1) + (p3 ^ p2));
		r = c.dist(p1);
	}

	circle(vec2* pts, int s) {
		shuffle(pts, pts + s, default_random_engine(0));
		circle cir(pts[0], 0);
		for (int i = 1; i < s; ++i) {
			if (cir.c.dist(pts[i]) <= cir.r) continue;
			cir = circle(pts[i], 0);
			for (int j = 0; j < i; ++j) {
				if (cir.c.dist(pts[j]) <= cir.r) continue;
				cir.c = (pts[i] + pts[j]) / 2;
				cir.r = cir.c.dist(pts[i]);
				for (int k = 0; k < j; ++k) {
					if (cir.c.dist(pts[k]) <= cir.r) continue;
					cir = circle(pts[i], pts[j], pts[k]);
				}
			}
		}
		c = cir.c;
		r = cir.r;
	}
	
	double area() const {
		return M_PI * r * r;
	}
	
	

	

	

	

	

	int location(const circle& cir) const {
		double d = c.dist(cir.c);
		double d1 = r + cir.r;
		double d2 = abs(r - cir.r);
		return d > d1 ? 3 :
			eq(d, d1) ? 2 :
			d > d2 ? 1 :
			eq(d, d2) ? 0 : -1;
	}
	
	double intersection_area(const circle& cir) const {
		int l = location(cir);
		if (l > 1) return 0;
		if (l < 1) return r < cir.r ? area() : cir.area();
		double d = c.dist(cir.c);
		double t1 = (r * r + d * d - cir.r * cir.r) / (2 * r * d);
		double t2 = (cir.r * cir.r + d * d - r * r) / (2 * cir.r * d);
		double b = r * sqrt(1 - t1 * t1);
		double a1 = acos(t1) * r * r;
		double a2 = acos(t2) * cir.r * cir.r;
		return a1 + a2 - b * d;
	}
};

class vec3 {
	
public:

	double x, y, z;

	vec3() : x(0), y(0), z(0) { }

	vec3(double x, double y, double z) : x(x), y(y), z(z) { }

	vec3 operator+(const vec3& v) const {
		return { x + v.x, y + v.y, z + v.z };
	}

	vec3 operator-(const vec3& v) const {
		return { x - v.x, y - v.y, z - v.z };
	}

	vec3 operator*(double v) const {
		return { x * v, y * v, z * v };
	}

	vec3 operator/(double v) const {
		return { x / v, y / v, z / v };
	}

	vec3 operator*(const vec3& v) const {
		return { x * v.x, y * v.y, z * v.z };
	}

	vec3 operator^(const vec3& v) const {
		return { y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x };
	}

	bool operator==(const vec3& v) const {
		return eq(x, v.x) && eq(y, v.y) && eq(z, v.z);
	}

	double mag() const {
		return sqrt(x * x + y * y + z * z);
	}

	double mag_2() const {
		return x * x + y * y + z * z;
	}

	double dist(const vec3& v) const {
		return (*this - v).mag();
	}
};

class sphere {
	
public:

	vec3 c; 


	double r; 


	sphere() : c(vec3()), r(0) { }

	sphere(vec3 c, double r) : c(c), r(r) { }

	double volume() const {
		return r * r * r * 4 / 3 * M_PI;
	}

	

	

	

	

	

	int location(const sphere& s) const {
		double d = c.dist(s.c);
		double d1 = r + s.r;
		double d2 = abs(r - s.r);
		return d > d1 ? 3 :
			eq(d, d1) ? 2 :
			d > d2 ? 1 :
			eq(d, d2) ? 0 : -1;
	}

	double intersection_volume(sphere& s) const {
		int l = location(s);
		if (l > 1) return 0;
		if (l < 1) return r < s.r ? volume() : s.volume();
		double d = c.dist(s.c);
		double t = (r * r + d * d - s.r * s.r) / (2 * r * d);
		double r0 = r * sqrt(1 - t * t);
		double l1 = sqrt(r * r - r0 * r0);
		double l2 = sqrt(s.r * s.r - r0 * r0);
		double v1 = ((r * r * r - l1 * l1 * l1) * 2 / 3 - r0 * r0 * l1) * M_PI;
		if (d * d + r * r - s.r * s.r < 0) v1 = volume() - v1;
		double v2 = ((s.r * s.r * s.r - l2 * l2 * l2) * 2 / 3 - r0 * r0 * l2) * M_PI;
		if (d * d + s.r * s.r - r * r < 0) v2 = s.volume() - v2;
		return v1 + v2;
	}
	
	double union_volume(sphere& s) const {
		return volume() + s.volume() - intersection_volume(s);
	}
};

class scan_line {
	
public:
	
	int n;
	int* an; 

	int* mn; 

	int* tn; 

	int* bn; 

	
	

	scan_line(int* an, int n) : an(an), n(n) {
		mn = new int[n * 4];
		tn = new int[n * 4];
		bn = new int[n * 4];
		fill(mn, mn + n * 4, 0);
		fill(bn, bn + n * 4, 0);
		build(1, n, 1);
	}
	
	void build(unsigned b, unsigned e, unsigned p) {
		if (b == e) {
			tn[p] = an[b];
			return;
		}
		unsigned m = (b + e) >> 1;
		build(b, m, p << 1);
		build(m + 1, e, p << 1 | 1);
		tn[p] = tn[p << 1] + tn[p << 1 | 1];
	}
	
	int get(int l, int r, unsigned b, unsigned e, unsigned p, int t = 0) {
		if (l <= b && e <= r) return tn[p] * (t + mn[p] == 0);
		unsigned m = (b + e) >> 1;
		return (l <= m ? get(l, r, b, m, p << 1, t + bn[p]) : 0) +
			(r > m ? get(l, r, m + 1, e, p << 1 | 1, t + bn[p]) : 0);
	}
	
	void update(int l, int r, int v, unsigned b, unsigned e, unsigned p) {
		if (l <= b && e <= r) {
			mn[p] += v;
			bn[p] += v;
			return;
		}
		unsigned m = (b + e) >> 1;
		if (l <= m) update(l, r, v, b, m, p << 1);
		if (r > m) update(l, r, v, m + 1, e, p << 1 | 1);
		int d = mn[p << 1] - mn[p << 1 | 1];
		mn[p] = min(mn[p << 1], mn[p << 1 | 1]) + bn[p];
		tn[p] = tn[p << 1] * (d <= 0) + tn[p << 1 | 1] * (d >= 0);
	}
};

template <class type>

class rbtree {
	
public:
	
	class node {
		
	public:
		
		type v; 

		bool c; 

		int s; 

		int q; 

		
		node* p; 

		node* l = nullptr; 

		node* r = nullptr; 

		
		node(type v, bool c = 1, node* p = nullptr, int s = 1, int q = 1) : v(v), c(c), p(p), s(s), q(q) { }
		
		node* prev() {
			node* n = this;
			if (n->l != nullptr) {
				n = n->l;
				while (n->r != nullptr) n = n->r;
				return n;
			}
			while (n->p->p != nullptr && n->p->l == n) n = n->p;
			return n->p;
		}
		
		node* next() {
			node* n = this;
			if (n->r != nullptr) {
				n = n->r;
				while (n->l != nullptr) n = n->l;
				return n;
			}
			while (n->p->p != nullptr && n->p->r == n) n = n->p;
			return n->p;
		}
	};
	
	node* end_node = new node(numeric_limits<type>::max(), 1, nullptr, 0, 0);
	
	node* root = end_node;
	
	int size(node* n) {
		return n == nullptr ? 0 : n->s;
	}
	
	void resize(node* n) {
		n->s = size(n->l) + size(n->r) + n->q;
	}
	
	void rotate(node* p, node* n, bool d) {
		node* g = p->p;
		n->p = g;
		p->p = n;
		node* c;
		if (d) {
			p->l = c = n->r;
			n->r = p;
		} else {
			p->r = c = n->l;
			n->l = p;
		}
		if (c != nullptr) c->p = p;
		if (p == root) root = n;
		else (n->v < g->v ? g->l : g->r) = n;
		resize(p);
		resize(n);
	}
	
	node* find(type v, int d = 0) {
		node* n = root;
		while (n != nullptr && v != n->v) {
			n->s += d;
			n = v < n->v ? n->l : n->r;
		}
		if (n != nullptr) n->s += d;
		return n;
	}
	
	node* find(type v, node*& p, int d = 0) {
		node* n = root;
		while (n != nullptr && v != n->v) {
			n->s += d;
			p = n;
			n = v < n->v ? n->l : n->r;
		}
		if (n != nullptr) n->s += d;
		return n;
	}
	
	void insert(type v) {
		node* p = nullptr;
		node* n = find(v, p, 1);
		if (n == nullptr) insert_fixup((v < p->v ? p->l : p->r) = new node(v, 0, p));
		else ++n->q;
	}
	
	void insert_fixup(node* n) {
		while (n != root && !n->p->c) {
			node* p = n->p;
			node* g = p->p;
			bool lp = g->l == p;
			node* u = lp ? g->r : g->l;
			if (u == nullptr || u->c) {
				bool ln = p->l == n;
				if (ln ^ lp) {
					rotate(p, n, ln);
					swap(n, p);
				}
				rotate(g, p, lp);
				swap(p->c, g->c);
				break;
			} else {
				p->c = u->c = 1;
				if (g == root) break;
				g->c = 0;
				n = g;
			}
		}
	}
	
	void erase(type v) {
		node* n = find(v, -1);
		if (--n->q > 0) return;
		if (n->l != nullptr && n->r != nullptr) {
			node* l = n;
			l = l->l;
			while (l->r != nullptr) l = l->r;
			swap(n->v, l->v);
			swap(n->q, l->q);
			node* b = l;
			while (b != n) {
				resize(b);
				b = b->p;
			}
			resize(n);
			n = l;
		}
		erase_fixup(n);
		node* c = n->l != nullptr ? n->l : n->r;
		if (c != nullptr) c->p = n->p;
		if (n == root) root = c;
		else (n->p->l == n ? n->p->l : n->p->r) = c;
		root->c = 1;
		delete n;
	}
	
	void erase_fixup(node* n) {
		while (n->c && n != root) {
			node* p = n->p;
			bool lb = p->l != n;
			node* b = lb ? p->l : p->r;
			if (b->c) {
				bool rl = b->l != nullptr && !b->l->c;
				bool rr = b->r != nullptr && !b->r->c;
				if (rl || rr) {
					bool lc = (lb && rl) || !rr;
					node* c = lc ? b->l : b->r;
					c->c = 1;
					if (lb ^ lc) {
						rotate(b, c, lc);
						swap(b, c);
					}
					rotate(p, b, lb);
					swap(b->c, p->c);
					break;
				} else {
					b->c = 0;
					if (!p->c) {
						p->c = 1;
						break;
					}
					n = p;
				}
			} else {
				rotate(p, b, lb);
				swap(b->c, p->c);
			}
		}
	}
	
	node* lower_bound(type v) {
		node* p = nullptr;
		node* n = find(v, p);
		return n == nullptr ? (v < p->v ? p : p->next()) : n;
	}
	
	node* upper_bound(type v) {
		node* n = lower_bound(v);
		return n->v == v ? n->next() : n;
	}
	
	int rank(type v) {
		node* n = root;
		int rnk = size(n->l);
		while (n->v != v) {
			if (n->v > v) {
				n = n->l;
				rnk -= size(n->r) + n->q;
			} else {
				rnk += n->q;
				n = n->r;
				rnk += size(n->l);
			}
		}
		return rnk;
	}
	
	int rank(node* n) {
		int rnk = size(n->l);
		while (n != root) {
			bool d = n->p->r == n;
			n = n->p;
			if (d) rnk += size(n->l) + n->q;
		}
		return rnk;
	}
	
	node* nth_node(int r) {
		node* n = root;
		int rnk = size(n->l);
		while (rnk > r || rnk + n->q <= r) {
			if (rnk > r) {
				n = n->l;
				rnk -= size(n->r) + n->q;
			} else {
				rnk += n->q;
				n = n->r;
				rnk += size(n->l);
			}
		}
		return n;
	}
	
	type nth_element(int r) {
		return nth_node(r)->v;
	}
};

template <class type>

class frac {
	
public:
	
	type n; 

	type d; 

	
	frac() { };
	
	frac(type n, type d) {
		type c = gcd(n, d);
		this->n = n / c;
		this->d = d / c;
	}
	
	type gcd(type a, type b) const {
		return b == 0 ? a : gcd(b, a % b);
	}
	
	frac operator+(const frac& f) const {
		return { n * f.d + f.n * d, d * f.d };
	}
	
	frac operator-(const frac& f) const {
		return { n * f.d - f.n * d, d * f.d };
	}
	
	frac operator*(const frac& f) const {
		return { n * f.n, d * f.d };
	}
	
	frac operator/(const frac& f) const {
		return { n * f.d, d * f.n };
	}
	
	frac operator%(type m) {
		return { n % m, d % m };
	}
	
	bool operator==(const frac& f) const {
		return n == f.n && d == f.d;
	}
	
	type fmod(type m) const {
		type k = m - 2;
		type a = 1;
		type b = d;
		while (k > 0) {
			if (k & 1) a = a * b % m;
			b = b * b % m;
			k >>= 1;
		}
		return a * n % m;
	}
};

template <class type>

class mat {
	
public:
	
	int r = 0;
	int c = 0;
	type** mn;
	
	mat() { };
	
	mat(int r, int c) : r(r), c(c) {
		mn = new type*[r];
		mn[0] = new type[r * c];
		for (int i = 0; i < r; ++i) mn[i] = mn[0] + i * c;
		fill(mn[0], mn[0] + r * c, 0);
	}
	
	mat(int r, int c, type* v) : mat(r, c) {
		copy(v, v + r * c, mn[0]);
	}
	
	mat(const mat& mv) : mat(mv.r, mv.c, mv.mn[0]) { }
	
	type* operator[](int k) const {
		return mn[k];
	}
	
	mat operator+(const mat& v) const {
		mat mt(r, c);
		for (int i = 0; i < r * c; ++i) mt[0][i] = mn[0][i] + v[0][i];
		return mt;
	}
	
	void operator+=(const mat& v) const {
		for (int i = 0; i < r * c; ++i) mn[0][i] += v[0][i];
	}
	
	mat operator-(const mat& v) const {
		mat mt(r, c);
		for (int i = 0; i < r * c; ++i) mt[0][i] = mn[0][i] - v[0][i];
		return mt;
	}
	
	void operator-=(const mat& v) const {
		for (int i = 0; i < r * c; ++i) mn[0][i] -= v[0][i];
	}
	
	mat operator*(type v) const {
		mat mt(r, c);
		for (int i = 0; i < r * c; ++i) mt[0][i] = mn[0][i] * v;
		return mt;
	}
	
	void operator*=(type v) const {
		for (int i = 0; i < r * c; ++i) mn[0][i] *= v;
	}
	
	mat operator/(type v) const {
		mat mt(r, c);
		for (int i = 0; i < r * c; ++i) mt[0][i] = mn[0][i] / v;
		return mt;
	}
	
	void operator/=(type v) const {
		for (int i = 0; i < r * c; ++i) mn[0][i] /= v;
	}
	
	mat operator%(type v) const {
		mat mt(r, c);
		for (int i = 0; i < r * c; ++i) mt[0][i] = mn[0][i] % v;
		return mt;
	}
	
	void operator%=(type v) const {
		for (int i = 0; i < r * c; ++i) mn[0][i] %= v;
	}
	
	mat operator*(const mat& v) const {
		mat mt(r, v.c);
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				for (int k = 0; k < v.c; ++k)
					mt[i][k] += mn[i][j] * v[j][k];
		return mt;
	}
	
	static mat identity(int v) {
		mat mt(v, v);
		for (int i = 0; i < v; ++i) mt[i][i] = 1;
		return mt;
	}
	
	mat transpose() const {
		return mat(c, r, mn[0]);
	}
	
	mat pow(unsigned v) const {
		mat mt = identity(r);
		mat bs = *this;
		while (v > 0) {
			if (v & 1) mt = mt * bs;
			bs = bs * bs;
			v >>= 1;
		}
		return mt;
	}
	
	type determinant() const {
		mat mt = mat(*this);
		for (int i = 0; i < r; ++i) {
			for (int j = i + 1; j < r; ++j) {
				double rt = mt[j][i] / mt[i][i];
				for (int k = i; k < r; ++k) mt[j][k] -= mt[i][k] * rt;
			}
		}
		type det = 1;
		for (int i = 0; i < r; ++i) det *= mt[i][i];
		return det;
	}
	
	int guass_elimination(mat& v) const {
		mat mt = mat(*this);
		for (int i = 0; i < r; ++i) {
			for (int j = i + 1; j < r; ++j) {
				double rt = mt[j][i] / mt[i][i];
				for (int k = i; k < c; ++k) mt[j][k] -= mt[i][k] * rt;
				for (int k = 0; k < v.c; ++k) v[j][k] -= v[i][k] * rt;
			}
		}
		int rnk = r;
		while (rnk > 0 && mt[rnk - 1][rnk - 1] == 0) --rnk;
		for (int i = 0; i < rnk; ++i) {
			for (int j = 0; j < v.c; ++j) v[i][j] /= mt[i][i];
			for (int j = c - 1; j >= i; --j) mt[i][j] /= mt[i][i];
		}
		for (int i = rnk - 1; i > 0; --i) {
			for (int j = 0; j < i; ++j) {
				double rt = mt[j][i] / mt[i][i];
				for (int k = 0; k < v.c; ++k) v[j][k] -= v[i][k] * rt;
			}
		}
		return rnk;
	}
	
	mat inverse() const {
		mat mt = identity(r);
		mat(*this).guass_elimination(mt);
		return mt;
	}
	
	mat conjugate_gradient(const mat& b) const {
		mat x = mat(r, 1);
		mat r = b - (*this) * x;
		mat p = mat(r);
		type rtr = 0;
		for (int i = 0; i < r.r; ++i) rtr += r[i][0] * r[i][0];
		for (int i = 0; i < 5; ++i) {
			mat ap = (*this) * p;
			type ptap = 0;
			for (int i = 0; i < p.r; ++i) ptap += p[i][0] * ap[i][0];
			type alpha = rtr / ptap;
			x = x + p * alpha;
			mat r1 = r - ap * alpha;
			type id1 = 0;
			for (int i = 0; i < r.r; ++i) id1 += r1[i][0] * r1[i][0];
			type beta = id1 / rtr;
			p = r1 + p * beta;
			r = r1;
			rtr = id1;
		}
		return x;
	}
};

mat<ll> matcross(const mat<ll>& a, const mat<ll>& b, ll m) {
	mat<ll> mt(a.r, b.c);
	for (int i = 0; i < a.r; ++i)
		for (int j = 0; j < a.c; ++j)
			for (int k = 0; k < b.c; ++k)
				mt[i][k] = (mt[i][k] + a[i][j] * b[j][k]) % m;
	return mt;
}

mat<ll> matpow(const mat<ll>& b, int v, ll m) {
	mat<ll> mt = mat<ll>::identity(b.r);
	mat<ll> bs = b;
	while (v > 0) {
		if (v & 1) mt = matcross(mt, bs, m);
		bs = matcross(bs, bs, m);
		v >>= 1;
	}
	return mt;
}

void matdiv(ll* an, ll* bn, int c, int n, ll m) {
	ll* mx = an;
	ll* mn = bn;
	if (mx[c] < mn[c]) swap(mx, mn);
	while (mn[c] > 0) {
		ll rt = mx[c] / mn[c];
		for (int i = c; i < n; ++i) mx[i] = (mx[i] + (m - rt) * mn[i]) % m;
		swap(mx, mn);
	}
	if (an[c] == 0) {
		for (int i = c; i < n; ++i) {
			swap(an[i], bn[i]);
			an[i] = m - an[i];
		}
	}
}

void matdiv(ll* an, ll* bn, ll* cn, ll* dn, int c1, int n1, int c2, int n2, ll m) {
	ll* mx = an;
	ll* mn = bn;
	ll* vx = cn;
	ll* vn = dn;
	if (mx[c1] < mn[c1]) {
		swap(mx, mn);
		swap(vx, vn);
	}
	while (mn[c1] > 0) {
		ll rt = mx[c1] / mn[c1];
		for (int i = c1; i < n1; ++i) mx[i] = (mx[i] + (m - rt) * mn[i]) % m;
		for (int i = c2; i < n2; ++i) vx[i] = (vx[i] + (m - rt) * vn[i]) % m;
		swap(mx, mn);
		swap(vx, vn);
	}
	if (an[c1] == 0) {
		for (int i = c1; i < n1; ++i) {
			swap(an[i], bn[i]);
			an[i] = m - an[i];
		}
		for (int i = c2; i < n2; ++i) {
			swap(cn[i], dn[i]);
			cn[i] = m - cn[i];
		}
	}
}

ll matdet(const mat<ll>& v, ll m) {
	mat<ll> mt = mat<ll>(v);
	for (int i = 0; i < mt.r; ++i) for (int j = i + 1; j < mt.r; ++j) matdiv(mt[i], mt[j], i, mt.c, m);
	ll det = 1;
	for (int i = 0; i < mt.r; ++i) det = (det * mt[i][i]) % m;
	return det;
}

int mateli(const mat<ll>& a, mat<ll>& b, ll m) {
	mat<ll> mt = mat<ll>(a);
	for (int i = 0; i < a.r; ++i)
		for (int j = i + 1; j < a.r; ++j)
			matdiv(mt[i], mt[j], b[i], b[j], i, mt.c, 0, b.c, m);
	int rnk = a.r;
	while (rnk > 0 && mt[rnk - 1][rnk - 1] == 0) --rnk;
	for (int i = 0; i < rnk; ++i) {
		for (int j = 0; j < b.c; ++j) b[i][j] = frac<ll>(b[i][j], mt[i][i]).fmod(m);
		for (int j = a.c - 1; j >= i; --j) mt[i][j] = frac<ll>(mt[i][j], mt[i][i]).fmod(m);
	}
	for (int i = rnk - 1; i > 0; --i)
		for (int j = 0; j < i; ++j)
			matdiv(mt[i], mt[j], b[i], b[j], i, mt.c, 0, b.c, m);
	return rnk;
}

template <class type>
inline type read() {
	type x = 0;
	bool f = 0;
	int ch = getchar();


	while (!isdigit(ch)) {
		f |= (ch == '-');
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return f ? -x : x;
}

template <class type>
inline void write(type x) {
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}

MAIN

int t;
cin >> t;

for (int _ = 0; _ < t; ++_) {
	int k;
	string s;
	int i3 = 0, i7 = 0;
	cin >> k >> s;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' || s[i] == '9') {
			cout << 1 << endl << s[i] << endl;
			goto endloop;
		}
	}
	for (int i = 1; i < s.length(); ++i) {
		if (s[i] == '2' || s[i] == '5') {
			cout << 2 << endl << s[0] << s[i] << endl;
			goto endloop;
		}
	}
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '3') {
			if (i3 == 0) {
				i3 = 1;
			} else {
				cout << 2 << endl << 33 << endl;
				goto endloop;
			}
		} else if (s[i] == '7') {
			if (i7 == 0) {
				i7 = 1;
			} else {
				cout << 2 << endl << 77 << endl;
				goto endloop;
			}
		}
	}
	cout << 2 << endl << s[0] << 7 << endl;
	endloop:
	continue;
}

END
