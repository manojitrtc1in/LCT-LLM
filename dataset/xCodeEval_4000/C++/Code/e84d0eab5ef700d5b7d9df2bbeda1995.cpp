#include <bits/stdc++.h>
#include "strstream"
using namespace std;
#define nn   <<endl
#define nnn  <<endl<<
#define ss   <<" "
#define sss   <<" "<

#define ull unsigned long long
#define ll long long

#define voyager1 ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);





int charToInt(char ch){
    return (ch - '0');
}
char intToChar( int digit){
    return (char)(digit + '0');
}
char toLower(char upper)
{
    return (char(upper + 32));
}


ll stringToInt(const string& strNum)
{
    ll num=0, n=0;
    for (ll i = (ll)strNum.size()-1; i >=0 ; i--,n++){num+= (strNum[i]-'0') * (ll)pow(10,n);}
    return num;
}
string intToString(ll num)
{
    strstream s; s << num;
    string str ; s >> str;
    return str;
}
template<typename T>
void printArray(T array[], int size)
{
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " "  ;
    }
    cout << endl;
}
template<typename T>
void printVector(vector<T> vect)
{
    for (const auto& i: vect) { cout << i << ","; }
    cout << endl;
}
template <typename f,typename s>
void printPair(pair<f,s> p)
{
    cout << p.first << " " << p.second << endl;
}
template<typename T>
void swap(T arr[],int firstIndex, int secondIndex)
{
    T temp =arr[firstIndex];
    arr[firstIndex]=arr[secondIndex];
    arr[secondIndex]=temp;
}
template<typename T>
void swap(vector<T>& arr,int firstIndex, int secondIndex)
{
    T temp =arr[firstIndex];
    arr[firstIndex]=arr[secondIndex];
    arr[secondIndex]=temp;
}


ll  fastPower(ll x, ll n)
{
    if(!x) { return 0; }
    if(x==1 || !n) { return 1; }
    long long powerOne=1;
    while (n>1) 

    {
        

        if(n&1){powerOne *= x; n--;}
        x *= x;
        n >>=1;
    }
    return  x * powerOne;
}


template<typename number>
void preFixSum(vector<number>& source)
{
    auto it= source.begin() + 1;
    for( ; it < source.end(); it++)
        (*it)= *(it - 1) + (*it);
}
template<typename number>
void preFixSum( const vector<number>& source, vector<number>& prefix_sum)
{
    prefix_sum.resize(source.size());
    prefix_sum[0]=source[0];
    auto itSource= source.begin() + 1;
    auto itPrefix_sum= prefix_sum.begin() + 1;
    for( ; itSource < source.end(); itSource++,itPrefix_sum++)
        (*itPrefix_sum)= *(itPrefix_sum - 1) + (*itSource);
}


template<typename T>
bool check( int i, T mask){return ( (mask >> i) & 1 ) ;}
template<typename T>
void setDigit(bool val,int i, T& mask)
{
    if(val){ mask |= (1ll<<i); }
    else{mask &=(~(1ll<<i));}
}
template<typename T>
void flip(int i, T& mask){mask ^= (1ll<<i);}
template<typename T>
T countOnes(T mask)
{
    T ctr=0;
    for(T i=0;(1ll<<i)<=mask;i++){if(check(i)){ctr++;}}
    return ctr;
}


