



















































































































































































































































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
    int n,kol=0,lind=0,chi,prchi=0,ans[100000]={0};
    char pok,prpok=' ';
    vector<pair<int,int>>adr;
    cin>>n;
    for(int i=0;i<n*2;i++){
        cin>>pok;
        if(pok=='+'){
            if(prpok==' '){
                adr.push_back({100001,0});
            }
            else if(prpok=='-'){prchi=0;}
            kol++;
            lind++;
        }
        else{
            kol--;
            if(kol<0){ cout << "NO" << endl; exit(0); }
            cin>>chi;
            if(prchi>0&&chi<prchi){cout<<"NO"<<endl;exit(0);}
            if(prchi==0){adr.push_back({chi,lind});}
            else{adr[adr.size()-1].first=max(chi, adr[adr.size() - 1].first);}
            prchi=chi;
            if(adr.size()==1){ cout << "NO" << endl; exit(0); }
            else{
                for(int j=adr.size()-2;j>=0;j--){
                    if(adr[j].first>chi){
                        if(adr[j+1].first>chi){ cout << "NO" << endl; exit(0); }
                        ans[adr[j].second]=chi;
                        adr[j].second++;
                        if(ans[adr[j].second]||adr[j].second==adr[j+1].second){
                            adr[j+1].first=max(adr[j].first,adr[j+1].first);
                            adr.erase(adr.begin()+j);
                        }
                        break;
                    }
                }
            }
        }
        prpok=pok;
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
