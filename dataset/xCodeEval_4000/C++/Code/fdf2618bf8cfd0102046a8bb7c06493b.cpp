#include <bits/stdc++.h>
using namespace std;

#define fst first
#define snd second
#define all(c) ((c).begin()), ((c).end())
#define TEST(x,a) { auto y=(x); if (sign(y-a)) { cout << "line " << __LINE__  << #x << " = " << y << " != " << a << endl; exit(-1); } }
double urand() { return rand() / (1.0 + RAND_MAX); }



double tick() {
  static clock_t oldtick;
  clock_t newtick = clock();
  double diff = 1.0*(newtick - oldtick) / CLOCKS_PER_SEC;
  oldtick = newtick;
  return diff;
}

template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  for (int i = 0; i < v.size(); os << v[i++])
    if (i > 0) os << " ";
  os << "]";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v) {
  os << "[";
  for (int i = 0; i < v.size(); os << v[i++])
    if (i > 0) os << endl << " ";
  os << "]";
  return os;
}

const double PI = acos(-1.0);





const double EPS = 1e-8;
int sign(double x) {
  if (x < -EPS) return -1;
  if (x > +EPS) return +1;
  return 0;
}

using rl = long double;
struct point {
  rl x, y;
  point(rl x = 0 , rl y = 0):x(x) , y(y){}
  point &operator+=(point p) { x += p.x; y += p.y; return *this; }
  point &operator-=(point p) { x -= p.x; y -= p.y; return *this; }
  point &operator*=(rl a)     { x *= a;   y *= a;   return *this; }
  point &operator/=(rl a)     { return *this *= (1.0/a); }
  point operator-() const    { return {-x, -y}; }
  bool operator<(point p) const {
    int s = sign(x - p.x);
    return s ? s < 0 : sign(y - p.y) < 0;
  }
};
bool operator==(point p, point q) { return !(p < q) && !(q < p); }
bool operator!=(point p, point q) { return p < q || q < p; }
bool operator<=(point p, point q) { return !(q < p); }
point operator+(point p, point q) { return p += q; }
point operator-(point p, point q) { return p -= q; }
point operator*(rl a, point p) { return p *= a; }
point operator*(point p, rl a) { return p *= a; }
point operator/(point p, rl a) { return p /= a; }
rl dot(point p, point q) { return p.x*q.x+p.y*q.y; }
rl cross(point p, point q) { return p.x*q.y-p.y*q.x; } 

rl norm2(point p) { return dot(p,p); }
point orth(point p) { return {-p.y, p.x}; }
rl norm(point p) { return sqrt(dot(p,p)); }
rl arg(point p) { return atan2(p.y, p.x); }
rl arg(point p, point q){ return atan2(cross(p,q), dot(p,q)); }

istream &operator>>(istream &is, point &p) { is>>p.x>>p.y;return is; }
ostream &operator<<(ostream &os, const point &p) { os<<"("<<p.x<<","<<p.y<<")"; return os; }






struct polar_angle {
  const point o;
  const int s; 

  polar_angle(point p = {0,0}, int s = +1) : o(p), s(s) { }
  int quad(point p) const {
    for (int i = 1; i <= 4; ++i, swap(p.x = -p.x, p.y))
      if (p.x > 0 && p.y >= 0) return i;
    return 0;
  }
  bool operator()(point p, point q) const {
    p = p - o; q = q - o;
    if (quad(p) != quad(q)) return s*quad(p) < s*quad(q);
    if (cross(p, q)) return s*cross(p, q) > 0;
    return norm2(p) < norm2(q); 

  }
};

struct line
{
    point p, q;
    line(point p = point(0,0) , point q = point(0,0)):p(p) , q(q){}
};
bool operator==(line l, line m) {
  return !sign(cross(l.p-l.q,m.p-m.q)) && !sign(cross(l.p-l.q,m.p-l.p));
}

struct segment
{
    point p, q;
    segment(point p = point(0,0) , point q = point(0,0)):p(p) , q(q){}
};
bool operator==(segment l, line m) {
  return (l.p==m.p && l.q==m.q) || (l.p==m.q && l.q==m.p); 

}
struct circle
{
    point p; rl r;
    circle(point p = point(0,0), rl r = 0):p(p) , r(r){}
};
bool operator==(circle c, circle d) { return c.p == d.p && !sign(c.r - d.r); }





vector<point> discretize(circle c, int n = 50) {
  vector<point> ps;
  for (int i = 0; i < n; ++i) {
    double x = cos(2*PI*i/n), y = sqrt(1 - x*x);
    ps.push_back(c.p + c.r * point({x,y}));
  }
  return ps;
}

typedef vector<point> polygon;








struct visualizer {
  rl minx, maxx, miny, maxy, scale;
  ofstream ofs;
  visualizer(string s = "data.js") : ofs(s) {
    minx = miny =  1.0/0.0;
    maxx = maxy = -1.0/0.0;
  }
  void update(point p) {
    minx = min(minx, p.x); miny = min(miny, p.y);
    maxx = max(maxx, p.x); maxy = max(maxy, p.y);
    scale = 480/(max(maxx-minx, max(maxy-miny,1.0l)));
  }
  double X(point p) { return scale * (p.x-minx) + 10; }
  double Y(point p) { return 490 - scale * (p.y-miny); }
  vector<point> ps;
  vector<segment> ss;
  vector<circle> cs;
  visualizer &operator<<(circle c) {
    cs.push_back(c);
    update(c.p + point({ c.r, c.r}));
    update(c.p + point({-c.r,-c.r}));
    return *this;
  }
  visualizer &operator<<(point p) {
    ps.push_back(p);
    update(p);
    return *this;
  }
  visualizer &operator<<(segment s) {
    ss.push_back(s);
    update(s.p);
    update(s.q);
    return *this;
  }
  ~visualizer() {
    for (point p: ps)
      ofs << "circle(" << X(p) << "," << Y(p) << ",3.0)" << endl;
    for (segment s: ss)
      ofs << "line(" << X(s.p) << "," << Y(s.p) << ","
                     << X(s.q) << "," << Y(s.q) << ")" << endl;
    for (circle c: cs)
      ofs << "circle(" << X(c.p) << "," << Y(c.p) << "," << scale*c.r << ")" << endl;
  }
};








vector<point> intersect(line l, point p) {
  if (sign(cross(l.p-p, l.q-p)) != 0) return {};
  return {p};
}
vector<point> intersect(point p, line l) {
  return intersect(l, p);
}







vector<point> intersect(segment s, point p) {
  if (sign(cross(s.p-p, s.q-p)) != 0) return {};
  if (sign(  dot(s.p-p, s.q-p))  > 0) return {}; 

  return {p};                                    

}
vector<point> intersect(point p, segment s) {
  return intersect(s, p);
}



























vector<point> intersect(line l, line m) {
  auto a = cross(m.q - m.p, l.q - l.p);
  auto b = cross(l.p - m.p, l.q - l.p);
  if ( sign(a)) return {m.p + b/a*(m.q - m.p)}; 

  if (!sign(b)) return {m.p, m.q};              

  return {};                                    

}













