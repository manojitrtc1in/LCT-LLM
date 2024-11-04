    
    
    
    
    
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

            int x,k;

            cin>>x>>k;

            int a[x+1]={0};

            while(k--) {
                int ar;
                cin>>ar;

                if(ar==1) {
                    int g,h;
                    cin>>g>>h;
            
                   a[g]=1;
                   a[h]=1;
                }

                else {
                    int y;
                    cin>>y;
                   a[y]=1;
                }
            }

            int i=1;


            int min_ans=0;
            int max_ans=0;

            while(i<x) {
                if(a[i]==0) {
                    if(i+1<x&&a[i+1]==0) {
                        a[i]=1;
                        a[i+1]=1;min_ans++;
                        max_ans+=2;
                        i+=2;
                    }

                    else {
                        a[i]=1;
                        max_ans++;
                        min_ans++;
                        i++;
                    }
                }

                else i++;
            }


            cout<<min_ans<<" "<<max_ans;
            
        }
        return 0;
    }