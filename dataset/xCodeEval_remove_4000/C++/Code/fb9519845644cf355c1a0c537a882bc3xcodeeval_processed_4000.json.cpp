




using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;
typedef priority_queue<ppi> max_heap_ppi;




















template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    return os << "]";
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
    return os<<"}";
}



    
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1<<" | ";
        __f(comma+1, args...);
    }

    

const int maxn=1e6+100;
const int MaxN=1e5+100;










































ld INF = 1e100;
ld EPS = 1e-9;
inline bool eq(ld a,ld b) {return fabs(a-b)<EPS;}
inline bool lt(ld a,ld b) {return a+EPS<b;}
inline bool gt(ld a,ld b) {return a>b+EPS;}
inline bool le(ld a,ld b) {return lt(a,b)||eq(a,b);}
inline bool ge(ld a,ld b) {return gt(a,b)||eq(a,b);}


struct pt{
    
    
    
    F1 x,y;
    
    pt() {};
    pt(F1 _x): x(_x),y((F1)(0)){};
    pt(F1 _x, F1 _y): x(_x),y(_y){};
    pt operator + (const pt &p) const {return pt(x+p.x,y+p.y);}
    pt operator - (const pt &p) const {return pt(x-p.x,y-p.y);}
    F2 operator * (const pt &p) const {return x*p.x+y*p.y;}
    F2 operator ^ (const pt &p) const {return x*p.y-y*p.x;}
    pt operator * (const F3 c) const {return pt(x*c,y*c);}
    pt operator / (const F3 c) const {return pt(x/c,y/c);}
    pt operator += (const pt &p) {this->x+=p.x;this->y+=p.y;return *this;}
    pt operator -= (const pt &p) {this->x-=p.x;this->y-=p.y;return *this;}
    pt operator *= (const F3 c) {this->x*=c;this->y*=c; return *this;}
    pt operator /= (const F3 c) {this->x/=c;this->y/=c;return *this;}
    

    bool operator < (const pt &p) const{ return lt(y,p.y)||(eq(y,p.y)&&lt(x,p.x));}
    inline bool operator == (const pt &r) const {return (eq(y,r.y) && eq(x,r.x));}
    bool operator > (const pt &p) const{ return p<pt(x,y);}
    inline bool operator <= (const pt &r) const {return !(*this>r);}
    inline bool operator >= (const pt &r) const {return !(*this<r);}
    inline bool operator != (const pt &r) const {return !(*this==r);}
    friend istream& operator >> (istream& is, pt& p){return is>>p.x>>p.y;}
    friend ostream& operator << (ostream& os, const pt& p) {return os<<"("<<p.x<<","<<p.y<<")";}
};
































ld dot(pt p,pt q) {return p.x*q.x+p.y*q.y;}
ld dist2(pt p, pt q) {return dot(p-q,p-q);}
ld dist(pt p,pt q) {return sqrt(dist2(p,q));}
ld norm2(pt p) {return dot(p,p);}
ld norm(pt p) {return sqrt(norm2(p));}
ld cross(pt p, pt q) { return p.x*q.y-p.y*q.x;}










int orient(pt a,pt b,pt c)
{
  pt p=b-a,q=c-b;double cr=cross(p,q);
  if(eq(cr,0))return 0;if(lt(cr,0))return 1;return -1;}


pt id8(pt p)   { return pt(-p.y,p.x); }
pt id15(pt p)    { return pt(p.y,-p.x); }
pt id3(pt p, ld t) {  

  return pt(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t)); }


pt id11(pt a, pt b, pt c) {
  return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);}


pt id16(pt a, pt b, pt c) {
  ld r = dot(b-a,b-a); if (eq(r,0)) return a;

  r = dot(c-a, b-a)/r;if (lt(r,0)) return a;

  if (gt(r,1)) return b; return a + (b-a)*r;}


ld id0(pt a, pt b, pt c) {
  return sqrt(dist2(c, id16(a, b, c)));}


ld id10(pt a, pt b, pt c) {
  return sqrt(dist2(c, id11(a, b, c)));}


bool LinesParallel(pt a, pt b, pt c, pt d) { 
  return eq(cross(b-a, c-d),0); }
bool id17(pt a, pt b, pt c, pt d) { 
  return LinesParallel(a, b, c, d) && eq(cross(a-b, a-c),0) && eq(cross(c-d, c-a),0);}


bool SegmentsIntersect(pt a, pt b, pt c, pt d) {
  if (id17(a, b, c, d)) {
    

    if(eq(dist2(a,c),0)||eq(dist2(a,d),0)||eq(dist2(b,c),0)||eq(dist2(b,d),0)) return true;
    if(gt(dot(c-a,c-b),0)&&gt(dot(d-a,d-b),0)&&gt(dot(c-b,d-b),0)) return false;
    return true;}
  if(gt(cross(d-a,b-a)*cross(c-a,b-a),0)) return false;

  if(gt(cross(a-c,d-c)*cross(b-c,d-c),0)) return false;

  return true;}






