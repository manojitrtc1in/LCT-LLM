


using namespace std;












int main()
{

    

    

    int n;
    cin >> n;

    long long a[n+5],b[n+5]= {0};
    loop(i,0,n)cin >> a[i],b[i]=a[i];
    

    

    rloop(i,n-2,0)b[i]+=b[i+1];


    loop(i,1,n)a[i]+=a[i-1];

    int j = n-1;
    long long m=0;
    if(n==1)
    {
        cout<<0<<endl;
        return 0 ;
    }
    loop(i,0,n)
    {
        if(i>=j)
            break;
        if(a[i]==b[j])
        {
            if(a[i]>m)
                m=a[i];
            j--;
        }
        else if(a[i]>b[j])
            i--,j--;


        


    }


    cout<<m<<endl;

    


}

