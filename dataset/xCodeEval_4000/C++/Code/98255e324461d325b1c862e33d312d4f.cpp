#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
 
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <sstream>
#include <deque>
#include <queue>
#include <random>
#include <complex>
#include <cassert>
 
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIXED cout << fixed << setprecision(12);
#define RANDOM srand(94385)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define f first
#define s second
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 998244353
#define inf 3000000000000000007ll
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])
 
template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
 
const int N = 5e5 + 10;
const int B = 300;

signed main() {
    FAST; FIXED; RANDOM;
    vector<vector<ll>> a(B, vector<ll>(B));
    vector<int> curr(N);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int mode, x, y;
        cin >> mode >> x >> y;
        if (mode == 1) {
            --x;
            curr[x] += y;
            a[1][x % 1] += y;
            a[2][x % 2] += y;
            a[3][x % 3] += y;
            a[4][x % 4] += y;
            a[5][x % 5] += y;
            a[6][x % 6] += y;
            a[7][x % 7] += y;
            a[8][x % 8] += y;
            a[9][x % 9] += y;
            a[10][x % 10] += y;
            a[11][x % 11] += y;
            a[12][x % 12] += y;
            a[13][x % 13] += y;
            a[14][x % 14] += y;
            a[15][x % 15] += y;
            a[16][x % 16] += y;
            a[17][x % 17] += y;
            a[18][x % 18] += y;
            a[19][x % 19] += y;
            a[20][x % 20] += y;
            a[21][x % 21] += y;
            a[22][x % 22] += y;
            a[23][x % 23] += y;
            a[24][x % 24] += y;
            a[25][x % 25] += y;
            a[26][x % 26] += y;
            a[27][x % 27] += y;
            a[28][x % 28] += y;
            a[29][x % 29] += y;
            a[30][x % 30] += y;
            a[31][x % 31] += y;
            a[32][x % 32] += y;
            a[33][x % 33] += y;
            a[34][x % 34] += y;
            a[35][x % 35] += y;
            a[36][x % 36] += y;
            a[37][x % 37] += y;
            a[38][x % 38] += y;
            a[39][x % 39] += y;
            a[40][x % 40] += y;
            a[41][x % 41] += y;
            a[42][x % 42] += y;
            a[43][x % 43] += y;
            a[44][x % 44] += y;
            a[45][x % 45] += y;
            a[46][x % 46] += y;
            a[47][x % 47] += y;
            a[48][x % 48] += y;
            a[49][x % 49] += y;
            a[50][x % 50] += y;
            a[51][x % 51] += y;
            a[52][x % 52] += y;
            a[53][x % 53] += y;
            a[54][x % 54] += y;
            a[55][x % 55] += y;
            a[56][x % 56] += y;
            a[57][x % 57] += y;
            a[58][x % 58] += y;
            a[59][x % 59] += y;
            a[60][x % 60] += y;
            a[61][x % 61] += y;
            a[62][x % 62] += y;
            a[63][x % 63] += y;
            a[64][x % 64] += y;
            a[65][x % 65] += y;
            a[66][x % 66] += y;
            a[67][x % 67] += y;
            a[68][x % 68] += y;
            a[69][x % 69] += y;
            a[70][x % 70] += y;
            a[71][x % 71] += y;
            a[72][x % 72] += y;
            a[73][x % 73] += y;
            a[74][x % 74] += y;
            a[75][x % 75] += y;
            a[76][x % 76] += y;
            a[77][x % 77] += y;
            a[78][x % 78] += y;
            a[79][x % 79] += y;
            a[80][x % 80] += y;
            a[81][x % 81] += y;
            a[82][x % 82] += y;
            a[83][x % 83] += y;
            a[84][x % 84] += y;
            a[85][x % 85] += y;
            a[86][x % 86] += y;
            a[87][x % 87] += y;
            a[88][x % 88] += y;
            a[89][x % 89] += y;
            a[90][x % 90] += y;
            a[91][x % 91] += y;
            a[92][x % 92] += y;
            a[93][x % 93] += y;
            a[94][x % 94] += y;
            a[95][x % 95] += y;
            a[96][x % 96] += y;
            a[97][x % 97] += y;
            a[98][x % 98] += y;
            a[99][x % 99] += y;
            a[100][x % 100] += y;
            a[101][x % 101] += y;
            a[102][x % 102] += y;
            a[103][x % 103] += y;
            a[104][x % 104] += y;
            a[105][x % 105] += y;
            a[106][x % 106] += y;
            a[107][x % 107] += y;
            a[108][x % 108] += y;
            a[109][x % 109] += y;
            a[110][x % 110] += y;
            a[111][x % 111] += y;
            a[112][x % 112] += y;
            a[113][x % 113] += y;
            a[114][x % 114] += y;
            a[115][x % 115] += y;
            a[116][x % 116] += y;
            a[117][x % 117] += y;
            a[118][x % 118] += y;
            a[119][x % 119] += y;
            a[120][x % 120] += y;
            a[121][x % 121] += y;
            a[122][x % 122] += y;
            a[123][x % 123] += y;
            a[124][x % 124] += y;
            a[125][x % 125] += y;
            a[126][x % 126] += y;
            a[127][x % 127] += y;
            a[128][x % 128] += y;
            a[129][x % 129] += y;
            a[130][x % 130] += y;
            a[131][x % 131] += y;
            a[132][x % 132] += y;
            a[133][x % 133] += y;
            a[134][x % 134] += y;
            a[135][x % 135] += y;
            a[136][x % 136] += y;
            a[137][x % 137] += y;
            a[138][x % 138] += y;
            a[139][x % 139] += y;
            a[140][x % 140] += y;
            a[141][x % 141] += y;
            a[142][x % 142] += y;
            a[143][x % 143] += y;
            a[144][x % 144] += y;
            a[145][x % 145] += y;
            a[146][x % 146] += y;
            a[147][x % 147] += y;
            a[148][x % 148] += y;
            a[149][x % 149] += y;
            a[150][x % 150] += y;
            a[151][x % 151] += y;
            a[152][x % 152] += y;
            a[153][x % 153] += y;
            a[154][x % 154] += y;
            a[155][x % 155] += y;
            a[156][x % 156] += y;
            a[157][x % 157] += y;
            a[158][x % 158] += y;
            a[159][x % 159] += y;
            a[160][x % 160] += y;
            a[161][x % 161] += y;
            a[162][x % 162] += y;
            a[163][x % 163] += y;
            a[164][x % 164] += y;
            a[165][x % 165] += y;
            a[166][x % 166] += y;
            a[167][x % 167] += y;
            a[168][x % 168] += y;
            a[169][x % 169] += y;
            a[170][x % 170] += y;
            a[171][x % 171] += y;
            a[172][x % 172] += y;
            a[173][x % 173] += y;
            a[174][x % 174] += y;
            a[175][x % 175] += y;
            a[176][x % 176] += y;
            a[177][x % 177] += y;
            a[178][x % 178] += y;
            a[179][x % 179] += y;
            a[180][x % 180] += y;
            a[181][x % 181] += y;
            a[182][x % 182] += y;
            a[183][x % 183] += y;
            a[184][x % 184] += y;
            a[185][x % 185] += y;
            a[186][x % 186] += y;
            a[187][x % 187] += y;
            a[188][x % 188] += y;
            a[189][x % 189] += y;
            a[190][x % 190] += y;
            a[191][x % 191] += y;
            a[192][x % 192] += y;
            a[193][x % 193] += y;
            a[194][x % 194] += y;
            a[195][x % 195] += y;
            a[196][x % 196] += y;
            a[197][x % 197] += y;
            a[198][x % 198] += y;
            a[199][x % 199] += y;
            a[200][x % 200] += y;
            a[201][x % 201] += y;
            a[202][x % 202] += y;
            a[203][x % 203] += y;
            a[204][x % 204] += y;
            a[205][x % 205] += y;
            a[206][x % 206] += y;
            a[207][x % 207] += y;
            a[208][x % 208] += y;
            a[209][x % 209] += y;
            a[210][x % 210] += y;
            a[211][x % 211] += y;
            a[212][x % 212] += y;
            a[213][x % 213] += y;
            a[214][x % 214] += y;
            a[215][x % 215] += y;
            a[216][x % 216] += y;
            a[217][x % 217] += y;
            a[218][x % 218] += y;
            a[219][x % 219] += y;
            a[220][x % 220] += y;
            a[221][x % 221] += y;
            a[222][x % 222] += y;
            a[223][x % 223] += y;
            a[224][x % 224] += y;
            a[225][x % 225] += y;
            a[226][x % 226] += y;
            a[227][x % 227] += y;
            a[228][x % 228] += y;
            a[229][x % 229] += y;
            a[230][x % 230] += y;
            a[231][x % 231] += y;
            a[232][x % 232] += y;
            a[233][x % 233] += y;
            a[234][x % 234] += y;
            a[235][x % 235] += y;
            a[236][x % 236] += y;
            a[237][x % 237] += y;
            a[238][x % 238] += y;
            a[239][x % 239] += y;
            a[240][x % 240] += y;
            a[241][x % 241] += y;
            a[242][x % 242] += y;
            a[243][x % 243] += y;
            a[244][x % 244] += y;
            a[245][x % 245] += y;
            a[246][x % 246] += y;
            a[247][x % 247] += y;
            a[248][x % 248] += y;
            a[249][x % 249] += y;
            a[250][x % 250] += y;
            a[251][x % 251] += y;
            a[252][x % 252] += y;
            a[253][x % 253] += y;
            a[254][x % 254] += y;
            a[255][x % 255] += y;
            a[256][x % 256] += y;
            a[257][x % 257] += y;
            a[258][x % 258] += y;
            a[259][x % 259] += y;
            a[260][x % 260] += y;
            a[261][x % 261] += y;
            a[262][x % 262] += y;
            a[263][x % 263] += y;
            a[264][x % 264] += y;
            a[265][x % 265] += y;
            a[266][x % 266] += y;
            a[267][x % 267] += y;
            a[268][x % 268] += y;
            a[269][x % 269] += y;
            a[270][x % 270] += y;
            a[271][x % 271] += y;
            a[272][x % 272] += y;
            a[273][x % 273] += y;
            a[274][x % 274] += y;
            a[275][x % 275] += y;
            a[276][x % 276] += y;
            a[277][x % 277] += y;
            a[278][x % 278] += y;
            a[279][x % 279] += y;
            a[280][x % 280] += y;
            a[281][x % 281] += y;
            a[282][x % 282] += y;
            a[283][x % 283] += y;
            a[284][x % 284] += y;
            a[285][x % 285] += y;
            a[286][x % 286] += y;
            a[287][x % 287] += y;
            a[288][x % 288] += y;
            a[289][x % 289] += y;
            a[290][x % 290] += y;
            a[291][x % 291] += y;
            a[292][x % 292] += y;
            a[293][x % 293] += y;
            a[294][x % 294] += y;
            a[295][x % 295] += y;
            a[296][x % 296] += y;
            a[297][x % 297] += y;
            a[298][x % 298] += y;
            a[299][x % 299] += y;
        } else {
            y += x - 1;
            y %= x;
            if (x >= B) {
                ll ans = 0;
                for (; y < N; y += x) ans += curr[y];
                cout << ans << '\n';
            } else {
                cout << a[x][y] << '\n';
            }
        }
    }
    return 0;
}  