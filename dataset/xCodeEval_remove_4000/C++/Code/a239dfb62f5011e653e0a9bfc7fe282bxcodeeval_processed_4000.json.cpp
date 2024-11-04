
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
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
            

            int n;


            cin>>n;

            int m=n;

            vector<int> v1,v2;

            while(n--) {
                int a,b;
                cin>>a>>b;
                
                v1.eb(a);
                v2.eb(b);

            }

            n=m;

           sort(v1.begin(),v1.end());
           sort(v2.begin(),v2.end());

           int x=v1[n-1]-v1[0];
           int y=v2[n-1]-v2[0];

           cout<<(x>y?x*x:y*y);

        }
        return 0;
    }
