#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>


using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
typedef long int l;
typedef long double ld;
extern const int primes[];
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define stringtochararray \
string s;cin>>s;int n=s.length();char a[n+1];strcpy(a,s.c_str());
#define PB push_back
#define F first
#define S second
#define PT palindromeTest
#define GS generateSubsets
				

#define GP generatePermutations
				

#define PF primeFactorization
				

main()
{
	fast;
	ll a,n,b,d,sum=0,ans=0;
	cin>>n>>b>>d;
	for (ll i=0;i<n;i++)
    {
        cin>>a;
        if (a<=b)
            sum+=a;
        if (sum>d)
        {
            ans+=1;
            sum=0;
        }
    }
    cout<<ans;
}

