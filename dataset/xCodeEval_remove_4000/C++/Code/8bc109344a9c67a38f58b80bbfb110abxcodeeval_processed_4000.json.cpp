
using namespace std;
typedef long long ll;
typedef long double lo;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
long double esp = 1e-8;
long double o = 0.0;
long double l1 = 1.0;

lo id4(lo a, lo b, lo c) {
    lo p = (a + b + c) / 2;
    return sqrt(p * (p - a)*(p - b)*(p - c));
}

struct point {
    lo x, y;

    point() {
        x = y = 0.0;
    }
    


    bool operator<(point other) const {
        if (fabs(x - other.x) > esp)
            return x < other.x;
        return y < other.y;
    }
};

struct vec {
    lo x, y;
};

vec tovec(point a, point b) {
    vec v;
    v.x = b.x - a.x;
    v.y = b.y - a.y;
    return v;
}

lo norm_sq(vec v) {
    return v.x * v.x + v.y * v.y;
};

lo dot(vec a, vec b) {
    return (a.x * b.x + a.y * b.y);
};

lo angle(point a, point o, point b) {
    vec oa = tovec(o, a), ob = tovec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

lo dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

point rotate(point p, lo theta) {
    

    lo rad = theta;
    point u;
    u.x = p.x * cos(rad) - p.y * sin(rad);
    u.y = p.x * sin(rad) + p.y * cos(rad);
    return u;
}

point rotate(point p, point o, lo theta) {
    p.x -= o.x;
    p.y -= o.y;
    

    lo rad = theta;
    point u;
    u.x = p.x * cos(rad) - p.y * sin(rad);
    u.y = p.x * sin(rad) + p.y * cos(rad);
    u.x += o.x;
    u.y += o.y;
    return u;
}

lo area(const vector<point > p) {
    lo result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < (int) p.size() - 1; i++) {
        x1 = p[i].x;
        x2 = p[i + 1].x;
        y1 = p[i].y;
        y2 = p[i + 1].y;
        result += (x1 * y2 - x2 * y1);

    }
    return fabs(result) / 2.0;
}



long double cross(vec u, vec v) {
    return u.x * v.y - u.y * v.x;
}



bool ccw(point p, point q, point r) {
    return cross(tovec(p, q), tovec(p, r)) > 0 + esp;
}



bool is_in(point p, vector<point> P) {
    int n = P.size();
    lo sum = 0;

    for (int i = 0; i < n - 1; i++)
        if (ccw(P[i], p, P[i + 1]))
            sum += angle(P[i], p, P[i + 1]);
        else
            sum -= angle(P[i], p, P[i + 1]);

    sum = fabs(sum);
    return fabs(sum - 4 * acos(0)) <= esp;
}


struct line {
    lo a, b, c;
};

bool areparallel(line l1, line l2) {
    return (fabs(l1.a - l2.a) < esp)&&(fabs(l1.b - l2.b) < esp);
}

bool id5(line l1, line l2, point &p) {
    if (areparallel(l1, l2)) return false;
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > esp)
        p.y = -(l1.a * p.x + l1.c);
    else
        p.y = -(l2.a * p.x + l2.c);
    return true;
}

void id9(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < esp) {
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x;
    } else {
        l.a = -(lo) (p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(lo) (l.a * p1.x) - p1.y;
    }
}

point translate(point p, vec v) {
    point pp;
    pp.x = p.x + v.x;
    pp.y = p.y + v.y;
    return pp;
}

point projection(point p, point a, point b) {
    vec ap = tovec(a, p), ab = tovec(a, b);
    lo u = dot(ap, ab) / norm_sq(ab);
    ab.x *= u;
    ab.y *= u;
    return translate(a, ab);
}







int id2(const point& p0, const point& p1, const point& cen,
        lo rad, point& r1, point & r2) {

    

    lo a, b, c, t1, t2;
    a = dot(tovec(p0, p1), tovec(p0, p1));
    a = ((p1.x - p0.x)*(p1.x - p0.x)+(p1.y - p0.y)*(p1.y - p0.y));
    b = 2 * dot(tovec(p0, p1), tovec(cen, p0));
    c = dot(tovec(cen, p0), tovec(cen, p0)) - rad * rad;
    lo det = b * b - 4 * a * c;
    int res;
    if (fabs(det) < esp)
        det = 0, res = 1;
    else if (det < 0)
        res = 0;
    else
        res = 2;
    det = sqrt(det);
    t1 = (-b + det) / (2 * a);
    t2 = (-b - det) / (2 * a);

    r1.x = t1 * (p1.x - p0.x) + p0.x;
    r1.y = t1 * (p1.y - p0.y) + p0.y;
    r2.x = t2 * (p1.x - p0.x) + p0.x;
    r2.y = t2 * (p1.y - p0.y) + p0.y;

    return res;
}

