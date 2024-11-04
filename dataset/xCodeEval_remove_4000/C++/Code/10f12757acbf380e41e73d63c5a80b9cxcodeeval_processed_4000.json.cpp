    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    
    

    

    
    
    
    
    using namespace std;
    
    pa p[N];
    int data[N];
    int _pow(int a,int b)
    {
       if(!b) return 1;
       int ans=a;
       REP(i,1,b){
       ans*=a;
       }
       return ans;
    }
    int main()
    {
       int n,k;
       scann(n,k);
       int m=n/k;
       REP(i,0,m){
       scan(p[i].x);
       }
       REP(i,0,m){
       scan(p[i].y);
       }
       LL ans=1;
       REP(i,0,m){
       int sum=(_pow(10,k)-1)/p[i].x+1;
       

       if(p[i].y==0){
         sum--;
         sum-=(_pow(10,k-1)-1)/p[i].x;
         data[i]=sum;
         continue;
       }
       int l=p[i].y*_pow(10,k-1)-1;
       int r=(p[i].y+1)*_pow(10,k-1)-1;
       sum-=(r/p[i].x-l/p[i].x);
       data[i]=sum;
      

       }
       REP(i,0,m){
       ans=ans*data[i]%mod;
       }
       printf("%lld\n",ans);
    }
    



    




    

    

    


    

    

    

    

   




    


    


