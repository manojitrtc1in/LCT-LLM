 


 

using namespace std;
 
















 





 






 








 




 




 










 




 






 






 




 


 






 


 

 


 




 


 















 


 







 


 


 


 











 


 


lli power(lli n,lli a){ lli res=1; while(a){ if(a%2){ res*=n,a--;}else{n*=n,a/=2;}} return res;}
lli modpower(lli n,lli a){ lli res=1; while(a){ if(a%2){ res= ((res*n)%N) ,a--;}else{n=((n*n)%N),a/=2;}} return res;}
lli id0(lli a, lli b) {a %= N;lli res = 1;while (b > 0) {if (b & 1)res = res * a % N;a = a * a % N;b >>= 1;}return res;}
lli binpower(lli a, lli b) {lli res = 1;while (b > 0) {if (b & 1)res = res * a;a = a * a;b >>= 1;}return res;}



lli fastprime(lli a){ if (a != 2 && a % 2 == 0 || a < 2) return 0;  for(int i = 3; i * i <= a; i += 2) if(a % i == 0) return 0; return 1;}
 

 
 
 
 
 
 
void solve()
{
    string s1,s2;
    cin>>s1>>s2;
    lli n=lcm2(s1.size(),s2.size()),c1=0,c2=0,i,j;
    string s;
    n/=min(s1.size(),s2.size());
    f(i,0,n){
        if(s1.size()<s2.size()){
            for(j=0;j<s1.size();j++){
                s.pb(s1[j]);
            }
            c1=1;
        }else{
            for(j=0;j<s2.size();j++){
                s.pb(s2[j]);
            }
            c2=1;
        }
    }
    if(c1==1){
        j=0;
        for(i=0;i<s.size();i++){
            if(s[i]!=s2[j]){
                cout<<"-1"<<endl;return;
            }
            if(j==s2.size()-1){j=0;}
            else{j++;}
        }
        cout<<s<<endl;
    }else{
        j=0;
        for(i=0;i<s.size();i++){
            if(s[i]!=s1[j]){
                cout<<"-1"<<endl;return;
            }
            if(j==s1.size()-1){j=0;}
            else{j++;}
        }
        cout<<s<<endl;
    }
    
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
