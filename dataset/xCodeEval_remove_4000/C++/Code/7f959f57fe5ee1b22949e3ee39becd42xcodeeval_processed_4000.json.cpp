




using namespace std;



void id9(int s[],int a)
{
    for(int h = 0;h < a;++h)
        cin >> s[h];
}
void id2(int y[],int u)
{
    for(int h = 0;h < u;++h)
    {
        cout << y[h] << ' ';
    }
}
void id6(string s[],int a)
{
    for(int h = 0;h < a;++h)
        cin >> s[h];
}
void id5(string y[],int u,string d)
{
    for(int h = 0;h < u;++h)
    {
        {
        cout << y[h];
        if(h > u - 1)
            cout << d;
        }
    }
}
void id8(string&s,int d)
{
    for(int g = 0;g < d;++g)
    {
        if((int)s[g] < 97)
            s[g] = s[g] + 32;
        else
            s[g] = s[g] - 32;
    }
}
void id4(int h[],int f,int j)
{
    for(int hg = 0;hg < f;++hg)
        h[hg] = h[hg] + j;
}
int id1(int64_t h[],int f)
{
    int64_t y = 0;
    for(int g = 0;g < f;++g)
        y = y + h[g];
    return y;
}
int id7(int y[],int h)
{
    int a = y[0];
    for(int g = 0;g < h;++g)
        a = min(a,y[g]);
    return a;
}
int id0(int y[],int h)
{
    int a = y[0];
    for(int g = 0;g < h;++g)
        a = max(a,y[g]);
    return a;
}
int plus_factory(int a)
{
    int u = 0;
    for(int j = 0; j < a;++j)
        u = u + j;
    return u;
}
int factory(int a)
{
    int u = 1;
    for(int j = 1; j < a;++j)
        u = u*j;
    return u;
}
void id3(int64_t y[],int h)
{
    int b = h - 1;
    int k[h];
    for(int l = 0;l < h;++l)
        k[l] = y[l];
    for(int r = 0;r < h;++r)
    {
        y[r] = k[r + b];
        b -= 2;
    }
}



















































































































































int main()
{
    int a;
    int b;
    cin >> a >> b;
    int c[a];
    id9(c,a);
    sort(c,c + a);
    int64_t d = 0;
    if(b > c[a/2])
    {
        for(int f = a/2;f < a;++f)
        {
            if(b - c[f] < 0)
                c[f] = b;
            d = d + b - c[f];
        }
    }
    if(b < c[a/2])
    {
        for(int f = 0;f < a/2 + 1;++f)
        {
            if(c[f] - b < 0)
                c[f] = b;
            d = d + c[f] - b;
        }
    }
    cout << d;
    return 0;
}
