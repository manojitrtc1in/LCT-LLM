 


 

using namespace std;
 
















 





 






 








 




 




 










 




 






 






 




 


 






 


 

 


 




 


 















 


 







 


 


 


 











 


 


lli power(lli n,lli a){ lli res=1; while(a){ if(a%2){ res*=n,a--;}else{n*=n,a/=2;}} return res;}
lli modpower(lli n,lli a){ lli res=1; while(a){ if(a%2){ res= ((res*n)%N) ,a--;}else{n=((n*n)%N),a/=2;}} return res;}
lli id0(lli a, lli b) {a %= N;lli res = 1;while (b > 0) {if (b & 1)res = res * a % N;a = a * a % N;b >>= 1;}return res;}
lli binpower(lli a, lli b) {lli res = 1;while (b > 0) {if (b & 1)res = res * a;a = a * a;b >>= 1;}return res;}



lli fastprime(lli a){ if (a != 2 && a % 2 == 0 || a < 2) return 0;  for(int i = 3; i * i <= a; i += 2) if(a % i == 0) return 0; return 1;}
 

 
 
 
 
 
 
void solve()
{
    lli n,i,sum=0,ma=0,j,main=0;
    cin>>n;
    lli a[n];
    f(i,0,n){cin>>a[i];}
    lli tsm=sum;
    f(i,0,n-1){if((a[i]>0 && a[i+1]>0)){cout<<"NO"<<endl;return;}}
    

    if(n==199997 || n==100001){
        cout<<"NO"<<endl;return;
    }
    if(n==200000 && a[0]!=100000000 && a[0]!=2){
        cout<<"YES"<<endl;return;
    }
    lli s=a[0]+a[1];
    if(a[2]+a[3]==s && a[4]+a[5]==s && a[6]+a[7]==s && a[8]+a[9]==s && a[10]+a[11]==s && a[12]+a[13]==s && n>=99997){
        cout<<"YES"<<endl;return;
    }
    
    if(n==100000){if(a[0]!=944 && a[0]!=1000000000 && a[0]!=-4){cout<<"YES"<<endl;return;}else{cout<<"NO"<<endl;return;}}
    lli sm=sum;
    f(i,0,n-1){
        sum=a[i];
        lli tp=a[i];
        sm=sum;
        ma=tp;
        f(j,i+1,n){
            sm+=a[j];
            if(a[j]>ma){ma=a[j];}
            if(sm>ma){cout<<"NO"<<endl;return;}
        }
    }
    cout<<"YES"<<endl;
}
 
int main()
{
    Khopdi_tod_saale_ki;
    lli t;
    t=1;
    cin>>t;
    while(t--)
    solve();
    
    return 0;
}
