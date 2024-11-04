






using namespace std;






using ll = long long int;
using vi = vector<int>;


using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}
struct P
{
    int x, y;
    P(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};
int sgn(int a)
{
    if(a >= 0) return 1;
    return -1;
}
int main()
{

    

    

    int xa, xb, xc, ya, yb, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    int ans = 1000000000, curans = 0;
    vector<P> ansv;
    vector<P> cur;
    short int a[1010][1010];
    for(int i = 0; i < 1010; i++)
    {
        for(int j = 0; j < 1010; j++)
        {
            a[i][j] = 0;
        }
    }
    int rxa = xa, rxb = xb, rxc = xc, rya = ya, ryb = yb, ryc = yc;
    while(rxa != rxb)
    {
        if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
        a[rxa][rya] = 1;

        rxa += sgn(rxb - rxa);
    }
     if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
        a[rxa][rya] = 1;
    while(rya != ryb)
    {
        if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
        a[rxa][rya] = 1;
        rya += sgn(ryb - rya);
    }
     if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
        a[rxa][rya] = 1;
    while(rxb != rxc)
    {
        if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
        a[rxb][ryb] = 1;
        rxb += sgn(rxc - rxb);
    }
    if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
    a[rxb][ryb] = 1;
    while(ryb != ryc)
    {
        if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
        a[rxb][ryb] = 1;
        ryb += sgn(ryc - ryb);
    }
    if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
    a[rxb][ryb] = 1;
     

     if(curans < ans)
     {
         ans = curans;
         ansv = cur;
     }
     cur.clear();
    curans = 0;
    for(int i = 0; i < 1010; i++)
    {
        for(int j = 0; j < 1010; j++)
        {
            

            a[i][j] = 0;
        }
        

    }
    

    rxa = xa, rxb = xb, rxc = xc, rya = ya, ryb = yb, ryc = yc;
    while(rxa != rxc)
    {
        if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
        a[rxa][rya] = 1;
        rxa += sgn(rxc - rxa);
    }
    if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
    a[rxa][rya] = 1;
    while(rya != ryc)
    {
        if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
        a[rxa][rya] = 1;
        rya += sgn(ryc - rya);
    }
    if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
    a[rxa][rya] = 1;
    while(rxb != rxc)
    {
        if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
        a[rxb][ryb] = 1;
        rxb += sgn(rxc - rxb);
    }
    if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
    a[rxb][ryb] = 1;
    while(ryb != ryc)
    {
        if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
        a[rxb][ryb] = 1;
        ryb += sgn(ryc - ryb);
    }
    if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
    a[rxb][ryb] = 1;
    

    if(curans < ans)
     {
         ans = curans;
         ansv = cur;
     }
     cur.clear();
     curans = 0;
    for(int i = 0; i < 1010; i++)
    {
        for(int j = 0; j < 1010; j++)
        {
            

            a[i][j] = 0;
        }
        

    }
    rxa = xa, rxb = xb, rxc = xc, rya = ya, ryb = yb, ryc = yc;
    while(rxc != rxa)
    {
        if(a[rxc][ryc] == 0) curans++, cur.push_back(P(rxc, ryc));
        a[rxc][ryc] = 1;
        rxc += sgn(rxa - rxc);
    }
    if(a[rxc][ryc] == 0) curans++, cur.push_back(P(rxc, ryc));
    a[rxc][ryc] = 1;
    while(ryc != rya)
    {
        if(a[rxc][ryc] == 0) curans++, cur.push_back(P(rxc, ryc));
        a[rxc][ryc] = 1;
        ryc += sgn(rya - ryc);
    }
    if(a[rxc][ryc] == 0) curans++, cur.push_back(P(rxc, ryc));
    a[rxc][ryc] = 1;
    while(rxb != rxa)
    {
        if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
        a[rxb][ryb] = 1;
        rxb += sgn(rxa - rxb);
    }
    if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
        a[rxb][ryb] = 1;
    while(ryb != rya)
    {
        if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
        a[rxb][ryb] = 1;
        ryb += sgn(rya - ryb);
    }
    if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
    a[rxb][ryb] = 1;
    
   if(curans < ans)
     {
         ans = curans;
         ansv = cur;
     }
     cur.clear();
     curans = 0;






















    for(int i = 0; i < 1010; i++)
    {
        for(int j = 0; j < 1010; j++)
        {
            a[i][j] = 0;
        }
    }
    rxa = xa, rxb = xb, rxc = xc, rya = ya, ryb = yb, ryc = yc;
    while(rya != ryb)
    {
        if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
        a[rxa][rya] = 1;
        rya += sgn(ryb - rya);
    }
     if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
        a[rxa][rya] = 1;
    while(rxa != rxb)
    {
        if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
        a[rxa][rya] = 1;

        rxa += sgn(rxb - rxa);
    }
    if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
    a[rxa][rya] = 1;
    while(rxb != rxc)
    {
        if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
        a[rxb][ryb] = 1;
        rxb += sgn(rxc - rxb);
    }
    if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
    a[rxb][ryb] = 1;
    while(ryb != ryc)
    {
        if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
        a[rxb][ryb] = 1;
        ryb += sgn(ryc - ryb);
    }
    if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
    a[rxb][ryb] = 1;
     

     if(curans < ans)
     {
         ans = curans;
         ansv = cur;
     }
     cur.clear();
    curans = 0;
    for(int i = 0; i < 1010; i++)
    {
        for(int j = 0; j < 1010; j++)
        {
            

            a[i][j] = 0;
        }
        

    }
    

    rxa = xa, rxb = xb, rxc = xc, rya = ya, ryb = yb, ryc = yc;
    while(rya != ryc)
    {
        if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
        a[rxa][rya] = 1;
        rya += sgn(ryc - rya);
    }
    if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
    a[rxa][rya] = 1;
     while(rxa != rxc)
    {
        if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
        a[rxa][rya] = 1;
        rxa += sgn(rxc - rxa);
    }
    if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
    a[rxa][rya] = 1;
    while(rxb != rxc)
    {
        if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
        a[rxb][ryb] = 1;
        rxb += sgn(rxc - rxb);
    }
    if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
    a[rxb][ryb] = 1;
    while(ryb != ryc)
    {
        if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
        a[rxb][ryb] = 1;
        ryb += sgn(ryc - ryb);
    }
    if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
    a[rxb][ryb] = 1;
    

    if(curans < ans)
     {
         ans = curans;
         ansv = cur;
     }
     cur.clear();
     curans = 0;
    for(int i = 0; i < 1010; i++)
    {
        for(int j = 0; j < 1010; j++)
        {
            

            a[i][j] = 0;
        }
        

    }
    rxa = xa, rxb = xb, rxc = xc, rya = ya, ryb = yb, ryc = yc;
    while(ryc != rya)
    {
        if(a[rxc][ryc] == 0) curans++, cur.push_back(P(rxc, ryc));
        a[rxc][ryc] = 1;
        ryc += sgn(rya - ryc);
    }
    if(a[rxc][ryc] == 0) curans++, cur.push_back(P(rxc, ryc));
    a[rxc][ryc] = 1;
     while(rxc != rxa)
    {
        if(a[rxc][ryc] == 0) curans++, cur.push_back(P(rxc, ryc));
        a[rxc][ryc] = 1;
        rxc += sgn(rxa - rxc);
    }
    if(a[rxc][ryc] == 0) curans++, cur.push_back(P(rxc, ryc));
    a[rxc][ryc] = 1;
    while(rxb != rxa)
    {
        if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
        a[rxb][ryb] = 1;
        rxb += sgn(rxa - rxb);
    }
    if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
        a[rxb][ryb] = 1;
    while(ryb != rya)
    {
        if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
        a[rxb][ryb] = 1;
        ryb += sgn(rya - ryb);
    }
    if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
    a[rxb][ryb] = 1;
    
    if(curans < ans)
     {
         ans = curans;
         ansv = cur;
     }
     cur.clear();
     curans = 0;





    for(int i = 0; i < 1010; i++)
    {
        for(int j = 0; j < 1010; j++)
        {
            a[i][j] = 0;
        }
    }
    rxa = xa, rxb = xb, rxc = xc, rya = ya, ryb = yb, ryc = yc;
    while(rxa != rxb)
    {
        if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
        a[rxa][rya] = 1;

        rxa += sgn(rxb - rxa);
    }
     if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
        a[rxa][rya] = 1;
    while(rya != ryb)
    {
        if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
        a[rxa][rya] = 1;
        rya += sgn(ryb - rya);
    }
     if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
        a[rxa][rya] = 1;
    while(ryb != ryc)
    {
        if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
        a[rxb][ryb] = 1;
        ryb += sgn(ryc - ryb);
    }
    if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
    a[rxb][ryb] = 1;
     while(rxb != rxc)
    {
        if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
        a[rxb][ryb] = 1;
        rxb += sgn(rxc - rxb);
    }
    if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
    a[rxb][ryb] = 1;
     

     if(curans < ans)
     {
         ans = curans;
         ansv = cur;
     }
     cur.clear();
    curans = 0;
    for(int i = 0; i < 1010; i++)
    {
        for(int j = 0; j < 1010; j++)
        {
            

            a[i][j] = 0;
        }
        

    }
    

    rxa = xa, rxb = xb, rxc = xc, rya = ya, ryb = yb, ryc = yc;
    while(rxa != rxc)
    {
        if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
        a[rxa][rya] = 1;
        rxa += sgn(rxc - rxa);
    }
    if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
    a[rxa][rya] = 1;
    while(rya != ryc)
    {
        if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
        a[rxa][rya] = 1;
        rya += sgn(ryc - rya);
    }
    if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
    a[rxa][rya] = 1;
    while(ryb != ryc)
    {
        if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
        a[rxb][ryb] = 1;
        ryb += sgn(ryc - ryb);
    }
    if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
    a[rxb][ryb] = 1;
    while(rxb != rxc)
    {
        if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
        a[rxb][ryb] = 1;
        rxb += sgn(rxc - rxb);
    }
    if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
    a[rxb][ryb] = 1;
    

    if(curans < ans)
     {
         ans = curans;
         ansv = cur;
     }
     cur.clear();
     curans = 0;
    for(int i = 0; i < 1010; i++)
    {
        for(int j = 0; j < 1010; j++)
        {
            

            a[i][j] = 0;
        }
        

    }
    rxa = xa, rxb = xb, rxc = xc, rya = ya, ryb = yb, ryc = yc;
    while(rxc != rxa)
    {
        if(a[rxc][ryc] == 0) curans++, cur.push_back(P(rxc, ryc));
        a[rxc][ryc] = 1;
        rxc += sgn(rxa - rxc);
    }
    if(a[rxc][ryc] == 0) curans++, cur.push_back(P(rxc, ryc));
    a[rxc][ryc] = 1;
    while(ryc != rya)
    {
        if(a[rxc][ryc] == 0) curans++, cur.push_back(P(rxc, ryc));
        a[rxc][ryc] = 1;
        ryc += sgn(rya - ryc);
    }
    if(a[rxc][ryc] == 0) curans++, cur.push_back(P(rxc, ryc));
    a[rxc][ryc] = 1;

    while(ryb != rya)
    {
        if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
        a[rxb][ryb] = 1;
        ryb += sgn(rya - ryb);
    }
    if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
    a[rxb][ryb] = 1;

     while(rxb != rxa)
    {
        if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
        a[rxb][ryb] = 1;
        rxb += sgn(rxa - rxb);
    }
    if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
        a[rxb][ryb] = 1;
    
   if(curans < ans)
     {
         ans = curans;
         ansv = cur;
     }
     cur.clear();
     curans = 0;



     for(int i = 0; i < 1010; i++)
    {
        for(int j = 0; j < 1010; j++)
        {
            a[i][j] = 0;
        }
    }
     rxa = xa, rxb = xb, rxc = xc, rya = ya, ryb = yb, ryc = yc;

    while(rya != ryb)
    {
        if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
        a[rxa][rya] = 1;
        rya += sgn(ryb - rya);
    }
     if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
        a[rxa][rya] = 1;
        while(rxa != rxb)
    {
        if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
        a[rxa][rya] = 1;

        rxa += sgn(rxb - rxa);
    }
     if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
    a[rxa][rya] = 1;
    while(ryb != ryc)
    {
        if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
        a[rxb][ryb] = 1;
        ryb += sgn(ryc - ryb);
    }
    if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
    a[rxb][ryb] = 1;
     while(rxb != rxc)
    {
        if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
        a[rxb][ryb] = 1;
        rxb += sgn(rxc - rxb);
    }
    if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
    a[rxb][ryb] = 1;
     

     if(curans < ans)
     {
         ans = curans;
         ansv = cur;
     }
     cur.clear();
    curans = 0;
    for(int i = 0; i < 1010; i++)
    {
        for(int j = 0; j < 1010; j++)
        {
            

            a[i][j] = 0;
        }
        

    }
    

    rxa = xa, rxb = xb, rxc = xc, rya = ya, ryb = yb, ryc = yc;

    while(rya != ryc)
    {
        if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
        a[rxa][rya] = 1;
        rya += sgn(ryc - rya);
    }
    if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
    a[rxa][rya] = 1;
     while(rxa != rxc)
    {
        if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
        a[rxa][rya] = 1;
        rxa += sgn(rxc - rxa);
    }
    if(a[rxa][rya] == 0) curans++, cur.push_back(P(rxa, rya));
    a[rxa][rya] = 1;
    while(ryb != ryc)
    {
        if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
        a[rxb][ryb] = 1;
        ryb += sgn(ryc - ryb);
    }
    if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
    a[rxb][ryb] = 1;
    while(rxb != rxc)
    {
        if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
        a[rxb][ryb] = 1;
        rxb += sgn(rxc - rxb);
    }
    if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
    a[rxb][ryb] = 1;
    

    if(curans < ans)
     {
         ans = curans;
         ansv = cur;
     }
     cur.clear();
     curans = 0;
    for(int i = 0; i < 1010; i++)
    {
        for(int j = 0; j < 1010; j++)
        {
            

            a[i][j] = 0;
        }
        

    }
    rxa = xa, rxb = xb, rxc = xc, rya = ya, ryb = yb, ryc = yc;

    while(ryc != rya)
    {
        if(a[rxc][ryc] == 0) curans++, cur.push_back(P(rxc, ryc));
        a[rxc][ryc] = 1;
        ryc += sgn(rya - ryc);
    }
    if(a[rxc][ryc] == 0) curans++, cur.push_back(P(rxc, ryc));
    a[rxc][ryc] = 1;
   while(rxc != rxa)
    {
        if(a[rxc][ryc] == 0) curans++, cur.push_back(P(rxc, ryc));
        a[rxc][ryc] = 1;
        rxc += sgn(rxa - rxc);
    }
    if(a[rxc][ryc] == 0) curans++, cur.push_back(P(rxc, ryc));
    a[rxc][ryc] = 1;
    while(ryb != rya)
    {
        if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
        a[rxb][ryb] = 1;
        ryb += sgn(rya - ryb);
    }
    if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
    a[rxb][ryb] = 1;

     while(rxb != rxa)
    {
        if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
        a[rxb][ryb] = 1;
        rxb += sgn(rxa - rxb);
    }
    if(a[rxb][ryb] == 0) curans++, cur.push_back(P(rxb, ryb));
        a[rxb][ryb] = 1;
    
   if(curans < ans)
     {
         ans = curans;
         ansv = cur;
     }
     cur.clear();
     curans = 0;
    cout << ans << "\n";
    for(P p : ansv) cout << p.x << " " << p.y << "\n";
    

}