void program()
{
    int n, m;
    cin >> n >> m;
    string program;
    cin >> program;
    vector<int> preFixMax(n);
    vector<int> preFixMin(n);
    vector<int> sufFixMax(n);
    vector<int> sufFixMin(n);
    vector<int> sum;
    int x=0;
    if(program[0]=='+'){x=1;} else {x=-1;};
    sum.push_back(x);
    preFixMax[0] = max(0,x) ;
    preFixMin[0] = min(0,x) ;
    for (int i = 1; i < program.size(); ++i)
    {
        if(program[i]=='+'){x++;} else {x--;}
        sum.push_back(x);
        preFixMax[i] = max(x,preFixMax[i-1]);
        preFixMin[i] = min(x,preFixMin[i-1]);
    }

    if(program[n-1]=='+'){x=1;} else {x=-1;};
    sufFixMax[n-1] = max(0,x) ;
    sufFixMin[n-1] = min(0,x) ;
    for (int i = n-2; i >=0; --i)
    {
        if(program[i]=='+'){x++;} else {x--;}
        sufFixMax[i] = max(x,sufFixMax[i+1]);
        sufFixMin[i] = min(x,sufFixMin[i+1]);
    }
    

    

    



    int l , r;
    while (m--) {
        cin >> l >> r; 

        l--;
        r--;
        if(l==0 && r==program.size()-1){cout << 1 << endl;continue;}

        if (l == 0)
        {
            cout <<  (sufFixMax[r + 1] )- sufFixMin[r+1] +1 <<endl;
            

        }
        else
        {
            if(r!=n-1){ cout << max(preFixMax[l - 1],  sum[l-1] +(sufFixMax[r + 1]+sum[r])) - min(preFixMin[l-1]  ,sum[l-1] + (sufFixMin[r+1] +sum[r])) +1  <<endl; }
            else{ cout << (preFixMax[l - 1]) - (preFixMin[l-1])  +1  <<endl; }
            

        }

    }

}


bool closer(int a, int b , int x)
{
    if((abs(x-a)<abs(x-b)) || ((abs(x-a) == abs(x-b)) && (a<b))){return true;}
    return false;
}
vector<int> findClosestElements(vector<int>& arr, int k, int x)
{
    int lo=0, hi=(int)arr.size()-k, mid, ans=-1;
    while (lo<=hi)
    {
        mid=lo+(hi-lo)/2;
        if(closer(arr[mid+k], arr[mid], x)){ans=mid+1; lo=mid+1;}
        else if (closer(arr[mid-1], arr[mid+k-1], x)){ans=mid-1; hi=mid+k-2;}
        else{ans=mid; break;}
    }



    vector<int> v;
    for (int i = ans; i < ans+k ; ++i) {v.push_back(arr[i]);}
    return v;


}


bool isPrimeRec(ll num)
{
    if (num<=1)
        return 0;
    static ll div= 1;
    div++;
    if((div*div)>num) {div = 1;return true;}
    if(num%div==0) {div = 1;  return false;}
    return isPrimeRec(num);

}
bool isPrimeItr(ll num)
{
    if(num==2){return true;}
    if ((num<=1) || !(num&1)) { return 0; }
    for (int i = 2; (i*i) <=num ; ++i) { if(num%i ==0){return false;}}
    return true;

}


void getFactors(ll n, vector<ll >& ans, bool sorted=false)
{
    

    if(!sorted) {
        for (ll i = 1; i * i <= n; ++i) {
            if (!(n % i)) {
                ans.push_back(i);
                if (i * i != n) { ans.push_back(n / i); }
            }
        }
    }
    else{
        vector<ll> secondHalf;
        for (ll i = 1; i * i <= n; ++i) {
            if (!(n % i)) {
                ans.push_back(i);
                if (i * i != n) { secondHalf.push_back(n / i); }
            }
        }
        for(auto it=secondHalf.rbegin();it<secondHalf.rend();it++){ans.push_back(*it);}
    }
}
void getPrimeFactors (ll n, vector<pair<ll,int>>& ans)
{
    

    for (ll i = 2; i*i<=n ; ++i) {
        int power=0;
        while (n%i==0){power++;  n/=i;} 

        if(power){ans.emplace_back(i,power);}
    }
    if(n!=1){ans.emplace_back(n,1);}
}
void getPrimeFactors (ll n, map<ll,int>& ans)
{
    

    for (ll i = 2; i*i<=n ; ++i) {
        int power=0;
        while (n%i==0){power++;  n/=i;} 

        if(power){ans.insert({i, power});}
    }
    if(n!=1){ans.insert({n, 1});}
}
void getPrimeFactors (ll n, unordered_map<ll,int>& ans)
{
    

    for (ll i = 2; i*i<=n ; ++i) {
        int power=0;
        while (n%i==0){power++;  n/=i;} 

        if(power){ans.insert({i, power});}
    }
    if(n!=1){ans.insert({n, 1});}
}
void getPrimeFactors (ll n, vector<ll>& ans)
{
    

    for (ll i = 2; i*i<=n ; ++i) {
        while (n%i==0){ ans.emplace_back(i); n/=i;} 

    }
    if(n!=1){ans.emplace_back(n);}
}
void getPrimeFactors2(ll n, vector<pair<ll,int>>& ans)
{
    

    ll prevFactor=1;
    while (n>1)
    {
        

        ll firstFactor = -1;
        for (ll i = prevFactor + 1; i * i <= n; ++i) { if ((n % i) == 0) { firstFactor = i; break; }}
        if (firstFactor == -1) { firstFactor = n; } 

        

        int power = 0;
        while ((n % firstFactor)==0) {power++;  n/=firstFactor;}
        ans.emplace_back(firstFactor, power);
        prevFactor = firstFactor;
    }
}

