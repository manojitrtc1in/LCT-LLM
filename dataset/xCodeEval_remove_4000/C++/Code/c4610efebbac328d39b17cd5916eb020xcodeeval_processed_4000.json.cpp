

using namespace std;


































template <class T> inline T bigmod(T p,T e,T M){ll ret = 1;for(; e > 0; e >>= 1){if(e & 1) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   

template <class T> inline T bpow(T p,T e){ll ret = 1;for(; e > 0; e >>= 1){if(e & 1) ret = (ret * p);p = (p * p);}return (T)ret;}

int toInt(string s){int sm;stringstream ss(s);ss>>sm;return sm;}
int id0(string s){long long int sm;stringstream ss(s);ss>>sm;return sm;}


























int ts,kk=1;





const double eps=1e-8;
const double pi=acos(-1.0);
const double inf=1e20;
const int maxp=1111;
int dblcmp(double d)
{
    if (fabs(d)<eps)return 0;
    return d>eps?1:-1;
}
inline double sqr(double x){return x*x;}

struct point
{
    double x,y;
    point()             {                                    }
    point(double _x,double _y){    x = _x; y = _y;           }
    void input()        {   scanf("%lf%lf",&x,&y);           }
    void output()       {   printf("%.2f %.2f\n",x,y);       }
    bool operator==(point a)const{
        return dblcmp(a.x - x) == 0 && dblcmp(a.y - y) == 0;
    }
    bool operator<(point a)const{
        return dblcmp(a.x - x) == 0 ? dblcmp(y - a.y) < 0 : x < a.x;
    }
    point operator-(point a)const{
		return point(x-a.x, y-a.y);
	}
    double len()        {   return hypot(x, y);              }
    double len2()       {   return x * x + y * y;            }
    double distance(point p){return hypot(x - p.x, y - p.y); }
    point add(point p)  {   return point(x + p.x, y + p.y);  }
    point sub(point p)  {   return point(x - p.x, y - p.y);  }
    point mul(double b) {   return point(x * b, y * b);      }
    point div(double b) {   return point(x / b, y / b);      }
    double dot(point p) {   return x*p.x+y*p.y;              }
    double det(point p) {   return x*p.y-y*p.x;              }
    double rad(point a,point b){
        point p=*this;
        return fabs(atan2(fabs(a.sub(p).det(b.sub(p))),a.sub(p).dot(b.sub(p))));
    }
    point trunc(double r){
        double l=len();
        if (!dblcmp(l))return *this;
        r/=l;
        return point(x*r,y*r);
    }
    point rotleft()     {   return point(-y,x);              }
    point rotright()    {   return point(y,-x);              }
    point rotate(point p,double angle){
        point v=this->sub(p);
        double c=cos(angle),s=sin(angle);
        return point(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
    }
};


struct line
{
    point a,b;
    line()              {                                    }
    line(point _a,point _b){ a=_a; b=_b;                     }
    bool operator==(line v){ return (a==v.a)&&(b==v.b);      }
    line(point p,double angle){
        a=p;
        if (dblcmp(angle-pi/2)==0){
            b=a.add(point(0,1));
        }else{
            b=a.add(point(1,tan(angle)));
        }
    }
    

    line(double _a,double _b,double _c){
        if (dblcmp(_a)==0){
            a=point(0,-_c/_b);
            b=point(1,-_c/_b);
        }else if (dblcmp(_b)==0){
            a=point(-_c/_a,0);
            b=point(-_c/_a,1);
        }else{
            a=point(0,-_c/_b);
            b=point(1,(-_c-_a)/_b);
        }
    }
    void input()        {   a.input(); b.input();            }
    void adjust()       {   if(b<a)swap(a,b);                }
    double length()     {   return a.distance(b);            }
    double angle(){
        double k=atan2(b.y-a.y,b.x-a.x);
        if (dblcmp(k)<0)k+=pi;
        if (dblcmp(k-pi)==0)k-=pi;
        return k;
    }
    int relation(point p){
        int c=dblcmp(p.sub(a).det(b.sub(a)));
        if (c<0)return 1;
        if (c>0)return 2;
        return 3;
    }
    bool pointonseg(point p){
        return dblcmp(p.sub(a).det(b.sub(a)))==0&&dblcmp(p.sub(a).dot(p.sub(b)))<=0;
    }
    bool parallel(line v){
        return dblcmp(b.sub(a).det(v.b.sub(v.a)))==0;
    }
    int segcrossseg(line v){
        int d1=dblcmp(b.sub(a).det(v.a.sub(a)));
        int d2=dblcmp(b.sub(a).det(v.b.sub(a)));
        int d3=dblcmp(v.b.sub(v.a).det(a.sub(v.a)));
        int d4=dblcmp(v.b.sub(v.a).det(b.sub(v.a)));
        if ((d1^d2)==-2&&(d3^d4)==-2)return 2;
        return (d1==0&&dblcmp(v.a.sub(a).dot(v.a.sub(b)))<=0||
			d2==0&&dblcmp(v.b.sub(a).dot(v.b.sub(b)))<=0||
			d3==0&&dblcmp(a.sub(v.a).dot(a.sub(v.b)))<=0||
			d4==0&&dblcmp(b.sub(v.a).dot(b.sub(v.b)))<=0);
    }
    int segcrossseg_inside(line v){
		if(v.pointonseg(a) || v.pointonseg(b) || pointonseg(v.a) || pointonseg(v.b)) return 0;
        int d1=dblcmp(b.sub(a).det(v.a.sub(a)));
        int d2=dblcmp(b.sub(a).det(v.b.sub(a)));
        int d3=dblcmp(v.b.sub(v.a).det(a.sub(v.a)));
        int d4=dblcmp(v.b.sub(v.a).det(b.sub(v.a)));
        if ((d1^d2)==-2&&(d3^d4)==-2)return 1;
        return (d1==0&&dblcmp(v.a.sub(a).dot(v.a.sub(b)))<=0||
			d2==0&&dblcmp(v.b.sub(a).dot(v.b.sub(b)))<=0||
			d3==0&&dblcmp(a.sub(v.a).dot(a.sub(v.b)))<=0||
			d4==0&&dblcmp(b.sub(v.a).dot(b.sub(v.b)))<=0);
    }
    int linecrossseg(line v){

        int d1=dblcmp(b.sub(a).det(v.a.sub(a)));
        int d2=dblcmp(b.sub(a).det(v.b.sub(a)));
        if ((d1^d2)==-2)return 2;
        return (d1==0||d2==0);
    }
    int linecrossline(line v){
        if ((*this).parallel(v)){
            return v.relation(a)==3;
        }
        return 2;
    }
    point crosspoint(line v){
        double a1=v.b.sub(v.a).det(a.sub(v.a));
        double a2=v.b.sub(v.a).det(b.sub(v.a));
        return point((a.x*a2-b.x*a1)/(a2-a1),(a.y*a2-b.y*a1)/(a2-a1));
    }
    double dispointtoline(point p){
        return fabs(p.sub(a).det(b.sub(a)))/length();
    }
    double dispointtoseg(point p){
        if (dblcmp(p.sub(b).dot(a.sub(b)))<0||dblcmp(p.sub(a).dot(b.sub(a)))<0){
            return min(p.distance(a),p.distance(b));
        }
        return dispointtoline(p);
    }
    point lineprog(point p){
        return a.add(b.sub(a).mul(b.sub(a).dot(p.sub(a))/b.sub(a).len2()));
    }
    point symmetrypoint(point p){
        point q=lineprog(p);
        return point(2*q.x-p.x,2*q.y-p.y);
    }
};

typedef pair<ll, ll> Point;

bool cw(const Point &a, const Point &b, const Point &c) {
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first) < 0;
}

vector<Point> id1(vector<Point> p) {
    int n = p.size();
    if (n <= 1)
        return p;
    sort(p.begin(), p.end());
    int cnt = 0;
    vector<Point> q(n * 2);
    for (int i = 0; i < n; q[cnt++] = p[i++])
        for (; cnt >= 2 && !cw(q[cnt - 2], q[cnt - 1], p[i]); --cnt)
            ;
    for (int i = n - 2, t = cnt; i >= 0; q[cnt++] = p[i--])
        for (; cnt > t && !cw(q[cnt - 2], q[cnt - 1], p[i]); --cnt)
            ;
    q.resize(cnt - 1 - (q[0] == q[1]));
    return q;
}
vector < Point > vc, vp;
LL area(Point p1, Point p2, Point p3){
    LL ret = (p1.xx*p2.yy + p2.xx*p3.yy + p3.xx*p1.yy) - (p1.yy*p2.xx + p2.yy*p3.xx + p3.yy*p1.xx);
    if(ret < 0) ret *= -1;
    return ret;
}

ll S;
int n;
int qx[2][5005][5005];

Point ra,rb,rc;
ll mx;

ll dx[]={0,0,-1,1,1,1,-1,-1};
ll dy[]={-1,1,0,0,-1,1,1,-1};

bool chk(Point a,Point b,Point c)
{
    int i;
    ll qq=area(a,b,c);
    if(qq>S*4LL)return 0;
    f(i,vc.size())
    {
        ll qx=area(a,b,vc[i]);
        qx+=area(a,c,vc[i]);
        qx+=area(c,b,vc[i]);
        if( qx!=qq )return 0;
    }
    cout<<a.xx<<" "<<a.yy<<endl;
    cout<<b.xx<<" "<<b.yy<<endl;
    cout<<c.xx<<" "<<c.yy<<endl;
    exit(0);
    return 1;
}

void clc(int a,int b,int c)
{
    point pa,pb,pc;
    line ab,bc,ca;
    pa=point(vc[a].xx,vc[a].yy);
    pb=point(vc[b].xx,vc[b].yy);
    pc=point(vc[c].xx,vc[c].yy);
    ab=line(pa,pb);
    bc=line(pb,pc);
    ca=line(pc,pa);
























    int q1,q2,q3;
    q1=a;
    q2=qx[0][a][b];
    q3=b;
    if(area(vc[q1],vc[q2],vc[q3])){
        ab=line(point(vc[q2].xx,vc[q2].yy),ab.angle());
    }

    q1=b;
    q2=qx[0][b][c];
    q3=c;
    if(area(vc[q1],vc[q2],vc[q3])){
        bc=line(point(vc[q2].xx,vc[q2].yy),bc.angle());
    }

    q1=a;
    q2=c;
    q3=qx[1][a][c];
    if(area(vc[q1],vc[q2],vc[q3])){
        ca=line(point(vc[q3].xx,vc[q3].yy),ca.angle());
    }


    pa=ab.crosspoint(ca);
    pb=ab.crosspoint(bc);
    pc=bc.crosspoint(ca);

    Point qa,qb,qc;
    qa=pll(pa.x,pa.y);
    qb=pll(pb.x,pb.y);
    qc=pll(pc.x,pc.y);
    if(area(qa,qb,qc)==0)return ;

    int i,j,k;
    f(i,8)
    {
        qa.xx+=dx[i];
        qa.yy+=dy[i];
        f(j,8)
        {
            qb.xx+=dx[j];
            qb.yy+=dy[j];
            f(k,8)
            {
                qc.xx+=dx[k];
                qc.yy+=dy[k];
                if(chk(qa,qb,qc))
                {
                    ll qq=area(qa,qb,qc);
                    if(qq>=S&&qq<=4*S&&qq>mx)
                    {
                        mx=qq;
                        ra=qa;
                        rb=qb;
                        rc=qc;


                    }
                }
                qc.xx-=dx[k];
                qc.yy-=dy[k];

            }
            qb.xx-=dx[j];
            qb.yy-=dy[j];
        }
        qa.xx-=dx[i];
        qa.yy-=dy[i];
    }

    ll qq=area(qa,qb,qc);
    if(chk(qa,qb,qc)&&qq>=S&&qq<=4*S&&qq>mx)
    {
        mx=qq;
        ra=qa;
        rb=qb;
        rc=qc;
    }
}

int main()
{




    int t,i,j,k,c,d;

    cin>>n>>S;

    f(i,n)
    {
        sc2(j,k);
        vp.pb(pll(j, k));
    }
    vc = id1(vp);
    n=vc.size();
    if(n==3)
    {
        f(i,n)cout<<vc[i].xx<<" "<<vc[i].yy<<endl;
        return 0;
    }
    S*=2LL;


    for(i = 0; i < vc.size(); i++){


        c = i; d = i + 1;
        for(j = i+1; j < vc.size(); j++){
            while(c < j && area(vc[i], vc[j], vc[c]) <= area(vc[i], vc[j], vc[c+1])) c++;
            while(d < vc.size() - 1 && area(vc[i], vc[j], vc[d]) <= area(vc[i], vc[j], vc[d+1])) d++;
            qx[0][i][j]=c;
            qx[1][i][j]=d;


        }
    }

    mx=0;
    f(i,n)
    {
        fl(i+1,j,n)
        {
            if(area(vc[i],vc[qx[0][i][j]],vc[j]))clc(i,qx[0][i][j],j);
            if(area(vc[i],vc[j],vc[qx[1][i][j]]))clc(i,j,qx[1][i][j]);
        }
    }



    cout<<ra.xx<<" "<<ra.yy<<endl;
    cout<<rb.xx<<" "<<rb.yy<<endl;
    cout<<rc.xx<<" "<<rc.yy<<endl;

    return 0;
}



