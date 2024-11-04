















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
vector<ll> primes;
long long mInv[10000];
typedef vector<long> adjList;
typedef set<long> divisors;
divisors allDivisors[1005];
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

adjList graph[200005];
bool isPrime(ll n){
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
ll minSegTreeData[500505];
ll minSegTree[3000505];
void buildMinSegTree(int pos, int startPos, int endPos){
    if(startPos == endPos){
        minSegTree[pos] = startPos;
        return;
    }
    int midPos = ( startPos + endPos)/2;
    buildMinSegTree(pos*2, startPos, midPos);
    buildMinSegTree(pos*2 + 1, midPos +1, endPos);
    int pos1 = minSegTree[pos*2];
    int pos2 = pos1+ 1;
    minSegTree[pos] = (minSegTreeData[minSegTree[pos*2]] < minSegTreeData[minSegTree[pos*2+1]])?minSegTree[pos*2]:minSegTree[pos*2+1];
   

}

ll getMinValPosFromSegTree(int pos, int queryStart, int queryEnd, int rangeStart, int rangeEnd){
    if(queryEnd < rangeStart || queryStart > rangeEnd)
        return -1;
    if(rangeEnd <= queryEnd && rangeStart >= queryStart){
        return minSegTree[pos];
    }
    int midRange = (rangeEnd + rangeStart)/2;
    int firstHalf = getMinValPosFromSegTree(pos * 2, queryStart, queryEnd, rangeStart, midRange);
    int secHalf = getMinValPosFromSegTree(pos * 2 + 1, queryStart, queryEnd, midRange + 1, rangeEnd);
    if(firstHalf == -1)
        return secHalf;
    if(secHalf == -1)
        return firstHalf;
    if(minSegTreeData[firstHalf] <  minSegTreeData[secHalf])
        return firstHalf;
    return secHalf;
        
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
short minORMax[305];
long parent[200005];
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
long visited[200005];

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
typedef set<long> adjacencyList;
fraction fractions[105];













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
long pleasure[25];
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
void replaceEdges(long nodeFrom, long nodeTo) {
    for(set<long>::iterator it = undirectedGraph[nodeFrom].begin(); it != undirectedGraph[nodeFrom].end(); it++) {
        long nextNode = *it;
        undirectedGraph[nodeTo].insert(nextNode);
        undirectedGraph[nextNode].erase(nodeFrom);
        undirectedGraph[nextNode].insert(nodeTo);
    }
    undirectedGraph[nodeFrom].clear();
}
void replaceCycle(long olderNode, long newerNode){
    makeSameGroup(olderNode, newerNode);
    long curNode = newerNode;
    while(curNode != olderNode){
        makeSameGroup(olderNode, curNode);
        replaceEdges(curNode, olderNode);
        pleasure[olderNode] += pleasure[curNode];
        pleasure[curNode] = 0;
        curNode = parent[curNode];
    }
}
bool circleRemains;
void dfsUndirectedGraph(long node) {
    if(1 != visited[node]) {
        visited[node] = 1;
        groupId[node] = node;
        for(set<long>::iterator it = undirectedGraph[node].begin(); it != undirectedGraph[node].end(); it++) {
            long nextNode = *it;
            if(nextNode != parent[node]) {
                if(visited[nextNode]) {
                    circleRemains = true;
                    replaceCycle(nextNode, node);
                }
                else{
                    parent[nextNode] = node;
                    dfsUndirectedGraph(nextNode);
                }
            }
        }
    }
}

string getPath(ll x,ll y) {
   

    if(x == 0 && y == 0) {
        return "";
    }
    if(x == 0 && y == 1) {
        return "N";
    }
    if(y == 0 && x == 1) {
        return "E";
    }
    if(x % 2 == y % 2){
        return "IMPOSSIBLE";
    }
    if(x%2 == 1) {
        string moveEast = getPath((x-1)/2,y/2);
        string moveWest = getPath((x+1)/2, y/2);
        if(moveWest != "IMPOSSIBLE"){
            moveWest = "W" + moveWest;
        }
        if(moveEast != "IMPOSSIBLE") {
            moveEast = "E" + moveEast;
        }
        if(moveEast == "IMPOSSIBLE") {
            return moveWest;
        }
        if(moveWest == "IMPOSSIBLE") {
            return moveEast;
        }
        return moveWest.size()<moveEast.size()?moveWest:moveEast;
    }
    string moveNorth = getPath(x/2, (y-1)/2);
    string moveSouth = getPath(x/2,(y+1)/2);
    if(moveNorth != "IMPOSSIBLE") {
        moveNorth = "N" + moveNorth;
    }
    if(moveSouth != "IMPOSSIBLE") {
        moveSouth = "S" + moveSouth;
    }
    if(moveNorth == "IMPOSSIBLE") {
        return moveSouth;
    }
    if(moveSouth == "IMPOSSIBLE") {
        return moveNorth;
    }
    return moveNorth.size()<moveSouth.size()?moveNorth:moveSouth;
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
vector<string> chekCenter(ll x, ll y, ll R) {
    vector<string> answers;
    string ans;
    int dirX[] = {-1,0,1,0};
    int dirY[] = {0,1,0,-1};
    for(long i = 0; i < 4; i++){
        ans = getAns(x+dirX[i]*R, y+ dirY[i]*R);
        answers.push_back(ans);
        if(ans == "CENTER" || ans == "WRONG") {
            return answers;
        }
    }
    return answers;

}
const ll halfSide = 1000000000;
bool foundCenter;
bool hitInside;
bool invalidQuery;
pair<ll,ll> findHit(ll startX, ll slope ){
    ll x = startX;
    ll y = slope * x;
    while(startX < halfSide) {
        string status = getAns(x, y);
        if(status == "HIT"){
            hitInside = true;
            return make_pair(x, y);
        }
        if(status == "CENTER") {
            foundCenter = true;
            return make_pair(x, y);
        }
        if(status == "WRONG") {
            invalidQuery = true;
            return make_pair(x, y);
        }
        x+= halfSide/4;
        y = x * slope;
        
    }
    return make_pair(x, y);
}
pair<ll, ll> getCenter(pair<ll,ll> insidePoint) {
    ll x = insidePoint.first;
    ll y = insidePoint.second;
    ll xMax = halfSide;
    ll xMin = x;
    while(xMax > xMin){
        ll xMid = (xMin + xMax + 1)/2;
        string status = getAns(xMid, y);
        if(status == "CENTER"){
            foundCenter = true;
            return make_pair(xMid, y);
        }
        if(status == "HIT"){
            xMin = xMid;
        }
        else {
            xMax = xMid - 1;
        }
    }
    ll xUpperLimit = xMax;
    xMax = x;
    xMin = 0 - halfSide;
    while(xMin < xMax){
        ll xMid = (xMin + xMax - 1) / 2;
        string status = getAns(xMid, y);
        if(status == "CENTER"){
            foundCenter = true;
            return make_pair(xMid, y);
        }
        if(status == "HIT"){
            xMax = xMid;
        }
        else {
            xMin = xMid + 1;
        }
    }
    ll xLower = xMin;
    ll centerX = (xLower + xUpperLimit)/2;
    
    ll yMax = halfSide;
    ll yMin = y;
    while (yMax > yMin) {
        ll yMid = (yMax + yMin + 1)/2;
        string status = getAns(centerX, yMid);
        if(status == "CENTER"){
            foundCenter = true;
            return make_pair(centerX, yMid);
        }
        if(status == "HIT"){
            yMin = yMid;
        }
        else {
            yMax = yMid - 1;
        }
    }
    ll yUp = yMax;
    yMax = y;
    yMin = 0- halfSide;
    while (yMax > yMin) {
        
        ll yMid = (yMax + yMin - 1)/2;
        string status = getAns(centerX, yMid);
        if(status == "CENTER"){
            foundCenter = true;
            return make_pair(centerX, yMid);
        }
        if(status == "HIT"){
            yMax = yMid;
        }
        else {
            yMin = yMid + 1;
        }
    }
    ll yLow = yMin;
    ll centerY = (yLow + yUp)/2;
    return make_pair(centerX, centerY);
}
void printRatings(ll n){
    ll rootVal = sqrt(n);
    if((rootVal+1) * (rootVal+1) <=n){
        rootVal++;
    }
    ll differentRatingCount = rootVal+rootVal;
    if(n >= rootVal*(rootVal+1)){
        differentRatingCount++;
    }
    cout<<differentRatingCount<<endl;
    for(long i = 0; i <= rootVal; i++){
        cout<<i<<" ";
    }
    ll lastVal = rootVal;
    for(ll i = rootVal+1; i > 0; i--){
        ll curVal = n/i;
        if(curVal > lastVal){
            cout<< curVal<<" ";
            lastVal = curVal;
        }
    }
    cout<<endl;
}
ll stringId[30];
int garland[110];
int garlandLength;
ll minComplexity[105][55][55][2];
ll getMinComplexity(ll pos, ll oddLeft, ll evenLeft,ll prevOdd) {
    if(minComplexity[pos][oddLeft][evenLeft][prevOdd] == -1) {
        if(pos >= garlandLength){
            minComplexity[pos][oddLeft][evenLeft][prevOdd] = 0;
        }
        else if(garland[pos] != 0) {
            minComplexity[pos][oddLeft][evenLeft][prevOdd] = getMinComplexity(pos + 1, oddLeft, evenLeft, garland[pos] % 2);
            if(pos != 0 && prevOdd != garland[pos] % 2){
                minComplexity[pos][oddLeft][evenLeft][prevOdd]++;
            }
        }
        else if(oddLeft == 0) {
            minComplexity[pos][oddLeft][evenLeft][prevOdd] = ((pos > 0)?prevOdd:0) + getMinComplexity(pos+1, oddLeft, evenLeft - 1, 0);
        }
        else if(evenLeft == 0) {
            minComplexity[pos][oddLeft][evenLeft][prevOdd] = ((pos > 0)?1- prevOdd:0)  + getMinComplexity(pos + 1, oddLeft - 1, evenLeft, 1);
        }
        else {
            ll evenComplexity = ((pos > 0)?prevOdd:0) + getMinComplexity(pos + 1, oddLeft, evenLeft - 1, 0);
            ll oddComplexity = ((pos > 0)?1- prevOdd:0) + getMinComplexity(pos + 1, oddLeft - 1, evenLeft, 1);
            minComplexity[pos][oddLeft][evenLeft][prevOdd] = min(evenComplexity, oddComplexity);
        }
    }
   

    return minComplexity[pos][oddLeft][evenLeft][prevOdd];
}
adjList tree[2010];
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
vector<double> getValues(long node){
    adjList curList = tree[node];
    
    vector<double>childValues;
    vector<double>allValues;
    if(curList.size() == 0) {
        if(greaterCount[node] == 0) {
            double myValue = (2*leafCount + 1)*8001;
            allValues.push_back(myValue);
            values[node] = myValue;
        }
        else {
            treePossible = false;
        }
        leafCount++;
        return allValues;
    }
    for(long i = 0; i < curList.size(); i++) {
        childValues = getValues(curList[i]);
        allValues = mergeVectors(allValues, childValues);
    }
    if(greaterCount[node] > allValues.size() || allValues.size() == 0){
        treePossible = false;
        allValues.clear();
    }
    else {
        if(greaterCount[node] == allValues.size()){
            double myValue = allValues[allValues.size() - 1] + 9999;
            values[node] = myValue;
            allValues.push_back(myValue);
        }
        else {
            double myValue;
            if(greaterCount[node] == 0){
                myValue = allValues[0]/2;
            }
            else {
                myValue = (allValues[greaterCount[node]] + allValues[greaterCount[node] - 1]) /2;
            }
            allValues.insert(allValues.begin()+greaterCount[node], myValue);
            values[node] = myValue;
            
        }
    }
    return allValues;
    
}
int getMinTime(int X, int Y, string M){
    if(X == 0 && Y==0){
        return 0;
    }
    for(long i = 0; i < M.size(); i++) {
        if(M[i] == 'E'){
            X++;
        }
        else if(M[i] == 'W'){
            X--;
        }
        else if(M[i] == 'N'){
            Y++;
        }
        else {
            Y--;
        }
        int distance = abs(X) + abs(Y);
        if(distance <= i+1){
            return i+1;
        }
    }
    return -1;
}
int maxLimits[11];
int minLimits[11];
map<char,int>charId;
map<char,int>charValue;
map<char,set<int>>possibleValues;
int charCount = 0;
int U;
void processRandomNumber(int maxLimit, string s){
    for(long i = 0; i < s.size(); i++) {
        char ch = s[i];
        if(charId[ch] == -1) {
            charId[ch] = charCount;
            charCount++;
            if(i == 0) {
                minLimits[charId[ch]] = 1;
            }
            else {
                minLimits[charId[ch]] = 0;
            }
            maxLimits[charId[ch]] = 9;
        }
    }
    if(U == 2){
        int firstDigit= -1;
        int secondDigit = -1;
        if(maxLimit > 9){
            firstDigit =  maxLimit/10;
            secondDigit = maxLimit % 10;
        }
        else {
            firstDigit =  maxLimit;
        }
        if(s.size() == 1){
            if(maxLimit < 10){
                maxLimits[charId[s[0]]] = min( maxLimits[charId[s[0]]], maxLimit);
            }
        }
        else {
            int curMaxVal = firstDigit;
            if(minLimits[charId[s[1]]] > secondDigit){
                curMaxVal--;
            }
             maxLimits[charId[s[0]]] = min( maxLimits[charId[s[0]]], curMaxVal);
            
            
        }
    }
}

vector<ll> angles;
map<ll,ll>sliceCount;
ll minCut;
ll getMinCut(ll originalAngle, ll devider, ll D){
    ll totalSlic = 0;
    ll totalCut = 0;
    for(ll cut = 0; cut + totalCut < minCut; cut++){
        ll desiredSize = (originalAngle*(cut+1))/devider;
        if(desiredSize * devider == originalAngle * (cut+1)){
            ll newSlice = (sliceCount[desiredSize])*(cut+1);
            if(newSlice + totalSlic < D){
                totalSlic += newSlice;
                totalCut += sliceCount[desiredSize]*cut;
            }
            else {
                ll sliceNeeded =  D - totalSlic;
                while (sliceNeeded > cut ) {
                    sliceNeeded -= (cut + 1);
                    totalCut += cut;
                }
                totalCut+= sliceNeeded;
                return totalCut;
            }
        }
    }
    totalCut += D-totalSlic;
    if(totalCut>= minCut){
        return totalCut;
    }
    for(long i = angles.size()-1; i > -1 &&  angles[i] * devider >= originalAngle;i--){
        ll newSlice = angles[i]*devider/originalAngle;
        if(newSlice > minCut || newSlice* originalAngle != angles[i] * devider){
            totalSlic += newSlice;
            if(totalSlic >= D)
                return totalCut;
        }
    }
    return - 1;
}
ll getNumberOfSlices(ll originalAngle, ll devider, ll cutCount){
    ll countt = 0;
    ll desiredSize = originalAngle*(cutCount+1)/devider;
    if(desiredSize*devider != originalAngle*(cutCount+1))
        return 0;
    return sliceCount[desiredSize];
}
map<pair<ll,ll>,ll> considered;
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

ll getMinCuts(ll D){
    
    for(ll cut = 0; cut < minCut; cut++){
        for(ll i = 0; i < angles.size(); i++){
            if(i == 0 || angles[i] > angles[i-1]){
                ll totalSlice = 0;
                ll devider = cut + 1;
                ll cutCount = 0;
                ll g = gcd(angles[i], devider);
                ll a = angles[i]/g;
                devider/=g;
                if(considered[make_pair(a, devider)] != 1){
                    considered[make_pair(a, devider)] = 1;
                    ll curCut = getMinCut(angles[i], cut+1, D);
                    if(curCut <  minCut && curCut>=0){
                        minCut = curCut;
                    }
                }
            }
            






        }
    }
    return minCut;
}
int getMinCutSmall(int D) {
    if(D == 2){
        for(long i = 1; i < angles.size(); i++){
            if(angles[i] == angles[i-1]){
                return 0;
            }
        }
        return 1;
    }
    if(D == 3){
        bool hasTwosame = (angles[0] == angles[1]);
        for(long i = 2; i < angles.size(); i++){
            if(angles[i] == angles[i-2]){
                return 0;
            }
            if(angles[i] == angles[i-1]){
                hasTwosame = true;
            }
        }
        if(hasTwosame){
            return 1;
        }
        long pos = 1;
        for(long i = 0; i < angles.size(); i++ ){
            while(pos < angles.size() && angles[pos] < angles[i] + angles[i]){
                pos++;
            }
            if(pos < angles.size() && angles[pos] == angles[i] + angles[i]){
                return 1;
            }
        }
    }
    return D-1;
}
ll xorNums[100005];
ll firstOf2sPowers[40];
ll N;
ll findPos(ll startPos, ll endPos, ll val){
    if(xorNums[startPos] > val){
        return startPos;
    }
    if(xorNums[endPos] < val)
        return endPos + 1;
    while(startPos < endPos){
        ll midPos = (startPos + endPos )/2;
        if(xorNums[midPos] < val){
            startPos = midPos + 1;
        }
        else {
            endPos = midPos;
        }
    }
    return startPos;
}
ll getFirstPos(ll num){
    ll pos = 0;
    ll zeroPos = 0;
    while(num > 0){
        if(num % 2 == 0){
            zeroPos = pos;
        }
        pos++;
        num /= 2;
    }
    return zeroPos;
}
ll getMinXorVal(ll startPos, ll endPos) {
    ll pow2Val = 1;
    if(xorNums[endPos] == 0) {
        return 0;
    }
    if(xorNums[startPos] == xorNums[endPos]){
        return 0;
    }
    while(xorNums[endPos] > pow2Val){
        pow2Val *= 2;
    }
    while(xorNums[startPos] >= pow2Val || xorNums[endPos] < pow2Val) {
        if(xorNums[startPos] >= pow2Val){
            for(long i = startPos; i <= endPos; i++) {
                xorNums[i] -= pow2Val;
            }
        }
        pow2Val /= 2;
    }
    ll startPos2 = findPos(startPos, endPos, pow2Val);
    ll minVal1 = getMinXorVal(startPos, startPos2 - 1);
    ll minVal2 = getMinXorVal(startPos2, endPos);
    return pow2Val + min(minVal1, minVal2);
    
}
int cellStatus[2][100005]; 

set<int> blockedCells;
int isBlocked[100005];
int blockedCount;
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
int charMap[30][200005];
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
ll nums[100005];
vector<pair<ll,string>> trimDirections(vector<pair<ll,string>> untrimmedDirection){
    vector<pair<ll,string>> trimmedDirection;
    for(long i = 0; i < untrimmedDirection.size(); i++){
        if(untrimmedDirection[i].first > 0){
            if(trimmedDirection.size() > 0 && trimmedDirection[trimmedDirection.size() - 1].second == untrimmedDirection[i].second){
                trimmedDirection[trimmedDirection.size() - 1].first += untrimmedDirection[i].first;
            }
            else {
                trimmedDirection.push_back(untrimmedDirection[i]);
            }
        }
    }
    return trimmedDirection;
}
void printDirection(vector<pair<ll,string>> directions){
    
    cout<<directions.size()<<endl;
    for(int i = 0; i < directions.size(); i++){
        pair<ll,string> curDir = directions[i];
        cout<<curDir.first<<" "<<curDir.second<<endl;
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

string msg;
typedef vector<ll> charPositions;
ll charChounts[26];
charPositions allCharPositions[30];
ll maxCharCount;
ll getMsgOccurence(int char1, int char2){
    int pos = 0;
    ll occurence = 0;

    for(long i = 0; i < allCharPositions[char1].size(); i++){
        while(pos < allCharPositions[char2].size() && allCharPositions[char2][pos] < allCharPositions[char1][i]){
            pos++;
        }
        occurence += (allCharPositions[char2].size() - pos);
    }
    return occurence;
}
ll specialFields[200005];
ll distanceFromField1[200005];
ll distanceFromFeildN[200005];
vector<pair<ll,ll>>specialFieldsDistanceFromField1;
vector<pair<ll,ll>>specialFieldsDistanceFromFieldN;

bool isSpecial[200005];
void dfs(ll startNode){
    queue<ll> Q;
    Q.push(startNode);
    ll dist = 0;
    while(!Q.empty()){
        ll curField = Q.front();
        Q.pop();
        for(ll i  = 0; i < graph[curField].size(); i++){
            ll nextNode = graph[curField][i];
            if(startNode == 1 && distanceFromField1[nextNode] == -1){
                Q.push(nextNode);
                distanceFromField1[nextNode] =  1 + distanceFromField1[curField];
            }
            if(startNode == N && distanceFromFeildN[nextNode] == -1){
                Q.push(nextNode);
                distanceFromFeildN[nextNode] =  1 + distanceFromFeildN[curField];
            }
        }
    }
}
ll skyScrappers(int startPos, int endPos){
    if(startPos == endPos){
        return minSegTreeData[startPos];
    }
    if(startPos > endPos){
        return 0;
    }
    

    int minPos = getMinValPosFromSegTree(1, startPos, endPos, 0, N - 1);
    ll flattenFirstHalf = (1 + minPos - startPos) * minSegTreeData[minPos] + skyScrappers(minPos+ 1, endPos);
    ll flattenSecHalf = skyScrappers(startPos, minPos-1)+ (1 + endPos - minPos) * minSegTreeData[minPos];
    if(flattenFirstHalf > flattenSecHalf){
        for(long i = startPos; i < minPos; i++){
            minSegTreeData[i] = minSegTreeData[minPos];
        }
        return flattenFirstHalf;
    }
    for(long i = minPos + 1; i <= endPos; i++){
        minSegTreeData[i] = minSegTreeData[minPos];
    }
    return flattenSecHalf;
}
bool firstPlayerWins(ll n){
    
    if(n == 1){
        return false;
    }
    if(n == 2 || n%2 == 1 || n%4 == 0 || ! (isPrime(n/2))){
        if(n%4 == 0){
            while(n % 2 == 0){
                n /= 2;
            }
            return (n > 1);
        }
        return true;
    }
    return false;
    
}
vector<pair<ll,ll>> edges;
ll neighbourCount[100005];
pair<ll,ll> getPair(ll a, ll b){
    if(a < b || (a-b)%2 > 0)
        return make_pair(-1, -1);
    if(a == b){
        return make_pair(a, 0);
    }
    if(b == 0){
        return make_pair(a/2, a/2);
    }
    if(a%2 == 1){
        pair<ll,ll> elems = getPair(a/2, b/2);
        if(elems.first != -1){
            elems.first = 1 + (2*elems.first);
            elems.second = 2 * elems.second;
        }
        return elems;
    }
    pair<ll,ll> elems = getPair(a/2, b/2);
    if(elems.first == -1){
        elems = getPair(a/2 -1, b/2);
        if(elems.first != -1) {
            elems.first = 1 + 2 * elems.first;
            elems.second = 1 + 2 * elems.second;
        }
    }
    else {
        elems.first = 2 * elems.first;
        elems.second = 2 * elems.second;
    }
    return elems;
    
}
vector<ll> getArray(ll a, ll b){
    vector<ll> elems;
    if(a < b || (a-b)%2 == 1){
        elems.push_back(-1);
        return elems;
    }
    if(a == 0){
        return elems;
    }
    if(a == b){
        elems.push_back(a);
        return elems;
    }
    pair<ll,ll> doubleElem = getPair(a,b);
    if(doubleElem.first != -1){
        elems.push_back(doubleElem.first);
        elems.push_back(doubleElem.second);
    }
    else {
        elems.push_back(b);
        elems.push_back((a-b)/2);
        elems.push_back((a-b)/2);
    }
    return elems;
}
string originalString;
ll getChangeCountForPos(int pos, int interval){
    ll charCount[30];
    memset(charCount, 0, sizeof(charCount));
    for(long i = pos; i < originalString.size(); i+= interval){
        int j =  (i - pos)+ (interval - pos -1);
        charCount[originalString[i]-'a']++;
        charCount[originalString[j]-'a']++;
    }
    ll maxChar = charCount[0];
    
    for(long i = 1; i < 26; i++){
        if(charCount[i] > maxChar){
            maxChar = charCount[i];
        }
    }
    ll changeCar = 2*(originalString.size()/interval) - maxChar;
    if(pos + pos + 1 == interval){
        changeCar/=2;
    }
    return changeCar;
    
}
ll bobsDp[505][505];
ll bobsMatrix[505][505];
ll bobsAlgo(int n, int m){
    memset(bobsDp, 0, sizeof(bobsDp));
    bobsDp[0][1]= bobsMatrix[1][1];
    for(long i = 1 ; i <=n; i++){
        for(long j = 1; j <=n; j++){
            bobsDp[i][j] = max(bobsDp[i-1][j]&bobsMatrix[i][j] , bobsDp[i][j-1] & bobsMatrix[i][j]);
        }
    }
    return bobsDp[n][m];
}
ll  w[200005];
ll  a[2000005];
ll curPos;
ll getGreen(ll n){
    if(n <= curPos){
        return (a[n-1]*4)%mdlo;
    }
    for(long i = curPos; i < n; i++){
        a[i] = 2 * a[i-1];
        if(i % 6 == 2 || i % 6 == 4 ){
            a[i]++;
        }
        if(i%6==3){
            a[i]--;
        }
        a[i] %= mdlo;
    }
    curPos = n;
    return (a[n-1]*4)%mdlo ;
}
int main(int argc, const char * argv[]) {
    

    ll test_cases = 1,I;
       

    

    

    

    

    ll minR,maxR;
    cin>>test_cases;
    string s;
    a[0] = 0;
    curPos = 1;
    for(long T = 0; T < test_cases; T++){
        cin>>n;
        cout<< getGreen(n)<< endl;
    }
    return 0;
}

