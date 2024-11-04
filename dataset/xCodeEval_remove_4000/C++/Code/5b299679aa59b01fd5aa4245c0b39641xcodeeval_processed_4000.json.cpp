    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
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

            map<int,float> mp1;

            map<float,int> mp2;

            for(int i=0;i<n;i++) {

            char c,d,e,f;
            float a,b,x;

            cin>>c>>a>>d>>b>>e>>f>>x;

            mp1[i+1]=(a+b)/x;

            mp2[(a+b)/x]++;

            }


            for(auto x:mp1) {
                cout<<mp2[x.s]<<" ";
            }



            
        }
        return 0;
    }