











































































































































#include <iostream>

using namespace std;

int main(){
    int t,n;
    cin>>t;
    while(t--){
        long long ans=100025;
        cin>>n;
        long long a[100025],b[100025],res[200050],minn[200000];
        for(int i=1;i<=n;i++)cin>>a[i],res[a[i]]=i-1;
        
        for(int i=1;i<=n*2;i+=2){
            if(i==1){
                minn[i]=res[i];
            }
            else{
                minn[i]=min(res[i],minn[i-2]);
            }
        }
        for(int i=1;i<=n;i++)cin>>b[i],ans=min(ans,i-1+minn[b[i]-1]);

        
        cout<<ans<<endl;
    }


}