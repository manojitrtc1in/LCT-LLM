#include <bits/stdc++.h>
typedef long long int ll;
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rrep(i, a, b) for (ll i = a; i >= b; i--)
#define repe(i, a, b) for (ll i = a; i <= b; i++)
#define repi(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define endl '\n'
#define sz(x) x.size()
#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define pq priority_queue
#define MOD 1000000007
#define PI 3.14159265
#define printVector(v) copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
#define printArray(arr, n) copy(arr, arr + n, ostream_iterator<int>(cout, " "));                        \
 
#define cin(vec)    for(auto &i:vec)cin>>i;
#define cout(vec)   for(auto i:vec)cout<<i<<" ";cout<<endl;
using ull = unsigned long long int;
using dd = double;
using ldd = long double;
using namespace std;
const int mod=998244353;
const int N=2e5+5;
 
 





   
   


  

  

int main()
{ 
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    
    while (t--)
    {
        int a;
        cin>>a;
        int maxx=0;
        set<int>st;
        map<int,int>freq;
        

        int arr[a];
        for (int i = 0; i < a; i++)
        {
            cin>>arr[i];
            st.insert(arr[i]);
            freq[arr[i]]++;
        }
        for(auto g:st)
        {
            

            maxx=max(maxx,freq[g]);
            

        }
        cout<<maxx<<endl;
    }
     
    }


 	 	 			  	    	         						