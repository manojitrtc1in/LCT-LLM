

using namespace std;







typedef long long ll;
typedef pair<int, int> ii;




typedef double ld;
const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-9;



bool eq(ld a, ld b) {
	return abs(a - b) <= eps;
}

struct pt { 

	ld x, y;
	pt() {}
	pt(ld x_, ld y_) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (!eq(x, p.x)) return x < p.x;
		if (!eq(y, p.y)) return y < p.y;
		return 0;
	}
	bool operator == (const pt p) const {
		return eq(x, p.x) and eq(y, p.y);
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const ld c) const { return pt(x*c  , y*c  ); }
	pt operator / (const ld c) const { return pt(x/c  , y/c  ); }
	ld operator * (const pt p) const { return x*p.x + y*p.y; }
	ld operator ^ (const pt p) const { return x*p.y - y*p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

struct line { 

	pt p, q;
	line() {}
	line(pt p_, pt q_) : p(p_), q(q_) {}
	friend istream& operator >> (istream& in, line& r) {
		return in >> r.p >> r.q;
	}
};




ld dist(pt p, pt q) { 

	return hypot(p.y - q.y, p.x - q.x);
}

ld dist2(pt p, pt q) { 

	return sq(p.x - q.x) + sq(p.y - q.y);
}

ld norm(pt v) { 

	return dist(pt(0, 0), v);
}

ld angle(pt v) { 

	ld ang = atan2(v.y, v.x);
	if (ang < 0) ang += 2*pi;
	return ang;
}

ld sarea(pt p, pt q, pt r) { 

	return ((q-p)^(r-q))/2;
}

bool col(pt p, pt q, pt r) { 

	return eq(sarea(p, q, r), 0);
}

int paral(pt u, pt v) { 

	if (!eq(u^v, 0)) return 0;
	if ((u.x > eps) == (v.x > eps) and (u.y > eps) == (v.y > eps))
		return 1;
	return -1;
}

bool ccw(pt p, pt q, pt r) { 

	return sarea(p, q, r) > eps;
}

pt rotate(pt p, ld th) { 

	return pt(p.x * cos(th) - p.y * sin(th),
			p.x * sin(th) + p.y * cos(th));
}

pt rotate90(pt p) { 

	return pt(-p.y, p.x);
}




bool isvert(line r) { 

	return eq(r.p.x, r.q.x);
}

ld getm(line r) { 

	if (isvert(r)) return DINF;
	return (r.p.y - r.q.y) / (r.p.x - r.q.x);
}

ld getn(line r) { 

	if (isvert(r)) return DINF;
	return r.p.y - getm(r) * r.p.x;
}

bool paraline(line r, line s) { 

	return paral(r.p - r.q, s.p - s.q);
}

bool isinseg(pt p, line r) { 

	if (p == r.p or p == r.q) return 1;
	return paral(p - r.p, p - r.q) == -1;
}

ld get_t(pt v, line r) { 

	if (eq(0, (r.p-r.q)^v)) return DINF;
    return (r.p^r.q) / ((r.p-r.q)^v);
}

pt proj(pt p, line r) { 

	if (r.p == r.q) return r.p;
	r.q = r.q - r.p; p = p - r.p;
	pt proj = r.q * ((p*r.q) / (r.q*r.q));
	return proj + r.p;
}

pt inter(line r, line s) { 

	if (paraline(r, s)) return pt(DINF, DINF);

	if (isvert(r)) return pt(r.p.x, getm(s) * r.p.x + getn(s));
	if (isvert(s)) return pt(s.p.x, getm(r) * s.p.x + getn(r));

	ld x = (getn(s) - getn(r)) / (getm(r) - getm(s));
	return pt(x, getm(r) * x + getn(r));
}

bool interseg(line r, line s) { 

	if (isinseg(r.p, s) or isinseg(r.q, s)
		or isinseg(s.p, r) or isinseg(s.q, r)) return 1;

	return ccw(r.p, r.q, s.p) != ccw(r.p, r.q, s.q) and
			ccw(s.p, s.q, r.p) != ccw(s.p, s.q, r.q);
}

ld id1(pt p, line r) { 

	return dist(p, proj(p, r));
}

ld id6(pt p, line r) { 

	if (isinseg(proj(p, r), r))
		return id1(p, r);
	return min(dist(p, r.p), dist(p, r.q));
}

ld distseg(line a, line b) { 

	if (interseg(a, b)) return 0;

	ld ret = DINF;
	ret = min(ret, id6(a.p, b));
	ret = min(ret, id6(a.q, b));
	ret = min(ret, id6(b.p, a));
	ret = min(ret, id6(b.q, a));

	return ret;
}








ld id3(pair<pt, pt> a, pair<pt, pt> b) {
	ld hor = 0, vert = 0;
	if (a.s.x < b.f.x) hor = b.f.x - a.s.x;
	else if (b.s.x < a.f.x) hor = a.f.x - b.s.x;
	if (a.s.y < b.f.y) vert = b.f.y - a.s.y;
	else if (b.s.y < a.f.y) vert = a.f.y - b.s.y;
	return dist(pt(0, 0), pt(hor, vert));
}

ld polarea(vector<pt> v) { 

	ld ret = 0;
	for (int i = 0; i < v.size(); i++)
		ret += sarea(pt(0, 0), v[i], v[(i + 1) % v.size()]);
	return abs(ret);
}

bool inpol(pt p, vector<pt> v) { 

	for (int i = 0; i < v.size(); i++)
		if (isinseg(p, line(v[i], v[(i+1)%v.size()]))) return 1;
	int c = 0;
	line r = line(p, pt(DINF, pi * DINF));
	for (int i = 0; i < v.size(); i++) {
		line s = line(v[i], v[(i + 1) % v.size()]);
		if (interseg(r, s)) c++;
	}
	return c % 2;
}

bool interpol(vector<pt> v1, vector<pt> v2) { 

	for (int i = 0; i < v1.size(); i++) if (inpol(v1[i], v2)) return 1;
	for (int i = 0; i < v2.size(); i++) if (inpol(v2[i], v1)) return 1;
	return 0;
}

ld distpol(vector<pt> v1, vector<pt> v2) { 

	if (interpol(v1, v2)) return 0;

	ld ret = DINF;

	for (int i = 0; i < v1.size(); i++) for (int j = 0; j < v2.size(); j++)
		ret = min(ret, distseg(line(v1[i], v1[(i + 1) % v1.size()]),
					line(v2[j], v2[(j + 1) % v2.size()])));
	return ret;
}

vector<pt> id5(vector<pt> v) { 

	if (v.size() <= 1) return v;
	vector<pt> l, u;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		while (l.size() > 1 and !ccw(l[l.size()-2], l.back(), v[i]))
			l.pop_back();
		l.pb(v[i]);
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		while (u.size() > 1 and !ccw(u[u.size()-2], u.back(), v[i]))
			u.pop_back();
		u.pb(v[i]);
	}
	l.pop_back(); u.pop_back();
	for (pt i : u) l.pb(i);
	return l;
}

