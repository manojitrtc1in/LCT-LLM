


using namespace std;
typedef long long ll;









const int  inf = 0x3f3f3f3f;
int intcmp(const void *v1,const void *v2)
{
    return *(int *)v1-*(int *)v2;
}

inline int read()
{
    int x=0,f=1;
    char cc=getchar();
    while(cc<'0' || cc>'9')
    {
        if(cc=='-') f=-1;
        cc=getchar();
    }
    while(cc>='0' && cc<='9')
    {
        x=x*10+cc-'0';
        cc=getchar();
    }
    return x*f;
}
string s,res;
int n,k;
int main()
{
    cin >> n >> k;
    cin >> s;
    if(n == k)
    {
        cout << s <<endl;
        return 0;
    }
    int cnt =0;
        k/=2;
    for(int i = 0;i <n;i ++)
    {
        if(s[i] =='(' && k > 0)
        {
            res+= '(';
            k--;
            cnt ++;
        }
        if(s[i] == ')' && cnt >0)
        {
            cnt --;

            res+=')';
        }

    }
    cout << res <<endl;
    return 0;

}