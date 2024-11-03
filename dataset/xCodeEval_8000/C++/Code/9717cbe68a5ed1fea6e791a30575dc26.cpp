


#include<bits/stdc++.h>
using namespace std;


#define ll                  long long
#define int                 long long
#define double              long double
#define ld                  long double
#define f(i,n)              for(ll i=0;i<(n);i++)
#define f1(i,n)             for(ll i=1;i<=(n);i++)
#define el  	            '\n'
#define sq(a)               (a)*(a)
#define pb                  emplace_back
#define sz(x)               (int)((x).size())
#define all(x)              (x).begin(), (x).end()
#define asort(a,n)          sort(a,a+n)
#define dsort(a,n)          sort(a,a+n,greater<>())
#define vasort(v)           sort(v.begin(), v.end());
#define vdsort(v)           sort(v.begin(), v.end(),greater<>());
#define cina(arr)           f(i,n) cin >> arr[i];
#define YES                 cout << "YES\n"
#define Yes                 cout << "Yes"<<el
#define yes                 cout << "yes"<<el
#define NO                  cout << "NO\n"
#define No                  cout << "No"<<el
#define no                  cout << "no"<<el
#define covid19             ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i, begin, end)  for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define TC                  int t; cin >> t; while(t--)




typedef pair<int,int> pii;
typedef map<int,int>mii;
typedef vector<int>vi;
typedef vector<pii>vii;
typedef set<int> si;
typedef set<char> sc;


bool as_second(const pair<ll,ll> &a, const pair<ll,ll> &b) {return (a.second < b.second); }

bool ds_first(const pair<ll,ll> &a, const pair<ll,ll> &b){ return (a.first > b.first);}

bool ds_second(const pair<ll,ll> &a, const pair<ll,ll> &b) {return a.second>b.second;}


bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}
ll factorial(ll n) {
    int fact = 1;
    for (int i = 1; i <= n; i++)fact *= i;
    return fact;
}
bool primeFactors(int n, int l, int r, bool notFound)
{
    for (int i = l; i <= r; i++)
    {
        if (i == 1)
            i++;
        if (n % i == 0)
        {
            cout << i << " ";
            notFound = false;
        }
        while (n % i == 0)
        {
            n = n / i;
        }
    }
    return notFound;
}
bool IsInBinarySequence(ll number) {
    ll numberToCheck = 1;
    do {
        if (number == numberToCheck) return true;
        numberToCheck *= 2;
    } while (numberToCheck <= number);
    return false;
}
ll nextPowerOf2(ll n)
{
    if (n && !(n & (n - 1)))
        return n;
    ll cnt = 0;
    while (n != 0)
    {
        n >>= 1;
        cnt++;
    }
    ll x = 1;
    x = x << cnt;
    return x;
}
ll highestPowerof2(ll n)
{
    ll res = 0;
    for (ll i = n; i >= 1; i--)
    {
        

        if ((i & (i - 1)) == 0)
        {
            res = i;
            break;
        }
    }
    return res;
}

vector<ll> first50fib1_1_2()
{
    vector<ll>v = { 1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155, 165580141 ,267914296 ,433494437 ,701408733 ,1134903170 ,1836311903 ,2971215073 ,4807526976 ,7778742049,12586269025,20365011074 };
    return v;
}
void first50fib0_0_1()
{
    ll arr[51]={0, 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368,75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437, 701408733, 1134903170, 1836311903, 2971215073, 4807526976, 7778742049};
}
ll fib(ll n) {
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}
ll binets_formula(ll n) {
    double sqrt5 = sqrt(5);

    int F_n = (pow((1 + sqrt5), n) - pow((1 - sqrt5), n)) / (pow(2, n) * sqrt5);

    return F_n;
}




