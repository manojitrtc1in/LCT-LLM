#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int read(){
	register int c=getchar();
	int x=0;
	for(;c<48||c>57;c=getchar());
	for(;c>47&&c<58;c=getchar())
		x=(x<<1)+(x<<3)+c-48;
	return x;
}
int main()
{
  int boys[105], girls[105];
  memset(boys,0,sizeof(boys));
  memset(girls,0,sizeof(girls));
  int n, m, cnt = 0, x, i = 0, j = 0;
  n=read();
  for (int i = 1; i <= n; ++i) {
    boys[read()]++;
  }
  m=read();
  for (int i = 1; i <= m; ++i) {
    girls[read()]++;
  }
if(girls[1]) for(int j = -1;j<=1;++j) for(;boys[1+j]&&girls[1];)--girls[1],--boys[1+j],++cnt;
if(girls[2]) for(int j = -1;j<=1;++j) for(;boys[2+j]&&girls[2];)--girls[2],--boys[2+j],++cnt;
if(girls[3]) for(int j = -1;j<=1;++j) for(;boys[3+j]&&girls[3];)--girls[3],--boys[3+j],++cnt;
if(girls[4]) for(int j = -1;j<=1;++j) for(;boys[4+j]&&girls[4];)--girls[4],--boys[4+j],++cnt;
if(girls[5]) for(int j = -1;j<=1;++j) for(;boys[5+j]&&girls[5];)--girls[5],--boys[5+j],++cnt;
if(girls[6]) for(int j = -1;j<=1;++j) for(;boys[6+j]&&girls[6];)--girls[6],--boys[6+j],++cnt;
if(girls[7]) for(int j = -1;j<=1;++j) for(;boys[7+j]&&girls[7];)--girls[7],--boys[7+j],++cnt;
if(girls[8]) for(int j = -1;j<=1;++j) for(;boys[8+j]&&girls[8];)--girls[8],--boys[8+j],++cnt;
if(girls[9]) for(int j = -1;j<=1;++j) for(;boys[9+j]&&girls[9];)--girls[9],--boys[9+j],++cnt;
if(girls[10]) for(int j = -1;j<=1;++j) for(;boys[10+j]&&girls[10];)--girls[10],--boys[10+j],++cnt;
if(girls[11]) for(int j = -1;j<=1;++j) for(;boys[11+j]&&girls[11];)--girls[11],--boys[11+j],++cnt;
if(girls[12]) for(int j = -1;j<=1;++j) for(;boys[12+j]&&girls[12];)--girls[12],--boys[12+j],++cnt;
if(girls[13]) for(int j = -1;j<=1;++j) for(;boys[13+j]&&girls[13];)--girls[13],--boys[13+j],++cnt;
if(girls[14]) for(int j = -1;j<=1;++j) for(;boys[14+j]&&girls[14];)--girls[14],--boys[14+j],++cnt;
if(girls[15]) for(int j = -1;j<=1;++j) for(;boys[15+j]&&girls[15];)--girls[15],--boys[15+j],++cnt;
if(girls[16]) for(int j = -1;j<=1;++j) for(;boys[16+j]&&girls[16];)--girls[16],--boys[16+j],++cnt;
if(girls[17]) for(int j = -1;j<=1;++j) for(;boys[17+j]&&girls[17];)--girls[17],--boys[17+j],++cnt;
if(girls[18]) for(int j = -1;j<=1;++j) for(;boys[18+j]&&girls[18];)--girls[18],--boys[18+j],++cnt;
if(girls[19]) for(int j = -1;j<=1;++j) for(;boys[19+j]&&girls[19];)--girls[19],--boys[19+j],++cnt;
if(girls[20]) for(int j = -1;j<=1;++j) for(;boys[20+j]&&girls[20];)--girls[20],--boys[20+j],++cnt;
if(girls[21]) for(int j = -1;j<=1;++j) for(;boys[21+j]&&girls[21];)--girls[21],--boys[21+j],++cnt;
if(girls[22]) for(int j = -1;j<=1;++j) for(;boys[22+j]&&girls[22];)--girls[22],--boys[22+j],++cnt;
if(girls[23]) for(int j = -1;j<=1;++j) for(;boys[23+j]&&girls[23];)--girls[23],--boys[23+j],++cnt;
if(girls[24]) for(int j = -1;j<=1;++j) for(;boys[24+j]&&girls[24];)--girls[24],--boys[24+j],++cnt;
if(girls[25]) for(int j = -1;j<=1;++j) for(;boys[25+j]&&girls[25];)--girls[25],--boys[25+j],++cnt;
if(girls[26]) for(int j = -1;j<=1;++j) for(;boys[26+j]&&girls[26];)--girls[26],--boys[26+j],++cnt;
if(girls[27]) for(int j = -1;j<=1;++j) for(;boys[27+j]&&girls[27];)--girls[27],--boys[27+j],++cnt;
if(girls[28]) for(int j = -1;j<=1;++j) for(;boys[28+j]&&girls[28];)--girls[28],--boys[28+j],++cnt;
if(girls[29]) for(int j = -1;j<=1;++j) for(;boys[29+j]&&girls[29];)--girls[29],--boys[29+j],++cnt;
if(girls[30]) for(int j = -1;j<=1;++j) for(;boys[30+j]&&girls[30];)--girls[30],--boys[30+j],++cnt;
if(girls[31]) for(int j = -1;j<=1;++j) for(;boys[31+j]&&girls[31];)--girls[31],--boys[31+j],++cnt;
if(girls[32]) for(int j = -1;j<=1;++j) for(;boys[32+j]&&girls[32];)--girls[32],--boys[32+j],++cnt;
if(girls[33]) for(int j = -1;j<=1;++j) for(;boys[33+j]&&girls[33];)--girls[33],--boys[33+j],++cnt;
if(girls[34]) for(int j = -1;j<=1;++j) for(;boys[34+j]&&girls[34];)--girls[34],--boys[34+j],++cnt;
if(girls[35]) for(int j = -1;j<=1;++j) for(;boys[35+j]&&girls[35];)--girls[35],--boys[35+j],++cnt;
if(girls[36]) for(int j = -1;j<=1;++j) for(;boys[36+j]&&girls[36];)--girls[36],--boys[36+j],++cnt;
if(girls[37]) for(int j = -1;j<=1;++j) for(;boys[37+j]&&girls[37];)--girls[37],--boys[37+j],++cnt;
if(girls[38]) for(int j = -1;j<=1;++j) for(;boys[38+j]&&girls[38];)--girls[38],--boys[38+j],++cnt;
if(girls[39]) for(int j = -1;j<=1;++j) for(;boys[39+j]&&girls[39];)--girls[39],--boys[39+j],++cnt;
if(girls[40]) for(int j = -1;j<=1;++j) for(;boys[40+j]&&girls[40];)--girls[40],--boys[40+j],++cnt;
if(girls[41]) for(int j = -1;j<=1;++j) for(;boys[41+j]&&girls[41];)--girls[41],--boys[41+j],++cnt;
if(girls[42]) for(int j = -1;j<=1;++j) for(;boys[42+j]&&girls[42];)--girls[42],--boys[42+j],++cnt;
if(girls[43]) for(int j = -1;j<=1;++j) for(;boys[43+j]&&girls[43];)--girls[43],--boys[43+j],++cnt;
if(girls[44]) for(int j = -1;j<=1;++j) for(;boys[44+j]&&girls[44];)--girls[44],--boys[44+j],++cnt;
if(girls[45]) for(int j = -1;j<=1;++j) for(;boys[45+j]&&girls[45];)--girls[45],--boys[45+j],++cnt;
if(girls[46]) for(int j = -1;j<=1;++j) for(;boys[46+j]&&girls[46];)--girls[46],--boys[46+j],++cnt;
if(girls[47]) for(int j = -1;j<=1;++j) for(;boys[47+j]&&girls[47];)--girls[47],--boys[47+j],++cnt;
if(girls[48]) for(int j = -1;j<=1;++j) for(;boys[48+j]&&girls[48];)--girls[48],--boys[48+j],++cnt;
if(girls[49]) for(int j = -1;j<=1;++j) for(;boys[49+j]&&girls[49];)--girls[49],--boys[49+j],++cnt;
if(girls[50]) for(int j = -1;j<=1;++j) for(;boys[50+j]&&girls[50];)--girls[50],--boys[50+j],++cnt;
if(girls[51]) for(int j = -1;j<=1;++j) for(;boys[51+j]&&girls[51];)--girls[51],--boys[51+j],++cnt;
if(girls[52]) for(int j = -1;j<=1;++j) for(;boys[52+j]&&girls[52];)--girls[52],--boys[52+j],++cnt;
if(girls[53]) for(int j = -1;j<=1;++j) for(;boys[53+j]&&girls[53];)--girls[53],--boys[53+j],++cnt;
if(girls[54]) for(int j = -1;j<=1;++j) for(;boys[54+j]&&girls[54];)--girls[54],--boys[54+j],++cnt;
if(girls[55]) for(int j = -1;j<=1;++j) for(;boys[55+j]&&girls[55];)--girls[55],--boys[55+j],++cnt;
if(girls[56]) for(int j = -1;j<=1;++j) for(;boys[56+j]&&girls[56];)--girls[56],--boys[56+j],++cnt;
if(girls[57]) for(int j = -1;j<=1;++j) for(;boys[57+j]&&girls[57];)--girls[57],--boys[57+j],++cnt;
if(girls[58]) for(int j = -1;j<=1;++j) for(;boys[58+j]&&girls[58];)--girls[58],--boys[58+j],++cnt;
if(girls[59]) for(int j = -1;j<=1;++j) for(;boys[59+j]&&girls[59];)--girls[59],--boys[59+j],++cnt;
if(girls[60]) for(int j = -1;j<=1;++j) for(;boys[60+j]&&girls[60];)--girls[60],--boys[60+j],++cnt;
if(girls[61]) for(int j = -1;j<=1;++j) for(;boys[61+j]&&girls[61];)--girls[61],--boys[61+j],++cnt;
if(girls[62]) for(int j = -1;j<=1;++j) for(;boys[62+j]&&girls[62];)--girls[62],--boys[62+j],++cnt;
if(girls[63]) for(int j = -1;j<=1;++j) for(;boys[63+j]&&girls[63];)--girls[63],--boys[63+j],++cnt;
if(girls[64]) for(int j = -1;j<=1;++j) for(;boys[64+j]&&girls[64];)--girls[64],--boys[64+j],++cnt;
if(girls[65]) for(int j = -1;j<=1;++j) for(;boys[65+j]&&girls[65];)--girls[65],--boys[65+j],++cnt;
if(girls[66]) for(int j = -1;j<=1;++j) for(;boys[66+j]&&girls[66];)--girls[66],--boys[66+j],++cnt;
if(girls[67]) for(int j = -1;j<=1;++j) for(;boys[67+j]&&girls[67];)--girls[67],--boys[67+j],++cnt;
if(girls[68]) for(int j = -1;j<=1;++j) for(;boys[68+j]&&girls[68];)--girls[68],--boys[68+j],++cnt;
if(girls[69]) for(int j = -1;j<=1;++j) for(;boys[69+j]&&girls[69];)--girls[69],--boys[69+j],++cnt;
if(girls[70]) for(int j = -1;j<=1;++j) for(;boys[70+j]&&girls[70];)--girls[70],--boys[70+j],++cnt;
if(girls[71]) for(int j = -1;j<=1;++j) for(;boys[71+j]&&girls[71];)--girls[71],--boys[71+j],++cnt;
if(girls[72]) for(int j = -1;j<=1;++j) for(;boys[72+j]&&girls[72];)--girls[72],--boys[72+j],++cnt;
if(girls[73]) for(int j = -1;j<=1;++j) for(;boys[73+j]&&girls[73];)--girls[73],--boys[73+j],++cnt;
if(girls[74]) for(int j = -1;j<=1;++j) for(;boys[74+j]&&girls[74];)--girls[74],--boys[74+j],++cnt;
if(girls[75]) for(int j = -1;j<=1;++j) for(;boys[75+j]&&girls[75];)--girls[75],--boys[75+j],++cnt;
if(girls[76]) for(int j = -1;j<=1;++j) for(;boys[76+j]&&girls[76];)--girls[76],--boys[76+j],++cnt;
if(girls[77]) for(int j = -1;j<=1;++j) for(;boys[77+j]&&girls[77];)--girls[77],--boys[77+j],++cnt;
if(girls[78]) for(int j = -1;j<=1;++j) for(;boys[78+j]&&girls[78];)--girls[78],--boys[78+j],++cnt;
if(girls[79]) for(int j = -1;j<=1;++j) for(;boys[79+j]&&girls[79];)--girls[79],--boys[79+j],++cnt;
if(girls[80]) for(int j = -1;j<=1;++j) for(;boys[80+j]&&girls[80];)--girls[80],--boys[80+j],++cnt;
if(girls[81]) for(int j = -1;j<=1;++j) for(;boys[81+j]&&girls[81];)--girls[81],--boys[81+j],++cnt;
if(girls[82]) for(int j = -1;j<=1;++j) for(;boys[82+j]&&girls[82];)--girls[82],--boys[82+j],++cnt;
if(girls[83]) for(int j = -1;j<=1;++j) for(;boys[83+j]&&girls[83];)--girls[83],--boys[83+j],++cnt;
if(girls[84]) for(int j = -1;j<=1;++j) for(;boys[84+j]&&girls[84];)--girls[84],--boys[84+j],++cnt;
if(girls[85]) for(int j = -1;j<=1;++j) for(;boys[85+j]&&girls[85];)--girls[85],--boys[85+j],++cnt;
if(girls[86]) for(int j = -1;j<=1;++j) for(;boys[86+j]&&girls[86];)--girls[86],--boys[86+j],++cnt;
if(girls[87]) for(int j = -1;j<=1;++j) for(;boys[87+j]&&girls[87];)--girls[87],--boys[87+j],++cnt;
if(girls[88]) for(int j = -1;j<=1;++j) for(;boys[88+j]&&girls[88];)--girls[88],--boys[88+j],++cnt;
if(girls[89]) for(int j = -1;j<=1;++j) for(;boys[89+j]&&girls[89];)--girls[89],--boys[89+j],++cnt;
if(girls[90]) for(int j = -1;j<=1;++j) for(;boys[90+j]&&girls[90];)--girls[90],--boys[90+j],++cnt;
if(girls[91]) for(int j = -1;j<=1;++j) for(;boys[91+j]&&girls[91];)--girls[91],--boys[91+j],++cnt;
if(girls[92]) for(int j = -1;j<=1;++j) for(;boys[92+j]&&girls[92];)--girls[92],--boys[92+j],++cnt;
if(girls[93]) for(int j = -1;j<=1;++j) for(;boys[93+j]&&girls[93];)--girls[93],--boys[93+j],++cnt;
if(girls[94]) for(int j = -1;j<=1;++j) for(;boys[94+j]&&girls[94];)--girls[94],--boys[94+j],++cnt;
if(girls[95]) for(int j = -1;j<=1;++j) for(;boys[95+j]&&girls[95];)--girls[95],--boys[95+j],++cnt;
if(girls[96]) for(int j = -1;j<=1;++j) for(;boys[96+j]&&girls[96];)--girls[96],--boys[96+j],++cnt;
if(girls[97]) for(int j = -1;j<=1;++j) for(;boys[97+j]&&girls[97];)--girls[97],--boys[97+j],++cnt;
if(girls[98]) for(int j = -1;j<=1;++j) for(;boys[98+j]&&girls[98];)--girls[98],--boys[98+j],++cnt;
if(girls[99]) for(int j = -1;j<=1;++j) for(;boys[99+j]&&girls[99];)--girls[99],--boys[99+j],++cnt;
if(girls[100]) for(int j = -1;j<=1;++j) for(;boys[100+j]&&girls[100];)--girls[100],--boys[100+j],++cnt;
  printf("%d\n", cnt);
  return 0;
}
