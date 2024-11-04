


















































using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef set<int> seti;

const double EPS=0.000000001;
const ll INF64=1000000000000000000;
const int INF32=2000000000;

bool id0(pii a,pii b,pii c,pii point){
    int x1=a.first,x2=b.first,x3=c.first,x0=point.first;
    int y1=a.second,y2=b.second,y3=c.second,y0=point.second;
    int aa=(x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0);
    int bb=(x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0);
    int cc=(x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0);
    if (aa==0 || bb==0 || cc==0) return 1;
    if (aa>=0 && bb>=0 && cc>=0) return 1;
    if (aa<=0 && bb<=0 && cc<=0) return 1;
    return 0;
}

bool iss_ll(ll &__1,ll &__2){ return INF64/__1>=__2;}
bool equal(double _1,double _2){ return (abs(_1-_2)<EPS);}
bool id2(int __1){ll __2=sqrt(__1); return __2*__2==__1;};
bool iss_prime(ll __1){for (int i=2; i*i<=__1; ++i) if (!(__1%i)) return 0; return 1;}
int gcd(int __1,int __2){ while (__1 && __2) if (__1>__2)  __1=__1%__2; else __2=__2%__1; return __1+__2;}
int lcm(int &__1,int &__2){ return __1*__2/(gcd(__1, __2));}
int sq_cube(ll x){if (x==0) return 0;int l=0,r=2e6;while (l+1<r){int m=(l+r)/2;if (m*m*m>x) r=m;else l=m;}return l;}

int HASH[1001000];
int dopp[1001000];
int p=97;

int modd;

int bigprost(){
    int x=INF32;
    srand(0);
    x+=(rand()*rand());
    while (!iss_prime(x))++x;
    return x;
}

bool id1 (int l1, int l2, int len){
    int r1=l1+len-1;
    int r2=l2+len-1;
    int x1=((HASH[r1]-HASH[l1-1])%modd)*dopp[l1];
    int x2=((HASH[r2]-HASH[l2-1])%modd)*dopp[l2];
    x1%=modd;
    x1+=modd;
    x1%=modd;
    x2%=modd;
    x2+=modd;
    x2%=modd;
    return x1==x2;
}

signed main(signed argc, const char * argv[]){
    FAST();
    string s,t;
    cin>>s>>t;
    modd=bigprost();
   

    

    int cnt0=0,cnt1=0;
    for (char i:s){
        if (i=='1') ++cnt1;
        else ++cnt0;
    }
    int st=p;
    for (int i=0; i<t.size(); ++i){
        HASH[i+1]=HASH[i]+st*(t[i]-'a');
        HASH[i+1]%=modd;
        st*=p;
        st%=modd;
    }
    vector<pii> mb;
    int n=t.size();
    dopp[n]=1;
    for (int i=n-1; i>0; --i){
        dopp[i]=dopp[i+1]*p;
        dopp[i]%=modd;
    }
    if (cnt1==0){
        if (n%cnt0==0) mb.push_back({0,n/cnt0});
    }elif (cnt0==0){
       if (n%cnt1==0) mb.push_back({n/cnt1,0});
    }else{
        for (int i=1; i<n; ++i){
            if (n-i*cnt1<=0) break;
            
            if ((n-i*cnt1)%cnt0==0){
                mb.push_back({i,(n-i*cnt1)/cnt0});
            }
        }
    }
    int cnt=0;string t1;string t2;
    int poss=1;
    while (poss<s.size() && s[poss]==s[poss-1]) {
        ++poss;
    }
    for (auto i:mb){
        bool fg=1;
        if (i.second==i.first){
           

           

            if (id1(1, poss*i.first+1, i.first))
                continue;
        }
        if (s[0]=='1' || s[0]=='0'){
            int pos=0;
            for (int i1=0; i1<s.size(); ++i1){
               

                if (s[0]=='1'){
                    if (s[i1]=='1'){
                        if (!id1(1+pos,1,i.first)){
                            fg=0;
                           

                           

                           

                            break;
                        }
                        pos+=i.first;
                    }else{
                        if (!id1(1+pos, poss*i.first+1, i.second)){
                            fg=0;
                           

                          

                          

                          

                            break;
                        }
                        pos+=i.second;
                    }
                }else{
                    if (s[i1]=='1'){
                        if (!id1(pos+1,poss*i.second+1,i.first)){
                            fg=0;
                          

                          

                          

                            break;
                        }
                        pos+=i.first;
                    }else{
                        if (!id1(pos+1, 1, i.second)){
                            fg=0;
                          

                        

                        

                            break;
                        }
                        pos+=i.second;
                    }
                }
                
            }
        }
        if (fg) {
           

            ++cnt;
        }
    }
    cout<<cnt<<en;
    return 0;
}
