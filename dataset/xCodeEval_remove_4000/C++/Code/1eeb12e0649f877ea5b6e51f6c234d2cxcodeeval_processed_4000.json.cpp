









using namespace std;
int power(int x, unsigned int y){int res = 1;while (y > 0){ if (y & 1){res = res*x;} y = y>>1;x = x*x;}return res;}
int id0(int x, unsigned int y, int p){int res = 1;x = x % p;while (y > 0){if (y & 1){res = (res*x) % p;}y = y>>1; x = (x*x) % p;}return res;}
int Mod(int x, int m){ return (x%m+m)%m;}
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}

int32_t main()
{

	
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
	

    fastio;
    int t;
    cin>>t;
    while(t--)
    { 
        string s;
        cin>>s;
        map<int,vector<int>>p;
        int n = s.size();
        for(int i=0;i<n;i++){
        	p[s[i]].pb(i);
        }
        int ans = 0;
        for(auto x:p){
        	ans = max(ans,x.second.size());
        }
        for(auto x:p){
        	for(auto y:p){
                if(x.first==y.first){
                	ans = max(ans,x.second.size());
                	continue;
                }
                bool check = true;
                int count =0 ;
                for(int i=0;i<n;i++){

                	if(s[i]==x.first && check==true){
                		count++;
                		check=false;
                	}
                	else if(s[i]==y.first && check==false){
                		count++;
                		check=true;
                	}
                }
                if(count%2!=0){
                	count--;
                }
                ans = max(ans,count);
        	}
        }
 
        cout<<n - ans<<endl;
    }

  return 0;


}



