



























































































 




 




 






 


 










 




 


















 




 






 














 




 




 









#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define vll vector<ll>
#define vpl vector<pair<ll, ll>>
#define all(x) x.begin(), x.end()
#define fr(n) for(ll i=0;i<(n);i++)
#define frr(k, n) for(ll j=(k); j<(n); j++)
#define lcm(a,b) (a*b)/__gcd(a,b)
#define lz(x) __builtin_clz(x)
#define endl "\n"
#define ff first
#define ss second
using namespace std;
mt19937 rng((ll)std::chrono::steady_clock::now().time_since_epoch().count());
const ll N=1e9+7;






























 
int main(){
ios_base :: sync_with_stdio(false);
cin.tie(nullptr);
int t=1;
cin>>t;
while(t--){









int n;
cin >> n; 
string s;
cin >> s;
int ans = 0;
int ex = 228;
fr(n)
{
    int chk  = 0;
    

    vector<int> a(10, 0);
    for(int j = i; j < n and j<i+ex; j++)
    {
        int k = s[j] - '0';
        if(a[k] == 0)
        {
            chk++;
        }
        a[k]++;
        if(chk >= *max_element(a.begin(),a.end()))
        {
            ans++;
        }
        else
        {
            continue;
        }
    }
}
cout << ans << endl;
}
return 0;
}
