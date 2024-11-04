












































typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int cnt[400400];
int arr[200200];
int n,m;
int greaterr(int x){
    mem0(cnt);
    int sum=n;
    cnt[sum]=1;
    int add=0;
    int ans=0;
    for (int i=0; i<n; ++i){
        if (arr[i]<x)
            --sum,add-=cnt[sum];
        else
            add+=cnt[sum],++sum;
        ans+=add;
        cnt[sum]++;
    }
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=0; i<n; ++i)
        cin>>arr[i];
    cout<<greaterr(m)-greaterr(m+1)<<en;
    return 0;
}
