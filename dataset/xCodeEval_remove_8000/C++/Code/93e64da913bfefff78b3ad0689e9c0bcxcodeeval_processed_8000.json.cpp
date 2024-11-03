
using namespace std;









typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;



const ll mod = 998244353;

const int maxn = 2e3+7;

const ll infll = 9e18;
const db infdb = 1e16;
const int infit = 2e9+7;
const db EPS = 1e-12;
const db PI = acos(-1.0);
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x;}

inline ll powmod(ll a,ll b=mod-2)
{
    ll res=1ll;a%=mod;assert(b>=0);
    for(;b;b>>=1)
    {
        if(b&1)
            res=res*a%mod;
        a=a*a%mod;
    }
    return res;
}


ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }
template<typename T=db>inline int sign(T a) { return a < -EPS ? -1 : a > EPS; }

template<typename T=db>inline int cmp(const T&a,const T&b) { return sign(a-b); }

template<typename T=db>inline T sqr(T x) { return x*x; }
inline double reps(){return (1.0*rand()/RAND_MAX-0.5)*EPS;}

template <typename T=int>
inline T transint(db x) { T v=x; return sign(x-v)?v+1:v; }

db norm(db x){
	while(x < 0) x += 2 * PI;
	while(x > 2 * PI) x -= 2 * PI;
	return x;
}






template <class T=db>
struct P {
	T x, y;

	db ag;

	P() {}
	P(T _x, T _y) : x(_x), y(_y) {ag = atan2(y, x);}
	P<T> operator+(P<T> p) { return {x + p.x, y + p.y}; }
	P<T> operator-(P<T> p) { return {x - p.x, y - p.y}; }
	P<T> operator*(T d) { return {x * d, y * d}; }
	P<T> operator/(T d) { return {x / d, y / d}; }
	P<T>& operator+=(P<T> p) { x+=p.x;y+=p.y;return *this; }
	P<T>& operator-=(P<T> p) { x-=p.x;y-=p.y;return *this; }
	bool operator<(P<T> p) const {
		int c = cmp(x, p.x);
		if (c) return c == -1;
		return cmp(y, p.y) == -1;
	}

	bool operator==(P<T> o) const{
		return cmp(x, o.x) == 0 && cmp(y, o.y) == 0;
	}


	T dot(P<T> p) { return x * p.x + y * p.y; }

	T det(P<T> p) { return x * p.y - y * p.x; }


	db distTo(P<T> p) { return (*this-p).abs(); }

	T distTo2(P<T> p) { return (*this-p).abs2(); }

	db alpha() { return atan2(y, x); }

	void read() { cin>>x>>y; }

	void write() {cout<<"("<<x<<","<<y<<")"<<endl;}

	db abs() { return sqrt(abs2());}
	T abs2() { return x * x + y * y; }
	P<T> rot90() { return P<T>(-y, x);}

	P<T> clrot90() { return P<T>(y, -x);}

	P<T> unit() { return *this/abs(); }

	bool quad() const { return sign(y) == 1 || (sign(y) == 0 && sign(x) >= 0); }
	

	P<T> rot(db an) { return {x*cos(an) - y*sin(an), x*sin(an) + y*cos(an)}; }
	

	void shake() { x+=reps();y+=reps(); }

};

template <typename T=db>
bool angcmp(P<T>& pa, P<T>& pb)
{
    if(cmp(pa.ag, pb.ag))
        return pa.ag < pb.ag;

    return pa < pb;

}

inline bool cmpAng (P<ll> &A, P<ll> &B) {
    return A.det(B)>0||(A.det(B)==0&&A.abs2()<B.abs2());
}


inline bool cmpAng (P<db> &A, P<db> &B) {
    return A.det(B)>0||(A.det(B)==0&&A.abs()<B.abs());
}


template <class T=db>
struct L{ 

	P<T> ps[2];
	P<T>& operator[](int i) { return ps[i]; }

	P<T> dir() { return ps[1] - ps[0]; }

	L (P<T> a,P<T> b) {
		ps[0]=a;
		ps[1]=b;
	}
	bool include(P<T> p)

