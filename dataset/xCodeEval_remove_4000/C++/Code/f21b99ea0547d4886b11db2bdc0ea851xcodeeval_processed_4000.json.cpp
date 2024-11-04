      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      using namespace std;
      int main()
      {

      
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
      


            std::ios::sync_with_stdio(false);
            int T;
            T=1;
            

            while(T--)
            {

                  int n,m,k;

                  cin>>n>>m>>k;

                

                  vector<int> v;


                  for(int i=0;i<k;i++) {
                        int y;
                        cin>>y;
                        v.eb(y);
                        

                  }


                 int sum=0;

                  while(n>0) {

                         int c=0;

                         int r;
                       
                       for(int i=0;i<m;i++) {
                                    cin>>r;

                                   for(int i=0;i<v.size();i++) {
                                    if(v[i]==r) {
                                          c+=(i+1);
                                          break;
                                    }
                                   }


                                    vector<int> y;

                                    y.eb(r);

                                    for(int i=0;i<v.size();i++) {
                                          if(v[i]!=r) {
                                                y.eb(v[i]);
                                          }
                                    }

                                    v=y;

                       }



                       sum+=c;
                       n--;

                  }



                  cout<<sum;
                  
            }
            return 0;
      }