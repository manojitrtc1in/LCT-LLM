    
    
    
    
    
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

            int n;

            int l=0,r=0;

            cin>>n;

            map<int,int> mpl,mpr;

            for(int i=0;i<n;i++) {
                char c;
                int p;

                cin>>c>>p;

                if(c=='L'){
                    l++;
                    mpl[p]=l;
                }

                else if(c=='R') {
                    r++;
                    

                    mpr[p]=r;
                }

                else {

                    if(mpl[p]==0) {
                        cout<<min(r-mpr[p],l+mpr[p]-1);
                    }

                    else if(mpr[p]==0) {
                        cout<<min(l-mpl[p],r+mpl[p]-1);
                    }

                    cout<<endl;


                }
                    
            }

            
        }
        return 0;
    }