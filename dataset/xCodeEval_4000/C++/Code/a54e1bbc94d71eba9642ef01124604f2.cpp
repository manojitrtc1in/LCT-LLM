#include <bits/stdc++.h>
using namespace std;
#define M_PI 3.14159265358979323846
double INF = 1e100; double EPS = 1e-12;
struct PT {
  double x, y;
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
  bool operator ==(const PT &p) const { return fabs(p.x-x)+fabs(p.y-y) < EPS; }
  bool operator <(const PT &p) const { if(fabs(p.x-x)<EPS) return x < p.x; return y < p.y;}
};
PT next(vector<PT> g,int i) { return g[(i+1)%g.size()]; }
PT curr(vector<PT> g,int i) { return g[i]; }
double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double dist(PT p,PT q)     { return hypot(p.x-p.y,q.x-q.y); } 

double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const PT &p) {os << "(" << p.x << "," << p.y << ")";}


PT RotateCCW90(PT p)   { return PT(-p.y,p.x); }
PT RotateCW90(PT p)    { return PT(p.y,-p.x); }
PT RotateCCW(PT p, double t) {return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t));}


PT ProjectPointLine(PT a, PT b, PT c) {return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);}


PT ProjectPointSegment(PT a, PT b, PT c) {
  double r = dot(b-a,b-a);
  if (fabs(r) < EPS) return a;
  r = dot(c-a, b-a)/r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b-a)*r;
}


double DistancePointSegment(PT a,PT b,PT c) {return sqrt(dist2(c,ProjectPointSegment(a,b,c)));}


double DistancePointPlane(double x, double y, double z,
                          double a, double b, double c, double d) {
  return fabs(a*x+b*y+c*z-d)/sqrt(a*a+b*b+c*c);
}


bool LinesParallel(PT a, PT b, PT c, PT d) {return fabs(cross(b-a, c-d)) < EPS;}
bool LinesCollinear(PT a, PT b, PT c, PT d) {
  return LinesParallel(a, b, c, d) && fabs(cross(a-b, a-c)) < EPS && fabs(cross(c-d, c-a)) < EPS;
}




bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
  if (LinesCollinear(a, b, c, d)) {
    if (dist2(a, c) < EPS || dist2(a, d) < EPS ||
      dist2(b, c) < EPS || dist2(b, d) < EPS) return true;
    if (dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0)
      return false;
    return true;
  }
  if (cross(d-a, b-a) * cross(c-a, b-a) > 0) return false;
  if (cross(a-c, d-c) * cross(b-c, d-c) > 0) return false;
  return true;
}




PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
  b=b-a; d=c-d; c=c-a;
  assert(dot(b, b) > EPS && dot(d, d) > EPS);
  return a + b*cross(c, d)/cross(b, d);
}

PT ComputeCircleCenter(PT a, PT b, PT c) { 

  b=(a+b)/2;
  c=(a+c)/2;
  return ComputeLineIntersection(b, b+RotateCW90(a-b), c, c+RotateCW90(a-c));
}

bool PointInPolygon(const vector<PT> &p, PT q) {
  bool c = 0;
  for (int i = 0; i < p.size(); i++){
    int j = (i+1)%p.size();
    if ((p[i].y <= q.y && q.y < p[j].y ||
      p[j].y <= q.y && q.y < p[i].y) &&
      q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
      c = !c;
  }
  return c;
}


bool PointOnPolygon(const vector<PT> &p, PT q) {
  for (int i = 0; i < p.size(); i++)
    if (dist2(ProjectPointSegment(p[i], p[(i+1)%p.size()], q), q) < EPS)
      return true;
  return false;
}


vector<PT> CircleLineIntersection(PT a, PT b, PT c, double r) {
  vector<PT> ret;
  b = b-a; a = a-c;
  double A = dot(b, b);
  double B = dot(a, b);
  double C = dot(a, a) - r*r;
  double D = B*B - A*C;
  if (D < -EPS) return ret;
  ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);
  if (D > EPS) ret.push_back(c+a+b*(-B-sqrt(D))/A);
  return ret;
}




vector<PT> CircleCircleIntersection(PT a, PT b, double r, double R) {
  vector<PT> ret;
  double d = sqrt(dist2(a, b));
  if (d > r+R || d+min(r, R) < max(r, R)) return ret;
  double x = (d*d-R*R+r*r)/(2*d);
  double y = sqrt(r*r-x*x);
  PT v = (b-a)/d;
  ret.push_back(a+v*x + RotateCCW90(v)*y);
  if (y > 0) ret.push_back(a+v*x - RotateCCW90(v)*y);
  return ret;
}








double ComputeSignedArea(const vector<PT> &p) {
  double area = 0;
  for(int i = 0; i < p.size(); i++) {
    int j = (i+1) % p.size();
    area += p[i].x*p[j].y - p[j].x*p[i].y;
  }
  return area / 2.0;
}
double ComputeArea(const vector<PT> &p) {return fabs(ComputeSignedArea(p));}
PT ComputeCentroid(const vector<PT> &p) {
  PT c(0,0);
  double scale = 6.0 * ComputeSignedArea(p);
  for (int i = 0; i < p.size(); i++){
    int j = (i+1) % p.size();
    c = c + (p[i]+p[j])*(p[i].x*p[j].y - p[j].x*p[i].y);
  }
  return c / scale;
}


