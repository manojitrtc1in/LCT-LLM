    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
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
            int b[n];

            for(int i=0;i<n;i++) {
                cin>>a[i];
            }

            map<int,int> mp;

            for(int j=0;j<n;j++) {
                cin>>b[j];
                mp[b[j]]=j;
            }

           int i=0,j=0;

           while(i<n) {
            if(a[j]==b[i]) {
                j++;
            }

            i++;
           }
           cout<<n-j;
        
        }
        return 0;
    }