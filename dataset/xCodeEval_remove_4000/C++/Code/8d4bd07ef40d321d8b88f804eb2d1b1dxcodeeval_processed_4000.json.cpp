

















  












  


















using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9+7;
const ld error = 2e-6;
const ld PI = acosl(-1); 

















inline ll MOD(ll x, ll m = mod){
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1000+10;



int low(vector<int>&vc, int key){

int l=0, r= vc.size()-1;
int ret=-1; int mid;
while(l<=r){
    mid= (l+r)/2; 

   

   

    if( vc[mid]<=key ){ ret= vc[mid]; l= mid+1; }
    else r= mid-1;

}

return ret;
}

int upper(vector<int>&vc, int key){
    int l=0, r= vc.size()-1;
int ret=-1; int mid;
while(l<=r){  

    mid= (l+r)/2;  

   

 

    if( vc[mid]>=key ){ ret= vc[mid]; r= mid-1; }
    else l= mid+1;

}
return ret;
}

long long sq(int x) { return 1ll * x * x; }

ll solve( vector<int>&a, vector<int>&b, vector<int>&c ){
    int i; ll cn= (1e18)*5;
    for( i=0;i<a.size();i++ ){
        int x= low(b,a[i]), y= upper(c,a[i]);
   
        if(x==-1 or y==-1) continue;
        cn= min( cn,  sq(a[i]-x)+ sq(a[i]-y) + sq(x-y)  );
    }
return cn;
}

int main()
{


    int t; scanf("%d",&t); 

    while(t--){
        vector<int>ga,gb,gc; map<int,int>id4, id2, id6, id5, id3, id11, id0, id1, id7, id8, id10, id9;
        int i; int x,y,z; cin>>x>>y>>z; map<int,int>isa,isb,isc; int inpx=0, inpy=0, inpz=0;
        int xxx= max(x, max(y,z))+2;
        for(i=1;i<=x;i++){
            int xx; scanf("%d",&xx);
            if(!isa[xx]){
            ga.pb(xx);
            isa[xx]=1;
            }
        }

        for(i=1;i<=y;i++){
            int xx; scanf("%d",&xx);
            if(!isb[xx]){
            gb.pb(xx);
            isb[xx]=1;
            }
        }

        for(i=1;i<=z;i++){
            int xx; scanf("%d",&xx);
            if(!isc[xx]){
            gc.pb(xx);
            isc[xx]=1;
            }
        }



        x= ga.size(), y= gb.size(), z= gc.size();
        inpx=0, inpy=0, inpz=0;

        sort(all(ga)); sort(all(gb)); sort(all(gc));

        ll f1= solve(ga,gb,gc), f2= solve(ga,gc,gb), f3= solve( gb, ga, gc ), f4= solve(gb,gc,ga ), f5= solve(gc, ga,gb), f6= solve(gc,gb,ga);
        cout<<  min(min(min(f1,f2),min(f3,f4)),min(f5,f6))<<endl;
       




   xxx= max( x, max(y,z) );
      





    }

    return 0;
}









































































