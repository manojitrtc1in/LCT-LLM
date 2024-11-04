#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stack>
#include <random>

using namespace std;

const int gigamod = 1000000007;
int t = 1;
double epsilon = 0.00000001;
vector<bool> isPrime;
vector<int> smallestFactorOf;

int check(const vector<char>& tgt, const vector<char>& src) {
    int n = tgt.size();
    if (src.size() != n) return 0;

    char xDig = 0;
    for (int i = 0; i < n; i++)
        if (src[i] == 'X') {
            if (xDig == 0) {
                xDig = tgt[i];
            } else {
                if (tgt[i] != xDig) return 0;
            }
        }

    if (tgt[0] == '0') return 0;

    for (int i = 0; i < n; i++)
        if (src[i] != '_' && src[i] != 'X' && tgt[i] != src[i]) return 0;

    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int tc = 0; tc < t; tc++) {
        string sOG;
        cin >> sOG;
        int n = sOG.length();

        if (n == 1) {
            if (sOG[0] == '0' || sOG[0] == '_' || sOG[0] == 'X')
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
            continue;
        }

        int answer = 0;

        {
            vector<char> s(sOG.begin(), sOG.end());
            bool shit = (s[n - 1] != '_' && s[n - 1] != 'X' && s[n - 1] != '0');
            shit |= (s[n - 2] != '_' && s[n - 2] != 'X' && s[n - 2] != '0');

            if (!shit) {
                if (s[n - 1] == 'X' || s[n - 2] == 'X')
                    for (int i = 0; i < n; i++)
                        if (s[i] == 'X')
                            s[i] = '0';
                s[n - 1] = '0';
                s[n - 2] = '0';

                answer += check(vector<char>{'0', '0'}, s);

                for (int num = 0; num < 1e6; num++) {
                    string tgt = to_string(num) + "00";
                    answer += check(vector<char>(tgt.begin(), tgt.end()), s);
                }
            }
        }

        {
            vector<char> s(sOG.begin(), sOG.end());
            bool shit = (s[n - 1] != '_' && s[n - 1] != 'X' && s[n - 1] != '5');
            shit |= s[n - 2] != '_' && s[n - 2] != 'X' && s[n - 2] != '2';
            shit |= (s[n - 1] == 'X' && s[n - 2] == 'X');

            if (!shit) {
                if (s[n - 1] == 'X') {
                    for (int i = 0; i < n; i++)
                        if (s[i] == 'X')
                            s[i] = '5';
                } else if (s[n - 2] == 'X') {
                    for (int i = 0; i < n; i++)
                        if (s[i] == 'X')
                            s[i] = '2';
                }

                s[n - 1] = '5';
                s[n - 2] = '2';

                answer += check(vector<char>{'2', '5'}, s);

                for (int num = 0; num < 1e6; num++) {
                    string tgt = to_string(num) + "25";
                    answer += check(vector<char>(tgt.begin(), tgt.end()), s);
                }
            }
        }

        {
            vector<char> s(sOG.begin(), sOG.end());
            bool shit = (s[n - 1] != '_' && s[n - 1] != 'X' && s[n - 1] != '0');
            shit |= s[n - 2] != '_' && s[n - 2] != 'X' && s[n - 2] != '5';
            shit |= (s[n - 1] == 'X' && s[n - 2] == 'X');

            if (!shit) {
                if (s[n - 1] == 'X') {
                    for (int i = 0; i < n; i++)
                        if (s[i] == 'X')
                            s[i] = '0';
                } else if (s[n - 2] == 'X') {
                    for (int i = 0; i < n; i++)
                        if (s[i] == 'X')
                            s[i] = '5';
                }

                s[n - 1] = '0';
                s[n - 2] = '5';

                answer += check(vector<char>{'5', '0'}, s);

                for (int num = 0; num < 1e6; num++) {
                    string tgt = to_string(num) + "50";
                    answer += check(vector<char>(tgt.begin(), tgt.end()), s);
                }
            }
        }

        {
            vector<char> s(sOG.begin(), sOG.end());
            bool shit = (s[n - 1] != '_' && s[n - 1] != 'X' && s[n - 1] != '5');
            shit |= s[n - 2] != '_' && s[n - 2] != 'X' && s[n - 2] != '7';
            shit |= (s[n - 1] == 'X' && s[n - 2] == 'X');

            if (!shit) {
                if (s[n - 1] == 'X') {
                    for (int i = 0; i < n; i++)
                        if (s[i] == 'X')
                            s[i] = '5';
                } else if (s[n - 2] == 'X') {
                    for (int i = 0; i < n; i++)
                        if (s[i] == 'X')
                            s[i] = '7';
                }

                s[n - 1] = '5';
                s[n - 2] = '7';

                answer += check(vector<char>{'7', '5'}, s);

                for (int num = 0; num < 1e6; num++) {
                    string tgt = to_string(num) + "75";
                    answer += check(vector<char>(tgt.begin(), tgt.end()), s);
                }
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
