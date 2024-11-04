    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    using namespace std;

    bool bydist(pair<int,int> p1,pair<int,int> p2) {

        double d1 = sqrt(p1.f*p1.f+p1.s*p1.s);

        double d2 = sqrt(p2.f*p2.f+p2.s*p2.s);


        return d1<d2;
    }


    signed main()
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
  int arr[2*n];
  for(int i=0;i<2*n;i++)
    cin>>arr[i];
  sort(arr,arr+(2*n));
  if(n==1)
  {
    cout<<0;
    return 0;
  }
  int now=INT_MAX;
  for(int i=1;i<n;i++)
  {
    now=min(now,arr[n+i-1]-arr[i]);
  }
  cout<<min((arr[2 * n - 1] - arr[0])*now,(arr[n - 1] - arr[0]) * (arr[2 * n - 1] - arr[n]));
            

        }
        return 0;
    }