vector<point> intersect(line l, segment s) {
  auto a = cross(s.q - s.p, l.q - l.p);
  auto b = cross(l.p - s.p, l.q - l.p);
  if (a < 0) { a *= -1; b *= -1; }
  if (sign(b) < 0 || sign(a-b) < 0) return {};      

  if (sign(a) != 0) return {s.p + b/a*(s.q - s.p)}; 

  if (sign(b) == 0) return {s.p, s.q};              

  return {};                                        

}













vector<point> intersect(segment s, segment t) {
  auto a = cross(s.q - s.p, t.q - t.p);
  auto b = cross(t.p - s.p, t.q - t.p);
  auto c = cross(s.q - s.p, s.p - t.p);
  if (a < 0) { a = -a; b = -b; c = -c; }
  if (sign(b) < 0 || sign(a-b) < 0 ||
      sign(c) < 0 || sign(a-c) < 0) return {};      

  if (sign(a) != 0) return {s.p + b/a*(s.q - s.p)}; 

  vector<point> ps;                                 

  auto insert_if_possible = [&](point p) {
    for (auto q: ps) if (sign(dot(p-q, p-q)) == 0) return;
    ps.push_back(p);
  };
  if (sign(dot(s.p-t.p, s.q-t.p)) <= 0) insert_if_possible(t.p);
  if (sign(dot(s.p-t.q, s.q-t.q)) <= 0) insert_if_possible(t.q);
  if (sign(dot(t.p-s.p, t.q-s.p)) <= 0) insert_if_possible(s.p);
  if (sign(dot(t.p-s.q, t.q-s.q)) <= 0) insert_if_possible(s.q);
  return ps;
}







point reflection(point p, line l) {
  auto a = dot(l.p-l.q, l.p-l.q);
  auto b = dot(l.p-p,   l.p-l.q);
  return 2 * (l.p + a/b*(l.q - l.p)) - p;
}







point projection(point p, line l) {
  auto a = dot(l.p-l.q, l.p-l.q);
  auto b = dot(l.p-p,   l.p-l.q);
  return l.p + a/b*(l.q - l.p);
}







point projection(point p, segment s) {
  auto a = dot(s.p-s.q, s.p-s.q);
  auto b = dot(s.p - p, s.p-s.q);
  if (sign(b)   < 0) return s.p;
  if (sign(a-b) < 0) return s.q;
  return s.p + b/a*(s.q - s.p);
}







point projection(point p, circle c) {
  point v = p - c.p;
  return c.p + c.r * v / norm(v);
}






rl dist(point p, point q) {
  return norm(p-q);
}
rl dist(point p, line l) {
  return dist(p, projection(p, l));
}
rl dist(line l, point p) {
  return dist(p, l);
}
rl dist(line l, line m) {
  if (sign(cross(l.p-l.q,m.p-m.q))) return 0; 

  return dist(l.p, m);
}
rl dist(point p, segment s) {
  return dist(p, projection(p, s));
}
rl dist(line l, segment s) {
  if (intersect(l, s).size()) return 0;
  return min(dist(l, s.p), dist(l, s.q));
}
rl dist(segment s, line l) {
  return dist(l, s);
}
rl dist(segment s, segment T) {
  if (intersect(s, T).size()) return 0;
  return min({dist(s.p,T), dist(s.q,T), dist(T.p,s), dist(T.q,s)});
}








vector<point> intersect(circle c, circle d) {
  if (c.r < d.r) swap(c, d);
  auto pow2 = [](rl a) { return a*a; };
  auto g = dot(c.p-d.p, c.p-d.p);
  if (sign(g) == 0) {
    if (sign(c.r-d.r) != 0) return {};
    return {{c.p.x+c.r, c.p.y}, {c.p.x, c.p.y+c.r}, {c.p.x-c.r, c.p.y}};
  }
  int inner = sign(g-pow2(c.r-d.r));
  int outer = sign(g-pow2(c.r+d.r));
  if (inner < 0 || outer > 0) return {};
  if (inner == 0) return {(c.r*d.p-d.r*c.p)/(c.r-d.r)};
  if (outer == 0) return {(c.r*d.p+d.r*c.p)/(c.r+d.r)};
  auto eta = (pow2(c.r) - pow2(d.r) + g)/(2*g);
  auto mu = sqrt(pow2(c.r)/g - pow2(eta));
  point q = c.p + eta*(d.p-c.p), v = mu*orth(d.p - c.p);
  return {q + v, q - v};
}







vector<point> intersect(line l, circle c) {
  point u = l.q - l.p, v = l.p - c.p;
  auto a = dot(u,u), b = dot(u,v)/a, t = (dot(v,v) - c.r*c.r)/a;
  auto det = b*b - t;
  if (sign(det) <  0) return {};          

  if (sign(det) == 0) return {l.p - b*u}; 

  return {l.p - (b + sqrt(det))*u,        

          l.p - (b - sqrt(det))*u};
}
vector<point> intersect(circle c, line l) {
  return intersect(l, c);
}





















vector<point> intersect(circle c, segment s) {
  point u = s.q - s.p, v = s.p - c.p;
  auto a = dot(u,u), b = dot(u,v)/a, t = (dot(v,v) - c.r*c.r)/a;
  auto det = b*b - t;
  if (sign(det) <  0) return {};          


  auto t1 = -b - sqrt(det), t2 = -b + sqrt(det);
  vector<point> ps;
  auto insert_if_possible = [&](point p) {
    for (auto q: ps) if (sign(dot(p-q, p-q)) == 0) return;
    ps.push_back(p);
  };
  if (sign(c.r - norm(s.p-c.p))   >= 0) insert_if_possible(s.p);
  if (sign(t1) >= 0 && sign(1-t1) >= 0) insert_if_possible(s.p+t1*u);
  if (sign(t2) >= 0 && sign(1-t2) >= 0) insert_if_possible(s.p+t2*u);
  if (sign(c.r - norm(s.q-c.p))   >= 0) insert_if_possible(s.q);
  return ps;
}
vector<point> intersect(segment s, circle c) {
  return intersect(c, s);
}
bool contains(circle c, point p) {
  return sign(dot(c.p-p, c.p-p) - c.r * c.r) <= 0;
}










int contains(polygon ps, point p) {
  bool in = false;
  for (int i = 0; i < ps.size(); ++i) {
    int j = (i+1 == ps.size() ? 0 : i+1);
    point a = ps[i] - p, b = ps[j] - p;
    if (a.y > b.y) swap(a, b);
    if (a.y <= 0 && 0 < b.y && cross(a, b) < 0) in = !in;
    if (!sign(cross(a, b)) && sign(dot(a, b)) <= 0)
      return 1; 

  }
  return in ? 2 : 0; 

}























polygon convex_hull(vector<point> ps) {
  int n = ps.size(), k = 0;
  sort(all(ps));
  vector<point> ch(2*n);
  auto cond = [&](point p, point q, point o) {
    int a = sign(cross(p-o, q-o)); 

    return a ? a < 0 : sign(dot(p-o, q-o)) >= 0;
  };
  for (int i = 0; i < n; ch[k++] = ps[i++]) 

    for (; k >= 2 && cond(ch[k-2], ch[k-1], ps[i]); --k);
  for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) 

    for (; k >= t && cond(ch[k-2], ch[k-1], ps[i]); --k);
  ch.resize(k-1);
  return ch;
}
