	{ return sign((ps[1] - ps[0]).det(p - ps[0])) > 0; }
	L<T> push(){ 

		const double eps = 1e-8;
		P<T> delta = (ps[1] - ps[0]).rot90().unit() * eps;
		return {ps[0] + delta, ps[1] + delta};
	}
};











template <typename T=db>
bool sameSide(P<T> p1, P<T> p2, P<T> q1, P<T> q2){
    return crossOp(p1, p2, q1) * crossOp(p1, p2, q2) > 0;
}

template <typename T=db>
bool chkLL(P<T> p1, P<T> p2, P<T> q1, P<T> q2) {
	T a1 = cross(q1, q2, p1), a2 = -cross(q1, q2, p2);
	return sign(a1+a2) != 0;
}


template <typename T=db>
P<T> isLL(P<T> p1, P<T> p2, P<T> q1, P<T> q2) {
	T a1 = cross(q1, q2, p1), a2 = -cross(q1, q2, p2);
	return (p1 * a2 + p2 * a1) / (a1 + a2);
}


template <typename T=db>
P<T> isLL(L<T> l1,L<T> l2){ return isLL(l1[0],l1[1],l2[0],l2[1]); }

template <typename T=db>
bool intersect(T l1,T r1,T l2,T r2){
	if(l1>r1) swap(l1,r1); if(l2>r2) swap(l2,r2);
	return !( cmp(r1,l2) == -1 || cmp(r2,l1) == -1 );
}

template <typename T=db>
bool isSS(P<T> p1, P<T> p2, P<T> q1, P<T> q2){
	return intersect(p1.x,p2.x,q1.x,q2.x) && intersect(p1.y,p2.y,q1.y,q2.y) &&
	crossOp(p1,p2,q1) * crossOp(p1,p2,q2) <= 0 && crossOp(q1,q2,p1)
			* crossOp(q1,q2,p2) <= 0;
}


template <typename T=db>
bool id4(P<T> p1, P<T> p2, P<T> q1, P<T> q2){
	return crossOp(p1,p2,q1) * crossOp(p1,p2,q2) < 0 && crossOp(q1,q2,p1)
			* crossOp(q1,q2,p2) < 0;
}


template <typename T=db>
bool isMiddle(T a, T m, T b) {
	return sign(a - m) == 0 || sign(b - m) == 0 || (a < m != b < m);
}


template <typename T=db>
bool isMiddle(P<T> a, P<T> m, P<T> b) {
	return isMiddle(a.x, m.x, b.x) && isMiddle(a.y, m.y, b.y);
}


template <typename T=db>
bool onSeg(P<T> p1, P<T> p2, P<T> q){
	return crossOp(p1,p2,q) == 0 && isMiddle(p1, q, p2);
}


template <typename T=db>
bool id12(P<T> p1, P<T> p2, P<T> q){
	return crossOp(p1,p2,q) == 0 && sign((q-p1).dot(p1-p2)) * sign((q-p2).dot(p1-p2)) < 0;
}


template <typename T=db>
P<T> proj(P<T> p1, P<T> p2, P<T> q) {
	P<T> dir = p2 - p1;

	return p1 + dir * (dir.dot(q - p1) / dir.abs2());
}


template <typename T=db>
P<T> reflect(P<T> p1, P<T> p2, P<T> q){
	return proj(p1,p2,q) * 2 - q;
}


template <typename T=db>
db nearest(P<T> p1,P<T> p2,P<T> q){
	P<T> h = proj(p1,p2,q);
	if(isMiddle(p1,h,p2))
		return q.distTo(h);
	return min(p1.distTo(q),p2.distTo(q));
}


template <typename T=db>
db disSS(P<T> p1, P<T> p2, P<T> q1, P<T> q2){
	if(isSS(p1,p2,q1,q2)) return 0;

	return min(min(nearest(p1,p2,q1),nearest(p1,p2,q2)), min(nearest(q1,q2,p1),nearest(q1,q2,p2)));
}


template <typename T=db>
db disLP(L<T> l,P<T> q){
	P<T> h = proj(l.ps[0],l.ps[1],q);
	return q.distTo(h);
}


