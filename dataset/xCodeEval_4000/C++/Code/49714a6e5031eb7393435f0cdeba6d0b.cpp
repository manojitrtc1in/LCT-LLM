#pragma GCC optimize(3,"Ofast","inline")
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;

typedef pair<int, int> pii;
const int maxn = 1e6 + 10;
const ll mod = 1e9 + 7;
const double pi = acos(-1.0);

int t;
int n, m;
int num = 0;
char s[105][105];
int k;
int x1[30005], yy[30005];
int x2[30005], y2[30005];
int x3[30005], y3[30005];


void init(){
  k = 0;
  num = 0;
  for(int i = 0; i <= 30000; i ++){
    x1[i] = 0;
    yy[i] = 0;
    x2[i] = 0;
    y2[i] = 0;
    x3[i] = 0;
    y3[i] = 0;
  }
}



void print()
{
  puts("----");
  for(int i = 0; i < n; i ++){
    for(int j = 0; j < m; j ++){
      cout << s[i][j];
    }
    cout << endl;
  }
  puts("----");
}

void calc(int i, int j)
{
            
            if(s[i - 1][j - 1] == '1' && s[i - 1][j] == '1' && s[i][j - 1] == '1' && s[i][j] == '1'){
              x1[k] = i - 1, yy[k] = j - 1,   x2[k] = i - 1, y2[k] = j,       x3[k] = i,     y3[k ++] = j - 1;
              s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '0', s[i][j] = '1';
              num -= 3;
            }

            
            else if(i == n - 1 && s[i - 1][j - 1] == '0' && s[i - 1][j] == '0' && s[i][j - 1] == '0' && s[i][j] == '1'){
              x1[k] = i - 1, yy[k] = j,       x2[k] = i,     y2[k] = j - 1,   x3[k] = i,     y3[k ++] = j;
              x1[k] = i - 1, yy[k] = j - 1,   x2[k] = i,     y2[k] = j - 1,   x3[k] = i,     y3[k ++] = j;
              x1[k] = i - 1, yy[k] = j - 1,   x2[k] = i - 1, y2[k] = j,       x3[k] = i,     y3[k ++] = j;
              s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '0', s[i][j] = '0';
              num --;
            }
            

            else if(s[i - 1][j - 1] == '1' && s[i - 1][j] == '0' && s[i][j - 1] == '0' && s[i][j] == '0'){
              x1[k] = i - 1, yy[k] = j - 1,   x2[k] = i,     y2[k] = j - 1,       x3[k] = i,     y3[k ++] = j;
              s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '1', s[i][j] = '1';
              num ++;
            }
            
            else if(s[i - 1][j - 1] == '0' && s[i - 1][j] == '1' && s[i][j - 1] == '0' && s[i][j] == '0'){
              x1[k] = i - 1, yy[k] = j,       x2[k] = i, y2[k] = j - 1,       x3[k] = i,     y3[k ++] = j;
              s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '1', s[i][j] = '1';
              num ++;
            }
            
            else if(i == n - 1 && s[i - 1][j - 1] == '0' && s[i - 1][j] == '0' && s[i][j - 1] == '1' && s[i][j] == '0'){
              x1[k] = i - 1, yy[k] = j - 1,       x2[k] = i,     y2[k] = j - 1,   x3[k] = i,     y3[k ++] = j;
              x1[k] = i - 1, yy[k] = j - 1,       x2[k] = i - 1, y2[k] = j,       x3[k] = i,     y3[k ++] = j - 1;
              x1[k] = i,     yy[k] = j - 1,       x2[k] = i - 1, y2[k] = j,       x3[k] = i,     y3[k ++] = j;
              s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '0', s[i][j] = '0';
              num --;
            }

            
            else if(s[i - 1][j - 1] == '0' && s[i - 1][j] == '1' && s[i][j - 1] == '1' && s[i][j] == '0'){
              x1[k] = i - 1, yy[k] = j,   x2[k] = i,     y2[k] = j - 1,   x3[k] = i,     y3[k ++] = j;
              s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '0', s[i][j] = '1';
              num --;
            }
            
            else if(s[i - 1][j - 1] == '1' && s[i - 1][j] == '0' && s[i][j - 1] == '0' && s[i][j] == '1'){
              x1[k] = i - 1, yy[k] = j - 1,       x2[k] = i, y2[k] = j - 1,       x3[k] = i,     y3[k ++] = j;
              s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '1', s[i][j] = '0';
              num --;
            }
            
            else if(s[i - 1][j - 1] == '1' && s[i - 1][j] == '0' && s[i][j - 1] == '1' && s[i][j] == '0'){
              x1[k] = i,     yy[k] = j - 1,   x2[k] = i - 1, y2[k] = j,      x3[k] = i,     y3[k ++] = j;
              x1[k] = i - 1, yy[k] = j - 1,   x2[k] = i - 1, y2[k] = j,       x3[k] = i,     y3[k ++] = j;
              s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '0', s[i][j] = '0';
              num -= 2;
            }

            
            else if(s[i - 1][j - 1] == '0' && s[i - 1][j] == '0' && s[i][j - 1] == '1' && s[i][j] == '1'){
              x1[k] = i - 1,     yy[k] = j - 1,   x2[k] = i - 1,     y2[k] = j,   x3[k] = i,     y3[k ++] = j - 1;
              x1[k] = i - 1,     yy[k] = j - 1,   x2[k] = i - 1,     y2[k] = j,   x3[k] = i,     y3[k ++] = j;
              s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '0', s[i][j] = '0';
              num -= 2;
            }
            
            else if(s[i - 1][j - 1] == '0' && s[i - 1][j] == '1' && s[i][j - 1] == '0' && s[i][j] == '1'){
              x1[k] = i - 1, yy[k] = j - 1,   x2[k] = i - 1, y2[k] = j,       x3[k] = i,     y3[k ++] = j - 1;
              x1[k] = i - 1, yy[k] = j - 1,   x2[k] = i,     y2[k] = j - 1,   x3[k] = i,     y3[k ++] = j;
              s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '0', s[i][j] = '0';
              num -= 2;
            }
            
            else if(s[i - 1][j - 1] == '1' && s[i - 1][j] == '1' && s[i][j - 1] == '0' && s[i][j] == '0'){
              x1[k] = i - 1, yy[k] = j,       x2[k] = i,     y2[k] = j - 1,   x3[k] = i,     y3[k ++] = j;
              x1[k] = i - 1, yy[k] = j - 1,   x2[k] = i,     y2[k] = j - 1,   x3[k] = i,     y3[k ++] = j;
              s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '0', s[i][j] = '0';
              num -= 2;
            }


            
            else if(s[i - 1][j - 1] == '1' && s[i - 1][j] == '1' && s[i][j - 1] == '0' && s[i][j] == '1'){
              x1[k] = i - 1, yy[k] = j - 1,   x2[k] = i - 1, y2[k] = j,       x3[k] = i,     y3[k ++] = j;
              s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '0', s[i][j] = '0';
              num -= 3;
            }
            
            else if(s[i - 1][j - 1] == '1' && s[i - 1][j] == '1' && s[i][j - 1] == '1' && s[i][j] == '0'){
              x1[k] = i - 1, yy[k] = j - 1,   x2[k] = i - 1, y2[k] = j,       x3[k] = i,     y3[k ++] = j - 1;
              s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '0', s[i][j] = '0';
              num -= 3;
            }
            
            else if(s[i - 1][j - 1] == '1' && s[i - 1][j] == '0' && s[i][j - 1] == '1' && s[i][j] == '1'){
              x1[k] = i - 1, yy[k] = j - 1,   x2[k] = i, y2[k] = j - 1,       x3[k] = i,     y3[k ++] = j;
              s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '0', s[i][j] = '0';
              num -= 3;
            }
            
            else if(s[i - 1][j - 1] == '0' && s[i - 1][j] == '1' && s[i][j - 1] == '1' && s[i][j] == '1'){
              x1[k] = i - 1, yy[k] = j,   x2[k] = i, y2[k] = j - 1,       x3[k] = i,     y3[k ++] = j;
              s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '0', s[i][j] = '0';
              num -= 3;
            }
}