pair<point,point> farthest_pair(vector<point> ps) {
  vector<point> ch = convex_hull(ps);
  int n = ch.size();
  int u = 0, v = 1;
  rl best = -1;
  for (int i = 0, j = 1; i < n; ++i) {
    while (1) {
      int k = (j+1 < n ? j+1 : 0);
      rl len = norm2(ch[j] - ch[i]);
      if (sign(len - norm2(ch[k] - ch[i])) <= 0) j = k;
      else {
        if (best < len) { best = len; u = i; v = j; }
        break;
      }
    }
  }
  return make_pair(ch[u], ch[v]);
}












rl area(polygon ps) {
  if (ps.size() <= 2) return 0;
  auto a = cross(ps.back(), ps[0]);
  for (int i = 0; i+1 < ps.size(); ++i)
    a += cross(ps[i], ps[i+1]);
  return a/2;
}











polygon convex_cut(polygon ps, line l) {
  vector<point> qs;
  for (int i = 0; i < ps.size(); ++i) {
    int j = (i+1 == ps.size() ? 0 : i+1);
    if (sign(cross(l.p - ps[i], l.q - ps[i])) >= 0) qs.push_back(ps[i]);
    if (sign(cross(l.p - ps[i], l.q - ps[i])) *
        sign(cross(l.p - ps[j], l.q - ps[j])) < 0) {
      auto a = cross(ps[j] - ps[i], l.q - l.p);
      auto b = cross(l.p - ps[i], l.q - l.p);
      qs.push_back(ps[i] + b/a*(ps[j] - ps[i]));
    }
  }
  return qs;
}







circle three_point_circle(point p, point q, point r) {
  point u = orth(q - p), v = r - p;
  point o = (p+q + u*dot(r-q,v)/dot(u,v))/2;
  return {o, norm(p-o)};
}








rl quadrilateral_area(rl a, rl b, rl c, rl d) {
  rl s = a+b+c+d;
  return sqrt((s-a)*(s-b)*(s-c)*(s-d))/4;
}
rl triangle_area(rl a, rl b, rl c) {
  return quadrilateral_area(a, b, c, 0);
}
rl excircle_radius(rl a, rl b, rl c) {
  return a*b*c/4/triangle_area(a, b, c);
}
rl incircle_radius(rl a, rl b, rl c) {
  return 2*triangle_area(a,b,c)/(a+b+c);
}























vector<line> tangent(point p, circle c) {
  point u = p - c.p, v = orth(u);
  auto g = dot(u,u) - c.r*c.r;
  if (sign(g) < 0) return {};
  if (sign(g) == 0) return {{p, p + v}};
  u = u * (c.r*c.r/dot(u,u));
  v = v * (c.r*sqrt(g)/dot(v,v));
  return {{p, c.p + u - v}, {p, c.p + u + v}};
}
vector<line> tangent(circle c, point p) {
  return tangent(p, c);
}











vector<line> tangent(circle c, circle d) {
  if (c.r < d.r) swap(c, d);
  auto g = dot(c.p-d.p, c.p-d.p);
  if (sign(g) == 0) return {}; 

  point u = (d.p-c.p)/sqrt(g), v = orth(u); 

  vector<line> ls;
  for (int s = +1; s >= -1; s -= 2) {
    auto h = (c.r+s*d.r)/sqrt(g); 

    if (sign(1 - h*h) == 0) { 

      ls.push_back({c.p+c.r*u, c.p+c.r*(u+v)});
    } else if (sign(1 - h*h) > 0) { 

      point uu = h*u, vv = sqrt(1-h*h)*v;
      ls.push_back({c.p+c.r*(uu+vv), d.p-d.r*(uu+vv)*s});
      ls.push_back({c.p+c.r*(uu-vv), d.p-d.r*(uu-vv)*s});
    }
  }
  return ls;
}





























vector<circle> tangent_circles(line l, line m, rl r) {
  vector<circle> cs;
  rl a = cross(l.p-m.p, l.q-l.p), b = cross(m.q-m.p, l.q-l.p);
  if (!sign(b)) { 

    if (l.q < l.p) swap(l.p, l.q);
    if (m.q < m.p) swap(m.p, m.q);
    if (sign(cross(m.p-l.p, m.q-l.p)) >= 0) swap(l, m); 

    point v = orth(m.q - m.p); v /= norm(v);
    rl d = a / cross(l.q - l.p, v);
    if (sign(d - 2*r) == 0) cs.push_back({l.p + r * v, r});
  } else {
    point o = m.p + a/b * (m.q - m.p), u = l.q - l.p, v = m.q - m.p;
    u /= norm(u); v /= norm(v);
    for (int i = 0; i < 4; ++i) {
      point w = u + v; w /= norm(w);
      rl t = r / sqrt(1 - dot(v,w)*dot(v,w));
      cs.push_back({o + t * w, r});
      u *= -1; swap(u, v);
    }
  }
  return cs;
}











int maximum_points_line(vector<point> ps) {
  sort(all(ps)); 

  int max_count = 0;
  for (int i = 0; i < ps.size(); ++i) {
    vector<point> qs;
    int base = 1;
    for (int j = 0; j < i; ++j)
      if (ps[j] == ps[i]) ++base;
      else qs.push_back(ps[j] - ps[i]);
    sort(all(qs), polar_angle());
    for (int j = 0, k; j < qs.size(); j += k) {
      for (k = 1; j+k < qs.size() && sign(cross(qs[j], qs[j+k])) == 0; ++k);
      max_count = max(max_count, base + k);
    }
  }
  return max_count;
}



int maximum_points_line_n(vector<point> ps) {
  sort(all(ps));
  int ans = 0;
  for (int i = 0; i < ps.size(); ++i) {
    for (int j = i+1; j < ps.size(); ++j) {
      if (ps[i] == ps[j]) continue;
      int count = 0;
      for (int k = 0; k < ps.size(); ++k) {
        if (intersect((line){ps[i], ps[j]}, ps[k]).size() > 0) ++count;
      }
      ans = max(ans, count);
    }
  }
  return ans;
}
void verify_maximum_points_line() {
  int n = 100;
  vector<point> ps(n);
  for (int i = 0; i < n; ++i) {
    ps[i].x = rand() % 20;
    ps[i].y = rand() % 20;
  }
  cout << maximum_points_line(ps) << endl;
  cout << maximum_points_line_n(ps) << endl;
}












rl triangulate(vector<point> ps) {
  int n = ps.size();
  vector<int> next(n);
  for (int i = 0; i < n-1; ++i) next[i] = i+1;
  auto is_ear = [&](int i, int j, int k) {
    if (sign(cross(ps[j]-ps[i], ps[k]-ps[i])) <= 0) return false;
    for (int l = next[k]; l != i; l = next[l])
      if (sign(cross(ps[i]-ps[l], ps[j]-ps[l])) >= 0
       && sign(cross(ps[j]-ps[l], ps[k]-ps[l])) >= 0
       && sign(cross(ps[k]-ps[l], ps[i]-ps[l])) >= 0) return false;
    return true;
  };
  rl area = 0;
  for (int i = 0; next[next[i]] != i; ) {
    if (is_ear(i, next[i], next[next[i]])) {
      area  += abs(cross(ps[next[i]]-ps[i], ps[next[next[i]]] - ps[i])) / 2;
      next[i] = next[next[i]];
    } else i = next[i];
  }
  return area;
}









