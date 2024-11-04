       
    
    
    using namespace std;
     
     

    const int   N           = (int) 1e6+5;
    const int   M           = (int) 1e9+5;
    const int   mod         = (int) 1000000007;
    const int   max_prime   = (int) 1e6+3;
    const int   BLK         = (int) 700;
    const double pi = acos(-1.0);

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    pair<int, int> p;
    vector<int> v;
     
    map<int,int>mp;
    set<int> st;



           
 void solve ()
{ int a,b;

         cin>>a>>b;
    string s;
    cin >> s;
    ll n = s.size();
    ll z = 0;
    ll o = 0;
    for (int i=0;i<n;i++)
    {
        if(s[i] == '0')
        {
            z ++;
        }
        else if(s[i] == '1')
        {
            o ++;
        }
    }
    if(z > a || o > b)
    {
        cout<<-1<<endl;
        return;
    }
    a -= z;
    b -= o;
    for (int i=0;i<n/2;i++)
    {
        if(s[i] == '?')
        {
            if(s[n - i - 1] == '?')
            {
                continue;
            }
            if(s[n - i - 1] == '1')
            {
                b --;
            }
            else
            {
                a --;
            }
            s[i] = s[n - i - 1];
        }
        else
        {
            if(  s[n - i - 1] == '?')
            {
                if(s[i] == '1')
                {
                    b --;
                }
                else
                {
                    a --;
                }
                s[n - i - 1] = s[i];
            }
            else if(s[i] != s[n - i - 1])
            {
                cout<<-1<<endl;
                return;
            }
        }
        if(a < 0 || b < 0)
        {
            cout<<-1<<endl;
            return;
        }
    }
    for (int i=0;i<n/2;i++)
    {
        if(s[i] == '?')
        {
            if(a > 1)
            {
                s[i] = '0';
                s[n - i - 1] = '0';
                a -= 2;
            }
            else if(b > 1)
            {
                s[i] = '1';
                s[n - i - 1] = '1';
                b -= 2;
            }
            else
            {
                cout<<-1<<endl;
                return;
            }
        }
    }
    if(s[(n + 1)/2  - 1] == '?')
    {
        if(a > 0)
        {
            s[(n + 1)/2  - 1] = '0';
        }
        else
        {
            s[(n + 1)/2  - 1] = '1';
        }
    }
    cout<<s<<endl;
     
 

}

   void solve2()
   {
      int n,l;
      cin>>n;
      vector<int>v;
       int array[n+5];
       for (int i=0;i<n;i++){
        cin>>array[i];
       }
       string s;
        for (int i=0;i<n;i++){
         cin>>l>>s;
          v.push_back(array[i]);
                      for(auto c:s){
                if(c=='D'){
                    array[i]++;
                    if(array[i]==10)array[i]=0;
                }
                else{
                    array[i]--;
                    if(array[i]==-1)array[i]=9;
                }
            }
          
        
       }
       for (int i=0;i<n;i++){
        cout<<array[i]<<" ";
       }
       cout<<endl;
       

   }
   
    
 void solve3(){
    int n;
    cin>>n;
    vector<string> v(n);
    map<string,bool> m;
    for(int i=0;i<n;i++){
        cin>>v[i];
        m[v[i]]=true;
    }
    for(int j=0;j<n;j++){
        bool flag=false;
        for(int i=1;i<v[j].size();i++){
            string s1=v[j].substr(0,i);
            string s2=v[j].substr(i,v[j].size()-1);
            

            if(m[s1] && m[s2]){
                flag=true;
                break;
            }
        }
       if(flag){
        cout<<1;
       }
       else cout<<0;
    }
    cout<<endl;
     
}  


