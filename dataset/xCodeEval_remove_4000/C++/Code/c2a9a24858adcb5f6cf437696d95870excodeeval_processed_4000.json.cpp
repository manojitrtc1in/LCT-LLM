    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
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

            int l=0,r=0;

            cin>>n;

            map<int,int> mpl,mpr;

            for(int i=0;i<n;i++) {
                char c;
                int p;

                cin>>c>>p;

                if(c=='L'){
                    l++;
                    mpl[p]=l;
                }

                else if(c=='R') {
                    r++;
                    

                    mpr[p]=r;
                }

                else {

                    if(mpl[p]==0) {
                        cout<<min(r-mpr[p],l+mpr[p]-1);
                    }

                    else if(mpr[p]==0) {
                        cout<<min(l-mpl[p],r+mpl[p]-1);
                    }

                    cout<<endl;


                }
                    
            }

            
        }
        return 0;
    }