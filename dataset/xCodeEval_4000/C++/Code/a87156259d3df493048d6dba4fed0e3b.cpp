
#include <bits/stdc++.h>
#define ll long long
#define el '\n'
#define pi 3.1415926536
#include <sstream>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;



 

ll const N=1e7;
ll a[N],b[N];
int main() {
    fast;
    int tc;cin>>tc;
    while(tc--){
        ll n,cnteven =0,cntodd=0,cnt=0,ans=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]%2==0){
                if(i!=0 && i!=n-1)
                cnteven++;
        }
          else {
            if(i!=0 && i!=n-1)cntodd++;
            if(i!=0&& i!=n-1&& a[i]==1)cnt++;
          }
        }
      if(cntodd<=1&&cnteven==0 )cout<<-1<<el;
      else if(cntodd==cnt && cntodd!=0 && cnteven==0)cout<<-1<<el;
      else{
        for(int i=1;i<n-1;i++){
            if(a[i]%2==0) ans+=(a[i]/2);
            else ans+=(a[i]+1)/2;
        }

      cout<<ans<<el;
      }



    }
	return 0;
}

 	  	    		  		 	 		  	 	    		