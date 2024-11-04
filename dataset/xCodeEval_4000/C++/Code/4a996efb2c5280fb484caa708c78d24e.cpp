    
    
    
    
    
    #include <bits/stdc++.h>
    #include <cstdio>
    #include <cstring>
    #include <cmath>
    #include <cstring>
    #include <chrono>
    #include <complex>
    #define endl "\n"
    #define int long long int
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
    signed main()
    {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif


        std::ios::sync_with_stdio(false);
        int T=1;
        

        while(T--)
        {

            int n,k;

            cin>>n>>k;

            int a[n];

            for(int i=0;i<n;i++) {
                cin>>a[i];
            }

            int pg;

            cin>>pg;

            int b[n];

            for(int i=0;i<n;i++) {
                cin>>b[i];
            }

            int c=0;

            vector<int> v;

            for(int i=0;i<n;i++) {
                if(a[i]<=k) {
                    v.push_back(b[i]);
                    sort(v.begin(),v.end());
                    continue;
                }

                else {

                    v.push_back(b[i]);

                    sort(v.begin(),v.end());

                   
                        while(k<a[i]&&v.size()>0) {
                            c+=v[0];
                            k+=pg;
                            v.erase(v.begin(),v.begin()+1);
                        }

                        if(k<a[i]&&v.size()<=0) {
                            cout<<-1;
                            return 0;
                        }

                    

                }

            }

            cout<<c;
            
        }
        return 0;
    }