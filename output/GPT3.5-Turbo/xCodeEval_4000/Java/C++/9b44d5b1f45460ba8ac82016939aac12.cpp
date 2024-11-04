#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <numeric>
#include <functional>
#include <random>
#include <fstream>
#include <chrono>
#include <tuple>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<vd> vvd;
typedef vector<vs> vvs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pdd> vpdd;
#define all(c) (c).begin(), (c).end()
#define loop(i, a, n) for (int i = a; i < n; i++)
#define rep(i, n) loop(i, 0, n)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define prec(n) fixed << setprecision(n)
const double PI = acos(-1);
const double EPS = 1e-10;
const int inf = 1e9 + 7;
const ll linf = 1LL << 60;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    rep(i, v.size()) is >> v[i];
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    rep(i, v.size()) os << v[i] << ' ';
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v)
{
    rep(i, v.size()) os << v[i] << endl;
    return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << p.first << ' ' << p.second;
    return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const map<T1, T2> &mp)
{
    for (auto itr = mp.begin(); itr != mp.end(); ++itr)
    {
        os << itr->first << ": " << itr->second << endl;
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &st)
{
    for (auto itr = st.begin(); itr != st.end(); ++itr)
    {
        os << *itr << endl;
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &st)
{
    for (auto itr = st.begin(); itr != st.end(); ++itr)
    {
        os << *itr << endl;
    }
    return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const unordered_map<T1, T2> &mp)
{
    for (auto itr = mp.begin(); itr != mp.end(); ++itr)
    {
        os << itr->first << ": " << itr->second << endl;
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const deque<T> &deq)
{
    for (auto itr = deq.begin(); itr != deq.end(); ++itr)
    {
        os << *itr << endl;
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const priority_queue<T> &que)
{
    auto tmp = que;
    while (!tmp.empty())
    {
        os << tmp.top() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const stack<T> &stk)
{
    auto tmp = stk;
    while (!tmp.empty())
    {
        os << tmp.top() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const queue<T> &que)
{
    auto tmp = que;
    while (!tmp.empty())
    {
        os << tmp.front() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const priority_queue<T, vector<T>, greater<T>> &que)
{
    auto tmp = que;
    while (!tmp.empty())
    {
        os << tmp.top() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const stack<T, vector<T>> &stk)
{
    auto tmp = stk;
    while (!tmp.empty())
    {
        os << tmp.top() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const queue<T, vector<T>> &que)
{
    auto tmp = que;
    while (!tmp.empty())
    {
        os << tmp.front() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const priority_queue<T, vector<T>, greater<T>, deque<T>> &que)
{
    auto tmp = que;
    while (!tmp.empty())
    {
        os << tmp.top() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const stack<T, deque<T>> &stk)
{
    auto tmp = stk;
    while (!tmp.empty())
    {
        os << tmp.top() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const queue<T, deque<T>> &que)
{
    auto tmp = que;
    while (!tmp.empty())
    {
        os << tmp.front() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const priority_queue<T, vector<T>, greater<T>, vector<T>> &que)
{
    auto tmp = que;
    while (!tmp.empty())
    {
        os << tmp.top() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const stack<T, vector<T>>> &stk)
{
    auto tmp = stk;
    while (!tmp.empty())
    {
        os << tmp.top() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const queue<T, vector<T>>> &que)
{
    auto tmp = que;
    while (!tmp.empty())
    {
        os << tmp.front() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const priority_queue<T, vector<T>, greater<T>, list<T>> &que)
{
    auto tmp = que;
    while (!tmp.empty())
    {
        os << tmp.top() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const stack<T, list<T>> &stk)
{
    auto tmp = stk;
    while (!tmp.empty())
    {
        os << tmp.top() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const queue<T, list<T>> &que)
{
    auto tmp = que;
    while (!tmp.empty())
    {
        os << tmp.front() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const priority_queue<T, vector<T>, greater<T>, vector<T>, list<T>>> &que)
{
    auto tmp = que;
    while (!tmp.empty())
    {
        os << tmp.top() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const stack<T, vector<T>, list<T>> &stk)
{
    auto tmp = stk;
    while (!tmp.empty())
    {
        os << tmp.top() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const queue<T, vector<T>, list<T>> &que)
{
    auto tmp = que;
    while (!tmp.empty())
    {
        os << tmp.front() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const priority_queue<T, vector<T>, greater<T>, deque<T>, list<T>>> &que)
{
    auto tmp = que;
    while (!tmp.empty())
    {
        os << tmp.top() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const stack<T, deque<T>, list<T>> &stk)
{
    auto tmp = stk;
    while (!tmp.empty())
    {
        os << tmp.top() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const queue<T, deque<T>, list<T>> &que)
{
    auto tmp = que;
    while (!tmp.empty())
    {
        os << tmp.front() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const priority_queue<T, vector<T>, greater<T>, deque<T>, list<T>, vector<T>>> &que)
{
    auto tmp = que;
    while (!tmp.empty())
    {
        os << tmp.top() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const stack<T, vector<T>, list<T>, deque<T>> &stk)
{
    auto tmp = stk;
    while (!tmp.empty())
    {
        os << tmp.top() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const queue<T, vector<T>, list<T>, deque<T>> &que)
{
    auto tmp = que;
    while (!tmp.empty())
    {
        os << tmp.front() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const priority_queue<T, vector<T>, greater<T>, deque<T>, list<T>, vector<T>, deque<T>>> &que)
{
    auto tmp = que;
    while (!tmp.empty())
    {
        os << tmp.top() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const stack<T, vector<T>, list<T>, deque<T>, vector<T>> &stk)
{
    auto tmp = stk;
    while (!tmp.empty())
    {
        os << tmp.top() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const queue<T, vector<T>, list<T>, deque<T>, vector<T>> &que)
{
    auto tmp = que;
    while (!tmp.empty())
    {
        os << tmp.front() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const priority_queue<T, vector<T>, greater<T>, deque<T>, list<T>, vector<T>, deque<T>, vector<T>>> &que)
{
    auto tmp = que;
    while (!tmp.empty())
    {
        os << tmp.top() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const stack<T, vector<T>, list<T>, deque<T>, vector<T>, deque<T>>> &stk)
{
    auto tmp = stk;
    while (!tmp.empty())
    {
        os << tmp.top() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const queue<T, vector<T>, list<T>, deque<T>, vector<T>, deque<T>>> &que)
{
    auto tmp = que;
    while (!tmp.empty())
    {
        os << tmp.front() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const priority_queue<T, vector<T>, greater<T>, deque<T>, list<T>, vector<T>, deque<T>, vector<T>, deque<T>>> &que)
{
    auto tmp = que;
    while (!tmp.empty())
    {
        os << tmp.top() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const stack<T, vector<T>, list<T>, deque<T>, vector<T>, deque<T>, vector<T>>> &stk)
{
    auto tmp = stk;
    while (!tmp.empty())
    {
        os << tmp.top() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const queue<T, vector<T>, list<T>, deque<T>, vector<T>, deque<T>, vector<T>>> &que)
{
    auto tmp = que;
    while (!tmp.empty())
    {
        os << tmp.front() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const priority_queue<T, vector<T>, greater<T>, deque<T>, list<T>, vector<T>, deque<T>, vector<T>, deque<T>, vector<T>>> &que)
{
    auto tmp = que;
    while (!tmp.empty())
    {
        os << tmp.top() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const stack<T, vector<T>, list<T>, deque<T>, vector<T>, deque<T>, vector<T>, deque<T>>> &stk)
{
    auto tmp = stk;
    while (!tmp.empty())
    {
        os << tmp.top() << endl;
        tmp.pop();
    }
    return os;
}
template <typename T>