rl intersection_area(circle c, circle d) {
  if (c.r < d.r) swap(c, d);
  auto A = [&](rl r, rl h) {
    return r*r*acos(h/r)-h*sqrt(r*r-h*h);
  };
  auto l = norm(c.p - d.p), a = (l*l + c.r*c.r - d.r*d.r)/(2*l);
  if (sign(l - c.r - d.r) >= 0) return 0; 

  if (sign(l - c.r + d.r) <= 0) return PI*d.r*d.r;
  if (sign(l - c.r) >= 0) return A(c.r, a) + A(d.r, l-a);
  else return A(c.r, a) + PI*d.r*d.r - A(d.r, a-l);
}








rl intersection_area(vector<point> ps, circle c) {
  auto tri = [&](point p, point q){
    point d = q - p;
    auto a = dot(d,p)/dot(d,d), b = (dot(p,p)-c.r*c.r)/dot(d,d);
    auto det = a*a - b;
    if (det <= 0) return arg(p,q) * c.r*c.r / 2;
    auto s = max(0.l, -a-sqrt(det)), t = min(1.l, -a+sqrt(det));
    if (t < 0 || 1 <= s) return c.r*c.r*arg(p,q)/2;
    point u = p + s*d, v = p + t*d;
    return arg(p,u)*c.r*c.r/2 + cross(u,v)/2 + arg(v,q)*c.r*c.r/2;
  };
  auto sum = 0.0;
  for (int i = 0; i < ps.size(); ++i)
    sum += tri(ps[i] - c.p, ps[(i+1)%ps.size()] - c.p);
  return sum;
}
rl intersection_area(circle c, vector<point> ps) {
  return intersection_area(ps, c);
}









pair<point,point> closest_pair(vector<point> ps) {
  sort(all(ps), [](point p, point q) { return p.y < q.y; });
  auto u = ps[0], v = ps[1];
  auto best = dot(u-v, u-v);
  auto update = [&](point p, point q) {
    auto dist = dot(p-q, p-q);
    if (best > dist) { best = dist; u = p; v = q; }
  };
  set<point> S; S.insert(u); S.insert(v);
  for (int l = 0, r = 2; r < ps.size(); ++r) {
    if (S.count(ps[r])) return {ps[r], ps[r]};
    if ((ps[l].y-ps[r].y)*(ps[l].y-ps[r].y) > best) S.erase(ps[l++]);
    auto i = S.insert(ps[r]).fst;
    for (auto j = i; ; ++j) {
      if (j == S.end() || (i->x-j->x)*(i->x-j->x) > best) break;
      if (i != j) update(*i, *j);
    }
    for (auto j = i; ; --j) {
      if (i != j) update(*i, *j);
      if (j == S.begin() || (i->x-j->x)*(i->x-j->x) > best) break;
    }
  }
  return {u, v};
}








pair<point,point> closest_pair2(vector<point> ps) {
  sort(all(ps), [](point p, point q) { return p.y < q.y; });
  auto u = ps[0], v = ps[1];
  auto best = dot(u-v, u-v);
  auto update = [&](point p, point q) {
    auto dist = dot(p-q, p-q);
    if (best > dist) { best = dist; u = p; v = q; }
  };
  function<void(int,int)> rec = [&](int l, int r) {
    if (r - l <= 1) {
      for (int i = l; i < r; ++i)
        for (int j = i+1; j < r; ++j)
          update(ps[i], ps[j]);
      stable_sort(&ps[l], &ps[r]);
    } else {
      int m = (l + r) / 2;
      auto y = ps[m].y;
      rec(l, m); rec(m, r);
      inplace_merge(&ps[l], &ps[m], &ps[r]);
      vector<point> qs;
      for (int i = l; i < r; ++i) {
        if ((ps[i].y-y)*(ps[i].y-y) >= best) continue;
        for (int j = (int)qs.size()-1; j >= 0; --j) {
          if ((qs[j].x-ps[i].x)*(qs[j].x-ps[i].x) >= best) break;
          update(qs[j], ps[i]);
        }
        qs.push_back(ps[i]);
      }
    }
  };
  rec(0, ps.size());
  return {u, v};
}










vector<point> half_plane_intersection(vector<line> ls) {
  int n = ls.size();
  sort(all(ls), [&](line l, line m) { return arg(l.p-l.q) < arg(m.p-m.q); });
  int L = 0, R = 0;
  vector<line> bd(2*n);
  vector<point> ps(2*n);
  bd[R] = ls[0];
  auto left = [&](point p, line l) { return sign(cross(l.p-p, l.q-p)) >= 0; };
  for (int i = 1; i < n; ++i) {
    if (!sign(cross(bd[R].p-bd[R].q, ls[i].p-ls[i].q))) {
      if (left(ls[i].p, bd[R])) bd[R] = ls[i];
    } else {
      while (L < R && !left(ps[R-1], ls[i])) --R;
      while (L < R && !left(ps[L]  , ls[i])) ++L;
      bd[++R] = ls[i];
    }
    if (R > L) ps[R-1] = intersect(bd[R-1], bd[R])[0];
  }
  while (L < R && !left(ps[R-1], bd[L])) --R;
  if (R - L <= 1) return {};
  if (R > L) ps[R] = intersect(bd[L], bd[R])[0];
  vector<point> ch = {ps[L]};
  for (int i = L+1; i <= R; ++i)
    if (!(ch.back() == ps[i])) ch.push_back(ps[i]);
  if (ch.size() > 1 && ch.back() == ch[0]) ch.pop_back();
  return ch;
}

















point geometric_median(vector<point> ps) {
  point g = {0,0};
  rl eta = 1000.0;
  for (int iter = 0; iter < 1000000; ++iter, eta /= 2) {
    rl w = 0;
    point h = {0,0};
    for (point p: ps) {
      rl a = eta + norm(p - g);
      h = h + p/a; w = w + 1/a;
    }
    h = h / w; swap(g, h);
    if (norm(g - h) < EPS) break;
  }
  return g;
}














int maximum_circle_cover(vector<point> ps, double r) {
  const double dx[] = {1,-1,-1,1}, dy[] = {1,1,-1,-1};
  point best_p;
  int best = 0;
  function<void(point,double,vector<point>)>
    rec = [&](point p, double w, vector<point> ps) {
    w /= 2;
    point qs[4];
    vector<point> pss[4];
    for (int i = 0; i < 4; ++i) {
      qs[i] = p + w * point({dx[i], dy[i]});
      int lo = 0;
      for (point q: ps) {
        auto d = dist(qs[i], q);
        if (sign(d - r) <= 0) ++lo;
        if (sign(d - w*sqrt(2) - r) <= 0) pss[i].push_back(q);
      }
      if (lo > best) { best = lo; best_p = qs[i]; }
    }
    for (int i = 0, j; i < 4; ++i) {
      for (int j = i+1; j < 4; ++j)
        if (pss[i].size() < pss[j].size())
          swap(pss[i], pss[j]), swap(qs[i], qs[j]);
      if (pss[i].size() <= best) break;
      rec(qs[i], w, pss[i]);
    }
  };
  rl w = 0;
  for (point p: ps) w = max(w, max(abs(p.x), abs(p.y)));
  rec({0,0}, w, ps);
  return best; 

}













