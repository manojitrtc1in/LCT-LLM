      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      using namespace std;
      int main()
      {

      
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
      


            std::ios::sync_with_stdio(false);
            int T=1;
            

            while(T--)
            {
                  
                  int n,v;

                  cin>>n>>v;

                  vector<pair<int,int>> vp;

                  for(int i=0;i<n;i++) {
                        int a,b;
                        cin>>a>>b;
                        vp.eb(mp(a,b));
                  }


                  sort(vp.begin(),vp.end());


                  vector<pair<int,int>> vp1;


                  for(int i=0;i<vp.size();i++) {
                        int a=vp[i].f;
                        int b=vp[i].s;

                        int sum=b;

                        for(int j=i+1;j<vp.size();j++) {
                              if(vp[j].f==a) {
                                    sum+=vp[j].s;
                              }

                              else {
                                    i=j-1;
                                    break;
                              }
                        }

                        vp1.eb(mp(a,sum));

                  }

                  vp1=vp;


                  int fld=0;

                  int ans=0;

                  for(int i=1;i<=3001;i++) {
                        int cd=0;

                        for(int j=0;j<vp1.size();j++) {
                              if(vp1[j].f==i) {
                                    cd+=vp1[j].s;
                              }
                        }

                        if(cd+fld<=v) {
                              ans+=cd+fld;
                              fld=0;
                        }

                        else {
                              ans+=v;
                              int tv=v-fld;
                              if(tv<0) {
                                    tv=0;
                              }
                              fld=cd-tv;
                        }
                  }

                  cout<<ans;
                  
            }
            return 0;
      }