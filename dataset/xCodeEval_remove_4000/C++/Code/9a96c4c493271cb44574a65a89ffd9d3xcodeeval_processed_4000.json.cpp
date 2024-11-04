



using namespace std;
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;



























































































































































 






















 










 




























































 


















































 



























void solve(){
    int n;cin>>n;
    vector<int>v(n);
    map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int m=count(v.begin(),v.end(),1);
    if(m==0){
        cout<<0<<endl;
        return;
    }
    for(int k=1;k<=110;k++){
        mp.clear();
        for(int j=0;j<n;j++){
            mp[v[j]]++;
        }
        mp[1]-=k-1;
        for(int j=1;j<=k;j++){
            int f=0;
            for(int l=1;l<=j;l++){
                if(mp[l]>0){
                    

                    mp[l]--;
                    f=1;
                    break;
                }
            }
            if(f==0){
                cout<<k-1<<endl;
                return;
            }
        }
    }
    
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    

    while(t--){
        solve();
    }
    

}








