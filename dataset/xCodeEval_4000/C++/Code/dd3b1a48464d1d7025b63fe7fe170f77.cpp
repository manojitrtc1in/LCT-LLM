#include<bits/stdc++.h>
using namespace std;

 
    
#define IOS ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int base=1e9+7;
long long IndianMul(long long a,long long b){
    if (b == 0)
        return 0;
    long long t = IndianMul(a, b / 2)%base;
    if((b&1)==0)
        t = (t + t)%base;
    if ((b&1)== 1)
        t = (t +t+ a)%base;
    return t;
}
long long POW(long long a, long long n)
{
    if(n==0) return 1;
    if(n == 1) {
        return a;
    }
    if(n>1){
        long long temp = POW(a, n/2);
        if((n&1) == 0)
            return (temp * temp)%base;
        else
            return ((temp * temp)%base* a)%base;
    }
}
int t,n,a[100001];
main (){
    cin>>t;
    while(t--){
        long long MAX=1e18,ok=1;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]>=MAX){
                ok=0;
            }
            MAX=a[i];
        }
        if(ok==0) cout<<"YES";
        else cout<<"NO";
        cout<<'\n';
    }
}
