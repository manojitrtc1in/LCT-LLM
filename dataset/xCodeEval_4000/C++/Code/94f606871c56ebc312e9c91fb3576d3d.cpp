
#include<bits/stdc++.h>
using namespace std;
#define lli             long long int
#define ios             ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define tst             cin>>t;while(t--)
#define nl              cout<<"\n"
#define for1(i,b)       for(int i=0;i<b;i++)
#define for2(i,a,b)     for(int i=a;i<b;i++)
#define str             string
#define max2(a,b)       a>b?a:b
#define max3(a,b,c)     a>(max2(b,c))?a:max2(b,c)
#define max4(a,b,c,d)   a>( max3(b,c,d) )?a:max3(b,c,d)
#define min2(a,b)       a<b?a:b
#define min3(a,b,c)     a<(min2(b,c))?a:min2(b,c)
#define min4(a,b,c,d)   a<( min3(b,c,d) )?a:min3(b,c,d)
#define swp(a,b)        a=a+b,b=a-b,a=a-b;
#define co				cout<<
#define cn				cin>>

int main(){
    ios;
    int t,n;
    tst{
        cn n;
        for2(i,1,n+1){
            if (i==1)co n<<" ";
            else co i-1<<" ";
        }
        nl;
    }
    return 0;
}

	    	 			     	 	 				    	 	