    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    using namespace std;
    signed main()
    {

    
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    


        std::ios::sync_with_stdio(false);
        int T=1;
        

        while(T--)
        {

            int n,k;

            cin>>n>>k;

            int a[n];

            for(int i=0;i<n;i++) {
                cin>>a[i];
            }

            int pg;

            cin>>pg;

            int b[n];

            for(int i=0;i<n;i++) {
                cin>>b[i];
            }

            int c=0;

            vector<int> v;

            for(int i=0;i<n;i++) {
                if(a[i]<=k) {
                    v.push_back(b[i]);
                    sort(v.begin(),v.end());
                    continue;
                }

                else {

                    v.push_back(b[i]);

                    sort(v.begin(),v.end());

                   
                        while(k<a[i]&&v.size()>0) {
                            c+=v[0];
                            k+=pg;
                            v.erase(v.begin(),v.begin()+1);
                        }

                        if(k<a[i]&&v.size()<=0) {
                            cout<<-1;
                            return 0;
                        }

                    

                }

            }

            cout<<c;
            
        }
        return 0;
    }