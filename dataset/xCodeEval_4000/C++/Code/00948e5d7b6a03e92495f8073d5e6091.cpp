#include <iostream>
#include <iomanip>
#include <climits>
#include <stack>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <cassert>

#define FOR(i,n) for(int i=0,_n=n;i<_n;i++)
#define FORR(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pli pair<ll,int>
#define vi vector<int>
#define fs first
#define sec second

#define maxn 1000000LL

using namespace std;
typedef long long ll;

const ll MOD = 1000000007LL;

string mem[300];

struct node{
    int type;

    int c1;
    int c2;
};

vector <node> tree;
int nocc[3];

void generate(int ind,int depth){
    node bv;
    if(depth>=7){bv.type=rand()%3;tree.pb(bv); return;}
    if(depth<3){
        memset(nocc,0,sizeof(nocc));
        if(rand()%100==0)bv.type = rand()%6;
        else bv.type=rand()%3+3;
    } else bv.type=rand()%6;
    while(bv.type<3 && nocc[bv.type]>3)bv.type++;
    

    tree.pb(bv);
    if(bv.type<=2)return;
    tree[ind].c1=tree.size();
    generate(tree[ind].c1,depth+1);
    if(bv.type==3)return;
    tree[ind].c2=tree.size();
    generate(tree[ind].c2,depth+1);
}

int evaluate(int ind, int x, int y, int z){
    if(tree[ind].type==0)return x;
    if(tree[ind].type==1)return y;
    if(tree[ind].type==2)return z;
    if(tree[ind].type==3)return 1-evaluate(tree[ind].c1,x,y,z);
    if(tree[ind].type==4)return (evaluate(tree[ind].c1,x,y,z))||(evaluate(tree[ind].c2,x,y,z));
    if(tree[ind].type==5)return (evaluate(tree[ind].c1,x,y,z))&&(evaluate(tree[ind].c2,x,y,z));
    return 0;
}

string gens(int ind){
    if(tree[ind].type==0)return "x";
    if(tree[ind].type==1)return "y";
    if(tree[ind].type==2)return "z";
    if(tree[ind].type==3){
        if(tree[tree[ind].c1].type<=3)return "!"+gens(tree[ind].c1);
        else return "!("+gens(tree[ind].c1)+")";
    }
    if(tree[ind].type==4){
        return gens(tree[ind].c1)+"|"+gens(tree[ind].c2);
    }
    if(tree[ind].type==5){
        string s1 = gens(tree[ind].c1);
        if(tree[tree[ind].c1].type==4)s1= "("+s1+")";
        string s2 = gens(tree[ind].c2);
        if(tree[tree[ind].c2].type==4)s2= "("+s2+")";
        if(s2<s1)swap(s1,s2);
        return s1+"&"+s2;
    }
    return "";
}

