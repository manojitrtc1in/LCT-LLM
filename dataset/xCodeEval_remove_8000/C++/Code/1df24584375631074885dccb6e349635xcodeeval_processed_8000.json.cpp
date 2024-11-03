

using namespace std;










 {cout << x[_i] << " ";} cout << endl;}








const long double PI = acos(-1);
const long double eps = 1e-9;
const long long inf = LLONG_MAX / 10;

void ECHO(string _s){cout<<_s;}
void ECHO(bool _s){if(_s)cout<<"true";else cout<<"false";}
void ECHO(char _s){cout<<_s;}
void ECHO(long unsigned _s) {cout<<_s;}

void ECHO(int _s){cout<<_s;}
void ECHO(long long _s){if(_s == inf)cout << "inf";else cout<<_s;}
void ECHO(double _s){cout<<_s;}
void ECHO(long double _s){cout<<_s;}
void ECHO(bitset<8> b) {cout << b;}

template<typename T> void ECHO(set<T> _s) {
    for(auto el : _s) {ECHO(el); cout << "_";}
}
template<typename T1, typename T2> void ECHO(map<T1, T2> _s) {
    for(auto el : _s) {ECHO(el); cout << "_";}
}
template<typename T1, typename T2> void ECHO(pair<T1, T2> _s) {
    cout << "("; ECHO(_s.fi); cout << ","; ECHO(_s.se); cout << ")";
}
template<typename T> void ECHO(vector<T> v) {
    for(auto el : v) {ECHO(el); cout << "_";}
}
template<typename T, typename ...Args> void ECHO(string _s, T x, Args... args){
    int _i, c = 0;
    for(_i = 0; _i < (int)_s.size(); _i++) {
        if(c==0 && _s[_i]==',') break;
        if(_s[_i] == '(') c++;
        if(_s[_i] == ')') c--;
    }
    cout << " (" << _s.substr(0, _i) << "): "; ECHO(x);
    while(_i < (int)_s.size() && (_s[_i] == ',' || _s[_i] == ' ')) _i++;
    ECHO(_s.substr(_i), args...);
} 

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll dp[151][10];

