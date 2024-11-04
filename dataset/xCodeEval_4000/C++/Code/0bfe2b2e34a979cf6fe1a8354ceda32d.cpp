#define sf scanf
#define pf printf

#define ssf sscanf
#define spf sprintf
#define fsf fscanf
#define fpf fprintf
#define scase sf ("%d",&tc)
#define sn sf ("%d",&n)
#define whilecase while (tc--)


#define forloop for (pos=1; pos<=tc; pos++)
#define arrayloop (i=0; i<n; i++)
#define cinstr cin >> str
#define getstr getline (cin,str)
#define pcase pf ("Case %d: ",pos)
#define pii pair <int,int>
#define pb push_back
#include <stack>
#define in insert
#define llu unsigned long long
#define ll long long
#define U unsigned int


#include<iostream>
#include<algorithm>
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl








#include<iostream>
#define     fast                   ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


#include<map>
#include<string>
#include <bits/stdc++.h>


#include <cmath>
#include <vector>
#include <stack>
#include <queue>

#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl








using namespace std;


ll M=1e9+7;
const int sz=1e5+10;
const int OO=0x3f3f3f3f;
ll gcd(ll a,ll b){
    while(b!=0)
    {
        ll a2=a;
        a=b;
        b=a2%b;
    }
    return a;
}
ll lcm(ll a,ll b)
{
    return a/ gcd(a,b)*b;
}
ll mul(ll a,ll b,ll m)
{
    return ((a%m)*(b%m))%m;
}
int binaryExponentiation(int x,int n)
{
    int result=1;
    while(n>0)
    {
        if(n%2==1){result=result*x;}
        x=x*x;
        n=n/2;
    }
    return result;
}
int modularExponentiation(int x,int n,int m)
{
    int result=1;
    while(n>0)
    {
        if(n%2==1){result=(result*x)%m;}
        x=(x*x)%m;
        n=n/2;
    }
    return result;
}
ll modularExponentiation_lastmodified(ll x,ll n,ll m)
{
    ll result=1;
    while(n>0)
    {
        if(n%2==1){result=mul(result,x,m);}
        x=mul(x,x,m);
        n=n/2;
    }
    return result;
}
const int NMAX=105;





const int MAX = 1000001;
bool prime[MAX];
void solve(){
    prime[0]=prime[1]=true;
    for(int i=4;i<MAX;i+=2)prime[i]=true;

    for(int i=3;i*i<=MAX;i++)
        if(!prime[i])
            for(int j=i*i;j<MAX;j+=2*i)
                prime[j]= true;
}
const int N=3005;
ll isprime[N];
void sieve(ll n){
    for(int i=2;i<=n;++i)
    {
        if(!isprime[i]) cout<<i<<" ";
            for(int j=i;j<=n;j+=i) {
                isprime[j]++;
             

            }

    }
}
int main() {

    fast
    int t;cin>>t;
    while(t--)
    {
        int a,b,n;
        cin>>n>>a>>b;
        string s;cin>>s;
        if(b>-1)
        {
            cout<<n*(a+b)<<" \n";
            continue;
        }
        int g0=0,g1=0,an=n*a;
        g0=(s[0]=='0'),g1=(s[0]=='1');
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=s[i-1])
            {
                g0+=(s[i]=='0');
                g1+=(s[i]=='1');
            }
        }
        cout<<an+min(g0+1,g1+1)*b<<" \n";

    }
}
						 	 			 			    						  	