void firstLuckyto1e9()
{
    vector<ll>v = { 4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777, 4444, 4447, 4474, 4477, 4744, 4747, 4774, 4777, 7444, 7447
            , 7474, 7477, 7744, 7747, 7774, 7777, 44444, 44447, 44474, 44477, 44744, 44747, 44774, 44777, 47444, 47447, 47474, 47477
            , 47744, 47747, 47774, 47777, 74444, 74447, 74474, 74477, 74744, 74747, 74774, 74777, 77444, 77447, 77474, 77477, 77744,
                    77747, 77774, 77777, 444444, 444447, 444474, 444477, 444744, 444747, 444774, 444777, 447444, 447447, 447474, 447477, 447744, 447747, 447774, 447777, 474444, 474447, 474474, 474477, 474744, 474747, 474774, 474777, 477444, 477447, 477474, 477477, 477744, 477747, 477774, 477777, 744444, 744447, 744474, 744477, 744744, 744747, 744774, 744777, 747444, 747447, 747474, 747477, 747744, 747747, 747774, 747777, 774444, 774447, 774474, 774477, 774744, 774747, 774774, 774777, 777444, 777447, 777474, 777477, 777744, 777747, 777774, 777777, 4444444, 4444447, 4444474, 4444477, 4444744, 4444747, 4444774, 4444777, 4447444, 4447447, 4447474, 4447477, 4447744, 4447747, 4447774, 4447777, 4474444, 4474447, 4474474, 4474477, 4474744, 4474747, 4474774, 4474777, 4477444, 4477447, 4477474, 4477477, 4477744, 4477747, 4477774, 4477777, 4744444, 4744447,
                    4744474, 4744477, 4744744, 4744747, 4744774, 4744777, 4747444, 4747447, 4747474, 4747477, 4747744, 4747747, 4747774, 4747777, 4774444, 4774447, 4774474, 4774477, 4774744, 4774747, 4774774, 4774777, 4777444, 4777447, 4777474, 4777477, 4777744, 4777747, 4777774, 4777777, 7444444, 7444447, 7444474, 7444477, 7444744, 7444747, 7444774, 7444777, 7447444, 7447447,
                    7447474, 7447477, 7447744, 7447747, 7447774, 7447777, 7474444, 7474447, 7474474, 7474477, 7474744, 7474747, 7474774, 7474777, 7477444, 7477447, 7477474, 7477477, 7477744, 7477747, 7477774, 7477777, 7744444, 7744447, 7744474, 7744477, 7744744, 7744747, 7744774, 7744777, 7747444, 7747447, 7747474, 7747477, 7747744, 7747747, 7747774, 7747777, 7774444, 7774447,
                    7774474, 7774477, 7774744, 7774747, 7774774, 7774777, 7777444, 7777447, 7777474, 7777477, 7777744, 7777747, 7777774, 7777777, 44444444, 44444447, 44444474, 44444477, 44444744, 44444747, 44444774, 44444777, 44447444, 44447447, 44447474, 44447477, 44447744, 44447747, 44447774, 44447777, 44474444, 44474447, 44474474, 44474477, 44474744, 44474747, 44474774, 44474777, 44477444, 44477447, 44477474, 44477477, 44477744, 44477747, 44477774, 44477777, 44744444, 44744447, 44744474, 44744477, 44744744, 44744747, 44744774, 44744777, 44747444, 44747447, 44747474, 44747477, 44747744, 44747747, 44747774, 44747777, 44774444, 44774447, 44774474, 44774477, 44774744, 44774747, 44774774, 44774777, 44777444, 44777447, 44777474, 44777477, 44777744, 44777747, 44777774, 44777777, 47444444, 47444447, 47444474, 47444477, 47444744, 47444747, 47444774, 47444777, 47447444, 47447447, 47447474, 47447477, 47447744, 47447747, 47447774, 47447777, 47474444, 47474447, 47474474, 47474477, 47474744, 47474747, 47474774, 47474777, 47477444, 47477447, 47477474, 47477477, 47477744, 47477747, 47477774, 47477777, 47744444, 47744447, 47744474, 47744477, 47744744, 47744747, 47744774, 47744777, 47747444, 47747447, 47747474, 47747477, 47747744, 47747747, 47747774, 47747777, 47774444, 47774447, 47774474, 47774477, 47774744, 47774747, 47774774, 47774777, 47777444, 47777447, 47777474, 47777477, 47777744, 47777747, 47777774, 47777777, 74444444, 74444447, 74444474, 74444477, 74444744, 74444747, 74444774, 74444777, 74447444, 74447447, 74447474, 74447477, 74447744, 74447747, 74447774, 74447777, 74474444, 74474447, 74474474, 74474477, 74474744, 74474747, 74474774, 74474777, 74477444, 74477447, 74477474, 74477477, 74477744, 74477747, 74477774, 74477777, 74744444, 74744447, 74744474, 74744477, 74744744, 74744747, 74744774, 74744777, 74747444, 74747447, 74747474, 74747477, 74747744, 74747747, 74747774, 74747777, 74774444, 74774447, 74774474, 74774477, 74774744, 74774747, 74774774, 74774777, 74777444, 74777447, 74777474, 74777477, 74777744, 74777747, 74777774, 74777777, 77444444, 77444447, 77444474, 77444477, 77444744, 77444747, 77444774, 77444777, 77447444, 77447447, 77447474, 77447477, 77447744, 77447747, 77447774, 77447777, 77474444, 77474447, 77474474, 77474477, 77474744, 77474747, 77474774, 77474777, 77477444, 77477447, 77477474, 77477477, 77477744, 77477747, 77477774, 77477777, 77744444, 77744447, 77744474, 77744477, 77744744, 77744747, 77744774, 77744777, 77747444, 77747447, 77747474, 77747477, 77747744, 77747747, 77747774, 77747777, 77774444, 77774447, 77774474, 77774477, 77774744, 77774747, 77774774, 77774777, 77777444, 77777447, 77777474, 77777477, 77777744, 77777747, 77777774, 77777777, 444444444, 444444447, 444444474, 444444477, 444444744, 444444747, 444444774, 444444777, 444447444, 444447447, 444447474, 444447477, 444447744, 444447747, 444447774, 444447777, 444474444, 444474447, 444474474, 444474477, 444474744, 444474747, 444474774, 444474777, 444477444, 444477447, 444477474, 444477477, 444477744, 444477747, 444477774, 444477777, 444744444, 444744447, 444744474, 444744477, 444744744, 444744747, 444744774, 444744777, 444747444, 444747447, 444747474, 444747477, 444747744, 444747747, 444747774, 444747777, 444774444, 444774447, 444774474, 444774477, 444774744, 444774747, 444774774, 444774777, 444777444, 444777447, 444777474, 444777477, 444777744, 444777747, 444777774, 444777777, 447444444, 447444447, 447444474, 447444477, 447444744, 447444747, 447444774, 447444777, 447447444, 447447447, 447447474, 447447477, 447447744, 447447747, 447447774, 447447777, 447474444, 447474447, 447474474, 447474477, 447474744, 447474747, 447474774, 447474777, 447477444, 447477447, 447477474, 447477477, 447477744, 447477747,447477774, 447477777, 447744444, 447744447, 447744474, 447744477, 447744744, 447744747, 447744774, 447744777, 447747444,447747447, 447747474, 447747477, 447747744, 447747747, 447747774, 447747777, 447774444, 447774447, 447774474, 447774477
            , 447774744, 447774747, 447774774, 447774777, 447777444, 447777447, 447777474, 447777477, 447777744, 447777747, 447777774, 447777777, 474444444, 474444447, 474444474, 474444477, 474444744, 474444747, 474444774, 474444777, 474447444, 474447447, 474447474, 474447477, 474447744, 474447747, 474447774, 474447777, 474474444, 474474447, 474474474, 474474477, 474474744, 474474747, 474474774, 474474777, 474477444, 474477447, 474477474, 474477477, 474477744, 474477747, 474477774, 474477777, 474744444, 474744447, 474744474, 474744477, 474744744, 474744747, 474744774, 474744777, 474747444, 474747447, 474747474, 474747477, 474747744, 474747747, 474747774, 474747777, 474774444, 474774447, 474774474, 474774477, 474774744, 474774747, 474774774, 474774777, 474777444, 474777447, 474777474, 474777477, 474777744, 474777747, 474777774, 474777777, 477444444, 477444447, 477444474, 477444477, 477444744, 477444747, 477444774, 477444777, 477447444, 477447447, 477447474, 477447477, 477447744, 477447747, 477447774, 477447777, 477474444, 477474447, 477474474, 477474477, 477474744, 477474747,477474774, 477474777, 477477444, 477477447, 477477474, 477477477, 477477744, 477477747, 477477774, 477477777, 477744444,477744447, 477744474, 477744477, 477744744, 477744747, 477744774, 477744777, 477747444, 477747447, 477747474, 477747477
            , 477747744, 477747747, 477747774, 477747777, 477774444, 477774447, 477774474, 477774477, 477774744, 477774747, 477774774, 477774777, 477777444, 477777447, 477777474, 477777477, 477777744, 477777747, 477777774, 477777777, 744444444, 744444447, 744444474, 744444477, 744444744, 744444747, 744444774, 744444777, 744447444, 744447447, 744447474, 744447477, 744447744, 744447747, 744447774, 744447777, 744474444, 744474447, 744474474, 744474477, 744474744, 744474747, 744474774, 744474777, 744477444, 744477447, 744477474, 744477477, 744477744, 744477747, 744477774, 744477777, 744744444, 744744447, 744744474, 744744477, 744744744, 744744747, 744744774, 744744777, 744747444, 744747447, 744747474, 744747477, 744747744, 744747747, 744747774, 744747777, 744774444, 744774447, 744774474, 744774477, 744774744, 744774747, 744774774, 744774777, 744777444, 744777447, 744777474, 744777477, 744777744, 744777747, 744777774, 744777777, 747444444, 747444447, 747444474, 747444477, 747444744, 747444747, 747444774, 747444777, 747447444, 747447447, 747447474, 747447477, 747447744, 747447747,747447774, 747447777, 747474444, 747474447, 747474474, 747474477, 747474744, 747474747, 747474774, 747474777, 747477444,747477447, 747477474, 747477477, 747477744, 747477747, 747477774, 747477777, 747744444, 747744447, 747744474, 747744477
            , 747744744, 747744747, 747744774, 747744777, 747747444, 747747447, 747747474, 747747477, 747747744, 747747747, 747747774, 747747777, 747774444, 747774447, 747774474, 747774477, 747774744, 747774747, 747774774, 747774777, 747777444, 747777447, 747777474, 747777477, 747777744, 747777747, 747777774, 747777777, 774444444, 774444447, 774444474, 774444477, 774444744, 774444747, 774444774, 774444777, 774447444, 774447447, 774447474, 774447477, 774447744, 774447747, 774447774, 774447777, 774474444, 774474447, 774474474, 774474477, 774474744, 774474747, 774474774, 774474777, 774477444, 774477447, 774477474, 774477477, 774477744, 774477747, 774477774, 774477777, 774744444, 774744447, 774744474, 774744477, 774744744, 774744747, 774744774, 774744777, 774747444, 774747447, 774747474, 774747477, 774747744, 774747747, 774747774, 774747777, 774774444, 774774447, 774774474, 774774477, 774774744, 774774747, 774774774, 774774777, 774777444, 774777447, 774777474, 774777477, 774777744, 774777747, 774777774, 774777777, 777444444, 777444447, 777444474, 777444477, 777444744, 777444747,
                    777444774, 777444777, 777447444, 777447447, 777447474, 777447477, 777447744, 777447747, 777447774, 777447777, 777474444,
                    777474447, 777474474, 777474477, 777474744, 777474747, 777474774, 777474777, 777477444, 777477447, 777477474, 777477477
            , 777477744, 777477747, 777477774, 777477777, 777744444, 777744447, 777744474, 777744477, 777744744, 777744747, 777744774, 777744777, 777747444, 777747447, 777747474, 777747477, 777747744, 777747747, 777747774, 777747777, 777774444, 777774447, 777774474, 777774477, 777774744, 777774747, 777774774, 777774777, 777777444, 777777447, 777777474, 777777477, 777777744, 777777747, 777777774, 777777777, 4444444444 };

}
void  luckyGenerator() {
    vector<ll> lucky;
    lucky.pb(0);
    int idx = 0;
    while (lucky.back() < 1e10) {
        lucky.push_back(((lucky[idx] * 10) + 4));
        lucky.push_back((lucky[idx] * 10) + 7);
        idx++;
    }
}
int binarySearch(int a[], int first, int last, int search_num) {
    int middle;
    if (last >= first) {
        middle = (first + last) / 2;
        

        if (a[middle] == search_num)
            return middle + 1;

            

        else if (a[middle] < search_num)
            return binarySearch(a, middle + 1, last, search_num);

            

        else
            return binarySearch(a, first, middle - 1, search_num);
    }
    return -1;
}
void factorize(long long n) {
    int count = 0;
    while (!(n % 2)) {
        n /= 2;
        count++;
    }
    if (count)
        cout << 2 << " " << count << endl;
    for (long long i = 3; i <= sqrt(n); i += 2) {
        count = 0;
        while (n % i == 0) {
            count++;
            n = n / i;
        }
        if (count)
            cout << i << " " << count << endl;
    }
    if (n > 2)
        cout << n << " " << 1 << endl;
}
void primeFactors(ll num) {
    ll fac = 2;
    while (num > 1) {
        if (num % fac == 0) {
            cout << fac << " ";
            num /= fac;
            ll pow = 1;
            while (num % fac == 0) {
                num /= fac;
                pow++;
            }
            cout << pow << el;
        }
        else {
            fac++;
        }
    }
}
bool onePrimeFactor(ll num) {
    ll fac = 2;
    int cnt = 0;
    while (num > 1) {
        if (num % fac == 0) {
            cnt++;
            while (num % fac == 0)
                num /= fac;
        } else
            fac++;
        if (cnt >= 2)
            return false;
    }
    return true;
}
bool isPerfect(ll d)
{
    double temp = d;
    d = sqrt(d);
    temp = sqrt(temp);
    if (temp == d)
        return true;
    return false;
}
void sort(string s[], int n)