void solve4(){
    int N,s;    cin>>N>>s;
    vector<string> v;
     map<string,bool> m;
    string str;
    string str_c;
    for(int i=0;i<N;i++){
        char x;
         cin>>x;
        if(x=='I'){
            cin>>str;
            

            m[str]=true;
        }else if(x=='Q'){
            int cnt=0;
            cin>>str_c;
             for(int i=1;i<str_c.size();i++){
            string s1=str_c.substr(0,i);
            

            

            if(m[s1]){
                cnt++;
            }
             
        }
       cout<<cnt<<endl; 
    }
}
}
  
 void solve5 ()
 {
    int n;
    cin>>n;
    int p,q;
    while (n--){
        cin>>p>>q;
        int sum=p-q;
        v.push_back(sum);
    }
sort(v.begin(), v.end(), greater<int>());

int summ=0,count=0;
int x=0;
for (int i=0;i<v.size();i++ ){
    x+=v[i];
}
  if (x<30){
    cout<<-1<<endl;
    return;
}
for (int i=0;i<v.size();i++){
     
    
    if (summ<30){
         count++;
         summ+=v[i];

    }
    else {
        break;
    }
}
cout<<count<<endl;
 }
 
 void solve6()
 {
     int n;
     cin>>n;
     int array[n+5];
     for (int i=0;i<n;i++){
        cin>>array[i];
     } bool flag=true;
     for (int i=1;i<n;i++){
        if (array[i]%array[0]==0){
            flag=true;
        }
        else {
            flag=false;
            break;
        }
     }
     if (flag) cout<<"YES"<<endl;
     else cout<<"NO"<<endl;
 }

void solve7()
{
    ll n,l,r;
        cin>>n>>l>>r;
         
      vector<int>v;
         
        for(int i=1;i<=n;i++)
        {
            if(l%(i)==0){
v.push_back(l);
            }  
            else {
                v.push_back(l+(i)-(l%(i)));
            }
        }
         
          int mx;
        mx=*max_element(v.begin(), v.end());
        
        if(mx>r) {
            cout<<"NO"<<endl;
            return;

        }
        else
        {
            cout<<"YES"<<endl;
            for(auto it:v)
                cout<<it<<" ";
             
        }
 
cout<<endl;
 
}
 void solve8(){

        ll n;
    cin >> n;
    ll array[n+5], array2[n+5]={0};

    map<int,vector<int>>mp;
    for(int i=0;i<n;i++){
        cin>>array[i];
        mp[array[i]].push_back(i);
    }
     
   
    for(auto it : mp){
        ll count=1;
        for(int i=1;i<it.second.size();i++){
            int x=(it.second[i]-it.second[i-1]);
            x--;
            if(x%2!=0){
                 continue;
            } 
            else {
               count++;
            }   
            
        }
        array2[it.first]=count;
    }

    for(int i=1;i<=n;i++){

        cout<<array2[i]<<" ";
    }
    cout <<endl;

    }
       
  void solve9()
  {
    ll x,y;
    cin>>x>>y;
  ll sum=x+y;
    ll l=0;
   ll r=1e10;
    while (l<r){
        ll mid;
        mid=(r+l)/2;
        ll sum2=(mid*(mid+1))/2;
        if (sum2>=sum){
            r=mid;

        }
        else {
            l =mid+1;
        }
    }
    cout<<l<<endl;
  }

   void solve10()
     {   
    int n;
        cin >> n;
      set<int>st;
        int array[n+5];
         
         for (int i=0;i<n;i++){
            cin>>array[i];
         }

       

        reverse(array,array+n);
        ll count=0;
        for (int i=0;i<n;i++)
        {
            if (st.find(array[i]) == st.end()){

                st.insert(array[i]);
            }
            else{
                break;
            }

           count++;
        }

        cout <<abs(count-n)<<endl;
    }


  void solve11(){
      ll num;
        cin>>num;

        string str;
      ll count=9;

        while (num)
        {
            while (num <count)
               count--;
            
            str+=to_string(count);
             
            num=num-count;
           count--;
        }

        reverse(str.begin(),str.end());

        cout<<str<<endl;
       

  }

  void solve12()
  {  

   ll n,h,m;
        cin>>n>>h>> m;

        vector<pair<ll,ll> >v(n);
        for (int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
        }
         

       sort (v.begin(),v.end());

        v.push_back({v[0].first+24,v[0].second});

      int  ans=24*60+100;

        for (int i=0;i<v.size();i++)
        {
            if (h<v[i].first || (v[i].first == h && (m <= v[i].second)))
            {   int  p=(h*60+(m-v[i].first*60)-v[i].second);
                ans=min(ans ,-p);

            }
        }

        cout<<ans/60<<' '<<ans%60<<endl;
  }


  void solve13()
  {
    ll n;
        cin>>n;

        vector<int> v(n);
        for (int i =0;i<n;i++) {
            v[i]=i+1;
        }
            
        cout <<n<<endl;
        int count = 0;
        while (n--)
        {
            for (auto x : v)
                cout <<x<<' ';
            cout <<endl;

            if (n!=0){

                swap(v[count], v[count+1]);
                count++;
            }
            
        
    }

    }
  

     
