




































using namespace std;










typedef long long ll; 

typedef long long lll;

const int maxint=2147483646;
const int minint=-2147483646;
const lll maxlll=9223372036854775805;
const lll minlll=-9223372036854775805;
const ll mody=1000000007;



template<class T>
ostream& operator<<(ostream& os, vector<T>& v){
    os<<"[";
    for(int i=0; i<v.size(); i++){
        os<<v[i];
        if(i!=v.size()-1){
            os<<", ";
        }
    }
    os<<"]";
    

    return os;
}
template<class T, class U>
ostream& operator<<(ostream& os, unordered_map<T,U>& dt){
    os<<"{";
    for (auto i=dt.begin(); i!=dt.end(); i++){
        os<<i->first<<": "<<i->second;
        auto temp=i;
        temp++;
        if(temp!=dt.end()){
            os<<", ";
        }
    }
    os<<"}";
    

    return os;
}
template<class T, class U>
ostream& operator<<(ostream& os, pair<T,U>& dt){
    os<<"<"<<dt.first<<","<<dt.second<<">";
    return os;
}
template <typename T, unsigned int N>
typename std::enable_if<!std::is_same<T, char>::value, std::ostream &>::type
operator<<(std::ostream & os, const T (&a)[N]){
    for (size_t i = 0; i < N; ++i)
    {
        os << a[i];
        if(i<N-1){
            cout<<" ";
        }
    }
    os <<endl;
  return os;
}





template<class T, class U>
ostream& operator<<(ostream& os, map<T,U>& dt){
    os<<"{";
    for (auto i=dt.begin(); i!=dt.end(); i++){
        os<<i->first<<": "<<i->second;
        auto temp=i;
        temp++;
        if(temp!=dt.end()){
            os<<", ";
        }
    }
    os<<"}";
    

    return os;
}
template<class T, class U>
ostream& operator<<(ostream& os, multimap<T,U>& dt){
    os<<"{";
    for (auto i=dt.begin(); i!=dt.end(); i++){
        os<<i->first<<": "<<i->second;
        auto temp=i;
        temp++;
        if(temp!=dt.end()){
            os<<", ";
        }
    }
    os<<"}";
    

    return os;
}
template<class T>
ostream& operator<<(ostream& os, set<T>& dt){
    os<<"{";
    for (auto i=dt.begin(); i!=dt.end(); i++){
        os<<*i;
        auto temp=i;
        temp++;
        if(temp!=dt.end()){
            os<<", ";
        }
    }
    os<<"}";
    

    return os;
}
template<class T>
ostream& operator<<(ostream& os, multiset<T>& dt){
    os<<"{";
    for (auto i=dt.begin(); i!=dt.end(); i++){
        os<<*i;
        auto temp=i;
        temp++;
        if(temp!=dt.end()){
            os<<", ";
        }
    }
    os<<"}";
    

    return os;
}
template<class T>
ostream& operator<<(ostream& os, stack<T>& dt){
    stack<T> t;
    os<<"[";
    while(!dt.empty()){
        T temp=dt.top();
        os<<temp;
        dt.pop();
        t.push(temp);
        if(!dt.empty()){
            os<<", ";
        }
    }
    os<<"]";
    while(!t.empty()){
        T temp=t.top();
        dt.push(temp);
        t.pop();
    }
    

    return os;
}
template<class T>
ostream& operator<<(ostream& os, queue<T>& dt){
    queue<T> t;
    os<<"[";
    while(!dt.empty()){
        T temp=dt.front();
        os<<temp;
        dt.pop();
        t.push(temp);
        if(!dt.empty()){
            os<<", ";
        }
    }
    os<<"]";
    while(!t.empty()){
        T temp=t.front();
        dt.push(temp);
        t.pop();
    }
    

    return os;
}
template<class T>
ostream& operator<<(ostream& os, list<T>& dt){
    os<<"[";
    for (auto i=dt.begin(); i!=dt.end(); i++){
        os<<*i;
        auto temp=i;
        temp++;
        if(temp!=dt.end()){
            os<<", ";
        }
    }
    os<<"]";
    

    return os;
}
template<class T>
ostream& operator<<(ostream& os, priority_queue<T>& dt){
    queue<T> t;
    os<<"[";
    while(!dt.empty()){
        T temp=dt.top();
        os<<temp;
        dt.pop();
        t.push(temp);
        if(!dt.empty()){
            os<<", ";
        }
    }
    os<<"]";
    while(!t.empty()){
        T temp=t.front();
        dt.push(temp);
        t.pop();
    }
    

    return os;
}


