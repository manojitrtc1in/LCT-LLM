



#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include<queue>
#include<complex>
using namespace std;




inline long long toint(string s) {long long v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}




template<class T> inline T sqr(T x) {return x*x;}




typedef long long ll;
typedef long long LL;
typedef vector<int > vi;
typedef vector<long long > VLL;
typedef vector<long long > vll;
typedef vector<string > ves;
typedef vector<char > vech;

typedef pair<long long , long long> pll;
typedef pair<long long , long long> PLL;
typedef map<ll , ll >mll;
typedef map<int , int >mii;
typedef map<char , int >mci;
typedef map<char , ll >mcl;
typedef vector<pair<ll , ll> > vpll;





#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define VECMAX(x) *max_element(ALL(x))
#define VECMIN(x) *min_element(ALL(x))
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())




#define FOR(i,a,b) for(long long i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)






const double EPS = 1e-10;
const double PI  = acos(-1.0);


#define CLR(a) memset((a), 0 ,sizeof(a))


#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define SIZEOF(x) sizeof(x)/sizeof(x[0])


const long long INF = 4e18;
const long long NINF = 1 - INF;

#define ENDL cout << endl;
#define CIN(a) REP(i,a.size())cin >> a[i];



struct POINT{
    double x;
    double y;

};



ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }


ll nCr(ll n,  ll r){
  if ( r * 2 > n ) r = n - r;
  ll dividend = 1;
  ll divisor  = 1;
  for ( unsigned int i = 1; i <= r; ++i ) {
    dividend *= (n-i+1);
    divisor  *= i;
  }
  return dividend / divisor;
}





template<class T>
pair<T , ll> maxP(vector<T> a , ll size){
    pair <T , ll> p;
    ll ind = 0;
    T mx = NINF;
    REP(i,size){
        if(mx<a[i]){
            mx = a[i];
            ind = i;
        }
    }
    p.first = mx;
    p.second = ind;
    return p;
}


template<class T>
pair<T , ll> minP(vector<T> a , ll size){
    pair <T , ll> p;
    T mn = INF;
    ll ind = 0;
    REP(i,size){
        if(mn > a[i]){
            mn = a[i];
            ind = i;
        }
    }
    p.first = mn;
    p.second = ind;
    return p;
}

template<class T>
T sumL(vector<T> a , ll size){
    T sum = 0;
    REP(i,size){
        sum += a[i];

    }
    return sum;
}


 

ll counT(VLL a ,ll left , ll right ,  ll t ){
    

    return upper_bound(a.begin() + left , a.begin() + right,t)-lower_bound(a.begin() + left , a.begin() + right, t);
}



ll kiriage(ll a , ll b){
    return a/b + (a%b!=0);
}

#define COUNT(a,b) counT((a),0,a.size(),(b))

#define MAX(x) maxP(x,x.size())
#define MIN(x) minP(x,x.size())
#define SUM(x) sumL(x,x.size())






ll search(vll &a , ll n ){

    std::vector<ll>::iterator iter = std::find(a.begin(), a.end(), n);
    size_t index = distance(a.begin(), iter);
    return index;
}




int getdigit(ll n){
    return log10(n)+1;
}





vll toBinary(ll bina){
    vll ans;
    for (ll i = 0; bina>0 ; i++)
    {
        ans.push_back(bina%2);
        bina = bina/2;
    }
    return ans;
}












































#define ENDL cout << endl;



template<class T>
class SegmentTree {
    ll n;  


    vector<vector<T> > dat;
    vector<T> A;

    public:
    

    SegmentTree(vector<T> a){

        A=a;
        n = a.size();

        REP(i,n*2+1)dat.push_back(vector<T>(0));
        
        init(0 , 0 , n);


    }

    ~SegmentTree(){}

    

    

    void init(int k, int l, int r ) {
        if (r - l == 1) { 
            dat[k].push_back(A[l]);
        } else {

            int lch = k * 2 + 1;
            int rch = k * 2 + 2; 
            
            init(lch, l, (l + r) / 2);
            init(rch, (l + r) / 2, r); 

            dat[k].resize(r - l);
            
            

            merge(dat[lch].begin(), dat[lch].end(), dat[rch].begin(), dat[rch].end(),dat[k].begin());
        } 
    }

    

    

    int query_sub(int i, int j, T x, int k  , int l  , int r) {

        if (j <= l || r <= i) {


            return 0;

        } else if (i <= l && r <= j) {


            return upper_bound(dat[k].begin(), dat[k].end(), x) - dat[k].begin(); 

        } else {


            int lc = query_sub(i, j, x, k * 2 + 1, l, (l + r) / 2);
            int rc = query_sub(i, j,  x, k * 2 + 2, (l + r) / 2, r);

            return lc + rc;
        }
    }

    

    int query(int i , int j , T x){
        return query_sub(i , j , x , 0 , 0 , n);
    }
};


bool sd(pll p , pll q){
    return p.second<q.second;
}


ll n , m;
ll h , w , k; 
mll p;




struct LazySumSegTree {
    private:
        int n;
        vector<ll> node, lazy;

    public:
    
    LazySumSegTree(vector<ll> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);

        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = compare( node[i*2+1] , node[i*2+2]);
    }




    

    inline ll compare(ll a , ll b){

        

        

        return a+b;

        
        

    }


    void eval(int k, int l, int r) {
    
    

    

        if(lazy[k] != 0) {
            node[k] = compare(node[k],lazy[k]);

            

            

            

            if(r - l > 1) {
                lazy[2*k+1] = compare(lazy[2*k+1], lazy[k] / 2);
                lazy[2*k+2] = compare( lazy[2*k+2] , lazy[k] / 2);
            }

            

            lazy[k] = 0;
        }
    }

    void add(int a, int b, ll x, int k=0, int l=0, int r=-1) {

        if(r < 0) r = n;

        

        eval(k, l, r);

        

        if(b <= l || r <= a) return;
        
        

        if(a <= l && r <= b) {
            lazy[k] = compare(lazy[k], (r - l) * x);
            eval(k, l, r);
        }

        

        

        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = compare(node[2*k+1] , node[2*k+2]);
        }
    }




    ll query(int a, int b, int k=0, int l=0, int r=-1) {

        if(r < 0) r = n;
        if(b <= l || r <= a) return 0;

        

        eval(k, l, r);
        if(a <= l && r <= b) return node[k];
        ll vl = query(a, b, 2*k+1, l, (l+r)/2);
        ll vr = query(a, b, 2*k+2, (l+r)/2, r);
        return compare(vl,vr);
    }


    ll getval(ll i){

        query(i,i+1);
        return node[i+n-1];

    }


};




int main(){
    ll t;
    cin >> t;
    
    while(t-->0){
        cin >>n;
        
        vpll V(n);
        REP(i,n)cin>>V[i].first>>V[i].second;

        ll now = 0;



        ll lef = 0;
        ll rig = n+1;
        while(rig-lef>1){
            ll X = lef+(rig-lef)/2;
            ll now = 0;

            REP(i,n){
            
                if(now<=V[i].second){
                    if(now>=X-1-V[i].first){
                        now++;
                    }
                }


            }
            if(now<X){
                rig = X;
            }else{
                lef= X;
            }
        }

        
        cout << lef << endl;
    }
    return 0;   
}