void calc2(int i, int j){

        if(s[i - 1][j - 1] == '1' && s[i - 1][j] == '1' && s[i][j - 1] == '1' && s[i][j] == '1'){
          x1[k] = i - 1, yy[k] = j - 1,   x2[k] = i - 1, y2[k] = j,       x3[k] = i,     y3[k ++] = j - 1;
          x1[k] = i - 1, yy[k] = j,       x2[k] = i,     y2[k] = j - 1,   x3[k] = i,     y3[k ++] = j;
          x1[k] = i - 1, yy[k] = j - 1,   x2[k] = i,     y2[k] = j - 1,   x3[k] = i,     y3[k ++] = j;
          x1[k] = i - 1, yy[k] = j - 1,   x2[k] = i - 1, y2[k] = j,       x3[k] = i,     y3[k ++] = j;
          s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '0', s[i][j] = '0';
          num -= 4;
        }

        
        else if(s[i - 1][j - 1] == '0' && s[i - 1][j] == '0' && s[i][j - 1] == '0' && s[i][j] == '1'){
          x1[k] = i - 1, yy[k] = j,       x2[k] = i,     y2[k] = j - 1,   x3[k] = i,     y3[k ++] = j;
          x1[k] = i - 1, yy[k] = j - 1,   x2[k] = i,     y2[k] = j - 1,   x3[k] = i,     y3[k ++] = j;
          x1[k] = i - 1, yy[k] = j - 1,   x2[k] = i - 1, y2[k] = j,       x3[k] = i,     y3[k ++] = j;
          s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '0', s[i][j] = '0';
          num --;
        }
        

        else if(s[i - 1][j - 1] == '1' && s[i - 1][j] == '0' && s[i][j - 1] == '0' && s[i][j] == '0'){
          x1[k] = i - 1, yy[k] = j - 1,   x2[k] = i - 1,     y2[k] = j,       x3[k] = i,     y3[k ++] = j - 1;
          x1[k] = i - 1, yy[k] = j - 1,   x2[k] = i,         y2[k] = j - 1,   x3[k] = i,     y3[k ++] = j;
          x1[k] = i - 1, yy[k] = j - 1,   x2[k] = i - 1,     y2[k] = j,       x3[k] = i,     y3[k ++] = j;
          s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '0', s[i][j] = '0';
          num --;
        }
        
        else if(s[i - 1][j - 1] == '0' && s[i - 1][j] == '1' && s[i][j - 1] == '0' && s[i][j] == '0'){
          x1[k] = i - 1, yy[k] = j - 1,       x2[k] = i - 1, y2[k] = j,       x3[k] = i,     y3[k ++] = j;
          x1[k] = i - 1, yy[k] = j - 1,       x2[k] = i - 1, y2[k] = j,       x3[k] = i,     y3[k ++] = j - 1;
          x1[k] = i,     yy[k] = j - 1,       x2[k] = i - 1, y2[k] = j,       x3[k] = i,     y3[k ++] = j;
          s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '0', s[i][j] = '0';
          num --;
        }
        
        else if(s[i - 1][j - 1] == '0' && s[i - 1][j] == '0' && s[i][j - 1] == '1' && s[i][j] == '0'){
          x1[k] = i - 1, yy[k] = j - 1,       x2[k] = i,     y2[k] = j - 1,   x3[k] = i,     y3[k ++] = j;
          x1[k] = i - 1, yy[k] = j - 1,       x2[k] = i - 1, y2[k] = j,       x3[k] = i,     y3[k ++] = j - 1;
          x1[k] = i,     yy[k] = j - 1,       x2[k] = i - 1, y2[k] = j,       x3[k] = i,     y3[k ++] = j;
          s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '0', s[i][j] = '0';
          num --;
        }

        
        else if(s[i - 1][j - 1] == '0' && s[i - 1][j] == '1' && s[i][j - 1] == '1' && s[i][j] == '0'){
          x1[k] = i - 1, yy[k] = j - 1,   x2[k] = i,     y2[k] = j - 1,   x3[k] = i,     y3[k ++] = j;
          x1[k] = i - 1, yy[k] = j - 1,   x2[k] = i - 1, y2[k] = j,       x3[k] = i,     y3[k ++] = j;
          s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '0', s[i][j] = '0';
          num -= 2;
        }
        
        else if(s[i - 1][j - 1] == '1' && s[i - 1][j] == '0' && s[i][j - 1] == '0' && s[i][j] == '1'){
          x1[k] = i - 1, yy[k] = j - 1,       x2[k] = i - 1, y2[k] = j,       x3[k] = i,     y3[k ++] = j - 1;
          x1[k] = i,     yy[k] = j - 1,       x2[k] = i - 1, y2[k] = j,       x3[k] = i,     y3[k ++] = j;
          s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '0', s[i][j] = '0';
          num -= 2;
        }
        
        else if(s[i - 1][j - 1] == '1' && s[i - 1][j] == '0' && s[i][j - 1] == '1' && s[i][j] == '0'){
          x1[k] = i,     yy[k] = j - 1,   x2[k] = i - 1, y2[k] = j,      x3[k] = i,     y3[k ++] = j;
          x1[k] = i - 1, yy[k] = j - 1,   x2[k] = i - 1, y2[k] = j,       x3[k] = i,     y3[k ++] = j;
          s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '0', s[i][j] = '0';
          num -= 2;
        }

        
        else if(s[i - 1][j - 1] == '0' && s[i - 1][j] == '0' && s[i][j - 1] == '1' && s[i][j] == '1'){
          x1[k] = i - 1,     yy[k] = j - 1,   x2[k] = i - 1,     y2[k] = j,   x3[k] = i,     y3[k ++] = j - 1;
          x1[k] = i - 1,     yy[k] = j - 1,   x2[k] = i - 1,     y2[k] = j,   x3[k] = i,     y3[k ++] = j;
          s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '0', s[i][j] = '0';
          num -= 2;
        }
        
        else if(s[i - 1][j - 1] == '0' && s[i - 1][j] == '1' && s[i][j - 1] == '0' && s[i][j] == '1'){
          x1[k] = i - 1, yy[k] = j - 1,   x2[k] = i - 1, y2[k] = j,       x3[k] = i,     y3[k ++] = j - 1;
          x1[k] = i - 1, yy[k] = j - 1,   x2[k] = i,     y2[k] = j - 1,   x3[k] = i,     y3[k ++] = j;
          s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '0', s[i][j] = '0';
          num -= 2;
        }
        
        else if(s[i - 1][j - 1] == '1' && s[i - 1][j] == '1' && s[i][j - 1] == '0' && s[i][j] == '0'){
          x1[k] = i - 1, yy[k] = j,       x2[k] = i,     y2[k] = j - 1,   x3[k] = i,     y3[k ++] = j;
          x1[k] = i - 1, yy[k] = j - 1,   x2[k] = i,     y2[k] = j - 1,   x3[k] = i,     y3[k ++] = j;
          s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '0', s[i][j] = '0';
          num -= 2;
        }


        
        else if(s[i - 1][j - 1] == '1' && s[i - 1][j] == '1' && s[i][j - 1] == '0' && s[i][j] == '1'){
          x1[k] = i - 1, yy[k] = j - 1,   x2[k] = i - 1, y2[k] = j,       x3[k] = i,     y3[k ++] = j;
          s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '0', s[i][j] = '0';
          num -= 3;
        }
        
        else if(s[i - 1][j - 1] == '1' && s[i - 1][j] == '1' && s[i][j - 1] == '1' && s[i][j] == '0'){
          x1[k] = i - 1, yy[k] = j - 1,   x2[k] = i - 1, y2[k] = j,       x3[k] = i,     y3[k ++] = j - 1;
          s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '0', s[i][j] = '0';
          num -= 3;
        }
        
        else if(s[i - 1][j - 1] == '1' && s[i - 1][j] == '0' && s[i][j - 1] == '1' && s[i][j] == '1'){
          x1[k] = i - 1, yy[k] = j - 1,   x2[k] = i, y2[k] = j - 1,       x3[k] = i,     y3[k ++] = j;
          s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '0', s[i][j] = '0';
          num -= 3;
        }
        
        else if(s[i - 1][j - 1] == '0' && s[i - 1][j] == '1' && s[i][j - 1] == '1' && s[i][j] == '1'){
          x1[k] = i - 1, yy[k] = j,   x2[k] = i, y2[k] = j - 1,       x3[k] = i,     y3[k ++] = j;
          s[i - 1][j - 1] = '0', s[i - 1][j] = '0', s[i][j - 1] = '0', s[i][j] = '0';
          num -= 3;
        }
}

void solve()
{
    int f = 0;
    while(num != 0){
        for(int i = 1; i < n; i ++){
          if(i == n - 1)    {f = 1; break;}
          for(int j = 1; j < m; j ++){
                calc(i, j);
            

            if(num == 0)    break;

          }
          if(num == 0)      break;
        }
        if(f)   break;
    }

    if(f){
        while(num != 0){
            for(int j = 1; j < m; ){
                if(m & 1)   calc2(n - 1, j), j ++;
                else        calc(n - 1, j), j ++;
                if(num == 0)    break;
            }
        }
    }

  printf("%d\n", k);
  for(int i = 0; i < k; i ++){
    printf("%d %d %d %d %d %d\n", ++ x1[i], ++ yy[i], ++ x2[i], ++ y2[i], ++ x3[i], ++ y3[i]);
  }
  init();
}


int main()
{
  cin >> t;
  while(t --){
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
      for(int j = 0; j < m; j ++){
        cin >> s[i][j];
        if(s[i][j] == '1')  num ++;
      }
    solve();
  }
  return 0;
}
