    
    
    
    
    
    #include <bits/stdc++.h>
    #include <cstdio>
    #include <cstring>
    #include <cmath>
    #include <cstring>
    #include <chrono>
    #include <complex>
    #define endl "\n"
    #define ll long long int
    #define vi vector<int>
    #define vll vector<ll>
    #define vvi vector < vi >
    #define pii pair<int,int>
    #define pll pair<long long, long long>
    #define mod 1000000007
    #define inf 1000000000000000001;
    #define all(c) c.begin(),c.end()
    #define mp(x,y) make_pair(x,y)
    #define mem(a,val) memset(a,val,sizeof(a))
    #define eb emplace_back
    #define f first
    #define s second
    
    using namespace std;
    int main()
    {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif


        std::ios::sync_with_stdio(false);
        int T=1;
       
        

        while(T--)
        {

            int n;

            cin>>n;

            int a[n];

            for(int i=0;i<n;i++) {
                cin>>a[i];
            }

            int f[n],b[n];

            for(int i=0;i<n;i++) {
                cin>>f[i];
            }

            for(int i=0;i<n;i++) {
                cin>>b[i];
            }

            set<int> s[4];

            for(int i=0;i<n;i++) {
                s[f[i]].insert(a[i]);
                s[b[i]].insert(a[i]);
            }

            int m;

            cin>>m;

            for(int i=0;i<m;i++) {
                int y;
                cin>>y;

                if(s[y].size()==0) {
                    cout<<-1<<" ";
                }


                else {
                   int val=*(s[y].begin());
      cout<<val<<" ";
      s[1].erase(val);
      s[2].erase(val);
      s[3].erase(val);
                }
            }
            
        }
        return 0;
    }