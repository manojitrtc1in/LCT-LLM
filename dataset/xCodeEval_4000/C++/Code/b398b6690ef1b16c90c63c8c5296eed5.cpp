#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int, int>
#define F first
#define S second
#define all(C) (C).begin(), (C).end()
#define fio ios_base::sync_with_stdio(0), cin.tie(0)
 #include<bits/stdc++.h>
using namespace std;


#define ss second
#define ff first
#define pb push_back
 #include<bits/stdc++.h>






#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mii map<int,int>
#define si set<int>


#define s second
#define all(v) v.begin(),v.end()
#define set_bits __builtin_popcount
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define ninf LLONG_MIN
#define inf LLONG_MAX


#define endl '\n'
#define nln cout<<endl;
using namespace std;
int tc = 1;
#include <bits/stdc++.h>
  #include <bits/stdc++.h>
  #include <cstdio>
  #include <cstring>
  #include <cmath>
  #include <chrono>
 
  #include <bits/stdc++.h>
using namespace std;








using ll= long long;
using lld= long double;
using ull= unsigned long long;


const lld pi= 3.141592653589793238;
const ll INF= 1e18;
const ll mod=1e9+7;


typedef pair<ll, ll> pll;


typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll,ll> umll;
typedef map<ll,ll> mll;


#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define fl(i,n) for(int i=0;i<n;i++)
#define rl(i,m,n) for(int i=n;i>=m;i--)
#define vr(v) v.begin(),v.end():
#define rv(v) v.end(),v.begin()
#include <complex>
#define endl "\n"
#define ll long long
#define lli long long int
#define vi vector<int>
#define vs vector<string>
#define vll vector<ll>
#define vvi vector < vi >
#define vpll vector<pair<ll,ll>>
#define pii pair<int,int>
#define mii map<int,int>
#define pll pair<ll, ll>
#define PI 3.141592653589793238462
#define mod 998244353
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define pb push_back
#define ppb pop_back
#define pf  push_front
#define ppf pop_front
#define go(i,n) for(ll i=0;i<n;i++)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define repe(i,a,b) for(ll i=a;i<=b;i++)
#define dep(i,a,b) for(ll i=a; i>=b; i--)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define dne cout<<-1<<endl
using namespace std;
 
 
 
 
 


  

 
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long T,n,l,r,fac[200005],ifac[200005];
long long power(long long a,long long b) {
	long long res=1;
	while(b) {
		if(b&1) res=(res*a)%mod; 


  

 
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}
long long C(long long a,long long b) {
	if(a<b||a<0||b<0) return 0;
	return ((fac[a]*ifac[b])%mod*ifac[a-b])%mod; 


  

 
}
signed main() {
	cin >> T;
	fac[1]=ifac[1]=fac[0]=ifac[0]=1;
	for(long long i=2; i<=200000; i++) {
		fac[i]=(fac[i-1]*i)%mod;
		ifac[i]=power(fac[i],mod-2); 


  

 
	}
	for(int i=1;i<=T;++i) {
		cin>>n>>l>>r;
		long long queryanswer=0;
		long long k=min(1-l,r-n);
		queryanswer=(queryanswer+k*C(n,n/2)%mod)%mod;
		if(n%2==1) queryanswer=(queryanswer+k*C(n,n/2)%mod)%mod;
		for(long long i=k+1; i<=k+n-1; i++) { 


  

 
			long long tempvarlonglong1,tempvarlonglong2;
			if(l-1+i<0) tempvarlonglong1=0;
			else
				tempvarlonglong1=l-1+i;
			if(n+i-r<0) tempvarlonglong2=0; 


  

 
			else
				tempvarlonglong2=n+i-r;
			if(tempvarlonglong1+tempvarlonglong2>n||tempvarlonglong1>(n+n%2)/2||tempvarlonglong2>(n+n%2)/2) break;
				queryanswer=(queryanswer+C(n-tempvarlonglong1-tempvarlonglong2,n/2-tempvarlonglong1)%mod)%mod; 


  

 
			if(n%2!=0) 
				queryanswer=(queryanswer+C(n-tempvarlonglong1-tempvarlonglong2,(n+1)/2-tempvarlonglong1)%mod)%mod;
		}
		cout << queryanswer << endl; 


  

 
	}
	return 0; 


  

 
} 


  

 