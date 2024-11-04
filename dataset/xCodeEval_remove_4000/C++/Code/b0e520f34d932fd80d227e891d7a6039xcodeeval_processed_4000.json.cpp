    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    using namespace std;
    int main()
    {

    
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    


        std::ios::sync_with_stdio(false);
        int T;
        cin>>T;
        

        while(T--)
        {


            int n,m;

            cin>>n>>m;

            int a[n][m];

            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    cin>>a[i][j];
                }
            }


            if(n==2&&m==2)  {
                a[0][0]==a[1][1]?cout<<0:cout<<1;
            }


            else {


                int c=0;


                int y=m+n-1;

                int r=y/2;


                vector<vector<int>> cnt(n+m-1,vector<int>(2));

                for(int i=0;i<n;i++) {
                    for(int j=0;j<m;j++) {
                        cnt[i+j][a[i][j]]++;
                    }
                }


                for(int i=0;i<n+m-1;i++) {

                    int j=n+m-2-i;

                    if(i<=j) {
                        continue;
                    }

                    else {

                        c+=min(cnt[i][0]+cnt[j][0],cnt[i][1]+cnt[j][1]);

                    }

                }

                cout<<c;



            }

            cout<<endl;

            
        }
        return 0;
    }