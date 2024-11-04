
 

















using namespace std;
ll mod = 1000000007;



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
 

       

       

       

int c[100001][2];
vector<vector<int> >d(100001);
void solve(){


int n;
cin>>n;
vector<int>a(n);
int col=2;
for(int i=0;i<n;i++){
    cin>>a[i];
   c[a[i]][0]=0;
   c[a[i]][1]=0;

}
for(int i=0;i<n;i++){
   c[a[i]][i%2]++;
}
sort(a.begin(),a.end());
for(int i=0;i<n;i++){
   c[a[i]][i%2]--;
}
for(int i=0;i<n;i++){
    if(c[a[i]][0]!=0 || c[a[i]][1]!=0){
        cout<<"NO"<<endl;
        return;
    }
}
cout<<"YES"<<endl;
}
int main()
{
    fast

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

int t;
cin>>t;
  while(t--)
    solve();
   

     
   
    return 0;
}
