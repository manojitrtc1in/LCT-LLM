


using namespace std;
typedef long long ll;
typedef long long int lli;
const unsigned int MOD = 1000000007;



int solve(int a[], int b[], int n, vector<pair<int, int>> &v)
{
    for (int i = 1; i < n; i++)
    {
        bool op1 = (a[i - 1] > a[i] && b[i - 1] > b[i]);
        bool op2 = (a[i - 1] < a[i] && b[i - 1] < b[i]);
        bool op3 = (a[i - 1] == a[i] && b[i - 1] == b[i]);
        bool op4 = (b[i - 1] == b[i] && a[i - 1] > a[i]);
        bool op5 = (a[i - 1] == a[i] && b[i - 1] > b[i]);
        if (op1 || op2 || op3 || op4 || op5)
            continue;
        else
            return -1;
    }
    int i, j;
    int count = 0;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            bool op1 = (b[i] == b[j] && a[i] > a[j]);
            bool op2 = (a[i] == a[j] && b[i] > b[j]);
            bool op3 = (a[j] < a[i]) && (b[j] < b[i]);
            if (op1 || op2 || op3)
            {
                swap(a[j], a[i]);
                swap(b[j], b[i]);
                v.push_back({i + 1, j + 1});
                count++;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] > a[i])
        {
            count = -1;
            break;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (b[i - 1] > b[i])
        {
            count = -1;
            break;
        }
    }

    return count;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        int a[n], b[n];
        int A[n], B[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            A[i] = a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            B[i] = b[i];
        }

        sort(A, A + n);
        sort(B, B + n);
bool flag=true;
        for(int i=0;i<n;i++){
            if(a[i]==A[i]&&b[i]==B[i])
             continue;

            else 
            {
                for(int j=i+1;j<n;j++){
                    if(a[j]==A[i]&&b[j]==B[i]){
                        v.push_back({i+1,j+1});
                        swap(a[i],a[j]);
                        swap(b[i],b[j]);

                    }
                }
            }
            if(a[i]==A[i]&&b[i]==B[i])
             continue;

             else {
                 flag=false;
                 break;
             }
        }
        

        if(flag==false)
         cout<<-1<<"\n";

         else {
             cout<<v.size()<<"\n";
              for(auto x: v){
                  cout<<x.first<<" "<<x.second<<"\n";
              }
         }
        
       

    }
    return 0;
}