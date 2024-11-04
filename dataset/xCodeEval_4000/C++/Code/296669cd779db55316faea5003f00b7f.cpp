














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
using namespace std;
#define DEBUG 0
#define mdlo 1000000007
typedef long long ll;
typedef unsigned long long ull;
vector<ll> primes;
long long mInv[10000];
typedef vector<long> adjList;
typedef set<long> divisors;
divisors allDivisors[100005];
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

adjList graph[100005];
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
typedef pair<long, long> fraction;
ll gcd (ll a, ll b) {
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


typedef pair<long,long> fraction;
typedef set<fraction> result;
class Solution {
    map<long,long> dpOneWay;
    map<long,long> dpBothWay;
    long long pows[31];
    long base;
    long getOperator(long long target,bool bothWay ){
        if(target == base)
            return 0;
        if(bothWay) {
            if(dpBothWay[target] == 0){
                dpBothWay[target] = getOperator(target, false);
                long pos = 0;
                while(pows[pos]< target)
                    pos++;
                if(pows[pos] > target){
                    long long rem = pows[pos] - target;
                    
                    long otherWay = pos + getOperator(rem, rem<pows[pos-1]);
                    dpBothWay[target] = min(dpBothWay[target], otherWay);
                }
                
            }
            return dpBothWay[target];
        }
        if(dpOneWay[target] == 0) {
            if(target == 0)
                return 0;
            long pos = 0;
            while(pows[pos] < target) {
                pos++;
            }
            if(pows[pos] == target) {
                if(pos == 0)
                    dpOneWay[target] = 1;
                else
                    dpOneWay[target] = pos - 1;
            }
            else {
                pos--;
                if(pos == 0)
                    dpOneWay[target] = 2 * target - 1;
                else {
                    dpOneWay[target] = pos + getOperator(target - pows[pos], true);
                }
            }
        }
        return dpOneWay[target];
    }
public:
    int leastOpsExpressTarget(int x, int target) {
        base = x;
        pows[0] = 1;
        long pos = 0;
        while(pows[pos] <= target) {
            pows[pos + 1] = base * pows[pos];
            pos++;
        }
        return getOperator(target, true);
    }
};
short minORMax[300005];
long parent[300005];
long root = 1;
long leaveCount;
long getMaxPos(long nodePos) {
    long childCount = graph[nodePos].size();
    if(childCount == 0){
        leaveCount++;
        return 1;
    }
    if(minORMax[nodePos] == 1) {
        long maxPos = 300005;
        for(long i = 0; i < childCount; i++){
            long pos = getMaxPos(graph[nodePos][i]);
            if(pos < maxPos)
                maxPos =pos;
        }
        return maxPos;
    }
    long pos = 0;
    for(long i = 0; i < childCount; i++) {
        pos += getMaxPos(graph[nodePos][i]);
    }
    return pos;
}
long respectCount[100005];
long getOptimalPos(vector<long long> inc, vector<long long> dec) {
    long maxDir = 0;
    sort(inc.begin(),inc.end());
    sort(dec.begin(), dec.end());
    
    long currentPeople = dec.size();
    long incPeopele = inc.size();
    if(incPeopele == 0)
        return 0;
    if(currentPeople == 0)
        return inc[inc.size()-1]+1;
    
    long incPos = 0;
    long optimalPos = 0;
    
    for(long i = 0; i < dec.size(); i++){
        long pos = dec[i] - 1;
        while(incPos < inc.size() && inc[incPos] < pos) {
            if(1+incPos + dec.size() - i > currentPeople){
                currentPeople =1+ incPos + dec.size() - i;
                optimalPos = inc[incPos]+1;
            }
            incPos++;
        }
        if(incPos > 0)
            incPos--;
        
    }
    if(incPeopele > currentPeople)
        return inc[inc.size()-1]+1;
    return optimalPos;
}
long charles[110];
long dan[110];
bool isFair(long L, long R, long K) {
    long charlMax = -1;
    long danMax = -1;
    for(long i = L; i <= R; i++) {
        if(charles[i] > charlMax)
            charlMax = charles[i];
        if(dan[i] > danMax)
            danMax = dan[i];
    }
    long dif = abs(charlMax - danMax);
    if(dif<=K)
        return true;
    return false;
}
long visited[100005];
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
fraction fractions[100005];












string moves[300];
long defeated[300];
long A;
map<char,char> winner;
char getMove(long pos) {
    map<char,long> moveMap;
    vector<char>curMoves;
    for(long i = 0; i < A; i++) {
        if(defeated[i] == 0 ) {
            long movePos = pos % moves[i].size();
            if(moveMap[moves[i][movePos]] != 1) {
                moveMap[moves[i][movePos]] = 1;
                curMoves.push_back(moves[i][movePos]);
            }
        }
    }
    if(curMoves.size() == 0)
        return 1;
    if(curMoves.size() == 3)
        return 0;
    if(curMoves.size() == 1)
        return winner[curMoves[0]];
    if(winner[curMoves[0]] == curMoves[1])
        return curMoves[1];
    return curMoves[0];
    
}
void markDefeated(char ch, long pos) {
    for(long i = 0; i < A; i++) {
        if(defeated[i] == 0) {
            long movepos = pos % moves[i].size();
            if(winner[moves[i][movepos]] == ch)
                defeated[i] = 1;
        }
    }
}
string getMoveSeq(){
    string moveSeq = "";
    memset(defeated, 0, sizeof(defeated));
    winner['R'] = 'P';
    winner['P'] = 'S';
    winner['S'] = 'R';
    for(long i = 0; i < 500; i++) {
        char nextMove = getMove(i);
        if(nextMove == 0){
            return "IMPOSSIBLE";
        }
        if(nextMove == 1) {
            return moveSeq;
        }
        moveSeq += nextMove;
        markDefeated(nextMove, i);
    }
    return  "IMPOSSIBLE";
}
typedef vector<long>mOrder;
string getCorrespondingString(long num) {
    vector<long > poses;
    poses.push_back(num/24);
    num = num%24;
    poses.push_back(num/6);
    num= num % 6;
    poses.push_back(num/2);
    num = num % 2;
    poses.push_back(num);
    poses.push_back(0);
    vector<char> chars;
    for(char ch = 'A' ; ch < 'F'; ch++)
        chars.push_back(ch);
    string str = "";
    for(long i = 0; i < 5; i++) {
        str += chars[poses[i]];
        for (long j = poses[i]; j < 5; j++) {
            chars[j] = chars[j+1];
        }
    }
    return str;
}
string testString;
long buildStrings(){
    testString = "";
    vector<long> poses;
    for(long i = 0; i < 120; i++)
        poses.push_back(i);
    poses.push_back(-1);
    long sum = 7140;
    for(long i = 0; i < 119; i++) {
        long pos = rand() % (120 - i);
        
        testString += getCorrespondingString(poses[pos]);
        sum -= poses[pos];
        

        for(long j = pos; j < 119; j++)
            poses[j] = poses[j+1];
    }
    return sum;
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
    return testString[pos - 1];
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
ll codium[330];
ll jar[330];
long N;
bool sameOrder(mOrder A, mOrder B){
    if(A.size() != B.size())
        return false;
    for(long i = 0; i < A.size(); i++){
        if(A[i]!=B[i])
            return false;
    }
    return true;
}
vector<mOrder> getAllOrder(){
    vector<mOrder> allOrder;
    for(long i = 1; i < 200; i++) {
        for(long j = 1; j < 200; j++) {
            vector<pair<ll,ll>>weightedOrder;
            for(long k = 0; k < N; k++) {
                ll w = i*codium[k] + j*jar[k];
                weightedOrder.push_back(make_pair(w, codium[k]));
            }
            sort(weightedOrder.begin(),weightedOrder.end());
            mOrder M;
            bool match = true;
            for(long k = 0 ; k < N; k++) {
                M.push_back(weightedOrder[k].second);
                if(weightedOrder[k].second != k)
                    match = false;
            }
            if(match){
                cout<<i<<" "<<j;
            }
            long unique = true;
            for(long k = 0; k < allOrder.size(); k++){
                if(sameOrder(M, allOrder[k])){
                    unique = false;
                    break;
                }
            }
            if(unique)
                allOrder.push_back(M);
        }
    }
    return allOrder;
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
ll getWeight(long i, ll C, ll J) {
    ll weight = codium[i] * C + jar[i]* J;
    return weight;
    
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

map<string,long>dpMap;
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
bool isSortable(string s){
    if(dpMap[s] == 1)
        return true;
    if(dpMap[s] == -1)
        return false;
    dpMap[s] =isSorted(s)? 1:-1;
    
    long minPos = s[0]< s[1]? 0:1;
    
    string minMoved = moveToLast(s, minPos);
    if(isSortable(minMoved)){
        dpMap[s] = 1;
        return true;
    }
    string maxMoved = moveToLast(s, 1-minPos);
    if(isSortable(maxMoved)){
        dpMap[s] = 1;
        return true;
    }
    return false;
    
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
long triplets[100005][3];
long tripletContained[100005][3];
long tripletCounter[100005];
long getFirstPos(long n){
    for(long i = 1; i < n; i++){
        if(tripletCounter[i] == 1)
            return i;
    }
    return -1;
}
bool containsPos(long tripletId, long pos) {
    if(tripletId == 0)
        return false;
    for(long i = 0; i < 3; i++){
        if(triplets[tripletId][i] == pos){
            return true;
        }
    }
    return false;
}
bool isNext(long tripletId, long a, long b, long c){
    if(containsPos(tripletId, a))
        return false;
    if(!containsPos(tripletId, b))
        return false;
    return containsPos(tripletId, c);
}
long nextTriplet(long a, long b, long c){
    long candidates[3];
    candidates[0] = tripletContained[b][0];
    candidates[1] = tripletContained[b][1];
    candidates[2] = tripletContained[b][2];
    for(long i = 0; i < 3; i++){
        if(isNext(tripletContained[b][i], a, b, c)){
            return tripletContained[b][i];
        }
    }
    return 0;
}
typedef vector<ll> sum;
vector<sum> sums;
ll n,m;
ll x[2005];
ll y[2005];
ll c[2005];
ll k;
long connector[2005];
long long getColors(long long num){
    for(long long i = 2; i*i <= num; i++) {
        if(num % i == 0) {
            while(num % i == 0) {
                num /= i;
            }
            if(num > 1) {
                return 1;
            }
            return i;
        }
    }
    return num;
}
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
map<ll,ll>aCount;
map<ll,ll>bCount;
map<ll,ll>used;
ll a[2020], b[2020];
bool feasibleX(ll x) {
    for(long i = 0; i < n; i++){
        ll nextVal = (a[i] + x) % m;
        if(aCount[a[i]] != bCount[nextVal])
            return false;
    }
    return true;
}
typedef pair<ll,ll> problem;
problem problems[200005];
string genString(long len, long val){
    string s;
    while(val > 0) {
        if(val%2==0)
            s += 'a';
        else
            s += 'b';
        val/=2;
    }
    for(long i = s.size(); i < len;i++)
        s+='a';
    return s;
}
ll firstOccurence[100005];
ll lastOccurence[100005];
int main(int argc, const char * argv[]) {
    

    ll test_cases = 1;
    
    

    

    

    

    


    

    for(long T = 0; T < test_cases; T++) {
        cin>>n>>k;
        memset(firstOccurence, -1, sizeof(firstOccurence));
        memset(lastOccurence, -1, sizeof(lastOccurence));
        ll guess;
        ll combo = 3*n - 2;
        for (int i = 0; i < k; i++) {
            scanf("%lld",&guess);
            if(firstOccurence[guess] == -1) {
                firstOccurence[guess] = i;
            }
            lastOccurence[guess] = i;
        }
        for(long i = 1; i <= n; i++) {
            if(firstOccurence[i] != -1) {
                combo--;
                if(i > 0 && lastOccurence[i-1] > firstOccurence[i]) {
                    combo--;
                }
                if(i < n && lastOccurence[i+1] > firstOccurence[i]) {
                    combo--;
                }
            }
        }
        cout<<combo<<endl;
    }
    return 0;
}
