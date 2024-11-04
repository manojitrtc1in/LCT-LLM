















#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <queue>
#include <fstream>
using namespace std;
#define DEBUG 0
#define mdlo 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef set<long> adjacencyList;
vector<ll> primes;
long long mInv[10000];
typedef vector<long> adjList;
typedef set<long> divisors;
typedef vector<pair<ll,ll>> weightedAdjList;
weightedAdjList weightedGraph[200005];

divisors allDivisors[1005];
ll fact[100005];
ll fib[200005];
adjList graph[300005];
long visited[25];
long parent[300005];
ll firstOf2sPowers[40];
ll N;
ll nums[500005];

ll segTreeData[500505];
ll minSegTree[3000505];
ll maxSegTree[3000505];

void buildfib(int n){
    fib[0] = 1;
    fib[1] = 1;
    n-=2;
    for(int i = 0; i < n; i++){
        fib[i+2] = (fib[i+1] + fib[i]) % mdlo;
    }
}
void genFact(int n){
    fact[0] = 1;
    for(long i = 0; i < n ; i++){
        fact[i+1] = ((i+1) * fact[i]) % mdlo;
    }
}
long long getmoduloInv(long long n){
    if(n==1)
        return 1;
    if(n < 10000 && mInv[n]>0)
        return mInv[n];
    long long m=(-1*mdlo)/n;
    m+=mdlo;
    m*=getmoduloInv(mdlo%n);
    if(n < 10000)
        mInv[n]=(m%mdlo);
    else
        return m%mdlo;
    return mInv[n];
}
divisors getDivisors(long num) {
    if(allDivisors[num].empty()) {
        divisors divs;
        divs.insert(1);
        long lim = 1 + sqrt(num);
        
        for (long i = 0; primes[i] < lim; i++) {
            if(num % primes[i] == 0) {
                divisors sub = getDivisors(num/primes[i]);
                for(set<long>::iterator it = sub.begin(); it != sub.end(); it++ ) {
                    long div = *it;
                    divs.insert(div);
                    divs.insert(div * primes[i]);
                }
                allDivisors[num] = divs;
                return divs;
            }
        }
    }
    return allDivisors[num];
}

