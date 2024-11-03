

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stack>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <cassert>
using namespace std;
#define pb push_back
#define INF 1001001001
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)((x).size()))
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (__typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

const int OFF = 8 * 30 + 10;
int dp[10][2 * OFF][2 * OFF];

void go (int n, int r) {
   vector<pii> pts;
   REP(x,-r,r) REP(y,-r,r) if (x*x + y*y <= r*r) pts.pb(mp(x,y));
   

   FOR(i,10) FOR(j,2*OFF) FOR(k,2*OFF) dp[i][j][k] = -INF;
   dp[0][0+OFF][0+OFF] = 0;
   FOR(i,n) {
      REP(sx,-n*r,n*r) REP(sy,-n*r,n*r) {
         if (-INF != dp[i][sx+OFF][sy+OFF]) {
            FOREACH(it,pts) {
               int x = it->fi, y = it->se;
               REMAX(dp[i+1][sx+x+OFF][sy+y+OFF], dp[i][sx+OFF][sy+OFF] + x*x + y*y);
            }
         }
      }
   }
   pair<int,pii> best;
   best.fi = -INF;
   REP(sx,-n*r,n*r) REP(sy,-n*r,n*r) if (-INF != dp[n][sx+OFF][sy+OFF]) {
      int cand = n * dp[n][sx+OFF][sy+OFF] - sx * sx - sy * sy;
      REMAX(best, mp(cand, mp(sx,sy)));
   }
   int sx = best.se.fi, sy = best.se.se;
   printf("%d\\n", best.fi);
   REPD(i,n,1) {
      

      FOREACH(it,pts) {
         int x = it->fi, y = it->se;
         if (dp[i][sx+OFF][sy+OFF] == dp[i-1][sx-x+OFF][sy-y+OFF] + x*x + y*y) {
            printf("%d %d\\n", x, y);
            sx -= x;
            sy -= y;
            break;
         }
      }
   }
}

int smain () {
   REP(n,1,8) REP(r,1,30) {
      printf("res[%d][%d] = \"", n, r);
      go(n, r);
      DBG(mp(n,r))
      printf("\";\n");
   }
}

string res[10][33];

int main () {
res[1][1] = "0\n1 0\n";
res[1][2] = "0\n2 0\n";
res[1][3] = "0\n3 0\n";
res[1][4] = "0\n4 0\n";
res[1][5] = "0\n5 0\n";
res[1][6] = "0\n6 0\n";
res[1][7] = "0\n7 0\n";
res[1][8] = "0\n8 0\n";
res[1][9] = "0\n9 0\n";
res[1][10] = "0\n10 0\n";
res[1][11] = "0\n11 0\n";
res[1][12] = "0\n12 0\n";
res[1][13] = "0\n13 0\n";
res[1][14] = "0\n14 0\n";
res[1][15] = "0\n15 0\n";
res[1][16] = "0\n16 0\n";
res[1][17] = "0\n17 0\n";
res[1][18] = "0\n18 0\n";
res[1][19] = "0\n19 0\n";
res[1][20] = "0\n20 0\n";
res[1][21] = "0\n21 0\n";
res[1][22] = "0\n22 0\n";
res[1][23] = "0\n23 0\n";
res[1][24] = "0\n24 0\n";
res[1][25] = "0\n25 0\n";
res[1][26] = "0\n26 0\n";
res[1][27] = "0\n27 0\n";
res[1][28] = "0\n28 0\n";
res[1][29] = "0\n29 0\n";
res[1][30] = "0\n30 0\n";
res[2][1] = "4\n-1 0\n1 0\n";
res[2][2] = "16\n-2 0\n2 0\n";
res[2][3] = "36\n-3 0\n3 0\n";
res[2][4] = "64\n-4 0\n4 0\n";
res[2][5] = "100\n-5 0\n5 0\n";
res[2][6] = "144\n-6 0\n6 0\n";
res[2][7] = "196\n-7 0\n7 0\n";
res[2][8] = "256\n-8 0\n8 0\n";
res[2][9] = "324\n-9 0\n9 0\n";
res[2][10] = "400\n-10 0\n10 0\n";
res[2][11] = "484\n-11 0\n11 0\n";
res[2][12] = "576\n-12 0\n12 0\n";
res[2][13] = "676\n-13 0\n13 0\n";
res[2][14] = "784\n-14 0\n14 0\n";
res[2][15] = "900\n-15 0\n15 0\n";
res[2][16] = "1024\n-16 0\n16 0\n";
res[2][17] = "1156\n-17 0\n17 0\n";
res[2][18] = "1296\n-18 0\n18 0\n";
res[2][19] = "1444\n-19 0\n19 0\n";
res[2][20] = "1600\n-20 0\n20 0\n";
res[2][21] = "1764\n-21 0\n21 0\n";
res[2][22] = "1936\n-22 0\n22 0\n";
res[2][23] = "2116\n-23 0\n23 0\n";
res[2][24] = "2304\n-24 0\n24 0\n";
res[2][25] = "2500\n-25 0\n25 0\n";
res[2][26] = "2704\n-26 0\n26 0\n";
res[2][27] = "2916\n-27 0\n27 0\n";
res[2][28] = "3136\n-28 0\n28 0\n";
res[2][29] = "3364\n-29 0\n29 0\n";
res[2][30] = "3600\n-30 0\n30 0\n";
res[3][1] = "8\n-1 0\n1 0\n1 0\n";
res[3][2] = "32\n-2 0\n2 0\n2 0\n";
res[3][3] = "76\n-2 -2\n0 3\n3 0\n";
res[3][4] = "130\n-2 -3\n0 4\n4 0\n";
res[3][5] = "224\n-5 0\n3 -4\n3 4\n";
res[3][6] = "312\n-6 0\n3 -5\n3 5\n";
res[3][7] = "416\n-3 -6\n-3 6\n7 0\n";
res[3][8] = "554\n-5 -6\n0 8\n8 0\n";
res[3][9] = "722\n-4 -8\n-4 8\n9 0\n";
res[3][10] = "896\n-10 0\n6 -8\n6 8\n";
res[3][11] = "1064\n-11 0\n6 -9\n6 9\n";
res[3][12] = "1248\n-12 0\n6 -10\n6 10\n";
res[3][13] = "1512\n-5 -12\n-5 12\n13 0\n";
res[3][14] = "1746\n-14 0\n7 -12\n7 12\n";
res[3][15] = "2016\n-15 0\n9 -12\n9 12\n";
res[3][16] = "2264\n-16 0\n9 -13\n9 13\n";
res[3][17] = "2600\n-8 -15\n-8 15\n17 0\n";
res[3][18] = "2888\n-8 -16\n-8 16\n18 0\n";
res[3][19] = "3218\n-10 -16\n-6 18\n19 0\n";
res[3][20] = "3584\n-20 0\n12 -16\n12 16\n";
res[3][21] = "3912\n-17 -12\n0 21\n20 -6\n";
res[3][22] = "4344\n-22 0\n11 -19\n11 19\n";
res[3][23] = "4712\n-11 -20\n-11 20\n23 0\n";
res[3][24] = "5138\n-24 0\n13 -20\n13 20\n";
res[3][25] = "5612\n-24 -7\n7 24\n20 -15\n";
res[3][26] = "6062\n-12 -23\n-12 23\n26 0\n";
res[3][27] = "6536\n-27 0\n14 -23\n14 23\n";
res[3][28] = "6984\n-28 0\n14 -24\n14 24\n";
res[3][29] = "7520\n-20 -21\n-7 28\n28 -7\n";
res[3][30] = "8084\n-24 18\n0 -30\n27 13\n";
res[4][1] = "16\n-1 0\n-1 0\n1 0\n1 0\n";
res[4][2] = "64\n-2 0\n-2 0\n2 0\n2 0\n";
res[4][3] = "144\n-3 0\n-3 0\n3 0\n3 0\n";
res[4][4] = "256\n-4 0\n-4 0\n4 0\n4 0\n";
res[4][5] = "400\n-5 0\n-5 0\n5 0\n5 0\n";
res[4][6] = "576\n-6 0\n-6 0\n6 0\n6 0\n";
res[4][7] = "784\n-7 0\n-7 0\n7 0\n7 0\n";
res[4][8] = "1024\n-8 0\n-8 0\n8 0\n8 0\n";
res[4][9] = "1296\n-9 0\n-9 0\n9 0\n9 0\n";
res[4][10] = "1600\n-10 0\n-10 0\n10 0\n10 0\n";
res[4][11] = "1936\n-11 0\n-11 0\n11 0\n11 0\n";
res[4][12] = "2304\n-12 0\n-12 0\n12 0\n12 0\n";
res[4][13] = "2704\n-13 0\n-13 0\n13 0\n13 0\n";
res[4][14] = "3136\n-14 0\n-14 0\n14 0\n14 0\n";
res[4][15] = "3600\n-15 0\n-15 0\n15 0\n15 0\n";
res[4][16] = "4096\n-16 0\n-16 0\n16 0\n16 0\n";
res[4][17] = "4624\n-17 0\n-17 0\n17 0\n17 0\n";
res[4][18] = "5184\n-18 0\n-18 0\n18 0\n18 0\n";
res[4][19] = "5776\n-19 0\n-19 0\n19 0\n19 0\n";
res[4][20] = "6400\n-20 0\n-20 0\n20 0\n20 0\n";
res[4][21] = "7056\n-21 0\n-21 0\n21 0\n21 0\n";
res[4][22] = "7744\n-22 0\n-22 0\n22 0\n22 0\n";
res[4][23] = "8464\n-23 0\n-23 0\n23 0\n23 0\n";
res[4][24] = "9216\n-24 0\n-24 0\n24 0\n24 0\n";
res[4][25] = "10000\n-25 0\n-25 0\n25 0\n25 0\n";
res[4][26] = "10816\n-26 0\n-26 0\n26 0\n26 0\n";
res[4][27] = "11664\n-27 0\n-27 0\n27 0\n27 0\n";
res[4][28] = "12544\n-28 0\n-28 0\n28 0\n28 0\n";
res[4][29] = "13456\n-29 0\n-29 0\n29 0\n29 0\n";
res[4][30] = "14400\n-30 0\n-30 0\n30 0\n30 0\n";
res[5][1] = "24\n-1 0\n-1 0\n1 0\n1 0\n1 0\n";
res[5][2] = "96\n-2 0\n-2 0\n2 0\n2 0\n2 0\n";
res[5][3] = "218\n-3 0\n-2 -2\n0 3\n3 0\n3 0\n";
res[5][4] = "384\n-4 0\n-4 0\n4 0\n4 0\n4 0\n";
res[5][5] = "624\n-5 0\n-5 0\n3 -4\n3 4\n5 0\n";
res[5][6] = "880\n-6 0\n-3 -5\n0 6\n6 0\n6 0\n";
res[5][7] = "1188\n-7 0\n-3 -6\n0 7\n7 0\n7 0\n";
res[5][8] = "1572\n-8 0\n-5 -6\n0 8\n8 0\n8 0\n";
res[5][9] = "2014\n-9 0\n-4 -8\n-4 8\n9 0\n9 0\n";
res[5][10] = "2496\n-10 0\n-10 0\n6 -8\n6 8\n10 0\n";
res[5][11] = "2984\n-11 0\n-11 0\n6 -9\n6 9\n11 0\n";
res[5][12] = "3520\n-12 0\n-6 -10\n0 12\n12 0\n12 0\n";
res[5][13] = "4224\n-13 0\n-5 -12\n-5 12\n12 -5\n12 5\n";
res[5][14] = "4870\n-14 0\n-7 -12\n-5 13\n14 0\n14 0\n";
res[5][15] = "5616\n-15 0\n-15 0\n9 -12\n9 12\n15 0\n";
res[5][16] = "6336\n-16 0\n-16 0\n9 -13\n9 13\n16 0\n";
res[5][17] = "7224\n-17 0\n-8 -15\n-8 15\n17 0\n17 0\n";
res[5][18] = "8056\n-18 0\n-8 -16\n-8 16\n18 0\n18 0\n";
res[5][19] = "9008\n-18 -6\n-18 -6\n0 19\n18 -6\n19 0\n";
res[5][20] = "9984\n-20 0\n-20 0\n12 -16\n12 16\n20 0\n";
res[5][21] = "10942\n-21 0\n-17 -12\n0 21\n20 -6\n21 0\n";
res[5][22] = "12080\n-22 0\n-22 0\n11 -19\n11 19\n22 0\n";
res[5][23] = "13144\n-23 0\n-11 -20\n-11 20\n23 0\n23 0\n";
res[5][24] = "14326\n-24 0\n-24 0\n13 -20\n13 20\n24 0\n";
res[5][25] = "15624\n-25 0\n-7 -24\n-7 24\n20 -15\n20 15\n";
res[5][26] = "16896\n-26 0\n-10 -24\n-10 24\n24 -10\n24 10\n";
res[5][27] = "18184\n-27 0\n-27 0\n14 -23\n14 23\n27 0\n";
res[5][28] = "19488\n-28 0\n-22 -17\n0 28\n26 -10\n28 0\n";
res[5][29] = "20968\n-29 0\n-7 -28\n0 29\n20 -21\n20 21\n";
res[5][30] = "22480\n-30 0\n-24 18\n0 -30\n27 13\n30 0\n";
res[6][1] = "36\n-1 0\n-1 0\n-1 0\n1 0\n1 0\n1 0\n";
res[6][2] = "144\n-2 0\n-2 0\n-2 0\n2 0\n2 0\n2 0\n";
res[6][3] = "324\n-3 0\n-3 0\n-3 0\n3 0\n3 0\n3 0\n";
res[6][4] = "576\n-4 0\n-4 0\n-4 0\n4 0\n4 0\n4 0\n";
res[6][5] = "900\n-5 0\n-5 0\n-5 0\n5 0\n5 0\n5 0\n";
res[6][6] = "1296\n-6 0\n-6 0\n-6 0\n6 0\n6 0\n6 0\n";
res[6][7] = "1764\n-7 0\n-7 0\n-7 0\n7 0\n7 0\n7 0\n";
res[6][8] = "2304\n-8 0\n-8 0\n-8 0\n8 0\n8 0\n8 0\n";
res[6][9] = "2916\n-9 0\n-9 0\n-9 0\n9 0\n9 0\n9 0\n";
res[6][10] = "3600\n-10 0\n-10 0\n-10 0\n10 0\n10 0\n10 0\n";
res[6][11] = "4356\n-11 0\n-11 0\n-11 0\n11 0\n11 0\n11 0\n";
res[6][12] = "5184\n-12 0\n-12 0\n-12 0\n12 0\n12 0\n12 0\n";
res[6][13] = "6084\n-13 0\n-13 0\n-13 0\n13 0\n13 0\n13 0\n";
res[6][14] = "7056\n-14 0\n-14 0\n-14 0\n14 0\n14 0\n14 0\n";
res[6][15] = "8100\n-15 0\n-15 0\n-15 0\n15 0\n15 0\n15 0\n";
res[6][16] = "9216\n-16 0\n-16 0\n-16 0\n16 0\n16 0\n16 0\n";
res[6][17] = "10404\n-17 0\n-17 0\n-17 0\n17 0\n17 0\n17 0\n";
res[6][18] = "11664\n-18 0\n-18 0\n-18 0\n18 0\n18 0\n18 0\n";
res[6][19] = "12996\n-19 0\n-19 0\n-19 0\n19 0\n19 0\n19 0\n";
res[6][20] = "14400\n-20 0\n-20 0\n-20 0\n20 0\n20 0\n20 0\n";
res[6][21] = "15876\n-21 0\n-21 0\n-21 0\n21 0\n21 0\n21 0\n";
res[6][22] = "17424\n-22 0\n-22 0\n-22 0\n22 0\n22 0\n22 0\n";
res[6][23] = "19044\n-23 0\n-23 0\n-23 0\n23 0\n23 0\n23 0\n";
res[6][24] = "20736\n-24 0\n-24 0\n-24 0\n24 0\n24 0\n24 0\n";
res[6][25] = "22500\n-25 0\n-25 0\n-25 0\n25 0\n25 0\n25 0\n";
res[6][26] = "24336\n-26 0\n-26 0\n-26 0\n26 0\n26 0\n26 0\n";
res[6][27] = "26244\n-27 0\n-27 0\n-27 0\n27 0\n27 0\n27 0\n";
res[6][28] = "28224\n-28 0\n-28 0\n-28 0\n28 0\n28 0\n28 0\n";
res[6][29] = "30276\n-29 0\n-29 0\n-29 0\n29 0\n29 0\n29 0\n";
res[6][30] = "32400\n-30 0\n-30 0\n-30 0\n30 0\n30 0\n30 0\n";
res[7][1] = "48\n-1 0\n-1 0\n-1 0\n1 0\n1 0\n1 0\n1 0\n";
res[7][2] = "192\n-2 0\n-2 0\n-2 0\n2 0\n2 0\n2 0\n2 0\n";
res[7][3] = "432\n-3 0\n-3 0\n-3 0\n3 0\n3 0\n3 0\n3 0\n";
res[7][4] = "768\n-4 0\n-4 0\n-4 0\n4 0\n4 0\n4 0\n4 0\n";
res[7][5] = "1224\n-5 0\n-5 0\n-5 0\n3 -4\n3 4\n5 0\n5 0\n";
res[7][6] = "1740\n-6 0\n-6 0\n-3 -5\n0 6\n6 0\n6 0\n6 0\n";
res[7][7] = "2356\n-7 0\n-7 0\n-3 -6\n0 7\n7 0\n7 0\n7 0\n";
res[7][8] = "3102\n-8 0\n-8 0\n-5 -6\n0 8\n8 0\n8 0\n8 0\n";
res[7][9] = "3954\n-9 0\n-9 0\n-4 -8\n-4 8\n9 0\n9 0\n9 0\n";
res[7][10] = "4896\n-10 0\n-10 0\n-10 0\n6 -8\n6 8\n10 0\n10 0\n";
res[7][11] = "5872\n-11 0\n-11 0\n-6 -9\n0 11\n11 0\n11 0\n11 0\n";
res[7][12] = "6960\n-12 0\n-12 0\n-6 -10\n0 12\n12 0\n12 0\n12 0\n";
res[7][13] = "8280\n-13 0\n-13 0\n-5 -12\n-5 12\n12 -5\n12 5\n13 0\n";
res[7][14] = "9564\n-14 0\n-14 0\n-7 -12\n-5 13\n14 0\n14 0\n14 0\n";
res[7][15] = "11016\n-15 0\n-15 0\n-15 0\n9 -12\n9 12\n15 0\n15 0\n";
res[7][16] = "12456\n-16 0\n-16 0\n-16 0\n9 -13\n9 13\n16 0\n16 0\n";
res[7][17] = "14160\n-17 0\n-17 0\n-8 -15\n-8 15\n17 0\n17 0\n17 0\n";
res[7][18] = "15816\n-18 0\n-18 0\n-8 -16\n-8 16\n18 0\n18 0\n18 0\n";
res[7][19] = "17666\n-19 0\n-18 -6\n-18 -6\n0 19\n18 -6\n19 0\n19 0\n";
res[7][20] = "19584\n-20 0\n-20 0\n-20 0\n12 -16\n12 16\n20 0\n20 0\n";
res[7][21] = "21500\n-21 0\n-21 0\n-17 -12\n0 21\n20 -6\n21 0\n21 0\n";
res[7][22] = "23688\n-22 0\n-22 0\n-22 0\n11 -19\n11 19\n22 0\n22 0\n";
res[7][23] = "25808\n-23 0\n-23 0\n-11 -20\n-11 20\n23 0\n23 0\n23 0\n";
res[7][24] = "28122\n-24 0\n-24 0\n-24 0\n13 -20\n13 20\n24 0\n24 0\n";
res[7][25] = "30624\n-25 0\n-25 0\n-7 -24\n-7 24\n20 -15\n20 15\n25 0\n";
res[7][26] = "33120\n-26 0\n-26 0\n-10 -24\n-10 24\n24 -10\n24 10\n26 0\n";
res[7][27] = "35664\n-27 0\n-27 0\n-27 0\n14 -23\n14 23\n27 0\n27 0\n";
res[7][28] = "38266\n-28 0\n-28 0\n-22 -17\n0 28\n26 -10\n28 0\n28 0\n";
res[7][29] = "41200\n-21 -20\n-21 -20\n-21 20\n-21 20\n29 0\n29 0\n29 0\n";
res[7][30] = "44076\n-30 0\n-30 0\n-30 0\n18 24\n24 -18\n24 -18\n27 13\n";
res[8][1] = "64\n-1 0\n-1 0\n-1 0\n-1 0\n1 0\n1 0\n1 0\n1 0\n";
res[8][2] = "256\n-2 0\n-2 0\n-2 0\n-2 0\n2 0\n2 0\n2 0\n2 0\n";
res[8][3] = "576\n-3 0\n-3 0\n-3 0\n-3 0\n3 0\n3 0\n3 0\n3 0\n";
res[8][4] = "1024\n-4 0\n-4 0\n-4 0\n-4 0\n4 0\n4 0\n4 0\n4 0\n";
res[8][5] = "1600\n-5 0\n-5 0\n-5 0\n-5 0\n5 0\n5 0\n5 0\n5 0\n";
res[8][6] = "2304\n-6 0\n-6 0\n-6 0\n-6 0\n6 0\n6 0\n6 0\n6 0\n";
res[8][7] = "3136\n-7 0\n-7 0\n-7 0\n-7 0\n7 0\n7 0\n7 0\n7 0\n";
res[8][8] = "4096\n-8 0\n-8 0\n-8 0\n-8 0\n8 0\n8 0\n8 0\n8 0\n";
res[8][9] = "5184\n-9 0\n-9 0\n-9 0\n-9 0\n9 0\n9 0\n9 0\n9 0\n";
res[8][10] = "6400\n-10 0\n-10 0\n-10 0\n-10 0\n10 0\n10 0\n10 0\n10 0\n";
res[8][11] = "7744\n-11 0\n-11 0\n-11 0\n-11 0\n11 0\n11 0\n11 0\n11 0\n";
res[8][12] = "9216\n-12 0\n-12 0\n-12 0\n-12 0\n12 0\n12 0\n12 0\n12 0\n";
res[8][13] = "10816\n-13 0\n-13 0\n-13 0\n-13 0\n13 0\n13 0\n13 0\n13 0\n";
res[8][14] = "12544\n-14 0\n-14 0\n-14 0\n-14 0\n14 0\n14 0\n14 0\n14 0\n";
res[8][15] = "14400\n-15 0\n-15 0\n-15 0\n-15 0\n15 0\n15 0\n15 0\n15 0\n";
res[8][16] = "16384\n-16 0\n-16 0\n-16 0\n-16 0\n16 0\n16 0\n16 0\n16 0\n";
res[8][17] = "18496\n-17 0\n-17 0\n-17 0\n-17 0\n17 0\n17 0\n17 0\n17 0\n";
res[8][18] = "20736\n-18 0\n-18 0\n-18 0\n-18 0\n18 0\n18 0\n18 0\n18 0\n";
res[8][19] = "23104\n-19 0\n-19 0\n-19 0\n-19 0\n19 0\n19 0\n19 0\n19 0\n";
res[8][20] = "25600\n-20 0\n-20 0\n-20 0\n-20 0\n20 0\n20 0\n20 0\n20 0\n";
res[8][21] = "28224\n-21 0\n-21 0\n-21 0\n-21 0\n21 0\n21 0\n21 0\n21 0\n";
res[8][22] = "30976\n-22 0\n-22 0\n-22 0\n-22 0\n22 0\n22 0\n22 0\n22 0\n";
res[8][23] = "33856\n-23 0\n-23 0\n-23 0\n-23 0\n23 0\n23 0\n23 0\n23 0\n";
res[8][24] = "36864\n-24 0\n-24 0\n-24 0\n-24 0\n24 0\n24 0\n24 0\n24 0\n";
res[8][25] = "40000\n-25 0\n-25 0\n-25 0\n-25 0\n25 0\n25 0\n25 0\n25 0\n";
res[8][26] = "43264\n-26 0\n-26 0\n-26 0\n-26 0\n26 0\n26 0\n26 0\n26 0\n";
res[8][27] = "46656\n-27 0\n-27 0\n-27 0\n-27 0\n27 0\n27 0\n27 0\n27 0\n";
res[8][28] = "50176\n-28 0\n-28 0\n-28 0\n-28 0\n28 0\n28 0\n28 0\n28 0\n";
res[8][29] = "53824\n-29 0\n-29 0\n-29 0\n-29 0\n29 0\n29 0\n29 0\n29 0\n";
res[8][30] = "57600\n-30 0\n-30 0\n-30 0\n-30 0\n30 0\n30 0\n30 0\n30 0\n";

wez2(n,r);
cout << res[n][r];
}

