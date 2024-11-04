










































using namespace std;


typedef vector<int> vint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=2000000000;

int in() {
    int a;
    scanf("%d", &a);
    return a;
}

double din() {
    double a;
    scanf("%lf", &a);
    return a;
}

int gcd(int a, int b) {
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
    

}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

const double eps = 1e-7;








int logbin(int a){
    int c=1;
    while(c<a) c<<=1;
    return c;
}

vector<int>  b,de;
void update(int v,int l,int r,int tl,int tr,int d){
    if(r<l) return ;
    if(l==tl && r==tr){
        if(l!=r){
            if(b[v]>-1)  b[v*2+1]=b[v*2]=b[v];
        }
        b[v]=d;
        return;
    }
    if(b[v]>-1)  b[v*2+1]=b[v*2]=b[v];
    b[v]=-1;
    int tm=(tr+tl)/2;
    update(v<<1,l,min(r,tm),tl,tm,d);
    update((v<<1)+1,max(l,tm+1),r,tm+1,tr,d);
}
int getsum(int v,int k,int tl,int tr){
    if(b[v]>-1){
        return b[v];
    }
    int tm=(tr+tl)/2;
    if(k<=tm){
        return getsum(2*v,k,tl,tm);
    }else{
        return getsum (2*v+1,k,tm+1,tr);
    }
}


int main(){
   

    


    

    int n=in();

    vector<pair<int,int> > v;
    vector<char> u(4);
    int res=0;
    for(int i=0;i<n;++i){
        int x=in(),y=in();
        v.push_back (make_pair(x,y));
    }
    for(int i=0;i<n;++i){
        u.assign (4,0);
        for(int j=0;j<n;++j){
            if(v[i].first==v[j].first && v[i].second<v[j].second){ u[0]=1; break;}
        }
        for(int j=0;j<n;++j){
            if(v[i].first==v[j].first && v[i].second>v[j].second){ u[1]=1; break;}
        }
        for(int j=0;j<n;++j){
            if(v[i].first<v[j].first && v[i].second==v[j].second){ u[2]=1; break;}
        }
        for(int j=0;j<n;++j){
            if(v[i].first>v[j].first && v[i].second==v[j].second){ u[3]=1; break;}
        }
        if(u[0] && u[1] && u[2] && u[3]) ++res;
    }
    cout<<res;

    return 0;

}



