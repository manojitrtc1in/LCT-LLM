



































using namespace::std;







































































































 



int main()
{
    lli t,i,j;
    cin>>t;
    
    while (t--)
    {
        lli n,count=0,c1=0,x,y,z;
        cin>>n;
        
        lli a[n];
        
        for (i=0; i<n; i++)
            cin>>a[i];
    
        
        
        
        for (i=0; i<n; i++)
        {
            count+=(a[i]-1);
        }
        
        
        if (count%2==0)
        {
            cout << "maomao90" << endl;
            
        }
        else
            cout << "errorgorn" << endl;
    }
}


