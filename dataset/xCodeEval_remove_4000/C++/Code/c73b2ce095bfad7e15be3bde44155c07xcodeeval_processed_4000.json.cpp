












using namespace std;

const int id8 = 256;
ll countDigit(ll n)
{
    return floor(log10(n) + 1);
}
ll ipow(ll base, ll exp)
{
    ll result = 1;
    for (;;)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }

    return result;
}

ll divi(ll n)
{  ll r;
     if(n%2==0)
     {
         return 2;
     }
     if(n%3==0)
     {
         return 3;
     }
     

    else
{   r=floor(sqrt(n));
    ll d=5;
    while ((n%d) && (d<n/d)) d+=2;
    if(n%d==0)
        return d;
    else
       return n;
}
}

int id5(int a[], int size)
{
    int id7 = INT_MIN, id2 = 0,
       start =0, end = 0, s=0;

    for (int i=0; i< size; i++ )
    {
        id2 += a[i];

        if (id7 < id2)
        {
            id7 = id2;
            start = s;
            end = i;
        }

        if (id2 < 0)
        {
            id2 = 0;
            s = i + 1;
        }
    }
        cout<< id7 << endl;
    cout << "Starting index "<< start
        << endl << "Ending index "<< end << endl;
}
bool id12(int arr[], int n, int sum)
{
    bool subset[2][sum + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++)
            {
            if (j == 0)
                subset[i % 2][j] = true;
            else if (i == 0)
                subset[i % 2][j] = false;
            else if (arr[i - 1] <= j)
                subset[i%2][j]=subset[(i+1)%2][j-arr[i-1]] || subset[(i+1)%2][j];
            else
                subset[i%2][j]=subset[(i+1)%2][j];
        }
    }

    return subset[n%2][sum];
}

