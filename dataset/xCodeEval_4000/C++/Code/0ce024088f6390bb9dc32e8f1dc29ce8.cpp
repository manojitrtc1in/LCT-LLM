  

  

    
    
    
    
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
            int n,m;

            cin>>n>>m;

            if((n-1)<=m&&m<=2*(n+1)) {
               int n2 = m-n;
        int id =0;
        for(int i=0;i<n;i++){
            if(i!=0 || (i==0 && m+1!=n))cout<<'1';
            if(n2>0){cout<<"1";n2--;}
            cout<<"0";
        }
        while(n2>0){
            cout<<"1";
            n2--;
        }
            }

            else {
                cout<<-1;
            }
            
        }
        return 0;
    }