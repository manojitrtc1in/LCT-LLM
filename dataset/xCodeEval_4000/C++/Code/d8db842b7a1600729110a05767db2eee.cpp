

















  












  


 






  




#include <bits/stdc++.h>
#include<stdio.h>
#define pb(x) push_back(x)
#define XX first
#define YY second
#define cst 1000000007
#define nor_rad(x) ( ( PI*x )/180)
#define rad_nor(x)  ( (x/IP)*180 )
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9 + 7;
const ld error = 2e-6;
const ld PI = acosl(-1); 


#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))












inline ll MOD(ll x, ll m = mod){
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1000+10;



bool cmp( pair<int,int>p1, pair<int,int>p2 ){
if( p1.XX!=p2.XX ) return p1.XX<p2.XX;
return p1.YY>p2.YY;
}







int main()
{
   


int n; cin>>n; int i; vector< pair<int,int> >vc(n); vector<int>ara;
for(i=0;i<n;i++){
    int xx; cin>>xx; ara.pb(xx); vc[i]= {xx,i};
} sort(all(vc),cmp);

vector<int>ott[n+2];
set<int>tes; int pussy=1;
for(i=n-1;i>=0;i--){
    tes.insert( vc[i].YY );
    ott[pussy].insert( ott[pussy].end(), tes.begin(), tes.end() ); pussy++;
}



int m; cin>>m;
for(i=1;i<=m;i++){
    int k,pos; cin>>k>>pos; vector<int>sv;
    int j;

    int ans= ott[k][pos-1];


    cout<< ara[ans]<<""<<endl;


}




    return 0;
}


































































