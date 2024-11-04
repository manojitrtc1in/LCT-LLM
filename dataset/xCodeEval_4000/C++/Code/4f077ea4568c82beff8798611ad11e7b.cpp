      
      
      
      
      
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

      #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
      #endif


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