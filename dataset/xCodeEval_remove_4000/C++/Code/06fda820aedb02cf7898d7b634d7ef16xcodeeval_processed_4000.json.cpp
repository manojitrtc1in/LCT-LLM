






using namespace std;

const double eps = 1e-7;
const double pi = acos(-1.0);
const double INF = 1e20;


inline int sign(double d) {
  return d < -eps ? -1 : d > eps;
}

inline double sqr(double x) {
  return x * x;
}

struct Point {
  double x, y;
  int xx, yy;
  Point() { x = 0.0; y = 0.0; }
  Point(double nx, double ny) : x(nx), y(ny) {}
  Point turnLeft() const {
    return Point(-y, x);
  }
  Point turnRight() const {
    return Point(y, -x);
  } 
  Point rotate(double ang) const {
    return Point(x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang));
  }

  inline double length() {
    return sqrt(x * x + y * y);
  }

  void normalize() {
    double r = length();
    if (sign(r) != 0)
      x /= r,y /= r;
  }

  bool operator < (const Point & other) const {
    return y < other.y || y == other.y == 0 && x < other.x;
  }

  bool operator == (const Point & other) const {
    return x == other.x && y == other.y;
  }

  
  inline bool equal(const Point & other) const {
    return sign(x - other.x) == 0 && sign(y - other.y) == 0;
  }

  friend ostream & operator << (ostream & out , const Point & point)
  {
    out << "(" << point.x << "," << point.y << ")";
    return out;
  }

};

inline Point operator + (const Point & a, const Point & b) {
  return Point(a.x + b.x, a.y + b.y);
}

inline Point operator - (const Point & a , const Point & b) {
  return Point(a.x - b.x, a.y - b.y);
}

inline Point operator * (const Point & a , double d) {
  return Point(a.x * d, a.y * d);
}

inline Point operator / (const Point & a , double d) {
  if (sign(d) == 0) return Point();
  return Point(a.x / d, a.y / d);
}

inline bool operator == (const Point & a , const Point & b) {
  return a.x == b.x && a.y == b.y;
}

inline bool operator != (const Point & a , const Point & b) {
  return a.x != b.x || a.y != b.y;
}

