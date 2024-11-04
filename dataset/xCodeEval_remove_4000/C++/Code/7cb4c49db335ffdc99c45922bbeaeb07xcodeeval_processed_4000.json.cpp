
































using namespace std;























typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
typedef vector<viii> vviii;
typedef vector<string> vs;

double id5(double d) { return d * PI / 180.0; }

double id1(double r) { return r * 180.0 / PI; }



struct point_i { int x, y; 

    point_i(int _x, int _y) { x = _x, y = _y; } 

};

struct point { double x, y; 

    point(double _x, double _y) { x = _x, y = _y; } 

    bool operator < (point other) { 

        if (fabs(x - other.x) > eps) 

            return x < other.x; 

        return y < other.y;   

    } };

bool areSame(point_i p1, point_i p2) { 

    return p1.x == p2.x && p1.y == p2.y; } 


bool areSame(point p1, point p2) { 

    

    return fabs(p1.x - p2.x) < eps && fabs(p1.y - p2.y) < eps; }

double dist(point p1, point p2) { 

    

    return hypot(p1.x - p2.x, p1.y - p2.y); } 




point rotate(point p, double theta) {
    

    

    double rad = id5(theta); 

    return point(p.x * cos(rad) - p.y * sin(rad),
                 p.x * sin(rad) + p.y * cos(rad)); }

struct line { double a, b, c; }; 




void id2(point p1, point p2, line *l) {
    if (fabs(p1.x - p2.x) < eps) 

        l->a = 1.0, l->b = 0.0, l->c = -p1.x;
    else {
        l->a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l->b = 1.0;
        l->c = -(double)(l->a * p1.x) - p1.y;
    } }






























bool areParallel(line l1, line l2) { 

    return (fabs(l1.a-l2.a) < eps) && (fabs(l1.b-l2.b) < eps); }

bool areSame(line l1, line l2) { 

    return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < eps); }



bool areIntersect(line l1, line l2, point *p) {
    if (areSame(l1, l2)) return false; 

    if (areParallel(l1, l2)) return false; 

    

    p->x = (double)(l2.b * l1.c - l1.b * l2.c) /
    (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > eps) 

        p->y = -(l1.a * p->x + l1.c);
    else 

        p->y = -(l2.a * p->x + l2.c);
    return true; }

struct vec { double x, y; 

    vec(double _x, double _y) { x = _x, y = _y; } };

vec toVector(point p1, point p2) { 

    return vec(p2.x - p1.x, p2.y - p1.y); }

vec scaleVector(vec v, double s) { 

    return vec(v.x * s, v.y * s); }  


point translate(point p, vec v) { 

    return point(p.x + v.x , p.y + v.y); }



void id12(point p, double m, line *l) {
    l->a = -m; 

    l->b = 1;  

    l->c = -((l->a * p.x) + (l->b * p.y)); } 


void closestPoint(line l, point p, point *ans) {
    line perpendicular; 

    if (fabs(l.b) < eps) { 

        ans->x = -(l.c);   ans->y = p.y;      return; }
    
    if (fabs(l.a) < eps) { 

        ans->x = p.x;      ans->y = -(l.c);   return; }
    
    id12(p, 1 / l.a, &perpendicular); 

    

    

    areIntersect(l, perpendicular, ans); }



void reflectionPoint(line l, point p, point *ans) {
    point b(0.0, 0.0);
    closestPoint(l, p, &b); 

    vec v = toVector(p, b); 

    *ans = translate(translate(p, v), v); } 


double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }







double id4(point p, point A, point B, point *c) {
    

    vec Ap = toVector(A, p), AB = toVector(A, B);
    double u = dot(Ap, AB) / norm_sq(AB);
    *c = translate(A, scaleVector(AB, u));
    return dist(p, *c); } 








double id10(point p, point A, point B, point* c) {
    vec Ap = toVector(A, p), AB = toVector(A, B);
    double u = dot(Ap, AB) / norm_sq(AB);
    if (u < 0.0) { *c = point(A.x, A.y); 

        return dist(p, A); } 

    if (u > 1.0) { *c = point(B.x, B.y); 

        return dist(p, B); } 

    return id4(p, A, B, c); } 


double angle(point a, point o, point b) { 

    vec oa = toVector(o, a), ob = toVector(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); }

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }


















bool ccw(point p, point q, point r) {
    return cross(toVector(p, q), toVector(p, r)) > 0; }



bool collinear(point p, point q, point r) {
    return fabs(cross(toVector(p, q), toVector(p, r))) < eps; }

int insideCircle(point_i p, point_i c, int r) { 

    int dx = p.x - c.x, dy = p.y - c.y;
    int Euc = dx * dx + dy * dy, rSq = r * r; 

    return Euc < rSq ? 0 : Euc == rSq ? 1 : 2; } 