void solve14()
{
     

        ll n;
        cin >> n;
        int mx1=0,mx2=0;
        int mn1=0,mn2=0;
          int x, y;

        while(n--)
        {
             
            cin >> x >> y;
           mx1 = max(mx1,x);
            mn1 = min(mn1,x);
            mx2 = max(mx2,y);
            mn2 = min(mn2,y);
        }

       
   ll res;
   res=((mx1-mn1)+(mx2- mn2));

        cout<<2*res<<endl;
}


 void solve15()
 {
    int n;
    cin>>n;
     
     vector<int>v(n+1);

       int array[n+5]; 
    for (int i=0;i<n;i++){

        cin>>array[i];
        


    }
    for (int i =0;i<n;i++ ){
        v[i]=array[i];
    }

    sort(v.begin(),v.end());


    int count=0;
    bool x=true;
    int l=0,r=n-1;
        while (l<=r)
        {
            if (array[l] == v[count])
                l++, count++;
            else if (array[r] == v[count])
                r--, count++;

            else
            {
                x = false;
                break;
            }
        }

        

        if (x==true){

            cout << "YES"<<endl;
        }
        else{

            cout <<"NO"<<endl;;
        }
    }

 
 
  void solve16()
  {
    int n,k;
   cin>>n>>k;
   vector<int>v;

   int array[n+5];
    
   for (int i=0;i<n;i++){
    cin>>array[i];
    v.push_back(array[i]);
   } int count=0;
     for (int i=0;i<k;i++){
        if (array[i]>k){
            count++;
        }
     }  
     cout<<count<<endl;


}
 void solve17()
 {
    ll n; 
    cin >> n;
    vector<int>v(n);
  for(int i =0;i<n;i++) {
        v[i] =i+1;
    }

    if(n%2==0) {
         
        for(int i=0;i<n;i+=2)
            swap(v[i], v[i+1]);
    }
    else {
         for(int i=1;i<n;i+=2)
            swap(v[i],v[i+1]);
    }
    

    for (int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
 }




   void solve18()
   {
    int n;
    cin>>n;
     vector<int>v(n);
     for (int i=0;i<n;i++){
        cin>>v[i];
     }
     if (is_sorted(v.begin(),v.end())){
        cout<<0<<endl;
        return;
     }
     map<int,int>mp;
     for (int i=0;i<n;i++){
        if (mp.find(v[i])==mp.end()){
            mp[v[i]]=i;
        }
     }int index=-1;
     for (int i=n-1;i>=0;i--){
        if (v[i]<v[i-1]){
            index=i-1;
            break;
        }
     }
     int res=mp.size();
     set<int>st;
     for (int i=n-1;i>=0;i--){
        if (mp[v[i]]<=index){
            break;
        }
        st.insert(v[i]);
     }
     res-=st.size();
     cout<<res<<endl;
   
}

 void solve19()
 {
    int n;
    cin>>n;
    int array[n+5];
    for (int i=0;i<n;i++){
        cin>>array[i];
    }
    int l=0;
    int r=n-1;
    vector<int >v;
    while (l<=r){
       if (array[l]<array[r]){
        v.push_back(array[r]);
        r--;
       }
       else {
       v.push_back(array[l]);
       l++;
       }
    }int sum=0,sum2=0;
    for (int i=0;i<v.size();i++){
        if (i%2==0){
            sum+=v[i];
         
    }
    else {
        sum2+=v[i];
    }

 }
 cout<<sum<<" "<<sum2<<endl;
}


void solve20()
{
    ll a, b, c, d;
        cin>>a>>b>>c>>d;
        ll x =a*d;
     ll y =b*c;

        if (a*d==b*c){
            cout<<0<<endl;
        }
        else
        {

            if ((y!=0 && x%y==0) or(x!=0 and y%x==0)){
                cout<<1<<endl;
            }
            
            else
                cout<<2<<endl;
        }
}
  

  void solve21(){
    string a, b;
     cin >> a >> b;
    set<char> se;
    for (auto x: a) {
      se.insert(x);
    }
    for (auto x: b) {
      se.insert(x);
    }
    cout <<se.size() - 1 << '\n';
  }

  
void solve22()
   {   
       string str1,str2;

        int n;
        cin>>n;
        cin>>str1;
        for(int i=0; i<str1.size(); i++)
        {
            if(str1[i]=='G')
            {
                str1[i]='B';
            }
        }
        cin>>str2;
        for(int i=0; i<str2.size(); i++)
        {
            if(str2[i]=='G')
            {
                str2[i]='B';
            }
        }

        if(str1==str2)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

  }

void solve23(){
    
    int n;
    cin>>n;

    vector<vector<string>>v(3,vector<string>(n));
    unordered_map<string,int>mp;

    for (int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
            mp[v[i][j]]++;
        }
    }



   vector<int>v2(3);
    for (int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            if(mp[v[i][j]]==1){
                v2[i]+=3;
            }else if(mp[v[i][j]]==2){
                v2[i]+=1;
            }
        }
    }

    cout<<v2[0]<<" "<<v2[1]<<" "<<v2[2]<<endl;


}

