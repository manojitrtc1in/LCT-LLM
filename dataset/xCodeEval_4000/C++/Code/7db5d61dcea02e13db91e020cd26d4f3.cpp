#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool check(long long x)
{
    if((long double)x==(long long)x)return true;
    else return false;
}
#define y cout<<"YES\n";
int main()
{
    int t;
    cin>>t;
    int idx=0;
    while(t--)
    {
        idx++;
        long long n;
        cin>>n;
        

        

        if(n%2==0)
        {
            cout<<(n-1)/2<<" "<<((n-1)/2)+1<<" "<<1<<"\n";
        }
        else
        {
            for(long long i=2;i<=n;i++)
            {
                int f=0;
                for(long long j=2;j*j<=i;j++)
                {
                    if(i%j==0)
                    {
                        f=1;
                        break;
                    }
                }
                if(f==0&&((n-1-i)%i!=0)){cout<<n-1-i<<" "<<i<<" "<<1<<endl;break;}
                

            }
            
        }
    }
    return 0;
}
   
       

       

       

       

       
       

       

   

   
   

       
       

   


        

        

        

        


              
       

        
        

        


    
   

    



    
        
        






