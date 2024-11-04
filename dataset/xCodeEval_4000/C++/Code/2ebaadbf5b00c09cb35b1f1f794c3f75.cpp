#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>

#define CPATH "c:\\Users\\alexey\\Documents\\Visual Studio 2012\\Projects\\ContestTsogu_17_01_2014\\Debug\\"
#define _CRT_SECURE_NO_WARNINGS

const int maxFileNameLength = 256;



class A
{
public:
    A(void);
    ~A(void);

    void solve();

    void testgen();

private:
    
    bool solver(int x);

    char * answer(bool ans);
};

A::A(void)
{
}

A::~A(void)
{
}

void A::testgen()
{
    int length = 20;
    int map[20] = { 8, 5, 4, 3, 2, 1, 7, 6, 10, 9, 53, 77, 32, 44, 98, 99, 90, 67, 100, 88 };

    for(int i = 0;i < length;i++)
    {
        char * fileName = new char[maxFileNameLength];
        sprintf_s(fileName, maxFileNameLength, "%sA\\inp\\input%d.txt", CPATH, i);

        FILE * fd;
        fopen_s(&fd, fileName, "w+");
        fprintf_s(fd, "%d", map[i]);
        fclose(fd);

        sprintf_s(fileName, maxFileNameLength, "%sA\\out\\output%d.txt", CPATH, i);
        

        fopen_s(&fd, fileName, "w+");
        fprintf_s(fd, "%s", this->answer(this->solver(map[i])));
        fclose(fd);

        delete fileName;
    }
}

void A::solve()
{
    int x = 0;

    

    scanf_s("%d", &x);
    printf("%s", this->answer(this->solver(x)));
}

bool A::solver(int x)
{
    return x % 2 == 0 && x != 2;
}

char * A::answer(bool ans)
{
    return ans ? "YES" : "NO";
}



class B
{
public:
    B(void);
    ~B(void);

    void solve();

    void testgen();

private:

    char * solver(char *);
};

