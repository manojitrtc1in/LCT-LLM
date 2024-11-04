
    using namespace std;
     
    typedef long long ll;
     
    ll ar[100005];
    ll diff[100005];
     
    int main(){
        ll n,k;
        cin >> n >> k;
        for( ll i=0; i<n; i++ ) cin >> ar[i];
        sort(ar,ar+n);
        

        for( ll j=1; j<n; j++ ) diff[j-1]=ar[j]-ar[j-1];
        

        ll result=ar[n-1]-ar[0];
        ll p1=0,p2=n-2;
        ll idx=1;
     
        while(p1<p2){
             if(k<((diff[p1]+diff[p2])*idx))
             {
                result-=(k/idx);
                k-=k;
     
             }
             else{
                result-=(diff[p1]+diff[p2]);
                k-=(diff[p1]+diff[p2])*idx;
             }
     
             p1++;
             p2--;
             idx++;
     
        }
        if(p1==p2) {
           if(k<diff[p1]*idx){
              result-=(k/idx);
           }else{
              result-=diff[p1];
           }
        }
        cout << result <<endl;
        return 0;
    }
    