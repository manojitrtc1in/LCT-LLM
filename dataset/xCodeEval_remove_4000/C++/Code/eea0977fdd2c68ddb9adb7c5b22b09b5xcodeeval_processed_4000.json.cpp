








using namespace std;


class id11
{
    

    

public:
    int N;
    vector<LL> dp;
public:
    class Line
    {
    public:
        LL m,c;
        LL domination;  

        Line(LL slope,LL intercept): m(slope), c(intercept), domination(999999999999999999) {}
        Line(): m(0),c(0),domination(999999999999999999) {}
    private:
        LL phawinDivision(LL a,LL b)    

        {
            if(b<0) return phawinDivision(-a,-b);
            if(a>0) return a/b;
            if((-a)%b==0) return a/b;
            return (a/b)-1;
        }
    public:
        LL getNewDominationLimit(Line &l2)  

        {
            

            LL ret = phawinDivision(l2.c-c,m-l2.m);
            

            if((l2.c-c)%(m-l2.m)==0) ret--;
            return ret;
        }
        void setNewDominationLimit(Line &l2)
        {
            domination = getNewDominationLimit(l2);
        }
    };

    const Line DUMMY_LINE = Line(0,-999999999999999999); 

public:
    

    virtual LL getStaticConstant(int idx) = 0;  

    virtual LL getLineConstant(int idx) = 0;    

    virtual LL getLineSlope(int idx) = 0;       

    virtual LL getLineArgument(int idx) = 0;    

    virtual void additionalPreProcess(deque<Line> &lineBank) = 0;
public:
    id11(int n): N(n), dp(vector<LL>(n+7)) {}
public:

    

    void dynamicProgrammingProcessing()
    {
        deque<Line> lineBank;
        lineBank.push_front(DUMMY_LINE);
        additionalPreProcess(lineBank);

        for(int i=0;i<N;i++)
        {
            

            LL x = getLineArgument(i);
            

            while(lineBank.size()>1 && x>lineBank.back().domination) lineBank.pop_back();
            

            dp[i] = getStaticConstant(i) + lineBank.back().c + (lineBank.back().m * x);

            


            Line newLine(getLineSlope(i),getLineConstant(i));
            


            if(!lineBank.empty() && newLine.m == lineBank.front().m)
            {
                if(newLine.c > lineBank.front().c)
                {
                    lineBank.pop_front();
                    lineBank.push_front(newLine);
                }
            }
            else
            {
                while(!lineBank.empty())
                {
                    int z = lineBank.size();
                    LL ifDom = lineBank.front().getNewDominationLimit(newLine);

                    LL id13 = -999999999999999;
                    if(z>=2) id13 = lineBank[1].domination+1;

                    if(ifDom>=id13) break;
                    lineBank.pop_front();
                }
                lineBank.front().setNewDominationLimit(newLine);
                lineBank.push_front(newLine);
            }


        }
    }

};




class id9: public id11
{
public:
    LL a,b,c;
    vector<LL> ps;
public:
    LL getStaticConstant(int idx)
    {
        return a*ps[idx]*ps[idx] + b*ps[idx] + c;
    }
    LL getLineConstant(int idx)
    {
        return dp[idx] + a*ps[idx]*ps[idx] - b*ps[idx];
    }
    LL getLineSlope(int idx)
    {
        return -2*a*ps[idx];
    }
    LL getLineArgument(int idx)
    {
        return ps[idx];
    }
    void additionalPreProcess(deque<Line> &lineBank)
    {
        lineBank.pop_front();
        lineBank.push_front(Line(0,0));
    }
public:
    id9(int n,LL A,LL B,LL C,vector<LL> s): id11(n), a(A), b(B), c(C)
    {
        

        

        ps = s; for(int i=1;i<n;i++) ps[i] = ps[i-1] + s[i];
        

    }

    LL getAnswer()
    {
        

        

        dynamicProgrammingProcessing();
        return dp[N-1];
    }
};

class id12
{
public:
    vector<LL> ps;
    LL a,b,c;
    int n;

    id12(int N,LL A,LL B,LL C,vector<LL> s): n(N),a(A),b(B),c(C)
    {
        ps = s;
        for(int i=1;i<n;i++) ps[i] = ps[i-1] + s[i];
    }

private:
    LL f(LL x)
    {
        return a*x*x + b*x + c;
    }

public:
    LL getAnswer()
    {
        vector<LL> dp(n);
        dp[0] = f(ps[0]);
        for(int i=1;i<n;i++)
        {
            dp[i] = f(ps[i]);
            for(int j=0;j<i;j++) dp[i] = max(dp[i],dp[j]+f(ps[i]-ps[j]));
        }
        return dp[n-1];
    }
};


int id3() 

