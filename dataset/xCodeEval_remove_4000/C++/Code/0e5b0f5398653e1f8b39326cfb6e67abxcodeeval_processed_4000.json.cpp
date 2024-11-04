
 


















using namespace std;
const int mod = 1e9 + 7;



int gcd(int a, int b)
{
    

    if (a == 0)
       return b;
    if (b == 0)
       return a;
  
    

    if (a == b)
        return a;
  
    

    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}
int id0(int arr[], int n)
{
    

    sort(arr, arr + n);
 
    

    int max_count = 1, res = arr[0], curr_count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1])
            curr_count++;
        else {
            if (curr_count > max_count) {
                max_count = curr_count;
                res = arr[i - 1];
            }
            curr_count = 1;
        }
    }
 
    

    if (curr_count > max_count)
    {
        max_count = curr_count;
        res = arr[n - 1];
    }
 
    return res;
}
 

       

       

       


void solve(){


ll n;
cin>>n;
ll lcm=1,ans=0,i=2;
while(1){
ll with_error = n / lcm;
             lcm = lcm * i / __gcd(lcm, i);
            ll id1 = n / lcm;
 
            ans += (with_error - id1) * i;
            ans %= mod;
            i++;
if(lcm>n){
    break;
}

}
cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

int t;

cin>>t;
  while(t--)
    solve();
   

     
   
    return 0;
}