bool IsSimple(const vector<PT> &p) {
  for (int i = 0; i < p.size(); i++) {
    for (int k = i+1; k < p.size(); k++) {
      int j = (i+1) % p.size();
      int l = (k+1) % p.size();
      if (i == l || j == k) continue;
      if (SegmentsIntersect(p[i], p[j], p[k], p[l])) return false;
    }
  }
  return true;
}
struct L : public vector<PT> {
  L(const PT &a, const PT &b) {push_back(a); push_back(b);}
  L() {}
};
int ccw(PT a, PT b, PT c) {
  b = b-a; c = c-a;
  if (cross(b, c) > 0)   return +1;       

  if (cross(b, c) < 0)   return -1;       

  if (dot(b, c) < 0)     return +2;       

  if (norm(complex<double>(b.y,b.x)) < norm(complex<double>(c.y,c.x))) return -2;       

  return 0;
}
vector<PT> convex_cut(const vector<PT>& g, const L& l) { 

  vector<PT> Q;
  for(int i = 0;i < g.size();i++) {
    PT A = curr(g,i);
    PT B = next(g,i);
    if (ccw(l[0], l[1], A) != -1) Q.push_back(A);
    if (ccw(l[0], l[1], A)*ccw(l[0], l[1], B) < 0)
      Q.push_back(ComputeLineIntersection(A,B,l[0],l[1]));
  }
  return Q;
}
double det(PT a,PT b) { return a.x*b.y - a.y*b.x;}
int dblcmp(double d) {if(d<-EPS) return -1; if(d>EPS) return 1; return 0;}
struct polygons
{
    vector<vector<PT> >p;
    polygons()
    {
        p.clear();
    }
    void clear()
    {
        p.clear();
    }
    void push(vector<PT> q)
    {
        if (dblcmp(ComputeArea(q))) p.push_back(q);
    }
    vector<pair<double,int> >e;
    void ins(PT s,PT t,PT X,int i)
    {
        double r=fabs(t.x-s.x)>EPS?(X.x-s.x)/(t.x-s.x):(X.y-s.y)/(t.y-s.y);
        r=min(r,1.0);r=max(r,0.0);
        e.push_back(make_pair(r,i));
    }
    double polyareaunion()
    {
        double ans=0.0;
        int c0,c1,c2,i,j,k,w;
        for (i=0;i<p.size();i++)
        {
            if (ComputeSignedArea(p[i]) < 0)reverse(p[i].begin(),p[i].end()); 

        }
        for (i=0;i<p.size();i++)
        {
            for (k=0;k<p[i].size();k++)
            {
                PT &s=p[i][k],&t=p[i][(k+1)%p[i].size()];
                if (!dblcmp(det(s,t)))continue;
                e.clear();
                e.push_back(make_pair(0.0,1));
                e.push_back(make_pair(1.0,-1));
                for (j=0;j<p.size();j++)if (i!=j)
                {
                    for (w=0;w<p[j].size();w++)
                    {
                        PT a=p[j][w],b=p[j][(w+1)%p[j].size()],c=p[j][(w-1+p[j].size())%p[j].size()];
                        c0=dblcmp(det(t-s,c-s));
                        c1=dblcmp(det(t-s,a-s));
                        c2=dblcmp(det(t-s,b-s));
                        if (c1*c2<0)ins(s,t,ComputeLineIntersection(s,t,a,b),-c2);
                        else if (!c1&&c0*c2<0)ins(s,t,a,-c2);
                        else if (!c1&&!c2)
                        {
                            int c3=dblcmp(det(t-s,p[j][(w+2)%p[j].size()]-s));
                            int dp=dblcmp(dot(t-s,b-a));
                            if (dp&&c0)ins(s,t,a,dp>0?c0*((j>i)^(c0<0)):-(c0<0));
                            if (dp&&c3)ins(s,t,b,dp>0?-c3*((j>i)^(c3<0)):c3<0);
                        }
                    }
                }
                sort(e.begin(),e.end());
                int ct=0;
                double tot=0.0,last;
                for (j=0;j<e.size();j++)
                {
                    if (ct==2)tot+=e[j].first-last;
                    ct+=e[j].second;
                    last=e[j].first;
                }
                ans+=det(s,t)*tot;
            }
        }
        return fabs(ans)*0.5;
    }
};

int main() {
  


  

  double w,h,a;
    cin >> w >> h >> a;
    if(a>180) a-=180;
    if(a>90) a = 180-a;
  vector<PT> g;
  g.push_back(PT(-w/2,-h/2)); g.push_back(PT(-w/2,h/2));
  g.push_back(PT(w/2,h/2)); g.push_back(PT(w/2,-h/2));
  vector<PT> grot;
  for(int i = 0;i < 4;i++) grot.push_back(RotateCCW(g[i],a/180*M_PI));

  vector<vector<PT>> polys;
  polys.push_back(g);
  polys.push_back(grot);

  polygons pg;
  pg.push(g);
  pg.push(grot);

  printf("%.12f",pg.polyareaunion());
  

  

}
