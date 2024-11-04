

#include <iostream>






#include <algorithm>






#include <unordered_map>


#include <unordered_set>




#include <vector>




#include <string>


#include <queue>


#include <set>











using namespace std;









void dfs(bool xr, int v, int prev, vector<vector<pair<int, int>>>& g, vector<int>& ans) {




    for (auto it : g[v]) {






        if (it.first == prev) {






            continue;




        }


        ans[it.second] = xr ? 2 : 3;


        dfs(xr ^ 1, it.first, v, g, ans);


    }






}





int main() {




    int t;






    cin >> t;






    while (t--) {


        int n;






        cin >> n;






        vector<vector<pair<int, int>>> g(n);






        for (int i = 0; i < n - 1; i++) {




            int v, u;


            cin >> v >> u;






            v--, u--;






            g[v].emplace_back(u, i);






            g[u].emplace_back(v, i);


        }






        if (std::any_of(g.begin(), g.end(), [](const vector<pair<int, int>> vs) { return vs.size() > 2; })) {




            cout << -1 << endl;


            continue;


        }




        vector<int> ans(n - 1);






        int v;


        for (int i = 0; i < n; i++) {






            if (g[i].size() == 1) {






                v = i;






                break;


            }


        }






        dfs(0, v, v, g, ans);






        for (auto it : ans) {






            std::cout << it << ' ';






        }


        cout << endl;






    }




}
