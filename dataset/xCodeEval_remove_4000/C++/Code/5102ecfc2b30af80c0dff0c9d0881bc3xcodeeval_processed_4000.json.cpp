



















typedef long long ll;
typedef long double ld;
using namespace std;
typedef pair<int,int> pii;
const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;

const int maxn = 15;

char tarr[3][20] = {"111001010100",
				    "010111010111",
				    "010001111100"};

int used[maxn][maxn];
int ans[maxn][maxn] = {};
int bestans = 0;
int n, m;
void rec(int x, int y, int num, int fr) {
	if (x == n) {
		if (num > bestans) {
			memcpy(ans,used,sizeof(ans));
			bestans = num;
		}
		return;
	}
	int nx = x;
	int ny = y+1;
	if (ny == m) {
		nx++;
		ny = 0;
	}
	if (fr/4+num<=bestans) return;
	if (x+3<=n && y+3<=m) {
		for (int st = 0; st < 12; st+=3) {
			bool ok = true;
			for (int i = 0; i < 3; ++i) {
				if (!ok) break;
				for (int j = 0; j < 3; ++j) {
					if (used[x+i][y+j] && tarr[i][st+j]=='1') {
						ok = false;
						break;
					}
				}
			}
			if (ok) {
				for (int i = 0; i < 3; ++i) {
					for (int j = 0; j < 3; ++j) {
						if (tarr[i][st+j]=='1') {
							used[x+i][y+j] = num+1;
						}
					}
				}
				int nfr = fr-4;
				if (!used[x][y]) nfr--;
				rec(nx,ny,num+1,nfr);
				for (int i = 0; i < 3; ++i) {
					for (int j = 0; j < 3; ++j) {
						if (tarr[i][st+j]=='1') {
							used[x+i][y+j] = 0;
						}
					}
				}
			}
		}
	}
	int nfr = fr;
	if (!used[x][y]) nfr--;
	rec(nx,ny,num,nfr);
}
void solve(int n, int m) {
	::n = n;
	::m = m;
	bestans = 0;
	memset(used,0,sizeof(used));
	memset(ans,0,sizeof(ans));
	rec(0,0,0,n*m);
}

