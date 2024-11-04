

#include <bits/stdc++.h>
using namespace std;

typedef int LL;

namespace MG{
  const float PI_F = acosf(-1);
  const double PI = acos(-1);
  const long double PI_L = acosl(-1);
  const double eps = 1e-7;

  template <typename T>
  class VECTOR{
  public:
    T x, y;
    VECTOR( T _x = 0, T _y = 0 ) : x(_x), y(_y) { }

    inline VECTOR operator + ( const VECTOR &p ) const { return VECTOR(x + p.x, y + p.y); }
    inline VECTOR operator - ( const VECTOR &p ) const { return VECTOR(x - p.x, y - p.y); }
    inline VECTOR operator * ( const T k ) const { return VECTOR(x * k, y * k); }
    inline VECTOR operator - () const { return VECTOR(-x, -y);}
    inline bool operator < ( const VECTOR &p ) const { return (x < p.x || (x == p.x && y < p.y)); }
    inline bool operator == ( const VECTOR &p ) const { return (x == p.x && y == p.y); }
    inline bool operator != ( const VECTOR &p ) const { return (x != p.x || y != p.y); }
    inline bool operator > ( const VECTOR &p ) const { return (x > p.x || (x == p.x && y > p.y)); }

    inline T norm2() const { return (x * x + y * y); }
    inline double norm() const { return sqrt(norm2()); }
    inline double ang() const { return atan2((double)y, (double)x); } 

    inline VECTOR normalize() const {return VECTOR( x / norm(), y / norm()); }
    inline T dist2(VECTOR<T> C) const { return ((x - C.x) * (x - C.x) + (y - C.y) * (y - C.y)); }
    inline double dist(VECTOR<T> C) const { return sqrt(dist2(C)); }
    inline int quadrant() const{
      if(x > 0 && y >= 0) return 1;
      if(x <= 0 && y > 0) return 2;
      if(x < 0 && y <= 0) return 3;
      if(x >= 0 && y < 0) return 4;
      return 4;
    }

    static inline bool angularCompare(const VECTOR<T> &A, const VECTOR<T> &B){
      

      if(A.quadrant() != B.quadrant()) return (A.quadrant() % 4 < B.quadrant() % 4);
      T c = cross(A, B);
      if(fabs(c) > eps){
        return (c > 0);
      } else{
        return (A.x * A.x + A.y * A.y < B.x * B.x + B.y * B.y);
      }
    }


    inline VECTOR translate(VECTOR norig) { return *this - norig;}
    