{
    for (int i = 1; i < n; i++)
    {
        string temp = s[i];
        int j = i - 1;
        while (j >= 0 && temp.length() < s[j].length())
        {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = temp;
    }
}
bool IsPowerOfTwo(ll x)
{
    return (x & (x - 1)) == 0;
}
int binarySearchCount(ll arr[], int n, ll key)
{
    int left = 0, right = n;

    int mid;
    while (left < right) {
        mid = (right + left) >> 1;

        if (arr[mid] == key) {
            while (mid + 1 < n && arr[mid + 1] == key)
                mid++;
            break;
        }

        else if (arr[mid] > key)
            right = mid;

        else
            left = mid + 1;
    }

    while (mid > -1 && arr[mid] > key)
        mid--;

    return mid + 1;
}
int countOnesInBin(ll n) {
    int cnt = 0;
    while (n) {
        cnt += n & 1;
        n >>= 1;
    }
    return cnt;
}
string convertToBinary(ll x) {
    string s;
    while (x > 0) {
        if (x % 2)
            s += '1';
        else
            s += '0';
        x /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}
ll convertToDecimal(string s) {
    reverse(s.begin(), s.end());
    ll ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1')
            ans += (1 << i);
    }
    return ans;
}
long long lcm(int a, int b)
{
    return (a / __gcd(a, b)) * b;
}
bool palindrome(string s) {
    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] != s[s.length() - i - 1])
            return false;
    }
    return true;
}
int sumOfDigits(ll n) {
    int sum = 0;
    string s = to_string(n);
    f(i, s.length())sum += s[i] - '0';
    return sum;
}
bool isUnique(ll x) {
    int size = log10(x) + 1;
    set<int> s;
    while (x > 0) {
        s.insert(x % 10);
        x /= 10;
    }
    if (s.size() == size)
        return true;
    else
        return false;
}
void subString(string s, int n) {
    for (int i = 0; i < n; i++)
        for (int len = 1; len <= n - i; len++)
            cout << s.substr(i, len) << el;
}

