    
    
    
    
    
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

            int n;

            cin>>n;

            map<int,float> mp1;

            map<float,int> mp2;

            for(int i=0;i<n;i++) {

            char c,d,e,f;
            float a,b,x;

            cin>>c>>a>>d>>b>>e>>f>>x;

            mp1[i+1]=(a+b)/x;

            mp2[(a+b)/x]++;

            }


            for(auto x:mp1) {
                cout<<mp2[x.s]<<" ";
            }



            
        }
        return 0;
    }