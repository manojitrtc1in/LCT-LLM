#include <bits/stdc++.h>
using namespace std;
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vl vector<ll>
#define vi vector<int>
#define lb lower_bound
#define ub upper_bound
#define all(x) (x).begin(), (x).end()
typedef int64_t ll;
typedef unsigned long long ull;
typedef long double lld;
#define pi pair<ll, int>


#ifndef Oendl_JUDGE
#else
#define debug(x)
#endif
void _yint(ll t)
{
        cerr << t;
}






































bool yime[100000];
ll gcd(ll a, ll b)
{
        if (b == 0)
                return a;
        return gcd(b, a % b);
}
void SieveOfEratosthenes()
{
        memset(yime, true, sizeof(yime));
        for (int p = 2; p * p <= 100000; p++)
        {
                if (yime[p] == true)
                {
                        for (int i = p * p; i <= 100000; i += p)
                                yime[i] = false;
                }
        }
}
long long binpow(long long a, long long b)
{
        a %= MOD;
        long long res = 1;
        while (b > 0)
        {
                if (b & 1)
                        res = res * a % MOD;
                a = a * a % MOD;
                b >>= 1;
        }
        return res % MOD;
}
ll invmd(ll n)
{
        return (binpow(n, MOD - 2));
}
ll ceil2(ll a, ll b)
{
        return (a + b - 1) / b;
}



























ll factorial(int n)
{
        ll fact = 1;
        rep(i, 2, n + 1)
            fact = fact * i;
        return fact;
}

ll diff(string s1, string s2)
{
        int a = s1.size();
        int sum = 0;
        rep(i, 0, a)
        {
                sum += abs(s2[i] - s1[i]);
        }
        return sum;
}

void solve()
{
        

        

        

        

        

        


        

        

        

        

        

        

        

        

        

        

        

        


        

        

        

        

        

        


        

        


        

        

        


        

        

        

        

        

        

        

        


        

        

        


        

        

        

        

        

        

        

        

        

        


        

        

        

        

        

        

        

        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        

        

        

        

        

        

        

        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        

        

        

        

        


        

        

        

        

        

        

        

        

        

        

        

        

        


        

        

        

        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        

        

        


        

        

        

        

        

        

        

        


        

        

        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        

        

        

        


        

        

        

        

        

        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        

        

        

        

        

        

        

        


        


        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        

        

        

        

        

        


        


        

        

        

        


        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        

        

        

        

        

        

        

        

        

        


        

        

        

        

        

        

        


        


        

        

        

        

        


        

        

        

        

        

        

        

        

        

        

        


        

        

        

        

        

        

        

        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        

        

        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        

        

        

        


        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        

        

        


        

        

        

        

        

        

        

        

        

        

        

        

        


        


        

        

        


        

        

        

        

        

        

        

        


        

        


        


        

        

        

        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        


        


        

        

        

        

        


        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        

        

        

        


        


        

        

        

        


        

        

        

        

        

        

        

        

        

        

        

        

        

        


        


        

        

        

        

        


        

        

        

        

        

        

        

        

        

        

        

        


        


        

        

        

        

        

        


        


        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        


        

        

        


        


        

        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        













        
        


        

        

        


        


        

        

        

        

        

        


        


        

        

        


       




































        














































    































       
       











        




















         
        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        




























          
        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        

        

        

        

        

        


        


        

        

        

        

        


        


        

        


        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        

        

        

        

                

                

                

                

                

                

                

                

                


        


        

        

        


        


        

        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        





































            
        


        

        

        

        

        


        


        


        


        

        

        

        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

 
        

        


        

        

        

        

        

        

        

        

        

 
        

        

        

        

        

     

        


        

        

        

        


        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        

        

        

        

        


        

        
        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        
        


        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        


        

        

        


        


        

        

        

        

        


        


        

        


        


        

        

        

        

        

        

        


        


        

        


        

        

        

        

        

        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        

        

        

        

        

        

        


        

        

        

        

        

        

        

        


        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        

        

        


        


        

        

        

        

        

        

        

        

        

        

        

        


        




















































        

        

        

        

        

        

        

        


        


        

        

        

        

        



        


        

        

        

        

        

        

        

        

        

                
        

        

        

        


        

        

        

        

        

        

        

        

        

        

        

        


        


        

        

        

        

        

        



        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        























































































































        

        

        

        

        

        

        

        

        

 

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        



        


























        ll w,h;cin>>w>>h;
        ll ans=INT_MIN;
        rep(i,0,4){
                ll k;cin>>k;
                ll maxi=INT_MIN,mini=INT_MAX;
                

                while(k--){
                        ll x;cin>>x;
                        maxi=max(maxi,x);
                        mini=min(mini,x);
                }
                if(i==2) swap(h,w);
                ans=max(ans,((maxi-mini)*h));
                

                

        }
        cout<<ans<<endl;

        


}



       
int main()
{
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
#ifndef Oendl_JUDGE
#endif
        int t;
        cin >> t;
        while (t--)
        {
                solve();
        }
        return 0;
}