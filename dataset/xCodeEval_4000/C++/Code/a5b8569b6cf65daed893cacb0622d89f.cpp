











#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(),x.end()
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define _upgrade ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define erase_duplicates(x) sort(all(x)); (x).resize(distance((x).begin(), unique(all(x))));


using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<
T,
null_type,
less<T>,
rb_tree_tag,
tree_order_statistics_node_update>;






typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<LL> VLL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<char> VC;
typedef long double LD;
typedef pair<LD,LD> PLD;
typedef vector<LD> VLD;
typedef vector<PLD> VPLD;

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<" = "<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<" = "<<h<<", "; _dbg(sdbg+1, a...);
}

string odp[100000];

int main()
{
odp[0] = "!x&x";
odp[1] = "!(x|y|z)";
odp[2] = "!x&!y&z";
odp[3] = "!x&!y";
odp[4] = "!x&!z&y";
odp[5] = "!x&!z";
odp[6] = "!(!y&!z|x|y&z)";
odp[7] = "!(x|y&z)";
odp[8] = "!x&y&z";
odp[9] = "!(!y&z|!z&y|x)";
odp[10] = "!x&z";
odp[11] = "!(!z&y|x)";
odp[12] = "!x&y";
odp[13] = "!(!y&z|x)";
odp[14] = "!x&(y|z)";
odp[15] = "!x";
odp[16] = "!y&!z&x";
odp[17] = "!y&!z";
odp[18] = "!(!x&!z|x&z|y)";
odp[19] = "!(x&z|y)";
odp[20] = "!(!x&!y|x&y|z)";
odp[21] = "!(x&y|z)";
odp[22] = "!(!x&!y|x&y|z)|!x&!y&z";
odp[23] = "!((x|y)&z|x&y)";
odp[24] = "!x&y&z|!y&!z&x";
odp[25] = "!x&y&z|!y&!z";
odp[26] = "!x&z|!y&!z&x";
odp[27] = "!x&z|!y&!z";
odp[28] = "!x&y|!y&!z&x";
odp[29] = "!x&y|!y&!z";
odp[30] = "!x&(y|z)|!y&!z&x";
odp[31] = "!x|!y&!z";
odp[32] = "!y&x&z";
odp[33] = "!(!x&z|!z&x|y)";
odp[34] = "!y&z";
odp[35] = "!(!z&x|y)";
odp[36] = "!x&!z&y|!y&x&z";
odp[37] = "!x&!z|!y&x&z";
odp[38] = "!x&!z&y|!y&z";
odp[39] = "!x&!z|!y&z";
odp[40] = "!x&y&z|!y&x&z";
odp[41] = "!(!x&z|!z&x|y)|!x&y&z";
odp[42] = "!(x&y)&z";
odp[43] = "!(!z&x|y)|!x&z";
odp[44] = "!x&y|!y&x&z";
odp[45] = "!(!y&z|x)|!y&x&z";
odp[46] = "!x&y|!y&z";
odp[47] = "!x|!y&z";
odp[48] = "!y&x";
odp[49] = "!(!x&z|y)";
odp[50] = "!y&(x|z)";
odp[51] = "!y";
odp[52] = "!x&!z&y|!y&x";
odp[53] = "!x&!z|!y&x";
odp[54] = "!x&!z&y|!y&(x|z)";
odp[55] = "!x&!z|!y";
odp[56] = "!x&y&z|!y&x";
odp[57] = "!(!x&z|y)|!x&y&z";
odp[58] = "!x&z|!y&x";
odp[59] = "!x&z|!y";
odp[60] = "!x&y|!y&x";
odp[61] = "!(!x&!y&z|x&y)";
odp[62] = "!x&(y|z)|!y&x";
odp[63] = "!x|!y";
odp[64] = "!z&x&y";
odp[65] = "!(!x&y|!y&x|z)";
odp[66] = "!x&!y&z|!z&x&y";
odp[67] = "!x&!y|!z&x&y";
odp[68] = "!z&y";
odp[69] = "!(!y&x|z)";
odp[70] = "!x&!y&z|!z&y";
odp[71] = "!x&!y|!z&y";
odp[72] = "!x&y&z|!z&x&y";
odp[73] = "!(!x&y|!y&x|z)|!x&y&z";
odp[74] = "!x&z|!z&x&y";
odp[75] = "!(!z&y|x)|!z&x&y";
odp[76] = "!(x&z)&y";
odp[77] = "!(!y&x|z)|!x&y";
odp[78] = "!x&z|!z&y";
odp[79] = "!x|!z&y";
odp[80] = "!z&x";
odp[81] = "!(!x&y|z)";
odp[82] = "!x&!y&z|!z&x";
odp[83] = "!x&!y|!z&x";
odp[84] = "!z&(x|y)";
odp[85] = "!z";
odp[86] = "!x&!y&z|!z&(x|y)";
odp[87] = "!x&!y|!z";
odp[88] = "!x&y&z|!z&x";
odp[89] = "!(!x&y|z)|!x&y&z";
odp[90] = "!x&z|!z&x";
odp[91] = "!(!x&!z&y|x&z)";
odp[92] = "!x&y|!z&x";
odp[93] = "!x&y|!z";
odp[94] = "!x&(y|z)|!z&x";
odp[95] = "!x|!z";
odp[96] = "!y&x&z|!z&x&y";
odp[97] = "!(!x&y|!y&x|z)|!y&x&z";
odp[98] = "!y&z|!z&x&y";
odp[99] = "!(!z&x|y)|!z&x&y";
odp[100] = "!y&x&z|!z&y";
odp[101] = "!(!y&x|z)|!y&x&z";
odp[102] = "!y&z|!z&y";
odp[103] = "!(!y&!z&x|y&z)";
odp[104] = "!x&y&z|!y&x&z|!z&x&y";
odp[105] = "!(!x&y|!y&x|z)|!x&y&z|!y&x&z";
odp[106] = "!(x&y)&z|!z&x&y";
odp[107] = "!(!z&x|y)|!x&z|!z&x&y";
odp[108] = "!(x&z)&y|!y&x&z";
odp[109] = "!(!y&x|z)|!x&y|!y&x&z";
odp[110] = "!(x&y)&z|!z&y";
odp[111] = "!x|!y&z|!z&y";
odp[112] = "!(y&z)&x";
odp[113] = "!(!x&y|z)|!y&x";
odp[114] = "!y&z|!z&x";
odp[115] = "!y|!z&x";
odp[116] = "!y&x|!z&y";
odp[117] = "!y&x|!z";
odp[118] = "!y&(x|z)|!z&y";
odp[119] = "!y|!z";
odp[120] = "!(y&z)&x|!x&y&z";
odp[121] = "!(!x&y|z)|!x&y&z|!y&x";
odp[122] = "!(x&y)&z|!z&x";
odp[123] = "!x&z|!y|!z&x";
odp[124] = "!(x&z)&y|!y&x";
odp[125] = "!x&y|!y&x|!z";
odp[126] = "!x&y|!y&z|!z&x";
odp[127] = "!(x&y&z)";
odp[128] = "x&y&z";
odp[129] = "!(x|y|z)|x&y&z";
odp[130] = "!x&!y&z|x&y&z";
odp[131] = "!x&!y|x&y&z";
odp[132] = "!x&!z&y|x&y&z";
odp[133] = "!x&!z|x&y&z";
odp[134] = "!(!y&!z|x|y&z)|x&y&z";
odp[135] = "!(x|y&z)|x&y&z";
odp[136] = "y&z";
odp[137] = "!(x|y|z)|y&z";
odp[138] = "!x&z|y&z";
odp[139] = "!x&!y|y&z";
odp[140] = "!x&y|y&z";
odp[141] = "!x&!z|y&z";
odp[142] = "!x&(y|z)|y&z";
odp[143] = "!x|y&z";
odp[144] = "!y&!z&x|x&y&z";
odp[145] = "!y&!z|x&y&z";
odp[146] = "!(!x&!z|x&z|y)|x&y&z";
odp[147] = "!(x&z|y)|x&y&z";
odp[148] = "!(!x&!y|x&y|z)|x&y&z";
odp[149] = "!(x&y|z)|x&y&z";
odp[150] = "!(!x&!y|x&y|z)|!x&!y&z|x&y&z";
odp[151] = "!((x|y)&z|x&y)|x&y&z";
odp[152] = "!y&!z&x|y&z";
odp[153] = "!y&!z|y&z";
odp[154] = "!x&z|!y&!z&x|y&z";
odp[155] = "!(x&z|y)|y&z";
odp[156] = "!x&y|!y&!z&x|y&z";
odp[157] = "!(x&y|z)|y&z";
odp[158] = "!x&(y|z)|!y&!z&x|y&z";
odp[159] = "!x|!y&!z|y&z";
odp[160] = "x&z";
odp[161] = "!(x|y|z)|x&z";
odp[162] = "!y&z|x&z";
odp[163] = "!x&!y|x&z";
odp[164] = "!x&!z&y|x&z";
odp[165] = "!x&!z|x&z";
odp[166] = "!x&!z&y|!y&z|x&z";
odp[167] = "!(x|y&z)|x&z";
odp[168] = "(x|y)&z";
odp[169] = "!(x|y|z)|(x|y)&z";
odp[170] = "z";
odp[171] = "!x&!y|z";
odp[172] = "!x&y|x&z";
odp[173] = "!(!y&z|x)|x&z";
odp[174] = "!x&y|z";
odp[175] = "!x|z";
odp[176] = "!y&x|x&z";
odp[177] = "!y&!z|x&z";
odp[178] = "!y&(x|z)|x&z";
odp[179] = "!y|x&z";
odp[180] = "!x&!z&y|!y&x|x&z";
odp[181] = "!(x&y|z)|x&z";
odp[182] = "!x&!z&y|!y&(x|z)|x&z";
odp[183] = "!x&!z|!y|x&z";
odp[184] = "!y&x|y&z";
odp[185] = "!(!x&z|y)|y&z";
odp[186] = "!y&x|z";
odp[187] = "!y|z";
odp[188] = "!x&y|!y&x|x&z";
odp[189] = "!x&!z|!y&x|y&z";
odp[190] = "!x&y|!y&x|z";
odp[191] = "!x|!y|z";
odp[192] = "x&y";
odp[193] = "!(x|y|z)|x&y";
odp[194] = "!x&!y&z|x&y";
odp[195] = "!x&!y|x&y";
odp[196] = "!z&y|x&y";
odp[197] = "!x&!z|x&y";
odp[198] = "!x&!y&z|!z&y|x&y";
odp[199] = "!(x|y&z)|x&y";
odp[200] = "(x|z)&y";
odp[201] = "!(x|y|z)|(x|z)&y";
odp[202] = "!x&z|x&y";
odp[203] = "!(!z&y|x)|x&y";
odp[204] = "y";
odp[205] = "!x&!z|y";
odp[206] = "!x&z|y";
odp[207] = "!x|y";
odp[208] = "!z&x|x&y";
odp[209] = "!y&!z|x&y";
odp[210] = "!x&!y&z|!z&x|x&y";
odp[211] = "!(x&z|y)|x&y";
odp[212] = "!z&(x|y)|x&y";
odp[213] = "!z|x&y";
odp[214] = "!x&!y&z|!z&(x|y)|x&y";
odp[215] = "!x&!y|!z|x&y";
odp[216] = "!z&x|y&z";
odp[217] = "!(!x&y|z)|y&z";
odp[218] = "!x&z|!z&x|x&y";
odp[219] = "!x&!y|!z&x|y&z";
odp[220] = "!z&x|y";
odp[221] = "!z|y";
odp[222] = "!x&z|!z&x|y";
odp[223] = "!x|!z|y";
odp[224] = "(y|z)&x";
odp[225] = "!(x|y|z)|(y|z)&x";
odp[226] = "!y&z|x&y";
odp[227] = "!(!z&x|y)|x&y";
odp[228] = "!z&y|x&z";
odp[229] = "!(!y&x|z)|x&z";
odp[230] = "!y&z|!z&y|x&y";
odp[231] = "!x&!y|!z&y|x&z";
odp[232] = "(x|y)&z|x&y";
odp[233] = "!(x|y|z)|(x|y)&z|x&y";
odp[234] = "x&y|z";
odp[235] = "!x&!y|x&y|z";
odp[236] = "x&z|y";
odp[237] = "!x&!z|x&z|y";
odp[238] = "y|z";
odp[239] = "!x|y|z";
odp[240] = "x";
odp[241] = "!y&!z|x";
odp[242] = "!y&z|x";
odp[243] = "!y|x";
odp[244] = "!z&y|x";
odp[245] = "!z|x";
odp[246] = "!y&z|!z&y|x";
odp[247] = "!y|!z|x";
odp[248] = "x|y&z";
odp[249] = "!y&!z|x|y&z";
odp[250] = "x|z";
odp[251] = "!y|x|z";
odp[252] = "x|y";
odp[253] = "!z|x|y";
odp[254] = "x|y|z";
odp[255] = "!x|x";

ios_base::sync_with_stdio(0);
int n;
cin>>n;
while(n--)
{
  string s;
  cin>>s;
  int val = 0;
  while(SZ(s))
  {
    val *= 2;
    val += s.back() - '0';
    s.pop_back();
  }
  cout<<odp[val]<<"\n";
}
}