bool sortByVal(const pair<string, int> &a,
               const pair<string, int> &b)
{
    return (a.second > b.second);
}

ll Round(double n) {
    ll y = n;
    if (y == n)
        return y;
    else
        return y + 1;
}
bool isLetter(char x) {
    if (x >= 'A' && x <= 'Z')
        return true;
    else if (x >= 'a' && x <= 'z')
        return true;
    else
        return false;
}
int findLastIndex(string s, char x)
{
    int index = -1;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == x)
            index = i;
    return index;
}
bool isVowel(char c) {
    c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o' || c == 'y')
        return true;
    else
        return false;
}
bool isOdd(char c) {
    if (c == '1' || c == '3' || c == '5' || c == '7' || c == '9')
        return true;
    else
        return false;
}
ll sum(ll n) {
    ll sum = (n * (n + 1)) / 2;
    return sum;
}
ll sumInRange(ll l , ll r) {
    ll ans = sum(r) - sum(l - 1);
    return ans;
}
bool sortedAsc(ll arr[],ll n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i-1])
            return false;
    }
    return true;
}
bool sortedDesc(ll arr[],ll n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1])
            return false;
    }
    return true;
}
ll decimalDigitRoot(ll n) {
    return ((n - 1) % 9) + 1;
}
bool equal(char x , char y) {
    if (x == '.')
        return true;
    return x == y;
}
string add(string s , int n) {
    string temp = "";
    while (n--)
        temp += s;
    return temp;
}
bool regularBracketSequence(string s) {
    stack<char> s1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            s1.push('(');
        else {
            if (s1.empty())
                return false;
            else
                s1.pop();
        }
    }
    return s1.empty();
}
bool sumDigits(int n) {
    int rem = 0;
    while (n) {
        rem += n % 10;
        n /= 10;
    }
    return rem == 10;
}
bool sortedA(int arr[],int n) {
    for (int i = 1; i < n; i++)
        if (arr[i] < arr[i - 1])
            return false;
    return true;
}
bool sortedD(int arr[],int n) {
    for (int i = 1; i < n; i++)
        if (arr[i] > arr[i - 1])
            return false;
    return true;
}