bool id0(point p1, point p2, double r, point *c) {
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) +
    (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d2 - 0.25;
    if (det < 0.0) return false;
    double h = sqrt(det);
    c->x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c->y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true; }







double perimeter(const vector<point> &P) {
    double result = 0.0;
    for (int i = 0; i < (int)P.size()-1; i++)
        result += dist(P[i], P[i+1]);
    return result; }





double area(const vector<point> &P) {
    double result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < (int)P.size()-1; i++) {
        x1 = P[i].x; x2 = P[i+1].x;
        y1 = P[i].y; y2 = P[i+1].y;
        result += (x1 * y2 - x2 * y1);
    }
    return fabs(result) / 2.0; }





bool id3(const vector<point> &P) {
    int sz = (int)P.size();
    if (sz <= 3) 

        return false;
    bool isLeft = ccw(P[0], P[1], P[2]); 

    for (int i = 1; i < sz-1; i++) 

        if (ccw(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isLeft)
            return false; 

    return true; } 




bool inPolygon(point p, const vector<point> &P) {
    if ((int)P.size() == 0) return false;
    double sum = 0; 

    for (int i = 0; i < (int)P.size()-1; i++) {
        if (ccw(p, P[i], P[i+1]))
            sum += angle(P[i], p, P[i+1]);   

        else sum -= angle(P[i], p, P[i+1]); } 

    return fabs(fabs(sum) - 2*PI) < eps; }



point id6(point p, point q, point A, point B) {
    double a = B.y - A.y;
    double b = A.x - B.x;
    double c = B.x * A.y - A.x * B.y;
    double u = fabs(a * p.x + b * p.y + c);
    double v = fabs(a * q.x + b * q.y + c);
    return point((p.x * v + q.x * u) / (u + v),
                 (p.y * v + q.y * u) / (u + v)); }





vector<point> cutPolygon(point a, point b, const vector<point> &Q) {
    vector<point> P;
    for (int i = 0; i < (int)Q.size(); i++) {
        double left1 = cross(toVector(a,b),toVector(a,Q[i])), left2 = 0;
        if (i != (int)Q.size()-1)
            left2 = cross(toVector(a,b),toVector(a,Q[i+1]));
        if (left1 > -eps) P.push_back(Q[i]); 

        if (left1 * left2 < -eps) 

            P.push_back(id6(Q[i], Q[i+1], a, b));
    }
    if (!P.empty() && (fabs(P.back().x - P.front().x) > eps ||
                       fabs(P.back().y - P.front().y) > eps))
        P.push_back(P.front()); 

    return P; }

point pivot(0, 0);
bool angle_cmp(point a, point b) { 

    if (collinear(pivot, a, b))
        return dist(pivot, a) < dist(pivot, b); 

    double id8 = a.x - pivot.x, id11 = a.y - pivot.y;
    double id7 = b.x - pivot.x, id9 = b.y - pivot.y;
    return (atan2(id11, id8) - atan2(id9, id7)) < 0; }

vector<point> CH(vector<point> &P) { 

    int i, j, n = (int)P.size();
    if (n <= 3) {
        vector<point> S=P;
        S.push_back(S[0]);
        return S;
    }

    
    

    int P0 = 0;
    for (i = 1; i < n; i++) 

        if (P[i].y  < P[P0].y ||
            (P[i].y == P[P0].y && P[i].x > P[P0].x))
            P0 = i;
    

    point temp = P[0]; P[0] = P[P0]; P[P0] = temp;
    
    

    pivot = P[0]; 

    sort(++P.begin(), P.end(), angle_cmp); 

    
    

    point prev(0, 0), now(0, 0);
    vector<point> S;
    S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]); 

    i = 2; 

    while (i < n) { 

        j = (int)S.size() - 1;
        if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]); 

        else S.pop_back(); 

    }
    return S; } 


bool id0(point p1, point p2, double r, point &c) { double d2 = (p1.x - p2.x) * (p1.x - p2.x) +
    (p1.y - p2.y) * (p1.y - p2.y); double det = r * r / d2 - 0.25;
    if (det < 0.0) return false;
    double h = sqrt(det);
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true; }


int n,x[1111],y[1111];

int main(){

	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d %d",&x[i],&y[i]);
	x[n]=x[0];
	y[n]=y[0];

	n++;
	x[n]=x[1];
	y[n]=y[1];

	n++;
	x[n]=x[2];
	y[n]=y[2];

	n++;

	double an=1e12;
	for(int i=0;i<n-2;i++){

		point c=point(0,0);
		an=min(an,id4(point(x[i+1],y[i+1]),point(x[i],y[i]),point(x[i+2],y[i+2]),&c)/2.0);
	}
	
	printf("%.10f",an);

	return 0;
}