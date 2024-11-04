


using namespace std;



















long long int casos, n, a[100003], cnt, mul;

int main()
{
    fastio;
    cin >> casos;
    while(casos--){
        cin >> n;
        cnt = 0;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n-1; i++){
            mul = i / a[i];
            mul++;
            for(int j = (mul * a[i]) - i; j <= n; j += a[i]){
                if(j > i && a[i] *  a[j] == i + j) cnt++;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}

