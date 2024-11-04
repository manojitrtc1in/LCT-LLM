










using namespace std;



typedef std::vector<int> int_vector;
typedef long long ll;
typedef long double ld;
double gcd(unsigned long long a, unsigned long long b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}
long long modul(long long first_value, long long second_value)
{
    if (first_value - second_value < 0)
    {
        return ((first_value - second_value) * -1);
    }
    else
    {
        return (first_value - second_value);
    }
}



































































































































































































































































































































































































































































































































































































































































































































































































int funif() {
    int a, b; cin >> a >> b;
    if (a == b)
    {
        cout << a + 1 << endl;
        for (int i = 0; i <= a; ++i)
        {
            cout << a * 2 - (2 * i) << endl;
        }
    }

    return 0;
}
int id2(){
    int result = 0;
    int n; cin >> n;
    vector<int> vc(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> vc[i];
    }
    if (n == 1)
    {
        cout << vc[0] << endl;
        return 0;
    }
    if (n == 2)
    {
        result += vc[0] + vc[n - 1];
        for (int i = 1; i < n; ++i)
        {
            if (vc[i] < vc[i - 1])
            {
                result += vc[i - 1] - vc[i];
            }
            else
            {
                result += vc[i] - vc[i - 1];
            }
        }
        if (vc[0] > vc[1])
        {
            result += -1 * (vc[0] - vc[1]);
        }
        cout << result << endl;
        return 0;
    }
    result += vc[0] + vc[n - 1];
    for (int i = 1; i < n; ++i)
    {
        if (vc[i] < vc[i - 1])
        {
            result += vc[i - 1] - vc[i];
        }
        else
        {
            result += vc[i] - vc[i - 1];
        }
    }
    if (vc[0] > vc[1])
    {
        result += -1 * (vc[0] - vc[1]);
    }
    if (vc[n-1] > vc[n-2])
    {
        result += -1 * (vc[n - 1] - vc[n - 2]);
    }
    for (int i = 1; i < n-1; ++i)
    {
        if (vc[i] > vc[i-1] && vc[i] > vc[i+1])
        {
            result += -1 * (vc[i] - MAX(vc[i - 1], vc[i + 1]));
        }
    }
    cout << result << endl;
return 0;
}
int id3()
{
    string id4;
    int n; cin >> n;
    int count_units = 0;
    int id0 = -1;
    int result = 0;
    int temp;
    int m;
    for (int i = 0; i < n; ++i)
    {
        id4 += '0';
    }
    string* books_which_we_need_read = new string[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        for (int j = 0; j < temp; ++j)
        {
            cin >> m;
            books_which_we_need_read[i] += m;
        }
    }
    while (true) {
        ++result;
        for (int i = 0; i < n; ++i)
        {
            if (id4[i] == '1')
            {
                continue;
            }
            if (books_which_we_need_read[i].size() == 0)
            {
                id4[i] = '1';
                ++count_units;
            }
            for (int j = 0; j < books_which_we_need_read[i].size(); ++j)
            {
                if (id4[books_which_we_need_read[i][j] - 1] == '0')
                {
                    break;
                }
                if (j == (books_which_we_need_read[i].size() - 1))
                {
                    id4[i] = '1';
                    ++count_units;
                }
            }
        }
        if (count_units == id4.size())
        {
            cout << result << endl;
            delete[] books_which_we_need_read;
            return 0;
        }
        if (count_units == id0)
        {
            cout << "-1" << endl;
            delete[] books_which_we_need_read;
            return 0;
        }
        id0 = count_units;
    }
}








































































































    


int id1() {
    int n,sum = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == ((double)(sum - arr[i])/(n-1)))
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
    
}


class asdasd {
public:
    long long exp = 0;
    void plusexp(long long plus) {
        exp += plus;
       
    }
    void input_info_exp() {
        cout << this->exp << endl;
    }
    
    
};

class abc {
    
};

void jopa(int a) {
    cout << a << endl;
}
void jopa(bool a) {
    cout << a << endl;
}

    
int main() {
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    int t; cin >> t;

    while (t--) {
        id1(); 

    }
    
    return 0;
}