












































using namespace std;













vector<pair<int, int>> dir = {




    {-1, 0},




    {1, 0},


    {0, -1},




    {0, 1},






};









int main() {




    int t;






    cin >> t;




    while (t--) {






        int n, m;




        cin >> n >> m;




        queue<pair<int, int>> q;


        set<pair<int, int>> s;




        int x = n / 2;


        int y = m / 2;




        q.emplace(x, y);




        s.emplace(x, y);


        if ((n % 2 == 0) && (m % 2 == 0)) {


            q.emplace(x - 1, y - 1);


            s.emplace(x - 1, y - 1);


            q.emplace(x, y - 1);






            s.emplace(x, y - 1);


            q.emplace(x - 1, y);






            s.emplace(x - 1, y);


        } else if (n % 2 == 0) {






            q.emplace(x - 1, y);


            s.emplace(x - 1, y);




        } else if (m % 2 == 0) {




            q.emplace(x, y - 1);




            s.emplace(x, y - 1);


        }




        int k = n * m;




        while (k--) {


            int x = q.front().first;






            int y = q.front().second;




            q.pop();






            int ans = 0;


            ans = std::max(ans, x + y);




            ans = std::max(ans, n - 1 - x + y);






            ans = std::max(ans, n - 1 - x + m - 1 - y);


            ans = std::max(ans, x + m - 1 - y);


            cout << ans << ' ';






            for (auto d : dir) {


                int nx = x + d.first;


                int ny = y + d.second;




                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {




                    if (s.find(make_pair(nx, ny)) == s.end()) {


                        s.emplace(nx, ny);


                        q.emplace(nx, ny);






                    }




                }


            }


        }


        cout << endl;


    }






}
