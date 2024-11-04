    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
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

            int x,k;

            cin>>x>>k;

            int a[x+1]={0};

            while(k--) {
                int ar;
                cin>>ar;

                if(ar==1) {
                    int g,h;
                    cin>>g>>h;
            
                   a[g]=1;
                   a[h]=1;
                }

                else {
                    int y;
                    cin>>y;
                   a[y]=1;
                }
            }

            int i=1;


            int min_ans=0;
            int max_ans=0;

            while(i<x) {
                if(a[i]==0) {
                    if(i+1<x&&a[i+1]==0) {
                        a[i]=1;
                        a[i+1]=1;min_ans++;
                        max_ans+=2;
                        i+=2;
                    }

                    else {
                        a[i]=1;
                        max_ans++;
                        min_ans++;
                        i++;
                    }
                }

                else i++;
            }


            cout<<min_ans<<" "<<max_ans;
            
        }
        return 0;
    }