#include<bits/stdc++.h>
#define   ll                           		long long int
#define   ull                           	unsigned long long int
#define   cint                              const int
#define   fo(number1,number2,number3)  		for(int number1=number2;number1<number3;++number1)
#define   rfo(number1,number2,number3) 		for(int number1=number2-1;number1>=number3;--number1)
#define   pi                          		pair<int,int>
#define   vLL                          		vector<ll>
#define	  vi								vector<int>
#define   vS								vector<string>
#define   pb                          		push_back
#define   ppb                               pop_back
#define   eb 								emplace_back
#define   lbd								lower_bound
#define   ubd								upper_bound
#define   mp                          		make_pair
#define   fastio                      		ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define   cps                         		CLOCKS_PER_SEC
#define   decimal(k)                  		fixed<<setprecision(k)
#define   PI                          		3.14159265359
#define   ff                           		first
#define   ss                           		second
#define   all(V)                      		(V).begin(),(V).end()
#define   alla(a,n) 						a, a+n
#define   sz(v) 							(ll)v.size()
#define   szz(a,n)							sizeof(a)/(n)
#define   SORT(v) 							sort(all(v))
#define   REV	 							reverse
#define   SUM(v) 							accumulate(v.begin(),v.end(),0)
#define   MAX 								max_element
#define   MIN	 							min_element
#define   UNIQUE(v) 						SORT(v); v.erase(unique(v.begin(),v.end()),v.end())
#define   UNIQUEA(a,n) 						unique(a,a+n)-a
#define   MAXA(a,n) 						max_element(a,a+n)
#define   MINA(a,n) 						min_element(a,a+n)
#define   SORTA(a, n) 						sort(alla(a, n))
#define   REVA(a, n) 						reverse(alla(a, n))
#define   mem1(a)           				memset(a,-1,sizeof(a));
#define   mem0(a)           				memset(a,0,sizeof(a));
#define   mymax                       		1000000000000000100
#define   mymin                      		-1000000001
#define   bitcount                    		__builtin_popcount
#define   gcd                         		__gcd
#define   MOD                         		(ll)1000000007
#define   TEST(t) 					  		int tc; cin>>tc; fo(t,1,tc+1)
#define   VECT(v,n)							ll n; cin >> n; vLL v(n); fo(i,0,n-1) cin >> v[i];
#define   NUM(n)							ll n; cin >> n;
#define	  STRING(s)							string s; cin >> s;
#define   TS								to_string
#define   len(s)							(s).length()
#define   line 						  		cout << "\n";
#define   el								"\n"
#define   clkstart							auto start = high_resolution_clock::now();
#define   clkend							auto stop = high_resolution_clock::now(); auto duration = duration_cast<microseconds>(stop - start);
#define   TIME								line; line; cout << "Time taken by function: " << duration.count()/1e6 << " seconds" << endl;
#define   open								{
#define	  close								}
#define   goog(tno)                         cout <<"Case #" << tno << ": "
#define   deb(x)							cout << #x << " = " << x << el;
#define   deb2(x,y)							cout << #x << " = " << x << " : " << #y << " = " << y << el;
#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H
#define left(i) (2*i + 1)
#define right(i) (2*i + 2)
#define parent(i) ((i-1)/2)
#include <vector>
using namespace std;
using namespace std::chrono;
const int maxN = 9e7+1;
bool primebool[maxN];
const int gmax = 3e4+1;
vi g[gmax];
int vis[gmax];

template<class T>
class SegmentTree
{
    public:
        SegmentTree(std::vector<T> data, T value, T (*combine)(T obj1, T obj2));
        SegmentTree(T ar[], int n, T value, T (*combine)(T obj1, T obj2));
        T query(int l, int r);
        void update(int idx, T val);
    private:
        T *tree;
        void buildTree(std::vector<T> data);
        int segTreeSize;
        T valueForExtraNodes;
        T (*combine)(T obj1, T obj2);
        int calculateSize(int n);
        T queryHelper(int l,int r, int st, int ed, int node);
};






