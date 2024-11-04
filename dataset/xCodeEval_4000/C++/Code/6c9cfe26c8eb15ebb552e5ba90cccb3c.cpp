#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); i--)
#define ITER(it, a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a, value) memset(a, value, sizeof(a))

#define SZ(a) (int) a.size()
#define ALL(a) a.begin(),a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const LL INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

string A = "01<>|&xyz!";

void print(string a)
{
	FOR (i, 0, SZ(a))
	{
		cout<<A[a[i]];
	}
	cout<<endl;
}

int solve(string a)
{
	while(SZ(a) > 1)
	{
	

	

	

	

	

		FOR (i, 0, SZ(a) - 1)
		{
			if (a[i] == 0 && a[i+1] == 0) throw -1;
			if (a[i] == '!' && a[i+1] <= 1)
			{
				int x = a[i+1];
		

				a.erase(a.begin() + i);
		

				a[i] = x ^ 1;
				break;
			}

			if (i > 0 && a[i-1] == '(' && a[i+1] == ')')
			{
				int x = a[i];
				a.erase(a.begin() + i - 1);
				a.erase(a.begin() + i - 1);
				a[i-1] = x;
				break;
			}

			if (i > 0 && a[i] == '&' && a[i-1] <= 1 && a[i+1] <= 1)
			{
				int x = a[i-1] & a[i+1];
				a.erase(a.begin() + i - 1);
				a.erase(a.begin() + i - 1);
				a[i-1] = x;
				break;
			}

			if (i > 0 && a[i] == '|' && a[i-1] <= 1 && a[i+1] <= 1)
			{
				if (i + 2 < SZ(a) && a[i+2] == '&') continue;

				int x = a[i-1] | a[i+1];
				a.erase(a.begin() + i - 1);
				a.erase(a.begin() + i - 1);
				a[i-1] = x;
				break;
			}
		}
	}

	return a[0];
}

int getMask(string a)
{
	int res = 0;
	string b = a;
	FOR (i, 0, 2)
	{
		FOR (j, 0, 2)
		{
			FOR (k, 0, 2)
			{
				a = b;
				FOR (s, 0, SZ(a))
				{
					if (a[s] == 'x') a[s] = i;
					if (a[s] == 'y') a[s] = j;
					if (a[s] == 'z') a[s] = k;
				}

				int cur = solve(a);
				

				if (cur) res += (1<<(i * 4 + j * 2 + k));
			}
		}
	}
	


	return res;
}

const int MAX = 256;

string res[MAX];

bool Less(string& a, string& b)
{
	if (b.empty()) return true;
	if (SZ(a) < SZ(b)) return true;
	if (SZ(a) > SZ(b)) return false;
	if (a < b) return true;
	return false;
}

bool add(string a)
{
	


	if (SZ(a) > 28) return false;

	

	int mask = getMask(a);
	

	

	if (Less(a, res[mask]))
	{
	

		res[mask] = a;
		return true;
	}
	return false;
}

string RES[MAX];
char buf[MAX];

string V[MAX];

