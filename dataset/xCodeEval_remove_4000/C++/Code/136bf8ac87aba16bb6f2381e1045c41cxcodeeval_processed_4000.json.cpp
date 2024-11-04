


































































































































using namespace std;









int gcd(int a, int b){ if (b == 0) return a; return gcd(b, a % b); }





















































































int power(int a, int b){
    if(b == 1) return a;
    if(b == 0) return 1;
    int ans = power(a,b/2);
    ans = (ans*ans);
    if(b&1) ans = (ans * a);
    return ans;
}
















































































const int N = 20000000;
bool isPrime[N+1];
vector<int> prime;
void primes(){
    for(int i=0; i<N; i++){
        isPrime[i] = true;
    }
    isPrime[1]=0;
    isPrime[0]=0;
    for(int i=2;i*i<=N;i++){
    if(isPrime[i]==1){
        for(int j=i*i;j<=N;j+=i){
            isPrime[j]=false;
        }
    }
    }
    for(int i=2; i<N; i++){
        if(isPrime[i])
            prime.push_back(i);
    }
}




















































































































































































































































































































































































































































































































































































































void solve(){
    int n; cin>>n;
    int q; cin>>q;
    int arr[n]; for(int i=0; i<n; i++) cin>>arr[i];
    int pre[n];int sum[n];
    pre[0] = arr[0];
    for(int i=1; i<n; i++) pre[i] = pre[i-1]^arr[i];
    sum[0] = arr[0];
    for(int i=1; i<n; i++) sum[i] = sum[i-1]+arr[i];
    map<int,vector<int>> even,odd;
    for(int i=0; i<n; i++){
        if(i&1) odd[pre[i]].push_back(i);
        else even[pre[i]].push_back(i);
    }
    while(q--){
        int i,j; cin>>i>>j; i--; j--;
        int xr = pre[j];
        if(i != 0) xr ^= pre[i-1];
        int parity = j-i+1;
        int currSum = sum[j];
        if(i != 0) currSum -= sum[i-1];
        if(xr != 0){
            cout<<"-1\n";
            continue;
        }
        if(currSum == 0){
            cout<<"0\n";
            continue;
        }
        if(parity&1){
            cout<<"1\n";
        }else{
            if(parity == 2){
                cout<<"-1\n";
                continue;
            }
            if(arr[i] == 0 or arr[j] == 0){
                cout<<"1\n";
                continue;
            }
            if(i&1){
                if(lower_bound(begin(i-1 >= 0 ? odd[pre[i-1]] : odd[0]),end(i-1>= 0 ? odd[pre[i-1]] : odd[0]),i) == odd[pre[i-1]].end()){
                    cout<<"-1\n";
                    continue;
                }
                int idx = *lower_bound(begin(i-1 >= 0 ? odd[pre[i-1]] : odd[0]),end(i-1>= 0 ? odd[pre[i-1]] : odd[0]),i);
                if(idx < j){
                    cout<<"2\n";
                }else{
                    cout<<"-1\n";
                }
            }else{
                if(i == 0 && lower_bound(begin(even[0]),end(even[0]),i) == even[0].end()){
                    cout<<"-1\n";
                    continue;
                }
                if(i != 0 && lower_bound(begin(even[pre[i-1]]),end(even[pre[i-1]]),i) == even[pre[i-1]].end()){
                    cout<<"-1\n";
                    continue;
                }
                int idx = *lower_bound(begin(i-1 >= 0 ? even[pre[i-1]] : even[0]),end(i-1>=0 ? even[pre[i-1]] : even[0]),i);
                if(idx < j){
                    cout<<"2\n";
                }else{
                    cout<<"-1\n";
                }
            }
        }
    }
}







signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    

    

    int tt = 1; 

    while(tt--){
        solve();
    }














    return 0;
}







































