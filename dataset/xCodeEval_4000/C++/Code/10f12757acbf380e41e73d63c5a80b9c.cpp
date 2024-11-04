    #include <stdio.h>
    #include <string.h>
    #include <iostream>
    #include <algorithm>
    #include <stack>
    #include <vector>
    #include <queue>
    #include <set>
    #include <map>
    #include <string>
    #include <cmath>
    #include <cstdlib>
    #include <ctime>
    #define REP(i,k,n) for(int i=k;i<n;i++)
    #define REPP(i,k,n) for(int i=k;i<=n;i++)
    #define scan(d) scanf("%d",&d)
    #define scann(n,m) scanf("%d%d",&n,&m)
    #define mst(a,k)  memset(a,k,sizeof(a));
    #define LL long long
    #define eps 1e-8
    #define mod 1000000007
    #define INF 0x6f6f6f6f
    #define ls (g<<1)
    #define rs (g<<1|1)
    

    #define PI acos(-1.0)
    

    #define max(a,b) a>b?a:b  

    #define pa pair<int,int>
    #define ppap pair<int,pa>
    #define x first
    #define y second
    using namespace std;
    #define N 100005
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
    



    




    

    

    


    

    

    

    

   




    


    