ll power(ll x,ll y,ll m){            

    if(y==0)return 1;
    ll a=power(x,y/2,m);
    if(y%2){
        return (a*((a*x)%m))%m;
    }
    else{
        return (a*a)%m;
    }
}

ll power(ll x,ll y){            

    if(y==0)return 1;
    ll a=power(x,y/2);
    if(y%2){
        return (a*((a*x)));
    }
    else{
        return (a*a);
    }
}

ll mod_inverse(ll x,ll m){
    return power(x,m-2,m);
}

ll fact(ll n){
	ll f = 1;
    for(ll i = n+1;--i;)
    {
    	f = f*i;
    }
    return f;
}

ll factmod(ll n, ll m)
{
	ll f = 1;
    for(ll i = n+1;--i;)
    {
    	f = ((f%m)*(i%m))%m;
    }
    return f;
}

ll ncr(ll n, ll r) {
    if(r > n - r) r = n - r;
    ll ans = 1;
    ll i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

int isPal(string s){
    int len=s.size();
    int flag=1;
    for(int i=0;i<len;++i){
        if(s[i]!=s[len-i-1]){
            flag=0;
			break;
        }
    }
    return flag;
}

ll isPrime(ll n)
{
	if(n < 2)
		return 0;
	for(ll i = 2; i*i <= n; i++)
		if(n%i == 0)
			return 0;
	return 1;
}

bool ispow2(ll n)
{
	return (ceil(log2(n)) == floor(log2(n)))?1:0;
}

ll sumD(ll n)
{
	if(n == 0)
		return 0;
	return (n%10) + sumD(n/10);
}

vLL pfactor(ll n)
{
	vLL v;
    while (n % 2 == 0)
    {
        v.pb(2);
        n = n/2;
    }
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            v.pb(i);
            n = n/i;
        }
    }
    if (n > 2)
        v.pb(n);
	return v;
}

string stringsort(string &s)
{
	string sr="";
	ll m[26] ={0};
	fo(i,0,len(s)-1)
		m[s[i]-'a']++;
	fo(i,0,25)
		while(m[i]--)
			sr += (char)(i+'a');
	return sr;
}

void arrinp(int *a, int n)
{
	fo(i,0,n)
		cin >> a[i];
}
void arrinp(ll *a, int n, int any)
{
	fo(i,0,n)
		cin >> a[i];
}
void showarr(int *a, int n)
{
	fo(i,0,n)
		cout << a[i] << " ";
	line;
}

void showarr(ll *a, int n, int any)
{
	fo(i,0,n)
		cout << a[i] << " ";
	line;
}

ll asum(int *a, int st, int ed)
{
	ll sum = 0;
	fo(i,st,ed)
		sum += a[i];
	return sum;
}

ll vsum(vi &a, int st, int ed)
{
	ll sum = 0;
	fo(i,st,ed)
		sum += a[i];
	return sum;
}

int agcd(int *arr, int st, int ed)
{
    int result = arr[st];
    for (int i = st+1; i <ed; i++)
    {
        result = gcd(arr[i], result);

        if(result == 1)
        {
           return 1;
        }
    }
    return result;
}

ll alcm(int *arr, int st, int ed)
{
    ll ans = arr[st];


    for (int i = st+1; i <ed; i++)
        ans = (((arr[i] * ans)) /
                (gcd((ll)arr[i], ans)));

    return ans;
}
int vgcd(vi &arr, int st, int ed)
{
    int result = arr[st];
    for (int i = st+1; i <ed; i++)
    {
        result = gcd(arr[i], result);

        if(result == 1)
        {
           return 1;
        }
    }
    return result;
}
ll vlcm(vLL &arr, int st, int ed)
{
	ll ans = arr[st];


    for (int i = st+1; i <ed; i++)
        ans = (((arr[i] * ans)) /
                (gcd((ll)arr[i], ans)));

    return ans;
}
void showvec(vi &v)
{
	 for(auto &x:v)
		cout << x << " ";
	 line;
}

