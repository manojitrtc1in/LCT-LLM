

























































using namespace std;
int main()
{
    int times;
    cin >> times;
    int counter = 0;
    int o= 0;
    char b;
    string a;
    for (int e = 1 ; e <= times ; ++e)
    {
    cin >> a;
        if (a.length() > 10)
        {
            for (std::string::iterator it = a.begin()+1 ; it < a.end()-1 ; ++it)
            {
                o++;
            }
            std::string::iterator it = a.begin();
            cout << *it;
            it = a.end()-1;
            cout << o;
            cout << *it << endl;
            o = 0;
        }
        else
        {
            cout << a << endl;
        }
    }
}