    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
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

            cin>>n;


            string a;
            cin>>a;

            int m=a.length();

            char c[n][m];

            for(int i=0;i<m;i++) {
                c[0][i]=a[i];
            }

            for(int i=1;i<n;i++) {
                string f;
                cin>>f;
                for(int j=0;j<m;j++) {
                    c[i][j]=f[j];
                }
            }


            string p="";

            for(int i=0;i<m;i++) {
               vector<char> v;
               char t;
               for(int j=0;j<n;j++) {
                v.eb(c[j][i]);
                if(c[j][i]!='?') {
                    t=c[j][i];
                }
               }


               if(count(v.begin(),v.end(),'?')==n) {
                p+='x';
               }

               else {
                if(count(v.begin(),v.end(),t)+count(v.begin(),v.end(),'?')==n) {
                    p+=t;
                }

                else {
                    p+='?';
                }
               }

            }


            cout<<p;

        }
        return 0;
    }