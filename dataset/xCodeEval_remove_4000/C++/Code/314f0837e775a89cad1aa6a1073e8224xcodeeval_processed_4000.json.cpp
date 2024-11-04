    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    using namespace std;
    int main()
    {

    
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    


        std::ios::sync_with_stdio(false);
        int T=1;


        int n;

        cin>>n;

        int a[n];

        for(int i=0;i<n;i++) {
            cin>>a[i];
        }


        int k=*max_element(a,a+n);

        int b[k+1]={0};

        for(int i=0;i<n;i++) {
            b[a[i]]++;
        }

        for(int i=2;i<k+1;i++) {
           

            if(b[i]>b[i-1]) {
                cout<<-1;
                return 0;
            }
        }


        cout<<b[1]<<endl;

        for(int i=0;i<n;i++) {
            cout<<b[a[i]]<<" ";
            b[a[i]]--;
        }

        return 0;
    }