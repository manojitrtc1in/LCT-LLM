#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> ans = {
	{1,-1},
	{1},
	{1,0,1},
	{2},
	{1,1,0,0},
	{3},
	{1,0,-1,-1,0},
	{4},
	{1,-1,0,1,0,1},
	{5},
	{1,-1,1,-1,0,0,0},
	{6},
	{1,-1,1,0,0,1,1,1},
	{7},
	{1,0,1,1,-1,1,1,1,0},
	{8},
	{1,-1,1,1,0,0,-1,-1,1,-1},
	{9},
	{1,1,0,-1,0,1,1,-1,1,1,1},
	{10},
	{1,1,-1,-1,0,-1,1,-1,1,-1,-1,1},
	{11},
	{1,-1,1,1,0,0,-1,1,1,0,-1,1,0},
	{12},
	{1,1,0,0,-1,-1,-1,1,0,0,1,-1,0,0},
	{13},
	{1,1,-1,0,0,0,-1,-1,0,1,-1,1,0,-1,1},
	{14},
	{1,0,-1,1,-1,-1,0,1,1,0,1,-1,1,1,0,-1},
	{15},
	{1,-1,0,1,1,-1,-1,1,0,-1,-1,-1,-1,-1,1,0,1},
	{16},
	{1,0,1,0,0,-1,-1,1,-1,1,1,0,1,1,1,0,-1,0},
	{17},
	{1,1,-1,0,0,1,-1,1,1,-1,-1,-1,-1,-1,1,-1,0,0,-1},
	{18},
	{1,0,1,-1,-1,1,-1,1,0,1,1,1,-1,-1,1,1,-1,1,0,0},
	{19},
	{1,0,-1,1,-1,0,0,-1,1,0,1,0,0,-1,0,-1,1,-1,1,-1,1},
	{20},
	{1,-1,0,0,-1,0,-1,-1,1,-1,1,-1,1,0,1,1,-1,-1,1,-1,0,1},
	{21},
	{1,1,0,-1,-1,-1,1,1,0,-1,1,1,0,0,1,1,1,1,1,0,-1,-1,0},
	{22},
	{1,0,1,-1,0,-1,-1,1,-1,-1,1,1,-1,-1,1,0,1,0,-1,1,-1,-1,-1,1},
	{23},
	{1,1,0,-1,1,-1,-1,1,-1,0,-1,0,-1,1,1,-1,1,0,0,0,1,-1,0,1,0},
	{24},
	{1,-1,0,-1,-1,1,1,1,0,1,0,-1,0,1,-1,0,-1,0,-1,1,0,0,1,1,1,0},
	{25},
	{1,1,-1,0,-1,-1,0,1,0,-1,0,-1,-1,-1,0,-1,0,1,0,-1,1,1,1,-1,0,-1,1},
	{26},
	{1,-1,1,1,-1,1,0,1,0,0,-1,0,1,0,1,0,-1,-1,0,1,1,1,1,0,0,1,1,-1},
	{27},
	{1,-1,0,1,-1,-1,0,-1,1,-1,-1,0,0,-1,-1,-1,-1,1,-1,-1,0,-1,0,0,1,1,1,-1,-1},
	{28},
	{1,0,-1,0,0,0,-1,1,0,-1,1,-1,0,-1,-1,1,1,-1,-1,0,-1,-1,0,1,1,0,0,0,1,-1},
	{29},
	{1,-1,1,0,0,-1,1,0,1,1,-1,0,-1,-1,-1,1,-1,0,0,1,-1,-1,1,0,0,-1,0,1,1,0,0},
	{30},
	{1,-1,0,1,1,1,0,1,1,1,1,-1,-1,1,0,-1,0,1,0,1,0,1,0,0,-1,1,0,0,-1,0,1,-1},
	{31},
	{1,1,0,0,1,-1,-1,1,-1,1,-1,-1,1,0,0,1,0,0,0,-1,1,0,1,1,1,1,1,-1,0,1,1,0,1},
	{32},
	{1,1,0,0,1,-1,1,-1,0,0,0,-1,1,1,1,0,-1,1,1,1,-1,1,0,1,0,0,0,0,0,1,0,0,1,-1},
	{33},
	{1,1,-1,1,0,-1,0,1,1,1,1,-1,1,-1,-1,1,-1,1,-1,-1,1,-1,-1,1,-1,1,-1,-1,1,1,-1,1,1,-1,0},
	{34},
	{1,-1,0,1,-1,1,1,0,1,1,-1,-1,0,0,1,1,1,1,1,-1,0,1,-1,0,-1,1,0,1,1,1,1,-1,1,0,0,-1},
	{35},
	{1,-1,1,1,-1,0,1,0,1,1,1,-1,-1,-1,0,1,1,0,-1,-1,0,0,-1,1,-1,1,-1,-1,1,-1,-1,1,1,-1,0,1,0},
	{36},
	{1,1,0,1,1,0,-1,1,-1,1,-1,0,-1,1,1,1,0,0,-1,0,1,0,1,0,1,-1,1,0,-1,1,0,1,0,-1,1,-1,0,-1},
	{37},
	{1,-1,1,0,1,1,-1,1,-1,1,-1,1,0,-1,1,-1,0,1,0,0,1,1,0,1,0,1,1,-1,0,0,0,1,1,0,-1,1,-1,1,0},
	{38},
	{1,0,1,1,0,1,-1,-1,-1,0,-1,-1,-1,-1,1,1,1,-1,1,0,1,1,-1,0,0,1,0,-1,1,-1,1,-1,1,1,1,-1,1,-1,0,0},
	{39},
	{1,1,0,0,-1,0,0,-1,1,0,-1,0,-1,1,1,0,-1,0,0,1,-1,-1,0,0,-1,0,1,0,1,1,-1,0,1,1,-1,-1,-1,1,-1,0,-1},
	{40},
	{1,-1,0,0,-1,1,1,0,0,-1,-1,-1,-1,1,0,0,-1,0,1,-1,-1,-1,1,1,0,-1,-1,1,0,0,0,1,0,1,-1,-1,1,1,0,1,-1,0},
	{41},
	{1,-1,1,-1,0,0,-1,1,0,-1,1,-1,0,0,0,-1,0,0,0,0,-1,0,0,-1,-1,1,0,-1,1,0,1,0,0,1,1,1,-1,-1,1,0,-1,-1,1},
	{42},
	{1,-1,1,0,1,0,-1,-1,-1,0,0,0,0,-1,1,-1,1,0,1,1,0,0,1,1,0,1,1,1,0,-1,1,-1,0,0,1,-1,0,-1,1,0,0,-1,-1,-1},
	{43},
	{1,-1,0,-1,1,0,-1,-1,0,-1,-1,1,-1,-1,1,-1,-1,-1,1,1,-1,1,1,0,-1,-1,1,-1,1,0,-1,-1,0,1,-1,0,0,0,1,-1,1,-1,-1,-1,0},
	{44},
	{1,0,1,1,-1,0,1,-1,-1,0,1,-1,-1,1,1,0,1,0,1,-1,-1,1,-1,-1,-1,-1,-1,-1,0,-1,-1,0,1,-1,-1,1,0,-1,0,1,1,0,1,1,0,1},
	{45},
	{1,-1,1,1,-1,0,1,1,0,-1,-1,0,0,0,0,0,1,-1,-1,1,0,0,-1,0,-1,0,-1,1,0,-1,0,0,-1,0,0,0,-1,-1,-1,1,0,0,0,-1,-1,1,0},
	{46},
	{1,-1,0,1,-1,-1,0,-1,0,0,0,0,1,1,-1,1,-1,1,-1,-1,0,-1,1,-1,-1,-1,0,1,0,1,-1,0,-1,1,0,0,0,-1,1,1,0,0,0,0,0,0,0,1},
	{47},
	{1,1,0,1,-1,-1,-1,-1,1,-1,-1,-1,1,-1,1,1,0,0,0,0,-1,1,0,-1,-1,0,1,-1,-1,-1,1,-1,-1,0,1,0,1,0,0,0,1,1,0,0,1,0,0,1,1},
	{48},
	{1,1,-1,0,1,-1,-1,1,0,-1,-1,-1,1,-1,0,-1,0,-1,0,-1,0,0,1,-1,-1,1,1,0,-1,1,1,0,1,-1,-1,-1,0,0,1,-1,1,1,0,0,-1,1,1,0,1,-1},
	{49},
	{1,0,1,1,0,-1,0,0,0,1,1,0,-1,1,1,1,1,-1,0,-1,-1,1,0,-1,0,1,1,-1,-1,0,0,1,-1,-1,1,1,0,-1,0,1,1,-1,0,-1,-1,0,0,1,1,1,-1},
	{50},
	{1,1,-1,0,-1,1,1,1,-1,0,0,0,1,-1,1,-1,-1,-1,1,1,-1,-1,0,0,1,-1,0,0,0,1,0,0,0,0,1,1,0,1,0,-1,-1,0,0,1,0,0,0,0,1,0,1,-1},
	{51},
	{1,0,-1,1,1,0,-1,0,1,-1,1,1,0,0,-1,0,0,1,1,-1,1,-1,0,-1,1,0,-1,1,-1,-1,0,1,1,-1,0,0,1,1,1,0,-1,-1,1,1,0,1,-1,1,0,-1,0,1,0},
	{52},
	{1,-1,0,1,0,-1,1,-1,1,1,-1,1,-1,0,0,-1,0,-1,-1,-1,-1,0,1,0,1,1,0,1,-1,1,1,-1,-1,1,1,1,1,1,-1,1,-1,0,1,-1,-1,0,0,0,1,0,1,-1,-1,1},
	{53},
	{1,0,1,1,0,-1,1,0,-1,0,1,0,1,1,1,0,-1,0,1,-1,0,-1,0,0,0,0,1,-1,1,1,-1,0,0,-1,0,1,0,-1,1,0,0,0,0,0,0,-1,-1,1,1,1,-1,0,0,1,1},
	{54},
	{1,0,1,-1,-1,-1,0,0,1,1,0,0,-1,1,0,-1,-1,-1,1,1,-1,-1,-1,-1,1,0,1,1,-1,1,1,-1,0,0,-1,1,1,0,-1,0,0,1,0,0,0,-1,1,-1,-1,0,1,0,1,-1,1,0},
	{55},
	{1,0,-1,1,1,0,1,-1,0,1,0,1,0,1,0,1,1,-1,0,0,1,-1,1,1,0,0,1,-1,-1,0,-1,1,-1,0,0,-1,-1,1,0,1,1,0,0,-1,-1,-1,-1,-1,-1,1,0,-1,1,0,0,0,1},
	{56},
	{1,1,-1,1,0,1,-1,1,-1,1,0,-1,0,-1,1,-1,-1,1,1,-1,1,-1,0,1,-1,0,0,0,0,0,-1,0,0,0,0,-1,1,1,-1,1,1,1,-1,-1,0,-1,0,0,-1,0,1,-1,1,0,-1,1,1,-1},
	{57},
	{1,1,0,0,1,-1,-1,-1,0,-1,0,-1,-1,0,0,1,1,1,1,1,1,-1,-1,0,0,0,1,0,-1,1,-1,0,0,1,1,0,-1,-1,1,-1,-1,0,-1,-1,-1,1,0,1,1,-1,-1,1,0,-1,0,-1,1,0,-1},
	{58},
	{1,0,1,0,0,0,-1,-1,1,1,-1,0,1,0,-1,1,0,-1,-1,-1,0,0,1,1,1,-1,0,0,1,-1,1,-1,1,1,0,0,-1,0,0,-1,1,-1,0,0,1,-1,0,-1,0,0,0,1,-1,0,1,-1,0,0,0,0},
	{59},
	{1,-1,0,1,1,-1,-1,1,1,-1,1,0,-1,0,1,0,0,-1,0,-1,1,-1,0,0,0,1,-1,0,1,-1,0,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,1,0,0,-1,0,-1,1,1,0,0,0,1,1,-1,-1,1,0,1,-1,0},
	{60},
	{1,0,1,0,0,0,-1,1,-1,0,1,-1,1,0,1,0,0,0,-1,0,0,1,1,-1,0,0,1,1,-1,1,1,1,-1,1,-1,1,0,0,1,0,-1,1,1,-1,0,1,0,1,-1,1,-1,1,0,-1,-1,-1,1,0,1,-1,-1,0},
	{61},
	{1,-1,0,0,1,1,1,-1,-1,0,-1,1,0,1,-1,-1,1,1,-1,1,0,-1,1,1,-1,1,0,-1,1,1,0,1,-1,-1,0,1,0,-1,1,0,1,-1,0,0,0,0,0,0,0,1,0,-1,-1,0,-1,0,-1,1,0,-1,0,-1,-1},
	{62},
	{1,1,-1,1,0,-1,1,-1,0,-1,1,1,0,-1,-1,1,1,-1,-1,1,0,-1,1,1,1,0,-1,0,-1,1,0,-1,0,0,1,-1,1,-1,0,0,0,-1,0,-1,0,-1,-1,-1,0,-1,-1,-1,0,-1,-1,-1,0,0,1,1,0,-1,1,1},
	{63},
	{1,-1,0,0,-1,1,1,1,0,0,-1,0,-1,1,-1,0,-1,0,-1,1,1,0,1,-1,0,-1,1,0,-1,0,-1,0,0,-1,-1,1,-1,-1,0,0,0,1,0,-1,1,1,0,1,0,1,0,-1,1,0,0,0,1,1,1,-1,-1,0,1,-1,0},
	{64},
	{1,-1,1,0,-1,-1,0,1,0,0,-1,-1,1,-1,0,1,0,-1,1,-1,1,1,-1,0,0,0,0,1,1,1,1,-1,-1,0,-1,1,1,1,0,-1,-1,0,-1,-1,1,-1,-1,-1,0,-1,-1,0,1,0,-1,-1,0,1,0,0,1,-1,0,-1,1,0},
	{65},
	{1,-1,1,-1,-1,1,0,0,-1,1,-1,0,-1,-1,1,-1,-1,0,0,-1,0,-1,0,-1,1,-1,0,-1,-1,0,1,1,1,1,-1,-1,1,1,1,1,1,1,-1,-1,-1,-1,-1,0,-1,1,1,1,1,-1,1,-1,-1,0,-1,1,-1,-1,0,-1,-1,1,-1},
	{66},
	{1,0,1,-1,1,0,-1,-1,0,0,-1,0,0,-1,-1,1,-1,0,0,-1,-1,1,0,0,-1,1,0,-1,1,0,0,-1,0,0,0,0,-1,0,1,-1,-1,-1,0,0,0,1,0,-1,1,-1,-1,1,1,-1,0,0,1,0,0,0,-1,-1,-1,0,0,0,-1,-1},
	{67},
	{1,1,-1,1,0,-1,1,-1,0,-1,-1,-1,-1,0,1,0,-1,0,1,-1,1,-1,0,-1,1,-1,0,0,-1,0,-1,0,0,1,-1,1,-1,1,-1,1,-1,-1,-1,1,1,1,0,1,0,-1,-1,0,-1,1,-1,0,1,0,-1,0,1,0,1,0,0,1,0,0,1},
	{68},
	{1,1,-1,1,1,1,0,0,1,1,0,-1,-1,0,1,0,-1,-1,0,0,-1,1,0,0,-1,0,0,1,0,0,1,0,-1,1,-1,1,1,0,-1,-1,-1,1,-1,0,-1,1,-1,-1,0,1,1,0,1,0,-1,1,1,1,1,-1,-1,1,0,0,1,1,-1,1,0,0},
	{69},
	{1,0,-1,1,-1,1,0,1,0,0,1,1,0,-1,-1,0,0,-1,-1,0,0,0,0,1,0,0,-1,1,-1,-1,1,-1,0,1,1,-1,-1,1,1,1,-1,1,0,1,-1,1,-1,1,-1,1,0,0,-1,1,1,1,0,-1,-1,1,-1,1,1,1,-1,-1,-1,0,-1,1,-1},
	{70},
	{1,1,-1,0,0,0,1,1,0,-1,0,-1,0,0,1,0,1,-1,1,0,-1,-1,-1,0,-1,0,-1,1,-1,1,-1,-1,0,-1,0,0,1,0,0,-1,1,-1,0,-1,1,0,-1,1,1,1,-1,1,1,1,-1,-1,0,0,-1,0,0,-1,0,-1,0,0,0,0,1,0,1,1},
	{71},
	{1,0,1,-1,0,0,-1,-1,-1,1,0,1,-1,-1,-1,-1,0,-1,1,-1,0,-1,-1,1,0,-1,0,0,-1,0,0,0,-1,0,1,1,1,1,-1,-1,0,1,-1,1,-1,0,-1,1,0,1,1,-1,-1,-1,1,0,-1,0,-1,1,-1,0,0,0,-1,-1,0,-1,1,1,-1,0,-1},
	{72},
	{1,1,0,0,1,-1,0,1,1,-1,-1,0,1,-1,1,0,-1,-1,0,-1,-1,-1,0,0,-1,1,1,1,-1,-1,-1,0,1,1,-1,0,-1,1,0,1,1,1,0,0,1,-1,-1,-1,1,1,-1,-1,1,0,0,-1,0,0,-1,1,0,-1,0,0,-1,0,1,-1,-1,0,-1,0,0,0},
	{73},
	{1,-1,0,1,1,0,0,-1,0,1,1,1,1,0,1,-1,0,0,1,1,1,-1,-1,0,0,-1,0,-1,1,1,0,-1,1,-1,-1,1,0,-1,-1,1,1,1,1,0,1,1,-1,0,0,1,-1,-1,-1,0,-1,1,-1,1,-1,-1,0,1,0,1,1,0,0,0,0,1,-1,0,-1,-1,-1},
	{74},
	{1,0,-1,0,0,0,-1,1,0,0,-1,1,0,1,1,0,1,1,0,0,-1,1,1,-1,1,-1,-1,0,-1,-1,0,-1,0,0,0,-1,-1,0,-1,1,-1,0,-1,0,0,-1,-1,0,-1,0,1,-1,-1,1,-1,-1,-1,1,0,-1,1,1,-1,0,0,0,1,1,-1,-1,1,0,0,1,-1,-1},
	{75},
	{1,0,-1,0,1,-1,1,0,1,0,0,-1,0,-1,1,-1,0,1,1,-1,1,-1,1,1,0,1,1,-1,-1,-1,-1,1,1,-1,0,0,0,-1,-1,-1,0,-1,1,1,-1,0,-1,1,0,-1,-1,-1,0,1,-1,-1,1,-1,-1,-1,0,-1,-1,0,0,0,1,1,1,-1,-1,-1,-1,1,0,1,0},
	{76},
	{1,-1,0,0,-1,-1,-1,-1,1,1,1,0,1,-1,-1,0,0,1,-1,1,0,-1,1,0,1,1,-1,0,-1,1,0,1,1,1,-1,0,-1,-1,1,1,-1,-1,-1,-1,0,-1,0,1,-1,-1,1,0,-1,1,-1,0,1,0,-1,1,-1,0,0,0,-1,0,-1,-1,-1,1,-1,-1,1,0,1,-1,1,-1},
	{77},
	{1,-1,1,1,-1,-1,-1,0,0,-1,-1,0,0,1,-1,1,1,1,-1,-1,-1,0,1,0,-1,-1,0,1,1,0,1,1,-1,1,1,0,0,0,1,-1,0,0,0,1,-1,0,1,1,0,-1,-1,0,1,-1,-1,-1,-1,1,-1,0,1,-1,0,1,1,0,-1,-1,1,-1,-1,0,0,1,-1,0,0,-1,0},
	{78},
	{1,-1,0,0,-1,-1,1,0,1,-1,-1,0,1,1,0,-1,-1,-1,1,1,0,1,1,-1,-1,1,0,0,0,0,-1,1,1,0,1,1,1,0,0,1,-1,1,0,1,0,-1,1,1,-1,-1,1,-1,-1,1,0,-1,0,1,0,-1,-1,0,-1,1,0,-1,1,-1,0,0,-1,0,-1,1,0,-1,-1,0,1,0},
	{79},
	{1,-1,0,-1,1,-1,1,0,-1,-1,-1,-1,-1,-1,0,1,-1,-1,0,-1,1,0,0,-1,0,0,-1,1,-1,1,1,-1,1,-1,-1,1,-1,-1,1,1,0,1,-1,1,-1,1,0,1,1,0,1,1,1,-1,0,0,1,1,-1,-1,1,1,0,1,-1,1,1,1,1,1,0,1,0,0,0,-1,0,0,1,1,1},
	{80},
	{1,1,-1,0,-1,0,0,0,0,1,0,-1,0,-1,-1,0,0,0,1,1,1,-1,1,0,1,-1,-1,-1,-1,0,0,-1,0,1,1,1,0,-1,-1,-1,-1,1,0,0,-1,1,-1,0,1,0,1,0,0,0,1,-1,-1,0,1,-1,-1,0,-1,0,-1,1,0,1,-1,1,-1,0,1,0,-1,0,0,1,1,-1,-1,0},
	{81},
	{1,1,-1,1,1,-1,-1,1,-1,1,-1,-1,0,-1,0,-1,0,-1,-1,0,0,-1,-1,-1,1,-1,0,0,-1,-1,1,1,1,1,0,1,-1,1,0,0,0,0,1,1,0,-1,-1,-1,0,0,-1,-1,-1,-1,0,-1,-1,-1,1,-1,-1,1,1,-1,-1,0,-1,-1,-1,1,1,1,0,0,1,-1,-1,-1,1,0,1,1,1},
	{82},
	{1,-1,1,-1,0,-1,-1,0,1,1,1,0,0,0,1,-1,1,0,1,-1,1,-1,0,1,0,1,0,1,0,0,0,0,0,-1,0,-1,1,-1,1,1,1,1,-1,0,0,1,0,0,0,0,0,-1,1,1,-1,-1,1,0,-1,-1,-1,0,-1,1,1,0,-1,0,0,-1,-1,0,1,-1,1,0,0,1,-1,-1,-1,0,0,1},
	{83},
	{1,-1,0,1,0,0,0,-1,0,1,1,1,-1,1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,0,1,0,1,-1,-1,-1,0,-1,1,-1,-1,1,0,-1,0,0,0,1,-1,0,1,-1,1,-1,0,1,0,1,-1,0,-1,-1,-1,-1,0,-1,0,-1,1,-1,0,-1,0,-1,-1,-1,1,1,1,1,1,1,-1,0,-1,1,0,1},
	{84},
	{1,0,-1,-1,0,1,-1,1,1,1,0,-1,1,-1,1,0,0,0,-1,-1,1,-1,-1,0,0,1,1,-1,0,0,0,1,1,0,1,1,-1,-1,1,-1,-1,-1,-1,1,0,0,0,-1,1,0,-1,1,1,-1,0,0,-1,-1,0,1,0,1,0,0,0,0,0,1,1,-1,0,1,0,0,1,-1,1,0,-1,-1,1,0,1,1,1,-1},
	{85},
	{1,-1,0,1,0,-1,1,-1,-1,1,0,-1,-1,-1,0,-1,-1,-1,1,1,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0,-1,0,1,-1,1,1,1,1,1,1,0,0,-1,1,-1,1,0,-1,0,0,-1,0,-1,0,-1,0,-1,0,-1,0,1,0,1,0,-1,0,0,1,0,-1,0,1,-1,1,1,0},
	{86},
	{1,1,-1,0,-1,1,1,1,1,-1,-1,0,-1,1,0,1,0,-1,0,0,-1,-1,1,0,0,1,1,-1,-1,1,1,1,1,0,-1,0,-1,-1,-1,0,0,0,1,1,-1,0,0,0,1,0,-1,-1,1,-1,0,-1,1,0,-1,-1,0,-1,-1,0,1,1,1,-1,-1,-1,0,1,0,-1,1,1,-1,0,0,1,-1,1,1,-1,1,0,0,-1},
	{87},
	{1,0,1,1,-1,1,-1,-1,-1,0,0,0,0,0,1,-1,0,1,1,-1,-1,-1,0,-1,1,0,1,-1,-1,-1,-1,-1,1,-1,1,0,0,1,0,1,0,1,-1,1,1,-1,1,0,-1,-1,1,0,-1,-1,1,1,0,1,1,1,1,0,1,-1,0,0,0,1,0,-1,0,1,1,1,1,1,0,1,0,0,1,-1,-1,1,0,-1,-1,1,1},
	{88},
	{1,0,1,1,0,0,0,-1,-1,-1,0,1,0,1,0,1,1,0,0,-1,-1,0,-1,-1,-1,1,0,-1,0,-1,-1,1,-1,-1,0,0,0,0,1,0,1,0,0,0,0,1,1,-1,0,-1,1,-1,0,1,-1,1,1,-1,-1,-1,0,0,-1,0,0,-1,-1,0,0,-1,1,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,0,-1,1,1},
	{89},
	{1,1,0,1,-1,0,-1,-1,1,1,-1,0,1,-1,0,1,1,0,0,0,1,-1,-1,1,0,-1,0,0,-1,-1,0,1,-1,1,1,0,0,0,1,-1,-1,-1,1,1,1,0,1,0,1,0,-1,1,1,-1,1,1,1,0,0,1,1,-1,1,-1,-1,1,1,0,0,1,1,1,1,1,1,0,-1,-1,0,-1,1,0,-1,1,-1,-1,0,1,1,-1,1},
	{90},
	{1,0,-1,0,1,1,-1,-1,1,0,1,-1,1,-1,0,1,-1,1,1,0,0,-1,0,1,0,-1,0,1,0,1,1,-1,1,-1,1,0,1,1,1,-1,-1,1,0,-1,-1,-1,-1,-1,-1,1,1,0,1,1,-1,0,1,0,1,0,1,1,1,0,-1,0,-1,-1,0,0,-1,1,-1,-1,1,0,-1,-1,1,-1,-1,-1,1,-1,1,-1,1,0,1,0,-1,1},
	{91},
	{1,1,0,1,-1,0,1,-1,-1,-1,0,-1,-1,-1,1,0,-1,1,1,-1,1,0,1,-1,1,0,1,0,0,0,1,-1,-1,-1,-1,0,0,-1,0,1,-1,-1,0,0,-1,-1,-1,1,-1,-1,1,1,1,1,1,0,0,0,1,1,1,-1,-1,-1,-1,-1,1,-1,0,-1,1,1,1,-1,0,1,0,1,1,0,0,1,0,-1,1,-1,1,-1,-1,1,0,-1,1},
	{92},
	{1,0,1,1,-1,-1,-1,0,0,0,-1,0,0,1,1,-1,1,1,-1,1,1,-1,-1,0,1,0,0,-1,1,-1,0,1,0,-1,1,1,0,1,-1,1,1,0,0,0,0,0,0,0,0,0,-1,0,0,-1,-1,0,1,-1,-1,1,0,0,0,-1,1,1,-1,1,1,1,1,1,-1,0,-1,1,-1,0,-1,1,-1,-1,0,1,0,1,1,0,1,1,0,0,0,1},
	{93},
	{1,-1,1,0,-1,-1,1,1,0,-1,0,0,-1,1,-1,-1,-1,0,0,-1,-1,1,-1,-1,1,-1,-1,-1,-1,-1,1,0,0,0,1,1,1,1,1,0,-1,-1,-1,0,0,-1,1,1,-1,0,1,-1,0,1,1,0,0,1,0,0,-1,0,-1,1,-1,-1,0,-1,-1,1,0,0,-1,1,-1,0,-1,1,-1,0,-1,0,0,1,0,0,-1,1,-1,1,1,0,0,1,0},
	{94},
	{1,1,0,1,1,-1,-1,1,1,-1,1,1,0,0,1,0,0,0,1,0,-1,0,1,-1,0,0,1,0,0,1,0,0,1,1,-1,1,-1,1,1,-1,-1,1,1,1,-1,0,-1,1,0,-1,-1,1,1,-1,1,1,1,1,-1,0,1,0,1,1,-1,-1,0,0,-1,0,0,1,-1,-1,0,0,-1,1,0,1,-1,0,0,-1,1,0,1,0,-1,-1,-1,-1,1,-1,-1,1},
	{95},
	{1,0,-1,-1,1,-1,1,1,-1,1,-1,0,1,0,0,-1,1,-1,0,-1,1,-1,1,1,0,1,0,1,-1,1,1,-1,0,-1,-1,0,-1,0,-1,1,0,-1,-1,-1,-1,1,0,1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,1,-1,1,1,-1,0,1,1,1,-1,-1,-1,1,0,0,-1,1,1,1,0,1,-1,1,1,1,1,-1,1,1,-1,1,0,0,1,-1,-1,-1,1,1},
	{96},
	{1,-1,1,0,0,-1,-1,1,0,1,1,-1,-1,1,0,-1,0,0,1,1,0,0,0,-1,-1,0,1,0,1,1,1,1,0,0,0,1,1,0,1,0,-1,1,1,-1,0,-1,0,1,0,-1,1,-1,1,-1,-1,1,1,-1,-1,0,-1,-1,0,0,-1,1,0,-1,0,0,1,0,-1,0,1,0,-1,-1,0,1,0,-1,-1,-1,0,0,-1,0,1,0,-1,-1,0,0,1,1,0,-1},
	{97},
	{1,0,-1,1,1,1,0,1,-1,-1,-1,-1,1,0,-1,1,-1,-1,-1,0,-1,0,1,0,1,-1,-1,0,-1,0,0,0,-1,1,0,-1,1,1,1,1,-1,0,0,-1,1,0,1,1,0,-1,0,0,1,-1,-1,0,0,1,1,1,-1,0,0,0,-1,1,-1,1,1,1,-1,1,-1,0,0,0,1,-1,0,0,0,-1,-1,-1,0,-1,1,-1,1,1,1,0,0,0,-1,0,-1,-1,1},
	{98},
	{1,-1,0,0,1,-1,-1,1,1,1,0,-1,-1,0,0,0,1,0,1,-1,0,-1,-1,1,1,0,-1,1,1,-1,1,1,-1,0,1,1,1,1,1,0,1,0,1,-1,1,-1,1,1,1,0,1,1,-1,-1,0,-1,0,1,1,1,-1,1,1,-1,-1,0,-1,-1,1,-1,1,0,1,0,1,0,-1,1,-1,-1,0,-1,1,1,0,0,1,1,0,1,1,0,1,1,-1,-1,0,0,0,-1},
	{99},
	{1,-1,0,-1,-1,1,0,0,-1,-1,0,-1,-1,0,0,0,1,1,-1,-1,0,1,-1,-1,1,-1,1,0,-1,1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,1,0,0,-1,1,-1,-1,-1,1,-1,-1,0,-1,0,0,1,0,-1,1,-1,-1,-1,0,-1,-1,1,-1,-1,0,-1,1,0,0,-1,1,0,0,1,1,0,1,1,1,-1,-1,0,-1,-1,1,1,0,-1,-1,1,-1,0,0,1,-1,-1,1},
	{100},
	{1,-1,1,1,0,1,-1,1,-1,-1,1,-1,1,1,1,-1,0,1,0,1,0,0,0,-1,1,-1,0,-1,-1,0,-1,1,0,1,1,0,-1,-1,-1,0,-1,-1,0,-1,-1,0,-1,0,-1,1,0,1,1,-1,-1,1,1,1,1,1,0,-1,1,0,-1,0,1,0,0,-1,1,1,-1,-1,1,-1,0,0,1,-1,0,0,1,-1,1,-1,1,0,-1,1,-1,1,-1,1,-1,0,0,1,1,1,1,1},
	{101},
	{1,1,0,-1,-1,1,-1,-1,0,-1,1,-1,0,1,0,-1,-1,0,1,1,-1,0,0,-1,1,-1,1,1,-1,1,1,1,-1,0,1,0,1,-1,0,-1,0,0,1,-1,0,0,-1,0,1,-1,1,0,1,0,0,0,0,0,1,0,-1,1,-1,0,-1,0,-1,1,0,1,0,-1,0,-1,1,1,0,1,0,1,0,0,0,-1,1,1,-1,-1,-1,1,1,0,0,0,-1,1,-1,0,-1,1,-1,0,0},
	{102},
	{1,-1,1,-1,-1,0,1,-1,0,0,0,1,0,-1,1,1,0,0,0,1,0,0,1,0,-1,1,0,-1,0,0,0,1,0,0,-1,1,1,-1,1,-1,1,0,-1,-1,0,-1,-1,-1,1,1,-1,0,0,-1,-1,0,-1,1,1,0,-1,0,0,1,-1,0,1,-1,0,0,0,0,1,-1,1,1,0,0,-1,0,0,0,1,1,0,1,0,0,0,1,0,1,0,1,1,0,1,0,0,-1,0,0,1,0},
	{103},
	{1,-1,1,1,-1,0,0,0,-1,1,1,1,1,0,1,1,1,0,1,0,0,1,0,1,1,1,1,0,-1,1,0,1,-1,0,0,-1,-1,-1,1,-1,-1,0,-1,1,-1,-1,0,-1,1,0,0,0,0,1,0,0,-1,1,1,-1,0,1,-1,0,-1,0,1,-1,1,0,-1,-1,-1,0,1,0,1,0,1,1,1,0,-1,0,-1,0,-1,-1,0,1,0,1,1,0,0,-1,0,-1,-1,0,1,1,1,0,-1},
	{104},
	{1,0,1,-1,1,-1,-1,1,-1,0,-1,-1,1,0,1,1,0,1,1,-1,-1,1,0,-1,1,0,1,-1,0,0,-1,0,-1,1,1,1,-1,-1,1,-1,0,-1,-1,-1,1,-1,0,-1,-1,-1,-1,1,-1,1,-1,0,-1,-1,0,-1,1,1,0,1,0,0,1,-1,0,1,-1,-1,-1,1,0,1,-1,-1,1,0,0,1,0,1,1,0,0,-1,0,1,-1,0,-1,1,1,0,-1,0,1,-1,0,0,0,0,-1,-1},
	{105},
	{1,-1,0,-1,1,0,1,1,-1,1,-1,1,-1,1,0,-1,0,-1,1,1,1,-1,0,-1,-1,1,1,0,0,-1,0,-1,0,-1,1,-1,0,0,-1,-1,-1,-1,-1,0,0,0,1,-1,-1,0,1,1,0,0,-1,1,-1,-1,0,1,-1,1,-1,1,-1,1,-1,1,0,-1,1,1,0,0,0,-1,1,0,-1,1,-1,-1,-1,-1,1,-1,1,-1,0,0,1,0,0,-1,0,0,1,0,1,0,1,0,1,0,-1,-1,0},
	{106},
	{1,0,-1,0,0,1,1,1,-1,-1,0,1,1,-1,-1,1,1,0,0,1,-1,-1,-1,0,1,0,1,-1,0,0,-1,-1,1,-1,0,0,0,0,0,1,1,1,1,0,1,1,0,-1,-1,-1,-1,0,0,-1,-1,-1,1,-1,0,-1,0,1,-1,1,0,1,-1,1,0,1,0,-1,1,0,1,1,0,0,-1,1,1,-1,0,-1,0,1,-1,-1,1,1,0,1,1,1,0,-1,1,1,1,0,0,0,0,0,1,0,1,0},
	{107},
	{1,-1,1,1,-1,-1,-1,-1,1,0,0,-1,-1,-1,0,0,0,0,-1,-1,1,0,-1,-1,1,0,1,0,0,0,0,-1,0,-1,-1,0,1,0,1,0,1,0,1,-1,0,-1,1,-1,0,1,1,0,0,1,1,-1,0,1,0,-1,-1,0,0,1,1,1,-1,0,0,-1,0,0,0,-1,0,-1,1,0,0,0,0,0,-1,-1,-1,-1,0,-1,-1,0,-1,0,1,1,-1,1,0,0,0,0,1,-1,1,1,0,0,1,-1,-1},
	{108},
	{1,-1,0,0,1,1,1,0,1,0,1,0,0,0,0,1,-1,1,-1,0,0,-1,-1,-1,-1,-1,-1,1,1,1,0,0,-1,1,-1,1,-1,0,-1,1,-1,0,-1,0,-1,1,0,0,-1,1,1,0,1,0,-1,-1,1,0,0,0,-1,1,-1,-1,-1,1,-1,-1,0,1,-1,0,-1,1,-1,0,1,0,1,1,1,-1,1,1,1,1,-1,0,-1,1,-1,0,0,0,1,0,0,-1,1,1,1,0,-1,-1,0,-1,1,-1,-1,1},
	{109},
	{1,-1,0,-1,-1,0,0,1,-1,0,0,-1,1,1,0,1,0,0,1,-1,1,0,0,-1,1,-1,1,0,-1,-1,0,1,0,0,0,0,-1,-1,0,-1,0,-1,0,0,-1,1,0,1,1,-1,-1,0,1,0,0,1,1,0,-1,1,1,-1,-1,0,0,0,-1,1,0,1,-1,-1,-1,1,1,0,0,0,-1,0,0,-1,-1,0,1,1,0,0,1,-1,1,0,0,1,1,1,0,-1,1,1,1,1,-1,0,0,-1,1,0,0,-1,1},
	{110},
	{1,1,0,1,1,0,-1,1,1,-1,1,1,0,0,0,-1,1,-1,0,0,-1,-1,-1,-1,1,-1,0,-1,-1,-1,1,-1,1,-1,1,1,-1,-1,1,1,1,1,0,0,-1,-1,0,1,0,1,0,1,-1,0,-1,1,-1,0,-1,-1,1,-1,-1,1,0,-1,1,1,-1,1,1,1,1,-1,-1,1,1,1,-1,-1,1,1,1,-1,0,1,-1,0,0,0,1,0,1,1,-1,0,1,1,-1,0,-1,1,-1,1,-1,1,1,-1,0,1,-1,0},
	{111},
	{1,-1,1,-1,0,1,1,-1,-1,1,-1,0,-1,0,1,0,-1,-1,1,1,0,0,1,0,-1,1,-1,0,1,0,1,1,0,1,-1,-1,0,-1,-1,0,-1,1,1,0,0,1,-1,0,-1,1,1,1,1,1,-1,1,0,1,0,0,0,-1,1,-1,-1,-1,0,0,0,1,-1,1,1,-1,0,-1,-1,0,1,-1,0,1,-1,-1,1,1,-1,-1,1,0,1,-1,1,0,0,1,1,-1,0,-1,-1,1,0,-1,-1,1,-1,-1,0,-1,0,1,-1},
	{112},
	{1,-1,0,1,1,1,0,0,1,0,0,-1,-1,0,0,0,0,-1,1,0,1,1,-1,-1,1,-1,-1,1,1,1,1,1,1,1,1,-1,1,-1,0,0,0,1,-1,1,0,1,0,-1,-1,-1,1,0,-1,1,0,-1,-1,0,-1,1,1,1,1,0,1,0,0,0,0,-1,-1,0,-1,0,0,0,-1,-1,1,0,0,0,-1,-1,0,0,0,0,-1,0,0,1,0,-1,1,0,0,-1,-1,0,0,0,1,1,1,0,0,0,0,0,1,0,-1,1},
	{113},
	{1,1,-1,1,1,1,0,-1,1,-1,0,0,1,-1,0,1,0,-1,-1,-1,0,1,1,0,0,1,0,0,0,1,0,-1,1,1,0,0,1,1,1,0,1,-1,-1,1,-1,1,1,-1,-1,1,0,1,1,-1,-1,0,-1,1,-1,0,0,1,-1,-1,0,1,0,0,0,-1,-1,0,0,1,0,-1,1,0,-1,1,1,1,0,1,-1,1,-1,-1,0,0,-1,-1,0,0,0,-1,-1,1,1,1,0,0,0,-1,-1,-1,-1,1,0,0,1,0,-1,0,-1},
	{114},
	{1,-1,1,0,0,1,0,-1,0,1,0,0,1,1,-1,-1,0,1,1,0,-1,-1,-1,0,0,-1,-1,1,1,-1,-1,1,-1,-1,0,-1,1,-1,-1,0,1,-1,1,0,-1,-1,1,0,1,-1,-1,-1,0,0,0,1,1,0,0,0,-1,1,0,0,1,1,0,1,-1,-1,0,1,-1,-1,1,0,0,1,-1,-1,1,-1,0,0,1,-1,0,1,0,-1,0,1,0,-1,0,-1,-1,1,-1,0,1,0,0,-1,-1,0,0,1,0,1,-1,-1,-1,1,-1,0},
	{115},
	{1,1,-1,-1,0,1,-1,0,0,-1,0,0,-1,1,0,0,1,0,0,-1,1,0,-1,0,0,1,1,-1,-1,-1,-1,-1,1,-1,0,0,-1,-1,1,-1,-1,-1,0,0,-1,-1,-1,-1,1,1,0,1,0,1,0,0,1,0,0,1,0,0,0,0,-1,1,1,0,1,-1,0,0,-1,-1,-1,0,-1,-1,1,-1,0,0,-1,-1,0,0,0,-1,-1,-1,-1,1,1,0,0,-1,1,0,-1,1,0,0,0,-1,-1,1,1,-1,-1,-1,0,0,1,0,-1,-1,0},
	{116},
	{1,0,-1,1,1,1,0,1,-1,-1,1,1,-1,0,0,-1,-1,0,0,0,-1,1,1,-1,1,1,1,1,0,-1,-1,0,1,0,-1,1,1,-1,0,-1,-1,0,1,-1,0,0,1,0,0,0,0,0,-1,-1,0,-1,-1,0,-1,-1,1,0,0,1,0,1,0,-1,1,-1,-1,-1,1,0,0,-1,1,0,-1,0,1,0,1,-1,1,0,0,-1,-1,1,-1,1,1,1,1,-1,1,-1,0,0,0,1,1,0,0,0,1,0,1,1,-1,-1,0,-1,0,0,1,-1},
	{117},
	{1,0,-1,-1,1,0,-1,0,1,0,0,0,0,0,1,0,-1,1,-1,-1,1,1,-1,-1,0,1,-1,-1,0,0,-1,0,1,-1,-1,0,0,0,-1,1,1,1,-1,-1,-1,1,1,0,1,1,0,0,1,-1,1,0,1,1,1,0,0,1,0,-1,-1,0,1,1,1,1,0,-1,0,1,0,-1,1,0,1,0,-1,1,1,0,1,0,1,0,0,1,1,1,1,-1,-1,1,1,1,-1,-1,1,1,0,0,1,1,1,0,0,1,-1,1,1,-1,-1,0,1,0,-1},
	{118},
	{1,1,-1,-1,0,-1,1,1,0,1,0,1,1,0,1,1,0,0,0,1,-1,-1,1,1,-1,-1,-1,-1,0,1,-1,0,0,0,1,0,0,-1,0,0,1,1,-1,0,0,1,0,-1,0,1,-1,0,0,-1,1,0,-1,-1,1,0,1,-1,-1,1,1,-1,0,-1,-1,1,1,1,1,1,0,-1,1,1,0,-1,-1,0,1,0,1,1,-1,-1,-1,-1,-1,1,-1,0,1,1,0,-1,0,1,1,-1,1,1,0,0,-1,-1,0,1,0,1,0,0,0,0,0,0,1,0},
	{119},
	{1,0,-1,-1,1,-1,-1,1,1,0,-1,0,1,0,0,-1,0,1,1,-1,1,-1,1,1,1,0,-1,0,-1,-1,-1,-1,0,-1,-1,0,0,-1,-1,0,0,-1,-1,0,-1,1,1,1,1,1,-1,0,-1,-1,-1,-1,0,0,1,-1,0,1,-1,0,-1,0,-1,1,1,0,-1,0,1,0,-1,-1,-1,-1,-1,0,1,0,1,-1,0,-1,0,0,1,-1,0,0,1,1,1,0,-1,0,0,1,1,1,0,1,0,1,-1,1,-1,0,-1,1,1,-1,0,-1,0,1,1,-1,-1},
	{120},
	{1,1,-1,-1,0,0,0,0,-1,0,-1,-1,1,-1,-1,1,1,0,-1,1,1,1,-1,0,0,-1,-1,1,-1,0,-1,-1,-1,1,-1,-1,-1,-1,0,1,0,1,1,0,-1,-1,0,-1,0,0,-1,1,0,0,-1,0,1,0,-1,1,1,0,-1,0,-1,0,0,1,0,-1,0,0,-1,0,1,-1,1,0,0,0,-1,1,-1,1,0,0,0,-1,1,0,-1,-1,0,0,0,1,1,-1,1,1,0,-1,-1,0,1,-1,1,0,1,0,-1,-1,-1,0,1,1,-1,0,-1,-1,-1,-1},
	{121},
	{1,0,1,-1,1,1,0,1,1,0,1,1,-1,0,1,1,1,1,-1,0,0,1,-1,-1,0,1,-1,-1,-1,1,-1,-1,0,-1,-1,0,1,1,0,1,0,0,0,1,-1,0,1,-1,0,-1,1,0,-1,1,0,1,1,1,1,-1,0,-1,0,0,-1,1,1,-1,1,0,1,0,-1,0,-1,0,-1,-1,1,0,0,1,1,1,1,1,0,1,0,-1,-1,0,0,0,1,0,0,0,1,-1,0,1,0,0,0,-1,-1,0,-1,1,-1,1,0,0,0,0,-1,1,0,1,-1,0,-1},
	{122},
	{1,-1,0,1,-1,1,-1,0,-1,0,1,0,0,-1,1,0,0,-1,0,1,0,-1,1,-1,-1,0,0,-1,1,1,1,-1,0,0,1,0,-1,-1,1,1,0,1,-1,-1,-1,0,0,1,1,1,1,-1,-1,0,0,-1,-1,1,-1,-1,-1,0,-1,0,1,-1,1,0,-1,1,-1,1,1,0,1,-1,1,1,-1,1,1,1,-1,-1,-1,1,-1,0,0,1,1,0,0,-1,1,0,0,1,1,1,1,-1,-1,1,1,-1,1,1,1,1,-1,1,0,-1,1,1,1,-1,0,1,-1,0,0,0},
	{123},
	{1,0,-1,-1,0,0,1,0,0,1,0,0,-1,0,0,1,0,1,-1,1,-1,-1,1,0,-1,0,-1,0,-1,1,1,1,-1,-1,-1,-1,-1,1,0,1,0,-1,-1,1,0,0,1,0,0,-1,-1,0,-1,-1,-1,0,1,0,-1,-1,0,0,1,-1,0,-1,-1,1,-1,0,0,1,0,1,-1,-1,-1,-1,0,1,-1,1,0,0,0,1,-1,-1,0,0,0,-1,1,-1,-1,0,1,-1,0,1,1,-1,1,0,-1,1,0,-1,1,0,-1,-1,0,-1,1,1,1,-1,-1,0,0,0,0,-1,-1},
	{124},
	{1,-1,0,-1,1,-1,1,0,1,0,0,1,0,-1,1,0,1,0,-1,-1,0,0,0,0,1,0,1,1,1,-1,1,1,0,-1,-1,0,0,-1,1,0,1,-1,-1,-1,0,0,1,0,-1,-1,1,-1,0,0,0,0,1,0,1,1,1,0,1,0,1,1,-1,0,-1,1,-1,-1,-1,0,-1,1,1,-1,0,0,0,0,0,-1,1,-1,1,0,0,0,0,0,-1,-1,-1,1,1,-1,1,0,-1,1,0,0,0,0,-1,1,-1,0,-1,0,-1,1,0,1,1,0,0,0,1,1,-1,-1,0,0},
	{125},
	{1,0,1,1,-1,0,1,-1,-1,0,0,1,1,1,0,0,0,-1,-1,1,-1,1,0,0,1,0,-1,-1,1,1,-1,1,-1,-1,1,0,1,0,0,1,0,-1,1,0,1,-1,1,0,0,0,-1,0,-1,1,0,1,-1,0,-1,-1,-1,0,-1,0,1,-1,1,0,1,-1,-1,-1,0,-1,0,0,-1,1,1,-1,-1,-1,1,0,-1,-1,0,-1,1,0,0,-1,-1,1,1,1,-1,0,0,1,-1,0,-1,0,-1,1,-1,0,1,-1,0,-1,1,0,1,1,1,-1,0,0,-1,-1,-1,-1,1,-1,-1},
	{126},
	{1,-1,0,1,-1,-1,-1,-1,0,-1,0,0,0,-1,0,0,1,1,0,-1,1,0,0,1,0,1,1,1,-1,1,1,0,1,-1,0,-1,-1,1,0,1,1,-1,0,0,0,1,1,1,1,0,1,0,1,-1,0,0,-1,0,1,-1,-1,0,1,-1,1,0,0,-1,-1,-1,-1,1,0,1,-1,-1,0,-1,1,1,0,1,0,1,-1,-1,-1,-1,1,-1,-1,1,0,-1,-1,0,0,1,1,0,0,-1,0,1,-1,1,-1,1,-1,-1,0,1,1,-1,0,1,0,-1,-1,-1,-1,0,-1,-1,1,1,1,0},
	{127},
	{1,0,1,-1,-1,-1,0,-1,0,1,0,1,1,0,0,-1,0,1,0,-1,-1,-1,1,-1,0,0,-1,-1,0,1,0,0,0,0,1,1,1,0,0,0,0,-1,0,0,0,1,-1,0,0,0,0,-1,1,-1,0,0,1,-1,0,1,1,-1,0,0,1,-1,0,1,0,1,-1,-1,1,1,1,1,1,1,-1,0,0,1,1,-1,1,0,0,1,0,-1,0,-1,0,1,1,-1,0,1,1,-1,0,0,0,1,-1,0,0,-1,-1,0,1,1,-1,0,1,-1,-1,1,-1,0,1,1,-1,-1,1,-1,0,0,1},
	{128},
	{1,0,-1,-1,0,0,0,0,1,0,1,1,1,-1,0,-1,-1,0,1,0,1,-1,1,1,-1,-1,0,1,-1,1,0,-1,0,0,-1,1,-1,1,-1,-1,0,1,-1,1,-1,-1,1,0,0,0,1,-1,1,1,-1,0,1,1,-1,-1,1,1,0,-1,1,1,1,-1,1,1,-1,0,1,1,-1,1,1,1,1,0,1,0,-1,0,1,-1,1,0,-1,-1,-1,1,-1,0,-1,1,0,1,1,0,1,0,-1,1,0,-1,1,-1,0,0,1,-1,0,1,0,-1,0,1,1,1,1,1,-1,-1,0,-1,-1,-1,-1,-1},
	{129},
	{1,0,-1,1,0,0,1,1,-1,1,1,1,1,0,1,-1,-1,1,0,1,-1,1,1,0,1,1,-1,1,1,0,-1,0,-1,0,-1,1,-1,1,0,-1,1,1,-1,1,-1,-1,-1,-1,1,1,1,-1,1,-1,0,1,-1,1,1,1,0,0,0,1,1,0,0,-1,1,0,0,1,-1,1,1,-1,1,1,0,1,-1,1,1,-1,1,0,-1,1,-1,-1,1,1,0,0,0,0,1,0,0,1,1,-1,1,-1,-1,1,0,1,-1,1,1,-1,1,0,-1,1,1,-1,0,0,0,0,-1,-1,-1,-1,0,-1,0,0,-1},
	{130},
	{1,1,0,1,1,1,-1,0,1,-1,0,-1,0,1,-1,-1,0,1,1,0,-1,1,0,-1,1,-1,-1,1,1,0,-1,-1,0,1,0,0,1,1,1,1,-1,1,1,0,1,0,1,-1,-1,0,1,0,0,-1,1,1,-1,1,0,-1,1,1,1,0,1,0,1,1,-1,1,0,-1,0,0,-1,-1,1,-1,0,-1,-1,-1,1,0,-1,0,0,0,1,0,1,0,0,0,-1,0,1,1,-1,-1,1,1,0,0,-1,0,1,-1,-1,0,0,-1,0,0,1,-1,1,0,0,1,-1,-1,-1,0,1,-1,1,1,-1,-1,1,-1},
	{131},
	{1,1,0,1,1,1,-1,-1,-1,0,0,0,-1,1,1,1,0,-1,1,-1,-1,-1,-1,1,1,-1,1,-1,1,1,-1,0,0,-1,0,1,-1,0,-1,-1,1,0,1,1,-1,0,1,1,1,0,0,1,1,0,0,1,1,1,0,1,0,1,-1,0,1,1,-1,1,0,-1,1,0,1,0,1,0,-1,0,-1,1,0,1,1,0,1,0,-1,0,0,1,0,-1,1,-1,0,0,1,1,0,0,-1,0,-1,-1,0,1,0,0,0,1,1,-1,1,0,0,1,-1,-1,-1,0,1,-1,1,1,-1,0,0,1,0,-1,0,0,0},
	{132},
	{1,-1,1,0,0,1,1,-1,1,0,1,1,0,-1,1,-1,0,0,-1,0,1,-1,1,0,1,0,-1,1,-1,0,0,-1,1,-1,1,0,-1,1,1,1,-1,0,1,1,1,1,-1,-1,-1,-1,-1,0,0,1,1,1,1,-1,0,1,1,1,-1,1,0,-1,-1,0,-1,1,1,0,0,0,-1,0,0,-1,0,1,0,0,0,-1,1,-1,1,0,-1,0,0,-1,1,1,-1,-1,1,-1,1,-1,-1,1,0,1,0,0,-1,1,1,1,1,0,0,-1,1,0,0,1,-1,-1,-1,0,0,1,0,1,-1,0,-1,0,-1,0,-1,0},
	{133},
	{1,0,-1,-1,1,-1,-1,1,1,-1,-1,0,1,0,1,-1,1,0,-1,-1,0,-1,0,0,0,1,0,0,-1,0,0,-1,1,0,0,0,0,1,0,0,1,0,1,0,0,1,1,-1,-1,-1,0,-1,0,-1,0,-1,-1,-1,-1,-1,0,0,-1,0,-1,1,-1,0,0,0,1,0,-1,1,-1,0,0,-1,1,-1,-1,0,0,1,0,1,-1,0,-1,-1,1,-1,0,0,0,0,0,1,0,-1,-1,0,0,0,0,1,-1,-1,-1,-1,0,0,1,1,0,0,1,1,-1,-1,-1,0,-1,1,-1,1,0,0,0,-1,0,-1,0,0,1},
	{134},
	{1,1,-1,-1,1,1,0,1,1,0,0,0,-1,1,0,-1,1,-1,0,0,-1,1,1,0,0,-1,-1,0,1,0,0,0,-1,0,1,0,1,-1,-1,0,0,1,-1,1,1,-1,1,1,-1,1,0,0,0,-1,-1,-1,1,1,1,0,-1,0,0,1,-1,-1,0,1,1,1,0,-1,1,0,-1,1,1,-1,1,-1,1,-1,1,-1,1,1,1,0,1,1,-1,0,-1,0,-1,-1,-1,0,-1,1,-1,0,-1,-1,0,0,-1,-1,1,1,0,0,0,-1,-1,-1,0,1,1,-1,1,1,0,1,1,1,0,-1,0,0,1,-1,0,-1,0,1},
	{135},
	{1,-1,1,0,1,1,0,0,0,1,-1,-1,0,-1,-1,-1,1,0,-1,0,-1,1,-1,0,-1,0,0,0,-1,-1,0,1,-1,-1,0,-1,-1,-1,0,1,-1,0,1,1,1,1,-1,0,-1,0,0,1,-1,0,-1,0,-1,-1,-1,-1,-1,0,0,-1,1,-1,-1,-1,0,1,-1,1,0,-1,0,0,-1,1,-1,1,0,0,1,0,1,1,-1,-1,1,-1,1,1,1,0,-1,1,0,0,1,-1,-1,1,1,1,-1,0,0,1,-1,0,0,1,-1,-1,1,-1,-1,1,0,0,0,-1,0,-1,0,1,-1,-1,-1,-1,-1,1,-1,-1,0,0,1},
	{136},
	{1,-1,0,1,1,0,1,-1,-1,1,0,1,1,0,1,1,0,1,1,-1,-1,-1,-1,-1,0,-1,-1,0,1,-1,-1,1,-1,1,0,-1,-1,-1,0,1,-1,-1,0,0,1,0,-1,-1,-1,-1,0,1,-1,0,-1,1,-1,-1,-1,-1,0,-1,1,0,-1,-1,-1,0,0,0,-1,-1,1,1,0,1,-1,1,-1,1,-1,1,1,-1,0,1,0,1,-1,0,1,1,-1,0,0,-1,1,0,0,0,0,1,1,0,0,0,0,-1,-1,0,1,0,0,0,1,-1,0,-1,1,1,1,1,0,1,0,0,1,0,1,1,-1,0,0,-1,-1,0,0,0},
	{137},
	{1,0,1,-1,-1,0,1,0,-1,-1,0,1,0,0,0,-1,0,-1,-1,0,-1,0,-1,1,-1,1,0,1,-1,1,0,-1,-1,1,0,0,-1,-1,-1,0,0,0,-1,-1,-1,0,-1,1,-1,1,0,0,0,0,-1,1,0,1,0,1,1,0,-1,1,-1,0,0,0,1,-1,-1,0,0,0,0,1,0,1,1,0,1,-1,-1,-1,-1,0,1,0,-1,1,0,-1,-1,0,-1,0,-1,1,1,-1,1,-1,1,1,1,-1,0,-1,-1,0,1,1,1,1,0,1,0,0,1,-1,-1,-1,-1,0,1,0,-1,-1,0,0,-1,0,0,1,-1,-1,0,1,0},
	{138},
	{1,0,1,-1,1,0,1,1,-1,-1,1,0,0,1,-1,0,-1,-1,-1,-1,0,-1,1,-1,0,1,0,1,-1,-1,1,0,0,0,1,0,-1,0,0,-1,0,-1,-1,0,-1,-1,-1,0,0,-1,1,1,-1,1,0,0,0,1,0,-1,-1,0,0,0,-1,-1,-1,0,1,0,1,0,-1,1,-1,0,1,-1,1,1,0,1,0,1,0,1,0,0,-1,-1,0,-1,1,1,-1,-1,0,0,1,-1,0,1,1,0,-1,1,-1,1,-1,-1,1,1,-1,0,0,0,0,1,1,1,0,0,-1,-1,0,0,0,-1,1,-1,-1,-1,0,0,1,0,-1,1,0,0},
	{139},
	{1,0,1,1,0,-1,1,-1,1,0,0,0,1,-1,0,1,-1,0,1,1,-1,1,1,-1,1,1,0,-1,-1,1,0,-1,0,-1,-1,1,0,1,-1,0,0,-1,0,0,-1,1,0,-1,0,0,0,1,0,0,-1,0,-1,0,0,1,0,0,1,-1,1,1,1,1,1,0,-1,0,0,0,1,0,1,0,1,0,-1,-1,-1,1,0,-1,-1,1,0,-1,1,1,1,0,1,0,0,-1,-1,-1,0,1,1,1,0,1,0,-1,0,0,0,1,1,1,0,0,1,1,0,-1,-1,-1,-1,1,0,-1,0,1,-1,1,-1,1,1,-1,1,1,-1,-1,-1,0,1},
	{140},
	{1,0,-1,-1,1,-1,0,1,0,1,0,0,-1,1,1,1,1,1,1,0,-1,-1,-1,1,-1,1,0,-1,0,0,1,0,-1,-1,1,0,0,-1,-1,-1,1,1,0,-1,1,0,-1,0,1,-1,1,-1,0,0,1,1,-1,1,-1,1,0,0,0,1,0,0,-1,0,1,0,0,1,0,0,-1,0,1,0,1,1,0,-1,-1,1,0,-1,1,1,1,-1,1,1,0,0,0,-1,-1,1,0,-1,-1,0,1,1,-1,1,-1,1,-1,-1,-1,0,0,-1,1,-1,-1,0,1,0,1,1,-1,-1,0,1,1,1,0,0,1,1,-1,0,1,-1,0,1,0,0,-1,0},
	{141},
	{1,1,-1,0,0,1,0,-1,0,-1,1,1,0,1,0,0,1,0,1,0,1,1,0,-1,0,0,1,-1,0,-1,0,-1,-1,1,1,0,0,-1,1,1,-1,-1,1,1,-1,0,-1,1,1,0,0,-1,-1,-1,-1,-1,0,1,-1,1,-1,1,-1,0,0,1,-1,1,-1,0,1,0,1,0,0,1,0,-1,1,-1,0,0,-1,0,1,1,1,0,1,-1,1,-1,1,-1,1,-1,-1,-1,-1,-1,0,-1,1,0,-1,1,-1,0,1,-1,0,-1,1,-1,1,1,1,-1,-1,1,-1,-1,1,-1,0,1,0,1,-1,-1,1,1,-1,-1,0,0,-1,1,1,1,-1,1,1},
	{142},
	{1,1,-1,-1,0,-1,-1,-1,-1,-1,0,1,-1,-1,1,1,0,-1,-1,1,1,1,-1,0,-1,0,-1,-1,0,1,1,1,0,-1,0,-1,-1,0,0,-1,1,1,-1,-1,1,1,1,0,0,1,1,-1,1,1,-1,0,0,-1,0,-1,1,-1,-1,0,0,0,1,1,-1,0,-1,-1,-1,0,-1,-1,0,-1,1,1,-1,0,0,-1,0,1,0,-1,1,-1,-1,1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,1,1,0,1,1,0,1,1,1,0,0,-1,-1,-1,0,-1,-1,0,-1,1,0,0,0,0,0,0,1,1,-1,1,-1,1,-1,1,-1,1,0,-1,1,0,0},
	{143},
	{1,0,1,-1,0,-1,0,0,1,-1,1,-1,-1,0,-1,1,1,1,0,-1,0,0,0,0,1,-1,1,0,0,0,-1,0,-1,0,1,0,0,-1,-1,-1,0,-1,0,0,0,1,1,1,0,-1,-1,-1,-1,0,0,1,1,0,0,0,-1,0,1,0,1,0,1,0,-1,0,1,1,0,0,0,-1,-1,0,1,1,1,-1,-1,1,1,1,1,0,0,-1,-1,1,-1,1,-1,-1,1,0,1,-1,1,0,1,0,-1,0,0,0,-1,1,1,-1,1,-1,1,1,-1,-1,0,0,-1,0,-1,-1,1,0,1,1,-1,0,1,1,-1,1,-1,0,1,1,-1,-1,1,-1,-1,1,-1},
	{144},
	{1,0,1,-1,-1,0,0,1,0,1,1,-1,1,-1,1,1,0,0,-1,1,1,1,-1,0,-1,0,0,0,0,1,1,1,0,-1,1,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,-1,-1,1,-1,1,-1,1,0,-1,-1,0,1,-1,1,1,-1,1,1,0,0,-1,0,-1,1,-1,-1,1,0,1,-1,0,1,0,-1,-1,1,0,1,-1,0,-1,1,0,0,1,0,1,0,-1,0,-1,0,1,0,0,-1,1,-1,1,0,0,0,-1,-1,0,0,1,-1,0,-1,1,1,-1,0,-1,1,-1,1,0,0,1,0,1,0,0,0,1,-1,1,1,0,0,-1,1,1,1},
	{145},
	{1,1,-1,0,-1,1,1,-1,1,1,1,-1,1,1,1,0,1,-1,-1,-1,1,0,0,0,1,1,-1,1,-1,0,1,1,0,1,0,1,-1,-1,1,-1,-1,1,0,-1,0,0,1,1,0,1,-1,-1,1,1,1,1,-1,-1,1,-1,1,0,-1,0,1,0,0,1,1,-1,-1,-1,-1,1,0,-1,0,-1,-1,-1,-1,0,1,1,1,0,1,1,1,1,-1,1,0,1,-1,-1,-1,1,-1,0,-1,0,0,0,0,-1,0,-1,0,1,-1,0,0,1,0,-1,0,0,-1,0,-1,-1,0,1,1,0,-1,0,1,0,-1,1,-1,1,0,1,1,0,1,-1,-1,-1,1,0,-1,-1,1},
	{146},
	{1,1,0,1,-1,-1,1,1,-1,1,1,-1,0,-1,0,-1,1,0,0,0,-1,0,1,1,1,1,-1,1,0,0,1,0,1,-1,0,-1,0,-1,1,-1,1,1,-1,-1,-1,0,0,1,-1,-1,-1,0,0,-1,0,0,1,1,-1,0,0,1,-1,0,0,0,0,-1,1,0,-1,1,-1,0,-1,-1,0,1,1,0,1,-1,-1,0,1,1,-1,0,1,-1,0,0,0,1,1,-1,-1,0,-1,-1,1,1,-1,-1,0,0,0,1,0,0,0,0,1,0,-1,0,0,-1,0,0,1,1,1,0,0,-1,0,1,0,1,1,0,1,-1,0,0,1,-1,-1,-1,0,1,1,-1,1,-1,1,0},
	{147},
	{1,-1,0,1,-1,0,-1,-1,0,1,1,-1,1,0,0,1,1,1,0,1,-1,1,-1,1,1,-1,-1,1,0,-1,0,-1,-1,-1,-1,0,0,0,1,-1,0,1,0,0,0,1,0,0,1,1,-1,-1,0,0,-1,-1,-1,-1,0,1,-1,-1,-1,0,-1,0,0,1,1,0,-1,0,0,0,1,1,1,0,0,1,-1,1,-1,-1,1,-1,0,1,-1,-1,1,1,0,1,0,1,0,-1,1,0,0,-1,-1,1,1,0,-1,0,1,0,0,0,0,0,1,-1,0,0,-1,-1,1,-1,-1,0,-1,0,-1,1,1,-1,0,-1,0,0,0,0,-1,0,-1,-1,-1,1,1,0,0,0,1,0,1},
	{148},
	{1,1,0,-1,-1,1,-1,1,-1,0,1,-1,-1,-1,-1,0,1,-1,0,-1,0,0,1,-1,-1,1,-1,1,0,-1,0,1,1,1,-1,-1,0,0,-1,1,0,-1,-1,0,1,0,-1,0,1,1,1,-1,-1,1,-1,0,1,0,0,0,1,-1,0,-1,-1,0,-1,1,-1,1,1,0,1,-1,-1,1,0,-1,0,-1,-1,0,0,0,-1,1,1,-1,0,0,1,-1,1,0,0,1,-1,1,1,-1,1,1,1,1,1,1,1,-1,0,0,0,1,1,-1,-1,0,-1,-1,1,1,1,1,-1,0,-1,1,0,-1,1,0,0,0,-1,0,0,-1,-1,-1,0,1,1,0,0,-1,0,1,1,0,-1,0},
	{149},
	{1,-1,1,-1,0,1,-1,0,-1,1,-1,-1,0,0,0,1,1,0,-1,0,1,-1,1,1,-1,0,-1,1,1,0,-1,0,0,-1,1,0,1,0,-1,0,0,0,1,-1,-1,0,1,-1,-1,1,0,1,-1,0,1,-1,1,1,0,1,0,1,0,-1,1,0,1,1,-1,1,-1,0,-1,-1,0,-1,1,0,0,1,-1,1,1,1,-1,0,-1,-1,0,0,-1,1,-1,1,-1,-1,0,1,-1,0,0,0,1,-1,1,1,0,1,-1,-1,0,1,-1,0,0,0,-1,0,1,0,0,-1,0,1,-1,-1,-1,0,1,0,1,1,-1,1,1,-1,0,-1,1,1,0,-1,0,1,1,1,0,1,0,-1,0},
	{150}};

void printa(int i) {
	cout << ans[i].size()-1 << endl;
	reverse(ans[i].begin(), ans[i].end());
	for (int j : ans[i]) cout << j << " ";
	cout << endl;
}

int main() { _
	int n; cin >> n;
	n--;
	printa(2*n);
	cout << ans[2*n+1][0]-1 << endl;
	for (int i = 0; i < ans[2*n+1][0]; i++) cout << 1 << " ";
	cout << endl;
	exit(0);
}