int maximum_circle_cover2(vector<point> ps, double r) {
  int best = 0;
  for (point p: ps) {
    int count = 0;
    vector<pair<double,int>> aux;
    for (point q: ps) {
      auto d = dist(p, q);
      if (sign(d) == 0) ++count;
      else if (sign(d - 2*r) <= 0) {
        auto theta = arg(q-p);
        auto phi   = acos(min(1.l, d/(2*r)));
        aux.push_back({theta-phi, -1});
        aux.push_back({theta+phi, +1});
      }
    }
    sort(all(aux));
    best = max(best, count);
    for (auto a: aux)
      best = max(best, count -= a.snd);
  }
  return best;
}













struct rectangle { point p, q; }; 

rl rectangle_union(vector<rectangle> rs) {
  vector<rl> ys; 

  struct event {
    rl x, ymin, ymax;
    int add;
    bool operator<(event e) const { return x < e.x; }
  };
  vector<event> es;
  for (auto r: rs) {
    ys.push_back(r.p.y);
    ys.push_back(r.q.y);
    es.push_back({r.p.x, r.p.y, r.q.y, +1});
    es.push_back({r.q.x, r.p.y, r.q.y, -1});
  }
  sort(all(es));
  sort(all(ys));
  ys.erase(unique(all(ys)), ys.end());

  vector<rl> len(4 * ys.size()); 

  vector<int> sum(4 * ys.size());
  function<void(rl, rl, int, int,int,int)> update
    = [&](rl ymin, rl ymax, int add, int i, int j, int k) {
    ymin = max(ymin, ys[i]); ymax = min(ymax, ys[j]);
    if (ymin >= ymax) return;
    if (ys[i] == ymin && ys[j] == ymax) sum[k] += add;
    else {
      update(ymin, ymax, add, i, (i+j)/2, 2*k+1);
      update(ymin, ymax, add, (i+j)/2, j, 2*k+2);
    }
    if (sum[k]) len[k] = ys[j] - ys[i];
    else        len[k] = len[2*k+1] + len[2*k+2];
  };
  rl area = 0;
  for (int i = 0; i+1 < es.size(); ++i) {
    update(es[i].ymin, es[i].ymax, es[i].add, 0, ys.size()-1, 0);
    area += len[0] * (es[i+1].x - es[i].x);
  }
  return area;
}















struct points_counter {
  int n;
  vector<point> ps;
  vector<vector<int>> low; 

  points_counter(vector<point> ps_) : n(ps_.size()), ps(ps_), low(n, vector<int>(n)) {
    double sint = 1e-1, cost = sqrt(1 - sint*sint); 

    for (point &p: ps) p = {p.x*cost - p.y*sint, p.x*sint + p.y*cost};

    vector<int> is(n); iota(all(is), 0);
    sort(all(is), [&](int i, int j) { return ps[i] < ps[j]; });

    vector<int> left;
    vector<vector<int>> iss(n); 

    for (int o: is) {
      sort(all(left), [&](int j, int k) { 

        point u = ps[j] - ps[o], v = ps[k] - ps[o];
        int s = sign(cross(u, v));
        return s ? s < 0 : dot(u,u) > dot(v,v);
      });
      iss[o] = left;
      left.push_back(o);
    }
    for (int o: is) {
      cout << "processing " << ps[o] << endl;
      cout << iss[o].size() << endl;
      for (int i = 0; i+1 < iss[o].size(); ++i) {
        int a = iss[o][i], b = iss[o][i+1];
        cout << "  comparing " << ps[a] << " " << ps[b] << endl;
        if (ps[b] < ps[a]) low[b][o] = low[a][o] + low[a][b] + 1;
        else               low[b][o] = low[a][o] - low[a][b];
        low[o][b] = low[b][o];
      }
    }
    cout << low << endl;


    vector<vector<int>> low2(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
          if (k == i || k == j) continue;
          point p = ps[i], q = ps[j], r = ps[k];
          if (q < p) swap(p, q); 

          if (r.x < p.x || r.x >= q.x) continue;
          if (sign(cross(q-r, p-r)) > 0) low2[i][j]++;
        }
        low2[j][i] = low2[i][j];
      }
    }
    cout << low2 << endl;
  }
  int count(int a, int b, int o) { 

    if (ps[b] < ps[a]) swap(a, b);
    if (ps[o] < ps[b]) swap(b, o);
    if (ps[b] < ps[a]) swap(a, b);
    if (ps[b].y < ps[a].y) swap(a, b);
    cout << "comparing " << ps[a] << " " << ps[b] << " " << ps[o] << endl;
    cout << "values " << low[o][a] << " " << low[a][b] << " " << low[o][b] << endl;
    return low[o][a] + low[a][b] - low[o][b] + (ps[a].x > ps[b].x);
  }
};






















namespace arrangement_slow {
struct arrangement {
  struct edge {
    int src, dst;
    rl weight;
    size_t id, rev;
  };
  int n;
  vector<point> ps;
  map<point,int> id;
  vector<vector<edge>> adj;

  arrangement(vector<segment> ss) : n(0) {
    vector<vector<pair<rl, int>>> group(ss.size());
    auto append = [&](int i, point p) {
      if (!id.count(p)) { id[p] = n++; ps.push_back(p); }
      group[i].push_back({norm(ss[i].p - p), id[p]});
    };
    for (int i = 0; i < ss.size(); ++i) {
      append(i, ss[i].p); append(i, ss[i].q);
      for (int j = 0; j < i; ++j) {
        for (point p: intersect(ss[i], ss[j])) {
          append(i, p); append(j, p);
        }
      }
    }
    adj.resize(n);
    for (auto &vs: group) {
      sort(all(vs));
      for (int i = 0; i+1 < vs.size(); ++i) {
        auto u = vs[i].snd, v = vs[i+1].snd;
        if (u == v) continue;
        auto len = vs[i+1].fst - vs[i].fst;
        adj[u].push_back({u, v, len});
        adj[v].push_back({v, u, len});
      }
    }
    

    vector<unordered_map<int, int>> idx(n);
    for (int u = 0; u < n; ++u) {
      auto eq = [&](edge e, edge f) { return e.dst == f.dst; };
      auto lt = [&](edge e, edge f) { return e.dst <  f.dst; };
      sort(all(adj[u]), lt);
      adj[u].erase(unique(all(adj[u]), eq), adj[u].end());
      sort(all(adj[u]), [&](edge e, edge f) {
        return arg(ps[e.dst] - ps[e.src]) > arg(ps[f.dst] - ps[f.src]);
      });
      for (int i = 0; i < adj[u].size(); ++i) {
        adj[u][i].id = i;
        int v = adj[u][i].dst;
        idx[u][v] = i;
        if (idx[v].count(u)) {
          int j = idx[v][u];
          adj[u][i].rev = j;
          adj[v][j].rev = i;
        }
      }
    }
  }
  

  

  edge twin(edge e) const { return adj[e.dst][e.rev]; }
  edge next(edge e) const {
    int j = adj[e.dst][e.rev].id + 1;
    if (j >= adj[e.dst].size()) j = 0;
    return adj[e.dst][j];
  }
  edge outer() const {
    int s = 0; 

    for (int i = 1; i < n; ++i) if (ps[i] < ps[s]) s = i;
    for (int i = 0; i < adj[s].size(); ++i) {
      edge e1 = adj[s][i], e2 = adj[s][(i+1)%adj[s].size()];
      if (cross(ps[e1.dst]-ps[s], ps[e2.dst]-ps[s]) <= 0) return e1;
    }
  }

  

