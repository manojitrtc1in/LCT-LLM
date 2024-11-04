    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    using namespace std;
    int main()
    {

    
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    


        std::ios::sync_with_stdio(false);
        int T=1;
        
        

        while(T--)
        {

            ll n,k;

            cin>>n>>k;

            string s;

            cin>>s;

            vector<ll> v;

            ll f=-1;
            ll g=-1;

            for(int i=0;i<n-1;i++) {
                if(s[i]=='4'&&s[i+1]=='7'&&s[i+2]=='7'&&i<n-2&&(i+1)%2) {
                    f=i;
                    break;
                }

                if(s[i]=='4'&&s[i+1]=='4'&&s[i+2]=='7'&&i<n-2&&(i+1)%2) {
                    g=i;
                    break;
                }
                
                if(s[i]=='4'&&s[i+1]=='7') {
                    v.eb(i);
                }                
            }


            ll u=k;

          
            for(int i=0;i<v.size();i++) {
                if((v[i]+1)%2==0&&u>0) {
                    s[v[i]]='7';
                    s[v[i]+1]='7';
                    u--;
                }
                else if((v[i]+1)%2==1&&u>0) {
                    s[v[i]]='4';
                    s[v[i]+1]='4';
                    u--;
                }
            }

            if(u>0) {
                if(f!=-1) {
                    if(u%2==0) {
                        s[f]='4';
                        s[f+1]='7';
                        s[f+2]='7';
                    }

                    else {
                        s[f]='4';
                        s[f+1]='4';
                        s[f+2]='7';
                    }
                    u=0;
                }

                else if(g!=-1) {
                    if(u%2==0) {
                        s[g]='4';
                        s[g+1]='4';
                        s[g+2]='7';
                    }
                    else {
                        s[g]='4';
                        s[g+1]='7';
                        s[g+2]='7';
                    }
                }
            }


            cout<<s<<endl;




            
        }
        return 0;
    }