














































using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef set<int> seti;
typedef pair<double, double> pdd;
typedef long double ld;

const double EPS=0.000000001;
const double id1=1000000000;
const ll INF64=1000000000000000000;
const int INF32=1000000000;



struct pt{
    int x,y;
    pt(int x,int y){x=x,y=y;}
    pt(){}
};

bool operator < (pt a,pt b){
    return (a.x<b.x) || (a.x==b.x && a.y<b.y);
}

bool cw(pt a,pt b,pt c){
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)<0;
}

vector <pt> id0(vector <pt> a){
    SORT(a);
    pt p1=a.front(),p2=a.back();
    vector <pt> up;
    up.push_back(p1);
    for (int i=1; i<a.size(); ++i){
        if (i==a.size()-1 || cw(p1,a[i],p2)){
            while (up.size()>1 && !cw(up[up.size()-2],up.back(),a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
    }
   

    return up;
}

signed main(void){
    

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int  n;
    cin>>n;
    vector <pt> VEC;
    VEC.resize(n);
    

    for (int i=0; i<n; ++i){
        cin>>VEC[i].x>>VEC[i].y;
        VEC[i].y-=VEC[i].x*VEC[i].x;
        

    }

    VEC=id0(VEC);
    int k = VEC.size();
    int ans = k-1;
    for (int i = 0; i<k-1; i++) if (VEC[i].x==VEC[i+1].x) ans--;
    cout<<ans<<en;

}