struct id0 {
	vector<pt> pol;

	id0(vector<pt> v) : pol(id5(v)) {}
	bool is_inside(pt p) { 

		if (pol.size() == 1) return p == pol[0];
		int l = 1, r = pol.size();
		while (l < r) {
			int m = (l+r)/2;
			if (ccw(p, pol[0], pol[m])) l = m+1;
			else r = m;
		}
		if (l == 1) return isinseg(p, line(pol[0], pol[1]));
		if (l == pol.size()) return false;
		return !ccw(p, pol[l], pol[l-1]);
	}
};

bool operator < (const line& a, const line& b) { 

	if (a.p == b.p) return ccw(a.p, a.q, b.q);
	if (!eq(a.p.x, a.q.x) and (eq(b.p.x, b.q.x) or a.p.x+eps < b.p.x))
		return ccw(a.p, a.q, b.p);
	return ccw(a.p, b.q, b.p);
}

bool simple(vector<pt> v) { 

	auto intersects = [&](pair<line, int> a, pair<line, int> b) {
		if ((a.s+1)%v.size() == b.s or (b.s+1)%v.size() == a.s) return false;
		return interseg(a.f, b.f);
	};
	vector<line> seg;
	vector<pair<pt, pair<int, int>>> w;
	for (int i = 0; i < v.size(); i++) {
		pt at = v[i], nxt = v[(i+1)%v.size()];
		

		if (nxt < at) swap(at, nxt);
		seg.push_back(line(at, nxt));
		w.push_back({at, {0, i}});
		w.push_back({nxt, {1, i}});
		

		if (isinseg(v[(i+2)%v.size()], line(at, nxt))) return 0;
		if (isinseg(v[(i+v.size()-1)%v.size()], line(at, nxt))) return 0;

	}
	sort(w.begin(), w.end());
	set<pair<line, int>> se;
	for (auto i : w) {
		line at = seg[i.s.s];
		if (i.s.f == 0) {
			auto nxt = se.lower_bound({at, i.s.s});
			if (nxt != se.end() and intersects(*nxt, {at, i.s.s})) return 0;
			if (nxt != se.begin() and intersects(*(--nxt), {at, i.s.s})) return 0;
			se.insert({at, i.s.s});
		} else {
			auto nxt = se.upper_bound({at, i.s.s}), cur = nxt, prev = --cur;
			if (nxt != se.end() and prev != se.begin()
				and intersects(*nxt, *(--prev))) return 0;
			se.erase(cur);
		}
	}
	return 1;
}



