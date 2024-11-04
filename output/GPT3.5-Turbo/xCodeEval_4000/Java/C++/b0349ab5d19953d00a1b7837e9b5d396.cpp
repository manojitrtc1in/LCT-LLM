#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

class ProblemC_76 {
    
    bool ONLINE_JUDGE;
    ifstream in;
    ofstream out;
    stringstream tok;
    
    void init(){
        if (ONLINE_JUDGE){
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
        }else{
            in.open("input.txt");
            out.open("output.txt");
        }
    }
    
    string readString(){
        string s;
        while(!tok.hasMoerTokens()){
            string line;
            if (ONLINE_JUDGE){
                getline(cin, line);
            }else{
                getline(in, line);
            }
            tok = stringstream(line);
        }
        tok >> s;
        return s;
    }
    
    int readInt(){
        int x;
        stringstream ss(readString());
        ss >> x;
        return x;
    }
    
    long long readLong(){
        long long x;
        stringstream ss(readString());
        ss >> x;
        return x;
    }
    
    double readDouble(){
        double x;
        stringstream ss(readString());
        ss >> x;
        return x;
    }
    
public:
    ProblemC_76(){
        ONLINE_JUDGE = (getenv("ONLINE_JUDGE") != NULL);
        init();
    }
    
    void run(){
        try{
            long long t1 = getCurrentTimeMillis();
            solve();
            long long t2 = getCurrentTimeMillis();
            cerr << "Time = " << (t2 - t1) << endl;
        }catch (exception& e){
            cerr << e.what() << endl;
            exit(-1);
        }
    }
    
    void solve(){
        int n = readInt() - 1;
        int m = readInt();
        int a = readInt() - 1;
        int b = readInt() - 1;
        int i = a / m;
        int j = b / m;
        int l = a % m;
        int r = b == n? m - 1: b % m;
        if (l == 0 && r == m - 1){
            out << 1;
            return;
        }
        if (j - i < 2){
            out << j - i + 1;
            return;
        }
        if (l != 0 && r == m - 1 || l == 0 && r != m - 1){
            out << 2;
            return;
        }
        if (l - r == 1){
            out << 2;
            return;
        }
        out << 3;
    }
    
    long long getCurrentTimeMillis(){
        return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
    }
};

int main(){
    ProblemC_76 problem;
    problem.run();
    return 0;
}