string onlyAlphaString(string s) {
    string temp = "";
    for (int i = 0; i < s.size(); i++)
        if (isalpha(s[i]))temp += tolower(s[i]);
    return temp;
}
int computeXOR(ll a) {
    if (a % 4 == 0) return a;
    else if (a % 4 == 1) return 1;
    else if (a % 4 == 2) return a + 1;
    else return 0;
}
void sort3(int& a, int& b, int& c) {
    if (a > b)swap(a, b);
    if (b > c)swap(b, c);
    if (a > b)swap(a, b);
}
int lis(vector<int>&a) {
    int n = a.size();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[j] < a[i])dp[i] = max(dp[i], dp[j] + 1);
    int ans = dp[0];
    for (int i = 1; i < n; i++)ans = max(ans, dp[i]);
    return ans;
}
bool oneCharacterString(string s) {
    vasort(s);
    return s[0] == s[s.size() - 1];
}

ll nPr(ll n , ll r) {
    ll fact = 1;
    while (r--) {
        fact *= n;
        n--;
    }
    return fact;
}




const ll mod = 1e9 + 7;


const double pi=acos(-1);
bool containEven(string s) {
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '2' || s[i] == '4' || s[i] == '6' || s[i] == '8')return true;
    return false;
}void printNcR(int n, int r) {
    long long p = 1, k = 1;

    if (n - r < r)
        r = n - r;

    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;

            long long m = __gcd(p, k);

            p /= m;
            k /= m;

            n--;
            r--;
        }
    } else
        p = 1;

    cout << p << endl;
}
string convertToTernary(int n) {
    string ans = "";
    while (n > 0) {
        ans += (char) ((n % 3) + '0');
        n /= 3;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
string sumOfTernaries(string s1,string s2) {
    string ans = "";
    for (int i = 0; i < s1.size(); i++) {
        int x = (s1[i] - '0') + (s2[i] - '0');
        x %= 3;
        ans += (char) (x + '0');
    }
    return ans;
}
string unique_string(string s) {
    string t = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == t.back())continue;
        t += s[i];
    }
    return t;
}
int countOdd(int L, int R) {

    int N = (R - L) / 2;

    

    if (R % 2 != 0 || L % 2 != 0)
        N += 1;

    return N;
}


