#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <string.h>
#include <functional>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <stdio.h>
#include <math.h>
typedef long long ll;
#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807LL
#define INF 2000000000
using namespace std;



































































int n;
vector < vector<pair<int, int>> >adj;
vector<int> parent(100001,-1);
vector<int> visited(100001,0);
vector<int> flags(100001, 0);


bool dfs(int k)
{
    visited[k] = 1;
    bool flag = flags[k];
    int sz=adj[k].size();
    for (int i = 0; i < sz; i++)
    {
        if (visited[adj[k][i].first] == 0)
        {
            flag=max(flag,dfs(adj[k][i].first));
        }
    }
    flags[k] = flag;
    return flag;
}


int counter = 0; vector<int> answers;
void dfs2(int k)
{
    visited[k] = 1;
    int sz = adj[k].size();
    bool found = false;
    for (int i = 0; i < sz; i++)
    {
        if (visited[adj[k][i].first] == 0 && flags[adj[k][i].first] == 1)
        {
            found = true;
            dfs2(adj[k][i].first);
        }
    }
    if (found == false &&flags[k]==1)
    {
        counter++;
        answers.push_back(k);
    }
}
int main()
{
    cin >> n;
    adj = vector<vector<pair<int, int>> >(n+1);
    bool trash = true;
    for (int i = 0; i < n - 1; i++)
    {
        int t1, t2, t3;
        scanf("%d %d %d", &t1, &t2, &t3);
        if (t3 == 2) trash = false;
        adj[t1].push_back(make_pair(t2, t3));
        adj[t2].push_back(make_pair(t1, t3));
        if (t3 == 2){
            flags[t1] = max(flags[t1],1); flags[t2] = max(flags[t2],1);
        }
    }
    dfs(1);
    visited = vector<int>(100001, 0);
    dfs2(1);
    cout << counter << endl;
    for (int i = 0; i < answers.size(); i++)
    {
        cout << answers[i] << " ";
    }
    return 0; 
}