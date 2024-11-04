
using namespace std;
















typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

int onbit(int x, int pos) {x |= (1 << pos); return pos;}
int check(int x, int pos) {return x & (1 << pos);}
int clear(int x, int pos) {x &= ~(1 << pos); return x;}
int flip(int x, int pos) {x ^= (1 << pos); return x;}
int lsb(int x) {return x & (-x);}
int setall(int x, int pos) {x = (1 << pos)-1; return x;}

const double EPS = 1e-9;
const double PI = 2*acos(0.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;

struct UF {
    int *ufid, ufcnt, *ufsz;
    UF(int N)   {
			ufcnt = N;
			ufid = new int[N];
			ufsz = new int[N];
			for(int i=0; i<N; i++)	{ufid[i] = i;ufsz[i] = 1;}
    }
    int find(int p)	{
      int root = p;
      while (root != ufid[root]) root = ufid[root];
      while (p != root) {
          int newp = ufid[p];
          ufid[p] = root;
          p = newp;
      }
      return root;
    }
    void merge(int x, int y)	{
        int i = find(x);
        int j = find(y);
        if (i == j) return;
        if(ufsz[i] < ufsz[j]) { 
					ufid[i] = j; 
					ufsz[j] += ufsz[i]; 
				} else	{ 
					ufid[j] = i; 
					ufsz[i] += ufsz[j]; 
				}
        ufcnt--;
    }
    int count() {
        return ufcnt;
    }
};

const int GN = 123;
bool vis[GN];
vi adjList[GN];

void dfs(int u) {
	vis[u] = 1;
	printf("%d ", u);
	tr(it, adjList[u])
		if(!vis[*it])
			dfs(*it);
}
void bfs(int u) {
	queue<int> q;
	q.push(u);
	vis[u] = 1;
	while(!q.empty()) {
		tr(it, adjList[q.front()])
			if(!vis[*it]) {
				q.push(*it);
				vis[*it] = 1;
			}
		printf("%d ", q.front());
		q.pop();
	}
}
void dijkstra();
void apsp();

struct Point_i {
	int x, y;
	Point_i() {x=y=0;}
	Point_i(int _x, int _y) {x=_x; y=_y;}
};
struct Point {
	double x, y;
	Point() {x=y=0.0;}
	Point(double _x, double _y) {x=_x; y=_y;}
	void rotate(double theta) {
		double rad = theta*(PI/180.0);
		x = x * cos(rad) - y * sin(rad);
		y = x * sin(rad) + y * cos(rad);
	}
	bool equals(Point other) {return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));}
	bool operator < (Point other) const {
		if (fabs(x - other.x) > EPS) return x < other.x;
		return y < other.y;
	}
};
double dist(Point p1, Point p2) {return hypot(p1.x - p2.x, p1.y - p2.y);}
struct Line {
	double a, b, c;
	bool parallel(Line l2){return (fabs(a-l2.a) < EPS) && (fabs(b-l2.b) < EPS);}
	bool equals(Line l2){return (fabs(a-l2.a) < EPS) && (fabs(b-l2.b) < EPS) && (fabs(c - l2.c) < EPS);}
	bool intersect(Line l2, Point &p) {
	if ((fabs(a-l2.a) < EPS) && (fabs(b-l2.b) < EPS)) return false; 

		p.x = (l2.b * c - b * l2.c) / (l2.a * b - a * l2.b);
		if (fabs(b) > EPS) p.y = -(a * p.x + c);
		else p.y = -(l2.a * p.x + l2.c);
		return true;
	}
};
Line id0(Point p1, Point p2) {
	Line l;
	if (fabs(p1.x - p2.x) < EPS) { 

		l.a = 1.0; l.b = 0.0; l.c = -p1.x;
	} else {
		l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0; 

		l.c = -(double)(l.a * p1.x) - p1.y;
	}
	return l;
}
struct Vec {
	double x, y;
	Vec(double _x, double _y) : x(_x), y(_y) {}
};
Vec toVec(Point a, Point b) {return Vec(b.x - a.x, b.y - a.y); }
Vec scale(Vec v, double s) {return Vec(v.x * s, v.y * s);}
Point translate(Point p, Vec v) {return Point(p.x + v.x , p.y + v.y);}
double dot(Vec a, Vec b) { return (a.x * b.x + a.y * b.y); }
double norm_sq(Vec v) {return v.x * v.x + v.y * v.y;}
double id2(Point p, Point a, Point b, Point &c) {
	Vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	c = translate(a, scale(ab, u));
	return dist(p, c);
}
double id6(Point p, Point a, Point b, Point &c) {
	Vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	if (u < 0.0) {
		c = Point(a.x, a.y);
		return dist(p, a);
	}
	if (u > 1.0) {
		c = Point(b.x, b.y);
		return dist(p, b);
	}
	return id2(p, a, b, c);
}
double angle(Point a, Point o, Point b) {
	Vec oa = toVec(o, a), ob = toVec(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}
double cross(Vec a, Vec b) { return a.x * b.y - a.y * b.x; }
bool ccw(Point p, Point q, Point r) {return cross(toVec(p, q), toVec(p, r)) > 0;}
bool collinear(Point p, Point q, Point r){return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;}
int insideCircle(Point_i p, Point_i c, int r) { 

	int dx = p.x - c.x, dy = p.y - c.y;
	int Euc = dx * dx + dy * dy, rSq = r * r;
	return Euc < rSq ? 0 : Euc == rSq ? 1 : 2;

}








int inCircle(Point p1, Point p2, Point p3, Point &ctr, double &r) {


	if (fabs(r) < EPS) return 0; 

	Line l1, l2; 

	double ratio = dist(p1, p2) / dist(p1, p3);
	Point p = translate(p2, scale(toVec(p2, p3), ratio / (1 + ratio)));
	l1 = id0(p1, p);
	ratio = dist(p2, p1) / dist(p2, p3);
	p = translate(p1, scale(toVec(p1, p3), ratio / (1 + ratio)));
	l2 = id0(p2, p);
	Line(l1).intersect(l2, ctr); 

	return 1;
}
double perimeter(const vector<Point> &P) {
	double result = 0.0;
	for (int i = 0; i < (int)P.size()-1; i++) 

	result += dist(P[i], P[i+1]);
	return result; 
}
double area(const vector<Point> &P) {
	double result = 0.0, x1, y1, x2, y2;
	for (int i = 0; i < (int)P.size()-1; i++) {
		x1 = P[i].x; x2 = P[i+1].x;
		y1 = P[i].y; y2 = P[i+1].y;
		result += (x1 * y2 - x2 * y1);
	}
	return fabs(result) / 2.0;
}
bool id1(const vector<Point> &P) { 

	int sz = (int)P.size(); 

	if (sz <= 3) return false; 

	bool isLeft = ccw(P[0], P[1], P[2]); 

	for (int i = 1; i < sz-1; i++) 

	if (ccw(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isLeft)
		return false; 

	return true;
}
bool inPolygon(Point pt, const vector<Point> &P) {
	if ((int)P.size() == 0) return false;
	double sum = 0; 

	for (int i = 0; i < (int)P.size()-1; i++) {
		if (ccw(pt, P[i], P[i+1]))
			sum += angle(P[i], pt, P[i+1]); 

		else sum -= angle(P[i], pt, P[i+1]);
	} 

	return fabs(fabs(sum) - 2*PI) < EPS;
}


Point id3(Point p, Point q, Point A, Point B) {
	double a = B.y - A.y;
	double b = A.x - B.x;
	double c = B.x * A.y - A.x * B.y;
	double u = fabs(a * p.x + b * p.y + c);
	double v = fabs(a * q.x + b * q.y + c);
	return Point((p.x * v + q.x * u) / (u+v), (p.y * v + q.y * u) / (u+v));
}




vector<Point> cutPolygon(Point a, Point b, const vector<Point> &Q) {
	vector<Point> P;
	for (int i = 0; i < (int)Q.size(); i++) {
	double left1 = cross(toVec(a, b), toVec(a, Q[i])), left2 = 0;
		if (i != (int)Q.size()-1) left2 = cross(toVec(a, b), toVec(a, Q[i+1]));
		if (left1 > -EPS) P.push_back(Q[i]); 

		if (left1 * left2 < -EPS) 

		P.push_back(id3(Q[i], Q[i+1], a, b));
	}
	if (!P.empty() && !(P.back().equals(P.front())))
		P.push_back(P.front()); 

	return P;
}



















const int dx1[] = {0, 1, 0, -1};
const int dy1[] = {1, 0, -1, 0};
const int dx2[] = {1};
const int dy2[] = {1};

const int id8 = 123;
bitset<id8> id7;
int sumprog(double a, double n, double b) {return (n/2)*(a+a + (n-1)*b);}
int gcd(int a, int b) {return b ? a : gcd(b, a % b);}
int lcm(int a, int b) {return a * (b / gcd(a, b));}
void id4() {
	const int id9 = 1e3;
	id7.flip();
	int finalBit = sqrt(id7.size()) + 1;
	for(int i = 2; i < finalBit; ++i){
		if(id7.test(i))
			for(int j = 2*i; j < id9; j+=i)id7.reset(j);
	}
}
bool id5(int x) {return (id7.test(x));}

int n;
pii a[123456];

bool cmp(pii a, pii b) {
	return a.fs < b.fs;
}

int main() {


	scanf("%d", &n);
	int x = 1, i = 1;
	set<int> id10;
	fr(i, 0, 31) {
		id10.insert(x);




		x *= 2;
	}
	fr(i, 1, n+1) {
		scanf("%d", &a[i].fs);
		a[i].sc = i;
	}
	sort(a+1, a+n+1);
	int tmp[123456];
	fr(i, 1, n+1) tmp[i] = a[i].fs;
	bool mark[123456];
	fr(i, 0, 123455) mark[i] = false;
	fr(i, 1, n+1) {


		tr(it, id10) {
			int v = *it;
			int id = lower_bound(tmp+i+1, tmp+n+1, v-a[i].fs) - (tmp);
			if(id < n+1)
				if(a[id].fs == v-a[i].fs) {




					mark[i] = mark[id] = true;
					break;
				}
			if(i > 1 && !mark[i]) {
				id = lower_bound(tmp+1, tmp+i-1, v-a[i].fs) - tmp;
				if(id > 0)
					if(a[id].fs == v-a[i].fs) {
						mark[i] = mark[id] = true;
						break;
					}
			}
				
		}
	}
	int res = 0;
	fr(i, 1, n+1)
		if(!mark[i]) res++;
	printf("%d\n", res);
	return 0;
}