template <typename T=db>
db rad(P<T> p1,P<T> p2){
	return atan2l(p1.det(p2),p1.dot(p2));
}


template <typename T=db>
db incircle(P<T> p1, P<T> p2, P<T> p3){
	db A = p1.distTo(p2);
	db B = p2.distTo(p3);
	db C = p3.distTo(p1);
	return sqrtl(A*B/(A+B+C)*C);
}


template <typename T=db>
db innercircle(P<T> p1, P<T> p2, P<T> p3){
	db A = p1.distTo(p2);
	db B = p2.distTo(p3);
	db C = p3.distTo(p1);
	db id15 = fabs(p1.dot(p2));
	return sqrtl(id15/(A+B+C));
}


template <typename T=db>
db outercircle(P<T> p1, P<T> p2, P<T> p3){
	db A = p1.distTo(p2);
	db B = p2.distTo(p3);
	db C = p3.distTo(p1);
	db id14 = 2.0*fabs(p1.dot(p2));
	return sqrtl(A*B/id14*C);
}





template <typename T=db> using Polygon = vector<P<T> >;


template <typename T=db>
T area(Polygon<T>& ps){
	db ret = 0;
	int s = ps.size();
	rep(i,0,s) ret += ps[i].det(ps[(i+1)%s]);
	return ret;
}


template <typename T=db>
db perimeter(Polygon<T>& ps){
	db ret = 0;
	int s = ps.size();
	rep(i,0,s) ret += ps[i].distTo(ps[(i+1)%s]);
	return ret;
}


template <typename T=db>
int contain(Polygon<T>& ps, P<T> p){ 

	int n = ps.size(), ret = 0;
	rep(i,0,n){
		P<T> u=ps[i],v=ps[(i+1)%n];
		if(onSeg(u,v,p)) return 1;
		if(cmp(u.y,v.y)<=0) swap(u,v);
		if(cmp(p.y,u.y) >0 || cmp(p.y,v.y) <= 0) continue;
		ret ^= crossOp(p,u,v) > 0;
	}
	return ret*2;
}


template <typename T=db>
bool id2(Polygon<T>& ps, P<T> p){ 

    int n = ps.size();
    

    if(p.det(ps[1])>0||ps[n-1].det(p)>0||
    p.det(ps[1])==0&&p.abs2()>ps[1].abs2()||
    p.det(ps[n-1])==0&&p.abs2()>ps[n-1].abs2()) return false;
    

    P<T> dp = ps[0];
	int l = 1, r = n-2, mid;
	while(l <= r) {
        mid = l+r>>1;
        T r1 = (ps[mid]-dp).det(p-dp),
          r2 = (ps[mid+1]-dp).det(p-dp);
        if(r1>=0&&r2<=0)
        {
            if((ps[mid+1]-ps[mid]).det(p-ps[mid])>=0)
                return true;
            return false;
        }
        if(r1<0)
            r = mid-1;
        else
            l = mid+1;
    }
	return false;
}


template <typename T=db>
Polygon<T> id11(Polygon<T>& ps, int flag = 1) {

    

    int n = ps.size();
    if (n <= 1) return ps;
    sort(ps.begin(), ps.end());
    Polygon<T> ans(n * 2);
    int now = -1;
    rep(i,0,n) {
        while (now > 0 && crossOp(ans[now - 1], ans[now], ps[i]) < flag) now--;
        ans[++now] = ps[i];
    }
    int pre = now;
    per(i,0,n-1) {
        while (now > pre && crossOp(ans[now - 1], ans[now], ps[i]) < flag) now--;
        ans[++now] = ps[i];
    }
    return ans.resize(now), ans;
}


