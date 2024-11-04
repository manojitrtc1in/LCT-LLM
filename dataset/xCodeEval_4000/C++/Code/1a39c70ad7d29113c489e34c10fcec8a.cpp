    
    
    
    
    
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

            int m;

            cin>>m;

            int q[m];

            for(int i=0;i<m;i++) {
                cin>>q[i];
            }

            int n;

            cin>>n;

            int a[n];

            for(int j=0;j<n;j++) {
                cin>>a[j];
            }

            sort(a,a+n,greater<int>());

            sort(q,q+m);

            int c=0;

            for(int i=0;i<n;i++) {  

                int f=q[0];

                for(int j=i;j<n;j++) {
                    if(f>0) {
                        f--;
                        c+=a[j];
                    }

                    else {
                        break;
                    }
                }

                i=i+q[0]-1;

                int t=2;

                while(t>0&&i<n) {
                    t--;
                    i++;
                }

            }

            cout<<c;


            
        }
        return 0;
    }