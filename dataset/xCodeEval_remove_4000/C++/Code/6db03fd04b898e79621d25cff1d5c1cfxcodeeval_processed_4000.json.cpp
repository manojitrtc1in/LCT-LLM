


using namespace std;
typedef long long ll;
const double PI=acos(-1.0);











mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());








const long double eps = 1e-12;
const long double infl = 1e20;

template <class T>
inline int sgn(const T & x) {
	return (x > eps) - (x < -eps);
}

template <class T>
struct Point {
 	T x, y;

	Point() : x(0), y(0) {

	}

	Point(const T & x, const T & y) : x(x), y(y) {

	}

	long double length() const {
		return sqrtl(x * x + y * y);
	}

	T length2() const {
		return x * x + y * y;
	}

	long double distance(const Point & rhs) const {
		return (rhs - *this).length();
	}

 	T cross(const Point & lhs, const Point & rhs) const {
		return (lhs - *this) * (rhs - *this);
	}

	T dot(const Point & lhs, const Point & rhs) const {
		return (lhs - *this) & (rhs - *this);
	}

	long double distance_to_line(const Point & p, const Point & q) const {
		if (p == q) return distance(p);
		else return fabsl(cross(p, q) / p.distance(q));
	}

	long double distance_to_segment(const Point & p, const Point & q) const {
		if (p == q) return distance(p);
		else if (p.dot(q, *this) < 0) return distance(p);
		else if (q.dot(p, *this) < 0) return distance(q);
		else return distance_to_line(p, q);
	}

	bool on_line(const Point & p, const Point & q) const {
		return sgn(cross(p, q)) == 0;
	}

	bool on_halfline(const Point & p, const Point & q, const bool & inclusive = true) const {
		if (*this == p) return inclusive;
		else return on_line(p, q) && sgn(p.dot(q, *this)) >= 0;
	}

	bool on_segment(const Point & p, const Point & q, const bool & inclusive = true) const {
		if (*this == p || *this == q) return inclusive;
		else return on_line(p, q) && sgn(dot(p, q)) <= 0;
	}

	bool in_triangle(const Point & u, const Point & v, const Point & w, const bool & inclusive = true) const {
		Point p[3] = {u, v, w};
		if (sgn(u.cross(v, w)) < 0) reverse(p, p + 3);
		for (int i = 0; i < 3; i++) {
			if (on_segment(p[i], p[(i + 1) % 3])) return inclusive;
			else if (sgn(cross(p[i], p[(i + 1) % 3])) < 0) return false;
		}
		return true;
	}

	bool in_angle(const Point & o, const Point & p, const Point & q, const bool & inclusive = true) const {
		if (on_halfline(o, p) || on_halfline(o, q)) return inclusive;
		int vs = sgn(o.cross(p, q)), ss = sgn(o.dot(p, q));
		if (vs == 0 && ss > 0) return false;
		int vp = sgn(o.cross(p, *this)), vq = sgn(o.cross(*this, q));
		if (sgn(o.cross(p, q)) >= 0) return vp > 0 && vq > 0;
		else return vp > 0 || vq > 0;
	}

	Point operator + (const Point & rhs) const {

		return Point(x + rhs.x, y + rhs.y);
	}

	Point operator - (const Point & rhs) const {

		return Point(x - rhs.x, y - rhs.y);
	}

	T operator * (const Point & rhs) const { 	

		return x * rhs.y - y * rhs.x;
	}

	T operator & (const Point & rhs) const { 	

		return x * rhs.x + y * rhs.y;
	}

	Point operator * (const T & rhs) const {	

		return Point(x * rhs, y * rhs);
	}

	Point operator / (const T & rhs) const {	

		return Point(x / rhs, y / rhs);
	}

	bool operator == (const Point & rhs) const {

		return x == rhs.x && y == rhs.y;
	}

	bool operator != (const Point & rhs) const {

		return x != rhs.x || y != rhs.y;
	}

	inline int quadrant() const {				

		if (x == 0 && y == 0) return -1;
		else if (x < 0 && y < 0) return 0;
		else if (x == 0 && y < 0) return 1;
		else if (x > 0 && y < 0) return 2;
		else if (x > 0 && y == 0) return 3;
		else if (x > 0 && y > 0) return 4;
		else if (x == 0 && y > 0) return 5;
		else if (x < 0 && y > 0) return 6;
		else return 7;
	}

	bool operator < (const Point & rhs) const {	

		int lq = quadrant(), rq = rhs.quadrant();
		if (lq != rq) {
			return lq < rq;
		} else {
			int s = sgn(*this * rhs);
			return s != 0 ? s > 0 : sgn(length2() - rhs.length2()) < 0;
		}
	}
};

