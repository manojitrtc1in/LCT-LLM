
using namespace std;
#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define ivt vector<int>
#define bvt vector<bool>
#define llvt vector<ll>
#define ullvt vector<ull>
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
inline int num1(char k) {return k-'0';}
inline ll num(string s) {ll ans=0;for (int i=s.length()-1;i>=0;i--){ans+=num1(s[i])*pow(10,s.length()-i-1);}return ans;}
int main()
{
    Fast;
    int t;cin>>t;
    while (t--)
    {
        ll s; cin>>s;
        cout<<(ll)s-(ll)pow(10,int(log10(s)))<<endl;
    }
}
