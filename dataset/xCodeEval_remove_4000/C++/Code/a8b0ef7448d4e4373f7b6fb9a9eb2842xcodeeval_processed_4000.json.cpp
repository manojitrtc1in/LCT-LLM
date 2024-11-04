












using namespace std;
typedef long long ll;
inline void read(int &a);
const int maxn=1e4+10;
const int N =1e3+10;
const int inf=0x3f3f3f3f;
const int mnf=0x1f1f1f1f;
const double eps = 1e-6;
const double pi= acos(-1.0);
int sgn(double a){return a<-eps?-1:a>eps;}
int id4(double a,double b){return sgn(a-b);}
int gcd(int a,int b) {return (b==0?a:gcd(b,a%b));}

struct ball{
    double x,y,z,r;
};
double id3(ball a,ball b){
    double ans = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
    return ans;
}
double ar3(ball a){
    double ans=(4.0/3)*pi*a.r*a.r*a.r;
    return ans;
}
double Uball(ball a,ball b){

    double ans=0;
    double d=id3(a,b);
    if(sgn(d-a.r-b.r)>=0){
        ans=ar3(a)+ar3(b);
    }
    else if(d<=abs(a.r-b.r)){
        ans=max(ar3(a),ar3(b));
    }
    else{
        double c = (a.r*a.r+d*d-b.r*b.r)/(2.0*d*a.r);
        double h = a.r*(1-c);
        ans+=(1.0/3)*pi*(3*a.r-h)*h*h;
        c = (b.r*b.r+d*d-a.r*a.r)/(2.0*d*b.r);
        h= b.r*(1-c);
        ans+=(1.0/3)*pi*(3*b.r-h)*h*h;

        ans=ar3(a)+ar3(b)-ans;

    }
    return ans;
}


struct point{
    double x,y;
    point() {}
    point(double _x,double _y){
        x = _x;
        y = _y;
    }
    point operator -(const point &b)const{
        return point(x - b.x,y - b.y);
    }
    double operator ^(const point &b)const{

        return x*b.y - y*b.x;
    }
    double operator *(const point &b)const{

        return x*b.x + y*b.y;
    }
    bool operator < (point p) const{
        int c=id4(x,p.x);
        if(c) return c==-1;
        return id4(y,p.y)==-1;
    }
    bool operator == (point o) const {
        return id4(x,o.x)==0&&id4(y,o.y)==0;
    }
    void transXY(double B){

        double tx = x,ty = y;
        x = tx*cos(B) - ty*sin(B);
        y = tx*sin(B) + ty*cos(B);
    }
    void input(){
        scanf("%lf%lf",&x,&y);
    }
};
struct line{
    point s,e;
    line() {}
    line(point _s,point _e){
        s = _s;
        e = _e;
    }








    bool operator <(line &l) const{

        if(e.x==l.e.x) return s.x<l.s.x;
        return e.x<l.e.x;
    }