template <class T>
inline bool xycmp(const Point<T> & lhs, const Point<T> & rhs) {
	if (lhs.x != rhs.x) return lhs.x < rhs.x;
	else return lhs.y < rhs.y;
}

template <class T>
void id4(vector<Point<T> > p, vector<Point<T> > & ans)  

{
	const int n = p.size();
	Point<T> o = *min_element(p.begin(), p.end(), xycmp<T>);
	for(int i = 0; i < n; i++) p[i] = p[i] - o;
	sort(p.begin(), p.end());
	for (int i = 0; i < n; i++) p[i] = o + p[i];
	ans.resize(n);
	int sz = 0;
	ans[sz++] = p[0];
	for(int i = 1; i < n; i++) {
		for(; sz > 1 && sgn(ans[sz - 2].cross(ans[sz - 1], p[i])) <= 0; sz--);
		ans[sz++] = p[i];
	}
	ans.resize(sz);
}

template <class T>
bool id0(const vector<Point<T> > & p, const Point<T> & q, const bool & inclusive = true) 
{
	const int n = p.size();
	if (n == 1) {
		return inclusive && p[0] == q;
	} else if (n == 2) {
		return inclusive && q.on_segment(p[0], p[1]);
	} else if (!q.in_angle(p[0], p[1], p[n - 1])) {
		return false;
	} else if (q.on_line(p[0], p[1]) || q.on_line(p[0], p[n - 1])) {
		return inclusive && (q.on_segment(p[0], p[1]) || q.on_segment(p[0], p[n - 1]));
	} else {
		int low = 1, high = n - 1;
		for (; low < high - 1; ) {
			int mid = low + (high - low) / 2;
			(sgn(q.cross(p[0], p[mid])) < 0 ? high : low) = mid;
		}
		if (q.on_segment(p[low], p[high])) {
			return inclusive;
		} else {
			return q.in_triangle(p[0], p[low], p[high]);
		}
	}
}

template <class T, class U>
inline T & minimize(T & a, const U & b) {
	if (b < a) a = b;
	return a;
}

template <class T>
Point<T> id2(const Point<T> & p1, const Point<T> & p2, const Point<T> & q1, const Point<T> & q2) {
	T pv1 = p1.cross(p2, q1), pv2 = p1.cross(p2, q2);
	return q1 * (-pv2 / (pv1 - pv2)) + q2 * (pv1 / (pv1 - pv2));
}

template <class T>
struct Line {
	Point<T> u, v;

	Line() {

	}

	Line(const Point<T> & u, const Point<T> & v) : u(u), v(v) {

	}

	Line(const T & px, const T & py, const T & qx, const T & qy) : u(px, py), v(qx, qy) {

	}

	T operator * (const Line & rhs) const {
		return (v - u) * (rhs.v - rhs.u);
	}

	T operator & (const Line & rhs) const {
		return (v - u) & (rhs.v - rhs.u);
	}

	bool operator < (const Line & rhs) const {
		int vs = sgn((v - u) * (rhs.v - rhs.u)), ss = sgn((v - u) & (rhs.v - rhs.u));
		if (vs == 0 && ss > 0) return on_left(rhs.u, false);
		else return v - u < rhs.v - rhs.u;
	}

	template <class U>
	bool on_left(const Point<U> & p, const bool & inclusive = true) const {
		return p.cross(u, v) > 0;
	}

	template <class U>
	bool on_right(const Point<U> & p, const bool & inclusive = true) const {
		return p.cross(u, v) < 0;
	}
};

typedef vector<Point<ld>> Polygon;
long double signed_area(Polygon p)
{
	long double area=0;
	for(int i=0;i<p.size();i++)
	{
		int j=i+1;
		j%=p.size();
		area+=p[i].x*p[j].y-p[j].x*p[i].y;
	}
	return area/2.0;
}
long double area(const Polygon &p)
{
	return fabsl(signed_area(p));
}

template <class T>
Point<T> id2(const Line<T> & lhs, const Line<T> & rhs) {
	return id2(lhs.u, lhs.v, rhs.u, rhs.v);
}