int main()
{
	

	


	

	

	RES[0] = "!x&x";
RES[1] = "!(x|y|z)";
RES[2] = "!x&!y&z";
RES[3] = "!x&!y";
RES[4] = "!x&!z&y";
RES[5] = "!x&!z";
RES[6] = "!(!y&!z|x|y&z)";
RES[7] = "!(x|y&z)";
RES[8] = "!x&y&z";
RES[9] = "!(!y&z|!z&y|x)";
RES[10] = "!x&z";
RES[11] = "!(!z&y|x)";
RES[12] = "!x&y";
RES[13] = "!(!y&z|x)";
RES[14] = "!x&(y|z)";
RES[15] = "!x";
RES[16] = "!y&!z&x";
RES[17] = "!y&!z";
RES[18] = "!(!x&!z|x&z|y)";
RES[19] = "!(x&z|y)";
RES[20] = "!(!x&!y|x&y|z)";
RES[21] = "!(x&y|z)";
RES[22] = "!(!x&!y|x&y|z)|!x&!y&z";
RES[23] = "!((x|y)&z|x&y)";
RES[24] = "!x&y&z|!y&!z&x";
RES[25] = "!x&y&z|!y&!z";
RES[26] = "!x&z|!y&!z&x";
RES[27] = "!x&z|!y&!z";
RES[28] = "!x&y|!y&!z&x";
RES[29] = "!x&y|!y&!z";
RES[30] = "!x&(y|z)|!y&!z&x";
RES[31] = "!x|!y&!z";
RES[32] = "!y&x&z";
RES[33] = "!(!x&z|!z&x|y)";
RES[34] = "!y&z";
RES[35] = "!(!z&x|y)";
RES[36] = "!x&!z&y|!y&x&z";
RES[37] = "!x&!z|!y&x&z";
RES[38] = "!x&!z&y|!y&z";
RES[39] = "!x&!z|!y&z";
RES[40] = "!x&y&z|!y&x&z";
RES[41] = "!(!x&z|!z&x|y)|!x&y&z";
RES[42] = "!(x&y)&z";
RES[43] = "!(!z&x|y)|!x&z";
RES[44] = "!x&y|!y&x&z";
RES[45] = "!(!y&z|x)|!y&x&z";
RES[46] = "!x&y|!y&z";
RES[47] = "!x|!y&z";
RES[48] = "!y&x";
RES[49] = "!(!x&z|y)";
RES[50] = "!y&(x|z)";
RES[51] = "!y";
RES[52] = "!x&!z&y|!y&x";
RES[53] = "!x&!z|!y&x";
RES[54] = "!x&!z&y|!y&(x|z)";
RES[55] = "!x&!z|!y";
RES[56] = "!x&y&z|!y&x";
RES[57] = "!(!x&z|y)|!x&y&z";
RES[58] = "!x&z|!y&x";
RES[59] = "!x&z|!y";
RES[60] = "!x&y|!y&x";
RES[61] = "!(!x&!y&z|x&y)";
RES[62] = "!x&(y|z)|!y&x";
RES[63] = "!x|!y";
RES[64] = "!z&x&y";
RES[65] = "!(!x&y|!y&x|z)";
RES[66] = "!x&!y&z|!z&x&y";
RES[67] = "!x&!y|!z&x&y";
RES[68] = "!z&y";
RES[69] = "!(!y&x|z)";
RES[70] = "!x&!y&z|!z&y";
RES[71] = "!x&!y|!z&y";
RES[72] = "!x&y&z|!z&x&y";
RES[73] = "!(!x&y|!y&x|z)|!x&y&z";
RES[74] = "!x&z|!z&x&y";
RES[75] = "!(!z&y|x)|!z&x&y";
RES[76] = "!(x&z)&y";
RES[77] = "!(!y&x|z)|!x&y";
RES[78] = "!x&z|!z&y";
RES[79] = "!x|!z&y";
RES[80] = "!z&x";
RES[81] = "!(!x&y|z)";
RES[82] = "!x&!y&z|!z&x";
RES[83] = "!x&!y|!z&x";
RES[84] = "!z&(x|y)";
RES[85] = "!z";
RES[86] = "!x&!y&z|!z&(x|y)";
RES[87] = "!x&!y|!z";
RES[88] = "!x&y&z|!z&x";
RES[89] = "!(!x&y|z)|!x&y&z";
RES[90] = "!x&z|!z&x";
RES[91] = "!(!x&!z&y|x&z)";
RES[92] = "!x&y|!z&x";
RES[93] = "!x&y|!z";
RES[94] = "!x&(y|z)|!z&x";
RES[95] = "!x|!z";
RES[96] = "!y&x&z|!z&x&y";
RES[97] = "!(!x&y|!y&x|z)|!y&x&z";
RES[98] = "!y&z|!z&x&y";
RES[99] = "!(!z&x|y)|!z&x&y";
RES[100] = "!y&x&z|!z&y";
RES[101] = "!(!y&x|z)|!y&x&z";
RES[102] = "!y&z|!z&y";
RES[103] = "!(!y&!z&x|y&z)";
RES[104] = "!x&y&z|!y&x&z|!z&x&y";
RES[105] = "!(!x&y|!y&x|z)|!x&y&z|!y&x&z";
RES[106] = "!(x&y)&z|!z&x&y";
RES[107] = "!(!z&x|y)|!x&z|!z&x&y";
RES[108] = "!(x&z)&y|!y&x&z";
RES[109] = "!(!y&x|z)|!x&y|!y&x&z";
RES[110] = "!(x&y)&z|!z&y";
RES[111] = "!x|!y&z|!z&y";
RES[112] = "!(y&z)&x";
RES[113] = "!(!x&y|z)|!y&x";
RES[114] = "!y&z|!z&x";
RES[115] = "!y|!z&x";
RES[116] = "!y&x|!z&y";
RES[117] = "!y&x|!z";
RES[118] = "!y&(x|z)|!z&y";
RES[119] = "!y|!z";
RES[120] = "!(y&z)&x|!x&y&z";
RES[121] = "!(!x&y|z)|!x&y&z|!y&x";
RES[122] = "!(x&y)&z|!z&x";
RES[123] = "!x&z|!y|!z&x";
RES[124] = "!(x&z)&y|!y&x";
RES[125] = "!x&y|!y&x|!z";
RES[126] = "!x&y|!y&z|!z&x";
RES[127] = "!(x&y&z)";
RES[128] = "x&y&z";
RES[129] = "!(x|y|z)|x&y&z";
RES[130] = "!x&!y&z|x&y&z";
RES[131] = "!x&!y|x&y&z";
RES[132] = "!x&!z&y|x&y&z";
RES[133] = "!x&!z|x&y&z";
RES[134] = "!(!y&!z|x|y&z)|x&y&z";
RES[135] = "!(x|y&z)|x&y&z";
RES[136] = "y&z";
RES[137] = "!(x|y|z)|y&z";
RES[138] = "!x&z|y&z";
RES[139] = "!x&!y|y&z";
RES[140] = "!x&y|y&z";
RES[141] = "!x&!z|y&z";
RES[142] = "!x&(y|z)|y&z";
RES[143] = "!x|y&z";
RES[144] = "!y&!z&x|x&y&z";
RES[145] = "!y&!z|x&y&z";
RES[146] = "!(!x&!z|x&z|y)|x&y&z";
RES[147] = "!(x&z|y)|x&y&z";
RES[148] = "!(!x&!y|x&y|z)|x&y&z";
RES[149] = "!(x&y|z)|x&y&z";
RES[150] = "!(!x&!y|x&y|z)|!x&!y&z|x&y&z";
RES[151] = "!((x|y)&z|x&y)|x&y&z";
RES[152] = "!y&!z&x|y&z";
RES[153] = "!y&!z|y&z";
RES[154] = "!x&z|!y&!z&x|y&z";
RES[155] = "!(x&z|y)|y&z";
RES[156] = "!x&y|!y&!z&x|y&z";
RES[157] = "!(x&y|z)|y&z";
RES[158] = "!x&(y|z)|!y&!z&x|y&z";
RES[159] = "!x|!y&!z|y&z";
RES[160] = "x&z";
RES[161] = "!(x|y|z)|x&z";
RES[162] = "!y&z|x&z";
RES[163] = "!x&!y|x&z";
RES[164] = "!x&!z&y|x&z";
RES[165] = "!x&!z|x&z";
RES[166] = "!x&!z&y|!y&z|x&z";
RES[167] = "!(x|y&z)|x&z";
RES[168] = "(x|y)&z";
RES[169] = "!(x|y|z)|(x|y)&z";
RES[170] = "z";
RES[171] = "!x&!y|z";
RES[172] = "!x&y|x&z";
RES[173] = "!(!y&z|x)|x&z";
RES[174] = "!x&y|z";
RES[175] = "!x|z";
RES[176] = "!y&x|x&z";
RES[177] = "!y&!z|x&z";
RES[178] = "!y&(x|z)|x&z";
RES[179] = "!y|x&z";
RES[180] = "!x&!z&y|!y&x|x&z";
RES[181] = "!(x&y|z)|x&z";
RES[182] = "!x&!z&y|!y&(x|z)|x&z";
RES[183] = "!x&!z|!y|x&z";
RES[184] = "!y&x|y&z";
RES[185] = "!(!x&z|y)|y&z";
RES[186] = "!y&x|z";
RES[187] = "!y|z";
RES[188] = "!x&y|!y&x|x&z";
RES[189] = "!x&!z|!y&x|y&z";
RES[190] = "!x&y|!y&x|z";
RES[191] = "!x|!y|z";
RES[192] = "x&y";
RES[193] = "!(x|y|z)|x&y";
RES[194] = "!x&!y&z|x&y";
RES[195] = "!x&!y|x&y";
RES[196] = "!z&y|x&y";
RES[197] = "!x&!z|x&y";
RES[198] = "!x&!y&z|!z&y|x&y";
RES[199] = "!(x|y&z)|x&y";
RES[200] = "(x|z)&y";
RES[201] = "!(x|y|z)|(x|z)&y";
RES[202] = "!x&z|x&y";
RES[203] = "!(!z&y|x)|x&y";
RES[204] = "y";
RES[205] = "!x&!z|y";
RES[206] = "!x&z|y";
RES[207] = "!x|y";
RES[208] = "!z&x|x&y";
RES[209] = "!y&!z|x&y";
RES[210] = "!x&!y&z|!z&x|x&y";
RES[211] = "!(x&z|y)|x&y";
RES[212] = "!z&(x|y)|x&y";
RES[213] = "!z|x&y";
RES[214] = "!x&!y&z|!z&(x|y)|x&y";
RES[215] = "!x&!y|!z|x&y";
RES[216] = "!z&x|y&z";
RES[217] = "!(!x&y|z)|y&z";
RES[218] = "!x&z|!z&x|x&y";
RES[219] = "!x&!y|!z&x|y&z";
RES[220] = "!z&x|y";
RES[221] = "!z|y";
RES[222] = "!x&z|!z&x|y";
RES[223] = "!x|!z|y";
RES[224] = "(y|z)&x";
RES[225] = "!(x|y|z)|(y|z)&x";
RES[226] = "!y&z|x&y";
RES[227] = "!(!z&x|y)|x&y";
RES[228] = "!z&y|x&z";
RES[229] = "!(!y&x|z)|x&z";
RES[230] = "!y&z|!z&y|x&y";
RES[231] = "!x&!y|!z&y|x&z";
RES[232] = "(x|y)&z|x&y";
RES[233] = "!(x|y|z)|(x|y)&z|x&y";
RES[234] = "x&y|z";
RES[235] = "!x&!y|x&y|z";
RES[236] = "x&z|y";
RES[237] = "!x&!z|x&z|y";
RES[238] = "y|z";
RES[239] = "!x|y|z";
RES[240] = "x";
RES[241] = "!y&!z|x";
RES[242] = "!y&z|x";
RES[243] = "!y|x";
RES[244] = "!z&y|x";
RES[245] = "!z|x";
RES[246] = "!y&z|!z&y|x";
RES[247] = "!y|!z|x";
RES[248] = "x|y&z";
RES[249] = "!y&!z|x|y&z";
RES[250] = "x|z";
RES[251] = "!y|x|z";
RES[252] = "x|y";
RES[253] = "!z|x|y";
RES[254] = "x|y|z";
RES[255] = "!x|x";


	int n;
	scanf("%d", &n);
	FOR (i, 0, n)
	{
		scanf("%s", buf);
		int mask = 0;
		FOR (i, 0, 8)
		{
			if (buf[i] == '1') mask |= (1<<i);
		}

		printf("%s\n", RES[mask].c_str());
	}

	return 0;


}
