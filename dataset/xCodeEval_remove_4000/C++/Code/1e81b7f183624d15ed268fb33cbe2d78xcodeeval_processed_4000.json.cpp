 


 

using namespace std;
 
















 





 






 








 




 




 










 




 






 






 




 


 






 


 

 


 




 


 















 


 







 


 


 


 











 


 


lli power(lli n,lli a){ lli res=1; while(a){ if(n%2) res*=n,a--; else	n*=n,a/=2;} return res;}
lli modpower(lli n,lli a) { lli res=1; while(a){ if(a%2) res= ((res*n)%N) ,a--; else	n=((n*n)%N),a/=2;} return res;}
lli id0(lli a, lli b) {a %= N;lli res = 1;while (b > 0) {if (b & 1)res = res * a % N;a = a * a % N;b >>= 1;}return res;}
lli binpower(lli a, lli b) {lli res = 1;while (b > 0) {if (b & 1)res = res * a;a = a * a;b >>= 1;}return res;}



lli fastprime(lli a){ if (a != 2 && a % 2 == 0 || a < 2) return 0;  for(int i = 3; i * i <= a; i += 2) if(a % i == 0) return 0; return 1;}
 

 
 
 
 
 
 
void solve()
{
    lli n,m,i,j,ct=0,id1=1000000000000,id2=1000000000000,ct1=0,k;
    cin>>n>>m;
    vector<vector<lli>> a(n,vector<lli>(m));
    f(i,0,n){f(j,0,m){cin>>a[i][j];}}
    if(m==1){cout<<"1 "<<"1"<<endl;return;}
    f(i,0,n){
        f(j,0,m-1){
            if(a[i][j]>a[i][j+1]){
                ct1=1;
                vl v=a[i];
                sort(all(v));
                f(k,0,v.size()){
                    if(a[i][k]!=v[k]){
                        if(ct==0){
                            id1=k;
                        
                        }
                        if(ct==1){
                            id2=k;
                        
                        }
                        if(ct==2){cout<<"-1"<<endl;return;}
                        ct++;
                    }
                }
                break;
            }        
        }
        if(ct1==1){break;}
    }
    if(ct1==0){cout<<"1 "<<"1"<<endl;return;}
    f(i,0,n){
        swap(a[i][id1],a[i][id2]);
    }

    f(i,0,n){
        f(j,0,m-1){
            if(a[i][j]>a[i][j+1]){
                cout<<"-1"<<endl;return;
            }
        }
    }
    cout<<id1+1<<" "<<id2+1<<endl;

}
 
int main()
{
    fast;
    lli t;
    t=1;
    cin>>t;
    while(t--)
    solve();
    
    return 0;
}