template <typename T=db>
inline void id1(Polygon<T>& ps, int flag = 0) {

    

    int sz = ps.size();
    P<T> id5 = P<T>(infit, infit);
    rep(i,0,sz)
        if(id5.y > ps[i].y ||
        id5.y == ps[i].y && id5.x > ps[i].x)
            id5 = ps[i];
    VI sta;
    sta.pb(0);
    rep(i,0,sz) ps[i] -= id5;
    sort(ps.begin(),ps.end(),
         [](P<T>&A,P<T>&B)->bool{ return A.det(B)>0||(A.det(B)==0&&A.abs()<B.abs()); });
    for(int i = 1; i < sz; sta.pb(i),++i)
		while(sta.size()>=2&&
        crossOp(ps[sta[sta.size()-2]],ps[i],ps[sta.back()])>=flag) sta.pop_back();
	rep(i,0,sta.size()) ps[i] = ps[sta[i]]+id5;
	ps.resize(sta.size());
}


template <typename T=db>
db id6(Polygon<T> ps){
	int n = ps.size(); if(n <= 1) return 0;
	int is = 0, js = 0; rep(k,1,n) is = ps[k]<ps[is]?k:is, js = ps[js] < ps[k]?k:js;
	int i = is, j = js;
	db ret = ps[i].distTo(ps[j]);
	do{
		if((ps[(i+1)%n]-ps[i]).det(ps[(j+1)%n]-ps[j]) >= 0)
			(++j)%=n;
		else
			(++i)%=n;
		ret = max(ret,ps[i].distTo(ps[j]));
	}while(i!=is || j!=js);
	return ret;
}


template <typename T=db>
Polygon<T> id13(const Polygon<T>&ps, P<T> q1, P<T> q2) {
	Polygon<T> qs;
	int n = ps.size();
	rep(i,0,n){
		P<T> p1 = ps[i], p2 = ps[(i+1)%n];
		int d1 = crossOp(q1,q2,p1), d2 = crossOp(q1,q2,p2);
		if(d1 >= 0) qs.pb(p1);
		if(d1 * d2 < 0) qs.pb(isLL(p1,p2,q1,q2));
	}
	return qs;
}


template <typename T=db>
int id0(P<T> pt, Polygon<T>& hull, int flag=1){
    int s = hull.size(), l=0, r=s, mid;
    P<T> p1, p2, p3; T pl, pmid, pr;
    auto id16 = [&] (int x) -> P<T> {return hull[x%s];};
    if(flag*crossOp(id16(0), id16(1), pt)<=0 &&
    flag*crossOp(id16(s-1), id16(0), pt)>=0) return 0;
    

    while(l < r) {
        mid = l+r >> 1;
        p1 = id16(l);
        p2 = id16(mid);
        p3 = id16(r);
        if(flag*crossOp(p2, id16(mid+1), pt)<=0 &&
        flag*crossOp(id16(mid-1), p2, pt)>=0) return mid;
        pl = crossOp(p1,id16(l+1),pt);
        pmid = crossOp(p2,id16(mid+1),pt);
        pr = crossOp(p3,id16(r+1),pt);
        if(pl==pr&&pr==pmid){if(pmid*crossOp(pt,p2,p3)<0)l = mid;else r = mid;}
        else{if(pmid*flag > 0)l = mid;else r = mid;}
    }
    return -1;

}


template <typename T=db>
inline void reArrange(Polygon<T>& ps) {
    int sz = ps.size();
    P<T> id5 = P<T>(infit, infit);
    rep(i,0,sz)
        if(id5.y > ps[i].y)
            id5 = ps[i];
    rep(i,0,sz)
        ps[i] -= id5;
    sort(ps.begin(),ps.end(),
         [](P<T>&A,P<T>&B)->bool{ return A.det(B)>0||(A.det(B)==0&&A.abs()<B.abs()); });
    

    

    rep(i,0,sz)
        ps[i] += id5;
}


template <typename T=db>
Polygon<T> id10(Polygon<T> &p1, Polygon<T> &p2)
{
    int n = p1.size(), m = p2.size();
    Polygon<T> s1, s2, A;
	rep(i,0,n-1) s1.pb(p1[i+1]-p1[i]);s1.pb(p1[0]-p1[n-1]);
	rep(i,0,m-1) s2.pb(p2[i+1]-p2[i]);s2.pb(p2[0]-p2[m-1]);
	A.pb(p1[0]+p2[0]);
	int cnt1=0,cnt2=0;
	while(cnt1<n&&cnt2<m) A.pb(A.back()+(s1[cnt1].det(s2[cnt2])>=0?s1[cnt1++]:s2[cnt2++]));
	while(cnt1<n) A.pb(A.back()+s1[cnt1++]);
	while(cnt2<m) A.pb(A.back()+s2[cnt2++]);
	return A;
}


