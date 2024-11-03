#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool check(string n)
{
    stack<char>s;
    for(int i=0;i<n.size();i++)
    {
        if(s.empty()||n[i]=='(')
            s.push(n[i]);
        else if(s.top()=='('&&n[i]==')')
                s.pop();

    }
    if(s.empty())return true;
    else return false;
}


int idx_b(int n)
{
    int c=0;
    while(n>0)
    {
        c++;
        n/=2;
    }
    return c;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        

       int n;
       cin>>n;
       int arr[n];
       map<int,int>mp;
       int f=0;
       for(int i=0;i<n;i++)
        {cin>>arr[i];if(arr[i]==1)f=1;mp[arr[i]]++;}
       if(f)
       {
           int kk=n/2;
           for(int i=0;i<n&&kk;i++)
           {
               if(arr[i]!=1)
               {
                   cout<<arr[i]<<" "<<1<<"\n";
                   kk--;
               }
           }

           continue;
       }
       int k=n/2;
       sort(arr,arr+n);
       for(int i=1;i<n&&k;i++)
       {
           if(arr[i]!=arr[0]&&mp[arr[i]%arr[0]]==0)
           {
               cout<<arr[i]<<" "<<arr[0]<<"\n";
                   k--;
           }
       }

       

       

       

       


       
        

        


        
        

    }
return 0;
}
    
        
    
    

    

    
    

    
    

    


    
            

            

   

     

    

        
   





   
       

       

       

       

       
       

       

   

   
   

       
       

   


        

        

        

        


              
       

        
        

        


    
   

    



    
        
        






