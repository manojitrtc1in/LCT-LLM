




using namespace std;


ll gcd(ll x,ll y){return y ? gcd(y,x%y) : x;}
template<class T>inline void read(T &res){
char c;T flag=1;
while((c=getchar())<'0'||c>'9')if(c=='-')flag=-1;res=c-'0';
while((c=getchar())>='0'&&c<='9')res=res*10+c-'0';res*=flag;
}

int a[1000005],k,sb;
int main()
{
    int t;read(t);
    while(t--){
        ll n,k;
        read(n),read(k);
        int sb=1,f=1;
        for(int i=1;i<=n;i++){
            read(a[i]);
            if(a[i]==k) sb=0;
            else f=0;
        }
        if(sb) {
            cout<<"no"<<endl;
            continue;
        }
        for(int i=1;i<n;i++){
            if(a[i]>=k){
                if(a[i+1]>=k){
                    f=1;break;
                }

            if(i<=n-2&&a[i+2]>=k){
                f=1;
                break;
            }}
        }
        if(!f) cout<<"no\n";
        else cout<<"yes"<<endl;
    }

	return 0;




}