bool id4(vector<line> v) {
	auto intersects = [&](pair<line, int> a, pair<line, int> b) {
		return interseg(a.f, b.f);
	};
	vector<pair<pt, pair<int, int>>> w;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].q < v[i].p) swap(v[i].p, v[i].q);
		w.push_back({v[i].p, {0, i}});
		w.push_back({v[i].q, {1, i}});
	}
	sort(w.begin(), w.end());
	set<pair<line, int>> se;
	for (auto i : w) {
		line at = v[i.s.s];
		if (i.s.f == 0) {
			auto nxt = se.lower_bound({at, i.s.s});
			if (nxt != se.end() and intersects(*nxt, {at, i.s.s})) return 1;
			if (nxt != se.begin() and intersects(*(--nxt), {at, i.s.s})) return 1;
			se.insert({at, i.s.s});
		} else {
			auto nxt = se.upper_bound({at, i.s.s}), cur = nxt, prev = --cur;
			if (nxt != se.end() and prev != se.begin()
				and intersects(*nxt, *(--prev))) return 1;
			se.erase(cur);
		}
	}
	return 0;
}




pt getcenter(pt a, pt b, pt c) { 

	b = (a + b) / 2;
	c = (a + c) / 2;
	return inter(line(b, b + rotate90(a - b)),
			line(c, c + rotate90(a - c)));
}

vector<pt> id2(pt a, pt b, pt c, ld r) { 

	vector<pt> ret;
	b = b-a, a = a-c;
	ld A = b*b;
	ld B = a*b;
	ld C = a*a - r*r;
	ld D = B*B - A*C;
	if (D < -eps) return ret;
	ret.push_back(c+a+b*(-B+sqrt(D+eps))/A);
	if (D > eps) ret.push_back(c+a+b*(-B-sqrt(D))/A);
	return ret;
}

vector<pt> circ_inter(pt a, pt b, ld r, ld R) { 

	vector<pt> ret;
	ld d = dist(a, b);
	if (d > r+R or d+min(r, R) < max(r, R)) return ret;
	ld x = (d*d-R*R+r*r)/(2*d);
	ld y = sqrt(r*r-x*x);
	pt v = (b-a)/d;
	ret.push_back(a+v*x + rotate90(v)*y);
	if (y > 0) ret.push_back(a+v*x - rotate90(v)*y);
	return ret;
}




double ang;
struct cmp {
	bool operator () (const line& a, const line& b) const {
		line r = line(pt(0, 0), rotate(pt(1, 0), ang));
		return norm(inter(r, a)) < norm(inter(r, b));
	}
};

int main(){ _
	int n;
	cin >> n;
	vector<pt> v(n), dir(n);
	vector<ld> s(n);
	for (int i = 0; i < n; i++){
		cin >> v[i] >> dir[i] >> s[i];
		dir[i] = dir[i]/norm(dir[i]);
	}
	
	ld ans = 1e10;
	for (int i = 0; i < n; i++){
		for (int j = i+1; j < n; j++){
			ld t_i = get_t(dir[i]*s[i], line(v[j]-v[i], v[j]-v[i]+dir[j]));
			ld t_j = get_t(dir[j]*s[j], line(v[i]-v[j], v[i]-v[j]+dir[i]));
			if (t_i > DINF-100) {
				if (paral(dir[i], dir[j]) == -1) {
					if (paral(v[j]-v[i], dir[i]) == 1) ans = min(ans, dist(v[i], v[j])/(s[i]+s[j]));
					continue;
				}
				if (paral(v[j]-v[i], dir[i]) == 1) ans = min(ans, dist(v[i], v[j])/s[i]);
				if (paral(v[i]-v[j], dir[j]) == 1) ans = min(ans, dist(v[i], v[j])/s[j]);
			} else if (min(t_i, t_j) > -eps) ans = min(ans, max(t_i, t_j));
		}
	}
	if (ans > 9e9) cout << "No show :(" << endl;
	else cout << fixed << setprecision(12) << ans << endl;

	exit(0);
}
