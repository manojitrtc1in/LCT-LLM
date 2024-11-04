     

    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    


    using namespace std;

    typedef long long ll ;
    typedef unsigned long long ull ;
    
       
    int main(){
          

        int n ; cin>>n ;
        double dpu[40005],dpd[40005];
        int one=0;
        double res=0 ;
        for(int i=0 ; i<2*n; i++){
            double x;
            cin>>x;
            
            if(x==(int)x)
                one++;
            else{
                res-=x-(int)x;
                
            dpu[i]=ceil(x)-x ;
            dpd[i]=1-dpu[i];
            }
        }
        
        res+=n-one;
       
        double mn = res>0?res:-res;
        
        for(int i=0 ; i<=one ; i++){
           

            mn=min(mn,( (res+i)>=0 ? res+i:-(res+i)) );
            
           
        }
        cout.precision(3);
            
        cout<<fixed<<mn;
        
    }
    
  
    
    
    
    
    
    
    


    