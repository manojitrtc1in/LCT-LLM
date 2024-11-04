    
    
    
    
    
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


            string a;
            cin>>a;

            int m=a.length();

            char c[n][m];

            for(int i=0;i<m;i++) {
                c[0][i]=a[i];
            }

            for(int i=1;i<n;i++) {
                string f;
                cin>>f;
                for(int j=0;j<m;j++) {
                    c[i][j]=f[j];
                }
            }


            string p="";

            for(int i=0;i<m;i++) {
               vector<char> v;
               char t;
               for(int j=0;j<n;j++) {
                v.eb(c[j][i]);
                if(c[j][i]!='?') {
                    t=c[j][i];
                }
               }


               if(count(v.begin(),v.end(),'?')==n) {
                p+='x';
               }

               else {
                if(count(v.begin(),v.end(),t)+count(v.begin(),v.end(),'?')==n) {
                    p+=t;
                }

                else {
                    p+='?';
                }
               }

            }


            cout<<p;

        }
        return 0;
    }