template <typename T=db>
db min_dist(Polygon<T> & ps,int l,int r){

	if(r-l<=5){
		db ret = 1e100;
		rep(i,l,r) rep(j,l,i) ret = min(ret,ps[i].distTo(ps[j]));
		return ret;
	}
	int m = (l+r)>>1;
	db ret = min(min_dist(ps,l,m),min_dist(ps,m,r));
	Polygon<T> qs; rep(i,l,r) if(fabs(ps[i].x-ps[m].x)<= ret) qs.pb(ps[i]);
	sort(qs.begin(), qs.end(),[](P<T> a,P<T> b) -> bool {return a.y<b.y; });
	

	rep(i,1,qs.size()) for(int j=i-1;j>=0&&qs[j].y>=qs[i].y-ret;--j)
		ret = min(ret,qs[i].distTo(qs[j]));
	return ret;
}







namespace circleOperation{
template <typename T=db>
int typeCC(P<T> o1,T r1,P<T> o2,T r2){
	db d = o1.distTo(o2);
	if(cmp(d,r1+r2) == 1) return 4;
	if(cmp(d,r1+r2) == 0) return 3;
	if(cmp(d,fabs(r1-r2)) == 1) return 2;
	if(cmp(d,fabs(r1-r2)) == 0) return 1;
	return 0;
}


template <typename T=db>
int typeCL(P<T> o,T r,P<T> p1,P<T> p2){
    int knd=cmp(fabs((o-p1).det(p2-p1)/p1.distTo(p2)),r);
    if(knd > 0) return 2;
    if(!knd) return 1;
    return 0;
}


template <typename T=db>
int typeCP(P<T> o,T r,P<T> p){
    T x = (p - o).abs2(), d = x - r * r;
    if(sign(d) > 0) return 2;
    if(!sign(d)) return 1;
    return 0;
}


template <typename T=db>
Polygon<T> isCL(P<T> o,T r,P<T> p1,P<T> p2){
	if (typeCL(o,r,p1,p2)==2) return {};
	db x = (p1-o).dot(p2-p1), y = (p2-p1).abs2(), d = x * x - y * ((p1-o).abs2() - r*r);
	d = max(d,(db)0.0); P<T> m = p1 - (p2-p1)*(x/y), dr = (p2-p1)*(sqrt(d)/y);
	return {m-dr,m+dr};
}


template <typename T=db>
Polygon<T> isCC(P<T> o1, T r1, P<T> o2, T r2) { 

	db d = o1.distTo(o2);
	int tp = typeCC(o1,r1,o2,r2);
	if (tp == 4 || tp == 0) return {};
	d = min(d, r1 + r2);
	db y = (r1 * r1 + d * d - r2 * r2) / (2 * d), x = sqrt(r1 * r1 - y * y);
	

	P<T> dr = (o2 - o1).unit();
	P<T> q1 = o1 + dr * y, q2 = dr.rot90() * x;
	return {q1-q2,q1+q2};
}


template <typename T=db>
Polygon<T> tanCP(P<T> o, T r, P<T> p) {
	T x = (p - o).abs2(), d = x - r * r;
	if (typeCP(o, r, p) < 2) return {}; 

	P<T> q1 = o + (p - o) * (r * r / x);
	P<T> q2 = (p - o).rot90() * (r * sqrt(d) / x);
	return {q1-q2,q1+q2};
}


template <typename T=db>
vector<L<T> > id8(P<T> o1, T r1, P<T> o2, T r2) {

	vector<L<T> > ret;
	if (cmp(r1, r2) == 0) {
		P<T> dr = (o2 - o1).unit().rot90() * r1;
		ret.pb(L<T>(o1 + dr, o2 + dr)), ret.pb(L<T>(o1 - dr, o2 - dr));
	} else {
		P<T> p = (o2 * r1 - o1 * r2) / (r1 - r2);
		Polygon<T> ps = tanCP(o1, r1, p), qs = tanCP(o2, r2, p);
		rep(i,0,min(ps.size(),qs.size())) ret.pb(L<T>(ps[i], qs[i]));
	}
	return ret;
}


template <typename T=db>
vector<L<T> > id9(P<T> o1, T r1, P<T> o2, T r2) {
	vector<L<T> > ret;
	P<T> p = (o1 * r2 + o2 * r1) / (r1 + r2);
	Polygon<T> ps = tanCP(o1,r1,p), qs = tanCP(o2,r2,p);
	rep(i,0,min(ps.size(),qs.size())) ret.pb(L<T>(ps[i], qs[i]));
	return ret;
}


template <typename T=db>
db areaCT(T r, P<T> p1, P<T> p2){
	Polygon<T> is = isCL(P<T>(0,0),r,p1,p2);
	if(is.empty()) return r*r*rad(p1,p2)/2;
	bool b1 = cmp(p1.abs2(),r*r) == 1, b2 = cmp(p2.abs2(), r*r) == 1;
	if(b1 && b2){
		if(sign((p1-is[0]).dot(p2-is[0])) <= 0 &&
			sign((p1-is[0]).dot(p2-is[0])) <= 0)
		return r*r*(rad(p1,is[0]) + rad(is[1],p2))/2 + is[0].det(is[1])/2;
		else return r*r*rad(p1,p2)/2;
	}
	if(b1) return (r*r*rad(p1,is[0]) + is[0].det(p2))/2;
	if(b2) return (p1.det(is[1]) + r*r*rad(is[1],p2))/2;
	return p1.det(p2)/2;
}







template <typename T=db>
db areaCC(P<T> o1, db r1, P<T> o2, db r2){
    db d = o1.distTo(o2);
    int knd = typeCC(o1,r1,o2,r2);
    if(knd >= 3) return 0;
    if(knd != 2) return PI*sqr(min(r1,r2));
    db x = (sqr(d)+sqr(r1)-sqr(r2))/(2.0*d);
    db t1 = acos(x/r1), t2 = acos((d-x)/r2);
    return sqr(r1)*t1+sqr(r2)*t2-d*r1*sin(t1);
}

}



