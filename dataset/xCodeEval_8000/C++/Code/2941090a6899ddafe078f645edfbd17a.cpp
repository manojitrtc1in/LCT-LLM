#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <cstring>
#include <cstdio>
#include <climits>

#define PII pair < int , int >
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define LL long long
#define NMAX 40

using namespace std;

int N,K;
vector< PII > solution[NMAX][NMAX];
vector< PII > :: iterator i;
int MAX[NMAX][NMAX];

int main()
{
#ifndef ONLINE_JUDGE
freopen("a.in","r",stdin);
freopen("a.out","w",stdout);
#endif

MAX[2][1]=4;
solution[2][1].push_back(make_pair(-1,0));
solution[2][1].push_back(make_pair(1,0));

MAX[2][2]=16;
solution[2][2].push_back(make_pair(-2,0));
solution[2][2].push_back(make_pair(2,0));

MAX[2][3]=36;
solution[2][3].push_back(make_pair(-3,0));
solution[2][3].push_back(make_pair(3,0));

MAX[2][4]=64;
solution[2][4].push_back(make_pair(-4,0));
solution[2][4].push_back(make_pair(4,0));

MAX[2][5]=100;
solution[2][5].push_back(make_pair(-5,0));
solution[2][5].push_back(make_pair(5,0));

MAX[2][6]=144;
solution[2][6].push_back(make_pair(-6,0));
solution[2][6].push_back(make_pair(6,0));

MAX[2][7]=196;
solution[2][7].push_back(make_pair(-7,0));
solution[2][7].push_back(make_pair(7,0));

MAX[2][8]=256;
solution[2][8].push_back(make_pair(-8,0));
solution[2][8].push_back(make_pair(8,0));

MAX[2][9]=324;
solution[2][9].push_back(make_pair(-9,0));
solution[2][9].push_back(make_pair(9,0));

MAX[2][10]=400;
solution[2][10].push_back(make_pair(-10,0));
solution[2][10].push_back(make_pair(10,0));

MAX[2][11]=484;
solution[2][11].push_back(make_pair(-11,0));
solution[2][11].push_back(make_pair(11,0));

MAX[2][12]=576;
solution[2][12].push_back(make_pair(-12,0));
solution[2][12].push_back(make_pair(12,0));

MAX[2][13]=676;
solution[2][13].push_back(make_pair(-13,0));
solution[2][13].push_back(make_pair(13,0));

MAX[2][14]=784;
solution[2][14].push_back(make_pair(-14,0));
solution[2][14].push_back(make_pair(14,0));

MAX[2][15]=900;
solution[2][15].push_back(make_pair(-15,0));
solution[2][15].push_back(make_pair(15,0));

MAX[2][16]=1024;
solution[2][16].push_back(make_pair(-16,0));
solution[2][16].push_back(make_pair(16,0));

MAX[2][17]=1156;
solution[2][17].push_back(make_pair(-17,0));
solution[2][17].push_back(make_pair(17,0));

MAX[2][18]=1296;
solution[2][18].push_back(make_pair(-18,0));
solution[2][18].push_back(make_pair(18,0));

MAX[2][19]=1444;
solution[2][19].push_back(make_pair(-19,0));
solution[2][19].push_back(make_pair(19,0));

MAX[2][20]=1600;
solution[2][20].push_back(make_pair(-20,0));
solution[2][20].push_back(make_pair(20,0));

MAX[2][21]=1764;
solution[2][21].push_back(make_pair(-21,0));
solution[2][21].push_back(make_pair(21,0));

MAX[2][22]=1936;
solution[2][22].push_back(make_pair(-22,0));
solution[2][22].push_back(make_pair(22,0));

MAX[2][23]=2116;
solution[2][23].push_back(make_pair(-23,0));
solution[2][23].push_back(make_pair(23,0));

MAX[2][24]=2304;
solution[2][24].push_back(make_pair(-24,0));
solution[2][24].push_back(make_pair(24,0));

MAX[2][25]=2500;
solution[2][25].push_back(make_pair(-25,0));
solution[2][25].push_back(make_pair(25,0));

MAX[2][26]=2704;
solution[2][26].push_back(make_pair(-26,0));
solution[2][26].push_back(make_pair(26,0));

MAX[2][27]=2916;
solution[2][27].push_back(make_pair(-27,0));
solution[2][27].push_back(make_pair(27,0));

MAX[2][28]=3136;
solution[2][28].push_back(make_pair(-28,0));
solution[2][28].push_back(make_pair(28,0));

MAX[2][29]=3364;
solution[2][29].push_back(make_pair(-29,0));
solution[2][29].push_back(make_pair(29,0));

MAX[2][30]=3600;
solution[2][30].push_back(make_pair(-30,0));
solution[2][30].push_back(make_pair(30,0));

MAX[3][1]=8;
solution[3][1].push_back(make_pair(-1,0));
solution[3][1].push_back(make_pair(-1,0));
solution[3][1].push_back(make_pair(1,0));

MAX[3][2]=32;
solution[3][2].push_back(make_pair(-2,0));
solution[3][2].push_back(make_pair(-2,0));
solution[3][2].push_back(make_pair(2,0));

MAX[3][3]=76;
solution[3][3].push_back(make_pair(-3,0));
solution[3][3].push_back(make_pair(0,-3));
solution[3][3].push_back(make_pair(2,2));

MAX[3][4]=130;
solution[3][4].push_back(make_pair(-4,0));
solution[3][4].push_back(make_pair(0,-4));
solution[3][4].push_back(make_pair(2,3));

MAX[3][5]=224;
solution[3][5].push_back(make_pair(-5,0));
solution[3][5].push_back(make_pair(3,-4));
solution[3][5].push_back(make_pair(3,4));

MAX[3][6]=312;
solution[3][6].push_back(make_pair(-6,0));
solution[3][6].push_back(make_pair(3,-5));
solution[3][6].push_back(make_pair(3,5));

MAX[3][7]=416;
solution[3][7].push_back(make_pair(-7,0));
solution[3][7].push_back(make_pair(3,-6));
solution[3][7].push_back(make_pair(3,6));

MAX[3][8]=554;
solution[3][8].push_back(make_pair(-8,0));
solution[3][8].push_back(make_pair(0,-8));
solution[3][8].push_back(make_pair(5,6));

MAX[3][9]=722;
solution[3][9].push_back(make_pair(-9,0));
solution[3][9].push_back(make_pair(4,-8));
solution[3][9].push_back(make_pair(4,8));

MAX[3][10]=896;
solution[3][10].push_back(make_pair(-10,0));
solution[3][10].push_back(make_pair(6,-8));
solution[3][10].push_back(make_pair(6,8));

MAX[3][11]=1064;
solution[3][11].push_back(make_pair(-11,0));
solution[3][11].push_back(make_pair(6,-9));
solution[3][11].push_back(make_pair(6,9));

MAX[3][12]=1248;
solution[3][12].push_back(make_pair(-12,0));
solution[3][12].push_back(make_pair(6,-10));
solution[3][12].push_back(make_pair(6,10));

MAX[3][13]=1512;
solution[3][13].push_back(make_pair(-13,0));
solution[3][13].push_back(make_pair(5,-12));
solution[3][13].push_back(make_pair(5,12));

MAX[3][14]=1746;
solution[3][14].push_back(make_pair(-14,0));
solution[3][14].push_back(make_pair(7,-12));
solution[3][14].push_back(make_pair(7,12));

MAX[3][15]=2016;
solution[3][15].push_back(make_pair(-15,0));
solution[3][15].push_back(make_pair(9,-12));
solution[3][15].push_back(make_pair(9,12));

MAX[3][16]=2264;
solution[3][16].push_back(make_pair(-16,0));
solution[3][16].push_back(make_pair(9,-13));
solution[3][16].push_back(make_pair(9,13));

MAX[3][17]=2600;
solution[3][17].push_back(make_pair(-17,0));
solution[3][17].push_back(make_pair(8,-15));
solution[3][17].push_back(make_pair(8,15));

MAX[3][18]=2888;
solution[3][18].push_back(make_pair(-18,0));
solution[3][18].push_back(make_pair(8,-16));
solution[3][18].push_back(make_pair(8,16));

MAX[3][19]=3218;
solution[3][19].push_back(make_pair(-19,0));
solution[3][19].push_back(make_pair(6,-18));
solution[3][19].push_back(make_pair(10,16));

MAX[3][20]=3584;
solution[3][20].push_back(make_pair(-20,0));
solution[3][20].push_back(make_pair(12,-16));
solution[3][20].push_back(make_pair(12,16));

MAX[3][21]=3912;
solution[3][21].push_back(make_pair(-21,0));
solution[3][21].push_back(make_pair(6,-20));
solution[3][21].push_back(make_pair(12,17));

MAX[3][22]=4344;
solution[3][22].push_back(make_pair(-22,0));
solution[3][22].push_back(make_pair(11,-19));
solution[3][22].push_back(make_pair(11,19));

MAX[3][23]=4712;
solution[3][23].push_back(make_pair(-23,0));
solution[3][23].push_back(make_pair(11,-20));
solution[3][23].push_back(make_pair(11,20));

MAX[3][24]=5138;
solution[3][24].push_back(make_pair(-24,0));
solution[3][24].push_back(make_pair(13,-20));
solution[3][24].push_back(make_pair(13,20));

MAX[3][25]=5612;
solution[3][25].push_back(make_pair(-24,-7));
solution[3][25].push_back(make_pair(7,24));
solution[3][25].push_back(make_pair(15,-20));

MAX[3][26]=6062;
solution[3][26].push_back(make_pair(-26,0));
solution[3][26].push_back(make_pair(12,-23));
solution[3][26].push_back(make_pair(12,23));

MAX[3][27]=6536;
solution[3][27].push_back(make_pair(-27,0));
solution[3][27].push_back(make_pair(14,-23));
solution[3][27].push_back(make_pair(14,23));

MAX[3][28]=6984;
solution[3][28].push_back(make_pair(-28,0));
solution[3][28].push_back(make_pair(14,-24));
solution[3][28].push_back(make_pair(14,24));

MAX[3][29]=7520;
solution[3][29].push_back(make_pair(-28,-7));
solution[3][29].push_back(make_pair(7,28));
solution[3][29].push_back(make_pair(20,-21));

MAX[3][30]=8084;
solution[3][30].push_back(make_pair(-30,0));
solution[3][30].push_back(make_pair(13,-27));
solution[3][30].push_back(make_pair(18,24));

MAX[4][1]=16;
solution[4][1].push_back(make_pair(-1,0));
solution[4][1].push_back(make_pair(-1,0));
solution[4][1].push_back(make_pair(1,0));
solution[4][1].push_back(make_pair(1,0));

MAX[4][2]=64;
solution[4][2].push_back(make_pair(-2,0));
solution[4][2].push_back(make_pair(-2,0));
solution[4][2].push_back(make_pair(2,0));
solution[4][2].push_back(make_pair(2,0));

MAX[4][3]=144;
solution[4][3].push_back(make_pair(-3,0));
solution[4][3].push_back(make_pair(-3,0));
solution[4][3].push_back(make_pair(3,0));
solution[4][3].push_back(make_pair(3,0));

MAX[4][4]=256;
solution[4][4].push_back(make_pair(-4,0));
solution[4][4].push_back(make_pair(-4,0));
solution[4][4].push_back(make_pair(4,0));
solution[4][4].push_back(make_pair(4,0));

MAX[4][5]=400;
solution[4][5].push_back(make_pair(-5,0));
solution[4][5].push_back(make_pair(-5,0));
solution[4][5].push_back(make_pair(5,0));
solution[4][5].push_back(make_pair(5,0));

MAX[4][6]=576;
solution[4][6].push_back(make_pair(-6,0));
solution[4][6].push_back(make_pair(-6,0));
solution[4][6].push_back(make_pair(6,0));
solution[4][6].push_back(make_pair(6,0));

MAX[4][7]=784;
solution[4][7].push_back(make_pair(-7,0));
solution[4][7].push_back(make_pair(-7,0));
solution[4][7].push_back(make_pair(7,0));
solution[4][7].push_back(make_pair(7,0));

MAX[4][8]=1024;
solution[4][8].push_back(make_pair(-8,0));
solution[4][8].push_back(make_pair(-8,0));
solution[4][8].push_back(make_pair(8,0));
solution[4][8].push_back(make_pair(8,0));

MAX[4][9]=1296;
solution[4][9].push_back(make_pair(-9,0));
solution[4][9].push_back(make_pair(-9,0));
solution[4][9].push_back(make_pair(9,0));
solution[4][9].push_back(make_pair(9,0));

MAX[4][10]=1600;
solution[4][10].push_back(make_pair(-10,0));
solution[4][10].push_back(make_pair(-10,0));
solution[4][10].push_back(make_pair(10,0));
solution[4][10].push_back(make_pair(10,0));

MAX[4][11]=1936;
solution[4][11].push_back(make_pair(-11,0));
solution[4][11].push_back(make_pair(-11,0));
solution[4][11].push_back(make_pair(11,0));
solution[4][11].push_back(make_pair(11,0));

MAX[4][12]=2304;
solution[4][12].push_back(make_pair(-12,0));
solution[4][12].push_back(make_pair(-12,0));
solution[4][12].push_back(make_pair(12,0));
solution[4][12].push_back(make_pair(12,0));

MAX[4][13]=2704;
solution[4][13].push_back(make_pair(-13,0));
solution[4][13].push_back(make_pair(-13,0));
solution[4][13].push_back(make_pair(13,0));
solution[4][13].push_back(make_pair(13,0));

MAX[4][14]=3136;
solution[4][14].push_back(make_pair(-14,0));
solution[4][14].push_back(make_pair(-14,0));
solution[4][14].push_back(make_pair(14,0));
solution[4][14].push_back(make_pair(14,0));

MAX[4][15]=3600;
solution[4][15].push_back(make_pair(-15,0));
solution[4][15].push_back(make_pair(-15,0));
solution[4][15].push_back(make_pair(15,0));
solution[4][15].push_back(make_pair(15,0));

MAX[4][16]=4096;
solution[4][16].push_back(make_pair(-16,0));
solution[4][16].push_back(make_pair(-16,0));
solution[4][16].push_back(make_pair(16,0));
solution[4][16].push_back(make_pair(16,0));

MAX[4][17]=4624;
solution[4][17].push_back(make_pair(-17,0));
solution[4][17].push_back(make_pair(-17,0));
solution[4][17].push_back(make_pair(17,0));
solution[4][17].push_back(make_pair(17,0));

MAX[4][18]=5184;
solution[4][18].push_back(make_pair(-18,0));
solution[4][18].push_back(make_pair(-18,0));
solution[4][18].push_back(make_pair(18,0));
solution[4][18].push_back(make_pair(18,0));

MAX[4][19]=5776;
solution[4][19].push_back(make_pair(-19,0));
solution[4][19].push_back(make_pair(-19,0));
solution[4][19].push_back(make_pair(19,0));
solution[4][19].push_back(make_pair(19,0));

MAX[4][20]=6400;
solution[4][20].push_back(make_pair(-20,0));
solution[4][20].push_back(make_pair(-20,0));
solution[4][20].push_back(make_pair(20,0));
solution[4][20].push_back(make_pair(20,0));

MAX[4][21]=7056;
solution[4][21].push_back(make_pair(-21,0));
solution[4][21].push_back(make_pair(-21,0));
solution[4][21].push_back(make_pair(21,0));
solution[4][21].push_back(make_pair(21,0));

MAX[4][22]=7744;
solution[4][22].push_back(make_pair(-22,0));
solution[4][22].push_back(make_pair(-22,0));
solution[4][22].push_back(make_pair(22,0));
solution[4][22].push_back(make_pair(22,0));

MAX[4][23]=8464;
solution[4][23].push_back(make_pair(-23,0));
solution[4][23].push_back(make_pair(-23,0));
solution[4][23].push_back(make_pair(23,0));
solution[4][23].push_back(make_pair(23,0));

MAX[4][24]=9216;
solution[4][24].push_back(make_pair(-24,0));
solution[4][24].push_back(make_pair(-24,0));
solution[4][24].push_back(make_pair(24,0));
solution[4][24].push_back(make_pair(24,0));

MAX[4][25]=10000;
solution[4][25].push_back(make_pair(-25,0));
solution[4][25].push_back(make_pair(-25,0));
solution[4][25].push_back(make_pair(25,0));
solution[4][25].push_back(make_pair(25,0));

MAX[4][26]=10816;
solution[4][26].push_back(make_pair(-26,0));
solution[4][26].push_back(make_pair(-26,0));
solution[4][26].push_back(make_pair(26,0));
solution[4][26].push_back(make_pair(26,0));

MAX[4][27]=11664;
solution[4][27].push_back(make_pair(-27,0));
solution[4][27].push_back(make_pair(-27,0));
solution[4][27].push_back(make_pair(27,0));
solution[4][27].push_back(make_pair(27,0));

MAX[4][28]=12544;
solution[4][28].push_back(make_pair(-28,0));
solution[4][28].push_back(make_pair(-28,0));
solution[4][28].push_back(make_pair(28,0));
solution[4][28].push_back(make_pair(28,0));

MAX[4][29]=13456;
solution[4][29].push_back(make_pair(-29,0));
solution[4][29].push_back(make_pair(-29,0));
solution[4][29].push_back(make_pair(29,0));
solution[4][29].push_back(make_pair(29,0));

MAX[4][30]=14400;
solution[4][30].push_back(make_pair(-30,0));
solution[4][30].push_back(make_pair(-30,0));
solution[4][30].push_back(make_pair(30,0));
solution[4][30].push_back(make_pair(30,0));

MAX[5][1]=24;
solution[5][1].push_back(make_pair(-1,0));
solution[5][1].push_back(make_pair(-1,0));
solution[5][1].push_back(make_pair(-1,0));
solution[5][1].push_back(make_pair(1,0));
solution[5][1].push_back(make_pair(1,0));

MAX[5][2]=96;
solution[5][2].push_back(make_pair(-2,0));
solution[5][2].push_back(make_pair(-2,0));
solution[5][2].push_back(make_pair(-2,0));
solution[5][2].push_back(make_pair(2,0));
solution[5][2].push_back(make_pair(2,0));

MAX[5][3]=218;
solution[5][3].push_back(make_pair(-3,0));
solution[5][3].push_back(make_pair(-3,0));
solution[5][3].push_back(make_pair(0,-3));
solution[5][3].push_back(make_pair(2,2));
solution[5][3].push_back(make_pair(3,0));

MAX[5][4]=384;
solution[5][4].push_back(make_pair(-4,0));
solution[5][4].push_back(make_pair(-4,0));
solution[5][4].push_back(make_pair(-4,0));
solution[5][4].push_back(make_pair(4,0));
solution[5][4].push_back(make_pair(4,0));

MAX[5][5]=624;
solution[5][5].push_back(make_pair(-5,0));
solution[5][5].push_back(make_pair(-5,0));
solution[5][5].push_back(make_pair(3,-4));
solution[5][5].push_back(make_pair(3,4));
solution[5][5].push_back(make_pair(5,0));

MAX[5][6]=880;
solution[5][6].push_back(make_pair(-6,0));
solution[5][6].push_back(make_pair(-6,0));
solution[5][6].push_back(make_pair(0,-6));
solution[5][6].push_back(make_pair(3,5));
solution[5][6].push_back(make_pair(6,0));

MAX[5][7]=1188;
solution[5][7].push_back(make_pair(-7,0));
solution[5][7].push_back(make_pair(-7,0));
solution[5][7].push_back(make_pair(0,-7));
solution[5][7].push_back(make_pair(3,6));
solution[5][7].push_back(make_pair(7,0));

MAX[5][8]=1572;
solution[5][8].push_back(make_pair(-8,0));
solution[5][8].push_back(make_pair(-8,0));
solution[5][8].push_back(make_pair(0,-8));
solution[5][8].push_back(make_pair(5,6));
solution[5][8].push_back(make_pair(8,0));

MAX[5][9]=2014;
solution[5][9].push_back(make_pair(-9,0));
solution[5][9].push_back(make_pair(-9,0));
solution[5][9].push_back(make_pair(4,-8));
solution[5][9].push_back(make_pair(4,8));
solution[5][9].push_back(make_pair(9,0));

MAX[5][10]=2496;
solution[5][10].push_back(make_pair(-10,0));
solution[5][10].push_back(make_pair(-10,0));
solution[5][10].push_back(make_pair(6,-8));
solution[5][10].push_back(make_pair(6,8));
solution[5][10].push_back(make_pair(10,0));

MAX[5][11]=2984;
solution[5][11].push_back(make_pair(-11,0));
solution[5][11].push_back(make_pair(-11,0));
solution[5][11].push_back(make_pair(6,-9));
solution[5][11].push_back(make_pair(6,9));
solution[5][11].push_back(make_pair(11,0));

MAX[5][12]=3520;
solution[5][12].push_back(make_pair(-12,0));
solution[5][12].push_back(make_pair(-12,0));
solution[5][12].push_back(make_pair(0,-12));
solution[5][12].push_back(make_pair(6,10));
solution[5][12].push_back(make_pair(12,0));

MAX[5][13]=4224;
solution[5][13].push_back(make_pair(-13,0));
solution[5][13].push_back(make_pair(-5,-12));
solution[5][13].push_back(make_pair(-5,12));
solution[5][13].push_back(make_pair(12,-5));
solution[5][13].push_back(make_pair(12,5));

MAX[5][14]=4870;
solution[5][14].push_back(make_pair(-14,0));
solution[5][14].push_back(make_pair(-14,0));
solution[5][14].push_back(make_pair(5,-13));
solution[5][14].push_back(make_pair(7,12));
solution[5][14].push_back(make_pair(14,0));

MAX[5][15]=5616;
solution[5][15].push_back(make_pair(-15,0));
solution[5][15].push_back(make_pair(-15,0));
solution[5][15].push_back(make_pair(9,-12));
solution[5][15].push_back(make_pair(9,12));
solution[5][15].push_back(make_pair(15,0));

MAX[5][16]=6336;
solution[5][16].push_back(make_pair(-16,0));
solution[5][16].push_back(make_pair(-16,0));
solution[5][16].push_back(make_pair(9,-13));
solution[5][16].push_back(make_pair(9,13));
solution[5][16].push_back(make_pair(16,0));

MAX[5][17]=7224;
solution[5][17].push_back(make_pair(-17,0));
solution[5][17].push_back(make_pair(-17,0));
solution[5][17].push_back(make_pair(8,-15));
solution[5][17].push_back(make_pair(8,15));
solution[5][17].push_back(make_pair(17,0));

MAX[5][18]=8056;
solution[5][18].push_back(make_pair(-18,0));
solution[5][18].push_back(make_pair(-18,0));
solution[5][18].push_back(make_pair(8,-16));
solution[5][18].push_back(make_pair(8,16));
solution[5][18].push_back(make_pair(18,0));

MAX[5][19]=9008;
solution[5][19].push_back(make_pair(-19,0));
solution[5][19].push_back(make_pair(-18,-6));
solution[5][19].push_back(make_pair(0,19));
solution[5][19].push_back(make_pair(18,-6));
solution[5][19].push_back(make_pair(18,-6));

MAX[5][20]=9984;
solution[5][20].push_back(make_pair(-20,0));
solution[5][20].push_back(make_pair(-20,0));
solution[5][20].push_back(make_pair(12,-16));
solution[5][20].push_back(make_pair(12,16));
solution[5][20].push_back(make_pair(20,0));

MAX[5][21]=10942;
solution[5][21].push_back(make_pair(-21,0));
solution[5][21].push_back(make_pair(-21,0));
solution[5][21].push_back(make_pair(6,-20));
solution[5][21].push_back(make_pair(12,17));
solution[5][21].push_back(make_pair(21,0));

MAX[5][22]=12080;
solution[5][22].push_back(make_pair(-22,0));
solution[5][22].push_back(make_pair(-22,0));
solution[5][22].push_back(make_pair(11,-19));
solution[5][22].push_back(make_pair(11,19));
solution[5][22].push_back(make_pair(22,0));

MAX[5][23]=13144;
solution[5][23].push_back(make_pair(-23,0));
solution[5][23].push_back(make_pair(-23,0));
solution[5][23].push_back(make_pair(11,-20));
solution[5][23].push_back(make_pair(11,20));
solution[5][23].push_back(make_pair(23,0));

MAX[5][24]=14326;
solution[5][24].push_back(make_pair(-24,0));
solution[5][24].push_back(make_pair(-24,0));
solution[5][24].push_back(make_pair(13,-20));
solution[5][24].push_back(make_pair(13,20));
solution[5][24].push_back(make_pair(24,0));

MAX[5][25]=15624;
solution[5][25].push_back(make_pair(-25,0));
solution[5][25].push_back(make_pair(-7,-24));
solution[5][25].push_back(make_pair(-7,24));
solution[5][25].push_back(make_pair(20,-15));
solution[5][25].push_back(make_pair(20,15));

MAX[5][26]=16896;
solution[5][26].push_back(make_pair(-26,0));
solution[5][26].push_back(make_pair(-10,-24));
solution[5][26].push_back(make_pair(-10,24));
solution[5][26].push_back(make_pair(24,-10));
solution[5][26].push_back(make_pair(24,10));

MAX[5][27]=18184;
solution[5][27].push_back(make_pair(-27,0));
solution[5][27].push_back(make_pair(-27,0));
solution[5][27].push_back(make_pair(14,-23));
solution[5][27].push_back(make_pair(14,23));
solution[5][27].push_back(make_pair(27,0));

MAX[5][28]=19488;
solution[5][28].push_back(make_pair(-28,0));
solution[5][28].push_back(make_pair(-28,0));
solution[5][28].push_back(make_pair(10,-26));
solution[5][28].push_back(make_pair(17,22));
solution[5][28].push_back(make_pair(28,0));

MAX[5][29]=20968;
solution[5][29].push_back(make_pair(-29,0));
solution[5][29].push_back(make_pair(-21,-20));
solution[5][29].push_back(make_pair(0,29));
solution[5][29].push_back(make_pair(21,-20));
solution[5][29].push_back(make_pair(28,7));

MAX[5][30]=22480;
solution[5][30].push_back(make_pair(-30,0));
solution[5][30].push_back(make_pair(-30,0));
solution[5][30].push_back(make_pair(13,-27));
solution[5][30].push_back(make_pair(18,24));
solution[5][30].push_back(make_pair(30,0));

MAX[6][1]=36;
solution[6][1].push_back(make_pair(-1,0));
solution[6][1].push_back(make_pair(-1,0));
solution[6][1].push_back(make_pair(-1,0));
solution[6][1].push_back(make_pair(1,0));
solution[6][1].push_back(make_pair(1,0));
solution[6][1].push_back(make_pair(1,0));

MAX[6][2]=144;
solution[6][2].push_back(make_pair(-2,0));
solution[6][2].push_back(make_pair(-2,0));
solution[6][2].push_back(make_pair(-2,0));
solution[6][2].push_back(make_pair(2,0));
solution[6][2].push_back(make_pair(2,0));
solution[6][2].push_back(make_pair(2,0));

MAX[6][3]=324;
solution[6][3].push_back(make_pair(-3,0));
solution[6][3].push_back(make_pair(-3,0));
solution[6][3].push_back(make_pair(-3,0));
solution[6][3].push_back(make_pair(3,0));
solution[6][3].push_back(make_pair(3,0));
solution[6][3].push_back(make_pair(3,0));

MAX[6][4]=576;
solution[6][4].push_back(make_pair(-4,0));
solution[6][4].push_back(make_pair(-4,0));
solution[6][4].push_back(make_pair(-4,0));
solution[6][4].push_back(make_pair(4,0));
solution[6][4].push_back(make_pair(4,0));
solution[6][4].push_back(make_pair(4,0));

MAX[6][5]=900;
solution[6][5].push_back(make_pair(-5,0));
solution[6][5].push_back(make_pair(-5,0));
solution[6][5].push_back(make_pair(-5,0));
solution[6][5].push_back(make_pair(5,0));
solution[6][5].push_back(make_pair(5,0));
solution[6][5].push_back(make_pair(5,0));

MAX[6][6]=1296;
solution[6][6].push_back(make_pair(-6,0));
solution[6][6].push_back(make_pair(-6,0));
solution[6][6].push_back(make_pair(-6,0));
solution[6][6].push_back(make_pair(6,0));
solution[6][6].push_back(make_pair(6,0));
solution[6][6].push_back(make_pair(6,0));

MAX[6][7]=1764;
solution[6][7].push_back(make_pair(-7,0));
solution[6][7].push_back(make_pair(-7,0));
solution[6][7].push_back(make_pair(-7,0));
solution[6][7].push_back(make_pair(7,0));
solution[6][7].push_back(make_pair(7,0));
solution[6][7].push_back(make_pair(7,0));

MAX[6][8]=2304;
solution[6][8].push_back(make_pair(-8,0));
solution[6][8].push_back(make_pair(-8,0));
solution[6][8].push_back(make_pair(-8,0));
solution[6][8].push_back(make_pair(8,0));
solution[6][8].push_back(make_pair(8,0));
solution[6][8].push_back(make_pair(8,0));

MAX[6][9]=2916;
solution[6][9].push_back(make_pair(-9,0));
solution[6][9].push_back(make_pair(-9,0));
solution[6][9].push_back(make_pair(-9,0));
solution[6][9].push_back(make_pair(9,0));
solution[6][9].push_back(make_pair(9,0));
solution[6][9].push_back(make_pair(9,0));

MAX[6][10]=3600;
solution[6][10].push_back(make_pair(-10,0));
solution[6][10].push_back(make_pair(-10,0));
solution[6][10].push_back(make_pair(-10,0));
solution[6][10].push_back(make_pair(10,0));
solution[6][10].push_back(make_pair(10,0));
solution[6][10].push_back(make_pair(10,0));

MAX[6][11]=4356;
solution[6][11].push_back(make_pair(-11,0));
solution[6][11].push_back(make_pair(-11,0));
solution[6][11].push_back(make_pair(-11,0));
solution[6][11].push_back(make_pair(11,0));
solution[6][11].push_back(make_pair(11,0));
solution[6][11].push_back(make_pair(11,0));

MAX[6][12]=5184;
solution[6][12].push_back(make_pair(-12,0));
solution[6][12].push_back(make_pair(-12,0));
solution[6][12].push_back(make_pair(-12,0));
solution[6][12].push_back(make_pair(12,0));
solution[6][12].push_back(make_pair(12,0));
solution[6][12].push_back(make_pair(12,0));

MAX[6][13]=6084;
solution[6][13].push_back(make_pair(-13,0));
solution[6][13].push_back(make_pair(-13,0));
solution[6][13].push_back(make_pair(-13,0));
solution[6][13].push_back(make_pair(13,0));
solution[6][13].push_back(make_pair(13,0));
solution[6][13].push_back(make_pair(13,0));

MAX[6][14]=7056;
solution[6][14].push_back(make_pair(-14,0));
solution[6][14].push_back(make_pair(-14,0));
solution[6][14].push_back(make_pair(-14,0));
solution[6][14].push_back(make_pair(14,0));
solution[6][14].push_back(make_pair(14,0));
solution[6][14].push_back(make_pair(14,0));

MAX[6][15]=8100;
solution[6][15].push_back(make_pair(-15,0));
solution[6][15].push_back(make_pair(-15,0));
solution[6][15].push_back(make_pair(-15,0));
solution[6][15].push_back(make_pair(15,0));
solution[6][15].push_back(make_pair(15,0));
solution[6][15].push_back(make_pair(15,0));

MAX[6][16]=9216;
solution[6][16].push_back(make_pair(-16,0));
solution[6][16].push_back(make_pair(-16,0));
solution[6][16].push_back(make_pair(-16,0));
solution[6][16].push_back(make_pair(16,0));
solution[6][16].push_back(make_pair(16,0));
solution[6][16].push_back(make_pair(16,0));

MAX[6][17]=10404;
solution[6][17].push_back(make_pair(-17,0));
solution[6][17].push_back(make_pair(-17,0));
solution[6][17].push_back(make_pair(-17,0));
solution[6][17].push_back(make_pair(17,0));
solution[6][17].push_back(make_pair(17,0));
solution[6][17].push_back(make_pair(17,0));

MAX[6][18]=11664;
solution[6][18].push_back(make_pair(-18,0));
solution[6][18].push_back(make_pair(-18,0));
solution[6][18].push_back(make_pair(-18,0));
solution[6][18].push_back(make_pair(18,0));
solution[6][18].push_back(make_pair(18,0));
solution[6][18].push_back(make_pair(18,0));

MAX[6][19]=12996;
solution[6][19].push_back(make_pair(-19,0));
solution[6][19].push_back(make_pair(-19,0));
solution[6][19].push_back(make_pair(-19,0));
solution[6][19].push_back(make_pair(19,0));
solution[6][19].push_back(make_pair(19,0));
solution[6][19].push_back(make_pair(19,0));

MAX[6][20]=14400;
solution[6][20].push_back(make_pair(-20,0));
solution[6][20].push_back(make_pair(-20,0));
solution[6][20].push_back(make_pair(-20,0));
solution[6][20].push_back(make_pair(20,0));
solution[6][20].push_back(make_pair(20,0));
solution[6][20].push_back(make_pair(20,0));

MAX[6][21]=15876;
solution[6][21].push_back(make_pair(-21,0));
solution[6][21].push_back(make_pair(-21,0));
solution[6][21].push_back(make_pair(-21,0));
solution[6][21].push_back(make_pair(21,0));
solution[6][21].push_back(make_pair(21,0));
solution[6][21].push_back(make_pair(21,0));

MAX[6][22]=17424;
solution[6][22].push_back(make_pair(-22,0));
solution[6][22].push_back(make_pair(-22,0));
solution[6][22].push_back(make_pair(-22,0));
solution[6][22].push_back(make_pair(22,0));
solution[6][22].push_back(make_pair(22,0));
solution[6][22].push_back(make_pair(22,0));

MAX[6][23]=19044;
solution[6][23].push_back(make_pair(-23,0));
solution[6][23].push_back(make_pair(-23,0));
solution[6][23].push_back(make_pair(-23,0));
solution[6][23].push_back(make_pair(23,0));
solution[6][23].push_back(make_pair(23,0));
solution[6][23].push_back(make_pair(23,0));

MAX[6][24]=20736;
solution[6][24].push_back(make_pair(-24,0));
solution[6][24].push_back(make_pair(-24,0));
solution[6][24].push_back(make_pair(-24,0));
solution[6][24].push_back(make_pair(24,0));
solution[6][24].push_back(make_pair(24,0));
solution[6][24].push_back(make_pair(24,0));

MAX[6][25]=22500;
solution[6][25].push_back(make_pair(-25,0));
solution[6][25].push_back(make_pair(-25,0));
solution[6][25].push_back(make_pair(-25,0));
solution[6][25].push_back(make_pair(25,0));
solution[6][25].push_back(make_pair(25,0));
solution[6][25].push_back(make_pair(25,0));

MAX[6][26]=24336;
solution[6][26].push_back(make_pair(-26,0));
solution[6][26].push_back(make_pair(-26,0));
solution[6][26].push_back(make_pair(-26,0));
solution[6][26].push_back(make_pair(26,0));
solution[6][26].push_back(make_pair(26,0));
solution[6][26].push_back(make_pair(26,0));

MAX[6][27]=26244;
solution[6][27].push_back(make_pair(-27,0));
solution[6][27].push_back(make_pair(-27,0));
solution[6][27].push_back(make_pair(-27,0));
solution[6][27].push_back(make_pair(27,0));
solution[6][27].push_back(make_pair(27,0));
solution[6][27].push_back(make_pair(27,0));

MAX[6][28]=28224;
solution[6][28].push_back(make_pair(-28,0));
solution[6][28].push_back(make_pair(-28,0));
solution[6][28].push_back(make_pair(-28,0));
solution[6][28].push_back(make_pair(28,0));
solution[6][28].push_back(make_pair(28,0));
solution[6][28].push_back(make_pair(28,0));

MAX[6][29]=30276;
solution[6][29].push_back(make_pair(-29,0));
solution[6][29].push_back(make_pair(-29,0));
solution[6][29].push_back(make_pair(-29,0));
solution[6][29].push_back(make_pair(29,0));
solution[6][29].push_back(make_pair(29,0));
solution[6][29].push_back(make_pair(29,0));

MAX[6][30]=32400;
solution[6][30].push_back(make_pair(-30,0));
solution[6][30].push_back(make_pair(-30,0));
solution[6][30].push_back(make_pair(-30,0));
solution[6][30].push_back(make_pair(30,0));
solution[6][30].push_back(make_pair(30,0));
solution[6][30].push_back(make_pair(30,0));

MAX[7][1]=48;
solution[7][1].push_back(make_pair(-1,0));
solution[7][1].push_back(make_pair(-1,0));
solution[7][1].push_back(make_pair(-1,0));
solution[7][1].push_back(make_pair(-1,0));
solution[7][1].push_back(make_pair(1,0));
solution[7][1].push_back(make_pair(1,0));
solution[7][1].push_back(make_pair(1,0));

MAX[7][2]=192;
solution[7][2].push_back(make_pair(-2,0));
solution[7][2].push_back(make_pair(-2,0));
solution[7][2].push_back(make_pair(-2,0));
solution[7][2].push_back(make_pair(-2,0));
solution[7][2].push_back(make_pair(2,0));
solution[7][2].push_back(make_pair(2,0));
solution[7][2].push_back(make_pair(2,0));

MAX[7][3]=432;
solution[7][3].push_back(make_pair(-3,0));
solution[7][3].push_back(make_pair(-3,0));
solution[7][3].push_back(make_pair(-3,0));
solution[7][3].push_back(make_pair(-3,0));
solution[7][3].push_back(make_pair(3,0));
solution[7][3].push_back(make_pair(3,0));
solution[7][3].push_back(make_pair(3,0));

MAX[7][4]=768;
solution[7][4].push_back(make_pair(-4,0));
solution[7][4].push_back(make_pair(-4,0));
solution[7][4].push_back(make_pair(-4,0));
solution[7][4].push_back(make_pair(-4,0));
solution[7][4].push_back(make_pair(4,0));
solution[7][4].push_back(make_pair(4,0));
solution[7][4].push_back(make_pair(4,0));

MAX[7][5]=1224;
solution[7][5].push_back(make_pair(-5,0));
solution[7][5].push_back(make_pair(-5,0));
solution[7][5].push_back(make_pair(-5,0));
solution[7][5].push_back(make_pair(3,-4));
solution[7][5].push_back(make_pair(3,4));
solution[7][5].push_back(make_pair(4,-3));
solution[7][5].push_back(make_pair(4,3));

MAX[7][6]=1740;
solution[7][6].push_back(make_pair(-6,0));
solution[7][6].push_back(make_pair(-6,0));
solution[7][6].push_back(make_pair(-6,0));
solution[7][6].push_back(make_pair(0,-6));
solution[7][6].push_back(make_pair(3,5));
solution[7][6].push_back(make_pair(6,0));
solution[7][6].push_back(make_pair(6,0));

MAX[7][7]=2356;
solution[7][7].push_back(make_pair(-7,0));
solution[7][7].push_back(make_pair(-7,0));
solution[7][7].push_back(make_pair(-7,0));
solution[7][7].push_back(make_pair(0,-7));
solution[7][7].push_back(make_pair(3,6));
solution[7][7].push_back(make_pair(7,0));
solution[7][7].push_back(make_pair(7,0));

MAX[7][8]=3102;
solution[7][8].push_back(make_pair(-8,0));
solution[7][8].push_back(make_pair(-8,0));
solution[7][8].push_back(make_pair(-8,0));
solution[7][8].push_back(make_pair(0,-8));
solution[7][8].push_back(make_pair(5,6));
solution[7][8].push_back(make_pair(8,0));
solution[7][8].push_back(make_pair(8,0));

MAX[7][9]=3954;
solution[7][9].push_back(make_pair(-9,0));
solution[7][9].push_back(make_pair(-9,0));
solution[7][9].push_back(make_pair(-9,0));
solution[7][9].push_back(make_pair(4,-8));
solution[7][9].push_back(make_pair(4,8));
solution[7][9].push_back(make_pair(9,0));
solution[7][9].push_back(make_pair(9,0));

MAX[7][10]=4896;
solution[7][10].push_back(make_pair(-10,0));
solution[7][10].push_back(make_pair(-10,0));
solution[7][10].push_back(make_pair(-10,0));
solution[7][10].push_back(make_pair(6,-8));
solution[7][10].push_back(make_pair(6,8));
solution[7][10].push_back(make_pair(8,-6));
solution[7][10].push_back(make_pair(8,6));

MAX[7][11]=5872;
solution[7][11].push_back(make_pair(-11,0));
solution[7][11].push_back(make_pair(-11,0));
solution[7][11].push_back(make_pair(-11,0));
solution[7][11].push_back(make_pair(0,-11));
solution[7][11].push_back(make_pair(6,9));
solution[7][11].push_back(make_pair(11,0));
solution[7][11].push_back(make_pair(11,0));

MAX[7][12]=6960;
solution[7][12].push_back(make_pair(-12,0));
solution[7][12].push_back(make_pair(-12,0));
solution[7][12].push_back(make_pair(-12,0));
solution[7][12].push_back(make_pair(0,-12));
solution[7][12].push_back(make_pair(6,10));
solution[7][12].push_back(make_pair(12,0));
solution[7][12].push_back(make_pair(12,0));

MAX[7][13]=8280;
solution[7][13].push_back(make_pair(-13,0));
solution[7][13].push_back(make_pair(-13,0));
solution[7][13].push_back(make_pair(-5,-12));
solution[7][13].push_back(make_pair(-5,12));
solution[7][13].push_back(make_pair(12,-5));
solution[7][13].push_back(make_pair(12,5));
solution[7][13].push_back(make_pair(13,0));

MAX[7][14]=9564;
solution[7][14].push_back(make_pair(-14,0));
solution[7][14].push_back(make_pair(-14,0));
solution[7][14].push_back(make_pair(-14,0));
solution[7][14].push_back(make_pair(5,-13));
solution[7][14].push_back(make_pair(7,12));
solution[7][14].push_back(make_pair(14,0));
solution[7][14].push_back(make_pair(14,0));

MAX[7][15]=11016;
solution[7][15].push_back(make_pair(-15,0));
solution[7][15].push_back(make_pair(-15,0));
solution[7][15].push_back(make_pair(-15,0));
solution[7][15].push_back(make_pair(9,-12));
solution[7][15].push_back(make_pair(9,12));
solution[7][15].push_back(make_pair(12,-9));
solution[7][15].push_back(make_pair(12,9));

MAX[7][16]=12456;
solution[7][16].push_back(make_pair(-16,0));
solution[7][16].push_back(make_pair(-16,0));
solution[7][16].push_back(make_pair(-16,0));
solution[7][16].push_back(make_pair(9,-13));
solution[7][16].push_back(make_pair(9,13));
solution[7][16].push_back(make_pair(16,0));
solution[7][16].push_back(make_pair(16,0));

MAX[7][17]=14160;
solution[7][17].push_back(make_pair(-17,0));
solution[7][17].push_back(make_pair(-17,0));
solution[7][17].push_back(make_pair(-17,0));
solution[7][17].push_back(make_pair(8,-15));
solution[7][17].push_back(make_pair(8,15));
solution[7][17].push_back(make_pair(17,0));
solution[7][17].push_back(make_pair(17,0));

MAX[7][18]=15816;
solution[7][18].push_back(make_pair(-18,0));
solution[7][18].push_back(make_pair(-18,0));
solution[7][18].push_back(make_pair(-18,0));
solution[7][18].push_back(make_pair(8,-16));
solution[7][18].push_back(make_pair(8,16));
solution[7][18].push_back(make_pair(18,0));
solution[7][18].push_back(make_pair(18,0));

MAX[7][19]=17666;
solution[7][19].push_back(make_pair(-19,0));
solution[7][19].push_back(make_pair(-19,0));
solution[7][19].push_back(make_pair(-18,-6));
solution[7][19].push_back(make_pair(0,19));
solution[7][19].push_back(make_pair(18,-6));
solution[7][19].push_back(make_pair(18,-6));
solution[7][19].push_back(make_pair(19,0));

MAX[7][20]=19584;
solution[7][20].push_back(make_pair(-20,0));
solution[7][20].push_back(make_pair(-20,0));
solution[7][20].push_back(make_pair(-20,0));
solution[7][20].push_back(make_pair(12,-16));
solution[7][20].push_back(make_pair(12,16));
solution[7][20].push_back(make_pair(16,-12));
solution[7][20].push_back(make_pair(16,12));

MAX[7][21]=21500;
solution[7][21].push_back(make_pair(-21,0));
solution[7][21].push_back(make_pair(-21,0));
solution[7][21].push_back(make_pair(-21,0));
solution[7][21].push_back(make_pair(6,-20));
solution[7][21].push_back(make_pair(12,17));
solution[7][21].push_back(make_pair(21,0));
solution[7][21].push_back(make_pair(21,0));

MAX[7][22]=23688;
solution[7][22].push_back(make_pair(-22,0));
solution[7][22].push_back(make_pair(-22,0));
solution[7][22].push_back(make_pair(-22,0));
solution[7][22].push_back(make_pair(11,-19));
solution[7][22].push_back(make_pair(11,19));
solution[7][22].push_back(make_pair(22,0));
solution[7][22].push_back(make_pair(22,0));

MAX[7][23]=25808;
solution[7][23].push_back(make_pair(-23,0));
solution[7][23].push_back(make_pair(-23,0));
solution[7][23].push_back(make_pair(-23,0));
solution[7][23].push_back(make_pair(11,-20));
solution[7][23].push_back(make_pair(11,20));
solution[7][23].push_back(make_pair(23,0));
solution[7][23].push_back(make_pair(23,0));

MAX[7][24]=28122;
solution[7][24].push_back(make_pair(-24,0));
solution[7][24].push_back(make_pair(-24,0));
solution[7][24].push_back(make_pair(-24,0));
solution[7][24].push_back(make_pair(13,-20));
solution[7][24].push_back(make_pair(13,20));
solution[7][24].push_back(make_pair(24,0));
solution[7][24].push_back(make_pair(24,0));

MAX[7][25]=30624;
solution[7][25].push_back(make_pair(-25,0));
solution[7][25].push_back(make_pair(-25,0));
solution[7][25].push_back(make_pair(-24,-7));
solution[7][25].push_back(make_pair(15,-20));
solution[7][25].push_back(make_pair(15,20));
solution[7][25].push_back(make_pair(20,15));
solution[7][25].push_back(make_pair(24,-7));

MAX[7][26]=33120;
solution[7][26].push_back(make_pair(-26,0));
solution[7][26].push_back(make_pair(-26,0));
solution[7][26].push_back(make_pair(-10,-24));
solution[7][26].push_back(make_pair(-10,24));
solution[7][26].push_back(make_pair(24,-10));
solution[7][26].push_back(make_pair(24,10));
solution[7][26].push_back(make_pair(26,0));

MAX[7][27]=35664;
solution[7][27].push_back(make_pair(-27,0));
solution[7][27].push_back(make_pair(-27,0));
solution[7][27].push_back(make_pair(-27,0));
solution[7][27].push_back(make_pair(14,-23));
solution[7][27].push_back(make_pair(14,23));
solution[7][27].push_back(make_pair(27,0));
solution[7][27].push_back(make_pair(27,0));

MAX[7][28]=38266;
solution[7][28].push_back(make_pair(-28,0));
solution[7][28].push_back(make_pair(-28,0));
solution[7][28].push_back(make_pair(-28,0));
solution[7][28].push_back(make_pair(10,-26));
solution[7][28].push_back(make_pair(17,22));
solution[7][28].push_back(make_pair(28,0));
solution[7][28].push_back(make_pair(28,0));

MAX[7][29]=41200;
solution[7][29].push_back(make_pair(-29,0));
solution[7][29].push_back(make_pair(-29,0));
solution[7][29].push_back(make_pair(-29,0));
solution[7][29].push_back(make_pair(21,-20));
solution[7][29].push_back(make_pair(21,-20));
solution[7][29].push_back(make_pair(21,20));
solution[7][29].push_back(make_pair(21,20));

MAX[7][30]=44076;
solution[7][30].push_back(make_pair(-30,0));
solution[7][30].push_back(make_pair(-30,0));
solution[7][30].push_back(make_pair(-30,0));
solution[7][30].push_back(make_pair(13,-27));
solution[7][30].push_back(make_pair(18,24));
solution[7][30].push_back(make_pair(30,0));
solution[7][30].push_back(make_pair(30,0));

MAX[8][1]=64;
solution[8][1].push_back(make_pair(-1,0));
solution[8][1].push_back(make_pair(-1,0));
solution[8][1].push_back(make_pair(-1,0));
solution[8][1].push_back(make_pair(-1,0));
solution[8][1].push_back(make_pair(1,0));
solution[8][1].push_back(make_pair(1,0));
solution[8][1].push_back(make_pair(1,0));
solution[8][1].push_back(make_pair(1,0));

MAX[8][2]=256;
solution[8][2].push_back(make_pair(-2,0));
solution[8][2].push_back(make_pair(-2,0));
solution[8][2].push_back(make_pair(-2,0));
solution[8][2].push_back(make_pair(-2,0));
solution[8][2].push_back(make_pair(2,0));
solution[8][2].push_back(make_pair(2,0));
solution[8][2].push_back(make_pair(2,0));
solution[8][2].push_back(make_pair(2,0));

MAX[8][3]=576;
solution[8][3].push_back(make_pair(-3,0));
solution[8][3].push_back(make_pair(-3,0));
solution[8][3].push_back(make_pair(-3,0));
solution[8][3].push_back(make_pair(-3,0));
solution[8][3].push_back(make_pair(3,0));
solution[8][3].push_back(make_pair(3,0));
solution[8][3].push_back(make_pair(3,0));
solution[8][3].push_back(make_pair(3,0));

MAX[8][4]=1024;
solution[8][4].push_back(make_pair(-4,0));
solution[8][4].push_back(make_pair(-4,0));
solution[8][4].push_back(make_pair(-4,0));
solution[8][4].push_back(make_pair(-4,0));
solution[8][4].push_back(make_pair(4,0));
solution[8][4].push_back(make_pair(4,0));
solution[8][4].push_back(make_pair(4,0));
solution[8][4].push_back(make_pair(4,0));

MAX[8][5]=1600;
solution[8][5].push_back(make_pair(-5,0));
solution[8][5].push_back(make_pair(-5,0));
solution[8][5].push_back(make_pair(-5,0));
solution[8][5].push_back(make_pair(-5,0));
solution[8][5].push_back(make_pair(5,0));
solution[8][5].push_back(make_pair(5,0));
solution[8][5].push_back(make_pair(5,0));
solution[8][5].push_back(make_pair(5,0));

MAX[8][6]=2304;
solution[8][6].push_back(make_pair(-6,0));
solution[8][6].push_back(make_pair(-6,0));
solution[8][6].push_back(make_pair(-6,0));
solution[8][6].push_back(make_pair(-6,0));
solution[8][6].push_back(make_pair(6,0));
solution[8][6].push_back(make_pair(6,0));
solution[8][6].push_back(make_pair(6,0));
solution[8][6].push_back(make_pair(6,0));

MAX[8][7]=3136;
solution[8][7].push_back(make_pair(-7,0));
solution[8][7].push_back(make_pair(-7,0));
solution[8][7].push_back(make_pair(-7,0));
solution[8][7].push_back(make_pair(-7,0));
solution[8][7].push_back(make_pair(7,0));
solution[8][7].push_back(make_pair(7,0));
solution[8][7].push_back(make_pair(7,0));
solution[8][7].push_back(make_pair(7,0));

MAX[8][8]=4096;
solution[8][8].push_back(make_pair(-8,0));
solution[8][8].push_back(make_pair(-8,0));
solution[8][8].push_back(make_pair(-8,0));
solution[8][8].push_back(make_pair(-8,0));
solution[8][8].push_back(make_pair(8,0));
solution[8][8].push_back(make_pair(8,0));
solution[8][8].push_back(make_pair(8,0));
solution[8][8].push_back(make_pair(8,0));

MAX[8][9]=5184;
solution[8][9].push_back(make_pair(-9,0));
solution[8][9].push_back(make_pair(-9,0));
solution[8][9].push_back(make_pair(-9,0));
solution[8][9].push_back(make_pair(-9,0));
solution[8][9].push_back(make_pair(9,0));
solution[8][9].push_back(make_pair(9,0));
solution[8][9].push_back(make_pair(9,0));
solution[8][9].push_back(make_pair(9,0));

MAX[8][10]=6400;
solution[8][10].push_back(make_pair(-10,0));
solution[8][10].push_back(make_pair(-10,0));
solution[8][10].push_back(make_pair(-10,0));
solution[8][10].push_back(make_pair(-10,0));
solution[8][10].push_back(make_pair(10,0));
solution[8][10].push_back(make_pair(10,0));
solution[8][10].push_back(make_pair(10,0));
solution[8][10].push_back(make_pair(10,0));

MAX[8][11]=7744;
solution[8][11].push_back(make_pair(-11,0));
solution[8][11].push_back(make_pair(-11,0));
solution[8][11].push_back(make_pair(-11,0));
solution[8][11].push_back(make_pair(-11,0));
solution[8][11].push_back(make_pair(11,0));
solution[8][11].push_back(make_pair(11,0));
solution[8][11].push_back(make_pair(11,0));
solution[8][11].push_back(make_pair(11,0));

MAX[8][12]=9216;
solution[8][12].push_back(make_pair(-12,0));
solution[8][12].push_back(make_pair(-12,0));
solution[8][12].push_back(make_pair(-12,0));
solution[8][12].push_back(make_pair(-12,0));
solution[8][12].push_back(make_pair(12,0));
solution[8][12].push_back(make_pair(12,0));
solution[8][12].push_back(make_pair(12,0));
solution[8][12].push_back(make_pair(12,0));

MAX[8][13]=10816;
solution[8][13].push_back(make_pair(-13,0));
solution[8][13].push_back(make_pair(-13,0));
solution[8][13].push_back(make_pair(-13,0));
solution[8][13].push_back(make_pair(-13,0));
solution[8][13].push_back(make_pair(13,0));
solution[8][13].push_back(make_pair(13,0));
solution[8][13].push_back(make_pair(13,0));
solution[8][13].push_back(make_pair(13,0));

MAX[8][14]=12544;
solution[8][14].push_back(make_pair(-14,0));
solution[8][14].push_back(make_pair(-14,0));
solution[8][14].push_back(make_pair(-14,0));
solution[8][14].push_back(make_pair(-14,0));
solution[8][14].push_back(make_pair(14,0));
solution[8][14].push_back(make_pair(14,0));
solution[8][14].push_back(make_pair(14,0));
solution[8][14].push_back(make_pair(14,0));

MAX[8][15]=14400;
solution[8][15].push_back(make_pair(-15,0));
solution[8][15].push_back(make_pair(-15,0));
solution[8][15].push_back(make_pair(-15,0));
solution[8][15].push_back(make_pair(-15,0));
solution[8][15].push_back(make_pair(15,0));
solution[8][15].push_back(make_pair(15,0));
solution[8][15].push_back(make_pair(15,0));
solution[8][15].push_back(make_pair(15,0));

MAX[8][16]=16384;
solution[8][16].push_back(make_pair(-16,0));
solution[8][16].push_back(make_pair(-16,0));
solution[8][16].push_back(make_pair(-16,0));
solution[8][16].push_back(make_pair(-16,0));
solution[8][16].push_back(make_pair(16,0));
solution[8][16].push_back(make_pair(16,0));
solution[8][16].push_back(make_pair(16,0));
solution[8][16].push_back(make_pair(16,0));

MAX[8][17]=18496;
solution[8][17].push_back(make_pair(-17,0));
solution[8][17].push_back(make_pair(-17,0));
solution[8][17].push_back(make_pair(-17,0));
solution[8][17].push_back(make_pair(-17,0));
solution[8][17].push_back(make_pair(17,0));
solution[8][17].push_back(make_pair(17,0));
solution[8][17].push_back(make_pair(17,0));
solution[8][17].push_back(make_pair(17,0));

MAX[8][18]=20736;
solution[8][18].push_back(make_pair(-18,0));
solution[8][18].push_back(make_pair(-18,0));
solution[8][18].push_back(make_pair(-18,0));
solution[8][18].push_back(make_pair(-18,0));
solution[8][18].push_back(make_pair(18,0));
solution[8][18].push_back(make_pair(18,0));
solution[8][18].push_back(make_pair(18,0));
solution[8][18].push_back(make_pair(18,0));

MAX[8][19]=23104;
solution[8][19].push_back(make_pair(-19,0));
solution[8][19].push_back(make_pair(-19,0));
solution[8][19].push_back(make_pair(-19,0));
solution[8][19].push_back(make_pair(-19,0));
solution[8][19].push_back(make_pair(19,0));
solution[8][19].push_back(make_pair(19,0));
solution[8][19].push_back(make_pair(19,0));
solution[8][19].push_back(make_pair(19,0));

MAX[8][20]=25600;
solution[8][20].push_back(make_pair(-20,0));
solution[8][20].push_back(make_pair(-20,0));
solution[8][20].push_back(make_pair(-20,0));
solution[8][20].push_back(make_pair(-20,0));
solution[8][20].push_back(make_pair(20,0));
solution[8][20].push_back(make_pair(20,0));
solution[8][20].push_back(make_pair(20,0));
solution[8][20].push_back(make_pair(20,0));

MAX[8][21]=28224;
solution[8][21].push_back(make_pair(-21,0));
solution[8][21].push_back(make_pair(-21,0));
solution[8][21].push_back(make_pair(-21,0));
solution[8][21].push_back(make_pair(-21,0));
solution[8][21].push_back(make_pair(21,0));
solution[8][21].push_back(make_pair(21,0));
solution[8][21].push_back(make_pair(21,0));
solution[8][21].push_back(make_pair(21,0));

MAX[8][22]=30976;
solution[8][22].push_back(make_pair(-22,0));
solution[8][22].push_back(make_pair(-22,0));
solution[8][22].push_back(make_pair(-22,0));
solution[8][22].push_back(make_pair(-22,0));
solution[8][22].push_back(make_pair(22,0));
solution[8][22].push_back(make_pair(22,0));
solution[8][22].push_back(make_pair(22,0));
solution[8][22].push_back(make_pair(22,0));

MAX[8][23]=33856;
solution[8][23].push_back(make_pair(-23,0));
solution[8][23].push_back(make_pair(-23,0));
solution[8][23].push_back(make_pair(-23,0));
solution[8][23].push_back(make_pair(-23,0));
solution[8][23].push_back(make_pair(23,0));
solution[8][23].push_back(make_pair(23,0));
solution[8][23].push_back(make_pair(23,0));
solution[8][23].push_back(make_pair(23,0));

MAX[8][24]=36864;
solution[8][24].push_back(make_pair(-24,0));
solution[8][24].push_back(make_pair(-24,0));
solution[8][24].push_back(make_pair(-24,0));
solution[8][24].push_back(make_pair(-24,0));
solution[8][24].push_back(make_pair(24,0));
solution[8][24].push_back(make_pair(24,0));
solution[8][24].push_back(make_pair(24,0));
solution[8][24].push_back(make_pair(24,0));

MAX[8][25]=40000;
solution[8][25].push_back(make_pair(-25,0));
solution[8][25].push_back(make_pair(-25,0));
solution[8][25].push_back(make_pair(-25,0));
solution[8][25].push_back(make_pair(-25,0));
solution[8][25].push_back(make_pair(25,0));
solution[8][25].push_back(make_pair(25,0));
solution[8][25].push_back(make_pair(25,0));
solution[8][25].push_back(make_pair(25,0));

MAX[8][26]=43264;
solution[8][26].push_back(make_pair(-26,0));
solution[8][26].push_back(make_pair(-26,0));
solution[8][26].push_back(make_pair(-26,0));
solution[8][26].push_back(make_pair(-26,0));
solution[8][26].push_back(make_pair(26,0));
solution[8][26].push_back(make_pair(26,0));
solution[8][26].push_back(make_pair(26,0));
solution[8][26].push_back(make_pair(26,0));

MAX[8][27]=46656;
solution[8][27].push_back(make_pair(-27,0));
solution[8][27].push_back(make_pair(-27,0));
solution[8][27].push_back(make_pair(-27,0));
solution[8][27].push_back(make_pair(-27,0));
solution[8][27].push_back(make_pair(27,0));
solution[8][27].push_back(make_pair(27,0));
solution[8][27].push_back(make_pair(27,0));
solution[8][27].push_back(make_pair(27,0));

MAX[8][28]=50176;
solution[8][28].push_back(make_pair(-28,0));
solution[8][28].push_back(make_pair(-28,0));
solution[8][28].push_back(make_pair(-28,0));
solution[8][28].push_back(make_pair(-28,0));
solution[8][28].push_back(make_pair(28,0));
solution[8][28].push_back(make_pair(28,0));
solution[8][28].push_back(make_pair(28,0));
solution[8][28].push_back(make_pair(28,0));

MAX[8][29]=53824;
solution[8][29].push_back(make_pair(-29,0));
solution[8][29].push_back(make_pair(-29,0));
solution[8][29].push_back(make_pair(-29,0));
solution[8][29].push_back(make_pair(-29,0));
solution[8][29].push_back(make_pair(29,0));
solution[8][29].push_back(make_pair(29,0));
solution[8][29].push_back(make_pair(29,0));
solution[8][29].push_back(make_pair(29,0));

MAX[8][30]=57600;
solution[8][30].push_back(make_pair(-30,0));
solution[8][30].push_back(make_pair(-30,0));
solution[8][30].push_back(make_pair(-30,0));
solution[8][30].push_back(make_pair(-30,0));
solution[8][30].push_back(make_pair(30,0));
solution[8][30].push_back(make_pair(30,0));
solution[8][30].push_back(make_pair(30,0));
solution[8][30].push_back(make_pair(30,0));

scanf("%d%d",&N,&K);

for (i=solution[N][K].begin(),printf("%d\n",MAX[N][K]);i!=solution[N][K].end();i++)
printf("%d %d\n",(*i).F,(*i).S);

return 0;
}
