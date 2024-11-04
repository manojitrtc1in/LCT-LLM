#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stdio.h>

using namespace std;

#define MAXN 1100

int n,m;
int used[MAXN][MAXN];

vector <pair<int,int> > solve_l_r(int sx,int sy,int fx,int fy){
    vector <pair<int,int> > ret;
    int len=abs(sx-fx)+1;
    if ((fy-sy+1)%2==1){
        int curx=sx, cury=sy;
        for (int i=1; i<=fy-sy+1; i++){
            for (int j=1; j<len; j++){
                ret.push_back(make_pair(curx,cury));
                if (i%2==0)
                    curx--; else
                    curx++;
            }
            ret.push_back(make_pair(curx,cury));
            cury++;
        }
    } else
    {
        int curx=sx, cury=sy;
        for (int i=1; i<=fy-sy-1; i++){
            for (int j=1; j<len; j++){
                ret.push_back(make_pair(curx,cury));
                if (i%2==0)
                    curx--; else
                    curx++;
            }
            ret.push_back(make_pair(curx,cury));
            cury++;
        }
        for (int i=1; i<=len-1; i++){
            ret.push_back(make_pair(curx,cury));
            if (i%2==0)
                cury--; else
                cury++;
            ret.push_back(make_pair(curx,cury));
            curx++;
        }
        if (curx==fx&&cury==fy)
            ret.push_back(make_pair(curx,cury)); else
            ret.push_back(make_pair(curx,cury)),
            ret.push_back(make_pair(fx,fy));
    }
    return ret;
}

vector <pair<int,int> > solve_r_l(int sx,int sy,int fx,int fy){
    vector <pair<int,int> > ret;
    int len=abs(sx-fx)+1;
    if ((sy-fy+1)%2==1){
        int curx=sx, cury=sy;
        for (int i=1; i<=sy-fy+1; i++){
            for (int j=1; j<len; j++){
                ret.push_back(make_pair(curx,cury));
                if (i%2==0)
                    curx--; else
                    curx++;
            }
            ret.push_back(make_pair(curx,cury));
            cury--;
        }
    } else
    {
        int curx=sx, cury=sy;
        for (int i=1; i<=sy-fy-1; i++){
            for (int j=1; j<len; j++){
                ret.push_back(make_pair(curx,cury));
                if (i%2==0)
                    curx--; else
                    curx++;
            }
            ret.push_back(make_pair(curx,cury));
            cury--;
        }
        for (int i=1; i<=len-1; i++){
            ret.push_back(make_pair(curx,cury));
            if (i%2==0)
                cury++; else
                cury--;
            ret.push_back(make_pair(curx,cury));
            curx++;
        }
        if (curx==fx&&cury==fy)
            ret.push_back(make_pair(curx,cury)); else
            ret.push_back(make_pair(curx,cury)),
            ret.push_back(make_pair(fx,fy));
    }
    return ret;
}

vector <pair<int,int> > simple_l(int sx,int sy,int fx,int fy,int len){
    vector <pair<int,int> > ret;
    if ((sx-fx+1)%2==0){
        int curx=sx, cury=sy;
        for (int i=1; i<=sx-fx+1; i++){
            for (int j=1; j<len; j++){
                ret.push_back(make_pair(curx,cury));
                if (i%2==0)
                    cury++; else
                    cury--;
            }
            ret.push_back(make_pair(curx,cury));
            curx--;
        }
    } else
    {
        int curx=sx, cury=sy;
        for (int i=1; i<=sx-fx-1; i++){
            for (int j=1; j<len; j++){
                ret.push_back(make_pair(curx,cury));
                if (i%2==0)
                    cury++; else
                    cury--;
            }
            ret.push_back(make_pair(curx,cury));
            curx--;
        }
        for (int i=1; i<=len-1; i++){
            ret.push_back(make_pair(curx,cury));
            if (i%2==0)
                curx++; else
                curx--;
            ret.push_back(make_pair(curx,cury));
            cury++;
        }
        if (curx==fx&&cury==fy)
            ret.push_back(make_pair(curx,cury)); else
            ret.push_back(make_pair(curx,cury)),
            ret.push_back(make_pair(fx,fy));
    }
    return ret;
}
vector <pair<int,int> > simple_r(int sx,int sy,int fx,int fy,int len){
    vector <pair<int,int> > ret;
    if ((sx-fx+1)%2==0){
        int curx=sx, cury=sy;
        for (int i=1; i<=sx-fx+1; i++){
            for (int j=1; j<len; j++){
                ret.push_back(make_pair(curx,cury));
                if (i%2==0)
                    cury--; else
                    cury++;
            }
            ret.push_back(make_pair(curx,cury));
            curx--;
        }
    } else
    {
        int curx=sx, cury=sy;
        for (int i=1; i<=sx-fx-1; i++){
            for (int j=1; j<len; j++){
                ret.push_back(make_pair(curx,cury));
                if (i%2==0)
                    cury--; else
                    cury++;
            }
            ret.push_back(make_pair(curx,cury));
            curx--;
        }
        for (int i=1; i<=len-1; i++){
            ret.push_back(make_pair(curx,cury));
            if (i%2==0)
                curx++; else
                curx--;
            ret.push_back(make_pair(curx,cury));
            cury--;
        }
        if (curx==fx&&cury==fy)
            ret.push_back(make_pair(curx,cury)); else
            ret.push_back(make_pair(curx,cury)),
            ret.push_back(make_pair(fx,fy));
    }
    return ret;
}