pt id13(pt a,pt b,pt c,pt d){
  b=b-a;d=c-d;c=c-a;

  assert(gt(dot(b, b),0)&&gt(dot(d, d),0));
  return a + b*cross(c, d)/cross(b, d);}


bool between(pt a,pt b,pt c){
  if(!eq(cross(b-a,c-b),0))return 0;

  return le(dot(b-a,b-c),0);
}


pt id5(pt a,pt b,pt c,pt d){
  if(!SegmentsIntersect(a,b,c,d))return {INF,INF};

  

  if(id17(a,b,c,d)){if(between(a,c,b))return c;if(between(c,a,d))return a;return b;}
  return id13(a,b,c,d);
}


pt id19(pt a,pt b,pt c){
  b=(a+b)/2;c=(a+c)/2;
  return id13(b,b+id15(a-b),c,c+id15(a-c));}






bool id21(const vector<pt> &p,pt q){
  int n=p.size(),id14=0;
  for(int i=0;i<n;++i){
    if(eq(dist2(q,p[i]),0)) return 1;

    int j=(i+1)%n;
    if(eq(p[i].y,q.y)&&eq(p[j].y,q.y)) {

      if(le(min(p[i].x,p[j].x),q.x)&&le(q.x,max(p[i].x, p[j].x))) return 1;}

    else {
      bool below=lt(p[i].y,q.y);
      if(below!=lt(p[j].y,q.y)) {
        auto orientation=orient(q,p[j],p[i]);
        if(orientation==0) return 1;

        if(below==(orientation>0)) id14+=below?1:-1;}}}
  return id14==0?0:1;
}


bool id7(const vector<pt> &p,pt q) {
  for (int i = 0; i < p.size(); i++)
    if (eq(dist2(id16(p[i],p[(i+1)%p.size()],q),q),0)) return true;
  return false;}




ld id6(const vector<pt> &p) {
  ld ans=0;
  for(int i = 0; i < p.size(); i++) {
    int j = (i+1) % p.size();
    ans+=cross(p[i],p[j]);
  } return ans / 2.0;}
ld ComputeArea(const vector<pt> &p) {
  return fabs(id6(p));
}




vector<pt> id4(pt a, pt b, pt c, ld r) {
  vector<pt> ret;
  b = b-a;a = a-c;
  ld A = dot(b, b),B = dot(a, b),C = dot(a, a) - r*r,D = B*B - A*C;
  if (lt(D,0)) return ret;	

  ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);
  if (gt(D,0)) ret.push_back(c+a+b*(-B-sqrt(D))/A);
  return ret;}





vector<pt> id9(pt a, pt b, ld r, ld R) {
  vector<pt> ret;
  ld d = sqrt(dist2(a, b)),d1=dist2(a,b);
  pt inf(INF,INF);
  if(eq(d1,0)&&eq(r,R)){ret.pb(inf);return ret;}

  if(gt(d,r+R) || lt(d+min(r, R),max(r, R)) ) return ret;  
  ld x = (d*d-R*R+r*r)/(2*d),y = sqrt(r*r-x*x);
  pt v = (b-a)/d;
  ret.push_back(a+v*x + id8(v)*y);
  if (gt(y,0)) ret.push_back(a+v*x - id8(v)*y);
  return ret;}
ld id12(pt c1,ld r1,pt c2,ld r2){
	if(lt(r1,r2))swap(c1,c2),swap(r1,r2);
	ld d=dist2(c1,c2),d1=dist(c1,c2);
	if(le(r1+r2,d1))return 0;
	if(ge(r1-r2,d1))return PI*r2*r2;
	ld alfa=acos((d+r1*r1-r2*r2)/(2*d1*r1));
	ld beta=acos((d+r2*r2-r1*r1)/(2*d1*r2));
	return alfa*r1*r1+beta*r2*r2-sin(2*alfa)*r1*r1/2-sin(2*beta)*r2*r2/2;}




pt id20(const vector<pt> &p) {
  pt c(0,0),inf(INF,INF);
  ld scale = 6.0 * id6(p);
  if(p.empty())return inf;

  if(eq(scale,0))return inf;

  for (int i = 0; i < p.size(); i++){
    int j = (i+1) % p.size();
    c = c + (p[i]+p[j])*cross(p[i],p[j]);}
  return c / scale;}


