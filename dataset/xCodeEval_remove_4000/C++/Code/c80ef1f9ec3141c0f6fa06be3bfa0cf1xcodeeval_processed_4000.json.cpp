





using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        ll ans=0,n,tmp=0;
        cin >> n;
        for(int i=0;i<n;i++){
            ll r;cin>>r;
            if(r==0&&tmp!=0){ ans++; }
            tmp=r;
        }
        if(tmp!=0) ans++;
        cout << min(ans,2ll)<<endl;
    }
}





