




using namespace std;
















const int MAX_CHAR = 256;
void hi()
{
    
    freopen("input.txt", "r", stdin);
    

    
}
void bye()
{
    
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
    
}
int main() 
{
    int t;
    cin>>t;
    while(t--)
	{
        ll n,a2=0;
        cin>>n;
        ll a[(int)n];
        for(int i=0;i<n;i++)
        {
            ll a;
            cin>>a;  
            if(i%2==0)
            {
                if(a<0)
                    cout<<-a<<" ";
                else
                {
                    cout<<a<<" ";
                }
            }
            else if(i%2!=0)
            {
                if(a<0)
                    cout<<a<<" ";
                else
                {
                    cout<<-a<<" ";
                }
                
            } 
            cout<<endl;
        }
    }
    return 0;
}