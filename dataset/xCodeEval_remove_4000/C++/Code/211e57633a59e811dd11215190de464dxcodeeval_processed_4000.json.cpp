 


 

using namespace std;
 
















 





 






 








 




 




 










 




 






 






 




 


 






 


 

 


 




 


 















 


 







 


 


 



 











 


 
















 

 
 
 
 
 
 
void solve()
{
    lli n,a,i,mi=100000000000000,ct,j,ct1=0,maxi=0,mini0,mini1=000000000000000000000,mini2=10000000000000000;
    cin>>n;
    vl v,vt;
    f(i,0,n){cin>>a;v.pb(a);vt.pb(a);if(a==1){ct1=1;}}


    


    


    

    

    

    

    sort(vt.begin(),vt.end());
    ct=(vt[0]+1)/2;
    ct+=(vt[1]+1)/2;
    mini0=ct;
    

    

    

    

    

    

    

    

    

    f(i,0,n-1){
        if(v[i]==v[i+1]){
            ct=(v[i]+v[i+1]+2)/3;
            mi=min(mi,ct);
        }else{
            maxi=max(v[i],v[i+1]);
            mini1=min(v[i],v[i+1]);
            if(2*mini1<=maxi){
                maxi=(maxi+1)/2;
                mi=min(mi,maxi);
            }else{
                ct=(v[i]+v[i+1]+2)/3;
                mi=min(mi,ct);
            }
        }
    }
    

    

    

    

    

    

    

    

    

    

    f(i,1,n-1){
        if((v[i-1]==v[i+1]) && 2*v[i-1]<=v[i]){
            mini2=min(mini2,v[i-1]);
        }else{
            mini1=min(v[i-1],v[i+1]);
            maxi=max(v[i-1],v[i+1]);
         
                ct=(maxi-mini1+1)/2;
                ct+=mini1;
            mini2=min(mini2,ct);
        }
    }
    

    

    

    

    

    

    

    

    

    

    

    

                    
    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

        
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

        mi=min3(mi,mini0,mini2);
    

    cout<<mi<<endl;
    
}
 
int main()
{
    

    

    

    

    

    lli t;
    t=1;
    

    while(t--)
    solve();
    
    return 0;
}
