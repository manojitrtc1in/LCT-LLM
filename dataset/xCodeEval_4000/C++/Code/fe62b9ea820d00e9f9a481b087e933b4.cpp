    
    
    
    
    
    #include <bits/stdc++.h>
    #include <cstdio>
    #include <cstring>
    #include <cmath>
    #include <cstring>
    #include <chrono>
    #include <complex>
    #define float long double
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

            float a,b,c;

            cin>>a>>b>>c;

            float d = sqrt(b*b-4*a*c);

            float r1,r2;

            r1=-b+d;
            r2=-b-d;


            r1=r1/(2*a);

            r2=r2/(2*a);
            
            if(r1>r2) {

            cout<<fixed<<setprecision(7)<<r1<<endl;
            cout<<fixed<<setprecision(7)<<r2;
            }


            else {

            cout<<fixed<<setprecision(7)<<r2<<endl;
            cout<<fixed<<setprecision(7)<<r1;
            }

        }
        return 0;
    }