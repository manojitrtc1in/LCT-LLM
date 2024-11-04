    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    using namespace std;
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

            int f[n],b[n];

            for(int i=0;i<n;i++) {
                cin>>f[i];
            }

            for(int i=0;i<n;i++) {
                cin>>b[i];
            }

            set<int> s[4];

            for(int i=0;i<n;i++) {
                s[f[i]].insert(a[i]);
                s[b[i]].insert(a[i]);
            }

            int m;

            cin>>m;

            for(int i=0;i<m;i++) {
                int y;
                cin>>y;

                if(s[y].size()==0) {
                    cout<<-1<<" ";
                }


                else {
                   int val=*(s[y].begin());
      cout<<val<<" ";
      s[1].erase(val);
      s[2].erase(val);
      s[3].erase(val);
                }
            }
            
        }
        return 0;
    }