int main(){
    srand(1000);


	mem[0] = "!x&x";
	mem[1] = "x&y&z";
	mem[2] = "!z&x&y";
	mem[3] = "x&y";
	mem[4] = "!y&x&z";
	mem[5] = "x&z";
	mem[6] = "!y&x&z|!z&x&y";
	mem[7] = "(y|z)&x";
	mem[8] = "!y&!z&x";
	mem[9] = "!y&!z&x|x&y&z";
	mem[10] = "!z&x";
	mem[11] = "!z&x|x&y";
	mem[12] = "!y&x";
	mem[13] = "!y&x|x&z";
	mem[14] = "!(y&z)&x";
	mem[15] = "x";
	mem[16] = "!x&y&z";
	mem[17] = "y&z";
	mem[18] = "!x&y&z|!z&x&y";
	mem[19] = "(x|z)&y";
	mem[20] = "!x&y&z|!y&x&z";
	mem[21] = "(x|y)&z";
	mem[22] = "!x&y&z|!y&x&z|!z&x&y";
	mem[23] = "(x|y)&z|x&y";
	mem[24] = "!x&y&z|!y&!z&x";
	mem[25] = "!y&!z&x|y&z";
	mem[26] = "!x&y&z|!z&x";
	mem[27] = "!z&x|y&z";
	mem[28] = "!x&y&z|!y&x";
	mem[29] = "!y&x|y&z";
	mem[30] = "!(y&z)&x|!x&y&z";
	mem[31] = "x|y&z";
	mem[32] = "!x&!z&y";
	mem[33] = "!x&!z&y|x&y&z";
	mem[34] = "!z&y";
	mem[35] = "!z&y|x&y";
	mem[36] = "!x&!z&y|!y&x&z";
	mem[37] = "!x&!z&y|x&z";
	mem[38] = "!y&x&z|!z&y";
	mem[39] = "!z&y|x&z";
	mem[40] = "!(!x&!y|x&y|z)";
	mem[41] = "!(!x&!y|x&y|z)|x&y&z";
	mem[42] = "!z&(x|y)";
	mem[43] = "!z&(x|y)|x&y";
	mem[44] = "!x&!z&y|!y&x";
	mem[45] = "!x&!z&y|!y&x|x&z";
	mem[46] = "!y&x|!z&y";
	mem[47] = "!z&y|x";
	mem[48] = "!x&y";
	mem[49] = "!x&y|y&z";
	mem[50] = "!(x&z)&y";
	mem[51] = "y";
	mem[52] = "!x&y|!y&x&z";
	mem[53] = "!x&y|x&z";
	mem[54] = "!(x&z)&y|!y&x&z";
	mem[55] = "x&z|y";
	mem[56] = "!x&y|!y&!z&x";
	mem[57] = "!x&y|!y&!z&x|y&z";
	mem[58] = "!x&y|!z&x";
	mem[59] = "!z&x|y";
	mem[60] = "!x&y|!y&x";
	mem[61] = "!x&y|!y&x|x&z";
	mem[62] = "!(x&z)&y|!y&x";
	mem[63] = "x|y";
	mem[64] = "!x&!y&z";
	mem[65] = "!x&!y&z|x&y&z";
	mem[66] = "!x&!y&z|!z&x&y";
	mem[67] = "!x&!y&z|x&y";
	mem[68] = "!y&z";
	mem[69] = "!y&z|x&z";
	mem[70] = "!y&z|!z&x&y";
	mem[71] = "!y&z|x&y";
	mem[72] = "!(!x&!z|x&z|y)";
	mem[73] = "!(!x&!z|x&z|y)|x&y&z";
	mem[74] = "!x&!y&z|!z&x";
	mem[75] = "!x&!y&z|!z&x|x&y";
	mem[76] = "!y&(x|z)";
	mem[77] = "!y&(x|z)|x&z";
	mem[78] = "!y&z|!z&x";
	mem[79] = "!y&z|x";
	mem[80] = "!x&z";
	mem[81] = "!x&z|y&z";
	mem[82] = "!x&z|!z&x&y";
	mem[83] = "!x&z|x&y";
	mem[84] = "!(x&y)&z";
	mem[85] = "z";
	mem[86] = "!(x&y)&z|!z&x&y";
	mem[87] = "x&y|z";
	mem[88] = "!x&z|!y&!z&x";
	mem[89] = "!x&z|!y&!z&x|y&z";
	mem[90] = "!x&z|!z&x";
	mem[91] = "!x&z|!z&x|x&y";
	mem[92] = "!x&z|!y&x";
	mem[93] = "!y&x|z";
	mem[94] = "!(x&y)&z|!z&x";
	mem[95] = "x|z";
	mem[96] = "!(!y&!z|x|y&z)";
	mem[97] = "!(!y&!z|x|y&z)|x&y&z";
	mem[98] = "!x&!y&z|!z&y";
	mem[99] = "!x&!y&z|!z&y|x&y";
	mem[100] = "!x&!z&y|!y&z";
	mem[101] = "!x&!z&y|!y&z|x&z";
	mem[102] = "!y&z|!z&y";
	mem[103] = "!y&z|!z&y|x&y";
	mem[104] = "!(!x&!y|x&y|z)|!x&!y&z";
	mem[105] = "!(!x&!y|x&y|z)|!x&!y&z|x&y&z";
	mem[106] = "!x&!y&z|!z&(x|y)";
	mem[107] = "!x&!y&z|!z&(x|y)|x&y";
	mem[108] = "!x&!z&y|!y&(x|z)";
	mem[109] = "!x&!z&y|!y&(x|z)|x&z";
	mem[110] = "!y&(x|z)|!z&y";
	mem[111] = "!y&z|!z&y|x";
	mem[112] = "!x&(y|z)";
	mem[113] = "!x&(y|z)|y&z";
	mem[114] = "!x&z|!z&y";
	mem[115] = "!x&z|y";
	mem[116] = "!x&y|!y&z";
	mem[117] = "!x&y|z";
	mem[118] = "!(x&y)&z|!z&y";
	mem[119] = "y|z";
	mem[120] = "!x&(y|z)|!y&!z&x";
	mem[121] = "!x&(y|z)|!y&!z&x|y&z";
	mem[122] = "!x&(y|z)|!z&x";
	mem[123] = "!x&z|!z&x|y";
	mem[124] = "!x&(y|z)|!y&x";
	mem[125] = "!x&y|!y&x|z";
	mem[126] = "!x&y|!y&z|!z&x";
	mem[127] = "x|y|z";
	mem[128] = "!(x|y|z)";
	mem[129] = "!(x|y|z)|x&y&z";
	mem[130] = "!(!x&y|!y&x|z)";
	mem[131] = "!(x|y|z)|x&y";
	mem[132] = "!(!x&z|!z&x|y)";
	mem[133] = "!(x|y|z)|x&z";
	mem[134] = "!(!x&y|!y&x|z)|!y&x&z";
	mem[135] = "!(x|y|z)|(y|z)&x";
	mem[136] = "!y&!z";
	mem[137] = "!y&!z|x&y&z";
	mem[138] = "!(!x&y|z)";
	mem[139] = "!y&!z|x&y";
	mem[140] = "!(!x&z|y)";
	mem[141] = "!y&!z|x&z";
	mem[142] = "!(!x&y|z)|!y&x";
	mem[143] = "!y&!z|x";
	mem[144] = "!(!y&z|!z&y|x)";
	mem[145] = "!(x|y|z)|y&z";
	mem[146] = "!(!x&y|!y&x|z)|!x&y&z";
	mem[147] = "!(x|y|z)|(x|z)&y";
	mem[148] = "!(!x&z|!z&x|y)|!x&y&z";
	mem[149] = "!(x|y|z)|(x|y)&z";
	mem[150] = "!(!x&y|!y&x|z)|!x&y&z|!y&x&z";
	mem[151] = "!(x|y|z)|(x|y)&z|x&y";
	mem[152] = "!x&y&z|!y&!z";
	mem[153] = "!y&!z|y&z";
	mem[154] = "!(!x&y|z)|!x&y&z";
	mem[155] = "!(!x&y|z)|y&z";
	mem[156] = "!(!x&z|y)|!x&y&z";
	mem[157] = "!(!x&z|y)|y&z";
	mem[158] = "!(!x&y|z)|!x&y&z|!y&x";
	mem[159] = "!y&!z|x|y&z";
	mem[160] = "!x&!z";
	mem[161] = "!x&!z|x&y&z";
	mem[162] = "!(!y&x|z)";
	mem[163] = "!x&!z|x&y";
	mem[164] = "!x&!z|!y&x&z";
	mem[165] = "!x&!z|x&z";
	mem[166] = "!(!y&x|z)|!y&x&z";
	mem[167] = "!(!y&x|z)|x&z";
	mem[168] = "!(x&y|z)";
	mem[169] = "!(x&y|z)|x&y&z";
	mem[170] = "!z";
	mem[171] = "!z|x&y";
	mem[172] = "!x&!z|!y&x";
	mem[173] = "!(x&y|z)|x&z";
	mem[174] = "!y&x|!z";
	mem[175] = "!z|x";
	mem[176] = "!(!y&z|x)";
	mem[177] = "!x&!z|y&z";
	mem[178] = "!(!y&x|z)|!x&y";
	mem[179] = "!x&!z|y";
	mem[180] = "!(!y&z|x)|!y&x&z";
	mem[181] = "!(!y&z|x)|x&z";
	mem[182] = "!(!y&x|z)|!x&y|!y&x&z";
	mem[183] = "!x&!z|x&z|y";
	mem[184] = "!x&y|!y&!z";
	mem[185] = "!(x&y|z)|y&z";
	mem[186] = "!x&y|!z";
	mem[187] = "!z|y";
	mem[188] = "!(!x&!y&z|x&y)";
	mem[189] = "!x&!z|!y&x|y&z";
	mem[190] = "!x&y|!y&x|!z";
	mem[191] = "!z|x|y";
	mem[192] = "!x&!y";
	mem[193] = "!x&!y|x&y&z";
	mem[194] = "!x&!y|!z&x&y";
	mem[195] = "!x&!y|x&y";
	mem[196] = "!(!z&x|y)";
	mem[197] = "!x&!y|x&z";
	mem[198] = "!(!z&x|y)|!z&x&y";
	mem[199] = "!(!z&x|y)|x&y";
	mem[200] = "!(x&z|y)";
	mem[201] = "!(x&z|y)|x&y&z";
	mem[202] = "!x&!y|!z&x";
	mem[203] = "!(x&z|y)|x&y";
	mem[204] = "!y";
	mem[205] = "!y|x&z";
	mem[206] = "!y|!z&x";
	mem[207] = "!y|x";
	mem[208] = "!(!z&y|x)";
	mem[209] = "!x&!y|y&z";
	mem[210] = "!(!z&y|x)|!z&x&y";
	mem[211] = "!(!z&y|x)|x&y";
	mem[212] = "!(!z&x|y)|!x&z";
	mem[213] = "!x&!y|z";
	mem[214] = "!(!z&x|y)|!x&z|!z&x&y";
	mem[215] = "!x&!y|x&y|z";
	mem[216] = "!x&z|!y&!z";
	mem[217] = "!(x&z|y)|y&z";
	mem[218] = "!(!x&!z&y|x&z)";
	mem[219] = "!x&!y|!z&x|y&z";
	mem[220] = "!x&z|!y";
	mem[221] = "!y|z";
	mem[222] = "!x&z|!y|!z&x";
	mem[223] = "!y|x|z";
	mem[224] = "!(x|y&z)";
	mem[225] = "!(x|y&z)|x&y&z";
	mem[226] = "!x&!y|!z&y";
	mem[227] = "!(x|y&z)|x&y";
	mem[228] = "!x&!z|!y&z";
	mem[229] = "!(x|y&z)|x&z";
	mem[230] = "!(!y&!z&x|y&z)";
	mem[231] = "!x&!y|!z&y|x&z";
	mem[232] = "!((x|y)&z|x&y)";
	mem[233] = "!((x|y)&z|x&y)|x&y&z";
	mem[234] = "!x&!y|!z";
	mem[235] = "!x&!y|!z|x&y";
	mem[236] = "!x&!z|!y";
	mem[237] = "!x&!z|!y|x&z";
	mem[238] = "!y|!z";
	mem[239] = "!y|!z|x";
	mem[240] = "!x";
	mem[241] = "!x|y&z";
	mem[242] = "!x|!z&y";
	mem[243] = "!x|y";
	mem[244] = "!x|!y&z";
	mem[245] = "!x|z";
	mem[246] = "!x|!y&z|!z&y";
	mem[247] = "!x|y|z";
	mem[248] = "!x|!y&!z";
	mem[249] = "!x|!y&!z|y&z";
	mem[250] = "!x|!z";
	mem[251] = "!x|!z|y";
	mem[252] = "!x|!y";
	mem[253] = "!x|!y|z";
	mem[254] = "!(x&y&z)";
	mem[255] = "!x|x";
    ll cnt=0;
    
    int n;
    cin >> n;
    FOR(i,n){
        int mask=0;
        string inp;
        cin >> inp;
        FOR(i,8)mask=mask*2+inp[i]-'0';
        cout << mem[mask]<<"\n";
    }
	return 0;
}
