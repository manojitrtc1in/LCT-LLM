

using namespace std;


int main()
{
    int n;
    cin >> n;

    int ans[100010] , a[100010] , b[100010];

    memset(ans , 0 , sizeof(ans));

    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i] >> b[i];
        ans[a[i]]++;
    }


    for(int i = 0 ; i < n ; i++)
    {
        cout << (n - 1 + ans[b[i]]) << " " << (2*(n - 1) - (n - 1 + ans[b[i]]));
        cout << endl;
    }



    


    
    

    
    

    
    
    
    

    



    
    
    
        

    
}