    pair<int,point> operator &(const line &b)const{
        point res = s;
        if(sgn((s-e)^(b.s-b.e)) == 0)
        {
            if(sgn((s-b.e)^(b.s-b.e)) == 0)
                return make_pair(0,res);

            else return make_pair(1,res);

        }
        double t = ((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
        res.x += (e.x-s.x)*t;
        res.y += (e.y-s.y)*t;
        return make_pair(2,res);
    }
};
struct triangle{
    point v[3];
};
struct circle{
    point center;
    double r;
    circle(){}
    circle (point p,double _r){
        center=p;
        r=_r;
    }
    point Point (double a){
        return point(center.x+cos(a)*r,center.y+sin(a)*r);
    }
};
double dist(point a,point b){return sqrt((a-b)*(a-b));}
bool inter(line l1,line l2);

bool id0(line l1,line l2);

double id7(point P, point A, point B);

point id1(point P,line L);

point id2(point P, point A, point B);

bool OnSeg(point P,line L);



double ar2(triangle a){return fabs(0.5*cross(a.v[0],a.v[1],a.v[2]));}
circle outtriangle(triangle t);

circle CroCircle(int n);

int circleIntersection(circle c1,circle c2);

ball CroBall(int n);

double alpha(line l){return atan2(l.e.y-l.s.y,l.e.x-l.s.x);}



int cmpgra(point a,point b);

int graham(int n);

int id5(point a,point p[],int n);

double calipers(int t);


double polygon_area(point *p, int n);

point polygon_center(int n);






point p[maxn],s[maxn];

ball bl[maxn];







































struct sox {int left, right, id;};
bool operator < (sox &Key1, sox &Key2) {return Key1.left == Key2.left ? Key1.right > Key2.right : Key1.left < Key2.left;}
int n,m;
point polygon[maxn];
point light[maxn];
int tot;
sox Sec[maxn];
vector<int> ans, buffer;
void slic(){
    tot=0;
    for (int i=0;i<m;i++) {
        int left=0;
        for (int j=0;j<n;j++)
            if (sgn((polygon[(j + 1)%n]-polygon[j])^(polygon[j]-light[i]))>0 && sgn((polygon[j]-polygon[(j-1+n)%n]) ^ (polygon[(j-1+n)%n]-light[i]))<=0) left=j;
        int right=left;
        while (right<=n+left) {
            if (sgn((polygon[(right+1)%n]-polygon[right%n])^(polygon[right%n]-light[i]))<=0) break;
            right++;
        }
        Sec[tot++]=(sox){left,right,i};
    }
        sort(Sec,Sec+tot);
}

void id6() {
    ans.clear();
    for (int start=0;start<tot;start++) {
        buffer.clear();
        int cur=start;
        buffer.push_back(Sec[cur].id);
        while (Sec[cur].right<Sec[start].left+n) {
            int last=Sec[cur].right;
            for (int j=start+1; j<tot && Sec[j].left <= last;j++) {
                if (Sec[j].right>Sec[cur].right) cur=j;
            }
            if (Sec[cur].right==last) break;
            buffer.push_back(Sec[cur].id);
        }
        if (Sec[cur].right>=Sec[start].left+n && ((int)ans.empty() || (int)buffer.size() < (int)ans.size())) ans.assign(buffer.begin(), buffer.end());
    }
}
long long a[maxn],b[maxn],sum[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);




    int n,h;cin>>n>>h;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(!i)sum[i]=a[i];
        else sum[i]=sum[i-1]+a[i];
    }
    int ans=1,t=-1;
    for(int i=n-1;i>=0;i--){
        if(sum[i]<=2*h) {t=i+1;break;}
    }
    

    for(int i=t;i>0;i--){
        for(int j=0;j<i;j++) b[j]=a[j];
        sort(b,b+i);
        long long  fuck=0;
        for(int j=i-1;j>=0;j-=2){
            fuck+=b[j];
            

            

        }
        

        if(fuck<=h){
            cout<<max(i,1)<<'\n';
            return 0;
        }
    }
    cout<<1<<'\n';
    return 0;
}

inline void read(int &a){
static char c;
bool flag=false;
while (((c=getchar())<'0'||c>'9'))flag=1;a=c-'0';
while ((c=getchar())>='0'&&c<='9') a=(a<<3)+(a<<1)+c-'0';if(flag)a=-a;}




























































bool id0(line l1,line l2){
    return sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0;
}
double id7(point P, point A, point B){
   return fabs(cross(A,B,P)/dist(A,B));
}
point id2(point P, point A, point B){
    point v = B-A;
    double x=v*(P-A)/(v*v);
    v.x=v.x*x+A.x;v.y=v.y*x+A.y;return v;
}
point id1(point P,line L){
    point result;
    double t = ((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));
    if(t >= 0 && t <= 1)
    {
        result.x = L.s.x + (L.e.x - L.s.x)*t;
        result.y = L.s.y + (L.e.y - L.s.y)*t;
    }
    else
    {
        if(dist(P,L.s) < dist(P,L.e))
            result = L.s;
        else result = L.e;
    }
    return result;
}
bool OnSeg(point P,line L){
    return
        sgn((L.s-P)^(L.e-P)) == 0 &&
        sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
        sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}
