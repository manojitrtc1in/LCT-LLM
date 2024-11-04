











































using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef set<int> seti;
typedef pair<double, double> pdd;

const double EPS=0.000000001;
const ll INF64=1000000000000000000;
const int INF32=2000000000;
const double id0=1000000000;



bool id1(pii a,pii b,pii c,pii point){
    int x1=a.first,x2=b.first,x3=c.first,x0=point.first;
    int y1=a.second,y2=b.second,y3=c.second,y0=point.second;
    int aa=(x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0);
    int bb=(x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0);
    int cc=(x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0);
    if (aa==0 || bb==0 || cc==0) return 1;
    if (aa>=0 && bb>=0 && cc>=0) return 1;
    if (aa<=0 && bb<=0 && cc<=0) return 1;
    return 0;
}



vector <pdd> inser(double r, double a, double b, double c){
    vector<pdd> ans;
    double x0 = -a*c/(a*a+b*b),  y0 = -b*c/(a*a+b*b);
    if (c*c > r*r*(a*a+b*b)+EPS)
    {}
    else if (abs (c*c - r*r*(a*a+b*b)) < EPS) {
        ans.push_back({x0,y0});
    }
    else {
        double d = r*r - c*c/(a*a+b*b);
        double mult = sqrt (d / (a*a+b*b));
        double ax,ay,bx,by;
        ax = x0 + b * mult;
        bx = x0 - b * mult;
        ay = y0 - a * mult;
        by = y0 + a * mult;
        ans.push_back({ax,ay});
        ans.push_back({bx,by});
    }
    return ans;
}

int id2 (double x1, double y1, double x2,double y2,double x3,double y3) {
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}


bool iss_ll(ll &__1,ll &__2){ return INF64/__1>=__2;}
bool equall(double _1,double _2){ return (abs(_1-_2)<EPS);}
bool id3(int __1){ll __2=sqrt(__1); return __2*__2==__1;};
bool iss_prime(ll __1){for (int i=2; i*i<=__1; ++i) if (!(__1%i)) return 0; return 1;}
int gcd(int __1,int __2){ while (__1 && __2) if (__1>__2)  __1=__1%__2; else __2=__2%__1; return __1+__2;}
int lcm(int &__1,int &__2){ return __1*__2/(gcd(__1, __2));}
int sq_cube(ll x){if (x==0) return 0;int l=0,r=2e6;while (l+1<r){int m=(l+r)/2;if (m*m*m>x) r=m;else l=m;}return l;}
int bigprost(){int x=INF32;srand(0);x+=(rand()*rand());while (!iss_prime(x))++x;return x;}

struct dd{
    int val,numb;
};
int n,m;
bool operator < (dd x,dd y){
    if (x.val!=y.val){
        return x.val<y.val;
    }
    if (abs((m+1)/2.0-x.numb)!=abs((m+1)/2.0-y.numb)){
        return (abs((m+1)/2.0-x.numb)<abs((m+1)/2.0-y.numb));
    }
    return x.numb<y.numb;
}
set <dd> SET;
signed main(void){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    dd x;
    for (int i=1; i<=m; ++i){
            x.numb=i;
            x.val=0;
        SET.insert(x);
    }
    for (int i=0; i<n; ++i){
        x=*SET.begin();
        SET.erase(x);
        x.val++;
        SET.insert(x);
        cout<<x.numb<<en;
    }

    return 0;
}




















