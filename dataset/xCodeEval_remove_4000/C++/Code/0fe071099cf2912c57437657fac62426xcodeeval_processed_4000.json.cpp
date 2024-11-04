







































const double Pi = 3.1415926535897932384626433832795;
const ll mod = 1e9+7;
using namespace std;




ll GCD(ll a, ll b)
{
	if (b == 0) return a;
	return GCD(b, a % b);
}

ll lcm(int a, int b){ return (a / GCD(a, b)) * b; }

bool isPrime(ull num){
	if (num == 0 || num == 1 || (num % 2 == 0 && num != 2))
		return false;
	for (ull i = 3; i*i <= num; i += 2) {
		if (num % i == 0)
			return false;
	}
	return true;
}

ull NCR(int n, int r) {
	if (n < r)
		return 0;
	if (r > n - r) r = n - r;
	long long ans = 1;
	int i;

	for (i = 1; i <= r; i++) {
		ans *= n - r + i;
		ans /= i;
	}
	return ans;
}



string bin(int n){
	string s = "";
	if (n == 0)
		return s;
	s+=to_string(n%2)+bin(n / 2);
	reverse(s.begin(), s.end());
	return s;
}
vector<int> v;
void print(int n,int x, int arr[]){
	if (x >= n)
		return;
	v.push_back(arr[x]);
	print(n, x + 2, arr);
}

ll fact(int n){
	if (n == 0 || n == 1)
		return 1;
	return n*fact(n - 1);
}

string vowel = "aeiouAEIOU";
int count(string s, int idx){
	if (idx == s.size())
		return 0;
	return count(s, idx + 1) + (vowel.find(s[idx])!=-1 ? 1 : 0);
}

int getmax(int arr[],int idx,int n, int &max){
	int d;
	for (int i = idx; i < n; i++){
		if (arr[i]>max){
			max = arr[i];
			d = i;
		}
	}
	return d;
}
ll getsum(int arr[], int n, int idx){
	if (idx == n)
		return 0;
	return getsum(arr, n, idx + 1) + arr[idx];
}

int fib(int n){
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	return fib(n - 1) + fib(n - 2);
}

ll getsuf(int arr[], int n, int m){
	if (m == 0)
		return 0;
	return getsuf(arr, n - 1, m - 1) + arr[n];
}

ll getlength(ll n){
	if (n == 1)
		return 1;
	if (n % 2 == 0)
		return getlength(n / 2) + 1;
	else
		return getlength(3*n+1) + 1;
}

ll knapsack(int n, int Weight, int w[], int v[]){

	if (Weight == 0||n==-1)
		return 0;
	
	int sum1 = Weight - w[n] >= 0 ? knapsack(n - 1, Weight - w[n], w, v) + v[n] : knapsack(n - 1, Weight, w, v);
	int sum2 = knapsack(n - 1, Weight, w, v);
	return std::max(sum1,sum2);
}

bool Valid(int arr[],int n,int z, int x, ll sum){
	if (n == z)
		return sum == x ? true : false;
	return Valid(arr, n,z+1, x, sum - arr[z]) || Valid(arr, n,z+1, x, sum + arr[z]);
}

bool reach(ll n,ll val){
	if (val == n)
		return true;
	else if(val > n)
		return false;
	return reach(n, val * 10) || reach(n, val * 20);
}


set<ll> myset;
void solve(string str, int n){
	if (str.size() == n){
		myset.insert(stoll(str));
		return;
	}
	solve(str + "7", n);
	solve(str + "4", n);
}

bool id0(string str){
	int f = 0, s = 0;
	fori(0, str.size()){
		if (str[i] == '4')
			f++;
		else if (str[i]=='7')
			s++;
	}
	return (f-s==0) ? true : false;
}


ull getSum(ull x){
	ull sum = 0;
	while (x > 0){
		sum += x % 10;
		x /= 10;
	}
	return sum;
}

bool ispal(string s)
{
	for (int i = 0; i < s.size() / 2; i++)
	if (s[i] != s[s.size() - i - 1]) return false;
	return true;
}

ll getpal(string s, string str,ll &c){

	ll sum = stoll(s) + stoll(str);
	if (ispal(to_string(sum)))
		return sum;
	s = to_string(sum);
	str = s;
	reverse(str.begin(), str.end());
	c++;
	return getpal(s, str, c);
	
}
map<int, int>m;
void getdepth(int arr[], int start, int end, int d){
	if (start == end){
		m[arr[start]] = d;
		return;
	}
	if (start > end)
		return;
	int max = 0;
	int idx  = getmax(arr,start,end+1, max);
	m[max] = d;
	getdepth(arr, start, idx - 1, d + 1);
	getdepth(arr, idx+1, end, d + 1);
}




int main()
{
	samir;
	WT{
		m.clear();
		int n, arr[100];
		in n;
		for (int i = 0; i < n; i++){
			in arr[i];
			m[arr[i]] = 0;
		}
		getdepth(arr, 0, n - 1, 0);
		for (int i = 0; i < n; i++)
			out m[arr[i]] << ' ';
		out E;
	}
	return 0;
}
		 		  		  				   	 		  	 					