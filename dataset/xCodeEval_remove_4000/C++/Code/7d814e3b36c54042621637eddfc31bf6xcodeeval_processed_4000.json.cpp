








using namespace std;
typedef long long int ll;



ll GCD(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    else {
        return GCD(b, a % b);
    }
}
ll LCM(ll a, ll b) {
    return a * b / GCD(a, b);
}




int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n,m,a,kl;
    cin>>t;
    for(int i=0;i<t;i++){
        map<int, vector<int>>mip;
        set<int>s;
        bool t1=true;
        cin>>n>>m;
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin>>a;
                if(k==0){kl=a;s.insert(kl);}
                mip[kl].push_back(a);
            }
        }
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                if(t1){cin>>a;}
                if(k==0&&s.find(a)!=s.end()){
                    t1=false;
                    for(int u=0;u<m;u++){
                        cout<<mip[a][u]<<' ';
                    }
                    cout<<endl;
                    for(int u=0;u<n-1;u++){
                        cin>>a;
                        for (int u1 = 0; u1 < m; u1++) {
                            cout << mip[a][u1] << ' ';
                        }
                        cout<<endl;
                    }
                }
                if(!t1){t1=true;break;}
            }
        }
    }
    return 0;
}
