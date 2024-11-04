    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
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
            
            int n;
            float v;

            cin>>n>>v;

            float a[n],b[n];

            for(int i=0;i<n;i++) {
                cin>>a[i];
            }

            for(int i=0;i<n;i++) {
                cin>>b[i];
            }

            
            float h=10000000;


            for(int i=0;i<n;i++) {
                h=min(h,b[i]/a[i]);
            }

            float sum=0;

            for(int i=0;i<n;i++) {
                sum+=(a[i]*h);
            }

            cout<<fixed<<setprecision(4)<<min(v,sum);

        }
        return 0;
    }