bool isPrime2(ll n){
    if(n < 2)
        return false;
    if(n == 2)
        return true;
    if(n % 2 == 0)
        return false;
    ll lim = sqrt(n) + 1;
    for(long i = 3; i <= lim; i+=2){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
bool isPrime(ll n){
    if(n < 2)
        return false;
    if(n == 2)
        return true;
    if(n % 2 == 0)
        return false;
    ll lim = sqrt(n) + 1;
    for(long i = 0; primes[i] <= lim; i++){
        if(n % primes[i] == 0){
            return false;
        }
    }
    return true;
}
vector<ll> genPrimes(ll lim) {
    bitset<1000009> isPrime;
    isPrime.set();
    primes.push_back(2);
    for(long i = 3; i <= lim; i+=2) {
        if(isPrime[i]){
            for(long j = i+i; j<=lim; j+= i) {
                isPrime.reset(j);
            }
            primes.push_back(i);
            if(DEBUG)
                cout<<i<<" ";
        }
    }
    if(DEBUG)
        cout<<endl;
    return primes;
}

void buildMinSegTree(int pos, int startPos, int endPos){
    if(startPos == endPos){
        minSegTree[pos] = startPos;
        return;
    }
    int midPos = ( startPos + endPos)/2;
    buildMinSegTree(pos*2, startPos, midPos);
    buildMinSegTree(pos*2 + 1, midPos +1, endPos);
    minSegTree[pos] = (segTreeData[minSegTree[pos*2]] <= segTreeData[minSegTree[pos*2+1]])?minSegTree[pos*2]:minSegTree[pos*2+1];
}

void buildMaxSegTree(int pos, int startPos, int endPos){
    if(startPos == endPos){
        maxSegTree[pos] = startPos;
        return;
    }
    int midPos = (startPos + endPos)/2;
    buildMaxSegTree(pos*2, startPos, midPos);
    buildMaxSegTree(pos*2 + 1, midPos + 1, endPos);
    maxSegTree[pos] = (segTreeData[maxSegTree[pos *2]] >= segTreeData[maxSegTree[pos * 2 + 1]])?maxSegTree[pos *2]:maxSegTree[pos *2 + 1];
}

ll getMinValPosFromSegTree(int pos, int queryStart, int queryEnd, int rangeStart, int rangeEnd){
    if(queryEnd < rangeStart || queryStart > rangeEnd)
        return -1;
    if(rangeEnd <= queryEnd && rangeStart >= queryStart){
        return minSegTree[pos];
    }
    int midRange = (rangeEnd + rangeStart)/2;
    ll firstHalf = getMinValPosFromSegTree(pos * 2, queryStart, queryEnd, rangeStart, midRange);
    ll secHalf = getMinValPosFromSegTree(pos * 2 + 1, queryStart, queryEnd, midRange + 1, rangeEnd);
    if(firstHalf == -1)
        return secHalf;
    if(secHalf == -1)
        return firstHalf;
    if(segTreeData[firstHalf] <=  segTreeData[secHalf])
        return firstHalf;
    return secHalf;
        
}

ll getMaxValPosFromSegTree(int pos, int queryStart, int queryEnd, int rangeStart, int rangeEnd){
    if(queryEnd < rangeStart || rangeEnd < queryStart)
        return -1;
    if(rangeEnd <= queryEnd && rangeStart >= queryStart){
        return maxSegTree[pos];
    }
    int midRange = (rangeEnd + rangeStart)/2;
    ll firstHalfPos = getMaxValPosFromSegTree(pos * 2, queryStart, queryEnd, rangeStart, midRange);
    ll secHalfPos = getMaxValPosFromSegTree(pos * 2 + 1, queryStart, queryEnd, midRange + 1, rangeEnd);
    if(firstHalfPos == -1)
        return secHalfPos;
    if(secHalfPos == -1)
        return firstHalfPos;
    if(segTreeData[firstHalfPos] > segTreeData[secHalfPos])
        return firstHalfPos;
    return secHalfPos;
}

typedef pair<long, long> fraction;
ll gcd (ll a, ll b) {
    priority_queue<fraction> pq;
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    if(b%a == 0)
        return a;
    return gcd(b%a,a);
}
ll lcm(ll a, ll b) {
    ll g = gcd(a,b);
    a/=g;
    return a*b;
}

vector<ll> getDivisors(ll num) {
    ll lim = 1 + sqrt(num);
    if(primes.empty())
        genPrimes(max((ll)1000006,lim));
    vector<pair<ll,ll>> components;
    for(long i = 0; primes[i] <= lim; i++) {
        if(num % primes[i] == 0) {
            long pow = 0;
            while (num% primes[i] == 0) {
                pow++;
                num/=primes[i];
            }
            lim = 1 +sqrt(num);
            components.push_back(make_pair(primes[i], pow));
        }
    }
    if(num > 1)
        components.push_back(make_pair(num, 1));
    vector<ll> divisors ;
    divisors.push_back(1);
    for(long i = 0; i < components.size(); i++) {
        long curLen = divisors.size();
        ll powVal = 1;
        for(long j = 0; j <components[i].second; j++) {
            powVal *= components[i].first;
            for(long k = 0; k < curLen; k++){
                divisors.push_back(divisors[k]*powVal);
            }
        }
    }
    return divisors;
}

fraction getFraction(ull pos) {
    if(pos == 1){
        fraction f;
        f.first = 1;
        f.second = 1;
        return f;
    }
    fraction f = getFraction(pos/2);
    if(pos % 2 == 0)
        f.second+= f.first;
    else
        f.first += f.second;
    return f;
    
}

void printFab(){
    ll fib[66];
    
    for(long i = 2; i < 64; i++) {
        fib[i] = fib[i-1] + fib[i-2];
        cout<<fib[i]<<" ";
    }
}
string sanitize (string str) {
    long pos = 0;
    while(str[pos] == '0')
        pos++;
    return str.substr(pos);
}
string toBinary (ll num) {
    string binaryString = "";
    return binaryString;
}
class node{
    char val;
    vector<node*> childs;
    long childNum;
public:
    node(){
        val = '.';
        childNum = 0;
    }
    node(char ch){
        val = ch;
        childNum = 0;
    }
    
    void addChild(node* n){
        if(getChild(n->val) == NULL){
            childs.push_back(n);
            childNum++;
        }
    }
    node* addChild(char ch){
        node *n =  getChild(ch);
        if(n == NULL){
            n = new node(ch);
            childs.push_back(n);
            childNum++;
        }
        return n;
    }
    node* getChild(char ch) {
        for(long i = 0; i < childNum; i++) {
            if(childs[i]->val == ch)
                return childs[i];
        }
        return NULL;
    }
    pair<long,long> getMatchCount(){
        long matched = 0;
        long unmatched = 0;
        if(childNum == 0)
            unmatched = 1;
        for(long i = 0; i < childNum; i++) {
            pair<long, long> match = childs[i]->getMatchCount();
            matched += match.first;
            unmatched += match.second;
        }
        if(val != '.') {
            if(unmatched > 1){
                matched+=2;
                if(unmatched > 2)
                    unmatched = 1;
                else
                    unmatched = 0;
            }
        }
        return make_pair(matched, unmatched);
    }
    void printTrie(){
        queue<node*> nodeBfs;
        nodeBfs.push(this);
        while(nodeBfs.empty() == false){
            node *front = nodeBfs.front();
            nodeBfs.pop();
            for(long i = 0; i < childNum; i++) {
                nodeBfs.push(childs[i]);
            }
        }
    }
};
void buildTrie(node *n, string s){
    if(s  == ""){
        n->addChild('*');
        return;
    }
    char ch = s[0];
    node *nextNode = n->getChild(ch);
    if(nextNode == NULL){
        nextNode = n->addChild(ch);
    }
    string restString = s.substr(1);
    buildTrie(nextNode, restString);
}

long comp(string s1, string s2) {
    if(s1.size() > s2.size())
        return 1;
    if(s1.size() < s2.size())
        return -1;
    for(long i = 0; i <s1.size(); i++) {
        if(s1[i] > s2[i])
            return 1;
        if(s2[i] > s1[i])
            return -1;
    }
    return 0;
}


typedef pair<long,long> fraction;
typedef set<fraction> result;
class Solution {
    map<long,long> dpOneWay;
    map<long,long> dpBothWay;
    long long pows[31];
    long base;
public:
    
};



long getTreeSize(long node){
    long size = 0;
    if(visited[node] == 0) {
        queue<long> nodes;
        nodes.push(node);
        visited[node] = 1;
        while (nodes.empty() == false) {
            long curNode = nodes.front();
            nodes.pop();
            size++;
            for(long i = 0; i < graph[curNode].size(); i++) {
                long child = graph[curNode][i];
                if(visited[child] == 0) {
                    nodes.push(child);
                    visited[child] = 1;
                }
            }
        }
    }
    return size;
}
long long getPow(long long base, long long p) {
    if(p == 1 || abs(base) < 2)
        return base;
    if(p == 0)
        return 1;
    long long half = getPow(base, p/2);
    long long result = half*half;
    if(result > mdlo)
        result %= mdlo;
    if(p%2 == 1)
        result = (result*base)%mdlo;
    return result;
}

long editDistance[310][310];
string edit1,edit2;
long getEditDistance(long pos1,long pos2) {
    if(editDistance[pos1][pos2] == -1) {
        if(pos1 >= edit1.size() && pos2 >= edit2.size()) {
            editDistance[pos1][pos2] = 0;
        }
        else if(pos1 >= edit1.size()) {
            editDistance[pos1][pos2] = edit2.size() - pos2;
        }
        else if(pos2 >= edit2.size()) {
            editDistance[pos1][pos2] = edit1.size() -pos1;
        }
        else if(edit2[pos2] == edit1[pos1]) {
            editDistance[pos1][pos2] = getEditDistance(pos1+1, pos2 +1);
        }
        else {
            long removeFirst = 1 + getEditDistance(pos1+ 1, pos2);
            long removeSecond = 1 + getEditDistance(pos1, pos2 +1);
            long changed = 1 + getEditDistance(pos1 + 1, pos2 + 1);
            long finalVal = min(changed,min(removeFirst,removeSecond));
            editDistance[pos1][pos2] = finalVal;
        }
    }
    return editDistance[pos1][pos2];
}

char getResponse(long pos) {
#if DEBUG
    return 'a';
#else
    cout<<pos;
    cout<<flush<<endl;
    char ch;
    cin>>ch;
    return ch;
#endif
}
string spell;
long tryCount;
long getResponse1282D(string s) {
#if DEBUG
    tryCount++;
    cout<<s<<" "<<tryCount<<" ";
    if(tryCount > spell.size() + 2){
        cout<<-1<<endl;
        return -1;
    }
    edit1 = s;
    edit2 = spell;
    memset(editDistance, -1, sizeof(editDistance));
    long dist = getEditDistance(0, 0);
    cout<<dist<<endl;
    return dist;
#else
    cout<<s;
    cout<<flush<<endl;
    long ch;
    cin>>ch;
    return ch;
#endif
}

typedef pair<double,pair<ll,ll>> ratiio;
ratiio getRatio(ll a, ll b){
    ll d = gcd(a,b);
    a/=d;
    b/=d;
    double r = (double)(a)/(double)(b);
    ratiio R ;
    R.first = r;
    R.second = make_pair(a, b);
    return R;
}

string genNextPerMutation(string s){
    long len = s.size();
    long pos = len - 1;
    while(pos > 0 && s[pos]  < s[pos-1])
        pos--;
    if(pos == 0)
        return s;
    char val = s[pos-1];
    long replacePos = pos - 1;
    while(pos < len && s[pos] > val)
        pos++;
    s[replacePos] = s[pos - 1];
    s[pos -1] = val;
    for(long i = 0; i < (len - replacePos)/2;i++){
        char temp = s[replacePos+i+1];
        s[replacePos+i+1] = s[len -(i+1)];
        s[len-(i+1)] = temp;
    }
    return s;
}



double stringToDouble(string s) {
    double val  = 0;
    for(long i = 0; i < s.size(); i++){
        val = val * 10 + (s[i] - '0');
    }
    return val;
}

string moveToLast(string s, long pos){
    char temp = s[pos];
    long len = s.size();
    while(pos + 1 < len){
        s[pos] = s[pos+1];
        pos++;
    }
    s[pos] = temp;
    return s;
}
bool isSorted(string s){
    for(long pos = 0; pos +1 < s.size(); pos++){
        if(s[pos] > s[pos+1])
            return false;
    }
    return true;
}

vector<ll> getPrimeDivisors(ll num){
    vector<ll>primeDivisors;
    long pos = 0;
    while(primes[pos] * primes[pos] <= num){
        if(num%primes[pos] == 0){
            primeDivisors.push_back(primes[pos]);
            while(num%primes[pos] == 0)
                num/=primes[pos];
        }
        pos++;
    }
    if(num > 1)
        primeDivisors.push_back(num);
    return primeDivisors;
}

ll n,m;
auto my_comp = [](const pair<ll,ll>& e1, const pair<ll,ll>& e2)
{ return e1.first > e2.first; };
using my_container_t = std::vector<pair<ll,ll>>;
priority_queue<pair<ll,ll>,my_container_t,decltype(my_comp)> next_node(my_comp);

long getAncestor(long node) {
    if(-1 == parent[node])
        parent[node] = node;
    if(node != parent[node])
        parent[node] = getAncestor(parent[node]);
    return parent[node];
}
void unifyNodes(long node1, long node2) {
    long par1 = getAncestor(node1);
    long par2 = getAncestor(node2);
    if(par1 > par2) {
        parent[par2] = par1;
    }
    else if(par2 > par1) {
        parent[par1] = par2;
    }
}
string incrementString(string S) {
    long pos = S.size() - 1;
    while(pos >=0 && S[pos] == '9'){
        pos--;
    }
    if(pos >= 0){
        S[pos] = S[pos] +1;
        for(long i = pos + 1; i < S.size(); i++) {
            S[i] = '0';
        }
        return S;
    }
    else {
        string temp = "1";
        for(long i = 0; i < S.size(); i++){
            temp = temp +"0";
        }
        return temp;
    }
        
    return "";
}
long compString(string s1, string s2){
    for(long i = 0; i < s1.size(); i++) {
        if(s1[i] < s2[i] ){
            return -1;
        }
        if(s1[i] > s2[i]) {
            return 1;
        }
    }
    return 0;
}


long andCount[100];
long getMinDistance(ll node1, ll node2){
    queue<long>nodeQ;
    map<long,long>level;
    for(long i = 0; i < graph[node1].size(); i++) {
        if(graph[node1][i] != node2) {
            nodeQ.push(graph[node1][i]);
            level[graph[node1][i]] = 1;
        }
    }
    
    while(!nodeQ.empty()){
        long curNode = nodeQ.front();
        long curLevel = level[curNode];
        for(long i = 0; i < graph[curNode].size(); i++) {
            if(graph[curNode][i] == node2) {
                return curLevel + 1;
            }
            if(!(level[graph[curNode][i]] > 0) && graph[curNode][i] != node1){
                nodeQ.push(graph[curNode][i]);
                level[graph[curNode][i]] = curLevel + 1;
            }
        }
        nodeQ.pop();
    }
    return -1;
}
adjacencyList undirectedGraph[25];
adjList trimmedGraph[25];
long groupId[25];
long getGroupId(long node) {
    if(groupId[node] == -1 ){
        groupId[node] = node;
    }
    else if(groupId[node] != node) {
        groupId[node] = getGroupId(groupId[node]);
    }
    return groupId[node];
}

void makeSameGroup(long node1, long node2) {
    long group1 = getGroupId(node1);
    long group2 = getGroupId(node2);
    if(group1 != group2) {
        groupId[group2] = group1;
    }
}


string swapChar(string s, char a, char b) {
    for(long i  = 0; i < s.size(); i++) {
        if(s[i] == a) {
            s[i] = b;
        }
        else if(s[i] == b) {
            s[i] = a;
        }
    }
    return s;
}
ll centerXAssumed,centerYAssumed,qRem,R;
vector<pair<pair<int,int>, string>> queries;
string getAns(ll x, ll y){
    string ans;
#if DEBUG
 

    if(abs(x) > 1000000000 || abs(y) > 1000000000 || qRem < 0){
        cout<<"WRONG\n";
        return "WRONG";
    }
    qRem--;
    if(x == centerXAssumed && y == centerYAssumed){
        cout<<"CENTER\n";
        return "CENTER";
    }
    ll D = (centerXAssumed -x)*(centerXAssumed -x) + (centerYAssumed - y)*(centerYAssumed - y);
    if(D> R*R) {
        return "MISS";
    }
    return "HIT";
    
#else
    cout<<x<<" "<<y;
    cout<<flush<<endl;
    cin>>ans;
    queries.push_back(make_pair(make_pair(x, y), ans));
    return ans;
#endif
}

double debtRemaining(double originalDebt,double interestRate,double monthlyPayment, int year){
    for(int i = 0; i < year; i++){
        originalDebt = originalDebt + originalDebt*interestRate/100.0 - 12.0 * monthlyPayment;
    }
    return originalDebt;
}
double debtRemaining2(double originalDebt,double interestRate,double monthlyPayment, int month){
    for(int i = 0; i < month; i++){
        originalDebt = (originalDebt + originalDebt*interestRate/1200.0) -  monthlyPayment;
    }
    return originalDebt;
}


int leafCount = 0;
int greaterCount[2010];
bool treePossible;
double values[2010];
vector<double> mergeVectors(vector<double> arr1, vector<double> arr2) {
    vector<double> result;
    int pos1 = 0;
    int pos2 = 0;
    while(pos1 < arr1.size() && pos2 < arr2.size()) {
        if(arr1[pos1] < arr2[pos2]) {
            result.push_back(arr1[pos1]);
            pos1++;
        }
        else {
            result.push_back(arr2[pos2]);
            pos2++;
        }
    }
    while(pos1 < arr1.size()) {
        result.push_back(arr1[pos1]);
        pos1++;
    }
    while(pos2 < arr2.size()) {
        result.push_back(arr2[pos2]);
        pos2++;
    }
    return result;
}

pair<ll,ll>getNumbersOfLCM(ll lcm){
    ll num1 = lcm;
    ll num2 = 1;
    ll sqrtLcm = 1 + sqrt(lcm+1);
    for(long i = 2;i < sqrtLcm; i++ ){
        if(lcm % i == 0){
            ll otherNum = lcm /i;
            if(gcd(i,otherNum) == 1){
                num1 = otherNum;
                num2 = i;
            }
        }
    }
    return make_pair(num2, num1);
}


void filterFile(){
    string line;
    ifstream myfile;
    ofstream myOutputFile;
    freopen ("//Users//nazmulhasnat//Projects//Algo//outputSmall.txt","w",stdout);
    myfile.open("//Users//nazmulhasnat//Projects//Algo//inputSmall.txt");
    while(getline(myfile,line)){
        size_t found = line.find("mirrormeister");
        if(found != string::npos){
            cout<<line<<endl;
        }
    }
}
string generateRandomString(int len){
    string s ="";
    for(long i = 0;i< len; i++){
        char ch = 'a' + rand()%2;
        s += ch;
    }
    while(rand()%2 == 0){
        s+= s[0];
    }
    return s;
}
string str;
int charMap[3][5];
bool isThereIrreducible(ll start, ll end){
    if(str[start-1] != str[end-1] || start == end){
        return true;
    }
    int countOfDifferentCharactersInTheRange = 0;
    for(long i = 0; i < 26; i++){
        int charCount = charMap[i][end] - charMap[i][start - 1];
        if(charCount > 0) {
            countOfDifferentCharactersInTheRange++;
            if(countOfDifferentCharactersInTheRange > 2){
                return true;
            }
        }
    }
    return false;
}
void buildCharMap(){
    memset(charMap, 0, sizeof(charMap));
    for(long i = 0; i < str.size(); i++ ){
        for(long j = 0; j < 26; j++) {
            charMap[j][i+1] = charMap[j][i];
            if(str[i] - 'a' == j)
                charMap[j][i+1]++;
        }
    }
}
int bitCount[64];
void addToBitCount(int num){
    long pos = 0;
    while(num > 0){
        if(num%2 == 1){
            bitCount[pos]++;
        }
        pos++;
        num /= 2;
    }
}

string description;
vector<ll> getShortesLis(){
    ll n = description.size() + 1;
    vector<ll>shortestLIS;
    vector<long>localMaximas;
    localMaximas.push_back(-1);
    for(long i = 0; i < description.size(); i++){
        if(description[i] == '>'){
            shortestLIS.push_back(n);
            int pos = i-1;
            n--;
            while(pos > -1 && shortestLIS[pos] == -1){
                shortestLIS[pos] = n;
                n--;
                pos--;
                
            }
        }
        else
            shortestLIS.push_back(-1);
    }
    shortestLIS.push_back(-1);
    long pos = description.size();
    while(pos > -1 && shortestLIS[pos] == -1) {
        shortestLIS[pos] = n;
        n--;
        pos--;
    }
    return shortestLIS;
}

vector<ll> getLongestLis(){
    ll n = 1;
    vector<ll>longestLIS;
    for(long i = 0; i < description.size(); i++){
        if(description[i] == '<'){
            longestLIS.push_back(n);
            int pos = i-1;
            n++;
            while(pos > -1 && longestLIS[pos] == -1){
                longestLIS[pos] = n;
                n++;
                pos--;
            }
        }
        else
            longestLIS.push_back(-1);
    }
    longestLIS.push_back(-1);
    long pos = description.size();
    while(pos > -1 && longestLIS[pos] == -1) {
        longestLIS[pos] = n;
        n++;
        pos--;
    }
    return longestLIS;
}


bool isPalindromeNum(long long num){
    vector<int>digits;
    while(num > 0){
        digits.push_back(num%10);
        num /= 10;
    }
    for(long i = 0; i < digits.size(); i++){
        if(digits[i] != digits[digits.size() - (i+1)]){
            return false;
        }
    }
    return true;
}

void codejam2022ProbB(ll testCase){
    ll total = 1000000;
    ll cMin = total;
    ll mMin = total;
    ll yMin = total;
    ll kMin = total;
    ll c,m,y,k;
    for(long i = 0; i < 3; i++){
        cin>>c>>m>>y>>k;
        if(c< cMin){
            cMin = c;
        }
        if(m<mMin){
            mMin = m;
        }
        if(y < yMin){
            yMin = y;
        }
        if(k < kMin){
            kMin = k;
        }
    }
    cout<<"Case #"<<testCase<<": ";
    if(kMin + yMin + mMin + cMin < total){
        cout <<"IMPOSSIBLE\n";
        return;
    }
    ll rem = total;
    c = min(cMin,rem);
    rem -= c;
    m = min(mMin,rem);
    rem -= m;
    y = min(yMin,rem);
    rem -= y;
    k = min(kMin,rem);
    cout<<c<<" "<<m<<" "<<y<<" "<<k<<endl;
    
}
ll dieSize[15];

void codejam2022ProbC(ll testCase){
    ll n;
    cin>>n;
    for(int i = 0; i < n; i++){
        scanf("%lld",&dieSize[i]);
    }
    cout<<"Case #"<<testCase<<": ";
    sort(dieSize,dieSize+n);
    ll minReq = 1;
    ll totalFound = 0;
    for(long i = 0; i < n; i++){
        if(dieSize[i] >= minReq){
            minReq++;
            totalFound++;
        }
    }
    cout<<totalFound<<endl;
    
}
vector<ll>pow2;
ll countOneInPos(ll num, int pos){ 

    ll ans = (num/pow2[pos+1])*pow2[pos];
    ll rem = num%pow2[pos+1];
    if(rem > pow2[pos]){
        ans+= (rem - pow2[pos]);
    }
    return ans;
}


vector<int>numberWithNOneCount(int N){
    vector<int>numbers;
    for(int i = 0; i < 256;i++){
        int oneCount = 0, temp = i;
        while(temp>0){
            oneCount += temp % 2;
            temp /=2;
        }
        if(oneCount == N){
            numbers.push_back(i);
        }
    }
    return numbers;
}
vector<vector<int>>numbersByOneCount;
void buildNumbersByOneCount(){
    for(int i = 0; i < 9; i++){
        numbersByOneCount.push_back(numberWithNOneCount(i));
    }
}

int curNumber;
int guessCount;
int makeGuess(int guess){
#if DEBUG
    cout<<" guess "<< guess<<endl;
    int r = rand()%8;
    int shiftVal = 1<<r;
    guess = guess / shiftVal + (guess % shiftVal) * (256/shiftVal);
    curNumber = curNumber^shiftVal;
    if(guessCount> 299 && curNumber != 0)
        return -1;
    int ans = 0, temp = curNumber;
    while (temp > 0) {
        ans += temp % 2;
        temp /= 2;
    }
    return ans;
#else
    cout<<guess;
    cout<<flush<<endl;
    int bitCount;
    cin>> bitCount;
    return bitCount;
#endif
    
    
    
}

int getOneCount(int num){
    int oneCount = 0;
    while(num> 0){
        oneCount += num % 2;
        oneCount /= 2;
    }
    return oneCount;
}

ll getD2(ll C, ll K){
    ll lim = (abs(C)+abs(K))*(abs(C)+abs(K))+10000;
    for(ll D2 = 0; D2 < lim;D2++){
        ll up1 = C - K*D2,up2 = C + K*D2;
        ll down = K+D2;
        if(up1 % down == 0)
            cout<<D2<<endl;
        else if(up2 % down == 0)
            cout<<D2*-1<<endl;
    }
    return -1;
}
string s;
string selection;
ll stringLen;
vector<ll>selectionCount;
void alterString(ll pos,ll selectionRemain, ll totalMove){
    if(selectionRemain == 0){
        for(ll i = pos; i <stringLen;i++){
            selectionCount.push_back(0);
            if(totalMove % 2 == 1)
                s[i] = (s[i] == '0')?'1':'0';
        }
        selectionCount[stringLen - 1] = selectionRemain;
        return;
    }
    if(pos + 1 == stringLen){
        if((totalMove - selectionRemain) % 2 == 1){
            s[pos] = (s[pos] == '0')?'1':'0';
        }
        selectionCount.push_back(selectionRemain);
        return;
    }
    if(totalMove % 2 == s[pos] % 2){
        selectionRemain--;
        selectionCount.push_back(1);
    }
    else{
        selectionCount.push_back(0);
    }
    s[pos] = '1';
    alterString(pos+1, selectionRemain, totalMove);
}

ll totalNum[25];
ll maxPoweredNum = 1;
ll getPowCount(ll num){
    ll powCount = 0;
    while (num > 0) {
        num /=2;
        powCount++;
    }
    return powCount;
}







































map<ll,int>inArray;
ll minNum = (ll)1000000000;
bool isInPath(ll num){
    if(num < minNum)
        return false;
    if(inArray[num] == 1)
        return true;
    if(num % 2 == 1)
        return isInPath(num/2);
    if(num % 4 == 0)
        return isInPath(num/4);
    return false;
}
int maxSumOfPartition[5];

int maxPosWithValueGreaterThan(ll val,int pos){
    if(pos > N)
        return -1;
    ll maxPos = -1;
    ll nextPos = getMaxValPosFromSegTree(1, pos, N, 0, N);
    if(segTreeData[nextPos] <= val)
        return -1;
    maxPos = nextPos;
    nextPos = maxPosWithValueGreaterThan(val,nextPos+1);
    if(nextPos >  maxPos)
        return nextPos;
    return maxPos;
    
}
int getMaxSumOfPartition(int pos){
    if(maxSumOfPartition[pos] > N){
        if(pos >= N){
            maxSumOfPartition[pos] = 0;
        }
        else if(pos + 1 == N){
            if(nums[pos] > 0)
                maxSumOfPartition[pos] = 1;
            else if(nums[pos] < 0)
                maxSumOfPartition[pos] = -1;
            else
                maxSumOfPartition[pos] = 0;
        }
        else if(segTreeData[pos] < segTreeData[N]){
            maxSumOfPartition[pos] = N - pos;
        }
        else {
            if(nums[pos] < 0){
                int val = getMaxSumOfPartition(pos + 1) - 1;
                ll minSum = segTreeData[pos];
                int nextPos = maxPosWithValueGreaterThan(minSum, pos+1);
                if(nextPos > pos){
                    int val2 = nextPos - pos + getMaxSumOfPartition(nextPos);
                    if(val2 > val)
                        val = val2;
                }
                maxSumOfPartition[pos] = val;
            }
            else{
                ll minSum = segTreeData[pos];
                int nextPos = maxPosWithValueGreaterThan(minSum, pos+1);
                int val = 0;
                if(nextPos > pos){
                    val = nextPos - pos + getMaxSumOfPartition(nextPos);
                }
                else{
                    val = getMaxSumOfPartition(pos + 1);
                }
                maxSumOfPartition[pos] = val;
            }
        }
    }
    return maxSumOfPartition[pos];
}
int reverseNum(int num){
    int revNum = 0;
    while(num){
        revNum = revNum * 10 + num % 10;
        num /= 10;
    }
    return revNum;
}
vector<ll>palindromes;
void buildPalindromeNumbers(){
    for(int i = 1; i < 10; i++){
        palindromes.push_back(i);
        palindromes.push_back(i * 11);
        for(int j = 0; j < 10; j++){
            palindromes.push_back(i * 101 + 10 * j);
            palindromes.push_back(i * 1001 + 110 * j);
            if(i < 4){
                for(int k = 0; k < 10; k++){
                    palindromes.push_back(i * 10001 + j*1010 + k * 100);
                }
            }
        }
    }
}
ll palindromebasis[4][5];
ll getPalindromeBasis(int num,int pos){
    if(palindromebasis[num][pos] == -1){
        if(palindromes[pos] == 1)
            palindromebasis[num][pos] = 1;
        else if(palindromes[pos] == 2){
            palindromebasis[num][pos] = 1 + num/2;
        }
        else{
            ll p = palindromes[pos];
            if(p > num)
                palindromebasis[num][pos] = getPalindromeBasis(num, pos+1);
            else
                palindromebasis[num][pos] = (getPalindromeBasis(num, pos+1) + getPalindromeBasis(num - p, pos)) % mdlo;
        }
    }
    return palindromebasis[num][pos];
}

ll getMaxTraiangle(ll lineNum){
    ll a = lineNum/3;
    if(lineNum % 3 == 0)
        return (ll)6 * a *a;
    if(lineNum % 3 == 1)
        return a*a*(ll)6 + (ll)4*a;
    

    

    

    return a*a*(ll)6 + a*(ll)8 +(ll)2;
}


ll childCount[300005];

void addEdge(ll node1, ll node2){
    graph[node1].push_back(node2);
    graph[node2].push_back(node1);
}

ll getChildCount(ll node){
    if(childCount[node] < 0){
        childCount[node] = 0;
        for(int i = 0; i < graph[node].size(); i++){
            if(parent[node] != graph[node][i]){
                parent[graph[node][i]] = node;
                childCount[node]++;
                childCount[node] += getChildCount(graph[node][i]);
            }
        }
    }
    return childCount[node];
}

ll getSaveCount(ll node){
    ll childCount1 = -1, childCount2 = -1;
    ll saveCount1 = -1, saveCount2 = -1;
    for(long i = 0; i < graph[node].size();i++){
        if(parent[node] != graph[node][i]){
            if(childCount1 == -1){
                childCount1 = getChildCount(graph[node][i]);
                saveCount1 = getSaveCount(graph[node][i]);
            }
            else{
                childCount2 = getChildCount(graph[node][i]);
                saveCount2 = getSaveCount(graph[node][i]);
            }
        }
    }
    if(childCount1 == -1)
        return 0;
    if(childCount2 == -1)
        return childCount1;
    ll maxSave = max(childCount1 + saveCount2 , childCount2 + saveCount1);
    return maxSave;
}
ll testDifficuilty[200005];
ll minIqRequired[200005];
ll getMinIQRequired(int pos){
    if(minIqRequired[pos] == -1){
        if(pos + 2 > n){
            minIqRequired[pos] = 1;
        }
        else{
            minIqRequired[pos] = getMinIQRequired(pos + 1);
            if(testDifficuilty[pos] > minIqRequired[pos])
                minIqRequired[pos]++;
        }
    }
    return minIqRequired[pos];
}
string getAttendanceSequence(ll iq){
    string attendanceSequence = "";
    for(int i = 0;i < n; i++){
        if(getMinIQRequired(i) <= iq){
            for(int j = i; j < n;j++){
                attendanceSequence += "1";
            }
            return attendanceSequence;
        }
        if(testDifficuilty[i] <= iq){
            attendanceSequence += "1";
        }
        else{
            attendanceSequence += "0";
        }
    }
    return attendanceSequence;
}
ll lcms[10000];
void buildLcms(ll maxVal){
    lcms[0] = 2;
    ll lastLcm = 2;
    ll pos = 1;
    while(lastLcm < maxVal){
        ll newLcm = lcm(lastLcm, pos+2);
        if(newLcm < lastLcm)
            break;
        else{
            lcms[pos] = newLcm;
            lastLcm = newLcm;
            pos++;
        

        }
    }
    
}

bool printPerm(long n){
    ll Pos[100000];
    memset(Pos, -1, sizeof(Pos));
    ll maxPos = n-1;
    for(ll i = n-1; i>-1; i--){
        ll maxVal = i+maxPos;
        ll maxSqr = sqrt(maxVal);
        ll curPos = (maxSqr * maxSqr)  - i;
        while(curPos >= 0 && Pos[curPos] != -1){
            maxSqr--;
            curPos = (maxSqr * maxSqr)  - i;
        }
        if(curPos>= 0){
            Pos[curPos] = i;
            while(maxPos >= 0 && Pos[maxPos] != -1)
                maxPos--;
        }
        else{
            cout<<"-1\n";
            return false;
        }
    }
    for(int i = 0; i < n;i++){
        cout<<Pos[i]<<" ";
    }
    cout<<endl;
    return true;
    
}
int matrix[505][505];
int row,col;
bool hasNeighbouringZero(int x, int y){
    for(int i = -1; i < 1; i++){
        for(int j = -1; j < 2; j++){
            int newX = x + i;
            int newY = y + j;
            if(newX >= 0 && newY >= 0 && newX < row && newY < col && matrix[newX][newY] == 0 &&(newX != x || newY != y))
                return true;
        }
    }
    return false;
}
void balsal(){
    double cur = 600, total = 0, target = 1000000000;
    int m = 1;
    while(target > total){
        total += cur;
        cout<<m<<" "<<cur<<" "<<total<<endl;
        cur += (cur*2.0)/9.0;
        m++;
    }
    
}
ll totalSum = 0,curSum = 0;
ll changeSum(ll pos, ll val){
    if(nums[pos] == val)
        return 0;
    bool startBlock = false, endBlock = false, newBlock, midBlock;
    if(pos == 1 )
        startBlock = true;
    else if(nums[pos-1] != nums[pos])
        startBlock = true;
    if(pos == n)
        endBlock = true;
    else if(nums[pos+1] != nums[pos])
        endBlock = true;
    newBlock = startBlock && endBlock;
    midBlock = (!startBlock) && (!endBlock);
    nums[pos] = val;
    if(midBlock){
        return (n-1) + ((pos-1) * (n-pos)*2);
    }
    bool matchesPrev = ((pos >1) && (nums[pos-1] == val));
    bool matchesNext = ((pos < n) && (nums[pos+1] == val));
    ll changeSum = 0;
    if(newBlock){
        if(matchesNext ){
            changeSum -= (pos*(n-pos));
        }
        if(matchesPrev){
            changeSum -= (pos-1)*(n-pos+1);
        }
        return changeSum;
    }
    if(startBlock){
        if(matchesPrev){
            changeSum = n-pos;
            changeSum -= pos-1;
        }
        else{
            changeSum += (pos-1) *(n-pos) ;
            changeSum += (n-pos);
            

        }
    }
    if(endBlock){
        if(matchesNext){
            changeSum = pos-1;
            changeSum -= (n-pos);
        }
        else{
            changeSum += (pos-1) *(n-pos) ;
           

            changeSum += pos-1;
            
        }
    }
    return changeSum;
}
ll minArray[100005];
void buildArray(ll pos,ll val){
    if(minArray[pos] != -1)
        return;
    minArray[pos] = val;
    for(int i = 0; i < weightedGraph[pos].size();i++){
        ll nextPos = weightedGraph[pos][i].first;
        ll nextVal = (weightedGraph[pos][i].second) | val;
        buildArray(nextPos,nextVal);
    }
}
void buildArray(){
    memset(minArray, -1, sizeof(minArray));
    for(int i = 0; i < n; i++){
        if(minArray[i] == -1){
            buildArray(i,0);
        }
    }
}


int main(int argc, const char * argv[]) {
    

    ll test_cases = 1;
    

    

    

    curNumber = rand() % 256;
    ll lim = 1000000;
    

    
    for(long T = 0; T < test_cases; T++){
        cin>>n>>m;
        ll curNum = -1;
        for(ll i = 1; i <= n; i++){
            scanf("%lld",&nums[i]);
            if(nums[i] == curNum){
                curSum += 1;
            }
            else{
                curSum += i;
            }
            totalSum += curSum;
            curNum = nums[i];
        }
        ll pos,val;
        for(int i = 0; i < m; i++){
            scanf("%lld%lld",&pos,&val);






            totalSum += changeSum(pos, val);


                printf("%lld\n",totalSum);
        }
        
    }
    return 0;
}