{
    int tc; scanf("%d",&tc);
    while(tc--)
    {
        int n; scanf("%d",&n);
        LL a,b,c; scanf("%lld%lld%lld",&a,&b,&c);
        vector<LL> s(n); for(int i=0;i<n;i++) scanf("%lld",&s[i]);
        id9 solver(n,a,b,c,s);
        LL ans = solver.getAnswer();
        printf("%lld\n",ans);
    }
    return 0;
}

class id5
{
public:
    int n;
    vector<LL> a,b;
public:
    id5(int N,vector<LL> A,vector<LL> B): n(N), a(A), b(B){}
    LL getAnswer()
    {
        vector<LL> dp(n);
        dp[0] = 0;
        for(int i=1;i<n;i++)
        {
            dp[i] = -999999999999999999;
            for(int j=0;j<i;j++) dp[i] = max(dp[i],dp[j]-a[i]*b[j]);
        }
        return -dp[n-1];
    }
};

class id0: public id11
{
public:
    vector<LL> a,b;
public:
    id0(int N,vector<LL> A,vector<LL> B): id11(N), a(A), b(B) {}
    LL getStaticConstant(int idx)
    {
        return 0;
    }
    LL getLineConstant(int idx)
    {
        return dp[idx];
    }
    LL getLineSlope(int idx)
    {
        return -b[idx];
    }
    LL getLineArgument(int idx)
    {
        return a[idx];
    }
    void additionalPreProcess(deque<Line> &lineBank)
    {
        lineBank.pop_front();
        lineBank.push_front(Line(0,0));
    }

    LL getAnswer()
    {
        dynamicProgrammingProcessing();
        return -dp[N-1];
    }

};

int id2()
{
    int n; scanf("%d",&n);
    vector<LL> a(n);
    vector<LL> b(n);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    for(int i=0;i<n;i++) scanf("%lld",&b[i]);

    

    id0 solver(n,a,b);
    LL ans = solver.getAnswer();
    printf("%I64d\n",ans);

}




LL id7(int n,int m,int p,vector<LL> d,vector<int> h,vector<LL> t)
{
    

    vector<LL> a(n);
    a[0] = 0;
    for(int i=1;i<n;i++) a[i] = a[i-1] + d[i-1];
    vector<LL> wishList;
    for(int i=0;i<m;i++)   wishList.push_back(t[i]-a[h[i]-1]);  

    sort(wishList.begin(),wishList.end());
    vector<LL> ps(m);
    ps[0] = wishList[0];
    for(int i=1;i<m;i++) ps[i] = ps[i-1] + wishList[i];

    



    

    vector<vector<LL>> dp(p+7,vector<LL>(m+7,999999999999999999));
    

    for(int i=0;i<m;i++)
    {
        dp[1][i] = wishList[i]*(i+1) - ps[i];
        

    }
    

    for(int f=2;f<=p;f++)
    {
        for(int i=0;i<m;i++)
        {

            for(int j=0;j<i;j++) dp[f][i] = min(dp[f][i],dp[f-1][j] + (i-j)*wishList[i] - (ps[i]-ps[j]));
            

        }
    }
    

    return dp[p][m-1];
}

class id1: public id11
{
public:
    vector<LL> t;
    vector<LL> ps;
    vector<LL> lastDP;
public:
    LL getStaticConstant(int idx)
    {
        return -idx*t[idx]+ps[idx];
    }
    LL getLineConstant(int idx)
    {
        return lastDP[idx]-ps[idx];
    }
    LL getLineSlope(int idx)
    {
        return idx;
    }
    LL getLineArgument(int idx)
    {
        return t[idx];
    }
    void additionalPreProcess(deque<Line> &lineBank)
    {
        lineBank.pop_front();
        lineBank.push_front(Line(0,-999999999999999));
    }
public:
    id1(int n,vector<LL> wishList,vector<LL> prefix,vector<LL> odp):id11(n),t(wishList),ps(prefix),lastDP(odp) {}

    vector<LL> getRow()
    {
        dynamicProgrammingProcessing();
        return dp;
    }
};