vector <pair<int,int> > solve2(int sx,int sy,int fx,int fy){
    vector <pair<int,int> > ret=simple_r(sy,sx,1,sx,n-sx+1);
    for (int i=0; i<ret.size(); i++)
        swap(ret[i].first,ret[i].second);

    int curx=ret.back().first, cury=ret.back().second;
    curx--;
    vector <pair<int,int> > tek=solve_r_l(fx,fy,curx,cury);
    reverse(tek.begin(),tek.end());
    for (int i=0; i<tek.size(); i++)
        ret.push_back(tek[i]);
    return ret;
}

vector <pair<int,int> > solve(int sx,int sy,int fx,int fy){
    vector <pair<int,int> > ret=solve2(sx,sy,1,sy);

    int curx=1, cury=sy+1;
    for (int i=1; i<fx; i++){
        if (i%2==1){
            for (int j=sy+1; j<m; j++)
                ret.push_back(make_pair(curx,cury)),
                cury++;
            ret.push_back(make_pair(curx,cury));
            curx++;
        } else
        {
            for (int j=sy+1; j<m; j++)
                ret.push_back(make_pair(curx,cury)),
                cury--;
            ret.push_back(make_pair(curx,cury));
            curx++;
        }
    }

    int tp=-1;
    if (cury==sy+1){
        vector <pair<int,int> > tk=solve_l_r(curx,cury,n,fy-1);
        for (int i=0; i<tk.size(); i++)
            ret.push_back(tk[i]);
        tp=1;
    } else
    {
        vector <pair<int,int> > tk=solve_r_l(curx,cury,n,fy+1);
        for (int i=0; i<tk.size(); i++)
            ret.push_back(tk[i]);
        tp=0;
    }

    curx=n, cury=fy;

    if (tp){
        vector <pair<int,int> > tk=simple_r(curx,cury,fx,fy,m-fy+1);
        for (int i=0; i<tk.size(); i++)
            ret.push_back(tk[i]);
    } else
    {
        vector <pair<int,int> > tk=simple_l(curx,cury,fx,fy,fy-sy);
        for (int i=0; i<tk.size(); i++)
            ret.push_back(tk[i]);
    }
    return ret;
}

int fnd_ans(int n,int m,int sx,int st,int fx,int fy){
    int col1=((sx+st+1)%2);
    int col2=((fx+fy+1)%2);

    int cntb=(n*m+1)/2;
    int cntw=(n*m)/2;

    if (col1==1&&col2==1)
        return cntb*2-1;
    if (col1==1&&col2==0)
        return cntw*2;
    if (col1==0&&col2==1)
        return cntw*2;
    if (col1==0&&col2==0)
        return 2*cntw-1;
}

int is_in(int x,int y){
    return (1<=x&&x<=n&&y>=1&&y<=m);
}

int check(vector <pair<int,int> > res,int sx,int sy,int fx,int fy){
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            used[i][j]=0;
    if (!(sx==res[0].first&&sy==res[0].second)) return 0;
    if (!(fx==res.back().first&&fy==res.back().second)) return 0;

    for (int i=0; i<res.size(); i++)
        if (!is_in(res[i].first,res[i].second)) return 0;
    for (int i=1; i<res.size(); i++){
        int sum=abs(res[i].first-res[i-1].first)+abs(res[i].second-res[i-1].second);
        if (sum!=1)
            return 0;
    }
    return 1;
}

