






using namespace std;



int main()
{
    long long p, q;
    int n;
    cin>>p>>q>>n;
    vector<long long>orig;
    long long temp;
    while (q)
    {
        orig.push_back(p/q);
        

        temp = p%q;
        p = q;
        q = temp;
    }
    vector<long long>cont(n);
    bool ok = true;
    for (int i=0; i < n; i++)
    {
        cin>>cont[i];
    }
    if (n > 1 && cont[n-1] == 1)
    {
            cont[n-2]++;
            cont.pop_back();
    }
    if (orig.size() == cont.size())
    {
        for (int i = 0; i < cont.size(); i++)
        {
            if (orig[i] != cont[i])
            {
                ok = false;
                break;
            }
        }
        if (ok)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}