template <class T>
bool id3(vector<Line<T> > L, vector<Point<T> > & ans) {
	const int n = L.size();
	sort(L.begin(), L.end());
	int first = 0, last = 0;
	vector<Point<T> > p(n);
	vector<Line<T> > q(n);
	q[last++] = L[0];
	for (int i = 1; i < n; i++) {
		for (; first + 1 < last && L[i].on_right(p[last - 2]); last--);
		for (; first + 1 < last && L[i].on_right(p[first]); first++);
		q[last++] = L[i];
		if (sgn(q[last - 2] * q[last - 1]) == 0) {
			last--;
			if (q[last - 1].on_left(L[i].u)) q[last - 1] = L[i];
		}
		if (first + 1 < last) p[last - 2] = id2(q[last - 2], q[last - 1]);
	}
	for (; first + 1 < last && q[first].on_right(p[last - 2]); last--);
	if (last - first <= 2) return false;
	p[last - 1] = id2(q[first], q[last - 1]);
	ans.clear();
	for (int i = first; i < last; i++) ans.push_back(p[i]);
	return true;
}

template <class T>
long double id1(const vector<Point<T> > & p, const vector<Point<T> > & q) {
	const int n = p.size();
	const int m = q.size();

	long double ans = p[0].distance(q[0]);

	for (int i = 0, k; i < n; i++) {
		if (i == 0) {
			k = -1;
			long long vmx;
			for (int j = 0; j < m; j++) {
				long long v = q[j].cross(p[0], p[1]);
				if (k == -1 || vmx < v) {
					k = j;
					vmx = v;
				}
			}
		} else {
			for (; q[k].cross(p[i], p[(i + 1) % n]) < q[(k + 1) % m].cross(p[i], p[(i + 1) % n]); k = (k + 1) % m);
		}
		minimize(ans, q[k].distance_to_segment(p[i], p[(i + 1) % n]));
		if (q[k].cross(p[i], p[(i + 1) % n]) == q[(k + m - 1) % m].cross(p[i], p[(i + 1) % n])) {
			minimize(ans, q[(k + m - 1) % m].distance_to_segment(p[i], p[(i + 1) % n]));
		}
		if (q[k].cross(p[i], p[(i + 1) % n]) == q[(k + 1) % m].cross(p[i], p[(i + 1) % n])) {
			minimize(ans, q[(k + 1) % m].distance_to_segment(p[i], p[(i + 1) % n]));
		}
	}

	for (int i = 0, k; i < m; i++) {
		if (i == 0) {
			k = -1;
			long long vmx;
			for (int j = 0; j < n; j++) {
				long long v = p[j].cross(q[0], q[1]);
				if (k == -1 || vmx < v){
					k = j;
					vmx = v;
				}
			}
		} else {
			for (; p[k].cross(q[i], q[(i + 1) % m]) < p[(k + 1) % n].cross(q[i], q[(i + 1) % m]); k = (k + 1) % n);
		}
		minimize(ans, p[k].distance_to_segment(q[i], q[(i + 1) % m]));
		if (p[k].cross(q[i], q[(i + 1) % m]) == p[(k + n - 1) % n].cross(q[i], q[(i + 1) % m])) {
			minimize(ans, p[(k + n - 1) % n].distance_to_segment(q[i], q[(i + 1) % m]));
		}
		if (p[k].cross(q[i], q[(i + 1) % m]) == p[(k + 1) % n].cross(q[i], q[(i + 1) % m])) {
			minimize(ans, p[(k + 1) % n].distance_to_segment(q[i], q[(i + 1) % m]));
		}
	}

	return ans;
}

ld area_t(Point<ld> a,Point<ld> b,Point<ld> c)
{
	ld x1=a.x;
	ld y1=a.y;
	ld x2=b.x;
	ld y2=b.y;
	ld x3=c.x;
	ld y3=c.y;
	return 0.5*abs(x1*y2+y1*x3+x2*y3-x3*y2-y3*x1-x2*y1);
}


int32_t main()
{
	fastio();
	int n;
	cin>>n;
	vector<Point<ld>> v;
	for(int i=0;i<n;i++)
	{
		ld x,y;
		cin>>x>>y;
		Point<ld> pt(x,y);
		v.push_back(pt);
	}
	vector<Point<ld>> hull=v;
	n=hull.size();
	ld ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			vector<Point<ld>> left,right;
			for(int k=0;k<n;k++)
			{
				if(k==i || k==j)continue;
				ld crs=((hull[k]-hull[i])*(hull[j]-hull[i]));
				if(crs<-eps)
				{
					left.push_back(hull[k]);
				}
				else if(crs>eps)
				{
					right.push_back(hull[k]);
				}
			}
			if(left.empty() || right.empty())continue;
			ld tmp1=0,tmp2=0;
			for(auto pt: left)
			{
				tmp1=max(tmp1,area_t(hull[i],hull[j],pt));
			}
			for(auto pt: right)
			{
				tmp2=max(tmp2,area_t(hull[i],hull[j],pt));
			}
			ans=max(ans,tmp1+tmp2);
		}
	}
	cout<<fixed<<setprecision(10);
	cout<<ans<<endl;
}
