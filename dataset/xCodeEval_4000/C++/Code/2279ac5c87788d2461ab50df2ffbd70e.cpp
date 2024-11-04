


#include <bits/stdc++.h>
using namespace std;
typedef long long int LL ;
#define INF 0x3f3f3f3f
const int M = 1e5+12;

int a[M],suml[M],sumr[M];

int abs (int a)
{
    if(a>=0)
        return a;
    else
        return -a;
}

int main()
{
    ios::sync_with_stdio(false);
    int n,l,r,ql,qr;
    while( cin>>n>>l>>r>>ql>>qr )
    {
        suml[0]=0,sumr[n+1]=0;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            suml[i]=suml[i-1]+a[i];   

        }
        for(int i=n; i; i--)
            sumr[i]=sumr[i+1]+a[i];   


        int mini=1<<30,tem;
        for(int i=0; i<=n; i++)
        {
            

            


            if(abs(i*2-n)<=1)        tem = 0;
            else if(i>n-i)      tem = ql*(i*2-n-1);  
            else                tem = qr*(n-2*i-1) ;

            mini=min(mini,suml[i]*l + sumr[i+1]*r + tem );
            

        }
        cout<<mini<<endl;
    }
    return 0;
}






