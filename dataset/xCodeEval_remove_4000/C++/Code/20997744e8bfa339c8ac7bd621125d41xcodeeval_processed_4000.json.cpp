    	
    	using namespace std;
    	
    	
    	
    	

        int dx[8]={1,1,0,-1,-1,-1,0,1};
        int dy[8]={0,1,1,1,0,-1,-1,-1};

    	
    	vector<int> ar[1000001];
        int vis[1000001],dis[1000001],cc[1000001],bt,used[1000][1000];
        char mat[1000][1000];

        void dfs(int i,int j)
        {
            used[i][j]=1;
           
                for(int k=0;k<8;k++)
                     if( mat[ i+dx[k] ][ j+dy[k] ]=='1' && used[ i+dx[k] ][ j+dy[k] ] == 0 )
                    {
                        dfs(i+dx[k] , j+dy[k] );
                    }
        }

    
    	 const int N=2e5+80;
    	signed main()  
    	{

    		
    		freopen("input.txt","r", stdin);
    		freopen("output.txt", "w", stdout);
    		
    		
    		int t=1;
    	

    		
    		while(t--)
    		{
               int flag=0;
               int n; cin>>n;  vector<int>a(n+2);
               vector<int> tree1(N),tree2(N);
               

               for(int i=0;i<n+1;i++) cin>>a[i];
               for(int i=1;i<n+1;i++)
               {
                  if(a[i]>1 and a[i-1]>1) flag=1;
               }   
               if(!flag) cout<<"perfect";
               else
               {
                 cout<<"ambiguous"<<endl;
                 tree1[1]=0; tree2[1]=0;
                int level=1; int cnt=2;
                 int fx=0;
                 for(int i=1;i<n+1;i++)
                 {
                    if(a[i]>1 and a[i-1]>1 and !fx)
                    {
                        tree1[cnt]=level;
                        tree2[cnt]=level+1;
                        cnt++; fx=1;
                        a[i]--;
                    }
                    for(int j=cnt;j<cnt+a[i];j++)
                        tree1[j]=tree2[j]=level;
                    level=cnt;
                    cnt+=a[i];
                

                 }
              

                 for(int i=1;i<cnt;i++) cout<<tree1[i]<<" "; cout<<endl;
                 for(int i=1;i<cnt;i++) cout<<tree2[i]<<" "; cout<<endl;
               } 

            }
     
    	    return 0;
    	}