  void shortest_path(point sp) {
    int s = id[sp];
    vector<rl> dist(n, 1.0/0.0);
    vector<int> prev(n, -1);
    typedef pair<rl, int> node;
    priority_queue<node, vector<node>, greater<node>> Q;
    Q.push(node(dist[s] = 0, s));
    while (!Q.empty()) {
      node z = Q.top(); Q.pop();
      if (dist[z.snd] <= z.fst) {
        for (auto e: adj[z.snd]) {
          if (dist[e.dst] > dist[e.src] + e.weight) {
            dist[e.dst] = dist[e.src] + e.weight;
            prev[e.dst] = e.src;
            Q.push({dist[e.dst], e.dst});
          }
        }
      }
    }
    rl ans = 0;
    for (int u = 0; u < n; ++u) {
      for (edge e: adj[u]) {
        rl s = (dist[e.dst] - dist[e.src] + e.weight)/2;
        ans = max(ans, dist[e.src] + s);
      }
    }
    printf("%.12lf\n", ans);
  }

  

  template <class F>
  void traverse(edge e, F func) {
    edge s = e;
    do {
      func(e);
      e = next(e);
    } while (e.src != s.src || e.dst != s.dst);
  }
  void traverse_all_faces() {
    vector<unordered_set<int>> visited(n);
    rl ans = 0;
    for (int u = 0; u < n; ++u) {
      for (edge e: adj[u]) {
        if (!visited[e.src].count(e.dst)) {
          rl area = 0;
          traverse(e, [&](edge e) {
            visited[e.src].insert(e.dst);
            area += cross(ps[e.src], ps[e.dst]);
          });
          ans = max(ans, area);
        }
      }
    }
    printf("%.6f\n", ans/2);
  }
  void traverse_all_faces2() {
    vector<unordered_set<int>> visited(n);
    rl ans = 0;
    for (int u = 0; u < n; ++u) {
      for (edge e: adj[u]) {
        if (!visited[e.src].count(e.dst)) {
          rl area = 0;
          traverse(e, [&](edge e) {
            visited[e.src].insert(e.dst);
            area += cross(ps[e.src], ps[e.dst]);
          });
          if (area > 0) ans += area;
        }
      }
    }
    printf("%.12f\n", ans/2);
  }
  edge contains() {
    vector<unordered_set<int>> visited(n);
    auto contains = [&](edge e, point p) {
      edge s = e;
      bool in = false;
      do {
        point a = ps[e.src] - p, b = ps[e.dst] - p;
        if (a.y > b.y) swap(a, b);
        if (a.y <= 0 && 0 < b.y && cross(a, b) < 0) in = !in;
        if (!sign(cross(a, b)) && sign(dot(a, b)) <= 0)
          return 1; 

        visited[e.src].count(e.dst);
        e = next(e);
      } while (e.src != s.src || e.dst != s.dst);
      return in ? 2 : 0; 

    };
    for (int u = 0; u < n; ++u)
      for (edge e: adj[u])
        if (!visited[e.src].count(e.dst))
          if (contains(e, (point){0,0})) return e;
    return {-1};
  }
};

void AOJ0273() {
  for (int c, w; ~scanf("%d %d", &c, &w) && c; ) {
    vector<point> ps(c);
    for (int i = 0; i < c; ++i) {
      scanf("%lf %lf", &ps[i].x, &ps[i].y);
    }
    vector<segment> ss;
    for (int i = 0; i < w; ++i) {
      int u, v; scanf("%d %d", &u, &v);
      ss.push_back({ps[u-1], ps[v-1]});
    }
    arrangement arr(ss);
    typedef arrangement::edge edge;
    edge e = arr.outer(); 


    vector<unordered_map<int,int>> step(arr.n);
    queue<edge> que;
    auto proceed = [&](edge s, int value) {
      if (step[s.src].count(s.dst)) return;
      edge e = s;
      do {
        step[e.src][e.dst] = value;
        que.push(arr.twin(e));
        e = arr.next(e);
      } while (e.src != s.src || e.dst != s.dst);
    };
    proceed(e, 0);
    int ans = 0;
    while (!que.empty()) {
      edge e = que.front(); que.pop();
      ans = step[e.dst][e.src];
      proceed(e, ans + 1);
    }
    printf("%d\n", ans);
  }
}



void AOJ1226() {
  for (int n; ~scanf("%d", &n) && n; ) {
    vector<vector<double>> a(4, vector<double>(n));
    for (int k = 0; k < 4; ++k)
      for (int i = 0; i < n; ++i)
        scanf("%lf", &a[k][i]);

    vector<segment> ss = {
      {{0,0},{0,1}},
      {{0,1},{1,1}},
      {{1,1},{1,0}},
      {{1,0},{0,0}}
    };
    for (int i = 0; i < n; ++i) {
      ss.push_back({{a[0][i],0},{a[1][i],1}});
      ss.push_back({{0,a[2][i]},{1,a[3][i]}});
    }
    arrangement arr(ss);
    arr.traverse_all_faces();
  }
}

void AOJ2448() {
  int n; scanf("%d", &n);
  vector<point> ps(n);
  for (int i = 0; i < n; ++i)
    scanf("%lf %lf", &ps[i].x, &ps[i].y);
  vector<segment> ss;
  for (int i = 0; i+1 < n; ++i)
    ss.push_back({ps[i], ps[i+1]});
  arrangement arr(ss);
  arr.traverse_all_faces2();
}

void AOJ1247() {
  for (int n; ~scanf("%d", &n) && n; ) {
    vector<segment> ss;
    for (int i = 0; i < n; ++i) {
      double x1, y1, x2, y2;
      scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
      ss.push_back({{x1,y1},{x2,y2}});
    }
    arrangement arr(ss);
    if (arr.contains().src >= 0) printf("yes\n");
    else                         printf("no\n");
  }
}
}
















struct arrangement {
  struct Vertex; struct Edge; 

  struct Vertex {
    point p;    

    Edge *edge; 

  };
  struct Edge {
    Vertex *vertex;    

    Edge *twin;        

    Edge *prev, *next; 

  };
  map<Vertex*, map<Vertex*, Edge*>> adj;
  vector<Vertex*> vertices;
  vector<Edge*> edges;

  vector<segment> segs;

  struct node { 

    int index;
    int size = 1;
    node *left = 0, *right = 0;
  } *root = 0;
  vector<node> ns;

  node *update(node *x) {
    if (x) {
      x->size = 1;
      if (x->left)  x->size += x->left->size;
      if (x->right) x->size += x->right->size;
    }
    return x;
  }
  node *merge(node *x, node *y) {
    if (!x) return y;
    if (!y) return x;
    if (rand() % (x->size + y->size) < x->size) {
      x->right = merge(x->right, y);
      return update(x);
    } else {
      y->left = merge(x, y->left);
      return update(y);
    }
  }
  template <class C> 

