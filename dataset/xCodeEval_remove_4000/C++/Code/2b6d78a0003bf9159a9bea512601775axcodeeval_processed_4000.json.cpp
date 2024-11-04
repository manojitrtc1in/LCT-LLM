
























using namespace std;


typedef long long ll;
typedef unsigned long long ull;
vector<ll> primes;
long long mInv[10000];
typedef vector<long> adjList;
typedef set<long> id0;
id0 allDivisors[100005];
long long id3(long long n){
    if(n==1)
        return 1;
    if(n < 10000 && mInv[n]>0)
        return mInv[n];
    long long m=(-1*mdlo)/n;
    m+=mdlo;
    m*=id3(mdlo%n);
    if(n < 10000)
        mInv[n]=(m%mdlo);
    else
        return m%mdlo;
    return mInv[n];
}
id0 id23(long num) {
    if(allDivisors[num].empty()) {
        id0 divs;
        divs.insert(1);
        long lim = 1 + sqrt(num);
        for (long i = 0; primes[i] < lim; i++) {
            if(num % primes[i] == 0) {
                id0 sub = id23(num/primes[i]);
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
vector<ll> id11(ll lim) {
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

vector<ll> id23(ll num) {
    ll lim = 1 + sqrt(num);
    if(primes.empty())
        id11(max((ll)1000006,lim));
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
    vector<ll> id0 ;
    id0.push_back(1);
    for(long i = 0; i < components.size(); i++) {
        long curLen = id0.size();
        ll powVal = 1;
        for(long j = 0; j <components[i].second; j++) {
            powVal *= components[i].first;
            for(long k = 0; k < curLen; k++){
                id0.push_back(id0[k]*powVal);
            }
        }
    }
    return id0;
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
        queue<node*> id24;
        id24.push(this);
        while(id24.empty() == false){
            node *front = id24.front();
            id24.pop();
            for(long i = 0; i < childNum; i++) {
                id24.push(childs[i]);
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
long id2(long nodePos) {
    long childCount = graph[nodePos].size();
    if(childCount == 0){
        leaveCount++;
        return 1;
    }
    if(minORMax[nodePos] == 1) {
        long maxPos = 300005;
        for(long i = 0; i < childCount; i++){
            long pos = id2(graph[nodePos][i]);
            if(pos < maxPos)
                maxPos =pos;
        }
        return maxPos;
    }
    long pos = 0;
    for(long i = 0; i < childCount; i++) {
        pos += id2(graph[nodePos][i]);
    }
    return pos;
}
long respectCount[100005];
long id12(vector<long long> inc, vector<long long> dec) {
    long maxDir = 0;
    sort(inc.begin(),inc.end());
    sort(dec.begin(), dec.end());
    
    long currentPeople = dec.size();
    long id16 = inc.size();
    if(id16 == 0)
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
    if(id16 > currentPeople)
        return inc[inc.size()-1]+1;
    return optimalPos;
}
long charles[110];
long dan[110];
bool isFair(long L, long R, long K) {
    long id7 = -1;
    long danMax = -1;
    for(long i = L; i <= R; i++) {
        if(charles[i] > id7)
            id7 = charles[i];
        if(dan[i] > danMax)
            danMax = dan[i];
    }
    long dif = abs(id7 - danMax);
    if(dif<=K)
        return true;
    return false;
}
long visited[100005];
long id21(long node){
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
long id15[300];
long A;
map<char,char> winner;
char getMove(long pos) {
    map<char,long> moveMap;
    vector<char>curMoves;
    for(long i = 0; i < A; i++) {
        if(id15[i] == 0 ) {
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
void id6(char ch, long pos) {
    for(long i = 0; i < A; i++) {
        if(id15[i] == 0) {
            long id20 = pos % moves[i].size();
            if(winner[moves[i][id20]] == ch)
                id15[i] = 1;
        }
    }
}
string id17(){
    string moveSeq = "";
    memset(id15, 0, sizeof(id15));
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
        id6(nextMove, i);
    }
    return  "IMPOSSIBLE";
}
typedef vector<long>mOrder;
string id13(long num) {
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
        
        testString += id13(poses[pos]);
        sum -= poses[pos];
        

        for(long j = pos; j < 119; j++)
            poses[j] = poses[j+1];
    }
    return sum;
}
char getResponse(long pos) {

    return testString[pos - 1];

    cout<<pos;
    cout<<flush<<endl;
    char ch;
    cin>>ch;
    return ch;

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
vector<mOrder> id8(){
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
bool find(mOrder M, vector<mOrder> mo) {
    for(long i = 0; i < mo.size(); i++){
        if(sameOrder(mo[i], M))
            return true;
    }
    return false;
}
void id9(int n) {
    for(long i = 1; i <= n; i++) {
        if(i%15 == 0)
            cout<<"FizzBuzz";
        else if(i % 5 == 0)
            cout<<"Buzz";
        else if (i % 3 == 0)
            cout<<"Fizz";
        else
            cout<<i;
        cout<<endl;
        
    }
}
string id19(string s){
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
char id10(vector<vector<int>> keyTimes) {
    map <long,int> maxTime;
    char id4 = 'a';
    for(long i = 0; i < keyTimes.size(); i++) {
        char currentChar = 'a' + keyTimes[i][0];
        int time = keyTimes[i][1];
        if (i > 0)
            time -= keyTimes[i-1][1];
        if(time > maxTime[currentChar])
            maxTime[currentChar] = time;
        if(time > maxTime[id4])
            id4 = currentChar;
    }
    return id4;
}
int minimumCost(vector<int>d, int p) {
    long low = 1, high = 1000000000,mid;
    while(low < high) {
        mid = (low+high)/2;
        long sum = 0;
        for(long i = 0; i < d.size(); i++) {
            sum+= (d[i] + mid - 1)/mid;
        }
        if(sum>p)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}


double id14(string s) {
    double val  = 0;
    for(long i = 0; i < s.size(); i++){
        val = val * 10 + (s[i] - '0');
    }
    return val;
}

map<string,long>dpMap;
string id1(string s, long pos){
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
    
    string minMoved = id1(s, minPos);
    if(isSortable(minMoved)){
        dpMap[s] = 1;
        return true;
    }
    string maxMoved = id1(s, 1-minPos);
    if(isSortable(maxMoved)){
        dpMap[s] = 1;
        return true;
    }
    return false;
    
}
vector<ll> id18(ll num){
    vector<ll>id22;
    long pos = 0;
    while(primes[pos] * primes[pos] <= num){
        if(num%primes[pos] == 0){
            id22.push_back(primes[pos]);
            while(num%primes[pos] == 0)
                num/=primes[pos];
        }
        pos++;
    }
    if(num > 1)
        id22.push_back(num);
    return id22;
}

int main(int argc, const char * argv[]) {
    

    ll test_cases = 1;
    

    

    

    

    

    

    long long n,num,temp;
    long long x[1010];
    long long y[1010];
    map<long long,long>lines;
    map<long long,long long>slopes;
    long long lineCount = 0;
    long long id5 = 0;
    long long crossCount = 0;
    for(long T = 0; T < test_cases; T++) {
        cin>>n;
        for(long i = 0; i < n ; i++) {
            cin>>x[i]>>y[i];
            for(long j = 0; j < i; j++){
                long long a = y[i] - y[j];
                long long b = x[j] - x[i];
                long long g = gcd(a,b);
                a /= g;
                b /= g;
                long long c = a*x[i] + b*y[i];
                long long slope = a*(ll)41111 + b;
                ll line = (ll)2000000011 * slope + c;
                if(lines[line] < 1){
                    crossCount += (lineCount - slopes[slope]);
                    lines[line] = 1;
                    lineCount++;
                    if(slopes[slope] < 1)
                        slopes[slope] = 1;
                    else
                        slopes[slope]++;
                }
            }
        }
        cout<<crossCount<<endl;
        

        

        
    }
    return 0;
}
