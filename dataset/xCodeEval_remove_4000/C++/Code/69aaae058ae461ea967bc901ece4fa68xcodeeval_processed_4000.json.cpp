

using namespace std;






int n_bits(int n)
{
    int c=0;
    while(n>0)
    {
        if(n&1) c++;
        n/=2;
    }
    return c;
}
struct cmp {
    bool operator()(pair<int,int>a,pair<int,int>b) {
        if(n_bits(a.first)==n_bits(b.first)) return a.second<b.second;
        else if(a.first==b.first) return a.second<b.second;
        else return n_bits(a.first)>n_bits(b.first);
        

        

    }
};
int main()
{
    int t;
    cin>>t;
    int idx=1;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            

        }
        


        

        
        

        

        

        sort(arr,arr+n);
        int a[n+1]={0};
        int i=0,j=n/2;
        int idx=0;
        int ff=0;
        while(i<n/2)
        {
            a[idx]=arr[i];
            idx++;
            a[idx]=arr[j];
            idx++;
            if(arr[i]>=arr[j])
                ff=1;
            

            

            i++;j++;
        }
        

        

        int f=0;
        

        for(int i=1;i<n-1;i++)
        {
            
            if(((a[i]>a[i-1])&&(a[i]>a[i+1]))||((a[i]<a[i-1])&&(a[i]<a[i+1]))) {f=0;}
            else {f=1;break;}
        }
        

        

        if(f||ff||(n&1)){cout<<"NO\n";continue;}
        else {cout<<"YES\n";}

        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;

        
        

    }
    
     
        

   

    
        

        

        

        
    

    

    

    
        
   

    
    
    return 0;
}
    
    

    




















    
    
    

    

    





    

    
        

        
        
        

        
        
        
    

    
    
    

    

    
    

    
    
    

    

    
    

    

    

    


    

    


    

    
    

    
        
        
       


   

        

    

        
            

            

         

       

        
  

  

     
     
     


  

        
            

            


         
      
        
        
        

        
        

    



    
     
   

   

   

    
    

    





