    
    
    
    
    
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


        int n;

        cin>>n;

        int a[n];

        for(int i=0;i<n;i++) {
            cin>>a[i];
        }


        int k=*max_element(a,a+n);

        int b[k+1]={0};

        for(int i=0;i<n;i++) {
            b[a[i]]++;
        }

        for(int i=2;i<k+1;i++) {
           

            if(b[i]>b[i-1]) {
                cout<<-1;
                return 0;
            }
        }


        cout<<b[1]<<endl;

        for(int i=0;i<n;i++) {
            cout<<b[a[i]]<<" ";
            b[a[i]]--;
        }

        return 0;
    }