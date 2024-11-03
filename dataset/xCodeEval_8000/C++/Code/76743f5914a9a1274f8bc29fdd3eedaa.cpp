
#include<bits/stdc++.h>

using namespace std;


#define loop(i,a,n)     for(int i=a;i<n;i++)
#define rloop(i,n,a)    for(int i=n;i>=a;i--)
#define all(v)          v.begin(),v.end()
#define all(v)          v.begin(),v.end()
#define p(a)            cout<<a<<" ";
#define check           cout<<"OOOOOF"<<endl;
#define inf             2e9+5
#define Q               int q;cin>>q;while(q--)


int main()
{

    

    

    int n;
    cin >> n;

    long long a[n+5],b[n+5]= {0};
    loop(i,0,n)cin >> a[i],b[i]=a[i];
    

    

    rloop(i,n-2,0)b[i]+=b[i+1];


    loop(i,1,n)a[i]+=a[i-1];

    int j = n-1;
    long long m=0;
    if(n==1)
    {
        cout<<0<<endl;
        return 0 ;
    }
    loop(i,0,n)
    {
        if(i>=j)
            break;
        if(a[i]==b[j])
        {
            if(a[i]>m)
                m=a[i];
            j--;
        }
        else if(a[i]>b[j])
            i--,j--;


        


    }


    cout<<m<<endl;

    


}