template <typename T=db>
inline bool parallel(L<T> &l0, L<T> &l1)

{ return !chkLL(l0.ps[0], l0.ps[1], l1.ps[0], l1.ps[1]); }

template <typename T=db>
inline bool sameDir(L<T> &l0, L<T> &l1)

{ return parallel(l0, l1) && sign(l0.dir().dot(l1.dir()) ) == 1; }



template <typename T=db>
inline bool cmpP (P<T> a, P<T> b) {
	if (a.quad() != b.quad()) {
		return a.quad() < b.quad();

	} else {
		return sign( a.det(b) ) > 0;

	}
}

template <typename T=db>
inline bool operator < (L<T> &l0, L<T> &l1) {
	if (sameDir(l0, l1)) {
		return l1.include(l0[0]); 

	} else {
		return cmpP( l0.dir(), l1.dir() );

	}
}

template <typename T=db>
inline bool check(L<T> &u, L<T> &v, L<T> &w) {
	return w.include(isLL(u,v));
}


template <typename T=db>
Polygon<T> id7(vector<L<T> > &l) {
	sort(l.begin(), l.end());
	deque<L<T> > q;

	for (int i = 0; i < (int)l.size(); ++i) {
		if (i && sameDir(l[i], l[i - 1])) continue;
		while (q.size() > 1 && !check(q[q.size() - 2], q[q.size() - 1], l[i])) q.pop_back();
		while (q.size() > 1 && !check(q[1], q[0], l[i])) q.pop_front();
		q.push_back(l[i]);
	}
	while (q.size() > 2 && !check(q[q.size() - 2], q[q.size() - 1], q[0])) q.pop_back();
	while (q.size() > 2 && !check(q[1], q[0], q[q.size() - 1])) q.pop_front();
	Polygon<T> ret;
	for (int i = 0; i < (int)q.size(); ++i) ret.push_back(isLL(q[i], q[(i + 1) % q.size()]));
	return ret;
}


