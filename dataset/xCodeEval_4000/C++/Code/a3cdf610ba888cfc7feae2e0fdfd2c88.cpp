    
    
    
    
    
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
        int T;
        T=1;
        

        while(T--)
        {

            int n,m;

            cin>>n>>m;

            int a[n];

            int b[m];


            for(int i=0;i<n;i++) {
                cin>>a[i];
            }

            for(int j=0;j<m;j++) {
                cin>>b[j];
            }


            vector<int> v;

            for(int i=0;i<m;i++) {
                v.eb(a[b[i]-1]);
                a[b[i]-1]=0;
            }

            int sum=0;


            for(int i=0;i<n;i++) {
                sum+=a[i];
            }

            if(sum==0) {
                sort(v.begin(),v.end(),greater<int>());

                for(int i=0;i<v.size();i++) {
                    if(sum<v[i]) {
                        sum+=v[i];
                    }

                    else {
                        sum=sum*2;
                    }
                }

            }

            else {
               sort(v.begin(),v.end(),greater<int>());

               for(int i=0;i<v.size();i++) {
                if(sum<v[i]) {
                    sum+=v[i];
                }
                else {
                    sum*=2;
                }
               }
            }


            cout<<sum;

            
        }
        return 0;
    }