void showvec(vLL v, int n)
{
	for(auto &x:v)
		cout << x << " ";
	line;
}
vLL divisor(ll n)
{
	vLL v;
    for (int i = 1; i*i < n; i++) {
        if (n % i == 0)
            v.pb(i);
    }
    for (int i = sqrt(n); i >= 1; i--) {
        if (n % i == 0)
            v.pb(n / i);
    }
    return v;

}

vLL divpair(ll n)
{
    vLL v;
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i == i)
                v.pb(i);

            else
                v.pb(i), v.pb(n/i);
        }
    }
    return v;
}

int mostfreq(int *arr, int n)
{
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++)
        hash[arr[i]]++;

    int max_count = 0, res = -1;
    for (auto &i : hash) {
        if (max_count <= i.second) {
            res = i.first;
            max_count = i.second;
        }
    }

    return res;
}

ll mostfreq(vLL &arr)
{
	int n = sz(arr);
    unordered_map<ll, ll> hash;
    for (int i = 0; i < n; i++)
        hash[arr[i]]++;

    ll max_count = 0, res = -1;
    for (auto &i : hash) {
        if (max_count <= i.second) {
            res = i.first;
            max_count = i.second;
        }
    }

    return res;
}

ll kadane(int *a, int n)
{
	ll ans=0,curr=0;
	for(int i=0;i<n;i++)
	{
		curr= curr+a[i];
		curr = max(0LL,curr);
		ans=max(ans,curr);
	}
	return ans;
}

vLL arrayIntersection(int *arr1, int *arr2, int m, int n)
{
	vLL v;
	int i = 0, j = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr1[i])
            j++;
        else
        {
            v.pb(arr2[j]);
            i++;
            j++;
        }
    }
	return v;
}

