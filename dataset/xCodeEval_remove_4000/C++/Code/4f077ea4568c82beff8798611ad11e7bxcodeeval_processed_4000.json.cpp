      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      using namespace std;

      bool isprime(int n) {

            if(n==2) {
                  return 1;
            }

            else {
                  for(int i=2;i*i<=n;i++) {
                        if(n%i==0) {
                              return 0;
                        }
                  }

                  return 1;
            }



      }

      int main()
      {

      
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
      


            std::ios::sync_with_stdio(false);
            int T=1;
            
            

            while(T--)
            {
                  
                  int n;

                  cin>>n;

                  int a[n];


                  for(int i=0;i<n;i++) {
                        cin>>a[i];
                  }

                  if(n==1) {
                        cout<<1;
                        return 0;
                  }


                  map<int,int> mp;


                  for(int i=0;i<n;i++) {

                        int y=a[i];

                        for(int j=1;j*j<=y;j++) {
                              if(y%j==0) {
                                    if(y/j==j) {
                                          mp[j]++;
                                    }
                                    else {
                                        if(j!=1){
                                          mp[j]++;
                                        } 
                                          mp[y/j]++;
                                    }
                              }
                        }

                  }

                  int c=INT_MIN;

                  for(auto x:mp) {
                        c=max(c,x.s);
                  }

                  if(c==mp[1]) {
                        cout<<1;
                  }

                  else {
                        cout<<c;
                  }

                  
            }
            return 0;
      }