template <class T=ll>
vector<T> clist(int n){
    std::vector<T> v;
    while(n--){
        T k;
        cin>>k;
        v.push_back(k);
    }
    return v;
}
template<class T=ll, class U=ll>
vector<pair<T,U>> id1(int n){
    std::vector<pair<T,U>> v;
    while(n--){
        T a;
        U b;
        cin>>a>>b;
        pair<T,U> p(a,b);
        v.push_back(p);
    }
    return v;
}



vector<char> id4(string& s){
    vector<char> v;
    for(int i=0; i<s.size(); i++){
        v.push_back(s[i]);
    }
    return v;
}




template<class T>
struct freq{
    

    

    

    

    


    

    map<T,vector<int>>m; 

    int n;
    freq(vector<T>& s){
        n=s.size();
        for(int i=0; i<s.size(); i++){
            if(m.find(s[i])==m.end()){
                vector<int> v;
                m[s[i]]=v;
            }
            m[s[i]].push_back(i);
        }
    }
    freq(string& s){
        n=s.size();
        for(int i=0; i<s.size(); i++){
            if(m.find(s[i])==m.end()){
                vector<int> v;
                m[s[i]]=v;
            }
            m[s[i]].push_back(i);
        }
    }
    typename map<T,vector<int>>::iterator begin(){
        return m.begin();
    }
    typename map<T,vector<int>>::iterator end(){
        return m.end();
    }
    int operator[] (T ind){ 

        if(m.find(ind)==m.end()){
            return 0;
        }
        return m[ind].size();
    }
    T mode(){ 

        int id5=0;
        T maxel;
        for(auto it=m.begin(); it!=m.end(); it++){
            if(it->second.size()>id5){
                id5=it->second.size();
                maxel=it->first;
            }
        }
        return maxel;
    }
    int first(T el){
        if(m[el].size()!=0){
            return m[el][0];
        }
        return n;
    }
    int last(T el){
        if(m[el].size()!=0){
            return m[el][m[el].size()-1];
        }
        return -1;
    }
};




template<class T>
int maxind(vector<T>& v){
    int maxi=0;
    for(int i=1; i<v.size(); i++){
        maxi=(v[maxi]<v[i])? i:maxi;
    }
    return maxi;
}
template<class T>
T maxel(vector<T>& v){
    return v[maxind(v)];
}
template<class T>
int minind(vector<T>& v){
    int mini=0;
    for(int i=1; i<v.size(); i++){
        mini=(v[mini]>v[i])? i:mini;
    }
    return mini;
}
template<class T>
T minel(vector<T>& v){
    return v[minind(v)];
}
template<class T>
vector<ll> partialsums(vector<T>& v){
    vector<ll> ps(v.size());
    ps[0]=v[0];
    for(int i=1; i<v.size();i++){
        ps[i]=ps[i-1]+v[i];
    }
    return ps;
}
template<class T>
ll sumy(vector<T>& v){
    ll s=0;
    for(int i=0; i<v.size(); i++){
        s+=v[i];
    }
    return s;
}
template<class T>
vector<int> id2(vector<T>& v){
    vector<int> ret={0};
    int curi=0;
    for(int i=1; i<v.size(); i++){
        if(v[i]<v[curi]){
            curi=i;

        }
        ret.push_back(curi);
    }
    return ret;
}
template<class T>
vector<int> id3(vector<T>& v){
    vector<int> ret={0};
    int curi=0;
    for(int i=1; i<v.size(); i++){
        if(v[i]>v[curi]){
            curi=i;

        }
        ret.push_back(curi);
    }
    return ret;
}
template<class T>
vector<T> pmin(vector<T>& v){
    vector<T> ret;
    vector<int> temp=id2(v);
    for(int i=0; i<temp.size(); i++){
        ret.push_back(v[temp[i]]);
    }
    return ret;
}
template<class T>
vector<T> pmax(vector<T>& v){
    vector<T> ret;
    vector<int> temp=id3(v);
    for(int i=0; i<temp.size(); i++){
        ret.push_back(v[temp[i]]);
    }
    return ret;
}