bool insidecircle(point p, point c, lo r) {
    lo dx = p.x - c.x, dy = p.y - c.y;
    lo euc = dx * dx + dy*dy, rsq = r*r;
    return euc <= rsq;
}

lo id6(point p1, point p2, point c, lo rad) {
    vec cp1 = tovec(c, p1);
    vec cp2 = tovec(c, p2);
    return 0.5 * rad * rad * angle(p1, c, p2) - fabs(cross(cp1, cp2)) / 2;
}

void id1(point p, point c, lo rad, lo &r1, lo &r2, lo &r3, lo &r4) {
    point a1, a2, a3, a4;
    
    

    point p1 = p;
    p1.x += 1;
    int ansx = id2(p, p1, c, rad, a1, a3);
    point p2 = p;
    p2.y += 1;
    int ansy = id2(p, p2, c, rad, a2, a4);
    

    vec cp = tovec(c, p);
    vec ca1 = tovec(c, a1);
    vec ca2 = tovec(c, a2);
    vec ca3 = tovec(c, a3);
    vec ca4 = tovec(c, a4);
    lo A = 2 * acos(0) * rad*rad;
    lo cut13 = id6(a1, a3, c, rad);
    lo cut24 = id6(a2, a4, c, rad);
    if (insidecircle(p, c, rad)) {

        r1 = 0.5 * rad * rad * angle(a1, c, a2) + cross(cp, ca1) / 2 + cross(ca2, cp) / 2;
        r2 = 0.5 * rad * rad * angle(a2, c, a3) + cross(cp, ca2) / 2 + cross(ca3, cp) / 2;
        r3 = 0.5 * rad * rad * angle(a3, c, a4) + cross(ca4, cp) / 2 + cross(cp, ca3) / 2;
        r4 = 0.5 * rad * rad * angle(a4, c, a1) + cross(ca1, cp) / 2 + cross(cp, ca4) / 2;
    } else {
        if (ansy != 2 && ansx != 2) {
            if (c.x > p.x && c.y > p.y) {
                r1 = A;
                r2 = r3 = r4 = 0;
            } else if (c.x < p.x && c.y > p.y) {
                r2 = A;
                r1 = r3 = r4 = 0;
            } else if (c.x < p.x && c.y < p.y) {
                r3 = A;
                r2 = r1 = r4 = 0;
            } else if (c.x > p.x && c.y < p.y) {
                r4 = A;
                r1 = r2 = r3 = 0;
            }
        } else if (ansy != 2) {
            if (c.x > p.x) {
                r2 = r3 = 0;
                if (p.y < c.y) {
                    r4 = cut13;
                    r1 = A - r4;
                } else {
                    r1 = cut13;
                    r4 = A - r1;
                }
            } else {
                r1 = r4 = 0;
                if (p.y < c.y) {
                    r3 = cut13;
                    r2 = A - r3;
                } else {
                    r2 = cut13;
                    r3 = A - r2;
                }
            }
        } else if (ansx != 2) {
            if (c.y > p.y) {
                r4 = r3 = 0;
                if (c.x > p.x) {
                    r2 = cut24;
                    r1 = A - r2;
                } else {
                    r1 = cut24;
                    r2 = A - r1;
                }
            } else {
                r1 = r2 = 0;

                if (c.x > p.x) {
                    r3 = cut24;
                    r4 = A - r3;
                } else {
                    r4 = cut24;
                    r3 = A - r4;
                }
            }

        } else {
            if (c.x < p.x && c.y < p.y) {
                r1 = 0;
                r4 = cut24;
                r2 = cut13;
                r3 = A - r4 - r2;
            } else if (c.x > p.x && c.y < p.y) {
                r2 = 0;
                r3 = cut24;
                r1 = cut13;
                r4 = A - r1 - r3;
            } else if (c.x > p.x && c.y > p.y) {
                r3 = 0;
                r2 = cut24;
                r4 = cut13;
                r1 = A - r2 - r4;
            } else if (c.x < p.x && c.y > p.y) {
                r4 = 0;
                r1 = cut24;
                r3 = cut13;
                r2 = A - r1 - r3;
            }
        }
    }
}