LL id8(int n,int m,int p,vector<LL> d,vector<int> h,vector<LL> t)
{
    

    vector<LL> a(n);
    a[0] = 0;
    for(int i=1;i<n;i++) a[i] = a[i-1] + d[i-1];
    vector<LL> wishList;
    for(int i=0;i<m;i++)   wishList.push_back(t[i]-a[h[i]-1]);  

    sort(wishList.begin(),wishList.end());
    vector<LL> ps(m);
    ps[0] = wishList[0];
    for(int i=1;i<m;i++) ps[i] = ps[i-1] + wishList[i];

    



    

    vector<vector<LL>> dp(p+7,vector<LL>(m+7,-999999999999999999));
    

    for(int i=0;i<m;i++)
    {
        dp[1][i] = -(wishList[i]*(i+1) - ps[i]);
        

    }
    

    for(int f=2;f<=p;f++)
    {
        

        id1 rowSolver(m,wishList,ps,dp[f-1]);
        

        dp[f] = rowSolver.getRow();
        

        

    }
    

    return -dp[p][m-1];
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
LL myRandom(LL L,LL R)
{
    uniform_int_distribution<mt19937_64::result_type> work(L,R);
    return work(rng);
}

bool id16()
{
    int n = 7;
    int m = 100;
    int p = 20;

    vector<LL> d(n-1); for(int i=0;i<n-1;i++) d[i] = myRandom(1,3);
    vector<int> h(m); for(int i=0;i<m;i++) h[i] = myRandom(1,n);
    vector<LL> t(m); for(int i=0;i<m;i++) t[i] = myRandom(1,10);

    

    

    

    

    


    LL sol = id7(n,m,p,d,h,t);
    

    LL opt = id8(n,m,p,d,h,t);

    if(sol==opt) return true;
    printf("WRONG ANSWER\n");
    printf("%d %d %d\n",n,m,p);
    for(int i=0;i<n-1;i++) printf("%I64d ",d[i]); printf("\n");
    for(int i=0;i<m;i++) printf("%d %I64d\n",h[i],t[i]);

    printf("\nExpected: %I64d Found: %I64d\n",sol,opt);
    return false;
}

int catDebugger()
{
    

    int tc = 10000;
    for(int t=1;t<=tc;t++)
    {
        fprintf(stderr,"Running on test %d/%d\n",t,tc);
        bool vd = id16();
        if(!vd) return 0;
    }
    printf("ALL CASES PASSED\n");
    return 0;
}

int id15()
{
    int n,m,p; scanf("%d%d%d",&n,&m,&p);
    vector<LL> d(n-1); for(int i=0;i<n-1;i++) scanf("%I64d",&d[i]);
    vector<int> h(m);
    vector<LL> t(m);
    for(int i=0;i<m;i++) scanf("%d%I64d",&h[i],&t[i]);

    LL ans = id8(n,m,p,d,h,t);  

    printf("%I64d\n",ans);
    return 0;
}




LL id4(int n,int k,vector<LL> w)
{
    vector<LL> psw(n);
    psw[0] = w[0]; for(int i=1;i<n;i++) psw[i] = psw[i-1] + w[i];
    vector<LL> psaw(n);
    psaw[0] = w[0]*0; for(int i=1;i<n;i++) psaw[i] = psaw[i-1] + w[i]*i;

    vector<vector<LL>> dp(k+1,vector<LL>(n+3,999999999999999999));
    

    for(int i=0;i<n;i++) dp[1][i] = psaw[i];
    

    for(int p=2;p<=k;p++)
    {
        for(int l=0;l<n;l++)
        {
            for(int i=0;i<l;i++) dp[p][l] = min(dp[p][l],dp[p-1][i]+(psaw[l]-psaw[i])-(i+1)*(psw[l]-psw[i]));
        }
    }
    return dp[k][n-1];
}

class id14: public id11
{
public:
    vector<LL> psw;
    vector<LL> psaw;
    vector<LL> lastDP;
public:
    LL getStaticConstant(int idx)
    {
        return -psaw[idx];
    }
    LL getLineConstant(int idx)
    {
        return lastDP[idx]-(idx+1)*psw[idx]+psaw[idx];
    }
    LL getLineSlope(int idx)
    {
        return idx+1;
    }
    LL getLineArgument(int idx)
    {
        return psw[idx];
    }
    void additionalPreProcess(deque<Line> &lineBank)
    {
        lineBank.pop_front();
        lineBank.push_front(Line(0,-999999999));
    }
public:
    id14(int n,vector<LL> PSW,vector<LL> PSAW,vector<LL> odp):id11(n),psw(PSW),psaw(PSAW),lastDP(odp) {}

    vector<LL> getRow()
    {
        dynamicProgrammingProcessing();
        return dp;
    }
};



LL id6(int n,int k,vector<LL> w) 

{
    vector<LL> psw(n);
    psw[0] = w[0]; for(int i=1;i<n;i++) psw[i] = psw[i-1] + w[i];
    vector<LL> psaw(n);
    psaw[0] = w[0]*0; for(int i=1;i<n;i++) psaw[i] = psaw[i-1] + w[i]*i;

    vector<vector<LL>> dp(k+1,vector<LL>(n+3,999999999999999999));
    

    for(int i=0;i<n;i++) dp[1][i] = -psaw[i];
    

    for(int p=2;p<=k;p++)
    {
        id14 rowSolver(n,psw,psaw,dp[p-1]);
        dp[p] = rowSolver.getRow();
    }
    return -dp[k][n-1];
}

int id10()
{
    int n,k; scanf("%d%d",&n,&k);
    vector<LL> w(n); for(int i=0;i<n;i++) scanf("%lld",&w[i]);
    LL ans = id6(n,k,w);
    printf("%lld\n",ans);
    return 0;
}

int main()
{
    

    return id15();
}


