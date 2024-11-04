  

  

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
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
            int n,m;

            cin>>n>>m;

            if((n-1)<=m&&m<=2*(n+1)) {
               int n2 = m-n;
        int id =0;
        for(int i=0;i<n;i++){
            if(i!=0 || (i==0 && m+1!=n))cout<<'1';
            if(n2>0){cout<<"1";n2--;}
            cout<<"0";
        }
        while(n2>0){
            cout<<"1";
            n2--;
        }
            }

            else {
                cout<<-1;
            }
            
        }
        return 0;
    }