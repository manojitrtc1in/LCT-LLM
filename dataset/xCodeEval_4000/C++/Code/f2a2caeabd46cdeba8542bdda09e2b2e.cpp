
#include<iostream>
#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
#define fast cin.tie(0);cin.sync_with_stdio(0);
#define ll long long
#define sumall n(n+1)/2
#define lcm(a,b) ((a)/__gcd(a,b))*(b)
#define fs(n)   fixed<<setprecision(n)

int main()
{
    fast;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,j;
        cin>>n;
        map<ll,ll> mp;
        ll a=0;
        for(int i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            x-=i;
            if(mp.count(x))
                a+=mp[x];
            mp[x]++;
        }

        cout<<a<<endl;

    }


    return 0;
}

		   	 	  		 			 		 	    			 	