    
    
    
    
    
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
        int T;
       T=1;
        

        while(T--)
        {

            ll n,m,k;

            cin>>n>>m>>k;

            ll a[m],b[k];


            for(int i=0;i<m;i++) {
                cin>>a[i];
            }

            for(int j=0;j<k;j++) {
                cin>>b[j];
            }

            vector<pair<ll,ll>> v;

            for(int i=0;i<m;i++) {
                ll c=0;
                for(int j=0;j<k;j++) {
                    if((b[j])%a[i]==0) {
                        c++;
                    }
                }
                v.eb(mp(c,i+1));
            }


            sort(v.begin(),v.end());

            int g=0;

            for(int i=0;i<v.size();i++) {
                if(v[i].f==v[0].f) {
                    g++;
                }
                else {
                    break;
                }
            }

            cout<<g<<endl;

            for(int i=0;i<v.size();i++) {
                if(v[i].f==v[0].f) {
                    cout<<v[i].s<<" ";
                }
                else {
                    break;
                }
            }
            
        }
        return 0;
    }