B::B() {};
B::~B() {};
void B::solve() 
{
    char * x = new char[110];
    memset(x, 0, 110);
    scanf("%s", x);
    char * res = this->solver(x);
    printf("%s", res);

    delete res;
    delete x;
}
char * B::solver(char * x)
{
    int l = strlen(x);
    char * res = new char[2 * l + 1];
    int j = 0;
    for(int i = 0;i < l;i++)
    {
        char c = x[i];
        char upperC = toupper(c);
        if (upperC == 'A' || upperC == 'O' || upperC == 'Y' || upperC == 'E' || upperC == 'U' || upperC == 'I')
        {
            continue;
        }

        res[j] = '.';
        res[j + 1] = tolower(c);
        j += 2;
    }
    res[j] = 0;
    return res;
}
void B::testgen()
{
    int length = 42;
    char * inputs[42] = {
        "tour",
        "Codeforces",
        "aBAcAba",
        "obn",
        "wpwl",
        "ggdvq",
        "pumesz",
        "g",
        "zjuotps",
        "jzbwuehe",
        "tnkgwuugu",
        "kincenvizh",
        "xattxjenual",
        "ktajqhpqsvhw",
        "xnhcigytnqcmy",
        "jfmtbejyilxcec",
        "D",
        "ab",
        "Ab",
        "aB",
        "AB",
        "ba",
        "bA",
        "Ba",
        "BA",
        "aab",
        "baa",
        "femOZeCArKCpUiHYnbBPTIOFmsHmcpObtPYcLCdjFrUMIyqYzAokKUiiKZRouZiNMoiOuGVoQzaaCAOkquRjmmKKElLNqCnhGdQM",
        "VMBPMCmMDCLFELLIISUJDWQRXYRDGKMXJXJHXVZADRZWVWJRKFRRNSAWKKDPZZLFLNSGUNIVJFBEQsMDHSBJVDTOCSCgZWWKvZZN",
        "MCGFQQJNUKuAEXrLXibVjClSHjSxmlkQGTKZrRaDNDomIPOmtSgjJAjNVIVLeUGUAOHNkCBwNObVCHOWvNkLFQQbFnugYVMkJruJ",
        "iyaiuiwioOyzUaOtAeuEYcevvUyveuyioeeueoeiaoeiavizeeoeyYYaaAOuouueaUioueauayoiuuyiuovyOyiyoyioaoyuoyea",
        "yjnckpfyLtzwjsgpcrgCfpljnjwqzgVcufnOvhxplvflxJzqxnhrwgfJmPzifgubvspffmqrwbzivatlmdiBaddiaktdsfPwsevl",
        "RIIIUaAIYJOiuYIUWFPOOAIuaUEZeIooyUEUEAoIyIHYOEAlVAAIiLUAUAeiUIEiUMuuOiAgEUOIAoOUYYEYFEoOIIVeOOAOIIEg",
        "VBKQCFBMQHDMGNSGBQVJTGQCNHHRJMNKGKDPPSQRRVQTZNKBZGSXBPBRXPMVFTXCHZMSJVBRNFNTHBHGJLMDZJSVPZZBCCZNVLMQ",
        "iioyoaayeuyoolyiyoeuouiayiiuyTueyiaoiueyioiouyuauouayyiaeoeiiigmioiououeieeeyuyyaYyioiiooaiuouyoeoeg",
        "ueyiuiauuyyeueykeioouiiauzoyoeyeuyiaoaiiaaoaueyaeydaoauexuueafouiyioueeaaeyoeuaueiyiuiaeeayaioeouiuy",
        "FSNRBXLFQHZXGVMKLQDVHWLDSLKGKFMDRQWMWSSKPKKQBNDZRSCBLRSKCKKFFKRDMZFZGCNSMXNPMZVDLKXGNXGZQCLRTTDXLMXQ",
        "EYAYAYIOIOYOOAUOEUEUOUUYIYUUMOEOIIIAOIUOAAOIYOIOEUIERCEYYAOIOIGYUIAOYUEOEUAEAYPOYEYUUAUOAOEIYIEYUEEY",
        "jvvzcdcxjstbbksmqjsngxkgtttdxrljjxtwptgwwqzpvqchvgrkqlzxmptzblxhhsmrkmzzmgdfskhtmmnqzzflpmqdctvrfgtx",
        "YB",
        "fly",
        "YyyYYYyyYxdwdawdDAWDdaddYYYY" 
    };

    for(int i = 0;i < length;i++)
    {
        char * fileName = new char[maxFileNameLength];
        sprintf_s(fileName, maxFileNameLength, "%sB\\inp\\input%d.txt", CPATH, i);

        FILE * fd;
        fopen_s(&fd, fileName, "w+");
        fprintf_s(fd, "%s", inputs[i]);
        fclose(fd);

        sprintf_s(fileName, maxFileNameLength, "%sB\\out\\output%d.txt", CPATH, i);
        

        fopen_s(&fd, fileName, "w+");
        char * res = this->solver(inputs[i]);
        fprintf_s(fd, "%s", res);
        delete res;
        fclose(fd);

        delete fileName;
    }
}

class C
{
public:
    C(void);
    ~C(void);

    void solve();
    void testgen();
private:
    int solver(int, int *);
};

