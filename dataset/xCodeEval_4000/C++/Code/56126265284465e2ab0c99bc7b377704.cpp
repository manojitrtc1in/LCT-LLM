#include <bits/stdc++.h>
using namespace std;

pair <int,int> p[3],temp[2];
pair <string,double> Len[3];
set < pair <int,int> > st[4];
set < pair <int,int> > :: iterator itr;

bool compare(pair <string,double> n1,pair <string,double> n2)
{
    return n1.second<n2.second;
}

int index(set < pair <int,int> > st1[4])
{
    int MIN = st1[0].size();
    int j=0;
    for(int i=1;i<4;i++)
    {
        if(MIN>st1[i].size())
        {
            MIN = st1[i].size();
            j = i;
        }
    }
    return j;
}

int main()
{
    int x,y; double res; string s1,s2;
    for(int i=0;i<3;i++)
    {
        cin >> x >> y;
        p[i] = make_pair(x,y);
    }
    

    x = p[0].first - p[1].first;
    y = p[0].second - p[1].second;
    res = sqrt(x*x + y*y);
    Len[0].first = "AB";
    Len[0].second = res;
    

    x = p[0].first - p[2].first;
    y = p[0].second - p[2].second;
    res = sqrt(x*x + y*y);
    Len[1].first = "AC";
    Len[1].second = res;
    

    x = p[1].first - p[2].first;
    y = p[1].second - p[2].second;
    res = sqrt(x*x + y*y);
    Len[2].first = "BC";
    Len[2].second = res;

    int XA = p[0].first; int YA = p[0].second;
    int XB = p[1].first; int YB = p[1].second;
    int XC = p[2].first; int YC = p[2].second;

    sort(Len,Len+3,compare);

    

    if(Len[1].second==Len[2].second && (int)Len[0].second==Len[0].second)
    {
        s1 = Len[1].first;
        s2 = Len[2].first;
    }
    else
    {
        s1 = Len[0].first;
        s2 = Len[1].first;
    }
    

    if(s1[0]==s2[0])
    {
        

        int x1 = XA - XC;
        int y1 = YB - YC;
        double res1 = sqrt(x1*x1 + y1*y1);
        

        int x2 = XB - XC;
        int y2 = YA - YC;
        double res2 = sqrt(x2*x2 + y2*y2);
        

        {
            st[0].insert(make_pair(XA,YB));
            st[1].insert(make_pair(XA,YB));
            while(YA>YB)
            {
                st[0].insert(make_pair(XA,YA));
                st[1].insert(make_pair(XA,YA));
                YA--;
            }
            while(YA<YB)
            {
                st[0].insert(make_pair(XA,YA));
                st[1].insert(make_pair(XA,YA));
                YA++;
            }
            while(XB>XA)
            {
                st[0].insert(make_pair(XB,YB));
                st[1].insert(make_pair(XB,YB));
                XB--;
            }
            while(XB<XA)
            {
                st[0].insert(make_pair(XB,YB));
                st[1].insert(make_pair(XB,YB));
                XB++;
            }
        }
        

        XA = p[0].first; YA = p[0].second;
        XB = p[1].first; YB = p[1].second;
        XC = p[2].first; YC = p[2].second;
        {
            st[2].insert(make_pair(XB,YA));
            st[3].insert(make_pair(XB,YA));
            while(YA>YB)
            {
                st[2].insert(make_pair(XB,YB));
                st[3].insert(make_pair(XB,YB));
                YB++;
            }
            while(YA<YB)
            {
                st[2].insert(make_pair(XB,YB));
                st[3].insert(make_pair(XB,YB));
                YB--;
            }
            while(XB>XA)
            {
                st[2].insert(make_pair(XA,YA));
                st[3].insert(make_pair(XA,YA));
                XA++;
            }
            while(XB<XA)
            {
                st[2].insert(make_pair(XA,YA));
                st[3].insert(make_pair(XA,YA));
                XA--;
            }
        }
        XA = p[0].first; YA = p[0].second;
        XB = p[1].first; YB = p[1].second;
        XC = p[2].first; YC = p[2].second;
        

        x1 = XA - XB;
        y1 = YC - YB;
        res1 = sqrt(x1*x1 + y1*y1);
        

        x2 = XC - XB;
        y2 = YA - YB;
        res2 = sqrt(x2*x2 + y2*y2);

        

        {
            st[0].insert(make_pair(XA,YC));
            st[2].insert(make_pair(XA,YC));
            while(YA>YC)
            {
                st[0].insert(make_pair(XA,YA));
                st[2].insert(make_pair(XA,YA));
                YA--;
            }
            while(YA<YC)
            {
                st[0].insert(make_pair(XA,YA));
                st[2].insert(make_pair(XA,YA));
                YA++;
            }
            while(XC>XA)
            {
                st[0].insert(make_pair(XC,YC));
                st[2].insert(make_pair(XC,YC));
                XC--;
            }
            while(XC<XA)
            {
                st[0].insert(make_pair(XC,YC));
                st[2].insert(make_pair(XC,YC));
                XC++;
            }
        }
        

        XA = p[0].first; YA = p[0].second;
        XB = p[1].first; YB = p[1].second;
        XC = p[2].first; YC = p[2].second;
        {
            st[1].insert(make_pair(XC,YA));
            st[3].insert(make_pair(XC,YA));
            while(YA>YC)
            {
                st[1].insert(make_pair(XC,YC));
                st[3].insert(make_pair(XC,YC));
                YC++;
            }
            while(YA<YC)
            {
                st[1].insert(make_pair(XC,YC));
                st[3].insert(make_pair(XC,YC));
                YC--;
            }
            while(XC>XA)
            {
                st[1].insert(make_pair(XA,YA));
                st[3].insert(make_pair(XA,YA));
                XA++;
            }
            while(XC<XA)
            {
                st[1].insert(make_pair(XA,YA));
                st[3].insert(make_pair(XA,YA));
                XA--;
            }
        }
    }
    

    else if(s1[1]==s2[1])
    {
        

        int x1 = XC - XB;
        int y1 = YA - YB;
        double res1 = sqrt(x1*x1 + y1*y1);
        

        int x2 = XA - XB;
        int y2 = YC - YB;
        double res2 = sqrt(x2*x2 + y2*y2);
        

        {
            st[0].insert(make_pair(XC,YA));
            st[1].insert(make_pair(XC,YA));
            while(YA>YC)
            {
                st[0].insert(make_pair(XC,YC));
                st[1].insert(make_pair(XC,YC));
                YC++;
            }
            while(YA<YC)
            {
                st[0].insert(make_pair(XC,YC));
                st[1].insert(make_pair(XC,YC));
                YC--;
            }
            while(XC>XA)
            {
                st[0].insert(make_pair(XA,YA));
                st[1].insert(make_pair(XA,YA));
                XA++;
            }
            while(XC<XA)
            {
                st[0].insert(make_pair(XA,YA));
                st[1].insert(make_pair(XA,YA));
                XA--;
            }
        }
        

        XA = p[0].first; YA = p[0].second;
        XB = p[1].first; YB = p[1].second;
        XC = p[2].first; YC = p[2].second;
        {
            st[2].insert(make_pair(XA,YC));
            st[3].insert(make_pair(XA,YC));
            while(YA>YC)
            {
                st[2].insert(make_pair(XA,YA));
                st[3].insert(make_pair(XA,YA));
                YA--;
            }
            while(YA<YC)
            {
                st[2].insert(make_pair(XA,YA));
                st[3].insert(make_pair(XA,YA));
                YA++;
            }
            while(XC>XA)
            {
                st[2].insert(make_pair(XC,YC));
                st[3].insert(make_pair(XC,YC));
                XC--;
            }
            while(XC<XA)
            {
                st[2].insert(make_pair(XC,YC));
                st[3].insert(make_pair(XC,YC));
                XC++;
            }
        }
        XA = p[0].first; YA = p[0].second;
        XB = p[1].first; YB = p[1].second;
        XC = p[2].first; YC = p[2].second;
        

        x1 = XC - XA;
        y1 = YB - YA;
        res1 = sqrt(x1*x1 + y1*y1);
        

        x2 = XB - XA;
        y2 = YC - YA;
        res2 = sqrt(x2*x2 + y2*y2);
        

        {
            st[0].insert(make_pair(XC,YB));
            st[2].insert(make_pair(XC,YB));
            while(YB>YC)
            {
                st[0].insert(make_pair(XC,YC));
                st[2].insert(make_pair(XC,YC));
                YC++;
            }
            while(YB<YC)
            {
                st[0].insert(make_pair(XC,YC));
                st[2].insert(make_pair(XC,YC));
                YC--;
            }
            while(XC>XB)
            {
                st[0].insert(make_pair(XB,YB));
                st[2].insert(make_pair(XB,YB));
                XB++;
            }
            while(XC<XB)
            {
                st[0].insert(make_pair(XB,YB));
                st[2].insert(make_pair(XB,YB));
                XB--;
            }
        }
        

        XA = p[0].first; YA = p[0].second;
        XB = p[1].first; YB = p[1].second;
        XC = p[2].first; YC = p[2].second;
        {
            st[1].insert(make_pair(XB,YC));
            st[3].insert(make_pair(XB,YC));
            while(YB>YC)
            {
                st[1].insert(make_pair(XB,YB));
                st[3].insert(make_pair(XB,YB));
                YB--;
            }
            while(YB<YC)
            {
                st[1].insert(make_pair(XB,YB));
                st[3].insert(make_pair(XB,YB));
                YB++;
            }
            while(XC>XB)
            {
                st[1].insert(make_pair(XC,YC));
                st[3].insert(make_pair(XC,YC));
                XC--;
            }
            while(XC<XB)
            {
                st[1].insert(make_pair(XC,YC));
                st[3].insert(make_pair(XC,YC));
                XC++;
            }
        }
    }
    

    else if(s1[1]==s2[0] || s1[0]==s2[1])
    {
        

        int x1 = XB - XC;
        int y1 = YA - YC;
        double res1 = sqrt(x1*x1 + y1*y1);
        

        int x2 = XA - XC;
        int y2 = YB - YC;
        double res2 = sqrt(x2*x2 + y2*y2);
        

        {
            st[0].insert(make_pair(XB,YA));
            st[1].insert(make_pair(XB,YA));
            while(YA>YB)
            {
                st[0].insert(make_pair(XB,YB));
                st[1].insert(make_pair(XB,YB));
                YB++;
            }
            while(YA<YB)
            {
                st[0].insert(make_pair(XB,YB));
                st[1].insert(make_pair(XB,YB));
                YB--;
            }
            while(XB>XA)
            {
                st[0].insert(make_pair(XA,YA));
                st[1].insert(make_pair(XA,YA));
                XA++;
            }
            while(XB<XA)
            {
                st[0].insert(make_pair(XA,YA));
                st[1].insert(make_pair(XA,YA));
                XA--;
            }
        }
        

        XA = p[0].first; YA = p[0].second;
        XB = p[1].first; YB = p[1].second;
        XC = p[2].first; YC = p[2].second;
        {
            st[2].insert(make_pair(XA,YB));
            st[3].insert(make_pair(XA,YB));
            while(YA>YB)
            {
                st[2].insert(make_pair(XA,YA));
                st[3].insert(make_pair(XA,YA));
                YA--;
            }
            while(YA<YB)
            {
                st[2].insert(make_pair(XA,YA));
                st[3].insert(make_pair(XA,YA));
                YA++;
            }
            while(XB>XA)
            {
                st[2].insert(make_pair(XB,YB));
                st[3].insert(make_pair(XB,YB));
                XB--;
            }
            while(XB<XA)
            {
                st[2].insert(make_pair(XB,YB));
                st[3].insert(make_pair(XB,YB));
                XB++;
            }
        }
        XA = p[0].first; YA = p[0].second;
        XB = p[1].first; YB = p[1].second;
        XC = p[2].first; YC = p[2].second;
        

        x1 = XB - XA;
        y1 = YC - YA;
        res1 = sqrt(x1*x1 + y1*y1);
        

        x2 = XC - XA;
        y2 = YB - YA;
        res2 = sqrt(x2*x2 + y2*y2);
        

        {
            st[0].insert(make_pair(XB,YC));
            st[2].insert(make_pair(XB,YC));
            while(YB>YC)
            {
                st[0].insert(make_pair(XB,YB));
                st[2].insert(make_pair(XB,YB));
                YB--;
            }
            while(YB<YC)
            {
                st[0].insert(make_pair(XB,YB));
                st[2].insert(make_pair(XB,YB));
                YB++;
            }
            while(XC>XB)
            {
                st[0].insert(make_pair(XC,YC));
                st[2].insert(make_pair(XC,YC));
                XC--;
            }
            while(XC<XB)
            {
                st[0].insert(make_pair(XC,YC));
                st[2].insert(make_pair(XC,YC));
                XC++;
            }
        }
        

        XA = p[0].first; YA = p[0].second;
        XB = p[1].first; YB = p[1].second;
        XC = p[2].first; YC = p[2].second;
        {
            st[1].insert(make_pair(XC,YB));
            st[3].insert(make_pair(XC,YB));
            while(YB>YC)
            {
                st[1].insert(make_pair(XC,YC));
                st[3].insert(make_pair(XC,YC));
                YC++;
            }
            while(YB<YC)
            {
                st[1].insert(make_pair(XC,YC));
                st[3].insert(make_pair(XC,YC));
                YC--;
            }
            while(XC>XB)
            {
                st[1].insert(make_pair(XB,YB));
                st[3].insert(make_pair(XB,YB));
                XB++;
            }
            while(XC<XB)
            {
                st[1].insert(make_pair(XB,YB));
                st[3].insert(make_pair(XB,YB));
                XB--;
            }
        }
    }
    int z = index(st);
    cout << st[z].size() << endl;
    for(itr=st[z].begin();itr!=st[z].end();itr++)
    {
        cout << itr->first << " " << itr->second << endl;
    }
    return 0;
}
