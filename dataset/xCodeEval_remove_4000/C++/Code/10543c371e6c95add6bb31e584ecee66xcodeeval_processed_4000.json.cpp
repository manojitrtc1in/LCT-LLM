




































































































































            













































 










































































































 





























































































 















































































            





































 




























































































































                












































































































 






































        




















        

























































       






























 














































                 
























































 


















































































using namespace std;
using namespace __gnu_pbds;






 
bool compare(ll a,ll b)
{
    return a<b;
}

int main ()
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    test()
    {
        ll i,j,n;
        cin>>n;

        vector<ll>v(n);

        for(i=0;i<n;i++)
        cin>>v[i];

        ll cnt = 0;
        

        ll occ = 1;
        for(i = n-2; i>=0; i--)
        {
            while(i>=0 and v[i]==v[n-1])
            {
                occ++;
                i--;
            }
            bool flag = false;
            ll temp = occ;
            for(int j = i; j>i-temp; j--)
            {
                if(j<0)
                {
                    break;
                }



                if(v[j]!=v[n-1])
                {
                    flag = true;
                }
                occ++;

                
            }
            i = i-temp+1;
            if(flag==true)
            {
                cnt++;
            }
        }





        
        cout<<cnt<<endl;

    }
    return 0;
}