int ind(int i, int n){
    if(i%n>=0){
        return i%n;
    }
    return (i%n)+n;
}
struct graph{};





set<int> id0(int n){
    set<int> s;
    for (int i=1; i<=sqrt(n); i++){
        if (n%i == 0){
            

            if (n/i == i){
                s.insert(i);
            }
            else{ 

                s.insert(i);
                s.insert(n/i);
            }
        }
    }
    return s;
}
freq<int> pf(int n){
    vector<int> s;
    

    while (n % 2 == 0){
        s.push_back(2);
        n = n/2;
    }
    

    

    for (int i = 3; i <= sqrt(n); i = i + 2){
        

        while (n % i == 0){
            s.push_back(i);
            n = n/i;
        }
    }
    

    

    if (n > 2){
        s.push_back(n);
    }
    return freq<int>(s);
}


bool isprime[1];
void seive(int n){
    loop(i,n+1){
        isprime[i]=true;;
    }
    isprime[0]=false;
    isprime[1]=false;
    loop(i,n+1){
        if(isprime[i]){
            for(int j=2*i; j<n+1; j+=i){
                isprime[j]=false;
            }
        }
    }
}

ll modexp(ll n, ll e){
    if(e==0){
        return 1;
    }else{
        if(e%2){
            return (n*(modexp(n,e-1)))%mody;
        }else{
            ll res=modexp(n,e/2);
            return (res*res)%mody;
        }
    }
}
int countbits(ll n){
 ll count = 0;
while (n){
    count += n & 1;
    n >>= 1;
}
return count;
}
void binary(){
    

    


    
}






ll dp[502][502][2];
ll fac(ll ones, ll zeroes, int l, ll& modus){
    if(dp[ones][zeroes][l]!=-1){
        return dp[ones][zeroes][l];
    }
    

    if(l==0 && ones==0 && zeroes==0){
        return 1;
    }
    

    

    

    ll ans=0;
    if(zeroes>=2){
        ans+=((zeroes*(zeroes-1))/2)*fac(ones+2,zeroes-2,l-1,modus);
        ans%=modus;
    }
    if(ones>=2){
        ans+=((ones*(ones-1)/2))*fac(ones-2,zeroes,l-1,modus);
        ans%=modus;
    }
    if(ones>=1 && zeroes>=1){
        ans+=(ones*zeroes)*fac(ones,zeroes-1,l-1,modus);
        ans%=modus;
    }
    dp[ones][zeroes][l]=ans;
    return ans;
}
int main(){
    loop(i,502){
        loop(j,502){
            loop(k,2){
                dp[i][j][k]=0;
            }
        }
    }
    int n,m;
    ll modus;
    cin>>n>>m>>modus;
    vector<int> v(n,0);
    loop(i,m){
        int nowcount=0;
        string s;
        cin>>s;
        loop(j,n){
            int p=s[j]-'0';
            

            if(p){
                nowcount++;
                v[j]++;
                if(v[j]>2){
                    cout<<0<<endl;
                    return 0;
                }
            }
        }
        if(nowcount!=2){
            cout<<0<<endl;
            return 0;
        }
    }
    

    freq<int> lt(v);
    int zeroes=lt[0];
    int ones=lt[1];
    int left=n-m;
    dp[0][0][0]=1;
    

    loopy(ld,1,left+1){
        loop(j,ones+zeroes+2){
            loop(i,zeroes+1){
                if(j+2*i!=2*ld){
                    continue;
                }
                    

                    int ly=ld%2;
                    ll ans=0;
                    if(i>=2){
                        ans+=((i*(i-1))/2)*dp[j+2][i-2][ind(ly-1,2)];
                        ans%=modus;
                    }
                    if(j>=2){
                        ans+=((j*(j-1)/2))*dp[j-2][i][ind(ly-1,2)];
                        ans%=modus;
                    }
                    if(j>=1 && i>=1){
                        

                        ans+=(j*i)*dp[j][i-1][ind(ly-1,2)];
                    

                        ans%=modus;
                    }
                    

                    dp[j][i][ly]=ans;
                    

                }
            }
        }
    

    cout<<dp[ones][zeroes][left%2]<<endl;
}
