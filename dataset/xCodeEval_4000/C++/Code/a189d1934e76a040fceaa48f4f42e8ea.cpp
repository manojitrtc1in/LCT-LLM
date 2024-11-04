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
#define forn(i,n) \
for(int i = 0; i < int(n); i++)
#define GS generateSubsets
				

#define GP generatePermutations
				

#define PF primeFactorization
				

main()
{
	fast;
	ll a,b,n,xmin,xmax,ymin,ymax,ans;
	cin>>n;
	cin>>a>>b;
	xmin=a;xmax=a;ymin=b;ymax=b;
	for (ll i=0;i<n-1;i++)
    {
        cin>>a>>b;
        if (a<xmin)
            xmin=a;
        else if (a>xmax)
            xmax=a;
        if (b<ymin)
            ymin=b;
        else if (b>ymax)
            ymax=b;
    }
    ans=pow(max(ymax-ymin,xmax-xmin),2);
    cout<<max(ymax-ymin,xmax-xmin)*max(ymax-ymin,xmax-xmin);
}

