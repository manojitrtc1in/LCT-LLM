













































using namespace std;





















int main() {




    int t;






    cin >> t;




    while (t--) {




        int n, k;




        cin >> n >> k;


        vector<pair<int, int>> x(n);










        for (size_t i = 0; i < n; i++) {






            cin >> x[i].first;




        }


        for (size_t i = 0; i < n; i++) {








            cin >> x[i].second;








        }








        while (true) {










            bool changes = false;




            for (auto it = x.begin(); it != x.end();) {








                auto y = *it;




                if (k >= y.first) {


                    k += y.second;








                    it = x.erase(it);










                    changes = true;




                } else {










                    it++;










                }




            }


            if (!changes || x.empty()) {








                break;










            }










        }










        cout << k << endl;




    }






}
