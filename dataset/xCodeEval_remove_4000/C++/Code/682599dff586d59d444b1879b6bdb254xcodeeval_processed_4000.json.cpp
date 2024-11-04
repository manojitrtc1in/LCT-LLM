

















  












  


 






  


















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




int main()
{
    

    int n,k; cin>>n>>k; vector<int>vc,sv; vc.pb(0); sv.pb(0); int i;
    string fk; cin>>fk;
   string dk= fk;
   for(i=k;i<n;i++){
    dk[i]=dk[i-k];
   }

   if(dk>=fk){ cout<<n<<endl<<dk<<endl; exit(0); }

   for(i=k-1;i>=0;i--){
    if(dk[i]!='9'){
        dk[i]+=1;
        for(int ii=i+1;ii<k;ii++){
             

            dk[ii]='0';
        }

    break;
    }
   }

for(i=0;i<n;i++){
    if(i+k<n){
        dk[i+k]=dk[i];
    }
   }

cout<<n<<endl<<dk<<endl;
    return 0;
}



































































