#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
map<int, int> row, col;
int n, m;
struct range {
   int x, y;
}vols[100005], cur[100005], prev[100005];

bool cmp(range a, range b) {
    if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}


int main() {
   cin >> n >> m;
   for (int i = 1; i <= m; i++) {
       cin >> vols[i].x >> vols[i].y;
   }
   sort(vols + 1, vols + m + 1, cmp);
   int curcnt = 0, prevcnt = 1;
   prev[1].x = 1;
   prev[1].y = 1;

   for (int i = 1; i <= m; i++) {
        if (vols[i].x != vols[i - 1].x + 1) {
            prevcnt = 1;
            prev[1].y = n;
        }

        int s = 1;
        int j;
        for (j = i; j <= m && vols[j].x == vols[i].x; j++); j--;
        curcnt = 0;
        for (int k = i; k <= j; k++) {
            if (vols[k].y >= s + 1) {
                cur[++curcnt].x = s;
                cur[curcnt].y = vols[k].y - 1;
            }
            s = vols[k].y + 1;
        }
        if (s <= n) {
            cur[++curcnt].x = s;
            cur[curcnt].y = n;
        }
        

        for (int k = 1; k <= curcnt; k++) {
            int l = 1, r = prevcnt, ret = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (prev[mid].y >= cur[k].x) {
                    ret = prev[mid].x;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (ret == -1 || ret > cur[k].y) {
                cur[k].x = cur[k].y = -1;
            } else {
                cur[k].x = max(cur[k].x, ret);
            }
        }


        prevcnt = 0;
        for (int k = 1; k <= curcnt; k++) {
            if (cur[k].x != -1 && cur[k].y != -1) {
                prev[++prevcnt] = cur[k];
            }
        }
        if (!prevcnt) {
            cout << "-1" << endl;
            exit(0);
        }
        i = j;
   }

      if (vols[m].x != n) {
          prevcnt = 1;
          prev[1].y = n;
      }

      if (prev[prevcnt].y == n)
          printf("%d\n", 2 * n - 2);
      else
          printf("-1");

    return 0;
}






























