void FILL() {
dp[0][1]=-1;
dp[1][1]=0;
dp[2][1]=-1;
dp[3][1]=1;
dp[4][1]=-1;
dp[5][1]=2;
dp[6][1]=-1;
dp[7][1]=3;
dp[8][1]=-1;
dp[9][1]=4;
dp[10][1]=9;
dp[11][1]=5;
dp[12][1]=19;
dp[13][1]=6;
dp[14][1]=29;
dp[15][1]=7;
dp[16][1]=39;
dp[17][1]=8;
dp[18][1]=49;
dp[19][1]=18;
dp[20][1]=59;
dp[21][1]=28;
dp[22][1]=69;
dp[23][1]=38;
dp[24][1]=79;
dp[25][1]=48;
dp[26][1]=89;
dp[27][1]=58;
dp[28][1]=189;
dp[29][1]=68;
dp[30][1]=289;
dp[31][1]=78;
dp[32][1]=389;
dp[33][1]=88;
dp[34][1]=489;
dp[35][1]=98;
dp[36][1]=589;
dp[37][1]=198;
dp[38][1]=689;
dp[39][1]=298;
dp[40][1]=789;
dp[41][1]=398;
dp[42][1]=889;
dp[43][1]=498;
dp[44][1]=989;
dp[45][1]=598;
dp[46][1]=1989;
dp[47][1]=698;
dp[48][1]=2989;
dp[49][1]=798;
dp[50][1]=3989;
dp[51][1]=898;
dp[52][1]=4989;
dp[53][1]=998;
dp[54][1]=5989;
dp[55][1]=1998;
dp[56][1]=6989;
dp[57][1]=2998;
dp[58][1]=7989;
dp[59][1]=3998;
dp[60][1]=8989;
dp[61][1]=4998;
dp[62][1]=9989;
dp[63][1]=5998;
dp[64][1]=19989;
dp[65][1]=6998;
dp[66][1]=29989;
dp[67][1]=7998;
dp[68][1]=39989;
dp[69][1]=8998;
dp[70][1]=49989;
dp[71][1]=9998;
dp[72][1]=59989;
dp[73][1]=19998;
dp[74][1]=69989;
dp[75][1]=29998;
dp[76][1]=79989;
dp[77][1]=39998;
dp[78][1]=89989;
dp[79][1]=49998;
dp[80][1]=99989;
dp[81][1]=59998;
dp[82][1]=199989;
dp[83][1]=69998;
dp[84][1]=299989;
dp[85][1]=79998;
dp[86][1]=399989;
dp[87][1]=89998;
dp[88][1]=499989;
dp[89][1]=99998;
dp[90][1]=599989;
dp[91][1]=199998;
dp[92][1]=699989;
dp[93][1]=299998;
dp[94][1]=799989;
dp[95][1]=399998;
dp[96][1]=899989;
dp[97][1]=499998;
dp[98][1]=999989;
dp[99][1]=599998;
dp[100][1]=1999989;
dp[101][1]=699998;
dp[102][1]=2999989;
dp[103][1]=799998;
dp[104][1]=3999989;
dp[105][1]=899998;
dp[106][1]=4999989;
dp[107][1]=999998;
dp[108][1]=5999989;
dp[109][1]=1999998;
dp[110][1]=6999989;
dp[111][1]=2999998;
dp[112][1]=7999989;
dp[113][1]=3999998;
dp[114][1]=8999989;
dp[115][1]=4999998;
dp[116][1]=9999989;
dp[117][1]=5999998;
dp[118][1]=19999989;
dp[119][1]=6999998;
dp[120][1]=29999989;
dp[121][1]=7999998;
dp[122][1]=39999989;
dp[123][1]=8999998;
dp[124][1]=49999989;
dp[125][1]=9999998;
dp[126][1]=59999989;
dp[127][1]=19999998;
dp[128][1]=69999989;
dp[129][1]=29999998;
dp[130][1]=79999989;
dp[131][1]=39999998;
dp[132][1]=89999989;
dp[133][1]=49999998;
dp[134][1]=99999989;
dp[135][1]=59999998;
dp[136][1]=199999989;
dp[137][1]=69999998;
dp[138][1]=299999989;
dp[139][1]=79999998;
dp[140][1]=399999989;
dp[141][1]=89999998;
dp[142][1]=499999989;
dp[143][1]=99999998;
dp[144][1]=599999989;
dp[145][1]=199999998;
dp[146][1]=699999989;
dp[147][1]=299999998;
dp[148][1]=799999989;
dp[149][1]=399999998;
dp[150][1]=899999989;
dp[0][2]=-1;
dp[1][2]=-1;
dp[2][2]=-1;
dp[3][2]=0;
dp[4][2]=-1;
dp[5][2]=-1;
dp[6][2]=1;
dp[7][2]=-1;
dp[8][2]=-1;
dp[9][2]=2;
dp[10][2]=-1;
dp[11][2]=-1;
dp[12][2]=3;
dp[13][2]=-1;
dp[14][2]=-1;
dp[15][2]=4;
dp[16][2]=-1;
dp[17][2]=-1;
dp[18][2]=5;
dp[19][2]=-1;
dp[20][2]=-1;
dp[21][2]=6;
dp[22][2]=-1;
dp[23][2]=-1;
dp[24][2]=7;
dp[25][2]=-1;
dp[26][2]=-1;
dp[27][2]=17;
dp[28][2]=-1;
dp[29][2]=-1;
dp[30][2]=27;
dp[31][2]=-1;
dp[32][2]=-1;
dp[33][2]=37;
dp[34][2]=-1;
dp[35][2]=-1;
dp[36][2]=47;
dp[37][2]=-1;
dp[38][2]=-1;
dp[39][2]=57;
dp[40][2]=-1;
dp[41][2]=-1;
dp[42][2]=67;
dp[43][2]=-1;
dp[44][2]=-1;
dp[45][2]=77;
dp[46][2]=-1;
dp[47][2]=-1;
dp[48][2]=87;
dp[49][2]=-1;
dp[50][2]=-1;
dp[51][2]=97;
dp[52][2]=-1;
dp[53][2]=-1;
dp[54][2]=197;
dp[55][2]=-1;
dp[56][2]=-1;
dp[57][2]=297;
dp[58][2]=-1;
dp[59][2]=-1;
dp[60][2]=397;
dp[61][2]=-1;
dp[62][2]=-1;
dp[63][2]=497;
dp[64][2]=-1;
dp[65][2]=-1;
dp[66][2]=597;
dp[67][2]=-1;
dp[68][2]=-1;
dp[69][2]=697;
dp[70][2]=-1;
dp[71][2]=-1;
dp[72][2]=797;
dp[73][2]=-1;
dp[74][2]=-1;
dp[75][2]=897;
dp[76][2]=-1;
dp[77][2]=-1;
dp[78][2]=997;
dp[79][2]=-1;
dp[80][2]=-1;
dp[81][2]=1997;
dp[82][2]=-1;
dp[83][2]=-1;
dp[84][2]=2997;
dp[85][2]=-1;
dp[86][2]=-1;
dp[87][2]=3997;
dp[88][2]=-1;
dp[89][2]=-1;
dp[90][2]=4997;
dp[91][2]=-1;
dp[92][2]=-1;
dp[93][2]=5997;
dp[94][2]=-1;
dp[95][2]=-1;
dp[96][2]=6997;
dp[97][2]=-1;
dp[98][2]=-1;
dp[99][2]=7997;
dp[100][2]=-1;
dp[101][2]=-1;
dp[102][2]=8997;
dp[103][2]=-1;
dp[104][2]=-1;
dp[105][2]=9997;
dp[106][2]=-1;
dp[107][2]=-1;
dp[108][2]=19997;
dp[109][2]=-1;
dp[110][2]=-1;
dp[111][2]=29997;
dp[112][2]=-1;
dp[113][2]=-1;
dp[114][2]=39997;
dp[115][2]=-1;
dp[116][2]=-1;
dp[117][2]=49997;
dp[118][2]=-1;
dp[119][2]=-1;
dp[120][2]=59997;
dp[121][2]=-1;
dp[122][2]=-1;
dp[123][2]=69997;
dp[124][2]=-1;
dp[125][2]=-1;
dp[126][2]=79997;
dp[127][2]=-1;
dp[128][2]=-1;
dp[129][2]=89997;
dp[130][2]=-1;
dp[131][2]=-1;
dp[132][2]=99997;
dp[133][2]=-1;
dp[134][2]=-1;
dp[135][2]=199997;
dp[136][2]=-1;
dp[137][2]=-1;
dp[138][2]=299997;
dp[139][2]=-1;
dp[140][2]=-1;
dp[141][2]=399997;
dp[142][2]=-1;
dp[143][2]=-1;
dp[144][2]=499997;
dp[145][2]=-1;
dp[146][2]=-1;
dp[147][2]=599997;
dp[148][2]=-1;
dp[149][2]=-1;
dp[150][2]=699997;
dp[0][3]=-1;
dp[1][3]=-1;
dp[2][3]=-1;
dp[3][3]=-1;
dp[4][3]=-1;
dp[5][3]=-1;
dp[6][3]=0;
dp[7][3]=-1;
dp[8][3]=-1;
dp[9][3]=-1;
dp[10][3]=1;
dp[11][3]=-1;
dp[12][3]=-1;
dp[13][3]=-1;
dp[14][3]=2;
dp[15][3]=9;
dp[16][3]=-1;
dp[17][3]=-1;
dp[18][3]=3;
dp[19][3]=19;
dp[20][3]=8;
dp[21][3]=-1;
dp[22][3]=4;
dp[23][3]=29;
dp[24][3]=18;
dp[25][3]=7;
dp[26][3]=5;
dp[27][3]=39;
dp[28][3]=28;
dp[29][3]=17;
dp[30][3]=6;
dp[31][3]=49;
dp[32][3]=38;
dp[33][3]=27;
dp[34][3]=16;
dp[35][3]=59;
dp[36][3]=48;
dp[37][3]=37;
dp[38][3]=26;
dp[39][3]=69;
dp[40][3]=58;
dp[41][3]=47;
dp[42][3]=36;
dp[43][3]=79;
dp[44][3]=68;
dp[45][3]=57;
dp[46][3]=46;
dp[47][3]=89;
dp[48][3]=78;
dp[49][3]=67;
dp[50][3]=56;
dp[51][3]=189;
dp[52][3]=88;
dp[53][3]=77;
dp[54][3]=66;
dp[55][3]=289;
dp[56][3]=188;
dp[57][3]=87;
dp[58][3]=76;
dp[59][3]=389;
dp[60][3]=288;
dp[61][3]=187;
dp[62][3]=86;
dp[63][3]=489;
dp[64][3]=388;
dp[65][3]=287;
dp[66][3]=96;
dp[67][3]=589;
dp[68][3]=488;
dp[69][3]=387;
dp[70][3]=196;
dp[71][3]=689;
dp[72][3]=588;
dp[73][3]=487;
dp[74][3]=296;
dp[75][3]=789;
dp[76][3]=688;
dp[77][3]=587;
dp[78][3]=396;
dp[79][3]=889;
dp[80][3]=788;
dp[81][3]=687;
dp[82][3]=496;
dp[83][3]=989;
dp[84][3]=888;
dp[85][3]=787;
dp[86][3]=596;
dp[87][3]=1989;
dp[88][3]=988;
dp[89][3]=887;
dp[90][3]=696;
dp[91][3]=2989;
dp[92][3]=1988;
dp[93][3]=987;
dp[94][3]=796;
dp[95][3]=3989;
dp[96][3]=2988;
dp[97][3]=1987;
dp[98][3]=896;
dp[99][3]=4989;
dp[100][3]=3988;
dp[101][3]=2987;
dp[102][3]=996;
dp[103][3]=5989;
dp[104][3]=4988;
dp[105][3]=3987;
dp[106][3]=1996;
dp[107][3]=6989;
dp[108][3]=5988;
dp[109][3]=4987;
dp[110][3]=2996;
dp[111][3]=7989;
dp[112][3]=6988;
dp[113][3]=5987;
dp[114][3]=3996;
dp[115][3]=8989;
dp[116][3]=7988;
dp[117][3]=6987;
dp[118][3]=4996;
dp[119][3]=9989;
dp[120][3]=8988;
dp[121][3]=7987;
dp[122][3]=5996;
dp[123][3]=19989;
dp[124][3]=9988;
dp[125][3]=8987;
dp[126][3]=6996;
dp[127][3]=29989;
dp[128][3]=19988;
dp[129][3]=9987;
dp[130][3]=7996;
dp[131][3]=39989;
dp[132][3]=29988;
dp[133][3]=19987;
dp[134][3]=8996;
dp[135][3]=49989;
dp[136][3]=39988;
dp[137][3]=29987;
dp[138][3]=9996;
dp[139][3]=59989;
dp[140][3]=49988;
dp[141][3]=39987;
dp[142][3]=19996;
dp[143][3]=69989;
dp[144][3]=59988;
dp[145][3]=49987;
dp[146][3]=29996;
dp[147][3]=79989;
dp[148][3]=69988;
dp[149][3]=59987;
dp[150][3]=39996;
dp[0][4]=-1;
dp[1][4]=-1;
dp[2][4]=-1;
dp[3][4]=-1;
dp[4][4]=-1;
dp[5][4]=-1;
dp[6][4]=-1;
dp[7][4]=-1;
dp[8][4]=-1;
dp[9][4]=-1;
dp[10][4]=0;
dp[11][4]=-1;
dp[12][4]=-1;
dp[13][4]=-1;
dp[14][4]=-1;
dp[15][4]=1;
dp[16][4]=-1;
dp[17][4]=-1;
dp[18][4]=-1;
dp[19][4]=9;
dp[20][4]=2;
dp[21][4]=-1;
dp[22][4]=-1;
dp[23][4]=8;
dp[24][4]=19;
dp[25][4]=3;
dp[26][4]=-1;
dp[27][4]=7;
dp[28][4]=18;
dp[29][4]=29;
dp[30][4]=4;
dp[31][4]=6;
dp[32][4]=17;
dp[33][4]=28;
dp[34][4]=39;
dp[35][4]=5;
dp[36][4]=16;
dp[37][4]=27;
dp[38][4]=38;
dp[39][4]=49;
dp[40][4]=15;
dp[41][4]=26;
dp[42][4]=37;
dp[43][4]=48;
dp[44][4]=59;
dp[45][4]=25;
dp[46][4]=36;
dp[47][4]=47;
dp[48][4]=58;
dp[49][4]=69;
dp[50][4]=35;
dp[51][4]=46;
dp[52][4]=57;
dp[53][4]=68;
dp[54][4]=79;
dp[55][4]=45;
dp[56][4]=56;
dp[57][4]=67;
dp[58][4]=78;
dp[59][4]=89;
dp[60][4]=55;
dp[61][4]=66;
dp[62][4]=77;
dp[63][4]=88;
dp[64][4]=189;
dp[65][4]=65;
dp[66][4]=76;
dp[67][4]=87;
dp[68][4]=188;
dp[69][4]=289;
dp[70][4]=75;
dp[71][4]=86;
dp[72][4]=187;
dp[73][4]=288;
dp[74][4]=389;
dp[75][4]=85;
dp[76][4]=186;
dp[77][4]=287;
dp[78][4]=388;
dp[79][4]=489;
dp[80][4]=95;
dp[81][4]=286;
dp[82][4]=387;
dp[83][4]=488;
dp[84][4]=589;
dp[85][4]=195;
dp[86][4]=386;
dp[87][4]=487;
dp[88][4]=588;
dp[89][4]=689;
dp[90][4]=295;
dp[91][4]=486;
dp[92][4]=587;
dp[93][4]=688;
dp[94][4]=789;
dp[95][4]=395;
dp[96][4]=586;
dp[97][4]=687;
dp[98][4]=788;
dp[99][4]=889;
dp[100][4]=495;
dp[101][4]=686;
dp[102][4]=787;
dp[103][4]=888;
dp[104][4]=989;
dp[105][4]=595;
dp[106][4]=786;
dp[107][4]=887;
dp[108][4]=988;
dp[109][4]=1989;
dp[110][4]=695;
dp[111][4]=886;
dp[112][4]=987;
dp[113][4]=1988;
dp[114][4]=2989;
dp[115][4]=795;
dp[116][4]=986;
dp[117][4]=1987;
dp[118][4]=2988;
dp[119][4]=3989;
dp[120][4]=895;
dp[121][4]=1986;
dp[122][4]=2987;
dp[123][4]=3988;
dp[124][4]=4989;
dp[125][4]=995;
dp[126][4]=2986;
dp[127][4]=3987;
dp[128][4]=4988;
dp[129][4]=5989;
dp[130][4]=1995;
dp[131][4]=3986;
dp[132][4]=4987;
dp[133][4]=5988;
dp[134][4]=6989;
dp[135][4]=2995;
dp[136][4]=4986;
dp[137][4]=5987;
dp[138][4]=6988;
dp[139][4]=7989;
dp[140][4]=3995;
dp[141][4]=5986;
dp[142][4]=6987;
dp[143][4]=7988;
dp[144][4]=8989;
dp[145][4]=4995;
dp[146][4]=6986;
dp[147][4]=7987;
dp[148][4]=8988;
dp[149][4]=9989;
dp[150][4]=5995;
dp[0][5]=-1;
dp[1][5]=-1;
dp[2][5]=-1;
dp[3][5]=-1;
dp[4][5]=-1;
dp[5][5]=-1;
dp[6][5]=-1;
dp[7][5]=-1;
dp[8][5]=-1;
dp[9][5]=-1;
dp[10][5]=-1;
dp[11][5]=-1;
dp[12][5]=-1;
dp[13][5]=-1;
dp[14][5]=-1;
dp[15][5]=0;
dp[16][5]=-1;
dp[17][5]=-1;
dp[18][5]=-1;
dp[19][5]=-1;
dp[20][5]=-1;
dp[21][5]=1;
dp[22][5]=-1;
dp[23][5]=-1;
dp[24][5]=9;
dp[25][5]=-1;
dp[26][5]=-1;
dp[27][5]=2;
dp[28][5]=-1;
dp[29][5]=-1;
dp[30][5]=7;
dp[31][5]=-1;
dp[32][5]=-1;
dp[33][5]=3;
dp[34][5]=-1;
dp[35][5]=-1;
dp[36][5]=5;
dp[37][5]=-1;
dp[38][5]=-1;
dp[39][5]=4;
dp[40][5]=-1;
dp[41][5]=-1;
dp[42][5]=15;
dp[43][5]=-1;
dp[44][5]=-1;
dp[45][5]=14;
dp[46][5]=-1;
dp[47][5]=-1;
dp[48][5]=25;
dp[49][5]=-1;
dp[50][5]=-1;
dp[51][5]=24;
dp[52][5]=-1;
dp[53][5]=-1;
dp[54][5]=35;
dp[55][5]=-1;
dp[56][5]=-1;
dp[57][5]=34;
dp[58][5]=-1;
dp[59][5]=-1;
dp[60][5]=45;
dp[61][5]=-1;
dp[62][5]=-1;
dp[63][5]=44;
dp[64][5]=-1;
dp[65][5]=-1;
dp[66][5]=55;
dp[67][5]=-1;
dp[68][5]=-1;
dp[69][5]=54;
dp[70][5]=-1;
dp[71][5]=-1;
dp[72][5]=65;
dp[73][5]=-1;
dp[74][5]=-1;
dp[75][5]=64;
dp[76][5]=-1;
dp[77][5]=-1;
dp[78][5]=75;
dp[79][5]=-1;
dp[80][5]=-1;
dp[81][5]=74;
dp[82][5]=-1;
dp[83][5]=-1;
dp[84][5]=85;
dp[85][5]=-1;
dp[86][5]=-1;
dp[87][5]=84;
dp[88][5]=-1;
dp[89][5]=-1;
dp[90][5]=185;
dp[91][5]=-1;
dp[92][5]=-1;
dp[93][5]=94;
dp[94][5]=-1;
dp[95][5]=-1;
dp[96][5]=285;
dp[97][5]=-1;
dp[98][5]=-1;
dp[99][5]=194;
dp[100][5]=-1;
dp[101][5]=-1;
dp[102][5]=385;
dp[103][5]=-1;
dp[104][5]=-1;
dp[105][5]=294;
dp[106][5]=-1;
dp[107][5]=-1;
dp[108][5]=485;
dp[109][5]=-1;
dp[110][5]=-1;
dp[111][5]=394;
dp[112][5]=-1;
dp[113][5]=-1;
dp[114][5]=585;
dp[115][5]=-1;
dp[116][5]=-1;
dp[117][5]=494;
dp[118][5]=-1;
dp[119][5]=-1;
dp[120][5]=685;
dp[121][5]=-1;
dp[122][5]=-1;
dp[123][5]=594;
dp[124][5]=-1;
dp[125][5]=-1;
dp[126][5]=785;
dp[127][5]=-1;
dp[128][5]=-1;
dp[129][5]=694;
dp[130][5]=-1;
dp[131][5]=-1;
dp[132][5]=885;
dp[133][5]=-1;
dp[134][5]=-1;
dp[135][5]=794;
dp[136][5]=-1;
dp[137][5]=-1;
dp[138][5]=985;
dp[139][5]=-1;
dp[140][5]=-1;
dp[141][5]=894;
dp[142][5]=-1;
dp[143][5]=-1;
dp[144][5]=1985;
dp[145][5]=-1;
dp[146][5]=-1;
dp[147][5]=994;
dp[148][5]=-1;
dp[149][5]=-1;
dp[150][5]=2985;
dp[0][6]=-1;
dp[1][6]=-1;
dp[2][6]=-1;
dp[3][6]=-1;
dp[4][6]=-1;
dp[5][6]=-1;
dp[6][6]=-1;
dp[7][6]=-1;
dp[8][6]=-1;
dp[9][6]=-1;
dp[10][6]=-1;
dp[11][6]=-1;
dp[12][6]=-1;
dp[13][6]=-1;
dp[14][6]=-1;
dp[15][6]=-1;
dp[16][6]=-1;
dp[17][6]=-1;
dp[18][6]=-1;
dp[19][6]=-1;
dp[20][6]=-1;
dp[21][6]=0;
dp[22][6]=-1;
dp[23][6]=-1;
dp[24][6]=-1;
dp[25][6]=-1;
dp[26][6]=-1;
dp[27][6]=-1;
dp[28][6]=1;
dp[29][6]=-1;
dp[30][6]=9;
dp[31][6]=-1;
dp[32][6]=8;
dp[33][6]=-1;
dp[34][6]=7;
dp[35][6]=2;
dp[36][6]=6;
dp[37][6]=19;
dp[38][6]=5;
dp[39][6]=18;
dp[40][6]=4;
dp[41][6]=17;
dp[42][6]=3;
dp[43][6]=16;
dp[44][6]=29;
dp[45][6]=15;
dp[46][6]=28;
dp[47][6]=14;
dp[48][6]=27;
dp[49][6]=13;
dp[50][6]=26;
dp[51][6]=39;
dp[52][6]=25;
dp[53][6]=38;
dp[54][6]=24;
dp[55][6]=37;
dp[56][6]=23;
dp[57][6]=36;
dp[58][6]=49;
dp[59][6]=35;
dp[60][6]=48;
dp[61][6]=34;
dp[62][6]=47;
dp[63][6]=33;
dp[64][6]=46;
dp[65][6]=59;
dp[66][6]=45;
dp[67][6]=58;
dp[68][6]=44;
dp[69][6]=57;
dp[70][6]=43;
dp[71][6]=56;
dp[72][6]=69;
dp[73][6]=55;
dp[74][6]=68;
dp[75][6]=54;
dp[76][6]=67;
dp[77][6]=53;
dp[78][6]=66;
dp[79][6]=79;
dp[80][6]=65;
dp[81][6]=78;
dp[82][6]=64;
dp[83][6]=77;
dp[84][6]=63;
dp[85][6]=76;
dp[86][6]=89;
dp[87][6]=75;
dp[88][6]=88;
dp[89][6]=74;
dp[90][6]=87;
dp[91][6]=73;
dp[92][6]=86;
dp[93][6]=189;
dp[94][6]=85;
dp[95][6]=188;
dp[96][6]=84;
dp[97][6]=187;
dp[98][6]=83;
dp[99][6]=186;
dp[100][6]=289;
dp[101][6]=185;
dp[102][6]=288;
dp[103][6]=184;
dp[104][6]=287;
dp[105][6]=93;
dp[106][6]=286;
dp[107][6]=389;
dp[108][6]=285;
dp[109][6]=388;
dp[110][6]=284;
dp[111][6]=387;
dp[112][6]=193;
dp[113][6]=386;
dp[114][6]=489;
dp[115][6]=385;
dp[116][6]=488;
dp[117][6]=384;
dp[118][6]=487;
dp[119][6]=293;
dp[120][6]=486;
dp[121][6]=589;
dp[122][6]=485;
dp[123][6]=588;
dp[124][6]=484;
dp[125][6]=587;
dp[126][6]=393;
dp[127][6]=586;
dp[128][6]=689;
dp[129][6]=585;
dp[130][6]=688;
dp[131][6]=584;
dp[132][6]=687;
dp[133][6]=493;
dp[134][6]=686;
dp[135][6]=789;
dp[136][6]=685;
dp[137][6]=788;
dp[138][6]=684;
dp[139][6]=787;
dp[140][6]=593;
dp[141][6]=786;
dp[142][6]=889;
dp[143][6]=785;
dp[144][6]=888;
dp[145][6]=784;
dp[146][6]=887;
dp[147][6]=693;
dp[148][6]=886;
dp[149][6]=989;
dp[150][6]=885;
dp[0][7]=-1;
dp[1][7]=-1;
dp[2][7]=-1;
dp[3][7]=-1;
dp[4][7]=-1;
dp[5][7]=-1;
dp[6][7]=-1;
dp[7][7]=-1;
dp[8][7]=-1;
dp[9][7]=-1;
dp[10][7]=-1;
dp[11][7]=-1;
dp[12][7]=-1;
dp[13][7]=-1;
dp[14][7]=-1;
dp[15][7]=-1;
dp[16][7]=-1;
dp[17][7]=-1;
dp[18][7]=-1;
dp[19][7]=-1;
dp[20][7]=-1;
dp[21][7]=-1;
dp[22][7]=-1;
dp[23][7]=-1;
dp[24][7]=-1;
dp[25][7]=-1;
dp[26][7]=-1;
dp[27][7]=-1;
dp[28][7]=0;
dp[29][7]=-1;
dp[30][7]=-1;
dp[31][7]=-1;
dp[32][7]=-1;
dp[33][7]=-1;
dp[34][7]=-1;
dp[35][7]=-1;
dp[36][7]=1;
dp[37][7]=9;
dp[38][7]=8;
dp[39][7]=7;
dp[40][7]=6;
dp[41][7]=5;
dp[42][7]=4;
dp[43][7]=3;
dp[44][7]=2;
dp[45][7]=19;
dp[46][7]=18;
dp[47][7]=17;
dp[48][7]=16;
dp[49][7]=15;
dp[50][7]=14;
dp[51][7]=13;
dp[52][7]=12;
dp[53][7]=29;
dp[54][7]=28;
dp[55][7]=27;
dp[56][7]=26;
dp[57][7]=25;
dp[58][7]=24;
dp[59][7]=23;
dp[60][7]=22;
dp[61][7]=39;
dp[62][7]=38;
dp[63][7]=37;
dp[64][7]=36;
dp[65][7]=35;
dp[66][7]=34;
dp[67][7]=33;
dp[68][7]=32;
dp[69][7]=49;
dp[70][7]=48;
dp[71][7]=47;
dp[72][7]=46;
dp[73][7]=45;
dp[74][7]=44;
dp[75][7]=43;
dp[76][7]=42;
dp[77][7]=59;
dp[78][7]=58;
dp[79][7]=57;
dp[80][7]=56;
dp[81][7]=55;
dp[82][7]=54;
dp[83][7]=53;
dp[84][7]=52;
dp[85][7]=69;
dp[86][7]=68;
dp[87][7]=67;
dp[88][7]=66;
dp[89][7]=65;
dp[90][7]=64;
dp[91][7]=63;
dp[92][7]=62;
dp[93][7]=79;
dp[94][7]=78;
dp[95][7]=77;
dp[96][7]=76;
dp[97][7]=75;
dp[98][7]=74;
dp[99][7]=73;
dp[100][7]=72;
dp[101][7]=89;
dp[102][7]=88;
dp[103][7]=87;
dp[104][7]=86;
dp[105][7]=85;
dp[106][7]=84;
dp[107][7]=83;
dp[108][7]=82;
dp[109][7]=189;
dp[110][7]=188;
dp[111][7]=187;
dp[112][7]=186;
dp[113][7]=185;
dp[114][7]=184;
dp[115][7]=183;
dp[116][7]=92;
dp[117][7]=289;
dp[118][7]=288;
dp[119][7]=287;
dp[120][7]=286;
dp[121][7]=285;
dp[122][7]=284;
dp[123][7]=283;
dp[124][7]=192;
dp[125][7]=389;
dp[126][7]=388;
dp[127][7]=387;
dp[128][7]=386;
dp[129][7]=385;
dp[130][7]=384;
dp[131][7]=383;
dp[132][7]=292;
dp[133][7]=489;
dp[134][7]=488;
dp[135][7]=487;
dp[136][7]=486;
dp[137][7]=485;
dp[138][7]=484;
dp[139][7]=483;
dp[140][7]=392;
dp[141][7]=589;
dp[142][7]=588;
dp[143][7]=587;
dp[144][7]=586;
dp[145][7]=585;
dp[146][7]=584;
dp[147][7]=583;
dp[148][7]=492;
dp[149][7]=689;
dp[150][7]=688;
dp[0][8]=-1;
dp[1][8]=-1;
dp[2][8]=-1;
dp[3][8]=-1;
dp[4][8]=-1;
dp[5][8]=-1;
dp[6][8]=-1;
dp[7][8]=-1;
dp[8][8]=-1;
dp[9][8]=-1;
dp[10][8]=-1;
dp[11][8]=-1;
dp[12][8]=-1;
dp[13][8]=-1;
dp[14][8]=-1;
dp[15][8]=-1;
dp[16][8]=-1;
dp[17][8]=-1;
dp[18][8]=-1;
dp[19][8]=-1;
dp[20][8]=-1;
dp[21][8]=-1;
dp[22][8]=-1;
dp[23][8]=-1;
dp[24][8]=-1;
dp[25][8]=-1;
dp[26][8]=-1;
dp[27][8]=-1;
dp[28][8]=-1;
dp[29][8]=-1;
dp[30][8]=-1;
dp[31][8]=-1;
dp[32][8]=-1;
dp[33][8]=-1;
dp[34][8]=-1;
dp[35][8]=-1;
dp[36][8]=0;
dp[37][8]=-1;
dp[38][8]=-1;
dp[39][8]=-1;
dp[40][8]=-1;
dp[41][8]=-1;
dp[42][8]=-1;
dp[43][8]=-1;
dp[44][8]=-1;
dp[45][8]=1;
dp[46][8]=-1;
dp[47][8]=-1;
dp[48][8]=-1;
dp[49][8]=-1;
dp[50][8]=-1;
dp[51][8]=-1;
dp[52][8]=-1;
dp[53][8]=-1;
dp[54][8]=11;
dp[55][8]=-1;
dp[56][8]=-1;
dp[57][8]=-1;
dp[58][8]=-1;
dp[59][8]=-1;
dp[60][8]=-1;
dp[61][8]=-1;
dp[62][8]=-1;
dp[63][8]=21;
dp[64][8]=-1;
dp[65][8]=-1;
dp[66][8]=-1;
dp[67][8]=-1;
dp[68][8]=-1;
dp[69][8]=-1;
dp[70][8]=-1;
dp[71][8]=-1;
dp[72][8]=31;
dp[73][8]=-1;
dp[74][8]=-1;
dp[75][8]=-1;
dp[76][8]=-1;
dp[77][8]=-1;
dp[78][8]=-1;
dp[79][8]=-1;
dp[80][8]=-1;
dp[81][8]=41;
dp[82][8]=-1;
dp[83][8]=-1;
dp[84][8]=-1;
dp[85][8]=-1;
dp[86][8]=-1;
dp[87][8]=-1;
dp[88][8]=-1;
dp[89][8]=-1;
dp[90][8]=51;
dp[91][8]=-1;
dp[92][8]=-1;
dp[93][8]=-1;
dp[94][8]=-1;
dp[95][8]=-1;
dp[96][8]=-1;
dp[97][8]=-1;
dp[98][8]=-1;
dp[99][8]=61;
dp[100][8]=-1;
dp[101][8]=-1;
dp[102][8]=-1;
dp[103][8]=-1;
dp[104][8]=-1;
dp[105][8]=-1;
dp[106][8]=-1;
dp[107][8]=-1;
dp[108][8]=71;
dp[109][8]=-1;
dp[110][8]=-1;
dp[111][8]=-1;
dp[112][8]=-1;
dp[113][8]=-1;
dp[114][8]=-1;
dp[115][8]=-1;
dp[116][8]=-1;
dp[117][8]=81;
dp[118][8]=-1;
dp[119][8]=-1;
dp[120][8]=-1;
dp[121][8]=-1;
dp[122][8]=-1;
dp[123][8]=-1;
dp[124][8]=-1;
dp[125][8]=-1;
dp[126][8]=91;
dp[127][8]=-1;
dp[128][8]=-1;
dp[129][8]=-1;
dp[130][8]=-1;
dp[131][8]=-1;
dp[132][8]=-1;
dp[133][8]=-1;
dp[134][8]=-1;
dp[135][8]=191;
dp[136][8]=-1;
dp[137][8]=-1;
dp[138][8]=-1;
dp[139][8]=-1;
dp[140][8]=-1;
dp[141][8]=-1;
dp[142][8]=-1;
dp[143][8]=-1;
dp[144][8]=291;
dp[145][8]=-1;
dp[146][8]=-1;
dp[147][8]=-1;
dp[148][8]=-1;
dp[149][8]=-1;
dp[150][8]=-1;
dp[0][9]=-1;
dp[1][9]=-1;
dp[2][9]=-1;
dp[3][9]=-1;
dp[4][9]=-1;
dp[5][9]=-1;
dp[6][9]=-1;
dp[7][9]=-1;
dp[8][9]=-1;
dp[9][9]=-1;
dp[10][9]=-1;
dp[11][9]=-1;
dp[12][9]=-1;
dp[13][9]=-1;
dp[14][9]=-1;
dp[15][9]=-1;
dp[16][9]=-1;
dp[17][9]=-1;
dp[18][9]=-1;
dp[19][9]=-1;
dp[20][9]=-1;
dp[21][9]=-1;
dp[22][9]=-1;
dp[23][9]=-1;
dp[24][9]=-1;
dp[25][9]=-1;
dp[26][9]=-1;
dp[27][9]=-1;
dp[28][9]=-1;
dp[29][9]=-1;
dp[30][9]=-1;
dp[31][9]=-1;
dp[32][9]=-1;
dp[33][9]=-1;
dp[34][9]=-1;
dp[35][9]=-1;
dp[36][9]=-1;
dp[37][9]=-1;
dp[38][9]=-1;
dp[39][9]=-1;
dp[40][9]=-1;
dp[41][9]=-1;
dp[42][9]=-1;
dp[43][9]=-1;
dp[44][9]=-1;
dp[45][9]=0;
dp[46][9]=1;
dp[47][9]=2;
dp[48][9]=3;
dp[49][9]=4;
dp[50][9]=5;
dp[51][9]=6;
dp[52][9]=7;
dp[53][9]=8;
dp[54][9]=9;
dp[55][9]=10;
dp[56][9]=11;
dp[57][9]=12;
dp[58][9]=13;
dp[59][9]=14;
dp[60][9]=15;
dp[61][9]=16;
dp[62][9]=17;
dp[63][9]=18;
dp[64][9]=19;
dp[65][9]=20;
dp[66][9]=21;
dp[67][9]=22;
dp[68][9]=23;
dp[69][9]=24;
dp[70][9]=25;
dp[71][9]=26;
dp[72][9]=27;
dp[73][9]=28;
dp[74][9]=29;
dp[75][9]=30;
dp[76][9]=31;
dp[77][9]=32;
dp[78][9]=33;
dp[79][9]=34;
dp[80][9]=35;
dp[81][9]=36;
dp[82][9]=37;
dp[83][9]=38;
dp[84][9]=39;
dp[85][9]=40;
dp[86][9]=41;
dp[87][9]=42;
dp[88][9]=43;
dp[89][9]=44;
dp[90][9]=45;
dp[91][9]=46;
dp[92][9]=47;
dp[93][9]=48;
dp[94][9]=49;
dp[95][9]=50;
dp[96][9]=51;
dp[97][9]=52;
dp[98][9]=53;
dp[99][9]=54;
dp[100][9]=55;
dp[101][9]=56;
dp[102][9]=57;
dp[103][9]=58;
dp[104][9]=59;
dp[105][9]=60;
dp[106][9]=61;
dp[107][9]=62;
dp[108][9]=63;
dp[109][9]=64;
dp[110][9]=65;
dp[111][9]=66;
dp[112][9]=67;
dp[113][9]=68;
dp[114][9]=69;
dp[115][9]=70;
dp[116][9]=71;
dp[117][9]=72;
dp[118][9]=73;
dp[119][9]=74;
dp[120][9]=75;
dp[121][9]=76;
dp[122][9]=77;
dp[123][9]=78;
dp[124][9]=79;
dp[125][9]=80;
dp[126][9]=81;
dp[127][9]=82;
dp[128][9]=83;
dp[129][9]=84;
dp[130][9]=85;
dp[131][9]=86;
dp[132][9]=87;
dp[133][9]=88;
dp[134][9]=89;
dp[135][9]=90;
dp[136][9]=181;
dp[137][9]=182;
dp[138][9]=183;
dp[139][9]=184;
dp[140][9]=185;
dp[141][9]=186;
dp[142][9]=187;
dp[143][9]=188;
dp[144][9]=189;
dp[145][9]=190;
dp[146][9]=281;
dp[147][9]=282;
dp[148][9]=283;
dp[149][9]=284;
dp[150][9]=285;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    ll n, k, tt;
    FILL();
    cin >> tt;
    while(tt--) {
        cin >> n >> k;

        if(k == 0) {
            if(n%9) cout << (n%9);
            cout << string(n/9, '9') << "\n";
            continue;
        }
        cout << dp[n][k] << "\n";
    }

    return 0;
}