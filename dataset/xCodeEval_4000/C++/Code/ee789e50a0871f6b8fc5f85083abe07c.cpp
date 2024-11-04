      
      
      
      
      
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

                  int a[n][m];

                  for(int i=0;i<n;i++) {
                        for(int j=0;j<m;j++) {
                              cin>>a[i][j];
                        }
                  }

                  int b[n][m];

                  for(int i=0;i<n;i++) {
                        for(int j=0;j<m;j++) {
                              cin>>b[i][j];
                        }
                  }


                  for(int i=0;i<n;i++) {
                        for(int j=0;j<m;j++) {
                              if(a[i][j]<=b[i][j]) {
                                    swap(a[i][j],b[i][j]);
                              }
                        }
                  }

                  
               

                    for(int i=0;i<n;i++) {
                        for(int j=0;j<m-1;j++) {
                              if(a[i][j]>=a[i][j+1]) {
                                    cout<<"Impossible";
                                    return 0;
                              }
                        }
                  }

                   for(int j=0;j<m;j++) {
                        for(int i=0;i<n-1;i++) {
                              if(a[i][j]>=a[i+1][j]) {
                                    cout<<"Impossible";
                                    return 0;
                              }
                        }
                  }




                    for(int i=0;i<n;i++) {
                        for(int j=0;j<m-1;j++) {
                              if(b[i][j]>=b[i][j+1]) {
                                    cout<<"Impossible";
                                    return 0;
                              }
                        }
                  }



                  for(int j=0;j<m;j++) {
                        for(int i=0;i<n-1;i++) {
                              if(b[i][j]>=b[i+1][j]) {
                                    cout<<"Impossible";
                                    return 0;
                              }
                        }
                  }


                  cout<<"Possible";
            }
            return 0;
      }