















using namespace std;
typedef long long int64;
const int inf = 0x3f3f3f3f;
typedef double real;
const real eps = 1e-6;
typedef pair<int64,int> pip;


template<typename T>
T gcd(const T& a, const T& b) {
  return a == 0 ? b : gcd(b%a,a);
}

template<typename T>
bool isprime(const T& k){
  for (T i = 2;i*i<=k;i++)if ((k%i)==0) return false;
  return true;
}

template<typename T>
T mabs(const T& x) {
  if (x>=0) return x;
  return -x;
}

int go(pip a, pip b, int z) {
  if (a.first <= z && a.second > z && b.first <= z && b.second > z) {
    return min(a.second,b.second)-max(a.first,b.first);
  }
  return -1;
}

vector<int> primes;
int TEN[10];

vector<int> canbe[10][100000];
int id0(int p, int x) {
  return ((p/TEN[x])%10);
}
char isp[1<<20];
int64 res = 0;
int b[10];

void go(int x, int k) {
  if (x==k) {
    res++;
    return;
  }
  for (int i = 0; i < canbe[x][b[x]].size(); i++) {
    int p = canbe[x][b[x]][i];
    bool good = true;
    for (int j = x+1; j < k; j++) {
      int q = id0(p,k-1-j);
      if (canbe[x+1][b[j]*10+q].size()==0){
        good = false;
        break;
      }
    }
    if(!good)continue;
    for (int j = x+1; j < k; j++) {
      b[j] = b[j]*10+id0(p,k-1-j);
    }
    int old = b[x];
    b[x]=p;
    go(x+1,k);
    b[x] = old;
    for (int j = x+1; j < k; j++) {
      b[j] /= 10;
    }
  }
}

int solve(int n) {
  int k = 0;
  int q = n;
  for (;q;q/=10,k++);
  q = n;
  for (int i = k-1;q;i--,q/=10){
    b[i] = q%10;
  }
  b[0]=n;
  res=0;
  for (int i = 1; i <=k ; i++) {
    for (int j = 0; j < TEN[i]; j++) {
      canbe[i][j].clear();
    }
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j < primes.size() && primes[j]<TEN[k];j++){
      int x = primes[j]/TEN[k-i];
      canbe[i][x].push_back(primes[j]);
    }
  }
  res=0;
  for (int i = 1; i < k; i++) if (canbe[1][b[i]].size()==0) return 0;
  go(1,k);
  return res;
}


int a[1<<20];
string tt("0123456789`~!@
char allres[]=",,,,4,2,3,1,2,1,4,3,4,2,3,2,1,4,3,4,2,1,2,1,3,n,s,/,t,y,),y,(,{,:,>,&,>,),],+,e,;,;,%,[,h,<,),],;,{,i,>,&,>,],?,^,e,},;,/,h,y,[,y,(,(,:,{,=,),],+,},[,%,n,t,q,w,y,;,{,/,:,&,?,>,),+,*,;,[,s,t,w,<,i,(,&,>,],?,^,*,;,[,n,/,y,[,q,y,i,/,(,{,=,?,],^,},;,n,t,q,),;,{,/,>,&,?,],],*,%,t,h,w,<,),],{,{,&,=,>,^,e,},*,/,h,q,],(,i,(,{,),?,^,},;,%,4<,3:,z],z_,+-,u],S_,a=,P(,*),Y[,)_,/
     int rev[256];
int main(){
  for (int i = 0; i < tt.size(); i++) {
    rev[tt[i]]=i;
  }
  TEN[0]=1;
  for (int i = 1; i < 10; i++) TEN[i] = TEN[i-1]*10;
  memset(isp,1,sizeof(isp));
  isp[0]=isp[1]=0;
  int  maxn = 99999+1;
  for (int i = 2; i*i<maxn;i++)if(isp[i])
    for (int j = i*i;j<maxn;j+=i)isp[j]=0;
  for (int i= 2; i < maxn; i++) if (isp[i]) primes.push_back(i);
  int z = 0;
  for (int i = 0; i < primes.size(); i++) {
    int x = z;
    for (;allres[x]!=',';x++);
    int base = 1;
    int t = 0;
    for (int j = x-1;j>=z;j--){
      t = t*tt.size()+rev[allres[j]];
    }
    z=x+1;
    a[primes[i]]=t;
  }
  int T; cin >> T;
  for (int _ = 0; _ < T; _++){
    int n; cin >> n;
    printf("%d\n",a[n]);
    continue;
    printf("%d\n",solve(n));
  }
  return 0;
  for (int i = 0; i < primes.size(); i++) {
    if (primes[i]>=10 && primes[i]<TEN[5]) {
      printf("a[%d]=%d;",primes[i],solve(primes[i]));
    }
  }
  return 0;
}
