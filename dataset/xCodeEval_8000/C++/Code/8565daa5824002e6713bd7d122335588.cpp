#define ONLINE_JUDGE 0

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef pair<int, int> ii;

int h, w, k;
ii start, finish;
char m[1000][1000];
set<int> vish[1000], visv[1000];
vector<ii> visTask;
int d[1000][1000];

void solve() {
    scanf("%d %d %d", &h, &w, &k);
    for (int i = 0; i < h; i++)
        vish[i].insert(-1);
    for (int j = 0; j < w; j++)
        visv[j].insert(-1);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf(" %c", &m[i][j]);


            vish[i].insert(j);
            visv[j].insert(i);
            d[i][j] = -1;
        }
    }
    scanf("%d %d", &start.x, &start.y);
    start.x--;
    start.y--;
    scanf("%d %d", &finish.x, &finish.y);
    finish.x--;
    finish.y--;
    queue<ii> bfs;
    bfs.push(start);
    d[start.x][start.y] = 0;
    vish[start.x].erase(start.y);
    visv[start.y].erase(start.x);
    while (!bfs.empty()) {
        ii cur = bfs.front();
        bfs.pop();
        
        int dd = d[cur.x][cur.y] + 1;
        auto ith = vish[cur.x].lower_bound(cur.y);
        { 

            auto it = ith;
            if (it == vish[cur.x].begin())
                break;
            it--;
            while (it != vish[cur.x].begin() && cur.y - *it <= k && m[cur.x][*it] != '#') {
                d[cur.x][*it] = dd;
                bfs.push({cur.x, *it});
                visTask.push_back({cur.x, *it});
                it--;
            }
        }
        { 

            auto it = ith;
            while (it != vish[cur.x].end() && *it - cur.y <= k && m[cur.x][*it] != '#') {
                d[cur.x][*it] = dd;
                bfs.push({cur.x, *it});
                visTask.push_back({cur.x, *it});
                it++;
            }
        }
        auto itv = visv[cur.y].lower_bound(cur.x);
        { 

            auto it = itv;
            if (it == visv[cur.x].begin())
                break;
            it--;
            while (it != visv[cur.y].begin() && cur.x - *it <= k && m[*it][cur.y] != '#') {
                d[*it][cur.y] = dd;
                bfs.push({*it, cur.y});
                visTask.push_back({*it, cur.y});
                it--;
            }
        }
        { 

            auto it = itv;
            while (it != visv[cur.y].end() && *it - cur.x <= k && m[*it][cur.y] != '#') {
                d[*it][cur.y] = dd;
                bfs.push({*it, cur.y});
                visTask.push_back({*it, cur.y});
                it++;
            }
        }
        while (!visTask.empty()) {
            ii pos = visTask.back();
            visTask.pop_back();
            vish[pos.x].erase(pos.y);
            visv[pos.y].erase(pos.x);
        }
    }


















    printf("%d", d[finish.x][finish.y]);
}

int main() {
    srand(time(nullptr));
    ios_base::sync_with_stdio(false);
    if (!ONLINE_JUDGE) {





    } else {
        freopen("input.txt", "r", stdin);


    }


    solve();
    return 0;
}