void id15(string str)
{
    int n = str.size();
    int freq[26];
    memset(freq, 0, sizeof(freq));

    

    for (int i = 0; i < n; i++)
        freq[str[i] - 'a']++;

    

    for (int i = 0; i < n; i++) {

        

        

        if (freq[str[i] - 'a'] != 0) {

            

            

            cout << str[i] << freq[str[i] - 'a'] << " ";

            

            

            

            freq[str[i] - 'a'] = 0;
        }
    }
}
string evenlength(string n)
{
    string res = n;
    for (int j = n.length() - 1; j >= 0; --j)
        res += n[j];

    return res;
}
ll id6(vec arr, ll n)
{

    sort(arr.begin(), arr.end());
    ll max_count = 1, res = arr[0], curr_count = 1;
    for (ll i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1])
            curr_count++;
        else {
            if (curr_count > max_count) {
                max_count = curr_count;
                res = arr[i - 1];
            }
            curr_count = 1;
        }
    }

    if (curr_count > max_count)
    {
        max_count = curr_count;
        res = arr[n - 1];
    }

    return res;
}
bool ck(int N)
    {
        if ((sqrt(N) - floor(sqrt(N))) != 0)
            return false;
        return true;
    }
 ll gcs(ll N)
    {
        if (ck(N))
        {

            return N;
        }
        ll aboveN = -1, belowN = -1;
        ll n1;
        n1 = N + 1;
        while (true) {
            if (ck(n1)) {
                aboveN = n1;
                break;
            }
            else
                n1++;
        }


  return aboveN;

}
bool is_prime(ll n) {
    if (n == 1) {
        return false;
    }
    ll i = 2;
    while (i*i <= n) {
        if (n % i == 0) {
            return false;
        }
        i += 1;
    }
    return true;
}
ll id16(ll n)
{
    vector<int> least_prime(n+1, 0);
    least_prime[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        if (least_prime[i] == 0)
        {
            least_prime[i] = i;

            for (int j = 2*i; j <= n; j += i)
                if (least_prime[j] == 0)
                   least_prime[j] = i;
        }
    }

   return least_prime[n];
}
ll id14(ll n)
{
    if (n % 2 == 0)
        return 2;
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return i;
    }

    return n;
}
ll countDistinct(ll arr[], ll n)
{
    unordered_set<int> s;
    ll res = 0;
    for (ll i = 0; i < n; i++) {
        if (s.find(arr[i]) == s.end()) {
            s.insert(arr[i]);
            res++;
        }
    }

    return res;
}
void countFreq(ll arr[], ll n)
{   vec v;
    vector<bool> visited(n, false);
    for (ll i = 0; i < n; i++) {
        if (visited[i] == true)
            continue;

        ll count = 1;
        for (ll j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = true;
                count++;
            }
        }
       v.push_back(count);
    }
    ll f=0;
    f(i,0,v.size())
    {  cout<<v[i]<<" ";
        if(v[i]<3)
        {
            f=1;
        }
    }

    if(f==1)
    {
        cout<<"No"<<endl;
    }
    else
    {
    cout<<"Yes"<<endl;
    }
}
ll mcm(ll p[], ll n)
{
    ll m[n][n];

    ll  j, k, q;
    f(i,1,n)
        {
            m[i][i] = 0;
        }
    f(L,2,n)
    {
        f(i,1,n - L + 1)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] +
                    p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n - 1];
}
ll lis(ll a[],ll n)
{
    int lis[n];
    lis[0]=1;
    for(int i=1;i<n;i++)
    {  lis[i]=1;
        for(int j=0;j<i;j++)
        {
            if(a[i]>=a[j] && lis[i]<lis[j]+1)
            {
                lis[i]=lis[j]+1;
            }
        }
    }

     sort(lis,lis+n);

}
bool id4(long double x)
{
  long double sr = sqrt(x);
  return ((sr - floor(sr)) == 0);
}
ll id13(string str)
{
    int n = str.length();
    int dist_count = 0;
    bool visited[id8] = { false };
    for (int i = 0; i < n; i++) {
        if (visited[str[i]] == false) {
            visited[str[i]] = true;
            dist_count++;
        }
    }
    int start = 0, start_index = -1, min_len = INT_MAX;

    int count = 0;
    int curr_count[id8] = { 0 };
    for (int j = 0; j < n; j++) {
        curr_count[str[j]]++;
        if (curr_count[str[j]] == 1)
            count++;
        if (count == dist_count) {
            while (curr_count[str[start]] > 1) {
                if (curr_count[str[start]] > 1)
                    curr_count[str[start]]--;
                start++;
            }
            int len_window = j - start + 1;
            if (min_len > len_window) {
                min_len = len_window;
                start_index = start;
            }
        }
    }
    return str.substr(start_index, min_len).length();
}
int bs(ll arr[], ll l, ll r, ll x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
void cutrod(int n,int a[],int s)
{

        int i;

	   

	    int dp[n+1] ;
	    for(i=0;i<n+1;i++){
	        dp[i] = INT_MIN ;
	    }
	    dp[0] = 0 ;
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=0;j<s;j++)
	            if(a[j]<=i)
	                dp[i]=max(dp[i],dp[i-a[j]]+1);
	    }
	    cout << dp[n] << endl ;
}
int id10(string &X, string &Y)
{

    

    int m = X.length(), n = Y.length();

    int L[2][n + 1];

    

    

    

    bool bi;

    for (int i = 0; i <= m; i++)
    {

        

        

        bi = i & 1;

        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[bi][j] = 0;

            else if (X[i-1] == Y[j-1])
                 L[bi][j] = L[1 - bi][j - 1] + 1;

            else
                L[bi][j] = max(L[1 - bi][j],
                               L[bi][j - 1]);
        }
    }

    

    

    

    return L[bi][n];
}
bool ckpal(string s,ll n)
{
    for(ll i=0;i <n ;i++){
        if(s[i] != s[n-i-1]){
            return false;
            break;}


          }
          return true;
    }
    bool is_reverse(string s1,string s2, ll m)
{
    ll l1 = m;
    ll l2 = m;
    ll index =0;
    if (index > l1-1)
        return true;

    if (l1 != l2 || s1[index] != s2[l2-index-1])
        return false;

    ++index;
    return is_reverse(s1, s2,index);
}