  tuple<node*, node*, node*> split(node *x, C cond) {
    if (!x) return make_tuple(x,x,x);
    if (cond(x) == 0) {
      auto a = split(x->left, cond);
      auto b = split(x->right, cond);
      x->left = x->right = 0; update(x);
      get<1>(a) = merge(merge(get<1>(a), x), get<1>(b));
      get<2>(a) = get<2>(b);
      return a;
    }
    if (cond(x) < 0) {
      auto a = split(x->right, cond);
      x->right = 0; update(x);
      get<0>(a) = merge(x, get<0>(a));
      return a;
    }
    if (cond(x) > 0) {
      auto a = split(x->left, cond);
      x->left = 0; update(x);
      get<2>(a) = merge(get<2>(a), x);
      return a;
    }
  }
  node *leftmost(node *x) { while (x && x->left) x = x->left; return x; }
  node *rightmost(node *x) { while (x && x->right) x = x->right; return x; }
  template <class F>
  void process(node *x, F func) {
    if (!x) return;
    process(x->left, func);
    func(x);
    process(x->right, func);
  }

  arrangement(vector<segment> segs_) : segs(segs_) {
    ns.resize(segs.size());

    set<point> events;
    map<point, set<int>> L, R;
    for (int i = 0; i < segs.size(); ++i) {
      if (segs[i].q < segs[i].p) swap(segs[i].p, segs[i].q);
      events.insert(segs[i].p);
      events.insert(segs[i].q);
      L[segs[i].p].insert(i);
      R[segs[i].q].insert(i);
      ns[i].index = i;
    }
    vector<Vertex*> last(segs.size());

    while (!events.empty()) {
      const point p = *events.begin();
      events.erase(events.begin());

      Vertex *u = new Vertex({p});
      vertices.push_back(u);

      auto cond = [&](node *x) {
        const segment &s = segs[x->index];
        if (sign(s.q.x - s.p.x) == 0) {
          if (sign(p.y - s.p.y) < 0) return -1;
          if (sign(s.q.y - p.y) < 0) return +1;
          return 0;
        }
        return -sign(cross(s.p - p, s.q - p));
      };
      auto z = split(root, cond);
      vector<node*> inserter;
      process(get<1>(z), [&](node *x) {
        Vertex *v = last[x->index];
        if (!adj[u][v]) {
          adj[u][v] = new Edge({u});
          adj[v][u] = new Edge({v});
          adj[u][v]->twin = adj[v][u];
          adj[v][u]->twin = adj[u][v];
          edges.push_back(adj[u][v]);
          edges.push_back(adj[v][u]);
        }
        if (!R[p].count(x->index))
          inserter.push_back(x);
      });
      for (int i: L[p])
        if (!R[p].count(i))
          inserter.push_back(&ns[i]);

      sort(all(inserter), [&](node *x, node *y) {
        const segment &s = segs[x->index], &t = segs[y->index];
        return sign(cross(s.q - s.p, t.q - t.p)) >= 0;
      });
      auto add_event = [&](node *x, node *y) {
        if (!x || !y) return;
        vector<point> ps = intersect(segs[x->index], segs[y->index]);
        for (point q: ps)
          if (p < q) events.insert(q);
      };
      if (inserter.empty()) {
        add_event(rightmost(get<0>(z)), leftmost(get<2>(z)));
      } else {
        add_event(rightmost(get<0>(z)), inserter[0]);
        add_event(leftmost(get<2>(z)), inserter.back());
      }
      root = 0;
      for (int i = 0; i < inserter.size(); ++i) {
        last[inserter[i]->index] = u;
        inserter[i]->left = inserter[i]->right = 0;
        root = merge(root, update(inserter[i]));
      }
      root = merge(merge(get<0>(z), root), get<2>(z));
    }
    for (auto &pp: adj) {
      Vertex *u = pp.fst;
      vector<Edge*> es;
      for (auto z: pp.snd) es.push_back(z.snd);
      sort(all(es), [&](Edge *e, Edge *f) {
        auto quad = [](point p) {
          for (int i = 1; i <= 4; ++i, swap(p.x = -p.x, p.y))
            if (p.x > 0 && p.y >= 0) return i;
          return 0;
        };
        const point p = e->twin->vertex->p - e->vertex->p;
        const point q = f->twin->vertex->p - f->vertex->p;
        if (quad(p) != quad(q)) return quad(p) < quad(q);
        return sign(cross(p, q)) > 0;
      });
      u->edge = es.back();
      for (Edge *e: es) {
        u->edge->next = e;
        u->edge->next->prev = u->edge;
        u->edge = u->edge->next;
      }
    }
  }
};
void AOJ1226() {
  for (int n; ~scanf("%d", &n) && n; ) {
    

    vector<vector<double>> a(4, vector<double>(n));
    for (int k = 0; k < 4; ++k)
      for (int i = 0; i < n; ++i)
        scanf("%lf", &a[k][i]);

    vector<segment> ss = {
      {{0,0},{0,1}},
      {{0,1},{1,1}},
      {{1,1},{1,0}},
      {{1,0},{0,0}}
    };
    for (int i = 0; i < n; ++i) {
      ss.push_back({{a[0][i],0},{a[1][i],1}});
      ss.push_back({{0,a[2][i]},{1,a[3][i]}});
    }
    arrangement arr(ss);

    double result = 0;
    set<arrangement::Edge*> seen;
    for (auto *e: arr.edges) {
      if (seen.count(e)) continue;
      auto *f = e;
      double area = 0;
      do {
        seen.insert(f);
        area += cross(f->vertex->p, f->twin->vertex->p);
        f = f->twin->prev;
      } while (f != e);
      result = max(result, area);
    }
    printf("%.6f\n", result/2);
  }
}
void AOJ2448() {
  int n; scanf("%d", &n);
  vector<point> ps(n);
  for (int i = 0; i < n; ++i)
    scanf("%lf %lf", &ps[i].x, &ps[i].y);
  vector<segment> ss;
  for (int i = 0; i+1 < n; ++i)
    ss.push_back({ps[i], ps[i+1]});
  arrangement arr(ss);

  double result = 0;
  set<arrangement::Edge*> seen;
  for (auto *e: arr.edges) {
    if (seen.count(e)) continue;
    auto *f = e;
    double area = 0;
    do {
      seen.insert(f);
      area += cross(f->vertex->p, f->twin->vertex->p);
      f = f->twin->prev;
    } while (f != e);
    if (area > 0) result += area;
  }
  printf("%.12f\n", result/2);
}
























struct visibility_graph {
  struct edge {
    int src, dst;
    rl weight;
  };
  int n;
  vector<point> ps;
  vector<vector<edge>> adj;
  visibility_graph(vector<point> ps, vector<polygon> os) :
    n(ps.size()), ps(ps), adj(n) {
    auto blocked = [&](point s, point t, polygon &obs) {
      bool in = false, on = false;
      point m = (s + t) / 2;
      for (int i = 0; i < obs.size(); ++i) {
        int j = (i+1 == obs.size() ? 0 : i+1);
        point a = obs[i], b = obs[j];
        if (!sign(cross(a-s,b-s)) && sign(dot(a-s,b-s)) <= 0 && 

            !sign(cross(a-t,b-t)) && sign(dot(a-t,b-t)) <= 0) return false;
        if (!sign(cross(s-a,t-a)) && sign(dot(s-a,t-a)) < 0) return false; 

        if (sign(cross(a-s,b-s))*sign(cross(a-t,b-t)) < 0 && 

            sign(cross(s-a,t-a))*sign(cross(s-b,t-b)) < 0) return true;
        if (b.y < a.y) swap(a, b); 

        if (a.y <= m.y && m.y < b.y)
          if (sign(cross(a-m, b-m)) < 0) in = !in;
      }
      return in; 

    };
    for (int i = 0; i < ps.size(); ++i) {
      for (int j = i+1, k; j < ps.size(); ++j) {
        for (k = 0; k < os.size(); ++k)
          if (blocked(ps[i], ps[j], os[k])) break;
        if (k == os.size()) {
          auto len = norm(ps[i] - ps[j]);
          adj[i].push_back({i, j, len});
          adj[j].push_back({j, i, len});
        }
      }
    }
  }
};




