vector <pair<int,int> > find_res(int x1,int y1,int x2,int y2,int ok){
    vector <pair<int,int> > res;
    res=solve(x1,y1,x2,y2);
    if (res.size()==ok&&check(res,x1,y1,x2,y2)) return res;

    swap(x1,x2), swap(y1,y2);
    res=solve(x1,y1,x2,y2);
    reverse(res.begin(),res.end());
    swap(x1,x2), swap(y1,y2);
    if (res.size()==ok&&check(res,x1,y1,x2,y2)) return res;

    swap(x1,y1), swap(x2,y2), swap(n,m);
    res=solve(x1,y1,x2,y2);
    for (int i=0; i<res.size(); i++)
        swap(res[i].first,res[i].second);
    swap(x1,y1), swap(x2,y2), swap(n,m);
    if (res.size()==ok&&check(res,x1,y1,x2,y2)) return res;

    swap(x1,y1), swap(x2,y2), swap(n,m), swap(x1,x2), swap(y1,y2);
    res=solve(x1,y1,x2,y2);
    for (int i=0; i<res.size(); i++)
        swap(res[i].first,res[i].second);
    reverse(res.begin(),res.end());
    swap(x1,y1), swap(x2,y2), swap(n,m), swap(x1,x2), swap(y1,y2);
    if (res.size()==ok&&check(res,x1,y1,x2,y2)) return res;

    x1=n+1-x1, x2=n+1-x2;
    res=solve(x1,y1,x2,y2);
    for (int i=0; i<res.size(); i++)
        res[i].first=n+1-res[i].first;
    x1=n+1-x1, x2=n+1-x2;
    if (res.size()==ok&&check(res,x1,y1,x2,y2)) return res;

    x1=n+1-x1, x2=n+1-x2;
    swap(x1,x2), swap(y1,y2);
    res=solve(x1,y1,x2,y2);
    for (int i=0; i<res.size(); i++)
        res[i].first=n+1-res[i].first;
    swap(x1,x2), swap(y1,y2);
    reverse(res.begin(),res.end());
    x1=n+1-x1, x2=n+1-x2;
    if (res.size()==ok&&check(res,x1,y1,x2,y2)) return res;

    y1=m+1-y1, y2=m+1-y2;
    res=solve(x1,y1,x2,y2);
    for (int i=0; i<res.size(); i++)
        res[i].second=m+1-res[i].second;
    y1=m+1-y1, y2=m+1-y2;
    if (res.size()==ok&&check(res,x1,y1,x2,y2)) return res;

    y1=m+1-y1, y2=m+1-y2;
    swap(x1,x2), swap(y1,y2);
    res=solve(x1,y1,x2,y2);
    for (int i=0; i<res.size(); i++)
        res[i].second=m+1-res[i].second;
    y1=m+1-y1, y2=m+1-y2;
    reverse(res.begin(),res.end());
    swap(x1,x2), swap(y1,y2);
    if (res.size()==ok&&check(res,x1,y1,x2,y2)) return res;

    y1=m+1-y1, y2=m+1-y2;
    x1=n+1-x1, x2=n+1-x2;
    res=solve(x1,y1,x2,y2);
    for (int i=0; i<res.size(); i++)
        res[i].second=m+1-res[i].second,
        res[i].first=n+1-res[i].first;
    y1=m+1-y1, y2=m+1-y2;
    x1=n+1-x1, x2=n+1-x2;
    if (res.size()==ok&&check(res,x1,y1,x2,y2)) return res;

    y1=m+1-y1, y2=m+1-y2;
    x1=n+1-x1, x2=n+1-x2;
    swap(x1,x2), swap(y1,y2);
    res=solve(x1,y1,x2,y2);
    for (int i=0; i<res.size(); i++)
        res[i].second=m+1-res[i].second,
        res[i].first=n+1-res[i].first;
    y1=m+1-y1, y2=m+1-y2;
    x1=n+1-x1, x2=n+1-x2;
    swap(x1,x2), swap(y1,y2);
    reverse(res.begin(),res.end());
    if (res.size()==ok&&check(res,x1,y1,x2,y2)) return res;

    
    
    swap(x1,y1), swap(x2,y2), swap(n,m);
    x1=n+1-x1, x2=n+1-x2;
    res=solve(x1,y1,x2,y2);
    for (int i=0; i<res.size(); i++)
        res[i].first=n+1-res[i].first,swap(res[i].first,res[i].second);;
    x1=n+1-x1, x2=n+1-x2;
    swap(x1,y1), swap(x2,y2), swap(n,m);
    if (res.size()==ok&&check(res,x1,y1,x2,y2)) return res;

    swap(x1,y1), swap(x2,y2), swap(n,m);
    x1=n+1-x1, x2=n+1-x2;
    swap(x1,x2), swap(y1,y2);
    res=solve(x1,y1,x2,y2);
    for (int i=0; i<res.size(); i++)
        res[i].first=n+1-res[i].first,swap(res[i].first,res[i].second);;
    swap(x1,x2), swap(y1,y2);
    x1=n+1-x1, x2=n+1-x2;
    swap(x1,y1), swap(x2,y2), swap(n,m);
    reverse(res.begin(),res.end());
    if (res.size()==ok&&check(res,x1,y1,x2,y2)) return res;

    swap(x1,y1), swap(x2,y2), swap(n,m);
    y1=m+1-y1, y2=m+1-y2;
    res=solve(x1,y1,x2,y2);
    for (int i=0; i<res.size(); i++)
        res[i].second=m+1-res[i].second,swap(res[i].first,res[i].second);;
    y1=m+1-y1, y2=m+1-y2;
    swap(x1,y1), swap(x2,y2), swap(n,m);
    if (res.size()==ok&&check(res,x1,y1,x2,y2)) return res;

    swap(x1,y1), swap(x2,y2), swap(n,m);
    y1=m+1-y1, y2=m+1-y2;
    swap(x1,x2), swap(y1,y2);
    res=solve(x1,y1,x2,y2);
    for (int i=0; i<res.size(); i++)
        res[i].second=m+1-res[i].second,swap(res[i].first,res[i].second);;
    y1=m+1-y1, y2=m+1-y2;
    swap(x1,x2), swap(y1,y2);
    swap(x1,y1), swap(x2,y2), swap(n,m);
    reverse(res.begin(),res.end());
    if (res.size()==ok&&check(res,x1,y1,x2,y2)) return res;

    swap(x1,y1), swap(x2,y2), swap(n,m);
    y1=m+1-y1, y2=m+1-y2;
    x1=n+1-x1, x2=n+1-x2;
    res=solve(x1,y1,x2,y2);
    for (int i=0; i<res.size(); i++)
        res[i].second=m+1-res[i].second,
        res[i].first=n+1-res[i].first,swap(res[i].first,res[i].second);;
    y1=m+1-y1, y2=m+1-y2;
    x1=n+1-x1, x2=n+1-x2;
    swap(x1,y1), swap(x2,y2), swap(n,m);
    if (res.size()==ok&&check(res,x1,y1,x2,y2)) return res;

    swap(x1,y1), swap(x2,y2), swap(n,m);
    y1=m+1-y1, y2=m+1-y2;
    x1=n+1-x1, x2=n+1-x2;
    swap(x1,x2), swap(y1,y2);
    res=solve(x1,y1,x2,y2);
    for (int i=0; i<res.size(); i++)
        res[i].second=m+1-res[i].second,
        res[i].first=n+1-res[i].first,swap(res[i].first,res[i].second);;
    y1=m+1-y1, y2=m+1-y2;
    x1=n+1-x1, x2=n+1-x2;
    swap(x1,x2), swap(y1,y2);
    swap(x1,y1), swap(x2,y2), swap(n,m);
    reverse(res.begin(),res.end());
    if (res.size()==ok&&check(res,x1,y1,x2,y2)) return res;

    res.clear();
    return res;
}


int main(){


    scanf("%d%d",&n,&m);
    int x1,y1,x2,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    vector <pair<int,int> > res=find_res(x1,y1,x2,y2,fnd_ans(n,m,x1,y1,x2,y2));
    printf("%d\n",res.size());
    for (int i=0; i<res.size(); i++){
        printf("%d %d\n",res[i].first,res[i].second);
    }

    


    return 0;
}