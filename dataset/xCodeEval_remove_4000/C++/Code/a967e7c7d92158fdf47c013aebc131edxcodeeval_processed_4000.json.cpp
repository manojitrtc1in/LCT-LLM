
using namespace std;

 
    

const int base=1e9+7;
long long IndianMul(long long a,long long b){
    if (b == 0)
        return 0;
    long long t = IndianMul(a, b / 2)%base;
    if((b&1)==0)
        t = (t + t)%base;
    if ((b&1)== 1)
        t = (t +t+ a)%base;
    return t;
}
long long POW(long long a, long long n)
{
    if(n==0) return 1;
    if(n == 1) {
        return a;
    }
    if(n>1){
        long long temp = POW(a, n/2);
        if((n&1) == 0)
            return (temp * temp)%base;
        else
            return ((temp * temp)%base* a)%base;
    }
}
long long t,n,a[100001],cnt[100001];
bool used[100001];
main (){
    cin>>t;
    while(t--){
        cin>>n;
        deque<long long>dq;
        long long res=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            int id=log2(a[i]);
            cnt[id]++;
            if(!used[id]){
                used[id]=true;
                dq.push_front(id);
            }
        }
        while(!dq.empty()){
            used[dq.front()]=false;
            res+=cnt[dq.front()]*(cnt[dq.front()]-1)/2;
            cnt[dq.front()]=0;
            dq.pop_front();
        }
        cout<<res<<'\n';
    }
}
