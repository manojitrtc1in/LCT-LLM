
using namespace std;

string id3("!,!,!,!,%,
const int N = 1e5;
bool is_prime[N];
vector<int> primes;
string rofl_code("0okso thisislikeaNEWNUMBERSYSTEM.iAMtryingtoXYZASD;getmanyxyzzyzyzychracterinhere|)@
string id0(int x){

    string ans;
    while(x > 0){
        ans.push_back(rofl_code[x%rofl_code.size()]);
        x/=rofl_code.size();
    }
    reverse(ans.begin(),ans.end());
    if(ans.size() == 0)
        ans.push_back(rofl_code[0]);
    return ans;
}
int id2(string s){
    int ans = 0;
    for(int i = 0; i < s.size(); ++i){
        ans *= rofl_code.size();
        ans += lower_bound(rofl_code.begin(),rofl_code.end(),s[i])-rofl_code.begin();
    }
    return ans;
}
int main(){
    sort(rofl_code.begin(),rofl_code.end());
    rofl_code.erase(unique(rofl_code.begin(),rofl_code.end()),rofl_code.end());
    fill(is_prime+2,is_prime+N,true);
    for(int i = 2; i < N; ++i)
        if(is_prime[i]){
            for(int j = 2*i; j < N; j+=i)
                is_prime[j] = false;
            primes.push_back(i);
        }
    
    stringstream in(id3.c_str());
    vector<string> separated;
    string id1;
    while(getline(in,id1,','))
        separated.push_back(id1);
    int q;
    cin >> q;
    while(q--){
        int a;
        cin >> a;
        int pos = lower_bound(primes.begin(),primes.end(),a)-primes.begin();
        cout << id2(separated[pos]) << '\n';
    }
}