void solve24()
{
    int n;
    cin>>n;
    string str;
    vector<int>v,v2;
    cin>>str;
    int count=0;
    for (int i=0;i<n;i++){
        if (str[i]=='L' and (i<(n-1-i))){
            

            v.push_back(n-1-2*i);
        }
        else if (str[i]=='R'&& i>(n-1-i)){
            v.push_back(2*i+1-n);
        }
        else {
            count+=(n-1-i);
        }

    }int sum=0;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        {
            sum+=v[i];
            v2.push_back(count+sum);
        }
        int sz=v.size();
        for (int i =sz;i<n;i++)
        {
            v2.push_back(count+sum);
        }

        for(int x:v2)
        {
            cout<<x<<" ";
        }
        cout<<endl;

}

 void solve25()
 {
    int n;
    cin>>n;
    string str;
    cin>>str;
    int sz=str.size();
    vector<ll>v1,v2(n+1);
    ll count=0,total=0;
    for (int i=0;i<sz;i++){
        ll l=i;
        ll r=n-i-1;
        if (str[i]=='L'){
            if (r>l){
                count++;
                total+=r;
                v1.push_back(r-l);
            }
            else {
                total+=l;
            }
        }
        else {
            if(l>r){
                count++;
                v1.push_back(l-r);
                total+=l;
            }
            else {
                total+=r;
            }
        }
    }
    for (int i=count;i<=n;i++){
        v2[i]=total;
    }
    sort(v1.begin(),v1.end(),greater<ll>());

    for (int i=count-1;i>=1;i--){
        total-=v1.back();
        v1.pop_back();
        v2[i]=total;
    }

    for (auto i=1;i<v2.size();i++){
        cout<<v2[i]<<" ";
    }
    cout<<endl;
 }

   void FastIO(){
    ios_base :: sync_with_stdio (false);
    cin.tie(NULL);
   }


     
       
  
void TestCase(){
     int t;
     cin >> t;
     while (t--){
         

        
         solve25();
         
          
     }
}

    int main()
    {
        FastIO();
    TestCase();
        

     return 0;

     
    }


  