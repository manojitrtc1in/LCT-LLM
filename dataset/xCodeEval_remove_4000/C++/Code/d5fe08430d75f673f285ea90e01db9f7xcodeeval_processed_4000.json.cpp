



using namespace std;



mt19937 gen(time(0));
bool id0 = 0;
ll sumdig(ll a) {
    ll res = 0;
    while (a) {
        res += a % 10;
        a /= 10;
    }
    return res;
}
ll get(ll x, ll k) {
    ll res = 0;
    for (ll i = x; i <= x + k; ++i)
        res += sumdig(i);
    return res;
}
ll ar(ll K) {
    return K * (K + 1) / 2;
}
void upd(ll a, ll &ans) {
    if (ans == -1)
        ans = a;
    else {
        if (ans > a)
            ans = a;
    }
}
map<int, map<int, ll>> mp;
void init(){
mp[1][0] = 1;
mp[1][1] = 0;
mp[1][2] = -1;
mp[1][3] = -1;
mp[1][4] = -1;
mp[1][5] = -1;
mp[1][6] = -1;
mp[1][7] = -1;
mp[1][8] = -1;
mp[1][9] = -1;
mp[2][0] = 2;
mp[2][1] = -1;
mp[2][2] = -1;
mp[2][3] = -1;
mp[2][4] = -1;
mp[2][5] = -1;
mp[2][6] = -1;
mp[2][7] = -1;
mp[2][8] = -1;
mp[2][9] = -1;
mp[3][0] = 3;
mp[3][1] = 1;
mp[3][2] = 0;
mp[3][3] = -1;
mp[3][4] = -1;
mp[3][5] = -1;
mp[3][6] = -1;
mp[3][7] = -1;
mp[3][8] = -1;
mp[3][9] = -1;
mp[4][0] = 4;
mp[4][1] = -1;
mp[4][2] = -1;
mp[4][3] = -1;
mp[4][4] = -1;
mp[4][5] = -1;
mp[4][6] = -1;
mp[4][7] = -1;
mp[4][8] = -1;
mp[4][9] = -1;
mp[5][0] = 5;
mp[5][1] = 2;
mp[5][2] = -1;
mp[5][3] = -1;
mp[5][4] = -1;
mp[5][5] = -1;
mp[5][6] = -1;
mp[5][7] = -1;
mp[5][8] = -1;
mp[5][9] = -1;
mp[6][0] = 6;
mp[6][1] = -1;
mp[6][2] = 1;
mp[6][3] = 0;
mp[6][4] = -1;
mp[6][5] = -1;
mp[6][6] = -1;
mp[6][7] = -1;
mp[6][8] = -1;
mp[6][9] = -1;
mp[7][0] = 7;
mp[7][1] = 3;
mp[7][2] = -1;
mp[7][3] = -1;
mp[7][4] = -1;
mp[7][5] = -1;
mp[7][6] = -1;
mp[7][7] = -1;
mp[7][8] = -1;
mp[7][9] = -1;
mp[8][0] = 8;
mp[8][1] = -1;
mp[8][2] = -1;
mp[8][3] = -1;
mp[8][4] = -1;
mp[8][5] = -1;
mp[8][6] = -1;
mp[8][7] = -1;
mp[8][8] = -1;
mp[8][9] = -1;
mp[9][0] = 9;
mp[9][1] = 4;
mp[9][2] = 2;
mp[9][3] = -1;
mp[9][4] = -1;
mp[9][5] = -1;
mp[9][6] = -1;
mp[9][7] = -1;
mp[9][8] = -1;
mp[9][9] = -1;
mp[10][0] = 19;
mp[10][1] = 9;
mp[10][2] = -1;
mp[10][3] = 1;
mp[10][4] = 0;
mp[10][5] = -1;
mp[10][6] = -1;
mp[10][7] = -1;
mp[10][8] = -1;
mp[10][9] = -1;
mp[11][0] = 29;
mp[11][1] = 5;
mp[11][2] = -1;
mp[11][3] = -1;
mp[11][4] = -1;
mp[11][5] = -1;
mp[11][6] = -1;
mp[11][7] = -1;
mp[11][8] = -1;
mp[11][9] = -1;
mp[12][0] = 39;
mp[12][1] = 19;
mp[12][2] = 3;
mp[12][3] = -1;
mp[12][4] = -1;
mp[12][5] = -1;
mp[12][6] = -1;
mp[12][7] = -1;
mp[12][8] = -1;
mp[12][9] = -1;
mp[13][0] = 49;
mp[13][1] = 6;
mp[13][2] = -1;
mp[13][3] = -1;
mp[13][4] = -1;
mp[13][5] = -1;
mp[13][6] = -1;
mp[13][7] = -1;
mp[13][8] = -1;
mp[13][9] = -1;
mp[14][0] = 59;
mp[14][1] = 29;
mp[14][2] = -1;
mp[14][3] = 2;
mp[14][4] = -1;
mp[14][5] = -1;
mp[14][6] = -1;
mp[14][7] = -1;
mp[14][8] = -1;
mp[14][9] = -1;
mp[15][0] = 69;
mp[15][1] = 7;
mp[15][2] = 4;
mp[15][3] = 9;
mp[15][4] = 1;
mp[15][5] = 0;
mp[15][6] = -1;
mp[15][7] = -1;
mp[15][8] = -1;
mp[15][9] = -1;
mp[16][0] = 79;
mp[16][1] = 39;
mp[16][2] = -1;
mp[16][3] = -1;
mp[16][4] = -1;
mp[16][5] = -1;
mp[16][6] = -1;
mp[16][7] = -1;
mp[16][8] = -1;
mp[16][9] = -1;
mp[17][0] = 89;
mp[17][1] = 8;
mp[17][2] = -1;
mp[17][3] = -1;
mp[17][4] = -1;
mp[17][5] = -1;
mp[17][6] = -1;
mp[17][7] = -1;
mp[17][8] = -1;
mp[17][9] = -1;
mp[18][0] = 99;
mp[18][1] = 49;
mp[18][2] = 5;
mp[18][3] = 3;
mp[18][4] = -1;
mp[18][5] = -1;
mp[18][6] = -1;
mp[18][7] = -1;
mp[18][8] = -1;
mp[18][9] = -1;
mp[19][0] = 199;
mp[19][1] = 18;
mp[19][2] = -1;
mp[19][3] = 19;
mp[19][4] = 9;
mp[19][5] = -1;
mp[19][6] = -1;
mp[19][7] = -1;
mp[19][8] = -1;
mp[19][9] = -1;
mp[20][0] = 299;
mp[20][1] = 59;
mp[20][2] = -1;
mp[20][3] = 8;
mp[20][4] = 2;
mp[20][5] = -1;
mp[20][6] = -1;
mp[20][7] = -1;
mp[20][8] = -1;
mp[20][9] = -1;
mp[21][0] = 399;
mp[21][1] = 28;
mp[21][2] = 6;
mp[21][3] = -1;
mp[21][4] = -1;
mp[21][5] = 1;
mp[21][6] = 0;
mp[21][7] = -1;
mp[21][8] = -1;
mp[21][9] = -1;
mp[22][0] = 499;
mp[22][1] = 69;
mp[22][2] = -1;
mp[22][3] = 4;
mp[22][4] = -1;
mp[22][5] = -1;
mp[22][6] = -1;
mp[22][7] = -1;
mp[22][8] = -1;
mp[22][9] = -1;
mp[23][0] = 599;
mp[23][1] = 38;
mp[23][2] = -1;
mp[23][3] = 29;
mp[23][4] = 8;
mp[23][5] = -1;
mp[23][6] = -1;
mp[23][7] = -1;
mp[23][8] = -1;
mp[23][9] = -1;
mp[24][0] = 699;
mp[24][1] = 79;
mp[24][2] = 7;
mp[24][3] = 18;
mp[24][4] = 19;
mp[24][5] = 9;
mp[24][6] = -1;
mp[24][7] = -1;
mp[24][8] = -1;
mp[24][9] = -1;
mp[25][0] = 799;
mp[25][1] = 48;
mp[25][2] = -1;
mp[25][3] = 7;
mp[25][4] = 3;
mp[25][5] = -1;
mp[25][6] = -1;
mp[25][7] = -1;
mp[25][8] = -1;
mp[25][9] = -1;
mp[26][0] = 899;
mp[26][1] = 89;
mp[26][2] = -1;
mp[26][3] = 5;
mp[26][4] = -1;
mp[26][5] = -1;
mp[26][6] = -1;
mp[26][7] = -1;
mp[26][8] = -1;
mp[26][9] = -1;
mp[27][0] = 999;
mp[27][1] = 58;
mp[27][2] = 17;
mp[27][3] = 39;
mp[27][4] = 7;
mp[27][5] = 2;
mp[27][6] = -1;
mp[27][7] = -1;
mp[27][8] = -1;
mp[27][9] = -1;
mp[28][0] = 1999;
mp[28][1] = 189;
mp[28][2] = -1;
mp[28][3] = 28;
mp[28][4] = 18;
mp[28][5] = -1;
mp[28][6] = 1;
mp[28][7] = 0;
mp[28][8] = -1;
mp[28][9] = -1;
mp[29][0] = 2999;
mp[29][1] = 68;
mp[29][2] = -1;
mp[29][3] = 17;
mp[29][4] = 29;
mp[29][5] = -1;
mp[29][6] = -1;
mp[29][7] = -1;
mp[29][8] = -1;
mp[29][9] = -1;
mp[30][0] = 3999;
mp[30][1] = 289;
mp[30][2] = 27;
mp[30][3] = 6;
mp[30][4] = 4;
mp[30][5] = 7;
mp[30][6] = 9;
mp[30][7] = -1;
mp[30][8] = -1;
mp[30][9] = -1;
mp[31][0] = 4999;
mp[31][1] = 78;
mp[31][2] = -1;
mp[31][3] = 49;
mp[31][4] = 6;
mp[31][5] = -1;
mp[31][6] = -1;
mp[31][7] = -1;
mp[31][8] = -1;
mp[31][9] = -1;
mp[32][0] = 5999;
mp[32][1] = 389;
mp[32][2] = -1;
mp[32][3] = 38;
mp[32][4] = 17;
mp[32][5] = -1;
mp[32][6] = 8;
mp[32][7] = -1;
mp[32][8] = -1;
mp[32][9] = -1;
mp[33][0] = 6999;
mp[33][1] = 88;
mp[33][2] = 37;
mp[33][3] = 27;
mp[33][4] = 28;
mp[33][5] = 3;
mp[33][6] = -1;
mp[33][7] = -1;
mp[33][8] = -1;
mp[33][9] = -1;
mp[34][0] = 7999;
mp[34][1] = 489;
mp[34][2] = -1;
mp[34][3] = 16;
mp[34][4] = 39;
mp[34][5] = -1;
mp[34][6] = 7;
mp[34][7] = -1;
mp[34][8] = -1;
mp[34][9] = -1;
mp[35][0] = 8999;
mp[35][1] = 98;
mp[35][2] = -1;
mp[35][3] = 59;
mp[35][4] = 5;
mp[35][5] = -1;
mp[35][6] = 2;
mp[35][7] = -1;
mp[35][8] = -1;
mp[35][9] = -1;
mp[36][0] = 9999;
mp[36][1] = 589;
mp[36][2] = 47;
mp[36][3] = 48;
mp[36][4] = 16;
mp[36][5] = 5;
mp[36][6] = 6;
mp[36][7] = 1;
mp[36][8] = 0;
mp[36][9] = -1;
mp[37][0] = 19999;
mp[37][1] = 198;
mp[37][2] = -1;
mp[37][3] = 37;
mp[37][4] = 27;
mp[37][5] = -1;
mp[37][6] = 19;
mp[37][7] = 9;
mp[37][8] = -1;
mp[37][9] = -1;
mp[38][0] = 29999;
mp[38][1] = 689;
mp[38][2] = -1;
mp[38][3] = 26;
mp[38][4] = 38;
mp[38][5] = -1;
mp[38][6] = 5;
mp[38][7] = 8;
mp[38][8] = -1;
mp[38][9] = -1;
mp[39][0] = 39999;
mp[39][1] = 298;
mp[39][2] = 57;
mp[39][3] = 69;
mp[39][4] = 49;
mp[39][5] = 4;
mp[39][6] = 18;
mp[39][7] = 7;
mp[39][8] = -1;
mp[39][9] = -1;
mp[40][0] = 49999;
mp[40][1] = 789;
mp[40][2] = -1;
mp[40][3] = 58;
mp[40][4] = 15;
mp[40][5] = -1;
mp[40][6] = 4;
mp[40][7] = 6;
mp[40][8] = -1;
mp[40][9] = -1;
mp[41][0] = 59999;
mp[41][1] = 398;
mp[41][2] = -1;
mp[41][3] = 47;
mp[41][4] = 26;
mp[41][5] = -1;
mp[41][6] = 17;
mp[41][7] = 5;
mp[41][8] = -1;
mp[41][9] = -1;
mp[42][0] = 69999;
mp[42][1] = 889;
mp[42][2] = 67;
mp[42][3] = 36;
mp[42][4] = 37;
mp[42][5] = 15;
mp[42][6] = 3;
mp[42][7] = 4;
mp[42][8] = -1;
mp[42][9] = -1;
mp[43][0] = 79999;
mp[43][1] = 498;
mp[43][2] = -1;
mp[43][3] = 79;
mp[43][4] = 48;
mp[43][5] = -1;
mp[43][6] = 16;
mp[43][7] = 3;
mp[43][8] = -1;
mp[43][9] = -1;
mp[44][0] = 89999;
mp[44][1] = 989;
mp[44][2] = -1;
mp[44][3] = 68;
mp[44][4] = 59;
mp[44][5] = -1;
mp[44][6] = 29;
mp[44][7] = 2;
mp[44][8] = -1;
mp[44][9] = -1;
mp[45][0] = 99999;
mp[45][1] = 598;
mp[45][2] = 77;
mp[45][3] = 57;
mp[45][4] = 25;
mp[45][5] = 14;
mp[45][6] = 15;
mp[45][7] = 19;
mp[45][8] = 1;
mp[45][9] = 0;
mp[46][0] = 199999;
mp[46][1] = 1989;
mp[46][2] = -1;
mp[46][3] = 46;
mp[46][4] = 36;
mp[46][5] = -1;
mp[46][6] = 28;
mp[46][7] = 18;
mp[46][8] = -1;
mp[46][9] = 1;
mp[47][0] = 299999;
mp[47][1] = 698;
mp[47][2] = -1;
mp[47][3] = 89;
mp[47][4] = 47;
mp[47][5] = -1;
mp[47][6] = 14;
mp[47][7] = 17;
mp[47][8] = -1;
mp[47][9] = 2;
mp[48][0] = 399999;
mp[48][1] = 2989;
mp[48][2] = 87;
mp[48][3] = 78;
mp[48][4] = 58;
mp[48][5] = 25;
mp[48][6] = 27;
mp[48][7] = 16;
mp[48][8] = -1;
mp[48][9] = 3;
mp[49][0] = 499999;
mp[49][1] = 798;
mp[49][2] = -1;
mp[49][3] = 67;
mp[49][4] = 69;
mp[49][5] = -1;
mp[49][6] = 13;
mp[49][7] = 15;
mp[49][8] = -1;
mp[49][9] = 4;
mp[50][0] = 599999;
mp[50][1] = 3989;
mp[50][2] = -1;
mp[50][3] = 56;
mp[50][4] = 35;
mp[50][5] = -1;
mp[50][6] = 26;
mp[50][7] = 14;
mp[50][8] = -1;
mp[50][9] = 5;
mp[51][0] = 699999;
mp[51][1] = 898;
mp[51][2] = 97;
mp[51][3] = 189;
mp[51][4] = 46;
mp[51][5] = 24;
mp[51][6] = 39;
mp[51][7] = 13;
mp[51][8] = -1;
mp[51][9] = 6;
mp[52][0] = 799999;
mp[52][1] = 4989;
mp[52][2] = -1;
mp[52][3] = 88;
mp[52][4] = 57;
mp[52][5] = -1;
mp[52][6] = 25;
mp[52][7] = 12;
mp[52][8] = -1;
mp[52][9] = 7;
mp[53][0] = 899999;
mp[53][1] = 998;
mp[53][2] = -1;
mp[53][3] = 77;
mp[53][4] = 68;
mp[53][5] = -1;
mp[53][6] = 38;
mp[53][7] = 29;
mp[53][8] = -1;
mp[53][9] = 8;
mp[54][0] = 999999;
mp[54][1] = 5989;
mp[54][2] = 197;
mp[54][3] = 66;
mp[54][4] = 79;
mp[54][5] = 35;
mp[54][6] = 24;
mp[54][7] = 28;
mp[54][8] = 11;
mp[54][9] = 9;
mp[55][0] = 1999999;
mp[55][1] = 1998;
mp[55][2] = -1;
mp[55][3] = 289;
mp[55][4] = 45;
mp[55][5] = -1;
mp[55][6] = 37;
mp[55][7] = 27;
mp[55][8] = -1;
mp[55][9] = 10;
mp[56][0] = 2999999;
mp[56][1] = 6989;
mp[56][2] = -1;
mp[56][3] = 188;
mp[56][4] = 56;
mp[56][5] = -1;
mp[56][6] = 23;
mp[56][7] = 26;
mp[56][8] = -1;
mp[56][9] = 11;
mp[57][0] = 3999999;
mp[57][1] = 2998;
mp[57][2] = 297;
mp[57][3] = 87;
mp[57][4] = 67;
mp[57][5] = 34;
mp[57][6] = 36;
mp[57][7] = 25;
mp[57][8] = -1;
mp[57][9] = 12;
mp[58][0] = 4999999;
mp[58][1] = 7989;
mp[58][2] = -1;
mp[58][3] = 76;
mp[58][4] = 78;
mp[58][5] = -1;
mp[58][6] = 49;
mp[58][7] = 24;
mp[58][8] = -1;
mp[58][9] = 13;
mp[59][0] = 5999999;
mp[59][1] = 3998;
mp[59][2] = -1;
mp[59][3] = 389;
mp[59][4] = 89;
mp[59][5] = -1;
mp[59][6] = 35;
mp[59][7] = 23;
mp[59][8] = -1;
mp[59][9] = 14;
mp[60][0] = 6999999;
mp[60][1] = 8989;
mp[60][2] = 397;
mp[60][3] = 288;
mp[60][4] = 55;
mp[60][5] = 45;
mp[60][6] = 48;
mp[60][7] = 22;
mp[60][8] = -1;
mp[60][9] = 15;
mp[61][0] = 7999999;
mp[61][1] = 4998;
mp[61][2] = -1;
mp[61][3] = 187;
mp[61][4] = 66;
mp[61][5] = -1;
mp[61][6] = 34;
mp[61][7] = 39;
mp[61][8] = -1;
mp[61][9] = 16;
mp[62][0] = 8999999;
mp[62][1] = 9989;
mp[62][2] = -1;
mp[62][3] = 86;
mp[62][4] = 77;
mp[62][5] = -1;
mp[62][6] = 47;
mp[62][7] = 38;
mp[62][8] = -1;
mp[62][9] = 17;
mp[63][0] = 9999999;
mp[63][1] = 5998;
mp[63][2] = 497;
mp[63][3] = 489;
mp[63][4] = 88;
mp[63][5] = 44;
mp[63][6] = 33;
mp[63][7] = 37;
mp[63][8] = 21;
mp[63][9] = 18;
mp[64][0] = 19999999;
mp[64][1] = 19989;
mp[64][2] = -1;
mp[64][3] = 388;
mp[64][4] = 189;
mp[64][5] = -1;
mp[64][6] = 46;
mp[64][7] = 36;
mp[64][8] = -1;
mp[64][9] = 19;
mp[65][0] = 29999999;
mp[65][1] = 6998;
mp[65][2] = -1;
mp[65][3] = 287;
mp[65][4] = 65;
mp[65][5] = -1;
mp[65][6] = 59;
mp[65][7] = 35;
mp[65][8] = -1;
mp[65][9] = 20;
mp[66][0] = 39999999;
mp[66][1] = 29989;
mp[66][2] = 597;
mp[66][3] = 96;
mp[66][4] = 76;
mp[66][5] = 55;
mp[66][6] = 45;
mp[66][7] = 34;
mp[66][8] = -1;
mp[66][9] = 21;
mp[67][0] = 49999999;
mp[67][1] = 7998;
mp[67][2] = -1;
mp[67][3] = 589;
mp[67][4] = 87;
mp[67][5] = -1;
mp[67][6] = 58;
mp[67][7] = 33;
mp[67][8] = -1;
mp[67][9] = 22;
mp[68][0] = 59999999;
mp[68][1] = 39989;
mp[68][2] = -1;
mp[68][3] = 488;
mp[68][4] = 188;
mp[68][5] = -1;
mp[68][6] = 44;
mp[68][7] = 32;
mp[68][8] = -1;
mp[68][9] = 23;
mp[69][0] = 69999999;
mp[69][1] = 8998;
mp[69][2] = 697;
mp[69][3] = 387;
mp[69][4] = 289;
mp[69][5] = 54;
mp[69][6] = 57;
mp[69][7] = 49;
mp[69][8] = -1;
mp[69][9] = 24;
mp[70][0] = 79999999;
mp[70][1] = 49989;
mp[70][2] = -1;
mp[70][3] = 196;
mp[70][4] = 75;
mp[70][5] = -1;
mp[70][6] = 43;
mp[70][7] = 48;
mp[70][8] = -1;
mp[70][9] = 25;
mp[71][0] = 89999999;
mp[71][1] = 9998;
mp[71][2] = -1;
mp[71][3] = 689;
mp[71][4] = 86;
mp[71][5] = -1;
mp[71][6] = 56;
mp[71][7] = 47;
mp[71][8] = -1;
mp[71][9] = 26;
mp[72][0] = 99999999;
mp[72][1] = 59989;
mp[72][2] = 797;
mp[72][3] = 588;
mp[72][4] = 187;
mp[72][5] = 65;
mp[72][6] = 69;
mp[72][7] = 46;
mp[72][8] = 31;
mp[72][9] = 27;
mp[73][0] = 199999999;
mp[73][1] = 19998;
mp[73][2] = -1;
mp[73][3] = 487;
mp[73][4] = 288;
mp[73][5] = -1;
mp[73][6] = 55;
mp[73][7] = 45;
mp[73][8] = -1;
mp[73][9] = 28;
mp[74][0] = 299999999;
mp[74][1] = 69989;
mp[74][2] = -1;
mp[74][3] = 296;
mp[74][4] = 389;
mp[74][5] = -1;
mp[74][6] = 68;
mp[74][7] = 44;
mp[74][8] = -1;
mp[74][9] = 29;
mp[75][0] = 399999999;
mp[75][1] = 29998;
mp[75][2] = 897;
mp[75][3] = 789;
mp[75][4] = 85;
mp[75][5] = 64;
mp[75][6] = 54;
mp[75][7] = 43;
mp[75][8] = -1;
mp[75][9] = 30;
mp[76][0] = 499999999;
mp[76][1] = 79989;
mp[76][2] = -1;
mp[76][3] = 688;
mp[76][4] = 186;
mp[76][5] = -1;
mp[76][6] = 67;
mp[76][7] = 42;
mp[76][8] = -1;
mp[76][9] = 31;
mp[77][0] = 599999999;
mp[77][1] = 39998;
mp[77][2] = -1;
mp[77][3] = 587;
mp[77][4] = 287;
mp[77][5] = -1;
mp[77][6] = 53;
mp[77][7] = 59;
mp[77][8] = -1;
mp[77][9] = 32;
mp[78][0] = 699999999;
mp[78][1] = 89989;
mp[78][2] = 997;
mp[78][3] = 396;
mp[78][4] = 388;
mp[78][5] = 75;
mp[78][6] = 66;
mp[78][7] = 58;
mp[78][8] = -1;
mp[78][9] = 33;
mp[79][0] = 799999999;
mp[79][1] = 49998;
mp[79][2] = -1;
mp[79][3] = 889;
mp[79][4] = 489;
mp[79][5] = -1;
mp[79][6] = 79;
mp[79][7] = 57;
mp[79][8] = -1;
mp[79][9] = 34;
mp[80][0] = 899999999;
mp[80][1] = 99989;
mp[80][2] = -1;
mp[80][3] = 788;
mp[80][4] = 95;
mp[80][5] = -1;
mp[80][6] = 65;
mp[80][7] = 56;
mp[80][8] = -1;
mp[80][9] = 35;
mp[81][0] = 999999999;
mp[81][1] = 59998;
mp[81][2] = 1997;
mp[81][3] = 687;
mp[81][4] = 286;
mp[81][5] = 74;
mp[81][6] = 78;
mp[81][7] = 55;
mp[81][8] = 41;
mp[81][9] = 36;
mp[82][0] = 1999999999;
mp[82][1] = 199989;
mp[82][2] = -1;
mp[82][3] = 496;
mp[82][4] = 387;
mp[82][5] = -1;
mp[82][6] = 64;
mp[82][7] = 54;
mp[82][8] = -1;
mp[82][9] = 37;
mp[83][0] = 2999999999;
mp[83][1] = 69998;
mp[83][2] = -1;
mp[83][3] = 989;
mp[83][4] = 488;
mp[83][5] = -1;
mp[83][6] = 77;
mp[83][7] = 53;
mp[83][8] = -1;
mp[83][9] = 38;
mp[84][0] = 3999999999;
mp[84][1] = 299989;
mp[84][2] = 2997;
mp[84][3] = 888;
mp[84][4] = 589;
mp[84][5] = 85;
mp[84][6] = 63;
mp[84][7] = 52;
mp[84][8] = -1;
mp[84][9] = 39;
mp[85][0] = 4999999999;
mp[85][1] = 79998;
mp[85][2] = -1;
mp[85][3] = 787;
mp[85][4] = 195;
mp[85][5] = -1;
mp[85][6] = 76;
mp[85][7] = 69;
mp[85][8] = -1;
mp[85][9] = 40;
mp[86][0] = 5999999999;
mp[86][1] = 399989;
mp[86][2] = -1;
mp[86][3] = 596;
mp[86][4] = 386;
mp[86][5] = -1;
mp[86][6] = 89;
mp[86][7] = 68;
mp[86][8] = -1;
mp[86][9] = 41;
mp[87][0] = 6999999999;
mp[87][1] = 89998;
mp[87][2] = 3997;
mp[87][3] = 1989;
mp[87][4] = 487;
mp[87][5] = 84;
mp[87][6] = 75;
mp[87][7] = 67;
mp[87][8] = -1;
mp[87][9] = 42;
mp[88][0] = 7999999999;
mp[88][1] = 499989;
mp[88][2] = -1;
mp[88][3] = 988;
mp[88][4] = 588;
mp[88][5] = -1;
mp[88][6] = 88;
mp[88][7] = 66;
mp[88][8] = -1;
mp[88][9] = 43;
mp[89][0] = 8999999999;
mp[89][1] = 99998;
mp[89][2] = -1;
mp[89][3] = 887;
mp[89][4] = 689;
mp[89][5] = -1;
mp[89][6] = 74;
mp[89][7] = 65;
mp[89][8] = -1;
mp[89][9] = 44;
mp[90][0] = 9999999999;
mp[90][1] = 599989;
mp[90][2] = 4997;
mp[90][3] = 696;
mp[90][4] = 295;
mp[90][5] = 185;
mp[90][6] = 87;
mp[90][7] = 64;
mp[90][8] = 51;
mp[90][9] = 45;
mp[91][0] = 19999999999;
mp[91][1] = 199998;
mp[91][2] = -1;
mp[91][3] = 2989;
mp[91][4] = 486;
mp[91][5] = -1;
mp[91][6] = 73;
mp[91][7] = 63;
mp[91][8] = -1;
mp[91][9] = 46;
mp[92][0] = 29999999999;
mp[92][1] = 699989;
mp[92][2] = -1;
mp[92][3] = 1988;
mp[92][4] = 587;
mp[92][5] = -1;
mp[92][6] = 86;
mp[92][7] = 62;
mp[92][8] = -1;
mp[92][9] = 47;
mp[93][0] = 39999999999;
mp[93][1] = 299998;
mp[93][2] = 5997;
mp[93][3] = 987;
mp[93][4] = 688;
mp[93][5] = 94;
mp[93][6] = 189;
mp[93][7] = 79;
mp[93][8] = -1;
mp[93][9] = 48;
mp[94][0] = 49999999999;
mp[94][1] = 799989;
mp[94][2] = -1;
mp[94][3] = 796;
mp[94][4] = 789;
mp[94][5] = -1;
mp[94][6] = 85;
mp[94][7] = 78;
mp[94][8] = -1;
mp[94][9] = 49;
mp[95][0] = 59999999999;
mp[95][1] = 399998;
mp[95][2] = -1;
mp[95][3] = 3989;
mp[95][4] = 395;
mp[95][5] = -1;
mp[95][6] = 188;
mp[95][7] = 77;
mp[95][8] = -1;
mp[95][9] = 50;
mp[96][0] = 69999999999;
mp[96][1] = 899989;
mp[96][2] = 6997;
mp[96][3] = 2988;
mp[96][4] = 586;
mp[96][5] = 285;
mp[96][6] = 84;
mp[96][7] = 76;
mp[96][8] = -1;
mp[96][9] = 51;
mp[97][0] = 79999999999;
mp[97][1] = 499998;
mp[97][2] = -1;
mp[97][3] = 1987;
mp[97][4] = 687;
mp[97][5] = -1;
mp[97][6] = 187;
mp[97][7] = 75;
mp[97][8] = -1;
mp[97][9] = 52;
mp[98][0] = 89999999999;
mp[98][1] = 999989;
mp[98][2] = -1;
mp[98][3] = 896;
mp[98][4] = 788;
mp[98][5] = -1;
mp[98][6] = 83;
mp[98][7] = 74;
mp[98][8] = -1;
mp[98][9] = 53;
mp[99][0] = 99999999999;
mp[99][1] = 599998;
mp[99][2] = 7997;
mp[99][3] = 4989;
mp[99][4] = 889;
mp[99][5] = 194;
mp[99][6] = 186;
mp[99][7] = 73;
mp[99][8] = 61;
mp[99][9] = 54;
mp[100][0] = 199999999999;
mp[100][1] = 1999989;
mp[100][2] = -1;
mp[100][3] = 3988;
mp[100][4] = 495;
mp[100][5] = -1;
mp[100][6] = 289;
mp[100][7] = 72;
mp[100][8] = -1;
mp[100][9] = 55;
mp[101][0] = 299999999999;
mp[101][1] = 699998;
mp[101][2] = -1;
mp[101][3] = 2987;
mp[101][4] = 686;
mp[101][5] = -1;
mp[101][6] = 185;
mp[101][7] = 89;
mp[101][8] = -1;
mp[101][9] = 56;
mp[102][0] = 399999999999;
mp[102][1] = 2999989;
mp[102][2] = 8997;
mp[102][3] = 996;
mp[102][4] = 787;
mp[102][5] = 385;
mp[102][6] = 288;
mp[102][7] = 88;
mp[102][8] = -1;
mp[102][9] = 57;
mp[103][0] = 499999999999;
mp[103][1] = 799998;
mp[103][2] = -1;
mp[103][3] = 5989;
mp[103][4] = 888;
mp[103][5] = -1;
mp[103][6] = 184;
mp[103][7] = 87;
mp[103][8] = -1;
mp[103][9] = 58;
mp[104][0] = 599999999999;
mp[104][1] = 3999989;
mp[104][2] = -1;
mp[104][3] = 4988;
mp[104][4] = 989;
mp[104][5] = -1;
mp[104][6] = 287;
mp[104][7] = 86;
mp[104][8] = -1;
mp[104][9] = 59;
mp[105][0] = 699999999999;
mp[105][1] = 899998;
mp[105][2] = 9997;
mp[105][3] = 3987;
mp[105][4] = 595;
mp[105][5] = 294;
mp[105][6] = 93;
mp[105][7] = 85;
mp[105][8] = -1;
mp[105][9] = 60;
mp[106][0] = 799999999999;
mp[106][1] = 4999989;
mp[106][2] = -1;
mp[106][3] = 1996;
mp[106][4] = 786;
mp[106][5] = -1;
mp[106][6] = 286;
mp[106][7] = 84;
mp[106][8] = -1;
mp[106][9] = 61;
mp[107][0] = 899999999999;
mp[107][1] = 999998;
mp[107][2] = -1;
mp[107][3] = 6989;
mp[107][4] = 887;
mp[107][5] = -1;
mp[107][6] = 389;
mp[107][7] = 83;
mp[107][8] = -1;
mp[107][9] = 62;
mp[108][0] = 999999999999;
mp[108][1] = 5999989;
mp[108][2] = 19997;
mp[108][3] = 5988;
mp[108][4] = 988;
mp[108][5] = 485;
mp[108][6] = 285;
mp[108][7] = 82;
mp[108][8] = 71;
mp[108][9] = 63;
mp[109][0] = 1999999999999;
mp[109][1] = 1999998;
mp[109][2] = -1;
mp[109][3] = 4987;
mp[109][4] = 1989;
mp[109][5] = -1;
mp[109][6] = 388;
mp[109][7] = 189;
mp[109][8] = -1;
mp[109][9] = 64;
mp[110][0] = 2999999999999;
mp[110][1] = 6999989;
mp[110][2] = -1;
mp[110][3] = 2996;
mp[110][4] = 695;
mp[110][5] = -1;
mp[110][6] = 284;
mp[110][7] = 188;
mp[110][8] = -1;
mp[110][9] = 65;
mp[111][0] = 3999999999999;
mp[111][1] = 2999998;
mp[111][2] = 29997;
mp[111][3] = 7989;
mp[111][4] = 886;
mp[111][5] = 394;
mp[111][6] = 387;
mp[111][7] = 187;
mp[111][8] = -1;
mp[111][9] = 66;
mp[112][0] = 4999999999999;
mp[112][1] = 7999989;
mp[112][2] = -1;
mp[112][3] = 6988;
mp[112][4] = 987;
mp[112][5] = -1;
mp[112][6] = 193;
mp[112][7] = 186;
mp[112][8] = -1;
mp[112][9] = 67;
mp[113][0] = 5999999999999;
mp[113][1] = 3999998;
mp[113][2] = -1;
mp[113][3] = 5987;
mp[113][4] = 1988;
mp[113][5] = -1;
mp[113][6] = 386;
mp[113][7] = 185;
mp[113][8] = -1;
mp[113][9] = 68;
mp[114][0] = 6999999999999;
mp[114][1] = 8999989;
mp[114][2] = 39997;
mp[114][3] = 3996;
mp[114][4] = 2989;
mp[114][5] = 585;
mp[114][6] = 489;
mp[114][7] = 184;
mp[114][8] = -1;
mp[114][9] = 69;
mp[115][0] = 7999999999999;
mp[115][1] = 4999998;
mp[115][2] = -1;
mp[115][3] = 8989;
mp[115][4] = 795;
mp[115][5] = -1;
mp[115][6] = 385;
mp[115][7] = 183;
mp[115][8] = -1;
mp[115][9] = 70;
mp[116][0] = 8999999999999;
mp[116][1] = 9999989;
mp[116][2] = -1;
mp[116][3] = 7988;
mp[116][4] = 986;
mp[116][5] = -1;
mp[116][6] = 488;
mp[116][7] = 92;
mp[116][8] = -1;
mp[116][9] = 71;
mp[117][0] = 9999999999999;
mp[117][1] = 5999998;
mp[117][2] = 49997;
mp[117][3] = 6987;
mp[117][4] = 1987;
mp[117][5] = 494;
mp[117][6] = 384;
mp[117][7] = 289;
mp[117][8] = 81;
mp[117][9] = 72;
mp[118][0] = 19999999999999;
mp[118][1] = 19999989;
mp[118][2] = -1;
mp[118][3] = 4996;
mp[118][4] = 2988;
mp[118][5] = -1;
mp[118][6] = 487;
mp[118][7] = 288;
mp[118][8] = -1;
mp[118][9] = 73;
mp[119][0] = 29999999999999;
mp[119][1] = 6999998;
mp[119][2] = -1;
mp[119][3] = 9989;
mp[119][4] = 3989;
mp[119][5] = -1;
mp[119][6] = 293;
mp[119][7] = 287;
mp[119][8] = -1;
mp[119][9] = 74;
mp[120][0] = 39999999999999;
mp[120][1] = 29999989;
mp[120][2] = 59997;
mp[120][3] = 8988;
mp[120][4] = 895;
mp[120][5] = 685;
mp[120][6] = 486;
mp[120][7] = 286;
mp[120][8] = -1;
mp[120][9] = 75;
mp[121][0] = 49999999999999;
mp[121][1] = 7999998;
mp[121][2] = -1;
mp[121][3] = 7987;
mp[121][4] = 1986;
mp[121][5] = -1;
mp[121][6] = 589;
mp[121][7] = 285;
mp[121][8] = -1;
mp[121][9] = 76;
mp[122][0] = 59999999999999;
mp[122][1] = 39999989;
mp[122][2] = -1;
mp[122][3] = 5996;
mp[122][4] = 2987;
mp[122][5] = -1;
mp[122][6] = 485;
mp[122][7] = 284;
mp[122][8] = -1;
mp[122][9] = 77;
mp[123][0] = 69999999999999;
mp[123][1] = 8999998;
mp[123][2] = 69997;
mp[123][3] = 19989;
mp[123][4] = 3988;
mp[123][5] = 594;
mp[123][6] = 588;
mp[123][7] = 283;
mp[123][8] = -1;
mp[123][9] = 78;
mp[124][0] = 79999999999999;
mp[124][1] = 49999989;
mp[124][2] = -1;
mp[124][3] = 9988;
mp[124][4] = 4989;
mp[124][5] = -1;
mp[124][6] = 484;
mp[124][7] = 192;
mp[124][8] = -1;
mp[124][9] = 79;
mp[125][0] = 89999999999999;
mp[125][1] = 9999998;
mp[125][2] = -1;
mp[125][3] = 8987;
mp[125][4] = 995;
mp[125][5] = -1;
mp[125][6] = 587;
mp[125][7] = 389;
mp[125][8] = -1;
mp[125][9] = 80;
mp[126][0] = 99999999999999;
mp[126][1] = 59999989;
mp[126][2] = 79997;
mp[126][3] = 6996;
mp[126][4] = 2986;
mp[126][5] = 785;
mp[126][6] = 393;
mp[126][7] = 388;
mp[126][8] = 91;
mp[126][9] = 81;
mp[127][0] = 199999999999999;
mp[127][1] = 19999998;
mp[127][2] = -1;
mp[127][3] = 29989;
mp[127][4] = 3987;
mp[127][5] = -1;
mp[127][6] = 586;
mp[127][7] = 387;
mp[127][8] = -1;
mp[127][9] = 82;
mp[128][0] = 299999999999999;
mp[128][1] = 69999989;
mp[128][2] = -1;
mp[128][3] = 19988;
mp[128][4] = 4988;
mp[128][5] = -1;
mp[128][6] = 689;
mp[128][7] = 386;
mp[128][8] = -1;
mp[128][9] = 83;
mp[129][0] = 399999999999999;
mp[129][1] = 29999998;
mp[129][2] = 89997;
mp[129][3] = 9987;
mp[129][4] = 5989;
mp[129][5] = 694;
mp[129][6] = 585;
mp[129][7] = 385;
mp[129][8] = -1;
mp[129][9] = 84;
mp[130][0] = 499999999999999;
mp[130][1] = 79999989;
mp[130][2] = -1;
mp[130][3] = 7996;
mp[130][4] = 1995;
mp[130][5] = -1;
mp[130][6] = 688;
mp[130][7] = 384;
mp[130][8] = -1;
mp[130][9] = 85;
mp[131][0] = 599999999999999;
mp[131][1] = 39999998;
mp[131][2] = -1;
mp[131][3] = 39989;
mp[131][4] = 3986;
mp[131][5] = -1;
mp[131][6] = 584;
mp[131][7] = 383;
mp[131][8] = -1;
mp[131][9] = 86;
mp[132][0] = 699999999999999;
mp[132][1] = 89999989;
mp[132][2] = 99997;
mp[132][3] = 29988;
mp[132][4] = 4987;
mp[132][5] = 885;
mp[132][6] = 687;
mp[132][7] = 292;
mp[132][8] = -1;
mp[132][9] = 87;
mp[133][0] = 799999999999999;
mp[133][1] = 49999998;
mp[133][2] = -1;
mp[133][3] = 19987;
mp[133][4] = 5988;
mp[133][5] = -1;
mp[133][6] = 493;
mp[133][7] = 489;
mp[133][8] = -1;
mp[133][9] = 88;
mp[134][0] = 899999999999999;
mp[134][1] = 99999989;
mp[134][2] = -1;
mp[134][3] = 8996;
mp[134][4] = 6989;
mp[134][5] = -1;
mp[134][6] = 686;
mp[134][7] = 488;
mp[134][8] = -1;
mp[134][9] = 89;
mp[135][0] = 999999999999999;
mp[135][1] = 59999998;
mp[135][2] = 199997;
mp[135][3] = 49989;
mp[135][4] = 2995;
mp[135][5] = 794;
mp[135][6] = 789;
mp[135][7] = 487;
mp[135][8] = 191;
mp[135][9] = 90;
mp[136][0] = 1999999999999999;
mp[136][1] = 199999989;
mp[136][2] = -1;
mp[136][3] = 39988;
mp[136][4] = 4986;
mp[136][5] = -1;
mp[136][6] = 685;
mp[136][7] = 486;
mp[136][8] = -1;
mp[136][9] = 181;
mp[137][0] = 2999999999999999;
mp[137][1] = 69999998;
mp[137][2] = -1;
mp[137][3] = 29987;
mp[137][4] = 5987;
mp[137][5] = -1;
mp[137][6] = 788;
mp[137][7] = 485;
mp[137][8] = -1;
mp[137][9] = 182;
mp[138][0] = 3999999999999999;
mp[138][1] = 299999989;
mp[138][2] = 299997;
mp[138][3] = 9996;
mp[138][4] = 6988;
mp[138][5] = 985;
mp[138][6] = 684;
mp[138][7] = 484;
mp[138][8] = -1;
mp[138][9] = 183;
mp[139][0] = 4999999999999999;
mp[139][1] = 79999998;
mp[139][2] = -1;
mp[139][3] = 59989;
mp[139][4] = 7989;
mp[139][5] = -1;
mp[139][6] = 787;
mp[139][7] = 483;
mp[139][8] = -1;
mp[139][9] = 184;
mp[140][0] = 5999999999999999;
mp[140][1] = 399999989;
mp[140][2] = -1;
mp[140][3] = 49988;
mp[140][4] = 3995;
mp[140][5] = -1;
mp[140][6] = 593;
mp[140][7] = 392;
mp[140][8] = -1;
mp[140][9] = 185;
mp[141][0] = 6999999999999999;
mp[141][1] = 89999998;
mp[141][2] = 399997;
mp[141][3] = 39987;
mp[141][4] = 5986;
mp[141][5] = 894;
mp[141][6] = 786;
mp[141][7] = 589;
mp[141][8] = -1;
mp[141][9] = 186;
mp[142][0] = 7999999999999999;
mp[142][1] = 499999989;
mp[142][2] = -1;
mp[142][3] = 19996;
mp[142][4] = 6987;
mp[142][5] = -1;
mp[142][6] = 889;
mp[142][7] = 588;
mp[142][8] = -1;
mp[142][9] = 187;
mp[143][0] = 8999999999999999;
mp[143][1] = 99999998;
mp[143][2] = -1;
mp[143][3] = 69989;
mp[143][4] = 7988;
mp[143][5] = -1;
mp[143][6] = 785;
mp[143][7] = 587;
mp[143][8] = -1;
mp[143][9] = 188;
mp[144][0] = 9999999999999999;
mp[144][1] = 599999989;
mp[144][2] = 499997;
mp[144][3] = 59988;
mp[144][4] = 8989;
mp[144][5] = 1985;
mp[144][6] = 888;
mp[144][7] = 586;
mp[144][8] = 291;
mp[144][9] = 189;
mp[145][0] = 19999999999999999;
mp[145][1] = 199999998;
mp[145][2] = -1;
mp[145][3] = 49987;
mp[145][4] = 4995;
mp[145][5] = -1;
mp[145][6] = 784;
mp[145][7] = 585;
mp[145][8] = -1;
mp[145][9] = 190;
mp[146][0] = 29999999999999999;
mp[146][1] = 699999989;
mp[146][2] = -1;
mp[146][3] = 29996;
mp[146][4] = 6986;
mp[146][5] = -1;
mp[146][6] = 887;
mp[146][7] = 584;
mp[146][8] = -1;
mp[146][9] = 281;
mp[147][0] = 39999999999999999;
mp[147][1] = 299999998;
mp[147][2] = 599997;
mp[147][3] = 79989;
mp[147][4] = 7987;
mp[147][5] = 994;
mp[147][6] = 693;
mp[147][7] = 583;
mp[147][8] = -1;
mp[147][9] = 282;
mp[148][0] = 49999999999999999;
mp[148][1] = 799999989;
mp[148][2] = -1;
mp[148][3] = 69988;
mp[148][4] = 8988;
mp[148][5] = -1;
mp[148][6] = 886;
mp[148][7] = 492;
mp[148][8] = -1;
mp[148][9] = 283;
mp[149][0] = 59999999999999999;
mp[149][1] = 399999998;
mp[149][2] = -1;
mp[149][3] = 59987;
mp[149][4] = 9989;
mp[149][5] = -1;
mp[149][6] = 989;
mp[149][7] = 689;
mp[149][8] = -1;
mp[149][9] = 284;
mp[150][0] = 69999999999999999;
mp[150][1] = 899999989;
mp[150][2] = 699997;
mp[150][3] = 39996;
mp[150][4] = 5995;
mp[150][5] = 2985;
mp[150][6] = 885;
mp[150][7] = 688;
mp[150][8] = -1;
mp[150][9] = 285;

}
void solve() {
    ll n, k;
    cin >> n >> k;
    cout << mp[n][k] << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed << setprecision(15);
    

    

    ll t;
    if (id0)
        t = 1;
    else
        cin >> t;
    init();
    while (t-->0) {
        solve();
    }
}