struct geometric_shortest_path {
  vector<point> ps;
  vector<int> prev, next;
  vector<vector<int>> region;
  vector<rl> weight;
  void add_region(vector<point> poly, rl w = 1.0/0.0) {
    int n = ps.size(), k = poly.size();
    vector<int> obj;
    for (int i = 0; i < k; ++i) {
      ps.push_back(poly[i]);
      obj.push_back(n+i);
      next.push_back(n+i+1);
      prev.push_back(n+i-1);
    }
    next[n+k-1] = n;
    prev[n] = n+k-1;
    region.push_back(obj);
    weight.push_back(w);
  }
  void refine(int v) {
    auto divide = [&](int u, int w) {
      int v = ps.size();
      ps.push_back((ps[u] + ps[w])/2);
      prev.push_back(u);
      next.push_back(w);
      prev[next[v]] = v;
      next[prev[v]] = v;
    };
    divide(prev[v], v);
    divide(v, next[v]);
  }
  enum { INTERSECT, CONTAINED, ONLINE, VISIBLE };
  int visibility(point s, point t, vector<int> &reg) {
    bool in = false;
    point m = (s + t) / 2;
    for (int i = 0; i < reg.size(); ++i) {
      point a = ps[reg[i]], b = ps[reg[(i+1)%reg.size()]];
      if (!sign(cross(a-s,b-s)) && sign(dot(a-s,b-s)) <= 0 && 

          !sign(cross(a-t,b-t)) && sign(dot(a-t,b-t)) <= 0) return ONLINE;
      if (sign(cross(a-s,b-s))*sign(cross(a-t,b-t)) < 0 && 

          sign(cross(s-a,t-a))*sign(cross(s-b,t-b)) < 0) return INTERSECT;
      if (b.y < a.y) swap(a, b);
      if (a.y <= m.y && m.y < b.y && sign(cross(a-m, b-m)) < 0) in = !in;
    }
    return in ? CONTAINED : VISIBLE;
  }
  rl length(int u, int v) {
    point s = ps[u], t = ps[v];
    auto len = norm(s - t);
    for (int i = 0; i < region.size(); ++i) {
      int a = visibility(s, t, region[i]);
      if (a == ONLINE) return len;
      if (a == CONTAINED) return weight[i] * len;
      if (a == INTERSECT) return 1.0 / 0.0;
    }
    return len;
  }
  pair<rl, vector<int>> shortest_path(point p, point q) {
    ps.push_back(p); ps.push_back(q);
    int n = ps.size(), s = n-2, t = n-1;
    vector<rl> dist(n, 1.0/0.0), h(n); dist[s] = 0;
    for (int u = 0; u < n; ++u) h[u] = norm(ps[u]-ps[t]); 

    vector<int> last(n, ~s); 

    while (last[t] < 0) {
      int u = t;
      for (int v = 0; v < n; ++v)
        if (last[v] < 0 && dist[v] + h[v] < dist[u] + h[u]) u = v;
      last[u] = ~last[u];
      for (int v = 0; v < n; ++v) {
        if (last[v] >= 0) continue;
        auto len = dist[u] + length(u, v);
        if (sign(dist[v] - len) > 0) {
          dist[v] = len;
          last[v] = ~u;
        }
      }
    }
    auto cost = dist[t];
    vector<int> path;
    if (cost < 1.0 / 0.0) {
      while (t != s) {
        path.push_back(t);
        t = last[t];
      }
      path.push_back(s);
    }
    ps.pop_back(); ps.pop_back();
    return {cost, path};
  }
};









vector<segment> merge_segments(vector<segment> ss) {
  auto compare = [&](segment s, segment t) {
    int a = sign(cross(s.q-s.p, t.p-t.q));
    return a ? a < 0 : sign(cross(t.p-s.p, t.q-s.p)) < 0;
  };
  for (segment &s: ss) if (s.q < s.p) swap(s.p, s.q);
  sort(all(ss), compare);
  vector<segment> res;
  for (int i = 0, j; i < ss.size(); i = j) {
    for (j = i+1; j < ss.size(); ++j)
      if (compare(ss[i], ss[j])) break;
    point o = ss[i].p, v = ss[i].q - ss[i].p;
    sort(ss.begin()+i, ss.begin()+j, [&](segment s, segment &t) {
      auto a = dot(s.p - t.p, v);
      if (a) return a < 0;
      return dot(s.q - t.q, v) < 0;
    });
    for (int a = i, b; a < j; a = b) {
      for (b = a+1; b < j; ++b) {
        if (sign(dot(ss[a].q - ss[b].p, v)) < 0) break;
        if (dot(ss[a].q - ss[b].q, v) < 0) ss[a].q = ss[b].q;
      }
      res.push_back(ss[a]);
    }
  }
  return res;
}




#define PI acos(-1)



point getInnerPointWithRatio(point a , point b , int m , int n)
{
    return point((n*a.x + m*b.x) / (n + m) , (n*a.y + m*b.y) / (n + m));
}


point getExternalPointWithRatio(point a , point b , int m , int n)
{
    return point((n*a.x - m*b.x) / (n - m) , (n*a.y - m*b.y) / (n - m));
}

circle c[3];
int main()
{
    for(int i = 0 ; i < 3 ; i++)
        cin >> c[i].p.x >> c[i].p.y >> c[i].r;

    vector < circle > v;
    vector < line > v2;
    for(int i = 0 ; i < 2 ; i++)
    {
        if(c[i].r == c[i+1].r)
        {
            point vec(c[i].p.y - c[i+1].p.y , c[i+1].p.x - c[i].p.x);
            point mid = (c[i].p + c[i+1].p) / 2;

            v2.push_back(line(mid , mid + vec));
        }
        else
        {
            point p1 = getInnerPointWithRatio(c[i].p , c[i+1].p , c[i].r , c[i+1].r);
            point p2 = getExternalPointWithRatio(c[i].p , c[i+1].p , c[i].r , c[i+1].r);

            v.push_back(circle((p1 + p2) / 2 , norm(p1 - p2) / 2));
        }
    }

    vector < point > intr;
    if(v.size() == 2)       intr = intersect(v[0] , v[1]);
    else if(v.size() == 1)  intr = intersect(v[0] , v2[0]);
    else                    intr = intersect(v2[0] , v2[1]);

    if(!intr.empty())
    {
        point ans = intr[0];
        for(auto in : intr)
            if(norm2(in - c[0].p) < norm2(ans - c[0].p))
                ans = in;

        cout << fixed << setprecision(5) << ans.x << ' ' << fixed << setprecision(5) << ans.y << endl;
    }
    return 0;
}