bool IsSimple(const vector<pt> &p) {
  for (int i = 0; i < p.size(); i++) {
    for (int k = i+1; k < p.size(); k++) {
      int j = (i+1) % p.size();
      int l = (k+1) % p.size();
      if (i == l || j == k) continue;
      if (SegmentsIntersect(p[i], p[j], p[k], p[l])) 
        return false;}}
  return true;}

int id1(vector<pt>& poly,pt point, int top) {
	if (point < poly[0] || point > poly[top]) return 1;

	auto orientation = orient(point, poly[top], poly[0]);
	
	if (orientation == 0) {
		if (point == poly[0] || point == poly[top]) return 0;
		return top == 1 || top + 1 == poly.size() ? 0 : -1;

		

	} else if (orientation < 0) {
		auto itRight = lower_bound(poly.begin() + 1, poly.begin() + top, point);
		return orient(itRight[0], point, itRight[-1]);
  	} else {
		auto itLeft = upper_bound(poly.rbegin(), poly.rend() - top-1, point);
		return (orient(itLeft == poly.rbegin() ? poly[0] : itLeft[-1], point, itLeft[0]));
  	}
}

ld id2(vector<pt>& poly) {
	int n = poly.size();
	ld res=0;
	for (int i = 0, j = n < 2 ? 0 : 1; i < j; ++i)
		for (;; j = j+1 %n) {
	  		res = max(res, dist2(poly[i], poly[j]));
	  	if (gt(cross(poly[j+1 % n] - poly[j],poly[i+1] - poly[i]),0)) break;
	}
	return res;
}









inline bool cmp_x(pt a,pt b){
    return (lt(a.x,b.x) || (eq(a.x,b.x) && lt(a.y,b.y)));
}
inline int ccw(pt a,pt b,pt c){
    F2 d=((b-a)^(c-a));
    if (d==0) return 0;
    if (d<0) return -1;
    return 1;
}


struct id18{
    vector<pt> down;
    vector<pt> up;
    int n=0;
    id18(): n(0ll) {};
    id18(vector<pt> points,bool issort=false){
        down=points;
        if (!issort) sort(all(down),cmp_x);
        n=down.size();
        up.resize(n);
        For(i,n) up[i]=down[i];
        build();
    }
    id18 operator = (const id18& a){
        down=a.down;
        n=down.size();
        up=a.up;
        return *this;
    }
    void build(){
        int m=0;
        if (n<=1){
        	return;
        }
        For(i,n){
            while (m>1 && ccw(down[m-2],down[m-1],down[i])<=0) --m;
            down[m++]=down[i];
        }
        down.resize(m);
        m=0; 

        For(i,n){
            while(m>1 && ccw(up[m-2],up[m-1],up[i])>=0) --m;
            up[m++]=up[i];
        }
        up.resize(m);
        n=m;
    }
    void clear(){
        down.clear();
        up.clear();
        n=0;
    }
    id18 merger(const id18& a) const {
        vector<pt> points(a.down.size()+down.size());
        merge(down.begin(),down.end(),a.down.begin(),a.down.end(),points.begin());
        id18 b(points,true);
        return b;
    }
    vector<pt> All(){
    	vector<pt> cu=down;
    	for(int i=(int)up.size()-2;i>0;--i) cu.pb(up[i]);
    	return cu;
    }
    ll min(ld x){
        if (n==0) return INF;
        int low=0,high=n-1;
        pt line={x,1};
        while (low<high){
            int mid=(low+high)/2;
            if (down[mid]*line<down[mid+1]*line){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return down[low]*line;
    }
    friend ostream& operator << (ostream& os, const id18& p) {return os<<"{"<<p.n<<" : "<<p.down<<"}";}
};
void solve(){
    int n;
    vector<pt> A;
    cin>>n;
    pt x;
    
    For(i,n){
        cin>>x;
        A.pb(x);
    }
    if (orient(A[0],A[1],A[2])==1){
        reverse(all(A));
    }
    

    vector<pt> tmp;
    

    

    

    

    int idx=0;
    

    for(int i=1;i<n;++i){
        if (A[i]<A[idx]){
            idx=i;
        }
    }
    

    for(int i=idx;i<n;++i) tmp.pb(A[i]);
    for(int i=0;i<idx;++i) tmp.pb(A[i]);
    A.swap(tmp);
    int top=0;
    for(int i=1;i<n;++i){
        if (A[i]>A[top]) top=i;
    }
    
    

    
    int m;
    cin>>m;
    bool pos=1;
    vector<pt> B;
    For(i,m){
        cin>>x;
        B.pb(x);
        
        if (id1(A,x,top)>=0) {pos=0;break;}
    }
    if (pos) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    
}
signed main(){
    

    

   
    fio;
    int t=1;
    

    while(t--) {
        solve();
    }
}