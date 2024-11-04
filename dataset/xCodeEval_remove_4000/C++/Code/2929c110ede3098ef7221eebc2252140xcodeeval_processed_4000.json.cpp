














































using namespace std;










typedef long long ll; 

typedef long long lll;

const int maxint=2147483646;
const int minint=-2147483646;
const lll maxlll=9223372036854775805;
const lll minlll=-9223372036854775805;
const ll mody=1000*1000*1000 +7;



template<class T>
ostream& operator<<(ostream& os, vector<T> v){
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
ostream& operator<<(ostream& os, unordered_map<T,U> dt){
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
ostream& operator<<(ostream& os, pair<T,U> dt){
    os<<"("<<dt.first<<","<<dt.second<<")";
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
ostream& operator<<(ostream& os, map<T,U> dt){
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
ostream& operator<<(ostream& os, multimap<T,U> dt){
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
ostream& operator<<(ostream& os, set<T> dt){
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
ostream& operator<<(ostream& os, multiset<T> dt){
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
ostream& operator<<(ostream& os, stack<T> dt){
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
ostream& operator<<(ostream& os, queue<T> dt){
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
ostream& operator<<(ostream& os, list<T> dt){
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
ostream& operator<<(ostream& os, priority_queue<T> dt){
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

template <class T=ll>
vector<pair<T,int>> id3(int n){
    std::vector<pair<T,int>> v;
    loop(i,n){
        T k;
        cin>>k;
        pair<T,int> p(k,i);
        v.push_back(p);
    }
    return v;
}
template<class T=ll, class U=ll>
vector<pair<pair<T,U>,int>> id8(int n){
    std::vector<pair<pair<T,U>,int>> v;
    loop(i,n){
        T a;
        U b;
        cin>>a>>b;
        pair<T,U> p(a,b);
        pair<pair<T,U>,int> pp(p,i);
        v.push_back(pp);
    }
    return v;
}


vector<char> id5(string& s){
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

        int id9=0;
        T maxel;
        for(auto it=m.begin(); it!=m.end(); it++){
            if(it->second.size()>id9){
                id9=it->second.size();
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
    bool equals(freq<T>& o){
        for(auto it=begin(); it!=end(); it++){
            if((*this)[it->first]!=o[it->first]){
                return false;

            }
        }
        for(auto it=o.begin(); it!=o.end(); it++){
            if((*this)[it->first]!=o[it->first]){
                return false;
            }
        }
        return true;
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
vector<int> id4(vector<T>& v){
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
    vector<int> temp=id4(v);
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

ll modsub(ll a, ll b){
    ll ans=a%mody-b%mody;
    if(ans<0){
        return ans+mody;
    }
    return ans;
}



template<class T=ll>
set<T> id0(T n){
    set<T> s;
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
template<class T=ll>
freq<T> pf(T n){
    vector<T> s;
    

    while (n % 2 == 0){
        s.push_back(2);
        n = n/2;
    }
    

    

    for (T i = 3; i <= sqrt(n); i = i + 2){
        

        while (n % i == 0){
            s.push_back(i);
            n = n/i;
        }
    }
    

    

    if (n > 2){
        s.push_back(n);
    }
    return freq<T>(s);
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

string bts(ll n,int p){
    string s="";
    loop(i,p){
        s.push_back('0');
    }
    loop(i,p){
        if(n%2){
            s[p-i-1]='1';
        }
        n/=2;
    }
    return s;
}


void binarysearch(){
    

    


    
}





ll comb[1][1]; 

ll choose(int n,int r){
    if(comb[n][r]!=-1){
        return comb[n][r];
    }
    if(r==n){
        return 1;
    }
    if(r==0){
        return 1;
    }
    comb[n][r]=(choose(n-1,r-1)+choose(n-1,r))%(mody);
    return comb[n][r];
}



ll factorial[1]; 

ll fact(int n){
    if(n==0){
        return 1;
    }
    if(factorial[n]!=-1){
        return factorial[n];
    }else{
        factorial[n]=(n*fact(n-1))%mody;
        return factorial[n];
    }
}


struct point{
    ll a;
    ll b;
    ll c;
    point(ll aa, ll bb, ll cc): a(aa), b(bb),c(cc){}

};
ostream& operator<<(ostream& os, point p){
    os<<"("<<p.a<<", "<<p.b<<", "<<p.c<<")";
    return os;
}
bool operator<(const point &a, const point &b)
{
    if(a.a==b.a){
        if(a.b==b.b){
            return a.c<b.c;
        }
        return a.b<b.b;
    }
    return a.a<b.a;
}
vector<point> id6(int n){
    std::vector<point> v;
    while(n--){
        ll a,b,c;
        cin>>a>>b>>c;
        point p(a,b,c);
        v.push_back(p);
    }
    return v;
}
vector<pair<point,int>> id7(int n){
    std::vector<pair<point,int>> v;
    loop(i,n){
        ll a,b,c;
        cin>>a>>b>>c;
        point p(a,b,c);
        pair<point,int> pp(p,i);
        v.push_back(pp);
    }
    return v;
}
template<class T>
vector<int> islets(vector<T>& v){
    vector<int> ret;
    int cur=1;
    loopy(i,1,v.size()){
        if(v[i]==v[i-1]){
            cur++;
        }else{
            ret.push_back(cur);
            cur=1;
        }
    }
    ret.push_back(cur);
    return ret;
}
















int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<int> ans;
        ans.push_back(n);
        loopy(i,2,n+1){
            int newie=n/i;
        

            if(newie==ans[ans.size()-1]){
                loop(j,newie){
                    ans.push_back(j);
                }
                break;
            }
            ans.push_back(newie);
        }
        

        sort(ans.begin(),ans.end());
        cout<<ans.size()+(n== 1 or n==2)<<endl;
        if(ans[0]!=0){
            cout<<0<<" ";
        }
        loop(i,ans.size()){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}