void getPrimeFactorsNumberSieve(ll n,vector<ll>& composite)
{
    

    composite.clear();
    composite.resize(n + 10, 0); 

    composite[0]=0;composite[1]=0;
    for (ll i = 2; i<=n ; ++i) {
        if(!composite[i]){
            for(ll nonPrime= i * 2; nonPrime <= n; nonPrime+=i){ composite[nonPrime]++;}
        }
    }

}


void sieve(ll n, vector<ll>& ans)
{
    

    vector<bool> prims(n + 10, 1);
    prims[0] = prims[1] = 0;
    for (ll i = 2;  i <=n ; ++i) {
        if(prims[i]){
            ans.push_back(i);
            for(ll nonPrime = i*i; nonPrime <= n; nonPrime += i){ prims[nonPrime]=0;}
         }
    }
}
void sieve(ll n, unordered_set<ll>& ans)
{
    

    vector<bool> prims(n + 10, 1);
    prims[0]=0;prims[1]=0;
    for (ll i = 2; i <=n ; ++i) {
        if(prims[i]){
            ans.insert(i);
            for(ll nonPrime = i*i; nonPrime <= n; nonPrime += i){ prims[nonPrime]=0;}
        }
    }
}


ll gcd(ll a, ll b){return (b? gcd(b,a%b):a);}


ll lcm(ll a, ll b){return (a/gcd(a,b) * b);}


long long bigModRec(const ll& b , ll p , const ll& m)
{
    if(p==1){ return b % m; }
    if(p%2==0)
    {
        ll half = bigModRec(b, p / 2, m);
        return (((half%m)*(half%m)) % m);
    }
    else{return ( (b%m) * (bigModRec(b, (p - 1), m)%m) ) % m;}
}


ll modInverseFermat(ll a, ll m)
{
    if(gcd(a,m)!=1){return -1;}
    return bigModRec(a,m-2,m);
}


ll nCrMod(ll n , ll r, ll m)
{
    

    

    if(n<r){return 0;}
    ll factMod[n+1];
    factMod[0]=1;
    for (int i = 1; i <=n ; i++) { factMod[i] = ((factMod[i-1]%m )*(i%m)) % m; }
    return ((factMod[n]*modInverseFermat(factMod[r],m))%m * modInverseFermat(factMod[n-r], m))%m; 

}


void countSort(vector<int>& nums)
{
    int mx= *(std::max_element(nums.begin(), nums.end()));
    int mn= *std::min_element(nums.begin(), nums.end());
    int shift = abs(min(mn,0));
    vector<int> freqArr(mx+shift+1,0);
    for (auto i:nums) { freqArr[i+shift]++;}
    for (int i = 0, j=0; i < freqArr.size(); ++i) {
        while (freqArr[i]--){nums[j++]=i-shift;}
    }
}


void countSortDigits(vector<int>& nums, int place)
{
    vector<queue<int>> freq(10);
    for (const int & i:nums) { freq[(i/place)%10].push(i);}

    for (int freqIndex = 0, numsIndex=0; freqIndex < 10; ++freqIndex) {
        while (!freq[freqIndex].empty()){
            nums[numsIndex++]=freq[freqIndex].front();
            freq[freqIndex].pop();
        }
    }
}
void radixSort(vector<int>& nums)
{
    int mx= *(max_element(nums.begin(), nums.end()));
    int mxLength=0;
    while(mx){mxLength++;mx/=10;}

    for (int i=1, place=1; i<=mxLength; ++i, place*=10 ) {countSortDigits(nums, place);}
}


