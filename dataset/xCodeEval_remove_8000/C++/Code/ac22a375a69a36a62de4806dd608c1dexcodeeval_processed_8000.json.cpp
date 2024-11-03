

















  












  


 






  


















using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9 + 7;
const ld error = 2e-6;
const ld PI = acosl(-1); 

















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

int m; cin>>m;
for(i=1;i<=m;i++){
    int k,pos; cin>>k>>pos; vector<int>sv;
    int j;
    for(j=n-1;j>=n-k;j--){
        sv.pb( vc[j].YY );
    }
    sort(all(sv));
    cout<< ara[sv[pos-1] ]<<""<<endl;


}




    return 0;
}


































































