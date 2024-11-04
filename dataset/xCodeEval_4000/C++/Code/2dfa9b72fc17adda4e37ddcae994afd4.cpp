




























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld=long double;
ll mod(ll a)
{
    if(a>=0)
    {
        return a;
    }
    else
    {
        return -a;
    }
}

ll gcd(ll a, ll b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
}

ll lcm(ll a,ll b)
{
    return (a*b)/gcd(a,b);
}

ll factorial(ll n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    else
    {
        return n*factorial(n-1);
    }
}

ll binarysearcharr(ll arr[],ll lowindex,ll sizeofarr,ll num)
{
    ll mid=lowindex+(sizeofarr-1)/2;
    if(lowindex<=sizeofarr && mid<sizeofarr)
    {
        if(arr[mid]==num)
        {
            return mid;
        }
        else if(arr[mid]>num)
        {
            return (binarysearcharr(arr,lowindex,mid-1,num));
        }
        else
        {
            return (binarysearcharr(arr,mid+1,sizeofarr,num));
        }
    }
    else
    {
        return -1;
    }
}

ll primefactors(ll n)
{
    ll numofprimefactors=0;
    if (n%2==0)
    {
        while (n%2==0)
        {
            n=n/2;
        }
        numofprimefactors++;
    }
    for (ll i = 3; i*i <= n; i=i+2)
    {
        if (n%i==0)
        {
            while (n%i==0)
            {
                n=n/i;
            }
            numofprimefactors++;
        }
    }
    if (n>1)
    {
        numofprimefactors++;
    }
    return numofprimefactors;
}

ll factors(ll n)
{
    ll numoffactors=0;
    for (ll i = 1; i*i <= n; i++)
    {
        if (n%i==0 && i*i==n)
        {
            numoffactors++;
            break;
        }
        else if(n%i==0)
        {
            numoffactors+=2;
        }
    }
    return numoffactors;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    t=1;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        map<char,ll>m;
        ll x=0;
        ll cnt=0;
        for (ll i = 0; i < s.size(); i++)
        {
            m[s[i]]++;
            if (m[s[i]]>1)
            {
                cnt=cnt+i-x-1;
                x=i+1;
                m.clear();
            }
        }
        cout<<cnt+s.size()-x<<"\n";
    }
}