C::C() {}
C::~C() {}
int C::solver(int n, int * a)
{
    std::sort(a, a + n);

    int totalSumm = 0;
    for(int i = 0;i < n;i++)
    {
        totalSumm += a[i];
    }

    int ans = 0;
    int ansSum = 0;
    while(ansSum <= (totalSumm - ansSum))
    {
        ans++;
        ansSum += a[n - ans];
    }

    return ans;
}
void C::solve()
{
    int n = 0;
    scanf("%d", &n);
    int * x = new int[n];
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &x[i]);
    }

    printf("%d", this->solver(n, x));
}
void C::testgen()
{
    int length = 29 * 2;
    char * inputs[29 * 2] = {
        "2",
        "3 3",
        "3 ",
        "2 1 2",
        "1 ",
        "5",
        "5",
        "4 2 2 2 2",
        "7 ",
        "1 10 1 2 1 1 1",
        "5 ",
        "3 2 3 3 1",
        "2",
        "2 1",
        "3",
        "2 1 3",
        "6",
        "1 1 1 1 1 1",
        "7",
        "10 10 5 5 5 5 1",
        "20",
        "2 1 2 2 2 1 1 2 1 2 2 1 1 1 1 2 1 1 1 1",
        "20",
        "4 2 4 4 3 4 2 2 4 2 3 1 1 2 2 3 3 3 1 4",
        "20",
        "35 26 41 40 45 46 22 26 39 23 11 15 47 42 18 15 27 10 45 40",
        "20",
        "7 84 100 10 31 35 41 2 63 44 57 4 63 11 23 49 98 71 16 90",
        "50",
        "19 2 12 26 17 27 10 26 17 17 5 24 11 15 3 9 16 18 19 1 25 23 18 6 2 7 25 7 21 25 13 29 16 9 25 3 14 30 18 4 10 28 6 10 8 2 2 4 8 28",
        "70",
        "2 18 18 47 25 5 14 9 19 46 36 49 33 32 38 23 32 39 8 29 31 17 24 21 10 15 33 37 46 21 22 11 20 35 39 13 11 30 28 40 39 47 1 17 24 24 21 46 12 2 20 43 8 16 44 11 45 10 13 44 31 45 45 46 11 10 33 35 23 42",
        "100",
        "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1",
        "100",
        "1 2 2 1 2 1 1 2 1 1 1 2 2 1 1 1 2 2 2 1 2 1 1 1 1 1 2 1 2 1 2 1 2 1 2 1 1 1 2 1 1 1 1 1 2 2 1 2 1 2 1 2 2 2 1 2 1 2 2 1 1 2 2 1 1 2 2 2 1 1 2 1 1 2 2 1 2 1 1 2 2 1 2 1 1 2 2 1 1 1 1 2 1 1 1 1 2 2 2 2",
        "100",
        "1 2 3 2 1 2 2 3 1 3 3 2 2 1 1 2 2 1 1 1 1 2 3 3 2 1 1 2 2 2 3 3 3 2 1 3 1 3 3 2 3 1 2 2 2 3 2 1 1 3 3 3 3 2 1 1 2 3 2 2 3 2 3 2 2 3 2 2 2 2 3 3 3 1 3 3 1 1 2 3 2 2 2 2 3 3 3 2 1 2 3 1 1 2 3 3 1 3 3 2",
        "100",
        "5 5 4 3 5 1 2 5 1 1 3 5 4 4 1 1 1 1 5 4 4 5 1 5 5 1 2 1 3 1 5 1 3 3 3 2 2 2 1 1 5 1 3 4 1 1 3 2 5 2 2 5 5 4 4 1 3 4 3 3 4 5 3 3 3 1 2 1 4 2 4 4 1 5 1 3 5 5 5 5 3 4 4 3 1 2 5 2 3 5 4 2 4 5 3 2 4 2 4 3",
        "100",
        "3 4 8 10 8 6 4 3 7 7 6 2 3 1 3 10 1 7 9 3 5 5 2 6 2 9 1 7 4 2 4 1 6 1 7 10 2 5 3 7 6 4 6 2 8 8 8 6 6 10 3 7 4 3 4 1 7 9 3 6 3 6 1 4 9 3 8 1 10 1 4 10 7 7 9 5 3 8 10 2 1 10 8 7 10 8 5 3 1 2 1 10 6 1 5 3 3 5 7 2",
        "100",
        "16 9 11 8 11 4 9 17 4 8 4 10 9 10 6 3 3 15 1 6 1 15 12 18 6 14 13 18 1 7 18 4 10 7 10 12 3 16 14 4 10 8 10 7 19 13 15 1 4 8 16 10 6 4 3 16 11 10 7 3 4 16 1 20 1 11 4 16 10 7 7 12 18 19 3 17 19 3 4 19 2 12 11 3 18 20 2 2 14 4 20 13 13 11 16 20 19 14 7 2",
        "100",
        "2 46 4 6 38 19 15 34 10 35 37 30 3 25 5 45 40 45 33 31 6 20 10 44 11 9 2 14 35 5 9 23 20 2 48 22 25 35 38 31 24 33 35 16 4 30 27 10 12 22 6 24 12 30 23 21 14 12 32 21 7 12 25 43 18 34 34 28 47 13 28 43 18 39 44 42 35 26 35 14 8 29 32 20 29 3 20 6 20 9 9 27 8 42 10 37 42 27 8 1",
        "100",
        "85 50 17 89 65 89 5 20 86 26 16 21 85 14 44 31 87 31 6 2 48 67 8 80 79 1 48 36 97 1 5 30 79 50 78 12 2 55 76 100 54 40 26 81 97 96 68 56 87 14 51 17 54 37 52 33 69 62 38 63 74 15 62 78 9 19 67 2 60 58 93 60 18 96 55 48 34 7 79 82 32 58 90 67 20 50 27 15 7 89 98 10 11 15 99 49 4 51 77 52",
        "100",
        "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100",
        "1",
        "1",
        "4",
        "4 1 2 3",
        "5",
        "2 2 2 4 4",
        "4",
        "100 99 99 100"
    };

    for(int i = 0;i < length;i += 2)
    {
        char * fileName = new char[maxFileNameLength];
        sprintf_s(fileName, maxFileNameLength, "%sC\\inp\\input%d.txt", CPATH, i / 2);

        FILE * fd;
        fopen_s(&fd, fileName, "w+");
        fprintf_s(fd, "%s\n%s", inputs[i], inputs[i + 1]);
        fclose(fd);

        fopen_s(&fd, fileName, "r");
        int n = 0;
        fscanf(fd, "%d", &n);
        int * x = new int[n];
        for (int j = 0;j < n;j++)
        {
            fscanf(fd, "%d", &x[j]);
        }

        sprintf_s(fileName, maxFileNameLength, "%sC\\out\\output%d.txt", CPATH, i / 2);
        

        fopen_s(&fd, fileName, "w+");
        fprintf_s(fd, "%d", this->solver(n, x));
        delete x;
        fclose(fd);

        delete fileName;
    }
}

