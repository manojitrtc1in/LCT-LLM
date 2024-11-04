








































typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int arr[100100];
bool iss[100100];
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int mini=1e9;
    for (int i=0; i<n; ++i){
        cin>>arr[i];
        mini=min(arr[i],mini);
    }
    sort(arr, arr+n);
    int cnt=0;
    int i=0,st=0;
    int stpos=-11;
    while (i<n){
        while (i<n && arr[i]==arr[st]) ++i;
        if (stpos<i) stpos=i;
        int k=i-st;
        for (stpos ; stpos<n && k>0; ++stpos){
            if (!iss[stpos]) ++cnt,--k;
        }
        st=i;
        i=st;
        
    }
    cout<<cnt<<en;
    return 0;
    
}