void leftRotate(int *arr, int d, int n)
{
    d = d % n;
    int g_c_d = gcd(d, n);
    for (int i = 0; i < g_c_d; i++) {
        int temp = arr[i];
        int j = i;

        while (1) {
            int k = j + d;
            if (k >= n)
                k = k - n;

            if (k == i)
                break;

            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}

void seive()
{
    for(int i = 2; i*i <= maxN; i++)
    {
        if(!primebool[i])
        {
            for(int j = i*i; j <= maxN; j+=i)
            {
                primebool[j] = true;
            }
        }
    }
}

vi z_algo(string &s)
{
	int n=s.size();
	vi z(n);
	for(int i=1,l=0,r=0;i<n;i++)
	{
		if(i<=r)
			z[i]=min(r-i+1, z[i-l]);
		while(i+z[i]<n && s[z[i]]==s[i+z[i]])
			z[i]++;
		if(i+z[i]-1>r)
			l=i, r=i+z[i]-1;
	}
	return z;
}

int phi(int n)
{
	int res = n;
	for(int i = 2; i*i <= n; i++)
	{
		if(n%i == 0)
		{
			res/=i;
			res *= (i-1);
			while(n%i == 0)
				n/=i;
		}
	}
	if(n>1)
		res/=n, res *= (n-1);
	return res;
}

void creategraph(int n, int m)
{
	int a, b;
	for(int i = 1; i <= m; i++)
	cin >> a >> b, g[a].pb(b), g[b].pb(a);

}

void dfs(int node)
{
	vis[node] = 1;
	for(int child: g[node])
	if(!vis[child])
		dfs(child);
}

int getSum(int *BITree, int index)
{
	int sum = 0;
	while (index > 0)
	{
		sum += BITree[index];
		index -= index & (-index);
	}
	return sum;
}

void updateBIT(int *BITree, int n, int index, int val)
{
	while (index <= n)
	{
	BITree[index] += val;

	index += index & (-index);
	}
}

void convert(int *arr, int n)
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

int inversion(int *arr, int n)
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


template<class T> SegmentTree<T>::SegmentTree(std::vector<T> data,
                                                T value, T (*combine)(T obj1, T obj2))
{
   this->combine = combine;
   valueForExtraNodes = value;
   segTreeSize = calculateSize(data.size());
   buildTree(data);
}

template<class T> SegmentTree<T>::SegmentTree(T ar[], int n,
                                            T value, T (*combine)(T obj1, T obj2))
{
   this->combine = combine;
   valueForExtraNodes = value;
   segTreeSize = calculateSize(n);

   std::vector<T> data;
   for(int i = 0; i < n; i++)
         data.push_back(ar[i]);

   buildTree(data);
}


template<class T> int SegmentTree<T>::calculateSize(int n)
{
    int pow2 = 1;
    while( pow2 < n)
    {
        pow2 = pow2 << 1;
    }
    return 2*pow2 - 1;
}

template<class T> T SegmentTree<T>::query(int l, int r)
{
    int st = 0, ed = segTreeSize/2;
    return queryHelper(l, r, st, ed, 0);
}

template<class T> T SegmentTree<T>::queryHelper(int l,int r, int st, int ed, int node)
{
    if( (r < st) || (l > ed) || (l > r) )
        return valueForExtraNodes;
    if(st >= l && ed <= r)
        return tree[node];
    T leftVal = queryHelper(l, r, st, (st + ed)/2, left(node));
    T rightVal = queryHelper(l, r, (st+ed)/2 + 1, ed, right(node));
    return combine(leftVal, rightVal);
}

template<class T> void SegmentTree<T>::buildTree(std::vector<T> data)
{
   int n = data.size();
   tree = new T[segTreeSize];
   int extraNodes = (segTreeSize/2 + 1) - n;
   for(int i = segTreeSize - 1; i >= 0; i--)
   {
       if(extraNodes>0)
           {
               tree[i] = valueForExtraNodes;
               extraNodes--;
           }
       else if(n>0)
           {
               tree[i] = data[n-1];
               n--;
           }
       else
           tree[i] = combine(tree[left(i)], tree[right(i)]);
   }
}

template<class T> void SegmentTree<T>::update(int idx, T val)
{
    int segTreeIdx = (segTreeSize/2) + idx;
    tree[segTreeIdx] = val;
    while(parent(segTreeIdx) >= 0)
    {
        segTreeIdx = parent(segTreeIdx);
        if(right(segTreeIdx) < segTreeSize)
          tree[segTreeIdx] = combine(tree[left(segTreeIdx)], tree[right(segTreeIdx)]);
        if(segTreeIdx == 0)
            break;
    }
}

#endif 










void seive();
ll power(ll x,ll y,ll m);											
ll power(ll x, ll y);												
ll mod_inverse(ll x,ll m);											
ll fact(ll n);														
ll fact(ll n, ll m);												
ll ncr(ll n, ll r);													
int isPal(string s);												
ll isPrime(ll n);													
bool ispow2(ll n);													
ll sumD(ll n);														
vLL pfactor(ll n);													
string stringsort(string &s);										
void arrinp(int *a, int n);											
void arrinp(ll *a, int n, int any);									
void showarr(int *a, int n);										
void showarr(ll *a, int n, int any);								
ll asum(int *a, int st, int ed);									
int agcd(int arr[], int st, int ed);								
ll alcm(int *arr, int st, int ed);									
ll vsum(vi &a, int st, int ed);										
int vgcd(vi &arr, int st, int ed);									
ll vlcm(vLL &arr, int st, int ed);									
int inversion(int *arr, int n);										
int mostfreq(int *arr, int n); 										
ll mostfreq(vLL &arr);												
void showvec(vi &v);												
void showvec(vLL v, int n);											
vLL divisor(ll n);													
vLL divpair(ll n);													
ll kadane(int *a, int n);											
vLL arrayIntersection(int *arr1, int *arr2, int m, int n);			
void leftRotate(int *arr, int d, int n);							
vi z_algo(string &s);												
int phi(int n);														
void creategraph(int n, int m);										
void dfs(int node);													







int main()
{
	fastio;
	

	


	TEST(tcc) open
	
	int w,h, n;
	cin >> w >> h >> n;
	int p2w = gcd(1<<20,w);
	int p2h = gcd(1<<20,h);
	ll cnt = p2w*p2h;
	if(n>cnt)
		cout << "NO";
		else
			cout << "YES";
	line;



























	close
	return 0;


}




