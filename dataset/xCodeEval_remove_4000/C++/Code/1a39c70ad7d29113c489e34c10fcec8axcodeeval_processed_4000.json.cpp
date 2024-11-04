    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
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

            int m;

            cin>>m;

            int q[m];

            for(int i=0;i<m;i++) {
                cin>>q[i];
            }

            int n;

            cin>>n;

            int a[n];

            for(int j=0;j<n;j++) {
                cin>>a[j];
            }

            sort(a,a+n,greater<int>());

            sort(q,q+m);

            int c=0;

            for(int i=0;i<n;i++) {  

                int f=q[0];

                for(int j=i;j<n;j++) {
                    if(f>0) {
                        f--;
                        c+=a[j];
                    }

                    else {
                        break;
                    }
                }

                i=i+q[0]-1;

                int t=2;

                while(t>0&&i<n) {
                    t--;
                    i++;
                }

            }

            cout<<c;


            
        }
        return 0;
    }