



#include <iostream>






#include <stack>






#include <utility>








#include <algorithm>


#include <vector>




#include <numeric>






#include <deque>





using namespace std;





int main() {






    int t;










    cin >> t;






    while (t--) {








        int n;


        cin >> n;








        vector<int> a(n);








        vector<deque<int>> b(n + 1);




        for (int i = 0; i < n; i++) {








            int x;








            cin >> x;


            a[i] = x;








            b[x].push_back(i);






        }




        int cnt = 0;






        vector<int> ans;










        while (cnt < n) {






            int i = 0;










            int mx = cnt + 1;






            while (i <= n) {










                if (b[i].empty()) {








                    break;






                }




                mx = std::max(mx, b[i].front() + 1);




                i++;










            }




            ans.push_back(i);










            while (cnt < mx) {




                b[a[cnt++]].pop_front();










            }




        }








        cout << ans.size() << endl;






        for (auto it : ans) {








            cout << it << ' ';






        }


        cout << endl;










    }




}
