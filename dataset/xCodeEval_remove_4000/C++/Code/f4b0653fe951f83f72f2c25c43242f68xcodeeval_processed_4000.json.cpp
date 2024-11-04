

using namespace std;

typedef int64_t LL;
typedef long double LD;
typedef uint64_t ull;
const int MX = 1<<22;
const int MOD = 1000000007;
const LL mod2 = 1000000007 * 1LL * 1000000007;
typedef pair< int , int > pii;
typedef pair< LL , LL > pll;






double strtod(string s) { stringstream str(s); double number=0; str>>number; return number; }
LL id4(string s) { stringstream str(s); LL number=0; str>>number; return number; }



LL ff[50005] , M[30005][505];
LL vis[100005]  , pref[100005];
LL cnt , n , m , s , t;
vector<int>gr[100005];

LL dp[1005][1005];

char str[1001][1001];


int dx[] = {-1, 1 , 0 , 0,1,-1,1,-1};
int dy[] = {0, 0 , -1 , 1,1,-1,-1,1};



LL dis[200005] ,dis2[200005];

vector<pll>grp[200005];

void dijkstra(LL v){
    set<pll>s;
    s.insert({0 , v});
    dis[v] = 0;
    while(!s.empty())
    {
        auto ff = *s.begin();
        s.erase(s.begin());
        for(auto i : grp[ff.s])
        {
            if(ff.s == n + 1)
            {
                if(dis[ff.s] + i.s < dis[i.f])
                {
                    s.erase({dis[i.f] , i.f});
                    dis[i.f] = dis[ff.s] + i.s;
                    s.insert({dis[i.f] , i.f});
                }
            }
            else
            {
                if(dis[ff.s] + 2 * 1LL * i.s < dis[i.f])
                {
                    s.erase({dis[i.f] , i.f});
                    dis[i.f] = dis[ff.s] + 2 * 1LL * i.s;
                    s.insert({dis[i.f] , i.f});
                }
            }
        }
    }
}

int Rank[100001],parent[100001],Color[100001][101];
int qu[200001],qq[200001], pai[200001],qar[200001];
int xxx[101],yyy[101];

int findSet(int x){return (parent[x]=(parent[x]==x)? x : findSet(parent[x]));}

int id1(int x,int y){return findSet(x)==findSet(y);}

void unionSet(int x,int y)
{
    if(!id1(x,y))
        {
            int xx=findSet(x),yy=findSet(y);
            if(Rank[xx]>Rank[yy])
            {
                parent[yy]=xx;
            }
            else
            {
                    parent[xx]=yy ;
            }
            if(Rank[xx]==Rank[yy])Rank[yy]++;
        }
}

bool isBetween(pii a, pii b, pii c){
   int crossproduct = (c.s - a.s) * (b.f - a.f) - (c.f - a.f) * (b.s- a.s);

    

    if (abs(crossproduct) != 0)return false;

    int dotproduct = (c.f - a.f) * (b.f - a.f) + (c.s - a.s)*(b.s - a.s);
    if (dotproduct < 0)return false;

    int id3 = (b.f - a.f)*(b.f - a.f) + (b.s - a.s)*(b.s - a.s);
    if (dotproduct > id3)return false;

    return true;
}

LL fast_pow(LL a , LL b , LL mod){
	LL res = 1;
	while(b){
		if(b & 1){
			res = (1LL * res * a) % mod;
		}
		a = (1LL * a * a) % mod;
		b >>= 1;
	}
	return res;
}


LL id0(LL n,LL MOD)
{
    return fast_pow(n,MOD-2,MOD);
}

LL nCr(LL n,LL r)
{
     LL fact[100001];
        fact[0]=1;
        LL i=1;
        while(i<=n)
        {
            fact[i]=(fact[i-1]*i)%MOD;
            i++;
        }

    LL nf=fact[n];
    LL den=(fact[r]*fact[n-r])%MOD;
    LL mmi_den=id0(den,MOD);
    return (nf*mmi_den)%MOD;
}


int  _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);

int mergeSort(int arr[], int array_size)
{
    int *temp = (int *)malloc(sizeof(int)*array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}


int _mergeSort(int arr[], int temp[], int left, int right)
{
  int mid, inv_count = 0;
  if (right > left)
  {
    
    mid = (right + left)/2;

    
    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid+1, right);

    
    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}


int merge(int arr[], int temp[], int left, int mid, int right)
{
  int i, j, k;
  int inv_count = 0;

  i = left; 
  j = mid;  
  k = left; 
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];

     
      inv_count = inv_count + (mid - i);
    }
  }

  
  while (i <= mid - 1)
    temp[k++] = arr[i++];

  
  while (j <= right)
    temp[k++] = arr[j++];

  
  for (i=left; i <= right; i++)
    arr[i] = temp[i];

  return inv_count;
}
vector<int>v[200005];









int getSum(int BITree[], int index)
{
	int sum = 0; 


	

	while (index > 0)
	{
		

		sum += BITree[index];

		

		index -= index & (-index);
	}
	return sum;
}







void updateBIT(int BITree[], int n, int index, int val)
{
	

	while (index <= n)
	{
	

	BITree[index] += val;

	

	index += index & (-index);
	}
}









void convert(int arr[], int n)
{
	

	

	int temp[n];
	for (int i=0; i<n; i++)
		temp[i] = arr[i];
	sort(temp, temp+n);

	

	for (int i=0; i<n; i++)
	{
		

		

		arr[i] = lower_bound(temp, temp+n, arr[i]) - temp + 1;
	}
}



int id2(int arr[], int n)
{
	int invcount = 0; 


	

	

	

	

	convert(arr, n);

	

	

	

	int BIT[n+1];
	for (int i=1; i<=n; i++)
		BIT[i] = 0;

	

	for (int i=n-1; i>=0; i--)
	{
		

		invcount += getSum(BIT, arr[i]-1);

		

		updateBIT(BIT, n, arr[i], 1);
	}

	return invcount;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,q;
    cin>>n>>q;
    LL ar[35]={0};
    for(int i=0;i<n;i++)
    {
        LL x;
        cin>>x;
        for(LL j=31;j>=0;j--)
        {
            if(x&(1LL<<j))
            {
                ar[j]++;
                break;
            }
        }
    }
    for(int i=0;i<q;i++)
    {
        LL x;
        cin>>x;
        LL ans=0;
        for(LL j=31;j>=0;j--)
        {
            if(x && ar[j] && (1LL<<j)<=x)
            {
                LL r=x/(1LL<<j);
                if(r>ar[j]){x-=ar[j]*1LL*(1LL<<j);ans+=ar[j];}
                else {x-=r*1LL*(1LL<<j);ans+=r;}
            }
        }
        if(x)ans=-1;
        cout<<ans<<"\n";
    }


    
    return 0;
}