int main()
{

	

	


	int n, m; scanf("%d%d", &n, &m);
	if (n==1&&m==1) {
printf("0\n");
printf(".\n");
}
if (n==1&&m==2) {
printf("0\n");
printf("..\n");
}
if (n==1&&m==3) {
printf("0\n");
printf("...\n");
}
if (n==1&&m==4) {
printf("0\n");
printf("....\n");
}
if (n==1&&m==5) {
printf("0\n");
printf(".....\n");
}
if (n==1&&m==6) {
printf("0\n");
printf("......\n");
}
if (n==1&&m==7) {
printf("0\n");
printf(".......\n");
}
if (n==1&&m==8) {
printf("0\n");
printf("........\n");
}
if (n==1&&m==9) {
printf("0\n");
printf(".........\n");
}
if (n==2&&m==1) {
printf("0\n");
printf(".\n");
printf(".\n");
}
if (n==2&&m==2) {
printf("0\n");
printf("..\n");
printf("..\n");
}
if (n==2&&m==3) {
printf("0\n");
printf("...\n");
printf("...\n");
}
if (n==2&&m==4) {
printf("0\n");
printf("....\n");
printf("....\n");
}
if (n==2&&m==5) {
printf("0\n");
printf(".....\n");
printf(".....\n");
}
if (n==2&&m==6) {
printf("0\n");
printf("......\n");
printf("......\n");
}
if (n==2&&m==7) {
printf("0\n");
printf(".......\n");
printf(".......\n");
}
if (n==2&&m==8) {
printf("0\n");
printf("........\n");
printf("........\n");
}
if (n==2&&m==9) {
printf("0\n");
printf(".........\n");
printf(".........\n");
}
if (n==3&&m==1) {
printf("0\n");
printf(".\n");
printf(".\n");
printf(".\n");
}
if (n==3&&m==2) {
printf("0\n");
printf("..\n");
printf("..\n");
printf("..\n");
}
if (n==3&&m==3) {
printf("1\n");
printf("AAA\n");
printf(".A.\n");
printf(".A.\n");
}
if (n==3&&m==4) {
printf("1\n");
printf("AAA.\n");
printf(".A..\n");
printf(".A..\n");
}
if (n==3&&m==5) {
printf("2\n");
printf("AAA.B\n");
printf(".ABBB\n");
printf(".A..B\n");
}
if (n==3&&m==6) {
printf("2\n");
printf("AAA.B.\n");
printf(".ABBB.\n");
printf(".A..B.\n");
}
if (n==3&&m==7) {
printf("3\n");
printf("AAABCCC\n");
printf(".A.B.C.\n");
printf(".ABBBC.\n");
}
if (n==3&&m==8) {
printf("3\n");
printf("AAA.BCCC\n");
printf(".ABBB.C.\n");
printf(".A..B.C.\n");
}
if (n==3&&m==9) {
printf("4\n");
printf("AAABCCC.D\n");
printf(".A.B.CDDD\n");
printf(".ABBBC..D\n");
}
if (n==4&&m==1) {
printf("0\n");
printf(".\n");
printf(".\n");
printf(".\n");
printf(".\n");
}
if (n==4&&m==2) {
printf("0\n");
printf("..\n");
printf("..\n");
printf("..\n");
printf("..\n");
}
if (n==4&&m==3) {
printf("1\n");
printf("AAA\n");
printf(".A.\n");
printf(".A.\n");
printf("...\n");
}
if (n==4&&m==4) {
printf("2\n");
printf("AAA.\n");
printf(".AB.\n");
printf(".AB.\n");
printf(".BBB\n");
}
if (n==4&&m==5) {
printf("2\n");
printf("AAA.B\n");
printf(".ABBB\n");
printf(".A..B\n");
printf(".....\n");
}
if (n==4&&m==6) {
printf("3\n");
printf("AAABBB\n");
printf(".AC.B.\n");
printf(".AC.B.\n");
printf(".CCC..\n");
}
if (n==4&&m==7) {
printf("4\n");
printf("AAABBB.\n");
printf(".AC.BD.\n");
printf(".AC.BD.\n");
printf(".CCCDDD\n");
}
if (n==4&&m==8) {
printf("4\n");
printf("AAA.BCCC\n");
printf(".ABBBDC.\n");
printf(".A..BDC.\n");
printf("....DDD.\n");
}
if (n==4&&m==9) {
printf("5\n");
printf("AAABBBCCC\n");
printf(".AD.BE.C.\n");
printf(".AD.BE.C.\n");
printf(".DDDEEE..\n");
}
if (n==5&&m==1) {
printf("0\n");
printf(".\n");
printf(".\n");
printf(".\n");
printf(".\n");
printf(".\n");
}
if (n==5&&m==2) {
printf("0\n");
printf("..\n");
printf("..\n");
printf("..\n");
printf("..\n");
printf("..\n");
}
if (n==5&&m==3) {
printf("2\n");
printf("AAA\n");
printf(".A.\n");
printf(".AB\n");
printf("BBB\n");
printf("..B\n");
}
if (n==5&&m==4) {
printf("2\n");
printf("AAA.\n");
printf(".AB.\n");
printf(".AB.\n");
printf(".BBB\n");
printf("....\n");
}
if (n==5&&m==5) {
printf("4\n");
printf("AAA.B\n");
printf(".ABBB\n");
printf("CA.DB\n");
printf("CCCD.\n");
printf("C.DDD\n");
}
if (n==5&&m==6) {
printf("4\n");
printf("AAA.B.\n");
printf(".ABBB.\n");
printf(".AC.BD\n");
printf("CCCDDD\n");
printf("..C..D\n");
}
if (n==5&&m==7) {
printf("5\n");
printf("AAA.B..\n");
printf(".ABBBC.\n");
printf("DA.EBC.\n");
printf("DDDECCC\n");
printf("D.EEE..\n");
}
if (n==5&&m==8) {
printf("6\n");
printf("AAA.BCCC\n");
printf(".ABBBDC.\n");
printf("EA.FBDC.\n");
printf("EEEFDDD.\n");
printf("E.FFF...\n");
}
if (n==5&&m==9) {
printf("7\n");
printf("AAA.BCCC.\n");
printf(".ABBBDC..\n");
printf("EA.FBDCG.\n");
printf("EEEFDDDG.\n");
printf("E.FFF.GGG\n");
}
if (n==6&&m==1) {
printf("0\n");
printf(".\n");
printf(".\n");
printf(".\n");
printf(".\n");
printf(".\n");
printf(".\n");
}
if (n==6&&m==2) {
printf("0\n");
printf("..\n");
printf("..\n");
printf("..\n");
printf("..\n");
printf("..\n");
printf("..\n");
}
if (n==6&&m==3) {
printf("2\n");
printf("AAA\n");
printf(".A.\n");
printf(".AB\n");
printf("BBB\n");
printf("..B\n");
printf("...\n");
}
if (n==6&&m==4) {
printf("3\n");
printf("AAA.\n");
printf(".AB.\n");
printf(".AB.\n");
printf("CBBB\n");
printf("CCC.\n");
printf("C...\n");
}
if (n==6&&m==5) {
printf("4\n");
printf("AAA.B\n");
printf(".ABBB\n");
printf(".AC.B\n");
printf("CCCD.\n");
printf("..CD.\n");
printf("..DDD\n");
}
if (n==6&&m==6) {
printf("5\n");
printf("AAA.B.\n");
printf(".ABBB.\n");
printf(".A.CB.\n");
printf("DCCCE.\n");
printf("DDDCE.\n");
printf("D..EEE\n");
}
if (n==6&&m==7) {
printf("6\n");
printf("AAABCCC\n");
printf(".A.B.C.\n");
printf("DABBBCE\n");
printf("DDDFEEE\n");
printf("DFFF..E\n");
printf("...F...\n");
}
if (n==6&&m==8) {
printf("7\n");
printf("AAA.BCCC\n");
printf(".ABBBDC.\n");
printf(".AE.BDC.\n");
printf("EEEFDDDG\n");
printf("..EF.GGG\n");
printf("..FFF..G\n");
}
if (n==6&&m==9) {
printf("8\n");
printf("AAA.BCCC.\n");
printf(".ABBB.C..\n");
printf(".A.DBEC..\n");
printf("FDDDGEEEH\n");
printf("FFFDGEHHH\n");
printf("F..GGG..H\n");
}
if (n==7&&m==1) {
printf("0\n");
printf(".\n");
printf(".\n");
printf(".\n");
printf(".\n");
printf(".\n");
printf(".\n");
printf(".\n");
}
if (n==7&&m==2) {
printf("0\n");
printf("..\n");
printf("..\n");
printf("..\n");
printf("..\n");
printf("..\n");
printf("..\n");
printf("..\n");
}
if (n==7&&m==3) {
printf("3\n");
printf("AAA\n");
printf(".A.\n");
printf(".AB\n");
printf("BBB\n");
printf(".CB\n");
printf(".C.\n");
printf("CCC\n");
}
if (n==7&&m==4) {
printf("4\n");
printf("AAA.\n");
printf(".AB.\n");
printf(".AB.\n");
printf("CBBB\n");
printf("CCCD\n");
printf("CDDD\n");
printf("...D\n");
}
if (n==7&&m==5) {
printf("5\n");
printf("AAA.B\n");
printf(".ABBB\n");
printf(".AC.B\n");
printf("CCCD.\n");
printf(".ECD.\n");
printf(".EDDD\n");
printf("EEE..\n");
}
if (n==7&&m==6) {
printf("6\n");
printf("AAA.B.\n");
printf(".ABBB.\n");
printf(".AC.BD\n");
printf("CCCDDD\n");
printf(".EC.FD\n");
printf(".EFFF.\n");
printf("EEE.F.\n");
}
if (n==7&&m==7) {
printf("8\n");
printf("AAABCCC\n");
printf(".A.B.C.\n");
printf("DABBBCE\n");
printf("DDDFEEE\n");
printf("DG.F.HE\n");
printf(".GFFFH.\n");
printf("GGG.HHH\n");
}
if (n==7&&m==8) {
printf("9\n");
printf("AAA.BBB.\n");
printf(".ACCCBD.\n");
printf(".AEC.BD.\n");
printf("EEECFDDD\n");
printf("G.EHFFFI\n");
printf("GGGHFIII\n");
printf("G.HHH..I\n");
}
if (n==7&&m==9) {
printf("10\n");
printf("AAA.BC...\n");
printf(".ABBBCCCD\n");
printf("EA.FBCDDD\n");
printf("EEEF.GGGD\n");
printf("EHFFFIGJ.\n");
printf(".H.IIIGJ.\n");
printf("HHH..IJJJ\n");
}
if (n==8&&m==1) {
printf("0\n");
printf(".\n");
printf(".\n");
printf(".\n");
printf(".\n");
printf(".\n");
printf(".\n");
printf(".\n");
printf(".\n");
}
if (n==8&&m==2) {
printf("0\n");
printf("..\n");
printf("..\n");
printf("..\n");
printf("..\n");
printf("..\n");
printf("..\n");
printf("..\n");
printf("..\n");
}
if (n==8&&m==3) {
printf("3\n");
printf("AAA\n");
printf(".A.\n");
printf(".AB\n");
printf("BBB\n");
printf(".CB\n");
printf(".C.\n");
printf("CCC\n");
printf("...\n");
}
if (n==8&&m==4) {
printf("4\n");
printf("AAA.\n");
printf(".AB.\n");
printf(".AB.\n");
printf("CBBB\n");
printf("CCCD\n");
printf("CDDD\n");
printf("...D\n");
printf("....\n");
}
if (n==8&&m==5) {
printf("6\n");
printf("AAA.B\n");
printf(".ABBB\n");
printf("CA.DB\n");
printf("CCCD.\n");
printf("CEDDD\n");
printf(".EFFF\n");
printf("EEEF.\n");
printf("...F.\n");
}
if (n==8&&m==6) {
printf("7\n");
printf("AAA.B.\n");
printf(".ABBB.\n");
printf(".AC.BD\n");
printf("CCCDDD\n");
printf("..CE.D\n");
printf("FEEEG.\n");
printf("FFFEG.\n");
printf("F..GGG\n");
}
if (n==8&&m==7) {
printf("9\n");
printf("AAAB..C\n");
printf(".A.BCCC\n");
printf("DABBBEC\n");
printf("DDDEEE.\n");
printf("DFFF.EG\n");
printf(".HFIGGG\n");
printf(".HFIIIG\n");
printf("HHHI...\n");
}
if (n==8&&m==8) {
printf("10\n");
printf("AAA.BCCC\n");
printf(".ABBBDC.\n");
printf("EA.FBDC.\n");
printf("EEEFDDDG\n");
printf("EHFFFGGG\n");
printf(".HIII.JG\n");
printf("HHHIJJJ.\n");
printf("...I..J.\n");
}
if (n==8&&m==9) {
printf("12\n");
printf("AAABBB..C\n");
printf(".AD.BECCC\n");
printf(".AD.BEEEC\n");
printf("FDDDGEHHH\n");
printf("FFFIGGGH.\n");
printf("FJ.IGK.HL\n");
printf(".JIIIKLLL\n");
printf("JJJ.KKK.L\n");
}
if (n==9&&m==1) {
printf("0\n");
printf(".\n");
printf(".\n");
printf(".\n");
printf(".\n");
printf(".\n");
printf(".\n");
printf(".\n");
printf(".\n");
printf(".\n");
}
if (n==9&&m==2) {
printf("0\n");
printf("..\n");
printf("..\n");
printf("..\n");
printf("..\n");
printf("..\n");
printf("..\n");
printf("..\n");
printf("..\n");
printf("..\n");
}
if (n==9&&m==3) {
printf("4\n");
printf("AAA\n");
printf(".A.\n");
printf(".AB\n");
printf("BBB\n");
printf("C.B\n");
printf("CCC\n");
printf("C.D\n");
printf("DDD\n");
printf("..D\n");
}
if (n==9&&m==4) {
printf("5\n");
printf("AAA.\n");
printf(".AB.\n");
printf(".AB.\n");
printf("CBBB\n");
printf("CCCD\n");
printf("CDDD\n");
printf("EEED\n");
printf(".E..\n");
printf(".E..\n");
}
if (n==9&&m==5) {
printf("7\n");
printf("AAA.B\n");
printf(".ABBB\n");
printf("CA.DB\n");
printf("CCCD.\n");
printf("CEDDD\n");
printf(".EEEF\n");
printf("GEFFF\n");
printf("GGG.F\n");
printf("G....\n");
}
if (n==9&&m==6) {
printf("8\n");
printf("AAA.B.\n");
printf(".ABBB.\n");
printf(".AC.BD\n");
printf("CCCDDD\n");
printf("E.CF.D\n");
printf("EEEF..\n");
printf("EGFFFH\n");
printf(".G.HHH\n");
printf("GGG..H\n");
}
if (n==9&&m==7) {
printf("10\n");
printf("AAA.B..\n");
printf(".ABBBC.\n");
printf(".AD.BC.\n");
printf("DDDECCC\n");
printf("F.DEEEG\n");
printf("FFFEGGG\n");
printf("FHIIIJG\n");
printf(".H.I.J.\n");
printf("HHHIJJJ\n");
}
if (n==9&&m==8) {
printf("12\n");
printf("AAA.BCCC\n");
printf(".ABBBDC.\n");
printf("EA.FBDC.\n");
printf("EEEFDDDG\n");
printf("EHFFFGGG\n");
printf(".HHHIIIG\n");
printf("JHKKKIL.\n");
printf("JJJK.IL.\n");
printf("J..K.LLL\n");
}
if (n==9&&m==9) {
printf("13\n");
printf("AAA.BCCC.\n");
printf(".ABBB.CD.\n");
printf(".AE.BFCD.\n");
printf("EEEFFFDDD\n");
printf("G.E.HFIII\n");
printf("GGGJHHHI.\n");
printf("GK.JHL.IM\n");
printf(".KJJJLMMM\n");
printf("KKK.LLL.M\n");
}

	return 0;
	
	FILE *f = fopen("output.txt", "w");
	for (int i = 1; i <= 9; ++i)
		for (int j = 1; j <= 9; ++j) {
			printf("%d %d\n", i, j);
			solve(i,j);
			fprintf(f,"if (n==%d&&m==%d) {\n", i, j);
			fprintf(f,"printf(\"%d\");\n", bestans);
			for (int k = 0; k < i; ++k) {
				string tmp = "";
				for (int j = 0; j < m; ++j) {
					if (ans[k][j] == 0) tmp += '.';
					else tmp += char('A'-1+ans[k][j]);
				}
				fprintf(f,"printf(\"%s\");\n",tmp.c_str());
			}
			fprintf(f,"}\n\n");
		}
	return 0;
}