    inline VECTOR rotate(double angle) { angle *= PI / 180; return VECTOR(x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle));}
  };
  template<typename T>
  inline T dot(const VECTOR<T> &p, const VECTOR<T> &q){ return (q.x * p.x + q.y * p.y); }
  template<typename T>
  inline T cross(const VECTOR<T> &p, const VECTOR<T> &q){ return (p.x * q.y - q.x * p.y); }
  template<typename T>
  inline T ccw(const VECTOR<T> &p, const VECTOR<T> &q, const VECTOR<T> &r){
    return cross(q - p, r - p);
  }
  template <typename T>
  ostream& operator<<(ostream& os, VECTOR<T> &pt){ os << pt.x << " " << pt.y; return os;}
  template <typename T>
  istream& operator>>(istream& is, VECTOR<T> &pt){ is >> pt.x >> pt.y; return is;}


  template<typename T>
  class LINEVECTOR{
  public:
    VECTOR<T> s, e, v;
    pair<bool, bool> ends; 

    LINEVECTOR(T a, T b, T c, pair<bool, bool> _ends = make_pair(false, false)) :ends(_ends){
      if(a == 0){
        s = VECTOR<T> (0, -(c / (1.0 * b)));
        e = VECTOR<T> (1, -(c / (1.0 * b)));
      } else if(b == 0){
        s = VECTOR<T> (-(c / (1.0 * a)), 0);
        e = VECTOR<T> (-(c / (1.0 * a)), 1);
      } else {
        s = VECTOR<T> (0, -(c / (1.0 * b)));
        e = VECTOR<T> (1, -((c + a) / (1.0 * b)));
      }
      v = e - s;
    }
    LINEVECTOR(VECTOR<T> P = VECTOR<T> (), VECTOR<T> Q = VECTOR<T> (), pair<bool, bool> _ends = make_pair(false, false)) : s(P), e(Q), v(Q - P), ends(_ends) {}
    inline bool isPerp(LINEVECTOR<T> L){
      return (v.dot(L.v) == 0);
    }
    inline double lineToPointDis(VECTOR<T> P){
      if(ends.first && dot(P - s, e - s) < 0){
          return s.dist(P);
      } else if(ends.second && dot(P - e, s - e) < 0){
          return fabs(e.dist(P));
      } else {
        return fabs(cross(v, P - s) / v.norm());
      }
    }
    inline double inrange(double t){
      bool ans = true;
      if(ends.first) ans &= (t >= 0);
      if(ends.second) ans &= (t <= 1);
      return ans;
    }
    inline bool online(VECTOR<T> C){
      if(fabs(cross(C - s, e - s)) > eps) return false;
      if(ends.first){
        if(!( (s.x <= e.x && s.x <= C.x) || (s.x >= e.x && s.x >= C.x) )) return false;
        if(!( (s.y <= e.y && s.y <= C.y) || (s.y >= e.y && s.y >= C.y) )) return false;
      }
      if(ends.second){
        if(!( (e.x <= s.x && e.x <= C.x) || (e.x >= s.x && e.x >= C.x) )) return false;
        if(!( (e.y <= s.y && e.y <= C.y) || (e.y >= s.y && e.y >= C.y) )) return false;
      }
      return true;
    }
    inline double lineTolineDis(LINEVECTOR<T> L2){
      

      T a, b, c, d, e;
      a = dot(this -> v, this -> v);
      b = dot(L2.v, this -> v);
      c = dot(L2.v, L2.v);
      d = dot(this -> v, this -> s - L2.s);
      e = dot(L2.v, this -> s - L2.s);
      if(a * c == b * b) return min(this -> lineToPointDis(L2.s), L2.lineToPointDis(this -> s)); 

      else {
        double ans = this -> s.dist(L2.s);
        ans = min(ans, this -> s.dist(L2.e));
        ans = min(ans, this -> e.dist(L2.s));
        ans = min(ans, this -> e.dist(L2.e));
        double sc = (b * e - c * d) / (a * c - b * b);
        double tc = (a * e - b * d) / (a * c - b * b);
        if(this -> inrange(sc) && L2.inrange(tc)){
          ans = min(ans, (this -> s + (this -> v) * sc).dist(L2.s + L2.v * tc));
        }
        sc = 0;tc = (e + sc * b) / c;
        if(this -> inrange(sc) && L2.inrange(tc)){
          ans = min(ans, (this -> s + (this -> v) * sc).dist(L2.s + L2.v * tc));
        }
        sc = 1;tc = (e + sc * b) / c;
        if(this -> inrange(sc) && L2.inrange(tc)){
          ans = min(ans, (this -> s + (this -> v) * sc).dist(L2.s + L2.v * tc));
        }
        tc = 0;sc = -(d - tc * b) / a;
        if(this -> inrange(sc) && L2.inrange(tc)){
          ans = min(ans, (this -> s + (this -> v) * sc).dist(L2.s + L2.v * tc));
        }
        tc = 1;sc = -(d - tc * b) / a;
        if(this -> inrange(sc) && L2.inrange(tc)){
          ans = min(ans, (this -> s + (this -> v) * sc).dist(L2.s + L2.v * tc));
        }
        return ans;
      }
    }
    inline pair<bool, VECTOR<T> > intersection(LINEVECTOR<T> L2){
      

      T a, b, c, d, e;
      a = dot(this -> v, this -> v);
      b = dot(L2.v, this -> v);
      c = dot(L2.v, L2.v);
      d = dot(this -> v, this -> s - L2.s);
      e = dot(L2.v, this -> s - L2.s);
      if(a * c == b * b) return make_pair(false, VECTOR<T> ()); 

      else {
        double sc = (b * e - c * d) / (a * c - b * b);
        double tc = (a * e - b * d) / (a * c - b * b);
        if(this -> inrange(sc) && L2.inrange(tc)){
          return make_pair(true, this -> s + (this -> v) * sc);
        } else return make_pair(false, VECTOR<T> ());
      }
    }
  };

  template<typename T>
  class LINE
  {
  public:
    T a, b, c;
    LINE(T a = 0, T b = 0, T c = 0) :a(a), b(b), c(c){}
    LINE(const VECTOR<T> &p, const VECTOR<T> &q){ 

      a = (q - p).y;
      b = - ((q - p).x);
      c = -cross(p, q);
    };
    LINE(const VECTOR<T> &q){
      a = q.y;
      b = -(q.x);
      c = 0;
    };

    inline LINE<T> perpendicular(VECTOR<T> C = VECTOR<T> ()){
      return LINE<T> (this -> b, -this -> a, -(this -> b * C.x - this -> a * C.y));
    }
    inline bool parallel(LINE<T> L2){
      return (this -> a * L2.b == this -> b * L2.a);
    }
    inline bool intercepting(LINE<T> L2){
      return (parallel(L2) && (this -> c * L2.a == this -> a * L2.c));
    }
    inline pair<bool, VECTOR<T> > intersection(LINE<T> L2){
      if(parallel(L2)) return make_pair(false, VECTOR<T> ());
      VECTOR<T> ans;
      ans.x = -((this -> a * L2.c - L2.a * this -> c) / (this -> a * L2.b - L2.a * this -> b));
      ans.y = -((this -> b * L2.c - L2.b * this -> c) / (this -> b * L2.b - L2.b * this -> b));
    }
    inline VECTOR<T> foot(VECTOR<T> C){
      return intersection(perpendicular(C)).second;
    }
    inline double lineToPointDis(VECTOR<T> C){
      return fabs((a * C.x + b * C.y + c) / sqrt(a * a + b * b));
    }
  };


  template<typename T>
  class POLY{
  public:
    vector<VECTOR<T> > v;
    POLY(int N = 0){
      v.resize(N);
    }
    pair<T, bool> darea(){
      T ans = 0;
      for(int i = 0;i < v.size();++i){
        int t1 = i, t2 = ((i + 1) == (int)v.size()?0:i + 1);
        ans += cross(v[t1], v[t2]);
      }
      return make_pair(abs(ans), ans < 0);
    }
    POLY<T> ccwOrder(){
      POLY<T> ans = *this;
      VECTOR<T> lb = ans.v[0];
      for(int i = 0;i < (int)ans.v.size();++i){
        lb = min(lb, ans.v[i]);
      }
      for(int i = 0;i < (int)ans.v.size();++i){
        ans.v[i] = ans.v[i].translate(lb);
      }
      sort(ans.v.begin(), ans.v.end(), VECTOR<T>::angularCompare);
      for(int i = 0;i < (int)ans.v.size();++i){
        ans.v[i] = ans.v[i].translate(-lb);
      }
      return ans;
    }
    POLY<T> getConvexHull(){
      POLY<T> cHull;
      POLY<T> ordered = ccwOrder();
      int len = 0;
      for(int i = 0;i < (int)ordered.v.size();++i){
        while(len >= 2 && ccw(cHull.v[len - 2], cHull.v[len - 1], ordered.v[i]) <= 0){
          cHull.v.pop_back();
          --len;
        }
        cHull.v.push_back(ordered.v[i]);
        ++len;
      }
      while(len >= 2 && ccw(cHull.v[len - 2], cHull.v[len - 1], cHull.v[0]) <= 0){
        cHull.v.pop_back();
        --len;
      }
      return cHull;
    }

    int position(VECTOR<T> P){
      

      return 0; 

    }
  };
};
using namespace MG;
typedef VECTOR<LL> POINT_L;
typedef VECTOR<double> POINT_D;
typedef POINT_L POINT;
bool isParallelogram(POLY<LL> P){
  if(P.v.size() != 4) return false;
  POLY<LL> Q = P.ccwOrder();
  POINT a = POINT(Q.v[0].x + Q.v[2].x, Q.v[0].y + Q.v[2].y);
  POINT b = POINT(Q.v[1].x + Q.v[3].x, Q.v[1].y + Q.v[3].y);
  return (a == b);
}
bool isRec(POLY<LL> P){
  if(P.v.size() != 4) return false;
  POLY<LL> Q = P.ccwOrder();
  POINT a = POINT(Q.v[0].x + Q.v[2].x, Q.v[0].y + Q.v[2].y);
  POINT b = POINT(Q.v[1].x + Q.v[3].x, Q.v[1].y + Q.v[3].y);
  if(a != b) return false;
  return (dot(Q.v[1] - Q.v[0], Q.v[2] - Q.v[1]) == 0);
}
bool isSquare(POLY<LL> P){
  if(P.v.size() != 4) return false;
  POLY<LL> Q = P.ccwOrder();
  POINT a = POINT(Q.v[0].x + Q.v[2].x, Q.v[0].y + Q.v[2].y);
  POINT b = POINT(Q.v[1].x + Q.v[3].x, Q.v[1].y + Q.v[3].y);
  if(a != b) return false;
  if(dot(Q.v[1] - Q.v[0], Q.v[2] - Q.v[1]) != 0) return false;
  return ((Q.v[1] - Q.v[0]).norm2() == (Q.v[2] - Q.v[1]).norm2());
}

int main(){
  int N; scanf("%d", &N);
  vector<POINT> p(N);
  for(int i = 0;i < N;++i){
    scanf("%d%d", &p[i].x, &p[i].y);
  }
  LL ans = 0;
  for(int i = 0;i < N;++i){
    for(int j = i + 1;j < N;++j){
      LL l = 0, r = 0;
      for(int k = 0;k < N;++k){
        l = max(l, ccw(p[i], p[j], p[k]));
        r = max(r, -ccw(p[i], p[j], p[k]));
      }
      if(l > 0 && r > 0)
        ans = max(ans, l + r);
    }
  }
  printf("%.6lf\n", ans / 2.0);
	return 0;
}