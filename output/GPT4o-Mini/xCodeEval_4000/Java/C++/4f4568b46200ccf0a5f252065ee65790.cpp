#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <stdexcept>
#include <gmpxx.h>

using namespace std;

class MyScanner {
    ifstream br;
    string line;
    stringstream st;

public:
    MyScanner(const string& file) {
        br.open(file);
        if (!br.is_open()) {
            cerr << "File not found" << endl;
            exit(42);
        }
    }

    MyScanner() {
        br.open("/dev/stdin");
    }

    string nextToken() {
        while (st.eof() || !st.good()) {
            getline(br, line);
            st.clear();
            st.str(line);
        }
        string token;
        st >> token;
        return token;
    }

    int nextInt() {
        return stoi(nextToken());
    }

    double nextDouble() {
        return stod(nextToken());
    }
};

class C {
    MyScanner in;
    ofstream out;

    const int shift = 100000;
    const int maxn = 300000000;

    const vector<int> prec = {
