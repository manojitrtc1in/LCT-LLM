



#include<bits/stdc++.h>
using namespace std;

#define fi              first
#define se                   second
#define ll             long long
#define pb              push_back
#define mp              make_pair
#define pll             pair<ll,ll>
#define vll              vector<int>
#define mll             map<ll,ll>
#define pqg             priority_queue<ll>
#define pqs             priority_queue<ll,vll,greater<ll> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define md             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
const int MAX_CHAR = 256;
void hi()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    

    #endif
}
void bye()
{
    #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
    #endif
}
int main() 
{
    int t;
    cin>>t;
    while(t--)
	{
        ll n,a2=0;
        cin>>n;
        ll a[(int)n];
        for(int i=0;i<n;i++)
        {
            ll a;
            cin>>a;  
            if(i%2==0)
            {
                if(a<0)
                    cout<<-a<<" ";
                else
                {
                    cout<<a<<" ";
                }
            }
            else if(i%2!=0)
            {
                if(a<0)
                    cout<<a<<" ";
                else
                {
                    cout<<-a<<" ";
                }
                
            } 
            cout<<endl;
        }
    }
    return 0;
}