bool compare(char arr1[], char arr2[])
{
    for (int i=0; i<MAX; i++)
        if (arr1[i] != arr2[i])
            return false;
    return true;
}
bool search(string pat,string txt)
{
    int M = pat.size(), N = txt.size();
    char countP[MAX] = {0}, countTW[MAX] = {0};
    for (int i = 0; i < M; i++)
    {
        (countP[pat[i]])++;
        (countTW[txt[i]])++;
    }
    for (int i = M; i < N; i++)
    {
        if (compare(countP, countTW))
           return true;
        (countTW[txt[i]])++;
        countTW[txt[i-M]]--;
    }
    if (compare(countP, countTW))
        return true;
        return false;
}
ll sd(ll n)
{
    if (n % 2 == 0)
        return 2;
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return i;
    }

    return n;
}
bool isorted(ll a[],ll n)
{
    f(i,0,n-1)
    {
        if(a[i]>a[i+1])
        {
            return false;
        }
    }
    return true;
}
bool id12(ll arr[], ll n, ll sum)
{
    bool subset[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < arr[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= arr[i - 1])
                subset[i][j] = subset[i - 1][j]
                               || subset[i - 1][j - arr[i - 1]];
        }
    }
    return subset[n][sum];
}
int id3(int arr[], int i, int sumCalculated, int sumTotal)
{
    

    

    

    

    if (i==0)
        return abs((sumTotal-sumCalculated) - sumCalculated);


    

    

    

    

    return min(id3(arr, i-1, sumCalculated+arr[i-1], sumTotal),
               id3(arr, i-1, sumCalculated, sumTotal));
}





int findMin(int arr[], int n)
{
    

    int sumTotal = 0;
    for (int i=0; i<n; i++)
        sumTotal += arr[i];

    

    return id3(arr, n, 0, sumTotal);
}
ull ceil(ull n,ull i){
    if(n==0)
        return 0;
    return (n-1)/i+1;
}
ll id9(ll n)
{
    ll s=0;
    while(n!=0)
    {
        s+=n%10;
        n/=10;
    }
    return s;
}
ll mio(vec v,ll n)
{   ll c=0;
    f(i,0,n)
    {
        if(v[i]!=-1)
        {
            c++;
        }
    }
    return c;
}
int count( int n )
{  int m=3;
   int S[2]={1,2};
    int table[n+1];
    memset(table, 0, sizeof(table));
    table[0] = 1;
    for(int i=0; i<m; i++)
        for(int j=S[i]; j<=n; j++)
            table[j] += table[j-S[i]];

    return table[n];
}

