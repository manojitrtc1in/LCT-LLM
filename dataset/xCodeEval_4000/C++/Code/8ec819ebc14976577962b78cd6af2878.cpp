#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef  long long ll;
#define INT_BITS 32
void display(int a)
{
     for(int k=32;k>=0;k--)
    {
        if(a&(1<<k))
            cout<<"1";
        else
            cout<<"0";
    }
    cout<<endl;

}
int  Sum(vector<int> m)
{
    int sum=0;
    for(int i=0;i<m.size();i++)
       sum+=m[i];
     return sum;
}
int  element(vector<int> d)
{
    int maxm = d[0];
    for(int i=0;i<d.size();i++)
    {
        if(maxm<=d[i])
            maxm=d[i];
    }
    return maxm;
}
int EuclidGCD(int a,int b)
{
    int rem;
    if(b ==0)
        return a;
    else
    {
        rem = a % b;
        return EuclidGCD(b,rem);
    }
}
int Min(vector<int> a)
{
    return (*min_element(a.begin(),a.end()));
}
void func_A()
{
     int n;
     cin>>n;
     vector<int> v;
     for(int i=0;i<n;i++)
     {
         int x;
         

         cin>>x;
         v.push_back(x);
     }
      if(Min(v)==1)
        cout<<element(v)<<endl;
     else
      cout<<Min(v)+1<<endl;


     


}
long long int fact(int n)
{
    long long int i=1;
    while(n>0)
    {
        i=i*n;
        n--;
    }
    return i;
}

int main()
{
    

   
    

   
    
   

    
    
    

   
     
     
   
	
  
   
    
   
   
  
  
   
    
   
  

   

   

    
  

    
   

     

      
       
       
      
       
        
        

        
       
        
       
    
      
     
    
    
     
     
     
      int t;
      cin>>t;
      while(t--)
      {
          int n,m;
          cin>>n>>m;
          int sum=0;
          for(int i=0;i<n;i++)
          {
              int x;
              cin>>x;
              sum+=x;

          }
          cout<<min(sum,m)<<endl;

      }









   return 0;
}
