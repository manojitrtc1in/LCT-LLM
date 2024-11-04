    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
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

            int a[n];

            int b[m];


            for(int i=0;i<n;i++) {
                cin>>a[i];
            }

            for(int j=0;j<m;j++) {
                cin>>b[j];
            }


            vector<int> v;

            for(int i=0;i<m;i++) {
                v.eb(a[b[i]-1]);
                a[b[i]-1]=0;
            }

            int sum=0;


            for(int i=0;i<n;i++) {
                sum+=a[i];
            }

            if(sum==0) {
                sort(v.begin(),v.end(),greater<int>());

                for(int i=0;i<v.size();i++) {
                    if(sum<v[i]) {
                        sum+=v[i];
                    }

                    else {
                        sum=sum*2;
                    }
                }

            }

            else {
               sort(v.begin(),v.end(),greater<int>());

               for(int i=0;i<v.size();i++) {
                if(sum<v[i]) {
                    sum+=v[i];
                }
                else {
                    sum*=2;
                }
               }
            }


            cout<<sum;

            
        }
        return 0;
    }