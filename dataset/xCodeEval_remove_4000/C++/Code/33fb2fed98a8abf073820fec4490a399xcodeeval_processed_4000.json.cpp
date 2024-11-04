













using namespace std;
string id0(long long n)
{
    string ans;
    stringstream convert;
    convert << n;
    ans = convert.str();
    return ans;
}
string sum ( string a , string b )
{
    int k;
    if ( a.size() > b.size() )
    {
        k = a.size()-b.size();
        for ( int i = 0 ; i < k ; i++ )
        {
            b.insert(0,"0");
        }
    }
    else
    {
        k = b.size()-a.size();
        for ( int i = 0 ; i < k ; i++ )
        {
            a.insert(0,"0");
        }
    }
    vector<long long> vect;
    vect.clear();
    int qw=0;
    for ( int i = a.size()-1 ; i >= 0 ; i-- )
    {
        vect.push_back((a[i]-'0')+(b[i]-'0'));
    }
    for ( int i = 0 ; i < vect.size() ; i++ )
    {
        if ( vect[i] > 9 )
        {
            if ( i == vect.size()-1 )
            {
                vect.push_back(vect[i]/10);
                vect[i] %= 10;
                break;
            }
            vect[i+1] += (vect[i]/10);
            vect[i] %= 10;
        }
    }
    string res;
    res.resize(vect.size());
    for ( int i = 0 ; i < vect.size() ; i++ )
    {
        res[i] = (vect[i]+'0');
    }
    res = string ( res.rbegin() , res.rend() );
    return res;
}
string multiply( string a , string b )
{
    vector<int> vect[7000];
    for ( int i = a.size()-1 ; i >= 0 ; i-- )
    {
        for ( int u = 0 ; u < a.size()-i-1 ; u++ )
            vect[a.size()-i-1].push_back(0);
        for ( int j = b.size()-1 ; j >= 0 ; j-- )
        {
            vect[a.size()-i-1].push_back((a[i]-'0')*(b[j]-'0'));
        }
        for ( int u = 0 ; u < vect[a.size()-i-1].size() ; u++ )
        {
            if ( vect[a.size()-i-1][u] > 9 )
            {
                if ( u == vect[a.size()-i-1].size()-1 )
                {
                    vect[a.size()-i-1].push_back(vect[a.size()-i-1][u]/10);
                    vect[a.size()-i-1][u] = vect[a.size()-i-1][u]%10;
                    break;
                }
                vect[a.size()-i-1][u+1] += (vect[a.size()-i-1][u]/10);
                vect[a.size()-i-1][u] = vect[a.size()-i-1][u]%10;
            }
        }
    }
    string res[7000];
    for ( int i = 0 ; i < a.size() ; i++ )
    {
        for ( int p = vect[i].size()-1 ; p >= 0  ; p-- )
        {
            string h;
            h += (vect[i][p]+'0');
            res[i].append(h);
        }
    }
    string ans= "0";
    for ( int i = 0 ; i < a.size() ; i++ )
    {
        ans = sum(ans,res[i]);
    }
    return ans;
}
long long rec1(long long n)
{
    long long ans = 0;
    if ( n == 1 )
    {
        for ( int i = 0 ; i < 10 ; i++ )
        {
            if ( i != 0 )
                ans++;
        }
    }
    else if ( n == 2 )
    {
        for ( int i = 0 ; i < 10 ; i++ )
        {
            for ( int k = 0 ; k < 10 ; k++ )
                if ( i != 0 && i != k )
                    ans++;
        }
    }
    else if ( n == 3 )
    {
        for ( int i = 0 ; i < 10 ; i++ )
            for ( int k = 0 ; k < 10 ; k++ )
                for ( int c = 0 ; c < 10 ; c++ )
                    if ( i != 0 && i != k && i != c && k != c )
                        ans++;
    }
    else if ( n == 4 )
    {
        for ( int i = 0 ; i < 10 ; i++ )
            for ( int k = 0 ; k < 10 ; k++ )
                for ( int c = 0 ; c < 10 ; c++ )
                    for ( int d = 0 ; d < 10 ; d++ )
                        if ( i != 0 && i != k && i != c && i != d && k != c && k != d && c != d )
                            ans++;
    }
    else if ( n == 5 )
    {
        for ( int i = 0 ; i < 10 ; i++ )
            for ( int k = 0 ; k < 10 ; k++ )
                for ( int c = 0 ; c < 10 ; c++ )
                    for ( int d = 0 ; d < 10 ; d++ )
                        for ( int e = 0 ; e < 10 ; e++ )
                            if ( i != 0 && i != k && i != c && i != d && i != e && k != c && k != d && k != e && c != d && c != e && d != e )
                                ans++;
    }
    else if ( n == 6 )
    {
        for ( int i = 0 ; i < 10 ; i++ )
            for ( int k = 0 ; k < 10 ; k++ )
                for ( int c = 0 ; c < 10 ; c++ )
                    for ( int d = 0 ; d < 10 ; d++ )
                        for ( int e = 0 ; e < 10 ; e++ )
                            for ( int f = 0 ; f < 10 ; f++ )
                                if ( i != 0 && i != k && i != c && i != d && i != e && i != f && k != c && k != d && k != e && k != f && c != d && c != e && c != f && d != e && d != f && e != f )
                                    ans++;
    }
    else if ( n == 7 )
    {
        for ( int i = 1 ; i < 10 ; i++ )
            for ( int k = 0 ; k < 10 ; k++ )
                for ( int c = 0 ; c < 10 ; c++ )
                    for ( int d = 0 ; d < 10 ; d++ )
                        for ( int e = 0 ; e < 10 ; e++ )
                            for ( int f = 0 ; f < 10 ; f++ )
                                for ( int g = 0 ; g < 10 ; g++ )
                                    if (  i != k && i != c && i != d && i != e && i != f && i != g && k != c && k != d && k != e && k != f && k != g && c != d && c != e && c != f && c != g && d != e && d != f && d != g && e != f && e != g && f != g)
                                        ans++;
    }
    else if ( n == 8 )
    {
        ans = 1632960;
        
    }
    else if ( n == 9 )
    {
        ans = 3265920;
        
    }
    else if ( n == 10 )
    {
        ans = 3265920;
        
    }
    return ans;
}
long long rec(long long n)
{
    long long ans = 0;
    if ( n == 1 )
    {
        for ( int i = 0 ; i < 10 ; i++ )
        {
                ans++;
        }
    }
    else if ( n == 2 )
    {
        for ( int i = 0 ; i < 10 ; i++ )
        {
            for ( int k = 0 ; k < 10 ; k++ )
                if (  i != k )
                    ans++;
        }
    }
    else if ( n == 3 )
    {
        for ( int i = 0 ; i < 10 ; i++ )
            for ( int k = 0 ; k < 10 ; k++ )
                for ( int c = 0 ; c < 10 ; c++ )
                    if (  i != k && i != c && k != c )
                        ans++;
    }
    else if ( n == 4 )
    {
        for ( int i = 0 ; i < 10 ; i++ )
            for ( int k = 0 ; k < 10 ; k++ )
                for ( int c = 0 ; c < 10 ; c++ )
                    for ( int d = 0 ; d < 10 ; d++ )
                        if (  i != k && i != c && i != d && k != c && k != d && c != d )
                            ans++;
    }
    else if ( n == 5 )
    {
        for ( int i = 0 ; i < 10 ; i++ )
            for ( int k = 0 ; k < 10 ; k++ )
                for ( int c = 0 ; c < 10 ; c++ )
                    for ( int d = 0 ; d < 10 ; d++ )
                        for ( int e = 0 ; e < 10 ; e++ )
                            if (  i != k && i != c && i != d && i != e && k != c && k != d && k != e && c != d && c != e && d != e )
                                ans++;
    }
    else if ( n == 6 )
    {
        for ( int i = 0 ; i < 10 ; i++ )
            for ( int k = 0 ; k < 10 ; k++ )
                for ( int c = 0 ; c < 10 ; c++ )
                    for ( int d = 0 ; d < 10 ; d++ )
                        for ( int e = 0 ; e < 10 ; e++ )
                            for ( int f = 0 ; f < 10 ; f++ )
                                if (  i != k && i != c && i != d && i != e && i != f && k != c && k != d && k != e && k != f && c != d && c != e && c != f && d != e && d != f && e != f )
                                    ans++;
    }
    else if ( n == 7 )
    {
        for ( int i = 0 ; i < 10 ; i++ )
            for ( int k = 0 ; k < 10 ; k++ )
                for ( int c = 0 ; c < 10 ; c++ )
                    for ( int d = 0 ; d < 10 ; d++ )
                        for ( int e = 0 ; e < 10 ; e++ )
                            for ( int f = 0 ; f < 10 ; f++ )
                                for ( int g = 0 ; g < 10 ; g++ )
                                    if (  i != k && i != c && i != d && i != e && i != f && i != g && k != c && k != d && k != e && k != f && k != g && c != d && c != e && c != f && c != g && d != e && d != f && d != g && e != f && e != g && f != g)
                                        ans++;
    }
    else if ( n == 8 )
    {
        ans = 1814400;
        
    }
    else if ( n == 9 )
    {
        ans = 3628800;
        
    }
    else if ( n == 10 )
    {
        ans = 3628800;
        
    }
    return ans;
}
int main()
{
    

    

    string x;
    

    while ( cin >> x )
    {
        string ans = "1";

        
        
        int vis[101];
        for ( int i = 0 ; i < 101 ; i++ )
            vis[i] = 0;

        long long CHn = 0;
        long long F = 0;
        for ( int i = 0 ; i < x.size() ; i++ )
        {
            if ( (x[i] >= 'A' && x[i] <= 'J')&& i != 0 && !vis[x[i]-'A'] )
            {
                CHn++;
                vis[x[i]-'A'] = 1;
                

            }
            else if ( (x[i] >= 'A' && x[i] <= 'J') && i == 0 && !vis[x[i]-'A'] )
            {
                F++;
                vis[x[i]-'A'] = 1;
                

            }
        }
        long long Zeros = 0;
        if ( x[0] == '\?' )
            ans = "9";
        for ( int i = 1 ; i < x.size() ; i++ )
        {
            if ( x[i] == '\?' )
            {
                Zeros++;
            }
            
        }
        if ( F!=0 )
        {
            

            ans = multiply(id0(rec1(F+CHn)),ans);
        }
        else if ( CHn > 0 )
        {
            

            ans = multiply(id0(rec(CHn)),ans);
        }
        
        printf("%s",ans.c_str()); for ( int i = 0 ; i < Zeros ; i++ ) printf("%c",'0');
        cout<<endl;
    }
    return 0;
}