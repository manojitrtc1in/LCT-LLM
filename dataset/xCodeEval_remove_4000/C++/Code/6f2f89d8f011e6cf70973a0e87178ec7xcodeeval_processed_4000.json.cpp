     
                
                using namespace std;
                long long mod=1e9+7;
        

        

        

        

            
        

        

            
        

            
        

            
        

            
        

        

        

        

            
        

                       
                
        

        

        

        

         
        

        

        

         
        

        

        

        

        

        

        

        

        

        

        

        

            
           
         
        

        

            
           
            
         
        

        

         
                
                
        

            
        

        

        

              
        

        

              
        

        

              
        

              
        

        

              
        

            
        

          
        

        

        

        

        

        

        

        

        

        

         
        

        

          
        

            
        

        

            
        

              
        

        

        

        

        

        

        

            
        

            
        

        

        

        

        

            
        

        

                
        

            
        

        

            
        

        

        

              
        

        

              
        

              
        

                
        

        

        

        

              
        

        

        

              
        

        

        

        

        

        

         
         
        

          
        

        

          
        

        

          
        

        

        

          
        

        

        

          
        

        

              
        

        

        

          
        

          
          
          
        

         
        

          
        

        

        

         
        

        

         
        

         
        

        

        

          
        

        

        

          
        

        

        

          
        

          
        

        

        

          
        

        

          
        

        

        

            
        

            
            
        

            
        

        

        

        

        

        

            
        

            
            
        

          
        

          
          
        

         
        

        

         
        

         
        

        

        

        

           
        

        

        

        

        

        

         
        

        

        

         
        

        

        

        

        

        

         
        

        

        

        

        

        

        

        

        

        

         
        

        

        

         
        

        

        

        

        

         
        

        

        

        

        

          
        

        

          
        

          
        

        
        long long id2(long long a[], long long size)
    {
        long long  id1 = -1e18, id3 = 0;
     
        for (long long i = 0; i < size; i++)
        {
            id3 = id3 + a[i];
            if (id1 < id3)
                id1 = id3;
     
            if (id3 < 0)
                id3 = 0;
        }
        return id1;
    }
     
     
     
    int LCS(string s, string x) {
          int n = s.size();
          int m = x.size();
          if(!n || !m) return 0;
          s = " " + s;
          x = " " + x;
          int ret = 0;
          vector < vector <int> > dp(n + 1, vector <int>(m + 1));
          for(int i = 1; i <= n; i++){
             for(int j = 1; j <= m ; j++){
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                if(s[i] == x[j]) {
                  dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
                }
             }
          }
          return dp[n][m];
       }
    bool id4(long long sequence, long long n)
    {
        while(sequence > 0 && n > 0)
        {
            if(n%10 == sequence%10)
            {
                sequence /= 10;
     
                if(sequence == 0)
                    return true;
            }
     
            n /= 10;
        }
     
        return false;
    }
     
    long long id0(long long arr[],long long n){
      
      long long size=2*n;
      
      bool visited[n];
      memset(visited,false,sizeof(visited));
      
     
    long long ans=0;
     
    for(long long i=0;i<n;i++){
      
      if(visited[arr[i]]==false){
        visited[arr[i]]=true;
      }
      
     long long count=0;
      
      for(long long j=i+1;j<size;j++){
        
        if(visited[arr[j]]==false){
          count++;
        }
        
        else if(arr[i]==arr[j]){
        ans+=count;
        }
      }
    }
     
    return ans;
    }
    
    bool id5(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
     
  

    
  

  

    
  

  

    
  

    
  

    
  

      
  

        
  

  

  

  

  

    
  

    
  

    
    
  


  
  
  
  

  

  

  

  
  

    
  

    
  

      
  

  

  

    
  

  

    
  

    
  

      
  

      
  

  

        
  

        
  

  

  

  

  

      
  

  

  

      
  

  

    
  

  

  

  

  

    
  

  
  bool comp(pair<int,long long>p1, pair<int,long long>p2){
    
    if(p1.first==p2.first){
      return p1.second>p2.second;
    }
    
    return p1.first<p2.first;
  }
  


  




  


  


    




    


    










    




  


  






  







  


  


  




      




       


       


        


















        
       
      




  






  


 






 


 





  






  




  








  




  


   


      


        








      


        
















 
  


  






  




  
  





  




  






  








  


    


    




    
    


      


      


        


        








    














  












 






 










 






 







  




  




  




   






     


   










     










   


  



















































  




  


  


    


    








  











 const string t="abacaba";

bool contains(string s){
  
  int count=0,n=s.length();
  for(int i=0;i<=n-7;i++){
    if(s.substr(i,7)==t){
      count++;
    }
  }
  
  return (count==1);
}

void process(string s){
  
  int n=s.length();
  
  for(int i=0;i<n;i++){
    
    if(s[i]=='?'){
      cout<<"d";
    }
    else{
      cout<<s[i];
    }
  }
  cout<<endl;
}



  








  










  


    




    


      












    















  


  


  


  


  






  




  










   






   


     
















         


















         






     




   




  





  






  




  




  












  






  


    


















  




















   


   






  




  


  


  






  


  


    




















  




  









int main(){
  
  int t;
  cin>>t;
  while(t--){
    
    long long n,m;
    cin>>n>>m;
    
   vector<long long>arr(n);
    for(long long i=0;i<n;i++)
    cin>>arr[i];
    
    long long gifts[m+1];
    
    for(long long i=1;i<=m;i++)
    cin>>gifts[i];
    
    sort(arr.rbegin(),arr.rend());
    
    long long ptr=1;
    
    long long ans=0;
    
    for(long long i=0;i<n;i++){
      
      if(ptr<=m){
      if(gifts[ptr]<gifts[arr[i]]){
        ans+=gifts[ptr];
        ptr++;
      }
      else{
        ans+=gifts[arr[i]];
      }
      }
      else{
         ans+=gifts[arr[i]];
      }
    }
    
   
    cout<<ans<<endl;
  }
  
  return 0;
}