circle outtriangle(triangle t){
    circle tmp;
    double a = dist(t.v[0],t.v[1]);
    double b = dist(t.v[0],t.v[2]);
    double c = dist(t.v[1],t.v[2]);
    tmp.r=a*b*c/4/ar2(t);
    double a1=t.v[1].x-t.v[0].x;
    double b1=t.v[1].y-t.v[0].y;
    double c1=(a1*a1+b1*b1)/2;
    double a2=t.v[2].x-t.v[0].x;
    double b2=t.v[2].y-t.v[0].y;
    double c2=(a2*a2+b2*b2)/2;
    double d=a1*b2-a2*b1;
    tmp.center.x=t.v[0].x+(c1*b2-c2*b1)/d;
    tmp.center.y=t.v[0].y+(a1*c2-a2*c1)/d;
    return tmp;
}
circle CroCircle(int n){
    random_shuffle(p+1,p+n+1);
    circle tep;
    tep.center=p[1];
    tep.r=0;
    for(int i=2;i<=n;i++){
        if(dist(p[i],tep.center)>tep.r+eps){
            tep.center=p[i];
            tep.r=0;
            for(int j=1;j<i;j++){
                if(dist(p[j],tep.center)>tep.r+eps){
                    tep.center.x=(p[i].x+p[j].x)/2;
                    tep.center.y=(p[i].y+p[j].y)/2;
                    tep.r=dist(p[i],p[j])/2;
                    for(int k=1;k<j;k++){
                        if(dist(p[k],tep.center)>tep.r+eps){
                            triangle t;
                            t.v[0]=p[i];
                            t.v[1]=p[j];
                            t.v[2]=p[k];
                            tep=outtriangle(t);}}}}}}
    return tep;
}
ball CroBall(int n){
    double step=100,mt;
    int s=0;
    ball z;
    z.x=z.y=z.z=0;
    z.r=1e30;
    while(step>eps){
        for(int i=1;i<=n;i++)
            if(id3(z,bl[s])<id3(z,bl[i])) s=i;
        mt=id3(z,bl[s]);
        z.r=min(z.r,mt);
        z.x+=(bl[s].x-z.x)/mt*step;
        z.y+=(bl[s].y-z.y)/mt*step;
        z.z+=(bl[s].z-z.z)/mt*step;
        step*=0.98;
    }
    return z;
}
bool inter(line l1,line l2){
    return
        max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
        max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
        max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
        max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
        sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0 &&
        sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e)) <= 0;}
int cmpgra(point a,point b){
    double x = cross(p[1],a,b);
    if(x>0) return 1;

    if(x==0&&dist(a,p[1])<dist(b,p[1])) return 1;

    return 0;
}
int graham(int n){












    int k=1;
    for(int i=2;i<=n;i++)
        if(p[i].y<p[k].y||(p[i].y==p[k].y&&p[i].x<p[k].x))k=i;
    swap(p[1],p[k]);

    sort(p+2,p+1+n,cmpgra);
    s[1]=p[1];s[2]=p[2];
    int t=2;
    for(int i=3;i<=n;i++){

        while(t>=2&&cross(s[t-1],s[t],p[i])<=0) t--;
        s[++t]=p[i];
    }
    return t;
}















int id5(point a,point p[],int n){
    for(int i = 1; i < n; i++){
        if(sgn((p[i]-a)^(p[i+1]-a)) < 0)return -1;
        else if(OnSeg(a,line(p[i],p[i+1])))return 0;
    }
    if(sgn((p[n]-a)^(p[1]-a)) < 0)return -1;
    else if(OnSeg(a,line(p[n],p[1])))return 0;
    return 1;
}

double polygon_area(point *p, int n){
    if(n < 3) return 0;

    double sum = 0;
    p[n + 1] = p[1];
    for(int i = 1; i <= n; i++)
        sum += p[i].x * p[i + 1].y - p[i].y * p[i + 1].x;

    sum = fabs(sum / 2.0);
    return sum;
}

point polygon_center(int n){
    double S=0,X=0,Y=0;
    for(int i=2;i<n;i++){
        double x=(p[i]-p[1])^(p[i+1]-p[1]);

        X+=(p[1].x+p[i].x+p[i+1].x)*x;

        Y+=(p[1].y+p[i].y+p[i+1].y)*x;
        S+=x;
    }
    point ans;
    ans.x=X/S/3.0;ans.y=Y/S/3.0;
    return ans;
}
































