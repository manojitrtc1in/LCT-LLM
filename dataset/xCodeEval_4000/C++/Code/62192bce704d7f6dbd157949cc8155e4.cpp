#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<fstream>
#include<vector>
using namespace std;

int main()
{
   
      ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long  t;
    cin>>t;
    while(t--)
    {
        long long  n;
        int m=-1;
        cin>>n;
         int x=0;
        long long  freq[n+4]={0};
        while(n--)
        {
            long long  a;
            cin>>a;
           
            freq[a]++;
            
            if(freq[a]>=3)
            {
                x=1;
            m=a;
           

            }
            
        }
        
        cout<<m<<"\n";
    }
    
    
    
    
    
    
}
    
    
    
    
    
    
    
    
    
    
    
    
    

      
	




	
       












    
    
     
   
      
       
     
     
 
 
     
      
  

	






	




       












    
    
     
   
      
       
     
     
 
 
     
      
  

	
    
    
    
    
    
    
    
    
    
    
    
    
    

      
	




	
       












    
    
     
   
      
       
     
     
 
 
     
      
  

	






	




       












    
    
     
   
      
       
     
     
 
 
     
      
  

	