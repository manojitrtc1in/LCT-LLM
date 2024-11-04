
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void Ahmed_Saber()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
long long gcd(long long n)
{
    long long sum=0;
    while(n!=0)
    {
        sum=sum+(n%10);
        n=n/10;
    }
    return sum;
}
long long get_gcd(long long n , long long digit)
{
    long long x=0;
    for(int i=1;i<=digit;++i)
    {
        if(n%i==0&&digit%i==0)
        {
            x = i;
        }
    }
    return x;
}
typedef long long ll;
bool get_prime(ll n)
{
    if(n==0||n==1)return false;
    else if(n ==2)return true;
    else
    {for(int i=2;i<n;++i)
    {
        if(n%i==0)
            return false;
    }
    }
    return true;
}
map<ll,ll>mp;
int main()
{
    Ahmed_Saber();
    
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,c,x,y;
        cin>>a>>b>>c>>x>>y;
        if(a>=x)
        {
            if(b>=y)
                cout<<"YES"<<"\n";
            else if(c+b>=y)
                cout<<"YES"<<"\n";
            else
                cout<<"NO"<<"\n";
        }
        else if(b>=y)
        {
            if(a>=x)
                cout<<"YES"<<"\n";
            else if(c+a>=x)
                cout<<"YES"<<"\n";
            else
                cout<<"NO"<<"\n";
        }
        else
        {
            if(c>=(x-a)+(y-b))
                cout<<"YES"<<"\n";
            else
                cout<<"NO"<<"\n";
        }

    }
}
