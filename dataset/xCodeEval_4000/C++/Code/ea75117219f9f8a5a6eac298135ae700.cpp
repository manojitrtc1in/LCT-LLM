




#pragma GCC optimize("O3")
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <stack>
#include <ctime>
#include <iomanip>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <bitset>






#define en "\n"
#define sqrt(n) sqrt((long double) n)
#define all(c) (c).begin() , (c).end()
#define MOD 1000000007
#define mem0(a) memset(a,0,sizeof(a))
#define FAST() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define elif else if
#define int long long
#define SORT(x) sort(all(x))
#define REVERSE(x) reverse(all(x))


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
const double INFD32=1000000000;
const ll INF64=1000000000000000000;
const int INF32=1000000000;

#define maxN 300300

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

vector <pt> convex_hull(vector <pt> a){
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

    VEC=convex_hull(VEC);
    int k = VEC.size();
    int ans = k-1;
    for (int i = 0; i<k-1; i++) if (VEC[i].x==VEC[i+1].x) ans--;
    cout<<ans<<en;

}




