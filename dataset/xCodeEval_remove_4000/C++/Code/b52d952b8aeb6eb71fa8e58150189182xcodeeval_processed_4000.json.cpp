    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
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

            int sum=0;

            sum=accumulate(a,a+n,sum);

            int sum1=0;

            int c=0;


            for(int i=0;i<n-1;i++) {
                if(sum1+a[i]==sum-a[i]) {
                    c++;
                }
                 sum-=a[i];
                 sum1+=a[i];
            }

            cout<<c;


            
        }
        return 0;
    }