class D
{
public:
    D(void);
    ~D(void);

    void solve();
    void testgen();
private:
    int solver(char *);
};

D::D() {}
D::~D() {}
int D::solver(char * x)
{
    int ans = 0;
    int length = strlen(x);
    bool * used = new bool[length];
    memset(used, 0, length);
    
    for(int i = 0; i < length; i++)
    {
        bool found = false;
        for(int j = i - 1;j >= 0;j--)
        {
            if (!used[j] && ((x[i] == '-' && x[j] == '+') || (x[j] == '-' && x[i] == '+')))
            {
                used[j] = true;
                found = true;
                break;
            }
        }

        if (!found)
        {
            ans++;
        }
    }

    return ans;
}
void D::solve()
{
    char x[310];
    memset(x, 0, 310);
    scanf("%s", x);
    printf("%d", this->solver(x));
}
void D::testgen()
{
    int length = 30;
    char * input[30] = {
        "+-+-+",
        "---",
        "-",
        "--",
        "---",
        "----",
        "---+",
        "--+-",
        "--++",
        "-+--",
        "-++",
        "-++-",
        "+",
        "+-",
        "+--",
        "+--+",
        "++--",
        "-+++--+-++--+-+--+-+",
        "++-++--+++++-+++++---+++-++-++-",
        "----+-+--++---++---++-+-----+--",
        "-+++---+++++++++++++-++-++++++-++-+-+++-",
        "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++",
        "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------",
        "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++-+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++",
        "++++++++++++++++++++-+++++++++++++++++++++++++++++++++++++++++++++++++++++++-+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++",
        "+++++++++++++++++++++++++++++++++++++++++-++++++++-++++++++++++-+++++++++++++++++++++++++++++++++++++++++++++++++++++-+++++++++++++++++++++++++-++++++++++++++++++++++++-++++-+++++++++++++-++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++-+++-+++++++++++++++++",
        "++++-+---+++--++++-++-++++++++-++-++++-++++++-+-+-+++--+-++++++-+++-++-+++-++++-++++-+-+----+++++---++++-+---+++--+++++-+++-+-++++++----+--+++++++++-+--+++-+-+-++++++--+-+-+-+-++--+-+-----++++++-+++-++--+++++++++---+-++++++-++-++++-+--+-++-++++-+-+--++-+--+++-+-++++++++++++-+++-+----++++++++--+-+-++",
        "+----++-----+----+++--++---+++--+-++++-++---++++++--++++--++-++--++--++----++++---+--+++----++--++--++--+--++++++++--++--+++----+++----++----++-+--+---+--+-++--+--+--+-+--+---++-+-++--+++++-++------+++-++--+--+--+++++++--++-+--+-+--++++-++--+---+-+-++-+-++----+-++++++-+++--+----++-+--++-----+++-++-+",
        "-+++----+-++--+-+----+--+++++----+---+-++-+---+++--+---++-+-----+----+------+--+----++-++-----+++--+---+-+-----++++------+--+-----++---+---+---+-++------++++--+-+-------------+---+--+-+--------++---+-++---+-----+++--+---+-++-+---+-+---+++--++-----++------+----+---+---+--+-+-++-+---++--------+----++",
        "----------+-----------------------------------------------------------+-+-------------+--------------------------------------------------------------------------------+--+-----+-+-------------------------------------------+-----------------------------------------------------------------+-----------"
    };

    for(int i = 0;i < length;i++)
    {
        char * fileName = new char[maxFileNameLength];
        sprintf_s(fileName, maxFileNameLength, "%sD\\inp\\input%d.txt", CPATH, i);

        FILE * fd;
        fopen_s(&fd, fileName, "w+");
        fprintf_s(fd, "%s", input[i]);
        fclose(fd);

        sprintf_s(fileName, maxFileNameLength, "%sD\\out\\output%d.txt", CPATH, i);
        

        fopen_s(&fd, fileName, "w+");
        fprintf_s(fd, "%d", this->solver(input[i]));
        fclose(fd);

        delete fileName;
    }
}