ll maxHist(ll row[],ll C)
{
    stack<ll> result;
    ll top_val;
    ll max_area = 0;
    ll area = 0;
    ll i = 0;
    while (i < C) {
        if (result.empty() || row[result.top()] <= row[i])
            result.push(i++);

        else {
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;

            if (!result.empty())
                area = top_val * (i - result.top() - 1);
            max_area = max(area, max_area);
        }
    }
    while (!result.empty()) {
        top_val = row[result.top()];
        result.pop();
        area = top_val * i;
        if (!result.empty())
            area = top_val * (i - result.top() - 1);

        max_area = max(area, max_area);
    }
    return max_area;
}
int id0(int arr[], int n)
{
    

    

    

    

    

    int max = 1, len = 1;

    

    for (int i=1; i<n; i++)
    {
        

        

        

        

        if (arr[i] < arr[i-1])
            len++;
        else
        {
            

            

            

            if (max < len)
                max = len;

            

            

            

            len = 1;
        }
    }

    

    

    if (max < len)
        max = len;

    

    return max;
}
int bitonic(int arr[], int n)
{
    

    

    int inc[n];

    

    

    int dec[n];
    int i, max;

    

    

    inc[0] = 1;

    

    

    dec[n-1] = 1;

    

    for (i = 1; i < n; i++)
    inc[i] = (arr[i] >= arr[i-1])? inc[i-1] + 1: 1;

    

    for (i = n-2; i >= 0; i--)
    dec[i] = (arr[i] >= arr[i+1])? dec[i+1] + 1: 1;
    int len=0;
    return id0(dec,n)+
    id0(inc,n)-1;


    

    

   

    

      

        


   

}
int id11(int A[], int n)
{
	

	

	int I[n + 1];
	I[0] = 1;
	for (int i = 1; i <= n; i++) {
		I[i] = 1;
		if (A[i-1] < A[i])
			I[i] = I[i-1] + 1;
	}

	

	

	int D[n + 1];
	D[n] = 1;
	for (int i = n - 1; i >= 0; i--) {
		D[i] = 1;
		if (A[i] > A[i+1])
			D[i] = D[i+1] + 1;
	}

	

	int lbs_len = 1;
	int beg = 0, end = 0;

	for (int i = 0; i <= n; i++)
	{
		if (lbs_len < I[i] + D[i] - 1)
		{
			lbs_len = I[i] + D[i] - 1;
			beg = i - I[i] + 1;
			end = i + D[i] - 1;
		}
	}

	

	printf("The length of longest bitonic sub-array is %d\n", lbs_len);
	printf("The longest bitonic sub-array is [%d, %d]", beg, end);

	return lbs_len;
}
int id1(int a[], int size)
{
   int id7 = 0, id2 = 0;
   for (int i = 0; i < size; i++)
   {
       id2 = id2 + a[i];
       if (id2 < 0)
           id2 = 0;

       
       else if (id7 < id2)
           id7 = id2;
   }
   return id7;
}
ll binarySearch( ll arr[] , ll x , ll low , ll high )
{
    ll mid;
    while( low < high ) {
        mid = ( high + low ) / 2;
        if( arr[mid]== x ) {
            break;
        }
        else if( arr[mid] > x ) {
            high=mid-1;
        }
        else {
            low= mid+1;
        }
    }
    mid = ( high + low ) / 2;
    if (x>=arr[mid])
        return mid;
    else
        return mid+1;
}
bool solve()
{
    ll n;
    cin>>n;
    ll a[n];
    f(i,0,n)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        return true;
    }
    else{
        ll i=0;
        while(1)
        {
            if(a[i]<a[i+1])
            {
                i++;
            }
            else if(a[i]==a[i+1] && a[i]!=0 && a[i-1]!=a[i]-1)
            {
                a[i]--;
                i++;
                break;
            }
            else
            {
                break;
            }
        }
        while (i<n-1)
        {
            if(a[i]<=0)
            {
                return false;
            }
            if(a[i]<=a[i+1])
            {
                a[i+1]=a[i]-1;
                i++;
            }
            else
            {
                i++;
            }
        }
       return true;
    }


}
int cpk(ll n)
{
    for(ll i=sqrt(n);i>=2;i--)
    {
        if(n%(i*i)==0)
        {
            return 0;
        }
    }
    return 1;
}
ll slv(ll c)
{
    ll s=0;
     if(c%4==0)
            {
                s+=6+1;
            }
             if(c%4==1)
            {
                s+=2+3;
            }
             if(c%4==2)
            {
                s+=4+9;
            }
             if(c%4==3)
            {
                s+=8+7;
            }
            return s;
}
int main()
{ ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  int t;


t=1;

while(t--)
    {
       string arr;
    cin >> arr;

    ll ln = arr.size();

    stack <char> stk;

    ll cnt = 0;
    for(ll i = 0; i < ln; i++){
         if(stk.size() and arr[i] == stk.top()){
             stk.pop();
             cnt++;
         }
         else
             stk.push(arr[i]);
    }

    if(cnt % 2 == 1) cout << "Yes" << endl;
    else cout << "No" << endl;

    }
   return 0;
}
