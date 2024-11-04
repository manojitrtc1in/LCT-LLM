
























































using namespace std;













using ll = long long;







int main() {


    int t;




    cin >> t;






    while (t--) {


        int n;


        cin >> n;






        vector<ll> t(n);


        vector<ll> a(n);


        for (size_t i = 0; i < n; i++) {


            cin >> t[i];






        }






        for (size_t i = 0; i < n; i++) {




            cin >> a[i];






        }







        vector<ll> d(n);


        d.back() = a.back();






        for (int i = n - 2; i >= 0; i--) {


            d[i] = max(a[i], d[i + 1] - (t[i + 1] - t[i]));




        }






        ll ans = 0;






        ll cur = 0;




        for (int i = 0; i < n; i++) {


            ll time = t[i] - (i ? t[i - 1] : 0);


            if (time >= d[i]) {






                cur = d[i];




                ans += d[i] * (d[i] + 1) / 2;




            } else {




                ans += (2 * (cur + 1) + time - 1) * time / 2;




                cur += time;


            }






        }


        cout << ans << endl;




    }




}
