    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
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

            float a,b,c;

            cin>>a>>b>>c;

            float d = sqrt(b*b-4*a*c);

            float r1,r2;

            r1=-b+d;
            r2=-b-d;


            r1=r1/(2*a);

            r2=r2/(2*a);
            
            if(r1>r2) {

            cout<<fixed<<setprecision(7)<<r1<<endl;
            cout<<fixed<<setprecision(7)<<r2;
            }


            else {

            cout<<fixed<<setprecision(7)<<r2<<endl;
            cout<<fixed<<setprecision(7)<<r1;
            }

        }
        return 0;
    }