void mergee (vector<int>& arr, int left, int mid, int right, vector<int>& tempArr)
{
    

    int l_idx = left, r_idx = mid+1, tempArr_idx=left;

    

    while(l_idx<=mid && r_idx <= right){
        if( arr[l_idx] <= arr[r_idx]) { tempArr[tempArr_idx++]=arr[l_idx++]; }
        else {  tempArr[tempArr_idx++]=arr[r_idx++];
        }
    }

    

    while (l_idx <= mid ) { tempArr[tempArr_idx++]=arr[l_idx++]; }
    while (r_idx <= right){ tempArr[tempArr_idx++]=arr[r_idx++]; }

    

    for (int i = left, j=left; i <= right ; ++i, ++j) { arr[i]=tempArr[j]; }

}
void mergeSort(vector<int>& arr, int left, int right, vector<int>& tempArr)
{

    if(left >= right){ return;}

    int mid = left + (right-left)/2;

    mergeSort(arr, left, mid,tempArr );
    mergeSort(arr, mid+1, right, tempArr);

    mergee(arr, left, mid, right, tempArr);

}
void mergeSort(vector<int>& arr, int left, int right )
{
    vector<int> tempArr (arr.size());
    mergeSort(arr, left, right, tempArr);
}




template<typename itemType, typename comparator>
void mergee (vector<itemType>& arr, int left, int mid, int right, vector<itemType>& tempArr, comparator comp)
{
    

    int l_idx = left, r_idx = mid+1, tempArr_idx=left;

    

    while(l_idx<=mid && r_idx <= right){
        if(comp(arr[l_idx], arr[r_idx])) { tempArr[tempArr_idx++] = arr[l_idx++]; }
        else { tempArr[tempArr_idx++] = arr[r_idx++];}
    }

    

    while (l_idx <= mid ) { tempArr[tempArr_idx++]=arr[l_idx++]; }
    while (r_idx <= right){ tempArr[tempArr_idx++]=arr[r_idx++]; }

    

    for (int i = left, j=left; i <= right ; ++i, ++j) { arr[i]=tempArr[j]; }

}
template<typename itemType, typename comparator>
void mergeSortAux(vector<itemType>& arr, int left, int right, vector<itemType>& tempArr, comparator comp)
{

    if(left >= right){ return;}

    int mid = left + (right-left)/2;
    mergeSortAux(arr, left, mid, tempArr, comp);
    mergeSortAux(arr, mid+1, right, tempArr, comp);
    mergee(arr, left, mid, right, tempArr, comp);

}
template<typename itemType, typename comparator>
void mergeSort(vector<itemType>& arr, int left, int right, comparator comp)
{
    vector<itemType> tempArr (arr.size());
    mergeSortAux(arr, left, right, tempArr, comp);
}


void swapMe(int& a, int& b){ int temp = a; a=b; b=temp; }
int partitioning (vector<int>& arr,int left,  int right)
{
    int pivot = left;

    for (int i = left+1; i <= right ; ++i) {
        if(arr[i] < arr[pivot]){
            swapMe(arr[pivot+1], arr[i]);
            swapMe(arr[pivot], arr[pivot+1]);
            pivot++;
        }
    }
    return pivot;
}
void quickSort(vector<int>& arr,int left,  int right)
{
    if(left >= right){ return;}

    int pivot = partitioning(arr, left, right);
    quickSort(arr, left, pivot-1);
    quickSort(arr, pivot+1, right);


}


bool isSuPerThan(const vector<vector<int>>& nums, int i1, int i2)
{
    int ctr=0;
    for (int i = 0; i < 5; ++i) { if(nums[i1][i] < nums[i2][i]){ ctr++;} }
    if(ctr>=3){ return 1;} else{ return 0; }
}
void solve()
{
    int n; cin >> n;
    vector<vector<int>> nums(n,vector<int>(5));
    for (auto &i:nums) {
        for (auto &j:i) { cin >> j;}
    }


    int super_i=0;
    for (int i = 0; i < n; ++i) {
        if(!isSuPerThan(nums, super_i, i)){super_i = i;}
    }


    for (int i = 0; i < n; ++i) {
        if(i==super_i){ continue;}
        if(!isSuPerThan(nums, super_i, i)){ cout << -1 << endl; return;}
    }
    cout << super_i+1 << endl;




}

int main()
{

    

    voyager1
    



    int tc=1; cin >> tc;
    while (tc--)
    {
        solve ();

    }

    

    return 0;
}












   	 						   	 		  			 	  			