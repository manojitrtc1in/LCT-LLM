#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
typedef long long LL;




































LL ans[150+1][9+1];
LL f(LL n, int d) 

{
	LL a = d;
	n -= d;
	LL base = 10;

	while(n >= 9)
	{
		a += 9*base;
		base *= 10;
		n -= 9;
	}
	a += n*base;
	return a;
}
int main()
{
	memset(ans,-1,sizeof ans);
	if(true)
	{
		ans[3][2] = 0;
		ans[6][2] = 1;
		ans[9][2] = 2;
		ans[12][2] = 3;
		ans[15][2] = 4;
		ans[18][2] = 5;
		ans[21][2] = 6;
		ans[24][2] = 7;
		ans[27][2] = 17;
		ans[30][2] = 27;
		ans[33][2] = 37;
		ans[36][2] = 47;
		ans[39][2] = 57;
		ans[42][2] = 67;
		ans[45][2] = 77;
		ans[48][2] = 87;
		ans[51][2] = 97;
		ans[54][2] = 197;
		ans[57][2] = 297;
		ans[60][2] = 397;
		ans[63][2] = 497;
		ans[66][2] = 597;
		ans[69][2] = 697;
		ans[72][2] = 797;
		ans[75][2] = 897;
		ans[78][2] = 997;
		ans[81][2] = 1997;
		ans[84][2] = 2997;
		ans[87][2] = 3997;
		ans[90][2] = 4997;
		ans[93][2] = 5997;
		ans[96][2] = 6997;
		ans[99][2] = 7997;
		ans[102][2] = 8997;
		ans[105][2] = 9997;
		ans[108][2] = 19997;
		ans[111][2] = 29997;
		ans[114][2] = 39997;
		ans[117][2] = 49997;
		ans[120][2] = 59997;
		ans[123][2] = 69997;
		ans[126][2] = 79997;
		ans[129][2] = 89997;
		ans[132][2] = 99997;
		ans[135][2] = 199997;
		ans[138][2] = 299997;
		ans[141][2] = 399997;
		ans[144][2] = 499997;
		ans[147][2] = 599997;
		ans[150][2] = 699997;
		ans[6][3] = 0;
		ans[10][3] = 1;
		ans[14][3] = 2;
		ans[18][3] = 3;
		ans[22][3] = 4;
		ans[26][3] = 5;
		ans[30][3] = 6;
		ans[25][3] = 7;
		ans[20][3] = 8;
		ans[15][3] = 9;
		ans[34][3] = 16;
		ans[29][3] = 17;
		ans[24][3] = 18;
		ans[19][3] = 19;
		ans[38][3] = 26;
		ans[33][3] = 27;
		ans[28][3] = 28;
		ans[23][3] = 29;
		ans[42][3] = 36;
		ans[37][3] = 37;
		ans[32][3] = 38;
		ans[27][3] = 39;
		ans[46][3] = 46;
		ans[41][3] = 47;
		ans[36][3] = 48;
		ans[31][3] = 49;
		ans[50][3] = 56;
		ans[45][3] = 57;
		ans[40][3] = 58;
		ans[35][3] = 59;
		ans[54][3] = 66;
		ans[49][3] = 67;
		ans[44][3] = 68;
		ans[39][3] = 69;
		ans[58][3] = 76;
		ans[53][3] = 77;
		ans[48][3] = 78;
		ans[43][3] = 79;
		ans[62][3] = 86;
		ans[57][3] = 87;
		ans[52][3] = 88;
		ans[47][3] = 89;
		ans[66][3] = 96;
		ans[61][3] = 187;
		ans[56][3] = 188;
		ans[51][3] = 189;
		ans[70][3] = 196;
		ans[65][3] = 287;
		ans[60][3] = 288;
		ans[55][3] = 289;
		ans[74][3] = 296;
		ans[69][3] = 387;
		ans[64][3] = 388;
		ans[59][3] = 389;
		ans[78][3] = 396;
		ans[73][3] = 487;
		ans[68][3] = 488;
		ans[63][3] = 489;
		ans[82][3] = 496;
		ans[77][3] = 587;
		ans[72][3] = 588;
		ans[67][3] = 589;
		ans[86][3] = 596;
		ans[81][3] = 687;
		ans[76][3] = 688;
		ans[71][3] = 689;
		ans[90][3] = 696;
		ans[85][3] = 787;
		ans[80][3] = 788;
		ans[75][3] = 789;
		ans[94][3] = 796;
		ans[89][3] = 887;
		ans[84][3] = 888;
		ans[79][3] = 889;
		ans[98][3] = 896;
		ans[93][3] = 987;
		ans[88][3] = 988;
		ans[83][3] = 989;
		ans[102][3] = 996;
		ans[97][3] = 1987;
		ans[92][3] = 1988;
		ans[87][3] = 1989;
		ans[106][3] = 1996;
		ans[101][3] = 2987;
		ans[96][3] = 2988;
		ans[91][3] = 2989;
		ans[110][3] = 2996;
		ans[105][3] = 3987;
		ans[100][3] = 3988;
		ans[95][3] = 3989;
		ans[114][3] = 3996;
		ans[109][3] = 4987;
		ans[104][3] = 4988;
		ans[99][3] = 4989;
		ans[118][3] = 4996;
		ans[113][3] = 5987;
		ans[108][3] = 5988;
		ans[103][3] = 5989;
		ans[122][3] = 5996;
		ans[117][3] = 6987;
		ans[112][3] = 6988;
		ans[107][3] = 6989;
		ans[126][3] = 6996;
		ans[121][3] = 7987;
		ans[116][3] = 7988;
		ans[111][3] = 7989;
		ans[130][3] = 7996;
		ans[125][3] = 8987;
		ans[120][3] = 8988;
		ans[115][3] = 8989;
		ans[134][3] = 8996;
		ans[129][3] = 9987;
		ans[124][3] = 9988;
		ans[119][3] = 9989;
		ans[138][3] = 9996;
		ans[133][3] = 19987;
		ans[128][3] = 19988;
		ans[123][3] = 19989;
		ans[142][3] = 19996;
		ans[137][3] = 29987;
		ans[132][3] = 29988;
		ans[127][3] = 29989;
		ans[146][3] = 29996;
		ans[141][3] = 39987;
		ans[136][3] = 39988;
		ans[131][3] = 39989;
		ans[150][3] = 39996;
		ans[145][3] = 49987;
		ans[140][3] = 49988;
		ans[135][3] = 49989;
		ans[149][3] = 59987;
		ans[144][3] = 59988;
		ans[139][3] = 59989;
		ans[148][3] = 69988;
		ans[143][3] = 69989;
		ans[147][3] = 79989;
		ans[10][4] = 0;
		ans[15][4] = 1;
		ans[20][4] = 2;
		ans[25][4] = 3;
		ans[30][4] = 4;
		ans[35][4] = 5;
		ans[31][4] = 6;
		ans[27][4] = 7;
		ans[23][4] = 8;
		ans[19][4] = 9;
		ans[40][4] = 15;
		ans[36][4] = 16;
		ans[32][4] = 17;
		ans[28][4] = 18;
		ans[24][4] = 19;
		ans[45][4] = 25;
		ans[41][4] = 26;
		ans[37][4] = 27;
		ans[33][4] = 28;
		ans[29][4] = 29;
		ans[50][4] = 35;
		ans[46][4] = 36;
		ans[42][4] = 37;
		ans[38][4] = 38;
		ans[34][4] = 39;
		ans[55][4] = 45;
		ans[51][4] = 46;
		ans[47][4] = 47;
		ans[43][4] = 48;
		ans[39][4] = 49;
		ans[60][4] = 55;
		ans[56][4] = 56;
		ans[52][4] = 57;
		ans[48][4] = 58;
		ans[44][4] = 59;
		ans[65][4] = 65;
		ans[61][4] = 66;
		ans[57][4] = 67;
		ans[53][4] = 68;
		ans[49][4] = 69;
		ans[70][4] = 75;
		ans[66][4] = 76;
		ans[62][4] = 77;
		ans[58][4] = 78;
		ans[54][4] = 79;
		ans[75][4] = 85;
		ans[71][4] = 86;
		ans[67][4] = 87;
		ans[63][4] = 88;
		ans[59][4] = 89;
		ans[80][4] = 95;
		ans[76][4] = 186;
		ans[72][4] = 187;
		ans[68][4] = 188;
		ans[64][4] = 189;
		ans[85][4] = 195;
		ans[81][4] = 286;
		ans[77][4] = 287;
		ans[73][4] = 288;
		ans[69][4] = 289;
		ans[90][4] = 295;
		ans[86][4] = 386;
		ans[82][4] = 387;
		ans[78][4] = 388;
		ans[74][4] = 389;
		ans[95][4] = 395;
		ans[91][4] = 486;
		ans[87][4] = 487;
		ans[83][4] = 488;
		ans[79][4] = 489;
		ans[100][4] = 495;
		ans[96][4] = 586;
		ans[92][4] = 587;
		ans[88][4] = 588;
		ans[84][4] = 589;
		ans[105][4] = 595;
		ans[101][4] = 686;
		ans[97][4] = 687;
		ans[93][4] = 688;
		ans[89][4] = 689;
		ans[110][4] = 695;
		ans[106][4] = 786;
		ans[102][4] = 787;
		ans[98][4] = 788;
		ans[94][4] = 789;
		ans[115][4] = 795;
		ans[111][4] = 886;
		ans[107][4] = 887;
		ans[103][4] = 888;
		ans[99][4] = 889;
		ans[120][4] = 895;
		ans[116][4] = 986;
		ans[112][4] = 987;
		ans[108][4] = 988;
		ans[104][4] = 989;
		ans[125][4] = 995;
		ans[121][4] = 1986;
		ans[117][4] = 1987;
		ans[113][4] = 1988;
		ans[109][4] = 1989;
		ans[130][4] = 1995;
		ans[126][4] = 2986;
		ans[122][4] = 2987;
		ans[118][4] = 2988;
		ans[114][4] = 2989;
		ans[135][4] = 2995;
		ans[131][4] = 3986;
		ans[127][4] = 3987;
		ans[123][4] = 3988;
		ans[119][4] = 3989;
		ans[140][4] = 3995;
		ans[136][4] = 4986;
		ans[132][4] = 4987;
		ans[128][4] = 4988;
		ans[124][4] = 4989;
		ans[145][4] = 4995;
		ans[141][4] = 5986;
		ans[137][4] = 5987;
		ans[133][4] = 5988;
		ans[129][4] = 5989;
		ans[150][4] = 5995;
		ans[146][4] = 6986;
		ans[142][4] = 6987;
		ans[138][4] = 6988;
		ans[134][4] = 6989;
		ans[147][4] = 7987;
		ans[143][4] = 7988;
		ans[139][4] = 7989;
		ans[148][4] = 8988;
		ans[144][4] = 8989;
		ans[149][4] = 9989;
		ans[15][5] = 0;
		ans[21][5] = 1;
		ans[27][5] = 2;
		ans[33][5] = 3;
		ans[39][5] = 4;
		ans[36][5] = 5;
		ans[30][5] = 7;
		ans[24][5] = 9;
		ans[45][5] = 14;
		ans[42][5] = 15;
		ans[51][5] = 24;
		ans[48][5] = 25;
		ans[57][5] = 34;
		ans[54][5] = 35;
		ans[63][5] = 44;
		ans[60][5] = 45;
		ans[69][5] = 54;
		ans[66][5] = 55;
		ans[75][5] = 64;
		ans[72][5] = 65;
		ans[81][5] = 74;
		ans[78][5] = 75;
		ans[87][5] = 84;
		ans[84][5] = 85;
		ans[93][5] = 94;
		ans[90][5] = 185;
		ans[99][5] = 194;
		ans[96][5] = 285;
		ans[105][5] = 294;
		ans[102][5] = 385;
		ans[111][5] = 394;
		ans[108][5] = 485;
		ans[117][5] = 494;
		ans[114][5] = 585;
		ans[123][5] = 594;
		ans[120][5] = 685;
		ans[129][5] = 694;
		ans[126][5] = 785;
		ans[135][5] = 794;
		ans[132][5] = 885;
		ans[141][5] = 894;
		ans[138][5] = 985;
		ans[147][5] = 994;
		ans[144][5] = 1985;
		ans[150][5] = 2985;
		ans[21][6] = 0;
		ans[28][6] = 1;
		ans[35][6] = 2;
		ans[42][6] = 3;
		ans[40][6] = 4;
		ans[38][6] = 5;
		ans[36][6] = 6;
		ans[34][6] = 7;
		ans[32][6] = 8;
		ans[30][6] = 9;
		ans[49][6] = 13;
		ans[47][6] = 14;
		ans[45][6] = 15;
		ans[43][6] = 16;
		ans[41][6] = 17;
		ans[39][6] = 18;
		ans[37][6] = 19;
		ans[56][6] = 23;
		ans[54][6] = 24;
		ans[52][6] = 25;
		ans[50][6] = 26;
		ans[48][6] = 27;
		ans[46][6] = 28;
		ans[44][6] = 29;
		ans[63][6] = 33;
		ans[61][6] = 34;
		ans[59][6] = 35;
		ans[57][6] = 36;
		ans[55][6] = 37;
		ans[53][6] = 38;
		ans[51][6] = 39;
		ans[70][6] = 43;
		ans[68][6] = 44;
		ans[66][6] = 45;
		ans[64][6] = 46;
		ans[62][6] = 47;
		ans[60][6] = 48;
		ans[58][6] = 49;
		ans[77][6] = 53;
		ans[75][6] = 54;
		ans[73][6] = 55;
		ans[71][6] = 56;
		ans[69][6] = 57;
		ans[67][6] = 58;
		ans[65][6] = 59;
		ans[84][6] = 63;
		ans[82][6] = 64;
		ans[80][6] = 65;
		ans[78][6] = 66;
		ans[76][6] = 67;
		ans[74][6] = 68;
		ans[72][6] = 69;
		ans[91][6] = 73;
		ans[89][6] = 74;
		ans[87][6] = 75;
		ans[85][6] = 76;
		ans[83][6] = 77;
		ans[81][6] = 78;
		ans[79][6] = 79;
		ans[98][6] = 83;
		ans[96][6] = 84;
		ans[94][6] = 85;
		ans[92][6] = 86;
		ans[90][6] = 87;
		ans[88][6] = 88;
		ans[86][6] = 89;
		ans[105][6] = 93;
		ans[103][6] = 184;
		ans[101][6] = 185;
		ans[99][6] = 186;
		ans[97][6] = 187;
		ans[95][6] = 188;
		ans[93][6] = 189;
		ans[112][6] = 193;
		ans[110][6] = 284;
		ans[108][6] = 285;
		ans[106][6] = 286;
		ans[104][6] = 287;
		ans[102][6] = 288;
		ans[100][6] = 289;
		ans[119][6] = 293;
		ans[117][6] = 384;
		ans[115][6] = 385;
		ans[113][6] = 386;
		ans[111][6] = 387;
		ans[109][6] = 388;
		ans[107][6] = 389;
		ans[126][6] = 393;
		ans[124][6] = 484;
		ans[122][6] = 485;
		ans[120][6] = 486;
		ans[118][6] = 487;
		ans[116][6] = 488;
		ans[114][6] = 489;
		ans[133][6] = 493;
		ans[131][6] = 584;
		ans[129][6] = 585;
		ans[127][6] = 586;
		ans[125][6] = 587;
		ans[123][6] = 588;
		ans[121][6] = 589;
		ans[140][6] = 593;
		ans[138][6] = 684;
		ans[136][6] = 685;
		ans[134][6] = 686;
		ans[132][6] = 687;
		ans[130][6] = 688;
		ans[128][6] = 689;
		ans[147][6] = 693;
		ans[145][6] = 784;
		ans[143][6] = 785;
		ans[141][6] = 786;
		ans[139][6] = 787;
		ans[137][6] = 788;
		ans[135][6] = 789;
		ans[150][6] = 885;
		ans[148][6] = 886;
		ans[146][6] = 887;
		ans[144][6] = 888;
		ans[142][6] = 889;
		ans[149][6] = 989;
		ans[28][7] = 0;
		ans[36][7] = 1;
		ans[44][7] = 2;
		ans[43][7] = 3;
		ans[42][7] = 4;
		ans[41][7] = 5;
		ans[40][7] = 6;
		ans[39][7] = 7;
		ans[38][7] = 8;
		ans[37][7] = 9;
		ans[52][7] = 12;
		ans[51][7] = 13;
		ans[50][7] = 14;
		ans[49][7] = 15;
		ans[48][7] = 16;
		ans[47][7] = 17;
		ans[46][7] = 18;
		ans[45][7] = 19;
		ans[60][7] = 22;
		ans[59][7] = 23;
		ans[58][7] = 24;
		ans[57][7] = 25;
		ans[56][7] = 26;
		ans[55][7] = 27;
		ans[54][7] = 28;
		ans[53][7] = 29;
		ans[68][7] = 32;
		ans[67][7] = 33;
		ans[66][7] = 34;
		ans[65][7] = 35;
		ans[64][7] = 36;
		ans[63][7] = 37;
		ans[62][7] = 38;
		ans[61][7] = 39;
		ans[76][7] = 42;
		ans[75][7] = 43;
		ans[74][7] = 44;
		ans[73][7] = 45;
		ans[72][7] = 46;
		ans[71][7] = 47;
		ans[70][7] = 48;
		ans[69][7] = 49;
		ans[84][7] = 52;
		ans[83][7] = 53;
		ans[82][7] = 54;
		ans[81][7] = 55;
		ans[80][7] = 56;
		ans[79][7] = 57;
		ans[78][7] = 58;
		ans[77][7] = 59;
		ans[92][7] = 62;
		ans[91][7] = 63;
		ans[90][7] = 64;
		ans[89][7] = 65;
		ans[88][7] = 66;
		ans[87][7] = 67;
		ans[86][7] = 68;
		ans[85][7] = 69;
		ans[100][7] = 72;
		ans[99][7] = 73;
		ans[98][7] = 74;
		ans[97][7] = 75;
		ans[96][7] = 76;
		ans[95][7] = 77;
		ans[94][7] = 78;
		ans[93][7] = 79;
		ans[108][7] = 82;
		ans[107][7] = 83;
		ans[106][7] = 84;
		ans[105][7] = 85;
		ans[104][7] = 86;
		ans[103][7] = 87;
		ans[102][7] = 88;
		ans[101][7] = 89;
		ans[116][7] = 92;
		ans[115][7] = 183;
		ans[114][7] = 184;
		ans[113][7] = 185;
		ans[112][7] = 186;
		ans[111][7] = 187;
		ans[110][7] = 188;
		ans[109][7] = 189;
		ans[124][7] = 192;
		ans[123][7] = 283;
		ans[122][7] = 284;
		ans[121][7] = 285;
		ans[120][7] = 286;
		ans[119][7] = 287;
		ans[118][7] = 288;
		ans[117][7] = 289;
		ans[132][7] = 292;
		ans[131][7] = 383;
		ans[130][7] = 384;
		ans[129][7] = 385;
		ans[128][7] = 386;
		ans[127][7] = 387;
		ans[126][7] = 388;
		ans[125][7] = 389;
		ans[140][7] = 392;
		ans[139][7] = 483;
		ans[138][7] = 484;
		ans[137][7] = 485;
		ans[136][7] = 486;
		ans[135][7] = 487;
		ans[134][7] = 488;
		ans[133][7] = 489;
		ans[148][7] = 492;
		ans[147][7] = 583;
		ans[146][7] = 584;
		ans[145][7] = 585;
		ans[144][7] = 586;
		ans[143][7] = 587;
		ans[142][7] = 588;
		ans[141][7] = 589;
		ans[150][7] = 688;
		ans[149][7] = 689;
		ans[36][8] = 0;
		ans[45][8] = 1;
		ans[54][8] = 11;
		ans[63][8] = 21;
		ans[72][8] = 31;
		ans[81][8] = 41;
		ans[90][8] = 51;
		ans[99][8] = 61;
		ans[108][8] = 71;
		ans[117][8] = 81;
		ans[126][8] = 91;
		ans[135][8] = 191;
		ans[144][8] = 291;
		ans[45][9] = 0;
		ans[46][9] = 1;
		ans[47][9] = 2;
		ans[48][9] = 3;
		ans[49][9] = 4;
		ans[50][9] = 5;
		ans[51][9] = 6;
		ans[52][9] = 7;
		ans[53][9] = 8;
		ans[54][9] = 9;
		ans[55][9] = 10;
		ans[56][9] = 11;
		ans[57][9] = 12;
		ans[58][9] = 13;
		ans[59][9] = 14;
		ans[60][9] = 15;
		ans[61][9] = 16;
		ans[62][9] = 17;
		ans[63][9] = 18;
		ans[64][9] = 19;
		ans[65][9] = 20;
		ans[66][9] = 21;
		ans[67][9] = 22;
		ans[68][9] = 23;
		ans[69][9] = 24;
		ans[70][9] = 25;
		ans[71][9] = 26;
		ans[72][9] = 27;
		ans[73][9] = 28;
		ans[74][9] = 29;
		ans[75][9] = 30;
		ans[76][9] = 31;
		ans[77][9] = 32;
		ans[78][9] = 33;
		ans[79][9] = 34;
		ans[80][9] = 35;
		ans[81][9] = 36;
		ans[82][9] = 37;
		ans[83][9] = 38;
		ans[84][9] = 39;
		ans[85][9] = 40;
		ans[86][9] = 41;
		ans[87][9] = 42;
		ans[88][9] = 43;
		ans[89][9] = 44;
		ans[90][9] = 45;
		ans[91][9] = 46;
		ans[92][9] = 47;
		ans[93][9] = 48;
		ans[94][9] = 49;
		ans[95][9] = 50;
		ans[96][9] = 51;
		ans[97][9] = 52;
		ans[98][9] = 53;
		ans[99][9] = 54;
		ans[100][9] = 55;
		ans[101][9] = 56;
		ans[102][9] = 57;
		ans[103][9] = 58;
		ans[104][9] = 59;
		ans[105][9] = 60;
		ans[106][9] = 61;
		ans[107][9] = 62;
		ans[108][9] = 63;
		ans[109][9] = 64;
		ans[110][9] = 65;
		ans[111][9] = 66;
		ans[112][9] = 67;
		ans[113][9] = 68;
		ans[114][9] = 69;
		ans[115][9] = 70;
		ans[116][9] = 71;
		ans[117][9] = 72;
		ans[118][9] = 73;
		ans[119][9] = 74;
		ans[120][9] = 75;
		ans[121][9] = 76;
		ans[122][9] = 77;
		ans[123][9] = 78;
		ans[124][9] = 79;
		ans[125][9] = 80;
		ans[126][9] = 81;
		ans[127][9] = 82;
		ans[128][9] = 83;
		ans[129][9] = 84;
		ans[130][9] = 85;
		ans[131][9] = 86;
		ans[132][9] = 87;
		ans[133][9] = 88;
		ans[134][9] = 89;
		ans[135][9] = 90;
		ans[136][9] = 181;
		ans[137][9] = 182;
		ans[138][9] = 183;
		ans[139][9] = 184;
		ans[140][9] = 185;
		ans[141][9] = 186;
		ans[142][9] = 187;
		ans[143][9] = 188;
		ans[144][9] = 189;
		ans[145][9] = 190;
		ans[146][9] = 281;
		ans[147][9] = 282;
		ans[148][9] = 283;
		ans[149][9] = 284;
		ans[150][9] = 285;

	}
	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	int T; cin >> T;
	while(T--)
	{
		int n, k; cin >> n >> k;
		if(k==0)
		{
			LL a = 1e18;
			for(int d = 0; d <= min(n,9); d++)
				a = min(a,f(n,d));
			cout<<a<<endl;
		}	
		else if(k==1)
		{
			LL a = 1e18;
			for(int nines = 0; 9*nines+1 <= n; nines++)
				if((n-9*nines-1)%2==0)
				{
					LL sub_a = 0;
					LL base = 1;
					for(int i = 0; i < nines; i++)
					{
						sub_a += 9*base;
						base *= 10;
					}

					LL sub_prev = 1e18;
					LL m = (n-9*nines-1)/2;
					for(int d = 0; d <= min(8LL,m); d++)
						sub_prev = min(sub_prev,f(m,d));
					sub_a += base*sub_prev;

					a = min(a,sub_a);
				}
			if(a==1e18)
				cout<<-1<<endl;
			else
				cout<<a<<endl;
		}
		else
			cout<<ans[n][k]<<endl;
	}

	return 0;
}