lo id0(point p1, point p2, point c, lo rad) {
    lo x1, y1, x2, y2;
    x1 = p1.x;
    x2 = p2.x;
    y1 = p1.y;
    y2 = p2.y;


    lo ans = 0;
    lo r1, r2, r3, r4;
    point p;
    p.x = x2;
    p.y = y2;
    id1(p, c, rad, r1, r2, r3, r4);
    ans += r1 + r2 + r4;
    p.x = x1;
    p.y = y2;
    id1(p, c, rad, r1, r2, r3, r4);
    ans += r3;
    p.x = x2;
    p.y = y1;
    id1(p, c, rad, r1, r2, r3, r4);
    ans += r3;
    p.x = x1;
    p.y = y1;
    id1(p, c, rad, r1, r2, r3, r4);
    ans -= r3;
    ans = 2 * acos(0) * rad * rad - ans;
    return ans;
}

lo id3(const point& a, const point& b, const point& p) {
    return fabs(cross(tovec(a, b), tovec(a, p)) / hypot(tovec(a, b).x, tovec(a, b).y));
}

lo id7(const point& a, const point& b, const point& p) {
    if (dot(tovec(a, b), tovec(a, p)) < esp)
        return hypot(tovec(a, p).x, tovec(a, p).y);
    if (dot(tovec(b, a), tovec(b, p)) < esp)
        return hypot(tovec(b, p).x, tovec(b, p).y);
    return id3(a, b, p);
}

bool collinear(point p, point q, point r) {
    return fabs(cross(tovec(p, q), tovec(p, r))) <= esp;
}

point pivot;

void Pivot(vector <point> p) {
    int n = p.size();
    pivot = p[0];
    for (int i = 1; i < n; i++)
        if (p[i].y < pivot.y)
            pivot = p[i];
}




bool ch_cmp(point a, point b) {
    if (collinear(pivot, a, b))
        return dist(pivot, a) > dist(pivot, b) ;

    lo dx1 = a.x - pivot.x, dy1 = a.y - pivot.y;
    lo dx2 = b.x - pivot.x, dy2 = b.y - pivot.y;

    return atan2(dy1, dx1) < atan2(dy2, dx2) - esp;
}

vector<point> id8(vector<point> P)
{
    int n = P.size();
    if (n <= 3) {
        if (n != 0 && !(P[0].x == P[n - 1].x && P[0].y == P[n - 1].y))
            P.push_back(P[0]);
        return P;
    }
    
    int idx = 0;
    for (int i = 1; i < n; i++)
        if (P[idx].y > P[i].y + esp || (fabs(P[idx].y - P[i].y) <= esp && P[idx].x < P[i].x - esp))
            idx = i;
    swap(P[0], P[idx]);

    pivot = P[0];
    sort(P.begin() + 1, P.end(), ch_cmp);

    vector<point> ch;
    ch.push_back(P[n - 1]), ch.push_back(P[0]), ch.push_back(P[1]);
    int i = 2;

    while (i < n) {
        int j = ch.size() - 1;
        if (ccw(ch[j - 1], ch[j], P[i]))
            ch.push_back(P[i]), i++;
        else
            ch.pop_back();
    }

    return ch;
}




set<iii> ss;
set<iii> :: iterator it;
int main() {
  
  


   int x1,y1,x2,y2;
   cin>>x1>>y1>>x2>>y2;
   
   point p1,p2;
   p1.x=x1;
   p2.x=x2;
   p1.y=y1;
   p2.y=y2;
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
       int a,b,c;
       cin>>a>>b>>c;
       ss.insert(iii(ii(a,b),c));
   }
   line ml;
  id9(p1,p2,ml);
  int ans=0;
  for(it=ss.begin();it!=ss.end();it++)
  {
      line lll;
      int a,b,c;
      a=it->first.first;
      b=it->first.second;
      c=it->second;
      if(b!=0)
      { lll.a=l1*a/b;
      lll.b=l1;
      lll.c=l1*c/b;
      }
      else
      {
          lll.a=l1;
         lll.b=o; 
         lll.c=l1*c/a;
      }
      if(areparallel(lll,ml)) continue;
     
      point pp;
      if(id5(lll,ml,pp)) 
     if(  id7(p1,p2,pp)<esp )
          ans++;
      
  }
 
  cout<<ans<<endl;
    
    return 0;
}
