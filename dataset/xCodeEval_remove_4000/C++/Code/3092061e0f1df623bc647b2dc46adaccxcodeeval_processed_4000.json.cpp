

















  












  


 






  


















using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 998244353;
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
   



    int m; cin>>m;
    for(int ii=1;ii<=m;ii++ ){
     ll n,T,a,b; cin>>n>>T>>a>>b; map<ll,ll>val,freq; vector<ll>difc, tme,tst;  

     int i;
     map<ll,ll>one,zero; ll owan=0, jero=0;
     for(i=0;i<n;i++){
        ll xx; cin>>xx; difc.pb(xx);
        if(xx==0) jero++;
        else owan++;
     }
     ll tot=owan*b+jero*a;
     for(i=0;i<n;i++){
        ll xx; cin>>xx; tst.pb(xx);
        if(difc[i]==0) zero[xx]++;
        else if(difc[i]==1) one[xx]++;
        if(freq[xx]==0) tme.pb(xx);
        freq[xx]++;
        if( difc[i]==0 ){ val[xx]+=a;  }
        else{ val[xx]+=b; }
     }
     sort(all(tme));
ll ft=n;


ll drk=0; ll ok=5; ll atlast=0;
ll id1=0, id0=0; ll TT=T;
     for(i=tme.size()-1;i>=0;i--){
            

        if( tot>T){
            id0+= one[ tme[i] ]; id1+=zero[ tme[i] ];
        ft-=freq[tme[i]]; T=tme[i]-1; tot-= one[tme[i]]*b+zero[ tme[i] ]*a;
        drk= T-tot; owan= id0; jero= id1;
        if(i==0){ ft=0; drk=tme[i]-1; ok=-1; if(tme[0]==0) drk=0; }
        }

        else{
ll ftt=ft;
ll t1= drk/a; ll t2= drk%a;
     if(t1<=jero){
            if(t1>0)
        ftt+=t1;
     }
    else {
            if(jero>0)
        ftt+=jero; t2+= a*(t1-jero);
     }

     t2= t2/b;
     if(min(t2,owan)>0)
     ftt+= min(t2,owan);
     atlast= max(atlast,ftt);



 id0+= one[ tme[i] ]; id1+=zero[ tme[i] ];
        ft-=freq[tme[i]]; T=tme[i]-1; tot-= one[tme[i]]*b+zero[ tme[i] ]*a;
        drk= T-tot; owan= id0; jero= id1;
        if(i==0){ ft=0; drk=tme[i]-1; ok=-2; if(tme[0]==0) drk=0; }





        }
     }
    


   

    

     

     int fct=0;

     ll ftt=ft;
ll t1= drk/a; ll t2= drk%a;
     if(t1<=jero){
            if(t1>0)
        ftt+=t1;
     }
    else {
            if(jero>0)
        ftt+=jero; t2+= a*(t1-jero);
     }

     t2= t2/b;
     if(min(t2,owan)>0)
     ftt+= min(t2,owan);
     atlast= max(atlast,ftt);


     cout<<atlast<<endl;






    }

    return 0;
}



































































