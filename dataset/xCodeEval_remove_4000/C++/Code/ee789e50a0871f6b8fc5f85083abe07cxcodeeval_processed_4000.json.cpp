      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      using namespace std;
      signed main()
      {

      
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
      


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