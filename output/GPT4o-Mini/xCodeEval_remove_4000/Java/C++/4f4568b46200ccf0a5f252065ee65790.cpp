#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <gmpxx.h>

using namespace std;

class MyScanner {
    ifstream inFile;
    string line;
    stringstream ss;

public:
    MyScanner(const string &file) {
        inFile.open(file);
        if (!inFile) {
            cerr << "File not found!" << endl;
            exit(42);
        }
    }

    MyScanner() {
        // Use standard input
    }

    string nextToken() {
        if (!(ss >> line)) {
            getline(cin, line);
            ss.clear();
            ss.str(line);
        }
        return line;
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

