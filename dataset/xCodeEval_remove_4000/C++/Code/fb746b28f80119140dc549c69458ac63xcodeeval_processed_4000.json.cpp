 


 

using namespace std;
 
















 





 






 








 




 




 










 




 






 






 




 


 






 


 

 


 




 


 















 


 







 


 


 


 











 


 


lli power(lli n,lli a){ lli res=1; while(a){ if(a%2){ res*=n,a--;}else{n*=n,a/=2;}} return res;}
lli modpower(lli n,lli a){ lli res=1; while(a){ if(a%2){ res= ((res*n)%N) ,a--;}else{n=((n*n)%N),a/=2;}} return res;}
lli id0(lli a, lli b) {a %= N;lli res = 1;while (b > 0) {if (b & 1)res = res * a % N;a = a * a % N;b >>= 1;}return res;}
lli binpower(lli a, lli b) {lli res = 1;while (b > 0) {if (b & 1)res = res * a;a = a * a;b >>= 1;}return res;}



lli fastprime(lli a){ if (a != 2 && a % 2 == 0 || a < 2) return 0;  for(int i = 3; i * i <= a; i += 2) if(a % i == 0) return 0; return 1;}
 

 
 
 
 
 
 
void solve()
{
    lli n,r,b,i,ctr=0,ctb=0;
    cin>>n>>r>>b;
    lli loop=r/(b+1);
    r=(r%(b+1));
    lli rlp=loop;
    string s;
    for(i=0;i<n;i++){
        if(ctr==loop){
            ctr=0;
            cout<<"B";
        }else{
            cout<<"R";
            if(r>0 && ctr==0){cout<<"R";r--;i++;}
            ctr++;
        }
    }cout<<endl;
    
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