class E
{
public:
    E(void);
    ~E(void);

    int p[5010][5010];
    int sum[5010][5010];
    char x[50010][5010];

    void solve();
    void testgen();
private:
};

E::E() {}
E::~E() {}
void E::solve()
{
    

    

    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0;i < n;i++)
    {
        scanf("%s", x[i]);
    }
    
    int ans = 0;

    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < n;j++)
        {
            if (x[j][i] == '1')
            {
                if (i - 1 >= 0)
                {
                    p[i][j] = p[i - 1][j] + 1;
                }
                else
                {
                    p[i][j] = 1;
                }
            }
            else
            {
                p[i][j] = 0;
            }
        }
    }

    for(int i = 0;i < m;i++)
    {
        int temp = 0;
        int start = 0;
        for(int j = 0;j < n;j++)
        {
            sum[i][p[i][j]]++;
            start = p[i][j] > start ? p[i][j] : start;
        }

        int j1 = 0;
        for(int j = start;j >= 0;j--)
        {
            int h = sum[i][j] * j + temp * j;
            if (ans < h)
            {
                ans = h;
            }
            temp += sum[i][j];
        }
    }
    
    printf("%d", ans);
}

E e;

int main() 
{
    

    

    

    

    


    

    

    

    


    

    

    

    


    

    

    

    


    e.solve();
    


    return 0;
}