inline double dist(const Point & a , const Point & b) {
  return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

inline double id1(const Point & a , const Point & b)
{
  return sqr(a.x - b.x) + sqr(a.y - b.y);
}


inline double operator ^ (const Point & a , const Point & b) {
  return a.x * b.y - a.y * b.x;
}

inline double cross(const Point & p , const Point & a , const Point & b) {
  return (a - p) ^ (b - p);
}


inline double operator * (const Point & a , const Point & b) {
  return a.x * b.x + a.y * b.y;
}

inline double dot(const Point & p , const Point & a , const Point & b) {
  return (a - p) * (b - p);
}


inline bool onSeg(const Point & p , const Point & a , const Point & b) {
  return ( sign(cross(p, a, b)) == 0 && sign(dot(p, a, b)) <= 0) ;
}


inline bool onRay(const Point & p , const Point & a , const Point & b) {
  return ( sign(cross(p, a, b)) == 0 && sign(dot(a, p, b)) >= 0) ;
}


inline bool onLine(const Point & p , const Point & a , const Point & b) {
  return sign(cross(p,a,b))==0;
}


vector<Point> interLine(const Point & a , const Point & b , const Point & c , const Point & d) 
{
  vector<Point> inters;
  double u = cross(a, c, b), v = cross(a, b, d);
  if (sign(u + v) == 0) return inters;
  Point p = (c * v + d * u) / (u + v);
  inters.push_back(p);
  return inters;
}


vector<Point> interSeg(const Point & a , const Point & b , const Point & c , const Point & d)
{
  vector<Point> inters = interLine(a, b, c, d);
  if (inters.size() == 0) return inters;
  const Point & p = inters[0];
  if (onSeg(p, a, b) && onSeg(p, c, d)) 
    return inters;
  else {
    inters.clear();
    return inters;
  }       
}


vector<Point> interCir(const Point & a , const Point & b , double r1 , double r2) {
  vector<Point> ret;
  double d = dist(a, b), d1 = ((sqr(r1) - sqr(r2)) / d + d) / 2;
  if (sign(r1 + r2 - d) < 0 || sign(abs(r1 - r2) - d) > 0) return ret;
  Point mid = a + ((b - a) / d) * d1;
  if (sign(r1 + r2 - d) == 0) {
    ret.push_back(mid);
    return ret;
  }
  Point incr = (b - a).turnLeft() / d * sqrt(sqr(r1) - sqr(d1));
  ret.push_back(mid - incr);
  ret.push_back(mid + incr);
  return ret;
}


vector<Point> id4(const Point & o , double r , const Point & a , 
    const Point & b) {
  vector<Point> ret;
  double d = dist(a, b), h = fabs(cross(a, b, o)) / d;
  if (sign(r - h) < 0) return ret;
  double d1 = ((sqr(dist(o, a)) - sqr(dist(o, b))) / d + d) / 2;
  Point mid = a + (b - a) / d * d1;
  if (sign(r - h) == 0) {
    ret.push_back(mid);
    return ret;
  }
  Point incr = (b - a) / d * sqrt(sqr(r) - sqr(h));
  ret.push_back(mid - incr);
  ret.push_back(mid + incr);
  return ret;
}


vector<Point> id5(const Point & o , double r , const Point & a) {
  vector<Point> ret;
  double d = dist(a, o);
  if (sign(d - r) < 0) return ret;
  if (sign(r - d) == 0) {
    ret.push_back(a);
    return ret;
  }
  return interCir(o, a, r, sqrt(sqr(d) - sqr(r)));
}

inline bool inCircle(const Point & p, const pair<Point, double> & circle) {
  double dis = dist(p, circle.first);
  return sign(dis - circle.second) <= 0;
}


pair<Point, Point> id6(const Point & a, const Point & b)
{
	Point mid = (a + b) / 2;
	Point dir = mid - a;
	dir = dir.turnLeft();
	Point end = mid + dir;
	return make_pair(mid, end);
}

struct Line
{
  Point start;
  Point stop;
  Point ori;

  void Refine()
  {
    if (stop < start) swap(start,stop);
    ori = stop - start;
  }

  Line() {;}
  Line(Point & startPoint , Point & stopPoint)
  {
    start = startPoint;
    stop = stopPoint;
    Refine();
  }

  Line(double startX,double startY,double stopX,double stopY)
  {
    start = Point(startX,startY);
    stop = Point(stopX,stopY);
    Refine();
  }

  bool operator < (const Line & other) const
  {
    int signL = sign (this->ori ^ other.ori);
    if (signL > 0) return true;
    if (signL < 0) return false;
    return sign(cross(start, stop, other.start)) > 0;
  }

  bool operator == (const Line & other) const {
    return sign(this->ori ^ other.ori) == 0;
  }

  friend ostream & operator << (ostream & out , Line line)
  {
    out << line.start << " -> " << line.stop << " (" << line.ori << ") ";
    return out;
  }
};



class Polygon 
{
  public:
    
    vector<Point> pt;

    void clear() { 
      pt.clear(); 
    }

    inline int size() const { return (int)pt.size(); }
    inline void addPoint(Point a) { pt.push_back(a); }
    inline void removePoint() { pt.pop_back(); }

    
    int inside(const Point & p) 
    {
      int N = pt.size();
      bool positiveSign = false;
      bool negativeSign = false;

      for (int i = 0; i < N; ++i)
      {
        Point & now = pt[i];
        Point & next = pt[(i + 1) % N];
        Point t1 = next - now;
        Point t2 = p - next;
        int s = sign(t1 ^ t2);
        if (s == 0) 
        {
          if (onSeg(p, now, next))
            return 0;
          else 
            return -1;
        }
        if (s > 0) positiveSign = true;
        if (s < 0) negativeSign = true;
      }

      if (positiveSign && negativeSign) 
        return -1;
      else
        return 1;
    }

    
    Polygon cut(const Point & a, const Point & b) {
      int size = this->size();
      addPoint(pt[0]);
      Polygon newPoly;
      Point temp;
      for (int i = 0; i < size; i++) {
        if (sign(cross(a, b, pt[i])) <= 0) newPoly.addPoint(pt[i]);
        if (sign(cross(a, b, pt[i])) * sign(cross(a, b, pt[i + 1])) < 0) {
          vector<Point> inters = interLine(pt[i], pt[i + 1], a, b);
          if (inters.size() > 0) 
            newPoly.addPoint(inters[0]);
        }
      }
      removePoint();
      return newPoly;
    }

    
    vector<Point> polyInterLine(const Point & a, const Point & b)
    {
      int N = pt.size();
      vector<Point> ret;
      Point temp;
      for (int i = 0; i < N; ++i)
      {
        Point & now = pt[i];
        Point & next = pt[(i + 1) % N];
        if (sign(cross(a, b, now)) * sign(cross(a, b, next)) <= 0)
        {
          vector<Point> inters = interLine(a, b, now, next);
          if (inters.size() > 0)
            ret.push_back(inters[0]);
        }
      }
      return ret;
    }

    
    double area()
    {
      int size = this->size();
      if (size <= 2) return 0.0;

      addPoint(this->pt[0]);
      double ans = 0;
      for (int i = 0; i < size; ++i) ans += (pt[i] ^ pt[i+1]);
      removePoint();

      return fabs(ans / 2);
    }

    
    double length()
    {
      int size = this->size();
      addPoint(pt[0]);
      double ans = 0;
      for (int i = 0; i < size; ++i) ans += dist(pt[i], pt[i+1]);
      removePoint();
      return ans;
    }

    inline int next(int x)
    {
      return (x + 1) % this->size();
    }

    
    pair<Point, Point>  getDiameter()
    {
      if (this->size() == 0) 
        return make_pair(Point(0,0), Point(0,0));
      if (this->size() == 1)
        return make_pair(pt[0], pt[0]);
      if (this->size() == 2)
        return make_pair(pt[0], pt[1]);

      pair<Point, Point> answer;
      double diameter = 0.0;

      for (unsigned int i = 0; i < pt.size(); ++i)
        for (unsigned int j = i + 1; j < pt.size(); ++j) {
          double now = id1(pt[i], pt[j]); 
          if (now > diameter) {
            diameter = now;
            answer = make_pair(pt[i], pt[j]);
          }
        }
      return answer;
    }

    
    pair<Point, double> minCoverCircle(const Point & a, const Point & b, const
        Point & c) 
    {
      if (a.equal(b)) 
        return make_pair((b + c) / 2, dist(b, c) / 2);
      if (b.equal(c)) 
        return make_pair((c + a) / 2, dist(c, a) / 2);
      if (c.equal(a))
        return make_pair((a + b) / 2, dist(a, b) / 2);

      if (onLine(a, b, c)) {
        if (onSeg(a, b, c)) 
          return make_pair((b + c) / 2, dist(b, c) / 2);
        if (onSeg(b, a, c))
          return make_pair((a + c) / 2, dist(a, c) / 2);
        return make_pair((a + b) / 2, dist(a, b) / 2);
      }

      pair<Point, double> minCircle;
      minCircle.second = INF;

      pair<Point, double> cir1 = make_pair((a + b) / 2, dist(a, b) / 2);
      pair<Point, double> cir2 = make_pair((b + c) / 2, dist(b, c) / 2);
      pair<Point, double> cir3 = make_pair((a + c) / 2, dist(a, c) / 2);

      if (inCircle(c, cir1) && cir1.second < minCircle.second)
        minCircle = cir1;
      if (inCircle(a, cir2) && cir2.second < minCircle.second)
        minCircle = cir2;
      if (inCircle(b, cir3) && cir3.second < minCircle.second)
        minCircle = cir3;

      Point mid1 = (a + b) / 2;
      Point mid2 = (b + c) / 2;
      Point turn1 = (b - a).turnLeft();
      Point turn2 = (c - b).turnLeft();
      turn1 = mid1 + turn1;
      turn2 = mid2 + turn2;

      vector<Point> inters = interLine(mid1, turn1, mid2, turn2);
      pair<Point, double> cir4 = make_pair(inters[0], dist(inters[0], a));
      if (cir4.second < minCircle.second)
        minCircle = cir4;

      return minCircle;
    }


    
    pair<Point, double> minCoverCircle()
    {
      vector<Point> & points = pt;

      if (points.size() == 0)
        return make_pair(Point(0, 0), 0);
      if (points.size() == 1)
        return make_pair(points[0], 0);
      if (points.size() == 2)
        return make_pair((points[0] + points[1]) / 2, dist(points[0], points[1]) / 2);

      Point a = points[0];
      Point b = points[1];
      Point c = points[2];
      pair<Point, double> nowCircle = minCoverCircle(a, b, c);

      while (true) {
        bool found = false;
        double maxDis = nowCircle.second;
        Point id0;
        for (int i = 0; i < points.size(); ++i) {
          double dis = dist(points[i], nowCircle.first);
          if (sign(dis - maxDis) > 0) {
            maxDis = dis;
            id0 = points[i];
            found = true;
          }
        }

        if (!found) break;
        Point d = id0;

        Point newa, newb, newc;
        pair<Point, double> cir1 = minCoverCircle(a, b, d);
        pair<Point, double> cir2 = minCoverCircle(a, c, d);
        pair<Point, double> cir3 = minCoverCircle(b, c, d);
        pair<Point, double> minCircle;
        minCircle.second = INF;
        if (inCircle(c, cir1) && cir1.second < minCircle.second) {
          minCircle = cir1;
          c = d;
        }
        else {
          if (inCircle(b, cir2) && cir2.second < minCircle.second) {
            minCircle = cir2;
            b = d;
          }
          else {
            if (inCircle(a, cir3) && cir3.second < minCircle.second) {
              minCircle = cir3;
              a = d;
            }
          }
        }
        nowCircle = minCircle;
      }
      return nowCircle;
    }

    friend ostream & operator << (ostream & out, const Polygon & poly) 
    {
      int size = poly.size();
      for (int i = 0; i < size; ++i) 
        out << poly.pt[i] << "\t";
      return out;
    }
};

struct ConvexHull
{
  static inline bool cmp(const Point &a, const Point &b) {
    return a.y < b.y || a.y == b.y && a.x < b.x;
  }

  
  static Polygon convexHull(const vector<Point> & points, bool id3 = false) 
  {
    vector<Point> p(points.begin(), points.end());
    vector<int> stack(p.size() + 1);
    Polygon poly;
    poly.clear();
    if (p.size() == 0) 
      return poly;
    if (p.size() == 1) {
      poly.addPoint(points[0]);
      return poly;
    }

    sort(p.begin(), p.end(), ConvexHull::cmp); 

    int threshold = 0;
    if (id3) 
      threshold = 1;

    int N = (int)p.size();
    int top = -1;
    stack[++top] = 0; stack[++top] = 1;
    for (int i = 2; i < N; i++)
    {
      while (top >= 1 && 
          sign(cross(p[stack[top - 1]], p[i], p[stack[top]])) >= threshold) top--; 
      stack[++top] = i;
    }
    int temp_top = top; 
    stack[++top] = N - 2;
    for (int i = N - 3; i >= 0; i--)
    {
      while (top >= temp_top + 1 && 
          sign(cross(p[stack[top - 1]], p[i], p[stack[top]])) >= threshold) top--; 
      stack[++top] = i;
    }

    for (int i = 0; i < top; ++i) 
      poly.addPoint(p[stack[i]]);
    return poly;
  }
};

int N;
vector<Point> points;
void init()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		Point np(x, y);
		np.xx = x;
		np.yy = y;
		points.push_back(np);
	}

	Polygon poly = ConvexHull::convexHull(points);

	long long ans = 0;
	for (int i = 0; i < poly.pt.size(); ++i)
	{
		Point & now = poly.pt[i];
		Point & next = poly.pt[(i + 1) % poly.pt.size()];
		int xxdiff = abs(now.xx - next.xx);
		int id2 = abs(now.yy - next.yy);
		ans += max(xxdiff, id2);
	}
	ans += 4;
	cout << ans << endl;
}

void york()
{
}

int main()
{
	init();
	york();

	return 0;
}





