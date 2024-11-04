
using namespace std;










typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;












void _print(int a){cerr<<a;}
void _print(char a){cerr<<a;}
void _print(string a){cerr<<a;}
void _print(bool a){cerr<<a;}
void _print(float a){cerr<<a;}
void _print(ll a){cerr<<a;}
void _print(ull a){cerr<<a;}
void _print(lld a){cerr<<a;}
template<class T> void _print(vector<T> v){cerr<<"[ ";for(T i:v){_print(i);cerr<<",";}cerr<<"]"<<endl;}



void id10(){
    int n,k;
    scanf("%d%d",&n,&k);
    string s;   cin>>s;
    int arr[n]={0};
    string ans="";
    int original_k=k;

    if(k%2==1){
        for(int i=0;i<n&&k>0;i++){
            if(i==n-1)  break;
            if(s[i]=='1'){
                arr[i]++;
                k--;
            }
            else continue;
        }
        while(k>0){
            arr[n-1]++;
            k--;
        }
    }
    else{
        for(int i=0;i<n&&k>0;i++){
            if(i==n-1)  break;
            if(s[i]=='0'){
                arr[i]++;
                k--;
            }
        }
        while(k>0){
            arr[n-1]++;
            k--;
        }
    }
    k=original_k;
    rep(i,0,n){
        if((k-arr[i])%2==0){
            ans+=s[i];
        }
        else{
            if(s[i]=='1')  ans+='0';
            else ans+='1';
        }
    }
    cout<<ans<<endl;
    rep(i,0,n){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void id9(){
    int n; scanf("%d",&n);
    vi v;
    rep(i,0,n){
        int ele; cin>>ele;
        v.pb(ele);
    }
    sort(v.begin(),v.end(),greater<int>());
    

    int sum=0;
    rep(i,0,n){
        sum+=v[i];
    }
    if(sum==0){
        cout<<0<<endl;
        return;
    }

    vi indices;
    for(int i=0;i<n;i++){
        int j=i+1;
        indices.pb(i);
        while(v[i]>=v[j]&&j<n){
            v[i]-=v[j];
            j++;
        }
        i+=(j-1);
    }
    int ans=0;
    rep(i,0,indices.size()){
        ans+=v[indices[i]];
    }
    if(ans==0){
        cout<<1<<endl;
    }
    else{
        cout<<ans<<endl;
    }
}

void id27(){
    int n; scanf("%d",&n);
    vi v(n);    rep(i,0,n)  scanf("%d",&v[i]);
    sort(v.begin(),v.end(),greater<int>());
    int i=0;
    bool once=false;
    int j=1;
    

    while(j<n){
        if(v[j]==0||i==j){ j++;    continue;}
        if(v[i]==0) {i+=j-1;}
        if(v[i]==v[j])  v[i]=0,    v[j]=0, i++,    j++,  once=true;
        else if(v[i]>v[j])  v[i]-=v[j], v[j]=0, j++, once=true;
    }
    if(i>=n)    i=n-1;
    if(v[i]==0&&once) printf("%d\n",1);
    else if(v[i]==0)    printf("%d\n",0);
    else printf("%d\n",v[i]);
}

void id1(){
    int n, k; scanf("%d%d",&n,&k);
    map<int, int> mapp;
    vi a(n);    rep(i,0,n){
        scanf("%d",&a[i]);
        mapp[a[i]]++;
    }

    vi good;
    for(auto x:mapp){
        if(x.second>=k){
            good.pb(x.first);
        }
    }
    if(good.size()==0){
        printf("-1\n");
        return;
    }
    sort(good.begin(),good.end());
    debug(good);
    int l=good[0], rans=good[0], lans=good[0],  mx=0;
    rep(i,1,good.size()){
        if(good[i-1]+1==good[i]){
            debug(good[i]);
            if(good[i]-l>mx){
                mx=good[i]-l;
                lans=l;
                rans=good[i];
            }
        }
        else{
            l=good[i];
        }
    }
    printf("%d %d\n",lans,rans);
}

void temp(){
    int a=1073741825;
    int b=INT_MAX;
    debug(a);
    debug(b);
}

void id11(){

    int n,  k; scanf("%d%d",&n,&k);
    vi v(n);    rep(i,0,n)  scanf("%d",&v[i]);
    vi freq(31,n);
    rep(j,0,31){
        rep(i,0,n){
            if((v[i]&(1<<j))>0){
                freq[j]--;
            }
        }
    }
    debug(freq);
    for(int i=30;i>-1;i--){
        if(freq[i]<=k){
            k-=freq[i];
            freq[i]=0;
        }
    }
    debug(freq);
    int ans=0;
    rep(i,0,31){
        if(freq[i]==0){
            ans=(ans|(1<<i));
            debug(ans);
        }
    }
    printf("%d\n",ans);
}

void id12(){
    int n; scanf("%d",&n);
    vector<long long> a(n);    rep(i,0,n)  cin>>a[i];
    ll counter=0;
    debug(a);
    ll mn=id7;
    rep(i,0,n){ 

        vector<ll> b(n,0);  counter=0;
        for(int j=i-1;j>-1;j--){
            b[j]=(abs(b[j+1]/a[j])+1)*a[j]*-1;
            counter+=abs(b[j]/a[j]);
        }
        for(int j=i+1;j<n;j++){
            b[j]=(b[j-1]/a[j]+1)*a[j];
            counter+=(b[j]/a[j]);
        }
        mn=min(mn,counter);
        debug(b);
    }
    cout<<mn<<nline;
}   

void id0(){
    int l, r;    scanf("%d%d",&l,&r);
    int mx=INT_MIN;
    rep(i,0,18){
        int counter=0;
        rep(j,l,r+1){
            if(((1<<i)&j)>0){
                counter++;
            }
        }
        mx=max(counter,mx);
    }
    printf("%d\n",r-l+1-mx);
}

void id28(){
    int n; scanf("%d",&n);
    

    vi v(n);    rep(i,0,n){
        scanf("%d",&v[i]);
        

    }
    vi pos(31,0);
    vi ans;
    rep(i,0,31){
        rep(j,0,n){
            if(v[j]==0) continue;
            if((v[j]&(1<<i))>0) pos[i]++;
        }
    }
    bool flag=true;
    rep(i,1,n+1){
        rep(j,0,31){
            if(pos[j]%i==0) continue;
            else flag=false;
        }
        if(flag)    ans.pb(i);
        else flag=true;
    }
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<nline;
}

void id13(){
    int n; scanf("%d",&n);
    vi v(n); rep(i,0,n) scanf("%d",&v[i]);
    vi ans(n);  ans[0]=0;
    rep(i,0,n-1){
        int res=0;
        rep(j,0,31){
            int a1=(v[i]&(1<<j)),   a2=(v[i+1]&(1<<j));
            if((a1&&a2)){
                continue;
            }
            else if((a1&&(!a2))){
                res=res|(1<<j);
            }
        }
        v[i+1]=v[i+1]^res;
        ans[i+1]=res;
    }
    rep(i,0,n){
        printf("%d ",ans[i]);
    }
    printf("\n");
}

void id19(){
    int n,m; cin>>n>>m;
    string s;
    vector<vector<int>> v(n);
    rep(i,0,n){
        cin>>s;
        rep(j,0,m){
            if(s[j]=='0')   v[i].pb(0);
            else v[i].pb(1);
        }
    }
    if(v[0][0]==1){
        cout<<-1<<nline; return;
    }
    vi ans;
    for(int i=n-1; i>-1; i--){
        for(int j=m-1; j>-1; j--){
            if(i==0&&j==0)  break;
            if(v[i][j]==1){
                if(j==0){
                    ans.pb(i);    ans.pb(j+1);
                    ans.pb(i+1);  ans.pb(j+1);
                }
                else{
                    ans.pb(i+1);    ans.pb(j);
                    ans.pb(i+1);  ans.pb(j+1);
                }
            }
        }
    }
    cout<<ans.size()/4<<nline;
    rep(i,0,ans.size()){
        cout<<ans[i]<<" ";
        if((i+1)%4==0)  cout<<nline;
    }
}

void id22(){  

    int n; cin>>n;
    vi pos(n+1);
    vi v(n);    rep(i,0,n){
        scanf("%d",&v[i]);
        pos[v[i]]=i+1;
    }
    vi ans(n+1);
    vi gpos(n+1);
    rep(i,1,n+1){
        gpos[i]=i;
    }  
    debug(gpos);
    debug(pos);
    for(int i=n;i>=1;i--){
        while(gpos[i]!=pos[i]){
            ans[i]++;
            gpos[i];
        }
    }
    debug(ans);
}

void id4(){
    int n; cin>>n;
    int ans1=0, ans2=0, on=0, en=0, odd=1, even=2 ,a;
    rep(i,1,n+1){
        cin>>a;
        if(a&1) ans1+=(abs(odd-i)), ans2+=(abs(even-i)), odd+=2, even+=2, on++;
        else en++;
    }
    debug(ans1);    debug(ans2);
    int mn=min(ans1,ans2);
    if(abs(on-en)>1)    cout<<-1<<nline;
    else if(on>en) cout<<ans1<<nline;
    else if(en>on)  cout<<ans2<<nline;
    else cout<<mn<<nline;
}

bool checker(int i,int h){
    int i1,i2;
    i2=i%10; i1=(i/10)%10;
    if(i1==5)   i1=2;
    else if(i1==2)  i1=5;
    if(i2==5)   i2=2;
    else if(i2==2)  i2=5;
    int new_n=(i2*10)+i1;
    bool check1=new_n<h;
    bool check2=(i1==0||i1==1||i1==2||i1==5||i1==8);
    bool check3=(i2==0||i2==1||i2==2||i2==5||i2==8);
    if(check1&&check2&&check3) return true;
    else return false;
}

void id3(){
    int h, m; cin>>h>>m;
    string s; cin>>s;
    int i=(s[0]-'0')*10+(s[1]-'0');
    int j=(s[3]-'0')*10+(s[4]-'0');
    bool check=true;
    int cnt=0;
    while(check){
        bool a=checker(i,m), b=checker(j,h);
        if(a&&b){
            if(i<10){
                cout<<0<<i<<":";
            }
            else cout<<i<<":";
            if(j<10){
                cout<<0<<j<<"\n";
            }
            else cout<<j<<"\n";
            return;
        }
        j++;
        if(j==m)    i++,    j=0;
        if(i==h)    i=0;
    }
}

void id15(){
    int n,m; scanf("%d%d",&n,&m);
    ll arr[n][m];
    rep(i,0,n){
        rep(j,0,m)  scanf("%lld",&arr[i][j]);
    }
    ll cnt=0, avg;
    rep(i,0,n){
        rep(j,0,m){
            ll x[]={arr[i][j],arr[n-1-i][j],arr[i][m-1-j],arr[n-1-i][m-1-j]};
            sort(x,x+4);
            avg=x[1];
            cnt+=abs(arr[i][j]-avg);    arr[i][j]=avg;
        }
    }
    cout<<cnt<<nline;
}

void id18(){
    ll a,b,n,m; cin>>a>>b>>n>>m;
    bool flag=true;
    if((n+m)>(a+b)) flag=false;
    if(a>b){
        m-=b;
        if(m>0)    flag=false;    
    }
    else{
        m-=a;
        if(m>0) flag=false;
    }
    cout<<(flag?"Yes":"No")<<nline;
}

ll id25(ll x){
    return (x*(x+1))/2;
}

void id25(){
    ll k, x; cin>>k>>x;
    ll l=1, r=2*k-1, mid, res=2*k-1;
    bool ok=false;
    while(l<=r){
        mid=(l+r)/2;
        if(mid<=k){
            ok=(id25(mid)>=x);
        }
        else{
            ok=(id25(k)+id25(k-1)-id25(2*k-1-mid))>=x;
        }
        if(ok){
            res=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<res<<nline;
}

void id26(){
    int n; cin>>n;
    vi v(n);
    bool odd=false;
    vi cnt(n+1);
    rep(i,0,n){
        scanf("%d",&v[i]);
        if(v[i]<=n) cnt[v[i]]=1;
    }
    int counter=0;
    sort(v.begin(), v.end());
    vi num(n+1);
    debug(num);
    int j=1;
    rep(i,0,n){
        while(num[j]>0){
            j++;
        }
        if(v[i]<=n && cnt[v[i]]>0){
            cnt[v[i]]--;
            num[v[i]]++;
            continue;
        }
        int p = v[i]-j;
        if(p<0 || (v[i]%p)!=j){  counter=-1; break;}
        counter++;
        j++;
    }
    cout<<counter<<nline;
}

void id23(){
    int n; cin>>n;
    vi v(n); rep(i,0,n) scanf("%d",&v[i]);
    string s; cin>>s;
    vi r, b;
    rep(i,0,n){
        if(s[i]=='R'){
            r.pb(v[i]);
        }
        else b.pb(v[i]);
    }
    sort(r.begin(), r.end());
    sort(b.begin(), b.end());
    int i=0, j=0, num=1, rs=r.size(), bs=b.size();
    bool flag=true;
    while(1){
        if(i>=bs && j>=rs){
            break;
        }
        if(i<bs){
            if(!(num>b[i])){
                i++; num++; continue;
            }
        }
        if(j<rs){
            if(!(num<r[j])){
                j++; num++; continue;
            }
        }
        flag=false; break;
    }
    cout<<(flag?"Yes":"No")<<nline;
}

void id21(){
    int n, k; cin>>n >> k;
    vector<ll> pos, neg;
    rep(i,0,n){
        ll ele; scanf("%lld",&ele);
        if(ele>0)   pos.pb(ele);
        else neg.pb(-1ll*ele);
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    ll d=0; int ps=pos.size(), ns=neg.size();
    int i=ps-1;
    debug(pos); debug(neg);
    while(1&&ps>0){
        d+=(2*pos[i]);
        debug(d);
        i-=k;
        if(i<=-1){
            

            debug(d);
            break;
        }
        else if(i==-1){
            break;
        }
    }
    i=ns-1;
    while(1&&ns>0){
        d+=(2*neg[i]);
        i-=k;
        if(i<=-1){
            

            break;
        }
        else if(i==-1){
            break;
        }
    }
    if(ps>0 && ns > 0)  d-=(max(pos[ps-1], neg[ns-1]));
    else if(ns==0)  d-=pos[ps-1];
    else if(ps==0)  d-=neg[ns-1];
    cout<<d<<nline;
}

bool id17(pair<int,int> p1, pair<int,int> p2){
    return p1.ff<p2.ff;
}

void id16(){
    int n; cin>>n;
    vector<pair<int,int>> p(n);
    rep(i,0,n){
        int k; cin>>k;
        vi a(k);
        int pos=0, mx=INT_MIN;
        rep(j,0,k){
            cin>>a[j];
            if((a[j]+1-j)>mx){
                mx=a[j]+1-j;
                pos=j;
            }
        }
        p[i]={mx, k};
    }
    sort(p.begin(), p.end(), id17);
    rep(i,0,n){
        cerr<<p[i].ff<<" "<<p[i].ss<<nline;
    }
    int ans=p[0].ff, os=ans, num=0;
    rep(i,1,n){
        ans+=p[i-1].ss;
        num+=p[i-1].ss;
        if(ans>=p[i].ff){
            continue;
        }
        else ans=p[i].ff, os=ans-num;
    }
    cout<<os<<nline;
}

void id2(){
    string s; cin>>s;
    int mn=INT_MAX;
    int n=s.size(), cnt=0;
    for(int i=0;i<60;i++){
        ll x=(ll)pow(2,i);
        cnt=0;
        string xs=to_string(x);
        int xn=xs.size();
        int j=0, k=0;
        while(1){
            int ans1=12, ans2=12;
            if(s[j]==xs[k]){
                j++; k++;
            }
            else{
                cnt++; j++;
            }
            if(j==n || k==xn){
                if(j==n) ans1=(xn-k);
                else if(k==xn)    ans2=(n-j);
                cnt+=(min(ans1,ans2));
                break;
            }
        }
        if(cnt<mn){
            mn=cnt;
        }

    }
    cout<<mn<<nline;
}

void id14(){
    int a, b; cin>>a>>b;
    int q=(a+b)/2, p=(a+b)-q;
    vi ans;
    for(int i=0;i<p;i++){
        int val=(a-(p-i));
        if(val<=q && val>=0){
            ans.pb(val);
        }
    } 
    int temp=p; p=q; q=temp;
    for(int i=0;i<q;i++){
        int val=(b-(q-i));
        if(val<=p && val>=0){
            ans.pb(val);
        }
    }
    int n=ans.size();
    cout<<n<<nline;
    rep(i,0,n){
        cout<<ans[i]<<" ";
    }
    cout<<nline;
}

void id6(){
    int n;
    cin >> n;
    vi v(n+1), m;
    rep(i, 1, n+1){
        cin>> v[i];
        if(v[i] < i)    m.pb(i);
    }
    ll counter = 0;
    vi gr;
    int ms = m.size();
    rep(i, 1, ms){
        if(v[m[i]] > m[0]) gr.pb(v[m[i]]);
    }
    int j = 0, i = 0;
    int gs = gr.size();
    debug(m);
    sort(gr.begin(), gr.end());
    debug(gr);
    while( j < gs){
        if(m[i] < gr[j]){
            i++; counter += (gs-j);
        }
        else j++;
    }
    cout << counter << nline;
}

void id8(){
    string s;
    cin >> s;
    int n = s.size();
    vi v(26, 0);
    int m = 0;
    rep(i,0,n){
        int c = s[i] - 'a';
        if(v[c]){
            m += 2;
            rep(i,0,26) v[i] = 0;
        }
        else v[c] = 1;
    }
    cout << n - m << nline;
}

void id5(){
    int n, k;
    cin >> n >> k;
    vi v(n);
    rep(i,0,n) cin >> v[i];
    sort(v.begin(), v.end());
    vi num, den;
    int p = n - 1;
    rep(i,0,k){
        den.pb(v[p]);
        p--;
    }
    rep(i,0,k){
        num.pb(v[p]);
        p--;
    }
    int score = 0;
    debug(num);
    debug(den);
    rep(i,0,p + 1){
        score += v[i];
    }
    rep(i,0,k){
        score += num[i] / den[i];
    }
    cout << score << nline;
}

void id20(){
    int m;
    cin >> m;
    vi top(m), bottom(m);
    int sum1 = 0, sum2 = 0;
    rep(i,0,m)  cin >> top[i];
    rep(i,0,m)  cin >> bottom[i];
    sum1 = accumulate(top.begin(), top.end(), 0);
    sum2 = 0;
    debug(sum1); debug(sum2);
    int ptr = 0;
    vi ansarr;
    rep(i,0,m){
        sum1 -= top[i];
        ansarr.pb(max(sum1, sum2));
        sum2 += bottom[i];
    }
    cout << *min_element(ansarr.begin(), ansarr.end()) << nline; 
}

void id24(){
    int n;
    cin >> n;
    vi v(n + 1);
    bool flag = false;
    rep(i, 1, n + 1)    cin >> v[i];
    rep(i,1,n + 1){
        for(int j = i + 1; j >= 2; j--){
            if(v[i] % j != 0){
                flag = true;
                break;
            }
        }
        if(flag){
            flag = false;
            continue;
        }
        else{
            cout << "NO\n"; 
            return;
        }
    }
    cout << "YES\n";
}

int main(){
    
        freopen("error.txt","w",stderr);
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    
    

    

    int T=1; scanf("%d",&T);
    while(T--){
        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        id24();
        

    }

    
}