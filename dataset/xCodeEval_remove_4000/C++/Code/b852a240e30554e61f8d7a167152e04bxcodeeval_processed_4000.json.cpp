    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
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

            ll n,m,k;

            cin>>n>>m>>k;

            ll a[m],b[k];


            for(int i=0;i<m;i++) {
                cin>>a[i];
            }

            for(int j=0;j<k;j++) {
                cin>>b[j];
            }

            vector<pair<ll,ll>> v;

            for(int i=0;i<m;i++) {
                ll c=0;
                for(int j=0;j<k;j++) {
                    if((b[j])%a[i]==0) {
                        c++;
                    }
                }
                v.eb(mp(c,i+1));
            }


            sort(v.begin(),v.end());

            int g=0;

            for(int i=0;i<v.size();i++) {
                if(v[i].f==v[0].f) {
                    g++;
                }
                else {
                    break;
                }
            }

            cout<<g<<endl;

            for(int i=0;i<v.size();i++) {
                if(v[i].f==v[0].f) {
                    cout<<v[i].s<<" ";
                }
                else {
                    break;
                }
            }
            
        }
        return 0;
    }