int n, k;
int dpcnt[maxn][maxn];
ll dpleft[maxn][maxn], subarea[maxn][maxn], al, x, y;
Polygon<ll> ps;

bool che(ll w)
{
    int id3 = 1;
    ll r, s;
    ms(dpcnt,0);
    rep(i,0,n)
    {
        rep(j,i+1,n)
        {
            dpleft[i][j] = al;
        }
    }
    rep(v,1,n)
        rep(i,0,n-v)
        {
            register int j = i+v;
            rep(k,i+1,j)
            {
                if((r=al-(al-dpleft[i][k])-(al-dpleft[k][j])) < w)
                    continue;
                if(dpcnt[i][k]+dpcnt[k][j] > dpcnt[i][j])
                    dpcnt[i][j] = dpcnt[i][k]+dpcnt[k][j], dpleft[i][j] = r;
                else if(dpcnt[i][k]+dpcnt[k][j] == dpcnt[i][j])
                    dpleft[i][j] = max(dpleft[i][j], r);
                if((s=subarea[i][k]-(al-dpleft[i][k])) >= w && r-s >= w)
                {
                    if(dpcnt[i][k]+dpcnt[k][j]+1 > dpcnt[i][j])
                    {
                        dpcnt[i][j] = dpcnt[i][k]+dpcnt[k][j]+1;
                        dpleft[i][j] = r-s;
                    }
                    else if(dpcnt[i][k]+dpcnt[k][j]+1 == dpcnt[i][j])
                        dpleft[i][j] = max(dpleft[i][j], r-s);
                }
                if((s=subarea[k][j]-(al-dpleft[k][j])) >= w && r-s >= w)
                {
                    if(dpcnt[i][k]+dpcnt[k][j]+1 > dpcnt[i][j])
                    {
                        dpcnt[i][j] = dpcnt[i][k]+dpcnt[k][j]+1;
                        dpleft[i][j] = r-s;
                    }
                    else if(dpcnt[i][k]+dpcnt[k][j]+1 == dpcnt[i][j])
                        dpleft[i][j] = max(dpleft[i][j], r-s);
                }
                if((r=al-subarea[i][k]-subarea[k][j]) >= w &&
                   (k == i+1 || dpleft[i][k]-r-subarea[k][j] >= w) &&
                   (k == j-1 || dpleft[k][j]-r-subarea[i][k] >= w))
                {
                    if(dpcnt[i][k]+dpcnt[k][j]+(k>i+1)+(k<j-1) > dpcnt[i][j])
                    {
                        dpcnt[i][j] = dpcnt[i][k]+dpcnt[k][j]+(k>i+1)+(k<j-1);
                        dpleft[i][j] = r;
                    }
                    else if(dpcnt[i][k]+dpcnt[k][j]+(k>i+1)+(k<j-1) == dpcnt[i][j])
                        dpleft[i][j] = max(dpleft[i][j], r);
                }
                
            }
            id3 = max(id3, dpcnt[i][j]+1);
        }
    

    return id3 >= k+1;
}

int main()
{
    cin >> n >> k;
    rep(i,0,n)
    {
        cin >> x >> y;
        ps.pb(P<ll>(x,y));
    }
    al = area(ps);
    ps.pb(ps.front());
    n += 1;
    rep(i,0,n)
    {
        rep(j,i+2,n)
        {
            subarea[i][j] = subarea[i][j-1] + abs(cross(ps[i],ps[j-1],ps[j]));
        }
    }
    

    

    

    

    

    ll l = 0, r = al, mid;
    while(l < r)
    {
        mid = l+r>>1ll;
        if(che(mid))
            l = mid+1;
        else
            r = mid;
    }
    

    ll ans = -1;
    for(ll i = max(0ll,l-1); i <= min(al,l+1); i++)
    {
        if(che(i))
            ans = i;
    }
    cout << ans << endl;
    return 0;
}
