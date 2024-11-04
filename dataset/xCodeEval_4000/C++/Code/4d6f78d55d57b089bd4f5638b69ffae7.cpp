     

    #ifndef ONLINE_JUDJE

    #define _CRT_SECURE_NO_WARNINGS
    #define starttime ll start_s = clock(), pauseds_s=0
    #define PT ll paused_s = clock()
    #define CT ll continue_s = clock(); pauseds_s+=continue_s-paused_s
    #define endtime ll stop_s = clock(); cout<<"\nProcess returned 0 (0x0)   execution time : "<< (((stop_s - start_s)-pauseds_s) / double(CLOCKS_PER_SEC) * 1000)/1000<<" s\n"; system ("pause")
    #define MOD 1000000007
    #define EPS 1e-6
    #define INF 0x3fffffff
    #define Scanf(x) scanf("%i",&x)
    #define Scanff(x,y) scanf("%i %i",&x ,&y)
    #define pb push_back
    #define mp make_pair    
    #define F first
    #define S second
    #define pp cout<<endl; system("pause");
    #define pm cout<<endl; system("pause");main();
    #define autoo(m) for (auto dd : m) printf("%i", dd) ;
    #define PQ priority_queue

    #endif

    #include<iostream>
    #include<sstream>
    #include<fstream> 
    #include<map>
    #include<cmath>
    #include<math.h>
    #include<vector>
    #include<algorithm>
    #include<iomanip>
    #include<cmath>
    #include<stack>
    #include<set>
    #include<string>
    #include<queue>
    #include<deque>
    #include<complex>
    #include<cstdio>
    #include <cstring>
    #include<bitset>
    #include <time.h>
    #include <ctime>
    


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
    
  
    
    
    
    
    
    
    


    