bool isPowerof10(int n) {
    while (n >= 10 && n % 10 == 0)n /= 10;
    return n == 1;
}
int sumDigitsString(string s) {
    int sum = 0;
    for (int i = 0; i < s.size(); i++)sum += s[i] - '0';
    return sum;
}
long long nCr(int n, int r) {
    if(r > n - r) r = n - r; 

    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}
int log_a_base_b(int a, int b) {
    return log2(a) / log2(b);
}










#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
string converToPigLatin(string s) {
    if (s.size() == 1) {
        s += "ay";
        return s;
    }
    string ans = "";
    for (int i = 1; i < s.size(); i++) {
        if (i == 1)ans += (char) toupper(s[i]);
        else ans += (char) tolower(s[i]);
    }
    ans += tolower(s[0]);
    ans += "ay";
    return ans;
}
int cntDivisors(int n) {
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (i * i == n)cnt = (cnt % mod + 1 % mod) % mod;
            else cnt = (cnt % mod + 2 % mod) % mod;
        }
    }
    return cnt % mod;
}
string cfRate(int n) {
    if (n < 1200)return "Newbie";
    else if (n <= 1399)return "Pupil";
    else if (n <= 1599)return "Specialist";
    else if (n <= 1899)return "Expert";
    else if (n <= 2099)return "Candidate master";
    else if (n <= 2299)return "Master";
    else if (n <= 2399)return "International master";
    else if (n <= 2599)return "Grandmaster";
    else if (n <= 2999)return "International grandmaster";
    return "Legendary grandmaster";
}
int maxDigit(int n) {
    int mx = 0;
    while (n > 0) {
        mx = max(mx, n % 10);
        n /= 10;
    }
    return mx;
}
int minDigit(int n) {
    int mn = 1e18;
    while (n > 0) {
        mn = min(mn, n % 10);
        n /= 10;
    }
    return mn;
}
string convert_from_decimal_to_X(int n, int x) {
    string ans = "";
    while (n > 0) {
        int rem = n % x;
        if (rem >= 10) {
            rem -= 10;
            ans += ('A' + rem);
        } else ans += (rem + '0');
        n /= x;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int convert_from_X_to_Decimal(string s,int x) {
    reverse(s.begin(), s.end());
    int st = 1, ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '0') {
            if (isalpha(s[i])) {
                int dig = (s[i] - 'A') + 10;
                ans += dig * st;
            } else ans += (s[i] - '0') * st;
        }
        st *= x;
    }
    return ans;
}
int mod9 = 998244353;
int fast_power(int a, int n) {
    if (n == 0)
        return 1;
    

    if (a == 0)
        return 0;
    int tmp = fast_power(a, n / 2);
    if (n % 2 == 0) 

        return (tmp % mod9 * tmp % mod9) % mod9;
    else
        return (a % mod9 * tmp % mod9 * tmp % mod9) % mod9;
}
bool checkSemiPrime(int num) {
    int cnt = 0;
    for (int i = 2; i * i <= num && cnt < 2; i++) {
        while (num % i == 0) {
            num /= i;
            cnt++;
            if (cnt > 2)break;
        }
    }
    if (num > 1)cnt++;
    return cnt == 2;
}
string binaryAdd(string a, string b) {
    string result = "";
    int temp = 0;
    int size_a = a.size() - 1;
    int size_b = b.size() - 1;

    while (size_a >= 0 || size_b >= 0 || temp == 1) {
        temp += ((size_a >= 0) ? a[size_a] - '0' : 0);
        temp += ((size_b >= 0) ? b[size_b] - '0' : 0);
        result = char(temp % 2 + '0') + result;
        temp /= 2;
        size_a--;
        size_b--;
    }
    return result;
}
int cmp(string a,string b) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i++)cnt += (a[i] != b[i]);
    return cnt;
}
int sumOfDivisors(int n) {
    int sum = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (n / i == i)sum += i;
            else sum += (n / i) + i;
        }
    }
    return sum;
}
int cntDistinctLetters(string s) {
    int cnt = 0;
    map<char, bool> vis;
    for (auto c: s)if (!vis[c] && c != ' ')cnt++, vis[c] = 1;
    return cnt;
}
int32_t main() {
    covid19
    TC {
        int n;
        cin >> n;
        int x, sum = 0, mx = 0;
        f(i, n) {
            cin >> x;
            sum += x;
            mx = max(mx, x);
        }
        if(mx*2<=sum && mx)cout << 1 << el;
        else cout << 2*mx - sum << el;
    }
}




