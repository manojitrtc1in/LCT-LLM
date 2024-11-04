#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class IO {
public:
    static int readInt() {
        int num;
        cin >> num;
        return num;
    }

    static long long readLong() {
        long long num;
        cin >> num;
        return num;
    }

    static string readString() {
        string str;
        cin >> str;
        return str;
    }

    static vector<int> readArrayInt(string split) {
        vector<int> arr;
        string str;
        cin >> str;
        size_t pos = 0;
        while ((pos = str.find(split)) != string::npos) {
            string token = str.substr(0, pos);
            arr.push_back(stoi(token));
            str.erase(0, pos + split.length());
        }
        arr.push_back(stoi(str));
        return arr;
    }

    static vector<long long> readArrayLong(string split) {
        vector<long long> arr;
        string str;
        cin >> str;
        size_t pos = 0;
        while ((pos = str.find(split)) != string::npos) {
            string token = str.substr(0, pos);
            arr.push_back(stoll(token));
            str.erase(0, pos + split.length());
        }
        arr.push_back(stoll(str));
        return arr;
    }

    static vector<string> readArrayString(string split) {
        vector<string> arr;
        string str;
        cin >> str;
        size_t pos = 0;
        while ((pos = str.find(split)) != string::npos) {
            string token = str.substr(0, pos);
            arr.push_back(token);
            str.erase(0, pos + split.length());
        }
        arr.push_back(str);
        return arr;
    }

    static void writeArray(vector<int>& arr, string split, bool enter) {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i];
            if (i != arr.size() - 1) {
                cout << split;
            }
        }
        if (enter) {
            cout << endl;
        }
    }

    static void writeArray(vector<long long>& arr, string split, bool enter) {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i];
            if (i != arr.size() - 1) {
                cout << split;
            }
        }
        if (enter) {
            cout << endl;
        }
    }

    static void writeArray(vector<string>& arr, string split, bool enter) {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i];
            if (i != arr.size() - 1) {
                cout << split;
            }
        }
        if (enter) {
            cout << endl;
        }
    }

    static void writeInt(int num, string end) {
        cout << num << end;
    }

    static void writeLong(long long num, string end) {
        cout << num << end;
    }

    static void writeString(string str, string end) {
        cout << str << end;
    }

    static void writeBoolean(bool value, string end) {
        cout << (value ? "true" : "false") << end;
    }

    static void writeChar(char ch, string end) {
        cout << ch << end;
    }

    static void writeEnter() {
        cout << endl;
    }
};

class Main : public IO {
public:
    static void main() {
        int i1 = readInt();
        map<int, int> countValue;
        for (int i2 = 0; i2 < i1; i2++) {
            countValue.clear();
            vector<int> quantity = readArrayInt(" ");
            vector<int> base = readArrayInt(" ");
            for (int i = 0; i < quantity[2]; i++) {
                countValue[base[i]]++;
            }
            int min = countValue.size();
            for (int i = quantity[2]; i < quantity[0]; i++) {
                countValue[base[i - quantity[2]]]--;
                if (countValue[base[i - quantity[2]]] == 0) {
                    countValue.erase(base[i - quantity[2]]);
                }
                countValue[base[i]]++;
                min = min(min, (int)countValue.size());
            }
            writeInt(min, "\n");
        }
    }
};

int main() {
    Main::main();
    return 0;
}
